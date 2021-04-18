#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <queue>
#include <stdlib.h>

#define MAX 1002000
using namespace std;

struct compare{
    bool operator()(pair<int, int>a, pair<int, int>b){
        return a.first > b.first;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, cut = 0, jobCut = 0; vector<int> t[1001];
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    for(int i = 0; i < jobs.size(); i++)
        t[jobs[i][0]].push_back(jobs[i][1]);

    for(int i = 0; i < MAX; i++){
        if(i < 1001)
            for(int j : t[i]) pq.push({j, i});
        if(jobCut == jobs.size()) break;
        if(cut) cut--;
        if(!cut && pq.size()){
            cut = pq.top().first;
            jobCut++;
            answer += (i - pq.top().second + cut);
            pq.pop();
        }
    }
    return answer/jobs.size();
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution({{0, 9}, {1, 1}, {1, 1}, {1, 1}, {1, 1}}) << endl;
    return 0;
}


