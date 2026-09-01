/*
    귤 고르기
    https://school.programmers.co.kr/learn/courses/30/lessons/138476
*/

#include "stdc++.h"

using namespace std;

// 1. unordered_map을 활용한 풀이
bool ComparePairValueGreater(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}

int solution1(int k, vector<int> tangerine) {
    int answer = 0;
    int countBoxTangerine = 0;
    unordered_map<int, int> mapSizeCount;
    
    // 각 크기별 개수를 계산
    for ( const auto &size : tangerine )
    {
        ++mapSizeCount[size];
    }
    
    // 개수를 기준으로 정렬
    vector<std::pair<int, int>> listSizeCount(mapSizeCount.begin(), mapSizeCount.end());
    sort(listSizeCount.begin(), listSizeCount.end(), ComparePairValueGreater);
    
    // 개수가 가장 많은 크기부터 상자에 담는다
    for ( const auto &sizeCount : listSizeCount )
    {
        countBoxTangerine += sizeCount.second;
        ++answer;
        
        if (countBoxTangerine >= k) { break; }
    }
        
    return answer;
}


// --------------------
// 2. vector의 인덱스를 이용하여 map을 대체한 풀이
// vector의 인덱스를 map에서의 크기(key)로 사용한다는 발상이 좋아 참고함
// 최악의 상황일 때 시간과 공간을 많이 사용하는 경향이 있음
// tangerine 벡터를 2번 방문한다는 점과, 
// 존재하지 않는 크기에 대한 공간까지 할당하기 때문인 것으로 추정
int solution2(int k, vector<int> tangerine) {
    int answer = 0;
    int numTotalBox = 0;
    int numMaxSize = *max_element(tangerine.begin(), tangerine.end());
    vector<int> vecSizeCount(numMaxSize, 0);
    
    for ( const auto &size : tangerine )
    {
        ++vecSizeCount[size - 1];
    }
    
    stable_sort(vecSizeCount.begin(), vecSizeCount.end(), greater<int>());
    
    for ( const auto &size : vecSizeCount )
    {
        numTotalBox += size;
        ++answer;
        if ( numTotalBox >= k ) { break; }
    }
    
    return answer;
}