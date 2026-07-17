-- 멸종위기의 대장균 찾기
-- https://school.programmers.co.kr/learn/courses/30/lessons/301651

-- 기존 풀이
WITH RECURSIVE generations AS (
    SELECT
        id,
        parent_id,
        1 AS generation
    FROM ecoli_data
    WHERE parent_id IS NULL

    UNION ALL

    SELECT
        child.id,
        child.parent_id,
        parent.generation + 1
    FROM generations AS parent
    JOIN ecoli_data AS child
        ON child.parent_id = parent.id
)

SELECT
    COUNT(*) AS count,
    leaf.generation AS generation
FROM generations AS leaf
WHERE NOT EXISTS (
    SELECT 1
    FROM generations AS child
    WHERE child.parent_id = leaf.id
)
GROUP BY leaf.generation
ORDER BY leaf.generation;

-- 최적화
WITH RECURSIVE generations AS (
    SELECT
        id,
        1 AS generation
    FROM ecoli_data
    WHERE parent_id IS NULL

    UNION ALL

    SELECT
        child.id,
        parent.generation + 1
    FROM generations AS parent
    JOIN ecoli_data AS child
        ON child.parent_id = parent.id
)

SELECT
    COUNT(*) AS count,
    parent.generation AS generation
FROM generations AS parent
LEFT JOIN ecoli_data AS child
    ON child.parent_id = parent.id
WHERE child.id IS NULL
GROUP BY parent.generation
ORDER BY parent.generation;