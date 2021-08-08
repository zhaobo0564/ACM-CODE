#include <iostream>
#include <cstring>
#include <queue>
#define judge(x,y) x>=1&&x<=n&&y>=1&&y<=m
using namespace std;
int n,m,sx,sy,ok,ans;
int xx[]={-1,1,0,0};
int yy[]={0,0,1,-1};
char map[55][55];
int book[55][55];
struct node{
    int x;
    int y;
    int f;      //²½Êý
};
void bfs();
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];
            if(map[i][j]=='*') book[i][j]=1;//±ê¼Ç¸ÐÈ¾µØ
            if(map[i][j]=='S') sx=i,sy=j;
        }
    }
    //±ê¼Ç¸ÐÈ¾µØ À©É¢ÇøÓò
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(book[i][j]==1){
                //9¸ö·½Î»
                for(int k=-1;k<=1;k++){
                    for(int l=-1;l<=1;l++){
                        if(judge(i+k,j+l))
                            map[i+k][j+l]='*';
                    }
                }
            }
        }
    }
     
    bfs();
}
void bfs(){
    queue <node> q;
    q.push({sx,sy,0});
    while(!q.empty()){
        node it=q.front();
        q.pop();
        //ÖÕµã
        if(map[it.x][it.y]=='E'){
            ans=it.f;
            ok=1;
            break;
        }
        map[it.x][it.y]='*';    //±ê¼ÇÒÑ×ß
        if(book[it.x][it.y] == 1)continue;
        book[it.x][it.y]=1;
        for(int i=0;i<4;i++){
            int tx=it.x+xx[i],ty=it.y+yy[i];
            if(judge(tx,ty)&&map[tx][ty]!='*'&&book[tx][ty]==0){
                q.push({tx,ty,it.f+1});
            }
        }
    }
    if(ok==1) printf("%d\n",ans);
    else printf("Impossible\n");
}