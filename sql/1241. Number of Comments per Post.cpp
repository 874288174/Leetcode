select a.sub_id post_id, count(distinct b.sub_id) number_of_comments
from (
        select distinct sub_id
        from Submissions
        where parent_id is null
     ) a
left join Submissions b on a.sub_id = b.parent_id
group by a.sub_id