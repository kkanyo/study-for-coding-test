/**
 * 게임 맵 최단거리
 * https://school.programmers.co.kr/learn/courses/30/lessons/1844
 */

#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int bfs(const vector<vector<int>>& maps, vector<vector<bool>> visited, int x, int y, int count) {
    int result = -1;

    queue<vector<int>> q;

    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty()) {
        int curY = q.front()[0];
        int curX = q.front()[1];
        count++;

        if (curX == maps.size() - 1 && curY == maps.size() - 1) {
            if (result < 0) {
                result = count;
            }

            min(result, count);
        }

        q.pop();

        vector<vector<int>> nextPoses {
            { curY + 1, curX },
            { curY, curX + 1},
            { curY - 1, curX},
            { curY, curX - 1}
        };

        for (auto pos : nextPoses) {
            if (visited[pos[0]][pos[1]]) {
                continue;
            }

            if (!maps[pos[0]][pos[1]]) {
                continue;
            }

            q.push(pos);
            visited[pos[0]][pos[1]];
            break;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> maps = {
        {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1}	
    };
    
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps.size(), false));

    cout << bfs(maps, visited, 0, 0, 0);

    return 0;
}