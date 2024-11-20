#pragma once

#include<stdio.h>
#include "BST_Node.h"
#include "Hashtable.h"


class BST_Tree
{
    vector<int> v;

public:
    Hashtable h;
    BST_Node *Root;
    BST_Node *BST_Tree :: delete_Account(BST_Node *, int);
    BST_Node *Search(BST_Node*,int);

    void add_Account(string,string,int,int,int);
    void withdraw(int,int);
    void deposit(int,int);
    void editaccount_byAdmin();
    void transfer(int,int,int);
    void transaction_history();
    void findMax(BST_Node*);
    void load_Server();
    void update_server(BST_Node*);
    void printInfo(BST_Node*);
};