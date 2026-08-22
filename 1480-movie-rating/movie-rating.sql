(SELECT name as results
from MovieRating JOIN Users using(user_id)
group by name
order by count(*) desc, name
limit 1)

union all

(select title as results
from MovieRating join Movies using(movie_id)
where extract(YEAR_MONTH from created_at)=202002
group by title 
order by avg(rating) desc, title
limit 1)