# Write your MySQL query statement below
select MAX(salary) as SecondHighestSalary from 
(select salary ,DENSE_RANK() over(order by salary desc) as rn from employee) as temp
where rn=2;

