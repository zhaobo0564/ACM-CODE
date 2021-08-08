#include <bits/stdc++.h>
using namespace std;
char s[222][222];
int l[222],r[222];
int n,m;
signed main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>(s[i]+1);
        for(int j=1;j<=m;j++){
            if(s[i][j]=='W'){
                if(!l[i])l[i]=j;
                r[i]=j;
            }
        }
    }
    while(n>=1&&!l[n])n--;//删掉末尾的空行
    int ans=0;
    int pos=1;
    for(int i=1;i<=n;i++){
        if(!l[i]){
            l[i]=n;
            r[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        l[i]=min(l[i],pos);
        r[i]=max(r[i],pos);
        if(i%2==1){//要走到右边
            if(i==n){//最后一行
                ans+=abs(r[i]-pos);
                break;
            }else{
                int ma=max(r[i],r[i+1]);
                if(ma>=pos){
                    ans+=ma-pos;
                    pos=ma;
                }
                ans++;//到下一行
            }
        }else{//要走到左边
            if(i==n){//最后一行
                ans+=abs(pos-l[i]);
                break;
            }else{
                int mi=min(l[i],l[i+1]);
                if(pos>=mi){
                    ans+=pos-mi;
                    pos=mi;
                }
                ans++;//到下一行
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}