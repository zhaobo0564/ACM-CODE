#include<bits/stdc++.h>
using namespace std;
string s;

int vis[20];
int t;
int ans[20];
int toal;
int ans = 0;
vector<int>q;

void dfs(int p, int sum, int va){
    if(p == toal){
        if(va % 3 == 0){
            if(sum > ans){
                ans = sum;
            }
        }
        return;
    }

    dfs(p + 1, sum|(1<<(p + 1)), va + q[p + 1]);
    dfs(p + 1, sum, va);
    

}

int main(){
    int k;
    scanf("%d", &t);
    while(t--){
        cin >> s;
        scanf("%d", &k);
        for(int j = 0; j < s.length(); i++){
            int pos = s[j] - '0';
            vis[pos]++;
        }

        long long sum = 0;
        for(int i = 9; i >=0; i--){
            if(i % 3 == 0){
                if(k >= vis[i]){
                    ans[i] = vis[i];
                    k -= vis[i];
                    vis[i] = 0;
                }else{
                    ans[i] = k;
                    vis[i] -= k;
                    k = 0;
                }
            }else{
                if(k >= vis[i]){
                    int cnt = vis[i]%3;
                    k -= (vis[i] - cnt);
                    ans[i] = vis[i] - cnt;
                    vis[i] = cnt;

                }
            }
        }
        for(int i = 9; i >=0; i--){
            if(vis[i]){
               for(int j = 1; j <= vis[i]; j++){
                   q.push_back(i);
               }
            }
        }
        reverse(q.begin(), q.end());
        toal = q.size();

        vector<int>g[20];


        for(int i = 9; i >= 0; i--){
            if(vis[i]){
                ans = 0;
                dfs(0, 1, q[0]);
                dfs(0, 0, 0);
                int cnt = 0;
                while(ans){
                    if(ans & 1){
                        g[i].push_back(q[cnt]);
                    }
                    ans =  ans / 2;
                    cnt++;
                }
                reverse(g[i].begin(), g[i].end());


            }
        }

    }
}