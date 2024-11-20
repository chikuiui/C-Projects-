#pragma once

#include "BST_Tree.h"
#include "Hashtable.h"



void customer()
{
    BST_Tree t;
    Hashtable h;
    int condition = 0;

    while(condition != 3)
    {
        cout << "\t\t\t Welcome CUStOMER \t\t\t" << endl;
        cout << "\t\t Choose the following please :- \t\t\t" << endl;
        cout << "\t\t Press 1 to see accound details \t\t" << endl;
        cout << "\t\t Press 2 to see transaction history \t\t"<<endl;
        cout << "\t\t Press 3 to exit \t\t" << endl;

        cin >> condition;

        if(condition == 1)
        {
            int accNo;
            cout << "Please Enter Account Number :";
            cin >> accNo;
            
            BST_Node *temp = t.Search(t.Root,accNo);

            cout << "Account Details Are :\t\t\t\t\t\t " << endl << endl;
            cout << "NAME : " << temp->name << endl;
            cout << "ADRESS : " << temp->adress << endl;
            cout << "ACCOUNT : " << temp->account_number << endl;
            cout << "PASSWORD : " << temp->password << endl;
            cout << "BALANCE : " << temp->balance << endl; 
        }
        if(condition == 2){
            // needs to show transaction history
        }

    }
}