package Programmers.coding_basic_training.day14;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.IntStream;

/*
    할 일 목록
    https://school.programmers.co.kr/learn/courses/30/lessons/181885
*/

public class J181885 {
    public String[] solution(String[] todoList, boolean[] finished) {
        List<String> answer = new ArrayList<>();

        for (int i = 0; i < todoList.length; i++) {
            if (!finished[i]) {
                answer.add(todoList[i]);
            }
        }

        return answer.toArray(String[]::new);
    }

    public String[] solutionStream(String[] todoList, boolean[] finished) {
        return IntStream.range(0, todoList.length)
                .filter(i -> !finished[i])
                .mapToObj(i -> todoList[i])
                .toArray(String[]::new);
    }
}
