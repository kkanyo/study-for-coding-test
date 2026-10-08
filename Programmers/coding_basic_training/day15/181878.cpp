/**
 * 원하는 문자열 찾기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181878
 */

#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(string myString, string pat) {
    auto it = search(myString.begin(), myString.end(),
           pat.begin(), pat.end(),
           [](unsigned char chr1, unsigned chr2) {
               return tolower(chr1) == tolower(chr2);
           });
    
    return it != myString.end();
}