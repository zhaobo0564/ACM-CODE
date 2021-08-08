#include<bits/stdc++.h>
using namespace std;
const int N = 507;

int mp[N][N], n, m;

int main(){
    int t; scanf("%d", &t);
    while(t--){
      scanf("%d %d", &n, &m);
      int f = 0;
      for(int i = 1; i <= n; i++){
          for(int j = 1; j <= m; j++){
                scanf("%d", &mp[i][j]);
                if(mp[i][j] > 4){
                    f = 1;
                }
          }
      } 
      if(mp[1][1] > 2 || mp[1][m] > 2 || mp[n][1] > 2 || mp[n][m] > 2)f = 1; 
      for(int i = 2; i < n; i++){
          if(mp[i][1] > 3 || mp[i][m] > 3){
              f = 1;
          }
      }  
      for(int i = 2; i < m; i++){
          if(mp[1][i] > 3 || mp[n][i] > 3){
              f = 1;
          }
      }
      
      if(f){
          puts("NO");
      }else{
          mp[1][1] = 2, mp[1][m] = 2, mp[n][1] = 2, mp[n][m] = 2;
         for(int i = 2; i < n; i++){
             mp[i][1] = mp[i][m] = 3;
        }  
        for(int i = 2; i < m; i++){
            mp[1][i] = mp[n][i] = 3;
        }
        for(int i = 2; i < n; i++){
            for(int j = 2; j < m; j++){
                mp[i][j] = 4;
            }
        }
        puts("YES");
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                printf("%d ", mp[i][j]);
            }
            puts("");
        }
      }
    }
    
}