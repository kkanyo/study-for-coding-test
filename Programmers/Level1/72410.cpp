/*
    신규 아이디 추천
    https://school.programmers.co.kr/learn/courses/30/lessons/72410
*/

#include "stdc++.h"

using namespace std;

void Level1(string& str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (isupper(str[i]))
            str[i] = tolower(str[i]);
    }
}

void Level2(string& str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (islower(str[i]) || isdigit(str[i]) ||
           str[i] == '-' || str[i] == '_' || str[i] == '.') {
            
        }
        else {
            str.erase(i--, 1);
        }
    }
}

void Level3(string& str)
{
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == '.')
        {
            if (str[i - 1] == '.')
                str.erase(i--, 1);
        }
    }
}

void Level4(string& str)
{
    if (str[0] == '.')
        str.erase(0, 1);
    
    int last = str.size() - 1;
    
    if (str[last] == '.')
        str.erase(last, 1);
}

void Level5(string& str)
{
    if(str.empty())
        str += 'a';
}

void Level6(string& str)
{
    int size = str.size();
    
    if (size >= 16) {
        str.erase(15, size - 15);
        
        if (str[14] == '.')
            str.erase(14, 1);
    }
    
}

void Level7(string& str)
{
    int size = str.size();
    
    if (size <= 2) {
        str.append(3 - size, str[size - 1]);
    }
}

string solution(string new_id) {
    string answer = "";
    
    answer = new_id;
    
    Level1(answer);
    Level2(answer);
    Level3(answer);
    Level4(answer);
    Level5(answer);
    Level6(answer);
    Level7(answer);
    
    return answer;
}

//for each문을 좀 더 활용해보자
//char형에 접근해보자