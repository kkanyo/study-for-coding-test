-- 입양 시각 구하기(1)
-- https://school.programmers.co.kr/learn/courses/30/lessons/59412

SELECT
    HOUR(datetime) AS hour,
    COUNT(*) AS `count`
FROM animal_outs
WHERE HOUR(datetime) BETWEEN 9 AND 19
GROUP BY hour
ORDER BY hour;