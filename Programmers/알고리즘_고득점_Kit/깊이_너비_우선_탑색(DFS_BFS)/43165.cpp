/**
 * 타겟 넘버
 * https://school.programmers.co.kr/learn/courses/30/lessons/43165
 */

#include <string>
#include <vector>

void dfs(const std::vector<int>& numbers, std::size_t startIdx, int curSum, int target, int& count) {
    // 현재 조합이 타겟과 같다면 조합 완성
    if (curSum == target) {
        ++count;
        return;
    }

    // 현재 조합이 타겟보다 작다면 추가 탐색 필요 없음
    if (curSum < target) {
        return;
    }

    for (std::size_t i = startIdx; i < numbers.size(); ++i) {
        const int nextSum = curSum - (numbers[i] * 2);

        // 중복 방지를 위해 다음 인덱스부터 탐색
        dfs(numbers, i + 1, nextSum, target, count);
    }
}
    
int solution(std::vector<int> numbers, int target) {
    int sum = 0;

    for (int number : numbers) {
        sum += number;
    }

    int count = 0;

    dfs(numbers, 0, sum, target, count);

    return count;
}

#include <numeric>

int solution(std::vector<int> numbers, int target) {
    const int totalSum = std::accumulate(numbers.begin(), numbers.end(), 0);
    const int difference = totalSum - target;

    // 타겟을 만들 수 없는 경우
    if (difference < 0 || difference % 2 != 0) {
        return 0;
    }

    const int negativeSum = difference / 2;
    std::vector<int> ways(negativeSum + 1, 0);
    
    ways[0] = 1;

    for (int number : numbers) {
        for (int sum = negativeSum; sum >= number; --sum) {
            ways[sum] += ways[sum - number];
        }
    }

    return ways[negativeSum];
}