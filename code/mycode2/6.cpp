#include<bits/stdc++.h>
using namespace std;
const int N = 8007;

int  t, n, a[N];
int vis[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int maxn = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            vis[a[i]] ++;

            
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int sum = a[i];
            for(int j = i + 1; j <= n; j++){
                    sum += a[j];
                    if(sum < N &&vis[sum]){
                        //cout << sum << endl;
                        ans+=vis[sum];
                        vis[sum] = 0;
                    }
                 //   cout << "sum = " << sum << endl;
            }
        }
    
        printf("%d\n", ans);
        for(int i = 0; i <= n; i++)vis[i] = 0;


    }
}