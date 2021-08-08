#include<iostream>
#include<malloc.h>
#include<string>
#include<cstring>
using namespace std;
const int N = 100000;

struct node{
 int p[10];
 int v;   
}tree[N];



int  root;
int ans = 0;
int cnt = 0;
int ok = 0;

void build(string a){
    int now = root;
    for(int i = 0; i < a.length(); i++){
        int pos = a[i] - '0';
        if(tree[now].p[pos] == 0){
            tree[now].p[pos] = ++cnt;
            now = cnt;
        }else{
            now = tree[now].p[pos];
            if(tree[now].v){
                ok = 1;
                break;
            }
            
        }
    }
    for(int i = 0 ; i < 10; i++){
        if(tree[now].p[i]){
            ok = 1;
            break;
        }
    }
   tree[now].v++;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int t; cin>>t;
    string s;
    while(t--){
        cnt = 0;
        int n;
        cin >> n;
        ok = 0;
        while(n--){
            cin >> s;
            if(ok)continue;
            build(s);
        }
        if(!ok){
            puts("YES");
        }else{
           puts("NO");
        }
        memset(tree, 0, sizeof(tree));
    }
   
}