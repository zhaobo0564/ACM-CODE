#include<bits/stdc++.h>
using namespace std;
const int N = 1007;

int a[N], n, vis[N];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        vis[a[i]]++;
    }
    int ans = vis[1];
    vector<int>g;
    for(int  i = 2; i <= n; i++){
        if(a[i] == 1){
            g.push_back(a[i - 1]);
        }
    }
    g.push_back(a[n]);
    cout << ans << endl;
    for(int j : g){
        cout << j <<  " ";
    }
    cout << endl;

   



}