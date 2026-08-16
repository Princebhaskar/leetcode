WITH t AS(
SELECT d.customer_id , MIN(d.order_date)AS x,MIN(d.customer_pref_delivery_date)AS y
FROM Delivery d
GROUP BY customer_id
) 
SELECT
ROUND((SUM(if(t.x = t.y ,1,0))*100.0) /(COUNT(t.customer_id)),2)
AS immediate_percentage
FROM t; 