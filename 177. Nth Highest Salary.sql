CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  declare ofst INT;  
  set ofst=N-1;
  RETURN (
      select distinct(Salary) from Employee order by Salary desc limit 1 offset ofst
  );
END