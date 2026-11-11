/**
 * 공백으로 구분하기 2
 * https://school.programmers.co.kr/learn/courses/30/lessons/181868
*/

#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    int begin = -1;
    
    for (int i = 0; i < my_string.size(); i++) {
        if (my_string.at(i) != ' ' && begin < 0) {
            begin = i;
            continue;
        }
        
        if (my_string.at(i) == ' ' && begin >= 0) {
            answer.push_back(my_string.substr(begin, i - begin));
            
            begin = -1;
        }
    }
    
    if (begin < my_string.length()) {
        answer.push_back(my_string.substr(begin, my_string.length() - begin));
    }
    
    return answer;
}



vector<string> solution2(string my_string) {
    vector<string> answer;
    char separator = ' ';
    istringstream iss(my_string);
    string str_buf;
    
    while (getline(iss, str_buf, separator)) {
        if (str_buf.empty()) {
            continue;
        }
        
        answer.push_back(str_buf);
    }
    
    return answer;
}

vector<string> solutionOpt1(string my_string) {
    vector<string> words;
    optional<size_t> wordStart; // optional<size_t>는 size_t 타입의 값을 가질 수 있거나 값이 없을 수 있는 타입

    for (size_t i = 0; i < my_string.size(); i++) {
        const bool isWordEnd = i == my_string.size() || my_string[i] == ' ';
    
        if (!isWordEnd && !wordStart) {
            wordStart = i;
        }
        else if (isWordEnd && wordStart) {
            words.push_back(my_string.substr(*wordStart, i - *wordStart));
            wordStart.reset();
        }
    }
}

vector<string> solutionOpt2(string my_string) {
    vector<string> words;
    istringstream stream(my_string);
    string word;

    // `operator>>`는 앞쪽 공백과 연속 공백을 자동으로 건너뜁니다.
    while (stream >> word) {
        words.push_back(word);
    }
}