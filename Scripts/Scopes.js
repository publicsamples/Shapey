const var dp = Synth.getDisplayBufferSource("OscOut1");

const var rb = dp.getDisplayBuffer(1);

const var BUFFER_LENGTH = 256;

const var P1 = Content.getComponent("VisPanel");



// These are the properties that you can give the peak meter
// NumChannels must be 1, but you can set another buffer length for the display
const var properties = {
  "BufferLength": BUFFER_LENGTH,
  "NumChannels": 1
};

// This will override the default properties of the node. You can use the same
// procedure to customize the FFT properties too (like Window type, etc).
rb.setRingBufferProperties(properties);


// We need to periodically query the ring buffer to create a signal path
// so we use the panel's timers for this.
P1.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = rb.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

P1.startTimer(30);

P1.setPaintRoutine(function(g)
{
	g.fillAll(0x22FFFFFF);
	g.setColour(0xFFE27070);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

