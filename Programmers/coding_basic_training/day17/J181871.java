package Programmers.coding_basic_training.day17;

/**
 * 문자열이 몇 번 등장하는지 세기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181871
 */

public class J181871 {
    public int solution(String myString, String pat) {
        int count = 0;
        int pos = myString.indexOf(pat, 0);

        while (pos >= 0) {
            count++;
            pos = myString.indexOf(pat, pos + 1);
        }

        return count;
    }
}
