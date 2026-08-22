CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    select MAX(salary) as getNthHighestSalary
    from (select salary,DENSE_RANK() over (order by salary desc) as rn from employee)as temp
    where rn=N

  );
END