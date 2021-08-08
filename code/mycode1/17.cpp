#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int a[N], n, t;

vector<int>v[208];

int sum[N][207], vis[207];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= 200; i++){
            vis[i] = 0;
            v[i].clear();
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 200; j++){
                sum[i][j] = 0;
            }
        }

        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            v[a[i]].push_back(i);
            vis[a[i]]++;
            for(int j = 1; j <= 200; j++)
                sum[i][j] = vis[j];
        }
        int ans = 0, maxn = 0;

        for(int i = 1; i <= n; i++){
           // cout << "i = " << i << endl;
            int l = sum[i][a[i]];
            maxn = max(maxn, l);
            int toal = v[a[i]].size();
            //cout << "L = " << l << endl;
          //  cout <<"toal = " << toal << " l = " << l << endl;
            if(toal - l <l)continue;
            int r = v[a[i]][toal - l] - 1;
            l = i;
         //   cout << "l = " << l << " r = " << r << endl;
       
            for(int j = 1; j <= 200; j++){ 
                //if(j == 10)
              // cout << sum[r][j] <<" " <<sum[l][j] << endl;
                ans = sum[r][j] - sum[l][j];
             //   cout << "ans = " << ans << endl;
                maxn = max(ans + sum[i][a[i]] * 2, maxn); 
            }
           

        }
        printf("%d\n", maxn);
        
    }
    
}