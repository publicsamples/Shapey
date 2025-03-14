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

namespace table_impl
{
// ==============================| Node & Parameter type declarations |==============================

using global_cable_t_index = runtime_target::indexers::fix_hash<-1797510589>;
using global_cable1_t_index = runtime_target::indexers::fix_hash<-1797510588>;

template <int NV>
using cable_table_mod = parameter::chain<ranges::Identity, 
                                         parameter::plain<wrap::no_process<math::add<NV>>, 0>, 
                                         parameter::plain<routing::global_cable<global_cable_t_index, parameter::empty>, 0>, 
                                         parameter::plain<routing::global_cable<global_cable1_t_index, parameter::empty>, 0>>;

template <int NV>
using cable_table_t = wrap::data<control::cable_table<cable_table_mod<NV>>, 
                                 data::external::table<0>>;
template <int NV>
using ramp_t = wrap::mod<parameter::plain<cable_table_t<NV>, 0>, 
                         wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using input_toggle1_t = control::input_toggle<parameter::plain<ramp_t<NV>, 2>>;
template <int NV>
using resetter_t = control::resetter<parameter::plain<input_toggle1_t<NV>, 2>>;
template <int NV>
using ahdsr_multimod = parameter::list<parameter::empty, 
                                       parameter::plain<resetter_t<NV>, 0>>;

template <int NV>
using ahdsr_t = wrap::no_data<envelope::ahdsr<NV, ahdsr_multimod<NV>>>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, ahdsr_t<NV>>, 
                                      resetter_t<NV>, 
                                      input_toggle1_t<NV>, 
                                      ramp_t<NV>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;

using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, core::empty>>;

using split_t = container::split<parameter::empty, wrap::fix<1, chain_t>>;

template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync<NV>>;
using peak1_t = wrap::no_data<core::peak>;

using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, peak1_t>, 
                                  routing::global_cable<global_cable_t_index, parameter::empty>>;
using peak2_t = peak1_t;

using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, peak2_t>, 
                                  routing::global_cable<global_cable1_t_index, parameter::empty>>;
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain1_t>, 
                                   chain2_t>;

namespace table_t_parameters
{
// Parameter list for table_impl::table_t ----------------------------------------------------------

DECLARE_PARAMETER_RANGE(div_InputRange, 
                        1., 
                        16.);
DECLARE_PARAMETER_RANGE_STEP(div_0Range, 
                             1., 
                             16., 
                             1.);

template <int NV>
using div_0 = parameter::from0To1<table_impl::tempo_sync_t<NV>, 
                                  1, 
                                  div_0Range>;

template <int NV>
using div = parameter::chain<div_InputRange, div_0<NV>>;

template <int NV>
using tempo = parameter::plain<table_impl::tempo_sync_t<NV>, 
                               0>;
template <int NV>
using trig = parameter::plain<table_impl::input_toggle1_t<NV>, 
                              0>;
template <int NV>
using once = parameter::plain<table_impl::ramp_t<NV>, 1>;
using Out = parameter::plain<table_impl::branch_t, 0>;
template <int NV>
using table_t_plist = parameter::list<tempo<NV>, 
                                      div<NV>, 
                                      trig<NV>, 
                                      once<NV>, 
                                      Out>;
}

template <int NV>
using table_t_ = container::chain<table_t_parameters::table_t_plist<NV>, 
                                  wrap::fix<1, midichain_t<NV>>, 
                                  split_t, 
                                  tempo_sync_t<NV>, 
                                  math::clear<NV>, 
                                  cable_table_t<NV>, 
                                  wrap::no_process<math::add<NV>>, 
                                  branch_t>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public table_impl::table_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 1;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(table);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(76)
		{
			0x005B, 0x0000, 0x7400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0001, 0x0000, 0x6964, 0x0076, 0x0000, 0x3F80, 0x0000, 0x4180, 
            0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 0x0000, 
            0x7400, 0x6972, 0x0067, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x035B, 0x0000, 0x6F00, 
            0x636E, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 0x0000, 0x4F00, 0x7475, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& midichain = this->getT(0);                     // table_impl::midichain_t<NV>
		auto& ahdsr = this->getT(0).getT(0);                 // table_impl::ahdsr_t<NV>
		auto& resetter = this->getT(0).getT(1);              // table_impl::resetter_t<NV>
		auto& input_toggle1 = this->getT(0).getT(2);         // table_impl::input_toggle1_t<NV>
		auto& ramp = this->getT(0).getT(3);                  // table_impl::ramp_t<NV>
		auto& split = this->getT(1);                         // table_impl::split_t
		auto& chain = this->getT(1).getT(0);                 // table_impl::chain_t
		auto& tempo_sync = this->getT(2);                    // table_impl::tempo_sync_t<NV>
		auto& clear = this->getT(3);                         // math::clear<NV>
		auto& cable_table = this->getT(4);                   // table_impl::cable_table_t<NV>
		auto& add = this->getT(5);                           // wrap::no_process<math::add<NV>>
		auto& branch = this->getT(6);                        // table_impl::branch_t
		auto& chain1 = this->getT(6).getT(0);                // table_impl::chain1_t
		auto& peak1 = this->getT(6).getT(0).getT(0);         // table_impl::peak1_t
		auto& global_cable = this->getT(6).getT(0).getT(1);  // routing::global_cable<global_cable_t_index, parameter::empty>
		auto& chain2 = this->getT(6).getT(1);                // table_impl::chain2_t
		auto& peak2 = this->getT(6).getT(1).getT(0);         // table_impl::peak2_t
		auto& global_cable1 = this->getT(6).getT(1).getT(1); // routing::global_cable<global_cable1_t_index, parameter::empty>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, tempo_sync); // tempo -> tempo_sync::Tempo
		
		this->getParameterT(1).connectT(0, tempo_sync); // div -> tempo_sync::Multiplier
		
		this->getParameterT(2).connectT(0, input_toggle1); // trig -> input_toggle1::Input
		
		this->getParameterT(3).connectT(0, ramp); // once -> ramp::LoopStart
		
		this->getParameterT(4).connectT(0, branch); // Out -> branch::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		cable_table.getWrappedObject().getParameter().connectT(0, add);           // cable_table -> add::Value
		cable_table.getWrappedObject().getParameter().connectT(1, global_cable);  // cable_table -> global_cable::Value
		cable_table.getWrappedObject().getParameter().connectT(2, global_cable1); // cable_table -> global_cable1::Value
		ramp.getParameter().connectT(0, cable_table);                             // ramp -> cable_table::Value
		input_toggle1.getWrappedObject().getParameter().connectT(0, ramp);        // input_toggle1 -> ramp::Gate
		resetter.getWrappedObject().getParameter().connectT(0, input_toggle1);    // resetter -> input_toggle1::Value2
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(1).connectT(0, resetter); // ahdsr -> resetter::Value
		tempo_sync.getParameter().connectT(0, ramp);    // tempo_sync -> ramp::PeriodTime
		
		// Default Values --------------------------------------------------------------------------
		
		ahdsr.setParameterT(0, 10.);  // envelope::ahdsr::Attack
		ahdsr.setParameterT(1, 1.);   // envelope::ahdsr::AttackLevel
		ahdsr.setParameterT(2, 20.);  // envelope::ahdsr::Hold
		ahdsr.setParameterT(3, 300.); // envelope::ahdsr::Decay
		ahdsr.setParameterT(4, 0.5);  // envelope::ahdsr::Sustain
		ahdsr.setParameterT(5, 20.);  // envelope::ahdsr::Release
		ahdsr.setParameterT(6, 0.5);  // envelope::ahdsr::AttackCurve
		ahdsr.setParameterT(7, 0.);   // envelope::ahdsr::Retrigger
		ahdsr.setParameterT(8, 0.);   // envelope::ahdsr::Gate
		
		; // resetter::Value is automated
		
		;                                   // input_toggle1::Input is automated
		input_toggle1.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                   // input_toggle1::Value2 is automated
		
		; // ramp::PeriodTime is automated
		; // ramp::LoopStart is automated
		; // ramp::Gate is automated
		
		;                                  // tempo_sync::Tempo is automated
		;                                  // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table::Value is automated
		
		; // add::Value is automated
		
		; // branch::Index is automated
		
		; // global_cable::Value is automated
		
		; // global_cable1::Value is automated
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 2.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
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
		
		this->getT(0).getT(0).setExternalData(b, index);         // table_impl::ahdsr_t<NV>
		this->getT(0).getT(3).setExternalData(b, index);         // table_impl::ramp_t<NV>
		this->getT(4).setExternalData(b, index);                 // table_impl::cable_table_t<NV>
		this->getT(6).getT(0).getT(0).setExternalData(b, index); // table_impl::peak1_t
		this->getT(6).getT(1).getT(0).setExternalData(b, index); // table_impl::peak2_t
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
using table = wrap::node<table_impl::instance<NV>>;
}


