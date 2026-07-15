-- 3월에 태어난 여성 회원 목록 출력하기

SELECT member_id,
    member_name,
    gender,
    date_of_birth
FROM member_profile
WHERE tlno IS NOT NULL
    AND MONTH(date_of_birth) = 3
    AND gender = 'W'
ORDER BY member_id;