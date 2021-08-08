#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int n, sum[N][3], a[N], b[N];
char s[N];

vector<pair<int, int> >v;

int main(){
    scanf("%d", &n);
    scanf(" %s", (s + 1));
    for(int i = 1; i <= n; i++){
        a[i] = s[i] - 'A';
    }

    int l = 1, r = n;
    int zero = 0, one = 0, two = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0){
            zero++;
        }else if(a[i] == 1){
            one++;
        }else if(a[i] == 2){
            two++;
        }
        sum[i][0] = zero;
        sum[i][1] = one;
        sum[i][2] = two;
    }
    v.push_back({zero, 0});
    v.push_back({one, 1});
    v.push_back({two, 2});
    v.push_back({0, 0});
    int ans = INT_MAX;
    int f = 1;
    for(int i = 1; i <= n; i++){
        int res = 0;
        int l = 0; 
        int r = 0;
        for(int j = 0; j < v.size(); j++){
     
            r += v[j].first;  
            if(v[j].second == 0){
                    res += v[j].first - (sum[r][0] - sum[l][0]);
            }else if(v[j].second == 1){
                    res += v[j].first - (sum[r][1] - sum[l][1]);
        
            }else if(v[j].second == 2){
                    res += v[j].first - (sum[r][2] - sum[l][2]);
    
                
            }
            l = r;
        }
        v[0].first--;
        v[3].first++;
        if(v[0].first == 0){
            v.erase(v.begin());
            v.push_back({0, f});
            f++;
        }
        ans = min(ans, res);
    }
    v.clear();
    v.push_back({zero, 0});  
    v.push_back({two, 2});
    v.push_back({one, 1});
    v.push_back({0, 0});
     f = 2;
    for(int i = 1; i <= n; i++){
        int res = 0;
        int l = 0; 
        int r = 0;
        for(int j = 0; j < v.size(); j++){
     
            r += v[j].first;   
            if(v[j].second == 0){
                    res += v[j].first - (sum[r][0] - sum[l][0]);
            }else if(v[j].second == 1){
                    res += v[j].first - (sum[r][1] - sum[l][1]);
        
            }else if(v[j].second == 2){
                    res += v[j].first - (sum[r][2] - sum[l][2]);
            }
            l = r;
        }
        v[0].first--;
        v[3].first++;
        if(v[0].first == 0){
            v.erase(v.begin());
            v.push_back({0, f});
            f--;
        }
        ans = min(ans, res);
    }

    printf("%d\n", ans);
}