/*
    완주하지 못한 선수
    https://school.programmers.co.kr/learn/courses/30/lessons/42576
 */

#include "stdc++.h"

using namespace std;

string solution_hash(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> mapParticipant;                //string: participant name
                                                    //int: the number of non-complete participant (nums)
    
    for (auto i : participant) {
        if (mapParticipant.count(i) > 0) {          //If paticipants who have same name,
            mapParticipant.find(i)->second += 1;    //increase 'nums'
        }
        mapParticipant.insert(make_pair(i, 1));
    }
    
    for (auto j : completion) {                 
        auto item = mapParticipant.find(j);         //If participant complete the marathon,
        item->second -= 1;                          //decrease 'nums'
    }
    
    for (auto k : mapParticipant) {                 //If nums == 0, that participant complete the marathon.
        if (k.second == 1) {                        //If nums >= 1, he/she did not complete it.
            answer = k.first;
        }
    }
    
    return answer;
}

string solution_sort(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    auto j = participant.begin();
    for (auto i : completion) {     //compare two vectors
        if (i != *j) {              //sorting order is not same means
            answer = *j;            //that participant do not complete the marathon
            return answer;
        }
        j++;
    }
    
    answer = *j;                    //Participant of last is do not complete the marathon
    
    return answer;
}

