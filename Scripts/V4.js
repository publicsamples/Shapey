//Voice 4

//Mod Panels

const var Osc4Mods =[];

for (i = 0; i < 5; i++)
{
    Osc4Mods[i] = Content.getComponent("OsModRouteD"+(i+1));

} 

inline function onOscModRoutPage4Control(component, value)
{
  for (i = 0; i < Osc4Mods.length; i++)
        Osc4Mods[i].showControl(value - 1 == i);
};

Content.getComponent("OscModRoutPage4").setControlCallback(onOscModRoutPage4Control);

const var File4Mods =[];

for (i = 0; i < 9; i++)
{
    File4Mods[i] = Content.getComponent("flModRouteD"+(i+1));

} 

const var ModLabels4 = [Content.getComponent("FileModLabel4"),
                        Content.getComponent("ModLabelsFile4")];

         

inline function onfileModRoutPage4Control(component, value)
{
 for (i = 0; i < File4Mods.length; i++)
        File4Mods[i].showControl(value - 1 == i);
        
        
        if (value == 1){
               	 for(s in ModLabels4)
                      s.showControl(0);
               	}
                 else {
               	   for(s in ModLabels4)
                      s.showControl(1); 
                 }
};

Content.getComponent("fileModRoutPage4").setControlCallback(onfileModRoutPage4Control);

const var Filter4Mods =[];

for (i = 0; i < 5; i++)
{
    Filter4Mods[i] = Content.getComponent("fModRouteD"+(i+1));

} 

inline function onFlModRoutPage4Control(component, value)
{
	 for (i = 0; i < Filter4Mods.length; i++)
        Filter4Mods[i].showControl(value - 1 == i);
};

Content.getComponent("FlModRoutPage4").setControlCallback(onFlModRoutPage4Control);



const var ShapePanel4 = Content.getComponent("ShapePanel4");
 
 inline function onShowUserTable4Control(component, value)
 {
 	ShapePanel4.showControl(value);
 };
 
 Content.getComponent("ShowUserTable4").setControlCallback(onShowUserTable4Control);
 
 
 //Pitch Mode Menu
 
 const var Semitones4 = [Content.getComponent("Pitch4"),
                         Content.getComponent("Step4")];
 
const var Harmonic4 = [Content.getComponent("Harm4"),
                       Content.getComponent("HarmStep4")];

const var Tempo4 = [Content.getComponent("Tempo4"),
                    Content.getComponent("Div4")];

 inline function onPitchMode4Control(component, value)
 {
	
f1.setAttribute(Osc1.pitchmode, value);           

 if (value == 1){
	 
 for(s in Semitones4)
       s.showControl(1);
 for(s in Harmonic4)
       s.showControl(0);    
 for(s in Tempo4)
       s.showControl(0);    
        
       }
   if (value == 4){
    	 
 for(s in Semitones4)
      s.showControl(0);
 for(s in Harmonic4)
       s.showControl(1);    
 for(s in Tempo4)
       s.showControl(0); 
               
          }   
   if (value == 4){
      	 
  for(s in Semitones4)
            s.showControl(0); 
   for(s in Harmonic4)
         s.showControl(0);    
   for(s in Tempo4)
         s.showControl(1);           
              
       }
   if (value == 4){
      	 
     for(s in Semitones4)
            s.showControl(0); 
   for(s in Harmonic4)
         s.showControl(0);    
   for(s in Tempo4)
         s.showControl(1);           
              
       }    
       
  
 };
 
 Content.getComponent("PitchMode4").setControlCallback(onPitchMode4Control);
