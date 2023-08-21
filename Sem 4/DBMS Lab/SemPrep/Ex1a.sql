--SEM Prep

--Ex1a
--DDL
CREATE TABLE Student
(
    rollno number(2),
    sname varchar(15),
    address varchar(15),
    cgpa number(5, 2)
);

DESC Student;

ALTER TABLE Student MODIFY rollno number(3);

ALTER TABLE Student ADD Department varchar(20); 
ALTER TABLE Student ADD CID varchar(20); 
ALTER TABLE Student ADD DOD date; 

ALTER TABLE Student DROP COLUMN address;

ALTER TABLE Student RENAME COLUMN DOD TO DOB;

--DML
INSERT INTO Student VALUES(1, 'A', 8.0, 'A', '12C2', '03-jan-01')
INSERT INTO Student VALUES(2, 'B', 8.0, 'A', '12C2', '03-jan-01')
INSERT INTO Student(RollNo, sname, cgpa, Department, DOB) VALUES(3, 'A', 8.0, '12C2', '03-jan-01')
INSERT INTO Student VALUES(6, 'A', 8.0, 'A', '12C2', '03-jan-01')
INSERT INTO Student VALUES(11, 'A', 8.0, 'A', '12C2', '03-jan-01')
INSERT INTO Student VALUES(12, 'AB', 8.0, 'A', '12C2', '03-jan-01')
    
SELECT * FROM Student;

UPDATE Student SET CGPA = 9.0 WHERE RollNo = 6;

ALTER TABLE Student ADD Address varchar(100);
UPDATE Student SET Address = 'New York' WHERE Rollno > 10;
SELECT SName, Address FROM Student WHERE Rollno > 10;

UPDATE Student SET Address = 'Chennai' WHERE Rollno = 1;
SELECT Rollno, Address FROM Student
WHERE Rollno != 5 and Address = 'Chennai';

UPDATE Student SET Sname = 'RAM' WHERE Rollno = 11;
UPDATE Student SET CGPA = 9.0 WHERE Rollno = 11;
SELECT * FROM Student
WHERE CGPA > 8.5 and (Sname = 'RAM' OR Sname = 'Ravi');

CREATE TABLE Student_Copy AS SELECT * FROM Student;
SELECT * FROM Student_Copy;

CREATE TABLE  Student_CGPA AS SELECT Rollno, CGPA FROM Student;
SELECT * FROM Student_CGPA;

CREATE TABLE Part_Time_Student AS SELECT * FROM Student WHERE 1 = 0;
SELECT * FROM Part_Time_Student;
DESC Part_Time_Student;

ALTER TABLE Student ADD Part_Time int;
UPDATE Student SET Part_Time = 1 WHERE RollNo = 1 OR Rollno = 3;
INSERT INTO Part_Time_Student 
    SELECT Rollno, Sname, CGPA, Department, CID, DOB, Address FROM Student; 


--DDL Continued
ALTER TABLE student READ ONLY;
DELETE FROM Student WHERE Rollno = 1;

ALTER TABLE Student READ WRITE;
DELETE FROM Student WHERE Rollno = 1;

DELETE FROM Student;

DROP TABLE Student;



