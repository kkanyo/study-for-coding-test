#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    answer.resize(num_list.size() / n + 1);

    for (int i = 0; i < numList.length; i += n) {
        answer.push_back(num_list[i]);
    }

    return answer;
}