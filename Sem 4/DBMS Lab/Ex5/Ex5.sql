--Ex 5
--Employee Relation
CREATE TABLE Employee
(
    Eno int, 
    Ename varchar(20),
    designation varchar(20),
    salary int
);

DESC Employee;

--Inserting Records
INSERT INTO Employee VALUES(1, 'ABC', 'EL', 73000);
INSERT INTO Employee VALUES(2, 'DEF', 'IC', 80000);
INSERT INTO Employee VALUES(4, 'GHI', 'MNG', 100000);
INSERT INTO Employee VALUES(5, 'JKL', 'DIR', 120000);
INSERT INTO Employee VALUES(5, 'MNO', 'VP', 160000);

SELECT * FROM Employee;

DECLARE
max_el int := 75000;
max_ic int := 100000;
max_mng int := 125000;
max_dir int := 150000;
max_vp int := 175000;

inc_el int := 5000;
inc_ic int := 10000;
inc_mng int := 15000;
inc_dir int := 20000;
inc_vp int := 25000;

desg varchar(20);
emp_sal int;
salary_exceeded EXCEPTION;

BEGIN
for enum in 1 .. 5 LOOP
    BEGIN
    	dbms_output.put_line('At Eno : ' ||  enum);
        SELECT E.designation, E.salary INTO desg, emp_sal
        FROM Employee E 
        WHERE E.eno = enum;

        IF desg = 'EL' THEN
            IF emp_sal + inc_el >= max_el THEN
                raise salary_exceeded;
            ELSE 
                UPDATE Employee E
                SET E.salary = E.salary + inc_el
                WHERE E.eno = enum;
				dbms_output.put_line('Update Successful');
            END IF;
        END IF;

        IF desg = 'IC' THEN
            IF emp_sal + inc_ic >= max_ic THEN
                raise salary_exceeded;
            ELSE 
                UPDATE Employee E
                SET E.salary = E.salary + inc_ic
                WHERE E.eno = enum;
				dbms_output.put_line('Update Successful');
            END IF;
        END IF;

        IF desg = 'MNG' THEN
            IF emp_sal + inc_mng >= max_mng THEN
                raise salary_exceeded;
            ELSE 
                UPDATE Employee E
                SET E.salary = E.salary + inc_mng
                WHERE E.eno = enum;
				dbms_output.put_line('Update Successful');
            END IF;
        END IF;

        IF desg = 'DIR' THEN
            IF emp_sal + inc_dir >= max_dir THEN
                raise salary_exceeded;
            ELSE 
                UPDATE Employee E
                SET E.salary = E.salary + inc_dir
                WHERE E.eno = enum;
				dbms_output.put_line('Update Successful');
            END IF;
        END IF;

        IF desg = 'VP' THEN
            IF emp_sal + inc_vp >= max_vp THEN
                raise salary_exceeded;
            ELSE 
                UPDATE Employee E
                SET E.salary = E.salary + inc_vp
                WHERE E.eno = enum;	
				dbms_output.put_line('Update Successful');
            END IF;
        END IF;
    EXCEPTION
        WHEN salary_exceeded THEN
            dbms_output.put_line('Reached the maximum limit');
        WHEN no_data_found THEN
            dbms_output.put_line('Employee Not Found');
        WHEN too_many_rows THEN
            dbms_output.put_line('Same Eno for More than 1 Employee');
        WHEN others THEN
            dbms_output.put_line('An unexpected error occurred.');
    END;

  END LOOP;

END;
