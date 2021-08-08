#include<bits/stdc++.h>

struct Tree {
    int lson, rson, value;
}tree[10000];

int top = 1;
void insert(int x, int &now) {
    if (!now) {
        now = top++;
        tree[now].value = x;
        return;
    }
    if (x < tree[now].value) {
        insert(x, tree[now].lson);
    } else {
        insert(x, tree[now].rson);
    }
}

void find(int x, int now) {
    if (tree[now].value == x) {
        std::cout << "find it!!!\n";
        return;
    }
    if (tree[now].value > x) {
        return find(x, tree[now].lson);
    } else {
        return find(x, tree[now].rson);
    }
}

int main() {

    int n; std::cin >> n; //����n����
    int rt = 0;
    for (int i = 1; i <= n; i++) {
        int x; std::cin >> x;
        insert(x, rt);
    }
    puts("������ҵ�����");
    int x; scanf("%d", &x); // ������ҵ���
    find(x, rt);
    puts("ʱ�� 1 ms");
}
