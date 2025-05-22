namespace project
{

struct blank_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "blank";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "440.nT6K8CV7CTWC.Xlz7TBHsZd.0zJ4IDq30gNaaK.Thkm22lpqKTvK8.BvzFEe4YHQzlRAx.PL.PC.sA7JUcJUyX8wiXAuOTbBy6hAiN57srs9wAiRxpWjhDw2ygECzeWZ.30IhBdwLiRT+IAzIgAuMLyqLQMARTp4S0coEPAqv7qSmx1Bno5dR5Ra3exmrLnmRcYEjU5YMenyqv3SzXWfjlAaqOJO5c1FMFXMbvV3fUpJempCx1dzZrFbzXsEqQXBWE4Wq7n0Lx3RV1p0M0ysDrfWS8.S+eMzCA8WlfHyCAiPmeTDEjJ+IoNGl20qtSl+ImhOzvqmV8bn2I7x364dBHEnQ2xPyLXFaniAPA.wXY2.gT5ExXky9X.b3AEttXOHcYsIL7z3A5Hv6Jq3DliSp2AKfCbqGlR.gKmSg6Vl9piwQbIkygAX14exrMaVKewn4OViF1A39.CcnO.DLboa4lGAX+kknPCIdH5.eR.8TFhRvDpn8.mtF39W7I.vjoWhcDcU3AHKhGPu29bqsUr5X.aT17gWU3AOrAvOFtpglXRv0c.t2YZq6YiVY8tLGqiCTYnSKf1.fnJ";
	}
};
}

