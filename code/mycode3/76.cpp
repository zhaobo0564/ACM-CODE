#include<bits/stdc++.h>
using namespace std;
int v1, v2, t, s, l;

int main(){
    scanf("%d %d %d %d %d", &v1, &v2, &t, &s, &l);
    int sx = 0, sh = 0;
    int cnt  = 0;
    int f = 0;
    while(1){
     //   cout << sx << " " << sh << " " << cnt << endl;
        cnt++;
        sx += v1;
        sh += v2;
        if(sx >= l && sh >= l){
            f = 3;
            break;
        }
        if(sx >= l){
            f = 1;
            break;
        }
        if(sx - sh >= t){
            int cn = s;
            while(cn--){
                sh += v2;
                if(sh >= l)break;
            }
            if(cn < 0)cn = 0;
           // cout <<"s " << s - cn << endl;
            cnt += (s - cn);
        }
        if(sh >= l){
            f = 2;
            break;
        }

    }
    if(f == 1){
        printf("Ming %d\n", cnt);
    }else if(f == 2){
        printf("Hong %d\n", cnt);
    }else{
        printf("Tie %d\n", cnt);
    }
}