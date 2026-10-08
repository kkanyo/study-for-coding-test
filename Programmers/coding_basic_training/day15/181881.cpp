/** 
 * 조건에 맞게 수열 변환하기 2
 * https://school.programmers.co.kr/learn/courses/30/lessons/181881
 */

#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int count = 0;
    bool isEqual = false;

    while (!isEqual) {
        isEqual = true;
        
        for (int i = 0; i < arr.size(); i++) {
            int orgValue = arr[i];
            
            if (orgValue >= 50 && orgValue % 2 == 0) {
                arr[i] /= 2;
            } else if (orgValue < 50 && orgValue % 2 != 0) {
                arr[i] = arr[i] * 2 + 1;
            }
            
            if (arr[i] != orgValue) {
                isEqual = false;
            }
        }

        count++;
    }

    return count - 1;
}