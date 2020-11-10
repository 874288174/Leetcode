select Id, Month, sum(Salary) over (partition by Id order by Month rows 2 preceding)  as Salary
from Employee
where (Id, Month) not in (
                            select Id, max(Month) 
                            from Employee
                            group by Id
                         )
order by Id, Month desc