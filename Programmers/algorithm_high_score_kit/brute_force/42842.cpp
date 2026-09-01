/*
    카펫
    https://school.programmers.co.kr/learn/courses/30/lessons/42842
*/

#include "stdc++.h"

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // i는 yellow 블럭의 세로 길이
    for (int i = 1; i <= sqrt(yellow); i++) {
        int row_y = 0;
        
        // 나누어 떨어지는 경우만 고려
        // yellow 블럭의 가로 길이 계산
        if (yellow % i == 0) { row_y = yellow / i; }
        
        // brown 블럭은 yellow 블럭을 둘러싸기 때문에
        // yellow 블럭의 가로 세로 크기 각각 2배만큼과 모서리 블럭 4개가 추가
        // 계산 후 입력 값 'brown'과 비교
        if ((i+row_y)*2 + 4 == brown) {
            answer.push_back(row_y + 2);
            answer.push_back(i + 2);
        }
    }
    
    return answer;
}