///// Loop Player Internal


//Store folder path

const FolderPath = [];
const FolderPath2 = [];
const var LpLoad1 = Content.getComponent("LpLoad1");
const var LpLoad2 = Content.getComponent("LpLoad2");

const var ModLoadWave = Content.getComponent("ModLoadWave");
const var ModLoadWave1 = Content.getComponent("ModLoadWave1");
const var BankB1 = Content.getComponent("BankB1");



const var FolderLabel = Content.getComponent("FolderLabel");

// Choose a folder to load samples from. 

inline function onFolderSelectControl(component, value) {

//Select a folder

if (value == 1)

    FileSystem.browseForDirectory(FileSystem.AudioFiles, function(folder) {
        if (isDefined(folder) && folder.isDirectory()) {
         
         //find files in selected folder
         
            var folderArray = FileSystem.findFiles(folder, "*.wav, *.aif, *.sfz", false);

            for (file in folderArray) {
                file = file.toString(0);
                
                var folderArray2 = FileSystem.findFiles(folder, "*.wav, *.aif, *.sfz", false);
                            
                            for (file1 in folderArray2) {
                                        file1 = file1.toString(1);        
                
         //Populate the Folder Label
              
              	
                FolderLabel.set("text", folder.toString(0));
                FolderPath.push(folder);
              
            };
            
            
            
            //send items to hidden ComboBox
            

         LpLoad1.set("items", folderArray.join("\n"));
		LpLoad2.set("items", folderArray2.join("\n"));
	
			
	//	LpLoad2.set("items", folderArray2.join("\n"));
    
}

        }
    });
};

Content.getComponent("FolderSelect").setControlCallback(onFolderSelectControl);

const var FolderLabel2 = Content.getComponent("FolderLabel2");

inline function onFolderSelect1Control(component, value) {

//Select a folder

if (value == 1)

    FileSystem.browseForDirectory(FileSystem.AudioFiles, function(folder) {
        if (isDefined(folder) && folder.isDirectory()) {
         
         //find files in selected folder
         
            var folderArray3 = FileSystem.findFiles(folder, "*.wav, *.aif, *.sfz", false);

            for (file in folderArray3) {
                file = file.toString(0);
                
                var folderArray4 = FileSystem.findFiles(folder, "*.wav, *.aif, *.sfz", false);
                            
                            for (file1 in folderArray4) {
                                        file1 = file1.toString(1);        
                
         //Populate the Folder Label
              
              	
                FolderLabel2.set("text", folder.toString(0));
                FolderPath2.push(folder);
              
            };
            
            
            
            //send items to hidden ComboBox
            

         ModLoadWave.set("items", folderArray3.join("\n"));
		ModLoadWave1.set("items", folderArray4.join("\n"));
    
}

        }
    });
};

Content.getComponent("FolderSelect1").setControlCallback(onFolderSelect1Control);




const var Shaper = Synth.getAudioSampleProcessor("Shaper");


const slot1 = Shaper.getAudioFile(0);
const slot2 = Shaper.getAudioFile(1);



const var ScriptnodeSynthesiser1 = Synth.getChildSynth("ScriptnodeSynthesiser1");

inline function onLpLoad1Control(component, value)
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

Content.getComponent("LpLoad1").setControlCallback(onLpLoad1Control);




inline function onLpLoad2Control(component, value)
{
	LpLoad1.setValue(value);
	LpLoad1.changed();
};

Content.getComponent("LpLoad2").setControlCallback(onLpLoad2Control);

const var ScriptnodeSynthesiser2 = Synth.getChildSynth("ScriptnodeSynthesiser1");

inline function onModLoadWaveControl(component, value)
{

	ScriptnodeSynthesiser2.setBypassed(false);
	
	reg v1 = value-1;
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		this.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{


		this.setBypassed(false);
		slot1.loadFile(ModLoadWave.get("items").split("\n")[v1]);
		}, this);

	}, ScriptnodeSynthesiser2);
};

Content.getComponent("ModLoadWave").setControlCallback(onModLoadWaveControl);


inline function onModLoadWave1Control(component, value)
{
		ModLoadWave.setValue(value);
	ModLoadWave.changed();
};

Content.getComponent("ModLoadWave1").setControlCallback(onModLoadWave1Control);


