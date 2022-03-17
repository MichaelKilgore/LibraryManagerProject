////////////////////////// ReturnItem.cpp file  /////////////////////////////

#include "ReturnItem.h"
#include "Library.h"

//----------------------------------------------------------------------------
// constructor
ReturnItem::ReturnItem(Library* library) : Command(library) {
  this->patron = NULL;
  this->tree = NULL;
  this->item = NULL;
}

//----------------------------------------------------------------------------
// destructor
ReturnItem::~ReturnItem() {
  this->patron = NULL;
  this->tree = NULL;
  this->item = NULL;
}

//----------------------------------------------------------------------------
// execute (return item)
// retrieves a pointer to the item the patron is attempting to check out,
// it then ticks the availability of the item up by one because this patron
// is returning the item. Then calls the patron.returnItem function.
//
// edgecase: If an item attempting to be returned does not exist in
//           the library then tree->getItem will return NULL indicating
//           the book does not exist, then the program will print
//           an error message.
// edgecase: If an items availability is >= copies of the book owned 
//           by the library then an error is displayed and the patron
//           is not allowed to return the item, as we already have all our 
//           copies which suggests that the book is not ours.
void ReturnItem::execute() {
  //retrieve item from ItemTree.
  Item* actualItem = this->tree->getItem(this->item);

  // if item was not found print error
  if (actualItem == NULL) {
    cout << "ERROR: " << this->patron->getFirstName() 
         << " " << this->patron->getLastName() 
         << " tried to return \'" << this->item->getTitle() 
         << "\' - not found in catalog." << endl;
    if (this->item != NULL) {
      delete this->item;
      this->item = NULL;
    }
    return;
  }

  // if we already have all our copies then print error
  if (actualItem->getAvailable() >= actualItem->getCopies()) {
    cout << "ERROR: " << this->patron->getFirstName() 
         << " " << this->patron->getLastName() 
         << " tried to return \'" << item->getTitle() 
         << "\' - this item cannot be returned as we" 
         << " already have all of our copies." << endl;
    delete this->item;
    this->item = NULL;
    return;
  }

  // TODO: Before adjusting availability
  if (!this->patron->hasCheckedOutItem(actualItem)) {
    cout << "ERROR: " << this->patron->getFirstName()   
         << " " << this->patron->getLastName()
         << " tried to return \'" << item->getTitle()
         << "\' - this item has not been checked"
         << " out by this patron." << endl;
    delete this->item;
    this->item = NULL;
    return;
  }

  // tick availability of item up one.
  actualItem->setAvailable(actualItem->getAvailable()+1);

  // patron returns item
  // this should add to history and remove a book from stack of 
  // books in possession of patron.
  this->patron->returnItem(actualItem, 
          this->library->getHistoryFactory());

  delete this->item;
  this->item = NULL;
}

//----------------------------------------------------------------------------
// parseFile
// reads the rest of the line for a ReturnItem Command.
// then stores in needed information to perform an execute after the parse.
void ReturnItem::parseFile(char type, istream& infile) {

  int id; 
  infile >> id;
  char bookType;
  infile >> bookType;
  char format;
  infile >> format;

  // check if bookType exists.
  if (!library->getItemFactory()->isItemRegistered(bookType)) {
    cout << "ERROR: item type \'" << bookType 
         << "\' does not exist." << endl;
    return;
  } else if (format != 'H') {
    cout << "ERROR: book type \'" << format << "\' does not exist." << endl;
    return;
  }

  // create item for searching for the actual item in the execute
  Item* searchItem = library->getItemFactory()
                      ->createItemForSearch(bookType, infile);

  // store variables in this in order to perform execute.
  if (this->library->getPatronManager()->getPatron(id)->getId() != -1) {
    this->patron = this->library->getPatronManager()->getPatron(id);
    this->tree = this->library->getItemMap()[bookType%26];
    this->item = searchItem;
  }

}





