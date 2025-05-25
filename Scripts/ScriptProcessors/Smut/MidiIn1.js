Content.makeFrontInterface(300, 200);

 const var rm = Engine.getGlobalRoutingManager();
 
 const cable1 = rm.getCable("trig1");
 const cable2 = rm.getCable("note1");
 const cable3 = rm.getCable("velo1");
 
 const var Min1 = Content.getComponent("Min1");
 const var Max1 = Content.getComponent("Max1");
 const var Step1 = Content.getComponent("Step1");
 const var CblSrc1 = Content.getComponent("CblSrc1");

 const var Note1 = Content.getComponent("Note1");
 
 
 cable2.setRange(36, 84);
 cable3.setRange(0, 127);


 inline function onSync(value)
  {


  local note = cable2.getValue();
  local vel = cable3.getValue();
  	
  	if (value == 1) {

		Synth.playNote(note, vel);
		Note1.setValue(note);
    	Note1.changed();
    //	Console.print("off"); 
  	   	 	}		
  	   	 	else{	
 // 	   	 		Console.print("off"); 
  	   	 	Note1.changed();
  	   		Engine.allNotesOff();
  	   	 	} 	
  	   	 	
  	 
  };
  

 cable1.registerCallback(onSync, SyncNotification); 
 

 function onNoteOn()
{
//	rm.setEventData(Message.getEventId(), 12, Note1.getValue());
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
 