Processor 
Type SynthChain ID Preset Bypassed Gain 	      �?Balance 	        VoiceLimit 	      P@KillFadeTime 	      4@IconColour 0 packageName  BuildVersion �  EditorStates BodyShown 0 Visible 1 Solo 0 Folded 1  ChildProcessors  Processor Type MidiProcessorChain ID Midi Processor Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor Type ScriptProcessor ID Interface Bypassed Script �Content.makeFrontInterface(600, 600);function onNoteOn()
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
  EditorStates BodyShown 1 Visible 1 Solo 0 contentShown 1 onInitOpen 1  ChildProcessors   Content   UIData  ContentProperties DeviceType 	Desktop  Processor Type ScriptProcessor ID Script Processor1 Bypassed Script B /*
 The MIT License (MIT)
 
 Copyright © 2017, 2018, 2019, 2020, 2021, 2022 David Healey
 
 Permission is hereby granted, free of charge, to any person obtaining
 a copy of this file (the “Software”), to deal in the Software without
 restriction, including without limitation the rights to use, copy,
 modify, merge, publish, distribute, sublicense, and/or sell copies of
 the Software, and to permit persons to whom the Software is furnished
 to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included
 in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS
 OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
 
 Content.setWidth(650);
 Content.setHeight(50);
 
 reg lastNote = -1;
 reg retrigger = -1;
 reg eventId;
 reg lastTuning = 0;
 
 //GUI
 const var bypass = Content.addButton("Bypass", 10, 10);
 
 const var time = Content.addKnob("Time", 160, 0);
 time.setRange(0, 2000, 0.01);
 
 function onNoteOn()
 {
     if (!bypass.getValue())
     {
         if (lastNote == -1)
         {
             lastNote = Message.getNoteNumber();
             eventId = Message.makeArtificial();
         }
         else
         {
             if (time.getValue() > 0 && eventId != -1)
             {
                 Message.ignoreEvent(true);                
                 Synth.addPitchFade(eventId, time.getValue(), lastTuning + Message.getNoteNumber()-lastNote, 0);                    
                 lastTuning = lastTuning + Message.getNoteNumber()-lastNote;
             }
             else
             {
                 if (eventId != -1) Synth.noteOffByEventId(eventId);
                     
                 eventId = Message.makeArtificial();
             }
             retrigger = lastNote;
             lastNote = Message.getNoteNumber();
         }
     }
 }
 
 function onNoteOff()
 {
     if (!bypass.getValue())
     {
         Message.ignoreEvent(true);
 
         if (eventId != -1 && Message.getNoteNumber() == lastNote)
         {
           if (Synth.isKeyDown(retrigger))
           {
               Synth.addPitchFade(eventId, time.getValue(), 0, 0);
               lastTuning = 0;
               lastNote = retrigger;
               retrigger = -1;
           }
           else
           {
               Synth.noteOffByEventId(eventId);
               eventId = -1; 
           }
         }
 
         if (!Synth.getNumPressedKeys())
         {
             lastNote = -1;
             lastTuning = 0;
         }
     }
     else if (eventId != -1 && eventId != undefined)
     {
         Synth.noteOffByEventId(eventId);
         eventId = -1;
         lastNote = -1;
         lastTuning = 0;
     }
 }
 
 function onController()
 {
 	
 }
  function onTimer()
 {
 	
 }
  function onControl(number, value)
 {
 	
 }function onNoteOn()
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
  EditorStates BodyShown 1 Visible 1 Solo 0 contentShown 1 onInitOpen 1  ChildProcessors   Content  Control type ScriptButton id Bypass value 	      �? Control type ScriptSlider id Time value 	     @�@ UIData  ContentProperties DeviceType 	Desktop Component type ScriptButton id Bypass x 
   y 
    Component 
type ScriptSlider id Time x �   y     style Knob middlePosition 	      �max 	     @�@suffix  filmstripImage Use default skin linkedTo   Processor Type ModulatorChain ID GainModulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type ModulatorChain ID PitchModulation Bypassed Intensity 	        EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type EffectChain ID FX Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type GlobalModulatorContainer ID Global Modulator Container1 Bypassed Gain 	      �?Balance 	        VoiceLimit 	      p@KillFadeTime 	      4@IconColour 0 EditorStates BodyShown 1 Visible 1 Solo 0 Folded 1  ChildProcessors  Processor Type MidiProcessorChain ID Midi Processor Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type ModulatorChain ID Global Modulators Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor Type ScriptTimeVariantModulator ID  Script Time Variant Modulator1 Bypassed Intensity 	      �?Bipolar Script � function prepareToPlay(sampleRate, samplesPerBlock)
{
	
}
 function processBlock(buffer)
{
	
}
 function onNoteOn()
{
	
}
 function onNoteOff()
{
	
}
 function onController()
{
	
}
 function onControl(number, value)
{
	
}
  EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors   Content   Networks  Network ID env Version 0.0.0  UIData  ContentProperties DeviceType 	Desktop  Processor Type ModulatorChain ID PitchModulation Bypassed Intensity 	        EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   Processor Type EffectChain ID FX Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors   RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� Processor 	Type ScriptSynth ID Scriptnode Syntesiser1 Bypassed Gain 	      �?Balance 	        VoiceLimit 	      p@KillFadeTime 	      4@IconColour 0 Script , function onControl(number, value)
{
	
}
  EditorStates BodyShown 1 Visible 1 Solo 0 Folded 1  ChildProcessors  Processor Type MidiProcessorChain ID Midi Processor Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor Type LegatoWithRetrigger ID Legato with Retrigger1 Bypassed EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors   Content   Processor Type ScriptProcessor ID Script Processor1 Bypassed Script � function onNoteOn()
{
Synth.noteOffDelayedByEventId(64,127);
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
  EditorStates BodyShown 1 Visible 1 Solo 0 contentShown 1 onInitOpen 1  ChildProcessors   Content  Control type ScriptButton id Bypass value 	      �? Control type ScriptSlider id Time value 	     @�@ UIData  ContentProperties DeviceType 	Desktop Component type ScriptButton id Bypass x 
   y 
    Component type ScriptSlider id Time x �   y     max 	     @�@ Processor Type ModulatorChain ID GainModulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor 	Type SimpleEnvelope ID DefaultEnvelope1 Bypassed Monophonic 	        Retrigger 	      �?Intensity 	      �?Attack 	      @Release 	      $@LinearMode 	      �?EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors  Processor Type ModulatorChain ID Attack Time Modulation Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0 Folded 1  ChildProcessors   Processor Type ModulatorChain ID PitchModulation Bypassed Intensity 	        EditorStates BodyShown 1 Visible 0 Solo 0 Folded 1  ChildProcessors   Processor Type EffectChain ID FX Bypassed EditorStates BodyShown 1 Visible 0 Solo 0  ChildProcessors  Processor Type 
ScriptFX ID Script FX1 Bypassed Script � function prepareToPlay(sampleRate, blockSize)
{
	
}
 function processBlock(channels)
{
	
}
 function onControl(number, value)
{
	
}
  EditorStates BodyShown 1 Visible 1 Solo 0  ChildProcessors   RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� Content   Networks  Network ID gtest Version 0.0.0 AllowPolyphonic 1  UIData  ContentProperties DeviceType 	Desktop  Processor Type ModulatorChain ID Extra1 Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0 Folded 1  ChildProcessors   Processor Type ModulatorChain ID Extra2 Bypassed Intensity 	      �?EditorStates BodyShown 1 Visible 0 Solo 0 Folded 1  ChildProcessors   RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� Content   UIData  ContentProperties DeviceType 	Desktop  RoutingMatrix NumSourceChannels    Channel0     Send0 ����Channel1    Send1 ���� macro_controls  macro name 	Macro 1 value 	        midi_cc ���� macro name 	Macro 2 value 	        midi_cc ���� macro name 	Macro 3 value 	        midi_cc ���� macro name 	Macro 4 value 	        midi_cc ���� macro name 	Macro 5 value 	        midi_cc ���� macro name 	Macro 6 value 	        midi_cc ���� macro name 	Macro 7 value 	        midi_cc ���� macro name 	Macro 8 value 	        midi_cc ���� MidiAutomation   MPEData Enabled  