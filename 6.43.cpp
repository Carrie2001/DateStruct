#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
struct node{
	int id;
	node *son[2];
	node(){son[0]=son[1]=NULL;}
	node(int ID){id=ID;son[0]=son[1]=NULL;}
};
map<int,node> mp;
void Insert(int ID[],bool flag){
	if(mp.find(ID[0])==mp.end()){
		mp[ID[0]]=*(new node(ID[0]));
	}
	if(mp.find(ID[1])==mp.end()){
		mp[ID[1]]=*(new node(ID[1]));
	}
	node *pTemp=&mp[ID[0]];
	if(!flag){
		pTemp->son[0]=&mp[ID[1]];
	}
	else{
		pTemp->son[1]=&mp[ID[1]];
	}
}
void dfs(node *root){
	if(root==NULL){
		return;
	}
	node *pTemp=root->son[0];
	root->son[0]=root->son[1];
	root->son[1]=pTemp;
	dfs(root->son[1]);
	dfs(root->son[0]);
}
void bfs(node *root){
	queue<node*>que;
	que.push(root);
	node *now;
	while(!que.empty()){
		now=que.front();
		que.pop();
		node *pTemp=now->son[0];
		now->son[0]=now->son[1];
		now->son[1]=pTemp;
		if(now->son[0]!=NULL){
			que.push(now->son[0]);
		}
		if(now->son[1]!=NULL){
			que.push(now->son[1]);
		}
	}
}
void dfsOutPut(node *root){
	if(root==NULL){
		return;
	}
	cout<<root->id<<' ';
	dfsOutPut(root->son[0]);
	dfsOutPut(root->son[1]);
}
void BuildTree(){
	mp.clear();
	int ID[2];
	int flag;
	cout<<"Same Input:father son flag(0:lson,1:rson)"<<endl;
	while(cin>>ID[0]&&ID[0]>0){
		cin>>ID[1]>>flag;
		Insert(ID,flag);
	}
}
void Solve(){
	BuildTree();
	int root;
	cout<<"Please input the root of the tree"<<endl;
	cin>>root;
	dfsOutPut(&mp[root]);
	cout<<endl;
	dfs(&mp[root]);//dfs
	dfsOutPut(&mp[root]);
	cout<<endl;
	bfs(&mp[root]);
	dfsOutPut(&mp[root]);
	cout<<endl;
}
int main(){
	Solve();
	return 0;
}