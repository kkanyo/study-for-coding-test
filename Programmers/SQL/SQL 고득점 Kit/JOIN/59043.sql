-- 있었는데요 없었습니다
-- https://school.programmers.co.kr/learn/courses/30/lessons/59043

SELECT
    ins.animal_id,
    ins.name
FROM animal_ins AS ins
JOIN animal_outs AS outs
    ON ins.animal_id = outs.animal_id
        AND outs.datetime < ins.datetime
ORDER BY ins.datetime;