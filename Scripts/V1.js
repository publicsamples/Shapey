//Voice 1

//Mod Panels

const var Osc1 = Synth.getEffect("Osc1");

const var Osc1Mods =[];

for (i = 0; i < 5; i++)
{
    Osc1Mods[i] = Content.getComponent("OsModRouteA"+(i+1));

} 

inline function onOscModRoutPage1Control(component, value)
{
  for (i = 0; i < Osc1Mods.length; i++)
        Osc1Mods[i].showControl(value - 1 == i);
};

Content.getComponent("OscModRoutPage1").setControlCallback(onOscModRoutPage1Control);

const var File1Mods =[];

for (i = 0; i < 9; i++)
{
    File1Mods[i] = Content.getComponent("flModRouteA"+(i+1));

} 

const var ModLabels1 = [Content.getComponent("FileModLabel1"),
                        Content.getComponent("ModLabelsFile1")];
  
        
inline function onfileModRoutPage1Control(component, value)
{
 for (i = 0; i < File1Mods.length; i++)
        File1Mods[i].showControl(value - 1 == i);
   
   
   	if (value == 1){
   		 for(s in ModLabels1)
       s.showControl(0);
   		}
   	  else {
	   for(s in ModLabels1)
       s.showControl(1); 
   	  }   
        
};

Content.getComponent("fileModRoutPage1").setControlCallback(onfileModRoutPage1Control);

const var Filter1Mods =[];

for (i = 0; i < 5; i++)
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
 
 const var FilePanel = Content.getComponent("Files");
 
 
 
 

const var WinUnsync1 = [Content.getComponent("FileWin1"),
                       Content.getComponent("FileXf1")];

const var WinSync1 = [Content.getComponent("FileXfTempo1"),
                     Content.getComponent("FileWinTempo1")];
                  
const var Files1 = Synth.getEffect("Files1");                  

inline function onWinSync1Control(component, value)
{
		 
	 if (value == 0){
	
		 for(s in WinUnsync1)
		         s.showControl(1);  
		         
		 for(s in WinSync1)
		 		 s.showControl(0);           
	 
		 Files1.setAttribute(Files1.WinSync, 0);
		 }
		 
	
		 if (value == 1){
		
			 for(s in WinUnsync1)
			         s.showControl(0);  
			         
			 for(s in WinSync1)
			 		 s.showControl(1);           
		 
			 Files1.setAttribute(Files1.WinSync, 1);
			 }	 
};

Content.getComponent("WinSync1").setControlCallback(onWinSync1Control);


const var CutLabel1 = Content.getComponent("CutLabel1");
const var CutLabel2 = Content.getComponent("CutLabel2");
const var CutLabel9 = Content.getComponent("CutLabel9");


inline function onFilterType1Control(component, value)
{
	Filter1.setAttribute(Filter1.type, value);

	if (value == 1){
		CutLabel1.setValue("Low Pass");
		CutLabel2.setValue("High Pass");
		CutLabel9.setValue("Serial/ Paralel");
	}
	
	if (value == 2){
			CutLabel1.setValue("Low Shelf");
			CutLabel2.setValue("High Shelf");
			CutLabel9.setValue("Serial/ Paralel");
		}
			
		
	if (value == 3){
			CutLabel1.setValue("Freq");
			CutLabel2.setValue("Low Pass");
			CutLabel9.setValue("FFWD/ Allpass");
			}		
	
};

Content.getComponent("FilterType1").setControlCallback(onFilterType1Control);

const var PosTable1 = Content.getComponent("PosTable1");
const var PosSp1 = Content.getComponent("PosSp1");

 
 inline function onPosModMode1Control(component, value)
 {
 	PosTable1.showControl(value-1);
 	PosSp1.showControl(value);
 	
 	f1.setAttribute(f1.tablestep, value);
 };
 
 Content.getComponent("PosModMode1").setControlCallback(onPosModMode1Control);
 
 
 const var FactoryFile1 = [Content.getComponent("ThirdCB"),
                           Content.getComponent("FolderSelect1"),
                           Content.getComponent("Wav1")];
 
 const var Userfile1 = [Content.getComponent("UsrCb1"),
                        Content.getComponent("UsrWav1"),
                        Content.getComponent("Folder1")];
 
 const var UsrCb1 = Content.getComponent("UsrCb1");
 const var UsrCbVis1 = Content.getComponent("UsrCbVis1");
 const FolderPath = [];
 
 inline function onUserModeControl(component, value)
 {
 Files1.setAttribute(Files1.UserMode, value-1);
 
 	for(s in FactoryFile1)
 		s.showControl(value);  
 		
 	for(s in Userfile1)
 	 		s.showControl(value-1);  	
 };
 
 Content.getComponent("UserMode").setControlCallback(onUserModeControl);
 
 
 inline function onFolder1Control(component, value)
 {
 //Select a folder

if (value == 1)

    FileSystem.browseForDirectory(FileSystem.AudioFiles, function(folder) {
        if (isDefined(folder) && folder.isDirectory()) {
         
         //find files in selected folder
         
            var folderArray = FileSystem.findFiles(folder, "*.wav, *.aif", false);

            for (file in folderArray) {
                file = file.toString(0);
                
                var folderArray2 = FileSystem.findFiles(folder, "*.wav, *.aif", false);
                            
                            for (file1 in folderArray2) {
                                        file1 = file1.toString(1);        
                
         //Populate the Folder Label
              
              	
              
                FolderPath.push(folder);
              
            };
            

         UsrCb1.set("items", folderArray.join("\n"));
		UsrCbVis1.set("items", folderArray2.join("\n"));

	//	LpLoad2.set("items", folderArray2.join("\n"));
    
}

        }
    });
};
 };
 
 Content.getComponent("Folder1").setControlCallback(onFolder1Control);
 

inline function onUsrCbVis1Control(component, value)
{
	ScriptnodeSynthesiser1.setBypassed(false);
	
	reg v = value-1;
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		this.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{


		this.setBypassed(false);
	
		slot2.loadFile(LpLoad1.get("items").split("\n")[v]);
		}, this);

	}, ScriptnodeSynthesiser1);
};

Content.getComponent("UsrCbVis1").setControlCallback(onUsrCbVis1Control);
