namespace project
{

struct send7_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "send7";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "299.nT6K8ClSAzPB.X.TzLBHKSa.GRiFcBMWfpjqG.jBrs.y..Hl0Nh5ADvffFSXjLnzOnB.o..K.feuvUP7K0RsbLKpWKeQh.+CywPZlZryFt0N3Mt31nD.7Qlf.OCMu4sUBnKvMLo.I9Gc.2LZkuRD3urQQplIDtioPOpdcL843mb.7PO0Yp42iJIQpk6X16YcNFRjIGvOgrWuZ314.dFOZTPCGObvvfTA9VhaLDEFG6IwcRvUnEvWpEhJnmlIUz51d9RsnAkxWpUlNFkD368sYzVc9eRIz6qwjjAfekZAd.BDPDPrvbm8VdvhBgewBwTAMELHLoRDNNS1wbB6CvIkGSkC8jKT.DvUdXggkhUT6gsBHWFL+CLaftbWDwo6CCdhm1h8uEbWrVRV98.";
	}
};
}

