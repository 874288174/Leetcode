SELECT
IFNULL(
    (SELECT DISTINCT Salary
     FROM Employee
     ORDER BY Salary DESC
     LIMIT 1 OFFSET 1), NULL) 
AS SecondHighestSalary

/*
SELECT  
    (SELECT DISTINCT Salary 
     FROM Employee
    ORDER BY Salary DESC
    LiMIT 1, 1) 
AS SecondHighestSalary
*/