package Programmers.coding_basic_training.day12_list;

/*
 * 2의 영역
 * https://school.programmers.co.kr/learn/courses/30/lessons/181894
*/

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class _181894 {
    public int[] solution(int[] arr) {
        final int target = 2;
        List<Integer> values = Arrays.stream(arr)
                .boxed()
                .collect(Collectors.toList());

        int firstTargetIndex = values.indexOf(target);
        if (firstTargetIndex == -1) {
            return new int[] { -1 };
        }

        int lastTargetIndex = values.lastIndexOf(target);

        return Arrays.copyOfRange(arr, firstTargetIndex, lastTargetIndex + 1);
    }

    // optimized solution
    // 2의 인덱스를 찾아서 배열을 한 번만 자르는 방식
    public int[] solutionOpㅅ(int[] arr) {
        int firstTargetIndex = -1;
        int lastTargetIndex = -1;

        for (int index = 0; index < arr.length; index++) {
            if (arr[index] == 2) {
                if (firstTargetIndex == -1) {
                    firstTargetIndex = index;
                }

                lastTargetIndex = index;
            }
        }

        if (firstTargetIndex == -1) {
            return new int[] { -1 };
        }

        return Arrays.copyOfRange(arr, firstTargetIndex, lastTargetIndex + 1);
    }
}