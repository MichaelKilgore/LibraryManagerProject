#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <iostream>

class Library;
class PatronManager;
class ItemFactory;
class ItemTree;
class Patron;

using namespace std;

//----------------------------------------------------------------------------
// class Command
// Command class performs actions that the Library class calls
//                    
// assumptions: This class is made to be used exclusively with the Library
//              class
//         
//----------------------------------------------------------------------------
class Command {
public:
  Command(Library*library);
  virtual ~Command();

  virtual void execute() = 0;
  virtual void parseFile(char type, istream& infile) = 0;
protected:
  Library*library;// store pointer to library to act on its member
};

#endif



