/////////////////////////////  Library.cpp file  /////////////////////////////

#include "Library.h"

//----------------------------------------------------------------------------
// constructor
// sets ItemMap vals all to null,
// then registers 3 items in the factory,
// finally Library loads in all the book and patron data.
Library::Library() {
  //Set ItemMap array vals to null
  for (int i=0; i<26; i++) {
    itemMap[i] = NULL;
  }

  // Register children, fiction, and periodical 
  this->itemFactory.registerItem('C', new Children("", 'H', "", 0, 0));
  itemMap['C'%26] = new ItemTree;
  this->itemFactory.registerItem('F', new Fiction("", 'H', "", 0, 0));
  itemMap['F'%26] = new ItemTree;
  this->itemFactory.registerItem('P', new Periodical(0, 'H', "", 0, 0));
  itemMap['P'%26] = new ItemTree;

  // Register all the commands the library is using
  this->commandFactory.registerCommand('C', new CheckoutItem(this));
  this->commandFactory.registerCommand('R', new ReturnItem(this));
  this->commandFactory.registerCommand('D', new DisplayLibrary(this));
  this->commandFactory.registerCommand('H', new DisplayPatronHistory(this));

  // Register all the history types the library is using
  this->historyFactory.registerItem('C', new CheckoutHistory(NULL));
  this->historyFactory.registerItem('R', new ReturnHistory(NULL));

  //laod in all the books
  ifstream infile("data4books.txt"); 
  this->loadInBooks(infile);
  
  //load in all the patrons
  ifstream infile2("data4patrons.txt");
  this->loadInPatrons(infile2);
}

//----------------------------------------------------------------------------
// destructor
// removes the 3 itemmaps that were created in the constructor
Library::~Library() { 
  //deallocate all ItemTrees maybe 
  delete itemMap['C'%26];
  delete itemMap['F'%26];
  delete itemMap['P'%26];
}

//----------------------------------------------------------------------------
// simulateInteractions
// basically this function reads through the data4commands file and simulates
// commands happening.
void Library::simulateInteractions() {
  //execute commands in order 
  ifstream infile("data4commands.txt");
  string foo;

  //read through the file while it exists.
  while(infile.good()) {
    char action;  
    infile >> action;

    if (infile.eof())
      return;

    if (commandFactory.isItemRegistered(action)) {
      Command* command = commandFactory.getCommand(action);
      command->parseFile(action, infile);
      commandFactory.execute(action, this);
    } else { //ERROR
      cout << "ERROR: \'" << action << "\' is not a valid command." << endl;
    }

    getline(infile, foo);
  }
}

ItemTree** Library::getItemMap() {
  return this->itemMap;
}

PatronManager* Library::getPatronManager() {
  return &this->pManager;
}

HistoryFactory* Library::getHistoryFactory() {
  return &this->historyFactory;
}

ItemFactory* Library::getItemFactory() {
  return &this->itemFactory;
}

//----------------------------------------------------------------------------
// loadInBooks
// loads in all the books from the books file and stores all the books
// in the Library.
void Library::loadInBooks(istream& infile) {
  while(!infile.eof()) { 
    char book_type;
    string foo;
    infile >> book_type;

    if (infile.eof()) return;      // stop reading if no more data

    // check if the item is registered to see if our 
    // factory will be able to create it.
    if (!this->itemFactory.isItemRegistered(book_type)) {
      cout << "ERROR: " << book_type << " is not a valid item type." << endl;
      getline(infile, foo);
      continue;
    }

    // create item
    Item* newItem = this->itemFactory.createItem(book_type, infile);

    // insert it into ItemMap
    itemMap[book_type%26]->insertItem(newItem);
  }
}

//----------------------------------------------------------------------------
// laodInPatrons
// inserts all the patrons into the pManager.
void Library::loadInPatrons(istream& infile) {
  while(infile.good()) {
    this->pManager.insertPatron(infile);     
  } 
}



