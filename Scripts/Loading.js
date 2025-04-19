///// Loop Player Internal


//Store folder path

const FolderPath = [];
const FolderPath2 = [];

const var FileLoadInit1 = Content.getComponent("FileLoadInit");


FileLoadInit1.setValue(1);
FileLoadInit1.changed();

const var LpLoad1 = Content.getComponent("LpLoad1");
const var LpLoad2 = Content.getComponent("LpLoad2");
const var LpLoad3 = Content.getComponent("LpLoad3");
const var LpLoad4 = Content.getComponent("LpLoad4");
const var LpLoad5 = Content.getComponent("LpLoad5");
const var LpLoad6 = Content.getComponent("LpLoad6");
const var LpLoad7 = Content.getComponent("LpLoad7");
const var LpLoad8 = Content.getComponent("LpLoad8");

const var ModLoadWave = Content.getComponent("ModLoadWave");
const var ModLoadWave1 = Content.getComponent("ModLoadWave1");
const var BankB1 = Content.getComponent("BankB1");



const var FolderLabel = Content.getComponent("FolderLabel");

const var FolderLabel3 = Content.getComponent("FolderLabel3");
const var FolderLabel4 = Content.getComponent("FolderLabel4");
const var FolderLabel5 = Content.getComponent("FolderLabel5");
const var FolderLabel6 = Content.getComponent("FolderLabel6");



// Choose a folder to load samples from. 

inline function onFolderSelectControl(component, value) {

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
            

         LpLoad1.set("items", folderArray.join("\n"));
		LpLoad2.set("items", folderArray2.join("\n"));
		LpLoad3.set("items", folderArray.join("\n"));
		LpLoad4.set("items", folderArray2.join("\n"));
		LpLoad5.set("items", folderArray.join("\n"));
		LpLoad6.set("items", folderArray2.join("\n"));
		LpLoad7.set("items", folderArray.join("\n"));
		LpLoad8.set("items", folderArray2.join("\n"));
	
			
	//	LpLoad2.set("items", folderArray2.join("\n"));
    
}

        }
    });
};

Content.getComponent("FolderSelect").setControlCallback(onFolderSelectControl);


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
	FolderLabel.set("text", LpLoad2.getItemText());
};

Content.getComponent("LpLoad2").setControlCallback(onLpLoad2Control);


inline function onLpLoad3Control(component, value)
{

	ScriptnodeSynthesiser1.setBypassed(false);
	
	reg v3 = value-1;
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		this.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{


		this.setBypassed(false);
	
		slot3.loadFile(LpLoad3.get("items").split("\n")[v3]);
		}, this);

	}, ScriptnodeSynthesiser1);
};

Content.getComponent("LpLoad3").setControlCallback(onLpLoad3Control);

inline function onLpLoad4Control(component, value)
{
	LpLoad3.setValue(value);
	LpLoad3.changed();
	FolderLabel3.set("text", LpLoad4.getItemText());
};

Content.getComponent("LpLoad4").setControlCallback(onLpLoad4Control);


inline function onLpLoad5Control(component, value)
{

	ScriptnodeSynthesiser1.setBypassed(false);
	
	reg v4 = value-1;
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		this.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{


		this.setBypassed(false);
	
		slot4.loadFile(LpLoad5.get("items").split("\n")[v4]);
		}, this);

	}, ScriptnodeSynthesiser1);
};

Content.getComponent("LpLoad5").setControlCallback(onLpLoad5Control);

inline function onLpLoad6Control(component, value)
{
	LpLoad5.setValue(value);
	LpLoad5.changed();
	FolderLabel4.set("text", LpLoad6.getItemText());
};

Content.getComponent("LpLoad6").setControlCallback(onLpLoad6Control);


inline function onLpLoad7Control(component, value)
{

	ScriptnodeSynthesiser1.setBypassed(false);
	
	reg v5 = value-1;
	Content.callAfterDelay(300, function()
	{
		Engine.allNotesOff();
	
		this.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{


		this.setBypassed(false);
	
		slot5.loadFile(LpLoad7.get("items").split("\n")[v5]);
		}, this);

	}, ScriptnodeSynthesiser1);
};

Content.getComponent("LpLoad7").setControlCallback(onLpLoad7Control);

inline function onLpLoad8Control(component, value)
{
	LpLoad7.setValue(value);
	LpLoad7.changed();
	FolderLabel6.set("text", LpLoad8.getItemText());
};

Content.getComponent("LpLoad8").setControlCallback(onLpLoad8Control);


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

const var FourFiles = [Content.getComponent("LpLoad8"),
                       Content.getComponent("LpLoad6"),
                       Content.getComponent("LpLoad4"),
                       Content.getComponent("FourFiles")];





