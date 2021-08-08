#include<bits/stdc++.h>
using namespace std;

int n;
int mp[5000][5000];
vector<pair<int, int> >g;

int main(){
    scanf("%d", &n);
    mp[0][0] = mp[0][1] = 1;
    mp[n + 1][n] = mp[n + 1][n + 1] = 1;
    for(int i = 1; i <= n; i++)mp[i][i] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(mp[i][j] == 1){
                mp[i][j - 1] = 1;
                mp[i][j + 1] = 1;
                break;
            }
        }
    }
    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= n + 1; j++){
            if(mp[i][j]){
                g.push_back({i, j});
            }
        }
    }
    cout << g.size() << endl;
    for(auto it: g){
        cout << it.first <<" " << it.second << endl;
    }
    
}