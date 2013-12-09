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
	bool visted;
	head_node(){
		first=NULL;
		visted=false;
	}
};
head_node *head;
int *degree;
bool Build_Head(int n){
	if(head!=NULL){
		delete[] head;
	}
	if(degree!=NULL){
		delete[] degree;
	}
	head = new head_node[n];
	degree = new int[n];
	memset(degree,0,sizeof(int)*n);
	if(head==NULL){
		return false;
	}
	return true;
}
void Add_Road(int s,int e,int w=0){
	eage_node *pTemp=head[s].first;
	degree[e]++;
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
	if(degree!=NULL){
		delete[] degree;
		degree=NULL;
	}
}
int *ans,cnt;
void Solve(int n){
	cnt=0;
	ans = new int[n];
	queue<int>q;
	for(int i=0;i<n;i++){
		if(degree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int now = q.front();
		ans[cnt++]=now;
		q.pop();
		eage_node *pTemp = head[now].first;
		while(pTemp!=NULL){
			degree[pTemp->vex_to]--;
			if(degree[pTemp->vex_to]==0){
				q.push(pTemp->vex_to);
			}
			pTemp = pTemp->pNext;
		}
	}
	if(cnt!=n){
		cout<<"no";
	}
	else{
		for(int i=0;i<cnt;i++){
			if(i){
				cout<<' ';
			}
			cout<<ans[i]+1;
		}
	}
	cout<<endl;
	delete[] ans;
}
int main(){
	head=NULL;
	int n,m;
	while(cin>>n>>m){
		int s,e;
		Build_Head(n);
		for(int i=0;i<m;i++){
			cin>>s>>e;
			s--;e--;
			Add_Road(s,e);
		}
		Solve(n);
		Delete_Graph(n);
	}
	return 0;
}
/*
12 15
1 4
1 2
1 12
9 12
9 10
9 11
10 12
4 5
2 3
11 6
5 7
3 5
3 7
3 8
6 8
*/