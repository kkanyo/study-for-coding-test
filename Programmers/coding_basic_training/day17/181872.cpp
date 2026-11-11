/**
 * 특정 문자열로 끝나는 가장 긴 부분 문자열 찾기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181872
*/

#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    return myString.substr(0, myString.find_last_of(pat) + 1);
}