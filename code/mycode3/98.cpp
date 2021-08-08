#include<bits/stdc++.h>
using namespace std;
int t, n, k,vis[200];
string s;

vector<int>v;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    scanf("%d", &t);
    while(t--){
        v.clear();
        for(int i = 'a'; i <= 'z'; i++)vis[i] = 0;
        int n, k;
        scanf("%d %d", &n, &k);
        cin >> s;
        for(auto it: s){
            vis[it]++;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(k % i == 0){
                for(int j = 1; j * i <= n; j++){
                    int cnt = 0;
                    for(int i = 'a'; i <= 'z'; i++){
                        cnt += vis[i] / j;
                    }
                    if(cnt >= i){
                        ans = max(ans, i * j);
                    }
                }
            }
        }
        printf("%d\n", ans);
       
    }
}