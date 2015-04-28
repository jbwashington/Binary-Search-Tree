//-----------------------------------------------------------
//  Purpose:    Header file for the BinaryTree class.
//  Author:     John Gauch
//-----------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <fstream>

//-----------------------------------------------------------
// BinaryTree data node definition
//-----------------------------------------------------------
class Node
{
  public:
    int Value;
    Node *Left;
    Node *Right;
};

//-----------------------------------------------------------
// Define the BinaryTree class interface 
//-----------------------------------------------------------
class BinaryTree
{
  public:
    // Constructor functions
    BinaryTree();
    BinaryTree(char *Name);
    BinaryTree(const BinaryTree & tree);
    ~BinaryTree();

    // General binary tree operations
    bool Search(int Value);
    bool Insert(int Value);
    bool Delete(int Value);
    void Print();
    bool ReadFile(const std::string Filename);

    // Special operation for tree_sort
    void Extract(int data[], int low, int high);
    void ExtractHelper(int data[], int &index, Node * Tree);

  private:
    // Helper functions
    void CopyHelper(Node * Tree1, Node * &Tree2);
    void DestroyHelper(Node * Tree);
    bool SearchHelper(int Value, Node * Tree);
    bool InsertHelper(int Value, Node * &Tree);
    bool DeleteNode(Node * &Tree);
    bool DeleteHelper(int Value, Node * &Tree);
    void PrintHelper(Node * Tree);

    // Tree pointer
    Node *Root;
};
