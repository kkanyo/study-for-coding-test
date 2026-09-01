/*
    명예의 전당 (1)
    https://school.programmers.co.kr/learn/courses/30/lessons/138477
*/

#include "stdc++.h"

using namespace std;

vector<int> solution(int k, vector<int> score) {
    const int dayLimit = score.size();
    
    vector<int> answer;
    vector<int> listHOF;        // 명예의 전당 점수 리스트
    
    answer.push_back(score[0]);
    listHOF.push_back(score[0]);
    
    for ( int i = 1; i < dayLimit; i++ )
    {
        // 명예의 전당이 비어있는 경우
        // 추가한 후 정렬하여 최하위 선별
        if ( i < k )
        {
            listHOF.push_back(score[i]);
            sort(listHOF.begin(), listHOF.end());
        }
        else
        {
            // 명예의 전당 최하위 점수보다 큰 경우
            // 해당 최하위 점수를 탈락 처리 후 정렬

            if ( listHOF[0] < score[i] )
            {
                listHOF[0] = score[i];
                sort(listHOF.begin(), listHOF.end());
            }
            
            // 명예의 전당 최하위 점수보다 작다면 탈락되므로
            // 최하위 점수가 유지된다
        }
        
        answer.push_back(listHOF[0]);
    }
    
    return answer;
}