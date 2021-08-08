#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;

string s;
int t;
char s_new[2 * N];
int p[2 * N];
 
int Init(string a){
    int len = a.length();
    s_new[0] = '$';
    s_new[1] = '#';
    int j = 2;
 
    for (int i = 0; i < len; i++){
        s_new[j++] = a[i];
        s_new[j++] = '#';
    }
 
    s_new[j] = '\0';  //别忘了哦  
 
    return j;  //返回s_new的长度  
}
 
int Manacher(string a){
    int len = Init(a);  //取得新字符串长度并完成向s_new的转换  
    int maxLen = -1;   //最长回文长度  
 
    int id;
    int mx = 0;
 
    for (int i = 1; i < len; i++){
        if (i < mx)
            p[i] = min(p[2 * id - i], mx - i);  //需搞清楚上面那张图含义, mx和2*id-i的含义
        else
            p[i] = 1;
 
        while (s_new[i - p[i]] == s_new[i + p[i]])  //不需边界判断，因为左有'$',右有'\0'  
            p[i]++;
 
        //我们每走一步i，都要和mx比较，我们希望mx尽可能的远，这样才能更有机会执行if (i < mx)这句代码，从而提高效率 
        if (mx < i + p[i])  {
            id = i;
            mx = i + p[i];
        }
 
       // maxLen = max(maxLen, p[i] - 1);
    }
 
   // return maxLen;
   return len;
}

int main(){
    scanf("%d", &t);
    while(t--){
        cin>>s;
        int len = s.length() - 1;
        int pos = 0;
        for(int i = 0; i <s.length(); i++){
            if(s[i] != s[len - i]){
                pos = i - 1;
                break;
            }
        }
        int l = pos + 1, r = len - pos - 1;
        int ans = 0;
        string b = "", cnt = "";
        for(int i = l; i <= r; i++){
            b += s[i];
        }
        int le = Manacher(b);
        for(int i = 1 ;i < le; i++){
            if(p[i] - 1 == i - 1){
                ans = p[i] - 1;
            }
        }
        int ans1 = 0;
        for(int i = le - 1; i; i--){
            if(p[i] - 1 == le - 1 - i){
                ans1 = p[i] - 1;
            }
        }
        for (int i = 0; i < le; i++){
            p[i] = 0;
        }
        le = Manacher(s);
        int ans2 = 0, ans3 = 0;
        for(int i = 1 ;i < le; i++){
            if(p[i] - 1 == i - 1){
                ans2 = p[i] - 1;
            }
        }
        for(int i = le - 1; i; i--){
            if(p[i] - 1 == le - 1 - i){
                ans3 = p[i] - 1;
            }
        }
        int Ans = ans + (pos + 1) * 2;
        int Ans1 = ans1 + (pos + 1)* 2;
        int cn = 0;
        if(len - pos == pos){
            cn = 1;
        }
        if(Ans >= Ans1 && Ans >= ans2 && Ans >= ans3){
            for(int i = 0; i <= pos + ans; i++){
                cout << s[i];
            }
            for(int i = len - pos + cn; i <= len; i++){
                cout << s[i];
            }
            cout << endl;
        }else if(Ans1 >= Ans && Ans1 >= ans2 && Ans1 >= ans3){
             for(int i = 0; i <= pos; i++){
                cout << s[i];
            }
            for(int i = len - pos + cn - ans1; i <= len; i++){
                cout << s[i];
            }
            cout << endl;
        }else if(ans2 >= Ans1 && ans2 >= Ans && ans2 >= ans3){
            for(int i = 0; i <ans2; i++){
                cout << s[i];
            }
            cout << endl;
        }else{
            for(int i = len - ans3; i <= len; i++){
                cout << s[i];
            }
            cout << endl;
        }
    }
    
}