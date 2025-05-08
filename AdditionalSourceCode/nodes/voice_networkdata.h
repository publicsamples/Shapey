namespace project
{

struct voice_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "voice";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "135.nT6K8Cxn0O..RgzFb.WPUA9fHMZZ29.cja58X8M.ZEOlpJdeLDRaxGv+g8FWDs00+gAxEQUOcL4MVHTSVN7mSaLTuOmFeL6PHeKpqkliLMgf7qAqx7ITBkdrC16hW3XxybOtkrbvKE93vvWliC3LHOBEl7.zrRbUAP..Sg.1OaA2gYsjrT6A";
	}
};
}

