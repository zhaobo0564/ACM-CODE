#include<bits/stdc++.h>
using namespace std;

vector<int>v;

int main(){
    int t, a, b, c;
    scanf("%d", &t);
    while(t--){
        v.clear();
        scanf("%d %d %d", &c, &b, &a);
        if(a)v.push_back(1);
        for(int i = 1; i <= a; i++){
            v.push_back(1);
        }
        if(a == 0 && b)v.push_back(1);
        for(int i = 1; i <= b; i++){
            if(i % 2 == 1){
                v.push_back(0);
            }else{
                v.push_back(1);
            }
        }
        if(v.size() == 0)v.push_back(0);
        if(v[v.size() - 1] == 1){
            v.pop_back();
            for(int i = 1; i <= c; i++){
                v.push_back(0);
            }
            v.push_back(1);
        }else{
            for(int i = 1; i <= c; i++){
                v.push_back(0);
            }
        }
        
        for(int i: v){
            printf("%d", i);
        }
        puts("");


    }
}