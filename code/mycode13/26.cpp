#include<iostream>
#include<algorithm>
using namespace std;
int a[10001];
struct node{
	int x;
	int y;
	int len;
}gl[100001];
bool cmp(node a,node b){
	return a.len<b.len;//比较函数 
}
int find(int n){
	if(n!=a[n])return a[n] = find(a[n]);
	else return n;//并查集之查找 
}
int tt(int N){
	for(int i=1;i<=N;i++){
		a[i]=i;//数组初始化,令其父节点为他本身 
	}
}
int main(){
	int N;
	ios::sync_with_stdio(0);
	while(cin>>N,N){
		tt(N);
		int m,mm=1,mark=0,ans=0,x,y,z,nb;
		m=N*(N-1)/2;
		for(int i=1;i<=m;i++){
			cin>>x>>y>>z>>nb;//输入 
			if(nb==1){
				int gh=find(x),hj=find(y);
				if(gh!=hj){
                    a[gh]=hj;
                    ans++;
				}
			}//已经修了路,分情况 
			else if(nb==0){
                gl[mm].x=x;gl[mm].y=y;gl[mm].len=z;
                mm++;	//未修合并到结构体 
			}
		}
		sort(gl+1,gl+mm,cmp);//令sort的次数越小越好 
		for(int i=1;i<=mm-1;i++){
            if(ans==(N-1))break;
            int xx=find(gl[i].x),yy=find(gl[i].y);
            if(xx!=yy){
                a[xx]=yy;
                mark+=gl[i].len;
                ans++;//记录次数,ans等于端点数减一得到段数,
			}
			if(ans==(N-1))break;
		}
		cout<<mark<<endl;
	}
}
