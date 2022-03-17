/////////////////////////////  ItemTree.h file  /////////////////////////////

#include "ItemTree.h"
#include "Item.h"

//----------------------------------------------------------------------------
// constructor
ItemTree::ItemTree() {
  this->root = NULL;
}

//----------------------------------------------------------------------------
// destructor
// calls deleteItemsHelper
ItemTree::~ItemTree() {
  deleteItemsHelper(this->root);
}

//----------------------------------------------------------------------------
// insertItem
// calls insertItemHelper
void ItemTree::insertItem(Item *item) {
  this->insertItemHelper(this->root, item); 
}

//----------------------------------------------------------------------------
// insertItemHelper
// traverses tree until an empty spot is found and then inserts the item
// 
// assumptions:
//       -- the way in which items are stored is sorted based on the 
//          operators that are overloaded in the item you are storing
void ItemTree::insertItemHelper(Node *& curr, Item *item) {
  if (curr == NULL) {
    curr = new Node();
    curr->item = item;
    curr->right = NULL;
    curr->left = NULL;
    return;
  }

  if (*item < *(curr->item)) {
    this->insertItemHelper(curr->left, item);
  } else {
    this->insertItemHelper(curr->right, item);
  }
}

//----------------------------------------------------------------------------
// getItem
// calls getItemHelper
Item * ItemTree::getItem(Item *item) {
  return this->getItemHelper(this->root, item);
}

//----------------------------------------------------------------------------
// getItemHelper
// searches for item and returns it when found, and returns NULL if item was
// not found.
Item * ItemTree::getItemHelper(Node *& curr, Item *item) {
  if (curr == NULL)
    return NULL;
  if (*(curr->item) == *item)
    return curr->item; 

  if (*item < *(curr->item))
    return this->getItemHelper(curr->left, item);
  else
    return this->getItemHelper(curr->right, item);
  
  return NULL;
}

//----------------------------------------------------------------------------
// display
// displays the intro then calls the display helper.
void ItemTree::display() const {
  if (this->root != NULL && this->root->item != NULL)
    root->item->displayFullDisplayIntro();  
  displayHelper(this->root); 
}

//----------------------------------------------------------------------------
// displayHelper
// traverses tree displaying all items in order.
void ItemTree::displayHelper(Node *curr) const {
  if (curr == NULL)
    return; 

  displayHelper(curr->left);
  curr->item->display();
  displayHelper(curr->right);

}

//----------------------------------------------------------------------------
// deleteItemsHelper
// traverses the tree in post order deleting all the allocated memory.
void ItemTree::deleteItemsHelper(Node *& curr) {
  if (curr == NULL)
    return;

  this->deleteItemsHelper(curr->left);
  this->deleteItemsHelper(curr->right);

  delete curr->item;
  curr->item = NULL;
  delete curr;
  curr = NULL;
}







