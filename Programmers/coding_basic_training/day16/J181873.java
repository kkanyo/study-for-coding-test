package Programmers.coding_basic_training.day16;

/**
 * 특정한 문자를 대문자로 바꾸기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181873
 */

public class J181873 {

    public String solution(String myString, String alp) {
        return myString.replace(alp, alp.toUpperCase());
    }
}
