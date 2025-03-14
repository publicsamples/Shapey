import("stdfaust.lib");
import("analyzers.lib");

// Morphing control sliders
alpha = hslider("Alpha [0-1]", 0.25, 0, 1, 0.01);
beta  = hslider("Beta [0-1]", 0.25, 0, 1, 0.01);
gamma = hslider("Gamma [0-1]", 0.25, 0, 1, 0.01);
delta = hslider("Delta [0-1]", 0.25, 0, 1, 0.01);

// Normalize weights
totalWeight = alpha + beta + gamma + delta + 0.0001;
normAlpha = alpha / totalWeight;
normBeta  = beta / totalWeight;
normGamma = gamma / totalWeight;
normDelta = delta / totalWeight;

// Live audio inputs (Stereo channels for input)
input1 = audioIn(0);  // Left channel input
input2 = audioIn(1);  // Right channel input

// Extract frequency spectra using spectrum
spectrum1 = input1 : spectrum(1024);  // 1024-point FFT
spectrum2 = input2 : spectrum(1024);

// Combine the frequency content using morphing weights
morphedSpectrum = (spectrum1 * normAlpha) + (spectrum2 * normBeta);

// Reconstruct the audio signal from morphed spectrum
morphedSignal = morphedSpectrum : ispectrum(1024);

// Output stereo signal
process = morphedSignal <: _, _; // Stereo output