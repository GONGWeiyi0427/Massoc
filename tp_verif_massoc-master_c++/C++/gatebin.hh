#pragma once
#include "signals.hh"
#include <string>
#include <vector>

#include "gatefactory.hh"

class GateBin : public Gate{
  Signal* _in0;
  Signal* _in1;
public:
  GateBin(Signal* i0, Signal* i1, Signal* out);
  Signal* in0() const  {return _in0;}
  Signal* in1() const  {return _in1;}
protected:
  void check_io_size() const;
};

class GateNand : public GateBin {
public:
  GateNand(Signal *i0, Signal *i1, Signal* out):GateBin(i0,i1,out){}
  void evaluate();
  std::string toString()const;
  void accept(Visitor& v) const {v.visit(*this);}
};

class GateAnd : public GateBin {
public:
  GateAnd(Signal *i0, Signal *i1, Signal* out):GateBin(i0,i1,out){}
  void evaluate();
  std::string toString()const;
  void accept(Visitor& v) const {v.visit(*this);}
};

class GateOr : public GateBin {
public:
  GateOr(Signal *i0, Signal *i1, Signal* out):GateBin(i0,i1,out){}
  void evaluate();
  std::string toString()const;
  void accept(Visitor& v) const {v.visit(*this);}
};

class GateNor : public GateBin {
public:
  GateNor(Signal *i0, Signal *i1, Signal* out):GateBin(i0,i1,out){}
  void evaluate();
  std::string toString()const;
  void accept(Visitor& v) const {v.visit(*this);}
};
class GateXor : public GateBin {
public:
  GateXor(Signal *i0, Signal *i1, Signal* out):GateBin(i0,i1,out){}
  void evaluate();
  std::string toString()const;
  void accept(Visitor& v) const {v.visit(*this);}
};

class GateXnor : public GateBin {
public:
  GateXnor(Signal *i0, Signal *i1, Signal* out):GateBin(i0,i1,out){}
  void evaluate();
  std::string toString()const;
  void accept(Visitor& v) const {v.visit(*this);}
};


