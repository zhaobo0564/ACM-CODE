#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int prime[N],vis[N],top=1, n, a[N];

void Prime(){
    for(int i=2;i<N;i++){
        if(!vis[i])prime[top++]=i;
        for(int j=1;j<top&&prime[j]*i<N;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;

        }
    }
}

vector<int>g[200007];

void work(int x){
    for(int i = 1; i < top; i++){
       if(prime[i] * prime[i] > x)break;
       if(x == 1)break;
        int num = 0;
        while(x % prime[i] == 0){
            x = x / prime[i];
            num++;
        }
        if(num) g[prime[i]].push_back(num);
    }
    if(x > 1)g[x].push_back(1);


}



int main(){
    Prime();

    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        work(a[i]);
    }

    long long ans = 1;
    for(int i = 1; i < top; i++){
        int x = prime[i];
        sort(g[x].begin(), g[x].end());
        if(g[x].size() == n){
          //  cout <<x << endl;
            for(int j = 1; j <= g[x][1]; j++)
                ans *= 1ll*x;
        }else if(g[x].size() == n - 1){
           // cout << x <<" " << g[x][0] << endl;
            for(int j = 1; j <= g[x][0]; j++){
                ans *= 1ll*x;
            }
        }
    }
    printf("%lld\n", ans);




}