/*
    로또의 최고 순위와 최저 순위
    https://school.programmers.co.kr/learn/courses/30/lessons/77484
*/

#include "stdc++.h"

using namespace std;

//우선 알 수 없는 번호를 제외하고 당첨된 번호의 개수를 센다
//그 후 알 수 없는 번호가 전부 맞는 경우와 전부 맞지 않은 경우를 고려한다

vector<int> solution(vector<int> lottos, vector<int> win_nums) {

    vector<int> answer;
    int count = 0;      //당첨된 번호의 개수
    int unknown = 0;    //알 수 없는 번호의 개수
    int rank;           //순위 계산
    
    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            unknown++;
        }
        else
        {
            for (int j = 0; j < win_nums.size(); j++)
            {
                if (lottos[i] == win_nums[j])
                {
                    count++;
                }
            }
        }
        
    }
    
    //알고 있는 번호로 순위 계산
    //알 수 없는 번호가 모두 맞지 않는다면 여기서 순위 결정
    switch(count)
    {
        case 2:
            rank = 5;
            break;
        case 3:
            rank = 4;
            break;
        case 4:
            rank = 3;
            break;
        case 5:
            rank = 2;
            break;
        case 6:
            rank = 1;
            break;
        default:
            rank = 6;
            break;
    }
    
    //알 수 없는 번호의 개수만큼 순위 변동
    //단, 모두 알 수 없는 경우 0위가 될 수 있으므로 1위로 계산
    if (rank - unknown <= 0)
    {
        answer.push_back(1);
    }
    else
    {
        answer.push_back(rank - unknown);
    }
    answer.push_back(rank);
    
    return answer;
}