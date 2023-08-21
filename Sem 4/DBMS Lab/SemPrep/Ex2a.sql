--Sem Prep
--Ex2a - JOINS

CREATE TABLE Employee
(
    Name varchar(20),
    Ssn int Constraint pk_emp PRIMARY KEY,
    Addr varchar(100),
    Sex varchar(1),
    salary int,
    super_ssn int,
    dno int
);

CREATE TABLE Dept
(
    dname varchar(20),
    Dno int Constraint pk_dep PRIMARY KEY,
    mgr_ssn int,
    msd date
);

CREATE TABLE Prj
(
    Pname varchar(20),
    Pno int Constraint pk_prj PRIMARY KEY,
    Ploc varchar(20),
    Dnum int
);

CREATE TABLE WorksOn
(
    ssn int,
    pno int,
    hours number(5,2),
    constraint fk1_wo FOREIGN KEY(ssn) REFERENCES Employee(ssn),
    constraint fk2_wo FOREIGN KEY(pno) REFERENCES Prj(pno),
    constraint pk_wo PRIMARY KEY(ssn, pno)
);

CREATE TABLE Dependent
(
    essn int,
    name varchar(20),
    sex varchar(1),
    relationship varchar(10),
    constraint fk_depe FOREIGN KEY(essn) REFERENCES Employee(ssn),
    constraint pk_depe PRIMARY KEY(essn, name)
);

CREATE TABLE DepLoc
(
    dno int ,
    loc varchar(20),
    constraint fk_dl foreign key(dno) references dept(dno),
    constraint pk_dl primary key(dno, loc)
);


ALTER TABLE employee ADD Constraint fk1_emp FOREIGN KEY(dno) REFERENCES Dept(dno);
ALTER TABLE Prj ADD Constraint fk1_prj FOREIGN KEY(dnum) REFERENCES Dept(dno);

INSERT INTO Dept VALUES('Research', 5, 123, '01-jan-01');
INSERT INTO Employee VALUES('John B Smith', 123, '123, Houston', 'M', 30000, 123, 5);
INSERT INTO Prj VALUES('X', 1, 'Stafford', 5);
INSERT INTO WorksOn VALUES(123, 1, 10.0);
INSERT INTO Dependent VALUES(123, 'A', 'M', 'Son');
INSERT INTO DepLoc VALUES(5, 'ABC');
INSERT INTO DepLoc VALUES(4, 'DEF');

SELECT E.ssn, E.addr, D.dname, P.pname
FROM Employee E, Dept D, Prj P
    WHERE
    E.name = 'John B Smith'
    AND
    E.dno = D.dno
	AND 
    D.dno = P.dnum;

SELECT E.name, E.addr
FROM Employee E
INNER JOIN Dept D
ON D.dname = 'Research'
AND D.mgr_ssn = E.ssn;


SELECT P.pno, P.Dnum, E.Name, E.addr 
FROM Employee E
INNER JOIN
Dept D
ON D.mgr_ssn = E.ssn
INNER JOIN 
Prj P
ON P.dnum = D.dno AND P.Ploc = 'Stafford';

SELECT E.ssn, D.Dname 
FROM Employee E
INNER JOIN
Dept D
ON E.dno = D.dno;

SELECT P.Pno
FROM Prj P
INNER JOIN 
Dept D
ON P.dnum = D.dno
INNER JOIN 
Employee E
ON D.dno = E.dno
AND E.name LIKE '%Smith%'
UNION ALL
SELECT P.Pno
FROM Prj P
INNER JOIN 
Dept D
ON P.dnum = D.dno
INNER JOIN 
Employee E
ON D.mgr_ssn = E.ssn
AND E.name LIKE '%Smith%'

INSERT INTO Employee VALUES('Franklin T Wang', 456, '450, Stone, Houston, TX', 'M', 20000, null, 4);
INSERT INTO Dept VALUES('Admin', 4, 456, '02-jan-88');
INSERT INTO Prj VALUES('Y', 2, 'Sug', 4);

SELECT Name
FROM Employee
WHERE super_ssn IS null;

SELECT max(salary) AS max, min(salary) AS min, avg(salary)
FROM Employee;

SELECT max(salary) AS max, min(salary) AS min, avg(salary)
FROM Employee E
INNER JOIN
Dept D
    ON E.dno = D.dno
	AND D.dname = 'Research';

SELECT count(*) AS CT
FROM Employee;

SELECT count(*) AS CT
FROM Employee E
INNER JOIN 
Dept D
ON E.dno = D.dno
AND D.dname = 'Research';

SELECT dno, count(dno), avg(salary)
FROM Employee 
GROUP BY dno;

SELECT P.pname, count(W.ssn) AS CT
FROM Prj P
INNER JOIN WorksOn W
ON P.pno = W.pno
GROUP BY P.Pname;

SELECT P.pno, P.pname, count(W.ssn) AS CT
FROM Prj P
INNER JOIN WorksOn W
ON P.pno = W.pno
GROUP BY P.Pname, P.Pno
HAVING count(W.ssn) > 0;

SELECT * 
FROM Employee E
INNER JOIN Dept D
ON E.dno = D.dno 
AND D.dname = 'Admin'
AND E.addr LIKE '%Houston%';

SELECT E.ssn, E.name, E.salary + 1000 AS INC
FROM Employee E
INNER JOIN WorksOn W
ON E.ssn = W.ssn
INNER JOIN Prj P
ON W.pno = P.pno
AND P.pname = 'X';

SELECT E.ssn, E.name, D.dname, P.pname
FROM Employee E
INNER JOIN Dept D
ON E.dno = D.dno
INNER JOIN Prj P
ON P.dnum = D.dno
ORDER BY D.dname, E.name;

SELECT E.name, E.salary, d.dname
FROM Employee E
INNER JOIN Employee E1
ON E.ssn = E1.super_ssn
INNER JOIN Dept D
ON E.dno = D.dno;

SELECT E.name
FROM Employee E
LEFT OUTER JOIN Dependent D
ON E.ssn = D.essn;

SELECT D.loc 
FROM DepLoc D
INNER JOIN Employee E
ON D.dno = E.dno
AND E.name LIKE '%John%';

SELECT E.name, W.pno
FROM Employee E
LEFT OUTER JOIN WorksOn W
ON E.ssn = W.ssn
WHERE W.pno IS null;

SELECT P.Pno, P.Pname
FROM Prj P
WHERE Pno NOT IN (SELECT W.Pno 
    			  FROM WorksOn W);

SELECT * FROM WorksOn;






