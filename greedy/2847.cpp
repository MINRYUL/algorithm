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
int n, r, arr[101];

int main() {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = (n - 1); i > 0; i--){
        if(arr[i] <= arr[i - 1]){
            while(arr[i] <= arr[i - 1]){
                arr[i - 1]--; r++;
            }
        }
    }
    cout << r << endl;
    return 0;
}
