package Programmers.coding_basic_training.day14;

/*
    짝수 홀수 개수
    https://school.programmers.co.kr/learn/courses/30/lessons/181887
*/

public class J181887 {
    public int solution(int[] numList) {
        int oddSum = 0;
        int evenSum = 0;

        for (int i = 0; i < numList.length; i++) {
            if (i % 2 == 0) {
                evenSum += numList[i];
            } else {
                oddSum += numList[i];
            }
        }

        return oddSum > evenSum ? oddSum : evenSum;
    }
}