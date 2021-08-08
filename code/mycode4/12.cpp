#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100005;
char t[maxn],p[maxn];
int lent,lenp;
int nexts[maxn];
int h=0;//数组从0开始就赋值为0，从1开始就赋值为1，等等,t数组和p数组要统一
void createNext()
{
    int j=h-1;
    nexts[h]=j;
    for(int i=h+1;i<h+lenp;i++){
        while(j>h-1&&p[j+1]!=p[i]){
            j=nexts[j];
        }

        if(p[j+1]==p[i]){
            ++j;
        }
        nexts[i]=j;
    }
}
int KMP()
{
    int num=0;//统计出现次数
    int j=h-1;
    for(int i=h;i<h+lent;i++){
        while(j>h-1&&p[j+1]!=t[i]){
            j=nexts[j];
        }
        if(p[j+1]==t[i]){
            ++j;
        }
        if(j==lenp+h-1){
            j=nexts[j];// ***
            num++;
            return i-lenp+1;//模式串在文本串中第一次出现的位置
        }
    }
    return -1;
    //return num;//返回模式串在文本串中出现的次数（允许部分重叠,如果要不允许重叠，把注释有***的那一行改为j=h-1）
}

int main(void){
    int T; scanf("%d", &T);
    while(T--){
        gets(p);
        lenp=strlen(p);//不是从0开始的记得改成 p+开始的位置
        for(int i = 0; i < lenp; i++){
            t[i] = p[i];
        }
        createNext();
        int k;
        int i = 0;
        while(i < lenp){
            int l = i, r = lenp - 1;
            int ans = -1;
            int cnt = -1;
            while(l <= r){
                int m = (l + r) / 2;
                h = l;
                int an = KMP();
                if(an == - 1 || an >= i){
                    r = m - 1;
                }else{
                    l = m + 1;
                    ans = m;
                    cnt = an;
                }
            }
            cout <<"cnt " << cnt << "ans " << ans << endl;
            if(ans == -1){
                printf("-1 %d\n", p[i]);
                i++;
            }else{
                int k = ans - i + 1;
                printf("%d %d\n", k, cnt);
                i += k;
            }
            

        }

        }
       // printf("pos: %d\n",KMP());
        return 0;  
    }
    

