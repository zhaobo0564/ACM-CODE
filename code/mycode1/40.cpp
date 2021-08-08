#include<bits/stdc++.h>
using namespace std;

const int N = 3e6 + 7;

int  n, t;

int fa[N];

vector<int>g;

struct node{
    int a, b;
    int c;
}p[N],p1[N];

int find(int x){
    if(x != fa[x]){
        return fa[x] = find(fa[x]);
    }
    return x;
}

int get_id(int x){
     return lower_bound(g.begin(), g.end(), x) - g.begin();
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        g.clear();
        for(int i = 0; i <= 3*n; i++)fa[i] = i;
        int ok = 0;
        int top = 1;
        for(int i = 1; i <= n; i++){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            p[i].a = a;
            p[i].b = b;
            p[i].c = c;
            g.push_back(a);
            g.push_back(b);
        }
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());

        for(int i = 1; i <= n; i++){
            if(p[i].c){
                int a = get_id(p[i].a);
                int b = get_id(p[i].b);
                int x = find(a);
                int y = find(b);
                if(x != y){
                    fa[x] = y;
                }
            }else{
                p1[top].a = p[i].a;
                p1[top].b = p[i].b;
                p1[top++].c = 0;
            }
            
        }
        for(int i = 1; i < top; i++){
                int a = get_id(p1[i].a);
                int b = get_id(p1[i].b);
                int x = find(a);
                int y = find(b);
                if(x == y){
                    ok = 1;
                    break;
                }
        }
        

        if(ok)puts("NO");
        else puts("YES");
    }
}