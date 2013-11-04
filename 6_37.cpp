#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct node{
 int id;
 node *lson,*rson;
 bool tag[3];
 node(){lson=rson=NULL;tag[0]=tag[1]=tag[2]=false;}
 node(ID){lson=rson=NULL;id=ID;tag[0]=tag[1]=tag[2]=false;}
};
mp<int,node>mp;
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
void Solve(){
 int ID[2];
 while(cin>>ID[0]&&ID[0]>0){
  cin>>ID[1];
  Insert(ID);
 }
 int root;
 cin>>root;
 node *now,next;
 vector<node>vec;
 vec.push(mp[root]);
 while(!vec.empty()){
  now=&vec.top();
  int i;
  if(now->tag[0]){
   cout<<now->id<<endl;
  }
  for(i=1;i<3;i++){
   if(!now->tag[i]){
    now->tag[i]=true;
    next
   }
  }
 }
}
int main(){
 Solve();
 return 0;
}
