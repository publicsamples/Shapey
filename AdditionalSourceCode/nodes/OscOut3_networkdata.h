namespace project
{

struct OscOut3_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "OscOut3";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "257.nT6K8C1r.z6A.HnytLBHqZU.GUIuKBvrJvJE.jFZwtkASffEY.aGffrjzRtgxo0R+7EwR0z.63K0ZWnywA8w1rMgiLzkdLjCa2j0fvdAiFK5mbyXiRGgVzqvoIgiiANIJXCPeTpe8BUDnaJ0wkfGAaREd7B8KxJvd4h1lvOesL5iZRISYBgCcrDlJ1fNdBa1NfdISFZJ1SFmvA8sn9Q0uTK0ZQnG1NYrA4MKidlC1RnL8ZnJ86cvULkdvjOV.zynAidFhckY6IfEf.gAgbc.WJCbbfoCNktiwxQRtBVfetPD1UeDffyqUXxPAKhxF5+foAhrmFHbAU3qDfExEL+jQQA";
	}
};
}

