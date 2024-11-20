#pragma once


#include "BST_Tree.h"
#include "Hashtable.h"



void staff()
{
    BST_Tree t;
    Hashtable h;

    int condition = 0;

    while(condition != 5)
    {
        cout << "\t\t\t Welcome STAFF \t\t\t" << endl;
        cout << "\t\t Choose the following please := \t\t" << endl;
        cout << "\t\t Press 1 to see transaction history " << endl;
        cout << "\t\t Press 2 to transfer \t\t" << endl;
        cout << "\t\t Press 3 to withdraw \t\t" << endl;
        cout << "\t\t Press 4 to deposit \t\t" << endl;
        cout << "\t\t Press 5 to exit \t\t" << endl;

        if(condition == 1)
        {
            // show the transaction history
        }
        if(condition == 2)
        {
            int senderAccNo,amount,recieverAccNo;
            cout << "Please enter sender Account Number :" << endl;
            cin >> senderAccNo; 
            cout << "Please enter receiver Account Number :" << endl;
            cin >> recieverAccNo;
            cout << "Please enter the amount :" << endl;
            cin >> amount;
            t.transfer(senderAccNo,amount,recieverAccNo);
        }
        if(condition == 3)
        {
            int accNo,amount;
            cout << "Please enter account number :" << endl;
            cin >> accNo;
            cout << "Please enter amount :" << endl;
            cin >> amount;
            t.withdraw(accNo,amount);
        }
        if(condition == 4)
        {
            int accNo,amount;
            cout << "Please enter account number :" << endl;
            cin >> accNo;
            cout << "Please enter amount :" << endl;
            cin >> amount;
            t.deposit(accNo,amount);
        }
        
    }
}