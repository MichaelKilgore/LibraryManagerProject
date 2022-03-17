/////////////////////  DisplayLibrary.cpp file  /////////////////////////////

#include "DisplayLibrary.h"
#include "Library.h"

//----------------------------------------------------------------------------
// constructor
DisplayLibrary::DisplayLibrary(Library *library) : Command(library) {
  this->itemMap = this->library->getItemMap();
}


//----------------------------------------------------------------------------
// destructor
DisplayLibrary::~DisplayLibrary() {
  this->itemMap = NULL;
}

//----------------------------------------------------------------------------
// execute (display library)
// calls display on every ItemTree passed from Library class
void DisplayLibrary::execute() {
  // loop through every itemtree.
  for (int i=0; i<26; i++) {
    // if ItemMap exists means it does not == NULL in which
    // case we want to call display on the ItemTree.
    if (this->itemMap[i] != NULL) {
      this->itemMap[i]->display();
      cout << endl;
    }
  }
}

//----------------------------------------------------------------------------
// parseFile
// DisplayLibrary doesn't need to actually parse the file at all
// because it only reads in one character 'D' which has already
// been read in.
void DisplayLibrary::parseFile(char type, istream& infile) {
  
}






