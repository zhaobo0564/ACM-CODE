#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[1000007],b[1000007];

int main(){
    int n = read();
    int m = read();
    int p = read();

    for(int i = 1; i <= n; i++){
        a[i] = read();
    }
    for(int i=1;i<=m;i++){
        b[i] = read();
    }
    int x,y;
    for(int i=1;i<=n;i++){
        if(a[i]%p){
            x=i;
            break;
        }   
    }
    for(int i = 1;i <= m; i++){
        if(b[i]%p){
            y=i;
            break;
        }
    }
    printf("%d\n",x+y-2);
}