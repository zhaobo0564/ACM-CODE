#include<bits/stdc++.h>
using namespace std;
int a[2007], n, t;
vector<pair<int,int> >ans;
int vis[2007];

int main(){
    scanf("%d", &t);
    while(t--){
        ans.clear();
        scanf("%d", &n);
        for(int i = 1; i <= 2*n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= 2 * n; i++){
                vis[i] = 0;
        }
        for(int i = 1; i <= 2 * n; i++){
            for(int j = i + 1; j <= 2 * n; j++){ 
                if(ans.size() == n - 1) break;
                if(a[i] % 2 ==  a[j] % 2 && vis[i] == 0 && vis[j] == 0){
                    vis[i] = 1;
                    vis[j] = 1;
                    ans.push_back({i, j});
                    break;
                }
            }
            if(ans.size() == n - 1)break;
        }
        for(auto it: ans){
            printf("%d %d\n", it.first, it.second);
        }
    }
}