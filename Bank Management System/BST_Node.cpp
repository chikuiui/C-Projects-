#include "BST_Node.h"



BST_Node :: BST_Node()
{
    left = right = nullptr;
    name = adress = "";
    account_number = password = balance = 0;
}

BST_Node :: BST_Node(string name, string adress, int accNo, int password , int balance)
{
    left = right = nullptr;
    this->name = name;
    this->adress = adress;
    this->account_number = accNo;
    this->password = password;
    this->balance = balance;
}