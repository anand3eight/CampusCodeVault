REM   Script: Ex2A
REM   New

CREATE TABLE EMPLOYEE  
(  
    Fname varchar(20),  
    Minit varchar(20),  
    Lname varchar(20),  
    Ssn int primary key,  
    Bdate date,  
    Address varchar(100),  
    Sex varchar(1),  
    Salary int,  
    Super_ssn int,   
    Dno int  
);

desc employee 


CREATE TABLE DEPARTMENT  
(  
    Dname varchar(20),  
    Dnumber int primary key,  
    Mgr_Ssn int,  
    Mgr_start_date date,  
    foreign key(Mgr_Ssn) references EMPLOYEE(Ssn)  
);

CREATE TABLE DEPT_LOCATIONS   
(   
    Dnumber int,   
    Dlocation varchar(20),   
    primary key(Dnumber, Dlocation),  
    foreign key(Dnumber)    
    references DEPARTMENT(Dnumber)   
);

CREATE TABLE PROJECT  
(  
    Pname varchar(20),  
    Pnumber int primary key,  
    Plocation varchar(20),  
    Dnum int,  
    foreign key(Dnum)  
    references DEPARTMENT(Dnumber)  
);

CREATE TABLE WORKS_ON   
(   
    Essn int,   
    Pno int,   
    Hourss number(3,1),   
    foreign key(Essn)    
    references EMPLOYEE(Ssn),   
    foreign key(Pno)   
    references PROJECT(Pnumber),   
    primary key(Essn, Pno)   
);

CREATE TABLE DEPENDENT  
(  
    Essn int,  
    Dependent_name varchar(20),  
    Sex varchar(1),  
    Bdate date,  
    Relationship varchar(10),  
    foreign key(Essn)  
    references EMPLOYEE(Ssn),  
    primary key(Essn, Dependent_name)  
);

desc employee 


insert into employee values('John', 'B', 'Smith', 123456789, '09-JAN-65', '731, Fondren, Houston, TX', 'M', 30000, 333445555, 5);

insert into employee values('Franklin', 'T', 'Wong', 333445555, '08-DEC-65', '638 Voss, Houston, TX', 'M', 40000, 88886555, 5);

insert into employee values('Alicia', 'J', 'Zelaya', 999987777, '19-JAN-68', '3321, Castle, Spring, TX', 'F', 25000, 987654321, 4);

insert into employee values('Jennifer', 'S', 'Wallace', 987654321, '20-JUN-41', '291, Berry, Bellaire, TX', 'F', 43000, 88886555, 4);

insert into employee values('Ramesh', 'K', 'Narayan', 6666884444, '15-SEP-62', '975, Fire Oak, Humble, TX', 'M', 38000, 333445555, 5);

insert into department values('Research', 5, 333445555, '22-MAY-88');

insert into department values('Administration', 4, 987654321, '01-jan-95');

insert into employee values('James', 'E', 'Borg', 888665555, '10-nov-37', '450, Stone, Houston, TX', 'M', 65000, null, 1);

insert into department values('Headquarters', 1, 888665555, '19-jun-81');

insert into dept_locations values(1, 'Houston');

insert into dept_locations values(4, 'Stafford');

insert into dept_locations values(5, 'Bellaire');

insert into dept_locations values(5, 'Sugarland');

insert into dept_locations values(5, 'Houston');

insert into project values('ProductX', 1, 'Bellaire', 5);

insert into project values('ProductY', 2, 'Sugarland', 5);

insert into project values('ProductZ', 3, 'Houston', 5);

insert into project values('Computerization', 10, 'Stafford', 4);

insert into works_on values(123456789, 1, 32.5);

insert into works_on values(123456789, 2, 7.5);

insert into works_on values(6666884444, 3, 40.0);

insert into works_on values(333445555, 2, 10.0);

insert into works_on values(333445555, 3, 10.0);

insert into works_on values(333445555, 10, 10.0);

insert into dependent values(333445555, 'Alice', 'F', '05-APR-86', 'Daughter');

insert into dependent values(333445555, 'Theodore', 'M', '25-OCT-83', 'Son');

insert into dependent values(333445555, 'Joy', 'F', '03-MAY-58', 'Spouse');

insert into dependent values(987654321, 'Abner', 'M', '28-FEB-42', 'Spouse');

insert into dependent values(123456789, 'Michael', 'M', '04-JAN-88', 'Son');

select e.ssn, e.address, d.dname, p.pname from employee e, department d , project p where e.dno = d.dnumber and e.dno = p.dnum and e.Fname = 'John' and e.Minit = 'B' and e.Lname = 'Smith';

select e.Fname, e.Minit, e.Lname, e.address from employee e inner join department d  on d.dname = 'Research' and d.dnumber = e.dno;

select p.pnumber, p.dnum, e.Lname, e.address, e.bdate from project p, department d, employee e where p.dnum = d.dnumber and d.mgr_ssn = e.ssn and p.plocation = 'Stafford';

select employee.ssn, department.dname from employee inner join department on employee.dno = department.dnumber;

select p.pnumber from project p inner join department d on p.dnum = d.dnumber inner join employee e on d.dnumber = e.dno and e.Lname = 'Smith'  
union  
select p.pnumber from project p inner join department d on p.dnum = d.dnumber inner join employee e on d.mgr_ssn = e.ssn and e.Lname = 'Smith';

select Fname, Minit, Lname from employee where super_ssn is NULL;

select max(salary) as max_salary, min(salary) as min_salary, avg(salary) as avg_salary from employee;

select max(e.salary) as max_salary, min(e.salary) as min_salary, avg(e.salary) as avg_salary from employee e inner join department d on d.dname = 'Research' and d.dnumber = e.dno;

select count(*) as no_of_employees from employee;

select count(*) as no_of_employees from employee e inner join department d on e.dno = d.dnumber and d.dname = 'Research';

select dno, count(dno)as count_emp, avg(salary) as avg_salary from employee group by dno;

select pno, pname, count(essn) from works_on, project where pno = pnumber group by pname, pno order by pno;

select pno, pname, count(essn) from works_on, project where pno = pnumber group by pname, pno having count(essn) > 2 order by pno;

select pno, pname, count(essn) from works_on, project where pno = pnumber group by pname, pno having count(essn) >= 2 order by pno;

insert into employee values('Ahmad', 'V', 'Jabbar', 987987987, '29-mar-69', '980, Dallas, Houston, TX', 'M', 25000, 987654321, 4);

select * from employee where dno = 4 and address like '%Houston, TX%';

select fname, salary * 1.10 as updated_salary from employee, works_on, project where ssn = essn and pno = pnumber and pname = 'ProductX';

select lname, pname from employee, project, works_on where ssn = essn and pno = pnumber order by dno, lname;

SELECT DISTINCT 
    ES.Fname, 
    ES.salary, 
    D.Dname 
FROM 
    Employee E 
INNER JOIN  
    Employee ES 
ON 
    E.super_ssn = ES.ssn 
INNER JOIN 
    Department D 
ON 
    ES.dno = D.dnumber;

SELECT  
      E.Fname, 
      D.relationship 
FROM  
      Employee E  
LEFT OUTER JOIN  
      Dependent D  
ON  
     E.ssn = D.essn  
ORDER BY  
     E.Fname, D.relationship;

SELECT  
    E.Fname,  
    DL.Dlocation  
FROM   
    Employee E  
INNER JOIN  
    Dept_Locations DL  
ON  
    E.dno = DL.dnumber  
WHERE  
    Fname LIKE 'John';

SELECT  
       ssn 
FROM  
       Employee 
MINUS 
SELECT  
      essn 
FROM Works_On 
      ;

SELECT 
    Pnumber 
FROM 
    Project 
MINUS 
SELECT 
    Pno  
FROM 
    Works_On 
     
;

