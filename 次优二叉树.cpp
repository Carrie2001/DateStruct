#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;
const int maxn = 110;
struct node{
	int data;
	node *lson, *rson;
	node(){
		data = 0;
		lson = rson = NULL;
	}
};
int sw[maxn];
int dfs(int l, int r, node *head){
	int i = l, min = abs(sw[r] - sw[l]), dw = abs(sw[r] + sw[l - 1]);
	for (int j = l + 1; j <= r; j++){
		if (abs(dw - sw[j] - sw[j - 1]) < min){
			i = j;
			min = abs(dw - sw[j] - sw[j - 1]);
		}
	}
	if (l <= i - 1){
		head[i].lson = &head[dfs(l, i - 1, head)];
	}
	if (r >= i + 1){
		head[i].rson = &head[dfs(i + 1, r, head)];
	}
	return i;
}
void Solve(int n, node* head){
	int s = dfs(1, n, head);
	queue<int>q;
	q.push(s);
	while (!q.empty()){
		int now = q.front();
		q.pop();
		if (head[now].lson != NULL){
			cout << now << " " << head[now].lson - head << endl;
			q.push(head[now].lson - head);
		}
		if (head[now].rson != NULL){
			cout << now << " " << head[now].rson - head << endl;
			q.push(head[now].rson - head);
		}
	}
}
int main(){
	int n;
	while (cin >> n&&n){
		node *head = new node[n + 1];
		sw[0] = 0;
		for (int i = 1; i <= n; i++){
			cin >> sw[i];
			sw[i] = sw[i] + sw[i - 1];
		}
		Solve(n, head);
		delete[] head;
	}
	return 0;
}
/*
9
1 1 2 5 3 4 4 3 5
*/