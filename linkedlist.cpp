#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class ll
{
	int data;
	class ll *link;
	public:
		ll()
		{
			data = NULL;
			link = NULL;
		}
		void insert(int elem);
		void search(int elem);
		void remove(int elem);
		void print();
}*head,*temp;

void ll::insert(int elem)
{
	ll *newnode = new ll;
	newnode->data = elem;
	newnode->link = NULL;
	temp=head;
	if(head->data!=NULL)
	{
		while(temp->link!=NULL)
			temp=temp->link;
		temp->link=newnode;
	}
	else
		head = newnode;
	cout<<"\nElement inserted";
}

void ll::search(int elem)
{
	temp=head;
	int flag=0;
	while(temp!=NULL)
	{
		if(temp->data == elem)
			flag = 1;
		temp=temp->link;
	}
	if(flag)
		cout<<"\nElement found";
	else
		cout<<"\nElement not found";
}

void ll::remove(int elem)
{
	temp=head;
	int flag=0;
	if(temp->data == elem)
	{
		head = temp->link;
		flag=1;
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->link!=NULL && temp->link->data == elem)
			{
				temp->link = temp->link->link;
				flag=1;
				break;
			}		
			temp=temp->link;
		}
	}
	if(flag)
		cout<<"\nFirst instance of the element deleted.";
	else
		cout<<"\nElement not found";
}

void ll::print()
{
	int flag=0;
	temp=head;
	cout<<"\nThe current list is: ";
	while(temp!=NULL)
	{
		cout<<temp->data<<"  ";
		temp=temp->link;
		flag=1;
	}
	if(!flag)
		cout<<"\nList empty.";
}

string get_input()
{
	int err_flag;
	string input_string;
	do
	{
		cin>>input_string;
		err_flag=0;
		for(int i=0; i<strlen(input_string.c_str()); i++)
			if(input_string[i]<48 || input_string[i]>57)
			{
				err_flag=1;
				break;
			}
		if(err_flag==1)
			cout<<"Enter a valid input, please.\n";
	}while(err_flag==1);
	return input_string;
}

int main()
{
	string elem,ch;
	temp = new ll;
	ll *call = new ll;
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
				call->insert(atoi(elem.c_str()));
				break;
			case 2:
				cout<<"\nEnter element to be deleted: ";
				elem=get_input();
				call->remove(atoi(elem.c_str()));
				break;
			case 3:
				cout<<"\nEnter element to be searched for: ";
				elem=get_input();
				call->search(atoi(elem.c_str()));
				break;
			case 4:
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

