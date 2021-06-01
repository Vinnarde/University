CREATE TABLE Contracts( 
   Id   INT                 NOT NULL, 
   Date DATE                NOT NULL, 
   InsuranceAmount MONEY    NOT NULL, 
   TarrifRate      MONEY    NOT NULL,
   InsuranceType_Id   INT   NOT NULL,
   PRIMARY KEY (ID)
);


CREATE TABLE InsuranceType( 
   Id   INT              NOT NULL, 
   Type nvarchar(64)	 NOT NULL,
   PRIMARY KEY (ID)
);

ALTER TABLE Contracts
   ADD CONSTRAINT FK_Contracts_InsuranceType FOREIGN KEY (InsuranceType_Id)
      REFERENCES InsuranceType (Id)
      ON DELETE CASCADE
      ON UPDATE CASCADE
;