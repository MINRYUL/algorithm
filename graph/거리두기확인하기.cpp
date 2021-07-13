#include <string>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {-1, 0, 1, 0},
    dy[4] = {0, -1, 0, 1};

struct point{
    int x, y;
};

bool checkPlaces(vector<string> &place) {
    for(int j = 0; j < place.size(); j++){
        for(int k = 0; k < place[j].size(); k++){
            if(place[j][k] == 'P'){
                bool visited[5][5] = {false, };
                queue<pair<point, int>> q;
                q.push({{j, k}, 0}); visited[j][k] = true;
                while(!q.empty()){
                    pair<point, int> x = q.front(); q.pop();
                    if(x.second >= 2) continue;
                    for(int z = 0; z < 4; z++){
                        int xx = x.first.x + dx[z];
                        int yy = x.first.y + dy[z];
                        if(xx > -1 && xx < 5 && yy > -1 && yy < 5 && !visited[xx][yy]){
                            if(place[xx][yy] == 'O'){
                                q.push({{xx, yy}, x.second + 1}); visited[xx][yy] = true;
                            } else if (place[xx][yy] == 'P'){
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i < places.size(); i++){
        if(checkPlaces(places[i])) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}

int main(){
    solution({{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}});
    return 0;
}

//[["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]
