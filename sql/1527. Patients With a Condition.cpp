select *
from Patients
where conditions like '%DIAB1%'


select *
from Patients
where conditions regexp 'DIAB1'