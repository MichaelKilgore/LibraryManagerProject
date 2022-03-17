#ifndef _CHILDREN_H_
#define _CHILDREN_H_

#include "Book.h"

//----------------------------------------------------------------------------
// class Children
// Inheriting from book class Children is a type of book.
//                    
// Implementation and assumptions:
//    -- used as a book for storing in ItemTree.
//
//----------------------------------------------------------------------------
class Children : public Book {
public:
  // constructor
  Children(string author, char format, string title, int year, int copies);  
  // destructor
  virtual ~Children();

  //getter
  string getAuthor() const; 

  virtual Item* create(istream&) const;
  virtual Item* createForSearch(istream& input) const;
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
  string author; // author of book.
};

#endif
