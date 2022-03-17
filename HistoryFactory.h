#ifndef _HISTORY_FACTORY_H_
#define _HISTORY_FACTORY_H_

#include "History.h"
#include "Item.h"

//----------------------------------------------------------------------------
// class HistoryFactory
// A HistoryFactory creates History objects.
//                    
//----------------------------------------------------------------------------
class HistoryFactory {
public:
  // constructor
  HistoryFactory();
  // destructor
  ~HistoryFactory();

  void registerItem(char action, History* item);
  History* createItem(char action, Item*itemPtr);
  bool isItemRegistered(char action);
private:
  History* items[26]; //stores all history objects that can be created
};

#endif
