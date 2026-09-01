package Programmers.algorithm_high_score_kit.stack_queue;

/*
    기능개발
    https://school.programmers.co.kr/learn/courses/30/lessons/42586
 */

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

class _42586 {
    public List<Integer> solution(int[] progresses, int[] speeds) {
        Queue<Integer> deployQueue = new ArrayDeque<>();
        for (int i = 0; i < progresses.length; i++) {
            int deployDate = (100 - progresses[i]) / speeds[i];
            deployDate = (100 - progresses[i]) % speeds[i] > 0 ? deployDate + 1 : deployDate;

            deployQueue.add(deployDate);
        }

        List<Integer> answer = new ArrayList<>();
        int nextDeployDate = 0;
        int deployCount = 0;
        while (deployQueue.size() > 0) {
            int deployDate = deployQueue.remove();

            // 배포일이 없으면 결정
            if (nextDeployDate < 1) {
                nextDeployDate = deployDate;
                deployCount++;
                continue;
            }

            // 배포일보다 빠르면 대기
            if (nextDeployDate >= deployDate) {
                deployCount++;
                continue;
            }

            // 배포일보다 늦으면 배포 후 결정
            if (nextDeployDate < deployDate) {
                answer.add(deployCount);
                nextDeployDate = deployDate;
                deployCount = 1;
            }
        }
        answer.add(deployCount);

        return answer;
    }
}
