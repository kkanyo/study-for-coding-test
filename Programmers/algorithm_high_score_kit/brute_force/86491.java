package Programmers.algorithm_high_score_kit.brute_force;

/*
    최소직사각형
    https://school.programmers.co.kr/learn/courses/30/lessons/86491
 */

import java.util.Collections;
import java.util.PriorityQueue;

class _86491 {
    public int solution(int[][] sizes) {
        PriorityQueue<Integer> rowQueue = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> columnQUeue = new PriorityQueue<>(Collections.reverseOrder());

        for (int[] size : sizes) {
            if (size[0] > size[1]) {
                rowQueue.add(size[0]);
                columnQUeue.add(size[1]);
            } else {
                rowQueue.add(size[1]);
                columnQUeue.add(size[0]);
            }
        }

        return rowQueue.peek() * columnQUeue.peek();
    }
}
