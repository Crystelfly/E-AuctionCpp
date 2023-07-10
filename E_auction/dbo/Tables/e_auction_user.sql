CREATE TABLE [dbo].[e_auction_user] (
    [Uid]       VARCHAR (20) NOT NULL,
    [Name]      VARCHAR (25) NULL,
    [User_type] CHAR (1)     NULL,
    [Phone]     CHAR (15)    NULL,
    [Address]   VARCHAR (30) NULL,
    [Password]  VARCHAR (25) NULL,
    [Issue_date] date        NULL,
    PRIMARY KEY CLUSTERED ([Uid] ASC)
);

