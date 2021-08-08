#include<bits/stdc++.h>
using namespace std;

char s[100007];

vector<char>v, b;

int main(){
    int t; scanf("%d", &t);
    while(t--){
        v.clear();
        b.clear();
        int n; scanf("%d", &n);
        scanf("%s", s + 1);
        for(int i = 1; i <= n; i++){
            if(s[i] == '0'){
                v.push_back(s[i]);
            }else{
                break;
            }
        }
        for(int i = n; i; i--){
            if(s[i] == '1'){
                b.push_back('1');
            }else{
                break;
            }
        }
        reverse(b.begin(), b.end());
        if(v.size() + b.size() == n){
            for(auto it: v){
                printf("%c", it);
            }
            for(auto it: b){
                printf("%c", it);
            }
            puts("");
        }else{
            for(auto it: v){
                printf("%c", it);
            }
            printf("0");
            for(auto it: b){
                printf("%c", it);
            }
            puts("");
        }

        
    }
}