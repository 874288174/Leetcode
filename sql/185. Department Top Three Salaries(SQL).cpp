select d.Name Department, e1.Name Employee, e1.Salary
from Employee e1 
join Department d on e1.DepartmentId = d.Id
where 3 > (select count(distinct(e2.Salary)) 
           from Employee e2        
           where e2.Salary > e1.Salary 
                 and e1.DepartmentId = e2.DepartmentId);









select d.Name Department, e1.Name Employee, e1.Salary
from Employee e1 
join Department d on e1.DepartmentId = d.Id
join Employee e2 on e2.Salary >= e1.Salary and e1.DepartmentId = e2.DepartmentId
group by e1.Id
having count(distinct e2.Salary) <= 3