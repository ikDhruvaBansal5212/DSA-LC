# Write your MySQL query statement below
select email from person Group by email having count(*)>1