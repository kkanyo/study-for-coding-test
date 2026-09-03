package Programmers.coding_basic_training.day14;

import java.util.Arrays;

/*
    n보다 커질 때까지 더하기
    https://school.programmers.co.kr/learn/courses/30/lessons/181884
*/
public class J181884 {
    public int solution(int[] numbers, int n) {
        int sum = 0;
        int i = 0;

        while (sum <= n) {
            sum += numbers[i++];
        }

        return sum;
    }

    public int solutionStream(int[] numbers, int n) {
        return Arrays.stream(numbers)
                .reduce(0, (a, b) -> a <= n ? a + b : a);
    }
}
