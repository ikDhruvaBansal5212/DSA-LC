# Write your MySQL query statement below
select e.name as Customers from Customers e left join Orders d on e.id=d.customerID where d.customerID is NULL