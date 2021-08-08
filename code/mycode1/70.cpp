#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

int work(int a, int b, vector<int>&v){
    int ans = 0, f = 0;
    for(int i = 0; i < v.size(); i++){
      //  cout << f << " " << v[i] << endl;
        if(f == 0 && v[i] == a){
            
            ans += i;
            f++;
        }
        else if(f == 1 && v[i] == b){
           // cout << "i = " << i << endl;
            ans += i - 1;
            f++;
            break;
        }
    }
 //   cout << f << " " << ans << endl;
    if(f == 2)return ans;
    return -1;
}

int main(){
    scanf("%lld", &n);
    vector<int>g;
    while(n){
        g.push_back(n % 10);
        n = n / 10;
    }        
    int ans = INT_MAX;
    int cnt;
    //work(0, 5, g);
    cnt = work(0, 0, g);
    if(cnt >= 0)ans = cnt;
    cnt = work(2, 5, g);
    if(cnt >= 0)ans = min(ans, cnt + 1);
    cnt = work(5, 2, g);
    if(cnt >= 0)ans = min(ans, cnt);
    cnt = work(5, 0, g);
    if(cnt >= 0)ans = min(ans, cnt + 1);
    cnt = work(0, 5, g);
    if(cnt >= 0)ans = min(ans, cnt);
    cnt = work(7, 5, g);
    if(cnt >= 0)ans = min(ans, cnt + 1);
    cnt = work(5, 7, g);
    if(cnt >= 0)ans = min(ans, cnt );
    if(ans == INT_MAX)puts("-1");
    else printf("%d\n", ans);

}
