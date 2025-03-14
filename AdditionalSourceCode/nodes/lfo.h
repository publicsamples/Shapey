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
using tempo_sync_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<converter_t<NV>, 0>, 
                                        parameter::plain<fx::sampleandhold<NV>, 0>>;

template <int NV>
using tempo_sync_t = wrap::mod<tempo_sync_mod<NV>, 
                               control::tempo_sync<NV>>;

template <int NV>
using no_midi_t_ = container::chain<parameter::empty, 
                                    wrap::fix<1, oscillator1_t<NV>>>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;

using sb1_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, core::empty>>;

using sb1_t = bypass::smoothed<20, sb1_t_>;
using switcher_c0 = parameter::bypass<sb1_t>;

template <int NV>
using sb2_t_ = container::chain<parameter::empty, 
                                wrap::fix<1, fx::sampleandhold<NV>>>;

template <int NV>
using sb2_t = bypass::smoothed<20, sb2_t_<NV>>;
template <int NV>
using switcher_c1 = parameter::bypass<sb2_t<NV>>;

template <int NV>
using switcher_multimod = parameter::list<switcher_c0, switcher_c1<NV>>;

template <int NV>
using switcher_t = control::xfader<switcher_multimod<NV>, faders::switcher>;

struct cable_table_t_data
{
	span<float, 512> data =
	{
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.0159351f, 0.0338271f, 0.0517191f, 0.0696111f, 0.0875037f, 0.105396f,
		0.123288f, 0.14118f, 0.159072f, 0.176964f, 0.194856f, 0.212748f,
		0.23064f, 0.248532f, 0.266424f, 0.284316f, 0.302208f, 0.320101f,
		0.337993f, 0.355885f, 0.373777f, 0.391669f, 0.409561f, 0.427453f,
		0.445345f, 0.463237f, 0.481129f, 0.499021f, 0.516914f, 0.534806f,
		0.552698f, 0.57059f, 0.588482f, 0.606374f, 0.624266f, 0.642158f,
		0.660051f, 0.677943f, 0.695835f, 0.713727f, 0.731619f, 0.749511f,
		0.767403f, 0.785295f, 0.803187f, 0.821079f, 0.838971f, 0.856863f,
		0.874755f, 0.892647f, 0.910539f, 0.928431f, 0.946324f, 0.964216f,
		0.982108f, 1.f
	};
};

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<switcher_t<NV>, 0>>, 
                                 data::embedded::table<cable_table_t_data>>;

template <int NV>
using sb_container_t = container::chain<parameter::empty, 
                                        wrap::fix<1, sb1_t>, 
                                        sb2_t<NV>>;

template <int NV>
using softbypass_switch3_t = container::chain<parameter::empty, 
                                              wrap::fix<1, switcher_t<NV>>, 
                                              sb_container_t<NV>>;

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

DECLARE_PARAMETER_RANGE_STEP(mode_InputRange, 
                             0., 
                             4., 
                             0.1);
DECLARE_PARAMETER_RANGE_STEP(mode_1Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using mode_1 = parameter::from0To1<lfo_impl::oscillator1_t<NV>, 
                                   0, 
                                   mode_1Range>;

template <int NV>
using mode = parameter::chain<mode_InputRange, 
                              parameter::plain<lfo_impl::cable_table_t<NV>, 0>, 
                              mode_1<NV>>;

template <int NV>
using tempo = parameter::plain<lfo_impl::tempo_sync_t<NV>, 
                               0>;
template <int NV>
using div = parameter::plain<lfo_impl::tempo_sync_t<NV>, 
                             1>;
using Dest = parameter::plain<lfo_impl::branch_t, 0>;
template <int NV>
using lfo_t_plist = parameter::list<tempo<NV>, 
                                    div<NV>, 
                                    mode<NV>, 
                                    Dest>;
}

template <int NV>
using lfo_t_ = container::chain<lfo_t_parameters::lfo_t_plist<NV>, 
                                wrap::fix<1, tempo_sync_t<NV>>, 
                                converter_t<NV>, 
                                no_midi_t<NV>, 
                                math::sig2mod<NV>, 
                                cable_table_t<NV>, 
                                softbypass_switch3_t<NV>, 
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
		SNEX_METADATA_ENCODED_PARAMETERS(62)
		{
			0x005B, 0x0000, 0x7400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0001, 0x0000, 0x6964, 0x0076, 0x0000, 0x3F80, 0x0000, 0x4180, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x025B, 0x0000, 
            0x6D00, 0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 0x4080, 0x0000, 
            0x4080, 0x0000, 0x3F80, 0xCCCD, 0x3DCC, 0x035B, 0x0000, 0x4400, 
            0x7365, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& tempo_sync = this->getT(0);                            // lfo_impl::tempo_sync_t<NV>
		auto& converter = this->getT(1);                             // lfo_impl::converter_t<NV>
		auto& no_midi = this->getT(2);                               // lfo_impl::no_midi_t<NV>
		auto& oscillator1 = this->getT(2).getT(0);                   // lfo_impl::oscillator1_t<NV>
		auto& sig2mod = this->getT(3);                               // math::sig2mod<NV>
		auto& cable_table = this->getT(4);                           // lfo_impl::cable_table_t<NV>
		auto& softbypass_switch3 = this->getT(5);                    // lfo_impl::softbypass_switch3_t<NV>
		auto& switcher = this->getT(5).getT(0);                      // lfo_impl::switcher_t<NV>
		auto& sb_container = this->getT(5).getT(1);                  // lfo_impl::sb_container_t<NV>
		auto& sb1 = this->getT(5).getT(1).getT(0);                   // lfo_impl::sb1_t
		auto& sb2 = this->getT(5).getT(1).getT(1);                   // lfo_impl::sb2_t<NV>
		auto& sampleandhold = this->getT(5).getT(1).getT(1).getT(0); // fx::sampleandhold<NV>
		auto& branch = this->getT(6);                                // lfo_impl::branch_t
		auto& chain = this->getT(6).getT(0);                         // lfo_impl::chain_t
		auto& peak1 = this->getT(6).getT(0).getT(0);                 // lfo_impl::peak1_t
		auto& global_cable = this->getT(6).getT(0).getT(1);          // routing::global_cable<global_cable_t_index, parameter::empty>
		auto& chain1 = this->getT(6).getT(1);                        // lfo_impl::chain1_t
		auto& peak2 = this->getT(6).getT(1).getT(0);                 // lfo_impl::peak2_t
		auto& global_cable1 = this->getT(6).getT(1).getT(1);         // routing::global_cable<global_cable1_t_index, parameter::empty>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, tempo_sync); // tempo -> tempo_sync::Tempo
		
		this->getParameterT(1).connectT(0, tempo_sync); // div -> tempo_sync::Multiplier
		
		auto& mode_p = this->getParameterT(2);
		mode_p.connectT(0, cable_table); // mode -> cable_table::Value
		mode_p.connectT(1, oscillator1); // mode -> oscillator1::Mode
		
		this->getParameterT(3).connectT(0, branch); // Dest -> branch::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		converter.getWrappedObject().getParameter().connectT(0, oscillator1); // converter -> oscillator1::Frequency
		tempo_sync.getParameter().connectT(0, converter);                     // tempo_sync -> converter::Value
		tempo_sync.getParameter().connectT(1, sampleandhold);                 // tempo_sync -> sampleandhold::Counter
		auto& switcher_p = switcher.getWrappedObject().getParameter();
		switcher_p.getParameterT(0).connectT(0, sb1);                        // switcher -> sb1::Bypassed
		switcher_p.getParameterT(1).connectT(0, sb2);                        // switcher -> sb2::Bypassed
		cable_table.getWrappedObject().getParameter().connectT(0, switcher); // cable_table -> switcher::Value
		peak1.getParameter().connectT(0, global_cable);                      // peak1 -> global_cable::Value
		peak2.getParameter().connectT(0, global_cable1);                     // peak2 -> global_cable1::Value
		
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
		
		; // cable_table::Value is automated
		
		; // switcher::Value is automated
		
		; // sampleandhold::Counter is automated
		
		; // branch::Index is automated
		
		; // global_cable::Value is automated
		
		; // global_cable1::Value is automated
		
		this->setParameterT(0, 3.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 4.);
		this->setParameterT(3, 1.);
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
		
		this->getT(6).getT(0).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable_t_index, parameter::empty>
		this->getT(6).getT(1).getT(1).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable1_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(2).getT(0).setExternalData(b, index);         // lfo_impl::oscillator1_t<NV>
		this->getT(4).setExternalData(b, index);                 // lfo_impl::cable_table_t<NV>
		this->getT(6).getT(0).getT(0).setExternalData(b, index); // lfo_impl::peak1_t
		this->getT(6).getT(1).getT(0).setExternalData(b, index); // lfo_impl::peak2_t
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


