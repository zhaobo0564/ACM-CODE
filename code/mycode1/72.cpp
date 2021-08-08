#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
typedef long long  ll;
ll a[N], c[N];
int n;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    for(int  i = 1; i <= n; i++){
        int l = i - a[i];
        if(l <= 0) l = 1;
        c[l]++;
        c[i]--;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        c[i] += c[i - 1];
    }
    for(int i = 1; i <= n; i++){
        if(!c[i]){
            ans++;
        }
    }
    printf("%d\n", ans);
}

HTTP/1.1 200 OK
Date: Fri, 01 May 2020 13:47:36 GMT
Content-Type: text/html
Content-Length: 251
Connection: keep-alive
Strict-Transport-Security: max-age=63072000; includeSubdomains; preload
Vary: Accept-Encoding
Content-Encoding: gzip
X-Request-Id: bad6a7f842b7d325fd08b480087d2ba8
Server: WAF/2.4-12.1

GET /wkcx//web.php?question=e HTTP/1.1
Host: wk.xlqwlcm.cn
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:75.0) Gecko/20100101 Firefox/75.0
Accept: */*
Accept-Language: zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2
Accept-Encoding: gzip, deflate
X-Requested-With: XMLHttpRequest
Connection: keep-alive
Referer: http://wk.xlqwlcm.cn/shihezi_dacx/
Cookie: PHPSESSID=8mmn9s814qsutctei32ri8uiu7; UM_distinctid=171d075ecb037a-0772f6922d9afa-4c302e7f-1fa400-171d075ecb121b; CNZZDATA1278706676=970957803-1588340321-null%7C1588340321