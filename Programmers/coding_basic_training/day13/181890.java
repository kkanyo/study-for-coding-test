package Programmers.coding_basic_training.day13;

/*
    왼쪽 오른쪽
    https://school.programmers.co.kr/learn/courses/30/lessons/181890
*/

import java.util.Arrays;

class Q181890 {
    public String[] solution(String[] strList) {
        for (int i = 0; i < strList.length; i++) {
            String direction = strList[i];

            if ("l".equals(direction)) {
                return Arrays.copyOfRange(strList, 0, i);
            } else if ("r".equals(direction)) {
                return Arrays.copyOfRange(strList, i + 1, strList.length);
            }
        }

        return new String[0];
    }
}
