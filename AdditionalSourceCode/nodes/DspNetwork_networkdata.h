namespace project
{

struct DspNetwork_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "DspNetwork";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "290.nT6K8CVIBTLB.HpSvTBHMhS.GTwNwHutEnkvJGDJqyavXfEL8uwoBDfDD.cQLTENZoe.PHDkPDCEdF3Q209.K8LwB4LGlpuFjl7PNxQrvk5+oAGLnAjmubaj+5VrheutwkVDxVZHESd1APFDEAEAwPWjGd0ttgCkWKd0Ps.1IYqbvsRZGEU.MUE4kdzj+VLIGwNclBP9Irk0Z4xB+01JUNP9013qqTBxWItTWfcrZczjmmzSYdlCygoJx+5lEjiLYwRRWjW5ASdHfsDQdJfHf.FH.J2xAbHU3eVWHZ55gABCwyxfg3lkAPDC.A2AkyyjKu.i66iGKWDxgaz3jD.JzAn+ANygLtnmcwLmMlWVD1GHi.LcvGZh6fEFQWHa5bybm2A";
	}
};
}

