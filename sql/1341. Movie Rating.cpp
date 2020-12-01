
(
    select name results
    from Movie_Rating a
    join Users b on a.user_id = b.user_id
    group by a.user_id, name
    order by count(*) desc, name
    limit 0, 1
)
union 
(
    select title results
    from Movie_Rating a
    join Movies b on a.movie_id = b.movie_id
    where created_at like '2020-02%'
    group by a.movie_id, title
    order by avg(rating) desc, title
    limit 0, 1
)