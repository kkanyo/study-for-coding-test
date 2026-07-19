-- 연도별 대장균 크기의 편차 구하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/299310

WITH yearly_max AS (
    SELECT
        YEAR(differentiation_date) AS differentiation_year,
        MAX(size_of_colony) AS max_colony_size
    FROM ecoli_data
    GROUP BY YEAR(differentiation_date)
)

SELECT
    yearly_max.differentiation_year AS year,
    yearly_max.max_colony_size - ecoli.size_of_colony AS year_dev,
    ecoli.id
FROM ecoli_data AS ecoli
JOIN yearly_max
    ON YEAR(ecoli.differentiation_date) = yearly_max.differentiation_year
ORDER BY
    year,
    year_dev;

-- 윈도우 함수 이용
SELECT
    YEAR(differentiation_date) AS year,
    MAX(size_of_colony) OVER (
        PARTITION BY YEAR(differentiation_date)
    ) - size_of_colony AS year_dev,
    id
FROM ecoli_data
ORDER BY
    year,
    year_dev;