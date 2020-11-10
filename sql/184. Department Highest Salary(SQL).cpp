select Department.Name as 'Department', Employee.Name Employee, Salary 
from Employee 
Join Department on Employee.DepartmentId = Department.Id
where
    (Employee.DepartmentId, Salary) IN
    (   
        SELECT DepartmentId, MAX(Salary)
        FROM Employee
        GROUP BY DepartmentId
	)