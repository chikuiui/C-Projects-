 /* -> so that this header file only included once in a compilation unit.
    -> ensures that the contents of the header file are only included once per translation unit.*/
#pragma once

# include <iostream>
# include <vector>
# include <fstream>
# include <string>
using namespace std;



class BST_Node 
{

public:
	BST_Node * left;
	BST_Node * right;
	string name;
	string adress;
	int account_number;
	int password;
	int balance;

	BST_Node();
	BST_Node(string, string, int, int, int);
	
};