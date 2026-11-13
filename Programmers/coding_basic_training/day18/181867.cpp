/**
 * x 사이의 개수
 * https://school.programmers.co.kr/learn/courses/30/lessons/181867
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    
    const char splitter = 'x';
    size_t tokenStart = 0;
    
    while (true) {
        const size_t splitterIndex = myString.find(splitter, tokenStart);
        
        if (splitterIndex == string::npos) {
            answer.push_back(static_cast<int>(myString.size() - tokenStart));
            break;
        }
        
        answer.push_back(static_cast<int>(splitterIndex - tokenStart));
        tokenStart = splitterIndex + 1;
    }
    
    return answer;
}ㅉ