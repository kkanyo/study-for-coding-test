package Programmers.coding_basic_training.day13;

/**
 * n개 간격의 원소들
 * https://school.programmers.co.kr/learn/courses/30/lessons/181888
 */
class Q181888 {
    public int[] solution(int[] numList, int n) {
        int length = numList.length / n;
        if (numList.length % n != 0) {
            length++;
        }

        int[] answer = new int[length];

        for (int i = 0; i < numList.length; i += n) {
            answer[i / n] = numList[i];
        }

        return answer;
    }
}
