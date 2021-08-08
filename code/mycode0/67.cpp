#include<bits/stdc++.h>
using namespace std;
map<string, double>v;


int main(){
    v["A"] = 4.0, v["A-"] = 3.7, v["B+"] = 3.3, v["B"] = 3.0;
    v["B-"] = 2.7, v["C+"] = 2.3, v["C"] = 2.0, v["C-"] = 1.7;
    v["D"] = 1.3, v["D-"] = 1.0, v["F"] = 0;

    int n;
    string s;

    while(~scanf("%d", &n)){
        int ans = 0;
        double sum = 0.0;
        for(int i = 1; i <= n; i++){
            int t; scanf("%d", &t);
            cin >> s;
            if(s == "N" || s == "P")continue;
            ans += t;
            sum += v[s] * t;
        }
        if(sum == 0|| ans == 0){
            puts("0.00");
        }else{
            printf("%.2lf\n", sum / ans);
        }
       

    }
}