#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(long long i : numbers){
        bitset<50> bs(i); int bitIndex = 0;
        long long twoSquares = 1;
        if(!(i % 2)){
            answer.push_back(i + 1);
            continue;
        }
        while(1){
            if(!bs[bitIndex]) break;
            if(bitIndex++) twoSquares <<= 1;
        }
        answer.push_back(i - twoSquares + (twoSquares << 1));
    }
    
    return answer;
}
