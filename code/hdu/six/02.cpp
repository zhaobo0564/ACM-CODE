#include<iostream>
#include<string>
using namespace std;

typedef long long ll;
ll transform(char c) {
    if(c>='0'&&c<='9')
        return c-'0';
    else
        return c-'A'+10;
}

ll work(int n, string str) {
    ll ans = 0;
    int l=str.length();
    for(int i=0;i<l;i++) {
        ans*=1ll*n;
        ans+=1ll*transform(str[i]);
    }
    return ans;

}

string s;

int main() {

    while (cin >> s) {
        char c = '0';
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '+' || s[i] == '/'|| s[i] == '*' || s[i] == '-' || s[i] == '=') continue;
            c = max(c, s[i]);
        }
        int n = transform(c);
        //n = max(2, n);
      //  cout << n << " " <<c << endl;
        string x = "", y = "", z = "";
        int  pos;
        int f = 0;
        int ok = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '+' || s[i] == '/'|| s[i] == '*' || s[i] == '-' || s[i] == '='){
                if (s[i] == '+') f = 1;
                else if (s[i] == '-') f = 2;
                else if (s[i] == '*') f = 3;
                else f = 4;
                pos = i;
                break;
            }
            if(ok == 0 && s[i] == '0') continue;
            else if(ok == 0 && s[i] != '0')ok=1;
            x += s[i];
        }
        ok = 0;
        for (int i = pos + 1; i < s.length(); i++) {
            if (s[i] == '+' || s[i] == '/'|| s[i] == '*' || s[i] == '-' || s[i] == '='){
                pos = i;
                break;
            }
            if(ok == 0 && s[i] == '0') continue;
            else if(ok == 0 && s[i] != '0')ok=1;
            y += s[i];
        }
        ok = 0;
        for (int i = pos + 1; i < s.length(); i++) {
            if(ok == 0 && s[i] == '0') continue;
            else if(ok == 0 && s[i] != '0')ok=1;
            z += s[i];
        }
    //    cout << x << " " << y << " " << z << endl;
        int ans  = -1;
        if (n == 0)n++;
        for (int i = n + 1; i <= 16; i++) {
            ll xx = work(i, x);
            ll yy = work(i, y);
            ll zz = work(i, z);
         //   cout << xx << " " << yy << "  "<< zz << endl;
            if (f == 1) {
                if (xx + yy == zz) {
                    ans = i;
                    break;
                }
            } else if (f == 2) {
                if (xx - yy == zz) {
                    ans = i;
                    break;
                }
            } else if (f == 3) {
                //__int128 xxx = xx, yyy = yy, zzz = zz;
                if (xx * yy == zz) {
                    ans = i;
                    break;
                }
            } else {
                if (xx % yy == 0) {
                    if (xx / yy == zz){
                        ans = i;
                        break;
                    }
                }
            }
        }
        printf("%d\n", ans);

    }
}