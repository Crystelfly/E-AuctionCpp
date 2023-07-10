CREATE TABLE [dbo].[Payment] (
    [Card_No]     CHAR (16)    NULL,
    [Card_Name]   VARCHAR (30) NULL,
    [Expiry_Date] DATE         NULL,
    [Bid]         INT          NULL,
    [Amount]      INT          NULL,
    FOREIGN KEY ([Bid]) REFERENCES [dbo].[Bidding] ([Bid]) ON DELETE CASCADE
);

