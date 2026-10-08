package Programmers.coding_basic_training.day15;

/**
 * 원하는 문자열 찾기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181878
 */

public class J181878 {
    public int solution(String myString, String pat) {
        return myString.toLowerCase().contains(pat.toLowerCase()) ? 1 : 0;
    }
}
