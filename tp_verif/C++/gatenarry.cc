#include "gatenarry.hh"

void  GateNarry::check_io_size() const
{
  for (auto s : _fanins)
    {
      if(s->nb_bits() != out()->nb_bits())
        throw  std::invalid_argument("Number of bits not compatible");
    }
}
GateNarry::GateNarry(std::vector<Signal*> fanins, Signal * out):Gate(out),_fanins(fanins){
  check_io_size();
}

void GateNarryNand::evaluate()
{
  unsigned int val = fanins()[0]->val();
  for (auto & s : fanins())
    { 
      val &= s->val();
    }
  setOut(~val);
}

std::string GateNarryNand::toString() const
{
  std::string str;
  str = out()->name() +  " = " +fanins()[0]->name() ;
  for ( size_t i = 1; i < fanins().size(); i++)
    {
      str+= " NAND " + fanins()[i]->name() ;
    }
  return str;
}
void GateNarryAnd::evaluate()
{
  unsigned int val = fanins()[0]->val();
  for (auto & s : fanins())
    { 
      val &= s->val();
    }
  setOut(val);
}

std::string GateNarryAnd::toString() const
{
  std::string str;
  str = out()->name() +  " = " +fanins()[0]->name() ;
  for ( size_t i = 1; i < fanins().size(); i++)
    {
      str+= " AND " + fanins()[i]->name() ;
    }
  return str;
}

void GateNarryOr::evaluate()
{
  unsigned int val = fanins()[0]->val();
  for (auto & s : fanins())
    { 
      val |= s->val();
    }
  setOut(val);
}

std::string GateNarryOr::toString() const
{
  std::string str;
  str = out()->name() +  " = " +fanins()[0]->name() ;
  for ( size_t i = 1; i < fanins().size(); i++)
    {
      str+= " OR " + fanins()[i]->name() ;
    }
  return str;
}
void GateNarryNor::evaluate()
{
  unsigned int val = fanins()[0]->val();
  for (auto & s : fanins())
    { 
      val |= s->val();
    }
  setOut(~val);
}

std::string GateNarryNor::toString() const
{
  std::string str;
  str = out()->name() +  " = " +fanins()[0]->name() ;
  for ( size_t i = 1; i < fanins().size(); i++)
    {
      str+= " NOR " + fanins()[i]->name() ;
    }
  return str;
}



// Factory Implementation
namespace{
  // Narry Gate factory
  GateNarryNand* createGateNarryNand(std::vector<Signal*>io){
    Signal * out = io.back();
    io.pop_back();
    return new GateNarryNand(io,out);
  }
  GateNarryAnd*  createGateNarryAnd(std::vector<Signal*>io){
    Signal * out = io.back();
    io.pop_back();
    return new GateNarryAnd(io,out);
  }
  GateNarryNor*  createGateNarryNor(std::vector<Signal*>io){
    Signal * out = io.back();
    io.pop_back();
    return new GateNarryNor(io,out);
    }
  GateNarryOr*   createGateNarryOr(std::vector<Signal*>io){
    Signal * out = io.back();
    io.pop_back();
    return new GateNarryOr(io,out);
  }
  const bool registeredGateNarryNand=GateFactory::Instance().registerGate("nandN",(GateFactory::CreateGateCallBack)createGateNarryNand);
  const bool registeredGateNarryAnd=GateFactory::Instance().registerGate("andN",(GateFactory::CreateGateCallBack)createGateNarryAnd);
  const bool registeredGateNarryNor=GateFactory::Instance().registerGate("norN",(GateFactory::CreateGateCallBack)createGateNarryNor);
  const bool registeredGateNarryOr=GateFactory::Instance().registerGate("orN",(GateFactory::CreateGateCallBack)createGateNarryOr);
}
