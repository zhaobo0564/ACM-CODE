#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll add[200], erase[200];

char s[100];
ll mp[200][200];


ll dp[55][55][2];

void init() {
    for(int k=1; k< 200; k++)  
        for(int i=1; i< 200; i++)  
            for(int j=1; j< 200; j++)  
                if(mp[i][k]+mp[k][j]<mp[i][j])  
                    mp[i][j]=mp[i][k]+mp[k][j];  
}

ll dfs(int begin, int end, int ok) {
    if (end <= begin) {
        if (ok) return 0;
        return 1e11;
    }
    if (dp[begin][end][ok] != -1) return dp[begin][end][ok];
    ll ans = 1e11;
    if(s[begin] == s[end]) {
        ans = min(ans, dfs(begin + 1, end - 1, ok & 1));
        if (add[s[end]] != -1) {
            ans = min(ans, dfs(begin, end - 1, ok & 1) + add[s[end]]);
        } 
        if (add[s[begin]] != -1) {
            ans = min(ans, dfs(begin + 1, end, ok & 1) + add[s[begin]]);
        }
    
        ll cnt = 1e11;
        for (int i = 'a'; i <= 'z'; i++) {
            if (add[i] != -1) {
                for (int j = 'a'; j <= 'z'; j++)
                    if (mp[i][j] < 1e11 && mp[s[end]][j] < 1e11) {
                        cnt = min(cnt, add[i] + mp[i][j] + mp[s[end]][j]);
                    }
            }
        }
        if (cnt < 1e11) {
            ans = min(ans, dfs(begin, end - 1, ok & 1) + cnt);
        }
        cnt = 1e11;
        for (int i = 'a'; i <= 'z'; i++) {
            if (add[i] != -1) {
                for (int j = 'a'; j <= 'z'; j++) 
                    if (mp[i][j] < 1e11 && mp[s[begin]][j] < 1e11) {
                        cnt = min(cnt, add[i] + mp[i][j] + mp[s[begin]][j] );
                    }
            }
        }
        if (cnt < 1e11) {
            ans = min(ans, dfs(begin + 1, end, ok & 1) + cnt);
        }
        cnt = 1e11;
        for (int i = 'a'; i <= 'z'; i++) {
            if (mp[s[begin]][i] < 1e11 && erase[i] != -1) {
                cnt = min(cnt, mp[s[begin]][i] + erase[i]);
            }
        }
        if (cnt < 1e11) {
            ans = min(ans, dfs(begin + 1, end, ok ) + cnt);
        }
        cnt = 1e11;
        for (int i = 'a'; i <= 'z'; i++) {
            if (mp[s[end]][i] < 1e11 && erase[i] != -1) {
                cnt = min(cnt, mp[s[end]][i] + erase[i]);
            }
        }
        if (cnt < 1e11) {
            ans = min(ans, dfs(begin, end - 1, ok ) + cnt);
        }
        

    } else {
        if (mp[s[begin]][s[end]] < 1e11) {
            ans = min(ans, dfs(begin + 1, end - 1, ok & 1) + mp[s[begin]][s[end]]);
        } 
        if (mp[s[end]][s[begin]] < 1e11) {
            ans = min(ans, dfs(begin + 1, end - 1, ok & 1) + mp[s[end]][s[begin]]);
        }
        ll cnt = 1e11;
        for (int i = 'a'; i <= 'z'; i++) {
            if (mp[s[begin]][i] < 1e11 && mp[s[end]][i] < 1e11) {
                cnt = min(cnt, mp[s[begin]][i] + mp[s[end]][i]);

            }
        }
        if (cnt < 1e11) {
            ans = min(ans, dfs(begin + 1, end - 1, ok & 1) + cnt);
        }
        cnt  = 1e11;
        for (int i = 'a'; i <= 'z'; i++) {
            if (mp[s[begin]][i] >= 1e11) continue;
            for (int j = 'a'; j <= 'z'; j++) {
                if (mp[s[begin]][i] < 1e11 && mp[s[end]][j] < 1e11) {
                    if (erase[i] != -1 && erase[j] != -1) {
                        cnt = min(cnt, mp[s[begin]][i] + mp[s[end]][j] + erase[i] + erase[j]);
                    }
                }
            }
        }
        if (cnt < 1e11) {
            ans = min(ans, dfs(begin + 1, end - 1, ok & 1) + cnt);
        }
        cnt = 1e11;
        for (int i = 'a'; i <= 'z'; i++) {
            if (add[i] != -1) {
                for (int j = 'a'; j <= 'z'; j++)
                    if (mp[i][j] < 1e11 && mp[s[end]][j] < 1e11) {
                        cnt = min(cnt, add[i] + mp[i][j] + mp[s[end]][j]);
                    }
            }
        }
        if (cnt < 1e11) {
            ans = min(ans, dfs(begin, end - 1, ok & 1) + cnt);
        }
        cnt = 1e11;
        for (int i = 'a'; i <= 'z'; i++) {
            if (add[i] != -1) {
                for (int j = 'a'; j <= 'z'; j++) 
                    if (mp[i][j] < 1e7 && mp[s[begin]][j] < 1e7) {
                        cnt = min(cnt, add[i] + mp[i][j] + mp[s[begin]][j] );
                    }
            }
        }
        if (cnt < 1e11) {
            ans = min(ans, dfs(begin + 1, end, ok & 1) + cnt);
        }
        cnt = 1e11;
        for (int i = 'a'; i <= 'z'; i++) {
            if (mp[s[begin]][i] < 1e11 && erase[i] != -1) {
                cnt = min(cnt, mp[s[begin]][i] + erase[i]);
            }
        }
        if (cnt < 1e11) {
            ans = min(ans, dfs(begin + 1, end, ok ) + cnt);
        }
        cnt = 1e11;
        for (int i = 'a'; i <= 'z'; i++) {
            if (mp[s[end]][i] < 1e11 && erase[i] != -1) {
                cnt = min(cnt, mp[s[end]][i] + erase[i]);
            }
        }
        if (cnt < 1e11) {
            ans = min(ans, dfs(begin, end - 1, ok ) + cnt);
        }
        

        
            
    }
    dp[begin][end][ok] = ans;
    return ans;
}

vector<pair<char, ll> > ad, de;

int main() {
    for(int i=1; i< 200; i++)  
        for(int j=1; j< 200; j++)  
            if(i==j)  
                mp[i][j]=0;  
            else  
                mp[i][j]=1e11; 
    cin >> (s + 1);
    int len = strlen(s + 1);
    int n; cin >> n;
    for (int i = 0; i < 200; i++) {
        add[i] = erase[i] = -1;
    }
    while (n--) {
        string op;
        cin >> op;
        if (op == "add") {
            char x; ll v;
            cin >> x >> v;
            add[x] = v;
            ad.push_back({x, v});
            
        } else if (op == "erase") {
            char x; ll v;
            cin >> x >> v;
            erase[x] = v;
            de.push_back({x, v});
        } else {
            char x, y; ll v;
            cin >> x >> y >> v;
            mp[x][y] = min(mp[x][y], v);
          

        }
    }
    for (int i = 0; i < de.size(); i++) {
        for (int j = 0; j < ad.size(); j++) {
            mp[de[i].first][ad[j].first] = min(mp[de[i].first][ad[j].first], de[i].second + ad[j].second);
        }
    }
    init();
    memset(dp, -1, sizeof(dp));
    ll ans = dfs(1, len, 1);
    if (ans >= 1e11) {
        cout << "-1\n";
    } else {
        cout << ans << endl;
    }
    reve
}