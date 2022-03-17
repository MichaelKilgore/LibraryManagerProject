///////////////////////////  Children.cpp file  /////////////////////////////

#include "Children.h"

//----------------------------------------------------------------------------
// constructor
Children::Children(string author, char format, string title, 
                    int year, int copies) 
                    : Book(format, title, year, copies) {
  this->author = author;
}

//----------------------------------------------------------------------------
// destructor
Children::~Children() {

}

//----------------------------------------------------------------------------
// getAuthor
string Children::getAuthor() const {
  return this->author;
}

//----------------------------------------------------------------------------
// create
// creates and returns a pointer to a newly created item.
//
// assumption: reading from file formatted like the book data file.
Item* Children::create(istream& input) const {
  //Pirsig Robert, Zen & the Art of Motorcycle Maint, 1974 
  string author, title;
  int year;

  getline(input, author, ',');
  getline(input, title, ',');
  author.erase(0,1);
  title.erase(0,1);

  input >> year;

  return new Children(author, 'H', title, year, 5);
}

//----------------------------------------------------------------------------
// createForSearch
// creates a Children object that can be used specifically for 
// searching for the actual object stored in an ItemTree.
Item* Children::createForSearch(istream& input) const {
  //author, title,
  string author, title;

  getline(input, title, ',');
  getline(input, author, ',');

  author.erase(0,1);
  title.erase(0,1);

  return new Children(author, 'H', title, 0, 0);

}

//----------------------------------------------------------------------------
// displayFullDisplayIntro()
// displays the first line for a block of children books.
void Children::displayFullDisplayIntro() const {
  cout << "CHILDREN BOOKS" << endl;
  cout << setw(6) << left << "AVAIL";
  cout << setw(24) << left << "AUTHOR"; 
  cout << setw(38) << left << "TITLE"; 
  cout << "YEAR" << endl;
}

//----------------------------------------------------------------------------
// display
// displays a single children book.
void Children::display() const {
  string tempAuthor = this->author;
  string tempTitle = this->title;
  if (this->author.length() > 22)
    tempAuthor = this->author.substr(0, 22);

  if (this->title.length() > 36)
    tempTitle = this->title.substr(0, 36);

  cout << setw(6) << left << this->available;
  cout << setw(24) << left << tempAuthor; 
  cout << setw(38) << left << tempTitle; 
  cout << this->year << endl; 
}

//----------------------------------------------------------------------------
// display book formatted for a history display.
void Children::historyDisplay() const {
  string tempAuthor = this->author;
  string tempTitle = this->title;
  if (this->author.length() > 22)
    tempAuthor = this->author.substr(0, 22);

  if (this->title.length() > 36)
    tempTitle = this->title.substr(0, 36);

  cout << setw(38) << left << tempTitle << setw(24) 
       << left << tempAuthor << this->year << endl;
}

//----------------------------------------------------------------------------
// operator==
// checks if two children books have the same title and same author
bool Children::operator==(const Item & item) const {
  const Children& childrenBook = static_cast<const Children&>(item);
  if (this->title == childrenBook.getTitle() 
        && this->author == childrenBook.getAuthor())
    return true;
  return false;
}

//----------------------------------------------------------------------------
// operator!=
// checks if the two children books do not have both the same title and
// same author
bool Children::operator!=(const Item & item) const {
  const Children& childrenBook = static_cast<const Children&>(item);
  if (!(*this == childrenBook))
    return true;
  return false;
}

//----------------------------------------------------------------------------
// operator<
// checks if one this is less than item based on title then author
bool Children::operator<(const Item & item) const {
  const Children& childrenBook = static_cast<const Children&>(item);
  if (this->title < childrenBook.getTitle())
    return true;
  else if (this->title == childrenBook.getTitle() 
            && this->author == childrenBook.getAuthor())
    return true;
  return false;
}

//----------------------------------------------------------------------------
// operator>
// checks if this is greater than item based on title then author
bool Children::operator>(const Item & item) const {
  const Children& childrenBook = static_cast<const Children&>(item);
  if (this->title > childrenBook.getTitle())
    return true;
  else if (this->title == childrenBook.getTitle() 
            && this->author > childrenBook.getAuthor())
    return true;
  return false;
}

//----------------------------------------------------------------------------
// operator<=
// checks if this is less than or equal to item based on title then author
bool Children::operator<=(const Item & item) const {
  const Children& childrenBook = static_cast<const Children&>(item);
  if (*this < childrenBook || *this == childrenBook) 
    return true;
  return false;
}

//----------------------------------------------------------------------------
// operator>=
// checks if this is greater than or equal to item based on title then author
bool Children::operator>=(const Item & item) const {
  const Children& childrenBook = static_cast<const Children&>(item);
  if (*this > childrenBook || *this == childrenBook)
    return true;
  return false;
}









