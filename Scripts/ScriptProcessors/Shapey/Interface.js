Content.makeFrontInterface(840, 660);

include("laf.js");
//include("mod.js");

const Maps = [];

const BellKey = ["Bell_Belles", "Bell_More", "Bell_Src", "Keys_DCOPiano", "Keys_Darkly", "Keys_EM25_1", "Keys_EM25_2", "Keys_EM25_3", "Keys_EM25_4", "Keys_EP1", "Keys_EP2", "Keys_EP3", "Keys_Euro", "Keys_Odd", "Keys_Swoosh1", "Keys_Swoosh2", "Keys_Swoosh3", "Keys_pswp"];
const FX = ["FX_CrazyLFO", "FX_Devistate", "FX_Drama", "FX_FMRings", "FX_FeedFwd", "FX_Gooey", "FX_HiYearner", "FX_LickElectric", "FX_LoopG", "FX_MagicResin", "FX_S&H", "FX_Zap", "FX__Bypass", "FX_heartache", "FX_BeastMode", "FX_BrainSeq", "FX_BseqSmooth", "FX_Burd", "FX_SmearedToy", "FX_Swish", "FX_WowOhWow"];
const KitSeq = ["Kit_612_perc", "Kit_CS", "Kit_MP", "Kit_Sh2", "SEQ_Bumpkin130", "SEQ_SpaceRaider", "SEQ_TwistingMellow1", "SEQ_TwistingMellow2", "SEQ_revolve130", "SEQ_sale", "Seq_Lemon90", "Seq_consider"];
const Lead = ["Lead_2ndFinger", "Lead_Astonish", "Lead_Astonished", "Lead_Bargain", "Lead_Basic", "Lead_Brew", "Lead_Cream", "Lead_CrumbFlute", "Lead_Crunch", "Lead_Crunchy", "Lead_CupCake", "Lead_Curious", "Lead_DF1", "Lead_Day3", "Lead_Drink", "Lead_Egg", "Lead_FakeSync", "Lead_Fingers", "Lead_Grizzle", "Lead_K30L", "Lead_K_Legs", "Lead_Log", "Lead_Lozange", "Lead_Messin", "Lead_PseudoSync", "Lead_RavST", "Lead_Rodge", "Lead_SadRing", "Lead_Sayer", "Lead_SaysThings", "Lead_Scream", "Lead_Screamer", "Lead_ShRes", "Lead_Simple", "Lead_SimpleJx", "Lead_SlwRing1", "Lead_SlwRing2", "Lead_SlwRing3", "Lead_TSync", "Lead_Tinkle", "Lead_funny", "Lead_harsh", "Lead_k30l2", "Lead_mth", "Lead_rude", "Lead_sawd", "Lead_stix"];
const Misc = ["Misc_EM25_1", "Misc_EM25_2", "Misc_EM25_3", "Misc_Gdad_1", "Misc_Gdad_2", "Misc_Gdad_3", "Misc_Gdad_4", "Misc_Gdad_5", "Misc_Meta_1", "Misc_Meta_2", "Misc_Meta_3", "Misc_Meta_4", "Misc_Meta_5", "Misc_SplGit", "Misc_Spook", "Misc_Toes", "Misc_Vibe", "Misc_WBrass", "Misc_Wet", "Pluck_Gater", "Pluck_PluckSH", "Bass_BooBass", "Bass_Bz", "Bass_Double", "Bass_Gooey", "Bass_HardBass", "Bass_HellCat", "Bass_Lilbass", "Bass_RM", "Bass_Round", "Bass_ShakeyBass", "Bass_Shrp", "Bass_Slap", "Bass_eBass", "Bass_hard", "Bass_nsty1", "Bass_nsty2"];
const Pad = ["Pad_BigElectric", "Pad_Bumpy", "Pad_Busy", "Pad_CsShock", "Pad_DF2", "Pad_DS", "Pad_Gravel", "Pad_GreatST", "Pad_Lfade", "Pad_Lingo", "Pad_OChord", "Pad_PulseString", "Pad_RLD", "Pad_Rouse", "Pad_Rust", "Pad_Scratchy", "Pad_Scrd", "Pad_SlowOne", "Pad_Special", "Pad_Swish", "Pad_Tortoise", "Pad_Trouble", "Pad_XpSea", "Pad_simr", " Strings_Classy", "Strings_EM25_1", "Strings_EM25_2", "Strings_EM25_3", "Strings_Z1_1", "Strings_Z1_2"];
const Waves = ["Wave_MP4xSaw1", "Wave_MP4xSaw2", "Wave_MPSawA1", "Wave_MPSawA2", "Wave_MPSawA3", "Wave_MPSawA4", "Wave_MPSawB1", "Wave_MPSawB2", "Wave_MPSawB3", "Wave_MPSqr_1", "Wave_MPSqr_2", "Wave_MPSqr_3", "Wave_MPSqr_4", "Wave_MPSqr_5", "Wave_MPTri", "Wave_Noise", "Wave_Noise1", "Wave_Noise2", "Wave_Noise3", "Wave_Noise4", "Wave_Pulse1", "Wave_Pulse2", "Wave_Pulse3", "Wave_Saw", "Wave_Sine"];

Maps.push(BellKey);
Maps.push(FX);
Maps.push(KitSeq);
Maps.push(Lead);
Maps.push(Misc);
Maps.push(Pad);
Maps.push(Waves);

const SMAPS = ["Bells & Keys", "FX","Kits & Seq", "Leads", "Misc", "Pads", "Basic Waves"];

Settings.setVoiceMultiplier(8);
const var AudioList = Engine.loadAudioFilesIntoPool();

Synth.setUseUniformVoiceHandler("Shapey", true);

// Make sure to set the display buffer of the oscillator to the first slot
const var dps = Synth.getDisplayBufferSource("Shaper");

// Grab a reference to the display buffer
const var dp = dps.getDisplayBuffer(0);
const var dp2 = dps.getDisplayBuffer(3);
const var dp3 = dps.getDisplayBuffer(3);

const var OscVisual = Content.getComponent("OscVisual");

OscVisual.setTimerCallback(function()
{
	// this creates a path from the current buffer content
	this.data.p = dp.createPath(
				    this.getLocalBounds(10), // target area [x, y, width, height]
				    [0, -1, -1.0, 1.0], // source area [startSample, endSample, minYValue, maxYValue]
				    0.0 // starting position
				  );
	this.repaint();
});

OscVisual.startTimer(30);


OscVisual.setPaintRoutine(function(g)
{
	g.setColour(Colours.white);

	if(isDefined(this.data.p))
		g.fillPath(this.data.p, this.getLocalBounds(10));
});

const var ScriptAudioWaveform2 = Content.getComponent("ScriptAudioWaveform2");


ScriptAudioWaveform2.setTimerCallback(function()
{
	// this creates a path from the current buffer content
	this.data.p = dp2.createPath(
				    this.getLocalBounds(10), // target area [x, y, width, height]
				    [0, -1, -1.0, 1.0], // source area [startSample, endSample, minYValue, maxYValue]
				    0.0 // starting position
				  );
	this.repaint();
});

ScriptAudioWaveform2.startTimer(30);


ScriptAudioWaveform2.setPaintRoutine(function(g)
{
	g.setColour(Colours.white);

	if(isDefined(this.data.p))
		g.fillPath(this.data.p, this.getLocalBounds(10));
});




const var ModA = Content.getComponent("ModA");
const var ModTempo = Content.getComponent("ModTempo");
const var ModDiv = Content.getComponent("ModDiv");
const var ModTrig = Content.getComponent("ModTrig");
const var WaveTable = Content.getComponent("WaveTable");
const var Looper = Content.getComponent("Looper");
const var Sample = Content.getComponent("Sample");




//settings

const var PnS = Content.getComponent("PnS");


inline function onPresetsControl(component, value)
{
	if(value == 0)
	{
	PnS.showControl(0);	
	}
	if(value == 1)
		{
		PnS.showControl(1);	
		}
};

Content.getComponent("Presets").setControlCallback(onPresetsControl);

const var Imp = Content.getComponent("Imp");


inline function onIrControl(component, value)
{
	if(value == 0)
	{	 	    
		 Imp.showControl(0);

	}	
if(value == 1)
	{	 	    
		 Imp.showControl(1);
	
	}	
};

Content.getComponent("Ir").setControlCallback(onIrControl);


///// Loop Player Internal


//Store folder path

const FolderPath = [];
const var LpLoad1 = Content.getComponent("LpLoad1");
const var LpLoad2 = Content.getComponent("LpLoad2");

const var FolderLabel = Content.getComponent("FolderLabel");

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
              
              	
                FolderLabel.set("text", folder.toString(0));
                FolderPath.push(folder);
              
            };
            
            
            
            //send items to hidden ComboBox
            

         LpLoad1.set("items", folderArray.join("\n"));
		LpLoad2.set("items", folderArray2.join("\n"));
    
}

        }
    });
};

Content.getComponent("FolderSelect").setControlCallback(onFolderSelectControl);





const var Shaper = Synth.getAudioSampleProcessor("Shaper");


const slot = Shaper.getAudioFile(0);
const slot1 = Shaper.getAudioFile(1);



inline function onLpLoad1Control(component, value)
{

	Shaper.setBypassed(false);
	
	reg v = value-1;
	Content.callAfterDelay(300, function()
	{
	//	Engine.allNotesOff();
	
		this.setAttribute(this.sswitch, 2);
		this.setBypassed(true);
		
		Content.callAfterDelay(300, function()
		{

		this.setAttribute(this.sswitch, 1);
		this.setBypassed(false);
		slot1.loadFile(LpLoad1.get("items").split("\n")[v]);
		}, this);

	}, Shaper);
};

Content.getComponent("LpLoad1").setControlCallback(onLpLoad1Control);



inline function onLpLoad2Control(component, value)
{
	LpLoad1.setValue(value);
	LpLoad1.changed();
};

Content.getComponent("LpLoad2").setControlCallback(onLpLoad2Control);



const var SyncOff = [Content.getComponent("Pitch"),
                     Content.getComponent("ScriptSlider45"),
                     Content.getComponent("ShapeModSource5"),
                     Content.getComponent("ScriptLabel87")];

const var SyncOn = [Content.getComponent("ScriptLabel80"),
                    Content.getComponent("Divide"),
                    Content.getComponent("ScriptSlider58"),
                    Content.getComponent("ScriptLabel86"),
                    Content.getComponent("ScriptSlider59"),
                    Content.getComponent("ShapeModSource16")];



inline function onPitchSyncControl(component, value)
{
	if(value == 0)
	{
for(s in SyncOff)
	       s.showControl(1);
	      
for(s in SyncOn)
	       s.showControl(0);
	       
	Shaper.setAttribute(Shaper.PitchSync, 0);
	}
	
	if(value == 1)
	{
	for(s in SyncOff)
	       s.showControl(0);
	       
	       for(s in SyncOn)
	       	       s.showControl(1);
	       	       
	
		Shaper.setAttribute(Shaper.PitchSync, 1);       	       
	       	
	}
	
	

};

Content.getComponent("PitchSync").setControlCallback(onPitchSyncControl);

const var BankADisplay = Content.getComponent("BankADisplay")


const var CarMultiSample = [Content.getComponent("ScriptAudioWaveform2"),
                            Content.getComponent("Categories"),
                            Content.getComponent("BankA"),
                            Content.getComponent("ScriptLabel88"),
                            Content.getComponent("bankLB")];

const var OscCont = [Content.getComponent("ScriptLabel75"),
                     Content.getComponent("Os Shape"),
                     Content.getComponent("OscVisual")];

const var Categories = Content.getComponent("Categories");
const var BankA = Content.getComponent("BankA");

inline function onModulatorModeControl(component, value)
{
	if(value == 0)
	{
	for(s in CarMultiSample)
		       s.showControl(1);
		      
	for(s in OscCont)
		       s.showControl(0);
	
	Shaper.setAttribute(Shaper.InputMode, 1);	       
		       
	}	  
	
	if(value == 1)
	{
	for(s in CarMultiSample)
		       s.showControl(0);
		      
	for(s in OscCont)
		       s.showControl(1);
		       
	Shaper.setAttribute(Shaper.InputMode, 0);	       	       
		       
	}	       

};

Content.getComponent("ModulatorMode").setControlCallback(onModulatorModeControl);


Categories.set("items", SMAPS.join("\n"));


var sampleMaps = Sampler.getSampleMapList();
const var Sampler1 = Synth.getSampler("Sampler1");
const var SampleModes = Categories.getValue();

inline function onCategoriesControl(component, value)
{

	BankA.set("items", [].join("\n")); 
	BankA.set("items", Maps[value-1].join("\n"));
	BankADisplay.set("items", [].join("\n")); 
	BankADisplay.set("items", Maps[value-1].join("\n"));
//	BankADisplay.set("items", Maps.join("\n"));
};

Content.getComponent("Categories").setControlCallback(onCategoriesControl);



inline function onBankAControl(component, value)
{
//	WAVELABEL1.set("text",BankA.get("items").split("\n")[value-1]);
	
slot.loadFile("{XYZ::SampleMap}" + component.getItemText());
//	slot.loadFile("{XYZ::SampleMap}" + (maps[value-1]));

Sampler1.loadSampleMap(sampleMaps[value-1]);

};

Content.getComponent("BankA").setControlCallback(onBankAControl);




inline function onBankADisplayControl(component, value)
{


  Sampler1.loadSampleMap(value);


};

Content.getComponent("BankADisplay").setControlCallback(onBankADisplayControl);



const var CarDisable = [Content.getComponent("ShapeModSource13"),
                        Content.getComponent("ScriptSlider54"),
                        Content.getComponent("ScriptSlider55"),
                        Content.getComponent("ScriptSlider23"),
                        Content.getComponent("ScriptSlider57"),
                        Content.getComponent("ShapeModSource15"),
                        Content.getComponent("LpLoad2"),
                        Content.getComponent("FolderSelect"),
                        Content.getComponent("ScriptAudioWaveform1"),
                        Content.getComponent("ScriptSlider56"),
                        Content.getComponent("BankADisplay1"),
                         Content.getComponent("ScriptLabel89"),
                          Content.getComponent("BankA1"),
                        Content.getComponent("bankLB1"),
                         Content.getComponent("Categories1"),
                         Content.getComponent("ScriptAudioWaveform3")];

const var CarMultis = [Content.getComponent("BankBDisplay"),
                       Content.getComponent("ScriptLabel89"),
                       Content.getComponent("BankB"),
                       Content.getComponent("bankLB1"),
                       Content.getComponent("Categories2"),
                       Content.getComponent("ScriptAudioWaveform3")];

const var CarWav = [Content.getComponent("ScriptAudioWaveform1"),
                    Content.getComponent("ScriptLabel82"),
                    Content.getComponent("FolderSelect"),
                    Content.getComponent("ScriptLabel81"),
                    Content.getComponent("LpLoad2")];

const var Panel3 = Content.getComponent("Panel3");


inline function onCarModeControl(component, value)
{
	if(value == 1)
	{
	Panel3.showControl(1); 
	for(s in CarMultis)
		       s.showControl(0);       
		       
	for(s in CarWav)
		       s.showControl(1);   
    	       
	      } 
	if(value == 2)
	{
	
	for(s in CarMultis)
		       s.showControl(0);       
		       
	for(s in CarWav)
		       s.showControl(1);   
	
	Panel3.showControl(0);      	       
	      } 
	 
	 if(value == 3)
	 {
	 
	 for(s in CarMultis)
	 	       s.showControl(1);       
	 	       
	 for(s in CarWav)
	 	       s.showControl(0);       
	 Panel3.showControl(0);  	       
	 	       	       
	       }      
	      
};

Content.getComponent("CarMode").setControlCallback(onCarModeControl);




function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onTimer()
{
	
}
 function onControl(number, value)
{
	
}
 