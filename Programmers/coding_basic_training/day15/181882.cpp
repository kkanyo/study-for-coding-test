/**
 * 조건에 맞게 수열 변환하기 1
 * https://school.programmers.co.kr/learn/courses/30/lessons/181882
 */

#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> newArr(arr);
    
    for (int i = 0; i < arr.size(); i++) {
        int origin = arr[i];
        
        if (origin >= 50 && origin % 2 == 0) {
            newArr[i] /= 2;
        } else if (origin < 50 && origin % 2 != 0) {
            newArr[i] *= 2;
        }
    }
    
    return newArr;
}