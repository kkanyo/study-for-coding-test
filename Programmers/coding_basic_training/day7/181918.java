package Programmers.coding_basic_training.day7;

/*
    배열 만들기 4
    https://school.programmers.co.kr/learn/courses/30/lessons/181918
 */

import java.util.*;

class _181918 {
    public int[] solution(int[] arr) {
        // 주석 처리 된 부분은 처음에 LinkedList를 사용하여 풀이했던 부분
        // 마지막 원소만 삽입/삭제하는 경우에는 LinkedList보다 Stack이 더 효율적

        // List<Integer> stk = new LinkedList<>();
        Stack<Integer> stk = new Stack<>();
        int i = 0;

        while (i < arr.length) {
            // int lastIdx = stk.size() - 1;

            // if (stk.isEmpty() || stk.get(lastIdx) < arr[i]) {
            if (stk.isEmpty() || stk.peek() < arr[i]) {
                // stk.add(arr[i++]);
                stk.push(arr[i++]);
            } else {
                // stk.remove(lastIdx);
                stk.pop();
            }
        }

        return stk.stream().mapToInt(Integer::intValue).toArray();
    }
}