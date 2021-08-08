#include<bits/stdc++.h>


int max(int a, int b) {
	return a > b ? a: b;
}

void print(int a, int b, int (*p)(int a, int b)) {
	printf("%d\n", p(a, b));
}

sort(, cmp)



int main() {
	print(1, 2, max);
}