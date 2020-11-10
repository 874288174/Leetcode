select Request_at Day, Round(sum(Status like 'can%') / count(Client_Id)
                             , 2) as 'Cancellation Rate'
from Trips
where Request_at between '2013-10-01' and '2013-10-03'
      and Client_Id not in (
                                select Users_id
                                from Users
                                where Role = 'client' and Banned = 'Yes'
                           ) 
group by Request_at