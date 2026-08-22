# Write your MySQL query statement below
select email from person as Email
group by email 
having count(*)>1;