Content.makeFrontInterface(845, 630);

include("laf.js");
include("mod.js");
include("osc.js");

Settings.setVoiceMultiplier(64);

Synth.setUseUniformVoiceHandler("Shapey", true);

const var WavetableSynthesiser1 = Synth.getChildSynth("Wavetable Synthesiser1");
const var PitchModSrc = Synth.getModulator("PitchModSrc");
const var Filter = Synth.getEffect("Filter");
const var TableIndexModSrc1 = Synth.getModulator("TableIndexModSrc1");
const var shaper = Synth.getEffect("shaper");
const var ModA = Content.getComponent("ModA");
const var ModTempo = Content.getComponent("ModTempo");
const var ModDiv = Content.getComponent("ModDiv");
const var ModTrig = Content.getComponent("ModTrig");
const var WaveTable = Content.getComponent("WaveTable");
const var Looper = Content.getComponent("Looper");
const var Sample = Content.getComponent("Sample");
const var SyntesizerGroup1 = Synth.getChildSynth("Syntesizer Group1");
const var AudioLoopPlayer1 = Synth.getChildSynth("Audio Loop Player1");



const var PreShape = Content.getComponent("PreShape");


inline function onPreShapeControl(component, value)
{
	AudioLoopPlayer1.setAttribute(AudioLoopPlayer1.Gain, (value));
WavetableSynthesiser1.setAttribute(WavetableSynthesiser1.Gain, (value));
};

Content.getComponent("PreShape").setControlCallback(onPreShapeControl);


const var preloadBar = Content.getComponent("preloadBar");
preloadBar.setPaintRoutine(function(g)
{
	g.fillAll(this.get("bgColour"));
	g.setColour(this.get("itemColour"));
	g.fillRect([0, 0, this.getWidth() * this.data.progress, this.getHeight()]);
});

preloadBar.setTimerCallback(function()
{
	this.data.progress = Engine.getPreloadProgress();
	this.repaint();	
});

preloadBar.setLoadingCallback(function(isPreloading)
{
    this.data.progress = 0.0;
    this.set("visible", isPreloading);
    
	if(isPreloading)
        this.startTimer(80);
    else
        this.stopTimer();
});

const var WTsel = Content.getComponent("WTsel");


inline function onWTselControl(component, value)
{
Engine.allNotesOff();

WavetableSynthesiser1.setAttribute(WavetableSynthesiser1.LoadedBankIndex, (value));
};

Content.getComponent("WTsel").setControlCallback(onWTselControl);

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
 