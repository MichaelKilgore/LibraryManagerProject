#ifndef _PATRON_H_
#define _PATRON_H_

#include <iostream>
#include <string>
#include <vector>
#include "History.h"
#include "HistoryFactory.h"
class Item;

using namespace std;
//----------------------------------------------------------------------------
// class Patron
// Patron object represents a user that interacts with the library to 
// checkout and remove books. It also keeps track of the actions a patron
// performs
//                    
//----------------------------------------------------------------------------
class Patron {
public:
  Patron(int, string, string);
  ~Patron(); // should delete only History objects! (NOT BOOKS)

  void displayHistory() const;  
  // append history to history vector
  void checkOutItem(Item *, HistoryFactory* factory);   
  // append history to history vector
  void returnItem(Item *, HistoryFactory* factory); 

  // getters
  string getFirstName() const;
  string getLastName() const;
  int getId() const;

  bool hasCheckedOutItem(Item* item);

private:
  int id; // user id
  string lastName;
  string firstName;

  vector<History*> history; // vector of history
};

#endif

