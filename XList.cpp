#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<stack>
#include<queue>
using namespace std;
const int maxn=1010;
struct eageNode{
	int head,tail;
	eageNode *hlink,*tlink;
	int info;
	eageNode(){
		hlink=tlink=NULL;
		head=tail=0;
	}
};
struct vexNode{
	int data;
	eageNode *firstIn,*firstOut;
};
map<int,int> mp;
struct XGraph{
	vexNode xlist[maxn];
	int vexNum,eageNum;
	void outPut(int vex){
		cout<<vex<<endl;
		eageNode *pTemp=xlist[mp[vex]].firstOut;
		while(pTemp!=NULL){
			cout<<pTemp->head<<' '<<pTemp->tail<<endl;
			pTemp=pTemp->hlink;
		}
		cout<<endl;
	}
};
void Init(XGraph &g,int n){
	g.vexNum=n;
	mp.clear();
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		g.xlist[i].data=data;
		g.xlist[i].firstIn=g.xlist[i].firstOut=NULL;
		mp[data]=i;
	}
}
void AddEage(int s,int e,int info,XGraph &g){
	int i=mp[s],j=mp[e];
	eageNode *pTemp=new eageNode();
	pTemp->head=s;pTemp->tail=e;pTemp->info=info;
	pTemp->hlink=g.xlist[i].firstOut;
	pTemp->tlink=g.xlist[j].firstIn;
	g.xlist[i].firstOut=pTemp;
	g.xlist[j].firstIn=pTemp;
}
XGraph g;
void Solve(){
	int n;
	cout<<"请输入顶点个数"<<endl;
	cin>>n;
	Init(g,n);
	cout<<"请输入边的个数"<<endl;
	int m;
	cin>>m;
	g.eageNum=m;
	for(int i=0;i<m;i++){
		int s,e,info=0;
		cin>>s>>e;
		AddEage(s,e,info,g);
	}
	int vex;
	while(cin>>vex){
		g.outPut(vex);
	}
}
int main(){
	Solve();
	system("pause");
	return 0;
}