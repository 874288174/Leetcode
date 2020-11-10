select a.student_id, s.student_name
from (
        select student_id,
            rank() over (partition by exam_id order by score) r1,
            rank() over (partition by exam_id order by score desc) r2
        from Exam
    ) a
join Student s on a.student_id = s.student_id
group by a.student_id
having min(r1) > 1 and min(r2) > 1
order by a.student_id