////////////////////// CommandFactory.cpp file  /////////////////////////////

#include "CommandFactory.h"
#include "Library.h"

//----------------------------------------------------------------------------
// constructor
CommandFactory::CommandFactory() {
  for (int i=0; i<26; i++)
    commands[i] = NULL;
}

//----------------------------------------------------------------------------
// destructor
CommandFactory::~CommandFactory() {
  for (int i=0; i<26; i++) {
    if (commands[i] != NULL)
      delete commands[i];
  }
}

//----------------------------------------------------------------------------
// registerCommand
// registers a new command in the commandFactory
void CommandFactory::registerCommand(char commandType,  Command *command) { 
  commands[commandType%26] = command;
}

//----------------------------------------------------------------------------
// isItemRegistered
// checks if command is registered.
bool CommandFactory::isItemRegistered(char commandType) {
  if (commands[commandType%26] != NULL)
    return true;
  return false;
}

//----------------------------------------------------------------------------
// getCommand
// returns command based on commandType given.
Command* CommandFactory::getCommand(char commandType) {
  return commands[commandType%26];
}

//----------------------------------------------------------------------------
// execute
// execute a command.
void CommandFactory::execute(char commandType, Library *library) {
  commands[commandType%26]->execute(); 
}







