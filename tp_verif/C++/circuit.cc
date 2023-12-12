#include <string>
#include "circuit.hh"
#include "visitor.hh"

Circuit::~Circuit(){
  for(auto s : _gates)
    {
      delete s.second;
    }
  for(auto s : _wires)
    {
      delete s.second;
    }
}


std::ostream& Circuit::buildClauses(std::ostream& out)
{
  CNFVisitor generatecnf(out);
  for (auto g : _gates)
    {
      g.second->accept(generatecnf);
    }
  return out;
}


std::ostream& Circuit::cnf(std::ostream& out)
{
  out << "c     file: " << _name << std::endl;
  out << "c     inputs:" << std::endl;
  for (auto i : _inputs)
    {
      out << "c " << i << " " <<  _wires[i]->index() << std::endl;
    }
  out << "c     outputs:" << std::endl;
  for (auto i : _outputs)
    {
      out << "c " << i << " " <<  _wires[i]->index() << std::endl;
    }

  out << "c\np cnf " << _wires.size() << " " << nbClauses() << std::endl;
  buildClauses(out);
  return out;
}


unsigned int Circuit::nbClauses(){
  countClauses count;
  for (auto g : _gates)
    {
      g.second->accept(count);
    }
  return  count.totalClauses();
}

