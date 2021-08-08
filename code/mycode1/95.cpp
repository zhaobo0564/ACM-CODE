#include<bits/stdc++.h>
using namespace std;
bitset<1000007>dp[107];

int main(){
   int n, l, r;
   scanf("%d", &n);
   for(int i = 1; i <= n; i++){
       scanf("%d %d", &l, &r);
       for(int j = l; j <= r; j++){
           g[i].push_back(j * j);
       }
   }
   for(int i : g[1])dp[1][i] = 1;
   for(int i = 2; i <= n; i++){
      for(int j : g[i]){
          dp[i] |= (dp[i - 1] << j);
        
      }
         
    }
    printf("%d\n", dp[n].count());

}