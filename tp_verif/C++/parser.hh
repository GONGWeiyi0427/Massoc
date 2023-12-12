#pragma once

#include <fstream>
#include "circuit.hh"
class ParserIscas85{
  std::string _fileName;
  std::ifstream _iscasFile;
public:
  ParserIscas85(std::string s);
  ~ParserIscas85();
  Circuit createCircuit();
  void newFile(std::string s);
};

