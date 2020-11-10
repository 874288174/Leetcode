select a.book_id, a.name
from books a 
left join orders b on a.book_id = b.book_id
where available_from < '2019-05-23'
group by a.book_id
having ifnull(sum(if(dispatch_date < '2018-06-23', 0, quantity)), 0) < 10
order by a.book_id