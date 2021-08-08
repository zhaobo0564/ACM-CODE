#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int a[N], t, x;
typedef long long ll;
const ll mod = 1e9 + 7;
char s[N];
vector<int>v;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %s", &x, (s + 1));
        int n = strlen(s + 1);
        v.clear();
        for(int i = 1; i <=n ; i++){
            v.push_back(s[i] - '0');
        }
        int l = 1;
        
        while(1){
  
            if(v[l - 1] > 1){
                int cnt = v.size() - 1;
                for(int i = 1; i < v[l - 1]; i++){
                    for(int j = l; j <= cnt; j++){
                        v.push_back(v[j]);
                        //if(v.size() >= x)break;
                    }
                   // if(v.size() >= x)break;
                }
            }
            l++;
            if(v.size() >= x)break;
            
        }
        ll cnt = 1ll *v.size();
       
        while(l <= x){
            cnt =(cnt + ((cnt - l + mod ) % mod * (v[l - 1] - 1 ) % mod ) % mod) % mod;
            cnt %= mod;
            l++;
        }
        printf("%lld\n", cnt);
    
    }
}