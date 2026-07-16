-- 조건에 맞는 개발자 찾기

SELECT d.id,
    d.email,
    d.first_name,
    d.last_name
FROM developers AS d
WHERE EXISTS (
    SELECT 1
    FROM skillcodes AS s
    WHERE (d.skill_code & s.code) = s.code
        AND s.name IN ('Python', 'C#')
)
ORDER BY d.id;