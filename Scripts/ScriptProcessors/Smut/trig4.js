 Content.makeFrontInterface(300, 200);
 
const var rm2 = Engine.getGlobalRoutingManager();
  
 const Trig2 = rm2.getCable("VGate4");
 
 const Lfo2 = rm2.getCable("LfoTrig4");
 
 
 
 Lfo2.setRange(0, 127);
 
 
  inline function onT3(value)
 { 
 
 local note = Lfo2.getValue();
 
 
 if (value == 1) {
   	
     Synth.playNoteFromUI(2, 61, 127);
   	
   	   }		
   	   	 
   	 else {
   	 
  	 Synth.noteOffFromUI(2, 44);
  //	 Engine.allNotesOff();
   	 
   	} 
 
 };
 
 Trig2.registerCallback(onT3, SyncNotification); 
 
 function onNoteOn()
{
	Message.ignoreEvent(Message.getChannel() != 2);
		
}
 function onNoteOff()
{
	Message.ignoreEvent(Message.getChannel() != 2);
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
 