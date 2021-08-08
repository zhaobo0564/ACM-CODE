#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N];
typedef long long ll;
vector<int>v;

int vis[N];
ll k;

int main(){
    int n;
    scanf("%d %lld", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    int now = 1;
    v.push_back(now);
    vis[now] = 1;
    while(1){
        now = a[now];
        v.push_back(now);
        if(vis[now]){
            break;
        }
        vis[now]++;
    }
    for(int i = 1; i <= n; i++){
        vis[i] = 0;
    }
    int cn = 0;
    int l, r;
    int pos;
    for(int i = 0; i < v.size(); i++){
        if(vis[v[i]]){
            cn = i - (vis[v[i]] - 1);
            pos = (vis[v[i]] - 1);
            l = vis[v[i]] - 1;
            r = i - 1 ;
            break;  
        }
        vis[v[i]] = i + 1;
    }
    // for(int i: v){
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << cn << endl;
    if(k < v.size()){
        printf("%d\n", v[k]);
    }else{
        k -= pos;
        k = k % cn;
       // cout << "k = " << k << endl;
        printf("%d\n", v[pos + k]);


    }


    
}