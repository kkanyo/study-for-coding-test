package Programmers.coding_beginner.day4;

/*
    피자 나눠 먹기 (1)
    https://school.programmers.co.kr/learn/courses/30/lessons/12081
*/

class _120814 {
    private static final int DEVISOR = 7;

    public int solution(int n) {
        // 처음 풀이
        // return n / DEVISOR + (n % DEVISOR > 0 ? 1 : 0);

        // 다른 사람 풀이 참고
        // 잉여값은 제수보다 작은 값임을 이용하여 아래와 같이 표현 가능
        return (n + DEVISOR - 1) / DEVISOR;
    }
}