#pragma once


#include "Node.h"
#include "Node_1.h"


class Hashtable
{
    public:
      Node *start;
      void starthash();
      void loadhashtable();
      void add(int,int);
      void match(int,int);
      void display();
      void displayPasswords();
      void delete_password(int);
}