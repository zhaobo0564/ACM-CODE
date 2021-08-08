#include<bits/stdc++.h>
using namespace std;

const int N = 1007;

int a[N], n;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    vector<int>ans;
    int pos = 0;
    long long maxn = 0;
    for(int i = 1; i <= n; i++){
        vector<int> v;
        int cnt = a[i];
        for(int j = i - 1; j; j--){
    
            if(cnt >= a[j]){
                v.push_back(a[j]);
                cnt = a[j];
            }else{
                v.push_back(cnt);
                //cnt = a[j + 1];
            }
        }
        reverse(v.begin(), v.end());
        v.push_back(a[i]);
        cnt = a[i];
        for(int j = i + 1; j <= n; j++){
            if(cnt >= a[j]){
                v.push_back(a[j]);
                cnt = a[j];
            }else{
                v.push_back(cnt);
        
            }
        }
        long long sum = 0;
        for(int j: v){
            sum += 1ll * j;
        }
        if(sum > maxn){
   
            maxn = sum;
            ans.clear();
            for(int j: v){
                ans.push_back(j);
            }
        }

    }

    for(int i: ans){
        printf("%d ", i);
    }
    puts("");
}