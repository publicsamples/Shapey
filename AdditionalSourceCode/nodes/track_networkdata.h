namespace project
{

struct track_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "track";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "315.nT6K8CVdAzXB.XGT0LBDMaa.upyYmjpQ7oLqRvVyvlvdfmQSdrSJD..ffDsjHyiljoB.q.PK.7Z6+ZHcfDw7KkMd+PKCKRjY8jLwkZoVutI4bELCz5uxHwHOIRLi2P77jztFByZ0kW6mZWI.YmkE5A2ZocWTAzDQoDIGsSvkpHQFKIsZ1r.9ZKFHkywEecXcSrVBhe6ZPAHQdxsUvW2dH98ZHZiMY6cVS6TTjOLv4.mDbP3QAZiD8o.532n9mTHSFaUX9MRCHxCF4wQDqDboVp9ZRVjnxv4miVeofL1pZhrmmSBH.HDHUaubjBSgYFN.g0iEDMeXRIA9xgqhKyOVE5FNfMTj0jgvZE9ZocHhA2VHzlgIwBCbE0x9PT9hlrFz1iZFF.gFUHfCNjWc0dO3nYaBay6l0Hy5HKPd";
	}
};
}

