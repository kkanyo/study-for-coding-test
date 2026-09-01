/*
    순서 바꾸기
    https://school.programmers.co.kr/learn/courses/30/lessons/181891
*/

#include <vector>

using namespace std;

vector<int> solution(const vector<int>& num_list, int n) {
    vector<int> result;
    result.reserve(numList.size());
    
    result.insert(result.end(), numList.begin() + n, numList.end());
    result.insert(result.end(), numList.begin(), numList.begin() + n);

    return answer;
}