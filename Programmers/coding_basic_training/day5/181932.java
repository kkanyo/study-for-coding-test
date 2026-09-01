package Programmers.coding_basic_training.day5;

/*
    코드 처리하기
    https://school.programmers.co.kr/learn/courses/30/lessons/181932
 */

class Solution {
    public String solution(String code) {
        int mode = 0;
        StringBuilder buffer = new StringBuilder();

        for (int i = 0; i < code.length(); i++) {
            char elem = code.charAt(i);

            if (elem == '1') {
                mode = mode == 0 ? 1 : 0;
                continue;
            }

            // 처음 나의 풀이이
            // if (mode == 0 && i % 2 == 0) {
            // buffer.append(elem);
            // continue;
            // }

            // if (mode == 1 && i % 2 == 1) {
            // buffer.append(elem);
            // continue;
            // }

            // 다른 사람 풀이 참고
            // 처음 풀이의 if문을 아래와 같이 더 간결하게 표현 가능능
            if (mode == i % 2) {
                buffer.append(elem);
            }
        }

        return buffer.length() > 0 ? buffer.toString() : "EMPTY";
    }
}