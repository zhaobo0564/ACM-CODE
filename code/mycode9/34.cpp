#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;

ll n, a[N];
int L[N], R[N], block[N], b, sum;

vector<int> g[N];

void build() {
    for (int i = 1; i <= n; i++) {
        g[block[i]].push_back(a[i]);
    }
}

void insert(int id, int pos, int v) {
    vector<int> s;
    for (int i = 0; i < g[id].size(); i++) {
        if (i == pos) {
            s.push_back(v);
        }
        s.push_back(g[id][i]);
    }
    g[id].clear();
    for (int i: s) {
       // cout << i << " ";
        g[id].push_back(i);
    }
    //cout << endl;
}

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void update(int pos, int v) {
    //sum++;
    
    for (int i = 0; i <= n / b; i++) {
        if (pos > g[i].size()) {
            pos -= g[i].size();
        } else {
            insert(i, pos - 1, v);
            break;
        }
             
    }
}


int query(int pos) {
    for (int i = 0; i <= n / b; i++) {
        //cout << "block " << i << " sz " << g[i].size() << endl;
        if (pos > g[i].size()) {
            pos -= g[i].size();
        } else {
            return g[i][pos - 1];
        }
    }
  
    return -1;
}

inline void write(int x){
	if (x < 0) x = ~x + 1, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int main() {
    //ios::sync_with_stdio(0);
    //scanf("%d", &n);
    n = read();
    b = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        block[i] = i / b;
    }
    build();
    int t = n;
    while (t--) {  
        int op = read(), l = read(), r = read(), c = read();
       // scanf("%d %d %d %d", &op, &l, &r, &c);
        if (op == 0) {
            update(l, r);
        } else {
            //printf("%d\n", query(r));
            write(query(r));
            puts("");
        }
        sum++;
        if (sum == b) {
            sum = 0;
            int top = 1;
            for (int i = 0; i <= n / b; i++) {
                for (int j: g[i]) {
                    a[top++] = j;
                }
                g[i].clear();
            }
            b = sqrt(top - 1);
            for (int i = 1; i < top; i++) {
                block[i] = i / b;
            }
            for (int i = 1; i < top; i++ ){
                g[block[i]].push_back(a[i]);
            }
            n = top - 1;
            
        }
      
    }

}