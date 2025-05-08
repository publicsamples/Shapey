namespace project
{

struct OscTest_networkdata: public scriptnode::dll::InterpretedNetworkData
{
	String getId() const override
	{
		return "OscTest";
	}
	bool isModNode() const override
	{
		return false;
	}
	String getNetworkData() const override
	{
		return "444.nT6K8CVPCTYC.XFUBUBHoia.L.Rj8HImO7RVVhd3ZtBTLlp4+Lri5MvVHjFm7LCR7iTJ2.fM.jC.RWK.uVUGS1TVcNkl2Wi7ByKinNAuQ4iN+Laqcunz5JCJw3QBgQ1J8WvQSnUvKUE.3kyT5o9WBrz4uYCljLGdQeTd0o97vqNxIGXF+bmxpCgOGU1KPrzCLc90oaU8c7KajlmR8qLIqkiw7iOuFOYfjjiFSQPfHI444TsMGsVDjoVTa.ERMDzZogZM7pt9Z0zG2x179XPOS7Yo4Eh2caEzH38yqIVg4rZprzn6iQ4DlmwG0svzIPzpNBscaUuirhEoBw7MO0JeUWABV3n0Pstkj5DYt3iwvOozAz3wAORQfFRsCpBlYRHPLztAPA.fFl4A3RY8.qosIPljx13RgCbS.QSY5MF0hM3Gy3VNzICn5c3gIGmDpUHYA63qc.ifEeKoz1EFjvUvuR0t1S5QPAARI380.EPxfzQNtOXQf5xGhC.AfYQtghYwr67ZG5sAWPhqAPNS45v.hUvrUCpX5rYcH42GEDAyEbdEloQ+pwZ9gLAL9D.Df0Xs7GU1z0AJ4.9O.vpA";
	}
};
}

