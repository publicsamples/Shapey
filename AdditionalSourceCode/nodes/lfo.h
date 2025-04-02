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

namespace lfo_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using oscillator1_t = wrap::no_data<core::oscillator<NV>>;
template <int NV>
using converter_t = control::converter<parameter::plain<oscillator1_t<NV>, 1>, 
                                       conversion_logic::ms2freq>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<converter_t<NV>, 0>, 
                               control::tempo_sync<NV>>;

template <int NV>
using no_midi_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, oscillator1_t<NV>>>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;

using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, core::empty>>;

template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<math::add<NV>, 0>>;
template <int NV>
using peak_t = wrap::mod<parameter::plain<minmax_t<NV>, 0>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, peak_t<NV>>, 
                                  math::clear<NV>, 
                                  minmax_t<NV>, 
                                  math::add<NV>>;

template <int NV>
using tempo_sync2_t = wrap::mod<parameter::plain<fx::sampleandhold<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, tempo_sync2_t<NV>>, 
                                  fx::sampleandhold<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain2_t>, 
                                    chain4_t<NV>, 
                                    chain3_t<NV>>;

using global_cable_t_index = runtime_target::indexers::fix_hash<2333884>;
using peak1_mod = parameter::plain<routing::global_cable<global_cable_t_index, parameter::empty>, 
                                   0>;
using peak1_t = wrap::mod<peak1_mod, 
                          wrap::no_data<core::peak>>;

using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, peak1_t>, 
                                 routing::global_cable<global_cable_t_index, parameter::empty>>;

using global_cable1_t_index = runtime_target::indexers::fix_hash<2333885>;
using peak2_mod = parameter::plain<routing::global_cable<global_cable1_t_index, parameter::empty>, 
                                   0>;
using peak2_t = wrap::mod<peak2_mod, 
                          wrap::no_data<core::peak>>;

using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, peak2_t>, 
                                  routing::global_cable<global_cable1_t_index, parameter::empty>>;
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain_t>, 
                                   chain1_t>;

namespace lfo_t_parameters
{
// Parameter list for lfo_impl::lfo_t --------------------------------------------------------------

template <int NV>
using div = parameter::chain<ranges::Identity, 
                             parameter::plain<lfo_impl::tempo_sync_t<NV>, 1>, 
                             parameter::plain<lfo_impl::tempo_sync2_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(mode_InputRange, 
                             1., 
                             5., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(mode_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using mode_0 = parameter::from0To1<lfo_impl::oscillator1_t<NV>, 
                                   0, 
                                   mode_0Range>;

template <int NV>
using mode = parameter::chain<mode_InputRange, mode_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Adjst_0Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using Adjst_0 = parameter::from0To1<lfo_impl::tempo_sync2_t<NV>, 
                                    0, 
                                    Adjst_0Range>;

template <int NV>
using Adjst = parameter::chain<ranges::Identity, 
                               Adjst_0<NV>, 
                               parameter::plain<lfo_impl::minmax_t<NV>, 4>>;

DECLARE_PARAMETER_RANGE_STEP(AjustMode_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(AjustMode_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using AjustMode_0 = parameter::from0To1<lfo_impl::branch1_t<NV>, 
                                        0, 
                                        AjustMode_0Range>;

template <int NV>
using AjustMode = parameter::chain<AjustMode_InputRange, AjustMode_0<NV>>;

template <int NV>
using tempo = parameter::plain<lfo_impl::tempo_sync_t<NV>, 
                               0>;
using Dest = parameter::plain<lfo_impl::branch_t, 0>;
template <int NV>
using lfo_t_plist = parameter::list<tempo<NV>, 
                                    div<NV>, 
                                    mode<NV>, 
                                    Dest, 
                                    Adjst<NV>, 
                                    AjustMode<NV>>;
}

template <int NV>
using lfo_t_ = container::chain<lfo_t_parameters::lfo_t_plist<NV>, 
                                wrap::fix<1, tempo_sync_t<NV>>, 
                                converter_t<NV>, 
                                no_midi_t<NV>, 
                                math::sig2mod<NV>, 
                                branch1_t<NV>, 
                                branch_t>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public lfo_impl::lfo_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(lfo);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(94)
		{
			0x005B, 0x0000, 0x7400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0x0000, 0x0041, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0001, 0x0000, 0x6964, 0x0076, 0x0000, 0x3F80, 0x0000, 0x4180, 
            0x0000, 0x4140, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x025B, 0x0000, 
            0x6D00, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 0x40A0, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x035B, 0x0000, 0x4400, 
            0x7365, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x045B, 0x0000, 0x4100, 0x6A64, 
            0x7473, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0005, 0x0000, 0x6A41, 0x7375, 
            0x4D74, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 0x4040, 0x0000, 
            0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& tempo_sync = this->getT(0);                    // lfo_impl::tempo_sync_t<NV>
		auto& converter = this->getT(1);                     // lfo_impl::converter_t<NV>
		auto& no_midi = this->getT(2);                       // lfo_impl::no_midi_t<NV>
		auto& oscillator1 = this->getT(2).getT(0);           // lfo_impl::oscillator1_t<NV>
		auto& sig2mod = this->getT(3);                       // math::sig2mod<NV>
		auto& branch1 = this->getT(4);                       // lfo_impl::branch1_t<NV>
		auto& chain2 = this->getT(4).getT(0);                // lfo_impl::chain2_t
		auto& chain4 = this->getT(4).getT(1);                // lfo_impl::chain4_t<NV>
		auto& peak = this->getT(4).getT(1).getT(0);          // lfo_impl::peak_t<NV>
		auto& clear = this->getT(4).getT(1).getT(1);         // math::clear<NV>
		auto& minmax = this->getT(4).getT(1).getT(2);        // lfo_impl::minmax_t<NV>
		auto& add = this->getT(4).getT(1).getT(3);           // math::add<NV>
		auto& chain3 = this->getT(4).getT(2);                // lfo_impl::chain3_t<NV>
		auto& tempo_sync2 = this->getT(4).getT(2).getT(0);   // lfo_impl::tempo_sync2_t<NV>
		auto& sampleandhold = this->getT(4).getT(2).getT(1); // fx::sampleandhold<NV>
		auto& branch = this->getT(5);                        // lfo_impl::branch_t
		auto& chain = this->getT(5).getT(0);                 // lfo_impl::chain_t
		auto& peak1 = this->getT(5).getT(0).getT(0);         // lfo_impl::peak1_t
		auto& global_cable = this->getT(5).getT(0).getT(1);  // routing::global_cable<global_cable_t_index, parameter::empty>
		auto& chain1 = this->getT(5).getT(1);                // lfo_impl::chain1_t
		auto& peak2 = this->getT(5).getT(1).getT(0);         // lfo_impl::peak2_t
		auto& global_cable1 = this->getT(5).getT(1).getT(1); // routing::global_cable<global_cable1_t_index, parameter::empty>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, tempo_sync); // tempo -> tempo_sync::Tempo
		
		auto& div_p = this->getParameterT(1);
		div_p.connectT(0, tempo_sync);  // div -> tempo_sync::Multiplier
		div_p.connectT(1, tempo_sync2); // div -> tempo_sync2::Multiplier
		
		this->getParameterT(2).connectT(0, oscillator1); // mode -> oscillator1::Mode
		
		this->getParameterT(3).connectT(0, branch); // Dest -> branch::Index
		
		auto& Adjst_p = this->getParameterT(4);
		Adjst_p.connectT(0, tempo_sync2); // Adjst -> tempo_sync2::Tempo
		Adjst_p.connectT(1, minmax);      // Adjst -> minmax::Step
		
		this->getParameterT(5).connectT(0, branch1); // AjustMode -> branch1::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		converter.getWrappedObject().getParameter().connectT(0, oscillator1); // converter -> oscillator1::Frequency
		tempo_sync.getParameter().connectT(0, converter);                     // tempo_sync -> converter::Value
		minmax.getWrappedObject().getParameter().connectT(0, add);            // minmax -> add::Value
		peak.getParameter().connectT(0, minmax);                              // peak -> minmax::Value
		tempo_sync2.getParameter().connectT(0, sampleandhold);                // tempo_sync2 -> sampleandhold::Counter
		peak1.getParameter().connectT(0, global_cable);                       // peak1 -> global_cable::Value
		peak2.getParameter().connectT(0, global_cable1);                      // peak2 -> global_cable1::Value
		
		// Default Values --------------------------------------------------------------------------
		
		;                                  // tempo_sync::Tempo is automated
		;                                  // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // converter::Value is automated
		
		;                                 // oscillator1::Mode is automated
		;                                 // oscillator1::Frequency is automated
		oscillator1.setParameterT(2, 1.); // core::oscillator::FreqRatio
		oscillator1.setParameterT(3, 1.); // core::oscillator::Gate
		oscillator1.setParameterT(4, 0.); // core::oscillator::Phase
		oscillator1.setParameterT(5, 1.); // core::oscillator::Gain
		
		sig2mod.setParameterT(0, 0.); // math::sig2mod::Value
		
		; // branch1::Index is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		;                            // minmax::Value is automated
		minmax.setParameterT(1, 0.); // control::minmax::Minimum
		minmax.setParameterT(2, 1.); // control::minmax::Maximum
		minmax.setParameterT(3, 1.); // control::minmax::Skew
		;                            // minmax::Step is automated
		minmax.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add::Value is automated
		
		;                                   // tempo_sync2::Tempo is automated
		;                                   // tempo_sync2::Multiplier is automated
		tempo_sync2.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync2.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // sampleandhold::Counter is automated
		
		; // branch::Index is automated
		
		; // global_cable::Value is automated
		
		; // global_cable1::Value is automated
		
		this->setParameterT(0, 8.);
		this->setParameterT(1, 12.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 0.5);
		this->setParameterT(5, 3.);
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
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(5).getT(0).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable_t_index, parameter::empty>
		this->getT(5).getT(1).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable1_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(2).getT(0).setExternalData(b, index);         // lfo_impl::oscillator1_t<NV>
		this->getT(4).getT(1).getT(0).setExternalData(b, index); // lfo_impl::peak_t<NV>
		this->getT(5).getT(0).getT(0).setExternalData(b, index); // lfo_impl::peak1_t
		this->getT(5).getT(1).getT(0).setExternalData(b, index); // lfo_impl::peak2_t
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
using lfo = wrap::node<lfo_impl::instance<NV>>;
}


