/* ------------------------------------------------------------
name: "DODE"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _DODE -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___DODE_H__
#define  ___DODE_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _DODE
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

static float _DODE_faustpower2_f(float value) {
	return value * value;
}
static float _DODE_faustpower4_f(float value) {
	return value * value * value * value;
}
static float _DODE_faustpower3_f(float value) {
	return value * value * value;
}

struct _DODE final : public ::faust::dsp {
	
	int fSampleRate;
	float fConst0;
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
	
	_DODE() {
	}
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _DODE -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("filename", "DODE.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("misceffects.lib/cubicnl:author", "Julius O. Smith III");
		m->declare("misceffects.lib/cubicnl:license", "STK-4.3");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.5.0");
		m->declare("name", "DODE");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("vaeffects.lib/diodeLadder:author", "Eric Tarr");
		m->declare("vaeffects.lib/diodeLadder:license", "MIT-style STK-4.3 license");
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
	
	_DODE* clone() {
		return new _DODE();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("DODE");
		ui_interface->addHorizontalSlider("Q", &fHslider1, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("freq", &fHslider0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider0)));
		float fSlow1 = std::tan(fConst0 * std::pow(1e+01f, 3.0f * fSlow0 + 1.0f));
		float fSlow2 = fSlow1 + 1.0f;
		float fSlow3 = fSlow1 / fSlow2;
		float fSlow4 = 2.0f * fSlow3;
		float fSlow5 = _DODE_faustpower2_f(fSlow1);
		float fSlow6 = fSlow1 * (1.0f - 0.25f * fSlow3) + 1.0f;
		float fSlow7 = fSlow2 * fSlow6;
		float fSlow8 = 0.25f * (fSlow5 / fSlow7) + 1.0f;
		float fSlow9 = fSlow1 / fSlow6;
		float fSlow10 = fSlow1 * (1.0f - 0.25f * fSlow9) + 1.0f;
		float fSlow11 = fSlow6 * fSlow10;
		float fSlow12 = 0.25f * (fSlow5 / fSlow11) + 1.0f;
		float fSlow13 = fSlow1 / fSlow10;
		float fSlow14 = 0.5f * fSlow13;
		float fSlow15 = fSlow1 * (1.0f - fSlow14) + 1.0f;
		float fSlow16 = 17.0f - 9.7f * std::pow(fSlow0, 1e+01f);
		float fSlow17 = std::max<float>(1.0f, std::min<float>(1e+01f, float(fHslider1))) + -0.70710677f;
		float fSlow18 = (0.5f * (fSlow5 / (fSlow10 * fSlow15)) + 1.0f) / (0.0051455377f * (_DODE_faustpower4_f(fSlow1) * fSlow16 * fSlow17 / (fSlow7 * fSlow10 * fSlow15)) + 1.0f);
		float fSlow19 = fSlow16 * fSlow17 / fSlow2;
		float fSlow20 = 0.02058215f * fSlow9;
		float fSlow21 = 0.5f * fSlow3;
		float fSlow22 = 0.02058215f * fSlow13;
		float fSlow23 = 0.5f * fSlow9;
		float fSlow24 = 0.0051455377f * (_DODE_faustpower3_f(fSlow1) / (fSlow11 * fSlow15));
		float fSlow25 = 1.0f / fSlow10;
		float fSlow26 = 0.5f * (fSlow1 / fSlow15);
		float fSlow27 = 1.0f / fSlow6;
		float fSlow28 = 1.0f / fSlow2;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = std::max<float>(-1.0f, std::min<float>(1.0f, 1e+02f * float(input0[i0])));
			float fTemp1 = fSlow21 * fRec0[1] + fRec1[1];
			float fTemp2 = fSlow23 * fTemp1;
			float fTemp3 = fTemp2 + fRec2[1];
			float fTemp4 = fSlow13 * fTemp3 + fRec3[1];
			float fTemp5 = fSlow18 * (1.5f * fTemp0 * (1.0f - 0.33333334f * _DODE_faustpower2_f(fTemp0)) - fSlow19 * (0.0411643f * fRec0[1] + fSlow20 * fTemp1 + fSlow22 * fTemp3 + fSlow24 * fTemp4)) + fSlow25 * (fTemp3 + fSlow26 * fTemp4) - fRec3[1];
			float fTemp6 = 0.5f * (fSlow12 * (fRec3[1] + fSlow3 * fTemp5) + fSlow27 * (fTemp1 + fSlow14 * fTemp3)) - fRec2[1];
			float fTemp7 = 0.5f * (fSlow8 * (fRec2[1] + fSlow3 * fTemp6) + fSlow28 * (fRec0[1] + fTemp2)) - fRec1[1];
			float fTemp8 = 0.5f * (fRec1[1] + fSlow3 * fTemp7) - fRec0[1];
			fRec0[0] = fRec0[1] + fSlow4 * fTemp8;
			fRec1[0] = fRec1[1] + fSlow4 * fTemp7;
			fRec2[0] = fRec2[1] + fSlow4 * fTemp6;
			fRec3[0] = fRec3[1] + fSlow4 * fTemp5;
			float fRec4 = fRec0[1] + fSlow3 * fTemp8;
			output0[i0] = FAUSTFLOAT(fRec4);
			float fTemp9 = std::max<float>(-1.0f, std::min<float>(1.0f, 1e+02f * float(input1[i0])));
			float fTemp10 = fSlow21 * fRec5[1] + fRec6[1];
			float fTemp11 = fSlow23 * fTemp10;
			float fTemp12 = fTemp11 + fRec7[1];
			float fTemp13 = fSlow13 * fTemp12 + fRec8[1];
			float fTemp14 = fSlow18 * (1.5f * fTemp9 * (1.0f - 0.33333334f * _DODE_faustpower2_f(fTemp9)) - fSlow19 * (0.0411643f * fRec5[1] + fSlow20 * fTemp10 + fSlow22 * fTemp12 + fSlow24 * fTemp13)) + fSlow25 * (fTemp12 + fSlow26 * fTemp13) - fRec8[1];
			float fTemp15 = 0.5f * (fSlow12 * (fRec8[1] + fSlow3 * fTemp14) + fSlow27 * (fTemp10 + fSlow14 * fTemp12)) - fRec7[1];
			float fTemp16 = 0.5f * (fSlow8 * (fRec7[1] + fSlow3 * fTemp15) + fSlow28 * (fRec5[1] + fTemp11)) - fRec6[1];
			float fTemp17 = 0.5f * (fRec6[1] + fSlow3 * fTemp16) - fRec5[1];
			fRec5[0] = fRec5[1] + fSlow4 * fTemp17;
			fRec6[0] = fRec6[1] + fSlow4 * fTemp16;
			fRec7[0] = fRec7[1] + fSlow4 * fTemp15;
			fRec8[0] = fRec8[1] + fSlow4 * fTemp14;
			float fRec9 = fRec5[1] + fSlow3 * fTemp17;
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
	
	#define FAUST_FILE_NAME "DODE.dsp"
	#define FAUST_CLASS_NAME "_DODE"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _DODE -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
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
