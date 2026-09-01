package Programmers.coding_basic_training.day7;

/*
    콜라츠 수열 만들기
    https://school.programmers.co.kr/learn/courses/30/lessons/181919
 */

import java.util.*;
import java.util.stream.IntStream;

class _181919 {
    // 처음 나의 풀이
    public int[] solution(int n) {
        List<Integer> answer = new ArrayList<>();

        answer.add(n);
        while (n > 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }

            answer.add(n);
        }

        return answer.stream().mapToInt(Integer::intValue).toArray();
    }

    // 다른 사람 풀이 참고
    // java 9 이상에서 사용 가능한 IntStream.iterate() 메소드를 사용한 풀이
    // https://docs.oracle.com/javase/9/docs/api/java/util/stream/IntStream.html
    public int[] solution2(int n) {
        return IntStream.iterate(n, i -> i >= 1, i -> i == 1 ? 0 : i % 2 == 0 ? i / 2 : 3 * i + 1).toArray();
    }
}