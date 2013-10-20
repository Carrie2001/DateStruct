#include<iostream>
struct Queue
{	
	int length,rear;
	int q[MAXN];
	Queue(){length=0,rear=-1;}
	bool full()
	{
		if(length==MAXN)
		{
			return true;
		}
		return false;
	}
	void push_back(int v)
	{
		if(full())
		{
			cout<<"erro"<<endl;
			return;
		}
		rear=(rear+1)%MAXN;
		q[rear]=v;
		length++;
	}
	int pop()
	{
		if(length==0)
		{
			cout<<"erro"<<endl;
			return -1;
		}
		int temp=rear-length+1;
		if(temp<0)
		{
			temp+=MAXN;
		}
		length--;
		return q[temp];
	}
	void Output()
	{
		int i=rear-length+1;
		if(i<0)
		{
			i+=MAXN;
		}
		for(int j=0;j<length;j++)
		{
			if(j)
			{
				cout<<' ';
			}
			cout<<q[i%MAXN];
			i++;
		}
		cout<<endl;
	}
};