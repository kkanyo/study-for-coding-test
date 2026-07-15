-- 강원도에 위치한 생산공장 목록 출력하기

SELECT factory_id,
    factory_name,
    address
FROM food_factory
WHERE SUBSTRING_INDEX(address, ' ', 1) = '강원도'
ORDER BY factory_id;