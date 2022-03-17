#ifndef _COMMAND_FACTORY_H_
#define _COMMAND_FACTORY_H_

#include "Command.h"
#include "Patron.h"
class Library;

//----------------------------------------------------------------------------
// class CommandFactory
// used for creating commands.
//                    
//----------------------------------------------------------------------------
class CommandFactory {
public:
  // constructor
  CommandFactory();
  // destructor
  ~CommandFactory();

  void registerCommand(char commandType, Command* command);
  bool isItemRegistered(char commandType);
  Command* getCommand(char commandType);
  void execute(char commandType, Library *library);
private:
  // stores all the possible commands that can be created
  Command* commands[26];
};

#endif
