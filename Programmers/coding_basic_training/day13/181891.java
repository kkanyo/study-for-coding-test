package Programmers.coding_basic_training.day13;

/*
    순서 바꾸기
    https://school.programmers.co.kr/learn/courses/30/lessons/181891
*/

import java.util.stream.IntStream;

class Q181891 {
    public int[] solution(int[] num_list, int n) {
        int length = num_list.length;
        int[] answer = new int[length];

        System.arraycopy(num_list, n, answer, 0, length - n);
        System.arraycopy(num_list, 0, answer, length - n, n);

        return answer;
    }

    public int[] solutionFor(int[] num_list, int n) {
        int length = num_list.length;
        int[] answer = new int[length];

        for (int i = 0; i < length; i++) {
            answer[i] = num_list[i < length - n ? i + n : i - length + n];
        }

        return answer;
    }

    public int[] solutionStream(int[] num_list, int n) {
        int length = num_list.length;

        return IntStream.range(0, length)
                .mapToObj(i -> num_list[i < length - n ? i + n : i - length + n])
                .mapToInt(Integer::intValue)
                .toArray();
    }
}
