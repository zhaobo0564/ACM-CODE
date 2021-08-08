#include<bits/stdc++.h>
using namespace std;


struct node{
    node *p[26];
    int v;
    node(){
        v = 0;
        for(int i = 0; i < 26; i++){
            p[i] = NULL;
        }
    }
};

node root;

void build(string s){
    node *now = &root;
    for(int i = 0; i < s.length(); i++){
        int pos = s[i] - 'a';
        if(now->p[pos] == NULL){
            now->p[pos] = (struct node *)malloc(sizeof(struct node));
            now  = now->p[pos];
            for(int i = 0; i < 26; i++){
                now->p[i] = NULL;
            }
            now->v = 1;
        }else{
            now = now->p[pos];
            now->v++;
        }
    }
}


int query(string s){
    node *now = &root;
    for(int i = 0; i < s.length(); i++){
        int pos = s[i] - 'a';
        if(now->p[pos] == NULL){
            return 0;
        }
        now = now->p[pos];
    }
    return now->v;
}

int main(){
    string a;
    char str;
    while(1){
        a = "";
        while(str = getchar()){
            if(str == '\n')break;
            a += str;
        }
        if(a.length() == 0)break;
        build(a);
    }
    //aprintf("888\n");
    while(cin>>a){
        printf("%d\n", query(a));
    }
}