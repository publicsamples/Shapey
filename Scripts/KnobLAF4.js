const var KnobLaf2 = Content.createLocalLookAndFeel();



KnobLaf2.registerFunction("drawRotarySlider", function(g, obj)
{
	var underDrag = Content.getComponentUnderDrag() == obj.id;
	

//	var textArea = Rect.removeFromBottom(obj.area, obj.area[3] - obj.area[2]);


	var isBipolar = obj.min < 0 && obj.id != "Knob1";
	var start = isBipolar ? 0 : -2.7;
	var modStart = isBipolar ? (-2.7 + obj.valueNormalized * 2 * 2.7) : -2.7;


	g.setColour(obj.bgColour);

	var radius = 65 - obj.clicked;

//	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 2));
//	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 3));
//	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 4));
	
	

	var p = Content.createPath();
	
//	p.startNewSubPath(0, 0);
//	p.startNewSubPath(1,1);
//	p.addArc([0.0, 0.0, 1.0, 1.0], -2.7, 2.7);
	
	g.setColour( obj.itemColour1);
	g.drawPath(p, Rect.reduced(obj.area, 5), 4);
	g.setColour(underDrag ? 0xFF303030 : 0xFF303030);
	g.drawPath(p, Rect.reduced(obj.area, 2), 2);

	p = Content.createPath();
		
	p.startNewSubPath(0, 0);
	p.startNewSubPath(1,1);
//	p.addArc([0.0, 0.0, 1.0, 1.0], start, -2.66 + Math.max(0.01, obj.valueNormalized) * 2 * 2.66);
	
//	g.setColour(Colours.withAlpha(obj.itemColour1, obj.clicked ? 1.0 : 0.8));
//	g.drawPath(p, Rect.reduced(obj.area, 5), 4);
	
//	p = Content.createPath();
			
//	p.startNewSubPath(0, 0);
//	p.startNewSubPath(1,1);
//	var modValue = matrix.getModValue(obj.id);
	

	
	g.setGradientFill([obj.bgColour, 0.0, 0.0,
					   obj.bgColour, 0.0, obj.area[5], false]);
	g.fillEllipse(Rect.withSizeKeepingCentre(obj.area, radius-1, radius-1));
	

	
	g.setGradientFill([obj.itemColour2, 0.0, 0.0,
					   obj.itemColour2, 0.0, obj.area[5], false]);
	g.drawEllipse(Rect.withSizeKeepingCentre(obj.area, radius-0, radius-0), 1);
	
	if(underDrag)
	{
		g.setColour(obj.bgColour);

		
		g.fillEllipse(Rect.reduced(obj.area, 6));
	}
	
	g.setColour(Colours.black);
	g.rotate(-2.66 + obj.valueNormalized * 2.66 * 2, Rect.getCentre(obj.area));
	g.fillRect(Rect.translated(Rect.withSizeKeepingCentre(obj.area, 2, 20), 0, -20));
	
	
	
//	g.drawAlignedText(obj.text, obj.area, "centred");
});



const var BigKnbs = [Content.getComponent("FilePos1"),
                     Content.getComponent("XfParamB2"),
                     Content.getComponent("XfParamA2"),
                     Content.getComponent("Pitch1"),
                     Content.getComponent("Harm1"),
                     Content.getComponent("Tempo1"),
                     Content.getComponent("Tempo1"),
                     Content.getComponent("FileIn1"),
                     Content.getComponent("OscShapeInput1")];


for(s in BigKnbs)
      s.setLocalLookAndFeel(KnobLaf2);
      
      
