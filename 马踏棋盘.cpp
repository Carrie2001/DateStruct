#include <iostream>
#include <cstdio>
#include<string>
#include <cmath>
#include <cstdlib>
#include<cstring>
using namespace std;
const int MAXN=10;
int map[MAXN][MAXN];//存棋盘
bool used[MAXN][MAXN];//保存已经访问过的点
int dir[8][2]={-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2,-2,-1};//方向
void Init()//初始化棋盘
{
	memset(map,0,sizeof(map));
	memset(used,0,sizeof(used));
}
struct node
{
	int x,y;//存放马的位置
	int steps;//保存编号
	node *next;
	node(){next=NULL;}//初始化节点
};//节点结构体
struct Queue
{
	node *head;//队首
	node *rear;//队尾
	int length;//队列长度
	Queue()//构造函数
	{
		head=rear=NULL;
		length=0;
	}
	void push(node v)//插入队尾
	{
		if(rear==NULL)
		{
			head=rear=new node();
			*rear=v;
			length++;
			return;
		}
		rear->next=new node();
		rear=rear->next;
		length++;
		*(rear)=v;
		rear->next=NULL;
		return;
	}
	bool empty()//判断队列是否空
	{
		if(head==NULL)
		{
			return true;
		}
		return false;
	}
	node front()//返回队首
	{
		if(empty())
		{
			cout<<"erro"<<endl;
			exit(-1);
		}
		return *head;
	}
	void pop()//抛出队首
	{
		if(empty())
		{
			cout<<"erro"<<endl;
			exit(-1);
		}
		if(rear==head)//特判
		{
			delete head;
			rear=head=NULL;
		}
		else
		{
			node *pTemp=head;
			head=head->next;
			delete pTemp;
		}
		length--;
	}
	int size()//返回队列元素个数
	{
		return length;
	}
};
void Solve()
{
	int x,y;
	cout<<"请输入起始点X,Y（X<0||Y<0结束程序）"<<endl;
	while (cin>>x>>y)
	{
		Init();//初始化
		if(x<0||y<0)
		{
			return;
		}
		Queue q;
		node now,next;
		now.x=x;
		now.y=y;
		used[x][y]=1;//节点已被访问
		int steps=0;
		now.steps=steps++;
		q.push(now);
		while (!q.empty())
		{
			now=q.front();
			q.pop();
			map[now.x][now.y]=now.steps;
			for(int i=0;i<8;i++)
			{
				next.x=now.x+dir[i][0];
				next.y=now.y+dir[i][1];
				if(!used[next.x][next.y]&&next.x>=0&&next.x<8&&next.y>=0&&next.y<8)
				{
					used[next.x][next.y]=1;
					next.steps=steps++;
					q.push(next);
				}
			}
		}
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(j)
				{
					cout<<' ';
				}
				cout<<map[i][j];
			}
			cout<<endl;
		}
		cout<<"请输入起始点X,Y（X<0||Y<0结束程序）"<<endl;
	}
}
int main()
{
	Solve();
	return 0;
}
