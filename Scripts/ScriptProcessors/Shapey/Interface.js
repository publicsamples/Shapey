Content.makeFrontInterface(820, 600);

include("laf.js");
include("Scopes.js");
include("Loading.js");

//Impulse panel


const var Imp = Content.getComponent("Imp");


inline function onIrControl(component, value)
{
	if(value == 0)
	{	 	    
		 Imp.showControl(0);

	}	
if(value == 1)
	{	 	    
		 Imp.showControl(1);
	
	}	
};

Content.getComponent("Ir").setControlCallback(onIrControl);

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

Content.getComponent("PitchSync").setControlCallback(onPitchSyncControl);

//carrier menu

const var ModMultiSample = [Content.getComponent("OscVisual")];



const var OsShape = Content.getComponent("Os Shape");
const var ModWaveLoad = [Content.getComponent("ModPos"),
                   Content.getComponent("FolderSelect1"),
                   Content.getComponent("ModLoadWave1"), 
                   Content.getComponent("ScriptAudioWaveform1"),                 
                   Content.getComponent("SelFolderLabel")];


inline function onModulatorModeControl(component, value)
{
	Shaper.setAttribute(Shaper.InputMode, value);

	if(value == 0)
	{
	for(s in ModMultiSample)
		       s.showControl(1);
		      
//	OsShape.showControl(1);
		      
		for(s in ModWaveLoad)
	 s.showControl(0);	
	

	 
   
	}	  
	
	if(value == 1)
	{
	for(s in ModMultiSample)
		       s.showControl(0);
		      
	OsShape.showControl(1);
		       
		for(s in ModWaveLoad)
		       	 s.showControl(1);	   
		       
	}
		    

};

Content.getComponent("ModulatorMode").setControlCallback(onModulatorModeControl);




inline function onBankADisplayControl(component, value)
{


  Sampler1.loadSampleMap(value);


};


const var CarMultis = [Content.getComponent("BankB"),
                       
                       Content.getComponent("Categories2")];

const var CarWav = [Content.getComponent("FolderSelect"),
                    Content.getComponent("LpLoad2")];

const var Panel3 = Content.getComponent("Panel3");


inline function onCarModeControl(component, value)
{
	
	Shaper.setAttribute(Shaper.OutMode, value);	       

	if(value == 0)
	{
	Panel3.showControl(1); 
	for(s in CarMultis)
		       s.showControl(0);       
		       
	for(s in CarWav)
		       s.showControl(1);   
	

    	       
	      } 
	if(value == 1)
	{
	
	for(s in CarMultis)
		       s.showControl(0);       
		       
	for(s in CarWav)
		       s.showControl(1);   
	
	Panel3.showControl(0);    
	}
};

Content.getComponent("CarMode").setControlCallback(onCarModeControl);

const var MODEnv1 = Content.getComponent("MOD Env1");
const var MODEnv2 = Content.getComponent("MOD Env2");

const var LFO12 = [Content.getComponent("LFO1"),
                   Content.getComponent("LFO2")];

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
 