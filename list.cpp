#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct elem
{
	elem(){num=0;}
	bool operator==(elem &v)
	{
		if (num==v.num)
		{
			return true;
		}
		return false;
	}
	int num;
};
struct node
{
	node(){prev=next=NULL;}
	bool operator==(node &v)
	{
		if (v.num==num)
		{
			return true;
		}
		return false;
	}
	node *prev,*next;
	elem num;
};
struct list
{
	list(){head=NULL,size=len=0;}
	void Clear();
	void operator=(const list &v);
	node& operator[](int n);
	bool AddPre(int n,node &v);
	bool Push_Back(node &v);
	bool AddNext(int n,node &v);
	bool Delete(node &v);
	bool Delete(int n);
	void Print();
	node *head,*tail;
	int size;
	int len;
};
void list::Clear()
{
	node *pTemp;
	while (head!=NULL)
	{
		pTemp=head;
		head=head->next;
		delete pTemp;
	}
	size=len=0;
	head=tail=NULL;
}
void list::operator=(const list &v)
{
	node *pTemp=v.head;
	Clear();
	for(int i=0;i<v.len;i++)
	{
		if(!Push_Back(*pTemp))
		{
			cout<<"内存不足"<<endl;
			exit(-1);
		}
		pTemp=pTemp->next;
	}
}
node& list::operator[](int n)
{
	if (n<0||n>=len||!len)
	{
		cout<<"数组越界"<<endl;
		system("pause");
		exit(-1);
	}
	node *pTemp=head;
	for(int i=0;i<n;i++)
	{
		pTemp=pTemp->next;
	}
	return *pTemp;
}
bool list::AddPre(int n,node &v)
{
	if (n<=0||n>len||!len)
	{
		return false;
	}
	if (n==1)
	{
		node *pTemp=new node();
		if (pTemp==NULL)
		{
			return false;
		}
		*pTemp=v;
		pTemp->next=head;
		pTemp->prev=NULL;
		head->prev=pTemp;
		head=pTemp;
		len++;
		size+=sizeof(node);
		return true;
	}
	else
	{
		node *pTemp=head,*pTemp_2;
		for(int i=0;i<n-1;i++)
		{
			pTemp=pTemp->next;
		}
		pTemp_2=new node();
		if (pTemp_2==NULL)
		{
			return false;
		}
		*pTemp_2=v;
		pTemp->prev->next=pTemp_2;
		pTemp_2->prev=pTemp->prev;
		pTemp_2->next=pTemp;
		pTemp->prev=pTemp_2;
		len++;
		size+=sizeof(node);
		return true;
	}
}
bool list::Push_Back(node &v)
{
	if (len==0)
	{
		head=tail=new node();
		if (head==NULL)
		{
			return false;
		}
		*head=v;
		head->prev=NULL;
		head->next=NULL;
	}
	else
	{
		tail->next=new node();
		if (tail->next==NULL)
		{
			return false;
		}
		*(tail->next)=v;
		tail->next->prev=tail;
		tail->next->next=NULL;
		tail=tail->next;
	}
	len++;
	size+=sizeof(node);
	return true;
}
bool list::AddNext(int n,node &v)
{
	if (n<=0||n>len||!len)
	{
		return false;
	}
	node *pTemp=head;
	for(int i=0;i<n-1;i++)
	{
		pTemp=pTemp->next;
	}
	node *pTemp_2=new node();
	if (pTemp_2==NULL)
	{
		return false;
	}
	if (pTemp==tail)
	{
		tail=pTemp_2;
	}
	*pTemp_2=v;
	pTemp_2->next=pTemp->next;
	if (pTemp->next!=NULL)
	{
		pTemp->next->prev=pTemp_2;
	}
	pTemp->next=pTemp_2;
	pTemp_2->prev=pTemp;
	len++;
	size+=sizeof(node);
	return true;
}
bool list::Delete(node &v)
{
	if (v==*head)
	{
		node *pTemp=head;
		head=head->next;
		if (pTemp==tail)
		{
			tail=NULL;
		}
		delete pTemp;
		len--;
		size-=sizeof(node);
		return true;
	}
	node *pTemp=head->next;
	for(int i=0;i<len;i++)
	{
		if (v==*pTemp)
		{
			if (pTemp->prev!=NULL)
			{
				pTemp->prev->next=pTemp->next;
			}
			if (pTemp->next!=NULL)
			{
				pTemp->next->prev=pTemp->prev;
			}
			if (pTemp==tail)
			{
				tail=pTemp->prev;
			}
			delete pTemp;
			len--;
			size-=sizeof(node);
			return true;
		}
		pTemp=pTemp->next;
	}
	return false;
}
bool list::Delete(int n)
{
	if (n<=0||n>len||!len)
	{
		return false;
	}
	node *pTemp=head;
	if (n==1)
	{
		head=head->next;
	}
	for(int i=0;i<n-1;i++)
	{
		pTemp=pTemp->next;
	}
	if (pTemp->prev!=NULL)
	{
		pTemp->prev->next=pTemp->next;
	}
	if (pTemp->next!=NULL)
	{
		pTemp->next->prev=pTemp->prev;
	}
	if (pTemp==tail)
	{
		tail=pTemp->prev;
	}
	delete pTemp;
	len--;
	size-=sizeof(node);
	return true;
}
void list::Print()
{
	node *pTemp=head;
	for(int i=0;i<len;i++)
	{
		if (i)
		{
			cout<<' ';
		}
		cout<<(pTemp->num.num);
		pTemp=pTemp->next;
	}
	cout<<endl;
}
void Solve()
{
	list a,b;
	while (true)
	{
		cout<<"1,AddPre"<<endl;
		cout<<"2,AddNext"<<endl;
		cout<<"3,Delete(node &v)"<<endl;
		cout<<"4,Delete(int n)"<<endl;
		cout<<"5,="<<endl;
		cout<<"6,[]"<<endl;
		cout<<"7,Clear()"<<endl;
		cout<<"8,Push_Back()"<<endl;
		cout<<"9,Print()"<<endl;
		int test;
		cin>>test;
		if (test<=0||test>9)
		{
			return;
		}
		switch (test)
		{
		case 1:
			{
				int i;
				node temp;
				scanf("%d%d",&i,&temp.num.num);
				if(!a.AddPre(i,temp))
				{
					cout<<"添加错误"<<endl;
				}
				cout<<a.len<<' '<<a.size<<endl;
				break;
			}
		case 2:
			{
				int i;
				node temp;
				scanf("%d%d",&i,&temp.num.num);
				if(!a.AddNext(i,temp))
				{
					cout<<"添加错误"<<endl;
				}
				cout<<a.len<<' '<<a.size<<endl;
				break;
			}
		case 3:
			{
				node temp;
				scanf("%d",&temp.num.num);
				if (!a.Delete(temp))
				{
					cout<<"删除错误"<<endl;
				}
				cout<<a.len<<a.size<<endl;
				break;
			}
		case 4:
			{
				int i;
				scanf("%d",&i);
				if (!a.Delete(i))
				{
					cout<<"删除错误"<<endl;
				}
				cout<<a.len<<' '<<a.size<<endl;
				break;
			}
		case 5:
			{
				b=a;
				a.Print();
				b.Print();
				break;
			}
		case 6:
			{
				int i;
				scanf("%d",&i);
				cout<<a[i].num.num<<endl;
				break;
			}
		case 7:
			{
				a.Clear();
				cout<<a.len<<' '<<a.size<<endl;
				break;
			}
		case 8:
			{
				node temp;
				scanf("%d",&temp.num.num);
				a.Push_Back(temp);
				break;
			}
		case 9:
			{
				a.Print();
			}
		default:
			break;
		}
	}
}
int main()
{
	Solve();
	return 0;
}
