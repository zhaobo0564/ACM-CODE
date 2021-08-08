#include<bits/stdc++.h>
using namespace std;

int n, k, a[1000], vis[200];

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        vis[a[i]] = i;

    }
    vector<int>q;
    for(int i = 1; i <= 100; i++){
        if(vis[i]){
            q.push_back(vis[i]);
        }
    }
    if(q.size() < k){
        printf("NO\n");
    }else{
        puts("YES");
        for(int i = 0; i < k; i++){
            printf("%d ", q[i]);
        }
        puts("");
    }


}