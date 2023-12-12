#pragma once
#include "signals.hh"
#include <string>
#include "visitor.hh"

class Gate {
  Signal* _fanout;
public:
  Gate(Signal * out):_fanout(out){}
  virtual ~Gate(){}
  virtual void check_io_size() const = 0;
  Signal * out()  const {return  _fanout;}
  void setOut(unsigned int val){_fanout->setVal(val);}
  virtual std::string toString()  const= 0 ;
  virtual void accept(Visitor& v) const = 0;
};
