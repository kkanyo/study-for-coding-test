package Programmers.coding_basic_training.day14;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.IntStream;

/*
    5명씩
    https://school.programmers.co.kr/learn/courses/30/lessons/181886
*/

public class J181886 {
    static final int MAXIMUM_CAPACITY = 5;

    public String[] solution(String[] names) {
        int length = names.length / MAXIMUM_CAPACITY;
        length += names.length % MAXIMUM_CAPACITY > 0 ? 1 : 0;

        String[] answer = new String[length];

        for (int i = 0; i < names.length; i += MAXIMUM_CAPACITY) {
            answer[i / MAXIMUM_CAPACITY] = names[i];
        }

        return answer;
    }

    public String[] solutionList(String[] names) {
        List<String> answer = new ArrayList<>();

        for (int i = 0; i < names.length; i += MAXIMUM_CAPACITY) {
            answer.add(names[i]);
        }

        return answer.toArray(String[]::new);
    }

    public String[] solutionStream(String[] names) {
        return IntStream.range(0, names.length)
                .filter(i -> i % MAXIMUM_CAPACITY == 0)
                .mapToObj(i -> names[i])
                .toArray(String[]::new);
    }
}
