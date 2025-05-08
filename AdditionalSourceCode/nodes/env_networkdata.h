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
		return "552.nT6K8C1rETOD.XGVNYB.wha.DHZYo41DRhZLZG98gR7qOrJmWePCkaOBPUk5P6t+YA0cJHD.AAvQ.DA8Zsy1dXspfPcrX+XyJFA2Z88kM57q5HdbqCmVbtERD6vsXyXk5YrOtJhMsx1jyKblRIkcClyramnH.2pgN47tkHytlU1kcrPXConhMiekigMq7dFZigU0G4PsqjqI6L1J0eZe4RyBavlK9TOaRu73f3YSoevRqPqlc731sBfyuZKa8+TXAhHEYAIISdML4wvDFbfiqgZeSduHGj7RXiHUl+TQQQO9Qm1hkwhV7XYnCgtFWPrOE3G21wgXUpiAi1CasLqFm5um53w9luFEmyA4hGv+VBFZodlLQ5S.jugpUQxqsK8K3G6tvW0n3GQQ15JehcDIsP4bBFBZk9FuhBdL+rOF5kZMFeZ0TEfWfFVLSYfhHI.fflAHB.DmZYxABSxlvVxEXPRt84QlNazsmfVNotgfeGf6kbtKR99xs.axOV4THiu1WvuIP.74d3twyv8niru.RcRY6jwnrztdbVeyBpLNKFzbfrn1.oMKzbYNodTmElMkFoEOAfi0SNDLFd0MJTLSMvDR54hSIC7nrAcL.NvcFHyLG2XQ8Jqj.bj52.aPa7f6fDMMAXUlc.1N4sSA1ZakrlvM.IYtxhOyFYNfCs5hVoK.RCZEfGyCP1nCrLlZ3Gzsnj6jrIH7jOasdpPM3leit6BToCnuGnTE";
	}
};
}

