//Voice 4

//Mod Panels

const var Osc4Mods =[];

for (i = 0; i < 5; i++)
{
    Osc4Mods[i] = Content.getComponent("OsModRoute"+(i+15));

} 

inline function onOscModRoutPage4Control(component, value)
{
  for (i = 0; i < Osc4Mods.length; i++)
        Osc4Mods[i].showControl(value - 1 == i);
};

Content.getComponent("OscModRoutPage4").setControlCallback(onOscModRoutPage4Control);

const var File4Mods =[];

for (i = 0; i < 6; i++)
{
    File4Mods[i] = Content.getComponent("flModRouteA"+(i+18));

} 


inline function onfileModRoutPage4Control(component, value)
{
 for (i = 0; i < File4Mods.length; i++)
        File4Mods[i].showControl(value - 1 == i);
};

Content.getComponent("fileModRoutPage4").setControlCallback(onfileModRoutPage4Control);

const var Filter4Mods =[];

for (i = 0; i < 3; i++)
{
    Filter4Mods[i] = Content.getComponent("fModRouteA"+(i+10));

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
	
Osc4.setAttribute(Osc4.pitchmode, value);           

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
 
const var WinUnsync4 = [Content.getComponent("FileWin4"),
                       Content.getComponent("FileXf4")];

const var WinSync4 = [Content.getComponent("FileXfTempo4"),
                     Content.getComponent("FileWinTempo4")];
      
  const var Osc4 = Synth.getEffect("Osc4");   
 const var Files4 = Synth.getEffect("Files4");                              

inline function onWinSync4Control(component, value)
{
		 
	 if (value == 0){
	
		 for(s in WinUnsync4)
		         s.showControl(1);  
		         
		 for(s in WinSync4)
		 		 s.showControl(0);           
	 
		 Files4.setAttribute(Files4.WinSync, 0);
		 }
		 
	
		 if (value == 1){
		
			 for(s in WinUnsync4)
			         s.showControl(0);  
			         
			 for(s in WinSync4)
			 		 s.showControl(1);           
		 
			 Files4.setAttribute(Files4.WinSync, 1);
			 }	 
};

Content.getComponent("WinSync4").setControlCallback(onWinSync4Control);

const var CutLabel10 = Content.getComponent("CutLabel10");
const var CutLabel11 = Content.getComponent("CutLabel11");
const var CutLabel12 = Content.getComponent("CutLabel12");


inline function onFilterType4Control(component, value)
{
	Filter1.setAttribute(Filter1.type, value);

	if (value == 1){
		CutLabel4.setValue("Low Pass");
		CutLabel5.setValue("High Pass");
		CutLabel6.setValue("Serial/ Paralel");
	}
	
	if (value == 4){
			CutLabel4.setValue("Low Shelf");
			CutLabel5.setValue("High Shelf");
			CutLabel6.setValue("Serial/ Paralel");
		}
		
	
	if (value == 4){
		CutLabel4.setValue("Low Pass");
		CutLabel5.setValue("High Pass");
		CutLabel6.setValue("Serial/ Paralel");
		}	
		
	if (value == 4){
			CutLabel4.setValue("Comb Freq");
			CutLabel5.setValue("Low Pass");
			CutLabel6.setValue("FFWD/ Allpass");
			}		
	
};

Content.getComponent("FilterType4").setControlCallback(onFilterType4Control);

const var PosTable4 = Content.getComponent("PosTable4");
const var PosSp4 = Content.getComponent("PosSp4");

 
 inline function onPosModMode4Control(component, value)
 {
 	PosTable4.showControl(value-1);
 	PosSp4.showControl(value);
 	
 	f4.setAttribute(f4.tablestep, value);
 };
 
 Content.getComponent("PosModMode4").setControlCallback(onPosModMode4Control);
 

 