#include<bits/stdc++.h>
using namespace std;

char str[107][10000];
int n;

struct node{
    int v, pos;
}p[107];

bool cmp(node a, node b){
    return a.v < b.v;
}



int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        cin >> str[i];
        p[i].v = strlen(str[i]);
        p[i].pos = i;
    }
    sort(p + 1, p + n + 1, cmp);
    int f = 0;
    for(int i = 1; i < n; i++){
        if(!strstr(str[p[i + 1].pos], str[p[i].pos])){
            f = 1;
            break;
        }
    }
    if(f){
        printf("NO\n");
    }else{
        puts("YES");
        for(int i = 1; i <= n; i++){
            cout << str[p[i].pos] << endl;
        }
    }

}