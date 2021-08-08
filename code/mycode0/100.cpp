#include<bits/stdc++.h>
using namespace std;


char s[67], text[1000500];

int t, n;
const int N=500050;
int tree[N][26];
int root = 0, top = 0, cnt[N], fail[N];

void insert(char a[]){
    int now = root;
    int len = strlen(a);
    for(int i = 0; i < len; i++){
        int pos = a[i] - 'a';
        if(tree[now][pos] == 0){
            tree[now][pos] = ++top;
            now = top;
        }else{
            now = tree[now][pos];
        }
    }
    cnt[now]++;
}

void bfs(){
    queue<int>q;
    for(int i = 0; i < 26; i++){
        if(tree[0][i] == 0)continue;
        fail[tree[0][i]] = 0;
        q.push(tree[0][i]);
    }

    while(q.size()){
        int now = q.front();
        q.pop();

        for(int i = 0; i < 26; i++){
            int son = tree[now][i];
            if(son) fail[son] = tree[fail[now]][i], q.push(son);
            else tree[now][i] = tree[fail[now]][i];
        }

    }

}

int query(){
    int now = 0, ans = 0;
    int len = strlen(text);
    for(int j = 0; j < len; j++){
        int pos = text[j] - 'a';

        now = tree[now][pos];
        for(int i = now; i && cnt[i] != -1; i = fail[i]){
            ans += cnt[i];
            cnt[i] = -1;
        }
    }
    return ans;
}

int main(){

    scanf("%d", &t);
    while(t--){
        top = 0;
        root = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%s", s);
            insert(s);
        }
        scanf("%s", text);
        fail[0] = 0;
        bfs();
        printf("%d\n", query());
        for(int i = 0; i<= top + 10; i++){
            for(int j = 0; j < 26; j++){
                tree[i][j] = 0;
            }
            cnt[i] = fail[i] = 0;
        }
    }


}
