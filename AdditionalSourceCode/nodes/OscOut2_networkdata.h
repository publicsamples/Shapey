namespace project
{

struct OscOut2_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "OscOut2";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "262.nT6K8C1r.T9A.HvCvLBHqZU.OUIuKBvrJvJE.jFZwtkASffliauT.BQRRK4FJmVK8+MwRo3A9wWp0tP2CD5isYiBGYn+oT2vjsziibX6lrFD1LZ3XQ+jaFaU5Hzh9BNvYgiyBmFC1.zGk5WyPIA5lRcbI3QvlbgGyP+jrBrWtnMJ7yWKi9nlTxUlR3PGOgohMnimvlsCnexjglh8jwJfPeKpeT8K0Rs1D5gsSFaQthkQOyA6IUldMjC86gvalRPXRHK.5a3fQeCw1gY6IXAHPXPHWGvkx.GGX5fSo6XrbjjqfEvOWnv55iEDrasBXFxZQT1P+GLMPj8z.gKnBek.rPtf4mLJJ.";
	}
};
}

