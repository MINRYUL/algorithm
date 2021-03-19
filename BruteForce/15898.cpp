#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int n, a, ans, quality[10][4][4], ansQulity[5][5];
char b, matarial[10][4][4], ansMatarial[5][5];
void rotate(int x){
    int rotatedNum[4][4];
    char rotatedChar[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            rotatedNum[j][3 - i] = quality[x][i][j];
            rotatedChar[j][3 - i] = matarial[x][i][j];
        }
    }
    for(int i = 0; i < 4; i++){
        copy(rotatedNum[i], rotatedNum[i] + 4, quality[x][i]);
        copy(rotatedChar[i], rotatedChar[i] + 4, matarial[x][i]);
    }
}

void sumAns(){
    int sumans = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(ansMatarial[i][j] == 'R') sumans += 7 * ansQulity[i][j];
            else if(ansMatarial[i][j] == 'B') sumans += 5 * ansQulity[i][j];
            else if(ansMatarial[i][j] == 'G') sumans += 3 * ansQulity[i][j];
            else if(ansMatarial[i][j] == 'Y') sumans += 2 * ansQulity[i][j];
        }
    }
    if(sumans > ans) ans = sumans;
}

void setAns(int a, int b, int position){
    for(int i = a; i < a + 4; i++){
        for(int j = b; j < b + 4; j++){
            ansQulity[i][j] += quality[position][i - a][j - b];
            if(ansQulity[i][j] > 9) ansQulity[i][j] = 9;
            else if(ansQulity[i][j] < 0) ansQulity[i][j] = 0;
            if(matarial[position][i - a][j - b] != 'W') ansMatarial[i][j] = matarial[position][i - a][j - b];
        }
    }
}

void searchAns(int a, int b, int c){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                for(int z = 0; z < 4; z++){
                    rotate(a);
                    for(int h = 0; h < 4; h++){
                        rotate(b);
                        for(int f = 0; f < 4; f++){
                            rotate(c);
                            if(i == 0)   setAns(0, 0, a);
                            else if(i == 1) setAns(0, 1, a);
                            else if(i == 2) setAns(1, 0, a);
                            else setAns(1, 1, a);
                            if(j == 0)   setAns(0, 0, b);
                            else if(j == 1) setAns(0, 1, b);
                            else if(j == 2) setAns(1, 0, b);
                            else setAns(1, 1, b);
                            if(k == 0)   setAns(0, 0, c);
                            else if(k == 1) setAns(0, 1, c);
                            else if(k == 2) setAns(1, 0, c);
                            else setAns(1, 1, c);
                            sumAns();
                            for(int o = 0; o < 5; o++){
                                memset(ansQulity[o], 0, sizeof(int) * 5);
                                memset(ansMatarial[o], 'W', sizeof(char) * 5);
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(void) {
    cin >> n;
    for(int i = 0; i < n * 2; i++)
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++){
                if(i % 2 == 0) cin >> a, quality[i/2][j][k] = a;
                else cin >> b, matarial[i/2][j][k] = b;
            }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            for(int k = 0; k < n; k++){
                if(k == i || k == j)  continue;
                searchAns(i, j, k);
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
