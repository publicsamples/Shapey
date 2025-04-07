
// Make sure to set the display buffer of the oscillator to the first slot
const var dps = Synth.getDisplayBufferSource("Shaper");

// Grab a reference to the display buffer
const var dp = dps.getDisplayBuffer(0);
//const var dp2 = dps.getDisplayBuffer(1);

const var OscVisual = Content.getComponent("OscVisual");



const var BUFFER_LENGTH = 8192;

const var properties = {
  "BufferLength": BUFFER_LENGTH,
  "NumChannels": 1
};

dp.setRingBufferProperties(properties);
//dp2.setRingBufferProperties(properties);

OscVisual.setTimerCallback(function()
{
	this.data.buffer = dp.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 4, 1.0], // [x_start, x_end, y_min, y_max]
								 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

OscVisual.startTimer(30);

OscVisual.setPaintRoutine(function(g)
{
	g.fillAll(0xFFCD5A58);
	g.setColour(0xFF2E4159);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});


