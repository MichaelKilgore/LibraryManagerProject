#ifndef _DISPLAY_LIBRARY_H_
#define _DISPLAY_LIBRARY_H_

#include "Command.h"
class ItemTree;
class Patron;
class ItemFactory;
class Library;
class PatronManager;

//----------------------------------------------------------------------------
// class DisplayLibrary
// Inheriting from the command class this class is a command used
// for displaying the contents of a library
//                    
// Implementation and assumptions:
//    -- Made to be created once. and acted upon multiple times.
//
//    -- all this really does is holds a pointer to all the items stored
//       and displays them when execute is called.
//
//----------------------------------------------------------------------------
class DisplayLibrary : public Command {
public:
  // constructor
  DisplayLibrary(Library *library);
  // destructor
  virtual ~DisplayLibrary();

  virtual void execute(); // actually performs the display
  virtual void parseFile(char type, istream& infile);
private:
  ItemTree ** itemMap; //stores a pointer to map of items for simplicity
};

#endif
