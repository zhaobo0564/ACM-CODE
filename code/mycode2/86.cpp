#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +7;
int  n, a[N], vis[N];


vector<int>g;
int get_id(int x){
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

int main(){
    scanf("%d", &n);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        g.push_back(a[i]);
    }
    sort(g.begin(), g.end());
    for(int i = 1; i <= n; i++){
        a[i] = get_id(a[i]);
        //cout << a[i] << " ";
    }
   // cout << endl;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        if(vis[a[i]])continue;
        vis[a[i]] = 1;
        int x = a[i];
        while(1){
             x = a[x];
           // cout << x << endl;
            if(vis[x])break;
            cnt++;
            vis[x] = 1;
        }
       // cout << "8888\n";
        ans += cnt;
    }
    printf("%d\n", ans);
   

}