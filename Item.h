#ifndef _ITEM_H_
#define _ITEM_H_

#include <iostream>
#include <iomanip>

using namespace std;

//----------------------------------------------------------------------------
// class Item
// Item is an abstract class that is inheritted by concrete classes to be
// stored in ItemTrees
//                    
//----------------------------------------------------------------------------
class Item {
public:
  // constructor
  Item(int, int);
  // destructor
  virtual ~Item();

  // getters
  int getCopies();
  int getAvailable();
  // setters
  void setCopies(int numCopies);
  void setAvailable(int numAvailable);

  virtual Item* create(istream &) const = 0;
  virtual Item* createForSearch(istream &) const = 0;
  virtual void displayFullDisplayIntro() const = 0;
  virtual void display() const = 0;
  virtual void historyDisplay() const = 0;
  virtual string getTitle() const = 0;

  // boolean comparison operators
  virtual bool operator==(const Item &) const = 0;   
	virtual bool operator!=(const Item &) const = 0;   
  virtual bool operator<(const Item &) const = 0;
  virtual bool operator>(const Item &) const = 0;
  virtual bool operator<=(const Item &) const = 0;
  virtual bool operator>=(const Item &) const = 0;

protected:
  int copies;  
  int available;
};

#endif



