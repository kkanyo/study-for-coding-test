-- 특정 기간동안 대여 가능한 자동차들의 대여비용 구하기
-- https://school.programmers.co.kr/learn/courses/30/lessons/157339

SELECT
    info.car_id,
    info.car_type,
    info.daily_fee * 30 * (100 - discount.discount_rate) / 100 AS fee
FROM car_rental_company_car AS info
JOIN car_rental_company_discount_plan AS discount
    ON info.car_type = discount.car_type
        AND duration_type = '30일 이상'
WHERE info.car_type IN ('SUV', '세단')
    AND info.car_id NOT IN (
        SELECT car_id
        FROM car_rental_company_rental_history
        WHERE 
            start_date <= '2022-11-30' 
            AND end_date >= '2022-11-01'
        GROUP BY car_id
    )
HAVING fee >= 500000
    AND fee < 2000000
ORDER BY 
    fee DESC,
    car_type,
    car_id DESC

-- 디테일
SELECT
    car.car_id,
    car.car_type,
    FLOOR(
        car.daily_fee * 30 * (100 - discount.discount_rate) / 100
    ) AS fee
FROM car_rental_company_car AS car
JOIN car_rental_company_discount_plan AS discount
    ON car.car_type = discount.car_type
        AND discount.duration_type = '30일 이상'
WHERE car.car_type IN ('세단', 'SUV')
    AND NOT EXISTS (
        SELECT 1
        FROM car_rental_company_rental_history AS history
        WHERE history.car_id = car.car_id
            AND history.start_date <= '2022-11-30'
            AND history.end_date >= '2022-11-01'
      )
HAVING fee >= 500000
    AND fee < 2000000
ORDER BY
    fee DESC,
    car_type ASC,
    car_id DESC;