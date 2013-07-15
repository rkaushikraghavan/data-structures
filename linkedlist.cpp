#include <iostream>
#include <cstdlib>
#include <cstring>
#include "linkedlist.h"
#include "inputchecker.h"

using namespace std;

int main()
{
        string elem,ch;
        temp = new ll;											//Linked list class object
        ll *call = new ll;										//Object used to refer to the linked list
        cout<<"\nImplementation of a singly linked list\n--------------------------------------\n";
	while(1)
        {
                cout<<"\n1. Insert";
                cout<<"\n2. Delete";
                cout<<"\n3. Search";
                cout<<"\n4. Print";
                cout<<"\n5. Exit";
                cout<<"\nYour choice: ";
                ch=get_input();
                switch(atoi(ch.c_str()))
                {
                        case 1:
                                if(head==NULL)
                                        head = new ll;
                                cout<<"\nEnter element to be inserted: ";
                                elem=get_input();
                                call->insert(atoi(elem.c_str()));			//Inserts element into ll
                                cout<<"\nElement inserted.";
				break;
                        case 2:
                                cout<<"\nEnter element to be deleted: ";
                                elem=get_input();
                                call->remove(atoi(elem.c_str()));			//Searches and removes element from ll
                                break;
                        case 3:
                                cout<<"\nEnter element to be searched for: ";
                                elem=get_input();
                                call->search(atoi(elem.c_str()));			//Tells if element is present or not
                                break;
                        case 4:
				cout<<"\nThe current list is: ";
                                call->print();
                                break;
                        case 5:
                                exit(0);
                        default:
                                cout<<"\nEnter valid choice, please.";
                }
        }
        return 0;
}

