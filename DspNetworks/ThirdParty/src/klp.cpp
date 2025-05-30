/* ------------------------------------------------------------
author: "Eric Tarr"
name: "korg35LPF"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _klp -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___klp_H__
#define  ___klp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _klp
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


struct _klp final : public ::faust::dsp {
	
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	float fRec1[2];
	float fRec2[2];
	float fRec3[2];
	float fRec5[2];
	float fRec6[2];
	float fRec7[2];
	
	_klp() {
	}
	
	void metadata(Meta* m) { 
		m->declare("author", "Eric Tarr");
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _klp -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("description", "Demonstration of the Korg 35 LPF");
		m->declare("filename", "klp.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "korg35LPF");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("vaeffects.lib/korg35LPF:author", "Eric Tarr");
		m->declare("vaeffects.lib/korg35LPF:license", "MIT-style STK-4.3 license");
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
		fConst0 = 6.2831855f / std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
	}
	
	void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(1.0f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec1[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec5[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec6[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec7[l5] = 0.0f;
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
	
	_klp* clone() {
		return new _klp();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("korg35LPF");
		ui_interface->addHorizontalSlider("Q", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::tan(fConst0 * std::pow(1e+01f, 3.0f * std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider0))) + 1.0f));
		float fSlow1 = fSlow0 + 1.0f;
		float fSlow2 = fSlow0 / fSlow1;
		float fSlow3 = std::max<float>(0.5f, std::min<float>(1e+01f, float(fHslider1))) + -0.70710677f;
		float fSlow4 = 1.0f - fSlow2;
		float fSlow5 = 1.0f / (1.0f - 0.21521823f * (fSlow0 * fSlow3 * fSlow4 / fSlow1));
		float fSlow6 = 1.0f / fSlow1;
		float fSlow7 = 0.21521823f * fSlow3 * fSlow4;
		float fSlow8 = 2.0f * fSlow2;
		float fSlow9 = 0.21521823f * fSlow3;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = float(input0[i0]) - fRec3[1];
			float fTemp1 = fSlow5 * (fRec3[1] + fSlow6 * (fSlow0 * fTemp0 + fSlow7 * fRec1[1] - fRec2[1])) - fRec1[1];
			float fTemp2 = fRec1[1] + fSlow2 * fTemp1;
			float fRec0 = fTemp2;
			fRec1[0] = fRec1[1] + fSlow8 * fTemp1;
			fRec2[0] = fRec2[1] + fSlow8 * (fSlow9 * fTemp2 - fRec2[1]);
			fRec3[0] = fRec3[1] + fSlow8 * fTemp0;
			output0[i0] = FAUSTFLOAT(fRec0);
			float fTemp3 = float(input1[i0]) - fRec7[1];
			float fTemp4 = fSlow5 * (fRec7[1] + fSlow6 * (fSlow0 * fTemp3 + fSlow7 * fRec5[1] - fRec6[1])) - fRec5[1];
			float fTemp5 = fRec5[1] + fSlow2 * fTemp4;
			float fRec4 = fTemp5;
			fRec5[0] = fRec5[1] + fSlow8 * fTemp4;
			fRec6[0] = fRec6[1] + fSlow8 * (fSlow9 * fTemp5 - fRec6[1]);
			fRec7[0] = fRec7[1] + fSlow8 * fTemp3;
			output1[i0] = FAUSTFLOAT(fRec4);
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "klp.dsp"
	#define FAUST_CLASS_NAME "_klp"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _klp -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
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
