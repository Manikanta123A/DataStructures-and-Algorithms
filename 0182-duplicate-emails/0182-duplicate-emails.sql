# Write your MySQL query statement below
select Distinct p.email as Email from Person p LEFT JOIN  Person s on p.email = s.email where p.id != s.id;