/*
    가장 가까운 같은 글자
    https://school.programmers.co.kr/learn/courses/30/lessons/142086
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int sizeStr = s.size();
    unordered_map<char, int> mpCharPos;
    
    for ( int i = 0; i < sizeStr; i++ ) {
        char ch = s[i];
        
        if ( mpCharPos.find(ch) != mpCharPos.end() ) {
            answer.push_back( i - mpCharPos[ch] );
        }
        else {
            answer.push_back( -1 );
        }
        
        mpCharPos[ch] = i;
    }
    
    return answer;
}