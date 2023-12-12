#pragma once

#include <string>
#include "signals.hh"
#include "gate.hh"
#include <map>
#include <set>
#include <ostream>

class Circuit{
  std::set<std::string> _inputs;
  std::set<std::string> _outputs;
  // gates : <output_gate,gate>
  std::map<std::string,Gate*> _gates;
  //map wires name with signal
  std::map<std::string, Signal*> _wires;
  std::string _name;
public:
  Circuit(std::set<std::string>& inputs,
          std::set<std::string>& outputs,
          std::map<std::string,Gate*>& gates,
          std::map<std::string, Signal*>& wires,
          std::string name = ""):_inputs(inputs),_outputs(outputs),_gates(gates),_wires(wires),_name(name){}
  std::map<std::string,Gate*>& gates() {return _gates;}
  Signal* operator[](std::string s) {return _wires[s];}
  std::string name() const {return _name;}
  std::set <std::string> inputs() const  {return _inputs;}
  std::set <std::string> outputs() const {return _outputs;}
  std::ostream& cnf(std::ostream& out);
  std::ostream& buildClauses(std::ostream& out);
  unsigned int nbClauses();
  unsigned int nbWires() const {return _wires.size();}
  unsigned int nbOutputs() const {return _outputs.size();}
  unsigned int nbInputs() const {return _inputs.size();}
  unsigned int nbGates() const {return _gates.size();}


  ~Circuit();
};

