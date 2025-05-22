Content.makeFrontInterface(900, 900);

Engine.loadFontAs("{PROJECT_FOLDER}TabloidScuzzball.otf", "scuz");
Engine.loadFontAs("{PROJECT_FOLDER}Montserrat-Medium.ttf", "mon");
include("laf.js");
include("KnobLAF1.js");
include("KnobLAF2.js");
include("Rect.js");
include("Scopes.js");
//include("Loading.js");


const var Poly = [Content.getComponent("Voices4"),
                  Content.getComponent("Voices3"),
                  Content.getComponent("Voices2"),
                  Content.getComponent("Voices1")];

const var v1 = Synth.getChildSynth("v1");
const var v2 = Synth.getChildSynth("v2");
const var v3 = Synth.getChildSynth("v3");
const var v4 = Synth.getChildSynth("v4");

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


//mod page menus

Synth.setUseUniformVoiceHandler("Smut", true);

const var rm = Engine.getGlobalRoutingManager();

const var Osc1 = Synth.getEffect("Osc1");

const var Osc1Mods =[];

for (i = 0; i < 8; i++)
{
    Osc1Mods[i] = Content.getComponent("OsModRoute"+(i+1));

} 

inline function onOscModRoutPage1Control(component, value)
{
  for (i = 0; i < Osc1Mods.length; i++)
        Osc1Mods[i].showControl(value - 1 == i);
};

Content.getComponent("OscModRoutPage1").setControlCallback(onOscModRoutPage1Control);



const var File1Mods =[];

for (i = 0; i < 4; i++)
{
    File1Mods[i] = Content.getComponent("flModRouteA"+(i+1));

} 


inline function onfileModRoutPage1Control(component, value)
{
 for (i = 0; i < File1Mods.length; i++)
        File1Mods[i].showControl(value - 1 == i);
};

Content.getComponent("fileModRoutPage1").setControlCallback(onfileModRoutPage1Control);

const var Filter1Mods =[];

for (i = 0; i < 3; i++)
{
    Filter1Mods[i] = Content.getComponent("fModRouteA"+(i+1));

} 

inline function onFlModRoutPage1Control(component, value)
{
	 for (i = 0; i < Filter1Mods.length; i++)
        Filter1Mods[i].showControl(value - 1 == i);
};

Content.getComponent("FlModRoutPage1").setControlCallback(onFlModRoutPage1Control);



const var ShapePanel1 = Content.getComponent("ShapePanel1");
 
 inline function onShowUserTable1Control(component, value)
 {
 	ShapePanel1.showControl(value);
 };
 
 Content.getComponent("ShowUserTable1").setControlCallback(onShowUserTable1Control);
 
 
 //Pitch Mode Menu
 
 const var Semitones1 = [Content.getComponent("Pitch1"),
                         Content.getComponent("Step1")];
 
const var Harmonic1 = [Content.getComponent("Harm1"),
                       Content.getComponent("HarmStep1")];

const var Tempo1 = [Content.getComponent("Tempo1"),
                    Content.getComponent("Div1")];


 
 inline function onPitchMode1Control(component, value)
 {
	
Osc1.setAttribute(Osc1.pitchmode, value);           

 if (value == 1){
	 
 for(s in Semitones1)
       s.showControl(1);
 for(s in Harmonic1)
       s.showControl(0);    
 for(s in Tempo1)
       s.showControl(0);    
        
       }
   if (value == 2){
    	 
 for(s in Semitones1)
      s.showControl(0);
 for(s in Harmonic1)
       s.showControl(1);    
 for(s in Tempo1)
       s.showControl(0); 
               
          }   
   if (value == 3){
      	 
  for(s in Semitones1)
            s.showControl(0); 
   for(s in Harmonic1)
         s.showControl(0);    
   for(s in Tempo1)
         s.showControl(1);           
              
       }
   if (value == 4){
      	 
     for(s in Semitones1)
            s.showControl(0); 
   for(s in Harmonic1)
         s.showControl(0);    
   for(s in Tempo1)
         s.showControl(1);           
              
       }    
       
  
 };
 
 Content.getComponent("PitchMode1").setControlCallback(onPitchMode1Control);
 
 
 namespace MacroParameterHandling
 {
 
 // Use EXACTLY as many names as you define with HISE_NUM_MACROS in your extra definitions here
 Engine.setFrontendMacros(["Slot 1", "Slot 2", "Slot 3", "Slot 4"]);
 
 const var mh = Engine.createMacroHandler();
 
 // This command will make sure that you can't assign more than one parameter to a macro slot
 // (omit this if you want to keep this, but usually you want a 1:1 connection to plugin parameters)
 mh.setExclusiveMode(true);
 
 //Note that macro assignments are part of the user preset data model, so they will be 
 // restored correctly when loading a DAW session. However if you want to keep the 
 // macro assignments consistent across user preset browsing, you will have to implement 
 // this manually by saving and restoring the macro connection data
 const var uph = Engine.createUserPresetHandler();
 
 reg currentMacroConnections;
 
 // This will be executed before a preset is loaded
 uph.setPreCallback(function(presetData)
 {
 	// checks if the preset load is coming from a user trying to load a preset
 	// (as opposed to the DAW restoring the project session)
 	if(!uph.isInternalPresetLoad())
 	{
 		// Store the current macro connections as a JSON object.
 		currentMacroConnections = mh.getMacroDataObject();
 	}
 });
 
 // This will be executed after a preset load and will restore the macro connection objects
 // when the user loads a preset so they stay consistent across browsing presets.
 uph.setPostCallback(function(presetFile)
 {
 	if(!uph.isInternalPresetLoad() && isDefined(currentMacroConnections))
 	{
 		mh.setMacroDataFromObject(currentMacroConnections);
 	}
 });
 	
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
 