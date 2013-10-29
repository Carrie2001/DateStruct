#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn=100000;//最大点数
struct node
{
	int s,e,len;//起点，终点，路的长度
};
bool cmp(node a,node b)//比较函数
{
	return a.len<b.len;
}
node road[maxn];//保存路径
int set[maxn],height[maxn];//set集合,height为树的深度
void Init(int n)//初始化
{
	for(int i=0;i<=n;i++)
	{
		set[i]=i;
		height[i]=1;
	}
}
int find(int x)//查找x的根
{
	if(x==set[x]){
		return x;
	}
	return x=find(set[x]);
}
void Bin(int a,int b)//并操作
{
	a=find(a),b=find(b);
	if(a!=b){
		if(height[a]>height[b]){
			set[b]=a;
		}
		else if(height[a]<height[b]){
			set[a]=b;
		}
		else{
			set[b]=a;
			height[a]++;
		}
	}
}
int Kruskal(int n,int m)//求解最小生成树
{
	sort(road,road+m,cmp);
	int ans=0;
	Init(n);
	for(int i=0;i<m;i++){
		int a=find(road[i].s),b=find(road[i].e);
		if(a!=b){
			ans+=road[i].len;
			Bin(a,b);
		}
	}
	return ans;
}
void Solve()
{
	int n,m;
	cout<<"请输入城市的个数:"<<endl;
	while(cin>>n){
		if(n>=maxn){
			cout<<"城市个数超过限制"<<endl;
			cout<<"请输入城市的个数:"<<endl;
			continue;
		}
		cout<<"请输入边的个数"<<endl;
		cin>>m;
		cout<<"依次输入起点，终点，路径长度(从1开始编号)"<<endl;
		for(int i=0;i<m;i++)
		{
			cin>>road[i].s>>road[i].e>>road[i].len;
		}
		cout<<"ans="<<Kruskal(n,m)<<endl;
		cout<<"请输入城市的个数:"<<endl;
	}
}
int main()
{
	Solve();
	return 0;
}
