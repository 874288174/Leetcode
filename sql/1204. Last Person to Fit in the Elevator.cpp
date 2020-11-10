select person_name
from (
        select person_name, turn, sum(weight) over(order by turn asc) as sum_w
        from Queue 
     ) as t
where sum_w <= 1000
order by turn desc
limit 0, 1


select a.person_name
from Queue a
join Queue b on a.turn >= b.turn
group by a.person_id
having sum(b.weight) <= 1000
order by sum(b.weight) desc
limit 0, 1