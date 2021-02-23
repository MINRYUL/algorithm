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
#define MAX 100001
int n, m, x, y, arr[MAX];


int main(void) {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++) arr[i] = arr[i] + arr[i - 1];
    for(int i = 0; i < m; i++){
        cin >> x >> y; cout << arr[y] - arr[x - 1] << '\n';
    }
    
    return 0;
}
