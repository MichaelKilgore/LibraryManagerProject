//////////////////////// PatronManager.cpp file  /////////////////////////////

#include "Patron.h"
#include "PatronManager.h"

//----------------------------------------------------------------------------
// constructor
// creates a default patron that is returned when a patron doesn't exist.
PatronManager::PatronManager() {
  patronMap[-1] = new Patron(-1, "", "");
}

//----------------------------------------------------------------------------
// destructor
// deletes all the patrons stored in hashmap stl
PatronManager::~PatronManager() {
  //traverse through every unordered_map item and delete allocated mem

  for (unordered_map<int, Patron*>::iterator it = this->patronMap.begin(); 
        it != this->patronMap.end(); ++it ) {
    if (it->second) {
      delete it->second;
    }
    it->second = NULL;
  }
}

//----------------------------------------------------------------------------
// getPatron
// returns patron if it exists and returns the default patron created in 
// constructor if the patron was not found as well as displays an error
// message.
Patron* PatronManager::getPatron(int id) {
  if (!patronMap.count(id)) {
    cout << "ERROR: there is no patron with ID " << id << "." << endl;
    return patronMap[-1];
  }

  return patronMap[id];
}

//----------------------------------------------------------------------------
// insertPatron
// reads from patron data file and creates and inserts the patron into
// the patronMap
void PatronManager::insertPatron(istream& infile) {
  int id;  
  string firstName, lastName;

  infile >> id;

  if (!(infile.good())) return;      // stop reading if no more data

  getline(infile, lastName, ' ');

  getline(infile, lastName, ' ');

  getline(infile, firstName);

  patronMap[id] = new Patron(id, firstName, lastName);

}


