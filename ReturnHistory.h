#ifndef _RETURN_HISTORY_H_
#define _RETURN_HISTORY_H_

#include "History.h"

//----------------------------------------------------------------------------
// class ReturnHistory
// A ReturnHistory inherits from the History Object and represents a 
// Return log. This class basically keeps track of a single return
// performed by a Patron.
//                    
//----------------------------------------------------------------------------
class ReturnHistory : public History {
public:
  ReturnHistory(Item*itemPtr);
  ~ReturnHistory();

  virtual void display() const;

  virtual History* create(Item*itemPtr) const;
  
  virtual string className() const;
private:

};

#endif
