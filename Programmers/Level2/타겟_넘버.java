package Programmers.Level2;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class 타겟_넘버 {
    public int solution(int[] numbers, int target) {
        boolean[] visited = new boolean[numbers.length + 1];
        List<Integer>[] numberList = new ArrayList[numbers.length + 1];

        numberList[0].add(0);
        for (int i = 1; i < numbers.length; i++) {
            numberList[i].add(numbers[i]);
            numberList[i].add(numbers[i] * -1);
        }

        return 0;
    }

    public int dfs(int v, int target, List<Integer>[] graph, boolean[] visited) {
        Stack<Integer> stack = new Stack<>();
        int count = 0;
        int sum = 0;

        while (!stack.isEmpty()) {
            int nodeIndex = stack.pop();

            System.out.println(nodeIndex + " -> ");

            for (int linkedNode : graph[nodeIndex]) {
                if (!visited[nodeIndex]) {
                    stack.push(linkedNode);
                    visited[linkedNode] = true;
                }
            }
        }

        return count;
    }
}