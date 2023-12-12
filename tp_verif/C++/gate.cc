#include "gate.hh"
#include "gatebin.hh"
#include "gateun.hh"
#include <stdexcept>

void  GateBin::check_io_size() const
{
  if (_in0->nb_bits() != _in1->nb_bits() || _in0->nb_bits() != out()->nb_bits() )
    throw  std::invalid_argument("Number of bits not compatible");
}
void  GateUn::check_io_size() const
{
  if (_in->nb_bits()  != out()->nb_bits() )
    throw  std::invalid_argument("Number of bits not compatible");
}

GateBin::GateBin(Signal * i0, Signal * i1, Signal * out):Gate(out),_in0(i0),_in1(i1){
  check_io_size();
}
GateUn::GateUn(Signal * i, Signal * out):Gate(out),_in(i){
  check_io_size();
}

void GateNand::evaluate()
{
  setOut(!(in1()->val() & in0()->val()));
}

std::string GateNand::toString() const
{
  std::string str;
  str = out()->name() +  " = " + in0()->name() + " NAND " + in1()->name();
  return str;
}

void GateAnd::evaluate()
{
    setOut((in1()->val() & in0()->val()));
}

std::string GateAnd::toString() const
{
  std::string str;
  str = out()->name() +  " = " + in0()->name() + " AND " + in1()->name();
  return str;
}

void GateOr::evaluate()
{
  setOut((in1()->val() | in0()->val()));
}
void GateNor::evaluate()
{
  setOut(!(in1()->val() | in0()->val()));
}
std::string GateOr::toString() const
{
  std::string str;
  str = out()->name() +  " = " + in0()->name() + " OR " + in1()->name();
  return str;
}
std::string GateNor::toString() const
{
  std::string str;
  str = out()->name() +  " = " + in0()->name() + " NOR " + in1()->name();
  return str;
}


void GateXor::evaluate()
{
  setOut((in1()->val() ^ in0()->val()));
}
void GateXnor::evaluate()
{
  setOut(!(in1()->val() ^ in0()->val()));
}
std::string GateXor::toString() const
{
  std::string str;
  str = out()->name() +  " = " + in0()->name() + " XOR " + in1()->name();
  return str;
}
std::string GateXnor::toString() const
{
  std::string str;
  str = out()->name() +  " = " + in0()->name() + " XNOR " + in1()->name();
  return str;
}

void GateNot::evaluate()
{
  setOut(~(in()->val()));
}
std::string GateNot::toString() const
{
  std::string str;
  str = out()->name() +  " = NOT " + in()->name();
  return str;
}

void GateBuf::evaluate()
{
  setOut((in()->val()));
}
std::string GateBuf::toString() const
{
  std::string str;
  str = out()->name() +  " =  " ;
  return str;
}

void GateFrom::evaluate()
{
  setOut((in()->val()));
}
std::string GateFrom::toString() const
{
  std::string str;
  str = out()->name() +  " from  " + in()->name();
  return str;
}


// Factory Implementation
namespace{
  // Binary Gate factory
  GateNand* createGateNand(std::vector<Signal*>io){return new GateNand(io[0],io[1],io[2]);}
  GateAnd*  createGateAnd(std::vector<Signal*>io){return new GateAnd(io[0],io[1],io[2]);}
  GateNor*  createGateNor(std::vector<Signal*>io){return new GateNor(io[0],io[1],io[2]);}
  GateOr*   createGateOr(std::vector<Signal*>io){return new GateOr(io[0],io[1],io[2]);}
  GateXor*  createGateXor(std::vector<Signal*>io){return new GateXor(io[0],io[1],io[2]);}
  GateXnor* createGateXnor(std::vector<Signal*>io){return new GateXnor(io[0],io[1],io[2]);}
  const bool registeredGateNand=GateFactory::Instance().registerGate("nand",(GateFactory::CreateGateCallBack)createGateNand);
  const bool registeredGateAnd=GateFactory::Instance().registerGate("and",(GateFactory::CreateGateCallBack)createGateAnd);
  const bool registeredGateNor=GateFactory::Instance().registerGate("nor",(GateFactory::CreateGateCallBack)createGateNor);
  const bool registeredGateOr=GateFactory::Instance().registerGate("or",(GateFactory::CreateGateCallBack)createGateOr);
  const bool registeredGateXor=GateFactory::Instance().registerGate("xor",(GateFactory::CreateGateCallBack)createGateXor);
  const bool registeredGateXnor=GateFactory::Instance().registerGate("xnor",(GateFactory::CreateGateCallBack)createGateXnor);
  //Unary Gate Factory
  GateNot*  createGateNot(std::vector<Signal*>io){return new GateNot(io[0],io[1]);}
  GateBuf*  createGateBuf(std::vector<Signal*>io){return new GateBuf(io[0],io[1]);}
  GateFrom* createGateFrom(std::vector<Signal*>io){return new GateFrom(io[0],io[1]);}
  const bool registeredGateNot=GateFactory::Instance().registerGate("not",(GateFactory::CreateGateCallBack)createGateNot);
  const bool registeredGateBuf=GateFactory::Instance().registerGate("buff",(GateFactory::CreateGateCallBack)createGateBuf);
  const bool registeredGateFrom=GateFactory::Instance().registerGate("from",(GateFactory::CreateGateCallBack)createGateFrom);
}
