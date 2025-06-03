const var KnobLaf = Content.createLocalLookAndFeel();




KnobLaf.registerFunction("drawRotarySlider", function(g, obj)
{
	var underDrag = Content.getComponentUnderDrag() == obj.id;
	

	var textArea = Rect.removeFromBottom(obj.area, obj.area[3] - obj.area[2]);


	var isBipolar = obj.min < 0 && obj.id != "Knob1";
	var start = isBipolar ? 0 : -2.7;
	var modStart = isBipolar ? (-2.7 + obj.valueNormalized * 2 * 2.7) : -2.7;

	g.setColour(0x00000000);

	var radius = 35 - obj.clicked;

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
                      Content.getComponent("Bend1"), 
                      Content.getComponent("Bend2"), 
                      Content.getComponent("Bend3"), 
                      Content.getComponent("Bend4"), 
                      Content.getComponent("HarmStep1"), 
                      Content.getComponent("Div1"),
                      Content.getComponent("PitchMod1"),
                      Content.getComponent("InputMod1"),
                      Content.getComponent("WidthMod1"),
                      Content.getComponent("OutMod1"),
                      Content.getComponent("ShapeMod1"),
                	  Content.getComponent("Step2"),
                      Content.getComponent("FmIn2"), 
                      Content.getComponent("HarmStep2"), 
                      Content.getComponent("Div2"),
                      Content.getComponent("PitchMod2"),
                      Content.getComponent("InputMod2"),
                      Content.getComponent("WidthMod2"),
                      Content.getComponent("OutMod2"),
                	  Content.getComponent("Step3"),
                      Content.getComponent("FmIn3"), 
                      Content.getComponent("HarmStep3"), 
                      Content.getComponent("Div3"),
                      Content.getComponent("PitchMod3"),
                      Content.getComponent("InputMod3"),
                      Content.getComponent("WidthMod3"),
                      Content.getComponent("OutMod3"),
                      Content.getComponent("ShapeMod3"),
                	  Content.getComponent("Step4"),
                      Content.getComponent("FmIn4"), 
                      Content.getComponent("HarmStep4"), 
                      Content.getComponent("Div4"),
                      Content.getComponent("PitchMod4"),
                      Content.getComponent("InputMod4"),
                      Content.getComponent("WidthMod4"),
                      Content.getComponent("OutMod4"),
                      Content.getComponent("ShapeMod4")];



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
                     Content.getComponent("WinMod1"),
                     Content.getComponent("WinXfMod1"),
                     Content.getComponent("FileInMod1"),
                     Content.getComponent("PosModTempo1"),
                     Content.getComponent("PosModDiv1"),
                     Content.getComponent("PosMod1"),
                Content.getComponent("FileSmooth2"),
                Content.getComponent("FileMix2"),
                Content.getComponent("FilePitch2"),
                Content.getComponent("FileWin2"),
                Content.getComponent("FileXf2"),
                Content.getComponent("FileWinTempo2"),
                Content.getComponent("FileXfTempo2"),
                Content.getComponent("Feed2"),
                Content.getComponent("FileTempoMod2"),
                Content.getComponent("FilePitchMod2"),
                Content.getComponent("WinMod2"),
                Content.getComponent("WinXfMod2"),
                Content.getComponent("FileInMod2"),
                Content.getComponent("PosModTempo2"),
                Content.getComponent("PosModDiv2"),
                Content.getComponent("PosMod2"),
                Content.getComponent("FileSmooth3"),
                Content.getComponent("FileMix3"),
                Content.getComponent("FilePitch3"),
                Content.getComponent("FileWin3"),
                Content.getComponent("FileXf3"),
                Content.getComponent("FileWinTempo3"),
                Content.getComponent("FileXfTempo3"),
                Content.getComponent("Feed3"),
                Content.getComponent("FileTempoMod3"),
                Content.getComponent("FilePitchMod3"),
                Content.getComponent("WinMod3"),
                Content.getComponent("WinXfMod3"),
                Content.getComponent("FileInMod3"),
                Content.getComponent("PosModTempo3"),
                Content.getComponent("PosModDiv3"),
                Content.getComponent("PosMod3"),
                Content.getComponent("FileSmooth4"),
                Content.getComponent("FileMix4"),
                Content.getComponent("FilePitch4"),
                Content.getComponent("FileWin4"),
                Content.getComponent("FileXf4"),
                Content.getComponent("FileWinTempo4"),
                Content.getComponent("FileXfTempo4"),
                Content.getComponent("Feed4"),
                Content.getComponent("FileTempoMod4"),
                Content.getComponent("FilePitchMod4"),
                Content.getComponent("WinMod4"),
                Content.getComponent("WinXfMod4"),
                Content.getComponent("FileInMod4"),
                Content.getComponent("PosModTempo4"),
                Content.getComponent("PosModDiv4"),
                Content.getComponent("PosMod4")];

 for(s in ShpKnbs)
       s.setLocalLookAndFeel(KnobLaf);     
       
const var FltrKnbs = [Content.getComponent("FxMix2"),
                      Content.getComponent("VcaPan1"),
                      Content.getComponent("VcaGain1"),
                      Content.getComponent("FilterMixMod3"),
                      Content.getComponent("FilterMixMod2"),                   
                      Content.getComponent("FilterMixMod1"),
					  Content.getComponent("FxMix3"),
                      Content.getComponent("VcaPan2"),
                      Content.getComponent("VcaGain2"),
                      Content.getComponent("FilterMixMod6"),
                      Content.getComponent("FilterMixMod5"),                   
                      Content.getComponent("FilterMixMod4"),
         			  Content.getComponent("FxMix4"),
                      Content.getComponent("VcaPan3"),
                      Content.getComponent("VcaGain3"),
                      Content.getComponent("FilterMixMod9"),
                      Content.getComponent("FilterMixMod8"),                   
                      Content.getComponent("FilterMixMod7"),
					  Content.getComponent("FxMix5"),
                      Content.getComponent("VcaPan4"),
                      Content.getComponent("VcaGain4"),
                      Content.getComponent("FilterMixMod12"),
                      Content.getComponent("FilterMixMod11"),                   
                      Content.getComponent("FilterMixMod10")];

for(s in FltrKnbs)
      s.setLocalLookAndFeel(KnobLaf);  
      
const var LfoMods1 = [Content.getComponent("LfoGateMod1"),
					  Content.getComponent("LfoGateMod2"),
					  Content.getComponent("LfoGateMod3"),
					  Content.getComponent("LfoGateMod4"),
                      Content.getComponent("LfoTempoMod1"),
                      Content.getComponent("LfoTempoMod2"),
                      Content.getComponent("LfoTempoMod3"),
                      Content.getComponent("LfoTempoMod4"),
                      Content.getComponent("XfadeMod"),
                      Content.getComponent("LfoDivMod1"),
                      Content.getComponent("LfoDivMod2"),
                      Content.getComponent("LfoDivMod3"),
                      Content.getComponent("LfoDivMod4"),
                      Content.getComponent("AdjMod1"),
                      Content.getComponent("AdjMod2"),
                      Content.getComponent("AdjMod3"),
                      Content.getComponent("AdjMod4")];


for(s in LfoMods1)
      s.setLocalLookAndFeel(KnobLaf);  

const var SeqMods = [Content.getComponent("SeqTempoMod1"),
                     Content.getComponent("SeqClockMod1"),
                     Content.getComponent("SeqTempoMod2"),
                     Content.getComponent("SeqClockMod2"),
					 Content.getComponent("SeqTempoMod3"),
                     Content.getComponent("SeqClockMod3"),
                     Content.getComponent("SeqTempoMod4"),
                     Content.getComponent("SeqClockMod4")];

 

  for(s in SeqMods)
        s.setLocalLookAndFeel(KnobLaf);      
