CREATE TABLE [dbo].[Contracts] (
    [Id]               INT   IDENTITY (1, 1) NOT NULL,
    [Date]             DATE  NOT NULL,
    [InsuranceAmount]  MONEY NOT NULL,
    [TarrifRate]       MONEY NOT NULL,
    [InsuranceType_Id] INT   NOT NULL,
    CONSTRAINT [PK__Contract__3214EC0755DDCD7F] PRIMARY KEY CLUSTERED ([Id] ASC),
    CONSTRAINT [FK_Contracts_InsuranceType] FOREIGN KEY ([InsuranceType_Id]) REFERENCES [dbo].[InsuranceType] ([Id]) ON DELETE CASCADE ON UPDATE CASCADE
);

