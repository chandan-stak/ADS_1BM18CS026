#include<bits/stdc++.h> 
using namespace std;
struct node
{
	int data;
	struct node *link;
	
};

class DLL
{
	public: struct node * head;
	DLL()
	{
		head=NULL;
	}
	struct node* XOR (struct node* a, struct node* b)  
	{  
    		return (struct node *) ((uintptr_t) (a) ^ (uintptr_t) (b));  
	}  
 
	void insert_end(int data)
	{
		struct node *newnode=new(struct node);
		newnode->data=data;
		newnode->link=NULL;
		
		if (head==NULL)
		{
			head=newnode;
			
		}
		else 
		{	struct node * current=head;
			struct node *prev=NULL;
			struct node *x;
			while(current->link!=prev)
			{	x=current;
				current=XOR(current->link,prev);
				prev=x;
			}
			current->link=XOR(current->link,newnode);
			newnode->link=current;
			
		}
	}
	void insert_beginning(int data)
	{
		struct node *newnode=new(struct node);
		newnode->data=data;
		newnode->link=NULL;
		
		if (head!=NULL)
		{
			newnode->link=head;
			head->link=XOR(head->link,newnode);
		}
		
		head=newnode;
	}
	void display()
	{ 	
		cout<<"The LIST is "<<endl;
		struct node * current=head;
		struct node *prev=NULL;
		struct node *x;
		while(current->link!=prev)
		{	x=current;
				cout<<current->data<<" " ;
				current=XOR(current->link,prev);
				prev=x;
		}
		cout<<current->data<<endl;
	}
	
};
int main()
{	
	DLL a=DLL();
	int choice,n,ct;
	do
	{
		cout<<"Enter 1 : Insert at the Beginning \nEnter 2 : Insert at End \nEnter 3 : Display List\n";
		cout<<"Enter you choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1 : cout<<"Enter the Element: ";
				cin>>n;
				a.insert_beginning(n);
				break;
			case 2 : cout<<"Enter the Element: ";
				cin>>n;
				a.insert_end(n);
				break;
			case 3 :a.display();
				break;
				
			default : cout<<"Incorrrect Choice.";
			
				
		};
		cout<<"Do you want to continue :(1/0): ";
		
		cin>>ct;
	}while(ct!=0);
	return 0;
}
