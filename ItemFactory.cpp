/////////////////////////  ItemFactory.cpp file  /////////////////////////////

#include "ItemFactory.h"

//----------------------------------------------------------------------------
// constructor
// initializes items array to all NULL
ItemFactory::ItemFactory() {
  for (int i=0; i<26; i++)
    items[i] = NULL;
}

//----------------------------------------------------------------------------
// destructor
// deallocates all the allocated memory for items
ItemFactory::~ItemFactory() {
  //deallocate all items pointed to in array
  for (int i=0; i<26; i++) {
    if (items[i] != NULL)
      delete items[i];
  }
}

//----------------------------------------------------------------------------
// registerItem
// registers an item to be created. Every item the factory can create must 
// be initially registered or when you attempt to create an item it won't be
// found.
void ItemFactory::registerItem(char itemType, Item *item) {
  items[itemType%26] = item;
}

//----------------------------------------------------------------------------
// createItem
// calls create on an item to create it which returns a pointer to the
// item.
Item * ItemFactory::createItem(char itemType, istream& input) {
  return items[itemType%26]->create(input);
}

//----------------------------------------------------------------------------
// createItemForSearch
// calls createForSearch on an item to create it which returns a pointer
// to the item.
//
// note: the way you read from the command file is slightly different
//       from the way you read from the creating an item file which is why
//       we need a different function that creates an item for searching for
//       an item.
Item * ItemFactory::createItemForSearch(char itemType, istream& input) {
  return items[itemType%26]->createForSearch(input);
}

//----------------------------------------------------------------------------
// isItemRegistered
// checks if an item is registered in the ItemFactory.
bool ItemFactory::isItemRegistered(char itemType) {
  if (items[itemType%26] != NULL)
    return true;
  return false;
}




