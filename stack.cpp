#include <iostream>
#include <cstdlib>
#include <cstring>
#include "linkedlist.h"
#include "inputchecker.h"

using namespace std;

int main()
{
	temp = new ll;								//Linked list class object
	ll *call = new ll;							//Object used to refer to the whole stack.
	string ch,elem;
	cout<<"\nImplementation of a stack\n-------------------------\n";
	while(1)	
	{
		cout<<"\n1. Push";
		cout<<"\n2. Pop";
		cout<<"\n3. Print";
		cout<<"\n4. Exit";
		cout<<"\nYour choice: ";
		ch=get_input();
		switch(atoi(ch.c_str()))
		{
			case 1:
				if(head == NULL)
					head = new ll;				//Head of the linked list
				cout<<"\nEnter element to be pushed: ";
				elem=get_input();
				call->insert(atoi(elem.c_str()));		//Insertion in the linked list
				cout<<"\nElement pushed.";
				break;
			case 2:
				call->pop();					//Pop deletes the last element in the linked list
				break;
			case 3:
				cout<<"\nThe current stack is: ";
				call->print();
				break;
			case 4:
				exit(0);
			default:
				cout<<"\nEnter valid choice, please.";		
		}
	}
	return 0;
}
