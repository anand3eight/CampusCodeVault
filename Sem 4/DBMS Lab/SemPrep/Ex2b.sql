--Sem Prep

CREATE TABLE employees
(
    e_id int Constraint pk_emp PRIMARY KEY,
    fname varchar(20),
    lname varchar(20),
    email varchar(50),
    pno number(10),
    hire_date date,
    job_id int,
    salary number(10, 2),
	m_id int,
    d_id int
);

CREATE TABLE Depts
(
    dept_id int CONSTRAINT pk_dept PRIMARY KEY,
    dname varchar(20),
    loc_id int
);

ALTER TABLE employees ADD CONSTRAINT fk1_stud
FOREIGN KEY(m_id)
REFERENCES employees(e_id);

ALTER TABLE employees ADD CONSTRAINT fk2_stud
FOREIGN KEY(d_id)
REFERENCES Depts(dept_id);

INSERT INTO Depts VALUES(1700, 'A', 1700);
INSERT INTO Depts VALUES(1450, 'B', 1450);

INSERT INTO employees VALUES(1, 'A', 'A', 'a', 1234566890, '01-jan-01', 1, 13, 1, 1700);
INSERT INTO employees VALUES(2, 'B', 'A', 'a', 1234566890, '01-jan-01', 1, 13, 1, 1450);

SELECT fname, lname 
FROM employees
WHERE d_id IN (SELECT dept_id
    			FROM Depts
    			WHERE loc_id = 1700);

SELECT fname, lname 
FROM employees
WHERE d_id IN (SELECT dept_id
    			FROM Depts
    			WHERE loc_id != 1450);

SELECT fname, pno, salary
FROM employees
WHERE salary = (SELECT max(salary)
    			FROM employees);

UPDATE employees SET salary = 10 WHERE E_id > 1;

SELECT *
FROM employees
WHERE salary > (SELECT avg(salary)
    			FROM employees);

SELECT *
FROM employees
WHERE salary > ALL(SELECT min(salary)
    				FROM employees
    				GROUP BY d_id);

SELECT *
FROM employees
WHERE salary >= ANY(SELECT max(salary)
    				FROM employees
    				GROUP BY d_id);

UPDATE employees SET salary = salary + 10000 WHERE d_id = 1700;
--Correlated Query
SELECT *
FROM Depts D
WHERE EXISTS (SELECT DISTINCT d_id
    			FROM employees E
    			WHERE salary > 10000 
    			AND D.dept_id = E.d_id);

SELECT *
FROM Depts D
WHERE NOT EXISTS (SELECT DISTINCT d_id
    			FROM employees E
    			WHERE salary > 10000 
    			AND D.dept_id = E.d_id);

UPDATE Depts SET Dname = 'Research' WHERE dept_id = 1450;
SELECT * FROM Employees E
WHERE EXISTS (SELECT Dname
    			FROM Depts D
    			WHERE D.dept_id = E.d_id
    			AND D.dname = 'Research');

