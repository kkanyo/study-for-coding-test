/**
 * 대문자로 바꾸기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181877
 */

#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string myString) {
    transform(myString.begin(), myString.end(), myString.begin(),
                    [](unsigned char ch){
                        return toupper(ch);
                    });
    
    return myString;
}