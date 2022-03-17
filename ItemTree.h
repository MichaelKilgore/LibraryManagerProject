#ifndef _ITEMTREE_H_
#define _ITEMTREE_H_

class Item;

//----------------------------------------------------------------------------
// class ItemTree
// used for storing Items in a tree or any concrete object that inherits
// from Item class.
//
//----------------------------------------------------------------------------
class ItemTree {
private:
  struct Node { 
		Item* item;                        // pointer to data object  
    Node* left;                            // left subtree pointer  
		Node* right;                           // right subtree pointer  
	}; 
	Node* root;

  void insertItemHelper(Node *&, Item *);
  Item* getItemHelper(Node *&, Item *);
  void displayHelper(Node *curr) const;
  void deleteItemsHelper(Node *& curr);
  public:
  // constructor
  ItemTree();
  // destructor
  ~ItemTree();

  void insertItem(Item *item); 
  Item * getItem(Item *item);
  void display() const;

};

#endif
