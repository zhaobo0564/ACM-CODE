#include<bits/stdc++.h>
using namespace std;

string s;
int vis[200];

int main(){
    int t; scanf("%d", &t);
    while(t--){

        for(int i = 1; i <= 199; i++)vis[i] = 0;
        cin >> s;
        for(int i = 0; i < s.length(); i++){
            vis[s[i]]++;
        }
        vector<char>v;
        if(vis['A'] == 0){
            v.push_back('A');
        }
        if(vis['C'] == 0){
            v.push_back('C');
        }
        if(vis['M'] == 0){
            v.push_back('M');
        }
        if(v.size() == 0){
            puts("-1");
        }else{
            for(auto it: v){
                printf("%c", it);
            }
            puts("");
        }
    }

}