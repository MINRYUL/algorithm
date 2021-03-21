#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <map>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    stack<int> st; vector<pair<int, int>> ongoing;
    reverse(truck_weights.begin(), truck_weights.end());
    for(int i = 0; i < truck_weights.size(); i++)
        st.push(truck_weights[i]);
    
    while(!st.empty()){
        int x = st.top();
        if(weight >= x){
            ongoing.push_back({x, bridge_length});
            weight -= x; st.pop();
        }
        for(int i = 0; i < ongoing.size(); i++){
            ongoing[i].second -= 1;
            if(!ongoing[i].second){
                weight += ongoing[i].first;
                ongoing.erase(ongoing.begin() + i);
                i--;
            }
        }
        answer++;
    }
    answer += ongoing[ongoing.size() - 1].second;
    return answer + 1;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution(100, 100, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}) << endl;
    return 0;
}

