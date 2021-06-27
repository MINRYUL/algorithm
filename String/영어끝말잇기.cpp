#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    char beforeAlphabet = 'A';
    map<string, int> m;
    
    for(int i = 0; i < words.size(); i++){
        int wordSize = words[i].size() - 1;
        if(i && ((beforeAlphabet != words[i][0]) || (m.count(words[i])))) {
            int person = (i + 1) % n;
            int sequence = ((i + 1) / n);
            if(!person) person = n;
            else sequence += 1;
            return {person, sequence};
        }
        beforeAlphabet = words[i][wordSize];
        m[words[i]] = 1;
    }

    return {0, 0};
}
