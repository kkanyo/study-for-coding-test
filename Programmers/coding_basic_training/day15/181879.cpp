/**
 * 길이에 따른 연산
 * https://school.programmers.co.kr/learn/courses/30/lessons/181879
 */

#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int total = 0;
    size_t size = num_list.size();
    
    if (size <= 10) {
        total = 1;
    }
    
    for (const auto& num : num_list) {
        if (size <= 10) {
            total *= num;
        } else {
            total += num;
        }
    }
    
    return total;
}