-- Python 개발자 찾기

SELECT id,
    email,
    first_name,
    last_name
FROM developer_infos
WHERE 'Python' IN (skill_1, skill_2, skill_3)
ORDER BY id;