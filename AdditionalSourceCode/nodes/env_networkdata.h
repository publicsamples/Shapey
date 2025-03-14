namespace project
{

struct env_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "env";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "557.nT6K8ClnEzQD.XPlPYBzxhE.3UkSMg7nLVernTeuecxYdNrtFzQq2wAWgWvA.PrzXdJL4OD.DAPR.3TXJmW7.Pb+V.b+wPbW1VaLa6gyo5o1Xy3EiVwG3NmaTyVkdqhQ.w8VRy3b+4wSbGiNs0NiyAVyr6Xn..26Tocb6LQlchIdiX7nsxtnW94IWJiL6tjBKFcdqZLL5kauoFwfS0c1A0OTqYEy31Ze6qXMp4RKCWv17V6LZUSjmNiZ0FTsRNQdR7HEYgQ3cph2qCb.QPQL.IUA1PEnkJVl5n6PcXEH7MIAS3iIUVeoduGjo3QzhyXSKj3NkyxVJaMtf3vE3Ht6QKwr0diMzdXKZE.jd0bv8bwB7eaeiRvRp8lMy5c.9MGUsKusw1pufoH.CPvnGTTCPuIHnjjjUi5awpFCO4RK5Drj+tBBfLG42BDzDTZ5EEPWfFYMBMAEAY..jfb.vH.PTpkoM7YmVCZS.XcjaWp1xhjBtOoV6zRmCLQkGRRlsFUaNFvuKkZPriyJ.e6f6L7Dbgibker+DmqwN2kNP+pmno3MrmbNZu.ON.lUTF3yWYX5dArQzHcB6PQ.AjDVszY.vsKNDyB1YX5P+wDH3balsAdLYPGDndHtEfyjVgYC8I2Xk+CpgssGJFzvoIvn1rClsSuapQMrfRVNDYrhhOhMEmEVM0NdEKpanaSBFMoKALWoffzJS7VEv7PDGWOU+y2LgAMYLzJC+VRmCnJA7qB";
	}
};
}

