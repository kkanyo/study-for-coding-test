/**
 * 공백으로 구분하기 1
 * https://school.programmers.co.kr/learn/courses/30/lessons/181869
*/

#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> strArr;
    char space = ' ';
    size_t begin = 0;
    size_t pos = my_string.find(space, begin);
    
    while (pos != string::npos) {
        strArr.push_back(my_string.substr(begin, pos - begin));
    
        begin = pos + 1;
        
        pos = my_string.find(space, begin);
    }
    
    strArr.push_back(my_string.substr(begin, my_string.size() - begin));
    
    return strArr;
}