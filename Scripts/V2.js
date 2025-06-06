//Voice 2

//Mod Panels

const var Osc2Mods =[];

for (i = 0; i < 5; i++)
{
    Osc2Mods[i] = Content.getComponent("OsModRouteB"+(i+1));

} 

inline function onOscModRoutPage2Control(component, value)
{
  for (i = 0; i < Osc2Mods.length; i++)
        Osc2Mods[i].showControl(value - 1 == i);
};

Content.getComponent("OscModRoutPage2").setControlCallback(onOscModRoutPage2Control);

const var File2Mods =[];

for (i = 0; i < 9; i++)
{
    File2Mods[i] = Content.getComponent("flModRouteB"+(i+1));

} 

const var ModLabels2 = [Content.getComponent("FileModLabel2"),
                        Content.getComponent("ModLabelsFile2")];

         
inline function onfileModRoutPage2Control(component, value)
{
 for (i = 0; i < File2Mods.length; i++)
        File2Mods[i].showControl(value - 1 == i);
        
        if (value == 1){
        	 for(s in ModLabels2)
               s.showControl(0);
        	}
          else {
        	   for(s in ModLabels2)
               s.showControl(1); 
          }
};

Content.getComponent("fileModRoutPage2").setControlCallback(onfileModRoutPage2Control);

const var Filter2Mods =[];

for (i = 0; i < 5; i++)
{
    Filter2Mods[i] = Content.getComponent("fModRouteB"+(i+1));

} 

inline function onFlModRoutPage2Control(component, value)
{
	 for (i = 0; i < Filter2Mods.length; i++)
        Filter2Mods[i].showControl(value - 1 == i);
};

Content.getComponent("FlModRoutPage2").setControlCallback(onFlModRoutPage2Control);



const var ShapePanel2 = Content.getComponent("ShapePanel2");
 
 inline function onShowUserTable2Control(component, value)
 {
 	ShapePanel2.showControl(value);
 };
 
 Content.getComponent("ShowUserTable2").setControlCallback(onShowUserTable2Control);
 
 
 //Pitch Mode Menu
 
 const var Semitones2 = [Content.getComponent("Pitch2"),
                         Content.getComponent("Step2")];
 
const var Harmonic2 = [Content.getComponent("Harm2"),
                       Content.getComponent("HarmStep2")];

const var Tempo2 = [Content.getComponent("Tempo2"),
                    Content.getComponent("Div2")];

 inline function onPitchMode3Control(component, value)
 {
	
Osc2.setAttribute(Osc2.pitchmode, value);           

 if (value == 1){
	 
 for(s in Semitones2)
       s.showControl(1);
 for(s in Harmonic2)
       s.showControl(0);    
 for(s in Tempo2)
       s.showControl(0);    
        
       }
   if (value == 2){
    	 
 for(s in Semitones2)
      s.showControl(0);
 for(s in Harmonic2)
       s.showControl(1);    
 for(s in Tempo2)
       s.showControl(0); 
               
          }   
   if (value == 3){
      	 
  for(s in Semitones2)
            s.showControl(0); 
   for(s in Harmonic2)
         s.showControl(0);    
   for(s in Tempo2)
         s.showControl(1);           
              
       }
   if (value == 4){
      	 
     for(s in Semitones2)
            s.showControl(0); 
   for(s in Harmonic2)
         s.showControl(0);    
   for(s in Tempo2)
         s.showControl(1);           
              
       }    
       
  
 };
 
 Content.getComponent("PitchMode3").setControlCallback(onPitchMode3Control);
 
const var PosTable2 = Content.getComponent("PosTable2");
const var PosSp2 = Content.getComponent("PosSp2");

 
 inline function onPosModMode2Control(component, value)
 {
 	PosTable2.showControl(value-1);
 	PosSp2.showControl(value);
 	
 //	f2.setAttribute(f2.tablestep, value);
 };
 
 Content.getComponent("PosModMode2").setControlCallback(onPosModMode2Control);
 


 