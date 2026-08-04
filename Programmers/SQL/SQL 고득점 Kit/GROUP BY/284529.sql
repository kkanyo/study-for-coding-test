-- 부서별 평균 연봉 조회하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/284529

SELECT
    department.dept_id,
    department.dept_name_en,
    ROUND(AVG(employees.sal)) AS avg_sal
FROM hr_employees AS employees
JOIN hr_department AS department
    ON employees.dept_id = department.dept_id
GROUP BY dept_id
ORDER BY avg_sal DESC;