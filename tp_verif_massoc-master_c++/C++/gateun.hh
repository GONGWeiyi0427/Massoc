#pragma once
#include "signals.hh"
#include <string>

#include "gatefactory.hh"
#include "visitor.hh"

class GateUn : public Gate{
  Signal* _in ;
public:
  GateUn(Signal* i0, Signal* out);
  Signal* in() const  {return _in;}
  virtual void accept(Visitor& v) const = 0;
protected:
  void check_io_size() const;
};

class GateNot : public GateUn {
public:
  GateNot(Signal * in, Signal* out):GateUn(in,out){}
  void evaluate();
  std::string toString()const;
  void accept(Visitor& v) const {v.visit(*this);}
};

class GateBuf : public GateUn {
public:
  GateBuf(Signal * in, Signal* out):GateUn(in,out){}
  void evaluate();
  std::string toString()const;
  void accept(Visitor& v) const {v.visit(*this);}
};

class GateFrom : public GateUn {
public:
  GateFrom(Signal * in, Signal* out):GateUn(in,out){}
  void evaluate();
  std::string toString()const;
  void accept(Visitor& v) const {v.visit(*this);}
};

