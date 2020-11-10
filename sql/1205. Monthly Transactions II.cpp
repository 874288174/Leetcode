select month, country,
        sum(case when tag=0 then 1 else 0 end) as approved_count,
        sum(case when tag=0 then amount else 0 end) as approved_amount,
        sum(case when tag=1 then 1 else 0 end) as chargeback_count,
        sum(case when tag=1 then amount else 0 end) as chargeback_amount
from (
        select date_format(trans_date,'%Y-%m') month, country, amount, 0 tag
        from Transactions
        where state = 'approved'

        union all

        select date_format(a.trans_date,'%Y-%m') month, country, amount, 1 tag 
        from Chargebacks a 
        left join Transactions b on a.trans_id = b.id 
     ) as t
 group by month, country