select a.visited_on, sum(b.amount) amount, round(sum(b.amount)/7, 2) average_amount
from (
         select distinct visited_on
         from Customer
         where visited_on >= (select min(visited_on) from Customer) + 6
     ) as a
join Customer b on datediff(a.visited_on , b.visited_on) between 0 and 6
group by a.visited_on




select distinct visited_on,sum_amount as amount, round(average_amount, 2) as average_amount 
from (
        select visited_on,
            sum(amount) over(order by visited_on rows 6 preceding) as sum_amount,
            avg(amount) over(order by visited_on rows 6 preceding) as average_amount
        from (
                select visited_on, sum(amount) as amount 
                from Customer
                group by visited_on
             ) t1
    ) t2 
where datediff(visited_on, (select min(visited_on) from Customer)) >= 6