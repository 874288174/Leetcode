#sum的用法： 可以访问同一行的两个不同列的值 ！！

select date_format(trans_date, "%Y-%m") month, country, count(*) trans_count, 
        sum(state = 'approved') approved_count, sum(amount) trans_total_amount, 
        sum(case when state = 'approved' then amount else 0 end) approved_total_amount
from Transactions
group by month, country