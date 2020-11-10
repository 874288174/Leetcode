select name, ifnull(sum(distance), 0) travelled_distance
from Users a
left join Rides b on a.id = b.user_id
group by a.id
order by travelled_distance desc, name