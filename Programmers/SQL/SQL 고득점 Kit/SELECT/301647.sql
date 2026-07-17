-- 부모의 형질을 모두 가지는 대장균 찾기

SELECT child.id,
    child.genotype,
    parent.genotype
FROM ecoli_data AS child
JOIN ecoli_data AS parent
    ON child.parent_id = parent.id
WHERE child.genotype & parent.genotype = parent.genotype
ORDER BY child.id;