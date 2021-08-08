#include<iostream>
using namespace std;
const int N=507;
int n,m;
int a[N][N],vis[N][N];
int b[N][N];
bool cal(int a,int b,int c,int d){
	return (a<=b)&&(a<=c)&&(a<=d);
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int tx=x+dx[i];
        int ty=x+dy[i];
        if(1<=tx&&tx<=n&&1<=ty&&ty<=m&&a[tx][ty]==1&&!vis[tx][ty])
    }
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d",&a[i][j]);
            b[i][j]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(i==n||i==1||j==1||j==m){
    			b[i][j]=1;
    		}
    		if(a[i][j]==1&&!vis[i][j]){
    			int c1=i-1;
    			int c2=j-1;
    			int c3=n-i;
    			int c4=m-j;
    			if(cal(c1,c2,c3,c4)){
    				for(int p=1;p<=i;p++){
    					b[p][j]=1;
    				}
    			}
    			else if(cal(c2,c1,c3,c4)){
    				for(int p=1;p<=j;p++){
    					b[i][p]=1;
    				}
    			}
    			else if(cal(c3,c1,c2,c4)){
    				for(int p=i;p<=n;p++){
    					b[p][j]=1;
    				}
    			}
    			else{
    				for(int p=j;p<=m;p++){
    					b[i][p]=1;
    				}
    			}
                dfs(i,j);
    		}
    	}
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(!a[i][j])printf("%d",b[i][j]);
    		else printf("%d",a[i][j]);
    	}puts("");
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(!a[i][j])printf("%d",!b[i][j]);
    		else printf("%d",a[i][j]);
    	}puts("");
    }
}