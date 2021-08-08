#include<iostream>
#include<stdio.h>
using namespace std;

const int N = 1e5 + 7;

int n , mm, a[N], flag[4 * N], vis[4 * N];

struct node{
    int lone,rone,max_one;
    int lzero, rzero, max_zero;
    int len, count;
    node(){
        lone = rone = max_one = lzero = rzero = max_zero = len = count = 0;
    }
}tree[4 * N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

int max(int a, int b, int c){
    a = max(a, b);
    a = max(a, c);
    return a;
}

void push_up(int node){
    if(tree[lson].len == tree[lson].lzero){
        tree[node].lzero = tree[lson].len + tree[rson].lzero;
    }else{
        tree[node].lzero = tree[lson].lzero;
    }

    if(tree[rson].len == tree[rson].rzero ){
        tree[node].rzero = tree[rson].len + tree[lson].rzero;
    }else{
        tree[node].rzero = tree[rson].rzero;
    }

    if(tree[lson].len == tree[lson].lone){
        tree[node].lone = tree[lson].len + tree[rson].lone;
    }else{
        tree[node].lone = tree[lson].lone;
    }

    if(tree[rson].len == tree[rson].rone ){
        tree[node].rone = tree[rson].len + tree[lson].rone;
    }else{
        tree[node].rone = tree[rson].rone;
    }
    ///
    tree[node].max_one = max(tree[lson].max_one, tree[rson].max_one, tree[lson].rone + tree[rson].lone);
    tree[node].max_zero = max(tree[lson].max_zero, tree[rson].max_zero, tree[lson].rzero + tree[rson].lzero);
    tree[node].count = tree[lson].count + tree[rson].count;
}

void push_down(int node){
    if(flag[node] == 1){
        tree[lson].count = tree[lson].lone = tree[lson].rone = tree[lson].max_one = 0;
        tree[rson].count = tree[rson].lone = tree[rson].rone = tree[rson].max_one = 0;
        tree[lson].lzero = tree[lson].rzero = tree[lson].max_zero = tree[lson].len;
        tree[rson].lzero = tree[rson].rzero = tree[rson].max_zero = tree[rson].len;

        flag[lson] = flag[node];
        flag[rson] = flag[node];
        vis[lson] = 0;
        vis[rson] = 0;
        flag[node] = 0;
    }else if(flag[node] == 2){
         tree[lson].count = tree[lson].lone = tree[lson].rone = tree[lson].max_one = tree[lson].len;
        tree[rson].count = tree[rson].lone = tree[rson].rone = tree[rson].max_one = tree[rson].len;
        tree[lson].lzero = tree[lson].rzero = tree[lson].max_zero = 0;
        tree[rson].lzero = tree[rson].rzero = tree[rson].max_zero = 0;
        flag[lson] = flag[node];
        flag[rson] = flag[node];
      //  cout <<"node = " << node << endl; 
        vis[lson] = 0;
        vis[rson] = 0;
        flag[node] = 0;
    }
    if (vis[node] == 3){
      //  cout << "sadsda=" << node << endl;
        swap(tree[lson].lone, tree[lson].lzero);
        swap(tree[lson].rzero, tree[lson].rone);
        swap(tree[lson].max_one, tree[lson].max_zero);
        swap(tree[rson].lone, tree[rson].lzero);
        swap(tree[rson].rzero, tree[rson].rone);
        swap(tree[rson].max_one, tree[rson].max_zero);
        tree[lson].count = tree[lson].len - tree[lson].count;
        tree[rson].count = tree[rson].len - tree[rson].count;
        if(vis[lson] == 3)vis[lson] = 0;
        else vis[lson] = vis[node];
        if(vis[rson] == 3)vis[rson] = 0;
        else vis[rson] = vis[node];
        if(vis[lson] && flag[lson] == 1)vis[lson] = 0, flag[lson] = 2;
        else if(vis[lson] && flag[lson] == 2)vis[lson] = 0, flag[lson] = 1;
        if(vis[rson] && flag[rson] == 1)flag[rson] = 2, vis[rson] = 0;
        else if(vis[rson] && flag[rson] == 2)flag[rson] = 1, vis[rson] = 0;
        vis[node] = 0;
    }

}

void build(int l, int r, int node){
    tree[node].len = r - l + 1;
    if(l == r){
        if(a[l]){
            tree[node].max_one = tree[node].rone = tree[node].lone = tree[node].count = 1;
        }else{
            tree[node].max_zero = tree[node].lzero = tree[node].rzero = 1;
        }
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    push_up(node);
}

void update(int ok, int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r){
        if(ok == 1){
            tree[node].lone = tree[node].rone = tree[node].max_one = 0;
            tree[node].lzero = tree[node].rzero = tree[node].max_zero = tree[node].len;
            tree[node].count = 0;
            flag[node] = 1;
            vis[node] = 0;
        }else if(ok == 2){
            tree[node].lone = tree[node].rone = tree[node].max_one = tree[node].len;
            tree[node].lzero = tree[node].rzero = tree[node].max_zero = 0;
            tree[node].count = tree[node].len;
            flag[node] = 2;
            vis[node] = 0;
        }else if(ok == 3){
            if(vis[node] == 3)vis[node] = 0;
            else vis[node] = 3;

            if(vis[node] && flag[node] == 1)flag[node] = 2, vis[node] = 0;
            else if(vis[node] && flag[node] == 2) flag[node] = 1, vis[node] = 0;
            swap(tree[node].lone, tree[node].lzero);
            swap(tree[node].max_one, tree[node].max_zero);
            swap(tree[node].rone, tree[node].rzero);
            tree[node].count = tree[node].len - tree[node].count;
            

        }
        return;
    }
    push_down(node);
    if(ql <= m) update(ok, ql, qr, l, m, lson);
    if(qr > m) update(ok, ql, qr, m + 1, r, rson);
    push_up(node);
}

struct node merg(struct node x, struct node y){
    //cout << "x = " << x.rone << "y = " << y.lone <<" " <<x.max_one << " "<<y.max_one << endl;
 //   cout << i << endl;
    struct node cd;
    if(x.len == 0)return y;
    cd.count = x.count + y.count;
    if(x.len == x.lone){
        cd.lone = x.len + y.lone;
    }else{
        cd.lone = x.lone;
    }

    if(y.rone == y.len){
        cd.rone = x.rone + y.len;
    }else{
        cd.rone = y.rone;
    }
    cd.len = x.len + y.len;
    cd.max_one = max(y.max_one, x.max_one, y.lone + x.rone);
  //  cout <<"xone" << x.rone << "yone = "<< y.lone << endl;
  //  cout <<"ans = "<<y.lone + x.rone << endl;
 //   cout << "asd = " << y.max_one << endl;
    return cd;

}


struct node  query(int ql, int qr, int l, int r, int node){
    if(ql <= l && qr >= r) {
    //    cout << "node= " << node << endl;
        //ans = merg(ans, tree[node]);
        return tree[node];
    }
    struct node ans;
    push_down(node);
    if(ql <= m){
        ans = merg(ans, query(ql, qr, l, m, lson));
        
    }
    if(qr > m){
        ans = merg(ans, query(ql, qr, m + 1, r, rson));

    }
    return ans;

}

void clear(int l ,int r, int node){
     tree[node].lone = tree[node].rone = tree[node].max_one = 0;
     tree[node].lzero = tree[node].rzero = tree[node].max_zero = 0;
     flag[node] = 0;
     tree[node].count = 0;
     vis[node] = 0;
    if(l == r)return;
    clear(l, m, lson);
    clear(m + 1, r , rson);
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &mm);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        build(1, n, 1);
        while(mm--){
            int op , l, r;
            scanf("%d %d %d", &op, &l, &r);
            op++, l++, r++;
            // struct node cd;
            // ans = cd;
            if(op == 1){
                update(op, l, r, 1, n, 1);
            }else if(op == 2){
                update(op, l, r, 1, n, 1);
            }else if(op == 3){
                update(op, l, r, 1, n, 1);
            }else if(op == 4){

                struct node ans = query(l, r, 1, n, 1);
                printf("%d\n", ans.count);
            }else{
                struct node ans = query(l, r, 1, n, 1);
                printf("%d\n", ans.max_one);
            }
            // for(int i = 1; i <= 9; i++){
            //     cout << tree[i].count << " " << tree[i].max_one << " " << tree[i].max_zero << endl;
            //     cout << "flag= " << flag[i] << endl;
            // }
            // cout <<"*************\n";
            
        }
        clear(1, n, 1);
    }
    
    
}