package Programmers.Level2;

public class 올바른_괄호 {
    boolean solution(String s) {
        int bracketsCount = 0;
        for (char c : s.toCharArray()) {
            if (bracketsCount < 1 && c == ')') {
                return false;
            }

            if (c == '(') {
                bracketsCount++;
            } else {
                bracketsCount--;
            }
        }

        return bracketsCount == 0;
    }
}
