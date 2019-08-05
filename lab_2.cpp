#include <bits/stdc++.h>
using namespace std;

struct node 
{
	long int x,y;
	struct node* next;
};

struct node* head;
void AddFirst(long int a,long int b)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->x=a;
	temp->y=b;
	    temp->next=head;
		head=temp;
}
void DelFirst()
{
	if(head==NULL)
	{
		return;
	}
	struct node* temp;
	temp=head;
	head=head->next;
	free(temp);
}
void Del(long int a,long int b)
{
	if(head==NULL)
	{
		return;
	}
	struct node* temp;
	struct node* prev=NULL;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->x==a&&temp->y==b)
		{
			if(prev==NULL)
			{
				DelFirst();
			}
			else
			{prev->next=temp->next;
			free(temp);
			}
                        cout<<0<<'\n';
			break;
		}
		prev=temp;
		temp=temp->next;
	}
        if(temp==NULL)
         {
           cout<<-1<<'\n';
         }	
}
void Search(long int d)
{
	struct node* temp;
	temp=head;
	while(temp!=NULL)
	{
		if(sqrt((temp->x)*(temp->x)+(temp->y)*(temp->y))-d<0.000001)
		{
			cout<<"("<<temp->x<<","<<temp->y<<") ";
		}
		temp=temp->next;
	}
	cout<<'\n';
}
void Search(long int a,long int b)
{
	struct node* temp;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->x==a&&temp->y==b)
		{
			cout<<"True\n";
			break;
		}
		temp=temp->next;
	}
	if(temp==NULL)
	{
	cout<<"False\n";
	}
}
void Length()
{
	struct node* temp;
	temp=head;
	long int len=0;
	while(temp!=NULL)
	{
		++len;
		temp=temp->next;
	}
	cout<<len<<'\n';
}

int main()
{
	head=NULL;
	long int tt,t;
	cin>>tt;
	while(tt--)
	{    cin>>t;
		if(t==1)
		{
			long int x,y;
			cin>>x>>y;
			AddFirst(x,y);
		}
		else if(t==2)
		{
			DelFirst();
		}
		else if(t==3)
		{
			long int x,y;
			cin>>x>>y;
			Del(x,y);
		}
		else if(t==4)
		{
			long int x;
			cin>>x;
			Search(x);
		}
		else if(t==5)
		{
			long int x,y;
			cin>>x>>y;
			Search(x,y);
		}
		else
		{
			Length();
		}
	}
		
	
}