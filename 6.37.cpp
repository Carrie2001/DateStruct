#include<iostream>
#include<stack>
#include<map>
using namespace std;
struct node{
	int id;
	node *lson,*rson;
	bool tag[3];
	node(){lson=rson=NULL;tag[0]=tag[1]=tag[2]=false;}
	node(int ID){lson=rson=NULL;id=ID;tag[0]=tag[1]=tag[2]=false;}
};
map<int,node>mp;
void Insert(int ID[]){
	if(mp.find(ID[0])==mp.end()){
		mp[ID[0]]=*(new node(ID[0]));
	}
	if(mp.find(ID[1])==mp.end()){
		mp[ID[1]]=*(new node(ID[1]));
	}
	node &father=mp[ID[0]],&son=mp[ID[1]];
	father.tag[0]=son.tag[0]=true;
	if(father.lson==NULL){
		father.tag[1]=true;
		father.lson=&son;
	}
	else{
		node *pTemp=father.lson;
		while(pTemp->rson!=NULL){
			pTemp=pTemp->rson;
		}
		pTemp->tag[2]=true;
		pTemp->rson=&son;
	}
}
void Solve(){
	int ID[2];
	while(cin>>ID[0]&&ID[0]>0){
		cin>>ID[1];
		Insert(ID);
	}
	int root;
	cin>>root;
	node *now,next;
	stack<node>vec;
	vec.push(mp[root]);
	while(!vec.empty()){
		now=&(vec.top());
		int i;
		if(now->tag[0]){
			cout<<now->id<<' ';
			now->tag[0]=false;
		}
		for(i=1;i<3;i++){
			if(now->tag[i]){
				now->tag[i]=false;
				if(i==1){
					next=*(now->lson);
				}
				else{
					next=*(now->rson);
				}
				vec.push(next);
				break;
			}
		}
		if(i==3){
			vec.pop();
		}
	}
	cout<<endl;
	system("pause");
}
int main(){
	Solve();
	return 0;
}
