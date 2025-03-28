/* ------------------------------------------------------------
name: "moogLadder"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _moogLadder -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___moogLadder_H__
#define  ___moogLadder_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _moogLadder
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

static float _moogLadder_faustpower4_f(float value) {
	return value * value * value * value;
}

struct _moogLadder final : public ::faust::dsp {
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	float fRec0[2];
	float fRec1[2];
	float fRec2[2];
	float fRec3[2];
	float fRec5[2];
	float fRec6[2];
	float fRec7[2];
	float fRec8[2];
	int fSampleRate;
	
	_moogLadder() {
	}
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _moogLadder -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("filename", "moogLadder.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "moogLadder");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
		m->declare("vaeffects.lib/moogLadder:author", "Dario Sanfilippo");
		m->declare("vaeffects.lib/moogLadder:license", "MIT-style STK-4.3 license");
		m->declare("vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
		m->declare("vaeffects.lib/version", "1.2.1");
	}

	static constexpr int getStaticNumInputs() {
		return 2;
	}
	static constexpr int getStaticNumOutputs() {
		return 2;
	}
	int getNumInputs() {
		return 2;
	}
	int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
	}
	
	void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(1.0f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec6[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec7[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec8[l7] = 0.0f;
		}
	}
	
	void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	_moogLadder* clone() {
		return new _moogLadder();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("moogLadder");
		ui_interface->addHorizontalSlider("Q", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::tan(1.5707964f * std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider0))));
		float fSlow1 = fSlow0 + 1.0f;
		float fSlow2 = fSlow0 / fSlow1;
		float fSlow3 = 2.0f * fSlow2;
		float fSlow4 = std::max<float>(0.5f, std::min<float>(1e+01f, float(fHslider1))) + -0.70710677f;
		float fSlow5 = 1.0f / (0.1646572f * (_moogLadder_faustpower4_f(fSlow0) * fSlow4 / _moogLadder_faustpower4_f(fSlow1)) + 1.0f);
		float fSlow6 = 0.1646572f * (1.0f - fSlow2) * fSlow4;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = fSlow5 * (float(input0[i0]) - fSlow6 * (fSlow2 * (fSlow2 * (fRec1[1] + fSlow2 * fRec0[1]) + fRec2[1]) + fRec3[1])) - fRec0[1];
			fRec0[0] = fRec0[1] + fSlow3 * fTemp0;
			float fTemp1 = fRec0[1] + fSlow2 * fTemp0 - fRec1[1];
			fRec1[0] = fRec1[1] + fSlow3 * fTemp1;
			float fTemp2 = fRec1[1] + fSlow2 * fTemp1 - fRec2[1];
			fRec2[0] = fSlow3 * fTemp2 + fRec2[1];
			float fTemp3 = fSlow2 * fTemp2 + fRec2[1] - fRec3[1];
			fRec3[0] = fSlow3 * fTemp3 + fRec3[1];
			float fRec4 = fSlow2 * fTemp3 + fRec3[1];
			output0[i0] = FAUSTFLOAT(fRec4);
			float fTemp4 = fSlow5 * (float(input1[i0]) - fSlow6 * (fSlow2 * (fSlow2 * (fSlow2 * fRec5[1] + fRec6[1]) + fRec7[1]) + fRec8[1])) - fRec5[1];
			fRec5[0] = fSlow3 * fTemp4 + fRec5[1];
			float fTemp5 = fSlow2 * fTemp4 + fRec5[1] - fRec6[1];
			fRec6[0] = fSlow3 * fTemp5 + fRec6[1];
			float fTemp6 = fSlow2 * fTemp5 + fRec6[1] - fRec7[1];
			fRec7[0] = fSlow3 * fTemp6 + fRec7[1];
			float fTemp7 = fSlow2 * fTemp6 + fRec7[1] - fRec8[1];
			fRec8[0] = fSlow3 * fTemp7 + fRec8[1];
			float fRec9 = fSlow2 * fTemp7 + fRec8[1];
			output1[i0] = FAUSTFLOAT(fRec9);
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "moogLadder.dsp"
	#define FAUST_CLASS_NAME "_moogLadder"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _moogLadder -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 2
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("Q", fHslider1, 1.0f, 0.5f, 1e+01f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("freq", fHslider0, 0.5f, 0.0f, 1.0f, 0.001f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, Q, "Q", fHslider1, 1.0f, 0.5f, 1e+01f, 0.01f) \
		p(HORIZONTALSLIDER, freq, "freq", fHslider0, 0.5f, 0.0f, 1.0f, 0.001f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
