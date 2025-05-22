const var allList = [];
const var allIds = [];

const var AudioList = Engine.loadAudioFilesIntoPool();

const Folder = [];

const var Files1 = Synth.getAudioSampleProcessor("Files1");

const slot1 = Files1.getAudioFile(1);



const var foldersV1 = [];        // Top-level Genre foldersV1
const var instrumentsV1 = {};    // Maps Genre to Instruments
const var samplesV1 = {};        // Maps Instrument to .wav files

const var FirstSp = Content.getComponent("FirstSp");
const var SecondSp = Content.getComponent("SecondSp");
const var ThirdSp = Content.getComponent("ThirdSp");

const var FirstCB = Content.getComponent("FirstCB");
const var SecondCB = Content.getComponent("SecondCB");
const var ThirdCB = Content.getComponent("ThirdCB");

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

inline function onThirdCBControl(component, value) {
    if (value >= 0) {
        // Get the selected sample name
        local selectedSample = ThirdCB.get("items").split("\n")[value - 1];

        // Construct the full path to the sample
        local selectedGenre = FirstCB.getItemText();
        local selectedInstrument = SecondCB.getItemText();
        local fullPath = "{PROJECT_FOLDER}" + selectedGenre + "/" + selectedInstrument + "/" + selectedSample;

        // Print the full path to the console to verify
       // Console.print("Attempting to load: " + fullPath);

        // Load the sample using the full path
        slot1.loadFile(fullPath);
      //  Console.print("Sample loaded successfully!");
    }
 //   ThirdCB.setValue(value+1);

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

