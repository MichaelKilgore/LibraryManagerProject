/////////////////////////////  History.cpp file  /////////////////////////////

#include "History.h"

//----------------------------------------------------------------------------
// constructor
History::History(Item*itemPtr) {
  this->item = itemPtr;
}

//----------------------------------------------------------------------------
// destructor
History::~History() {
    
}

Item* History::itemPointer() const {
  return this->item;
}


