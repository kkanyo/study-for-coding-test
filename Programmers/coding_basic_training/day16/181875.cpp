/**
 * 배열에서 문자열 대소문자 변환하기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181875
 */

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(),
             [](unsigned char c) {
                 return tolower(c);
             });
    
    return str;
}

string toUpperCase(string str) {
    transform(str.begin(), str.end(), str.begin(),
              [](unsigned char c) {
                  return toupper(c);
              });
    
    return str;
}

vector<string> solution(vector<string> strArr) {
    for (int i = 0; i < strArr.size(); i++) {
        if (i % 2 != 0) {
            strArr[i] = toUpperCase(strArr[i]);
        } else {
            strArr[i] = toLowerCase(strArr[i]);
        }
    }
    
    return strArr;
}