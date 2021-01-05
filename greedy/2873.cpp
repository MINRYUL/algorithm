#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1001
using namespace std;
string result;
int R, C, x, check, a, b, v[MAX][MAX];

void call(int i){
    bool c = false;
    for(int j = 0; j < C; j += 2){
        if(j == b){ result += "RD"; c = true;}
        else if(j + 1 == b){ result += "DR"; c = true;}
        else if(!c){ result += "DRU"; c = false;}
        else{ result += "URD"; c = true;}
        if((i == R - 1 || i == R - 2) && j == C - 2) break;
        else if(j != C - 2)  result += 'R';
        else result += 'D';
    }
}

int main(int argc, const char * argv[]) {
    cin >> R >> C;  check = INT32_MAX;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> v[i][j]; if(!(R % 2) && !(C % 2)) if(check > v[i][j] && (i + j) % 2){ a = i; b = j; check = v[i][j]; }
        }
    }
    if(R % 2 != 0 || C % 2 != 0){
        if(R % 2 != 0){
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    if(i == R - 1 && j == C - 1) break;
                    if(!(i % 2)){
                        if(j == C - 1)  result += 'D';
                        else result += 'R';
                    } else{
                        if(j == C - 1)  result += 'D';
                        else result += 'L';
                    }
                }
            }
        }
        else{
            for(int i = 0; i < C; i++){
                for(int j = 0; j < R; j++){
                    if(i == C - 1 && j == R - 1) break;
                    if(!(i % 2)){
                        if(j == R - 1)  result += 'R';
                        else result += 'D';
                    } else{
                        if(j == R - 1)  result += 'R';
                        else result += 'U';
                    }
                }
            }
        }
    }
    else{
        for(int i = 0; i < R - 1; i++){
            for(int j = 0; j < C; j++){
                if(i == R - 2 && j == C - 1) break;
                if((a == i + 1 || a == i) && i % 2 == 0){ call(i); break; }
                else if(!(i % 2)){
                    if(j == C - 1)  result += 'D';
                    else result += 'R';
                } else{
                    if(j == C - 1)  result += 'D';
                    else result += 'L';
                }
            }
        }
    }
  
    cout << result << endl;
    return 0;
}
