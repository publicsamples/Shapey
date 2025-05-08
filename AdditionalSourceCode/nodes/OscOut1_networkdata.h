namespace project
{

struct OscOut1_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "OscOut1";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "260.nT6K8C1r.T8A.HsiuLBHqZU.GUIuKBvrJ3jC.FK0dF8YaPzrDuvd..1RIjdCjQyl98MwR07.63K0ZWnyAB8w1rMgibz+TBpQ5wONrcSVCB6ELZrnexMiMJcLZQuANKEG3ffSAJ1.zGk5WuPEA5lRcbI3PfMICOtg9EYEXubQaS3muVF8PZRISYRgCcrDlJ1fNdBa1NfdISNZJ1SFu.B8MH8ipeoVp0lPOrcxX6waVF8LGrkPY50QU52Kg2LkfXRnE.8LZvn2gXWY1dhEf.gAgbc.WJCbbfoCNktiwxQRtBV.+bqEFUeDffyqUXxPAKhxF5+foAhrmFHbAU3qDfExEL+jQQA";
	}
};
}

