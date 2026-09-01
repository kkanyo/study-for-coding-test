/*
    점 찍기
    https://school.programmers.co.kr/learn/courses/30/lessons/140107
*/

#include <cmath>

using namespace std;

// 정수 연산만을 이용한 방법
long long solution1(int k, int d) {
    long long answer = 0;
    int posY = d - d % k;
    
    for (int posX = 0; posX <= d; posX += k)
    {
        // 찍히는 점은 호를 그리므로, 이전 y값보다 클 수 없다
        for (; posY >= 0; posY -= k)
        {
            if ( (long long)posX * posX + (long long)posY * posY
                    <= (long long)d * d )
            {
                // 최초로 찍은 점의 y값을 이용하여 세로축 갯수 추산
                // y = 0 에 대해서도 고려하는 것 주의
                answer += posY / k + 1;
                break;
            }
        }
    }

    return answer;
}

// sqrt 연산을 이용한 방법
long long solution2(int k, int d) {
    long long answer = 0;
    long long maxDistance = (long long)d * d;
    
    for (int posX = 0; posX <= d; posX += k)
    {
        int posY = sqrt( maxDistance - (long long)posX * posX );
        answer += posY / k + 1;
    }

    return answer;
}