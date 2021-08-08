
#include<bits/stdc++.h>
using namespace std;

const int N = 2000007;

char s[1001][60], text[N];
int tree[50007][26], cnt[50007], fail[50007], vis[1007];
int top = 0;
queue<int>q;
void insert(char str[], int id){
    int len = strlen(str);
    int now = 0;
    for(int i = 0; i < len; i++){
        if(tree[now][str[i]- 'A'] == 0){
            tree[now][str[i]- 'A'] = ++top;
            memset(tree[top], 0, sizeof(tree[top]));
            cnt[top] = 0;
            fail[top] = 0;
        }
        now = tree[now][str[i] - 'A'];
    }
    cnt[now] = id;
}

void bfs(){

    fail[0] = 0;
    for(int i = 0; i < 26; i++){
        if(tree[0][i]){
            q.push(tree[0][i]);
        }
    }
    while(q.size()){
        int now = q.front();
        q.pop();
        for(int i = 0; i < 26; i++){
            if(tree[now][i]){
                fail[tree[now][i]] = tree[fail[now]][i];
                q.push(tree[now][i]);
            }else{
                tree[now][i] = tree[fail[now]][i];
            }
        }

    }
}

void query(char str[]){
    int len = strlen(str);
    int now = 0, ans = 0;
    for(int i = 0; i < len; i++){
        int pos = str[i] - 'A';
        if(pos < 0 || pos > 25){
            now = 0;
            continue;
        }

        now = tree[now][pos];
       // cout <<"now= " << now << endl;
        for(int j = now; j ; j = fail[j]){
            if(cnt[j])vis[cnt[j]]++;
        }
    }

}

int main(){

    int n;
    while(~scanf("%d",&n)){
        top = 0;
       // memset(fail, 0,sizeof(fail));
       fail[0] = 0;
      // memset(cnt, 0, sizeof(cnt));

        memset(tree[0], 0, sizeof(tree[0]));
        //memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++){
            scanf("%s", s[i]);
            insert(s[i], i);
            //vis[i] = 0;
        }
       bfs();
        scanf("%s", text);
        query(text);
        for(int  i = 1; i <= n; i++){
            if(vis[i]){
                printf("%s: %d\n", s[i], vis[i]);
                vis[i] = 0;
            }
        }


    }
    return 0;



}
