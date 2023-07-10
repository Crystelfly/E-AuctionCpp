CREATE TABLE [dbo].[product] (
    [Pid]          VARCHAR (20) NOT NULL,
    [Name]         VARCHAR (25) NULL,
    [Qty]          INT          NULL,
    [Company_Name] VARCHAR (25) NULL,
    [Mfg_Date]     DATE         NULL,
    PRIMARY KEY CLUSTERED ([Pid] ASC)
);

