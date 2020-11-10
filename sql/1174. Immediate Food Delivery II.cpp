select round(sum(order_date = customer_pref_delivery_date) / count(distinct customer_id)*100, 2) immediate_percentage
from Delivery
where (customer_id, order_date) in (
                                        select customer_id, min(order_date)
                                        from Delivery
                                        group by customer_id
                                    )
