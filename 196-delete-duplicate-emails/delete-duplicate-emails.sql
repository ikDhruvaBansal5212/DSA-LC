# Write your MySQL query statement below

DELETE FROM person
WHERE ID IN(select id from (select id,row_number() over(partition by email order by id) rn from person)X where rn>1)