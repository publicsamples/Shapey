Content.makeFrontInterface(900, 900);


Synth.setUseUniformVoiceHandler("Shpy", true);
const var matrix = Engine.createModulationMatrix("Global Modulator Container1");
const var rm = Engine.getGlobalRoutingManager();

const var OscShaper1 = Synth.getEffect("OscShaper1");
const var OscShapeMod1 = Content.getComponent("OscShapeMod1");
const var OscShape1 = Content.getComponent("OscShape1");


//const cable1 = rm.getCable("shape1");

//cable1.setRange(0, 1);
const var c = rm.getCable("shp1");
//c.connectToGlobalModulator("Env1", true);
//c.connectToModuleParameter("OscShaper1", "shaper", {"MinValue": 0.0, "MaxValue": 1.0});
//c.registerCallback(function(value) {OscShapeMod1.setValue(value);}, false);

const var OscShapeInput1 = Content.getComponent("OscShapeInput1");

matrix.addParameterTarget({
	"Target": "OscShaper1",
	"Parameter": "shapein",
	"ID": "ShapeIn1",
	"Component": "OscShapeInput1",
	"Mode": matrix.Bipolar
});function onNoteOn()
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
 