namespace project
{

struct blank_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "blank";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "133.nT6K8CxnkO..xejFa.WZazAJoVRynTKKQP5lYGfLfhDppZgXonQoe7eWqOkI6D4+N.nxjGIpykMOF9xRkUp0kkukWnA3UdIxSyuUhH.dMgOP7pjJoVl4ZUwIfLvuXKqz7zXDGt0J7kMaKPBveHgA9klcd5Q.E.vTHf+YSrvAt6vbQRVp8.";
	}
};
}

