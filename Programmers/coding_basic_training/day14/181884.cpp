#include <vector>

using namespace std;

/*
    n보다 커질 때까지 더하기
    https://school.programmers.co.kr/learn/courses/30/lessons/181884
*/
int solution(vector<int> numbers, int n) {
    int sum = 0;
    int i = 0;

    while (sum <= n) {
        sum += numbers[i++];
    }

    return sum;
}