--SemPrep
--Ex3

CREATE TABLE Student
(
    Rno int,
    Name varchar(20),
    age int,
    addr varchar(100),
    ph number(10),
    semfee number(8,2),
    hostelfee number(8,2),
    messfee number(8,2),
    semno int,
    cgpa number(5,2),
    cno int,
    totabs int,
    totpre int,
    pct number(5,2)
);

ALTER TABLE Student ADD Constraint pk_stud PRIMARY KEY(Rno);

CREATE OR REPLACE VIEW Tutor
AS SELECT Rno, Name, Semno, CGPA, cno, totabs, totpre, pct
	FROM Student;

CREATE OR REPLACE VIEW Parent
AS SELECT Rno, Name, Semfee, hostelfee, messfee
	FROM Student;

INSERT INTO Tutor VALUES(1, 'A', 1, 9.0, 1, 1, 9, 90.0);

SELECT * FROM Tutor;
SELECT * FROM Student;

UPDATE Student SET CGPA = 9.8 WHERE Rno = 1;

DROP VIEW Tutor;
DROP VIEW Parent;

CREATE SYNONYM s1 FOR Student;

SELECT * FROM s1;

CREATE SEQUENCE seq_rno
START WITH 1
INCREMENT BY 1
MINVALUE 1
MAXVALUE 35;

INSERT INTO Student VALUES(1, 'B', 19, 'A', 1234567890, 13, 12, 10, 1, 10, 9.7, 2, 8, 80.0);
INSERT INTO Student VALUES(seq_rno.nextval, 'C', 19, 'A', 1234567890, 13, 12, 10, 1, 10, 9.7, 2, 8, 80.0);
INSERT INTO Student VALUES(seq_rno.nextval, 'D', 19, 'A', 1234567890, 13, 12, 10, 1, 10, 9.7, 2, 8, 80.0);

SELECT * FROM Student;

CREATE INDEX studRno ON Student(rno, name);

COMMIT;

INSERT INTO Student VALUES(seq_rno.nextval, 'E', 19, 'A', 1234567890, 13, 12, 10, 1, 10, 9.7, 2, 8, 80.0);
INSERT INTO Student VALUES(seq_rno.nextval, 'F', 19, 'A', 1234567890, 13, 12, 10, 1, 10, 9.7, 2, 8, 80.0);

EXEC SAVEPOINT s1;

UPDATE Student SET name = 'EFG' WHERE name = 'E';

EXEC SAVEPOINT s2;

DELETE FROM Student WHERE rno < 3;
SELECT * FROM Student;
ROLLBACK TO s2;
SELECT * FROM Student;

SELECT * FROM Student;
ROLLBACK TO s1;
SELECT * FROM Student;
ROLLBACK;

