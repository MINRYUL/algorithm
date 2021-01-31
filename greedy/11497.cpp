//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> //sort ..
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cstring> //memset
#include <utility> //pair
using namespace std;
int t, n, x, MAX, result, temp;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n; result = 0;
        vector<int> v, t1, t2, r;
        for(int i = 0; i < n; i++){
            cin >> x; v.push_back(x);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            if(!(i % 2)) t1.push_back(v[i]);
            else t2.push_back(v[i]);
        }
        for(int i = 0; i < t1.size(); i++) r.push_back(t1[i]);
        reverse(t2.begin(), t2.end());
        for(int i = 0; i < t2.size(); i++) r.push_back(t2[i]);
        
        for(int i = 1; i < r.size(); i++){
            temp = abs({r[i - 1] - r[i]});
            result = max({result, temp});
        }
        temp = abs({r[r.size() - 1] - r[0]});
        result = max({result, temp});
        cout << result << '\n';
    }
    
    return 0;
}
