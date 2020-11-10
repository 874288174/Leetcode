select Id, Company, Salary 
from (
    select Id, Company, Salary,
        row_number() over(partition by Company order by Salary) as rnk,
        count(*) over(partition by Company) as cnt 
    from Employee ) t 
where rnk in (cnt/2, cnt/2+1, cnt/2+0.5)