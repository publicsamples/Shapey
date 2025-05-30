const var KnobLaf4 = Content.createLocalLookAndFeel();




KnobLaf4.registerFunction("drawRotarySlider", function(g, obj)
{
	var underDrag = Content.getComponentUnderDrag() == obj.id;
	

	var textArea = Rect.removeFromBottom(obj.area, obj.area[3] - obj.area[2]);


	var isBipolar = obj.min < 0 && obj.id != "Knob1";
	var start = isBipolar ? 0 : -2.7;
	var modStart = isBipolar ? (-2.7 + obj.valueNormalized * 2 * 2.7) : -2.7;

	g.setColour(0x00000000);

	var radius = 25 - obj.clicked;

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
	g.drawEllipse(Rect.withSizeKeepingCentre(obj.area, radius-3, radius-3), 1);
	
	if(underDrag)
	{
		g.setColour(0xFF515151);

		
		g.fillEllipse(Rect.reduced(obj.area, 6));
	}
	
	g.setColour(Colours.black);
	g.rotate(-2.66 + obj.valueNormalized * 2.66 * 2, Rect.getCentre(obj.area));
	g.fillRect(Rect.translated(Rect.withSizeKeepingCentre(obj.area, 1, 10), 0, -8));
	
	
	
	//g.drawAlignedText(obj.text, obj.area, "centred");
});



const var ModSm = [Content.getComponent("GateStep1"),
                   Content.getComponent("VelStep1"),
                   Content.getComponent("PitchStep1"),
                   Content.getComponent("SeqDiv1"),
                   Content.getComponent("SeqDiv5"),
                   Content.getComponent("SeqMin1"),
                   Content.getComponent("Seqmax1"),
                   Content.getComponent("SeqScl1"),
         		  Content.getComponent("GateStep2"),
                   Content.getComponent("VelStep2"),
                   Content.getComponent("PitchStep2"),
                   Content.getComponent("SeqDiv2"),
                   Content.getComponent("SeqDiv2"),
                   Content.getComponent("SeqMin2"),
                   Content.getComponent("Seqmax2"),
                   Content.getComponent("SeqScl2"),
				   Content.getComponent("GateStep3"),
                   Content.getComponent("VelStep3"),
                   Content.getComponent("PitchStep3"),
                   Content.getComponent("SeqDiv3"),
                   Content.getComponent("SeqDiv3"),
                   Content.getComponent("SeqMin3"),
                   Content.getComponent("Seqmax3"),
                   Content.getComponent("SeqScl3"),
         		  Content.getComponent("GateStep4"),
                   Content.getComponent("VelStep4"),
                   Content.getComponent("PitchStep4"),
                   Content.getComponent("SeqDiv4"),
                   Content.getComponent("SeqDiv4"),
                   Content.getComponent("SeqMin4"),
                   Content.getComponent("Seqmax4"),
                   Content.getComponent("SeqScl4")];

const var LfoMidiVal1 = [Content.getComponent("LfoMidiMin1"),
						 Content.getComponent("LfoMidiMin2"),
						 Content.getComponent("LfoMidiMin3"),
						 Content.getComponent("LfoMidiMin4"),
                         Content.getComponent("LfoMidiMax1"),
                         Content.getComponent("LfoMidiMax2"),
                         Content.getComponent("LfoMidiMax3"),
                         Content.getComponent("LfoMidiMax4"),
                         Content.getComponent("LfoMidiStep1"),
                         Content.getComponent("LfoMidiStep2"),
                         Content.getComponent("LfoMidiStep3"),
                         Content.getComponent("LfoMidiStep4")];




for(s in LfoMidiVal1)
      s.setLocalLookAndFeel(KnobLaf4);  


