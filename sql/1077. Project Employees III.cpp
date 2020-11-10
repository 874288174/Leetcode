select a.project_id, a.employee_id 
from Project a
join Employee b on a.employee_id = b.employee_id
where (a.project_id, b.experience_years) in (
                                                select a.project_id, max(experience_years)
                                                from Project a
                                                join Employee b on a.employee_id = b.employee_id
                                                group by a.project_id
                                            )





SELECT project_id, employee_id
FROM (
        SELECT p.project_id, p.employee_id,
                RANK() OVER(PARTITION BY p.project_id ORDER BY e.experience_years DESC) as 'num'
        FROM Project p 
        JOIN Employee e ON p.employee_id = e.employee_id
    ) t
WHERE num = 1