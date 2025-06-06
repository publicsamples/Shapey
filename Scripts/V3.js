//Voice 3

//Mod Panels

const var Osc3Mods =[];

for (i = 0; i < 5; i++)
{
    Osc3Mods[i] = Content.getComponent("OsModRouteC"+(i+1));

} 

inline function onOscModRoutPage3Control(component, value)
{
  for (i = 0; i < Osc3Mods.length; i++)
        Osc3Mods[i].showControl(value - 1 == i);
};

Content.getComponent("OscModRoutPage3").setControlCallback(onOscModRoutPage3Control);

const var File3Mods =[];

for (i = 0; i < 9; i++)
{
    File3Mods[i] = Content.getComponent("flModRouteC"+(i+1));

} 

const var ModLabels3 = [Content.getComponent("FileModLabel3"),
                        Content.getComponent("ModLabelsFile3")];


inline function onfileModRoutPage3Control(component, value)
{
 for (i = 0; i < File3Mods.length; i++)
        File3Mods[i].showControl(value - 1 == i);
        
        
        if (value == 1){
        	 for(s in ModLabels3)
               s.showControl(0);
        	}
          else {
        	   for(s in ModLabels3)
               s.showControl(1); 
          }
};

Content.getComponent("fileModRoutPage3").setControlCallback(onfileModRoutPage3Control);

const var Filter3Mods =[];

for (i = 0; i < 5; i++)
{
    Filter3Mods[i] = Content.getComponent("fModRouteC"+(i+1));

} 

inline function onFlModRoutPage3Control(component, value)
{
	 for (i = 0; i < Filter3Mods.length; i++)
        Filter3Mods[i].showControl(value - 1 == i);
};

Content.getComponent("FlModRoutPage3").setControlCallback(onFlModRoutPage3Control);



const var ShapePanel3 = Content.getComponent("ShapePanel3");
 
 inline function onShowUserTable3Control(component, value)
 {
 	ShapePanel3.showControl(value);
 };
 
 Content.getComponent("ShowUserTable3").setControlCallback(onShowUserTable3Control);
 
 
 //Pitch Mode Menu
 const var Osc3 = Synth.getEffect("Osc3");
 
 const var Semitones3 = [Content.getComponent("Pitch3"),
                         Content.getComponent("Step3")];
 
const var Harmonic3 = [Content.getComponent("Harm3"),
                       Content.getComponent("HarmStep3")];

const var Tempo3 = [Content.getComponent("Tempo3"),
                    Content.getComponent("Div3")];

 inline function onPitchMode3Control(component, value)
 {
	
Osc3.setAttribute(Osc3.pitchmode, value);           

 if (value == 1){
	 
 for(s in Semitones3)
       s.showControl(1);
 for(s in Harmonic3)
       s.showControl(0);    
 for(s in Tempo3)
       s.showControl(0);    
        
       }
   if (value == 3){
    	 
 for(s in Semitones3)
      s.showControl(0);
 for(s in Harmonic3)
       s.showControl(1);    
 for(s in Tempo3)
       s.showControl(0); 
               
          }   
   if (value == 3){
      	 
  for(s in Semitones3)
            s.showControl(0); 
   for(s in Harmonic3)
         s.showControl(0);    
   for(s in Tempo3)
         s.showControl(1);           
              
       }
   if (value == 4){
      	 
     for(s in Semitones3)
            s.showControl(0); 
   for(s in Harmonic3)
         s.showControl(0);    
   for(s in Tempo3)
         s.showControl(1);           
              
       }    
       
  
 };
 
 Content.getComponent("PitchMode3").setControlCallback(onPitchMode3Control);
 

 
 