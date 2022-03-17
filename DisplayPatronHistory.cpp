//////////////////  DisplayPatronHistory.cpp file  //////////////////////////

#include "DisplayPatronHistory.h"
#include "Library.h"

//----------------------------------------------------------------------------
// constructor
DisplayPatronHistory::DisplayPatronHistory(Library *library) 
                        : Command(library) {
  this->patron = NULL;
}

//----------------------------------------------------------------------------
// destructor
DisplayPatronHistory::~DisplayPatronHistory() {
  this->patron = NULL;
}

//----------------------------------------------------------------------------
// execute
// calls patron display history on patron passed in, which displays
// a list of all the check outs and returns performed by a patron.
void DisplayPatronHistory::execute() {
  this->patron->displayHistory();  
}

//----------------------------------------------------------------------------
// parseFile
// parses the rest of the line for a DisplayPatronHistory command
// the only thing left to parse is an id though.
void DisplayPatronHistory::parseFile(char type, istream& infile) {
  int id;
  infile >> id;

  this->patron = this->library->getPatronManager()->getPatron(id);
}



