#include <iostream>
#include <ctime>
#include <cstdio>
#include <cctype>
namespace FastIO
{
char buf[1 << 21], buf2[1 << 21], a[20], *p1 = buf, *p2 = buf, hh = '\n';
int p, p3 = -1;
void read() {}
void print() {}
inline int getc()
{
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
}
inline void flush()
{
    fwrite(buf2, 1, p3 + 1, stdout), p3 = -1;
}
template <typename T, typename... T2>
inline void read(T &x, T2 &... oth)
{
    int f = 0;
    x = 0;
    char ch = getc();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = 1;
        ch = getc();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - 48;
        ch = getc();
    }
    x = f ? -x : x;
    read(oth...);
}
template <typename T, typename... T2>
inline void print(T x, T2... oth)
{
    if (p3 > 1 << 20)
        flush();
    if (x < 0)
        buf2[++p3] = 45, x = -x;
    do
    {
        a[++p] = x % 10 + 48;
    } while (x /= 10);
    do
    {
        buf2[++p3] = a[p];
    } while (--p);
    buf2[++p3] = hh;
    print(oth...);
}
} // namespace FastIO
#define read FastIO::read
#define print FastIO::print
//======================================
const int maxn = 1e5+5;
struct Node
{
    int l,r;
    int val,size;
    int cnt;        //��ǰ����ظ�������Ĭ��Ϊ1
}spl[maxn];         //�ڴ��
int cnt,root;       //�ڴ�ؼ���������ڵ���
inline void newnode(int &now,int &val)
{
    spl[now=++cnt].val=val;
    spl[cnt].size++;
    spl[cnt].cnt++;
}
inline void update(int now) //����size
{
    spl[now].size=spl[spl[now].l].size+spl[spl[now].r].size+spl[now].cnt;
}
inline void zig(int &now)
{
    int l = spl[now].l;
    spl[now].l = spl[l].r;
    spl[l].r = now;
    now = l;
    update(spl[now].r),update(now);
}
inline void zag(int &now)
{
    int r = spl[now].r;
    spl[now].r = spl[r].l;
    spl[r].l = now;
    now = r;
    update(spl[now].l),update(now);
}
void splaying(int x,int &y) //��Ҫ��x��չ��y�Ǹ�λ�ã�
{
    if(x==y) return;        //��������յ㣬return
    int &l = spl[y].l, &r = spl[y].r;   //temp
    if(x==l) zig(y);        //�����������յ㣬�Ǿ͵���
    else if(x==r) zag(y);   //�Ҷ������յ�Ҳ�ǵ���
    else        //�����һ����˫��
    {
        if(spl[x].val<spl[y].val)
        {
            if(spl[x].val<spl[l].val)
                splaying(x,spl[l].l),zig(y),zig(y);     //zigzig���
            else splaying(x,spl[l].r),zag(l),zig(y);    //zagzig���
        }
        else 
        {
            if(spl[x].val>spl[r].val)
                splaying(x,spl[r].r),zag(y),zag(y);     //zagzag���
            else splaying(x,spl[r].l),zig(r),zag(y);    //zigzag���
        }
    }
}
inline void delnode(int now)
{
    splaying(now,root);     //��Ҫɾ���Ľ����չ�������
    if(spl[now].cnt>1) spl[now].size--,spl[now].cnt--;  //������ظ������ظ�����--
    else if(spl[root].r)    //���������ǰ����к��
    {
        int p = spl[root].r;
        while(spl[p].l) p=spl[p].l;     //�ҵ����
        splaying(p,spl[root].r);        //������չ��������Ҷ���
        spl[spl[root].r].l=spl[root].l; //�Ҷ�������ӱ�Ϊ�����
        root=spl[root].r;               //������Ϊ������Ҷ���
        update(root);                   //����һ��size��Ϣ
    }
    else root = spl[root].l;    //��չ֮��û�к�̣�˵�����������ˣ��Ǿ�ֱ��ɾ��
}
void ins(int &now,int &val)
{
    if(!now) newnode(now,val),splaying(now,root);
    else if(val<spl[now].val) ins(spl[now].l,val);
    else if(val>spl[now].val) ins(spl[now].r,val);
    else spl[now].size++,spl[now].cnt++,splaying(now,root); //������ͬ�����
}
void del(int now,int &val)
{
    if(spl[now].val==val) delnode(now);
    else if(val<spl[now].val) del(spl[now].l,val);
    else del(spl[now].r,val);
}
//���´�������ǰ�Ĵ�����ͬ���д�䶯�ĵط�������ע��
int getrank(int val)
{
    int now = root, rank = 1;
    while(now)
    {
        if(spl[now].val==val)   //�ҵ���Ҫ�Ľ�㣬���֮ǰ��û��
        {
            rank+=spl[spl[now].l].size;
            splaying(now,root);
            break;
        }
        if(val<=spl[now].val)
            now=spl[now].l;
        else 
        {
            rank+=spl[spl[now].l].size+spl[now].cnt;
            now=spl[now].r;
        }
    }
    return rank;
}
int getnum(int rank)
{
    int now = root;
    while(now)
    {
        int lsize = spl[spl[now].l].size;
        if(lsize+1<=rank&&rank<=lsize+spl[now].cnt) //����������Χ�ڣ��Ǿ��ǵ�ǰ���
        {
            splaying(now,root);
            break;
        }
        else if(lsize>=rank)
            now=spl[now].l;
        else 
        {
            rank-=lsize+spl[now].cnt;
            now=spl[now].r;
        }
    }
    return spl[now].val;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    clock_t c1 = clock();
    //======================================
    int t;
    read(t);
    while(t--)
    {
        int opt,x;
        read(opt,x);
        switch(opt)
        {
        case 1:
            ins(root,x);
            break;
        case 2:
            del(root,x);
            break;
        case 3: 
            print(getrank(x));
            break;
        case 4:
            print(getnum(x));
            break;
        case 5:
            print(getnum(getrank(x)-1));
            break;
        case 6:
            print(getnum(getrank(x+1)));
            break;
        }
    }
    //======================================
    FastIO::flush();
    std::cerr << "Time:" << clock() - c1 << "ms" << std::endl;
    return 0;
}
/*
 * ����������   ���������Щ������Щ������Щ������� ���������Щ������Щ������Щ������� ���������Щ������Щ������Щ������� ���������Щ������Щ�������
 * ��Esc��   �� F1�� F2�� F3�� F4�� �� F5�� F6�� F7�� F8�� �� F9��F10��F11��F12�� ��P/S��S L��P/B��  ����    ����    ����
 * ����������   ���������ة������ة������ة������� ���������ة������ة������ة������� ���������ة������ة������ة������� ���������ة������ة�������  ����    ����    ����
 * ���������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ��������������� ���������Щ������Щ������� ���������Щ������Щ������Щ�������
 * ��~ `��! 1��@ 2��# 3��$ 4��% 5��^ 6��& 7��* 8��( 9��) 0��_ -��+ =�� BacSp �� ��Ins��Hom��PUp�� ��Num�� / �� * �� - ��
 * ���������ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ����������� ���������੤�����੤������ ���������੤�����੤�����੤������
 * �� Tab �� Q �� W �� E �� R �� T �� Y �� U �� I �� O �� P ��{ [��} ]�� | \ �� ��Del��End��PDn�� �� 7 �� 8 �� 9 ��   ��
 * �������������ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ة����������� ���������ة������ة������� ���������੤�����੤������ + ��
 * �� Caps �� A �� S �� D �� F �� G �� H �� J �� K �� L ��: ;��" '�� Enter  ��               �� 4 �� 5 �� 6 ��   ��
 * ���������������ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة�����������������     ����������     ���������੤�����੤�����੤������
 * �� Shift  �� Z �� X �� C �� V �� B �� N �� M ��< ,��> .��? /��  Shift   ��     �� �� ��     �� 1 �� 2 �� 3 ��   ��
 * �������������Щ����ة��Щ��ة����Щة������ة������ة������ة������ة������ة����Щة������੤�����ةЩ��������Щ��������� ���������੤�����੤������ ���������ة������੤������ E����
 * �� Ctrl�� Win�� Alt��         Space         �� Alt�� Win��Menu��Ctrl�� �� �� �� �� �� �� �� ��   0   �� . ����������
 * �������������ة��������ة��������ة����������������������������������������������ة��������ة��������ة��������ة��������� ���������ة������ة������� �����������������ة������ة�������
 */