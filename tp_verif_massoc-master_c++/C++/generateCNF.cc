#include "visitor.hh"
#include "gatenarry.hh"
#include "gateun.hh"
#include "gatebin.hh"
#include <iostream>


void CNFVisitor::visit(const  GateNarryAnd& g) {
  // If any input is 0, the output is 0.
  _out << "c " << g.toString() << std::endl;
  for (auto s : g.fanins())
    {
      _out << (s->index()) << " " << "-" <<  (g.out()->index()) << " 0" << std::endl;
    }
  // If all inputs are 1, the output must be 1. 
  for (auto s : g.fanins())
    {
      _out << "-" << s->index() << " " ;
    }
  _out << g.out()->index() << " 0" << std::endl;
}
void CNFVisitor::visit(const  GateNarryNand& g) {
  //TODO
  // If any input is 0, the output is 0.
  _out << "c " << g.toString() << std::endl;
  for (auto s : g.fanins())
    {
      _out << (s->index()) << " " <<  (g.out()->index()) << " 0" << std::endl;
    }
  // If all inputs are 1, the output must be 1. 
  for (auto s : g.fanins())
    {
      _out << "-" << s->index() << " " ;
    }
  _out <<  "-" <<  g.out()->index() << " 0" << std::endl;
}
void CNFVisitor::visit(const  GateNarryOr& g)    {
  //TODO
  // If any input is 0, the output is 0.
  _out << "c " << g.toString() << std::endl;
  for (auto s : g.fanins())
    {
      _out << "-" << (s->index()) << (g.out()->index()) << " 0" << std::endl;
    }
  // If all inputs are 1, the output must be 1. 
  for (auto s : g.fanins())
    {
      _out << s->index() << " " ;
    }
  _out <<  "-" <<  g.out()->index() << " 0" << std::endl;
}
void CNFVisitor::visit(const GateNarryNor& g){
  //TODO
  // If any input is 0, the output is 0.
  _out << "c " << g.toString() << std::endl;
  for (auto s : g.fanins())
    {
      _out << "-" << (s->index()) << "-" << (g.out()->index()) << " 0" << std::endl;
    }
  // If all inputs are 1, the output must be 1. 
  for (auto s : g.fanins())
    {
      _out << s->index() << " " ;
    }
  _out << g.out()->index() << " 0" << std::endl;
}

void CNFVisitor::visit(const  GateNot& g){
  //TODO
  _out << "c " << g.toString() << std::endl;
  // if one input is 0, output must be 0
  _out << "-" << g.in()->index() << " " << "-" << g.out()->index() << " 0" << std::endl;
  _out << g.in()->index() << " " << g.out()->index() << " 0" << std::endl;  
}
void CNFVisitor::visit(const  GateFrom& g)  {
  Signal * in = g.in();
  Signal * out = g.out();
  _out << "c " << g.toString() << std::endl;
  /* If input is 0, output must be 0. */
  _out << in->index() << " " << "-" << out->index() << " 0" << std::endl;
  /* If input is 1, output must be 1. */
  _out << "-" << in->index() << " " << out->index() << " 0" << std::endl;
}
void CNFVisitor::visit(const  GateBuf& g)   {
  _out << "c " << g.toString() << std::endl;
  /* If input is 0, output must be 0. */
  _out << g.in()->index() << " " << "-" <<g.out()->index() << " 0" << std::endl;
  /* If input is 1, output must be 1. */
  _out << "-" << g.in()->index() << " " << g.out()->index() << " 0" << std::endl;
}

void CNFVisitor::visit(const  GateAnd& g)   {
  _out << "c " << g.toString() << std::endl;
  // if one input is 0, output must be 0
  _out << g.in0()->index() << " " << "-" << g.out()->index() << " 0" << std::endl;
  _out << g.in1()->index() << " " << "-" << g.out()->index() << " 0" << std::endl;  
  // if all inputs are 1, output must be 1
  _out << "-" << g.in0()->index() << " -" << g.in1()->index() << " " << g.out()->index() << " 0" << std::endl;
}
void CNFVisitor::visit(const  GateNand& g)  {
  //TODO
  _out << "c " << g.toString() << std::endl;
  // if one input is 0, output must be 0
  _out << g.in0()->index() << " " << g.out()->index() << " 0" << std::endl;
  _out << g.in1()->index() << " " << g.out()->index() << " 0" << std::endl;  
  // if all inputs are 1, output must be 1
  _out << "-" << g.in0()->index() << " -" << g.in1()->index() << " " << "-" << g.out()->index() << " 0" << std::endl;
}
void CNFVisitor::visit(const  GateNor& g)   {
  //TODO
  _out << "c " << g.toString() << std::endl;
  // if one input is 0, output must be 0
  _out << "-" << g.in0()->index() << " " << "-" << g.out()->index() << " 0" << std::endl;
  _out << "-" << g.in1()->index() << " " << "-" << g.out()->index() << " 0" << std::endl;  
  // if all inputs are 1, output must be 1
  _out << " " << g.in0()->index() << " " << g.in1()->index() << " " << g.out()->index() << " 0" << std::endl;
}
void CNFVisitor::visit(const  GateOr& g)    {
  //TODO
  _out << "c " << g.toString() << std::endl;
  // if one input is 0, output must be 0
  _out << "-" << g.in0()->index() << " " << g.out()->index() << " 0" << std::endl;
  _out << "-" << g.in1()->index() << " " << g.out()->index() << " 0" << std::endl;  
  // if all inputs are 1, output must be 1
  _out << g.in0()->index() << " " << g.in1()->index() << " -" << g.out()->index() << " 0" << std::endl;
}
void CNFVisitor::visit(const  GateXor& g)   {
  //TODO
  // if all inputs are 1, output must be 1
  _out << "-" << g.in0()->index() << " -" << g.in1()->index() << " " << "-" << g.out()->index() << " 0" << std::endl;
  _out << g.in0()->index() << " " << g.in1()->index() << " " << g.out()->index() << " 0" << std::endl;
  _out << g.in0()->index() << " -" << g.in1()->index() << " " << g.out()->index() << " 0" << std::endl;
  _out << "-" << g.in0()->index() << " " << g.in1()->index() << " " << g.out()->index() << " 0" << std::endl;
}
void CNFVisitor::visit(const  GateXnor& g)  {
  _out << "c " << g.toString() << std::endl;
  // if  all inputs are 0, output must be 1
  _out << g.in0()->index() <<  " " << g.in1()->index() << " " << g.out()->index() << " 0" << std::endl;
  // if  all inputs are 1, output must be 1
  _out << "-" << g.in0()->index() <<  " -" << g.in1()->index() << " " << g.out()->index() << " 0" << std::endl;
  // if in0 is 1 and in1 is 0, output must be 0
  _out << "-" << g.in0()->index() <<  " " << g.in1()->index() << " -" << g.out()->index() << " 0" << std::endl;
  // if in0 is 0 and in1 is 1, output must be 0
  _out << g.in0()->index() <<  " -" << g.in1()->index() << " -" << g.out()->index() << " 0" << std::endl;
}

