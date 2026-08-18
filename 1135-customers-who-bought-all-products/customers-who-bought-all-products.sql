WITH t as (
SELECT customer_id , COUNT(DISTINCT product_key)As cnt
FROM Customer 
GROUP BY customer_id
)
SELECT customer_id
FROM t
WHERE cnt = (select COUNT(product_key)FROM Product)