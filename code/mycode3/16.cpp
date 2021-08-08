/*
pku3461(Oulipo), hdu1711(Number Sequence)
这个模板 字符串是从0开始的
Next数组是从1开始的
*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e6 + 7;
int nexts[N];
char S[N], T[N];
int slen, tlen;

void getNext()
{
    int j, k;
    j = 0; k = -1; nexts[0] = -1;
    while(j < tlen)
        if(k == -1 || T[j] == T[k])
            nexts[++j] = ++k;
        else
            k = nexts[k];

}
/*
返回模式串T在主串S中首次出现的位置
返回的位置是从0开始的。
*/
int KMP()
{
    int i = 0, j = 0;
    getNext();

    while(i < slen && j < tlen)
    {
        if(j == -1 || S[i] == T[j])
        {
            i++; j++;
        }
        else
            j = nexts[j];
    }
    if(j == tlen)
        return i - tlen;
    else
        return -1;
}

char str[N];

int main(){

    int t;
    scanf("%d", &t);
    while(t--){
       scanf(" %s", str);
       int len = strlen(str);
       for(int i = 1; i < len; i++){
           S[i - 1] = str[i];
       }
       S[len - 1] = '\0';
       slen = strlen(S);

       int ans = -1, l = 0, r = len - 1;
       while(l <= r){
           int m = (l + r) / 2;
           for(int i = 0; i <= m; i++){
               T[i] = str[i];
           }
           T[m + 1] = '\0';
           tlen = strlen(T);
           if(KMP() != -1){
               l = m + 1;
               ans = m;
           } else{
               r = m -1;
           }

       }
       printf("%d\n", ans + 1);
       
    }
}
