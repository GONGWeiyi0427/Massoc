#pragma once

#include <iostream>

class GateNarryAnd;
class GateNarryNand;
class GateNarryNor;
class GateNarryOr;
class GateNot;
class GateFrom;
class GateBuf;
class GateAnd;
class GateNand;
class GateNor;
class GateOr;
class GateXor;
class GateXnor;

class Visitor {
public:
  virtual void visit(const  GateNarryAnd&)  = 0 ;
  virtual void visit(const  GateNarryNand&) = 0 ;
  virtual void visit(const  GateNarryNor&)  = 0 ;
  virtual void visit(const  GateNarryOr&)   = 0 ;
  virtual void visit(const  GateNot&)  = 0 ;
  virtual void visit(const  GateFrom&) = 0 ;
  virtual void visit(const  GateBuf&)  = 0 ;
  virtual void visit(const  GateAnd&)  = 0 ;
  virtual void visit(const  GateNand&) = 0 ;
  virtual void visit(const  GateNor&)  = 0 ;
  virtual void visit(const  GateOr&)   = 0 ;
  virtual void visit(const  GateXor&)  = 0 ;
  virtual void visit(const  GateXnor&) = 0 ;

};

class CNFVisitor: public Visitor{
  std::ostream &_out;

public:
  CNFVisitor(std::ostream &out):_out(out){}
  void visit(const  GateNarryAnd&)   ;
  void visit(const  GateNarryNand&)  ;
  void visit(const  GateNarryNor&)   ;
  void visit(const  GateNarryOr&)    ;
  void visit(const  GateNot&)   ;
  void visit(const  GateFrom&)  ;
  void visit(const  GateBuf&)   ;
  void visit(const  GateAnd&)   ;
  void visit(const  GateNand&)  ;
  void visit(const  GateNor&)   ;
  void visit(const  GateOr&)    ;
  void visit(const  GateXor&)   ;
  void visit(const  GateXnor&)  ;
};

class countClauses: public Visitor{
  size_t _total;
public:
  countClauses():_total(0){}
  size_t totalClauses(){return _total;}
  void visit(const  GateNarryAnd&)   ;
  void visit(const  GateNarryNand&)  ;
  void visit(const  GateNarryNor&)   ;
  void visit(const  GateNarryOr&)    ;
  void visit(const  GateNot&)   ;
  void visit(const  GateFrom&)  ;
  void visit(const  GateBuf&)   ;
  void visit(const  GateAnd&)   ;
  void visit(const  GateNand&)  ;
  void visit(const  GateNor&)   ;
  void visit(const  GateOr&)    ;
  void visit(const  GateXor&)   ;
  void visit(const  GateXnor&)  ;
};

