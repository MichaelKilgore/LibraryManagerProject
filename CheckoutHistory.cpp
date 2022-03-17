////////////////////// CheckOutHistory.cpp file  /////////////////////////////

#include "CheckoutHistory.h"

//----------------------------------------------------------------------------
// constructor
CheckoutHistory::CheckoutHistory(Item* itemPtr)
                  : History(itemPtr) {
}

//----------------------------------------------------------------------------
// destructor
CheckoutHistory::~CheckoutHistory() {
  
}


//----------------------------------------------------------------------------
// display
// displays a checkout history object.
void CheckoutHistory::display() const {
  cout << setw(12) << left << "  CheckOut";
  this->item->historyDisplay();
}

//----------------------------------------------------------------------------
// create
// creates and returns a new CheckoutHistory object.
History* CheckoutHistory::create(Item*itemPtr) const {
  return new CheckoutHistory(itemPtr);
}

//----------------------------------------------------------------------------
// returnClassName
string CheckoutHistory::className() const {
  return "CheckoutHistory";
}

