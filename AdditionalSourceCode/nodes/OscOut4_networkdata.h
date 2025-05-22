namespace project
{

struct OscOut4_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "OscOut4";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "257.nT6K8C1r.z6A.HnytLBHqZU.OUIuKBvrJvJE.jFZwtkASffRAAaGffrjzRtgxo0R+7EwR0z.+3K0ZWn6wA8w1rQgiLzkdbjCa2j0fvlQCGK5mbyXqRGgVzWPhEMNNKbRnXCPeTpeMCkDnaJ0wkfGAaxDdrB8SxJvd4h1nvOesL5iZRIWY5fCc7DlJ1fNdBa1Nf9ISFZJ1SFivA8sn9Q0uTK0ZQnG1NYrE4MKidlC1SpL8ZHF52yfqXJAgIgr.nugCF8KDaFlsmfEf.gAgbc.WJCbbfoCNktiwxQRtBVfetPD1UeDffyqUXxPAKhxF5+foAhrmFHbAU3qDfExEL+jQQA";
	}
};
}

