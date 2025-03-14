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
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(dry_wet_mixer_c1Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using dry_wet_mixer_c1 = parameter::from0To1<core::gain<NV>, 
                                             0, 
                                             dry_wet_mixer_c1Range>;

template <int NV>
using dry_wet_mixer_multimod = parameter::list<parameter::empty, dry_wet_mixer_c1<NV>>;

template <int NV>
using dry_wet_mixer_t = control::xfader<dry_wet_mixer_multimod<NV>, 
                                        faders::linear>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>>;

using convolution_t = wrap::data<filters::convolution, 
                                 data::external::audiofile<0>>;
template <int NV>
using tempo_sync1_t = wrap::mod<parameter::plain<convolution_t, 1>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, tempo_sync1_t<NV>>, 
                                  convolution_t, 
                                  filters::one_pole<NV>, 
                                  filters::one_pole<NV>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain1_t<NV>>, 
                                 chain2_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, dry_wet_mixer_t<NV>>, 
                                 split_t<NV>>;

namespace verb_t_parameters
{
// Parameter list for verb_impl::verb_t ------------------------------------------------------------

template <int NV>
using master = parameter::plain<core::gain<NV>, 0>;
template <int NV>
using wet = parameter::plain<verb_impl::dry_wet_mixer_t<NV>, 
                             0>;
template <int NV>
using pro = parameter::plain<verb_impl::tempo_sync1_t<NV>, 
                             0>;
template <int NV>
using damp = parameter::plain<filters::one_pole<NV>, 0>;
template <int NV> using hi = damp<NV>;
template <int NV>
using verb_t_plist = parameter::list<master<NV>, 
                                     wet<NV>, 
                                     pro<NV>, 
                                     damp<NV>, 
                                     hi<NV>>;
}

template <int NV>
using verb_t_ = container::chain<verb_t_parameters::verb_t_plist<NV>, 
                                 wrap::fix<2, chain_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public verb_impl::verb_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 1;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(verb);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(76)
		{
			0x005B, 0x0000, 0x6D00, 0x7361, 0x6574, 0x0072, 0x0000, 0xC2C8, 
            0x0000, 0x0000, 0x6666, 0xC1AE, 0x833E, 0x40AD, 0xCCCD, 0x3DCC, 
            0x015B, 0x0000, 0x7700, 0x7465, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0002, 
            0x0000, 0x7270, 0x006F, 0x0000, 0x0000, 0x0000, 0x4190, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x035B, 0x0000, 0x6400, 
            0x6D61, 0x0070, 0x0000, 0x41A0, 0x4000, 0x469C, 0x1800, 0x4619, 
            0x6C1A, 0x3E6B, 0x0000, 0x0000, 0x045B, 0x0000, 0x6800, 0x0069, 
            0x0000, 0x41A0, 0x4000, 0x469C, 0x0000, 0x4355, 0x6C1A, 0x3E6B, 
            0x0000, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain = this->getT(0);                               // verb_impl::chain_t<NV>
		auto& dry_wet_mixer = this->getT(0).getT(0);               // verb_impl::dry_wet_mixer_t<NV>
		auto& split = this->getT(0).getT(1);                       // verb_impl::split_t<NV>
		auto& chain1 = this->getT(0).getT(1).getT(0);              // verb_impl::chain1_t<NV>
		auto& dry_gain = this->getT(0).getT(1).getT(0).getT(0);    // core::gain<NV>
		auto& chain2 = this->getT(0).getT(1).getT(1);              // verb_impl::chain2_t<NV>
		auto& tempo_sync1 = this->getT(0).getT(1).getT(1).getT(0); // verb_impl::tempo_sync1_t<NV>
		auto& convolution = this->getT(0).getT(1).getT(1).getT(1); // verb_impl::convolution_t
		auto& one_pole = this->getT(0).getT(1).getT(1).getT(2);    // filters::one_pole<NV>
		auto& one_pole1 = this->getT(0).getT(1).getT(1).getT(3);   // filters::one_pole<NV>
		auto& wet_gain = this->getT(0).getT(1).getT(1).getT(4);    // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, dry_gain); // master -> dry_gain::Gain
		
		this->getParameterT(1).connectT(0, dry_wet_mixer); // wet -> dry_wet_mixer::Value
		
		this->getParameterT(2).connectT(0, tempo_sync1); // pro -> tempo_sync1::Tempo
		
		this->getParameterT(3).connectT(0, one_pole); // damp -> one_pole::Frequency
		
		this->getParameterT(4).connectT(0, one_pole1); // hi -> one_pole1::Frequency
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& dry_wet_mixer_p = dry_wet_mixer.getWrappedObject().getParameter();
		dry_wet_mixer_p.getParameterT(1).connectT(0, wet_gain); // dry_wet_mixer -> wet_gain::Gain
		tempo_sync1.getParameter().connectT(0, convolution);    // tempo_sync1 -> convolution::Predelay
		
		// Default Values --------------------------------------------------------------------------
		
		; // dry_wet_mixer::Value is automated
		
		;                               // dry_gain::Gain is automated
		dry_gain.setParameterT(1, 20.); // core::gain::Smoothing
		dry_gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                   // tempo_sync1::Tempo is automated
		tempo_sync1.setParameterT(1, 8.);   // control::tempo_sync::Multiplier
		tempo_sync1.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync1.setParameterT(3, 18.4); // control::tempo_sync::UnsyncedTime
		
		convolution.setParameterT(0, 1.);     // filters::convolution::Gate
		;                                     // convolution::Predelay is automated
		convolution.setParameterT(2, 0.);     // filters::convolution::Damping
		convolution.setParameterT(3, 20000.); // filters::convolution::HiCut
		convolution.setParameterT(4, 1.);     // filters::convolution::Multithread
		
		;                                // one_pole::Frequency is automated
		one_pole.setParameterT(1, 0.3);  // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                 // one_pole1::Frequency is automated
		one_pole1.setParameterT(1, 0.3);  // filters::one_pole::Q
		one_pole1.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 1.);   // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                               // wet_gain::Gain is automated
		wet_gain.setParameterT(1, 20.); // core::gain::Smoothing
		wet_gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, -21.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 9798.);
		this->setParameterT(4, 213.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(1).getT(1).getT(1).setExternalData(b, index); // verb_impl::convolution_t
	}
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// ======================================| Public Definition |======================================

namespace project
{
// polyphonic template declaration

template <int NV>
using verb = wrap::node<verb_impl::instance<NV>>;
}


