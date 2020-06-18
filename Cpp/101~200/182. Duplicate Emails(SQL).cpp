# Write your MySQL query statement below
/*
select distinct a.Email
from Person a
Join Person b on a.Email = b.Email and a.Id <> b.Id;
*/

/*
select Email
from  (select Email, count(Email) as num
       from Person
       group by Email) a
where a.num > 1;
*/


select Email
from Person
group by Email
having count(Email) > 1;