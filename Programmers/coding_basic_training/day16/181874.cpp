/**
 * A 강조하기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181874
 */

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string myString) {
    transform(myString.begin(), myString.end(), myString.begin(),
             [](unsigned char c) {
                 if (c == 'a') {
                     c = 'A';
                 } else if (c != 'A') {
                     c = tolower(c);
                 }
                 
                 return c;
             });
    
    return myString;
}