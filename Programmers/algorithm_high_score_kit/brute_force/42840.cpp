#include "stdc++.h"

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> students[3];
    
    // 각 수포자가 찍는 방식의 패턴을 벡터에 저장
    students[0] = {1, 2, 3, 4, 5};
    students[1] = {2, 1, 2, 3, 2, 4, 2, 5};
    students[2] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    // 각 수포자의 정답 수를 저장
    int sum[3] = {0};
    
    // 각 수포자의 패턴을 진행하기 위한 반복자 개체
    vector<int>::iterator iter[3];
    
    // 반복자 초기화
    for (int i = 0; i < 3; i++) {
        iter[i] = students[i].begin();
    }
    
    // 답안을 기준으로 반복
    for (auto &answer : answers) {
        for (int i = 0; i < 3; i++) {
            // 패턴의 마지막인 경우 다시 처음으로 돌아감
            if (iter[i] == students[i].end()) { iter[i] = students[i].begin(); }
            // 패턴 벡터의 반복자를 하나씩 비교하면서 정답과 같은 경우 정답 수 증가
            if (*iter[i]++ == answer) { sum[i]++; }
        }
    }
    
    // 가장 높은 정답 수 체크
    int max = 0;
    for (int i = 0; i < 3; i++) {
        if (max <= sum[i]) {
            max = sum[i];
        }
    }
    
    // 가장 높은 정답 수를 가진 학생 찾기
    for (int i = 0; i < 3; i++) {
        if (max == sum[i]) {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}