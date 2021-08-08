#include<bits/stdc++.h>
using namespace std;

int n;
char s[1000];


int main(){
    scanf("%d", &n);
    scanf("%s", (s + 1));
    int b = 0, w = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == 'B')b++;
        else w++;
    }
    if(b == 0 || w ==0){
        puts("0");
    }else if(w % 2 == 0){
        vector<int>v;
        for(int i = 1; i < n; i++){
            if(s[i] == 'W' && s[i + 1] == 'B'){
                swap(s[i], s[i + 1]);
                v.push_back(i);
            }else if(s[i] == 'W' && s[i + 1] == 'W'){
                v.push_back(i);
                s[i] = 'B';
                s[i + 1] = 'B';
            }
        }
        cout << v.size() << endl;
        for(int i: v){
            printf("%d ", i);
        }
        puts("");
    }else if(b % 2 == 0){
        vector<int>v;
        for(int i = 1; i < n; i++){
            if(s[i] == 'B' && s[i + 1] == 'W'){
                swap(s[i], s[i + 1]);
                v.push_back(i);
            }else if(s[i] == 'B' && s[i + 1] == 'B'){
                v.push_back(i);
                s[i] = 'W';
                s[i + 1] = 'W';
            }
        }
        cout << v.size() << endl;
        for(int i: v){
            printf("%d ", i);
        }
        puts("");
    }else{
        puts("-1");
    }
         

}