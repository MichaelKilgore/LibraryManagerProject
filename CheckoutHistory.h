#ifndef _CHECKOUT_HISTORY_H_
#define _CHECKOUT_HISTORY_H_

#include "History.h"

//----------------------------------------------------------------------------
// class CheckoutHistory
// A CheckoutHistory inherits from the History Object and represents a 
// Checkout log. This class basically keeps track of a single checkout
// performed by a Patron.
//                    
//----------------------------------------------------------------------------
class CheckoutHistory : public History {
  public:  
    CheckoutHistory(Item*itemPtr);

    virtual ~CheckoutHistory();

    virtual void display() const;

    virtual History* create(Item*itemPtr) const;

    virtual string className() const;
  private:

};

#endif
