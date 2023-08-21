--CA2 Prep
--Basic Structure

DECLARE 
a int:= 10;
b int:= 30;
c int;
BEGIN
    c := a * b;
	dbms_output.put_line('Output : ' || c);
END;

--Procedure 1
CREATE OR REPLACE PROCEDURE mulproc1(x IN int, y IN int) AS
    BEGIN
		dbms_output.put_line('Output : ' || x*y);
	END;
EXEC mulproc1(10, 30);

--Procedure 2
DECLARE 
	a int;
	b int;
	c int;
PROCEDURE mulproc2(x IN int, y IN int, z OUT int) IS
	BEGIN
		z := x * y;
	END;
BEGIN
	a := 10;
	b := 30;
	mulproc2(a,b,c);
	dbms_output.put_line('Output : ' || c);
END;

--Function 1
CREATE OR REPLACE FUNCTION mulfun1(x IN int, y IN int) 
RETURN int
AS 
    BEGIN
		RETURN x * y;
	END;

SELECT mulfun1(10, 30) as Output FROM DUAL;
--DUAL -> Dummy Table

--Function 2
DECLARE 
	a int;
	b int;
	c int;
FUNCTION mulfun2(x IN int, y IN int)
RETURN int
IS 
	BEGIN
		RETURN x * y;
	END;

BEGIN 
	a := 10;
	b := 30;
	c := mulfun2(a,b);
	dbms_output.put_line('Output : ' || c);
END;

--Control Statements
CREATE OR REPLACE FUNCTION chkfun(x IN int)
RETURN varchar
AS
	BEGIN
		if(x = 0) THEN
			RETURN 'Zero';
		elsif(x = 1) THEN
			RETURN 'One';
		else
			RETURN 'None';
	END IF;
	END;

SELECT chkfun(1) AS Output FROM Dual;

--Loop1
CREATE OR REPLACE PROCEDURE loopfun1(x IN int, y IN varchar) AS
i int := 1;
    BEGIN
		while(i <= x) LOOP
			dbms_output.put_line(i || ' ' || y);
			i := i + 1;
		END LOOP;
	END;

EXEC loopfun1(5, 'ABC');

--Loop2
CREATE OR REPLACE PROCEDURE loopfun2(x IN int, y IN varchar) AS
i int;
    BEGIN
		 FOR i IN 1 .. x LOOP
			dbms_output.put_line(i || ' ' || y);
		END LOOP;
	END;

EXEC loopfun2(5, 'ABC');

--Loop3
CREATE OR REPLACE PROCEDURE loopfun3(x IN int, y IN varchar) AS
i int;
    BEGIN
		FOR i IN REVERSE 1 .. x LOOP
			dbms_output.put_line(i || ' ' || y);
		END LOOP;
	END;

EXEC loopfun3(6, 'ABC');

--Triggers
CREATE TABLE t1
(
    name varchar(20),
    val int
);

CREATE TABLE t2
(
    name varchar(20),
    sum int
);

DESC t1;
DESC t2;

--Trigger1
CREATE OR REPLACE TRIGGER insTrig
AFTER INSERT
ON t1
FOR EACH ROW
WHEN(new.name IS NOT null)
BEGIN
	UPDATE t2 SET sum = sum + :new.val 
	WHERE t2.name = :new.name;
END;

INSERT INTO t2 VALUES('A', 10);
SELECT * FROM t2;

INSERT INTO t1 VALUES('A', 10);
SELECT * FROM t1;
SELECT * FROM t2;

--Trigger2

CREATE OR REPLACE TRIGGER updTrig
AFTER UPDATE
ON t1
FOR EACH ROW
BEGIN
	UPDATE t2 SET t2.sum = t2.sum - :old.val + :new.val 
	WHERE t2.name = :old.name;
END;

UPDATE t1 SET val = 0 WHERE name = 'A';

SELECT * FROM t1;
SELECT * from t2;

--Trigger3

CREATE OR REPLACE TRIGGER delTrig
AFTER DELETE
ON t1
FOR EACH ROW
BEGIN
	UPDATE t2 SET t2.sum = t2.sum - :old.val
	WHERE t2.name = :old.name;
END;

DELETE FROM t1 WHERE name = 'A';

SELECT * FROM t1;
SELECT * from t2;