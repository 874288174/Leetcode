select a.Name as 'Name'
from Employee a
join Employee b on b.ManagerId = a.Id
group by a.Id
having count(*) > 4