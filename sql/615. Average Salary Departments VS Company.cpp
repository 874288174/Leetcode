select distinct pay_month, department_id,  case 
                                                when d_avg > c_avg then "higher"
                                                when d_avg = c_avg then "same"
                                                else "lower" 
                                            end as comparison
from (
        select date_format(pay_date, "%Y-%m") as pay_month, department_id, 
                avg(amount)over(partition by date_format(pay_date, "%Y-%m"), department_id) as d_avg,
                avg(amount)over(partition by date_format(pay_date, "%Y-%m")) as c_avg
        from salary 
        join employee on salary.employee_id = employee.employee_id
    ) t




select date_format(pay_date, "%Y-%m") pay_month, department_id, case 
                                                    when abs(avg(amount) - avg_m) < 1e-3 then 'same'
                                                    when avg(amount) < avg_m then 'lower'
                                                    else 'higher'
                                                 end as comparison
from salary a
join employee b on a.employee_id = b.employee_id
join (
        select date_format(pay_date, "%Y-%m") pay_month, avg(amount) avg_m
        from salary
        group by date_format(pay_date, "%Y-%m")
    ) t on t.pay_month = date_format(pay_date, "%Y-%m") 
group by date_format(pay_date, "%Y-%m"), department_id