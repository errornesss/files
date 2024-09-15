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

insert into Promotion values
  ('P02', "Holiday Special", 20.0),
  ('P03', "ValenTine's Day", 15.0),
  ('P04', "Spring Sale", 10.0),
  ('P05', "Summer Deal", 25.0),
  ('P06', "Winter Clearance", 30.0);

insert into Category values
  ('CAT02', "Dark Chocolate", "Rich and intense chocolate with a high cocoa content."),
  ('CAT03', "Milk Chocolate", "Smooth chocolate made with milk powder."),
  ('CAT04', "White Chocolate", "Creamy chocolate made with cocoa butter and milk."),
  ('CAT05', "Nutty Chocolate", "Chocolate with a mix of nuts and cocoa."),
  ('CAT06', "Fruit Chocolate", "Chocolate with fruit infusions like berries or citrus.");

insert into Chocolate values
  ('CHOC14', "Dark Delight", "A rich dark chocolate with 70% cocoa.", 4.99, 100, 'CAT02'),
  ('CHOC15', "Milk Magic", "Smooth milk chocolate with creamy texture.", 3.99, 100, 'CAT03'),
  ('CHOC16', "White Wonder", "Sweet and creamy white chocolate with a hint of vanilla.", 5.49, 100, 'CAT04'),
  ('CHOC17', "Nut Crunch", "Milk chocolate with crispy nuts.", 6.99, 120, 'CAT05'),
  ('CHOC18', "Berry Bliss", "Dark chocolate infused with mixed berries.", 7.49, 100, 'CAT06');

insert into Discount values
  ('P02', 'CHOC14', '2024-12-01 00:00:00', '2024-12-31 23:59:59'),
  ('P03', 'CHOC15', '2024-02-01 00:00:00', '2024-02-14 23:59:59'),
  ('P04', 'CHOC16', '2024-03-01 00:00:00', '2024-03-31 23:59:59'),
  ('P05', 'CHOC17', '2024-06-01 00:00:00', '2024-06-30 23:59:59'),
  ('P06', 'CHOC18', '2024-11-01 00:00:00', '2024-11-30 23:59:59');

insert into Customer values
  ('CUS146', "Alice Johnson", "alice.johnson@example.com", "5551234123"),
  ('CUS147', "Bob Smith", "bob.smith@example.com", "5555678456"),
  ('CUS148', "Charlie Brown", "charlie.brown@example.com", "5558765789"),
  ('CUS149', "Diana Prince", "diana.prince@example.com", "5554321012"),
  ('CUS150', "Eve Davis", "eve.davis@example.com", "5556789345");

insert into Review values
  ('REV132', 8, "Absolutely delicious! Will buy again.", '2024-01-15 14:30:00', 'CUS146', 'CHOC14'),
  ('REV133', 6, "Very smooth, but a bit too sweet for my taste.", '2024-02-20 09:15:00', 'CUS147', 'CHOC15'),
  ('REV134', 10, "The best white chocolate I have ever tasted!", '2024-03-05 17:45:00', 'CUS148', 'CHOC16'),
  ('REV135', 4, "Nice texture but the nuts were not crunchy enough.", '2024-04-10 11:00:00', 'CUS149', 'CHOC17'),
  ('REV136', 7, "Great combination of dark chocolate and berries.", '2024-05-25 13:30:00', 'CUS150', 'CHOC18');

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

