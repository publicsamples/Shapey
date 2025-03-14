namespace project
{

struct out_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "out";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "207.nT6K8Cld.zhA.HFymDBPqwI.XiqUs4hQ.UMsbpbmzSt.ML2Vs17LluR3zMqrl9QjWruk4OAAMf7PbSKQlG9XGGFHhVlCtTx7eiqBDybK5EV1cvOBV1oBbvUnZ1CNj.zxQK3PtoW.HOhlx2vP35hP71ZeTGOts1XqUpA4ehKSzqipkgTdtoWx7HGHGH5.4a8B93FdhlxqVs9wEwZlFMioviLZUyqjHkWwqaD4kz.HfIjj9.wfNEzpL6NnWA3JsSgwKNtAFWcdeaHfwtE219lA";
	}
};
}

