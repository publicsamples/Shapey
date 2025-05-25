#pragma once

// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace verb_impl
{
// ====================| Node & Parameter type declarations |====================

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader_c0 = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      xfader_c0Range>;

template <int NV> using xfader_c1 = xfader_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::overlap>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, core::gain<NV>>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, project::hole<NV>>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain_t<NV>>, 
                                 chain1_t<NV>>;

namespace verb_t_parameters
{
// Parameter list for verb_impl::verb_t -----------------------------------------

DECLARE_PARAMETER_RANGE_STEP(size_InputRange, 
                             0.1, 
                             60., 
                             0.1);
DECLARE_PARAMETER_RANGE_STEP(size_0Range, 
                             0.1, 
                             60., 
                             0.1);

template <int NV>
using size_0 = parameter::from0To1<project::hole<NV>, 
                                   2, 
                                   size_0Range>;

DECLARE_PARAMETER_RANGE(size_1Range, 
                        0.5, 
                        3.);

template <int NV>
using size_1 = parameter::from0To1<project::hole<NV>, 
                                   0, 
                                   size_1Range>;

template <int NV>
using size = parameter::chain<size_InputRange, 
                              size_0<NV>, 
                              size_1<NV>>;

template <int NV>
using mix = parameter::plain<verb_impl::xfader_t<NV>, 
                             0>;
template <int NV>
using diff = parameter::plain<project::hole<NV>, 1>;
template <int NV>
using Damp = parameter::plain<project::hole<NV>, 3>;
template <int NV>
using Low = parameter::plain<project::hole<NV>, 4>;
template <int NV>
using MidX = parameter::plain<project::hole<NV>, 5>;
template <int NV>
using HighX = parameter::plain<project::hole<NV>, 6>;
template <int NV>
using LowBand = parameter::plain<project::hole<NV>, 7>;
template <int NV>
using HighBand = parameter::plain<project::hole<NV>, 8>;
template <int NV>
using Mod = parameter::plain<project::hole<NV>, 9>;
template <int NV>
using ModRate = parameter::plain<project::hole<NV>, 10>;
template <int NV>
using verb_t_plist = parameter::list<mix<NV>, 
                                     size<NV>, 
                                     diff<NV>, 
                                     Damp<NV>, 
                                     Low<NV>, 
                                     MidX<NV>, 
                                     HighX<NV>, 
                                     LowBand<NV>, 
                                     HighBand<NV>, 
                                     Mod<NV>, 
                                     ModRate<NV>>;
}

template <int NV>
using verb_t_ = container::chain<verb_t_parameters::verb_t_plist<NV>, 
                                 wrap::fix<2, xfader_t<NV>>, 
                                 split_t<NV>>;

// ========================| Root node initialiser class |========================

template <int NV> struct instance: public verb_impl::verb_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(verb);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(170)
		{
			0x005B, 0x0000, 0x6D00, 0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x163F, 0x25B2, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0001, 
            0x0000, 0x6973, 0x657A, 0xCD00, 0xCCCC, 0x003D, 0x7000, 0x9A42, 
            0x9999, 0x003E, 0x8000, 0xCD3F, 0xCCCC, 0x5B3D, 0x0002, 0x0000, 
            0x6964, 0x6666, 0x0000, 0x0000, 0xA400, 0x7D70, 0xD63F, 0xE978, 
            0x003D, 0x8000, 0x6F3F, 0x8312, 0x5B3A, 0x0003, 0x0000, 0x6144, 
            0x706D, 0x0000, 0x0000, 0x7700, 0x7FBE, 0xDD3F, 0x8793, 0x003E, 
            0x8000, 0x173F, 0xD1B7, 0x5B38, 0x0004, 0x0000, 0x6F4C, 0x0077, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x5C29, 0x3F4F, 0x0000, 0x3F80, 
            0xD70A, 0x3C23, 0x055B, 0x0000, 0x4D00, 0x6469, 0x0058, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0A3D, 0x3F57, 0x0000, 0x3F80, 0xD70A, 
            0x3C23, 0x065B, 0x0000, 0x4800, 0x6769, 0x5868, 0x0000, 0x0000, 
            0x0000, 0x8000, 0xF53F, 0xDC28, 0x003E, 0x8000, 0x0A3F, 0x23D7, 
            0x5B3C, 0x0007, 0x0000, 0x6F4C, 0x4277, 0x6E61, 0x0064, 0x0000, 
            0x42C8, 0x8000, 0x45BB, 0x5A67, 0x4592, 0x0000, 0x3F80, 0xCCCD, 
            0x3DCC, 0x085B, 0x0000, 0x4800, 0x6769, 0x4268, 0x6E61, 0x0064, 
            0x0000, 0x447A, 0x4000, 0x461C, 0x9733, 0x45EF, 0x0000, 0x3F80, 
            0xCCCD, 0x3DCC, 0x095B, 0x0000, 0x4D00, 0x646F, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x8A3F, 0x2041, 0x003F, 0x8000, 0x6F3F, 0x8312, 
            0x5B3A, 0x000A, 0x0000, 0x6F4D, 0x5264, 0x7461, 0x0065, 0x0000, 
            0x0000, 0x0000, 0x4120, 0x9999, 0x3F19, 0x0000, 0x3F80, 0xD70A, 
            0x3C23, 0x0000
		};
	};
	
	instance()
	{
		// Node References ------------------------------------------------------
		
		auto& xfader = this->getT(0);                // verb_impl::xfader_t<NV>
		auto& split = this->getT(1);                 // verb_impl::split_t<NV>
		auto& chain = this->getT(1).getT(0);         // verb_impl::chain_t<NV>
		auto& gain = this->getT(1).getT(0).getT(0);  // core::gain<NV>
		auto& chain1 = this->getT(1).getT(1);        // verb_impl::chain1_t<NV>
		auto& faust = this->getT(1).getT(1).getT(0); // project::hole<NV>
		auto& gain1 = this->getT(1).getT(1).getT(1); // core::gain<NV>
		
		// Parameter Connections ------------------------------------------------
		
		this->getParameterT(0).connectT(0, xfader); // mix -> xfader::Value
		
		auto& size_p = this->getParameterT(1);
		size_p.connectT(0, faust); // size -> faust::t60
		size_p.connectT(1, faust); // size -> faust::size
		
		this->getParameterT(2).connectT(0, faust); // diff -> faust::earlyDiff
		
		this->getParameterT(3).connectT(0, faust); // Damp -> faust::damp
		
		this->getParameterT(4).connectT(0, faust); // Low -> faust::lowX
		
		this->getParameterT(5).connectT(0, faust); // MidX -> faust::midX
		
		this->getParameterT(6).connectT(0, faust); // HighX -> faust::highX
		
		this->getParameterT(7).connectT(0, faust); // LowBand -> faust::lowBand
		
		this->getParameterT(8).connectT(0, faust); // HighBand -> faust::highBand
		
		this->getParameterT(9).connectT(0, faust); // Mod -> faust::mDepth
		
		this->getParameterT(10).connectT(0, faust); // ModRate -> faust::mFreq
		
		// Modulation Connections -----------------------------------------------
		
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);  // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1); // xfader -> gain1::Gain
		
		// Default Values -------------------------------------------------------
		
		; // xfader::Value is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // faust::size is automated
		; // faust::earlyDiff is automated
		; // faust::t60 is automated
		; // faust::damp is automated
		; // faust::lowX is automated
		; // faust::midX is automated
		; // faust::highX is automated
		; // faust::lowBand is automated
		; // faust::highBand is automated
		; // faust::mDepth is automated
		; // faust::mFreq is automated
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.647249);
		this->setParameterT(1, 0.3);
		this->setParameterT(2, 0.114);
		this->setParameterT(3, 0.2648);
		this->setParameterT(4, 0.81);
		this->setParameterT(5, 0.84);
		this->setParameterT(6, 0.43);
		this->setParameterT(7, 4683.3);
		this->setParameterT(8, 7666.9);
		this->setParameterT(9, 0.626);
		this->setParameterT(10, 0.6);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// =============================| Public Definition |=============================

namespace project
{
// polyphonic template declaration

template <int NV>
using verb = wrap::node<verb_impl::instance<NV>>;
}


