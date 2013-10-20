#include<iostream>
using namespace std;
struct node
{
	int date;
	node *next;
	node(int temp):date(temp){}
	node(){date=0,next=NULL;}
};
struct que
{
	node head;
	node *tail;
	int size;
	que(){size=0,tail=&head,head.next=&head;}
	void OutPut()
	{
		node *pTemp=head.next;
		while (pTemp!=&head)
		{
			cout<<pTemp->date<<' ';
			pTemp=pTemp->next;
		}
		cout<<endl;
	}
};
void Push(que &q,int x)
{
	node *pTemp=new node(x);
	q.tail->next=pTemp;
	q.tail=pTemp;
	pTemp->next=&q.head;
	q.size++;
}
bool Pop(que &q)
{
	if(q.size==0)
	{
		return false;
	}
	node *pTemp=q.head.next->next;
	delete q.head.next;
	q.head.next=pTemp;
	q.size--;
	return true;
}
void Solve()
{
	que q;
	while (true)
	{
		char s[2];
		cin>>s;
		if(s[0]=='I')
		{
			int x;
			cin>>x;
			Push(q,x);
		}
		else
		{
			Pop(q);
		}
		q.OutPut();
	}
}
int main()
{
	Solve();
	return 0;
}