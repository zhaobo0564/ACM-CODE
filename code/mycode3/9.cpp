#include<bits/stdc++.h>
using namespace std;

int n, m;
char mp[107][107];

bool judge(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mp[i][j] == '0'){
                return false;
            }
        }
    }
    return true;
}

void work(int x, int y, int l, int r){
    int c = min(l, r);
    for(int i = x; i <= x + c - 1; i++){
        for(int j = y; j <= y + c - 1; j++){
            mp[i][j] = 'A';
        }
    }
 
    int f = 0;
    if(mp[x - 1][y + c] == 'B')f = 1;
    for(int i = x ; i <= x + c - 1; i++){
        if(f == 0){
            mp[i][y + c] = 'B';
            f = 1;
        }else{
            mp[i][y + c] = 'C';
            f = 0;
        }
    }

    
}

void work1(int x, int y, int l, int r){
    int c = min(l , r);
     for(int i = x; i <= x + c - 1; i++){
        for(int j = y; j <= y + c - 1; j++){
            mp[i][j] = 'B';
        }
    }
    int f = 0;
    if(mp[x - 1][y + c] == 'A') f = 1;
    for(int i = x; i <= x + c - 1; i++){
        if(f == 0){
            mp[i][y + c] = 'A';
            f = 1;
        }else{
            mp[i][y + c] = 'C';
            f = 0;
        }
    }


}

int main(){
    scanf("%d %d", &n, &m);
    int c = min(n, m);
    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= m + 1; j++){
            mp[i][j] = '0';
        }
    }

    for(int i = 1; i <= c; i++){
        for(int j = 1; j <= c; j++){
            mp[i][j] = 'A';
        }   
    }
    

    for(int i = 1; i <= c; i++){
        if(i % 2){
            mp[i][c + 1] = 'B';
        }else{
            mp[i][c + 1] = 'C';
        }
    }
    

    while(1){
        if(judge())break;
        int u = 0, r = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                u = 0, r = 0;
                if(mp[i][j] == '0'){
                  //  cout <<"j " << j << "i " << i << endl;
                    for(int k = i ; k <= n; k++){
                        if(mp[k][j] == '0'){
                            u++;
                        }else break;
                    }
                    for(int k = j; k <= m; k++){
                        if(mp[i][k] == '0'){
                            r++;
                        }else break;
                    }
                   // cout << u << " " << r << endl;
                   if(mp[i - 1][j] == 'A'){
                       work1(i, j, u, r);
                   }else work(i, j, u, r);
                    
                }
            }
        }

        // printf("**********\n");
        // for(int i = 1; i <= n; i++){
        // for(int j = 1; j <= m; j++){
        //     printf("%c", mp[i][j]);
        // }
        // puts("");
    

    }









    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            printf("%c", mp[i][j]);
        }
        puts("");
    }

}