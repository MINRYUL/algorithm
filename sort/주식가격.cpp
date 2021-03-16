#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<pair<int, int>> r;
    priority_queue<pair<int, int>> pq;
    pq.push({prices[0], 0});
    for(int i = 1; i < prices.size(); i++){
        if(pq.top().first <= prices[i]){
            pq.push({prices[i], i});
            continue;
        }
        while(pq.top().first > prices[i]){
            r.push_back({i - pq.top().second, pq.top().second});
            pq.pop();
            if(!pq.size()) break;
        }
        pq.push({prices[i], i});
    }
    while(!pq.empty()){
        r.push_back({prices.size() - pq.top().second - 1, pq.top().second});
        pq.pop();
    }
    sort(r.begin(), r.end(), cmp);
    for(pair<int, int> i : r) answer.push_back(i.first);
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solution({1, 2, 3, 2, 3});
    return 0;
}

