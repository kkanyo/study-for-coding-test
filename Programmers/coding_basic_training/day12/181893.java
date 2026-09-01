package Programmers.coding_basic_training.day12;

/*
 * 배열 조각하기
 * https://school.programmers.co.kr/learn/courses/30/lessons/181893
*/

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class _181893 {
    public int[] solution(int[] arr, int[] query) {
        List<Integer> arrList = Arrays.stream(arr)
                .boxed()
                .collect(Collectors.toList());

        for (int i = 0; i < query.length; i++) {
            if (i % 2 == 0) {
                arrList = arrList.subList(0, query[i] + 1);
            } else {
                arrList = arrList.subList(query[i], arrList.size());
            }
        }

        return arrList.stream()
                .mapToInt(Integer::intValue)
                .toArray();
    }

    // optimized solution
    // 필요한 인덱스를 찾아서 배열을 한 번만 자르는 방식
    public int[] solutionOpt(int[] arr, int[] query) {
        int startIndex = 0;
        int endIndex = arr.length - 1;

        for (int queryIndex = 0; queryIndex < query.length; queryIndex++) {
            int cutIndex = query[queryIndex];

            if (queryIndex % 2 == 0) {
                endIndex = startIndex + cutIndex;
            } else {
                startIndex += cutIndex;
            }
        }

        return Arrays.copyOfRange(arr, startIndex, endIndex + 1);
    }
}