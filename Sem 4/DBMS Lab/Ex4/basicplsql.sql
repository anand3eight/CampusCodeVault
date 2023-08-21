--PLSQL Basics
--1
DECLARE
	msg varchar2(20) := 'Hello, World!';
BEGIN
	dbms_output.put_line(msg);
END;

--2
DECLARE
	a integer := 10;
	b integer := 20;
	c integer;
BEGIN
	c := a + b;
	dbms_output.put_line('Output : ' || c);
END;

--3
CREATE PROCEDURE Hello
AS
BEGIN
	dbms_output.put_line('Hello, World!');
END;

EXEC Hello; 

--4
CREATE OR REPLACE PROCEDURE print(word IN varchar2)
AS
BEGIN
	dbms_output.put_line('Hello : ' || word);
END;

EXEC print('Kichaa');

--5
DECLARE
    a number;
	b number;
	c number;
PROCEDURE findmin(x IN number, y IN number, z OUT number)
IS
BEGIN
	IF x < y THEN
		z := x;
	ELSE
		z := y;
	END IF;
END;

BEGIN
	a := 2323;
	b := 3232;
	findmin(a, b, c);
	dbms_output.put_line('Min Value : ' || c);
END;

--6
CREATE OR REPLACE FUNCTION printfun(word IN varchar2)
RETURN varchar2
AS
BEGIN
	RETURN('Hello, ' || word);
END;

SELECT printfun('Kichaa') FROM DUAL;

DECLARE 
	msg varchar2(30);
BEGIN
	msg := 'Kichaa';
	dbms_output.put_line(printfun('Nithish'));
END;


