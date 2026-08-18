# Write your MySQL query statement below

select p.firstName,p.lastName,d.city,d.state from person p left join address d on p.personID=d.personID