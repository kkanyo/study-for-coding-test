#include <string>
#include <vector>

using namespace std;

/*
    짝수 홀수 개수
    https://school.programmers.co.kr/learn/courses/30/lessons/181887
*/
int solution(vector<int> num_list) {
    int oddSum = 0;
    int evenSum = 0;

    for (int i = 0; i < num_list.size(); i++) {
        if (i % 2 == 0) {
            evenSum += num_list[i];
        } else {
            oddSum += num_list[i];
        }
    }
    
    return oddSum > evenSum ? oddSum : evenSum;
}