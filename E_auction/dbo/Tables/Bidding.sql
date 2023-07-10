CREATE TABLE [dbo].[Bidding] (
    [Bid]           INT          IDENTITY (1, 1) NOT NULL,
    [Sid]           INT          NULL,
    [Uid]           VARCHAR (20) NULL,
    [Bidding_Price] INT          NULL,
    [Bid_Finalise]  INT          NULL,
    [Security_Fees] INT          NULL,
    PRIMARY KEY CLUSTERED ([Bid] ASC),
    FOREIGN KEY ([Sid]) REFERENCES [dbo].[seller] ([Sid]),
    FOREIGN KEY ([Uid]) REFERENCES [dbo].[e_auction_user] ([Uid])
);

