#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        string s;
        cin >> s;
        int ok = 0;
        sort(s.begin(), s.end());
        for(int i = 0; i < s.length() - 1; i++){
            if(s[i + 1] - s[i] != 1){
                ok = 1;
                break;
            }
        }
        if(ok)puts("No");
        else puts("Yes");
    }
}