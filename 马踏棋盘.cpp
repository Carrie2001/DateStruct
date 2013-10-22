#include <iostream>
#include <cstdio>
#include<string>
#include <cmath>
#include <cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN=10;
int map[MAXN][MAXN];//存棋盘
bool used[MAXN][MAXN];//保存已经访问过的点
int dir[8][2]={-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2,-2,-1};//方向
struct Dir
{
	int i;
	int num;
};//保存方向
struct node
{
	int x,y;//存放马的位置
	int steps;//保存编号
	Dir dir[8];//保存8个方向的出口个数
	int nextI;
};//节点结构体
node sta[64];//模拟栈
bool cmp(Dir a,Dir b)//比较函数
{
	return a.num<b.num;
}
int getDir(int x,int y)//算出当前方格的出口数
{
	int nextX,nextY;
	int ans=0;
	for(int i=0;i<8;i++)
	{
		nextX=x+dir[i][0];
		nextY=y+dir[i][1];
		if(!used[nextX][nextY]&&nextX>=0&&nextX<8&&nextY>=0&&nextY<8)
		{
			ans++;
		}
	}
	return ans;
}
void Solve()//解决问题
{
	int x,y;
	cout<<"请输入坐标（x<0||y<0退出）"<<endl;
	while(cin>>x>>y)
	{
		if(x<0||y<0)
		{
			break;
		}
		if(x>=8||y>=8)
		{
			cout<<"越界"<<endl;
			cout<<"请输入坐标（x<0||y<0退出）"<<endl;
			continue;
		}
		memset(map,0,sizeof(map));//初始化地图和标记
		memset(used,0,sizeof(used));
		int top=0;//栈头
		node now,next;//当前形态，下一形态
		now.x=x;
		now.y=y;
		used[x][y]=1;
		now.steps=1;
		for(int i=0;i<8;i++)
		{
			now.dir[i].i=i;
		}
		now.nextI=0;
		sta[top]=now;//入栈
		while(top>=0)
		{
			now=sta[top];
			map[now.x][now.y]=now.steps;//地图标记
			if(now.steps==64)//结束判断
			{
				break;
			}
			int i;
			for(i=now.nextI;i<8;i++)
			{
				next.x=now.x+dir[now.dir[i].i][0];
				next.y=now.y+dir[now.dir[i].i][1];
				next.steps=now.steps+1;//马的下一步
				if(!used[next.x][next.y]&&next.x>=0&&next.x<8&&next.y>=0&&next.y<8)//判断是否可跳
				{
					used[next.x][next.y]=true;
					for(int j=0;j<8;j++)
					{
						next.dir[j].i=j;
						int tempX,tempY;
						tempX=next.x+dir[j][0];
						tempY=next.y+dir[j][1];
						if(used[tempX][tempY]||tempX<0||tempX>=8||tempY<0||tempY>=8)
						{
							next.dir[j].num=9;
						}
						else
						{
							next.dir[j].num=getDir(tempX,tempY);
						}
					}
					sort(next.dir,next.dir+8,cmp);//贪心策略，将下一步按出口数排序
					next.nextI=0;
					sta[top].nextI=i+1;//改变栈顶方向寻找的起始点
					top++;
					sta[top]=next;//入栈
					break;
				}
			}
			if(i==8)//当前状态找不到解，退栈
			{
				used[now.x][now.y]=false;
				map[now.x][now.y]=0;
				top--;
			}
		}
		for(int i=0;i<8;i++)//输出答案
		{
			for(int j=0;j<8;j++)
			{
				if(j)cout<<' ';
				cout<<map[i][j];
			}
			cout<<endl;
		}
		cout<<"请输入坐标（x<0||y<0退出）"<<endl;
	}
}
int main()
{
	Solve();
	return 0;
}