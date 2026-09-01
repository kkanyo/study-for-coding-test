package Programmers.coding_beginner.day5;

/*
    배열 뒤집기
    https://school.programmers.co.kr/learn/courses/30/lessons/120821
*/

import java.util.*;
import java.util.stream.*;

class _120821 {
    public int[] solution(int[] num_list) {
        // 의도된 풀이
        // int[] answer = new int[num_list.length];

        // int idx = num_list.length - 1;
        // for (int num : num_list) {
        // answer[idx--] = num;
        // }

        // return answer;

        // Stream을 사용한 풀이
        List<Integer> numList = Arrays.stream(num_list)
                .boxed()
                .collect(Collectors.toList());

        Collections.reverse(numList);

        return numList.stream()
                .mapToInt(i -> i)
                .toArray();
    }
}