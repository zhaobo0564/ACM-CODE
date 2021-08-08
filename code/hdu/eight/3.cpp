#include<bits/stdc++.h>
using namespace std;

int x[3], y[3];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 3; i++) {
            scanf("%d %d", &x[i], &y[i]);
        } 
        if (x[0] > 0 && y[0] > 0) { // 1
            if (y[1] <= y[0] && y[2] <= y[0]) {
                if (x[1] > x[2]) {
                    puts("Clockwise");
                } else {
                    puts("Counterclockwise");
                }
            } else if (y[1] <= y[0]) {
                puts("Clockwise");
            } else if (y[2] <= y[0]) {
                puts("Counterclockwise");
            } else {
                if (x[1] < x[2]) {
                    puts("Clockwise");
                } else {
                    puts("Counterclockwise");
                }
            }
        } else if (x[0] > 0 && y[0] < 0) { // 2
            if (y[1] <= y[0] && y[2] <= y[0]) {
                if (x[1] > x[2]) {
                    puts("Clockwise");
                } else {
                    puts("Counterclockwise");
                }
            } else if (y[1] <= y[0]) {
                puts("Clockwise");
            } else if (y[2] <= y[0]) {
                puts("Counterclockwise");
            } else {
                if (x[1] < x[2]) {
                    puts("Clockwise");
                } else {
                    puts("Counterclockwise");
                }
            }
        } else if (x[0] < 0 && y[0] < 0) { // 3
            if (y[1] <= y[0] && y[2] <= y[0]) {
                if (x[1] > x[2]) {
                    puts("Clockwise");
                } else {
                    puts("Counterclockwise");
                }
            } else if (y[1] <= y[0]) {
                puts("Counterclockwise");
            } else if (y[2] <= y[0]) {
                puts("Clockwise");
            } else {
                if (x[1] < x[2]) {
                    puts("Clockwise");
                } else {
                    puts("Counterclockwise");
                }
            }
        } else if (x[0] < 0 && y[0] > 0) {
            if (y[1] <= y[0] && y[2] <= y[0]) {
                if (x[1] > x[2]) {
                    puts("Clockwise");
                } else {
                    puts("Counterclockwise");
                }
            } else if (y[1] <= y[0]) {
                puts("Counterclockwise");
            } else if (y[2] <= y[0]) {
                puts("Clockwise");
            } else {
                if (x[1] < x[2]) {
                    puts("Clockwise");
                } else {
                    puts("Counterclockwise");
                }
            }
        }
    }
}