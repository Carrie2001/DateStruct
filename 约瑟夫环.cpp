#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct node
{
	node()
	{
		next=pre=NULL;
	}
	int m;
	int name;
	node *next;
	node *pre;
};
struct List
{
	node *head;
	node *tail;
	int size;
	List()
	{
		head=NULL;
		tail=NULL;
		size=0;
	}
	node &operator[](int x)
	{
		node *tempP=head;
		for(int i=0;i<x;i++)
		{
			tempP=tempP->next;
		}
		return *tempP;
	}
	bool push_back(node &v)
	{
		if (tail==NULL)
		{
			head=tail=new node();
			if(tail==NULL)
			{
				return false;
			}
		}
		else
		{
			tail->next=new node();
			if(tail->next==NULL)
			{
				return false;
			}
			if(head==NULL)
			{
				head=tail;
			}
			tail->next->pre=tail;
			tail=tail->next;
		}
		tail->m=v.m;
		tail->name=v.name;
		size++;
		return true;
	}
	bool Del(int x)
	{
		node &temp=(*this)[x];
		if(head==&temp)
		{
			head=temp.next;
		}
		if(tail==&temp)
		{
			tail=temp.pre;
		}
		if (temp.pre!=NULL)
		{
			temp.pre->next=temp.next;
		}
		if(temp.next!=NULL)
		{
			temp.next->pre=temp.pre;
		}
		delete &temp;
		size--;
		if(!size)
		{
			head=tail=NULL;
		}
		return true;
	}
	void clear()
	{
		if(!size)
		{
			head=tail=NULL;
			return;
		}
		node *pTemp=head;
		node *now;
		while (pTemp!=NULL)
		{
			now=pTemp->next;
			delete pTemp;
			pTemp=now;
		}
		head=tail=NULL;
		size=0;
	}
	bool empty()
	{
		if(size>0)
		{
			return false;
		}
		return true;
	}
};
void Solve()
{
	int m,n;
	List l;
	while (cin>>n)
	{
		m=20;
		node temp;
		for(int i=0;i<n;i++)
		{
			cin>>temp.m;
			temp.name=i+1;
			l.push_back(temp);
		}
		l.head->pre=l.tail;
		l.tail->next=l.head;
		bool flag=false;
		while (!l.empty())
		{
			if(flag)
			{
				printf(",");
			}
			int x=m-1;
			printf("%d",l[x].name);
			m=l[x].m;
			node *pTemp;
			pTemp=l[x].next;
			l.Del(x);
			l.head=pTemp;
			n--;
			flag=true;
		}
		printf("\n");
		l.clear();
	}
}
int main()
{
	Solve();
	return 0;
}
