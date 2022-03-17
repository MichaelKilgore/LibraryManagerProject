#ifndef _HISTORY_H_
#define _HISTORY_H_

#include "Item.h"
//----------------------------------------------------------------------------
// class History
// A history object is used to store information about an action that a 
// patron performed.
//                    
// Implementation and assumptions:
//      -- History objects are typically stored by patrons to keep track
//         of actions that a user has performed.
//
//----------------------------------------------------------------------------
class History {
public:
  // constructor
  History(Item*item=NULL);
  // destructor
  virtual ~History();

  // displays the history object.
  virtual void display() const = 0;  
  virtual History* create(Item*itemPtr) const = 0;
  virtual string className() const = 0;
  Item* itemPointer() const;
protected:
  Item *item; //pointer to book data
};

#endif
