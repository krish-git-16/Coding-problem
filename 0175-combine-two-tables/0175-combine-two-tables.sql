# Write your MySQL query statement below
select firstName,lastName,city,state from person p LEFT join address a on p.personid=a.personid;