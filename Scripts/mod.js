//mod

inline function onModTempoControl(component, value)
{
	PitchModSrc.setAttribute(PitchModSrc.tempo, value);
Filter.setAttribute(Filter.tempo, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.tempo, value);
shaper.setAttribute(shaper.tempoS, value);
shaper.setAttribute(shaper.tempoG, value);

};

Content.getComponent("ModTempo").setControlCallback(onModTempoControl);


inline function onModTrigControl(component, value)
{
		PitchModSrc.setAttribute(PitchModSrc.trig, value);
Filter.setAttribute(Filter.trig, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.trig, value);
shaper.setAttribute(shaper.syncS, value);
shaper.setAttribute(shaper.syncG, value);
};

Content.getComponent("ModTrig").setControlCallback(onModTrigControl);



inline function onModDivControl(component, value)
{
		PitchModSrc.setAttribute(PitchModSrc.div, value);
Filter.setAttribute(Filter.div, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.div, value);
shaper.setAttribute(shaper.divS, value);
shaper.setAttribute(shaper.divG, value);

};

Content.getComponent("ModDiv").setControlCallback(onModDivControl);


inline function onModAControl(component, value)
{
PitchModSrc.setAttribute(PitchModSrc.A, value);
Filter.setAttribute(Filter.A, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.A, value);
shaper.setAttribute(shaper.A, value);
};

Content.getComponent("ModA").setControlCallback(onModAControl);

const var ModH = Content.getComponent("ModH");

inline function onModHControl(component, value)
{
PitchModSrc.setAttribute(PitchModSrc.H,value);
Filter.setAttribute(Filter.H, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.H, value);
shaper.setAttribute(shaper.H, value);
};

Content.getComponent("ModH").setControlCallback(onModHControl);

const var ModD = Content.getComponent("ModD");

inline function onModDControl(component, value)
{
PitchModSrc.setAttribute(PitchModSrc.D,value);
Filter.setAttribute(Filter.D, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.D, value);
shaper.setAttribute(shaper.D, value);
};

Content.getComponent("ModD").setControlCallback(onModDControl);

const var ModS = Content.getComponent("ModS");

inline function onModSControl(component, value)
{
PitchModSrc.setAttribute(PitchModSrc.S,value);
Filter.setAttribute(Filter.S, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.S, value);
shaper.setAttribute(shaper.S, value);
};

Content.getComponent("ModS").setControlCallback(onModSControl);

const var ModR = Content.getComponent("ModR");

inline function onModRControl(component, value)
{
PitchModSrc.setAttribute(PitchModSrc.R,value);
Filter.setAttribute(Filter.R, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.R, value);
shaper.setAttribute(shaper.R, value);
};

Content.getComponent("ModR").setControlCallback(onModRControl);
