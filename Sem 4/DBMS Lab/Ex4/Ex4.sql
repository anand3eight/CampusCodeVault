--EX4
--Question 1
CREATE TABLE Ord_mst
(
    Ord_no INT,
    Cust_cd VARCHAR2(10),
    Status VARCHAR2(10)
);

DESC Ord_mst;

CREATE TABLE Ord_dtl
(
    Ord_No INT,
    Prod_Cd VARCHAR2(10),
    Qty INT
);

DESC Ord_dtl;

INSERT INTO Ord_dtl VALUES(1, 'P1', 100);
INSERT INTO Ord_dtl VALUES(1, 'P2', 200);

SELECT * FROM Ord_dtl;

CREATE TABLE Prod_mst
(
    Prod_cd VARCHAR2(10),
    Prod_Name VARCHAR2(20),
    Qty_in_Stock INT,
    Booked_Qty INT
);

DESC Prod_mst;

INSERT INTO Prod_mst VALUES('P1', 'Floppies', 10000, 1000);
INSERT INTO Prod_mst VALUES('P2', 'Printers', 5000, 600);
INSERT INTO Prod_mst VALUES('P3', 'Modems', 3000, 200);

SELECT * FROM Prod_mst;

--Trigger 1
CREATE OR REPLACE TRIGGER Update_Qty
AFTER INSERT ON Ord_dtl
FOR EACH ROW WHEN (new.prod_cd is NOT NULL)
BEGIN
UPDATE Prod_mst P SET P.Booked_Qty = P.Booked_Qty + :new.Qty
WHERE :new.Prod_cd = P.Prod_cd;
END;

INSERT INTO Ord_dtl VALUES(2, 'P2', 600);
SELECT * FROM Ord_dtl;
SELECT * FROM Prod_mst;

--Trigger 2
CREATE OR REPLACE TRIGGER Update_Qty2
AFTER DELETE ON Ord_dtl
FOR EACH ROW
BEGIN
UPDATE Prod_mst P SET P.Booked_Qty = P.Booked_Qty - :old.Qty
WHERE :old.Prod_cd = P.Prod_cd;
END;

DELETE FROM Ord_dtl WHERE Ord_no = 2;
SELECT * FROM Ord_dtl;
SELECT * FROM Prod_mst;

--Question 2
--Functions and Procedures

--a
CREATE TABLE Stud_Marks
(
    Srno int constraint pk_StudMarks primary key, 
    Sname varchar2(20),
    Total_Marks int, 
    Grade varchar(2)
);

DESC Stud_Marks;
INSERT INTO Stud_Marks(Srno, Sname, Total_marks) VALUES (1, 'XYZ', 95);
INSERT INTO Stud_Marks(Srno, Sname, Total_marks) VALUES (2, 'PQR', 85);
INSERT INTO Stud_Marks(Srno, Sname, Total_marks) VALUES (3, 'ABC', 75);
INSERT INTO Stud_Marks(Srno, Sname, Total_marks) VALUES (4, 'DEF', 65);
INSERT INTO Stud_Marks(Srno, Sname, Total_marks) VALUES (5, 'GHI', 5);
SELECT * FROM Stud_Marks;

--b
CREATE OR REPLACE PROCEDURE Grade(rno IN int, gr OUT varchar2)
AS
    mark int;
BEGIN
	SELECT Total_marks INTO mark FROM Stud_Marks WHERE Srno = rno;
	IF mark > 90 THEN
		gr := 'A';
	ELSIF mark > 80 THEN
		gr := 'B';
	ELSIF mark > 70 THEN
		gr := 'C';
	ELSIF mark > 60 THEN
		gr := 'D';
	ELSE
		gr := 'F';
	END IF;
END;

DECLARE
    rno int;
	gr varchar(20);
BEGIN
	FOR rno IN 1 .. 5 LOOP
		grade(rno, gr);
		UPDATE Stud_Marks SET Grade = gr WHERE Srno = rno;
	END LOOP;
END;

SELECT * FROM Stud_Marks;

--c
CREATE OR REPLACE FUNCTION Result(gr IN varchar)
RETURN varchar
AS
res varchar2(100);
BEGIN
	IF gr = 'A' THEN
		res := 'Your Grade is Outstanding';
	
	ELSIF gr = 'B' THEN
		res := 'Your Grade is Excellent';
	ELSIF gr = 'C' THEN
		res := 'Your Grade is Very Good';
	ELSIF gr = 'D' THEN
		res := 'Your Grade is Average';
	ELSIF gr = 'F' THEN
		res := 'Your Grade is Poor';
	ELSE
		res := 'No such Grade in the list';
	END IF;
	RETURN res;
END;

DECLARE
    rno int;
	gr varchar(20);
BEGIN
	FOR rno IN 1 .. 5 LOOP
		SELECT Grade INTO gr FROM Stud_Marks WHERE Srno = rno;
		dbms_output.put_line('Rno : ' || rno || ' Result : ' || Result(gr));
	END LOOP;
END;



