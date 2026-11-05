package Programmers.coding_basic_training.day16;

/**
 * A 강조하기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181874
 */

public class J181874 {
    public String solution(String myString) {
        StringBuilder sb = new StringBuilder(myString);

        for (int i = 0; i < sb.length(); i++) {
            if (sb.charAt(i) == 'a') {
                sb.setCharAt(i, 'A');
            } else if (sb.charAt(i) != 'A') {
                sb.setCharAt(i, Character.toLowerCase(sb.charAt(i)));
            }
        }

        return sb.toString();
    }
}
