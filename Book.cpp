/////////////////////////////  book.cpp file  /////////////////////////////

#include "Book.h"

//---------------------------------------------------------------------------
// constructor
Book::Book(char format, string title, int year, int copies) 
            : Item(copies, copies) {
  this->format = format;
  this->title = title;
  this->year = year;
}

//---------------------------------------------------------------------------
// destructor
Book::~Book() {

}

//---------------------------------------------------------------------------
// getFormat
// returns format
char Book::getFormat() const {
  return this->format;
}

//---------------------------------------------------------------------------
// getTitle
// returns title
string Book::getTitle() const {
  return this->title;
}

//---------------------------------------------------------------------------
// getYear
// returns year
int Book::getYear() const {
  return this->year;
}

//---------------------------------------------------------------------------
// displayTitle
// couts the title to screen
void Book::displayTitle() const {
  cout << this->title;
}









