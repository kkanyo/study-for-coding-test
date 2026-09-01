/*
    문자열 나누기
    https://school.programmers.co.kr/learn/courses/30/lessons/140108
*/

#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    int strSize = s.size();
    int standIndex = 0;
    int cmpIndex = 0;
    int numStandCnt = 0;
    
    while ( true )
    {
        // 기준 문자(x)가 나온 횟수 기록
        if ( s[standIndex] == s[cmpIndex] ) { ++numStandCnt; }
        
        // 현재 검사 완료된 문자열의 길이가 기준 글자가 나온 횟수의 2배가 되면 분해
        if ( cmpIndex - standIndex + 1 == numStandCnt * 2 )
        {
            ++answer;
            numStandCnt = 0;
            standIndex = cmpIndex + 1;
        }
        // 문자열의 끝까지 검사를 완료했다면
        // 횟수가 다른지 검사하고 종료
        // 문자열 마지막 '\n' 고려
        else if ( cmpIndex >= strSize - 2 )     
        {
            if ( cmpIndex - standIndex + 1 < numStandCnt * 2 ) 
            {
                ++answer;
            }
            break;
        }
        
        ++cmpIndex;
    }

    
    return answer;
}