-- 조건에 맞는 사용자와 총 거래금액 조회하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/164668

SELECT
    users.user_id,
    users.nickname,
    SUM(price) AS total_sales
FROM used_goods_board AS boards
JOIN used_goods_user AS users
    ON boards.writer_id = users.user_id
WHERE boards.status = 'DONE'
GROUP BY users.user_id
HAVING total_sales >= 700000
ORDER BY total_sales;