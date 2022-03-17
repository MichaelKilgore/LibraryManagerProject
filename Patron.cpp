/////////////////////////////  Patron.cpp file  /////////////////////////////

#include "Patron.h"
#include "Item.h"

//----------------------------------------------------------------------------
// constructor
Patron::Patron(int id, string lastName, string firstName) {
  this->id = id;
  this->lastName = lastName;
  this->firstName = firstName;
}

//----------------------------------------------------------------------------
// destructor
Patron::~Patron() {
 if (this->id != -1) {
    for (vector<History*>::const_iterator it = this->history.begin(); 
          it != this->history.end(); ++it) {
      delete (*it);
    } 
  }
}

//----------------------------------------------------------------------------
// displayHistory
// traverses history vector displaying all the history
void Patron::displayHistory() const {
  if (this->id != -1) {
    cout << this->id << "  " << this->lastName 
                     << ", " << this->firstName << ":" << endl;
    for (vector<History*>::const_iterator it = this->history.begin(); 
          it != this->history.end(); ++it) {
      (*it)->display();
    } 
  }
}

//----------------------------------------------------------------------------
// checkOutItem
// a history object is added to vector of items.
void Patron::checkOutItem(Item* item, HistoryFactory* factory) {
  history.push_back(factory->createItem('C', item));
}

//----------------------------------------------------------------------------
// returnItem
// adds to patron history
void Patron::returnItem(Item *item, HistoryFactory* factory) {
  history.push_back(factory->createItem('R', item));
}


//----------------------------------------------------------------------------
// getFirstName
string Patron::getFirstName() const {
  return this->firstName;
}

//----------------------------------------------------------------------------
// getLastName
string Patron::getLastName() const {
  return this->lastName;
}

//----------------------------------------------------------------------------
// getId
int Patron::getId() const {
  return this->id;
}

bool Patron::hasCheckedOutItem(Item* item) {
  int balance = 0;
  for (vector<History*>::const_iterator it = this->history.begin(); 
        it != this->history.end(); ++it) {
    if ((*it)->className() == "CheckoutHistory" && (*it)->itemPointer() == item) {
      balance += 1;
    } else if ((*it)->className() == "ReturnHistory" && (*it)->itemPointer() == item) {
      balance -= 1;
    }
  }
  if (balance >= 1)
    return true;
  return false;
}








