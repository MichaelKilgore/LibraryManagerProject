/////////////////////////////  Periodical.cpp file  /////////////////////////

#include "Periodical.h"

//----------------------------------------------------------------------------
// constructor
Periodical::Periodical(int month, char format, string title, int year, 
                  int copies) : Book(format, title, year, copies) {
  this->month = month;
}

//----------------------------------------------------------------------------
// destructor
Periodical::~Periodical() {

}

//----------------------------------------------------------------------------
// getMonth
int Periodical::getMonth() const {
  return this->month;
}

//----------------------------------------------------------------------------
// create
// creates and returns a pointer to a newly allocated periodical object.
Item* Periodical::create(istream& input) const {
  //Pirsig Robert, Zen & the Art of Motorcycle Maint, 1974 
  string title;
  int month, year;

  getline(input, title, ',');

  title.erase(0,1);

  input >> month;
  input >> year;

  return new Periodical(month, 'H', title, year, 1);
}

//----------------------------------------------------------------------------
// createForSearch
//
// creates and returns a pointer to a newly allocated periodical object
// created specifically for searching for an actual periodical book.
Item* Periodical::createForSearch(istream& input) const {
  //234 P H 1996 3 Communications of the ACM
  //author, title,
  int year, month;
  string title;

  input >> year;
  input >> month;


  getline(input, title, ',');

  title.erase(0,1);

  return new Periodical(month, 'H', title, year, 0);
}

//----------------------------------------------------------------------------
// displayFullDisplayIntro
// displays intro line for block of periodial books.
void Periodical::displayFullDisplayIntro() const {
  cout << "PERIODICAL BOOKS" << endl; 
  cout << setw(6) << left << "AVAIL";
  cout << setw(38) << left << "TITLE"; 
  cout << setw(6) << left << "YEAR"; 
  cout << "MONTH" << endl;
}

//----------------------------------------------------------------------------
// display
// displays periodical book information
void Periodical::display() const {
  string tempTitle = this->title;

  if (this->title.length() > 36)
    tempTitle = this->title.substr(0, 36);

  cout << setw(6) << left << this->available;
  cout << setw(38) << left << tempTitle; 
  cout << setw(6) << left << this->year;
  cout << this->month << endl;
}

//----------------------------------------------------------------------------
// historyDisplay
// displays book in a format for displaying a patrons history.
void Periodical::historyDisplay() const {
  string tempTitle = this->title;
  if (this->title.length() > 36)
    tempTitle = this->title.substr(0, 36);

  cout << setw(4) << left << this->month << setw(8) <<
       this->year << setw(8) << left << tempTitle << endl;
}

//----------------------------------------------------------------------------
// operator==
// checks if two periodical books are equal by comparing year, then month
// then title.
bool Periodical::operator==(const Item & item) const {
  const Periodical& periodicalBook = static_cast<const Periodical&>(item); 
  if (this->year == periodicalBook.getYear() && 
      this->month == periodicalBook.getMonth() && 
      this->title == periodicalBook.getTitle())
    return true;
  return false;
}

//----------------------------------------------------------------------------
// operator==
// checks if two periodical books are not equal by comparing year, then month
// then title.
bool Periodical::operator!=(const Item & item) const {
  const Periodical& periodicalBook = static_cast<const Periodical&>(item);
  if (!(*this == periodicalBook))
    return true;
  return false;
}

//----------------------------------------------------------------------------
// operator<
// checks if this < item comparing in order from year, then month
// then title.
bool Periodical::operator<(const Item & item) const {
  const Periodical& periodicalBook = static_cast<const Periodical&>(item);
  if (this->year < periodicalBook.getYear())
    return true;
  else if (this->year == periodicalBook.getYear() && 
           this->month < periodicalBook.getMonth())
    return true;
  else if (this->year == periodicalBook.getYear() &&
           this->month == periodicalBook.getMonth() &&
           this->title < periodicalBook.getTitle())
    return true;
  return false;
}

//----------------------------------------------------------------------------
// operator>
// checks if this > item comparing in order from year, then month
// then title.
bool Periodical::operator>(const Item & item) const {
  const Periodical& periodicalBook = static_cast<const Periodical&>(item);
  if (!(*this < periodicalBook) && *this != periodicalBook)
    return true;
  return false;
}

//----------------------------------------------------------------------------
// operator<=
// checks if this <= item comparing in order from year, then month
// then title.
bool Periodical::operator<=(const Item & item) const {
  const Periodical& periodicalBook = static_cast<const Periodical&>(item);
  if (!(*this > periodicalBook))
    return true;
  return false;
}

//----------------------------------------------------------------------------
// operator>=
// checks if this >= item comparing in order from year, then month
// then title.
bool Periodical::operator>=(const Item & item) const {
  const Periodical& periodicalBook = static_cast<const Periodical&>(item);
  if (!(*this < periodicalBook))
    return true;
  return false;
}



