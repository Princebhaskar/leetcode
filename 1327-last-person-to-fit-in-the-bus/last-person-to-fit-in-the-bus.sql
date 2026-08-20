with t as (
SELECT turn , person_id, person_name , weight,SUM(weight) OVER (ORDER BY turn) as tot_wt
FROM Queue q
order by q.turn ASC
)

SELECT person_name
from t
where t.tot_wt <= 1000
ORDER BY turn DESC
LIMIT 1
