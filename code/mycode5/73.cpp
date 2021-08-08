#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long,long long >
#define f first
#define s second
const int MAXN = 1e5+5;
typedef long long ll;
ll x,y;ll s_x;ll s_y;
unordered_map<ll,bool> m;

ll cor(ll X,ll Y){
    return (X-s_x)+1e7*(Y-s_y);
}
void solve(){
    m.clear();
    scanf("%lld%lld",&x,&y);
    static queue<pll> Q;
    while(!Q.empty()){
        Q.pop();
    }
    ll cnt=0;
    ll fenmu = 0;
    ll fenzi = 0;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(__gcd(x+i,y+j)!=1){
                fenzi++;
            }
        }
    }
    s_x = x-2e5;
    s_y = y-2e5;
    Q.push({x,y});
    m[cor(x,y)]=1;
    while((!Q.empty())&&cnt<MAXN){
        auto p = Q.front();    Q.pop();
//        printf("search %lld,%lld\n",p.f,p.s);
        cnt++;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                ll now_x = p.f+i;
                ll now_y = p.s+j;
                if(now_x==now_y){
                    printf("0/1\n");
                    return;
                }
                if(__gcd(now_x,now_y)!=1){
                    fenmu++; 
                    if(m[cor(now_x,now_y)]){
                        continue;
                    } 
                    Q.push({now_x,now_y});
                    m[cor(now_x,now_y)]=1;
                }
            }
        } 
    }
    if(!Q.empty()){
        printf("0/1\n");
    }
    else{
        ll yue = __gcd(fenzi,fenmu);
        printf("%lld/%lld\n",fenzi/yue,fenmu/yue);
    }
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}
