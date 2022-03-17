#ifndef _PERIODICAL_H_
#define _PERIODICAL_H_

#include "Book.h"

//----------------------------------------------------------------------------
// class Periodical
// Inheriting from book class Periodical is a type of book.
//                    
// Implementation and assumptions:
//    -- used as an item for storing in ItemTree.
//
//----------------------------------------------------------------------------
class Periodical : public Book {
public:
  // constructor
  Periodical(int month, char format, string title, int year, int copies);
  // destructor
  virtual ~Periodical();

  // getter
  int getMonth() const;
  
  virtual Item* create(istream&) const;
  virtual Item* createForSearch(istream &) const;
  virtual void displayFullDisplayIntro() const;
  virtual void display() const;
  virtual void historyDisplay() const;

  // boolean comparison operators
  virtual bool operator==(const Item &) const;   
	virtual bool operator!=(const Item &) const;   
  virtual bool operator<(const Item &) const;
  virtual bool operator>(const Item &) const;
  virtual bool operator<=(const Item &) const;
  virtual bool operator>=(const Item &) const;

private:
  int month; // month the book was published.
};

#endif
