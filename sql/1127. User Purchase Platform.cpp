select t2.*, ifnull(sum(amount), 0) total_amount, ifnull(count(user_id), 0) total_users
from (
         select distinct spend_date, "desktop" as platform from Spending
         union
         select distinct spend_date, "mobile" as platform from Spending
         union
         select distinct spend_date, "both" as platform from Spending 
     ) t2
left join (
             select spend_date, sum(amount) amount, user_id, 
                    case when count(*) = 1 then platform else "both" end as platform
             from Spending 
             group by spend_date, user_id
          ) t1 on t1.spend_date = t2.spend_date and t1.platform = t2.platform
group by t2.spend_date, t2.platform