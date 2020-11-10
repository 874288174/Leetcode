select user_id, user_name, credit + IFNULL(sum(IF(paid_by=user_id, -amount, amount)), 0) credit,
                IF(credit +IFNULL(sum(IF(paid_by=user_id, -amount, amount)), 0) < 0, 'Yes', 'No') credit_limit_breached
from Users
left join Transactions b on user_id = paid_by or user_id = paid_to
group by user_id, user_name