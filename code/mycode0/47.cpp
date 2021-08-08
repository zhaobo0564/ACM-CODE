#include<bits/stdc++.h>
using namespace std;
 
map<int, int>v;
int t, p;
 
int getCount(int x, int y){
    int ans = 0;
    while(x >= y){
        ans += x / y;
        x = x / y;
    }
    return ans;
}
 
bool judge(int x){
    for(auto it: v){
        int value = it.first;
        int count = it.second;
        int ans = getCount(x, value);
        if(ans < count) return false;
    }
    return true;
}
 
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &p);
        int n = p;
        for(int i = 2; i <= sqrt(n); i++){
            while(p % i == 0 ) {
                p = p/ i;
                v[i]++;
            }
        }
        if(p != 1) v[p]++;
        int l = 1, r = 1e9;
        while(r >= l){
            int m = (l + r) / 2;
            
            if(judge(m)){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        printf("%d\n", l);
        v.clear();
 
    }
}