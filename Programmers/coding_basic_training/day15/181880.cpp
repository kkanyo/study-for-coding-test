/**
 * 1로 만들기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181880
 */

#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int totalCount = 0;
    bool isOne = false;
    vector<int>counts(num_list.size(), 0);
    
    while (!isOne) {
        isOne = true;

        for (int i = 0; i < num_list.size(); i++) {
            if (num_list[i] == 1) {
                continue;
            } else {
                isOne = false;
            }
            
            num_list[i] = (num_list[i] - num_list[i] % 2) / 2;
            
            counts[i]++;
        }
    }
    
    for (const auto& count : counts) {
        totalCount += count;
    }
    
    return totalCount;
}