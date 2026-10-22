-- FrontEnd 개발자 찾기
-- https://school.programmers.co.kr/learn/courses/30/lessons/276035

WITH frontend_skills AS (
    SELECT
        SUM(`code`) AS `code`
    FROM skillcodes
    WHERE category = 'Front End'
)

SELECT
    devs.id,
    devs.email,
    devs.first_name,
    devs.last_name
FROM developers AS devs
JOIN frontend_skills AS skills
WHERE devs.skill_code & skills.code > 0
ORDER BY devs.id