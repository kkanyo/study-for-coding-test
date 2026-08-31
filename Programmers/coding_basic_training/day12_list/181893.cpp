
/*
 * 배열 조각하기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181893
*/

#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    for (int i = 0; i < query.size(); i++) {
        if (i % 2 == 0) {
            arr.erase(arr.begin() + query[i] + 1, arr.end());
        } else {
            arr.erase(arr.begin(), arr.begin() + query[i]);
        }
    }

    return arr;
}

// optimized solution
vector<int> solutionOpt(const vector<int>& arr, const vector<int>& query) {
    int startIndex = 0;
    int endIndex = static_cast<int>(arr.size()) - 1;

    for (int queryIndex = 0; queryIndex < static_cast<int>(query.size()); ++queryIndex) {
        int cutIndex = query[queryIndex];

        if (queryIndex % 2 == 0) {
            endIndex = startIndex + cutIndex;
        } else {
            startIndex += cutIndex;
        }
    }
    
    return vector<int>(
        arr.begin() + startIndex,
        arr.begin() + endIndex + 1
    );
}