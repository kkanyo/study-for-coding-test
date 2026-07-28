-- 대여 횟수가 많은 자동차들의 월별 대여 횟수 구하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/151139

WITH qualifying_cars AS (
    SELECT
        car_id
    FROM car_rental_company_rental_history
    WHERE start_date >= '2022-08-01'
      AND start_date < '2022-11-01'
    GROUP BY car_id
    HAVING COUNT(*) >= 5
)

SELECT
    MONTH(history.start_date) AS month,
    history.car_id,
    COUNT(*) AS records
FROM car_rental_company_rental_history AS history
JOIN qualifying_cars
    ON history.car_id = qualifying_cars.car_id
WHERE 
    history.start_date >= '2022-08-01'
    AND history.start_date < '2022-11-01'
GROUP BY
    month,
    history.car_id
ORDER BY
    month,
    history.car_id DESC;

-- 월별 집계 결과로 전체 기간 대여 횟수까지 계산
WITH monthly_records AS (
    SELECT
        MONTH(start_date) AS month,
        car_id,
        COUNT(*) AS records
    FROM car_rental_company_rental_history
    WHERE start_date >= '2022-08-01'
      AND start_date < '2022-11-01'
    GROUP BY
        month,
        car_id
),
records_with_total AS (
    SELECT
        month,
        car_id,
        records,
        SUM(records) OVER (PARTITION BY car_id) AS total_records
    FROM monthly_records
)

SELECT
    month,
    car_id,
    records
FROM records_with_total
WHERE total_records >= 5
ORDER BY
    month,
    car_id DESC;