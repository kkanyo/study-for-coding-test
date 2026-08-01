-- 조건에 맞는 사원 정보 조회하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/284527

WITH annual_scores AS (
    SELECT
        grade.emp_no,
        SUM(grade.score) AS score
    FROM hr_grade AS grade
    WHERE grade.year = 2022
    GROUP BY grade.emp_no
),
highest_score AS (
    SELECT
        MAX(score) AS score
    FROM annual_scores
)

SELECT
    annual_scores.score,
    annual_scores.emp_no,
    employee.emp_name,
    employee.position,
    employee.email
FROM annual_scores
JOIN highest_score
    ON highest_score.score = annual_scores.score
JOIN hr_employees AS employee
    ON employee.emp_no = annual_scores.emp_no;