package Programmers.coding_beginner.day6;

/*
    뒤집힌 문자열
    https://school.programmers.co.kr/learn/courses/30/lessons/120822
 */

class Solution {
    public String solution(String my_string) {
        // // 처음 나의 풀이
        // StringBuilder buffer = new StringBuilder();
        // for (char ch : my_string.toCharArray()) {
        // buffer.insert(0, ch);
        // }

        // 다른 사람 풀이 참고
        // 공식 문서를 볼 때 조금 더 꼼꼼히 볼 것!
        StringBuilder buffer = new StringBuilder(my_string);
        buffer.reverse();

        return buffer.toString();

        // 빠른 실행 속도의 풀이
        // char[] revString = new char[my_string.length()];

        // int idx = my_string.length() - 1;
        // for (char ch : my_string.toCharArray()) {
        // revString[idx--] = ch;
        // }

        // return new String(revString);
    }
}