#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], n;

int vis[N];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        vis[a[i]]++;
    }
    vector<int>up, down;
    for(int i = 0; i < N; i++){
        if(vis[i]){
            up.push_back(i);
            vis[i]--;
        }
    }
    int ok = 0;
    for(int i = N - 1; i >= 0; i--){
        if(vis[i] == 1){
            down.push_back(i);
        }else if(vis[i] > 1){
            ok = 1;
            break;
        }
    }
    if(ok)puts("No");
    else{
        puts("Yes");
        printf("%d\n", up.size());
        for(int i : up){
            printf("%d ", i);
        }
        puts("");
        printf("%d\n", down.size());
        for(int i: down){
            printf("%d ", i);
        }
        puts("");
    }
}