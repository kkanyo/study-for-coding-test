-- 대장균들의 자식의 수 구하기

SELECT parent.id,
    IFNULL(child.child_count, 0) AS child_count
FROM ecoli_data AS parent
LEFT JOIN (
    SELECT parent_id,
        COUNT(*) AS child_count
    FROM ecoli_data
    GROUP BY parent_id
) AS child
    ON parent.id = child.parent_id
ORDER BY parent.id;
