#include<bits/stdc++.h>
using namespace std;

int t;
string s;
map<string, int>v;


int main(){
    v["B"] = 0, v["KB"] = 1, v["MB"] = 2, v["GB"] = 3, v["TB"] = 4;
    v["PB"] = 5, v["EB"] = 6, v["ZB"] = 7, v["YB"] = 8;
    scanf("%d", &t);
    int ca = 0;
    while(t--){
        cin >> s;
        long long ans = 0;
        string a = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '['){
                for(int j = i + 1; j <s.length(); j++){
                    if(s[j] == ']')break;
                    a += s[j];
                }
                break;
            }
            ans = ans * 10 + s[i] - '0';
        }
        long long ans1 = 1;
        ans = 1;
        for(int i = 1; i <= v[a]; i++){
            ans = ans * 1000;
            ans1 = ans1 * 1024;
        }
        double f = (double)ans / (double)ans1;
        f = 1 - f;
        f = f * 100;
        printf("Case #%d: ", ++ca);
        if(a == "ZB") printf("%.2lf%%\n", 15.296705274569966);
        else if(a == "YB") printf("%.2lf%%\n", 17.281938744697234);
        else printf("%.2lf%%\n", f);
    
    }

}