#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 7;

ll a[N], n, k;

struct  lb{
    ll b[63],nb[63],tot; //b为线性基  nb用来求第K小异或值 tot为nb元素个数
    bool flag=false;
    void Init(){    //初始化
        tot=0;
        flag=false;
        memset(b,0,sizeof(b));
        memset(nb,0,sizeof(nb));
    }
    void Ins(ll  x){ //插入
        for(int i=62;i>=0;i--){
            if(x&(1ll<<i)){
                if(!b[i]){
                    b[i]=x;
                    return;
                }
                x^=b[i];
            }
        }
        flag=true;
        return ;
    }
    bool Fin(ll x){ //验证存在性
        if(x==0&&b[0])return 1;
        for(int i=62;i>=1;i--){
            int j=i-1;
            if(x&(1<<j)){
                x^=b[i];
                if(!x)return 1;
            }
        }
        return 0;
    }
    ll Max(ll x){   //求最大值
        ll res=x;
        for(int i=62;i>=0;i--){
            res=max(res,res^b[i]);
        }
        return res;
    }
    ll Min(ll x){   //求最小值
        ll res=x;
        for(int i=0;i<=62;i++){
            if(b[i])res^=b[i];
        }
        return res;
    }
    void build(){   //第K大
        for(int i=62;i>=0;i--){
            if(b[i]==0)continue;
            for(int j=i-1;j>=0;j--){
                if(b[j]==0)continue;
                if(b[i]&(1ll<<j))b[i]^=b[j];
            }
        }
        for(int i=0;i<=62;i++){
            if(b[i])nb[tot++]=b[i];
        }
    }
    ll Kth_Max(ll k){
        if(flag)k--;  //???
        ll res=0;
        if(k==0)return 0;
        if(k>=(1ll<<tot))return -1;
        for(int i=62;i>=0;i--){
            if(k&(1ll<<i))res^=nb[i];
        }
        return res;
    }
}LB;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> k;
    lb cnt;
    cnt.Init();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt.Ins(a[i]);
    }
    cnt.build();

   // ll maxn = cnt.query_max();

    ll l = 1, r = 1e15, ans;
   // cout << cnt.query_kth(17) <<endl;

    while (l <= r) {
        ll m = (l + r) / 2;
        ll x = cnt.Kth_Max(m);
        if (x == -1) {
            r = m -1;
        } else {
            ans = m;
            l = m + 1;
        }
    }
    ll sum = ans;
    l = 1, r = ans, ans = -1;

    while (l <= r) {
        ll m = (l + r) / 2;
        ll x = cnt.Kth_Max(m);
        if (x <= k) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << sum - ans << endl;
    


    


}