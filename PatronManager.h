#ifndef _PATRONMANAGER_H_
#define _PATRONMANAGER_H_

#include <iostream>
#include <unordered_map>

using namespace std;

class Patron;

//----------------------------------------------------------------------------
// class PatronManager
// manages patrons, and allows inserting and getting Patrons.
//                    
//----------------------------------------------------------------------------
class PatronManager {
public:
  // constructor
  PatronManager();  
  // destructor
  ~PatronManager();

  Patron * getPatron(int);
  void insertPatron(istream&);
private:
  unordered_map<int, Patron*> patronMap;
};

#endif
