# Write your MySQL query statement below
select f.firstName,f.lastName,s.state,s.city from Person f Left JOIN Address s on f.personId = s.personId;