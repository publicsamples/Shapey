Content.makeFrontInterface(900, 600);

const var WavetableSynthesiser1 = Synth.getChildSynth("Wavetable Synthesiser1");

//Mod Env Shared Controls

const var PitchModSrc = Synth.getModulator("PitchModSrc");
const var FilterModSrc = Synth.getModulator("FilterModSrc");
const var TableIndexModSrc1 = Synth.getModulator("TableIndexModSrc1");

const var ModA = Content.getComponent("ModA");

inline function onModAControl(component, value)
{
PitchModSrc.setAttribute(PitchModSrc.A, value);
FilterModSrc.setAttribute(FilterModSrc.A, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.A, value);
};

Content.getComponent("ModA").setControlCallback(onModAControl);

const var ModH = Content.getComponent("ModH");

inline function onModHControl(component, value)
{
PitchModSrc.setAttribute(PitchModSrc.H,value);
FilterModSrc.setAttribute(FilterModSrc.H, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.H, value);
};

Content.getComponent("ModH").setControlCallback(onModHControl);

const var ModD = Content.getComponent("ModD");

inline function onModDControl(component, value)
{
PitchModSrc.setAttribute(PitchModSrc.D,value);
FilterModSrc.setAttribute(FilterModSrc.D, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.D, value);
};

Content.getComponent("ModD").setControlCallback(onModDControl);

const var ModS = Content.getComponent("ModS");

inline function onModSControl(component, value)
{
PitchModSrc.setAttribute(PitchModSrc.S,value);
FilterModSrc.setAttribute(FilterModSrc.S, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.S, value);
};

Content.getComponent("ModS").setControlCallback(onModSControl);

const var ModR = Content.getComponent("ModR");

inline function onModRControl(component, value)
{
PitchModSrc.setAttribute(PitchModSrc.R,value);
FilterModSrc.setAttribute(FilterModSrc.R, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.R, value);
};

Content.getComponent("ModR").setControlCallback(onModRControl);

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
 