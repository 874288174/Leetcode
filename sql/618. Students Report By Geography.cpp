#聚合函数 遍历
select
    max(case when continent = 'America' then name else null end) America,
    min(case when continent = 'Asia' then name else null end) Asia,
    max(case when continent = 'Europe' then name else null end) Europe
from (
        select name, continent, 
            row_number()over(partition by continent order by name) cur_rank
        from student
     ) t 
group by cur_rank




select America, Asia, Europe
from (
        select row_number() over(order by name) id, name as America 
        from student
        where continent = 'America'
     ) a
left join (
            select row_number() over(order by name) id, name as Asia
            from student
            where continent = 'Asia'
          ) b on a.id = b.id
left join (
            select row_number() over(order by name) id, name as Europe
            from student
            where continent = 'Europe'
          ) c on a.id = c.id