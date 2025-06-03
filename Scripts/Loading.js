
//File Manager 
 

inline function onFolderSelect1Control(component, value)
{
	FilePanel.showControl(value-1);
};

Content.getComponent("FolderSelect1").setControlCallback(onFolderSelect1Control);


inline function onFolderSelect2Control(component, value)
{
	FilePanel.showControl(value-1);
};

Content.getComponent("FolderSelect2").setControlCallback(onFolderSelect2Control);


inline function onFolderSelect3Control(component, value)
{
	FilePanel.showControl(value-1);
};

Content.getComponent("FolderSelect3").setControlCallback(onFolderSelect3Control);


inline function onFolderSelect4Control(component, value)
{
	FilePanel.showControl(value-1);
};

Content.getComponent("FolderSelect4").setControlCallback(onFolderSelect4Control);


const var allList = [];
const var allIds = [];

const var AudioList = Engine.loadAudioFilesIntoPool();

const Folder = [];

const var File1 = Synth.getAudioSampleProcessor("Files1");
const var File2 = Synth.getAudioSampleProcessor("Files2");
const var File3 = Synth.getAudioSampleProcessor("Files3");
const var File4 = Synth.getAudioSampleProcessor("Files4");

const slot1 = File1.getAudioFile(1);
const slot2 = File2.getAudioFile(1);
const slot3 = File3.getAudioFile(1);
const slot4 = File4.getAudioFile(1);


const var foldersV1 = [];        // Top-level Genre foldersV1
const var instrumentsV1 = {};    // Maps Genre to Instruments
const var samplesV1 = {};        // Maps Instrument to .wav files
const var foldersV2 = [];        // Top-level Genre foldersV1
const var instrumentsV2 = {};    // Maps Genre to Instruments
const var samplesV2 = {}; 
const var foldersV3 = [];        // Top-level Genre foldersV1
const var instrumentsV3 = {};    // Maps Genre to Instruments
const var samplesV3 = {}; 
const var foldersV4 = [];        // Top-level Genre foldersV1
const var instrumentsV4 = {};    // Maps Genre to Instruments
const var samplesV4 = {}; 


const var FirstSp = Content.getComponent("FirstSp");
const var SecondSp = Content.getComponent("SecondSp");
const var ThirdSp = Content.getComponent("ThirdSp");
const var FirstSp1 = Content.getComponent("FirstSp1");
const var SecondSp1 = Content.getComponent("SecondSp1");
const var ThirdSp1 = Content.getComponent("ThirdSp1");
const var FirstSp2 = Content.getComponent("FirstSp2");
const var SecondSp2 = Content.getComponent("SecondSp2");
const var ThirdSp2 = Content.getComponent("ThirdSp2");
const var FirstSp3 = Content.getComponent("FirstSp3");
const var SecondSp3 = Content.getComponent("SecondSp3");
const var ThirdSp3 = Content.getComponent("ThirdSp3");

const var FirstCB = Content.getComponent("FirstCB");
const var SecondCB = Content.getComponent("SecondCB");
const var ThirdCB = Content.getComponent("ThirdCB");
const var FirstCB1 = Content.getComponent("FirstCB1");
const var SecondCB1 = Content.getComponent("SecondCB1");
const var ThirdCB1 = Content.getComponent("ThirdCB1");
const var FirstCB2 = Content.getComponent("FirstCB2");
const var SecondCB2 = Content.getComponent("SecondCB2");
const var ThirdCB2 = Content.getComponent("ThirdCB2");
const var FirstCB3 = Content.getComponent("FirstCB3");
const var SecondCB3 = Content.getComponent("SecondCB3");
const var ThirdCB3 = Content.getComponent("ThirdCB3");

// Populate the hierarchy
inline function sortAudioFilesListV1() {
	
///	for (file in samplesArray) {
	               
for (file in AudioList) {

        local fullPath = file.split("}")[1];

        local pathParts = fullPath.split("/");
    
        local genreFolder = pathParts[0];
        local instrumentFolder = pathParts[1];
        local sampleFile = pathParts[2];

     
        if (foldersV1.indexOf(genreFolder) == -1) {
            foldersV1.push(genreFolder);
            instrumentsV1[genreFolder] = []; 
        }

       
        if (instrumentsV1[genreFolder].indexOf(instrumentFolder) == -1) {
            instrumentsV1[genreFolder].push(instrumentFolder);
            samplesV1[instrumentFolder] = []; 
        }


        samplesV1[instrumentFolder].push(sampleFile);
  
  
    }

   FirstSp.set("items", foldersV1.join("\n"));
   FirstCB.set("items", foldersV1.join("\n"));
}



// Run the sorting function
sortAudioFilesListV1();

// Callback for GenreV1 selection
inline function onFirstCBControl(component, value) {
    if (value >= 0) {
        // Get the selected Genre
        local selectedGenre = foldersV1[value-1];
     //   Console.print("Selected Genre: " + selectedGenre);

        // Update InstrumentV1 dropdown with instrumentsV1 in the selected Genre
        if (instrumentsV1[selectedGenre]) {
            SecondSp.set("items", instrumentsV1[selectedGenre].join("\n"));
            SecondCB.set("items", instrumentsV1[selectedGenre].join("\n"));
     
        } else {
            SecondSp.set("items", "no file");
            SecondCB.set("items", "no file");


        }

        // Clear SampleV1 as no Instrument is selected yet
        ThirdSp.set("items", "no file");
        
     //   FirstCB.setValue(value);
		SecondCB.setValue(value);
         
    }
}

Content.getComponent("FirstCB").setControlCallback(onFirstCBControl);

inline function onSecondCBControl(component, value) {
    if (value >= 0) {
	    
    
        // Get the selected Instrument
        local selectedInstrument = SecondCB.getItemText();
    //    Console.print("Selected Instrument: " + selectedInstrument);
 		
        // Update SampleV1 dropdown with .wav files in the selected Instrument
        if (samplesV1[selectedInstrument]) {

            ThirdSp.set("items", samplesV1[selectedInstrument].join("\n"));
            ThirdCB.set("items", samplesV1[selectedInstrument].join("\n"))-1;
        } else {
            ThirdSp.set("items", "no file");
 			ThirdCB.set("items", "no file");
        }
      
        
    }
    
    SecondCB.setValue(value);
}

Content.getComponent("SecondCB").setControlCallback(onSecondCBControl);

const var SynthesiserGroup1 = Synth.getChildSynth("Synthesiser Group1");

inline function onThirdCBControl(component, value) 
{
	
	if (value >= 0) {

		local selectedSample = ThirdCB.get("items").split("\n")[value - 1];

       // Construct the full path to the sample
       local selectedGenre = FirstCB.getItemText();
       local selectedInstrument = SecondCB.getItemText();
       local fullPath = "{PROJECT_FOLDER}" + selectedGenre + "/" + selectedInstrument + "/" + selectedSample;

	
	SynthesiserGroup1.setBypassed(false);
	reg voc1 = value-1;
	
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		SynthesiserGroup1.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{
	
	
		SynthesiserGroup1.setBypassed(false);

   
        // Load the sample using the full path
        slot1.loadFile("{PROJECT_FOLDER}" + FirstCB.getItemText() + "/" + SecondCB.getItemText()  + "/" + ThirdCB.getItemText());
      //  Console.print("Sample loaded successfully!");
    
    
    }, this);

	}, ScriptnodeSynthesiser1);
}
}

Content.getComponent("ThirdCB").setControlCallback(onThirdCBControl);




inline function onFirstSpControl(component, value)
{
	FirstCB.setValue(value+1);
	FirstCB.changed();
};

Content.getComponent("FirstSp").setControlCallback(onFirstSpControl);


inline function onSecondSpControl(component, value)
{
	SecondCB.setValue(value+1);
	SecondCB.changed();
};

Content.getComponent("SecondSp").setControlCallback(onSecondSpControl);


inline function onThirdSpControl(component, value)
{
	ThirdCB.setValue(value+1);
	ThirdCB.changed();
};

Content.getComponent("ThirdSp").setControlCallback(onThirdSpControl);

///voice2

// Populate the hierarchy
inline function sortAudioFilesListV2() {
	
///	for (file in samplesArray) {
	               
for (file in AudioList) {

        local fullPath = file.split("}")[1];

        local pathParts = fullPath.split("/");
    
        local genreFolder = pathParts[0];
        local instrumentFolder = pathParts[1];
        local sampleFile = pathParts[2];

     
        if (foldersV2.indexOf(genreFolder) == -1) {
            foldersV2.push(genreFolder);
            instrumentsV2[genreFolder] = []; 
        }

       
        if (instrumentsV2[genreFolder].indexOf(instrumentFolder) == -1) {
            instrumentsV2[genreFolder].push(instrumentFolder);
            samplesV2[instrumentFolder] = []; 
        }


        samplesV2[instrumentFolder].push(sampleFile);
  
  
    }

   FirstSp1.set("items", foldersV2.join("\n"));
   FirstCB1.set("items", foldersV2.join("\n"));
}



// Run the sorting function
sortAudioFilesListV2();

// Callback for GenreV1 selection
inline function onFirstCB1Control(component, value) {
    if (value >= 0) {
        // Get the selected Genre
        local selectedGenre = foldersV2[value-1];
     //   Console.print("Selected Genre: " + selectedGenre);

        // Update InstrumentV1 dropdown with instrumentsV2 in the selected Genre
        if (instrumentsV2[selectedGenre]) {
            SecondSp1.set("items", instrumentsV2[selectedGenre].join("\n"));
            SecondCB1.set("items", instrumentsV2[selectedGenre].join("\n"));
     
        } else {
            SecondSp1.set("items", "no file");
            SecondCB1.set("items", "no file");


        }

        // Clear SampleV1 as no Instrument is selected yet
        ThirdSp1.set("items", "no file");
        
     //   FirstCB1.setValue(value);
		SecondCB1.setValue(value);
         
    }
}

Content.getComponent("FirstCB1").setControlCallback(onFirstCB1Control);

inline function onSecondCB1Control(component, value) {
    if (value >= 0) {
	    
    
        // Get the selected Instrument
        local selectedInstrument = SecondCB1.getItemText();
    //    Console.print("Selected Instrument: " + selectedInstrument);
 		
        // Update SampleV1 dropdown with .wav files in the selected Instrument
        if (samplesV2[selectedInstrument]) {

            ThirdSp1.set("items", samplesV2[selectedInstrument].join("\n"));
            ThirdCB1.set("items", samplesV2[selectedInstrument].join("\n"))-1;
        } else {
            ThirdSp1.set("items", "no file");
 			ThirdCB1.set("items", "no file");
        }
      
        
    }
    
    SecondCB1.setValue(value);
}

Content.getComponent("SecondCB1").setControlCallback(onSecondCB1Control);

const var SynthesiserGroup2 = Synth.getChildSynth("Synthesiser Group2");

inline function onThirdCB1Control(component, value) 
{
	
	if (value >= 0) {

		local selectedSample = ThirdCB1.get("items").split("\n")[value - 1];

       // Construct the full path to the sample
       local selectedGenre = FirstCB1.getItemText();
       local selectedInstrument = SecondCB1.getItemText();
       local fullPath = "{PROJECT_FOLDER}" + selectedGenre + "/" + selectedInstrument + "/" + selectedSample;

	
	SynthesiserGroup2.setBypassed(false);
	reg voc2 = value-1;
	
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		SynthesiserGroup2.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{
	
	
		SynthesiserGroup2.setBypassed(false);

   
        // Load the sample using the full path
        slot2.loadFile("{PROJECT_FOLDER}" + FirstCB1.getItemText() + "/" + SecondCB1.getItemText()  + "/" + ThirdCB1.getItemText());
      //  Console.print("Sample loaded successfully!");
    
    
    }, this);

	}, ScriptnodeSynthesiser2);
}
}

Content.getComponent("ThirdCB1").setControlCallback(onThirdCB1Control);



inline function onFirstSp1Control(component, value)
{
	FirstCB1.setValue(value+1);
	FirstCB1.changed();
};

Content.getComponent("FirstSp1").setControlCallback(onFirstSp1Control);


inline function onSecondSp1Control(component, value)
{
	SecondCB1.setValue(value+1);
	SecondCB1.changed();
};

Content.getComponent("SecondSp1").setControlCallback(onSecondSp1Control);


inline function onThirdSp1Control(component, value)
{
	ThirdCB1.setValue(value+1);
	ThirdCB1.changed();
};

Content.getComponent("ThirdSp1").setControlCallback(onThirdSp1Control);


//voice3

// Populate the hierarchy
inline function sortAudioFilesListV3() {
	
///	for (file in samplesArray) {
	               
for (file in AudioList) {

        local fullPath = file.split("}")[1];

        local pathParts = fullPath.split("/");
    
        local genreFolder = pathParts[0];
        local instrumentFolder = pathParts[1];
        local sampleFile = pathParts[2];

     
        if (foldersV3.indexOf(genreFolder) == -1) {
            foldersV3.push(genreFolder);
            instrumentsV3[genreFolder] = []; 
        }

       
        if (instrumentsV3[genreFolder].indexOf(instrumentFolder) == -1) {
            instrumentsV3[genreFolder].push(instrumentFolder);
            samplesV3[instrumentFolder] = []; 
        }


        samplesV3[instrumentFolder].push(sampleFile);
  
  
    }

   FirstSp2.set("items", foldersV3.join("\n"));
   FirstCB2.set("items", foldersV3.join("\n"));
}



// Run the sorting function
sortAudioFilesListV3();

// Callback for GenreV1 selection
inline function onFirstCB2Control(component, value) {
    if (value >= 0) {
        // Get the selected Genre
        local selectedGenre = foldersV3[value-1];
     //   Console.print("Selected Genre: " + selectedGenre);

        // Update InstrumentV1 dropdown with instrumentsV3 in the selected Genre
        if (instrumentsV3[selectedGenre]) {
            SecondSp2.set("items", instrumentsV3[selectedGenre].join("\n"));
            SecondCB2.set("items", instrumentsV3[selectedGenre].join("\n"));
     
        } else {
            SecondSp2.set("items", "no file");
            SecondCB2.set("items", "no file");


        }

        // Clear SampleV1 as no Instrument is selected yet
        ThirdSp2.set("items", "no file");
        
     //   FirstCB2.setValue(value);
		SecondCB2.setValue(value);
         
    }
}

Content.getComponent("FirstCB2").setControlCallback(onFirstCB2Control);

inline function onSecondCB2Control(component, value) {
    if (value >= 0) {
	    
    
        // Get the selected Instrument
        local selectedInstrument = SecondCB2.getItemText();
    //    Console.print("Selected Instrument: " + selectedInstrument);
 		
        // Update SampleV1 dropdown with .wav files in the selected Instrument
        if (samplesV3[selectedInstrument]) {

            ThirdSp2.set("items", samplesV3[selectedInstrument].join("\n"));
            ThirdCB2.set("items", samplesV3[selectedInstrument].join("\n"))-1;
        } else {
            ThirdSp2.set("items", "no file");
 			ThirdCB2.set("items", "no file");
        }
      
        
    }
    
    SecondCB2.setValue(value);
}

Content.getComponent("SecondCB2").setControlCallback(onSecondCB2Control);

const var SynthesiserGroup3 = Synth.getChildSynth("Synthesiser Group3");

inline function onThirdCB2Control(component, value) 
{
	
	if (value >= 0) {

		local selectedSample = ThirdCB2.get("items").split("\n")[value - 1];

       // Construct the full path to the sample
       local selectedGenre = FirstCB2.getItemText();
       local selectedInstrument = SecondCB2.getItemText();
       local fullPath = "{PROJECT_FOLDER}" + selectedGenre + "/" + selectedInstrument + "/" + selectedSample;

	
	SynthesiserGroup3.setBypassed(false);
	reg voc3 = value-1;
	
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		SynthesiserGroup3.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{
	
	
		SynthesiserGroup3.setBypassed(false);

   
        // Load the sample using the full path
        slot3.loadFile("{PROJECT_FOLDER}" + FirstCB2.getItemText() + "/" + SecondCB2.getItemText()  + "/" + ThirdCB2.getItemText());
      //  Console.print("Sample loaded successfully!");
    
    
    }, this);

	}, ScriptnodeSynthesiser2);
}
}

Content.getComponent("ThirdCB2").setControlCallback(onThirdCB2Control);



inline function onFirstSp2Control(component, value)
{
	FirstCB2.setValue(value+1);
	FirstCB2.changed();
};

Content.getComponent("FirstSp2").setControlCallback(onFirstSp2Control);


inline function onSecondSp2Control(component, value)
{
	SecondCB2.setValue(value+1);
	SecondCB2.changed();
};

Content.getComponent("SecondSp2").setControlCallback(onSecondSp2Control);


inline function onThirdSp2Control(component, value)
{
	ThirdCB2.setValue(value+1);
	ThirdCB2.changed();
};

Content.getComponent("ThirdSp2").setControlCallback(onThirdSp2Control);


//voice4

// Populate the hierarchy
inline function sortAudioFilesListV4() {
	
///	for (file in samplesArray) {
	               
for (file in AudioList) {

        local fullPath = file.split("}")[1];

        local pathParts = fullPath.split("/");
    
        local genreFolder = pathParts[0];
        local instrumentFolder = pathParts[1];
        local sampleFile = pathParts[2];

     
        if (foldersV4.indexOf(genreFolder) == -1) {
            foldersV4.push(genreFolder);
            instrumentsV4[genreFolder] = []; 
        }

       
        if (instrumentsV4[genreFolder].indexOf(instrumentFolder) == -1) {
            instrumentsV4[genreFolder].push(instrumentFolder);
            samplesV4[instrumentFolder] = []; 
        }


        samplesV4[instrumentFolder].push(sampleFile);
  
  
    }

   FirstSp3.set("items", foldersV4.join("\n"));
   FirstCB3.set("items", foldersV4.join("\n"));
}



// Run the sorting function
sortAudioFilesListV4();

// Callback for GenreV1 selection
inline function onFirstCB3Control(component, value) {
    if (value >= 0) {
        // Get the selected Genre
        local selectedGenre = foldersV4[value-1];
     //   Console.print("Selected Genre: " + selectedGenre);

        // Update InstrumentV1 dropdown with instrumentsV4 in the selected Genre
        if (instrumentsV4[selectedGenre]) {
            SecondSp3.set("items", instrumentsV4[selectedGenre].join("\n"));
            SecondCB3.set("items", instrumentsV4[selectedGenre].join("\n"));
     
        } else {
            SecondSp3.set("items", "no file");
            SecondCB3.set("items", "no file");


        }

        // Clear SampleV1 as no Instrument is selected yet
        ThirdSp3.set("items", "no file");
        
     //   FirstCB3.setValue(value);
		SecondCB3.setValue(value);
         
    }
}

Content.getComponent("FirstCB3").setControlCallback(onFirstCB3Control);

inline function onSecondCB3Control(component, value) {
    if (value >= 0) {
	    
    
        // Get the selected Instrument
        local selectedInstrument = SecondCB3.getItemText();
    //    Console.print("Selected Instrument: " + selectedInstrument);
 		
        // Update SampleV1 dropdown with .wav files in the selected Instrument
        if (samplesV4[selectedInstrument]) {

            ThirdSp3.set("items", samplesV4[selectedInstrument].join("\n"));
            ThirdCB3.set("items", samplesV4[selectedInstrument].join("\n"))-1;
        } else {
            ThirdSp3.set("items", "no file");
 			ThirdCB3.set("items", "no file");
        }
      
        
    }
    
    SecondCB3.setValue(value);
}

Content.getComponent("SecondCB3").setControlCallback(onSecondCB3Control);

const var SynthesiserGroup4 = Synth.getChildSynth("Synthesiser Group4");

inline function onThirdCB3Control(component, value) 
{
	
	if (value >= 0) {

		local selectedSample = ThirdCB3.get("items").split("\n")[value - 1];

       // Construct the full path to the sample
       local selectedGenre = FirstCB3.getItemText();
       local selectedInstrument = SecondCB3.getItemText();
       local fullPath = "{PROJECT_FOLDER}" + selectedGenre + "/" + selectedInstrument + "/" + selectedSample;

	
	SynthesiserGroup4.setBypassed(false);
	reg voc4 = value-1;
	
	Content.callAfterDelay(400, function()
	{
		Engine.allNotesOff();
	
		SynthesiserGroup4.setBypassed(true);
		
		Content.callAfterDelay(400, function()
		{
	
	
		SynthesiserGroup4.setBypassed(false);

   
        // Load the sample using the full path
        slot4.loadFile("{PROJECT_FOLDER}" + FirstCB3.getItemText() + "/" + SecondCB3.getItemText()  + "/" + ThirdCB3.getItemText());
      //  Console.print("Sample loaded successfully!");
    
    
    }, this);

	}, ScriptnodeSynthesiser4);
}
}

Content.getComponent("ThirdCB3").setControlCallback(onThirdCB3Control);



inline function onFirstSp3Control(component, value)
{
	FirstCB3.setValue(value+1);
	FirstCB3.changed();
};

Content.getComponent("FirstSp3").setControlCallback(onFirstSp3Control);


inline function onSecondSp3Control(component, value)
{
	SecondCB3.setValue(value+1);
	SecondCB3.changed();
};

Content.getComponent("SecondSp3").setControlCallback(onSecondSp3Control);


inline function onThirdSp3Control(component, value)
{
	ThirdCB3.setValue(value+1);
	ThirdCB3.changed();
};

Content.getComponent("ThirdSp3").setControlCallback(onThirdSp3Control);


//USER



 
 const var FactoryFile1 = [Content.getComponent("ThirdCB"),
                           Content.getComponent("FolderSelect1"),
                           Content.getComponent("Wav1")];
 
 const var Userfile1 = [Content.getComponent("UsrCbVis1"),
                        Content.getComponent("UsrWav1"),
                        Content.getComponent("FolderSel1")];
 
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
 
 
 inline function onFolderSel1Control(component, value) {
 
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
             
             
             
             //send items to hidden ComboBox
             
 
          UsrCb1.set("items", folderArray.join("\n"));
 		UsrCbVis1.set("items", folderArray2.join("\n"));

 			
 	//	LpLoad2.set("items", folderArray2.join("\n"));
     
 }
 
         }
     });
 };
 
 Content.getComponent("FolderSel1").setControlCallback(onFolderSel1Control);
 
const var SGroup1 = Synth.getChildSynth("Synthesiser Group1");

const slotU1 = File1.getAudioFile(0);
const slotU2 = File2.getAudioFile(0);
const slotU3 = File3.getAudioFile(0);
const slotU4 = File4.getAudioFile(0);


inline function onUsrCb1Control(component, value)
{
	SGroup1.setBypassed(false);
	
	reg v = value-1;
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		this.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{


		this.setBypassed(false);
	
		slotU1.loadFile(UsrCb1.get("items").split("\n")[v]);
		}, this);

	}, SGroup1);
};

Content.getComponent("UsrCb1").setControlCallback(onUsrCb1Control);


inline function onUsrCbVis1Control(component, value)
{
	UsrCb1.setValue(value);
	UsrCb1.changed();
};

Content.getComponent("UsrCbVis1").setControlCallback(onUsrCbVis1Control);


