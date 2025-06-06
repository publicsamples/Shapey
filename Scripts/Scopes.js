//osc1

const var OsdDp1 = Synth.getDisplayBufferSource("Osc1");
const var rb1 = OsdDp1.getDisplayBuffer(0);
const var OsdDp2 = Synth.getDisplayBufferSource("Osc2");
const var rb2 = OsdDp2.getDisplayBuffer(0);
const var OsdDp3 = Synth.getDisplayBufferSource("Osc3");
const var rb3 = OsdDp3.getDisplayBuffer(0);
const var OsdDp4 = Synth.getDisplayBufferSource("Osc4");
const var rb4 = OsdDp4.getDisplayBuffer(0);

const var BUFFER_LENGTH1 = 256;
const var P1 = Content.getComponent("VisPanel");
const var P2 = Content.getComponent("VisPanel1");
const var P3 = Content.getComponent("VisPanel2");
const var P4 = Content.getComponent("VisPanel3");

// These are the properties that you can give the peak meter
// NumChannels must be 1, but you can set another buffer length for the display
const var properties = {
  "BufferLength": BUFFER_LENGTH1,
  "NumChannels": 1
};

// This will override the default properties of the node. You can use the same
// procedure to customize the FFT properties too (like Window type, etc).
rb1.setRingBufferProperties(properties);
rb2.setRingBufferProperties(properties);
rb3.setRingBufferProperties(properties);
rb4.setRingBufferProperties(properties);

// We need to periodically query the ring buffer to create a signal path
// so we use the panel's timers for this.
P1.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = rb1.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH1, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

P1.startTimer(30);

//OSC2

P1.setPaintRoutine(function(g)
{
	g.fillAll(0x22FFFFFF);
	g.setColour(0xFFE27070);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

P2.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = rb2.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH1, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

P2.startTimer(30);

P2.setPaintRoutine(function(g)
{
	g.fillAll(0x22FFFFFF);
	g.setColour(0xFFE27070);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

//OSC3

P3.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = rb3.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH1, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

P1.startTimer(30);

P3.setPaintRoutine(function(g)
{
	g.fillAll(0x22FFFFFF);
	g.setColour(0xFFE27070);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

//OSC4

P4.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = rb4.createPath(this.getLocalBounds(0), // area
									 [0, BUFFER_LENGTH1, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

P4.startTimer(30);

P4.setPaintRoutine(function(g)
{
	g.fillAll(0x22FFFFFF);
	g.setColour(0xFFE27070);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});



//LFO 1

const var properties2 = {
  "BufferLength": BUFFER_LENGTH2,
  "NumChannels": 1
};

const var BUFFER_LENGTH2 = 16384;

const var dpLFO1 = Synth.getDisplayBufferSource("LFO1");
const var dpLFO2 = Synth.getDisplayBufferSource("LFO2");
const var dpLFO3 = Synth.getDisplayBufferSource("LFO3");
const var dpLFO4 = Synth.getDisplayBufferSource("LFO4");
const var dpENV1 = Synth.getDisplayBufferSource("Env1");
const var dpENV2 = Synth.getDisplayBufferSource("Env2");

const var dpl1 = dpLFO1.getDisplayBuffer(0);
const var dpl2 = dpLFO2.getDisplayBuffer(0);
const var dpl3 = dpLFO3.getDisplayBuffer(0);
const var dpl4 = dpLFO4.getDisplayBuffer(0);
const var dpl5 = dpENV1.getDisplayBuffer(0);
const var dpl6 = dpENV2.getDisplayBuffer(0);
const var dpl7 = dpENV1.getDisplayBuffer(2);
const var dpl8 = dpENV2.getDisplayBuffer(2);

dpl1.setRingBufferProperties(properties2);
dpl2.setRingBufferProperties(properties2);
dpl3.setRingBufferProperties(properties2);
dpl4.setRingBufferProperties(properties2);
dpl5.setRingBufferProperties(properties2);
dpl6.setRingBufferProperties(properties2);
dpl7.setRingBufferProperties(properties2);
dpl8.setRingBufferProperties(properties2);

const var LfoShapeVis1 = Content.getComponent("LfoShapeVis1");
const var LfoShapeVis2 = Content.getComponent("LfoShapeVis2");
const var LfoShapeVis3 = Content.getComponent("LfoShapeVis3");
const var LfoShapeVis4 = Content.getComponent("LfoShapeVis4");
const var LfoShapeVis5 = Content.getComponent("LfoShapeVis5");
const var LfoShapeVis6 = Content.getComponent("LfoShapeVis6");
const var AdjVis1 = Content.getComponent("AdjVis1");
const var AdjVis2 = Content.getComponent("AdjVis2");
const var AdjVis3 = Content.getComponent("AdjVis3");
const var AdjVis4 = Content.getComponent("AdjVis4");








LfoShapeVis1.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = dpl1.createPath(this.getLocalBounds(2), // area
									 [0, BUFFER_LENGTH2, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

LfoShapeVis1.startTimer(30);

LfoShapeVis1.setPaintRoutine(function(g)
{
	g.fillAll(0x22FFFFFF);
	g.setColour(0xFFE27070);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

LfoShapeVis2.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = dpl2.createPath(this.getLocalBounds(2), // area
									 [0, BUFFER_LENGTH2, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

LfoShapeVis2.startTimer(30);

LfoShapeVis2.setPaintRoutine(function(g)
{
	g.fillAll(0x22FFFFFF);
	g.setColour(0xFFE27070);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

LfoShapeVis3.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = dpl3.createPath(this.getLocalBounds(2), // area
									 [0, BUFFER_LENGTH2, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

LfoShapeVis3.startTimer(30);

LfoShapeVis3.setPaintRoutine(function(g)
{
	g.fillAll(0x22FFFFFF);
	g.setColour(0xFFE27070);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

LfoShapeVis4.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = dpl5.createPath(this.getLocalBounds(2), // area
									 [0, BUFFER_LENGTH2, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

LfoShapeVis4.startTimer(30);

LfoShapeVis4.setPaintRoutine(function(g)
{
	g.fillAll(0x22FFFFFF);
	g.setColour(0xFFE27070);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

LfoShapeVis5.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = dpl6.createPath(this.getLocalBounds(2), // area
									 [0, BUFFER_LENGTH2, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

LfoShapeVis5.startTimer(30);

LfoShapeVis5.setPaintRoutine(function(g)
{
	g.fillAll(0x22FFFFFF);
	g.setColour(0xFFE27070);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

LfoShapeVis6.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = dpl4.createPath(this.getLocalBounds(2), // area
									 [0, BUFFER_LENGTH2, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

LfoShapeVis6.startTimer(30);

LfoShapeVis6.setPaintRoutine(function(g)
{
	g.fillAll(0x22FFFFFF);
	g.setColour(0xFFE27070);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

AdjVis1.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = dpl1.createPath(this.getLocalBounds(2), // area
									 [0, BUFFER_LENGTH2, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

AdjVis1.startTimer(30);

AdjVis1.setPaintRoutine(function(g)
{
	g.fillAll(0x70AEC2C6);
	g.setColour(0X70AEC2C6);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

AdjVis2.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = dpl2.createPath(this.getLocalBounds(1), // area
									 [0, BUFFER_LENGTH2, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

AdjVis2.startTimer(30);

AdjVis2.setPaintRoutine(function(g)
{
	g.fillAll(0xFFF5EDD8);
	g.setColour(0X70AEC2C6);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

AdjVis3.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = dpl3.createPath(this.getLocalBounds(2), // area
									 [0, BUFFER_LENGTH2, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

AdjVis3.startTimer(30);

AdjVis3.setPaintRoutine(function(g)
{
	g.fillAll(0XFFF5EDD8);
	g.setColour(0x70AEC2C6);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});

AdjVis4.setTimerCallback(function()
{
	// The autocomplete fails somehow with supplying you the methods,
	// but you can look in the API Browser under ScriptRingBuffer
	// This method creates a path object to mirror the peak display.
	this.data.buffer = dpl4.createPath(this.getLocalBounds(2), // area
									 [0, BUFFER_LENGTH2, 0, 5.0], // [x_start, x_end, y_min, y_max]
									 0.0 // start value (the initial value at position 0)
									 );
	this.repaint();
});

AdjVis4.startTimer(30);

AdjVis4.setPaintRoutine(function(g)
{
	g.fillAll(0XFFF5EDD8);
	g.setColour(0X70AEC2C6);
	g.fillPath(this.data.buffer, this.getLocalBounds(0));
});


//env1

const var LfoEnvVis1 = Content.getComponent("LfoEnvVis1");

LfoEnvVis1.setTimerCallback(function()
{
	// this creates a path from the current buffer content
	this.data.p = dpl7.createPath(
				    this.getLocalBounds(10), // target area [x, y, width, height]
				    [0, -1, -1.0, 1.0], // source area [startSample, endSample, minYValue, maxYValue]
				    0.0 // starting position
				  );
	this.repaint();
});

LfoEnvVis1.startTimer(30);


LfoEnvVis1.setPaintRoutine(function(g)
{
	g.setColour(0xFFE27070);

	if(isDefined(this.data.p))
		g.fillPath(this.data.p, this.getLocalBounds(10));
});
