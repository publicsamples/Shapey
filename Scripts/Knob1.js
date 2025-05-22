const var KnobLaf = Content.createLocalLookAndFeel();

KnobLaf.registerFunction("drawRotarySlider", function(g, obj)
{
//	var underDrag = Content.getComponentUnderDrag() == obj.id;

//	var textArea = Rect.removeFromBottom(obj.area, obj.area[3] - obj.area[2]);

	g.setColour(obj.textColour);
	
	//Font, Font Size, alignment (colour picked from property editor)
	
	g.setFont("Lato Bold", 14.0);
	g.drawAlignedText(obj.clicked ? obj.valueAsText : obj.text, textArea, "centred");
	
	var isBipolar = obj.min < 0 && obj.id != "Knob1";
	var start = isBipolar ? 0 : -2.7;
	var modStart = isBipolar ? (-2.7 + obj.valueNormalized * 2 * 2.7) : -2.7;

	//Drop Shadow colour
	
	g.setColour(0x10000000);
	
	// Knob Size

	var radius = 50 - obj.clicked;

//	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 2));
//	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 3));
//	g.fillEllipse(Rect.translated(Rect.withSizeKeepingCentre(obj.area, radius + 2, radius +2), 0, 4));
	
	var p = Content.createPath();
	
	p.startNewSubPath(0, 0);
	p.startNewSubPath(1,1);
	p.addArc([0.0, 0.0, 1.0, 1.0], -2.7, 2.7);
	
	// Inner Ring Colour

	g.setColour(0xFF303030);
	
	//Draw inner ring
	g.drawPath(p, Rect.reduced(obj.area, 5), 4);
	
	// Outer Ring Colour
	g.setColour(underDrag ? 0xFF303030 : 0xFF303030);
	
	//Draw outer ring
	g.drawPath(p, Rect.reduced(obj.area, 1), 2);

	p = Content.createPath();
		
	p.startNewSubPath(0, 0);
	p.startNewSubPath(1,1);
	p.addArc([0.0, 0.0, 1.0, 1.0], start, -2.66 + Math.max(0.01, obj.valueNormalized) * 2 * 2.66);

//	Inner Ring Fill	(colour picked from property editor)
	g.setColour(Colours.withAlpha(obj.itemColour1, obj.clicked ? 1.0 : 0.8));
	g.drawPath(p, Rect.reduced(obj.area, 5), 4);
	
	p = Content.createPath();
			
	p.startNewSubPath(0, 0);
	p.startNewSubPath(1,1);

	
	g.setColour(Colours.withAlpha(obj.itemColour1, obj.clicked ? 0.8 : 0.5));
	g.drawPath(p, Rect.reduced(obj.area, 1), 2);
	
	
g.setGradientFill([0xFF303030, 0.0, 0.0,
					   0xFF515050, 0.0, obj.area[3], false]);
	g.fillEllipse(Rect.withSizeKeepingCentre(obj.area, radius, radius));

	

	

	
	//g.drawAlignedText(obj.text, obj.area, "centred");
});

Content.getComponent("Pitch1").setLocalLookAndFeel(KnobLaf);
Content.getComponent("FmSrc1").setLocalLookAndFeel(KnobLaf);
Content.getComponent("OscShapeInput1").setLocalLookAndFeel(KnobLaf);
