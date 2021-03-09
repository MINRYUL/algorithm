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
int h, w, x, result, check;
vector<int> arr;
pair<int, int> present;
pair<int, int> temp;

int main() {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> h >> w;
    for(int i = 0; i < w; i++){
        cin >> x; arr.push_back(x);
    }
    for(int i = 0; i < w; i++){
        if(!arr[i]) continue;
        present = {arr[i], i};
        for(int j = i + 1; j < w; j++){
            if(!arr[j]) continue;
            if(temp.first < arr[j]) temp = {arr[j], j};
            if(temp.first >= present.first) break;
        }
        int t = min(present.first, temp.first);
        for(int j = present.second + 1; j < temp.second; j++)
            result += (t - arr[j]);
        if(temp.first) i = temp.second - 1;
        temp = {0, 0};
    }
    cout << result << endl;
    return 0;
}
