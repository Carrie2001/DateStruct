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
	bool operator < (const node &v)const{
		return len<v.len;
	}
	bool operator == (const node &v)const{
		return len==v.len;
	}
};
node road[maxn];//保存路径
int set[maxn];//set集合
void Init(int n)//初始化
{
	memset(set,-1,sizeof(int)*n);
}
template<class T>
void sort(T *a,int l,int r){//快速排序
	if(l>=r){
		return;
	}
	if(l==r-1){
		if(a[r]<a[l]){
			T temp=a[l];
			a[l]=a[r];
			a[r]=temp;
		}
		return;
	}
	T k,temp;
	int i,j;
	k=a[l];
	i=l,j=r;
	while(i<j){
		while(i<j&&(k<a[j]||k==a[j])){
			j--;
		}
		temp=a[j];
		a[j]=a[i];
		a[i]=temp;
		while(i<j&&(a[i]<k||a[i]==k)){
			i++;
		}
		temp=a[j];
		a[j]=a[i];
		a[i]=temp;
	}
	sort(a,l,i-1);
	sort(a,i+1,r);
}
int find(int x)//查找x的根
{
	if(set[x]<0){
		return x;
	}
	return set[x]=find(set[x]);
}
void Bin(int a,int b)//并操作
{
	a=find(a),b=find(b);
	if(a!=b){
		if(set[a]<set[b]){
			set[b]=a;
		}
		else if(set[a]>set[b]){
			set[a]=b;
		}
		else{
			set[b]=a;
			set[a]--;
		}
	}
}
int Kruskal(int n,int m)//求解最小生成树
{
	sort(road,0,m-1);
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
