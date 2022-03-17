////////////////////////  CheckoutItem.cpp file  /////////////////////////////

#include "CheckoutItem.h"
#include "Library.h"

//----------------------------------------------------------------------------
// constructor
CheckoutItem::CheckoutItem(Library* library) : Command(library) {
  this->patron = NULL;
  this->tree = NULL;
  this->item = NULL;
}

//----------------------------------------------------------------------------
// destructor
CheckoutItem::~CheckoutItem() {
  this->patron = NULL;
  this->tree = NULL;
  this->item = NULL;
}

//----------------------------------------------------------------------------
// execute (check out item)
// retrieves a pointer to the item the patron is attempting to check out,
// it then ticks the availability of the item down by one because this patron
// is checking out the item. Then calls the patron.checkOutItem function.
// 
// edgecase: If an item attempting to be checked out does not exist in
//           the library then tree->getItem will return NULL indicating
//           the book does not exist, then the program will print
//           an error message.
// edgecase: If an items availability is <= 0 then an error is displayed
//           and the patron is not allowed to checkout the item.
void CheckoutItem::execute() {
  if (this->item == NULL)
    return;

  Item *actualItem = this->tree->getItem(this->item);
  
  // if item was not found print error
  if (actualItem == NULL) {
    cout << "ERROR: " << this->patron->getFirstName() 
         << " " << this->patron->getLastName() 
         << " tried to check out \'" << this->item->getTitle() 
         << "\' - not found in catalog." << endl;
    if (this->item != NULL) {
      delete this->item;
      this->item = NULL;
    }
    return;
  }

  // if items availability == 0 print error
  if (actualItem->getAvailable() <= 0) {
    cout << "ERROR: " << this->patron->getFirstName() 
         << " " << this->patron->getLastName() 
         << " tried to check out \'" << this->item->getTitle() 
         << "\' - no copies are left to check out." << endl;
    delete this->item;
    this->item = NULL;
    return;
  } 
  
  // tick availability of item down one
  actualItem->setAvailable(actualItem->getAvailable()-1);
  // patron checks out the item
  //this should add to history and add to stack of books owned.
  this->patron->checkOutItem(actualItem, this->library->getHistoryFactory()); 

  // delete the item we just created for searching.
  delete this->item;
  this->item = NULL;
}

//----------------------------------------------------------------------------
// parseFile
// parses the file passed in to store needed variables to perform an
// execute on the stuff read in.
void CheckoutItem::parseFile(char type, istream& infile) {
  int id;
  infile >> id;
  char bookType;
  infile >> bookType;
  char format;
  infile >> format;

  if (!this->library->getItemFactory()->isItemRegistered(bookType)) {
    cout << "ERROR: item type \'" 
         << bookType << "\' does not exist." << endl;
    return;
  } else if (format != 'H') {
    cout << "ERROR: book type \'" << format << "\' does not exist." << endl;
    return;
  }


  Item* searchItem = this->library->getItemFactory()
                       ->createItemForSearch(bookType, infile);

  if (this->library->getPatronManager()->getPatron(id)->getId() != -1) {
    this->patron = this->library->getPatronManager()->getPatron(id);
    this->tree = this->library->getItemMap()[bookType%26];
    this->item = searchItem;
  } else {
    delete searchItem;
    searchItem = NULL;
  }
     
}






