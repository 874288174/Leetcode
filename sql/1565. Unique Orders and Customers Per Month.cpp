select DATE_FORMAT(order_date, "%Y-%m") month, count(*) order_count, count(distinct customer_id) customer_count
from Orders
where invoice > 20
group by month
