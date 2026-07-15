-- 흉부외과 또는 일반외과 의사 목록 출력하기

SELECT dr_name,
    dr_id,
    mcdp_cd,
    hire_ymd
FROM doctor
WHERE mcdp_cd = 'CS'
    OR mcdp_cd = 'GS'
ORDER BY hire_ymd DESC,
    dr_name;