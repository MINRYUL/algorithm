#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    unordered_map<string,int> um;
    
    for(int i = 0; i < cities.size(); i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        priority_queue<pair<int, string>> pq;
        string maxIndex = ""; int checkMax = 0;
        bool didPop = false;
        
        if(!cacheSize){ answer += 5; continue; }
        for(auto j : um){
            um[j.first] = j.second + 1;
            pq.push({j.second + 1, j.first});
        }
        
        if(um.count(cities[i])){
            um[cities[i]] = 1;
            didPop = true; answer += 1;
        } else if(um.size() < cacheSize){
             um.insert({cities[i], 1});
            didPop = true; answer += 5;
        }
        
        if(cacheSize > 0 && pq.size() > 0){
            pair<int, string> temp = pq.top();
            if(cacheSize > 1 && pq.size() > 1)
                if(temp.second == cities[i]) pq.pop();
        
            temp = pq.top();
            
            if(!didPop){
                um.erase(temp.second);
                um.insert({cities[i], 1});
                answer += 5;
                continue;
            }
        }
        if(!didPop){
            um.insert({cities[i], 1});
            answer += 5;
        }
    }
    
    return answer;
}
