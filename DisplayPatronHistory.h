#ifndef _DISPLAY_PATRON_HISTORY_H_
#define _DISPLAY_PATRON_HISTORY_H_

#include "Command.h"
class ItemTree;
class Patron;
class ItemFactory;
class Library;
class PatronManager;

//----------------------------------------------------------------------------
// class DisplayPatronHistory
// inherits from Command this object is used for displaying the history
// of a patron. parseFile reads in and sets this->patron == patron found
// with id found and then execute is called to display the history of that
// patron.
//                    
//----------------------------------------------------------------------------
class DisplayPatronHistory : public Command {
public:
  DisplayPatronHistory(Library *library);
  virtual ~DisplayPatronHistory();

  virtual void execute();
  virtual void parseFile(char type, istream& infile);
private:
  Patron *patron; // patron we are displaying the history of
};

#endif
