-- 서울에 위치한 식당 목록 출력하기

SELECT ri.rest_id,
    ri.rest_name,
    ri.food_type,
    ri.favorites,
    ri.address,
    rr.score
FROM rest_info AS ri
JOIN (
    SELECT rest_id, 
        ROUND(AVG(review_score), 2) AS score
    FROM rest_review
    GROUP BY rest_id
) AS rr
    ON ri.rest_id = rr.rest_id
WHERE SUBSTRING_INDEX(ri.address, ' ' , 1) LIKE '서울%'
ORDER BY rr.score DESC,
    ri.favorites DESC;