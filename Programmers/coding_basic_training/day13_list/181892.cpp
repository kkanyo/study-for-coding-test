/*
 * n 번째 원소부터
 * https://school.programmers.co.kr/learn/courses/30/lessons/181892
*/

#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    return vector<int>(num_list.begin() + n, num_list.end());
}