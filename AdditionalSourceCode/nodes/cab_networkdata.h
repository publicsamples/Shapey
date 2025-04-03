namespace project
{

struct cab_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "cab";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "266.nT6K8CFmAT.B.HjStPBHMhS.GTwNwHBGIxoJkA.k04sH7rfo+MNUTKf.BHShC8DCR52cP3IgmFJzLv0ErUyDKjyVLUeNHJxC4HWYgazeyCObPCHOWMsQ9qcwF+dsCkwkzEgrkFFwjmcfiAOONONMTF4gU8T6XM44hUMTK37jz1fXZk5oIp.Z9SwjbkE5LEf7RXJp0xkE9ysTZKH+ba70Mkf7ThazEXGa6CE4YIMTlmsXKltH+qcTPNxk1lp4YnAl7Q.aIhLTZ.vUfCFvz0vYcMrlN3vXXYH77.rYvgPuiYVNOUtbKP458UXkuXR1M9NIi0UI5LyvW3nbHqgqlUAGqr8DrM8PrMFa3n.";
	}
};
}

