# Write your MySQL query statement below
select name AS customers from customers 
where id not in (select c.id from customers c join orders o
on c.id=o.customerid)