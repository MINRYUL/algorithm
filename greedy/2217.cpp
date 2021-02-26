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
int n, k, t, r, rope[MAX];

int main() {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> rope[i];
    sort(rope, rope + n);
    for(int i = 0; i < n; i++) rope[i] *= (n - i);
    sort(rope, rope + n);
    cout << rope[n - 1] << endl;
    return 0;
}
