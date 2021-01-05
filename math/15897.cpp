#include<iostream>
using namespace std;
long long n, x, ans;

int main(void) {
    cin >> n;
    for (int i = --n + 1; i > 0; i = n / ((n / i) + 1))
        ans += (n / i + 1) * (i - (n / ((n / i) + 1)));
    cout << ans;
    return 0;
}
