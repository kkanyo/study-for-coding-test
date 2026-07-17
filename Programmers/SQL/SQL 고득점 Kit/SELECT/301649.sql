-- 대장균의 크기에 따라 분류하기 2
-- https://school.programmers.co.kr/learn/courses/30/lessons/301649

WITH ranked_ecoli AS (
    SELECT
        id,
        NTILE(4) OVER (ORDER BY size_of_colony DESC) AS size_rank
    FROM ecoli_data
)

SELECT
    id,
    CASE size_rank
        WHEN 1 THEN 'CRITICAL'
        WHEN 2 THEN 'HIGH'
        WHEN 3 THEN 'MEDIUM'
        ELSE 'LOW'
    END AS colony_name
FROM ranked_ecoli
ORDER BY id;