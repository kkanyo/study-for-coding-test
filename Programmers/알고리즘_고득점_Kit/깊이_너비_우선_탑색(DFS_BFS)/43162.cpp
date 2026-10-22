/**
 * 네트워크
 * https://school.programmers.co.kr/learn/courses/30/lessons/43162
 */

#include <vector>
#include <queue>

using namespace std;

int bfs(const vector<vector<int>>& computers, vector<bool>& visited) {
    int countNetwork = 0;
    
    for (int start = 0; start < computers.size(); start++) {
        if (visited[start]) {
            continue;
        }
        
        // 네트워크 카운드
        countNetwork++;
        
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int next = 0; next < computers[curr].size(); next++) {
                if (visited[next]) {
                    continue;
                }

                if (computers[curr][next]) {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
    }
    
    return countNetwork;
}


int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n);
    
    return bfs(computers, visited);
}