#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
using namespace std;
struct node{
	node *lson;
	node *rson;
	int id;
	bool lTag,rTag;//0 son 1 brother
	node(){
		lson=rson=NULL;
		lTag=rTag=0;
	}
	node(int ID){
		lson=rson=NULL;
		lTag=rTag=0;
		id=ID;
	}
};
map<int,node>mp;
int *judge,cnt;
void Insert(int ID[]){
	if(mp.find(ID[0])==mp.end()){
		mp[ID[0]]=*(new node(ID[0]));
	}
	if(mp.find(ID[1])==mp.end()){
		mp[ID[1]]=*(new node(ID[1]));
	}
	node &father=mp[ID[0]],&son=mp[ID[1]];
	if(father.lson==NULL){
		father.lson=&son;
	}
	else{
		node *pTemp=father.lson;
		while(pTemp->rson!=NULL){
			pTemp=pTemp->rson;
		}
		pTemp->rson=&son;
	}
}
void outPut(node *root){
	if(root==NULL){
		return;
	}
	if(root->lTag==1&&(root->lson)->id!=judge[cnt-1]){
		cout<<"erro"<<endl;
	}
	judge[cnt++]=root->id;
	cout<<root->id<<' ';
	if(root->lTag==1){
		return;
	}
	outPut(root->lson);
	outPut(root->rson);
}
node * dfsFront(node *root,node *front){
	if(root==NULL){
		return NULL;
	}
	cout<<root->id<<' ';
	if(root->lson==NULL&&front!=NULL){
		root->lson=front;
		root->lTag=1;
		return root;
	}
	node *pTemp[2];
	pTemp[0]=dfsFront(root->lson,root);
	pTemp[1]=dfsFront(root->rson,pTemp[0]);
	if(pTemp[1]!=NULL){
		return pTemp[1];
	}
	else if(pTemp[0]!=NULL){
		return pTemp[0];
	}
	else{
		return root;
	}
}
void Solve(){
	int N;
	int ID[2];
	cout<<"same input father son(input end with -1)"<<endl;
	while(cin>>ID[0]&&ID[0]>0){
		cin>>ID[1];
		Insert(ID);
	}
	cout<<"please input the number of root"<<endl;
	cin>>N;
	cout<<"Please input the roots"<<endl;
	int *root;
	root=new int[N];
	judge=new int[N];
	for(int i=0;i<N;i++){
		cin>>root[i];
	}
	node *pTemp=&mp[root[0]];
	for(int i=1;i<N;i++){
		pTemp->rson=&mp[root[i]];
		pTemp=pTemp->rson;
	}
	dfsFront(&mp[root[0]],NULL);
	cout<<endl;
	outPut(&mp[root[0]]);//输出先序遍历
	mp.clear();
	system("pause");
}
int main(){
	Solve();
	return 0;
}
/*
1 2
1 3
1 4
2 5
2 6
7 8
7 9
8 10
8 11
12 13
12 14
-1
3
1
7
12
*/