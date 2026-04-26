# Write your MySQL query statement below
select eu.unique_id,et.name 
from Employees as et
left join EmployeeUNI as eu
on et.id = eu.id
