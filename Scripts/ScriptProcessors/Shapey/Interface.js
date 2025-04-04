Content.makeFrontInterface(770, 545);

include("laf.js");
include("Scopes.js");
include("Loading.js");

//Impulse panel


const var ModA = Content.getComponent("ModA");
const var ModTempo = Content.getComponent("ModTempo");
const var ModDiv = Content.getComponent("ModDiv");
const var ModTrig = Content.getComponent("ModTrig");

//sync button

const var SyncOff = [Content.getComponent("Pitch"),
                     Content.getComponent("PitchModuation"),
                     Content.getComponent("PitchModSrc"),
                     Content.getComponent("PitchMod"),
                     Content.getComponent("PitchLabel")];

const var SyncOn = [Content.getComponent("ScriptLabel80"),
                    Content.getComponent("Divide"),
                    Content.getComponent("ScriptSlider58"),
                    Content.getComponent("ScriptLabel86"),
                    Content.getComponent("ScriptSlider59"),
                    Content.getComponent("ShapeModSource16")];



inline function onPitchSyncControl(component, value)
{
	if(value == 0)
	{
for(s in SyncOff)
	       s.showControl(1);
	      
for(s in SyncOn)
	       s.showControl(0);
	       
	Shaper.setAttribute(Shaper.PitchSync, 0);
	}
	
	if(value == 1)
	{
	for(s in SyncOff)
	       s.showControl(0);
	       
	       for(s in SyncOn)
	       	       s.showControl(1);
	       	       
	
		Shaper.setAttribute(Shaper.PitchSync, 1);       	       
	       	
	}
	
	

};


inline function onOscShapeControl(component, value)
{
		Shaper.setAttribute(Shaper.OscMode, value);
	
	if(value == 5)
	{

	
		Shaper.setAttribute(Shaper.InputMode, 2);       	       
	       	
	}	
		
};

Content.getComponent("OscShape").setControlCallback(onOscShapeControl);


Content.getComponent("PitchSync").setControlCallback(onPitchSyncControl);

//carrier menu

const var ModMultiSample = [Content.getComponent("OscVisual")];



const var OsShape = Content.getComponent("OscVisual");
const var ModWaveLoad = [Content.getComponent("ModPos"),
                   Content.getComponent("FolderSelect1"),
                   Content.getComponent("ModLoadWave1"), 
                   Content.getComponent("PitchModuation1"), 
                   Content.getComponent("ScriptAudioWaveform1"),                 
                   Content.getComponent("SelFolderLabel")];


inline function onModulatorModeControl(component, value)
{


	if(value == 0)
	{
	for(s in ModMultiSample)
		       s.showControl(1);
		      
//	OsShape.showControl(1);
		      
		for(s in ModWaveLoad)
	 s.showControl(0);	
	
Shaper.setAttribute(Shaper.ModPostSwitch, 1);
	 
   
	}	  
	
	if(value == 1)
	{
	for(s in ModMultiSample)
		       s.showControl(0);
		      
	OsShape.showControl(0);
		       
		for(s in ModWaveLoad)
		       	 s.showControl(1);	  

	Shaper.setAttribute(Shaper.ModPostSwitch, 3);	       	  
		       
	}
		    

};

Content.getComponent("ModulatorMode").setControlCallback(onModulatorModeControl);



inline function onBankADisplayControl(component, value)
{


  Sampler1.loadSampleMap(value);


};




const var Panel3 = Content.getComponent("Panel3");


const var MODEnv1 = Content.getComponent("MOD Env1");
const var MODEnv2 = Content.getComponent("MOD Env2");

const var LFO12 = [Content.getComponent("LFO1")];

const var Table = Content.getComponent("Table");


inline function onModPageControl(component, value)
{
	 if(value == 1)
	 {
	 MODEnv1.showControl(1);
	 MODEnv2.showControl(0);
	 Table.showControl(0);
	  for(s in LFO12)
	 s.showControl(0); 

	  }
	  
	  if(value == 2)
	  	 {
	  	 MODEnv1.showControl(0);
	  	 MODEnv2.showControl(1);
	  	 Table.showControl(0);
	  	  for(s in LFO12)
	  	 s.showControl(0); 
	 
	  	  }
	  	  
	  	  if(value == 3)
	  	  	 {
	  	  	 MODEnv1.showControl(0);
	  	  	 MODEnv2.showControl(0);
	  	  	 Table.showControl(1);
	  	  	  for(s in LFO12)
	  	  	 s.showControl(0); 
	  	  
	  	  	  }
	  	  	  
	  	  	  if(value == 4)
	  	  	  	 {
	  	  	  	 MODEnv1.showControl(0);
	  	  	  	 MODEnv2.showControl(0);
	  	  	  	 Table.showControl(0);
	  	  	  	  for(s in LFO12)
	  	  	  	 s.showControl(1); 
	  	  	 
	  	  	  	  }
};

Content.getComponent("ModPage").setControlCallback(onModPageControl);

const var OscStuff = [Content.getComponent("Transform"),
                      Content.getComponent("Osc1"),
                      Content.getComponent("Osc2")];

const var Arp = Content.getComponent("Arp");
const var PnS = Content.getComponent("PnS");


inline function onPresetsControl(component, value)
{
	if(value == 0)
	{
	PnS.showControl(0);	
	}
	if(value == 1)
		{
		PnS.showControl(1);	
		Arp.showControl(0);	
		for(s in OscStuff)
		s.showControl(0);
		}
};

Content.getComponent("Presets").setControlCallback(onPresetsControl);


inline function onArpPanelControl(component, value)
{
		if(value == 0)
	{
	Arp.showControl(0);	
	}
	if(value == 1)
		{
    	PnS.showControl(0);	
		Arp.showControl(1);	
		for(s in OscStuff)
		s.showControl(0);
		}
};

Content.getComponent("ArpPanel").setControlCallback(onArpPanelControl);


inline function onOscPanelControl(component, value)
{

		if(value == 0)
	{
  	  	  for(s in OscStuff)
	  	  	  	 s.showControl(0); 
	}
	if(value == 1)
		{
	  	  	  PnS.showControl(0);	
	  	  	  		Arp.showControl(0);	
	  	  	  for(s in OscStuff)
	  	  	  	 s.showControl(1); 
		}
};

Content.getComponent("OscPanel").setControlCallback(onOscPanelControl);

const var TransformLabel1 = Content.getComponent("TransformLabel1");
const var TransformLabel2 = Content.getComponent("TransformLabel2");



inline function onShapeModSource12Control(component, value)
{
	
	Shaper.setAttribute(Shaper.AdjustMode, value);

		if(value == 1)
	{
		TransformLabel1.setValue("fold");
		TransformLabel2.setValue("smooth");
	}
	
	if(value == 2)
	{
		TransformLabel1.setValue("multi");
		TransformLabel2.setValue("smooth");
	}
	
		if(value == 3)
	{		
		TransformLabel1.setValue("clip");
		TransformLabel2.setValue("smooth");
	}

	if(value == 4)
	{
		TransformLabel1.setValue("freq.");
		TransformLabel2.setValue("resonance");
	}
	
		if(value == 5)
	{		
		TransformLabel1.setValue("freq");
		TransformLabel2.setValue("resonance");
	}

	if(value == 6)
	{
		TransformLabel1.setValue("freq.");
		TransformLabel2.setValue("resonance");
	}
	
		if(value == 7)
	{		
		TransformLabel1.setValue("freq");
		TransformLabel2.setValue("resonance");
	}
	if(value == 8)
	{
		TransformLabel1.setValue("divide");
		TransformLabel2.setValue("Smooth");
	}
	
	if(value == 9)
	{		
		TransformLabel1.setValue("freq");
		TransformLabel2.setValue("mod");
	}
	
	if(value == 10)
	{
		TransformLabel1.setValue("tempo");
		TransformLabel2.setValue("divide");
	}
	
	if(value == 11)
	{		
		TransformLabel1.setValue("bit depth");
		TransformLabel2.setValue("smooth");
	}

};

Content.getComponent("ShapeModSource12").setControlCallback(onShapeModSource12Control);

const var LoopAHD = [Content.getComponent("LpA"),
                     Content.getComponent("LpD")];
                     
const var LoopAHDSync = [Content.getComponent("LpDiv"),
                         Content.getComponent("LpA1"),
                         Content.getComponent("Amp AHDSR23"),
                         Content.getComponent("LpD1")];




inline function onEnSyncControl(component, value)
{
  
	  	  if(value == 0)
	  	  	 {
	  	  
	  	  	  for(s in LoopAHD)
	  	  	 s.showControl(1); 
	  	  	 
	  	  	 for(s in LoopAHDSync)
	  	  	 s.showControl(0); 
	  	  	 
	  	  	 Shaper.setAttribute(Shaper.Env2Sync, 0);	       
	  	  
	  	  	  }
	  	  	  
	  	
	  		  	  if(value == 1)
	  		  	  	 {
	  		  	  
	  		  	  	  for(s in LoopAHD)
	  		  	  	 s.showControl(0); 
	  		  	  	 
	  		  	  	 for(s in LoopAHDSync)
	  		  	  	 s.showControl(1); 
	  		  	  	 
	  		  	  	 Shaper.setAttribute(Shaper.Env2Sync, 1);	       
	  		  	  
	  		  	  	  }  	  
};

Content.getComponent("EnSync").setControlCallback(onEnSyncControl);


const var Mix = Content.getComponent("Mix");
const var AMPEnv = Content.getComponent("AMP Env");

inline function onRoutingControl(component, value)
{

	  		  	  if(value == 0)
	  		  	  	 {
	  		 Mix.showControl(0);
	  		 AMPEnv.showControl(1);
	  		 }	  
	  		 
	  		 if(value == 1)
	  		 		  	  	 {
	  		 Mix.showControl(1);
	  		 AMPEnv.showControl(0);
	  		 		 }	  
};

Content.getComponent("Routing").setControlCallback(onRoutingControl);


inline function onOscShapeControl(component, value)
{
	Shaper.setAttribute(Shaper.ModPostSwitch, value);
		  		  	 
		  		  	  if(value == 5)
		  		  	  	 {
	Shaper.setAttribute(Shaper.ModPostSwitch, 2);
		  		 }	  


};

Content.getComponent("OscShape").setControlCallback(onOscShapeControl);

const var ModoscExtra = Content.getComponent("ModoscExtra");


inline function onSubPageControl(component, value)
{
	ModoscExtra.showControl(value);
};

Content.getComponent("SubPage").setControlCallback(onSubPageControl);

const var ExpLink = Content.getComponent("ExpLink");

ExpLink.setMouseCallback(function(event)
{
  if (event.clicked)
  {
    Engine.openWebsite("https://modularsamples.gumroad.com/l/lgzxw");
  } 
  else 
  {
 //   link_hover = event.hover;
    this.repaint();
  }
});





function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 