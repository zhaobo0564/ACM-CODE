#include<bits/stdc++.h>
using namespace std;

int k;
vector<int>g[20];

vector<int>v;



int main(){
    int t; scanf("%d", &t);
    for(int i = 0; i < 10; i++){
        g[1].push_back(i);
    }
    g[2].push_back(2), g[2].push_back(3), g[2].push_back(5), g[2].push_back(6), g[2].push_back(8), g[2].push_back(9);
    g[2].push_back(0);
    g[3].push_back(3), g[3].push_back(6), g[3].push_back(9);
    for(int i = 4; i <= 9; i++){
        g[4].push_back(i);
        if(i >= 7){
            g[7].push_back(i);
        }
    }
    g[4].push_back(0);
    g[5].push_back(5), g[5].push_back(6), g[5].push_back(8), g[5].push_back(9), g[5].push_back(0);
    g[6].push_back(6), g[6].push_back(9);
    g[7].push_back(0);
    g[8].push_back(8), g[8].push_back(9), g[8].push_back(0);
    g[9].push_back(9);g[0].push_back(0);

    for(int i = 1; i < 10; i++){
        for(int j: g[i]){
            v.push_back(j);
            int ans = j;
            for(int k : g[j]){
                int an = ans * 10 + k;
                v.push_back(an);
                for(int z: g[k]){
                    int a = an * 10 + z;
                    v.push_back(a);
                }
            }
        }
    }

    while(t--){
        scanf("%d", &k);
        int minn = 10000, ans;
        for(int i : v){
            int cn = abs(i - k);
            if(cn < minn){
                minn = cn;
                ans = i;
            }
        }
        printf("%d\n", ans);
        



    }
  

}