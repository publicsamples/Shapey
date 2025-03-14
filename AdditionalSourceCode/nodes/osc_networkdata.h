namespace project
{

struct osc_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "osc";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "423.nT6K8CVCCzNC.Xxz9TBHKia.bAS15oH7b38z5DEL5ZuND0.FS0TI4GDf.VVDdyqEOJkBx.vL.XC.TMB3sp1RYyuR0QZ75VdJLuMNsE7JeHc5UVWiBJ+Jqr3Kg8wnBKE8aMdij..uXlOV0ozkqGYczhBi5ZGkwiVM7PPvM9bmesiQ3.IVJBlN85rkv9pIuglx5Xwoz1J6wVQ0LcIrqxuCGuGliYZcLbNGGONGWAA7ZJ1Z7pu3QSZJbO.mr75zSldxUrqHgSTv6ttCZI3MiaQJg4kN8KwtKU9vJkKkODlgjPGZWI0Vjn1K3ZNnGDDTiaeXsYvf29ZKxnj9kC9LRS.nFIz3Ag2iAziSEAZX8JGHXrIgvPncC.F.fZRy.rJxCic4XYEHNBl3Z9GhCgq4.yhhMwPDYYbvXMvtarL5Ydcp.M2eo0MKqy.lIPNZeKyFBRSk7Bg2DOhNQF3GrHfiqGhAf.HsICKJzCOsZYYv0JxaBH.9UE3IUvPfj0WdAPfhyVLnpmN6rLb24IQga49GNSCqkckG2xPuguBnzQZJCbSrg55.kLPZO.VM";
	}
};
}

