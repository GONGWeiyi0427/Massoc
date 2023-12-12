#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "signals.hh"

// init _id
size_t Signal::_id = 1;

//throw expetion out-of-bpund
void Signal::check_bound() const
{
  if (_val > std::pow(2,_nb_bits)-1)
    {
      std::stringstream ss;
      ss << "Signal (" << _name << "): Value out of bound, should not be more than " << std::pow(2,_nb_bits)-1;
      throw std::out_of_range(ss.str());
    }
}
Signal::Signal(std::string name, size_t nb_bits,  unsigned int val):_name(name),_nb_bits(nb_bits),_val(val),_index(_id){
  _id++;
  if (_nb_bits == 0)
    throw std::invalid_argument("Signal: Number of bits cannot be 0" );
  check_bound();
}

void Signal::setVal(unsigned int val)
{
  _val = val;
  check_bound();
}
