/* ------------------------------------------------------------
author: "Mayank Sanganeria"
name: "Granulator"
version: "1.0"
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

struct _gSIG0 {
	
	int getNumInputs_gSIG0() {
		return 0;
	}
	int getNumOutputs_gSIG0() {
		return 1;
	}
	
	void instanceInit_gSIG0(int sample_rate) {
	}
	
	void fill_gSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			table[i1] = 0.0f;
		}
	}

};

static _gSIG0* new_gSIG0() { return (_gSIG0*)new _gSIG0(); }
static void delete_gSIG0(_gSIG0* dsp) { delete dsp; }


struct _g final : public ::faust::dsp {
	
	FAUSTFLOAT fHslider0;
	float ftbl0[480000];
	int iVec0[2];
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fHslider1;
	int iRec0[2];
	FAUSTFLOAT fHslider2;
	int iRec3[2];
	int iRec2[2];
	int iRec67[2];
	int iRec1[2];
	int iRec69[2];
	int iRec68[2];
	int iRec71[2];
	int iRec70[2];
	int iRec73[2];
	int iRec72[2];
	int iRec75[2];
	int iRec74[2];
	int iRec77[2];
	int iRec76[2];
	int iRec79[2];
	int iRec78[2];
	int iRec81[2];
	int iRec80[2];
	int iRec83[2];
	int iRec82[2];
	int iRec85[2];
	int iRec84[2];
	int iRec87[2];
	int iRec86[2];
	int iRec89[2];
	int iRec88[2];
	int iRec91[2];
	int iRec90[2];
	int iRec93[2];
	int iRec92[2];
	int iRec95[2];
	int iRec94[2];
	int iRec97[2];
	int iRec96[2];
	int iRec99[2];
	int iRec98[2];
	int iRec101[2];
	int iRec100[2];
	int iRec103[2];
	int iRec102[2];
	int iRec105[2];
	int iRec104[2];
	int iRec107[2];
	int iRec106[2];
	int iRec109[2];
	int iRec108[2];
	int iRec111[2];
	int iRec110[2];
	int iRec113[2];
	int iRec112[2];
	int iRec115[2];
	int iRec114[2];
	int iRec117[2];
	int iRec116[2];
	int iRec119[2];
	int iRec118[2];
	int iRec121[2];
	int iRec120[2];
	int iRec123[2];
	int iRec122[2];
	int iRec125[2];
	int iRec124[2];
	int iRec127[2];
	int iRec126[2];
	int iRec128[2];
	int iRec129[2];
	int iRec131[2];
	int iRec130[2];
	int iRec133[2];
	int iRec132[2];
	int iRec135[2];
	int iRec134[2];
	int iRec137[2];
	int iRec136[2];
	int iRec139[2];
	int iRec138[2];
	int iRec141[2];
	int iRec140[2];
	int iRec143[2];
	int iRec142[2];
	int iRec145[2];
	int iRec144[2];
	int iRec147[2];
	int iRec146[2];
	int iRec149[2];
	int iRec148[2];
	int iRec151[2];
	int iRec150[2];
	int iRec153[2];
	int iRec152[2];
	int iRec155[2];
	int iRec154[2];
	int iRec157[2];
	int iRec156[2];
	int iRec159[2];
	int iRec158[2];
	int iRec161[2];
	int iRec160[2];
	int iRec163[2];
	int iRec162[2];
	int iRec165[2];
	int iRec164[2];
	int iRec167[2];
	int iRec166[2];
	int iRec169[2];
	int iRec168[2];
	int iRec171[2];
	int iRec170[2];
	int iRec173[2];
	int iRec172[2];
	int iRec175[2];
	int iRec174[2];
	int iRec177[2];
	int iRec176[2];
	int iRec179[2];
	int iRec178[2];
	int iRec181[2];
	int iRec180[2];
	int iRec183[2];
	int iRec182[2];
	int iRec185[2];
	int iRec184[2];
	int iRec187[2];
	int iRec186[2];
	int iRec189[2];
	int iRec188[2];
	int iRec191[2];
	int iRec190[2];
	int iRec193[2];
	int iRec192[2];
	
	_g() {
	}
	
	void metadata(Meta* m) { 
		m->declare("author", "Mayank Sanganeria");
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _g -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("filename", "g.dsp");
		m->declare("name", "Granulator");
		m->declare("version", "1.0");
	}

	static constexpr int getStaticNumInputs() {
		return 1;
	}
	static constexpr int getStaticNumOutputs() {
		return 2;
	}
	int getNumInputs() {
		return 1;
	}
	int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		_gSIG0* sig0 = new_gSIG0();
		sig0->instanceInit_gSIG0(sample_rate);
		sig0->fill_gSIG0(480000, ftbl0);
		fConst0 = float(fSampleRate);
		delete_gSIG0(sig0);
	}
	
	void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(1e+01f);
		fHslider2 = FAUSTFLOAT(0.1f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iRec0[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			iRec3[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			iRec2[l3] = 0;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			iRec67[l4] = 0;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			iRec1[l5] = 0;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			iRec69[l6] = 0;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			iRec68[l7] = 0;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			iRec71[l8] = 0;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			iRec70[l9] = 0;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			iRec73[l10] = 0;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			iRec72[l11] = 0;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			iRec75[l12] = 0;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			iRec74[l13] = 0;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			iRec77[l14] = 0;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			iRec76[l15] = 0;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			iRec79[l16] = 0;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			iRec78[l17] = 0;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			iRec81[l18] = 0;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			iRec80[l19] = 0;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			iRec83[l20] = 0;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			iRec82[l21] = 0;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			iRec85[l22] = 0;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			iRec84[l23] = 0;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			iRec87[l24] = 0;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			iRec86[l25] = 0;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			iRec89[l26] = 0;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			iRec88[l27] = 0;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			iRec91[l28] = 0;
		}
		for (int l29 = 0; l29 < 2; l29 = l29 + 1) {
			iRec90[l29] = 0;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			iRec93[l30] = 0;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			iRec92[l31] = 0;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			iRec95[l32] = 0;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			iRec94[l33] = 0;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			iRec97[l34] = 0;
		}
		for (int l35 = 0; l35 < 2; l35 = l35 + 1) {
			iRec96[l35] = 0;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			iRec99[l36] = 0;
		}
		for (int l37 = 0; l37 < 2; l37 = l37 + 1) {
			iRec98[l37] = 0;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			iRec101[l38] = 0;
		}
		for (int l39 = 0; l39 < 2; l39 = l39 + 1) {
			iRec100[l39] = 0;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			iRec103[l40] = 0;
		}
		for (int l41 = 0; l41 < 2; l41 = l41 + 1) {
			iRec102[l41] = 0;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			iRec105[l42] = 0;
		}
		for (int l43 = 0; l43 < 2; l43 = l43 + 1) {
			iRec104[l43] = 0;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			iRec107[l44] = 0;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			iRec106[l45] = 0;
		}
		for (int l46 = 0; l46 < 2; l46 = l46 + 1) {
			iRec109[l46] = 0;
		}
		for (int l47 = 0; l47 < 2; l47 = l47 + 1) {
			iRec108[l47] = 0;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			iRec111[l48] = 0;
		}
		for (int l49 = 0; l49 < 2; l49 = l49 + 1) {
			iRec110[l49] = 0;
		}
		for (int l50 = 0; l50 < 2; l50 = l50 + 1) {
			iRec113[l50] = 0;
		}
		for (int l51 = 0; l51 < 2; l51 = l51 + 1) {
			iRec112[l51] = 0;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			iRec115[l52] = 0;
		}
		for (int l53 = 0; l53 < 2; l53 = l53 + 1) {
			iRec114[l53] = 0;
		}
		for (int l54 = 0; l54 < 2; l54 = l54 + 1) {
			iRec117[l54] = 0;
		}
		for (int l55 = 0; l55 < 2; l55 = l55 + 1) {
			iRec116[l55] = 0;
		}
		for (int l56 = 0; l56 < 2; l56 = l56 + 1) {
			iRec119[l56] = 0;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			iRec118[l57] = 0;
		}
		for (int l58 = 0; l58 < 2; l58 = l58 + 1) {
			iRec121[l58] = 0;
		}
		for (int l59 = 0; l59 < 2; l59 = l59 + 1) {
			iRec120[l59] = 0;
		}
		for (int l60 = 0; l60 < 2; l60 = l60 + 1) {
			iRec123[l60] = 0;
		}
		for (int l61 = 0; l61 < 2; l61 = l61 + 1) {
			iRec122[l61] = 0;
		}
		for (int l62 = 0; l62 < 2; l62 = l62 + 1) {
			iRec125[l62] = 0;
		}
		for (int l63 = 0; l63 < 2; l63 = l63 + 1) {
			iRec124[l63] = 0;
		}
		for (int l64 = 0; l64 < 2; l64 = l64 + 1) {
			iRec127[l64] = 0;
		}
		for (int l65 = 0; l65 < 2; l65 = l65 + 1) {
			iRec126[l65] = 0;
		}
		for (int l66 = 0; l66 < 2; l66 = l66 + 1) {
			iRec128[l66] = 0;
		}
		for (int l67 = 0; l67 < 2; l67 = l67 + 1) {
			iRec129[l67] = 0;
		}
		for (int l68 = 0; l68 < 2; l68 = l68 + 1) {
			iRec131[l68] = 0;
		}
		for (int l69 = 0; l69 < 2; l69 = l69 + 1) {
			iRec130[l69] = 0;
		}
		for (int l70 = 0; l70 < 2; l70 = l70 + 1) {
			iRec133[l70] = 0;
		}
		for (int l71 = 0; l71 < 2; l71 = l71 + 1) {
			iRec132[l71] = 0;
		}
		for (int l72 = 0; l72 < 2; l72 = l72 + 1) {
			iRec135[l72] = 0;
		}
		for (int l73 = 0; l73 < 2; l73 = l73 + 1) {
			iRec134[l73] = 0;
		}
		for (int l74 = 0; l74 < 2; l74 = l74 + 1) {
			iRec137[l74] = 0;
		}
		for (int l75 = 0; l75 < 2; l75 = l75 + 1) {
			iRec136[l75] = 0;
		}
		for (int l76 = 0; l76 < 2; l76 = l76 + 1) {
			iRec139[l76] = 0;
		}
		for (int l77 = 0; l77 < 2; l77 = l77 + 1) {
			iRec138[l77] = 0;
		}
		for (int l78 = 0; l78 < 2; l78 = l78 + 1) {
			iRec141[l78] = 0;
		}
		for (int l79 = 0; l79 < 2; l79 = l79 + 1) {
			iRec140[l79] = 0;
		}
		for (int l80 = 0; l80 < 2; l80 = l80 + 1) {
			iRec143[l80] = 0;
		}
		for (int l81 = 0; l81 < 2; l81 = l81 + 1) {
			iRec142[l81] = 0;
		}
		for (int l82 = 0; l82 < 2; l82 = l82 + 1) {
			iRec145[l82] = 0;
		}
		for (int l83 = 0; l83 < 2; l83 = l83 + 1) {
			iRec144[l83] = 0;
		}
		for (int l84 = 0; l84 < 2; l84 = l84 + 1) {
			iRec147[l84] = 0;
		}
		for (int l85 = 0; l85 < 2; l85 = l85 + 1) {
			iRec146[l85] = 0;
		}
		for (int l86 = 0; l86 < 2; l86 = l86 + 1) {
			iRec149[l86] = 0;
		}
		for (int l87 = 0; l87 < 2; l87 = l87 + 1) {
			iRec148[l87] = 0;
		}
		for (int l88 = 0; l88 < 2; l88 = l88 + 1) {
			iRec151[l88] = 0;
		}
		for (int l89 = 0; l89 < 2; l89 = l89 + 1) {
			iRec150[l89] = 0;
		}
		for (int l90 = 0; l90 < 2; l90 = l90 + 1) {
			iRec153[l90] = 0;
		}
		for (int l91 = 0; l91 < 2; l91 = l91 + 1) {
			iRec152[l91] = 0;
		}
		for (int l92 = 0; l92 < 2; l92 = l92 + 1) {
			iRec155[l92] = 0;
		}
		for (int l93 = 0; l93 < 2; l93 = l93 + 1) {
			iRec154[l93] = 0;
		}
		for (int l94 = 0; l94 < 2; l94 = l94 + 1) {
			iRec157[l94] = 0;
		}
		for (int l95 = 0; l95 < 2; l95 = l95 + 1) {
			iRec156[l95] = 0;
		}
		for (int l96 = 0; l96 < 2; l96 = l96 + 1) {
			iRec159[l96] = 0;
		}
		for (int l97 = 0; l97 < 2; l97 = l97 + 1) {
			iRec158[l97] = 0;
		}
		for (int l98 = 0; l98 < 2; l98 = l98 + 1) {
			iRec161[l98] = 0;
		}
		for (int l99 = 0; l99 < 2; l99 = l99 + 1) {
			iRec160[l99] = 0;
		}
		for (int l100 = 0; l100 < 2; l100 = l100 + 1) {
			iRec163[l100] = 0;
		}
		for (int l101 = 0; l101 < 2; l101 = l101 + 1) {
			iRec162[l101] = 0;
		}
		for (int l102 = 0; l102 < 2; l102 = l102 + 1) {
			iRec165[l102] = 0;
		}
		for (int l103 = 0; l103 < 2; l103 = l103 + 1) {
			iRec164[l103] = 0;
		}
		for (int l104 = 0; l104 < 2; l104 = l104 + 1) {
			iRec167[l104] = 0;
		}
		for (int l105 = 0; l105 < 2; l105 = l105 + 1) {
			iRec166[l105] = 0;
		}
		for (int l106 = 0; l106 < 2; l106 = l106 + 1) {
			iRec169[l106] = 0;
		}
		for (int l107 = 0; l107 < 2; l107 = l107 + 1) {
			iRec168[l107] = 0;
		}
		for (int l108 = 0; l108 < 2; l108 = l108 + 1) {
			iRec171[l108] = 0;
		}
		for (int l109 = 0; l109 < 2; l109 = l109 + 1) {
			iRec170[l109] = 0;
		}
		for (int l110 = 0; l110 < 2; l110 = l110 + 1) {
			iRec173[l110] = 0;
		}
		for (int l111 = 0; l111 < 2; l111 = l111 + 1) {
			iRec172[l111] = 0;
		}
		for (int l112 = 0; l112 < 2; l112 = l112 + 1) {
			iRec175[l112] = 0;
		}
		for (int l113 = 0; l113 < 2; l113 = l113 + 1) {
			iRec174[l113] = 0;
		}
		for (int l114 = 0; l114 < 2; l114 = l114 + 1) {
			iRec177[l114] = 0;
		}
		for (int l115 = 0; l115 < 2; l115 = l115 + 1) {
			iRec176[l115] = 0;
		}
		for (int l116 = 0; l116 < 2; l116 = l116 + 1) {
			iRec179[l116] = 0;
		}
		for (int l117 = 0; l117 < 2; l117 = l117 + 1) {
			iRec178[l117] = 0;
		}
		for (int l118 = 0; l118 < 2; l118 = l118 + 1) {
			iRec181[l118] = 0;
		}
		for (int l119 = 0; l119 < 2; l119 = l119 + 1) {
			iRec180[l119] = 0;
		}
		for (int l120 = 0; l120 < 2; l120 = l120 + 1) {
			iRec183[l120] = 0;
		}
		for (int l121 = 0; l121 < 2; l121 = l121 + 1) {
			iRec182[l121] = 0;
		}
		for (int l122 = 0; l122 < 2; l122 = l122 + 1) {
			iRec185[l122] = 0;
		}
		for (int l123 = 0; l123 < 2; l123 = l123 + 1) {
			iRec184[l123] = 0;
		}
		for (int l124 = 0; l124 < 2; l124 = l124 + 1) {
			iRec187[l124] = 0;
		}
		for (int l125 = 0; l125 < 2; l125 = l125 + 1) {
			iRec186[l125] = 0;
		}
		for (int l126 = 0; l126 < 2; l126 = l126 + 1) {
			iRec189[l126] = 0;
		}
		for (int l127 = 0; l127 < 2; l127 = l127 + 1) {
			iRec188[l127] = 0;
		}
		for (int l128 = 0; l128 < 2; l128 = l128 + 1) {
			iRec191[l128] = 0;
		}
		for (int l129 = 0; l129 < 2; l129 = l129 + 1) {
			iRec190[l129] = 0;
		}
		for (int l130 = 0; l130 < 2; l130 = l130 + 1) {
			iRec193[l130] = 0;
		}
		for (int l131 = 0; l131 < 2; l131 = l131 + 1) {
			iRec192[l131] = 0;
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
		ui_interface->openVerticalBox("Granulator");
		ui_interface->addHorizontalSlider("delay length", &fHslider1, FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.5f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.1f));
		ui_interface->addHorizontalSlider("grain density", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(64.0f), FAUSTFLOAT(1.0f));
		ui_interface->addHorizontalSlider("grain length", &fHslider2, FAUSTFLOAT(0.1f), FAUSTFLOAT(0.01f), FAUSTFLOAT(0.5f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::max<float>(1.0f, std::min<float>(64.0f, float(fHslider0)));
		float fSlow1 = 1.0f / fSlow0;
		float fSlow2 = float(44.0f < fSlow0);
		int iSlow3 = int(fConst0 * std::max<float>(0.5f, std::min<float>(1e+01f, float(fHslider1))));
		int iSlow4 = int(fConst0 * std::max<float>(0.01f, std::min<float>(0.5f, float(fHslider2))));
		float fSlow5 = float(iSlow4 + -1);
		float fSlow6 = 1.0f / fSlow5;
		float fSlow7 = 0.5f * float(iSlow3);
		float fSlow8 = 6.28318f / fSlow5;
		float fSlow9 = float(42.0f < fSlow0);
		float fSlow10 = float(4e+01f < fSlow0);
		float fSlow11 = float(5e+01f < fSlow0);
		float fSlow12 = float(48.0f < fSlow0);
		float fSlow13 = float(46.0f < fSlow0);
		float fSlow14 = float(56.0f < fSlow0);
		float fSlow15 = float(54.0f < fSlow0);
		float fSlow16 = float(52.0f < fSlow0);
		float fSlow17 = float(62.0f < fSlow0);
		float fSlow18 = float(6e+01f < fSlow0);
		float fSlow19 = float(58.0f < fSlow0);
		float fSlow20 = float(26.0f < fSlow0);
		float fSlow21 = float(24.0f < fSlow0);
		float fSlow22 = float(22.0f < fSlow0);
		float fSlow23 = float(32.0f < fSlow0);
		float fSlow24 = float(3e+01f < fSlow0);
		float fSlow25 = float(28.0f < fSlow0);
		float fSlow26 = float(38.0f < fSlow0);
		float fSlow27 = float(36.0f < fSlow0);
		float fSlow28 = float(34.0f < fSlow0);
		float fSlow29 = float(8.0f < fSlow0);
		float fSlow30 = float(6.0f < fSlow0);
		float fSlow31 = float(4.0f < fSlow0);
		float fSlow32 = float(14.0f < fSlow0);
		float fSlow33 = float(12.0f < fSlow0);
		float fSlow34 = float(1e+01f < fSlow0);
		float fSlow35 = float(2e+01f < fSlow0);
		float fSlow36 = float(18.0f < fSlow0);
		float fSlow37 = float(0.0f < fSlow0);
		float fSlow38 = float(2.0f < fSlow0);
		float fSlow39 = float(16.0f < fSlow0);
		float fSlow40 = float(63.0f < fSlow0);
		float fSlow41 = float(61.0f < fSlow0);
		float fSlow42 = float(41.0f < fSlow0);
		float fSlow43 = float(39.0f < fSlow0);
		float fSlow44 = float(37.0f < fSlow0);
		float fSlow45 = float(47.0f < fSlow0);
		float fSlow46 = float(45.0f < fSlow0);
		float fSlow47 = float(43.0f < fSlow0);
		float fSlow48 = float(53.0f < fSlow0);
		float fSlow49 = float(51.0f < fSlow0);
		float fSlow50 = float(49.0f < fSlow0);
		float fSlow51 = float(59.0f < fSlow0);
		float fSlow52 = float(57.0f < fSlow0);
		float fSlow53 = float(55.0f < fSlow0);
		float fSlow54 = float(23.0f < fSlow0);
		float fSlow55 = float(21.0f < fSlow0);
		float fSlow56 = float(19.0f < fSlow0);
		float fSlow57 = float(29.0f < fSlow0);
		float fSlow58 = float(27.0f < fSlow0);
		float fSlow59 = float(25.0f < fSlow0);
		float fSlow60 = float(35.0f < fSlow0);
		float fSlow61 = float(33.0f < fSlow0);
		float fSlow62 = float(31.0f < fSlow0);
		float fSlow63 = float(5.0f < fSlow0);
		float fSlow64 = float(3.0f < fSlow0);
		float fSlow65 = float(1.0f < fSlow0);
		float fSlow66 = float(11.0f < fSlow0);
		float fSlow67 = float(9.0f < fSlow0);
		float fSlow68 = float(7.0f < fSlow0);
		float fSlow69 = float(17.0f < fSlow0);
		float fSlow70 = float(13.0f < fSlow0);
		float fSlow71 = float(15.0f < fSlow0);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			iRec0[0] = (iRec0[1] + 1) % iSlow3;
			ftbl0[std::max<int>(0, std::min<int>(iRec0[0] % iSlow3, 479999))] = float(input0[i0]);
			int iTemp0 = 1103515245 * (iRec3[1] + 12345);
			int iTemp1 = 1103515245 * (iTemp0 + 12345);
			int iTemp2 = 1103515245 * (iTemp1 + 12345);
			int iTemp3 = 1103515245 * (iTemp2 + 12345);
			int iTemp4 = 1103515245 * (iTemp3 + 12345);
			int iTemp5 = 1103515245 * (iTemp4 + 12345);
			int iTemp6 = 1103515245 * (iTemp5 + 12345);
			int iTemp7 = 1103515245 * (iTemp6 + 12345);
			int iTemp8 = 1103515245 * (iTemp7 + 12345);
			int iTemp9 = 1103515245 * (iTemp8 + 12345);
			int iTemp10 = 1103515245 * (iTemp9 + 12345);
			int iTemp11 = 1103515245 * (iTemp10 + 12345);
			int iTemp12 = 1103515245 * (iTemp11 + 12345);
			int iTemp13 = 1103515245 * (iTemp12 + 12345);
			int iTemp14 = 1103515245 * (iTemp13 + 12345);
			int iTemp15 = 1103515245 * (iTemp14 + 12345);
			int iTemp16 = 1103515245 * (iTemp15 + 12345);
			int iTemp17 = 1103515245 * (iTemp16 + 12345);
			int iTemp18 = 1103515245 * (iTemp17 + 12345);
			int iTemp19 = 1103515245 * (iTemp18 + 12345);
			int iTemp20 = 1103515245 * (iTemp19 + 12345);
			int iTemp21 = 1103515245 * (iTemp20 + 12345);
			int iTemp22 = 1103515245 * (iTemp21 + 12345);
			int iTemp23 = 1103515245 * (iTemp22 + 12345);
			int iTemp24 = 1103515245 * (iTemp23 + 12345);
			int iTemp25 = 1103515245 * (iTemp24 + 12345);
			int iTemp26 = 1103515245 * (iTemp25 + 12345);
			int iTemp27 = 1103515245 * (iTemp26 + 12345);
			int iTemp28 = 1103515245 * (iTemp27 + 12345);
			int iTemp29 = 1103515245 * (iTemp28 + 12345);
			int iTemp30 = 1103515245 * (iTemp29 + 12345);
			int iTemp31 = 1103515245 * (iTemp30 + 12345);
			int iTemp32 = 1103515245 * (iTemp31 + 12345);
			int iTemp33 = 1103515245 * (iTemp32 + 12345);
			int iTemp34 = 1103515245 * (iTemp33 + 12345);
			int iTemp35 = 1103515245 * (iTemp34 + 12345);
			int iTemp36 = 1103515245 * (iTemp35 + 12345);
			int iTemp37 = 1103515245 * (iTemp36 + 12345);
			int iTemp38 = 1103515245 * (iTemp37 + 12345);
			int iTemp39 = 1103515245 * (iTemp38 + 12345);
			int iTemp40 = 1103515245 * (iTemp39 + 12345);
			int iTemp41 = 1103515245 * (iTemp40 + 12345);
			int iTemp42 = 1103515245 * (iTemp41 + 12345);
			int iTemp43 = 1103515245 * (iTemp42 + 12345);
			int iTemp44 = 1103515245 * (iTemp43 + 12345);
			int iTemp45 = 1103515245 * (iTemp44 + 12345);
			int iTemp46 = 1103515245 * (iTemp45 + 12345);
			int iTemp47 = 1103515245 * (iTemp46 + 12345);
			int iTemp48 = 1103515245 * (iTemp47 + 12345);
			int iTemp49 = 1103515245 * (iTemp48 + 12345);
			int iTemp50 = 1103515245 * (iTemp49 + 12345);
			int iTemp51 = 1103515245 * (iTemp50 + 12345);
			int iTemp52 = 1103515245 * (iTemp51 + 12345);
			int iTemp53 = 1103515245 * (iTemp52 + 12345);
			int iTemp54 = 1103515245 * (iTemp53 + 12345);
			int iTemp55 = 1103515245 * (iTemp54 + 12345);
			int iTemp56 = 1103515245 * (iTemp55 + 12345);
			int iTemp57 = 1103515245 * (iTemp56 + 12345);
			int iTemp58 = 1103515245 * (iTemp57 + 12345);
			int iTemp59 = 1103515245 * (iTemp58 + 12345);
			int iTemp60 = 1103515245 * (iTemp59 + 12345);
			int iTemp61 = 1103515245 * (iTemp60 + 12345);
			int iTemp62 = 1103515245 * (iTemp61 + 12345);
			int iTemp63 = 1103515245 * (iTemp62 + 12345);
			iRec3[0] = 1103515245 * (iTemp63 + 12345);
			int iRec4 = iTemp63;
			int iRec5 = iTemp62;
			int iRec6 = iTemp61;
			int iRec7 = iTemp60;
			int iRec8 = iTemp59;
			int iRec9 = iTemp58;
			int iRec10 = iTemp57;
			int iRec11 = iTemp56;
			int iRec12 = iTemp55;
			int iRec13 = iTemp54;
			int iRec14 = iTemp53;
			int iRec15 = iTemp52;
			int iRec16 = iTemp51;
			int iRec17 = iTemp50;
			int iRec18 = iTemp49;
			int iRec19 = iTemp48;
			int iRec20 = iTemp47;
			int iRec21 = iTemp46;
			int iRec22 = iTemp45;
			int iRec23 = iTemp44;
			int iRec24 = iTemp43;
			int iRec25 = iTemp42;
			int iRec26 = iTemp41;
			int iRec27 = iTemp40;
			int iRec28 = iTemp39;
			int iRec29 = iTemp38;
			int iRec30 = iTemp37;
			int iRec31 = iTemp36;
			int iRec32 = iTemp35;
			int iRec33 = iTemp34;
			int iRec34 = iTemp33;
			int iRec35 = iTemp32;
			int iRec36 = iTemp31;
			int iRec37 = iTemp30;
			int iRec38 = iTemp29;
			int iRec39 = iTemp28;
			int iRec40 = iTemp27;
			int iRec41 = iTemp26;
			int iRec42 = iTemp25;
			int iRec43 = iTemp24;
			int iRec44 = iTemp23;
			int iRec45 = iTemp22;
			int iRec46 = iTemp21;
			int iRec47 = iTemp20;
			int iRec48 = iTemp19;
			int iRec49 = iTemp18;
			int iRec50 = iTemp17;
			int iRec51 = iTemp16;
			int iRec52 = iTemp15;
			int iRec53 = iTemp14;
			int iRec54 = iTemp13;
			int iRec55 = iTemp12;
			int iRec56 = iTemp11;
			int iRec57 = iTemp10;
			int iRec58 = iTemp9;
			int iRec59 = iTemp8;
			int iRec60 = iTemp7;
			int iRec61 = iTemp6;
			int iRec62 = iTemp5;
			int iRec63 = iTemp4;
			int iRec64 = iTemp3;
			int iRec65 = iTemp2;
			int iRec66 = iTemp1;
			int iTemp64 = int(fSlow7 * (1.0f - float(iRec47)));
			int iTemp65 = 1 - iVec0[1];
			iRec2[0] = iRec2[1] * iVec0[1] + iTemp64 * iTemp65;
			iRec67[0] = (iRec67[1] + 1) % iSlow4;
			int iTemp66 = (iRec2[0] + iRec67[0]) % iSlow4;
			float fTemp67 = float(iTemp66);
			int iTemp68 = int(fSlow6 * fTemp67);
			iRec1[0] = iRec1[1] * (1 - iTemp68) + iTemp64 * iTemp68;
			int iTemp69 = int(fSlow7 * (1.0f - float(iRec45)));
			iRec69[0] = iRec69[1] * iVec0[1] + iTemp69 * iTemp65;
			int iTemp70 = (iRec67[0] + iRec69[0]) % iSlow4;
			float fTemp71 = float(iTemp70);
			int iTemp72 = int(fSlow6 * fTemp71);
			iRec68[0] = iRec68[1] * (1 - iTemp72) + iTemp69 * iTemp72;
			int iTemp73 = int(fSlow7 * (1.0f - float(iRec43)));
			iRec71[0] = iRec71[1] * iVec0[1] + iTemp73 * iTemp65;
			int iTemp74 = (iRec67[0] + iRec71[0]) % iSlow4;
			float fTemp75 = float(iTemp74);
			int iTemp76 = int(fSlow6 * fTemp75);
			iRec70[0] = iRec70[1] * (1 - iTemp76) + iTemp73 * iTemp76;
			int iTemp77 = int(fSlow7 * (1.0f - float(iRec53)));
			iRec73[0] = iRec73[1] * iVec0[1] + iTemp77 * iTemp65;
			int iTemp78 = (iRec67[0] + iRec73[0]) % iSlow4;
			float fTemp79 = float(iTemp78);
			int iTemp80 = int(fSlow6 * fTemp79);
			iRec72[0] = iRec72[1] * (1 - iTemp80) + iTemp77 * iTemp80;
			int iTemp81 = int(fSlow7 * (1.0f - float(iRec51)));
			iRec75[0] = iRec75[1] * iVec0[1] + iTemp81 * iTemp65;
			int iTemp82 = (iRec67[0] + iRec75[0]) % iSlow4;
			float fTemp83 = float(iTemp82);
			int iTemp84 = int(fSlow6 * fTemp83);
			iRec74[0] = iRec74[1] * (1 - iTemp84) + iTemp81 * iTemp84;
			int iTemp85 = int(fSlow7 * (1.0f - float(iRec49)));
			iRec77[0] = iRec77[1] * iVec0[1] + iTemp85 * iTemp65;
			int iTemp86 = (iRec77[0] + iRec67[0]) % iSlow4;
			float fTemp87 = float(iTemp86);
			int iTemp88 = int(fSlow6 * fTemp87);
			iRec76[0] = (1 - iTemp88) * iRec76[1] + iTemp88 * iTemp85;
			int iTemp89 = int(fSlow7 * (1.0f - float(iRec59)));
			iRec79[0] = iRec79[1] * iVec0[1] + iTemp89 * iTemp65;
			int iTemp90 = (iRec67[0] + iRec79[0]) % iSlow4;
			float fTemp91 = float(iTemp90);
			int iTemp92 = int(fSlow6 * fTemp91);
			iRec78[0] = iRec78[1] * (1 - iTemp92) + iTemp89 * iTemp92;
			int iTemp93 = int(fSlow7 * (1.0f - float(iRec57)));
			iRec81[0] = iRec81[1] * iVec0[1] + iTemp93 * iTemp65;
			int iTemp94 = (iRec67[0] + iRec81[0]) % iSlow4;
			float fTemp95 = float(iTemp94);
			int iTemp96 = int(fSlow6 * fTemp95);
			iRec80[0] = iRec80[1] * (1 - iTemp96) + iTemp93 * iTemp96;
			int iTemp97 = int(fSlow7 * (1.0f - float(iRec55)));
			iRec83[0] = iTemp97 * iTemp65 + iRec83[1] * iVec0[1];
			int iTemp98 = (iRec67[0] + iRec83[0]) % iSlow4;
			float fTemp99 = float(iTemp98);
			int iTemp100 = int(fSlow6 * fTemp99);
			iRec82[0] = iRec82[1] * (1 - iTemp100) + iTemp97 * iTemp100;
			int iTemp101 = int(fSlow7 * (1.0f - float(iRec65)));
			iRec85[0] = iRec85[1] * iVec0[1] + iTemp101 * iTemp65;
			int iTemp102 = (iRec67[0] + iRec85[0]) % iSlow4;
			float fTemp103 = float(iTemp102);
			int iTemp104 = int(fSlow6 * fTemp103);
			iRec84[0] = iRec84[1] * (1 - iTemp104) + iTemp101 * iTemp104;
			int iTemp105 = int(fSlow7 * (1.0f - float(iRec63)));
			iRec87[0] = iRec87[1] * iVec0[1] + iTemp105 * iTemp65;
			int iTemp106 = (iRec67[0] + iRec87[0]) % iSlow4;
			float fTemp107 = float(iTemp106);
			int iTemp108 = int(fSlow6 * fTemp107);
			iRec86[0] = iRec86[1] * (1 - iTemp108) + iTemp105 * iTemp108;
			int iTemp109 = int(fSlow7 * (1.0f - float(iRec61)));
			iRec89[0] = iTemp109 * iTemp65 + iRec89[1] * iVec0[1];
			int iTemp110 = (iRec67[0] + iRec89[0]) % iSlow4;
			float fTemp111 = float(iTemp110);
			int iTemp112 = int(fSlow6 * fTemp111);
			iRec88[0] = iRec88[1] * (1 - iTemp112) + iTemp109 * iTemp112;
			int iTemp113 = int(fSlow7 * (1.0f - float(iRec29)));
			iRec91[0] = iRec91[1] * iVec0[1] + iTemp113 * iTemp65;
			int iTemp114 = (iRec67[0] + iRec91[0]) % iSlow4;
			float fTemp115 = float(iTemp114);
			int iTemp116 = int(fSlow6 * fTemp115);
			iRec90[0] = iRec90[1] * (1 - iTemp116) + iTemp113 * iTemp116;
			int iTemp117 = int(fSlow7 * (1.0f - float(iRec27)));
			iRec93[0] = iRec93[1] * iVec0[1] + iTemp117 * iTemp65;
			int iTemp118 = (iRec67[0] + iRec93[0]) % iSlow4;
			float fTemp119 = float(iTemp118);
			int iTemp120 = int(fSlow6 * fTemp119);
			iRec92[0] = iRec92[1] * (1 - iTemp120) + iTemp117 * iTemp120;
			int iTemp121 = int(fSlow7 * (1.0f - float(iRec25)));
			iRec95[0] = iRec95[1] * iVec0[1] + iTemp121 * iTemp65;
			int iTemp122 = (iRec67[0] + iRec95[0]) % iSlow4;
			float fTemp123 = float(iTemp122);
			int iTemp124 = int(fSlow6 * fTemp123);
			iRec94[0] = iRec94[1] * (1 - iTemp124) + iTemp121 * iTemp124;
			int iTemp125 = int(fSlow7 * (1.0f - float(iRec35)));
			iRec97[0] = iRec97[1] * iVec0[1] + iTemp125 * iTemp65;
			int iTemp126 = (iRec67[0] + iRec97[0]) % iSlow4;
			float fTemp127 = float(iTemp126);
			int iTemp128 = int(fSlow6 * fTemp127);
			iRec96[0] = iRec96[1] * (1 - iTemp128) + iTemp125 * iTemp128;
			int iTemp129 = int(fSlow7 * (1.0f - float(iRec33)));
			iRec99[0] = iRec99[1] * iVec0[1] + iTemp129 * iTemp65;
			int iTemp130 = (iRec67[0] + iRec99[0]) % iSlow4;
			float fTemp131 = float(iTemp130);
			int iTemp132 = int(fSlow6 * fTemp131);
			iRec98[0] = iRec98[1] * (1 - iTemp132) + iTemp129 * iTemp132;
			int iTemp133 = int(fSlow7 * (1.0f - float(iRec31)));
			iRec101[0] = iRec101[1] * iVec0[1] + iTemp133 * iTemp65;
			int iTemp134 = (iRec67[0] + iRec101[0]) % iSlow4;
			float fTemp135 = float(iTemp134);
			int iTemp136 = int(fSlow6 * fTemp135);
			iRec100[0] = iRec100[1] * (1 - iTemp136) + iTemp133 * iTemp136;
			int iTemp137 = int(fSlow7 * (1.0f - float(iRec41)));
			iRec103[0] = iRec103[1] * iVec0[1] + iTemp137 * iTemp65;
			int iTemp138 = (iRec67[0] + iRec103[0]) % iSlow4;
			float fTemp139 = float(iTemp138);
			int iTemp140 = int(fSlow6 * fTemp139);
			iRec102[0] = iRec102[1] * (1 - iTemp140) + iTemp137 * iTemp140;
			int iTemp141 = int(fSlow7 * (1.0f - float(iRec39)));
			iRec105[0] = iRec105[1] * iVec0[1] + iTemp141 * iTemp65;
			int iTemp142 = (iRec67[0] + iRec105[0]) % iSlow4;
			float fTemp143 = float(iTemp142);
			int iTemp144 = int(fSlow6 * fTemp143);
			iRec104[0] = iRec104[1] * (1 - iTemp144) + iTemp141 * iTemp144;
			int iTemp145 = int(fSlow7 * (1.0f - float(iRec37)));
			iRec107[0] = iRec107[1] * iVec0[1] + iTemp145 * iTemp65;
			int iTemp146 = (iRec67[0] + iRec107[0]) % iSlow4;
			float fTemp147 = float(iTemp146);
			int iTemp148 = int(fSlow6 * fTemp147);
			iRec106[0] = iRec106[1] * (1 - iTemp148) + iTemp145 * iTemp148;
			int iTemp149 = int(fSlow7 * (1.0f - float(iRec11)));
			iRec109[0] = iRec109[1] * iVec0[1] + iTemp149 * iTemp65;
			int iTemp150 = (iRec67[0] + iRec109[0]) % iSlow4;
			float fTemp151 = float(iTemp150);
			int iTemp152 = int(fSlow6 * fTemp151);
			iRec108[0] = iRec108[1] * (1 - iTemp152) + iTemp149 * iTemp152;
			int iTemp153 = int(fSlow7 * (1.0f - float(iRec9)));
			iRec111[0] = iRec111[1] * iVec0[1] + iTemp153 * iTemp65;
			int iTemp154 = (iRec67[0] + iRec111[0]) % iSlow4;
			float fTemp155 = float(iTemp154);
			int iTemp156 = int(fSlow6 * fTemp155);
			iRec110[0] = iRec110[1] * (1 - iTemp156) + iTemp153 * iTemp156;
			int iTemp157 = int(fSlow7 * (1.0f - float(iRec7)));
			iRec113[0] = iRec113[1] * iVec0[1] + iTemp157 * iTemp65;
			int iTemp158 = (iRec67[0] + iRec113[0]) % iSlow4;
			float fTemp159 = float(iTemp158);
			int iTemp160 = int(fSlow6 * fTemp159);
			iRec112[0] = iRec112[1] * (1 - iTemp160) + iTemp157 * iTemp160;
			int iTemp161 = int(fSlow7 * (1.0f - float(iRec17)));
			iRec115[0] = iRec115[1] * iVec0[1] + iTemp161 * iTemp65;
			int iTemp162 = (iRec67[0] + iRec115[0]) % iSlow4;
			float fTemp163 = float(iTemp162);
			int iTemp164 = int(fSlow6 * fTemp163);
			iRec114[0] = iRec114[1] * (1 - iTemp164) + iTemp161 * iTemp164;
			int iTemp165 = int(fSlow7 * (1.0f - float(iRec15)));
			iRec117[0] = iRec117[1] * iVec0[1] + iTemp165 * iTemp65;
			int iTemp166 = (iRec67[0] + iRec117[0]) % iSlow4;
			float fTemp167 = float(iTemp166);
			int iTemp168 = int(fSlow6 * fTemp167);
			iRec116[0] = iRec116[1] * (1 - iTemp168) + iTemp165 * iTemp168;
			int iTemp169 = int(fSlow7 * (1.0f - float(iRec13)));
			iRec119[0] = iRec119[1] * iVec0[1] + iTemp169 * iTemp65;
			int iTemp170 = (iRec67[0] + iRec119[0]) % iSlow4;
			float fTemp171 = float(iTemp170);
			int iTemp172 = int(fSlow6 * fTemp171);
			iRec118[0] = iRec118[1] * (1 - iTemp172) + iTemp169 * iTemp172;
			int iTemp173 = int(fSlow7 * (1.0f - float(iRec23)));
			iRec121[0] = iRec121[1] * iVec0[1] + iTemp173 * iTemp65;
			int iTemp174 = (iRec67[0] + iRec121[0]) % iSlow4;
			float fTemp175 = float(iTemp174);
			int iTemp176 = int(fSlow6 * fTemp175);
			iRec120[0] = iRec120[1] * (1 - iTemp176) + iTemp173 * iTemp176;
			int iTemp177 = int(fSlow7 * (1.0f - float(iRec21)));
			iRec123[0] = iRec123[1] * iVec0[1] + iTemp177 * iTemp65;
			int iTemp178 = (iRec67[0] + iRec123[0]) % iSlow4;
			float fTemp179 = float(iTemp178);
			int iTemp180 = int(fSlow6 * fTemp179);
			iRec122[0] = iRec122[1] * (1 - iTemp180) + iTemp177 * iTemp180;
			int iTemp181 = int(fSlow7 * (1.0f - float(iRec3[0])));
			iRec125[0] = iRec125[1] * iVec0[1] + iTemp181 * iTemp65;
			int iTemp182 = (iRec125[0] + iRec67[0]) % iSlow4;
			float fTemp183 = float(iTemp182);
			int iTemp184 = int(fSlow6 * fTemp183);
			iRec124[0] = iRec124[1] * (1 - iTemp184) + iTemp181 * iTemp184;
			int iTemp185 = int(fSlow7 * (1.0f - float(iRec5)));
			iRec127[0] = iRec127[1] * iVec0[1] + iTemp185 * iTemp65;
			int iTemp186 = (iRec67[0] + iRec127[0]) % iSlow4;
			float fTemp187 = float(iTemp186);
			int iTemp188 = int(fSlow6 * fTemp187);
			iRec126[0] = iRec126[1] * (1 - iTemp188) + iTemp185 * iTemp188;
			int iTemp189 = int(fSlow7 * (1.0f - float(iRec19)));
			iRec128[0] = iRec128[1] * iVec0[1] + iTemp189 * iTemp65;
			int iTemp190 = (iRec67[0] + iRec128[0]) % iSlow4;
			float fTemp191 = float(iTemp190);
			int iTemp192 = int(fSlow6 * fTemp191);
			iRec129[0] = iRec129[1] * (1 - iTemp192) + iTemp189 * iTemp192;
			output0[i0] = FAUSTFLOAT(fSlow1 * (fSlow2 * ftbl0[std::max<int>(0, std::min<int>((iRec1[0] + iTemp66) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp67) + fSlow9 * ftbl0[std::max<int>(0, std::min<int>((iRec68[0] + iTemp70) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp71) + fSlow10 * ftbl0[std::max<int>(0, std::min<int>((iRec70[0] + iTemp74) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp75) + fSlow11 * ftbl0[std::max<int>(0, std::min<int>((iRec72[0] + iTemp78) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp79) + fSlow12 * ftbl0[std::max<int>(0, std::min<int>((iRec74[0] + iTemp82) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp83) + fSlow13 * ftbl0[std::max<int>(0, std::min<int>((iRec76[0] + iTemp86) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp87) + fSlow14 * ftbl0[std::max<int>(0, std::min<int>((iRec78[0] + iTemp90) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp91) + fSlow15 * ftbl0[std::max<int>(0, std::min<int>((iRec80[0] + iTemp94) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp95) + fSlow16 * ftbl0[std::max<int>(0, std::min<int>((iRec82[0] + iTemp98) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp99) + fSlow17 * ftbl0[std::max<int>(0, std::min<int>((iRec84[0] + iTemp102) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp103) + fSlow18 * ftbl0[std::max<int>(0, std::min<int>((iRec86[0] + iTemp106) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp107) + fSlow19 * ftbl0[std::max<int>(0, std::min<int>((iRec88[0] + iTemp110) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp111) + fSlow20 * ftbl0[std::max<int>(0, std::min<int>((iRec90[0] + iTemp114) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp115) + fSlow21 * ftbl0[std::max<int>(0, std::min<int>((iRec92[0] + iTemp118) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp119) + fSlow22 * ftbl0[std::max<int>(0, std::min<int>((iRec94[0] + iTemp122) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp123) + fSlow23 * ftbl0[std::max<int>(0, std::min<int>((iRec96[0] + iTemp126) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp127) + fSlow24 * ftbl0[std::max<int>(0, std::min<int>((iRec98[0] + iTemp130) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp131) + fSlow25 * ftbl0[std::max<int>(0, std::min<int>((iRec100[0] + iTemp134) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp135) + fSlow26 * ftbl0[std::max<int>(0, std::min<int>((iRec102[0] + iTemp138) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp139) + fSlow27 * ftbl0[std::max<int>(0, std::min<int>((iRec104[0] + iTemp142) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp143) + fSlow28 * ftbl0[std::max<int>(0, std::min<int>((iRec106[0] + iTemp146) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp147) + fSlow29 * ftbl0[std::max<int>(0, std::min<int>((iRec108[0] + iTemp150) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp151) + fSlow30 * ftbl0[std::max<int>(0, std::min<int>((iRec110[0] + iTemp154) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp155) + fSlow31 * ftbl0[std::max<int>(0, std::min<int>((iRec112[0] + iTemp158) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp159) + fSlow32 * ftbl0[std::max<int>(0, std::min<int>((iRec114[0] + iTemp162) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp163) + fSlow33 * ftbl0[std::max<int>(0, std::min<int>((iRec116[0] + iTemp166) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp167) + fSlow34 * ftbl0[std::max<int>(0, std::min<int>((iRec118[0] + iTemp170) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp171) + fSlow35 * ftbl0[std::max<int>(0, std::min<int>((iRec120[0] + iTemp174) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp175) + fSlow36 * ftbl0[std::max<int>(0, std::min<int>((iRec122[0] + iTemp178) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp179) + fSlow37 * ftbl0[std::max<int>(0, std::min<int>((iRec124[0] + iTemp182) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp183) + fSlow38 * ftbl0[std::max<int>(0, std::min<int>((iRec126[0] + iTemp186) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp187) + fSlow39 * std::sin(fSlow8 * fTemp191) * ftbl0[std::max<int>(0, std::min<int>((iRec129[0] + iTemp190) % iSlow3, 479999))]));
			int iTemp193 = int(fSlow7 * (1.0f - float(iRec66)));
			iRec131[0] = iRec131[1] * iVec0[1] + iTemp193 * iTemp65;
			int iTemp194 = (iRec67[0] + iRec131[0]) % iSlow4;
			float fTemp195 = float(iTemp194);
			int iTemp196 = int(fSlow6 * fTemp195);
			iRec130[0] = iRec130[1] * (1 - iTemp196) + iTemp193 * iTemp196;
			int iTemp197 = int(fSlow7 * (1.0f - float(iRec64)));
			iRec133[0] = iRec133[1] * iVec0[1] + iTemp197 * iTemp65;
			int iTemp198 = (iRec67[0] + iRec133[0]) % iSlow4;
			float fTemp199 = float(iTemp198);
			int iTemp200 = int(fSlow6 * fTemp199);
			iRec132[0] = iRec132[1] * (1 - iTemp200) + iTemp197 * iTemp200;
			int iTemp201 = int(fSlow7 * (1.0f - float(iRec44)));
			iRec135[0] = iRec135[1] * iVec0[1] + iTemp201 * iTemp65;
			int iTemp202 = (iRec67[0] + iRec135[0]) % iSlow4;
			float fTemp203 = float(iTemp202);
			int iTemp204 = int(fSlow6 * fTemp203);
			iRec134[0] = iRec134[1] * (1 - iTemp204) + iTemp201 * iTemp204;
			int iTemp205 = int(fSlow7 * (1.0f - float(iRec42)));
			iRec137[0] = iRec137[1] * iVec0[1] + iTemp205 * iTemp65;
			int iTemp206 = (iRec67[0] + iRec137[0]) % iSlow4;
			float fTemp207 = float(iTemp206);
			int iTemp208 = int(fSlow6 * fTemp207);
			iRec136[0] = iRec136[1] * (1 - iTemp208) + iTemp205 * iTemp208;
			int iTemp209 = int(fSlow7 * (1.0f - float(iRec40)));
			iRec139[0] = iRec139[1] * iVec0[1] + iTemp209 * iTemp65;
			int iTemp210 = (iRec67[0] + iRec139[0]) % iSlow4;
			float fTemp211 = float(iTemp210);
			int iTemp212 = int(fSlow6 * fTemp211);
			iRec138[0] = iRec138[1] * (1 - iTemp212) + iTemp209 * iTemp212;
			int iTemp213 = int(fSlow7 * (1.0f - float(iRec50)));
			iRec141[0] = iRec141[1] * iVec0[1] + iTemp213 * iTemp65;
			int iTemp214 = (iRec67[0] + iRec141[0]) % iSlow4;
			float fTemp215 = float(iTemp214);
			int iTemp216 = int(fSlow6 * fTemp215);
			iRec140[0] = iRec140[1] * (1 - iTemp216) + iTemp213 * iTemp216;
			int iTemp217 = int(fSlow7 * (1.0f - float(iRec48)));
			iRec143[0] = iRec143[1] * iVec0[1] + iTemp217 * iTemp65;
			int iTemp218 = (iRec67[0] + iRec143[0]) % iSlow4;
			float fTemp219 = float(iTemp218);
			int iTemp220 = int(fSlow6 * fTemp219);
			iRec142[0] = iRec142[1] * (1 - iTemp220) + iTemp217 * iTemp220;
			int iTemp221 = int(fSlow7 * (1.0f - float(iRec46)));
			iRec145[0] = iRec145[1] * iVec0[1] + iTemp221 * iTemp65;
			int iTemp222 = (iRec67[0] + iRec145[0]) % iSlow4;
			float fTemp223 = float(iTemp222);
			int iTemp224 = int(fSlow6 * fTemp223);
			iRec144[0] = iRec144[1] * (1 - iTemp224) + iTemp221 * iTemp224;
			int iTemp225 = int(fSlow7 * (1.0f - float(iRec56)));
			iRec147[0] = iRec147[1] * iVec0[1] + iTemp225 * iTemp65;
			int iTemp226 = (iRec67[0] + iRec147[0]) % iSlow4;
			float fTemp227 = float(iTemp226);
			int iTemp228 = int(fSlow6 * fTemp227);
			iRec146[0] = iRec146[1] * (1 - iTemp228) + iTemp225 * iTemp228;
			int iTemp229 = int(fSlow7 * (1.0f - float(iRec54)));
			iRec149[0] = iRec149[1] * iVec0[1] + iTemp229 * iTemp65;
			int iTemp230 = (iRec67[0] + iRec149[0]) % iSlow4;
			float fTemp231 = float(iTemp230);
			int iTemp232 = int(fSlow6 * fTemp231);
			iRec148[0] = iRec148[1] * (1 - iTemp232) + iTemp229 * iTemp232;
			int iTemp233 = int(fSlow7 * (1.0f - float(iRec52)));
			iRec151[0] = iRec151[1] * iVec0[1] + iTemp233 * iTemp65;
			int iTemp234 = (iRec67[0] + iRec151[0]) % iSlow4;
			float fTemp235 = float(iTemp234);
			int iTemp236 = int(fSlow6 * fTemp235);
			iRec150[0] = iRec150[1] * (1 - iTemp236) + iTemp233 * iTemp236;
			int iTemp237 = int(fSlow7 * (1.0f - float(iRec62)));
			iRec153[0] = iRec153[1] * iVec0[1] + iTemp237 * iTemp65;
			int iTemp238 = (iRec67[0] + iRec153[0]) % iSlow4;
			float fTemp239 = float(iTemp238);
			int iTemp240 = int(fSlow6 * fTemp239);
			iRec152[0] = iRec152[1] * (1 - iTemp240) + iTemp237 * iTemp240;
			int iTemp241 = int(fSlow7 * (1.0f - float(iRec60)));
			iRec155[0] = iRec155[1] * iVec0[1] + iTemp241 * iTemp65;
			int iTemp242 = (iRec67[0] + iRec155[0]) % iSlow4;
			float fTemp243 = float(iTemp242);
			int iTemp244 = int(fSlow6 * fTemp243);
			iRec154[0] = iRec154[1] * (1 - iTemp244) + iTemp241 * iTemp244;
			int iTemp245 = int(fSlow7 * (1.0f - float(iRec58)));
			iRec157[0] = iRec157[1] * iVec0[1] + iTemp245 * iTemp65;
			int iTemp246 = (iRec67[0] + iRec157[0]) % iSlow4;
			float fTemp247 = float(iTemp246);
			int iTemp248 = int(fSlow6 * fTemp247);
			iRec156[0] = iRec156[1] * (1 - iTemp248) + iTemp245 * iTemp248;
			int iTemp249 = int(fSlow7 * (1.0f - float(iRec26)));
			iRec159[0] = iRec159[1] * iVec0[1] + iTemp249 * iTemp65;
			int iTemp250 = (iRec67[0] + iRec159[0]) % iSlow4;
			float fTemp251 = float(iTemp250);
			int iTemp252 = int(fSlow6 * fTemp251);
			iRec158[0] = iRec158[1] * (1 - iTemp252) + iTemp249 * iTemp252;
			int iTemp253 = int(fSlow7 * (1.0f - float(iRec24)));
			iRec161[0] = iRec161[1] * iVec0[1] + iTemp253 * iTemp65;
			int iTemp254 = (iRec67[0] + iRec161[0]) % iSlow4;
			float fTemp255 = float(iTemp254);
			int iTemp256 = int(fSlow6 * fTemp255);
			iRec160[0] = iRec160[1] * (1 - iTemp256) + iTemp253 * iTemp256;
			int iTemp257 = int(fSlow7 * (1.0f - float(iRec22)));
			iRec163[0] = iRec163[1] * iVec0[1] + iTemp257 * iTemp65;
			int iTemp258 = (iRec67[0] + iRec163[0]) % iSlow4;
			float fTemp259 = float(iTemp258);
			int iTemp260 = int(fSlow6 * fTemp259);
			iRec162[0] = iRec162[1] * (1 - iTemp260) + iTemp257 * iTemp260;
			int iTemp261 = int(fSlow7 * (1.0f - float(iRec32)));
			iRec165[0] = iRec165[1] * iVec0[1] + iTemp261 * iTemp65;
			int iTemp262 = (iRec67[0] + iRec165[0]) % iSlow4;
			float fTemp263 = float(iTemp262);
			int iTemp264 = int(fSlow6 * fTemp263);
			iRec164[0] = iRec164[1] * (1 - iTemp264) + iTemp261 * iTemp264;
			int iTemp265 = int(fSlow7 * (1.0f - float(iRec30)));
			iRec167[0] = iRec167[1] * iVec0[1] + iTemp265 * iTemp65;
			int iTemp266 = (iRec67[0] + iRec167[0]) % iSlow4;
			float fTemp267 = float(iTemp266);
			int iTemp268 = int(fSlow6 * fTemp267);
			iRec166[0] = iRec166[1] * (1 - iTemp268) + iTemp265 * iTemp268;
			int iTemp269 = int(fSlow7 * (1.0f - float(iRec28)));
			iRec169[0] = iTemp269 * iTemp65 + iRec169[1] * iVec0[1];
			int iTemp270 = (iRec67[0] + iRec169[0]) % iSlow4;
			float fTemp271 = float(iTemp270);
			int iTemp272 = int(fSlow6 * fTemp271);
			iRec168[0] = iRec168[1] * (1 - iTemp272) + iTemp269 * iTemp272;
			int iTemp273 = int(fSlow7 * (1.0f - float(iRec38)));
			iRec171[0] = iRec171[1] * iVec0[1] + iTemp273 * iTemp65;
			int iTemp274 = (iRec67[0] + iRec171[0]) % iSlow4;
			float fTemp275 = float(iTemp274);
			int iTemp276 = int(fSlow6 * fTemp275);
			iRec170[0] = iRec170[1] * (1 - iTemp276) + iTemp273 * iTemp276;
			int iTemp277 = int(fSlow7 * (1.0f - float(iRec36)));
			iRec173[0] = iRec173[1] * iVec0[1] + iTemp277 * iTemp65;
			int iTemp278 = (iRec67[0] + iRec173[0]) % iSlow4;
			float fTemp279 = float(iTemp278);
			int iTemp280 = int(fSlow6 * fTemp279);
			iRec172[0] = iRec172[1] * (1 - iTemp280) + iTemp277 * iTemp280;
			int iTemp281 = int(fSlow7 * (1.0f - float(iRec34)));
			iRec175[0] = iRec175[1] * iVec0[1] + iTemp281 * iTemp65;
			int iTemp282 = (iRec67[0] + iRec175[0]) % iSlow4;
			float fTemp283 = float(iTemp282);
			int iTemp284 = int(fSlow6 * fTemp283);
			iRec174[0] = iRec174[1] * (1 - iTemp284) + iTemp281 * iTemp284;
			int iTemp285 = int(fSlow7 * (1.0f - float(iRec8)));
			iRec177[0] = iRec177[1] * iVec0[1] + iTemp285 * iTemp65;
			int iTemp286 = (iRec67[0] + iRec177[0]) % iSlow4;
			float fTemp287 = float(iTemp286);
			int iTemp288 = int(fSlow6 * fTemp287);
			iRec176[0] = iRec176[1] * (1 - iTemp288) + iTemp285 * iTemp288;
			int iTemp289 = int(fSlow7 * (1.0f - float(iRec6)));
			iRec179[0] = iRec179[1] * iVec0[1] + iTemp289 * iTemp65;
			int iTemp290 = (iRec67[0] + iRec179[0]) % iSlow4;
			float fTemp291 = float(iTemp290);
			int iTemp292 = int(fSlow6 * fTemp291);
			iRec178[0] = iRec178[1] * (1 - iTemp292) + iTemp289 * iTemp292;
			int iTemp293 = int(fSlow7 * (1.0f - float(iRec4)));
			iRec181[0] = iRec181[1] * iVec0[1] + iTemp293 * iTemp65;
			int iTemp294 = (iRec67[0] + iRec181[0]) % iSlow4;
			float fTemp295 = float(iTemp294);
			int iTemp296 = int(fSlow6 * fTemp295);
			iRec180[0] = iRec180[1] * (1 - iTemp296) + iTemp293 * iTemp296;
			int iTemp297 = int(fSlow7 * (1.0f - float(iRec14)));
			iRec183[0] = iRec183[1] * iVec0[1] + iTemp297 * iTemp65;
			int iTemp298 = (iRec67[0] + iRec183[0]) % iSlow4;
			float fTemp299 = float(iTemp298);
			int iTemp300 = int(fSlow6 * fTemp299);
			iRec182[0] = iRec182[1] * (1 - iTemp300) + iTemp297 * iTemp300;
			int iTemp301 = int(fSlow7 * (1.0f - float(iRec12)));
			iRec185[0] = iRec185[1] * iVec0[1] + iTemp301 * iTemp65;
			int iTemp302 = (iRec67[0] + iRec185[0]) % iSlow4;
			float fTemp303 = float(iTemp302);
			int iTemp304 = int(fSlow6 * fTemp303);
			iRec184[0] = iRec184[1] * (1 - iTemp304) + iTemp301 * iTemp304;
			int iTemp305 = int(fSlow7 * (1.0f - float(iRec10)));
			iRec187[0] = iTemp305 * iTemp65 + iRec187[1] * iVec0[1];
			int iTemp306 = (iRec67[0] + iRec187[0]) % iSlow4;
			float fTemp307 = float(iTemp306);
			int iTemp308 = int(fSlow6 * fTemp307);
			iRec186[0] = iRec186[1] * (1 - iTemp308) + iTemp305 * iTemp308;
			int iTemp309 = int(fSlow7 * (1.0f - float(iRec20)));
			iRec189[0] = iRec189[1] * iVec0[1] + iTemp309 * iTemp65;
			int iTemp310 = (iRec67[0] + iRec189[0]) % iSlow4;
			float fTemp311 = float(iTemp310);
			int iTemp312 = int(fSlow6 * fTemp311);
			iRec188[0] = iRec188[1] * (1 - iTemp312) + iTemp309 * iTemp312;
			int iTemp313 = int(fSlow7 * (1.0f - float(iRec16)));
			iRec191[0] = iTemp313 * iTemp65 + iRec191[1] * iVec0[1];
			int iTemp314 = (iRec67[0] + iRec191[0]) % iSlow4;
			float fTemp315 = float(iTemp314);
			int iTemp316 = int(fSlow6 * fTemp315);
			iRec190[0] = iRec190[1] * (1 - iTemp316) + iTemp313 * iTemp316;
			int iTemp317 = int(fSlow7 * (1.0f - float(iRec18)));
			iRec193[0] = iRec193[1] * iVec0[1] + iTemp317 * iTemp65;
			int iTemp318 = (iRec67[0] + iRec193[0]) % iSlow4;
			float fTemp319 = float(iTemp318);
			int iTemp320 = int(fSlow6 * fTemp319);
			iRec192[0] = iRec192[1] * (1 - iTemp320) + iTemp317 * iTemp320;
			output1[i0] = FAUSTFLOAT(fSlow1 * (fSlow40 * ftbl0[std::max<int>(0, std::min<int>((iRec130[0] + iTemp194) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp195) + fSlow41 * ftbl0[std::max<int>(0, std::min<int>((iRec132[0] + iTemp198) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp199) + fSlow42 * ftbl0[std::max<int>(0, std::min<int>((iRec134[0] + iTemp202) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp203) + fSlow43 * ftbl0[std::max<int>(0, std::min<int>((iRec136[0] + iTemp206) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp207) + fSlow44 * ftbl0[std::max<int>(0, std::min<int>((iRec138[0] + iTemp210) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp211) + fSlow45 * ftbl0[std::max<int>(0, std::min<int>((iRec140[0] + iTemp214) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp215) + fSlow46 * ftbl0[std::max<int>(0, std::min<int>((iRec142[0] + iTemp218) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp219) + fSlow47 * ftbl0[std::max<int>(0, std::min<int>((iRec144[0] + iTemp222) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp223) + fSlow48 * ftbl0[std::max<int>(0, std::min<int>((iRec146[0] + iTemp226) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp227) + fSlow49 * ftbl0[std::max<int>(0, std::min<int>((iRec148[0] + iTemp230) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp231) + fSlow50 * ftbl0[std::max<int>(0, std::min<int>((iRec150[0] + iTemp234) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp235) + fSlow51 * ftbl0[std::max<int>(0, std::min<int>((iRec152[0] + iTemp238) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp239) + fSlow52 * ftbl0[std::max<int>(0, std::min<int>((iRec154[0] + iTemp242) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp243) + fSlow53 * ftbl0[std::max<int>(0, std::min<int>((iRec156[0] + iTemp246) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp247) + fSlow54 * ftbl0[std::max<int>(0, std::min<int>((iRec158[0] + iTemp250) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp251) + fSlow55 * ftbl0[std::max<int>(0, std::min<int>((iRec160[0] + iTemp254) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp255) + fSlow56 * ftbl0[std::max<int>(0, std::min<int>((iRec162[0] + iTemp258) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp259) + fSlow57 * ftbl0[std::max<int>(0, std::min<int>((iRec164[0] + iTemp262) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp263) + fSlow58 * ftbl0[std::max<int>(0, std::min<int>((iRec166[0] + iTemp266) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp267) + fSlow59 * ftbl0[std::max<int>(0, std::min<int>((iRec168[0] + iTemp270) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp271) + fSlow60 * ftbl0[std::max<int>(0, std::min<int>((iRec170[0] + iTemp274) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp275) + fSlow61 * ftbl0[std::max<int>(0, std::min<int>((iRec172[0] + iTemp278) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp279) + fSlow62 * ftbl0[std::max<int>(0, std::min<int>((iRec174[0] + iTemp282) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp283) + fSlow63 * ftbl0[std::max<int>(0, std::min<int>((iRec176[0] + iTemp286) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp287) + fSlow64 * ftbl0[std::max<int>(0, std::min<int>((iRec178[0] + iTemp290) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp291) + fSlow65 * ftbl0[std::max<int>(0, std::min<int>((iRec180[0] + iTemp294) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp295) + fSlow66 * ftbl0[std::max<int>(0, std::min<int>((iRec182[0] + iTemp298) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp299) + fSlow67 * ftbl0[std::max<int>(0, std::min<int>((iRec184[0] + iTemp302) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp303) + fSlow68 * ftbl0[std::max<int>(0, std::min<int>((iRec186[0] + iTemp306) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp307) + fSlow69 * ftbl0[std::max<int>(0, std::min<int>((iRec188[0] + iTemp310) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp311) + fSlow70 * ftbl0[std::max<int>(0, std::min<int>((iRec190[0] + iTemp314) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp315) + fSlow71 * ftbl0[std::max<int>(0, std::min<int>((iRec192[0] + iTemp318) % iSlow3, 479999))] * std::sin(fSlow8 * fTemp319)));
			iVec0[1] = iVec0[0];
			iRec0[1] = iRec0[0];
			iRec3[1] = iRec3[0];
			iRec2[1] = iRec2[0];
			iRec67[1] = iRec67[0];
			iRec1[1] = iRec1[0];
			iRec69[1] = iRec69[0];
			iRec68[1] = iRec68[0];
			iRec71[1] = iRec71[0];
			iRec70[1] = iRec70[0];
			iRec73[1] = iRec73[0];
			iRec72[1] = iRec72[0];
			iRec75[1] = iRec75[0];
			iRec74[1] = iRec74[0];
			iRec77[1] = iRec77[0];
			iRec76[1] = iRec76[0];
			iRec79[1] = iRec79[0];
			iRec78[1] = iRec78[0];
			iRec81[1] = iRec81[0];
			iRec80[1] = iRec80[0];
			iRec83[1] = iRec83[0];
			iRec82[1] = iRec82[0];
			iRec85[1] = iRec85[0];
			iRec84[1] = iRec84[0];
			iRec87[1] = iRec87[0];
			iRec86[1] = iRec86[0];
			iRec89[1] = iRec89[0];
			iRec88[1] = iRec88[0];
			iRec91[1] = iRec91[0];
			iRec90[1] = iRec90[0];
			iRec93[1] = iRec93[0];
			iRec92[1] = iRec92[0];
			iRec95[1] = iRec95[0];
			iRec94[1] = iRec94[0];
			iRec97[1] = iRec97[0];
			iRec96[1] = iRec96[0];
			iRec99[1] = iRec99[0];
			iRec98[1] = iRec98[0];
			iRec101[1] = iRec101[0];
			iRec100[1] = iRec100[0];
			iRec103[1] = iRec103[0];
			iRec102[1] = iRec102[0];
			iRec105[1] = iRec105[0];
			iRec104[1] = iRec104[0];
			iRec107[1] = iRec107[0];
			iRec106[1] = iRec106[0];
			iRec109[1] = iRec109[0];
			iRec108[1] = iRec108[0];
			iRec111[1] = iRec111[0];
			iRec110[1] = iRec110[0];
			iRec113[1] = iRec113[0];
			iRec112[1] = iRec112[0];
			iRec115[1] = iRec115[0];
			iRec114[1] = iRec114[0];
			iRec117[1] = iRec117[0];
			iRec116[1] = iRec116[0];
			iRec119[1] = iRec119[0];
			iRec118[1] = iRec118[0];
			iRec121[1] = iRec121[0];
			iRec120[1] = iRec120[0];
			iRec123[1] = iRec123[0];
			iRec122[1] = iRec122[0];
			iRec125[1] = iRec125[0];
			iRec124[1] = iRec124[0];
			iRec127[1] = iRec127[0];
			iRec126[1] = iRec126[0];
			iRec128[1] = iRec128[0];
			iRec129[1] = iRec129[0];
			iRec131[1] = iRec131[0];
			iRec130[1] = iRec130[0];
			iRec133[1] = iRec133[0];
			iRec132[1] = iRec132[0];
			iRec135[1] = iRec135[0];
			iRec134[1] = iRec134[0];
			iRec137[1] = iRec137[0];
			iRec136[1] = iRec136[0];
			iRec139[1] = iRec139[0];
			iRec138[1] = iRec138[0];
			iRec141[1] = iRec141[0];
			iRec140[1] = iRec140[0];
			iRec143[1] = iRec143[0];
			iRec142[1] = iRec142[0];
			iRec145[1] = iRec145[0];
			iRec144[1] = iRec144[0];
			iRec147[1] = iRec147[0];
			iRec146[1] = iRec146[0];
			iRec149[1] = iRec149[0];
			iRec148[1] = iRec148[0];
			iRec151[1] = iRec151[0];
			iRec150[1] = iRec150[0];
			iRec153[1] = iRec153[0];
			iRec152[1] = iRec152[0];
			iRec155[1] = iRec155[0];
			iRec154[1] = iRec154[0];
			iRec157[1] = iRec157[0];
			iRec156[1] = iRec156[0];
			iRec159[1] = iRec159[0];
			iRec158[1] = iRec158[0];
			iRec161[1] = iRec161[0];
			iRec160[1] = iRec160[0];
			iRec163[1] = iRec163[0];
			iRec162[1] = iRec162[0];
			iRec165[1] = iRec165[0];
			iRec164[1] = iRec164[0];
			iRec167[1] = iRec167[0];
			iRec166[1] = iRec166[0];
			iRec169[1] = iRec169[0];
			iRec168[1] = iRec168[0];
			iRec171[1] = iRec171[0];
			iRec170[1] = iRec170[0];
			iRec173[1] = iRec173[0];
			iRec172[1] = iRec172[0];
			iRec175[1] = iRec175[0];
			iRec174[1] = iRec174[0];
			iRec177[1] = iRec177[0];
			iRec176[1] = iRec176[0];
			iRec179[1] = iRec179[0];
			iRec178[1] = iRec178[0];
			iRec181[1] = iRec181[0];
			iRec180[1] = iRec180[0];
			iRec183[1] = iRec183[0];
			iRec182[1] = iRec182[0];
			iRec185[1] = iRec185[0];
			iRec184[1] = iRec184[0];
			iRec187[1] = iRec187[0];
			iRec186[1] = iRec186[0];
			iRec189[1] = iRec189[0];
			iRec188[1] = iRec188[0];
			iRec191[1] = iRec191[0];
			iRec190[1] = iRec190[0];
			iRec193[1] = iRec193[0];
			iRec192[1] = iRec192[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "g.dsp"
	#define FAUST_CLASS_NAME "_g"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _g -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 1
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 3
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("delay length", fHslider1, 1e+01f, 0.5f, 1e+01f, 0.1f);
	FAUST_ADDHORIZONTALSLIDER("grain density", fHslider0, 1.0f, 1.0f, 64.0f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("grain length", fHslider2, 0.1f, 0.01f, 0.5f, 0.01f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, delay_length, "delay length", fHslider1, 1e+01f, 0.5f, 1e+01f, 0.1f) \
		p(HORIZONTALSLIDER, grain_density, "grain density", fHslider0, 1.0f, 1.0f, 64.0f, 1.0f) \
		p(HORIZONTALSLIDER, grain_length, "grain length", fHslider2, 0.1f, 0.01f, 0.5f, 0.01f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
