-- 연간 평가점수에 해당하는 평가 등급 및 성과금 조회하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/284528

WITH annual_grades AS (
    SELECT
        emp_no,
        CASE
            WHEN AVG(score) >= 96 THEN 'S'
            WHEN AVG(score) >= 90 THEN 'A'
            WHEN AVG(score) >= 80 THEN 'B'
            ELSE 'C'
        END AS grade,
        CASE
            WHEN AVG(score) >= 96 THEN 0.2
            WHEN AVG(score) >= 90 THEN 0.15
            WHEN AVG(score) >= 80 THEN 0.1
            ELSE 0
        END AS bonus_rate
    FROM hr_grade
    GROUP BY emp_no
)

SELECT
    employees.emp_no,
    employees.emp_name,
    grades.grade,
    grades.bonus_rate * employees.sal AS bonus
FROM annual_grades AS grades
JOIN hr_employees AS employees
    ON grades.emp_no = employees.emp_no
ORDER BY employees.emp_no;