/* ------------------------------------------------------------
name: "OBLP"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _OBLP -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___OBLP_H__
#define  ___OBLP_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _OBLP
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

static float _OBLP_faustpower2_f(float value) {
	return value * value;
}

struct _OBLP final : public ::faust::dsp {
	
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	float fRec0[2];
	float fRec1[2];
	float fRec3[2];
	float fRec4[2];
	
	_OBLP() {
	}
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _OBLP -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("filename", "OBLP.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("misceffects.lib/cubicnl:author", "Julius O. Smith III");
		m->declare("misceffects.lib/cubicnl:license", "STK-4.3");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.5.0");
		m->declare("name", "OBLP");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
		m->declare("vaeffects.lib/oberheim:author", "Eric Tarr");
		m->declare("vaeffects.lib/oberheim:license", "MIT-style STK-4.3 license");
		m->declare("vaeffects.lib/oberheimLPF:author", "Eric Tarr");
		m->declare("vaeffects.lib/oberheimLPF:license", "MIT-style STK-4.3 license");
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
			fRec3[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec4[l3] = 0.0f;
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
	
	_OBLP* clone() {
		return new _OBLP();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("OBLP");
		ui_interface->addHorizontalSlider("Q", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::tan(fConst0 * std::pow(1e+01f, 3.0f * std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider0))) + 1.0f));
		float fSlow1 = 2.0f * fSlow0;
		float fSlow2 = 1.0f / std::max<float>(1.0f, std::min<float>(1e+01f, float(fHslider1))) + fSlow0;
		float fSlow3 = fSlow0 * fSlow2 + 1.0f;
		float fSlow4 = fSlow0 / fSlow3;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = float(input0[i0]) - (fRec0[1] + fSlow2 * fRec1[1]);
			float fTemp1 = fSlow4 * fTemp0;
			float fTemp2 = std::max<float>(-1.0f, std::min<float>(1.0f, fRec1[1] + fTemp1));
			float fTemp3 = fTemp2 * (1.0f - 0.33333334f * _OBLP_faustpower2_f(fTemp2));
			fRec0[0] = fRec0[1] + fSlow1 * fTemp3;
			fRec1[0] = fTemp1 + fTemp3;
			float fTemp4 = fSlow0 * fTemp3;
			float fRec2 = fRec0[1] + fTemp4;
			output0[i0] = FAUSTFLOAT(fRec2);
			float fTemp5 = float(input1[i0]) - (fRec3[1] + fSlow2 * fRec4[1]);
			float fTemp6 = fSlow4 * fTemp5;
			float fTemp7 = std::max<float>(-1.0f, std::min<float>(1.0f, fRec4[1] + fTemp6));
			float fTemp8 = (1.0f - 0.33333334f * _OBLP_faustpower2_f(fTemp7)) * fTemp7;
			fRec3[0] = fRec3[1] + fSlow1 * fTemp8;
			fRec4[0] = fTemp8 + fTemp6;
			float fTemp9 = fSlow0 * fTemp8;
			float fRec5 = fRec3[1] + fTemp9;
			output1[i0] = FAUSTFLOAT(fRec5);
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "OBLP.dsp"
	#define FAUST_CLASS_NAME "_OBLP"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _OBLP -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 2
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("Q", fHslider1, 1.0f, 1.0f, 1e+01f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("freq", fHslider0, 0.5f, 0.0f, 1.0f, 0.001f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, Q, "Q", fHslider1, 1.0f, 1.0f, 1e+01f, 0.01f) \
		p(HORIZONTALSLIDER, freq, "freq", fHslider0, 0.5f, 0.0f, 1.0f, 0.001f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
