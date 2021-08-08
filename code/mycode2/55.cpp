#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
int n;
long long a[N], b[N];

struct node{
    int x, y, z;
};
vector<node>g;

map<ll, int>q;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        q[a[i]]++;
    }
    ll cnt;
    int maxn = 0;
    for(int i = 1; i <= n; i++){
        if(maxn < q[a[i]]){
            maxn = q[a[i]];
            cnt = a[i];
        }
    }
  
    int pos;
    for(int i = 1; i <= n; i++){
        if(a[i] == cnt){
            pos = i;
            break;
        }
    }
    for(int i = pos - 1; i; i--){
        if(a[i + 1] > a[i] ){
            g.push_back({1, i, i + 1});
            a[i] = cnt;
        }else if(a[i + 1] < a[i]){
            g.push_back({2, i, i + 1});
            a[i] = cnt;
        }
    }
    for(int i = pos + 1; i <= n; i++){
        if(a[i] > a[i - 1]){
            g.push_back({2, i, i - 1});
            a[i] = cnt;
        }else if(a[i] < a[i - 1]){
            g.push_back({1, i, i - 1});
            a[i] = cnt;
        }
    }
    printf("%d\n", g.size());
    for(auto it: g){
        printf("%d %d %d\n", it.x, it.y, it.z);
    }

   

}