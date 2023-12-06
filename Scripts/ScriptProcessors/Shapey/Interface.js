Content.makeFrontInterface(900, 600);

const var WavetableSynthesiser1 = Synth.getChildSynth("Wavetable Synthesiser1");

//Mod Env Shared Controls

const var PitchModSrc = Synth.getModulator("PitchModSrc");
const var FilterModSrc = Synth.getModulator("FilterModSrc");
const var TableIndexModSrc1 = Synth.getModulator("TableIndexModSrc1");
const var shaper = Synth.getEffect("shaper");

const var ModA = Content.getComponent("ModA");

inline function onModAControl(component, value)
{
PitchModSrc.setAttribute(PitchModSrc.A, value);
FilterModSrc.setAttribute(FilterModSrc.A, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.A, value);
shaper.setAttribute(shaper.A, value);
};

Content.getComponent("ModA").setControlCallback(onModAControl);

const var ModH = Content.getComponent("ModH");

inline function onModHControl(component, value)
{
PitchModSrc.setAttribute(PitchModSrc.H,value);
FilterModSrc.setAttribute(FilterModSrc.H, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.H, value);
shaper.setAttribute(shaper.H, value);
};

Content.getComponent("ModH").setControlCallback(onModHControl);

const var ModD = Content.getComponent("ModD");

inline function onModDControl(component, value)
{
PitchModSrc.setAttribute(PitchModSrc.D,value);
FilterModSrc.setAttribute(FilterModSrc.D, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.D, value);
shaper.setAttribute(shaper.D, value);
};

Content.getComponent("ModD").setControlCallback(onModDControl);

const var ModS = Content.getComponent("ModS");

inline function onModSControl(component, value)
{
PitchModSrc.setAttribute(PitchModSrc.S,value);
FilterModSrc.setAttribute(FilterModSrc.S, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.S, value);
shaper.setAttribute(shaper.S, value);
};

Content.getComponent("ModS").setControlCallback(onModSControl);

const var ModR = Content.getComponent("ModR");

inline function onModRControl(component, value)
{
PitchModSrc.setAttribute(PitchModSrc.R,value);
FilterModSrc.setAttribute(FilterModSrc.R, value);
TableIndexModSrc1.setAttribute(TableIndexModSrc1.R, value);
shaper.setAttribute(shaper.R, value);
};

Content.getComponent("ModR").setControlCallback(onModRControl);


const var Gmod1 = Synth.getModulator("Gmod1");
const var mods3 = [];

mods3[0] = Content.getComponent("LFO1");
mods3[1] = Content.getComponent("Table3");
mods3[2] = Content.getComponent("8step3");
mods3[3] = Content.getComponent("8Trig3");

inline function onMODSEL3Control(component, value)

{

	if(value == 1)
	{
	
	Gmod1.setAttribute(Gmod1.modsel, 0);
      mods3[0].showControl(1);  
      mods3[1].showControl(0);   
      mods3[2].showControl(0);  
      mods3[3].showControl(0);    
         
	}
	
		if(value == 2)
	{

      Gmod1.setAttribute(Gmod1.modsel, 1.7);
      mods3[0].showControl(0);  
      mods3[1].showControl(1);   
      mods3[2].showControl(0);  
      mods3[3].showControl(0);  
	  
	}
	
	if(value == 3)
	{
	
	Gmod1.setAttribute(Gmod1.modsel, 2.7);
   mods3[0].showControl(0);  
      mods3[1].showControl(0);   
      mods3[2].showControl(1);  
      mods3[3].showControl(0);  
	  
	}
	
	if(value == 4)
	{
	
	Gmod1.setAttribute(Gmod1.modsel, 4);
   mods3[0].showControl(0);  
      mods3[1].showControl(0);   
      mods3[2].showControl(0);  
      mods3[3].showControl(1);  
	  
	}
};


Content.getComponent("MODSEL3").setControlCallback(onMODSEL3Control);

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
 