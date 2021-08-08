#include<bits/stdc++.h>
int mp[400][400];
int n;

bool judge(){
    for(int i = 21; i <= 320; i++){
        for(int j = 21; j <= 320; j++){
            if(mp[i][j] == 1){
                // 右边5个
                int k = j;
                while(mp[i][k] == 1)k++;
                if(k - j >= 5) return true;

                // 左边5个
                k = j;
                while(mp[i][k] == 1)k--;
                if(j - k >= 5) return true;

                // 下方5个
                k = i;
                while(mp[k][j] == 1)k++;
                if(k - i >= 5) return true;

                // 上方5个
                k = i;
                while(mp[k][j] == 1)k--;
                if(i - k >= 5)return true;

                // 左下方
                int x = i, y = j;
                while(mp[x][y] == 1) x++, y++;
                if(y - j >= 5)return true;
                // 左上方

                x = i, y = j;
                while(mp[x][y] == 1) x--, y--;
                if(j - y >= 5)return true;

                // 右下方
                x = i, y = j;
                while(mp[x][y] == 1)x++, y--;
                if(x - i >= 5)return true;

                // 右上方
                x = i, y = j;
                while(mp[x][y] == 1)x--, y++;
                if(y - j >= 5)return true;
            }else if(mp[i][j] == 2){
                // 右边5个
                int k = j;
                while(mp[i][k] == 2)k++;
                if(k - j >= 5) return true;

                // 左边5个
                k = j;
                while(mp[i][k] == 2)k--;
                if(j - k >= 5) return true;

                // 下方5个
                k = i;
                while(mp[k][j] == 2)k++;
                if(k - i >= 5) return true;

                // 上方5个
                k = i;
                while(mp[k][j] == 2)k--;
                if(i - k >= 5)return true;

                // 左下方
                int x = i, y = j;
                while(mp[x][y] == 2) x++, y++;
                if(y - j >= 5)return true;
                // 左上方

                x = i, y = j;
                while(mp[x][y] == 2) x--, y--;
                if(j - y >= 5)return true;

                // 右下方
                x = i, y = j;
                while(mp[x][y] == 2)x++, y--;
                if(x - i >= 5)return true;

                // 右上方
                x = i, y = j;
                while(mp[x][y] == 2)x--, y++;
                if(y - j >= 5)return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d", &n);
    int ans = 0, f = -1;
    for(int i = 1; i <= n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        x += 20;
        y += 20;
        if(i % 2 == 1){
            mp[x][y] = 1;
        }else{
            mp[x][y] = 2;
        }
        if(judge() && ans == 0){
            ans = i;
            f = i % 2;
        }
    }

    if(f == 1){
        printf("xiaoming %d\n", ans);
    }else if(f == 0 ){
        printf("xiaohong %d\n", ans);
    }else if(f == -1){
        puts("-1");
    }
}