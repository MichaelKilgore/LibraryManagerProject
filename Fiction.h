#ifndef _FICTION_H_
#define _FICTION_H_

#include "Book.h"

//----------------------------------------------------------------------------
// class Fiction
// Inheriting from book class Fiction is a type of book.
//                    
// Implementation and assumptions:
//    -- used as a book for storing in ItemTree.
//
//----------------------------------------------------------------------------
class Fiction : public Book {
public:
  // constructor
  Fiction(string author, char format, string title, int year, int copies);
  // destructor
  virtual ~Fiction();

  // getter
  string getAuthor() const;

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
  string author;
};

#endif
