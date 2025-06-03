Content.makeFrontInterface(300, 200);

const var rm = Engine.getGlobalRoutingManager();
 
const Trig1 = rm.getCable("VGate1");

const Lfo1 = rm.getCable("Vnote1");



Lfo1.setRange(0, 127);


 inline function onT2(value)
{ 

local note = Lfo1.getValue();

 if (value == 1) {
   	
     Synth.playNoteFromUI(1, note, 127);
   	
   	   }		
   	   	 
   	 else {
   	 
  	 Synth.noteOffFromUI(1, note);
  //	 Engine.allNotesOff();
   	 
   	} 

};

Trig1.registerCallback(onT2, SyncNotification); 

function onNoteOn()
{
Message.ignoreEvent(Message.getChannel() != 1);
	
}
 function onNoteOff()
{
	Message.ignoreEvent(Message.getChannel() != 1);
	
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
 