#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
int n;
struct power{
    ll x, y;
}p[N];


vector<ll>v;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld%lld", &p[i].x, &p[i].y);
        ll ans = p[i].y*(p[i].x -p[i].y)*(p[i].x -p[i].y);
        v.push_back(ans);
    }
    sort(v.begin(), v.end());
    ll ans =0 ;
    for(int i =1; i < v.size(); i++){
        ans +=v[i]-v[i-1];
    }
    printf("%lld\n",ans);
  

}