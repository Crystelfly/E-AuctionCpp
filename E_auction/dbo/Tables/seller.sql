CREATE TABLE [dbo].[seller] (
    [Sid]           INT          NOT NULL,
    [Uid]           VARCHAR (20) NULL,
    [Pid]           VARCHAR (20) NULL,
    [Offer_Price]   INT          NULL,
    [Expiry_Date]   DATE         NULL,
    [Security_Fees] INT          NULL,
    PRIMARY KEY CLUSTERED ([Sid] ASC),
    FOREIGN KEY ([Pid]) REFERENCES [dbo].[product] ([Pid]) ON DELETE CASCADE,
    FOREIGN KEY ([Uid]) REFERENCES [dbo].[e_auction_user] ([Uid]) ON DELETE CASCADE
);


GO
CREATE UNIQUE NONCLUSTERED INDEX [UK_Seller_Uid_Pid]
    ON [dbo].[seller]([Uid] ASC, [Pid] ASC);

