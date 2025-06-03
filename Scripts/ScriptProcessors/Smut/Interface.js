Content.makeFrontInterface(900, 890);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "mon");
//Engine.setMaximumBlockSize(64);

include("laf.js");
include("KnobLAF1.js");
include("KnobLAF2.js");
include("KnobLAF3.js");
include("KnobLAF4.js");
include("Rect.js");
include("Scopes.js");
include("Loading.js");

include("V1.js");
include("V2.js");
include("V3.js");
include("V4.js");


const var Poly = [Content.getComponent("Voices4"),
                  Content.getComponent("Voices3"),
                  Content.getComponent("Voices2"),
                  Content.getComponent("Voices1")];

const var v1 = Synth.getChildSynth("Synthesiser Group1");
const var v2 = Synth.getChildSynth("Synthesiser Group2");
const var v3 = Synth.getChildSynth("Synthesiser Group3");
const var v4 = Synth.getChildSynth("Synthesiser Group4");

const var f1 = Synth.getEffect("Files1");
const var f2 = Synth.getEffect("Files2");
const var f3 = Synth.getEffect("Files3");
const var f4 = Synth.getEffect("Files4");

const var Filter1 = Synth.getEffect("Filter1");
const var Filter2 = Synth.getEffect("Filter2");
const var Filter3 = Synth.getEffect("Filter3");
const var Filter4 = Synth.getEffect("Filter4");

//Voice Menu

inline function onVoiceModeControl(component, value)
{
	 if (value == 1){
	 
	 for(s in Poly)
	           s.setValue(16); 	
	 for(s in Poly)	
	           s.changed();  
	           
      
	           
     v1.setBypassed(0);
     v2.setBypassed(1);   
     v3.setBypassed(1);   
     v4.setBypassed(1);                      
	           
	}
	
	if (value == 2){
		 
		 
		 for(s in Poly)
		           s.setValue(16); 	
		 for(s in Poly)	
		           s.changed(); 
		           
	v1.setBypassed(0);
	   v2.setBypassed(0);   
	   v3.setBypassed(1);   
	   v4.setBypassed(1); 	                      
		           
		}
	if (value == 3){
		 		 
		 for(s in Poly)
		           s.setValue(4); 	
		 for(s in Poly)	
		           s.changed(); 
		           
	v1.setBypassed(0);
	   v2.setBypassed(0);   
	   v3.setBypassed(0);   
	   v4.setBypassed(0); 	           
		}            
		           
	if (value == 4){
		

	
		 
		 for(s in Poly)
		           s.setValue(1); 	
		 for(s in Poly)	
		           s.changed();  
		           
	v1.setBypassed(0);
	   v2.setBypassed(0);   
	   v3.setBypassed(0);   
	   v4.setBypassed(0); 		                                              
		           
		}	 
	if (value == 5){
		 
		 for(s in Poly)
		           s.setValue(1); 	
		 for(s in Poly)	
		           s.changed();  

	v1.setBypassed(0);
	   v2.setBypassed(0);   
	   v3.setBypassed(0);   
	   v4.setBypassed(0); 		           
		                                              
		           
		}		 
	 
};

Content.getComponent("VoiceMode").setControlCallback(onVoiceModeControl);

//Voice Pages

const var VoiceMode1 = Content.getComponent("VoiceMode1");

const var VoicePages =[];

for (i = 0; i < 4; i++)
{
    VoicePages[i] = Content.getComponent("Voice"+(i+1));
}

const var SeqPages =[];

for (i = 0; i < 4; i++)
{
    SeqPages[i] = Content.getComponent("Seq"+(i+1));
}

const var FilePages =[];

for (i = 0; i < 4; i++)
{
    FilePages[i] = Content.getComponent("File"+(i+1));
}

inline function onVoiceMode1Control(component, value)
{
	 for (i = 0; i < VoicePages.length; i++)
        VoicePages[i].showControl(value - 1 == i);
        
  //   for (i = 0; i < SeqPages.length; i++)
  //          SeqPages[i].showControl(value - 1 == i);
            
      for (i = 0; i < FilePages.length; i++)
             FilePages[i].showControl(value - 1 == i);         
};

Content.getComponent("VoiceMode1").setControlCallback(onVoiceMode1Control);



Synth.setUseUniformVoiceHandler("Smut", true);

const var rm = Engine.getGlobalRoutingManager();

const var Files = Content.getComponent("Files");



/// MOD

const var ModPages =[];

ModPages[0] = Content.getComponent("lfo1");
ModPages[1] = Content.getComponent("lfo2");
ModPages[2] = Content.getComponent("lfo3");
ModPages[3] = Content.getComponent("lfo4");
ModPages[4] = Content.getComponent("Env1");
ModPages[5] = Content.getComponent("Env2");
ModPages[6] = Content.getComponent("Xfade");


inline function onModSelectControl(component, value)
{
	  for (i = 0; i < ModPages.length; i++)
        ModPages[i].showControl(value - 1 == i);
};

Content.getComponent("ModSelect").setControlCallback(onModSelectControl);



//LFO1

const var LFO1 = Synth.getEffect("LFO1");

const var LfoShpPanel1 = Content.getComponent("LfoShapeVis1");
const var LfoTable1 = Content.getComponent("LfoTable1");
const var LfoSliderPack1 = Content.getComponent("LfoSliderPack1");
const var MiniVis1 = Content.getComponent("MiniVis1");


inline function onLfoShape1Control(component, value)
{
	
	LFO1.setAttribute(LFO1.Shape, value);

	if (value == 1){
	
		LfoShpPanel1.showControl(1);
		LfoTable1.showControl(0);
		LfoSliderPack1.showControl(0);
		MiniVis1.showControl(0);

	}
	if (value == 2){

		LfoShpPanel1.showControl(1);
		LfoTable1.showControl(0);
		LfoSliderPack1.showControl(0);
		MiniVis1.showControl(0);
        }
        
      if (value == 3){
      
      	LfoShpPanel1.showControl(1);
      	LfoTable1.showControl(0);
      	LfoSliderPack1.showControl(0);
      	MiniVis1.showControl(0);
              }
    
    if (value == 4){

    	LfoShpPanel1.showControl(1);
    	LfoTable1.showControl(0);
    	LfoSliderPack1.showControl(0);
    	MiniVis1.showControl(0);
            }          
 
		if (value == 5){
		

			LfoShpPanel1.showControl(1);
			LfoTable1.showControl(0);
			LfoSliderPack1.showControl(0);
			MiniVis1.showControl(0);
		        }
		        
	if (value == 6){
	

		LfoShpPanel1.showControl(0);
		LfoTable1.showControl(1);
		LfoSliderPack1.showControl(0);
		MiniVis1.showControl(1);
	        }	        
	 
	 	if (value == 7){

	 		LfoShpPanel1.showControl(0);
	 		LfoTable1.showControl(0);
	 		LfoSliderPack1.showControl(1);
	 		MiniVis1.showControl(1);
	 	        }	        
	 	     
     
};

Content.getComponent("LfoShape1").setControlCallback(onLfoShape1Control);

//LFO2

const var LFO2 = Synth.getEffect("LFO2");

const var LfoShpPanel2 = Content.getComponent("LfoShapeVis2");
const var LfoTable2 = Content.getComponent("LfoTable2");
const var LfoSliderPack2 = Content.getComponent("LfoSliderPack2");
const var MiniVis2 = Content.getComponent("MiniVis2");


inline function onLfoShape2Control(component, value)
{
	
	LFO2.setAttribute(LFO2.Shape, value);

	if (value == 1){
	
		LfoShpPanel2.showControl(1);
		LfoTable2.showControl(0);
		LfoSliderPack2.showControl(0);
		MiniVis2.showControl(0);

	}
	if (value == 2){

		LfoShpPanel2.showControl(1);
		LfoTable2.showControl(0);
		LfoSliderPack2.showControl(0);
		MiniVis2.showControl(0);
        }
        
      if (value == 3){
      
      	LfoShpPanel2.showControl(1);
      	LfoTable2.showControl(0);
      	LfoSliderPack2.showControl(0);
      	MiniVis2.showControl(0);
              }
    
    if (value == 4){

    	LfoShpPanel2.showControl(1);
    	LfoTable2.showControl(0);
    	LfoSliderPack2.showControl(0);
    	MiniVis2.showControl(0);
            }          
 
		if (value == 5){
		

			LfoShpPanel2.showControl(1);
			LfoTable2.showControl(0);
			LfoSliderPack2.showControl(0);
			MiniVis2.showControl(0);
		        }
		        
	if (value == 6){
	

		LfoShpPanel2.showControl(0);
		LfoTable2.showControl(1);
		LfoSliderPack2.showControl(0);
		MiniVis2.showControl(1);
	        }	        
	 
	 	if (value == 7){

	 		LfoShpPanel2.showControl(0);
	 		LfoTable2.showControl(0);
	 		LfoSliderPack2.showControl(1);
	 		MiniVis2.showControl(1);
	 	        }	        
	 	     
     
};

Content.getComponent("LfoShape2").setControlCallback(onLfoShape2Control);

//LFO3

const var LFO3 = Synth.getEffect("LFO3");

const var LfoShpPanel3 = Content.getComponent("LfoShapeVis3");
const var LfoTable3 = Content.getComponent("LfoTable3");
const var LfoSliderPack3 = Content.getComponent("LfoSliderPack3");
const var MiniVis3 = Content.getComponent("MiniVis3");


inline function onLfoShape3Control(component, value)
{
	
	LFO3.setAttribute(LFO3.Shape, value);

	if (value == 1){
	
		LfoShpPanel3.showControl(1);
		LfoTable3.showControl(0);
		LfoSliderPack3.showControl(0);
		MiniVis3.showControl(0);

	}
	if (value == 2){

		LfoShpPanel3.showControl(1);
		LfoTable3.showControl(0);
		LfoSliderPack3.showControl(0);
		MiniVis3.showControl(0);
        }
        
      if (value == 3){
      
      	LfoShpPanel3.showControl(1);
      	LfoTable3.showControl(0);
      	LfoSliderPack3.showControl(0);
      	MiniVis3.showControl(0);
              }
    
    if (value == 4){

    	LfoShpPanel3.showControl(1);
    	LfoTable3.showControl(0);
    	LfoSliderPack3.showControl(0);
    	MiniVis3.showControl(0);
            }          
 
		if (value == 5){
		

			LfoShpPanel3.showControl(1);
			LfoTable3.showControl(0);
			LfoSliderPack3.showControl(0);
			MiniVis3.showControl(0);
		        }
		        
	if (value == 6){
	

		LfoShpPanel3.showControl(0);
		LfoTable3.showControl(1);
		LfoSliderPack3.showControl(0);
		MiniVis3.showControl(1);
	        }	        
	 
	 	if (value == 7){

	 		LfoShpPanel3.showControl(0);
	 		LfoTable3.showControl(0);
	 		LfoSliderPack3.showControl(1);
	 		MiniVis3.showControl(1);
	 	        }	        
	 	     
     
};

Content.getComponent("LfoShape3").setControlCallback(onLfoShape3Control);

//LFO4

const var LFO4 = Synth.getEffect("LFO4");

const var LfoShpPanel4 = Content.getComponent("LfoShapeVis4");
const var LfoTable4 = Content.getComponent("LfoTable4");
const var LfoSliderPack4 = Content.getComponent("LfoSliderPack4");
const var MiniVis4 = Content.getComponent("MiniVis4");


inline function onLfoShape4Control(component, value)
{
	
	LFO4.setAttribute(LFO4.Shape, value);

	if (value == 1){
	
		LfoShpPanel4.showControl(1);
		LfoTable4.showControl(0);
		LfoSliderPack4.showControl(0);
		MiniVis4.showControl(0);

	}
	if (value == 2){

		LfoShpPanel4.showControl(1);
		LfoTable4.showControl(0);
		LfoSliderPack4.showControl(0);
		MiniVis4.showControl(0);
        }
        
      if (value == 3){
      
      	LfoShpPanel4.showControl(1);
      	LfoTable4.showControl(0);
      	LfoSliderPack4.showControl(0);
      	MiniVis4.showControl(0);
              }
    
    if (value == 4){

    	LfoShpPanel4.showControl(1);
    	LfoTable4.showControl(0);
    	LfoSliderPack4.showControl(0);
    	MiniVis4.showControl(0);
            }          
 
		if (value == 5){
		

			LfoShpPanel4.showControl(1);
			LfoTable4.showControl(0);
			LfoSliderPack4.showControl(0);
			MiniVis4.showControl(0);
		        }
		        
	if (value == 6){
	

		LfoShpPanel4.showControl(0);
		LfoTable4.showControl(1);
		LfoSliderPack4.showControl(0);
		MiniVis4.showControl(1);
	        }	        
	 
	 	if (value == 7){

	 		LfoShpPanel4.showControl(0);
	 		LfoTable4.showControl(0);
	 		LfoSliderPack4.showControl(1);
	 		MiniVis4.showControl(1);
	 	        }	        
	 	     
     
};

Content.getComponent("LfoShape4").setControlCallback(onLfoShape4Control);



//env

const var LfoPanels4 =[];

LfoPanels4[0] = Content.getComponent("LfoShapeVis4");
LfoPanels4[1] = Content.getComponent("EnvPanel1");
LfoPanels4[2] = Content.getComponent("LfoTable4");
LfoPanels4[3] = Content.getComponent("LfoSliderPack4");
LfoPanels4[4] = Content.getComponent("AdjVis4");

const var Env1 = Synth.getModulator("Env1");

inline function onLfoShape4Control(component, value)
{
	
	Env1.setAttribute(Env1.Shape, value);

		if (value == 1){
	
		LfoPanels4[0].showControl(0);
		LfoPanels4[1].showControl(1);
		LfoPanels4[2].showControl(0);
		LfoPanels4[3].showControl(0);
		LfoPanels4[4].showControl(1);

	}
	if (value == 2){
	
		LfoPanels4[0].showControl(1);
		LfoPanels4[1].showControl(0);
		LfoPanels4[2].showControl(0);
		LfoPanels4[3].showControl(0);
		LfoPanels4[4].showControl(0);
	
	}
	if (value == 3){
	
		LfoPanels4[0].showControl(1);
		LfoPanels4[1].showControl(0);
		LfoPanels4[2].showControl(0);
		LfoPanels4[3].showControl(0);
		LfoPanels4[4].showControl(0);
	
	}
	
	if (value == 4){
	
		LfoPanels4[0].showControl(1);
		LfoPanels4[1].showControl(0);
		LfoPanels4[2].showControl(0);
		LfoPanels4[3].showControl(0);
		LfoPanels4[4].showControl(0);
	
	}
	
	if (value == 5){
	
		LfoPanels4[0].showControl(0);
		LfoPanels4[1].showControl(0);
		LfoPanels4[2].showControl(1);
		LfoPanels4[3].showControl(0);
		LfoPanels4[4].showControl(1);
	
	}
	if (value == 6){
	
	LfoPanels4[0].showControl(0);
	LfoPanels4[1].showControl(0);
	LfoPanels4[2].showControl(0);
	LfoPanels4[3].showControl(1);
	LfoPanels4[4].showControl(1);
	
	        }
	        
	  
};

Content.getComponent("LfoShape4").setControlCallback(onLfoShape4Control);

const var PresetPanel = Content.getComponent("PresetPanel");


inline function onPresetsControl(component, value)
{
	PresetPanel.showControl(value-1);
};

Content.getComponent("Presets").setControlCallback(onPresetsControl);

const var cmbPresets = Content.getComponent("cmbPresets");
cmbPresets.setControlCallback(oncmbPresetsControl);

inline function oncmbPresetsControl(component, value)
{
	if (!value)
		return;

	local itemText = Engine.getUserPresetList()[value - 1];

	Console.print(itemText);
}

populatePresetsMenu();

inline function populatePresetsMenu()
{
	cmbPresets.set("items", "");

	for (x in Engine.getUserPresetList())
	{
		local arr = x.split("/");			
		local item = "";
		
		for (i = 0; i < arr.length; i++)
		{
			item += arr[i];
			
			if (i < arr.length - 1)
				item += "::";
		}

		cmbPresets.addItem(item);
	}
}

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
 