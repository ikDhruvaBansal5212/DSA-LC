# Write your MySQL query statement below
Select  teacher_id ,count(Distinct subject_id) as cnt from teacher group by teacher_id
