/**
 * 소문자로 바꾸기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181876
 */

#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

string solution(string myString) {
    transform(myString.begin(), myString.end(), myString.begin(),
             [](unsigned char c){
                 return tolower(c);
             });
    
    return myString;
}