#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<map>
#include<string>
#include<queue>
using namespace std;
struct eage_node{
	int vex_to;
	int info;
	eage_node *pNext;
	bool visted;
	eage_node(){
		pNext=NULL;
		vex_to=-1;
		info=-1;
		visted=false;
	}
};
struct head_node{
	eage_node *first;
	int pre;
	bool visted;
	head_node(){
		first=NULL;
		pre=-1;
		visted=false;
	}
};
head_node *head;
int *in_degree,*out_degree;
bool Build_Head(int n){
	if(head!=NULL){
		delete[] head;
	}
	if(in_degree!=NULL){
		delete[] in_degree;
	}
	head = new head_node[n];
	in_degree = new int[n];
	out_degree = new int[n];
	memset(in_degree,0,sizeof(int)*n);
	memset(out_degree,0,sizeof(int)*n);
	if(head==NULL){
		return false;
	}
	return true;
}
void Add_Road(int s,int e,int w=0){
	eage_node *pTemp=head[s].first;
	in_degree[e]++;
	out_degree[s]++;
	if(pTemp==NULL){
		head[s].first = new eage_node();
		head[s].first->vex_to=e;
		head[s].first->info=w;
		return;
	}
	while(pTemp->pNext!=NULL){
		pTemp=pTemp->pNext;
	}
	pTemp->pNext = new eage_node();
	pTemp->pNext->vex_to=e;
	pTemp->pNext->info=w;
}
void Delete_Graph(int n){
	for(int i=0;i<n;i++){
		eage_node *pTemp = head[i].first;
		while(pTemp!=NULL){
			eage_node *pTemp2 = pTemp;
			pTemp = pTemp->pNext;
			delete pTemp2;
		}
	}
	if(head!=NULL){
		delete[] head;
		head=NULL;
	}
	if(in_degree!=NULL){
		delete[] in_degree;
		in_degree=NULL;
	}
	delete[] out_degree;
}int *dp,cnt,*start;
bool bfs(int n){
	queue<int> q;
	int flag=0;
	for(int i=0;i<n;i++){
		if(in_degree[i]==0){
			q.push(i);
			flag++;
		}
		if(out_degree[i]==0){
			start[cnt++]=i;
		}
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		eage_node *pTemp;
		pTemp = head[now].first;
		while(pTemp!=NULL){
			in_degree[pTemp->vex_to]--;
			if(!in_degree[pTemp->vex_to]){
				flag++;
				q.push(pTemp->vex_to);
			}
			if(dp[pTemp->vex_to]<dp[now]+pTemp->info){
				head[pTemp->vex_to].pre=now;
				dp[pTemp->vex_to]=dp[now]+pTemp->info;
			}
			pTemp= pTemp->pNext;
		}
	}
	if(flag!=n){
		return false;
	}
	return true;
}
void Out_Puts(int s,int n){
	int *ans = new int[n],len=0;
	ans[len++]=s;
	while (~head[s].pre){
		s=head[s].pre;
		ans[len++]=s;
	}
	for(int i=len-1;i>0;i--){
		cout<<ans[i]+1<<' ';
	}
	cout<<ans[0]+1<<endl;
	delete[] ans;
}
void Solve(int n){
	dp = new int[n];
	start = new int[n];
	memset(dp,0,sizeof(int)*n);
	cnt=0;
	if(!bfs(n)){
		cout<<"no"<<endl;
	}
	else{
		for(int i=0;i<cnt;i++){
			Out_Puts(start[i],n);
		}
	}
	delete[] dp;
	delete[] start;
}
int main(){
	head=NULL;
	int n,m;
	while(cin>>n>>m){
		int s,e,w;
		Build_Head(n);
		for(int i=0;i<m;i++){
			cin>>s>>e>>w;
			s--;e--;
			Add_Road(s,e,w);
		}
		Solve(n);
		Delete_Graph(n);
	}
	return 0;
}
/*
9 11
1 2 6
1 3 4
1 4 5
2 5 1
3 5 1
4 6 2
5 7 9
5 8 7
6 8 4
7 9 2
8 9 4
*/