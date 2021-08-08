#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int vis[1007];

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        v.clear();
        scanf("%d", &n);
        if(n == 4){
            cout << 3 <<" " << 1 <<" " << 4 << " " << 2<< endl;
            continue; 
        }

        for(int i = 1; i <= n; i++) vis[i] = 0;
        if(n == 2 || n == 3)puts("-1");
        else{
            int ans = 1;
            for(int i = 1; i <= n / 5; i++){
                int sum = ans;
                for(int j = 1; j <= 5; j++){
                    v.push_back(sum);
                    if(j % 2 == 1)sum += 3;
                    else sum -= 2;
                }
                ans += 5;
            }
            ans--;
            if(n % 5 == 1){
                v.push_back(ans + 1);
            }else if(n % 5 == 2){
                if(v.size())v.pop_back();
                v.push_back(ans + 2);
                v.push_back(ans - 2);
                v.push_back(ans + 1);
            }else if(n % 5 == 3){
                if(v.size())v.pop_back();
                v.push_back(ans + 2);
                v.push_back(ans - 2);
                v.push_back(ans + 1);
                v.push_back(ans + 3);
            }else if(n % 5 == 4){
                if(v.size())v.pop_back();
                v.push_back(ans + 3);
                v.push_back(ans + 1);
                v.push_back(ans - 2);
                v.push_back(ans + 2);
                v.push_back(ans + 4);
            }
            for(int i: v){
                printf("%d ", i);
            }
            puts("");

        }
            
    }
}