package Programmers.coding_beginner.day3;

/*
    최빈값 구하기
    https://school.programmers.co.kr/learn/courses/30/lessons/120812
*/

import java.util.Map;
import java.util.HashMap;

class _120812 {
    public int solution(int[] array) {
        int answer = 0;
        int maxCount = 0;

        // 처음 나의의 풀이
        // HashMap<Integer, Integer> arrayMap = new HashMap<>();
        // for (var elem : array) {
        // int count = arrayMap.getOrDefault(elem, 0);
        // arrayMap.put(elem, count+1);
        // }

        // for (var elem : arrayMap.keySet()) {
        // if (maxCount < arrayMap.get(elem)) {
        // maxCount = arrayMap.get(elem);
        // answer = elem;
        // continue;
        // }

        // if (maxCount == arrayMap.get(elem)) {
        // answer = -1;
        // }
        // }

        // 다른 사람 풀이 참고
        // HashMap의 경우 삽입 순서를 보장하지 않는 대신 O(1)의 시간복잡도를 가지는 특징을 이용
        // 처음 풀이와 다른 점은 array를 순회하는 동시에 HashMap에 삽입하면서 maxCount와 answer를 갱신하는 방식
        Map<Integer, Integer> map = new HashMap<>();
        for (var elem : array) {
            int count = map.getOrDefault(elem, 0) + 1;
            if (maxCount < count) {
                maxCount = count;
                answer = elem;
            } else if (maxCount == count) {
                answer = -1;
            }

            map.put(elem, count);
        }

        return answer;
    }
}