#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;
struct node{
	int id;
	node *lson,*rson;
	bool tag[3];
	node(){lson=rson=NULL;tag[0]=true;tag[1]=tag[2]=false;}
	node(int ID){id=ID;lson=rson=NULL;tag[0]=true;tag[1]=tag[2]=false;}
};
map<int,node>mp;
void Insert(int ID[]){
	if(mp.find(ID[0])==mp.end()){
		mp[ID[0]]=*(new node(ID[0]));
	}
	if(mp.find(ID[1])==mp.end()){
		mp[ID[1]]=*(new node(ID[1]));
	}
	node *pTemp=&mp[ID[0]];
	if(pTemp->lson==NULL){
		pTemp->lson=&mp[ID[1]];
		pTemp->tag[1]=true;
	}
	else{
		pTemp->rson=&mp[ID[1]];
		pTemp->tag[2]=true;
	}
}
void dfs(node *now){
	if(now==NULL){
		return;
	}
	cout<<now->id<<' ';
	dfs(now->lson);
	dfs(now->rson);
}
void Solve(){
	int ID[2];
	while(cin>>ID[0]&&ID[0]>0){
		cin>>ID[1];
		Insert(ID);
	}
	int root;
	cin>>root;
	dfs(&mp[root]);//先序
	cout<<endl;
	node *now,*next;
	now=&mp[root];
	stack<node*> sta;
	sta.push(now);//后续
	while(!sta.empty()){
		now=sta.top();
		if(now==NULL){
			sta.pop();
			continue;
		}
		int i;
		for(i=1;i<3;i++){
			if(now->tag[i]){
				now->tag[i]=false;
				if(i==1){
					next=now->lson;
				}
				else{
					next=now->rson;
				}
				sta.push(next);
				break;
			}
		}
		if(i==3){
			cout<<now->id<<' ';
			now->tag[0]=false;
			sta.pop();
		}
	}
	cout<<endl;
	mp.clear();
	system("pause");
}
int main(){
	Solve();
	return 0;
}