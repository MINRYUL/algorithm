//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> //sort ..
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cmath> //pow, sqrt
#include <cstring> //memset
#include <utility> //pair
#define MAX 100001
using namespace std;
int n, r, a[51], b[51];

int main() {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n); sort(b, b + n);
    for(int i = 0; i < n; i++) r += a[i] * b[n - i - 1];
    cout << r << endl;
    return 0;
}
