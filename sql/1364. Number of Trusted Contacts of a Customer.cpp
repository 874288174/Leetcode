select invoice_id, customer_name, price, count(c.contact_name) contacts_cnt, 
       ifnull(sum(c.contact_name in (select customer_name from Customers)), 0) as trusted_contacts_cnt
from Invoices a
join Customers b on a.user_id = customer_id
left join Contacts c on a.user_id = c.user_id
group by invoice_id, customer_name, price
order by invoice_id



