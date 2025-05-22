
// Make sure to set the display buffer of the oscillator to the first slot
// Option 1: Use external display buffers
// ==============================================================================

// Get the script FX module as the display buffer source
const var dp = Synth.getDisplayBufferSource("scope1");

// Get the first external display buffer (in our case the peak node that we set 
// to be the External Display Buffer #1)
const var rb = dp.getDisplayBuffer(0);

const var BUFFER_LENGTH = 8192;

//8192
//16384

// These are the properties that you can give the peak meter
// NumChannels must be 1, but you can set another buffer length for the display
const var properties = {
  "BufferLength": BUFFER_LENGTH,
  "NumChannels": 1
};

// This will override the default properties of the node. You can use the same
// procedure to customize the FFT properties too (like Window type, etc).
rb.setRingBufferProperties(properties);

// Now let's add a simple panel for displaying the signalconst var P1 = Content.addPanel("OscVisual", 0, 0);
const var scp = Content.getComponent("VisPanel");


// We need to periodically query the ring buffer to create a signal path
// so we use the panel's timers for this.
scp.setTimerCallback(function()
{
	this.data.buffer = rb.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 1.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
});

scp.startTimer(30);

scp.setPaintRoutine(function(g)
{
	g.fillAll(0x00000000);
	g.setColour(0xFF7D7979);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});
