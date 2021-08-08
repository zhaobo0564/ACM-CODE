#include<bits/stdc++.h>
using namespace std;
long long a[30], n, t, w, x;
multiset<long long>q;

int main(){
    scanf("%lld", &t);
    int no =0 ,yes =0;
    while(t--){
        q.clear();
        scanf("%lld%lld%lld", &n, &x, &w);
        int f = 0;
        long long sum = 0;
        for(int i = 1; i <= n; i++){
            scanf("%lld",&a[i]);
            q.insert(a[i]);
            if(a[i] > w){
                f = 1;
            }
        }
        long long cnt = min(n, x);
       // cout<<cnt<<endl;
        if( f){
            printf("No\n");
            no++;
            continue;
        }
        while(1){
            auto it =q.begin();
            long long  ans = w - *it;
          //  cout<<*it<<" "<<w<<endl;
            q.erase(it);
            if(q.empty()){
                break;
            }
            it = q.upper_bound(ans);
            while(it != q.begin()){
                it--;
                q.erase(it);
              //  cout<<*it <<" " << ans<<endl;
                if(q.empty()){
                    break;
                }
                ans -= *it;
                it = q.upper_bound(ans);
            }
            if(cnt){
                cnt--;
            }
            if(cnt == 0){
                break;
            }
            if(q.empty()){
                break;
            }
        }
        if(q.empty()){
            printf("Yes\n");
            yes++;
        }else{
            printf("No\n");
            no++;
        }

    }
    cout<<yes <<" "<<no<<endl;
}