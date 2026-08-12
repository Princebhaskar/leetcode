SELECT temp.name 
FROM(
SELECT id , name 
FROM Employee 
) AS temp
WHERE (
    SELECT COUNT(*)
    FROM Employee e
    WHERE e.managerId = temp.id
)>=5;