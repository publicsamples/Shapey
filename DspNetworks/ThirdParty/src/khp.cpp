/* ------------------------------------------------------------
author: "Eric Tarr"
name: "korg35HPF"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _khp -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___khp_H__
#define  ___khp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _khp
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


struct _khp final : public ::faust::dsp {
	
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	float fRec0[2];
	float fRec1[2];
	float fRec2[2];
	float fRec4[2];
	float fRec5[2];
	float fRec6[2];
	
	_khp() {
	}
	
	void metadata(Meta* m) { 
		m->declare("author", "Eric Tarr");
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _khp -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("description", "Demonstration of the Korg 35 LPF");
		m->declare("filename", "khp.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "korg35HPF");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("vaeffects.lib/korg35HPF:author", "Eric Tarr");
		m->declare("vaeffects.lib/korg35HPF:license", "MIT-style STK-4.3 license");
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
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec4[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec6[l5] = 0.0f;
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
	
	_khp* clone() {
		return new _khp();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("korg35HPF");
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
		float fSlow3 = 2.0f * fSlow2;
		float fSlow4 = std::max<float>(0.5f, std::min<float>(1e+01f, float(fHslider1))) + -0.70710677f;
		float fSlow5 = 1.0f - 0.21521823f * (fSlow0 * fSlow4 * (1.0f - fSlow2) / fSlow1);
		float fSlow6 = 0.21521823f * (fSlow4 / fSlow5);
		float fSlow7 = 1.0f / fSlow1;
		float fSlow8 = 1.0f / fSlow5;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = float(input0[i0]);
			float fTemp1 = fTemp0 - fRec2[1];
			float fTemp2 = fTemp0 - (fRec2[1] + fSlow7 * (fSlow0 * fTemp1 - fRec0[1] + fSlow2 * fRec1[1]));
			float fTemp3 = fSlow6 * fTemp2;
			float fTemp4 = fTemp3 - fRec1[1];
			fRec0[0] = fRec0[1] + fSlow3 * (fTemp3 - (fSlow2 * fTemp4 + fRec0[1] + fRec1[1]));
			fRec1[0] = fRec1[1] + fSlow3 * fTemp4;
			fRec2[0] = fRec2[1] + fSlow3 * fTemp1;
			float fRec3 = fSlow8 * fTemp2;
			output0[i0] = FAUSTFLOAT(fRec3);
			float fTemp5 = float(input1[i0]);
			float fTemp6 = fTemp5 - fRec6[1];
			float fTemp7 = fTemp5 - (fRec6[1] + fSlow7 * (fSlow0 * fTemp6 - fRec4[1] + fSlow2 * fRec5[1]));
			float fTemp8 = fSlow6 * fTemp7;
			float fTemp9 = fTemp8 - fRec5[1];
			fRec4[0] = fSlow3 * (fTemp8 - (fSlow2 * fTemp9 + fRec4[1] + fRec5[1])) + fRec4[1];
			fRec5[0] = fSlow3 * fTemp9 + fRec5[1];
			fRec6[0] = fSlow3 * fTemp6 + fRec6[1];
			float fRec7 = fSlow8 * fTemp7;
			output1[i0] = FAUSTFLOAT(fRec7);
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fRec6[1] = fRec6[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "khp.dsp"
	#define FAUST_CLASS_NAME "_khp"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _khp -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
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
