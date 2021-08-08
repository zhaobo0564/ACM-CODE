#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200000 + 7;

ll n, t, a[N];
vector<ll>positive, negative;

int main(){    
    ll ans = 0;
    scanf("%lld %lld", &n, &t);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        if(a[i] == 0){
            ans++;
        }else if(a[i] > 0){
            positive.push_back(a[i]);
        }else{
            negative.push_back(-a[i]);
        }
    }
    sort(negative.begin(), negative.end());
    positive.push_back(100000000000000);
    negative.push_back(100000000000000);
   
    // positive
    ll cnt = t;
    ll res = 0;
    ll maxn = 0;
    for(int i = 0; i < positive.size() - 1; i++){
        if(cnt >= positive[i]){
            res++;
            ll cn =cnt - positive[i];
            if(cn >= positive[i]){
                ll cat =cn - positive[i];
                int p = upper_bound(negative.begin(), negative.end(), cat) - negative.begin();
                maxn = max(ans + res + p, maxn);

            }
        }else{
            break;
        }
    }
    maxn = max(maxn, res + ans);

    // negative
    res = 0;
    cnt = t;
    for(int i = 0; i < negative.size() - 1; i++){
        if(cnt >= negative[i]){
            ll cn =cnt - negative[i];
            res++;
            if(cn >= negative[i]){
                ll cat = cn - negative[i];
                int p = upper_bound(positive.begin(), positive.end(), cat) - positive.begin();
                maxn = max(ans + res + p, maxn);
            }
        }else{
            break;
        }
    }
    maxn = max(ans + res, maxn);
    printf("%lld\n", maxn);


}   