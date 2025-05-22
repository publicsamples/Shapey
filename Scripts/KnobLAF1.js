const var KnobLaf = Content.createLocalLookAndFeel();




KnobLaf.registerFunction("drawRotarySlider", function(g, obj)
{
	var underDrag = Content.getComponentUnderDrag() == obj.id;
	

	var textArea = Rect.removeFromBottom(obj.area, obj.area[3] - obj.area[2]);


	var isBipolar = obj.min < 0 && obj.id != "Knob1";
	var start = isBipolar ? 0 : -2.7;
	var modStart = isBipolar ? (-2.7 + obj.valueNormalized * 2 * 2.7) : -2.7;

	g.setColour(0x00000000);

	var radius = 40 - obj.clicked;

	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 2));
	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 3));
	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 4));
	
	

	var p = Content.createPath();
	
//	p.startNewSubPath(0, 0);
//	p.startNewSubPath(1,1);
//	p.addArc([0.0, 0.0, 1.0, 1.0], -2.7, 2.7);
	
	g.setColour( obj.itemColour1);
	g.drawPath(p, Rect.reduced(obj.area, 5), 4);
	g.setColour(underDrag ? 0xFF303030 : 0xFF303030);
	g.drawPath(p, Rect.reduced(obj.area, 1), 2);

	p = Content.createPath();
		
	p.startNewSubPath(0, 0);
	p.startNewSubPath(1,1);
//	p.addArc([0.0, 0.0, 1.0, 1.0], start, -2.66 + Math.max(0.01, obj.valueNormalized) * 2 * 2.66);
	
	g.setColour(Colours.withAlpha(obj.itemColour1, obj.clicked ? 1.0 : 0.8));
	g.drawPath(p, Rect.reduced(obj.area, 5), 4);
	
	p = Content.createPath();
			
	p.startNewSubPath(0, 0);
	p.startNewSubPath(1,1);
//	var modValue = matrix.getModValue(obj.id);
	
	
///	p.addArc([0.0, 0.0, 1.0, 1.0], modStart, -2.66 + Math.max(0.01, modValue) * 2 * 2.66);
	
	g.setColour(Colours.withAlpha(obj.itemColour1, obj.clicked ? 0.8 : 0.5));
	g.drawPath(p, Rect.reduced(obj.area, 1), 2);

//	g.addDropShadowFromAlpha(0x44000000, 2);
	
	g.setGradientFill([obj.bgColour, 0.0, 0.0,
					   obj.bgColour, 0.0, obj.area[3], false]);
	g.fillEllipse(Rect.withSizeKeepingCentre(obj.area, radius, radius));
	

	
	g.setGradientFill([obj.itemColour2, 0.0, 0.0,
					   obj.itemColour2, 0.0, obj.area[3], true]);
	g.drawEllipse(Rect.withSizeKeepingCentre(obj.area, radius-3, radius-3), 3.5);
	
	if(underDrag)
	{
		g.setColour(0xFF515151);

		
		g.fillEllipse(Rect.reduced(obj.area, 6));
	}
	
	g.setColour(Colours.black);
	g.rotate(-2.66 + obj.valueNormalized * 2.66 * 2, Rect.getCentre(obj.area));
	g.fillRect(Rect.translated(Rect.withSizeKeepingCentre(obj.area, 2, 11), 0, -8));
	
	
	
	//g.drawAlignedText(obj.text, obj.area, "centred");
});


KnobLaf.registerFunction("drawTableRuler", function(g, obj)
{
    g.setColour(Colours.withAlpha(obj.textColour, 5));
    
    var x = obj.position * obj.area[2];
    
    g.drawLine(x, x, 0, obj.area[3], 0.0);
    g.setColour(obj.bgColour);
    g.drawLine(x, x, 0, obj.area[3], 1);
});

const var UserShape1 = Content.getComponent("UserShape1").setLocalLookAndFeel(KnobLaf);     ;


const var OscKnobs = [Content.getComponent("Step1"),
                      Content.getComponent("FmIn1"), 
                      Content.getComponent("HarmStep1"), 
                      Content.getComponent("Div1"), 
                      Content.getComponent("Input1"),
                      Content.getComponent("Width1"),
                      Content.getComponent("PitchMod1"),
                      Content.getComponent("InputMod1"),
                      Content.getComponent("WidthMod1"),
                      Content.getComponent("OutMod1"),
                      Content.getComponent("ShapeMod1")];



for(s in OscKnobs)
      s.setLocalLookAndFeel(KnobLaf);

const var ShpKnbs = [Content.getComponent("FileSmooth1"),
                     Content.getComponent("FileMix1"),
                     Content.getComponent("FilePitch1"),
                     Content.getComponent("FileWin1"),
                     Content.getComponent("FileXf1"),
                     Content.getComponent("FileWinTempo1"),
           			 Content.getComponent("FileXfTempo1"),
                     Content.getComponent("Feed1"),
                     Content.getComponent("FileTempoMod1"),
                     Content.getComponent("FilePitchMod1"),
                     Content.getComponent("FileInMod1"),
                     Content.getComponent("PosModTempo1"),
                     Content.getComponent("PosModDiv1"),
                     Content.getComponent("PosMod1")];

 for(s in ShpKnbs)
       s.setLocalLookAndFeel(KnobLaf);     
       
const var FltrKnbs = [Content.getComponent("FxMix2"),
                      Content.getComponent("XfParamB3"),
                      Content.getComponent("FilterMixMod3"),
                      Content.getComponent("FilterMixMod2"),                   
                      Content.getComponent("FilterMixMod1")];

for(s in FltrKnbs)
      s.setLocalLookAndFeel(KnobLaf);  

      
