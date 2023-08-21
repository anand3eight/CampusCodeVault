--SemPrep

--Ex5

CREATE TABLE Employee
(
    Eno int,
    Ename varchar(20),
    desg varchar(20),
    salary number(8,2)
);

INSERT INTO Employee VALUES(1, 'A', 'EL', 74000);
INSERT INTO Employee VALUES(3, 'B', 'IC', 74000);
INSERT INTO Employee VALUES(3, 'C', 'EL', 74000);
INSERT INTO Employee VALUES(4, 'D', 'IC', 74000);

SELECT * FROM Employee;

--PL/SQL
DECLARE 
	inc_el int := 5000;
	inc_ic int := 10000;
	
	max_el int := 75000;
	max_ic int := 100000;

	des varchar(20);
	sal int;
	se EXCEPTION;
BEGIN 
	FOR enum IN 1 .. 4 LOOP
    BEGIN
		SELECT desg, salary INTO des, sal
		FROM Employee 
		WHERE eno = enum;

		IF des = 'EL' THEN
			IF sal + inc_el > max_el THEN
				raise se;
			ELSE 
				UPDATE Employee SET salary = salary + inc_el
                WHERE eno = enum;
			END IF;
		ELSIF des = 'IC' THEN 
			IF sal + inc_ic > max_ic THEN
				raise se;
			ELSE 
				UPDATE Employee SET salary = salary + inc_ic
                WHERE eno = enum;
			END IF;
		END IF;
		EXCEPTION 
				WHEN se THEN	
					dbms_output.put_line('Salary Limit Exceeded');
				WHEN too_many_rows THEN	
					dbms_output.put_line('More than 1 Employee');
				WHEN no_data_found THEN
					dbms_output.put_line('No Employee for Given Eno');
		END;
		END LOOP;
END;
		
	
	
	
	

