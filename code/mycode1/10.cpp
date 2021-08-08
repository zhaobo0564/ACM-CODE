#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int a[N], t, n, vis[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            vis[a[i]]++;
        }
        int maxn = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i] > maxn){
                maxn = vis[i];
            }
        }
        int sum = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i]){
                sum++;
            }
        }
        if(sum > maxn){
            printf("%d\n", maxn);
        }else if(sum == maxn){
            printf("%d\n", maxn - 1);
        }else{
            printf("%d\n", sum);
        }
        for(int i = 1; i <= n; i++){
            vis[a[i]] = 0;
        }
    }
}