package Programmers.Level2;

import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.stream.Collectors;

public class 더_맵게 {
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
