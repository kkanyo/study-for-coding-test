package Programmers.Level1;

import java.util.PriorityQueue;

public class 모의고사 {
    public int[] solution(int[] answers) {
        final int[][] ANSWERS_STUDENT = {
                { 1, 2, 3, 4, 5 },
                { 2, 1, 2, 3, 2, 4, 2, 5 },
                { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 } };

        int[] scoresStudent = new int[ANSWERS_STUDENT.length];
        int[] indexStudents = new int[ANSWERS_STUDENT.length];

        int indexAnswers = 0;
        while (indexAnswers < answers.length) {
            for (int i = 0; i < ANSWERS_STUDENT.length; i++) {
                // 학생별 인덱스 확인
                int indexStudent = indexStudents[i] < ANSWERS_STUDENT[i].length ? indexStudents[i] : 0;

                if (answers[indexAnswers] == ANSWERS_STUDENT[i][indexStudent]) {
                    scoresStudent[i]++;
                }
                
                indexStudents[i] = indexStudent + 1;
            }

            indexAnswers++;
        }

        PriorityQueue<Integer> answer = new PriorityQueue<>();
        int maxScore = 0;
        for (int i = 0; i < ANSWERS_STUDENT.length; i++) {
            if (maxScore > scoresStudent[i]) {
                continue;
            }

            if (maxScore <= scoresStudent[i]) {
                // 최고 점수가 갱신된 경우
                if (!answer.isEmpty() && maxScore < scoresStudent[i]) {
                    answer.poll();
                }

                maxScore = scoresStudent[i];
                answer.add(i + 1);
            }
        }

        return answer.stream()
                .mapToInt(i -> i)
                .toArray();
    }
}
