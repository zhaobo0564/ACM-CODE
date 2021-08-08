#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int q, a[N], n, vis[2 * N];

int main(){
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        vis[a[i]]++;
    }
    while(q--){
        int k, x, y;
        scanf("%d %d %d", &k, &x, &y);
        if((a[x] ^ a[y]) == k){
            puts("1");
        }else{
            if(a[x] == a[y]){
                int cnt = k ^ a[x];
                if(vis[cnt]){
                    puts("2");
                }else{
                    puts("-1");
                }
            }else{
                puts("-1");
            }
        }

    }
}