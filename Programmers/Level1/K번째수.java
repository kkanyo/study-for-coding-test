package Programmers.Level1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class K번째수 {
    public int[] solution(int[] array, int[][] commands) {
        List<Integer> answer = new ArrayList<>();
        List<Integer> arrayList = Arrays.stream(array)
                .boxed()
                .toList();

        for (int[] command : commands) {
            List<Integer> subList = new ArrayList<>(arrayList.subList(command[0] - 1, command[1]));
            subList.sort(null);

            answer.add(subList.get(command[2] - 1));
        }

        return answer.stream()
                .mapToInt(i -> i)
                .toArray();
    }
}
