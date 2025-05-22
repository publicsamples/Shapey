const var KnobLaf2 = Content.createLocalLookAndFeel();

KnobLaf2.registerFunction("drawRotarySlider", function(g, obj)
{

//	var textArea = Rect.removeFromBottom(obj.area, obj.area[3] - obj.area[2]);

	g.setColour(obj.textColour);
	
	//Font, Font Size, alignment (colour picked from property editor)
	
//	g.setFont("Lato Bold", 14.0);
//	g.drawAlignedText(obj.clicked ? obj.valueAsText : obj.text, textArea, "right");
	
	var start = isBipolar ? 0 : -2.7;
	
	var p = Content.createPath();

	p.startNewSubPath(0, 0);
	p.startNewSubPath(1,1);
	p.addArc([0.1, 0.1, 1.0, 1.0], start, -2.66 + Math.max(0.01, obj.valueNormalized) * 1 * 2.66);
	

//	Inner Ring Fill	(colour picked from property editor)
	g.setColour(Colours.withAlpha(obj.itemColour1, obj.clicked ? 1.0 : 0.8));
	
	//area, thickness
//	g.drawPath(p, Rect.scale(obj.area, 1), 8);

});

Content.getComponent("Pitch1").setLocalLookAndFeel(KnobLaf2);

