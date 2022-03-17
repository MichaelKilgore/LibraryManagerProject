#ifndef _ITEMFACTORY_H_
#define _ITEMFACTORY_H_

#include "Item.h"

//----------------------------------------------------------------------------
// class ItemFactory
// used for creating items that are stored in the library .
//                    
//----------------------------------------------------------------------------
class ItemFactory {
public:
  // constructor
  ItemFactory();
  // destructor
  ~ItemFactory();

  void registerItem(char itemType, Item* item);
  Item* createItem(char itemType, istream& input);
  Item* createItemForSearch(char itemType, istream& input);
  bool isItemRegistered(char itemType);
private:
  Item* items[26]; // hash map for storing different item types.

};

#endif
