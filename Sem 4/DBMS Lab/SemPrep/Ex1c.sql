--Sem Prep

--Ex1c
CREATE TABLE Student
(
    Rollno int CONSTRAINT pk_stud PRIMARY KEY,
    Sname varchar(20),
    Pno int,
    Dcode int,
    age int,
    cgpa number(5,2),
    CID int
);

INSERT INTO Student VALUES(1, 'A', 1, 1, 1, 1, 1);
INSERT INTO Student VALUES(2, 'Mohit Sharma', 1, 1, 1, 6.9, 1);
INSERT INTO Student VALUES(3, 'Mohit Sharmi', 1, 1, 1, 6.9, 1);

SELECT Rollno, Sname AS StudName 
FROM Student;

SELECT cgpa + 0.5 as CGPAchanged FROM Student
WHERE cgpa = 5.9 or cgpa = 6.9 or cgpa = 7.9 or cgpa = 8.9;

SELECT * FROM Student
WHERE Sname LIKE 'M_____%i' OR Sname LIKE 'V_____%i';

SELECT * FROM Student
WHERE Sname LIKE '_a%' OR Sname LIKE '%A%' OR Sname LIKE '%e%' OR Sname LIKE '%i%' OR Sname LIKE '%o%' OR Sname LIKE '%u%';

SELECT RollNo, Sname 
FROM Student
WHERE Sname NOT LIKE 'Z%' OR Sname NOT LIKE 'Q%';

UPDATE Student SET Pno = null WHERE Rollno > 1;
SELECT Sname FROM Student
WHERE Pno IS null
ORDER BY Sname;

UPDATE Student SET CID = null WHERE Rollno < 3;
SELECT RollNo, Sname FROM Student
WHERE CID IS NOT NULL

ALTER TABLE Student ADD PS int;
ALTER TABLE Student ADD PE int;
ALTER TABLE Student ADD FS int;

UPDATE Student SET PS = 1 WHERE Rollno = 1;
UPDATE Student SET FS = 1, PE = 1 WHERE Rollno = 2;
UPDATE Student SET PE = 1 WHERE Rollno = 1;

ALTER TABLE Student ADD Ph number(10);
UPDATE Student SET Ph = 1234567890 WHERE Rollno = 1;

CREATE TABLE PST AS 
    SELECT Rollno AS SID, Sname AS Name, Ph FROM Student 
    WHERE PS = 1;

CREATE TABLE PET AS 
    SELECT Rollno AS SID, Sname AS Name, Ph FROM Student 
    WHERE PE = 1;

CREATE TABLE FST AS 
    SELECT Rollno AS SID, Sname AS Name, Ph FROM Student 
    WHERE FS = 1;

SELECT max(CGPA) AS MAX_cgpa, min(CGPA) AS MIN_cgpa, avg(CGPA) as AVG_cgpa
FROM Student;

UPDATE Student SET age = 3 WHERE Rollno = 3;
SELECT count(*) AS Tot_Stud
FROM Student;

SELECT sum(count(*)) AS DC
FROM Student
GROUP BY age
HAVING count(age) = 1;

SELECT sum(age) FROM Student;

SELECT Dcode, count(*) AS Ct
FROM Student
GROUP BY Dcode;

SELECT Dcode, avg(cgpa) AS AVG
FROM Student
GROUP BY Dcode;

ALTER TABLE Student ADD Dname varchar(10);
UPDATE Student SET Dname = 'IT' WHERE Dcode = 1;

SELECT Dname, avg(CGPA) AS Avg
FROM Student
GROUP BY Dname
HAVING Dname = 'IT';

SELECT Dname, count(*) AS CT
FROM Student
GROUP BY Dname
HAVING count(*) > 2;

SELECT Name FROM FST
INTERSECT --ALL
SELECT Name FROM PET;

SELECT Name FROM PST
MINUS
SELECT Name FROM PET;

SELECT Name FROM PST
UNION
SELECT Name FROM PET;
``