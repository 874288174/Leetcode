select t.* 
from stadium t
left join stadium p1 on t.id - 1 = p1.id
left join stadium p2 on t.id - 2 = p2.id
left join stadium n1 on t.id + 1 = n1.id
left join stadium n2 on t.id + 2 = n2.id
where  (t.people >= 100 and p1.people >= 100 and p2.people >= 100) 
    or (t.people >= 100 and n1.people >= 100 and n2.people >= 100)
    or (t.people >= 100 and n1.people >= 100 and p1.people >= 100)
order by id;




select s1.* 
from stadium as s1
join stadium as s2 on s2.people >= 100 
join stadium as s3 on s3.people >= 100 
where s1.people >= 100 
      and ((s1.id + 1 = s2.id and s1.id + 2 = s3.id)
        or (s1.id - 1 = s2.id and s1.id + 1 = s3.id)
        or (s1.id - 2 = s2.id and s1.id - 1 = s3.id))    
group by s1.id
order by s1.id




with t1 as (
                select id, visit_date, people,
                       id-rank() over(order by id) rk
                from stadium
                where people >= 100
            )


select id, visit_date, people
from t1
where rk in (
                select rk 
                from t1 
                group by rk 
                having count(*) >= 3
            );
