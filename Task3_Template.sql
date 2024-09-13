-- Question-A
-- Table Creation (Incomplete and Erroneous - please fix the errors and complete this section)

CREATE TABLE Promotion (
	PromoID CHAR(3) primary key,
	PromoName VARCHAR(50),
	PromoDiscount DECIMAL(4,1)
);

CREATE TABLE Category (
	CategoryID CHAR(5) primary key,
	CategoryName VARCHAR(50),
	CategoryDesc VARCHAR(200)
);

CREATE TABLE Chocolate (
	ChocolateID CHAR(6) primary key,
	ChocolateName VARCHAR(50),
	ChocolateDesc VARCHAR(200),
	ChocolatePrice DECIMAL (5, 2),
	ChocolateWeight INT,
	CategoryID char(6),
  foreign key (CategoryID) references Category(CategoryID)
);

CREATE TABLE Discount (
	PromotionID CHAR(3),
	ChocolateID CHAR(6),
	StartDate DATETIME,
	EndDate DATETIME,
	PRIMARY KEY (PromotionID, ChocolateID)
);

CREATE TABLE Customer (
	CustomerID CHAR(6) primary key,
	CustonerName VARCHAR(70),
	CustomerEmail VARCHAR(100),
	CustomerPhNum VARCHAR(32)
);

CREATE TABLE Review (
	ReviewID CHAR(6) primary key,
	ReviewRating DECIMAL (2,0),
	ReviewComment VARCHAR(255),
	ReviewDate DATETIME,
	CustomerID CHAR(6),
	ChocolateID CHAR(6),
  foreign key (Customer) references Customer(CustomerID),
  foreign key (Chocolate) references Chocolate(ChocolateID)
);
-- Once successfully implemented, these insert statements should work.

INSERT INTO Promotion VALUES
	('P01', "Opening Sale", 50.0);

INSERT INTO Category VALUES
	('CAT01', "Ecuador Single Origin", "Cocoa beans from a single Ecuadorian source");

INSERT INTO Chocolate VALUES
	('CHOC13', "Dark Chocolate Tablet", "Small, bite sized dark chocolate tablets", 17.99, 80, 'CAT01');

INSERT INTO Discount VALUES
	('P01', 'CHOC13', '2023-02-01 08:00:00', '2023-02-02 18:00:00');

INSERT INTO Customer VALUES
	('CUS145', "Jon Snow", "j.snow@notreal.com",  "90861923");

INSERT INTO Review VALUES
	('REV131', 8, "A delicious milk chocolate", '2023-02-02 13:22:54', 'CUS145','CHOC13');

-- Please ensure you INSERT atleast 5 records for every table and add it below







-- Question-B
/* Explain in simple words what each query does and make sure you comment it
 */

-- An example of an answer to a Query

/* This query prints the names of all chocolates */

Select ChocolateName
from Chocolate;

-- Query 1: A query involving a single table with one condition. Insert your answer below



-- Query 2: A query involving a single table with two conditions, with one of the conditions that uses a wild card operator. Insert your answer below



-- Query 3: A query involving a join between at least two tables with an order by clause. Insert your answer below



-- Query 4: A query involving a single table with an aggregate and group by function. Insert your answer below

