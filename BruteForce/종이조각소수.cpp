#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>

using namespace std;
int result, arr[7], n;
string s;
bool visited[7];
bool checkNum[10000000];

bool sieveFind(int M) {
    if(M < 2) return false;
    for(int i = 2; i <= sqrt(M); i++)
        if(M % i == 0) return false;
    return true;
}

void dfs(){
    if(s.size() > n) return;
    stringstream ss(s);
    int t = 0; ss >> t;
    if(sieveFind(t) && !checkNum[t]){
        checkNum[t] = true; result++;
    }
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        visited[i] = true; s.push_back(arr[i] + 48);
        dfs();
        visited[i] = false; s.pop_back();
    }
}

int solution(string numbers) {
    n = numbers.size();
    for(int i = 0; i < numbers.size(); i++)
        arr[i] = numbers[i] - 48;
    
    for(int i = 0; i < n; i++){
        if(!arr[i]) continue;
        visited[i] = true; s.push_back(arr[i] + 48);
        dfs();
        visited[i] = false; s.pop_back();
    }
    return result;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution("011") << endl;
    return 0;
}

