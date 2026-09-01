package Programmers.algorithm_high_score_kit.stack_queue;

/*
    올바른 괄호
    https://school.programmers.co.kr/learn/courses/30/lessons/12909
 */

class _12909 {
    boolean solution(String s) {
        int bracketsCount = 0;
        for (char c : s.toCharArray()) {
            if (bracketsCount < 1 && c == ')') {
                return false;
            }

            if (c == '(') {
                bracketsCount++;
            } else {
                bracketsCount--;
            }
        }

        return bracketsCount == 0;
    }
}
