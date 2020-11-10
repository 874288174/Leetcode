select student_id, course_id, grade
from (
        select *, row_number() over(partition by student_id order by grade desc, course_id) as n
        from Enrollments
    ) as a 
where n = 1;


select student_id, min(course_id) course_id, grade
from Enrollments
where (student_id, grade) in (
                                select student_id, max(grade)
                                from Enrollments
                                group by student_id
                            )
group by student_id, grade
order by student_id