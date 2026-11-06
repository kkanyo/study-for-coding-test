/**
 * 특정한 문자를 대문자로 바꾸기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181873
 */

#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string toUpperCase(string org, const string alp) {
    transform(org.begin(), org.end(), org.begin(),
             [&alp](unsigned char c) {
                 if (alp.find(c) != string::npos) {
                     return toupper(c);
                 }
                 
                 return static_cast<int>(c);
             });

    return org;
}

string solution(string my_string, string alp) {
    return toUpperCase(my_string, alp);
}