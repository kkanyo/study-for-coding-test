/*
    왼쪽 오른쪽
    https://school.programmers.co.kr/learn/courses/30/lessons/181890
*/

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list) {
    for (auto it = str_list.begin(); it != str_list.end(); it++) {
        if (*it == "l") {
            return vector<string>(str_list.begin(), it);
        }

        if (*it == "r") {
            return vector<string>(it + 1, str_list.end());
        }
    }

    return vector<string>();
}