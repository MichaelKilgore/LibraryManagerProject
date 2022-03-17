#ifndef _BOOK_H_
#define _BOOK_H_

#include "Item.h"

//----------------------------------------------------------------------------
// class Book
// Abstract Book Class stores general book information and is
// meant to be inherited.
//                    
// Implementation and assumptions:
//    -- The Book class is made to be inherited by different types of
//       books. Provides a general layout for all book classes currently
//       made and also provides a general layou for future book
//       classes to be made.
//
//----------------------------------------------------------------------------
class Book : public Item {
public:
  // constructor
  Book(char, string, int, int);
  // destructor
  virtual ~Book();

  //getters
  char getFormat() const;
  virtual string getTitle() const;
  int getYear() const;

  virtual Item* create(istream &) const = 0;
  virtual Item* createForSearch(istream &) const = 0;
  virtual void displayFullDisplayIntro() const = 0;
  virtual void display() const = 0;
  virtual void historyDisplay() const = 0;
  virtual void displayTitle() const;

  // boolean comparison operators
  virtual bool operator==(const Item &) const = 0;   
	virtual bool operator!=(const Item &) const = 0;   
  virtual bool operator<(const Item &) const = 0;
  virtual bool operator>(const Item &) const = 0;
  virtual bool operator<=(const Item &) const = 0;
  virtual bool operator>=(const Item &) const = 0;

protected:
  char format; // book format
  string title; // book title
  int year; // book year it was released
};

#endif
