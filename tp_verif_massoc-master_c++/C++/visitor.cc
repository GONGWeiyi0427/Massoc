#include "visitor.hh"
#include "gatenarry.hh"
#include "gateun.hh"
#include "gatebin.hh"
#include <iostream>




void countClauses::visit(const  GateNarryAnd& g)   {
  _total += g.fanins().size() + 1;
}
void countClauses::visit(const  GateNarryNand& g)  {
  _total += g.fanins().size() + 1;
}
void countClauses::visit(const  GateNarryNor& g)   {
  _total += g.fanins().size() + 1;
}
void countClauses::visit(const  GateNarryOr& g)    {
  _total += g.fanins().size() + 1;
}
void countClauses::visit(const  GateNot& g)   {
  _total+=2;
}
void countClauses::visit(const  GateFrom& g)  {
  _total+=2;
}
void countClauses::visit(const  GateBuf& g)   {
  _total+=2;
}
void countClauses::visit(const  GateAnd& g)   {
  _total+=3;
}
void countClauses::visit(const  GateNand& g)  {
  _total+=3;
}
void countClauses::visit(const  GateNor& g)   {
  _total+=3;
}
void countClauses::visit(const  GateOr& g)    {
  _total+=3;
}
void countClauses::visit(const  GateXor& g)   {
  _total+=4;
}
void countClauses::visit(const  GateXnor& g)  {
  _total+=4;
}
