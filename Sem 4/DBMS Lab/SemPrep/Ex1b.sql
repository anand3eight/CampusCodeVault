--SEM Prep

--Ex1b

CREATE TABLE Student
(
    Rollno int UNIQUE NOT NULL,
    Sname varchar(20),
    Pno int UNIQUE,
    Dcode int,
    age int,
    Qualification varchar(20),
    CONSTRAINT chk_stud CHECK (AGE > 17 and AGE < 21)
);

ALTER TABLE Student MODIFY Qualification varchar(20) DEFAULT 'HSC';

INSERT INTO Student VALUES(1, 'A', 2, 1, 18, null);
INSERT INTO Student VALUES(2, 'B', 3, 2, 18, 'MS');
INSERT INTO Student VALUES(3, 'A', 4, 1, 18, 'Btech');


INSERT INTO Student VALUES(null, 'A', 2, 1, 18, null);
INSERT INTO Student VALUES(5, 'A', 2, 1, 18, null);
INSERT INTO Student VALUES(1, 'A', 2, 1, 28, null);

CREATE TABLE Stud_Marks
(
    Rollno int,
    Sem_no int,
    GPA number(5,2),
    CGPA number(5,2),
	CONSTRAINT fk_sm
    FOREIGN KEY(Rollno)
    REFERENCES Student(Rollno)
);

INSERT INTO Stud_Marks VALUES(1, 1, 9, 8);
DELETE FROM Student WHERE Rollno = 1;

CREATE TABLE Dept
(
 	DeptName varchar(20) NOT NULL,
    DeptCode int NOT NULL,
    HOD varchar(20) NOT NULL,
    Location varchar(20) NOT NULL
);

ALTER TABLE Dept ADD Constraint pk_Dept PRIMARY KEY(DeptCode);

INSERT INTO Dept VALUES('A', 1, 'B', 'C');
INSERT INTO Dept VALUES('AB', 2, 'B', 'C');

ALTER TABLE Student ADD Constraint fk_stud
FOREIGN KEY(Dcode)
REFERENCES Dept(DeptCode);

DELETE FROM Dept WHERE DeptCode = 1;
SELECT * FROM Student;

ALTER TABLE Student DROP Constraint fk_stud1;
ALTER TABLE Student ADD Constraint fk_stud1
FOREIGN KEY(Dcode)
REFERENCES Dept(Deptcode)
ON DELETE CASCADE;
DELETE FROM Dept WHERE DeptCode = 1;



ALTER TABLE Student DROP Constraint fk_stud1;
ALTER TABLE Student ADD Constraint fk_stud2
FOREIGN KEY(Dcode)
REFERENCES Dept(Deptcode)
ON DELETE SET NULL;

DELETE FROM Dept WHERE DeptCode = 2;
SELECT * FROM Student;

UPDATE Student SET Qualification = null;
ALTER TABLE Student MODIFY Qualification int DEFAULT null;

ALTER TABLE Student MODIFY Rollno int null;
