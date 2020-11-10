select distinct title
from TVProgram a
join Content b on a.content_id = b.content_id and Kids_content = 'Y' and content_type = 'Movies'
where program_date like "2020-06%"
