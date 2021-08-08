#include<iostream> 
#include<cstring> 
#include<iomanip> 
#include<algorithm> 
using namespace std; 

#define MAXN 999999999
#define MAXSIZE 10
#define DLEN 4
const int mod=1e9+7;
#define ll long long

class BigNum
{ 
private: 
    int a[100007];   
    int len;      
public: 
    BigNum(){ len = 1;memset(a,0,sizeof(a)); }   	
    BigNum(const int);       						//��һ��int���͵ı���ת��Ϊ����
    BigNum(const string &s);     						//��һ���ַ������͵ı���ת��Ϊ����
    BigNum(const BigNum &);  						
    
   
    
    BigNum operator+(const BigNum &) const;   //���ؼӷ����������������֮���������� 
    BigNum operator*(const BigNum &) const;   //���س˷����������������֮���������� 
    
   
    ll    operator%(const int  &) const;    //������һ��int���͵ı�������ȡģ����    
   
    
    void print();       					//�������
}; 
BigNum::BigNum(const int b)     //��һ��int���͵ı���ת��Ϊ����
{ 
    int c,d = b;
    len = 0;
    memset(a,0,sizeof(a));
    while(d > MAXN)
    {
        c = d - (d / (MAXN + 1)) * (MAXN + 1); 
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}
BigNum::BigNum(const string &s)     //��һ���ַ������͵ı���ת��Ϊ����
{
    int t,k,index,l,i;
    memset(a,0,sizeof(a));
    l=s.length();   
    len=l/DLEN;
    if(l%DLEN)
        len++;
    index=0;
    for(i=l-1;i>=0;i-=DLEN)
    {
        t=0;
        k=i-DLEN+1;
        if(k<0)
            k=0;
        for(int j=k;j<=i;j++)
            t=t*10+s[j]-'0';
        a[index++]=t;
    }
}
BigNum::BigNum(const BigNum & T) : len(T.len)  //�������캯��
{ 
    int i; 
    memset(a,0,sizeof(a)); 
    for(i = 0 ; i < len ; i++)
        a[i] = T.a[i]; 
} 



BigNum BigNum::operator+(const BigNum & T) const   //��������֮����������
{
    BigNum t(*this);
    int i,big;      //λ��   
    big = T.len > len ? T.len : len; 
    for(i = 0 ; i < big ; i++) 
    { 
        t.a[i] +=T.a[i]; 
        if(t.a[i] > MAXN) 
        { 
            t.a[i + 1]++; 
            t.a[i] -=MAXN+1; 
        } 
    } 
    if(t.a[big] != 0)
        t.len = big + 1; 
    else
        t.len = big;   
    return t;
}
 

BigNum BigNum::operator*(const BigNum & T) const   //��������֮���������� 
{ 
    BigNum ret; 
    int i,j,up; 
    int temp,temp1;   
    for(i = 0 ; i < len ; i++)
    { 
        up = 0; 
        for(j = 0 ; j < T.len ; j++)
        { 
            temp = a[i] * T.a[j] + ret.a[i + j] + up; 
            if(temp > MAXN)
            { 
                temp1 = temp - temp / (MAXN + 1) * (MAXN + 1); 
                up = temp / (MAXN + 1); 
                ret.a[i + j] = temp1; 
            } 
            else
            { 
                up = 0; 
                ret.a[i + j] = temp; 
            } 
        } 
        if(up != 0) 
            ret.a[i + j] = up; 
    } 
    ret.len = i + j; 
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--; 
    return ret; 
} 

ll BigNum::operator %(const int & b) const    //������һ��int���͵ı�������ȡģ����    
{
    ll i,d=0;
    for (i = len-1; i>=0; i--)
    {
        d = ((d * (MAXN+1))% b + a[i])% b;  
    }
    return d;
}




void BigNum::print()    //�������
{ 
    int i;   
    cout << a[len - 1]; 
    for(i = len - 2 ; i >= 0 ; i--)
    { 
        cout.width(DLEN); 
        cout.fill('0'); 
        cout << a[i]; 
    } 
    cout << endl;
}

int vis[11];


int main(){
    int t; 
    scanf("%d", &t);
    
    while (t--) {
        int n;
        for (int i = 0; i < 10; i++) vis[i] = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            vis[x]++;
        }
      
        int a;
        int j = 0;
        string cc = "";
        if (vis[0]) {
            for (int i = 1; i < 10; i++) {
                if (vis[i]) {
                    a = i;
                    vis[i]--;
                    break;
                }
            }

            for (int i = 1; i < 10; i++) {
                if (vis[i]) {
                    cc += (i + '0');
                    vis[i]--;
                    while (vis[0]) {
                        cc += '0';
                        vis[0]--;
                    }
                    i--;
                }
            }
        } else {
            for (int i = 1; i < 10; i++) {
                if (vis[i]) {
                    a = i;
                    vis[i]--;
                    break;
                }
            }

            for (int i = 1; i < 10; i++) {
                if (vis[i]) {
                    cc += (i + '0');
                    vis[i]--;
                    i--;
                }
            }
        }
        //cout << cc << endl;
        BigNum b(cc);
        //b.print();
        b = b * BigNum(a);
      
       b.print();

    }
	
}
