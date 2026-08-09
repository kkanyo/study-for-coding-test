-- 노선별 평균 역 사이 거리 조회하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/284531

SELECT
    route,
    CONCAT(ROUND(SUM(d_between_dist), 1), 'km') AS total_distance,
    CONCAT(ROUND(AVG(d_between_dist), 2), 'km') AS average_distance
FROM subway_distance
GROUP BY route
ORDER BY SUM(d_between_dist) DESC
