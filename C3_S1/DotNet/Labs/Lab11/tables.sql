
USE lab11db;

CREATE TABLE teachers (
    id INT NOT NULL IDENTITY(1, 1) PRIMARY KEY,
    first_name VARCHAR(255) NOT NULL,
	last_name VARCHAR(255) NOT NULL,
	middle_name VARCHAR(255),
    degree INT
);

CREATE TABLE degrees (
    id INT NOT NULL IDENTITY(1, 1) PRIMARY KEY,
    title VARCHAR(255) NOT NULL
);



--------------------------------------------------

ALTER TABLE teachers 
    ADD CONSTRAINT FK_TeacherDegree FOREIGN KEY (degree)
        REFERENCES degrees (id)
        ON DELETE CASCADE
        ON UPDATE CASCADE
;

