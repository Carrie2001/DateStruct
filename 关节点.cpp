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
const int INF = 1 << 30;
int head[maxn], v[maxn * maxn], Next[maxn * maxn], sz;
int cnt;
int low[maxn];
int vist[maxn];
void Init(int n){
	memset(head, -1, sizeof(int)*(n + 1));
	memset(vist, 0, sizeof(int)*(n + 1));
	for (int i = 0; i < n; i++){
		low[i] = INF;
	}
	cnt = 1;
	sz = 0;
}
void Add_Road(int s, int e){
	v[sz] = e;
	Next[sz] = head[s];
	head[s] = sz++;
}
void dfs(int s){
	int number;
	vist[s] = number = cnt++;
	for (int i = head[s]; ~i; i = Next[i]){
		if (!vist[v[i]]){
			dfs(v[i]);
			number = min(number, low[v[i]]);
			if (low[v[i]] >= vist[s]){
				cout << s << ' ';
			}
		}
		else{
			number = min(number, vist[v[i]]);
		}
	}
	low[s] = number;
}
void Solve(int n){
	dfs(0);
	cout << endl;
}
int main(){
	int n;
	while (cin >> n){
		Init(n);
		int s, e;
		while (cin >> s >> e && (s || e)){
			Add_Road(s, e);
			Add_Road(e, s);
		}
		Solve(n);
	}
	return 0;
}
/*
13
0 5
0 2
0 1
0 11
1 2
1 3
1 6
1 7
3 4
6 8
6 7
6 10
7 10
9 11
9 12
11 12
12 1
0 0
*/