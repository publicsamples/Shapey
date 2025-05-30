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

namespace NoteSelector_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::add<NV>>>;
using global_cable15_t_index = runtime_target::indexers::fix_hash<1752812596>;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   math::add<NV>>;
using global_cable1_t_index = runtime_target::indexers::fix_hash<1752812597>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable1_t<NV>>, 
                                  math::add<NV>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<1752812598>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable2_t<NV>>, 
                                  math::add<NV>>;
using global_cable6_t_index = runtime_target::indexers::fix_hash<1752812599>;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable6_t<NV>>, 
                                  math::add<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain20_t<NV>>, 
                                   chain14_t<NV>, 
                                   chain1_t<NV>, 
                                   chain2_t<NV>, 
                                   chain6_t<NV>>;

using peak_t = wrap::mod<parameter::plain<routing::public_mod, 0>, 
                         wrap::data<core::peak, data::external::displaybuffer<0>>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch_t<NV>>, 
                                   peak_t, 
                                   routing::public_mod>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain12_t<NV>>>;

namespace NoteSelector_t_parameters
{
DECLARE_PARAMETER_RANGE_STEP(NoteSrc_InputRange, 
                             1., 
                             8., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(NoteSrc_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using NoteSrc_0 = parameter::from0To1<NoteSelector_impl::branch_t<NV>, 
                                      0, 
                                      NoteSrc_0Range>;

template <int NV>
using NoteSrc = parameter::chain<NoteSrc_InputRange, NoteSrc_0<NV>>;

}

template <int NV>
using NoteSelector_t_ = container::chain<NoteSelector_t_parameters::NoteSrc<NV>, 
                                         wrap::fix<1, split2_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance:  public NoteSelector_impl::NoteSelector_t_<NV>,
                                    public routing::public_mod_target
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 1;
		
		SNEX_METADATA_ID(NoteSelector);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(18)
		{
			0x005B, 0x0000, 0x4E00, 0x746F, 0x5365, 0x6372, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0041, 0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& split2 = this->getT(0);                                         // NoteSelector_impl::split2_t<NV>
		auto& chain12 = this->getT(0).getT(0);                                // NoteSelector_impl::chain12_t<NV>
		auto& branch = this->getT(0).getT(0).getT(0);                         // NoteSelector_impl::branch_t<NV>
		auto& chain20 = this->getT(0).getT(0).getT(0).getT(0);                // NoteSelector_impl::chain20_t<NV>
		auto& add = this->getT(0).getT(0).getT(0).getT(0).getT(0);            // math::add<NV>
		auto& chain14 = this->getT(0).getT(0).getT(0).getT(1);                // NoteSelector_impl::chain14_t<NV>
		auto& global_cable15 = this->getT(0).getT(0).getT(0).getT(1).getT(0); // NoteSelector_impl::global_cable15_t<NV>
		auto& add12 = this->getT(0).getT(0).getT(0).getT(1).getT(1);          // math::add<NV>
		auto& chain1 = this->getT(0).getT(0).getT(0).getT(2);                 // NoteSelector_impl::chain1_t<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(0).getT(2).getT(0);  // NoteSelector_impl::global_cable1_t<NV>
		auto& add1 = this->getT(0).getT(0).getT(0).getT(2).getT(1);           // math::add<NV>
		auto& chain2 = this->getT(0).getT(0).getT(0).getT(3);                 // NoteSelector_impl::chain2_t<NV>
		auto& global_cable2 = this->getT(0).getT(0).getT(0).getT(3).getT(0);  // NoteSelector_impl::global_cable2_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(0).getT(3).getT(1);           // math::add<NV>
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(4);                 // NoteSelector_impl::chain6_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(0).getT(4).getT(0);  // NoteSelector_impl::global_cable6_t<NV>
		auto& add6 = this->getT(0).getT(0).getT(0).getT(4).getT(1);           // math::add<NV>
		auto& peak = this->getT(0).getT(0).getT(1);                           // NoteSelector_impl::peak_t
		auto& public_mod = this->getT(0).getT(0).getT(2);                     // routing::public_mod
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, branch); // NoteSrc -> branch::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable15.getWrappedObject().getParameter().connectT(0, add12); // global_cable15 -> add12::Value
		global_cable1.getWrappedObject().getParameter().connectT(0, add1);   // global_cable1 -> add1::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add2);   // global_cable2 -> add2::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add6);   // global_cable6 -> add6::Value
		peak.getParameter().connectT(0, public_mod);                         // peak -> public_mod::Value
		
		// Public Mod Connection -------------------------------------------------------------------
		
		public_mod.connect(*this);
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch::Index is automated
		
		add.setParameterT(0, 0.5); // math::add::Value
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add1::Value is automated
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add2::Value is automated
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add6::Value is automated
		
		; // public_mod::Value is automated
		
		this->setParameterT(0, 2.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable15_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable1_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable2_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable6_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).setExternalData(b, index); // NoteSelector_impl::peak_t
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
using NoteSelector = wrap::node<NoteSelector_impl::instance<NV>>;
}


