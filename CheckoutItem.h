#ifndef _CHECKOUT_ITEM_H_
#define _CHECKOUT_ITEM_H_

#include "Command.h"
class Library;
class ItemTree;
class Patron;
class ItemFactory;
class PatronManager;
class Item;

//----------------------------------------------------------------------------
// class CheckoutItem
// inherits from Command this Command class performs checkouts of items
//                    
//----------------------------------------------------------------------------
class CheckoutItem : public Command {
public:
  CheckoutItem(Library* library);
  virtual ~CheckoutItem();

  virtual void execute();
  virtual void parseFile(char type, istream& infile);
private:
  Patron *patron; // patron that is checking out an item
  ItemTree *tree; // tree of items he is checking out from
  Item *item; // the item we are using to search for the actual item.
};

#endif
