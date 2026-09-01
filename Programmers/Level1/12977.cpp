/*
    소수 만들기
    https://school.programmers.co.kr/learn/courses/30/lessons/12977
*/

#include "stdc++.h"

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int sum = 0;    
    
    // 완전 탐색
    for (int posBegin = 0; posBegin < nums.size() - 2; ++posBegin) {
        sum += nums[posBegin];
        
        for (int posMiddle = posBegin+1; posMiddle < nums.size() - 1; ++posMiddle) {
            sum += nums[posMiddle];
            
            for (int posEnd = posMiddle+1; posEnd < nums.size(); ++posEnd) {
                sum += nums[posEnd];
                
                // 소수인지 확인한다
                int i = 1;
                // 2 ~ sum/2 까지만 확인해도 상관없다
                while (++i < sum/2) {
                    if (sum % i == 0) { break; }
                }
                
                // 끝까지 확인해봤을 때 나누어떨어지지 않았다면 소수다
                if(i >= sum/2) answer++;
                
                sum -= nums[posEnd];
            }
            sum -= nums[posMiddle];
        }
        sum -= nums[posBegin];
    }
        
    return answer;
}