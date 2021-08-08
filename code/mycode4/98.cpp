#include<bits/stdc++.h>
using namespace std;

const int N = 1007;

int vis[N], a[N];

int t, n;

vector<int>ans;

int get_id(){
    for(int i = 0; i <= n; i++){
        vis[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        vis[a[i]] = 1;
    }
    for(int i = 0; i <= n; i++){
        if(vis[i] == 0){
            return i;
        }
    }
}


int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ans.clear();
        for(int i = 0; i <= n; i++){
            vis[i]= 0;
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        while(1){
            int mx = get_id();
            if(mx == n){
                for(int i = 1; i <= n; i++){
                    if(a[i] != i - 1){
                        a[i] = n;
                        ans.push_back(i);
                        break;
                    }
                }
            }else{
                ans.push_back(mx + 1);
                a[mx + 1] = mx;
            }
            int f = 0;
            for(int i = 1; i <= n; i++){
                if(a[i] != i - 1){
                    f = 1;
                    break;
                }
            }
            if(f == 0)break;
        }
        printf("%d\n", (int)ans.size());
        for(int i : ans){
            printf("%d ", i);
        }
        puts("");

    }
}