-- 언어별 개발자 분류하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/276036

-- skillcodes를 3번 조회한다는 단점이 존재
-- COALESCE를 사용하여 NULL 값을 0으로 변환
WITH
frontend_mask AS (
    SELECT
        COALESCE(SUM(code), 0) AS skill_mask
    FROM skillcodes
    WHERE category = 'Front End'
),
python_mask AS (
    SELECT
        COALESCE(MAX(code), 0) AS skill_mask
    FROM skillcodes
    WHERE name = 'Python'
),
csharp_mask AS (
    SELECT
        COALESCE(MAX(code), 0) AS skill_mask
    FROM skillcodes
    WHERE name = 'C#'
),
graded_developers AS (
    SELECT
        CASE
            WHEN (developer.skill_code & frontend_mask.skill_mask) != 0
             AND (developer.skill_code & python_mask.skill_mask) != 0
                THEN 'A'
            WHEN (developer.skill_code & csharp_mask.skill_mask) != 0
                THEN 'B'
            WHEN (developer.skill_code & frontend_mask.skill_mask) != 0
                THEN 'C'
        END AS grade,
        developer.id,
        developer.email
    FROM developers AS developer
    CROSS JOIN frontend_mask
    CROSS JOIN python_mask
    CROSS JOIN csharp_mask
)

SELECT
    grade,
    id,
    email
FROM graded_developers
WHERE grade IS NOT NULL
ORDER BY
    grade,
    id;

-- skillcodes를 한 번만 읽어 모든 마스크를 계산
-- BIT_OR을 사용하여 모든 마스크를 한 번에 계산
WITH skill_masks AS (
    SELECT
        COALESCE(
            BIT_OR(CASE WHEN category = 'Front End' THEN code ELSE 0 END),
            0
        ) AS frontend_mask,
        COALESCE(
            MAX(CASE WHEN name = 'Python' THEN code ELSE 0 END),
            0
        ) AS python_mask,
        COALESCE(
            MAX(CASE WHEN name = 'C#' THEN code ELSE 0 END),
            0
        ) AS csharp_mask
    FROM skillcodes
),
graded_developers AS (
    SELECT
        CASE
            WHEN (developer.skill_code & skill_masks.frontend_mask) != 0
             AND (developer.skill_code & skill_masks.python_mask) != 0
                THEN 'A'
            WHEN (developer.skill_code & skill_masks.csharp_mask) != 0
                THEN 'B'
            WHEN (developer.skill_code & skill_masks.frontend_mask) != 0
                THEN 'C'
        END AS grade,
        developer.id,
        developer.email
    FROM developers AS developer
    CROSS JOIN skill_masks
)

SELECT
    grade,
    id,
    email
FROM graded_developers
WHERE grade IS NOT NULL
ORDER BY
    grade,
    id;