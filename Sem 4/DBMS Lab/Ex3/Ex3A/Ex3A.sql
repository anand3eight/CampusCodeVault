--Ex3A
--1
CREATE TABLE Student
(
    Rno int,
    Name varchar(20),
    Age int,
    Address varchar(50),
    Phone_Number number(10,0),
    Semester_Fee number(8,2),
    Hostel_Fee number(8,2),
    Mess_Fee number(8,2),
    Semester_Number int,
    CGPA number(4,2),
    Course_Number int,
    Total_Absent int,
    Total_Present int,
    Percentage number(5,2)
);

DESC Student;

INSERT INTO Student VALUES(1, 'Krishna', 19, '1D3, Krishna Nagar', 9898989898, 10000.00, 15000.00, 8000.00, 4, 10.0, 121, 1, 9, 90.0);
INSERT INTO Student VALUES(2, 'Nithish', 19, '1D4, Nithish Nagar', 9898989897, 10000.00, null, null, 4, 9.0, 122, 2, 8, 80.0);
INSERT INTO Student VALUES(3, 'Tharun', 18, '1D5, Tharun Nagar', 9898989896, 15000.00, 12000.00, 7000.00, 2, 9.0, 123, 1, 9, 90.0);
INSERT INTO Student VALUES(4, 'Kishoar', 18, '1D6, Kishoar Nagar', 9898989895, 15000.00, null, null, 2, 10.0, 124, 2, 8, 80.0);
INSERT INTO Student VALUES(5, 'Vishal', 20, '1D7, Vishal Nagar', 9898989894, 9000.00, 15000.00, 8000.00, 6, 9.0, 125, 0, 10, 100.0);
INSERT INTO Student VALUES(6, 'Methy', 20, '1D8, Methy Nagar', 9898989893, 9000.00, null, null, 6, 9.0, 126, 1, 9, 90.0);

SELECT * FROM Student; 

--2
ALTER TABLE Student ADD CONSTRAINT pk_student primary key(Rno);

--3
CREATE VIEW Tutor 
    AS SELECT Rno, Name, Age, Phone_Number, 
    		Semester_Number, CGPA, Course_Number, Total_Absent, 
    		Total_Present, Percentage
    	FROM Student;   

SELECT * FROM Tutor;

CREATE VIEW Parent 
    AS SELECT Rno, Name, Age, Phone_Number, 
    		Semester_Fee, Hostel_Fee, Mess_Fee,	
    		Semester_Number, CGPA, Percentage
    	FROM Student;   

SELECT * FROM Parent;

--4
UPDATE Tutor SET Semester_Number = Semester_Number + 1;
SELECT * FROM Tutor;
SELECT * FROM Student;

--5
INSERT INTO Student VALUES(7, 'Vaishnav', 20, '1D9, Vaishnav Nagar', 9898989893, 9000.00, null, null, 7, 9.0, 127, 3, 7, 70.0);

SELECT * FROM Tutor;
SELECT * FROM Parent;
SELECT * FROM Student;

--6
DROP VIEW Tutor;
SELECT * FROM Tutor;
DROP VIEW Parent;
SELECT * FROM Parent;

--7
CREATE SYNONYM S1 FOR Student;

--8
SELECT * FROM S1;
SELECT * FROM Student;

--9
CREATE SEQUENCE Seq_Rno 
START WITH 1
INCREMENT BY 1
MINVALUE 1
MAXVALUE 35;

--10
CREATE SEQUENCE Seq_Rno_Student 
START WITH 8
INCREMENT BY 1
MINVALUE 8
MAXVALUE 35;

INSERT INTO Student VALUES(Seq_Rno_Student.nextval, 'Aswath', 21, '1D9, Aswath Nagar', 9898989892, 25000.00, 20000.00, 8000.00, 4, 9.0, 128, 2, 8, 80.0);
INSERT INTO Student VALUES(Seq_Rno_Student.nextval, 'Dakku', 21, '1D10, Dakku Nagar', 9898989891, 25000.00, null, null, 4, 9.0, 129, 1, 9, 90.0);
INSERT INTO Student VALUES(Seq_Rno_Student.nextval, 'Sarvesh', 20, '1D11, Sarvesh Nagar', 9898989890, 25000.00, 20000.00, 8000.00, 6, 10.0, 130, 3, 7, 70.0);

SELECT * FROM Student
ORDER BY Rno;

--11
CREATE INDEX Rno_Index ON Student(Rno, Name);

--12
COMMIT;

--13
INSERT INTO Student VALUES(11, 'Abhijith', 19, '1D12, Abhijith Nagar', 9898989889, 20000.00, 15000.00, 8000.00, 7, 10.0, 132, 1, 9, 90.0);
INSERT INTO Student VALUES(12, 'Sivasaran', 17, '1D13, Sivasaran Nagar', 9898989888, 10000.00, 15000.00, 8000.00, 3, 9.0, 133, 2, 8, 80.0);

--14
EXEC SAVEPOINT s1;

--15
UPDATE Student SET Name = 'Abijith' WHERE Rno = 11;

--16
EXEC SAVEPOINT s2;

--17
DELETE FROM Student WHERE Rno = 11 OR Rno = 12;
SELECT * FROM Student;

--18
ROLLBACK TO SAVEPOINT s2;
SELECT * FROM Student;

--19
ROLLBACK TO SAVEPOINT s1;
SELECT * FROM Student;

--20
ROLLBACK;
SELECT * FROM Student;


