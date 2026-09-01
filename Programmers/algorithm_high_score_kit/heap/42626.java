package Programmers.algorithm_high_score_kit.heap;

/*
    더 맵게
    https://school.programmers.co.kr/learn/courses/30/lessons/42626
 */

import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.stream.Collectors;

class _42626 {
    public int solution(int[] scoville, int K) {
        int answer = 0;

        PriorityQueue<Integer> scovilleQueue = Arrays.stream(scoville)
                .boxed()
                .collect(Collectors.toCollection(PriorityQueue::new));

        int lowestScoville = scovilleQueue.poll();
        while (lowestScoville < K && scovilleQueue.size() > 0) {
            int newScoville = lowestScoville + scovilleQueue.poll() * 2;
            scovilleQueue.add(newScoville);

            lowestScoville = scovilleQueue.poll();

            answer++;
        }

        return lowestScoville >= K ? answer : -1;
    }
}
