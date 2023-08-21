--SemPrep

--Ex4

CREATE TABLE Ord_dtl
(
    Ord_no int,
    Prod_cd varchar(2),
    Qty int
);

CREATE TABLE Prod_mst
(
    Prod_cd varchar(2),
    Prod_name varchar(20),
    stock int,
    booked_qty int
);

INSERT INTO Prod_mst VALUES('P1', 'Floppies', 10000, 1000);

CREATE OR REPLACE TRIGGER Upd_Prod
AFTER INSERT ON Ord_dtl
FOR EACH ROW
WHEN (new.prod_cd is NOT null)

BEGIN 
	UPDATE Prod_mst SET Booked_qty = Booked_qty + :new.qty
	WHERE Prod_cd = :new.prod_cd;
END;

INSERT INTO Ord_dtl VALUES(1, 'P1', 100);
SELECT * FROM Prod_mst;


CREATE OR REPLACE TRIGGER Upd_Prod2
AFTER DELETE ON Ord_dtl
FOR EACH ROW

BEGIN 
	UPDATE Prod_mst SET Booked_qty = Booked_qty - :old.qty
	WHERE Prod_cd = :old.prod_cd;
END;

DELETE FROM Ord_dtl WHERE Prod_cd = 'P1';
SELECT * FROM Prod_mst;


CREATE TABLE Stud_Marks
(
    Srno int,
    Sname varchar(20),
    tot_marks int,
    gr varchar(2)
);

INSERT INTO Stud_Marks VALUEs(1, 'A', 80, null);
INSERT INTO Stud_Marks VALUEs(2, 'B', 90, null);
INSERT INTO Stud_Marks VALUEs(3, 'C', 30, null);

CREATE OR REPLACE PROCEDURE grade(rno IN int, gr OUT varchar)
AS 
    mark int;
BEGIN 
	SELECT tot_marks INTO mark 
	FROM Stud_Marks WHERE Srno = rno;

	IF mark >= 90 THEN 	
		gr := 'A';
	ELSIF mark >= 80 THEN 
		gr := 'B';
	ELSIF mark < 40 THEN
		gr := 'F';
	END IF;
END;

SELECT * FROM Stud_Marks;

DECLARE 
    grd varchar(10);
BEGIN
	FOR rno IN 1 .. 3 LOOP
		grade(rno, grd);
		UPDATE Stud_Marks SET gr = grd WHERE Srno = rno;
	END LOOP;
END;

CREATE OR REPLACE FUNCTION stmt(rno IN int)
RETURN varchar
AS
grd varchar(2);
res varchar(100);
BEGIN
	SELECT gr INTO grd 
	FROM Stud_Marks WHERE Srno = rno;

	IF grd = 'A' THEN
		res := 'Your Grade is Outstanding';

	ELSIF grd = 'B' THEN
		res := 'Your Grade is Excellent';

	ELSIF grd = 'F' THEN
		res := 'Your Grade is Poor';

	ELSE 
		res := 'No such grade in the list';

	END IF;
	RETURN res;
END;

BEGIN 
	FOR rno IN 1 .. 3 LOOP
		dbms_output.put_line(rno || ' : ' || stmt(rno));
	END LOOP;
END;

