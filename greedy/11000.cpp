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
#define MAX 987654321
using namespace std;
long long int n, s, t, r;
vector<pair<int, int>> v;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first < b.first;
}

int main() {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s >> t; v.push_back({s, t});
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(v.begin(), v.end(), cmp);
    pq.push(v[0].second);
    for(int i = 1; i < v.size(); i++){
        if(v[i].first < pq.top()) pq.push(v[i].second);
        else{ pq.pop(); pq.push(v[i].second); }
    }
    cout << pq.size() << '\n';
    return 0;
}
