#include<iostream>
#include<algorithm>
using namespace std;
int N, a[3];
double pos[7][7][7][1001], result;

int cal(int x, int y, int z) {
    a[0] = x; a[1] = y; a[2] = z;
    sort(a, a + 3);
    if(a[0] == a[1] && a[1] == a[2]) return 10000 + a[0] * 1000;
    else if(a[0] == a[1] || a[1] == a[2])  return 1000 + a[1] * 100;
    else return a[2] * 100;
}

double sol(int x, int y, int z, int n){
    double r = cal(x, y, z);
    if(n == 0) return r;
    double& a = pos[x][y][z][n];
    if(a > 0) return a;
    double m = 0;
    for(int i = 1; i < 7; i++)
        m += sol(y, z, i, n - 1);
    return a = max(r, m / 6);
    }

int main() {
    cin >> N;
    for(int i = 1; i < 7; i ++)
        for(int j = 1; j < 7; j++)
            for(int k = 1; k < 7; k++)
                result += sol(i, j, k, N - 3);
    
    cout.precision(12);
    cout << result / 216 << endl;
    return 0;
}
