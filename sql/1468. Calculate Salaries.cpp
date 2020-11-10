select company_id, employee_id, employee_name, round((case 
                                                        when max(salary) over (partition by company_id) < 1000 then 1
                                                        when max(salary) over (partition by company_id) <= 10000 then 0.76
                                                        else 0.51
                                                     end) * salary,0) as 'salary'
from Salaries






select company_id, employee_id, employee_name, case 
                                                    when max_salary < 1000 then salary 
                                                    when max_salary > 10000 then round(salary*0.51,0)
                                                    else round(salary*0.76,0)
                                               end as salary
from (
        select *, max(salary) over(partition by company_id) as max_salary
        from Salaries
     ) t