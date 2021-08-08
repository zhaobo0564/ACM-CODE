#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
ll a[40] ,fn[80];
int vis[100];

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int ans = 0 , f = 0 , l;
        scanf("%d%d", &n, &k);
        fn[0] = 1;
        for(int i = 1 ;i < 70 ;i++){
            if (1ll*fn[i - 1]*k<0)break;
            fn[i] = 1ll*fn[i - 1] * k;
            l = i;
            if(fn[i] > 10000000000000009){
                break;
            }
        }
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
            if(a[i] == 0)continue;
            for(int j = l; j >= 0; j--){
                if(a[i] >= fn[j]){
                    vis[j]++;
                    a[i] -= fn[j];
                }
            }
            if(a[i]){
                f = 1;
            }
         
        }
        for(int i = 0; i <= l; i++){
            if(vis[i]>1){
                f = 1;
                break;
            }
        }
        if(f){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
        for(int i = 0; i < 100; i++){
            vis[i] = 0;
        }


    

    }
}