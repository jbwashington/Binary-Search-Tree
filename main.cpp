#include <cstdlib>
#include <iostream>
#include <fstream>

#include "tree.h"

/* TODO: open, read, and select data fields to print */

int main()
{
  // Create tree
  BinaryTree Tree;
  Tree.ReadFile("QB.txt");

  /* // Test binary tree insertion */
  /* const int MAX = 10; */

  /* for (int Count = 0; Count < MAX; Count++) */
  /* { */
  /*   int Value = rand() % MAX; */
  /*   if (Tree.Insert(Value)) */
  /*     std::cout << "Insert " << Value << " ok\n"; */
  /*   else */
  /*     std::cout << "Insert " << Value << " failed\n"; */
  /*   Tree.Print(); */
  /* } */

  /* // Test binary tree search */
  /* for (int Count = 0; Count < MAX; Count++) */
  /* { */
  /*   int Value = rand() % MAX; */
  /*   if (Tree.Search(Value)) */
  /*     std::cout << "Search " << Value << " found\n"; */
  /*   else */
  /*     std::cout << "Search " << Value << " not found\n"; */
  /* } */

  /* // Test binary tree deletion */
  /* for (int Count = 0; Count < MAX; Count++) */
  /* { */
  /*   int Value = rand() % MAX; */
  /*   if (Tree.Delete(Value)) */
  /*     std::cout << "Delete " << Value << " ok\n"; */
  /*   else */
  /*     std::cout << "Delete " << Value << " failed\n"; */
  /*   Tree.Print(); */
  /* } */
  return 0;
}
