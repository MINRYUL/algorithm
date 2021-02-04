#include<bits/stdc++.h>
using namespace std;
int n;

void sol(int a, int x, int y) {
    if (a == 0) return;
    sol(a - 1, x, 6 - x - y);
    printf("%d %d\n", x, y);
    sol(a - 1, 6 - x - y, y);
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; cout << (1 << n) - 1 << endl; sol(n, 1, 3);
    return 0;
}