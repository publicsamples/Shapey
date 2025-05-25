//Voice 3

//Mod Panels

const var Osc3Mods =[];

for (i = 0; i < 5; i++)
{
    Osc3Mods[i] = Content.getComponent("OsModRoute"+(i+10));

} 

inline function onOscModRoutPage3Control(component, value)
{
  for (i = 0; i < Osc3Mods.length; i++)
        Osc3Mods[i].showControl(value - 1 == i);
};

Content.getComponent("OscModRoutPage3").setControlCallback(onOscModRoutPage3Control);

const var File3Mods =[];

for (i = 0; i < 6; i++)
{
    File3Mods[i] = Content.getComponent("flModRouteA"+(i+13));

} 


inline function onfileModRoutPage3Control(component, value)
{
 for (i = 0; i < File3Mods.length; i++)
        File3Mods[i].showControl(value - 1 == i);
};

Content.getComponent("fileModRoutPage3").setControlCallback(onfileModRoutPage3Control);

const var Filter3Mods =[];

for (i = 0; i < 3; i++)
{
    Filter3Mods[i] = Content.getComponent("fModRouteA"+(i+8));

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
 
 
 
 
const var WinUnsync3 = [Content.getComponent("FileWin3"),
                       Content.getComponent("FileXf3")];

const var WinSync3 = [Content.getComponent("FileXfTempo3"),
                     Content.getComponent("FileWinTempo3")];
                                    

inline function onWinSync3Control(component, value)
{
		 
	 if (value == 0){
	
		 for(s in WinUnsync3)
		         s.showControl(1);  
		         
		 for(s in WinSync3)
		 		 s.showControl(0);           
	 
		 Files1.setAttribute(Files1.WinSync, 0);
		 }
		 
	
		 if (value == 1){
		
			 for(s in WinUnsync3)
			         s.showControl(0);  
			         
			 for(s in WinSync3)
			 		 s.showControl(1);           
		 
			 Files1.setAttribute(Files1.WinSync, 1);
			 }	 
};

Content.getComponent("WinSync3").setControlCallback(onWinSync3Control);

const var CutLabel7 = Content.getComponent("CutLabel7");
const var CutLabel8 = Content.getComponent("CutLabel8");
const var CutLabel9 = Content.getComponent("CutLabel9");


inline function onFilterType3Control(component, value)
{
	Filter1.setAttribute(Filter1.type, value);

	if (value == 1){
		CutLabel4.setValue("Low Pass");
		CutLabel5.setValue("High Pass");
		CutLabel6.setValue("Serial/ Paralel");
	}
	
	if (value == 3){
			CutLabel4.setValue("Low Shelf");
			CutLabel5.setValue("High Shelf");
			CutLabel6.setValue("Serial/ Paralel");
		}
		
	
	if (value == 3){
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

Content.getComponent("FilterType3").setControlCallback(onFilterType3Control);

const var PosTable3 = Content.getComponent("PosTable3");
const var PosSp3 = Content.getComponent("PosSp3");

 
 inline function onPosModMode3Control(component, value)
 {
 	PosTable3.showControl(value-1);
 	PosSp3.showControl(value);
 	
 	f3.setAttribute(f3.tablestep, value);
 };
 
 Content.getComponent("PosModMode3").setControlCallback(onPosModMode3Control);
 
 
 