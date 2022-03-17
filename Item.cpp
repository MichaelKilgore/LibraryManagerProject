/////////////////////////////  Item.cpp file  /////////////////////////////

#include "Item.h"

//----------------------------------------------------------------------------
// constructor
Item::Item(int copies, int available) {
  this->copies = copies;
  this->available = available;
}

//----------------------------------------------------------------------------
// destructor
Item::~Item() {

}

//----------------------------------------------------------------------------
// getCopies
int Item::getCopies() {
  return this->copies;
}

//----------------------------------------------------------------------------
// getAvailable
int Item::getAvailable() {
  return this->available;
}

//----------------------------------------------------------------------------
// setCopies
void Item::setCopies(int numCopies) {
  this->copies = numCopies;
}

//----------------------------------------------------------------------------
// setAvailable
void Item::setAvailable(int numAvailable) {
  this->available = numAvailable;
}

