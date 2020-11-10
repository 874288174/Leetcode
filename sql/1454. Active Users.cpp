with tbl as (
                SELECT id, login_date, dense_rank() over(partition by id order by login_date) as rnk
                FROM Logins
            )

select distinct a.id, a.name
from tbl
JOIN Accounts as a ON tbl.id = a.id
GROUP BY a.id, date_add(login_date, interval - rnk day)
HAVING count(distinct login_date) >= 5





select distinct L1.id, name
from Logins as L1 
JOIN Logins as L2 on L1.id = L2.id 
                    and Datediff(L1.login_date, L2.login_date) BETWEEN 0 and 4               
join Accounts on Accounts.id = L1.id
group by L1.id, L1.login_date
having count(distinct L2.login_date) = 5