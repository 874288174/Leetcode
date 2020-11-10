select project_id
from project
group by project_id
having count(*) >= all(select count(*) over(partition by project_id) from project);