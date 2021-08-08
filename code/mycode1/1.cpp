#include<bits/stdc++.h>
using namespace std;

char s[207], text[10007];
const int N = 1e5 + 7;

int trie[N][129], cnt[N], fail[N];
bool vis[N];

int n, m, top;
queue<int>q;
vector<int> v;

int ans[5], p;


void insert(char str[], int pos){
    int now = 0;
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        int id = str[i];
        if(trie[now][id] == 0){
            trie[now][id] = ++top;
        }
        now = trie[now][id];
    }
    cnt[now] = pos;
}

void bfs(){

    fail[0] = 0;
    for(int i = 0; i < 129; i++){
        if(trie[0][i]){
            q.push(trie[0][i]);
        }
    }

    while(q.size()){
        int now = q.front();
        q.pop();

        for(int i = 0; i < 129; i++){
            if(trie[now][i]) fail[trie[now][i]] = trie[fail[now]][i],q.push(trie[now][i]);
            else trie[now][i] = trie[fail[now]][i];
        }
    }
}


void query(char str[], int pos){
    int len = strlen(str);
    int now = 0;

    for(int i = 0; i < len; i++){
        int id = str[i];
        now = trie[now][id];
        for(int j = now; j && vis[j] != 1; j = fail[j]){
            if(cnt[j]) ans[p++] = cnt[j];
            vis[j] = 1;
            v.push_back(j);
        }
    }

}


int main(){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%s", s);
            insert(s, i);
        }
        int total = 0;
        bfs();
        scanf("%d", &m);
        for(int i = 1; i <= m; i++){
            p = 0;
            scanf("%s", text);
            query(text, i);
            for(int j: v){
                vis[j] = 0;
            }
            v.clear();
            if(p){
                sort(ans, ans + p);
                printf("web %d:", i);
                for(int i = 0; i < p; i++){
                    printf(" %d", ans[i]);
                }
                puts("");
                total++;
            }
        }


        printf("total: %d\n", total);



}
