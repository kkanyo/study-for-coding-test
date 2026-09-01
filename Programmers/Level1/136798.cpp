/*
    기사단원의 무기
    https://school.programmers.co.kr/learn/courses/30/lessons/136798
*/

#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> vecCountDiv(number, 0);
    
    // 어떤 수는 약수의 배수라는 점을 이용한 방법
    for ( int i = 1; i <= number; i++)
    {
        for ( int j = 1; j <= number / i; j++)
        {
            ++vecCountDiv[i * j - 1];
        }
    }
    
    for ( int i = 0; i < number; i++)
    {
        answer += 
            vecCountDiv[i] > limit ? power : vecCountDiv[i];
    }
    
    return answer;
}