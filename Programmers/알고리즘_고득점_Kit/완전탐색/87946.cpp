/**
 * 피로도
 * https://school.programmers.co.kr/learn/courses/30/lessons/87946
 * 
 * 재풀이 필요
 */

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int dfs(int k, vector<vector<int>>& dungeons, vector<int> visited, int clear) {
    // 현재 던전 방문 수 저장
    int result = clear;
    
    // 모든 던전을 순회하면서
    for (int i = 0; i < dungeons.size(); i++) {
        // 이미 방문한 던전이거나 현재 피로도가 던전의 최소 피로도보다 작으면 건너뜀
        if (visited[i] || k < dungeons[i][0]) {
            continue;
        }
        
        // 현재 던전 방문 처리
        visited[i] = 1;
        
        // 소모 피로도를 빼고 다음 던전 방문
        result = max(dfs(k - dungeons[i][1], dungeons, visited, clear + 1), result);
        
        // 다음 던전 방문을 위해 방문 처리 초기화 (백트래킹)
        visited[i] = 0;
    }
    
    return result;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<int> visited(dungeons.size(), 0);
    int clear = 0;
    
    return dfs(k, dungeons, visited, clear);
}

