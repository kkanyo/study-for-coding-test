package Programmers.algorithm_high_score_kit.sort;

/*
    가장 큰 수
    https://school.programmers.co.kr/learn/courses/30/lessons/42746
*/

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

class _42746 {
    public String solution(int[] numbers) {
        List<String> numberStringList = Arrays.stream(numbers)
                .mapToObj(String::valueOf)
                .toList();

        numberStringList = numberStringList.stream()
                .sorted(Comparator.reverseOrder())
                .toList();

        StringBuilder stringBuilder = new StringBuilder();
        numberStringList.forEach(s -> stringBuilder.append(s));

        return stringBuilder.toString();
    }
}
