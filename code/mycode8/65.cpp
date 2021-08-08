
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

struct node {
    int v, nxt, last;
}e[200 * N];

int top = 1, head, tail;

int vis[N];

void add(int x) {
    e[top].v = x;
    e[top].nxt = head;
    e[head].last = top;
    head = top++;
}



int main() {
    int n, m; 
    scanf("%d %d", &n, &m);
    for (int i = n; i; i--) {
        vis[i] = top;
        add(i);
    }

    int p = head;
    while(p) {
        tail = p;
        p = e[p].nxt;
    }
  
    int f = 0;
    
    while (m--) {
        int op;
        scanf("%d", &op); 
        e[tail].nxt = 0;
        e[head].last = 0;
        if (op == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (x == y) continue;
            int px = vis[x];
            int py = vis[y];
            if (f == 0) {
                if (e[px].last == 0) {
                    head = e[px].nxt;
                }
                if (e[px].nxt == 0) {
                    tail = e[px].last;
                }
                e[e[px].last].nxt = e[px].nxt;
                e[e[px].nxt].last = e[px].last; 
                int nxtpy = e[py].nxt;
                e[top].v = x;
                e[py].nxt = top;
                e[top].last = py;
                e[top].nxt = nxtpy;
                if (nxtpy == 0) {
                    tail = top;
                } else {
                    e[nxtpy].last = top;
                }
            
                vis[x] = top;
                top++;
            } else {
                if (e[px].last == 0) {
                    head = e[px].nxt;
                } 
                if (e[px].nxt == 0) {
                    tail = e[px].last;
                }
                e[e[px].last].nxt = e[px].nxt;
                e[e[px].nxt].last = e[px].last; 
                int nxtpy = e[py].last;
                e[top].v = x;
                e[py].last = top;
                e[top].nxt = py;
                e[top].last = nxtpy;
                if (nxtpy == 0) {
                    head = top;
                } else {
                    e[nxtpy].nxt = top;
                }
            
                vis[x] = top;
                top++;
                
            }
        } else if (op == 2) {
            int x, y;
            scanf("%d %d", &y, &x);
            if (x == y) continue;
            int px = vis[x];
            int py = vis[y];
            if (f == 0) {
                if (e[py].nxt == 0) {
                    tail = e[py].last;
                }
                if (e[py].last == 0) {
                    head = e[py].nxt;
                }
                e[e[py].last].nxt = e[py].nxt;
                e[e[py].nxt].last = e[py].last;
                e[top].v = y;
                e[top].last = e[px].last;
                e[top].nxt = px;
                e[px].last = top;

                if (e[top].last == 0) {
                    head = top;
                } else {
                    e[e[top].last].nxt = top;
                }

                vis[y] = top;
                top++;
            } else {
                if (e[py].nxt == 0) {
                    tail = e[py].last;
                }
                if (e[py].last == 0) {
                    cout << "WW\n";
                    head = e[py].nxt;
                }
                e[e[py].last].nxt = e[py].nxt;
                e[e[py].nxt].last = e[py].last;
                e[top].v = y;
                e[top].last = px;
                cout << "px " << px << " top " << top << endl;
                e[top].nxt = e[px].nxt;
                cout << "ss " << e[px].nxt << endl;
                e[px].nxt = top;

                if (e[top].nxt == 0) {
                    tail = top;
                } else {
                    e[e[top].nxt].last = top;
                    cout << "AA \n";
                }
                vis[y] = top;
                top++;

            }

        } else if (op == 3) {
            if (f == 0) {
                f = 1;
            } else {
                f = 0;
            }
        } else {
            if (f == 0) {
                int now = vis[1];
               
                while(now) {
                    printf("%d ", e[now].v);
                    now = e[now].nxt;
                }
                int p = head;
                while (p != vis[1] && p) {
                    printf("%d ", e[p].v);
                    p = e[p].nxt;
                }
                cout << endl;
            } else {
                int now = vis[1];
                cout << "NOW " << now << endl;
                cout << e[now].last << endl;
                while(now) {
                    printf("%d ", e[now].v);
                 //   cout << "now " << now << endl;
                    now = e[now].last;
                }
                int p = tail;
                while (p != vis[1] && p) {
                    cout <<"p = " << p << endl;
                    //printf("%d ", e[p].v);
                    p = e[p].last;
                }
                cout << endl;
            }
        }
    }
}

/*

*/