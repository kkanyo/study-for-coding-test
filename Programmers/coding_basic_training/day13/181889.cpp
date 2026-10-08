/**
 * n 번째 원소까지
 * https://school.programmers.co.kr/learn/courses/30/lessons/181889
 */
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    return vector<int>(num_list.begin(), num_list.begin() + n);
}