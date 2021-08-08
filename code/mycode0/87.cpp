#include<bits/stdc++.h>
using namespace std;

struct node{
    node * p[26];
    int v;
    node(){
        v = 0;
        for(int i = 0; i < 26; i++){
            p[i] = NULL;
        }
    }
    
};

node  root[1000];
int ans = 0;
int cnt = 0;

void build(string a){
    node *now = &root[cnt];
    for(int i = 0; i < a.length(); i++){
        int pos = a[i] - 'a';
       // cout <<"pos = " << pos << endl;
        if(now->p[pos] == NULL){
            now->p[pos] = (struct node*)malloc(sizeof(node));
            now = now->p[pos];
            for(int i = 0; i < 26; i++){
                now->p[i] = NULL;
            }
            now->v = 0;
           // cout <<"***\n";
        }else{
            now =  now->p[pos];
        }
    }
    if(now->v == 0){
        ans++;
        now->v = 1;
    }
}

int main(){
    for(string input; getline(cin, input);){
        if(input == "#")break;
        stringstream ss(input);
        string s;
        while(ss >> s)build(s);
        printf("%d\n", ans);
        cnt++;
        ans = 0;
    
    }
   // printf("%d\n", ans);
}