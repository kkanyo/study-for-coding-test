package Programmers.coding_basic_training.day18;

/**
 * x 사이의 개수
 * https://school.programmers.co.kr/learn/courses/30/lessons/181867
 */

public class J181867 {
    public int[] solution(String myString) {
        String[] subStrings;
        String splitter = "x";

        subStrings = myString.split(splitter, -1);
        int[] answer = new int[subStrings.length];

        for (int i = 0; i < subStrings.length; i++) {
            answer[i] = subStrings[i].length();
        }

        return answer;
    }
}