/////////////////////////////  Fiction.cpp file  /////////////////////////////

#include "Fiction.h"

//----------------------------------------------------------------------------
// constructor
Fiction::Fiction(string author, char format, string title, int year, 
                 int copies) : Book(format, title, year, copies) {
  this->author = author;
}

//----------------------------------------------------------------------------
// destructor
Fiction::~Fiction() {

}

//----------------------------------------------------------------------------
// getAuthor
string Fiction::getAuthor() const {
  return this->author;
}

//----------------------------------------------------------------------------
// create
// creates a fiction object and returns it
Item* Fiction::create(istream& input) const {
  //Pirsig Robert, Zen & the Art of Motorcycle Maint, 1974 
  string author, title, foo;
  int year;

  getline(input, author, ',');
  getline(input, title, ',');

  author.erase(0,1);
  title.erase(0,1);

  input >> year;
  getline(input, foo);

  return new Fiction(author, 'H', title, year, 5);
}

//----------------------------------------------------------------------------
// createForSearch
// creates a Item specifically for searching for an actual item.
Item* Fiction::createForSearch(istream& input) const {
  //author, title,
  string author, title;

  getline(input, author, ',');
  getline(input, title, ',');

  author.erase(0,1);
  title.erase(0,1);

  // notice we only need the author and title stored
  // as this is what we search for fiction books on.
  return new Fiction(author, 'H', title, 0, 0); 
}

//----------------------------------------------------------------------------
// displayFullDisplayIntro
// displays the first line for block of fiction books.
void Fiction::displayFullDisplayIntro() const {
  cout << "FICTION BOOKS" << endl;
  cout << setw(6) << left << "AVAIL";
  cout << setw(24) << left << "AUTHOR"; 
  cout << setw(38) << left << "TITLE"; 
  cout << "YEAR" << endl;
}

//----------------------------------------------------------------------------
// display
// displays a Fuction Book
void Fiction::display() const {
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
// historyDisplay
// performs display formatted for displaying history
void Fiction::historyDisplay() const {
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
// checks if two fiction books have the same title and same author
bool Fiction::operator==(const Item & item) const {
  const Fiction& fictionBook = static_cast<const Fiction&>(item);
  if (this->author == fictionBook.getAuthor() && 
        this->title == fictionBook.getTitle()) 
    return true;
  return false;
}

//----------------------------------------------------------------------------
// operator!=
// checks if the two fiction books do not have both the same title and
// same author
bool Fiction::operator!=(const Item & item) const {
  const Fiction& fictionBook = static_cast<const Fiction&>(item);
  if (this->author != fictionBook.getAuthor() || 
        this->title != fictionBook.getTitle())
    return true;
  return false;
}

//----------------------------------------------------------------------------
// operator<
// checks if one this is less than item based on title then author
bool Fiction::operator<(const Item & item) const {
  const Fiction& fictionBook = static_cast<const Fiction&>(item);
  if (this->author < fictionBook.getAuthor())
    return true;
  else if (this->author == fictionBook.getAuthor() 
            && this->title < fictionBook.getTitle())
    return true;
  return false;
}

//----------------------------------------------------------------------------
// operator>
// checks if this is greater than item based on title then author
bool Fiction::operator>(const Item & item) const {
  const Fiction& fictionBook = static_cast<const Fiction&>(item);
  if (this->author > fictionBook.getAuthor())
    return true;
  else if (this->author == fictionBook.getAuthor() 
            && this->title > fictionBook.getTitle())
    return true;
  return true;
}

//----------------------------------------------------------------------------
// operator<=
// checks if this is less than or equal to item based on title then author
bool Fiction::operator<=(const Item & item) const {
  const Fiction& fictionBook = static_cast<const Fiction&>(item);
  if (*this < fictionBook || *this == fictionBook) 
    return true;
  return false;
}

//----------------------------------------------------------------------------
// operator>=
// checks if this is greater than or equal to item based on title then author
bool Fiction::operator>=(const Item & item) const {
  const Fiction& fictionBook = static_cast<const Fiction&>(item);
  if (*this > fictionBook || *this == fictionBook)
    return true;
  return false;
}














