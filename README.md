
# Shapey!: An Experimental "Wavetable" Synthesizer  

![Shapey](https://raw.githubusercontent.com/publicsamples/Shapey/main/Shapey.png)


Shapey! is an open source, experimental synthesiser with a unusal approach to wavetable synthesis. Its primary sound generator is a single "complex" wavetable oscillator with three sections. While it borrows terminology from FM synthesis, its architecture is quite different. The modulator controls the pitch and, to a certain extent, timing of a sample player (carrier), enabling several distinct synthesis techniques depending on their configuration. 

An additional collection of sounds and presets is available for purchase [here](https://modularsamples.gumroad.com/l/lgzxw?_gl=1*1t25l91*_ga*MTYxMjA0MTcwNy4xNzQyOTQ4MDQz*_ga_6LJN6D94N6*MTc0MzY5NDY5Mi4xMS4xLjE3NDM2OTQ5NTcuMC4wLjA.). Not only does this expand Shapey!'s sonic capabilities, but it also helps support its future development—and me, the person who made it.  

###  Summary:

-   **Complex wavetable oscillator**  with three sections.
-   **Two modulator modes**: waveform oscillator or sample-based.
-   **Waveshaping & FX section**  for further sound transformation.
-   **Versatile sample-based carrier**  with pitch and timing controls.
-   **Dual-mode filter**  (serial/parallel) inspired by the Korg MS-20.
-   **Comprehensive modulation system**  with envelopes and LFOs.
-   **Arpeggiator/step sequencer**  for rhythmic pattern creation.
-  **Mac OS & Windows** with VST3 and audio unit plugins
-   **Built using HISE & FAUST**  for a flexible and efficient synthesis engine.

## The Oscillator  

### Modulator  
In its first mode, the modulator functions as a simple multi-waveform oscillator with pitch, glide, and output gain controls. A sub-oscillator with phase and AM controls can be added to the signal. Additionally, the pitch can be quantized or synced to tempo, allowing it to act as an LFO. In its second mode, it replicates the entire oscillator section, placing a sample player after the oscillator, which enables the use of two samples within a single patch.  

### Transformer  
The transformer sits between the modulator and carrier, providing various waveshaping, FX, and filtering options. It includes a mix control along with two additional controls whose functionality depends on the current mode.  

### Carrier  
The carrier is a versatile sample player with controls for position, input gain, smoothing, quantization, and pitch shifting.  

## The Filter  
The filter is a dual low-pass/high-pass design, similar to the Korg MS-20, capable of operating in serial or parallel. Additionally, the "modulator in" control allows the signal from the modulator to be routed directly into the filter.  

## The Amp  
Shapey! features a simple AHDSR-controlled VCA.  

## The Modulators  
The modulation section includes an AHDSR envelope, a looping AR envelope with tempo-synced attack and release stages, a loopable table envelope, and two master LFOs with multiple wave shapes and quantization options.  

## The Arpeggiator  
A flexible arpeggiator and step sequencer rounds out the feature set, allowing for intricate rhythmic pattern creation.  

---  

**Built with HISE & FAUST.**  



