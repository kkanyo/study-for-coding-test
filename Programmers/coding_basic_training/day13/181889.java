package Programmers.coding_basic_training.day13;

import java.util.Arrays;

/**
 * n 번째 원소까지
 * https://school.programmers.co.kr/learn/courses/30/lessons/181889
 */
class Q181889 {
    public int[] solution(int[] numList, int n) {
        return Arrays.copyOfRange(numList, 0, n);
    }
}