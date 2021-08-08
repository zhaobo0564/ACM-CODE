#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int sum[N][30], vis[30];
string s, t;

int main(){
    int T;scanf("%d", &T);
    while(T--){
        cin >> s >> t;
        memset(vis, 0, sizeof(vis));
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < s.length(); i++){
            vis[s[i] - 'a']++;
            for(int j = 0; j < 26; j++){
                sum[i + 1][j] = vis[j];
            }
        }
        for(int i = 0; i < 26; i++)vis[i] = 0;
        int cn = 0;
        for(int i = 0; i < t.length(); i++){
            vis[t[i] - 'a']++;
        }

        int lt = t.length();
        int ans = 0;
        for(int i = lt; i <= s.length(); i++){
            int f = 0;

            for(int j = 0; j < 26; j++){
                int cnt = sum[i][j] - sum[i - lt][j];
              
                f += abs(cnt - vis[j]);
                    
                
            }
            if(f <= 2){
               // cout <<"i " << i <<" " << f << endl;
                ans++;
            }
          
        }
        printf("%d\n", ans);

    }
}