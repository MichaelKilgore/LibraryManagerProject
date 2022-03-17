///////////////////////  ReturnHistory.cpp file  /////////////////////////////

#include "ReturnHistory.h"

//----------------------------------------------------------------------------
// constructor
ReturnHistory::ReturnHistory(Item*itemPtr) 
                : History(itemPtr) {
}

//----------------------------------------------------------------------------
// destructor
ReturnHistory::~ReturnHistory() {
}

//----------------------------------------------------------------------------
// display
// displays the Return History
void ReturnHistory::display() const {
  cout << setw(12) << left << "  Return";
  this->item->historyDisplay();
}

//----------------------------------------------------------------------------
// create
// creates and returns a new history object
History* ReturnHistory::create(Item*itemPtr) const {
  return new ReturnHistory(itemPtr);
}

//----------------------------------------------------------------------------
// returnClassName
string ReturnHistory::className() const {
  return "ReturnHistory";
}





