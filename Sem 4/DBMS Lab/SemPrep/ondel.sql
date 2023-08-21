CREATE TABLE a
(
    n int PRIMARY KEY,
    name varchar(20)
);

CREATE TABLE b
(
    n int,
    name varchar(20),
    FOREIGN KEY(n)
    REFERENCES a(n)
    ON DELETE SET NULL
);

INSERT INTO a VALUES(1, 'A');
INSERT INTO b VALUES(1, 'B');

SELECT * FROM a;
SELECT * FROM b;

DELETE FROM a;
