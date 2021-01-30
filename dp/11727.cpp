#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char* argv[]) {
    int x, dp[1001];    cin >> x;
    dp[1] = 1;  dp[2] = 3;  dp[3] = 5;
    for (int i = 3; i <= x; i++)    dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 2]) % 10007;

    cout << dp[x] << endl;
    return 0;
}
