#include "BST_Tree.h"
#include "Hashtable.h"

BST_Tree ::BST_Tree()
{
}

void BST_Tree ::add_Account(string name, string adress, int accNo, int password, int balance)
{
    h.add(accNo, password);

    // saving user info into local file.
    ofstream write;
    write.open("server.txt", ios::app);
    write << name << endl
          << adress << endl
          << accNo << endl
          << password << endl
          << balance << endl;
    write.close();

    BST_Node *temp = new BST_Node(name, adress, accNo, password, balance);

    BST_Node *curr = Root;

    if (Root == nullptr)
        Root = temp;
    else
    {
        while (true)
        {
            // if my new account num. is smaller than root account number then store it on left
            if (accNo < current->account_number)
            {
                if (current->left == nullptr)
                {
                    current->left = temp;
                    break;
                }
                current = current->left;
            }

            // if my new account num. is greater than root account number then store it on right.
            if (accNo > current->account_number)
            {
                if (current->right == nullptr)
                {
                    current->right = temp;
                    break;
                }
                current = current->right;
            }
        }
    }
}

BST_Node *BST_Tree ::delete_Account(BST_Node *root, int accNo)
{
    if (root == nullptr)
        cout << "it seems that Database is Empty or you have entered wrong data." << endl;
    else if (accNo < root->account_number)
        root->left = delete_Account(root->left, accNo);
    else if (accNo > root->account_number)
        root->right = delete_Account(root->right, accNo);
    else
    {
        // we find that account which we want to delete it.

        if (root->left && root->right)
        {
            findMax(root->left);
            root->account_number = v.back();
            root->left = delete_Account(root->left, root->account_number);
        }
        else
        {
            cout << " aya " << endl;
            BST_Node *temp = root;

            if (root->left == nullptr)
                root = root->right;
            else if (root->right == nullptr)
                root = root->right;
            delete temp;
        }
    }
    return (root);
}

void BST_Tree ::withdraw(int accNo, int amount)
{
    load_Server();

    BST_Node *temp = Search(Root, accNo);
    if (amount > temp - balance)
    {
        cout << "Insufficient ammount to withdraw." << endl;
        return;
    }
    else
    {
        temp->balance -= amount;

        vector<int> data;

        ifstream read;
        read.open("transaction.txt", ios::app);
        int line = 0;
        while (!read.eof())
        {
            read >> line;
            if (line == accNo)
            {
                data.push_back(line);
                line = (amount * -1);
                data.push_back(line);
                continue;
            }
            data.push_back(line);
        }
        read.close();

        ofstream write;
        write.open("temp.txt", ios::app);
        for (int i = 0; i < data.size(); i++)
        {
            write << data[i] << endl;
        }
        write.close();
        remove("transaction.txt");
        rename("temp.txt", "transaction.txt");

        update_server(Root);
    }
}


void BST_Tree :: deposit(int accNo,int amount)
{
    load_Server();

    BST_Node *temp = Search(Root,accNo);
    temp->balance += amount;

    vector<int> data;
    
    ifstream read;
    read.open("transaction.txt",ios::app);
    int line = 0;
    while(!read.eof())
    {
        read >> line;
        if(line == accNo)
        {
            data.push_back(line);
            line = amount;
            data.push_back(line);
            continue;
        }
        data.push_back(line);
    }
    read.close();

    ofstream write;
    write.open("temp.txt",ios::app);
    for(int i = 0 ; i < data.size() ; i++)
    {
        write << data[i] << endl;
    }
    write.close();
    remove("transaction.txt");
    rename("temp.txt","transaction.txt");

    update_server(Root);

}


void BST_Tree :: editaccount_byAdmin(){}

// similar to passbook
void BST_Tree :: transfer(int sender_accNo,int reciever_accNo,int send_amount)
{
    BST_Node *sender = Search(Root,sender_accNo);
    BST_Node *reciever = Search(Root,reciever_accNo);
    sender->balance -= send_amount;
    reciever->balance += send_amount;

    update_server(Root);


    vector<int> data;

    // FOR SENDER -> all the transaction stored here so only change that particular transaction.
    ifstream read;
    read.open("transaction.txt",ios::app);
    int line = 0;
    while(!read.eof())
    {
        read >> line;
        if(line == sender_accNo)
        {
            data.push_back(line);
            line = (send_amount* -1);
            data.push_back(line);
            continue;
        }
        data.push_back(line);
    }
    read.close();

    ofstream write;
    write.open("temp.txt",ios::app);
    for(int i = 0 ; i < data.size() ; i++)
    {
        write << data[i] << endl;
    }
    write.close();
    remove("transaction.txt");
    rename("temp.txt","transaction.txt");


    // FOR RECIEVER -> all the transaction stored here so only change that particular transaction.
    vector<int> data; // can cause error so use data.clear()
    
    ifstream read;
    read.open("transaction.txt",ios::app);
    int line = 0;
    while(!read.eof())
    {
        read >> line;
        if(line == reciever_accNo)
        {
            data.push_back(line);
            line = send_amount;
            data.push_back(line);
            continue;
        }
        data.push_back(line);
    }
    read.close();

    ofstream write;
    write.open("temp.txt",ios::app);

    for(int i = 0 ; i < data.size() ; i++)
    {
        write << data[i] << endl;
    }

    write.close();
    remove("transaction.txt");
    rename("temp.txt","transaction.txt");
}


void BST_Tree :: transaction_history(){}

void BST_Tree :: findMax(BST_Node *root)
{
    if(root)
    {
        findMax(root->left);
        v.push_back(root->account_number);
        findMax(root->right);
    }
}

void BST_Tree :: load_Server()
{
    ifstream read;
    read.open("server.txt",ios::app);

    string name = "";
    string adress = "";
    int accountno = 0;
    int password = 0;
    int balance = 0;

    while(!read.eof())
    {
        getline(read,name);
        getline(read,adress);
        read >> accountno;
        read >> password;
        read >> balance;
        read.ignore(); // for skipping or ignoring unwanted characters 
        read.ignore();

        if(name != "" && adress != "" && accountno != 0 && password != 0)
        {
            BST_Node * temp = new BST_Node(name,adress,accountno,password,balance);
            BST_Node * current = Root;
            if(Root == nullptr)
            {
                Root = temp;
            }
            else
            {
                while(true)
                {
                    
					if (accountno < current->account_number)
					{
						if (current->left == nullptr)
						{
							current->left = temp;
							break;
						}
						current = current->left;
					}

					if (accountno > current->account_number)
					{
						if (current->right == nullptr)
						{
							current->right = temp;
							break;
						}
						current = current->right;
					}
					if (accountno == current->account_number)
					{
						break;
					}
                }
            }
        }
    }
    read.close();
}

void BST_Tree :: update_server(BST_Node *root)
{
    static int i = 0;
    if(i == 0)
    {
        i++;
        remove("server.txt")
    }

    ofstream write;
    write.open("server.txt");

    if(root)
    {
        update_server(root->left);
        write << root->name << endl;
        write << root->adress << endl;
        write << root->account_number << endl;
        write << root->password << endl;
        write << root->balance << endl;
        update_server(root->right);
    }
    write.close()
}

BST_Node * BST_Tree :: Search(BST_Node *root,int accNo)
{
    if(root == nullptr) return (nullptr);
    else if(accNo < root->account_number) return (Search(root->left,accNo));
    else if(accNo > root->account_number) return (Search(root->right,accNo));
    else return (root);
}


void BST_Tree :: printInfo(BST_Node *root)
{
    if(root)
    {
        printInfo(root->left);
        cout << root->name << endl;
        cout << root->adress << endl;
        cout << root->password << endl;
        cout << root->balance << endl;
        printInfo(root->right);
    }
}