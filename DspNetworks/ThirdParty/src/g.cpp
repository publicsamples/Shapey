/* ------------------------------------------------------------
author: "RM"
name: "freeverb"
version: "0.0"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _g -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___g_H__
#define  ___g_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _g
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


struct _g final : public ::faust::dsp {
	
	FAUSTFLOAT fVslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fVslider1;
	float fConst2;
	FAUSTFLOAT fVslider2;
	float fRec9[2];
	int IOTA0;
	float fVec0[8192];
	int iConst3;
	float fRec8[2];
	float fRec11[2];
	float fVec1[8192];
	int iConst4;
	float fRec10[2];
	float fRec13[2];
	float fVec2[8192];
	int iConst5;
	float fRec12[2];
	float fRec15[2];
	float fVec3[8192];
	int iConst6;
	float fRec14[2];
	float fRec17[2];
	float fVec4[8192];
	int iConst7;
	float fRec16[2];
	float fRec19[2];
	float fVec5[8192];
	int iConst8;
	float fRec18[2];
	float fRec21[2];
	float fVec6[8192];
	int iConst9;
	float fRec20[2];
	float fRec23[2];
	float fVec7[8192];
	int iConst10;
	float fRec22[2];
	float fVec8[2048];
	int iConst11;
	int iConst12;
	float fRec6[2];
	float fVec9[2048];
	int iConst13;
	int iConst14;
	float fRec4[2];
	float fVec10[2048];
	int iConst15;
	int iConst16;
	float fRec2[2];
	float fVec11[1024];
	int iConst17;
	int iConst18;
	float fRec0[2];
	float fRec33[2];
	float fVec12[8192];
	float fConst19;
	FAUSTFLOAT fVslider3;
	float fRec32[2];
	float fRec35[2];
	float fVec13[8192];
	float fRec34[2];
	float fRec37[2];
	float fVec14[8192];
	float fRec36[2];
	float fRec39[2];
	float fVec15[8192];
	float fRec38[2];
	float fRec41[2];
	float fVec16[8192];
	float fRec40[2];
	float fRec43[2];
	float fVec17[8192];
	float fRec42[2];
	float fRec45[2];
	float fVec18[8192];
	float fRec44[2];
	float fRec47[2];
	float fVec19[8192];
	float fRec46[2];
	float fVec20[2048];
	float fRec30[2];
	float fVec21[2048];
	float fRec28[2];
	float fVec22[2048];
	float fRec26[2];
	float fVec23[2048];
	float fRec24[2];
	
	_g() {
	}
	
	void metadata(Meta* m) { 
		m->declare("author", "RM");
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _g -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
		m->declare("demos.lib/freeverb_demo:author", " Romain Michon");
		m->declare("demos.lib/freeverb_demo:licence", "LGPL");
		m->declare("demos.lib/name", "Faust Demos Library");
		m->declare("demos.lib/version", "1.2.0");
		m->declare("description", "Freeverb demo application.");
		m->declare("filename", "g.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "freeverb");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reverbs.lib/mono_freeverb:author", "Romain Michon");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/stereo_freeverb:author", "Romain Michon");
		m->declare("reverbs.lib/version", "1.3.0");
		m->declare("version", "0.0");
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
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 12348.0f / fConst0;
		fConst2 = 1.764e+04f / fConst0;
		iConst3 = int(0.028956916f * fConst0);
		iConst4 = int(0.026938776f * fConst0);
		iConst5 = int(0.025306122f * fConst0);
		iConst6 = int(0.036666665f * fConst0);
		iConst7 = int(0.035306122f * fConst0);
		iConst8 = int(0.033809524f * fConst0);
		iConst9 = int(0.030748298f * fConst0);
		iConst10 = int(0.0322449f * fConst0);
		iConst11 = int(0.0126077095f * fConst0);
		iConst12 = std::min<int>(1024, std::max<int>(0, iConst11 + -1));
		iConst13 = int(0.01f * fConst0);
		iConst14 = std::min<int>(1024, std::max<int>(0, iConst13 + -1));
		iConst15 = int(0.0077324263f * fConst0);
		iConst16 = std::min<int>(1024, std::max<int>(0, iConst15 + -1));
		iConst17 = int(0.0051020407f * fConst0);
		iConst18 = std::min<int>(1024, std::max<int>(0, iConst17 + -1));
		fConst19 = 0.0010430838f * fConst0;
	}
	
	void instanceResetUserInterface() {
		fVslider0 = FAUSTFLOAT(0.3333f);
		fVslider1 = FAUSTFLOAT(0.5f);
		fVslider2 = FAUSTFLOAT(0.5f);
		fVslider3 = FAUSTFLOAT(0.5f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec9[l0] = 0.0f;
		}
		IOTA0 = 0;
		for (int l1 = 0; l1 < 8192; l1 = l1 + 1) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec8[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec11[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 8192; l4 = l4 + 1) {
			fVec1[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec10[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec13[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 8192; l7 = l7 + 1) {
			fVec2[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec12[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			fRec15[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 8192; l10 = l10 + 1) {
			fVec3[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec14[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec17[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 8192; l13 = l13 + 1) {
			fVec4[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec16[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec19[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 8192; l16 = l16 + 1) {
			fVec5[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec18[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec21[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 8192; l19 = l19 + 1) {
			fVec6[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec20[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec23[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 8192; l22 = l22 + 1) {
			fVec7[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			fRec22[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2048; l24 = l24 + 1) {
			fVec8[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			fRec6[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2048; l26 = l26 + 1) {
			fVec9[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec4[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2048; l28 = l28 + 1) {
			fVec10[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			fRec2[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 1024; l30 = l30 + 1) {
			fVec11[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			fRec0[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fRec33[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 8192; l33 = l33 + 1) {
			fVec12[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			fRec32[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			fRec35[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 8192; l36 = l36 + 1) {
			fVec13[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			fRec34[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fRec37[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 8192; l39 = l39 + 1) {
			fVec14[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fRec36[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			fRec39[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 8192; l42 = l42 + 1) {
			fVec15[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 2; l43 = l43 + 1) {
			fRec38[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			fRec41[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 8192; l45 = l45 + 1) {
			fVec16[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = l46 + 1) {
			fRec40[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 2; l47 = l47 + 1) {
			fRec43[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 8192; l48 = l48 + 1) {
			fVec17[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = l49 + 1) {
			fRec42[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 2; l50 = l50 + 1) {
			fRec45[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 8192; l51 = l51 + 1) {
			fVec18[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			fRec44[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 2; l53 = l53 + 1) {
			fRec47[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 8192; l54 = l54 + 1) {
			fVec19[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 2; l55 = l55 + 1) {
			fRec46[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2048; l56 = l56 + 1) {
			fVec20[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fRec30[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2048; l58 = l58 + 1) {
			fVec21[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 2; l59 = l59 + 1) {
			fRec28[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 2048; l60 = l60 + 1) {
			fVec22[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = l61 + 1) {
			fRec26[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 2048; l62 = l62 + 1) {
			fVec23[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 2; l63 = l63 + 1) {
			fRec24[l63] = 0.0f;
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
	
	_g* clone() {
		return new _g();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openHorizontalBox("Freeverb");
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("0x00");
		ui_interface->declare(&fVslider2, "0", "");
		ui_interface->declare(&fVslider2, "style", "knob");
		ui_interface->declare(&fVslider2, "tooltip", "Somehow control the         density of the reverb.");
		ui_interface->addVerticalSlider("Damp", &fVslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.025f));
		ui_interface->declare(&fVslider1, "1", "");
		ui_interface->declare(&fVslider1, "style", "knob");
		ui_interface->declare(&fVslider1, "tooltip", "The room size         between 0 and 1 with 1 for the largest room.");
		ui_interface->addVerticalSlider("RoomSize", &fVslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.025f));
		ui_interface->declare(&fVslider3, "2", "");
		ui_interface->declare(&fVslider3, "style", "knob");
		ui_interface->declare(&fVslider3, "tooltip", "Spatial         spread between 0 and 1 with 1 for maximum spread.");
		ui_interface->addVerticalSlider("Stereo Spread", &fVslider3, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->declare(&fVslider0, "1", "");
		ui_interface->declare(&fVslider0, "tooltip", "The amount of reverb applied to the signal         between 0 and 1 with 1 for the maximum amount of reverb.");
		ui_interface->addVerticalSlider("Wet", &fVslider0, FAUSTFLOAT(0.3333f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.025f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::max<float>(0.0f, std::min<float>(1.0f, float(fVslider0)));
		float fSlow1 = 0.1f * fSlow0;
		float fSlow2 = fConst1 * std::max<float>(0.0f, std::min<float>(1.0f, float(fVslider1))) + 0.7f;
		float fSlow3 = fConst2 * std::max<float>(0.0f, std::min<float>(1.0f, float(fVslider2)));
		float fSlow4 = 1.0f - fSlow3;
		float fSlow5 = 1.0f - fSlow0;
		int iSlow6 = int(fConst19 * std::max<float>(0.0f, std::min<float>(1.0f, float(fVslider3))));
		int iSlow7 = iConst7 + iSlow6;
		int iSlow8 = iConst8 + iSlow6;
		int iSlow9 = iConst10 + iSlow6;
		int iSlow10 = iConst9 + iSlow6;
		int iSlow11 = iConst3 + iSlow6;
		int iSlow12 = iConst4 + iSlow6;
		int iSlow13 = iConst6 + iSlow6;
		int iSlow14 = iConst5 + iSlow6;
		int iSlow15 = iSlow6 + -1;
		int iSlow16 = std::min<int>(1024, std::max<int>(0, iConst11 + iSlow15));
		int iSlow17 = std::min<int>(1024, std::max<int>(0, iConst13 + iSlow15));
		int iSlow18 = std::min<int>(1024, std::max<int>(0, iConst15 + iSlow15));
		int iSlow19 = std::min<int>(1024, std::max<int>(0, iConst17 + iSlow15));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = float(input0[i0]);
			float fTemp1 = float(input1[i0]);
			float fTemp2 = fSlow1 * (fTemp0 + fTemp1);
			fRec9[0] = fSlow3 * fRec9[1] + fSlow4 * fRec8[1];
			fVec0[IOTA0 & 8191] = fTemp2 + fSlow2 * fRec9[0];
			fRec8[0] = fVec0[(IOTA0 - iConst3) & 8191];
			fRec11[0] = fSlow3 * fRec11[1] + fSlow4 * fRec10[1];
			fVec1[IOTA0 & 8191] = fTemp2 + fSlow2 * fRec11[0];
			fRec10[0] = fVec1[(IOTA0 - iConst4) & 8191];
			fRec13[0] = fSlow3 * fRec13[1] + fSlow4 * fRec12[1];
			fVec2[IOTA0 & 8191] = fSlow2 * fRec13[0] + fTemp2;
			fRec12[0] = fVec2[(IOTA0 - iConst5) & 8191];
			fRec15[0] = fSlow3 * fRec15[1] + fSlow4 * fRec14[1];
			fVec3[IOTA0 & 8191] = fSlow2 * fRec15[0] + fTemp2;
			fRec14[0] = fVec3[(IOTA0 - iConst6) & 8191];
			fRec17[0] = fSlow3 * fRec17[1] + fSlow4 * fRec16[1];
			fVec4[IOTA0 & 8191] = fSlow2 * fRec17[0] + fTemp2;
			fRec16[0] = fVec4[(IOTA0 - iConst7) & 8191];
			fRec19[0] = fSlow3 * fRec19[1] + fSlow4 * fRec18[1];
			fVec5[IOTA0 & 8191] = fSlow2 * fRec19[0] + fTemp2;
			fRec18[0] = fVec5[(IOTA0 - iConst8) & 8191];
			fRec21[0] = fSlow3 * fRec21[1] + fSlow4 * fRec20[1];
			fVec6[IOTA0 & 8191] = fTemp2 + fSlow2 * fRec21[0];
			fRec20[0] = fVec6[(IOTA0 - iConst9) & 8191];
			fRec23[0] = fSlow3 * fRec23[1] + fSlow4 * fRec22[1];
			fVec7[IOTA0 & 8191] = fSlow2 * fRec23[0] + fTemp2;
			fRec22[0] = fVec7[(IOTA0 - iConst10) & 8191];
			float fTemp3 = fRec8[0] + fRec10[0] + fRec12[0] + fRec14[0] + fRec16[0] + fRec18[0] + fRec20[0] + fRec22[0] + 0.5f * fRec6[1];
			fVec8[IOTA0 & 2047] = fTemp3;
			fRec6[0] = fVec8[(IOTA0 - iConst12) & 2047];
			float fRec7 = -(0.5f * fTemp3);
			float fTemp4 = fRec7 + 0.5f * fRec4[1] + fRec6[1];
			fVec9[IOTA0 & 2047] = fTemp4;
			fRec4[0] = fVec9[(IOTA0 - iConst14) & 2047];
			float fRec5 = -(0.5f * fTemp4);
			float fTemp5 = fRec5 + 0.5f * fRec2[1] + fRec4[1];
			fVec10[IOTA0 & 2047] = fTemp5;
			fRec2[0] = fVec10[(IOTA0 - iConst16) & 2047];
			float fRec3 = -(0.5f * fTemp5);
			float fTemp6 = fRec3 + 0.5f * fRec0[1] + fRec2[1];
			fVec11[IOTA0 & 1023] = fTemp6;
			fRec0[0] = fVec11[(IOTA0 - iConst18) & 1023];
			float fRec1 = -(0.5f * fTemp6);
			output0[i0] = FAUSTFLOAT(fRec1 + fSlow5 * fTemp0 + fRec0[1]);
			fRec33[0] = fSlow3 * fRec33[1] + fSlow4 * fRec32[1];
			fVec12[IOTA0 & 8191] = fSlow2 * fRec33[0] + fTemp2;
			fRec32[0] = fVec12[(IOTA0 - iSlow7) & 8191];
			fRec35[0] = fSlow3 * fRec35[1] + fSlow4 * fRec34[1];
			fVec13[IOTA0 & 8191] = fSlow2 * fRec35[0] + fTemp2;
			fRec34[0] = fVec13[(IOTA0 - iSlow8) & 8191];
			fRec37[0] = fSlow3 * fRec37[1] + fSlow4 * fRec36[1];
			fVec14[IOTA0 & 8191] = fSlow2 * fRec37[0] + fTemp2;
			fRec36[0] = fVec14[(IOTA0 - iSlow9) & 8191];
			fRec39[0] = fSlow3 * fRec39[1] + fSlow4 * fRec38[1];
			fVec15[IOTA0 & 8191] = fSlow2 * fRec39[0] + fTemp2;
			fRec38[0] = fVec15[(IOTA0 - iSlow10) & 8191];
			fRec41[0] = fSlow3 * fRec41[1] + fSlow4 * fRec40[1];
			fVec16[IOTA0 & 8191] = fSlow2 * fRec41[0] + fTemp2;
			fRec40[0] = fVec16[(IOTA0 - iSlow11) & 8191];
			fRec43[0] = fSlow3 * fRec43[1] + fSlow4 * fRec42[1];
			fVec17[IOTA0 & 8191] = fSlow2 * fRec43[0] + fTemp2;
			fRec42[0] = fVec17[(IOTA0 - iSlow12) & 8191];
			fRec45[0] = fSlow3 * fRec45[1] + fSlow4 * fRec44[1];
			fVec18[IOTA0 & 8191] = fSlow2 * fRec45[0] + fTemp2;
			fRec44[0] = fVec18[(IOTA0 - iSlow13) & 8191];
			fRec47[0] = fSlow3 * fRec47[1] + fSlow4 * fRec46[1];
			fVec19[IOTA0 & 8191] = fSlow2 * fRec47[0] + fTemp2;
			fRec46[0] = fVec19[(IOTA0 - iSlow14) & 8191];
			float fTemp7 = fRec32[0] + fRec34[0] + fRec36[0] + fRec38[0] + fRec40[0] + fRec42[0] + fRec44[0] + fRec46[0] + 0.5f * fRec30[1];
			fVec20[IOTA0 & 2047] = fTemp7;
			fRec30[0] = fVec20[(IOTA0 - iSlow16) & 2047];
			float fRec31 = -(0.5f * fTemp7);
			float fTemp8 = fRec31 + 0.5f * fRec28[1] + fRec30[1];
			fVec21[IOTA0 & 2047] = fTemp8;
			fRec28[0] = fVec21[(IOTA0 - iSlow17) & 2047];
			float fRec29 = -(0.5f * fTemp8);
			float fTemp9 = fRec29 + 0.5f * fRec26[1] + fRec28[1];
			fVec22[IOTA0 & 2047] = fTemp9;
			fRec26[0] = fVec22[(IOTA0 - iSlow18) & 2047];
			float fRec27 = -(0.5f * fTemp9);
			float fTemp10 = fRec27 + 0.5f * fRec24[1] + fRec26[1];
			fVec23[IOTA0 & 2047] = fTemp10;
			fRec24[0] = fVec23[(IOTA0 - iSlow19) & 2047];
			float fRec25 = -(0.5f * fTemp10);
			output1[i0] = FAUSTFLOAT(fRec25 + fSlow5 * fTemp1 + fRec24[1]);
			fRec9[1] = fRec9[0];
			IOTA0 = IOTA0 + 1;
			fRec8[1] = fRec8[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fRec30[1] = fRec30[0];
			fRec28[1] = fRec28[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "g.dsp"
	#define FAUST_CLASS_NAME "_g"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _g -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 4
	#define FAUST_PASSIVES 0

	FAUST_ADDVERTICALSLIDER("Freeverb/[0]/Damp", fVslider2, 0.5f, 0.0f, 1.0f, 0.025f);
	FAUST_ADDVERTICALSLIDER("Freeverb/[0]/RoomSize", fVslider1, 0.5f, 0.0f, 1.0f, 0.025f);
	FAUST_ADDVERTICALSLIDER("Freeverb/[0]/Stereo Spread", fVslider3, 0.5f, 0.0f, 1.0f, 0.01f);
	FAUST_ADDVERTICALSLIDER("Freeverb/Wet", fVslider0, 0.3333f, 0.0f, 1.0f, 0.025f);

	#define FAUST_LIST_ACTIVES(p) \
		p(VERTICALSLIDER, Damp, "Freeverb/[0]/Damp", fVslider2, 0.5f, 0.0f, 1.0f, 0.025f) \
		p(VERTICALSLIDER, RoomSize, "Freeverb/[0]/RoomSize", fVslider1, 0.5f, 0.0f, 1.0f, 0.025f) \
		p(VERTICALSLIDER, Stereo_Spread, "Freeverb/[0]/Stereo Spread", fVslider3, 0.5f, 0.0f, 1.0f, 0.01f) \
		p(VERTICALSLIDER, Wet, "Freeverb/Wet", fVslider0, 0.3333f, 0.0f, 1.0f, 0.025f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
