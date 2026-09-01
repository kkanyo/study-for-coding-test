/*
    크레인 인형뽑기 게임
    https://school.programmers.co.kr/learn/courses/30/lessons/64061
*/

#include "stdc++.h"

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    const int height = board[0].size();
    vector<int> bucket;
    
    for (auto &m : moves) {
        // 크레인이 이동한 위치에 인형이 있는지 확인
        for (int i = 0; i < height; ++i)  {
            // 해당 줄에 인형이 있다면 꺼냄
            if (board[i][m-1] != 0) {
                int doll = board[i][m-1];
                board[i][m-1] = 0;
                
                // 바구니의 가장 위에 같은 인형이 있다면
                // 기존 인형을 없애고 인형 2개 정산
                if (!bucket.empty() &&
                   *(bucket.rbegin()) == doll) { bucket.pop_back(); answer += 2; }
                else { bucket.push_back(doll); }
                
                break;
            }
        }
    }

    return answer;
}