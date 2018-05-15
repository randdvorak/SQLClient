SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [rpctest]
	-- Add the parameters for the stored procedure here
	(@intin int,
	@fltin float,
	@bitin bit ,
	@datein datetime,
	@stringin varchar(128),
	@datain binary(512),
	@intout int out,
	@fltout float out,
	@bitout bit out,
	@dateout datetime out,
	@stringout varchar(128) out,
	@dataout binary(512) out)
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

	select @intout = @intin;
	select @fltout = @fltin;
	select @bitout = @bitin;
	select @dateout = @datein;
	select @stringout = @stringin;
	select @dataout = @datain;

	return 123;
END
GO
