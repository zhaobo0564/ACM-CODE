#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int vis[N], a[N];

int prime[N],top=1;

void Prime(){
    for(int i=2;i<N;i++){
        if(!vis[i])prime[top++]=i;
        for(int j=1;j<top&&prime[j]*i<N;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;

        }
    }
}

int main() {
   
    int t, p;
    scanf("%d", &t);
    while (t--){
        scanf("%d", &p);
        for (int i = 1; i <= p; i++) {
            vis[i] = 0;
        }
      
        a[1] = 1;
        int f = 0;
        vis[1] = 1;
        for (int i = 2; i < p; i++) {
            if (vis[(2 * a[i - 1]) % p] == 0) {
                a[i] = (2 * a[i - 1]) % p;
                vis[a[i]] = 1;
            } else if (vis[(3 * a[i - 1]) %p] == 0) {
                a[i] = (3 * a[i - 1]) % p;
                vis[a[i]] = 1;
            } else {
                f = 1;
                break;
            }
        }
        if (f) {
            puts("-1");
            continue;
        }
        for (int i = 1; i < p; i++) {
            printf("%d ", a[i]);
        }
        puts("");
        
       
    }
}