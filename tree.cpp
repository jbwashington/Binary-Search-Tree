//-----------------------------------------------------------
//  Purpose:    Implementation of BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "tree.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BinaryTree::BinaryTree()
{
  Root = NULL;
}

//-----------------------------------------------------------
// Constructor function that reads tree from file.
//-----------------------------------------------------------
BinaryTree::BinaryTree(char *Name)
{
  Root = NULL;

  // Open input file
  std::ifstream din;
  din.open(Name);
  if (din.fail())
    std::cout << "Error: could not open input file\n";

  // Read the data
  int Value;
  din >> Value;
  while (!din.eof())
  {
    InsertHelper(Value, Root);
    din >> Value;
  }

  // Close the file
  din.close();
}

//-----------------------------------------------------------
// Copy constructor helper function.
//-----------------------------------------------------------
void BinaryTree::CopyHelper(Node * Tree1, Node * &Tree2)
{
  // Check terminating condition
  if (Tree1 == NULL)
    Tree2 = NULL;

  // Copy node and it's children
  else
  {
    Tree2 = new Node;
    Tree2->Value = Tree1->Value;
    CopyHelper(Tree1->Left, Tree2->Left);
    CopyHelper(Tree1->Right, Tree2->Right);
  }
}

//-----------------------------------------------------------
// Copy constructor.
//-----------------------------------------------------------
BinaryTree::BinaryTree(const BinaryTree & B)
{
  // Call tree copy function
  CopyHelper(B.Root, Root);
}

//-----------------------------------------------------------
// Destructor function helper function.
//-----------------------------------------------------------
void BinaryTree::DestroyHelper(Node * Tree)
{
  // Delete node and it's children
  if (Tree != NULL)
  {
    DestroyHelper(Tree->Left);
    DestroyHelper(Tree->Right);
    delete Tree;
  }
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BinaryTree::~BinaryTree()
{
  // Call tree destroy function
  DestroyHelper(Root);
}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(int Value, Node * Tree)
{
  // Data value not found 
  if (Tree == NULL)
    return false;

  // Data value found 
  else if (Tree->Value == Value)
    return true;

  // Recursively search for data value
  else if (Tree->Value > Value)
    return (SearchHelper(Value, Tree->Left));
  else if (Tree->Value < Value)
    return (SearchHelper(Value, Tree->Right));
  else
    return false;
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Search(int Value)
{
  // Call tree searching function
  return (SearchHelper(Value, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(int Value, Node * &Tree)
{
  // Insert data into the tree
  if (Tree == NULL)
  {
    Tree = new Node;
    Tree->Value = Value;
    Tree->Left = NULL;
    Tree->Right = NULL;
    return true;
  }

  // Recursively search for insertion position
  else if (Tree->Value > Value)
    return (InsertHelper(Value, Tree->Left));
  else 
    return (InsertHelper(Value, Tree->Right));
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(int Value)
{
  // Call tree insertion function
  return (InsertHelper(Value, Root));
}

//-----------------------------------------------------------
// Delete a single node from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::DeleteNode(Node * &Tree)
{
  Node *Temp = Tree;

  // Node has 0 children
  if ((Tree->Left == NULL) && (Tree->Right == NULL))
    Tree = NULL;

  // Node has 1 child
  else if (Tree->Left == NULL)
    Tree = Tree->Right;
  else if (Tree->Right == NULL)
    Tree = Tree->Left;


  // Node has 2 children
  else
  {
    // Find leftmost node in right subtree
    Node *Parent = Tree;
    Temp = Tree->Right;
    while (Temp->Left != NULL)
    {
      Parent = Temp;
      Temp = Parent->Left;
    }

    // Replace deleted data with leftmost value
    if (Parent == Tree)
      Parent->Right = Temp->Right;
    else
      Parent->Left = Temp->Right;
    Tree->Value = Temp->Value;
  }

  // Delete node
  delete Temp;
  return true;
}

//-----------------------------------------------------------
// Delete helper function.
//-----------------------------------------------------------
bool BinaryTree::DeleteHelper(int Value, Node * &Tree)
{
  // Data value not found
  if (Tree == NULL)
    return false;

  // Data value found and deleted
  else if (Tree->Value == Value)
    return (DeleteNode(Tree));

  // Recursively search for node to delete
  else if (Tree->Value > Value)
    return (DeleteHelper(Value, Tree->Left));
  else if (Tree->Value < Value)
    return (DeleteHelper(Value, Tree->Right));
  else
    return false;
}

//-----------------------------------------------------------
// Delete data from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Delete(int Value)
{
  // Call tree deletion function
  return (DeleteHelper(Value, Root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node * Tree)
{
  // Check terminating condition
  if (Tree != NULL)
  {
    // Print left subtree
    std::cout << "(";
    PrintHelper(Tree->Left);

    // Print node value
    std::cout << " " << Tree->Value << " ";

    // Print right subtree
    PrintHelper(Tree->Right);
    std::cout << ")";
  }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print()
{
  // Call tree printing function
  PrintHelper(Root);
  std::cout << std::endl;
}


/* --------------------------------- */
/* read contents of array from file  */
/* --------------------------------- */
bool BinaryTree::ReadFile(const std::string Filename)
{
  std::string line;
  std::ifstream infile (Filename.c_str());
  /* infile.open(Filename.c_str()); */
  if (infile.fail()) {
    std::cout << "couldn't open the file" << std::endl;
    return false;
  }
  if (infile.is_open()) {
    while (getline (infile,line)) {
      std::cout << line << std::endl;
    }
    infile.close();
  }
  // while not at the end of file, print out everything

  /* while (!infile.eof()) { */

  /* } */
  return true;
}
