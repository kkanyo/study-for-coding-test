/**
 * 문자열이 몇 번 등장하는지 세기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181871
*/

#include <string>

using namespace std;

int solution(string myString, string pat) {
    int count = 0;
    size_t pos = myString.find(pat, 0);
    
    while (pos != string::npos) {
        count++;
        
        pos = myString.find(pat, pos + 1);
    }
    
    return count;
}