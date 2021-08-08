#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int prime[N],vis[N],top=1;
int vist[1001];

void Prime(){
    for(int i=2;i<N;i++){
        if(!vis[i])prime[top++]=i;
        for(int j=1;j<top&&prime[j]*i<N;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;

        }
    }
}

int main(){
    Prime();
    cout << top - 1 << endl;
    for(int i=1;i<top;i++){
        //printf("%d ",prime[i]);
        vist[prime[i]] = 1;
    }
    int cnt =0;
    for(int i = 12; i <= 1000; i++){
        if(!vist[i]){
            cout << i << " ";
            cnt++;
        }
    }
    cout << endl << cnt << endl;

}