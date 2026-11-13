/**
 * 문자열 잘라서 정렬하기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181866
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    string str_buffer = "";
    const char separator = 'x';
    
    
    for (const auto& c : myString) {        
        if (c == separator) {
            
            if (!str_buffer.empty()) {
                answer.push_back(str_buffer);
                str_buffer.clear();
            }
            
            continue;
        }
        
        str_buffer += c;
    }
    
    if (!str_buffer.empty()) {
        answer.push_back(str_buffer);    
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}