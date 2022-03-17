#ifndef _RETURN_ITEM_H_
#define _RETURN_ITEM_H_

#include "Command.h"

class Library;
class ItemTree;
class Patron;
class ItemFactory;
class PatronManager;
class Item;

//----------------------------------------------------------------------------
// class ReturnItem
// A ReturnItem class inherits from Command class and performs a return
// after calling parseFile. You call execute to execute the return.
//                    
//----------------------------------------------------------------------------
class ReturnItem : public Command {
public:
  ReturnItem(Library* library);
  virtual ~ReturnItem();

  virtual void execute();
  virtual void parseFile(char type, istream& infile);
private:
  Patron *patron; // patron performing the return
  ItemTree *tree; // tree in which the item being returned is found
  Item *item; // item we are using to search for the item being returned.
};

#endif
