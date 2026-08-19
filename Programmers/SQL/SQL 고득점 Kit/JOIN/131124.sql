-- 그룹별 조건에 맞는 식당 목록 출력하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/131124

WITH review_counts AS (
    SELECT
        member_id,
        COUNT(*) AS review_count
    FROM rest_review
    GROUP BY member_id
),
top_reviewers AS (
    SELECT
        member_id
    FROM review_counts
    WHERE review_count = (
        SELECT MAX(review_count)
        FROM review_counts
    )
)

SELECT
    member.member_name,
    review.review_text,
    review.review_date
FROM member_profile AS member
JOIN rest_review AS review
    ON member.member_id = review.member_id
JOIN top_reviewers
    ON review.member_id = top_reviewers.member_id
ORDER BY
    review.review_date,
    review.review_text;