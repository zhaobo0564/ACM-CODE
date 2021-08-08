#include<bits/stdc++.h>
using namespace std;

const int  N = 1e5 + 7;

struct msg {
    char name[22];
    int sex, grade, id;
}st[N];

struct node {
    char name[22];
    node(char *s) {
        strcpy(this->name, s);
    }
};


vector<node> g[200];

typedef long long ll;


const int mod = 1288888;

const int mod1 = 1233333;

int get_hash(char *s) {
    int n = strlen(s);
    int base = s[0];
    int d = 27;
    for (int i = 1; i < n; i++) {
        base = base * d % mod + s[i];
        base = base % mod;
    }
    return base;
}

int get_hash1(char *s) {
    int n = strlen(s);
    int base = s[0];
    int d = 47;
    for (int i = 1; i < n; i++) {
        base = base * d % mod1 + s[i];
        base = base % mod1;
    }
    return base;
}



inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}



inline void write(int x){
	if (x < 0) x = ~x + 1, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

bool cmp(node x, node y) {
    int lx = strlen(x.name), ly = strlen(y.name);
    if (lx <= ly) {
        for (int i = 0; i < lx; i++) {
            if (x.name[i] < y.name[i]) {
                return true;
            } else if (x.name[i] > y.name[i]) {
                return false;
            }
        } 
        return true;
    } else {
        for (int i = 0; i < ly; i++) {
            if (x.name[i] < y.name[i]) {
                return true;
            } else if (x.name[i] > y.name[i]) {
                return false;
            }
        } 
        return false;
    }
}




int v[2687369];


int n, m;

int main() {
    //ios::sync_with_stdio(0);
    n = read();
    for (int i = 1; i <= n; i++) {
        //cin >> st[i].name >> st[i].grade >> st[i].sex >> st[i].id;
        scanf("%s", st[i].name);
        st[i].grade = read();
        st[i].sex = read();
        st[i].id = read();

        g[st[i].grade].push_back(node(st[i].name));
        ll cnt = get_hash(st[i].name);
        ll cnt1 = get_hash1(st[i].name);
        cnt = cnt*cnt1 % mod;
        v[cnt] = i;
    
       
       

    }
    for (int i = 0; i <= 100; i++) {
        sort(g[i].begin(), g[i].end(), cmp);
    }
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            char name[22];
            scanf("%s", name);
            ll cnt = get_hash(name);
            ll cnt1 = get_hash1(name);
            cnt = cnt*cnt1 % mod;
            int id = v[cnt];
           
            if (id == 0) continue;
            write(st[id].grade);
            putchar(' ');
            write(st[id].id);
            putchar(' ');
            write(st[id].sex);
            puts("");
        } else {
            int x = read();
            for (int i = 0; i < g[x].size(); i++) {
                printf("%s\n", g[x][i].name);
            }
        }
    }
}