/*
 * 2의 영역
 * https://school.programmers.co.kr/learn/courses/30/lessons/181894
*/

#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    constexpr int target = 2;

    const auto firstTargetIndex = find(arr.begin(), arr.end(), target);
    if (firstTargetIndex == arr.end()) {
        return {-1};
    }

    const auto lastTargetIndex = find(arr.rbegin(), arr.rend(), target);

    // base()는 reverse iterator가 가리키는 원소의 다음 위치를 가리킨다.
    return vector<int>(firstTargetIndex, lastTargetIndex.base());
}

// 한 번만 순회
vector<int> solutionOpt(vector<int> arr) {
    int firstTargetIndex = -1;
    int lastTargetIndex = -1;
    for (int index = 0; index < static_cast<int>(arr.size()); ++index) {
        if (arr[index] == 2) {
            if (firstTargetIndex == -1) {
                firstTargetIndex = index;
            }
            lastTargetIndex = index;
        }
    }
    if (firstTargetIndex == -1) {
        return {-1};
    }
    return vector<int>(
        arr.begin() + firstTargetIndex,
        arr.begin() + lastTargetIndex + 1
    );
}