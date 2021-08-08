#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
char s[N], t[N];

int dp[4000][4000], cnt[4000][4000];

int main(){
    cin >>(s + 1) >> (t + 1);
    int ls = strlen((s + 1));
    int lt = strlen((t + 1));
    for(int i = 1; i <= ls; i++){
        for(int j = 1; j <= lt; j++){
            if(s[i] == t[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                cnt[i][j] = 1;
            }else{
                if(dp[i - 1][j] > dp[i][j - 1]){
                    dp[i][j] = dp[i - 1][j];
                    cnt[i][j] = 2;
                }else{
                    dp[i][j] = dp[i][j - 1];
                    cnt[i][j] = 3;
                }
            }
        }
    }
    vector<char>g;
    int x = ls, y = lt;
   // cout << cnt[x][y]<< endl;
    while(cnt[x][y]){
        if(cnt[x][y] == 1){
            g.push_back(s[x]);
            x--;
            y--;
        }else if(cnt[x][y] == 2){
            x--;
        }else if(cnt[x][y] == 3){
            y--;
        }
    }
    reverse(g.begin(), g.end());
    for(auto it: g){
        cout << it;
    }
    cout << endl;
}