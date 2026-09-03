#include <vector>

using namespace std;

/*
    수열과 구간 쿼리 1
    https://school.programmers.co.kr/learn/courses/30/lessons/181883
*/
vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for (auto query : queries) {
        for (int i = query[0]; i <= query[1]; i++) {
            arr[i] += 1;
        }
    }

    return arr;
}