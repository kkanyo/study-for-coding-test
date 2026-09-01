/*
 * n 번째 원소부터
 * https://school.programmers.co.kr/learn/courses/30/lessons/181892
*/

package Programmers.coding_basic_training.day13_list;

import java.util.Arrays;

class _181892 {
    public int[] solution(int[] num_list, int n) {
        return Arrays.copyOfRange(num_list, n - 1, num_list.length);
    }
}
