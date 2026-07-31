-- 입양 시각 구하기(2)
-- https://school.programmers.co.kr/learn/courses/30/lessons/59413

WITH RECURSIVE hour_numbers AS (
    SELECT 0 AS hour

    UNION ALL

    SELECT hour + 1
    FROM hour_numbers
    WHERE hour < 23
),
adoption_counts AS (
    SELECT
        HOUR(datetime) AS hour,
        COUNT(*) AS adoption_count
    FROM animal_outs
    GROUP BY HOUR(datetime)
)

SELECT
    hour_numbers.hour,
    COALESCE(adoption_counts.adoption_count, 0) AS `count`
FROM hour_numbers
LEFT JOIN adoption_counts
    ON hour_numbers.hour = adoption_counts.hour
ORDER BY hour_numbers.hour;