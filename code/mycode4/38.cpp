#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int t, n, k;
typedef long long ll;
ll a[N];
int w[N];

bool cmp(ll x, ll y){
    return x > y;
}

int main(){
    cout << sizeof(long long ) << endl;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
        }
        for(int i = 1; i <= k; i++){
            scanf("%d", &w[i]);
        }
        sort(a + 1, a + n + 1, cmp);
        sort(w + 1, w + k + 1);
        ll sum = 0;
        int p = 1;
        int l = n;
        int pos = 0;
        for(int i = 1; i <= k; i++){
            if(w[i] == 1){
                sum += a[p] + a[p];
                p++;
                pos = i;
            }else{
                break;
            }
        }
        for(int i = k; i > pos; i--){
            ll mxn = a[p], minn= a[l];
          //  cout << "i " << i << " " << w[i] << endl;
            for(int j = 2; j <= w[i]; j++){
                minn = min(minn, a[l]);
                l--;
            }
            p++;
           // cout << mxn << " " << minn << endl;
            sum += mxn + minn;
        }
        printf("%lld\n", sum);

    }
}