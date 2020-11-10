select c2.name as country 
from Calls c1
join Person p on id = caller_id or id = callee_id
join Country c2 on country_code = left(phone_number, 3)
group by c2.name 
having avg(duration) > (select avg(duration) from Calls)