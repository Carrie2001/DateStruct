#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn=1010;
struct eage_node{
	bool mark;
	int ivex,jvex;
	eage_node *ilink,*jlink;
	int info;
	eage_node(){
		mark=false;
		ivex=jvex=info=0;
		ilink=jlink=NULL;
	}
};
vector<eage_node*> Del;
struct head_node{
	eage_node *first;
	bool mark;
	head_node(){
		first=NULL;
		mark=false;
	}
};
head_node *head;
void Build_Head(int n){
	head = new head_node[n];
}
void  Delete_Road(int n){
	for(unsigned int i=0;i<Del.size();i++){
		delete Del[i];
	}
	Del.clear();
	delete[] head;
	head=NULL;
}
void Add_Road(int s,int e){
	eage_node *pTemp = new eage_node();
	Del.push_back(pTemp);
	pTemp->ivex=s;
	pTemp->jvex=e;
	pTemp->ilink=head[s].first;
	pTemp->jlink=head[e].first;
	head[s].first=pTemp;
	head[e].first=pTemp;
}
void dfs(int s){
	cout<<s+1<<' ';
	eage_node *pTemp=head[s].first;
	while(pTemp!=NULL){
		if(pTemp->ivex==s){
			if(!head[pTemp->jvex].mark){
				head[pTemp->jvex].mark=true;
				dfs(pTemp->jvex);	
			}
			pTemp=pTemp->ilink;
		}
		else{
			if(!head[pTemp->ivex].mark){
				head[pTemp->ivex].mark=true;
				dfs(pTemp->ivex);
			}
			pTemp=pTemp->jlink;
		}
	}
}
void bfs(int s){
	queue<int>q;
	q.push(s);
	head[s].mark=true;
	while(!q.empty()){
		s=q.front();
		q.pop();
		cout<<s+1<<' ';
		eage_node *pTemp;
		pTemp=head[s].first;
		while(pTemp!=NULL){
			if(pTemp->ivex==s){
				if(!head[pTemp->jvex].mark){
					head[pTemp->jvex].mark=true;
					q.push(pTemp->jvex);
				}
				pTemp=pTemp->ilink;
			}
			else{
				if(!head[pTemp->ivex].mark){
					head[pTemp->ivex].mark=true;
					q.push(pTemp->ivex);
				}
				pTemp=pTemp->jlink;
			}
		}
	}
	cout<<endl;
}
void Solve(){
	int n;
	while(cin>>n){
		Build_Head(n);
		int s,e;
		while(cin>>s>>e&&(s||e)){
			s--,e--;
			Add_Road(s,e);
		}
		head[0].mark=true;
		dfs(0);
		cout<<endl;
		for(int i=0;i<n;i++){
			head[i].mark=false;
		}
		head[0].mark=true;
		bfs(0);
		Delete_Road(n);
	}
}
int main(){
	Solve();
	return 0;
}