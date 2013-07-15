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
		void pop();						//Used for the stack implementation
		void dequeue();						//Used for the queue implementation
		void print();
}*head, *temp;

void ll::insert(int elem)
{
	ll *newnode = new ll;						//Creates a new empty node with the data to be inserted
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
}

void ll::search(int elem)
{
	temp=head;
	int flag=0;							//Flag is set if the element is found
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
	temp = head;
	int flag = 0;
	if(temp->data == elem)						//Corner case where the first element needs to be deleted
	{
		head = temp->link;
		flag = 1;
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
			temp = temp->link;
		}
	}
	if(flag)
		cout<<"\nFirst instance of the element deleted.";
	else
		cout<<"\nElement not found";
}

void ll::pop()
{
	temp = head;
	if(temp == NULL)								//Case: zero elements
	{
		cout<<"\nStack underflow.";
		return;
	}
	if(temp->link == NULL)								//Case: One element
	{	
		cout<<"\nPopped element: "<<temp->data;
		temp = NULL;
		head = NULL;
		return;
	}
	while(temp->link!=NULL && temp->link->link!=NULL)				//Case: Many elements
		temp = temp->link;
	cout<<"\nPopped element: "<<temp->link->data;
	temp->link = NULL;
}

void ll::dequeue()
{
	if(head == NULL)
	{
		cout<<"\nQueue underflow.";
		return;
	}
	cout<<"\nDequeued element: "<<head->data;
	head=head->link;
}

void ll::print()
{
	int flag=0;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"  ";
		temp=temp->link;
		flag=1;
	}
	if(!flag)
		cout<<"\nEmpty.";
}
