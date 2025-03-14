namespace project
{

struct cablein_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "cablein";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "326.nT6K8CFrATdB.XKD2PBHMSa.GPKi9YQ7j+D1ZjALjYuSEAB864utF.AhHl5RTYr6TJvJ.zB.t.fyVBzLyyT5D8mwL.oY27IplK0RsVEZBcmTrqjPW+tvrM.MgD4QSMQGhumDP2O4QKO9h+vrCj3ofTCyeWr3HB2CaTJ0MexilqERyVKIwb5rPBcbFlJ1PG+vuolKIy2eMr.nYO83JIzcOqgP+wF0w8wliGo.oIiCZfPiDZ3fgAajlwI+4OTXBr34M9Oof1ZrJyyaVARHQVDAKIWp0tPmjDZtJh82a3HSIaMdWMaQ9FSjcfyIf.EH5PrdP5.yjy0GrAhgd+KHHMKA+I.ImwwNAEugGvlEYMxPrVAbs7NDgA2RHJxgIwBCeE0i8Mp7EHGtoi+7..cfCbr1wPCdGrmAFCV1w6fwUHbeTH.psNRQdYF";
	}
};
}

