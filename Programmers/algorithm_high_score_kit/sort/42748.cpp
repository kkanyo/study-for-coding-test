/*
    K번째수
    https://school.programmers.co.kr/learn/courses/30/lessons/42748
*/

#include "stdc++.h"

using namespace std;

// sort -> O(NlogN)
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    // O(K) (max 50)
    for (auto &c : commands) {
        // commands[0] : 처음 위치
        // commands[1] : 마지막 위치
        // commands[2] : 출력 원소 위치
        vector<int> copyArray;
        
        // O(N) (max 100)
        for (int pos = c[0]-1; pos < c[1]; pos++) {
            copyArray.push_back(array[pos]);
        }
        // O(NlogN)
        sort(copyArray.begin(), copyArray.end());
        
        answer.push_back(copyArray[c[2]-1]);
    }
    
    return answer;
}