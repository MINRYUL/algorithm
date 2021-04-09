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

using namespace std;

int solution(string dirs) {
    int answer = 0; bool visited[11][11][11][11] = {false, };
    map<char, pair<int, int>> m;
    m.insert({'U', {-1, 0}}); m.insert({'D', {1, 0}});
    m.insert({'R', {0, 1}}); m.insert({'L', {0, -1}});
    
    int x = 5, y = 5;
    for(char i : dirs){
        pair<int, int> pos = m.find(i)->second;
        int xx = x + pos.first, yy = y + pos.second;
        if(xx < 0 || yy < 0 || xx > 10 || yy > 10) continue;
        if(!visited[x][y][xx][yy]){
            visited[x][y][xx][yy] = true;
            visited[xx][yy][x][y] = true;
            answer++;
        }
        x = xx; y = yy;
    }
    
    return answer;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution("ULURRDLLU");
    return 0;
}


