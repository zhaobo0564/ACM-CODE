#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<double, double> >g;
 
vector<pair<ll, ll> >v;
ll cn[1000];

double eps = 0.000000000000015;
 
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        ll k, b;
        scanf("%lld %lld", &k, &b);
        v.push_back({k, b});
        cn[i] = k;

    }
    int ans = 0;
    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            if(cn[i + 1] == cn[j + 1])continue;
            double x =((double)v[i].second - (double)v[j].second)/((double)v[j].first - (double)v[i].first);
            double y = x * (double)v[i].first + (double)v[i].second;
            int f = 0;
            for(int k = 0 ; k <g.size(); k++){
                if(abs(g[k].first - x) < eps && abs(g[k].second - y) < eps){
                    f = 1;
                    break;
                }
            }
            if(f == 0)
                g.push_back({x, y}), ans++;
           
        }
    }
    

 if(ans == 0){
         printf("No Fire Point.\n");
    }else{
         
        printf("%d\n", ans);
    }
}