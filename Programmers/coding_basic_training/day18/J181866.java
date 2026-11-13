package Programmers.coding_basic_training.day18;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

/**
 * 문자열 잘라서 정렬하기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181866
 */

public class J181866 {
    // StringTokenizer 사용
    public String[] solution(String myString) {
        List<String> answer = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(myString, "x");

        while (st.hasMoreTokens()) {
            answer.add(st.nextToken());
        }

        answer.sort(Comparator.naturalOrder());

        return answer.toArray(new String[0]);
    }

    // 정규식 사용
    public String[] solutionRegex(String myString) {
        return Arrays.stream(myString.split("x+"))
                .filter(word -> !word.isEmpty())
                .sorted()
                .toArray(String[]::new);
    }
}
