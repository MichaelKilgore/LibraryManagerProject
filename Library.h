#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include <fstream>

#include "Fiction.h"
#include "Children.h"
#include "Periodical.h"

#include "CheckoutItem.h"
#include "ReturnItem.h"
#include "DisplayLibrary.h"
#include "DisplayPatronHistory.h"

#include "CheckoutHistory.h"
#include "ReturnHistory.h"

#include "ItemFactory.h"
#include "HistoryFactory.h"
#include "CommandFactory.h"

#include "PatronManager.h"
#include "Command.h"
#include "ItemTree.h"


//----------------------------------------------------------------------------
// class Library
// Library class stores patrons, and items, and performs checkouts, returns,
// and displays.
//----------------------------------------------------------------------------
class Library {
public:
  // constructor
  Library();
  // destructor
  ~Library();
  
  void simulateInteractions();
  
  ItemTree** getItemMap();
  PatronManager* getPatronManager();
  HistoryFactory* getHistoryFactory(); 
  ItemFactory* getItemFactory();

private:
  HistoryFactory historyFactory; // used for creating history objects
  ItemTree* itemMap[26]; // a list of pointers to ItemTree objects
  PatronManager pManager; // Patron Manager

  ItemFactory itemFactory; // creates item and returns pointer to new item

  CommandFactory commandFactory; // used for creating commands


  void loadInBooks(istream& infile);
  void loadInPatrons(istream& infile);
};

#endif
