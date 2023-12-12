#pragma once

#include "signals.hh"
#include <string>
#include <vector>
#include "visitor.hh"
#include "gatefactory.hh"

class GateNarry : public Gate{
  std::vector<Signal*> _fanins;
public:
  GateNarry(std::vector<Signal*>, Signal* out);
  std::vector<Signal*> fanins() const  {return _fanins;}
  //visitor implementation
  virtual void accept(Visitor& v) const = 0;
protected:
  void check_io_size() const;
};

class GateNarryNand : public GateNarry {
 public:
  GateNarryNand(std::vector<Signal*> fanins, Signal* out):GateNarry(fanins,out){}
  void evaluate();
  std::string toString()const;
  void accept(Visitor& v) const {v.visit(*this);}
};

class GateNarryAnd : public GateNarry {
public:
  GateNarryAnd(std::vector<Signal*> fanins, Signal* out):GateNarry(fanins,out){}
  void evaluate();
  std::string toString()const;
  void accept(Visitor& v) const {v.visit(*this);}
};

class GateNarryNor : public GateNarry {
public:
  GateNarryNor(std::vector<Signal*> fanins, Signal* out):GateNarry(fanins,out){}
  void evaluate();
  std::string toString()const;
  void accept(Visitor& v) const {v.visit(*this);}
};

class GateNarryOr : public GateNarry {
public:
  GateNarryOr(std::vector<Signal*> fanins, Signal* out):GateNarry(fanins,out){}
  void evaluate();
  std::string toString()const;
  void accept(Visitor& v) const {v.visit(*this);}
};



