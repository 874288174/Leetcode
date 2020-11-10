select name, bonus
from Employee a
left join bonus b on a.empId = b.empId
where ifnull(bonus, 0) < 1000;