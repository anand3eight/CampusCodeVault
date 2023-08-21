CREATE TABLE Departments
(
  department_id int primary key,
  department_name varchar(20),
  location_id int
);

desc Departments;

CREATE TABLE Employees
(
  emp_id int primary key,
  first_name varchar(20),
  last_name varchar(20),
  email varchar(20),
  phone_number number(10),
  hire_date date,
  job_id int,
  salary number(10,2),
  manager_id int,
  emp_dept_id int,
  foreign key (emp_dept_id) 
  references Departments(department_id) 
  on delete set NULL
);

desc Employees;

INSERT INTO Departments Values(1, 'App Development', 1700);
INSERT INTO Departments Values(2, 'WebSocket', 202);
INSERT INTO Departments Values(3, 'ML', 1450);

SELECT * FROM Departments;

INSERT INTO Employees Values(1, 'Abey', 'Joan', 'abey@gmail.com', 1234567890, '01-JAN-20', 122, 20000.00, 2, 1);
INSERT INTO Employees Values(2, 'Beak', 'Joey', 'beaky@hotmail.com', 1234567898, '01-JAN-19', 121, 30000.00, 3, 1);
INSERT INTO Employees Values(3, 'Candy', 'Doan', 'candy@gmail.com', 1234567897, '01-AUG-18', 120, 35000.00, 4, 2);
INSERT INTO Employees Values(4, 'Dhoni', 'Singh', 'dhoni@gmail.com', 1234567896, '01-JAN-18', 119, 40000.00, 5, 2);
INSERT INTO Employees Values(5, 'Eagle', 'Vik', 'Eagle@yahoo.com', 1234567895, '01-JAN-20', 123, 20000.00, 2, 3);
INSERT INTO Employees Values(6, 'Fienny', 'Joy', 'Fienny@gmail.com', 1234567891, '01-JAN-18', 118, 50000.00, null, 3);

SELECT * FROM Employees;

--1
SELECT first_name, last_name
FROM Employees 
WHERE Emp_Dept_ID = (SELECT Department_ID
                    FROM Departments 
                    WHERE Location_ID = 1700)
ORDER BY first_name;

--2
SELECT first_name, last_name
FROM Employees 
WHERE Emp_Dept_ID != (SELECT Department_ID
                    FROM Departments 
                    WHERE Location_ID = 1450)
ORDER BY first_name;

--3
SELECT first_name AS Name, phone_number, salary
FROM Employees
WHERE salary = (SELECT max(salary)
                FROM Employees)
ORDER BY first_name;

--4
SELECT first_name AS Name, phone_number, salary
FROM Employees
WHERE salary > (SELECT avg(salary)
                FROM Employees)
ORDER BY first_name;

--5
SELECT emp_dept_id, min(salary)
FROM Employees
GROUP BY emp_dept_id;
  
SELECT first_name AS Name, phone_number, salary
FROM Employees
WHERE salary > all(SELECT min(salary)
                FROM Employees
                GROUP BY emp_dept_id)
ORDER BY first_name;

--6
SELECT emp_dept_id, max(salary)
FROM Employees
GROUP BY emp_dept_id;

SELECT first_name AS Name, phone_number, salary
FROM Employees
WHERE salary >= any(SELECT max(salary)
                FROM Employees
                GROUP BY emp_dept_id)
ORDER BY first_name;

--Correlated Query

--1

UPDATE Employees SET salary = 10000 WHERE emp_dept_id = 1;

SELECT Department_ID, Department_Name
FROM Departments D
WHERE EXISTS(SELECT DISTINCT emp_dept_id
                  FROM Employees E
                  WHERE salary > 10000
                  AND D.Department_ID = E.emp_dept_ID);

--2
SELECT Department_ID, Department_Name
FROM Departments D
WHERE NOT EXISTS(SELECT DISTINCT emp_dept_id
                  FROM Employees E
                  WHERE salary > 10000
                  AND D.Department_ID = E.emp_dept_ID);



--3
UPDATE Departments 
  SET Department_Name = 'Research' 
  WHERE Department_ID = 2;


SELECT Emp_ID, First_Name 
FROM Employees E
WHERE EXISTS(SELECT Department_ID
            FROM Departments D
            WHERE Department_name = 'Research'
            AND D.Department_ID = E.emp_dept_ID);

