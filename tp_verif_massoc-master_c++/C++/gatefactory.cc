#include "gatefactory.hh"
#include <iostream>
#include <vector>
#include "signals.hh"

//add a pair with type from CallBackMap::value_type return the bool from
// the return pair value <iterator, bool>
bool GateFactory::registerGate(std::string GateId, CreateGateCallBack createfn)
{
  return _callbacks.insert(CallBackMap::value_type(GateId, createfn)).second;
}
//Erase return the number of elements erased
bool GateFactory::unregisterGate(std::string gateId)
{
  return   _callbacks.erase(gateId) == 1 ;
}

Gate * GateFactory::createGate(std::string gateId, std::vector<Signal*>io) const
{
  CallBackMap::const_iterator i = _callbacks.find(gateId);
  if(i  ==  _callbacks.end())
    {
      std::cerr << "Type " << gateId << " not registered in GateFactory" << std::endl;
      return nullptr;
    }
  return(i->second)(io);
}

GateFactory& GateFactory::Instance(){
  static GateFactory obj;
  return obj;
}

void GateFactory::printRegistered() const
{
  for (auto g : _callbacks)
    {
      std::cout << g.first << std::endl;
    }
}
