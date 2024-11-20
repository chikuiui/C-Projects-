#pragma once


#include "BST_Tree.h"
#include "Hashtable.h"



void main()
{
    BST_Tree t;
    Hashtable h;
    
    int condition = 0;

    while(condition != 6)
    {
        cout << "\t\t\tWelcome ADMIN\t\t\t" << endl;
        cout << "\t\tChoose the following please :-\t\t" << endl;
        cout << "\t\tpress 1 to add account \t\t" << endl;
        cout << "\t\tPress 2 to delete account \t\t" << endl;
        cout << "\t\tPress 3 to check all account \t\t" << endl;
        cout << "\t\tPress 4 to see password of account " << endl;
        cout << "\t\tPress 5 to edit account " << endl;
        cout << "\t\tPress 6 to exit \t\t" << endl;

        cin >> condition;

        if(condition == 1)
        {
            string n = "",a = "";
            int acc, p , b;
            cout << "Enter name :" << endl;
            cin >> n;
            cout << "Enter adress" << endl;
            cin >> a;
            cout << "Enter account number" << endl;
            cin >> acc;
            cout << "Enter password" << endl;
            cin >> p;
            cout << "Enter balance" << endl;
            cin >> b;
            t.add_Account(n,a,acc,p,b);
        }
        if(condition == 2)
        {
            int acc = 0;
            cout << "Enter account number " << endl;
            cin >> acc;
            t.load_Server();
            cout << "delete account from Tree" << endl;
            t.Root = t.delete_Account(t.Root,acc);
            cout << "delete password " << endl;
            h.delete_passwords(acc);
            cout << "update the server" << endl;
            t.update_server(t.Root);
            
        }
        if(condition == 3)
        {
            t.load_Server();
            t.printInfo(t.Root);
        }

        if(condition == 4)
        {
            h.displayPasswords();
        }

        if(condition == 5){}
    }
}