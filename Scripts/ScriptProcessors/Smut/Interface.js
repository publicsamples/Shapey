Content.makeFrontInterface(900, 890);

Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "mon");


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

const var v1 = Synth.getChildSynth("v1");
const var v2 = Synth.getChildSynth("v2");
const var v3 = Synth.getChildSynth("v3");
const var v4 = Synth.getChildSynth("v4");

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
	           s.setValue(32); 	
	 for(s in Poly)	
	           s.changed();  
	           
     v1.setBypassed(0);
     v2.setBypassed(1);   
     v3.setBypassed(1);   
     v4.setBypassed(1);                      
	           
	}
	
	if (value == 2){
		 
		 for(s in Poly)
		           s.setValue(8); 	
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
        
     for (i = 0; i < SeqPages.length; i++)
            SeqPages[i].showControl(value - 1 == i);
            
      for (i = 0; i < FilePages.length; i++)
             FilePages[i].showControl(value - 1 == i);         
};

Content.getComponent("VoiceMode1").setControlCallback(onVoiceMode1Control);



Synth.setUseUniformVoiceHandler("Smut", true);

const var rm = Engine.getGlobalRoutingManager();

const var Files = Content.getComponent("Files");


inline function onCloseFilesControl(component, value)
{
	 if (value == 1){
		 Files.showControl(0);
		 }
	 
};

Content.getComponent("CloseFiles").setControlCallback(onCloseFilesControl);


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
 