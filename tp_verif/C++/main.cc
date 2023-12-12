#include <iostream>
#include "signals.hh"
#include "gatebin.hh"
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include "parser.hh"
#include "circuit.hh"
#include "visitor.hh"
#include "gateun.hh"
#include "gatenarry.hh"


// TODO Add clauses to impose same inputs.
// if not the same inputs (name and number return false)
bool addEqualInputsClauses(Circuit & c1, Circuit & c2, std::ostream& out)
{
 
  return false;
}

// TODO Add clauses to the mitter structure
// if not the same outputs (name and number return false)
// else generate XOR gates btw the outputs and
// the final or for the equivalence check
bool buildEquivOutputs(Circuit & c1, Circuit & c2, unsigned int index_max, std::ostream& out)
{
  return false;
}

//TODO testGenerateCNF
void testGenerateCNF(std::string f1)
{
  ParserIscas85 parse(f1);
  Circuit circ1 = parse.createCircuit();
  circ1.cnf(std::cout);
}

void testGenerateCNFEquiv(std::string f1, std::string f2)
{
  ParserIscas85 parse(f1);
  Circuit circ1 = parse.createCircuit();
  parse.newFile(f2);
  Circuit circ2 = parse.createCircuit();

  //Compute number of clauses and number of literals
  unsigned int nbClauses = circ1.nbClauses() + circ2.nbClauses() + 2*circ1.nbInputs() + 4*circ1.nbOutputs() + 1;
  unsigned int nbWires = circ1.nbWires() + circ2.nbWires() + circ1.nbOutputs();

  // print CNF header
  std::cout << "c " << Signal::_id << std::endl;
  std::cout << "c\np cnf " << nbWires << " " << nbClauses << std::endl;
  circ1.buildClauses(std::cout);
  circ2.buildClauses(std::cout);
  if(! addEqualInputsClauses(circ1,circ2, std::cout))
    {
      std::cerr << "[WARNING] not the same inputs" << std::endl;
      exit(2);
    }
  if(!buildEquivOutputs(circ1,circ2, circ1.nbWires() + circ2.nbWires(),std::cout))
    {
      std::cerr << "[WARNING] not the same outputs" << std::endl;
      exit(3);
    }
}

int main(int argc,char* argv[])
{
  if (argc <= 1)
    {
      std::cout << "usage : \n \t circ fichier iscas85  " << std::endl;
      return 0;
    }
  try{
    if(argc == 2)
      testGenerateCNF(argv[1]);
    if(argc == 3)
      testGenerateCNFEquiv(argv[1],argv[2]);

  }
  catch(std::string e)
    {
      std::cerr << e << std::endl;
      return 1;
    }

  return 0;
}
