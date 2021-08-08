#include<iostream>
using namespace std;

const int N = 2e3 + 7;

int mp[N][N];

int tree[N][5 * N], lefts[N][5 * N], rights[N][5 * N];

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

void push_down(int id, int node, int nl) {
    if (lefts[id][node]) {
        lefts[id][lson] = lefts[id][node];
        lefts[id][rson] = lefts[id][node] + nl;
        //cout << "nl " << nl << endl;
        
        tree[id][lson] = lefts[id][lson];
        tree[id][rson] = lefts[id][rson];
        rights[id][lson] = 0;
        rights[id][rson] = 0;
        lefts[id][node] = 0;
    } else if (rights[id][node]) {
        rights[id][lson] = rights[id][node];
        rights[id][rson] = rights[id][node] - nl;
        tree[id][lson] = rights[id][lson];
        tree[id][rson] = rights[id][rson];
        lefts[id][lson] = 0;
        lefts[id][rson] = 0;
        rights[id][node] = 0;
    }
}

int v;

void update(int id, int f, int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        if (f == 1) {
            lefts[id][node] = v;
            rights[id][node] = 0;
            tree[id][node] = v;
            v = v + (r - l + 1);
        } else {
            rights[id][node] = v;
            lefts[id][node] = 0;
            tree[id][node] = v;
            v = v - (r - l + 1);
        }
        return;
    }
    push_down(id, node, m - l + 1);
   
    if (ql <= m) update(id, f, ql, qr, l, m, lson);
    if (qr > m) update(id, f, ql, qr, m + 1, r, rson);
    
}
inline void write(int x){
	if (x < 0) x = ~x + 1, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
   
}

void print(int id, int l, int r, int node) {

    if (l == r) {
       write(tree[id][node]);
        putchar(' ');
        return;
    }
    push_down(id, node, m - l + 1);
    print(id, l, m, lson);
    print(id, m + 1, r, rson);
}
int n, q;
void show() {
   // puts("****\n");
    for (int i = 1; i <= n; i++) {
        print(i, 1, n, 1);
        puts("");
    }
}
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[2 *N], b[2 *N], c[2 *N];



int main() {
    
    n = read();
    q = read();
     for (int i = 1; i <= q; i++) {
         a[i] = read();

         b[i] = read();
         c[i] = read();
         if (c[i] > mp[a[i]][b[i]]) {
             mp[a[i]][b[i]] = i;
         } 
     }

    for (int i = 1; i <= q; i++) {
        int x, y, k;
       // scanf("%d %d %d", &x, &y, &k);
       x = a[i];
       y = b[i];
       k = c[i];
        if (mp[a[i]][b[i]] > i) {
            continue;
        }

        for (int j = 0; j < k; j++) {
            if (j % 2 == 0) {
              //  cout << "l " << y << " r = " << y + k - 1 << " va " << j * k + 1 << endl; 
                v = j * k + 1;
                update(x + j, 1, y, y + k - 1, 1, n, 1);
            } else {
             //   cout << "l " << y << " r = " << y + k - 1 << " va " << j* k + k << endl;
                v = j * k + k;
                update(x + j, 0, y, y + k - 1, 1, n, 1);
            }

        }
       
    }

    show();


    
}