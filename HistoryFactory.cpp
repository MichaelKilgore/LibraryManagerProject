/////////////////////// HistoryFactory.cpp file  /////////////////////////////

#include "HistoryFactory.h"
#include "History.h"
#include "Item.h"

//----------------------------------------------------------------------------
// constructor
HistoryFactory::HistoryFactory() {
  for (int i=0; i<26; i++)
    this->items[i] = NULL;
}

//----------------------------------------------------------------------------
// destructor
HistoryFactory::~HistoryFactory() {
 for (int i=0; i<26; i++) {
    if (this->items[i] != NULL)
      delete this->items[i];
  } 
}

//----------------------------------------------------------------------------
// registerItem
// registers a new type of history object in the HistoryFactory
// so that HistoryFactory can create objects like that history object.
void HistoryFactory::registerItem(char action, History* item) {
  this->items[action%26] = item;
}

//----------------------------------------------------------------------------
// createItem
// Creates a history object and returns it.
History* HistoryFactory::createItem(char action, Item*itemPtr) {
  return items[action%26]->create(itemPtr);
}

//----------------------------------------------------------------------------
// checks if a history object is registered in the History Factory.
bool HistoryFactory::isItemRegistered(char action) {
  if (items[action%26] != NULL)
    return true;
  return false;
}


