//osc
const var panelswitch = Content.getComponent("panelswitch");


inline function onOscTypeControl(component, value)
	
{
	Engine.allNotesOff();

	if(value == 1)
	{	 	    
	Engine.allNotesOff();
		 WaveTable.showControl(1);
		 Looper.showControl(0);
		 panelswitch.showControl(0);
		 AudioLoopPlayer1.setBypassed(1);
	 WavetableSynthesiser1.setBypassed(0);

		 SyntesizerGroup1.setAttribute(SyntesizerGroup1.CarrierIndex, 0);
		 SyntesizerGroup1.setAttribute(SyntesizerGroup1.EnableFM, (0));
		 SyntesizerGroup1.setAttribute(SyntesizerGroup1.ModulatorIndex, 3);

	}	
	
	if(value == 2)
	{	 	    
		 Engine.allNotesOff();
		 WaveTable.showControl(0);
		 Looper.showControl(1);
		 panelswitch.showControl(0);
		 AudioLoopPlayer1.setBypassed(0);
		 WavetableSynthesiser1.setBypassed(1);

		 SyntesizerGroup1.setAttribute(SyntesizerGroup1.CarrierIndex,0);
		 SyntesizerGroup1.setAttribute(SyntesizerGroup1.EnableFM, (0));
		 SyntesizerGroup1.setAttribute(SyntesizerGroup1.ModulatorIndex, 3);
	}	
	
		if(value == 3)
		{	 	    
			 Engine.allNotesOff();
			 WaveTable.showControl(1);
			 Looper.showControl(0);
			 panelswitch.showControl(0);
			 AudioLoopPlayer1.setBypassed(1);	
			 WavetableSynthesiser1.setBypassed(0);
			 SyntesizerGroup1.setAttribute(SyntesizerGroup1.CarrierIndex, 2);
			 SyntesizerGroup1.setAttribute(SyntesizerGroup1.EnableFM, (1));
			 SyntesizerGroup1.setAttribute(SyntesizerGroup1.ModulatorIndex, 3);
	
		}
		
		if(value == 4)
		{	 	    
			 Engine.allNotesOff();
			 WaveTable.showControl(0);
			 Looper.showControl(1);
			 panelswitch.showControl(0);
			 AudioLoopPlayer1.setBypassed(0);
			 WavetableSynthesiser1.setBypassed(1);
			 SyntesizerGroup1.setAttribute(SyntesizerGroup1.CarrierIndex, 1);
			 SyntesizerGroup1.setAttribute(SyntesizerGroup1.EnableFM, (1));
			 SyntesizerGroup1.setAttribute(SyntesizerGroup1.ModulatorIndex, 3);
			 
		}
		
		if(value == 5)
			{	 	    
				 Engine.allNotesOff();
				 WaveTable.showControl(1);
				 Looper.showControl(0);
				 panelswitch.showControl(1);
				 AudioLoopPlayer1.setBypassed(0);
				 WavetableSynthesiser1.setBypassed(0);
				 SyntesizerGroup1.setAttribute(SyntesizerGroup1.CarrierIndex, 2);
				 SyntesizerGroup1.setAttribute(SyntesizerGroup1.EnableFM, (1));
				 SyntesizerGroup1.setAttribute(SyntesizerGroup1.ModulatorIndex, 1);
				 
			}
			
			if(value == 6)
					{	 	    
						 Engine.allNotesOff();
						 WaveTable.showControl(0);
						 Looper.showControl(1);
						 panelswitch.showControl(2);
						 AudioLoopPlayer1.setBypassed(0);
						 WavetableSynthesiser1.setBypassed(0);
						 SyntesizerGroup1.setAttribute(SyntesizerGroup1.CarrierIndex, 1);
						 SyntesizerGroup1.setAttribute(SyntesizerGroup1.EnableFM, (1));
						 SyntesizerGroup1.setAttribute(SyntesizerGroup1.ModulatorIndex, 2);
						 
					}		
	
};

Content.getComponent("OscType").setControlCallback(onOscTypeControl);

const var wt = Content.getComponent("wt");



inline function onwtControl(component, value)
{
if(value == 0)
{	 	    

	 WaveTable.showControl(1);
	 Looper.showControl(0);
}	

if(value == 1)
{	 	    

	 WaveTable.showControl(0);
	 Looper.showControl(1);
}	

};

Content.getComponent("wt").setControlCallback(onwtControl);




