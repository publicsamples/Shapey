namespace project
{

struct subs_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "subs";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "408.nT6K8CF1BTGC.XC0AUBDqia.brHW7VVqzJBRjmnN3SsfHxXRIqUKY...dRgxNBlEnuLE2.PM.fC.s0hxTedmBYJHZaW4WZs8I8jdNEsU5w42aVHNn1BiR2J6ykS0feccvN4TmtDschEn1tv6MP6KALuXEjcEXT5XOawolw4Hf11YezfnsuOmMzepc2ITqw3K6yA01pdN4rORVYjsfReKiLU5Pm.AWULFO7DqjfwN9kiBbtuqhdhSbKVpuoSNAWCexVYR8Gc3I8dPpW7lkg9ozSVhiAcp.JpQyhOLy1wt67aZiwOSQqXb.vPZYZw.DL8HRDDokon1R6NOqYpQaa3W8LGnvVJcD1kVw3bzpaPDomKgLxUB2.BTfnwYUFPMA05ECttCrNwkvIIWHM4PjSfEtan4vGFFM3n8C13XJ8tfZFw06JQJ+gv5d1VQzgapKF8LvLkV9Gg24FtwNRvNvIb2O8CWE.BaeFtsnFuSbvh3ZCe3jA1.VGDZ3zBb0N1sKILwWjMHCIv.K8T.X64pAdAzhVFluNLxYbhB";
	}
};
}

