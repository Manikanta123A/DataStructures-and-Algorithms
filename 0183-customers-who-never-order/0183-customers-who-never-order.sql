# Write your MySQL query statement below
select s.name as Customers from Orders o RIGHT JOIN Customers s on s.id = o.customerid where o.customerid is NULL ;