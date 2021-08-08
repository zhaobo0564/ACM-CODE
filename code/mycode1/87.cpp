#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int tree[4 * N], flag[4 * N];
int n, mm;

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void build(int l, int r, int node){
    flag[node] = 0;
    if(l == r){
        tree[node] = 4;
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    tree[node] = tree[lson] | tree[rson];
}

void push_down(int node){
    if(flag[node]){
        tree[lson] = flag[node];
        tree[rson] = flag[node];
        flag[lson] = flag[node];
        flag[rson] = flag[node];
        flag[node] = 0;
    }
}

void update(int v, int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        tree[node] = (1 << v);
        flag[node] = (1 << v);
        return;
    }
    push_down(node);
    if(ql <= m) update(v, ql, qr, l, m, lson);
    if(qr > m) update(v, ql, qr, m + 1, r, rson);
    tree[node] = tree[lson] | tree[rson];
}

int query(int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r)return tree[node];
    int ans = 0;
    push_down(node);
    if(ql <= m) ans |= query(ql, qr, l, m, lson);
    if(qr > m) ans |= query(ql, qr, m + 1, r, rson);
    return ans;
}

int main(){
    while(~scanf("%d %d", &n, &mm) && n){
        build(1, n, 1);
        while(mm--){
            char op;
            int l, r, c;
          
            scanf(" %c %d %d", &op, &l, &r);
   
            if(op == 'P'){
                scanf("%d", &c);
                update(c, l, r, 1, n, 1);
            }else{
        
                int ans = query(l, r, 1, n, 1);
                int cnt = 0;
               // cout << " ans = " << ans << endl;
               vector<int>v;
                while(ans){
                    if(ans & 1){
                        //printf("%d ", cnt);
                        v.push_back(cnt);
                    }
                    ans = ans / 2;
                    cnt++;
                }
                printf("%d", v[0]);
                for(int i = 1; i < v.size() ; i++){
                    printf(" %d", v[i]);
                }
                printf("\n");
            }
        }
    }
}