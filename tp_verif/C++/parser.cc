#include "parser.hh"
#include "gatefactory.hh"
#include <string>
#include <sstream>
#include <set>
#include <exception>

ParserIscas85::ParserIscas85(std::string s):_fileName(s) {
  _iscasFile.open(s);
  if(! _iscasFile.is_open())
    std::cerr << "file " << s << " not open" << std::endl;
}
void ParserIscas85::newFile(std::string s) {
  _fileName = s;
  _iscasFile.close();
  _iscasFile.open(s);
  if(! _iscasFile.is_open())
    std::cerr << "file " << s << " not open" << std::endl;

}

ParserIscas85::~ParserIscas85()
{
  _iscasFile.close();
}

// TODO change wires to be for construct only and rebuild with the correct or with name
Circuit ParserIscas85::createCircuit()
{
  std::string s;
  std::set<std::string> inputs;
  std::set<std::string> outputs;
  std::map<std::string,Gate*> gates;
  // map id in iscas format with signals
  std::map<int, Signal*> wires;
  //internals signal for circuit
  std::map<std::string,Signal*> internals;

  GateFactory& factory = GateFactory::Instance();
  while(getline(_iscasFile,s))
    {
      if(s[0] == '*' || s[0] == '\n' || s[0] == '\r')
        continue;
      std::stringstream ss(s);
      int index;
      std::string wirename;
      std::string wiretype ;
      unsigned int fanins, fanouts;
      //read line
      ss >> index  >> wirename >> wiretype ;
      //index already exists
      auto it = wires.find(index);
      if( it != wires.end())
        throw  std::string("Signal " + std::to_string(index) + " already used ");
      //else
      if(wiretype == "inpt")
        {
          wires[index] = new Signal(wirename,1,0);
          inputs.insert(wirename);
          internals[wirename] = wires[index];
        }
      else{
        if(wiretype == "from")
          {
            std::string i0_name;
            ss >> i0_name;
            auto it = internals.find(i0_name);
            // find signal from by name
            if(it == internals.end()) // not found
              throw std::string("Signal" + i0_name + " input of from " + std::to_string(index) + " not found");
            //else
            wires[index] =  new Signal(wirename);
            gates[wirename] = factory.createGate(wiretype,{internals[i0_name],wires[index]});
            internals[wirename] = wires[index];
          }
        else{
          ss >> fanouts >> fanins;
          wires[index] = new Signal(wirename,1,0);
          internals[wirename] = wires[index];
          //fill vector
          std::vector<Signal *> io;
          for(size_t i = 0; i < fanins; i++)
            {
              int indexI;
              _iscasFile >> indexI;
              if(wires.find(indexI) == wires.end())
                {
                  std::cerr << "Design error: fanin "  << indexI << " for wire " << index << " (" \
                            <<  wirename  << ") " << wiretype << " does not exist" << std::endl;
                  exit(1);
                }
              io.push_back(wires[indexI]);
            }
          io.push_back(wires[index]);
          if(fanins <= 2)
            {
              gates[wirename] = factory.createGate(wiretype,io);
            }
          else{
            std::string name=wiretype+'N';
            gates[wirename] = factory.createGate(name,io);
          }
          //outputs
          if (fanouts == 0)
            {
              outputs.insert(wirename);
            }
          getline(_iscasFile,s); //to go to the next line
        }
      }
    }
  return Circuit(inputs,outputs,gates,internals,_fileName);
}
