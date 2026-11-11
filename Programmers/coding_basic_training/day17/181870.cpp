/**
 * ad 제거하기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181870
*/

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    for (int i = 0; i < strArr.size(); i++) {
        if (strArr[i].find("ad") != string::npos) {
            continue;
        }
        
        answer.push_back(strArr[i]);
    }
    
    return answer;
}