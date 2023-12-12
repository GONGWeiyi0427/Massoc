#pragma once

#include "gate.hh"
#include <map>
#include <string>
#include <vector>

class GateFactory{
public:
  typedef Gate* (*CreateGateCallBack)(std::vector<Signal*>);
private:
  typedef std::map<std::string,CreateGateCallBack> CallBackMap;
public:
  bool registerGate(std::string GateId, CreateGateCallBack createFn);
  bool unregisterGate(std::string GateId);
  Gate * createGate(std::string GateId, std::vector<Signal*>io) const;
  void printRegistered() const;
private:
  CallBackMap _callbacks;
  //Singleton implementation
public:
  static GateFactory& Instance();
private:
  GateFactory(){}
  GateFactory(const GateFactory&);
  GateFactory& operator=(const GateFactory&);
  ~GateFactory(){}
};
