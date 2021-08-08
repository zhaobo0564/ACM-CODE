#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+ 7;
vector<int>pos[N];
vector<int>g;
  
vector<int>zheng;
vector<int>fu;
int a[N];
  
int get_id(int x){
    return lower_bound(g.begin(), g.end(), x) - g.begin();
}
  
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(a[i] >= 0){
            zheng.push_back(a[i]);
        }else{
            fu.push_back(a[i]);
        }
        g.push_back(a[i]);
    }
    sort(zheng.begin(), zheng.end());
    sort(fu.begin(), fu.end());
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    for(int i = 1; i <= n; i++){
        int po = get_id(a[i]);
        pos[po].push_back(i);
    }
  
    int minn = INT_MAX;
    int minn_pos = INT_MAX;
    for(int i = 1; i <= n; i++){
        int ans = INT_MAX;
        if(a[i] >= 0){
            int p = lower_bound(fu.begin(), fu.end(), -a[i]) - fu.begin();
            if(p >= 0 && p < fu.size())
                ans = min(ans, abs(a[i] + fu[p]));
            if(p + 1 < fu.size()){
                ans = min(ans, abs(fu[p + 1] + a[i]));
            }
            if(p - 1 >= 0){
                ans = min(ans, abs(fu[p - 1] + a[i]));
            }
            if(zheng.size()){
                int po = get_id(zheng[0]);
                if(pos[po].size() == 1 && zheng[0] == a[i]){
                    if(zheng.size() > 1){
                        ans = min(ans, abs(a[i] + zheng[1]));
                    }
                }
                else ans = min(ans, abs(a[i] + zheng[0]));
            }
                 
        }else{
            int p = lower_bound(zheng.begin(), zheng.end(), -a[i]) - zheng.begin();
            if(p >= 0 && p < zheng.size())
                ans = min(ans, abs(a[i] + zheng[p]));
            if(p + 1 < zheng.size()){
                ans = min(ans, abs(zheng[p + 1] + a[i]));
            }
            if(p - 1 >= 0){
                ans = min(ans, abs(zheng[p - 1] + a[i]));
            }
            if(fu.size()){
                int po = get_id(a[i]);
                if(pos[po].size() == 1 && fu[fu.size() - 1] == a[i]){
                    if(fu.size() > 1){
                        ans == min(ans, abs(fu[fu.size() - 2] + a[i]));
                    }
                }
                else
                    ans = min(ans, abs(fu[fu.size() - 1] + a[i]));
            }
        }
        minn = min(ans, minn);
    }
  
    for(int i = 1; i <= n; i++){
        int ans = INT_MAX;
        if(a[i] >= 0){
            int p = lower_bound(fu.begin(), fu.end(), -a[i]) - fu.begin();
            ans = INT_MAX;
            if(p >= 0 && p < fu.size()){
                 ans = min(ans, abs(a[i] + fu[p]));
                 if(ans == minn){
                     int po = get_id(fu[p]);
                  if(pos[po][0] == i)continue;
                     minn_pos = min(minn_pos, i + pos[po][0]);
                 }
            }
            ans = INT_MAX;
            if(p + 1 < fu.size()){
                ans = min(ans, abs(fu[p + 1] + a[i]));
                if(ans == minn){
                    int po = get_id(fu[p + 1]);
                    if(pos[po][0] == i)continue;
                    minn_pos = min(minn_pos, i + pos[po][0]);
                }
            }
            ans = INT_MAX;
            if(p - 1 >= 0){
                ans = min(ans, abs(fu[p - 1] + a[i]));
                if(ans == minn){
                    int po = get_id(fu[p - 1]);
                    if(pos[po][0] == i)continue;
                    minn_pos = min(minn_pos, i + pos[po][0]);
                }
                  
            }
            ans = INT_MAX;
            if(zheng.size()){
                int po = get_id(zheng[0]);
                if(pos[po].size() == 1 && zheng[0] == a[i]){
                    if(zheng.size() > 1){
                        ans = min(ans, abs(a[i] + zheng[1]));
                        if(ans == minn){
                            int po = get_id(zheng[1]);
                            if(pos[po][0] == i)continue;
                            minn_pos = min(minn_pos, pos[po][0] + i);
                            ans = INT_MAX;
                        }
                    }
                }
             
                else {
                    ans = min(ans, abs(a[i] + zheng[0]));
                if(ans == minn){
                    int po = get_id(zheng[0]);
                    if(pos[po][0] == i)continue;
                    minn_pos = min(minn_pos, i + pos[po][0]);
                }
                }
            }
          
        }else{ans = INT_MAX;
            int p = lower_bound(zheng.begin(), zheng.end(), -a[i]) - zheng.begin();
            if(p >= 0 && p < zheng.size())
                ans = min(ans, abs(a[i] + zheng[p]));
                if(ans == minn){
                     int po = get_id(zheng[p]);
                     if(pos[po][0] == i)continue;
                    minn_pos = min(minn_pos, i + pos[po][0]);
                }
               ans = INT_MAX;
            if(p + 1 < zheng.size()){
                ans = min(ans, abs(zheng[p + 1] + a[i]));
                if(ans == minn){
                    int po = get_id(zheng[p + 1]);
                    if(pos[po][0] == i)continue;
                    minn_pos = min(minn_pos, i + pos[po][0]);
                }
                   
            }ans = INT_MAX;
            if(p - 1 >= 0){
                ans = min(ans, abs(zheng[p - 1] + a[i]));
                if(ans == minn){
                    int po = get_id(zheng[p - 1]);
                    if(pos[po][0] == i)continue;
                    minn_pos = min(minn_pos, i + pos[po][0]);
                }
                   
            }ans = INT_MAX;
            if(fu.size()){
                int po = get_id(a[i]);
                if(pos[po].size() == 1 && fu[fu.size() - 1] == a[i]){
                    if(fu.size() > 1){
                        ans == min(ans, abs(fu[fu.size() - 2] + a[i]));
                        if(ans == minn){
                            int po = get_id(fu.size() - 2);
                           // if(pos[po][0] == i)continue;
                            minn_pos = min(minn_pos, i + pos[po][0]);
                            ans = INT_MAX;
                        }
                    }
                }
                else
                    ans = min(ans, abs(fu[fu.size() - 1] + a[i]));
                if(ans == minn){
                    int po = get_id(fu[fu.size() - 1]);
                   // if(pos[po][0] == i)continue;
                    minn_pos = min(minn_pos, pos[po][0] + i);
                }
                
            }
  
        }
      
    }
    cout << minn << " " << minn_pos << endl;
  
}