#include<iostream>
using namespace std;
const int MAXN_LEN=10000;
struct Stack
{	
	int tws[MAXN_LEN];
	int top[2];
	int len;
	void OutPut()
	{
		for(int i=top[0]+1;i<top[1];i++)
		{
			cout<<tws[i]<<' ';
		}
		cout<<endl;
	}
};
Stack tws;
void InitStack(Stack &v)
{
	v.len=0;
	v.top[0]=MAXN_LEN>>1;
	v.top[1]=(MAXN_LEN>>1)+1;
}
bool Push(Stack &v,int i,int x)
{
	if (v.top[i]<0||v.top[1]>=MAXN_LEN)
	{
		return false;
	}
	v.tws[v.top[i]]=x;
	if(i)
	{
		v.top[i]++;
	}
	else
	{
		v.top[i]--;
	}
	v.len++;
	return true;
}
bool pop(Stack &v,int i)
{
	if(v.len==0)
	{
		return false;
	}
	if (i)
	{
		v.top[i]--;
	}
	else
	{
		v.top[i]++;
	}
	v.len--;
	return true;
}
void Solve()
{
	InitStack(tws);
	while (true)
	{
		char s[2];
		cin>>s;
		if(s[0]=='I')
		{
			int i,x;
			cin>>i>>x;
			Push(tws,i,x);
		}
		else
		{
			int i;
			cin>>i;
			pop(tws,i);
		}
		tws.OutPut();
	}
}
int main()
{
	Solve();
	return 0;
}