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
using namespace std;
pair<int, int> r[41];
int n, x;

int main() {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n;
    r[0] = {1, 0}; r[1] = {0, 1}; r[2] = {1, 1};
    for(int i = 3; i <= 40; i++){
        r[i] = {r[i - 1].first + r[i - 2].first, r[i - 1].second + r[i - 2].second};
    }
    for(int i = 0; i < n; i++){
        cin >> x; cout << r[x].first << ' ' << r[x].second << '\n';
    }
    return 0;
}
