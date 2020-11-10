/*
delete p1 from Person p1, Person p2
where p1.Email = p2.Email and p1.Id > p2.Id
*/
    
delete from Person where Id not in (
    select id from (
        select min(Id) as id from Person
        group by Email
    ) as _      # it needs an alias for set
)