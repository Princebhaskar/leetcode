SELECT temp.name 
FROM(
SELECT id , name 
FROM Employee 
) AS temp
WHERE (
    SELECT COUNT(*)>=5
    FROM Employee e
    WHERE e.managerId = temp.id
);