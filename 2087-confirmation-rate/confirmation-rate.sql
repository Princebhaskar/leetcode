SELECT s.user_id,
ROUND(IFNULL(c.rate, 0), 2) AS confirmation_rate
FROM Signups s
LEFT JOIN (
SELECT user_id,
SUM(IF(action = 'confirmed', 1, 0)) / COUNT(*) AS rate
FROM Confirmations
GROUP BY user_id
) AS c
ON s.user_id = c.user_id;