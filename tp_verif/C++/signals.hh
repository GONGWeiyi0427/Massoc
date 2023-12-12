#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cmath>

class Signal {
  const std::string  _name;
  const size_t _nb_bits;
  unsigned int _val;
  unsigned int _index;
public :
  static size_t _id;
  Signal(std::string name, size_t nb_bits, unsigned int val);
  //binary signals
  Signal(std::string name):Signal(name,1,0){}
  unsigned int val() const  {return _val;}
  void setVal(unsigned int);
  size_t nb_bits() const {return _nb_bits;}
  std::string name() const {return _name;}
  unsigned int index() const {return _index;}
protected :
  void check_bound() const;

};


