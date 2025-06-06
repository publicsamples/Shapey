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
using global_cable15_t_index = runtime_target::indexers::fix_hash<1378478464>;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   math::add<NV>>;
using global_cable19_t_index = runtime_target::indexers::fix_hash<1378478465>;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable19_t<NV>>, 
                                   math::add<NV>>;
using global_cable18_t_index = runtime_target::indexers::fix_hash<1378478466>;

template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable18_t<NV>>, 
                                   math::add<NV>>;
using global_cable17_t_index = runtime_target::indexers::fix_hash<1378478467>;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>>;
using global_cable16_t_index = runtime_target::indexers::fix_hash<1752812596>;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
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
                                   chain18_t<NV>, 
                                   chain17_t<NV>, 
                                   chain16_t<NV>, 
                                   chain15_t<NV>, 
                                   chain1_t<NV>, 
                                   chain2_t<NV>, 
                                   chain6_t<NV>>;

using global_cable_t_index = runtime_target::indexers::fix_hash<-1727851543>;
using change_mod = parameter::plain<routing::global_cable<global_cable_t_index, parameter::empty>, 
                                    0>;
template <int NV>
using change_t = control::change<NV, change_mod>;

template <int NV>
using peak_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<wrap::no_process<routing::public_mod>, 0>, 
                                  parameter::plain<change_t<NV>, 0>>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::data<core::peak, data::external::displaybuffer<0>>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch_t<NV>>, 
                                   peak_t<NV>, 
                                   change_t<NV>, 
                                   routing::global_cable<global_cable_t_index, parameter::empty>, 
                                   wrap::no_process<routing::public_mod>>;

template <int NV> using chain21_t = chain20_t<NV>;
using global_cable20_t_index = global_cable15_t_index;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable20_t<NV>>, 
                                   math::add<NV>>;
using global_cable21_t_index = global_cable19_t_index;

template <int NV>
using global_cable21_t = routing::global_cable<global_cable21_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable21_t<NV>>, 
                                   math::add<NV>>;
using global_cable22_t_index = global_cable18_t_index;

template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable22_t<NV>>, 
                                   math::add<NV>>;
using global_cable23_t_index = global_cable17_t_index;

template <int NV>
using global_cable23_t = routing::global_cable<global_cable23_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable23_t<NV>>, 
                                   math::add<NV>>;
using global_cable24_t_index = global_cable16_t_index;

template <int NV>
using global_cable24_t = routing::global_cable<global_cable24_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable24_t<NV>>, 
                                   math::add<NV>>;
using global_cable3_t_index = global_cable1_t_index;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable3_t<NV>>, 
                                  math::add<NV>>;
using global_cable4_t_index = global_cable2_t_index;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable4_t<NV>>, 
                                  math::add<NV>>;
using global_cable7_t_index = global_cable6_t_index;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable7_t<NV>>, 
                                  math::add<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain21_t<NV>>, 
                                    chain19_t<NV>, 
                                    chain22_t<NV>, 
                                    chain23_t<NV>, 
                                    chain24_t<NV>, 
                                    chain25_t<NV>, 
                                    chain3_t<NV>, 
                                    chain4_t<NV>, 
                                    chain7_t<NV>>;

using global_cable5_t_index = runtime_target::indexers::fix_hash<-1727851542>;
using change1_mod = parameter::plain<routing::global_cable<global_cable5_t_index, parameter::empty>, 
                                     0>;
template <int NV>
using change1_t = control::change<NV, change1_mod>;

template <int NV>
using peak1_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<wrap::no_process<routing::public_mod>, 0>, 
                                   parameter::plain<change1_t<NV>, 0>>;

template <int NV>
using peak1_t = wrap::mod<peak1_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch1_t<NV>>, 
                                   peak1_t<NV>, 
                                   change1_t<NV>, 
                                   routing::global_cable<global_cable5_t_index, parameter::empty>, 
                                   wrap::no_process<routing::public_mod>>;

template <int NV> using chain27_t = chain20_t<NV>;
using global_cable25_t_index = global_cable15_t_index;

template <int NV>
using global_cable25_t = routing::global_cable<global_cable25_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable25_t<NV>>, 
                                   math::add<NV>>;
using global_cable26_t_index = global_cable19_t_index;

template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable26_t<NV>>, 
                                   math::add<NV>>;
using global_cable27_t_index = global_cable18_t_index;

template <int NV>
using global_cable27_t = routing::global_cable<global_cable27_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable27_t<NV>>, 
                                   math::add<NV>>;
using global_cable28_t_index = global_cable17_t_index;

template <int NV>
using global_cable28_t = routing::global_cable<global_cable28_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable28_t<NV>>, 
                                   math::add<NV>>;
using global_cable29_t_index = global_cable16_t_index;

template <int NV>
using global_cable29_t = routing::global_cable<global_cable29_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable29_t<NV>>, 
                                   math::add<NV>>;
using global_cable8_t_index = global_cable1_t_index;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable8_t<NV>>, 
                                  math::add<NV>>;
using global_cable9_t_index = global_cable2_t_index;

template <int NV>
using global_cable9_t = routing::global_cable<global_cable9_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable9_t<NV>>, 
                                  math::add<NV>>;
using global_cable10_t_index = global_cable6_t_index;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable10_t<NV>>, 
                                  math::add<NV>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain27_t<NV>>, 
                                    chain28_t<NV>, 
                                    chain29_t<NV>, 
                                    chain30_t<NV>, 
                                    chain31_t<NV>, 
                                    chain32_t<NV>, 
                                    chain5_t<NV>, 
                                    chain8_t<NV>, 
                                    chain9_t<NV>>;

using global_cable11_t_index = runtime_target::indexers::fix_hash<-1727851541>;
using change2_mod = parameter::plain<routing::global_cable<global_cable11_t_index, parameter::empty>, 
                                     0>;
template <int NV>
using change2_t = control::change<NV, change2_mod>;

template <int NV>
using peak2_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<wrap::no_process<routing::public_mod>, 0>, 
                                   parameter::plain<change2_t<NV>, 0>>;

template <int NV>
using peak2_t = wrap::mod<peak2_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch2_t<NV>>, 
                                   peak2_t<NV>, 
                                   change2_t<NV>, 
                                   routing::global_cable<global_cable11_t_index, parameter::empty>, 
                                   wrap::no_process<routing::public_mod>>;

template <int NV> using chain34_t = chain20_t<NV>;
using global_cable30_t_index = global_cable15_t_index;

template <int NV>
using global_cable30_t = routing::global_cable<global_cable30_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable30_t<NV>>, 
                                   math::add<NV>>;
using global_cable31_t_index = global_cable19_t_index;

template <int NV>
using global_cable31_t = routing::global_cable<global_cable31_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable31_t<NV>>, 
                                   math::add<NV>>;
using global_cable32_t_index = global_cable18_t_index;

template <int NV>
using global_cable32_t = routing::global_cable<global_cable32_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable32_t<NV>>, 
                                   math::add<NV>>;
using global_cable33_t_index = global_cable17_t_index;

template <int NV>
using global_cable33_t = routing::global_cable<global_cable33_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable33_t<NV>>, 
                                   math::add<NV>>;
using global_cable34_t_index = global_cable16_t_index;

template <int NV>
using global_cable34_t = routing::global_cable<global_cable34_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable34_t<NV>>, 
                                   math::add<NV>>;
using global_cable12_t_index = global_cable1_t_index;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   math::add<NV>>;
using global_cable13_t_index = global_cable2_t_index;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>>;
using global_cable14_t_index = global_cable6_t_index;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain34_t<NV>>, 
                                    chain35_t<NV>, 
                                    chain36_t<NV>, 
                                    chain37_t<NV>, 
                                    chain38_t<NV>, 
                                    chain39_t<NV>, 
                                    chain10_t<NV>, 
                                    chain11_t<NV>, 
                                    chain40_t<NV>>;

using global_cable35_t_index = runtime_target::indexers::fix_hash<-1727851540>;
using change3_mod = parameter::plain<routing::global_cable<global_cable35_t_index, parameter::empty>, 
                                     0>;
template <int NV>
using change3_t = control::change<NV, change3_mod>;

template <int NV>
using peak3_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<wrap::no_process<routing::public_mod>, 0>, 
                                   parameter::plain<change3_t<NV>, 0>>;

template <int NV>
using peak3_t = wrap::mod<peak3_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch3_t<NV>>, 
                                   peak3_t<NV>, 
                                   change3_t<NV>, 
                                   routing::global_cable<global_cable35_t_index, parameter::empty>, 
                                   wrap::no_process<routing::public_mod>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain12_t<NV>>, 
                                  chain13_t<NV>, 
                                  chain26_t<NV>, 
                                  chain33_t<NV>>;

namespace NoteSelector_t_parameters
{
// Parameter list for NoteSelector_impl::NoteSelector_t --------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(NoteSrc_InputRange, 
                             1., 
                             9., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(NoteSrc_0Range, 
                             0., 
                             8., 
                             1.);

template <int NV>
using NoteSrc_0 = parameter::from0To1<NoteSelector_impl::branch_t<NV>, 
                                      0, 
                                      NoteSrc_0Range>;

template <int NV>
using NoteSrc = parameter::chain<NoteSrc_InputRange, NoteSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Note2_InputRange, 
                             1., 
                             9., 
                             1.);
template <int NV>
using Note2_0 = parameter::from0To1<NoteSelector_impl::branch1_t<NV>, 
                                    0, 
                                    NoteSrc_0Range>;

template <int NV>
using Note2 = parameter::chain<Note2_InputRange, Note2_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Note3_InputRange, 
                             1., 
                             9., 
                             1.);
template <int NV>
using Note3_0 = parameter::from0To1<NoteSelector_impl::branch2_t<NV>, 
                                    0, 
                                    NoteSrc_0Range>;

template <int NV>
using Note3 = parameter::chain<Note3_InputRange, Note3_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Note4_InputRange, 
                             1., 
                             9., 
                             1.);
template <int NV>
using Note4_0 = parameter::from0To1<NoteSelector_impl::branch3_t<NV>, 
                                    0, 
                                    NoteSrc_0Range>;

template <int NV>
using Note4 = parameter::chain<Note4_InputRange, Note4_0<NV>>;

template <int NV>
using NoteSelector_t_plist = parameter::list<NoteSrc<NV>, 
                                             Note2<NV>, 
                                             Note3<NV>, 
                                             Note4<NV>>;
}

template <int NV>
using NoteSelector_t_ = container::chain<NoteSelector_t_parameters::NoteSelector_t_plist<NV>, 
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
		SNEX_METADATA_ENCODED_PARAMETERS(64)
		{
			0x005B, 0x0000, 0x4E00, 0x746F, 0x5365, 0x6372, 0x0000, 0x8000, 
            0x003F, 0x1000, 0x0041, 0x0000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0001, 0x0000, 0x6F4E, 0x6574, 0x0032, 0x0000, 0x3F80, 
            0x0000, 0x4110, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x025B, 0x0000, 0x4E00, 0x746F, 0x3365, 0x0000, 0x8000, 0x003F, 
            0x1000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0003, 0x0000, 0x6F4E, 0x6574, 0x0034, 0x0000, 0x3F80, 0x0000, 
            0x4110, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000
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
		auto& chain18 = this->getT(0).getT(0).getT(0).getT(2);                // NoteSelector_impl::chain18_t<NV>
		auto& global_cable19 = this->getT(0).getT(0).getT(0).getT(2).getT(0); // NoteSelector_impl::global_cable19_t<NV>
		auto& add16 = this->getT(0).getT(0).getT(0).getT(2).getT(1);          // math::add<NV>
		auto& chain17 = this->getT(0).getT(0).getT(0).getT(3);                // NoteSelector_impl::chain17_t<NV>
		auto& global_cable18 = this->getT(0).getT(0).getT(0).getT(3).getT(0); // NoteSelector_impl::global_cable18_t<NV>
		auto& add15 = this->getT(0).getT(0).getT(0).getT(3).getT(1);          // math::add<NV>
		auto& chain16 = this->getT(0).getT(0).getT(0).getT(4);                // NoteSelector_impl::chain16_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(0).getT(4).getT(0); // NoteSelector_impl::global_cable17_t<NV>
		auto& add14 = this->getT(0).getT(0).getT(0).getT(4).getT(1);          // math::add<NV>
		auto& chain15 = this->getT(0).getT(0).getT(0).getT(5);                // NoteSelector_impl::chain15_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(0).getT(5).getT(0); // NoteSelector_impl::global_cable16_t<NV>
		auto& add13 = this->getT(0).getT(0).getT(0).getT(5).getT(1);          // math::add<NV>
		auto& chain1 = this->getT(0).getT(0).getT(0).getT(6);                 // NoteSelector_impl::chain1_t<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(0).getT(6).getT(0);  // NoteSelector_impl::global_cable1_t<NV>
		auto& add1 = this->getT(0).getT(0).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain2 = this->getT(0).getT(0).getT(0).getT(7);                 // NoteSelector_impl::chain2_t<NV>
		auto& global_cable2 = this->getT(0).getT(0).getT(0).getT(7).getT(0);  // NoteSelector_impl::global_cable2_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain6 = this->getT(0).getT(0).getT(0).getT(8);                 // NoteSelector_impl::chain6_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(0).getT(8).getT(0);  // NoteSelector_impl::global_cable6_t<NV>
		auto& add6 = this->getT(0).getT(0).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& peak = this->getT(0).getT(0).getT(1);                           // NoteSelector_impl::peak_t<NV>
		auto& change = this->getT(0).getT(0).getT(2);                         // NoteSelector_impl::change_t<NV>
		auto& global_cable = this->getT(0).getT(0).getT(3);                   // routing::global_cable<global_cable_t_index, parameter::empty>
		auto& public_mod = this->getT(0).getT(0).getT(4);                     // wrap::no_process<routing::public_mod>
		auto& chain13 = this->getT(0).getT(1);                                // NoteSelector_impl::chain13_t<NV>
		auto& branch1 = this->getT(0).getT(1).getT(0);                        // NoteSelector_impl::branch1_t<NV>
		auto& chain21 = this->getT(0).getT(1).getT(0).getT(0);                // NoteSelector_impl::chain21_t<NV>
		auto& add3 = this->getT(0).getT(1).getT(0).getT(0).getT(0);           // math::add<NV>
		auto& chain19 = this->getT(0).getT(1).getT(0).getT(1);                // NoteSelector_impl::chain19_t<NV>
		auto& global_cable20 = this->getT(0).getT(1).getT(0).getT(1).getT(0); // NoteSelector_impl::global_cable20_t<NV>
		auto& add17 = this->getT(0).getT(1).getT(0).getT(1).getT(1);          // math::add<NV>
		auto& chain22 = this->getT(0).getT(1).getT(0).getT(2);                // NoteSelector_impl::chain22_t<NV>
		auto& global_cable21 = this->getT(0).getT(1).getT(0).getT(2).getT(0); // NoteSelector_impl::global_cable21_t<NV>
		auto& add18 = this->getT(0).getT(1).getT(0).getT(2).getT(1);          // math::add<NV>
		auto& chain23 = this->getT(0).getT(1).getT(0).getT(3);                // NoteSelector_impl::chain23_t<NV>
		auto& global_cable22 = this->getT(0).getT(1).getT(0).getT(3).getT(0); // NoteSelector_impl::global_cable22_t<NV>
		auto& add19 = this->getT(0).getT(1).getT(0).getT(3).getT(1);          // math::add<NV>
		auto& chain24 = this->getT(0).getT(1).getT(0).getT(4);                // NoteSelector_impl::chain24_t<NV>
		auto& global_cable23 = this->getT(0).getT(1).getT(0).getT(4).getT(0); // NoteSelector_impl::global_cable23_t<NV>
		auto& add20 = this->getT(0).getT(1).getT(0).getT(4).getT(1);          // math::add<NV>
		auto& chain25 = this->getT(0).getT(1).getT(0).getT(5);                // NoteSelector_impl::chain25_t<NV>
		auto& global_cable24 = this->getT(0).getT(1).getT(0).getT(5).getT(0); // NoteSelector_impl::global_cable24_t<NV>
		auto& add21 = this->getT(0).getT(1).getT(0).getT(5).getT(1);          // math::add<NV>
		auto& chain3 = this->getT(0).getT(1).getT(0).getT(6);                 // NoteSelector_impl::chain3_t<NV>
		auto& global_cable3 = this->getT(0).getT(1).getT(0).getT(6).getT(0);  // NoteSelector_impl::global_cable3_t<NV>
		auto& add4 = this->getT(0).getT(1).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain4 = this->getT(0).getT(1).getT(0).getT(7);                 // NoteSelector_impl::chain4_t<NV>
		auto& global_cable4 = this->getT(0).getT(1).getT(0).getT(7).getT(0);  // NoteSelector_impl::global_cable4_t<NV>
		auto& add5 = this->getT(0).getT(1).getT(0).getT(7).getT(1);           // math::add<NV>
		auto& chain7 = this->getT(0).getT(1).getT(0).getT(8);                 // NoteSelector_impl::chain7_t<NV>
		auto& global_cable7 = this->getT(0).getT(1).getT(0).getT(8).getT(0);  // NoteSelector_impl::global_cable7_t<NV>
		auto& add7 = this->getT(0).getT(1).getT(0).getT(8).getT(1);           // math::add<NV>
		auto& peak1 = this->getT(0).getT(1).getT(1);                          // NoteSelector_impl::peak1_t<NV>
		auto& change1 = this->getT(0).getT(1).getT(2);                        // NoteSelector_impl::change1_t<NV>
		auto& global_cable5 = this->getT(0).getT(1).getT(3);                  // routing::global_cable<global_cable5_t_index, parameter::empty>
		auto& public_mod1 = this->getT(0).getT(1).getT(4);                    // wrap::no_process<routing::public_mod>
		auto& chain26 = this->getT(0).getT(2);                                // NoteSelector_impl::chain26_t<NV>
		auto& branch2 = this->getT(0).getT(2).getT(0);                        // NoteSelector_impl::branch2_t<NV>
		auto& chain27 = this->getT(0).getT(2).getT(0).getT(0);                // NoteSelector_impl::chain27_t<NV>
		auto& add8 = this->getT(0).getT(2).getT(0).getT(0).getT(0);           // math::add<NV>
		auto& chain28 = this->getT(0).getT(2).getT(0).getT(1);                // NoteSelector_impl::chain28_t<NV>
		auto& global_cable25 = this->getT(0).getT(2).getT(0).getT(1).getT(0); // NoteSelector_impl::global_cable25_t<NV>
		auto& add22 = this->getT(0).getT(2).getT(0).getT(1).getT(1);          // math::add<NV>
		auto& chain29 = this->getT(0).getT(2).getT(0).getT(2);                // NoteSelector_impl::chain29_t<NV>
		auto& global_cable26 = this->getT(0).getT(2).getT(0).getT(2).getT(0); // NoteSelector_impl::global_cable26_t<NV>
		auto& add23 = this->getT(0).getT(2).getT(0).getT(2).getT(1);          // math::add<NV>
		auto& chain30 = this->getT(0).getT(2).getT(0).getT(3);                // NoteSelector_impl::chain30_t<NV>
		auto& global_cable27 = this->getT(0).getT(2).getT(0).getT(3).getT(0); // NoteSelector_impl::global_cable27_t<NV>
		auto& add24 = this->getT(0).getT(2).getT(0).getT(3).getT(1);          // math::add<NV>
		auto& chain31 = this->getT(0).getT(2).getT(0).getT(4);                // NoteSelector_impl::chain31_t<NV>
		auto& global_cable28 = this->getT(0).getT(2).getT(0).getT(4).getT(0); // NoteSelector_impl::global_cable28_t<NV>
		auto& add25 = this->getT(0).getT(2).getT(0).getT(4).getT(1);          // math::add<NV>
		auto& chain32 = this->getT(0).getT(2).getT(0).getT(5);                // NoteSelector_impl::chain32_t<NV>
		auto& global_cable29 = this->getT(0).getT(2).getT(0).getT(5).getT(0); // NoteSelector_impl::global_cable29_t<NV>
		auto& add26 = this->getT(0).getT(2).getT(0).getT(5).getT(1);          // math::add<NV>
		auto& chain5 = this->getT(0).getT(2).getT(0).getT(6);                 // NoteSelector_impl::chain5_t<NV>
		auto& global_cable8 = this->getT(0).getT(2).getT(0).getT(6).getT(0);  // NoteSelector_impl::global_cable8_t<NV>
		auto& add9 = this->getT(0).getT(2).getT(0).getT(6).getT(1);           // math::add<NV>
		auto& chain8 = this->getT(0).getT(2).getT(0).getT(7);                 // NoteSelector_impl::chain8_t<NV>
		auto& global_cable9 = this->getT(0).getT(2).getT(0).getT(7).getT(0);  // NoteSelector_impl::global_cable9_t<NV>
		auto& add10 = this->getT(0).getT(2).getT(0).getT(7).getT(1);          // math::add<NV>
		auto& chain9 = this->getT(0).getT(2).getT(0).getT(8);                 // NoteSelector_impl::chain9_t<NV>
		auto& global_cable10 = this->getT(0).getT(2).getT(0).getT(8).getT(0); // NoteSelector_impl::global_cable10_t<NV>
		auto& add11 = this->getT(0).getT(2).getT(0).getT(8).getT(1);          // math::add<NV>
		auto& peak2 = this->getT(0).getT(2).getT(1);                          // NoteSelector_impl::peak2_t<NV>
		auto& change2 = this->getT(0).getT(2).getT(2);                        // NoteSelector_impl::change2_t<NV>
		auto& global_cable11 = this->getT(0).getT(2).getT(3);                 // routing::global_cable<global_cable11_t_index, parameter::empty>
		auto& public_mod2 = this->getT(0).getT(2).getT(4);                    // wrap::no_process<routing::public_mod>
		auto& chain33 = this->getT(0).getT(3);                                // NoteSelector_impl::chain33_t<NV>
		auto& branch3 = this->getT(0).getT(3).getT(0);                        // NoteSelector_impl::branch3_t<NV>
		auto& chain34 = this->getT(0).getT(3).getT(0).getT(0);                // NoteSelector_impl::chain34_t<NV>
		auto& add27 = this->getT(0).getT(3).getT(0).getT(0).getT(0);          // math::add<NV>
		auto& chain35 = this->getT(0).getT(3).getT(0).getT(1);                // NoteSelector_impl::chain35_t<NV>
		auto& global_cable30 = this->getT(0).getT(3).getT(0).getT(1).getT(0); // NoteSelector_impl::global_cable30_t<NV>
		auto& add28 = this->getT(0).getT(3).getT(0).getT(1).getT(1);          // math::add<NV>
		auto& chain36 = this->getT(0).getT(3).getT(0).getT(2);                // NoteSelector_impl::chain36_t<NV>
		auto& global_cable31 = this->getT(0).getT(3).getT(0).getT(2).getT(0); // NoteSelector_impl::global_cable31_t<NV>
		auto& add29 = this->getT(0).getT(3).getT(0).getT(2).getT(1);          // math::add<NV>
		auto& chain37 = this->getT(0).getT(3).getT(0).getT(3);                // NoteSelector_impl::chain37_t<NV>
		auto& global_cable32 = this->getT(0).getT(3).getT(0).getT(3).getT(0); // NoteSelector_impl::global_cable32_t<NV>
		auto& add30 = this->getT(0).getT(3).getT(0).getT(3).getT(1);          // math::add<NV>
		auto& chain38 = this->getT(0).getT(3).getT(0).getT(4);                // NoteSelector_impl::chain38_t<NV>
		auto& global_cable33 = this->getT(0).getT(3).getT(0).getT(4).getT(0); // NoteSelector_impl::global_cable33_t<NV>
		auto& add31 = this->getT(0).getT(3).getT(0).getT(4).getT(1);          // math::add<NV>
		auto& chain39 = this->getT(0).getT(3).getT(0).getT(5);                // NoteSelector_impl::chain39_t<NV>
		auto& global_cable34 = this->getT(0).getT(3).getT(0).getT(5).getT(0); // NoteSelector_impl::global_cable34_t<NV>
		auto& add32 = this->getT(0).getT(3).getT(0).getT(5).getT(1);          // math::add<NV>
		auto& chain10 = this->getT(0).getT(3).getT(0).getT(6);                // NoteSelector_impl::chain10_t<NV>
		auto& global_cable12 = this->getT(0).getT(3).getT(0).getT(6).getT(0); // NoteSelector_impl::global_cable12_t<NV>
		auto& add33 = this->getT(0).getT(3).getT(0).getT(6).getT(1);          // math::add<NV>
		auto& chain11 = this->getT(0).getT(3).getT(0).getT(7);                // NoteSelector_impl::chain11_t<NV>
		auto& global_cable13 = this->getT(0).getT(3).getT(0).getT(7).getT(0); // NoteSelector_impl::global_cable13_t<NV>
		auto& add34 = this->getT(0).getT(3).getT(0).getT(7).getT(1);          // math::add<NV>
		auto& chain40 = this->getT(0).getT(3).getT(0).getT(8);                // NoteSelector_impl::chain40_t<NV>
		auto& global_cable14 = this->getT(0).getT(3).getT(0).getT(8).getT(0); // NoteSelector_impl::global_cable14_t<NV>
		auto& add35 = this->getT(0).getT(3).getT(0).getT(8).getT(1);          // math::add<NV>
		auto& peak3 = this->getT(0).getT(3).getT(1);                          // NoteSelector_impl::peak3_t<NV>
		auto& change3 = this->getT(0).getT(3).getT(2);                        // NoteSelector_impl::change3_t<NV>
		auto& global_cable35 = this->getT(0).getT(3).getT(3);                 // routing::global_cable<global_cable35_t_index, parameter::empty>
		auto& public_mod3 = this->getT(0).getT(3).getT(4);                    // wrap::no_process<routing::public_mod>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, branch); // NoteSrc -> branch::Index
		
		this->getParameterT(1).connectT(0, branch1); // Note2 -> branch1::Index
		
		this->getParameterT(2).connectT(0, branch2); // Note3 -> branch2::Index
		
		this->getParameterT(3).connectT(0, branch3); // Note4 -> branch3::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		global_cable15.getWrappedObject().getParameter().connectT(0, add12);   // global_cable15 -> add12::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add16);   // global_cable19 -> add16::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, add15);   // global_cable18 -> add15::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add14);   // global_cable17 -> add14::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add13);   // global_cable16 -> add13::Value
		global_cable1.getWrappedObject().getParameter().connectT(0, add1);     // global_cable1 -> add1::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add2);     // global_cable2 -> add2::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add6);     // global_cable6 -> add6::Value
		change.getWrappedObject().getParameter().connectT(0, global_cable);    // change -> global_cable::Value
		peak.getParameter().connectT(0, public_mod);                           // peak -> public_mod::Value
		peak.getParameter().connectT(1, change);                               // peak -> change::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add17);   // global_cable20 -> add17::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add18);   // global_cable21 -> add18::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add19);   // global_cable22 -> add19::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add20);   // global_cable23 -> add20::Value
		global_cable24.getWrappedObject().getParameter().connectT(0, add21);   // global_cable24 -> add21::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add4);     // global_cable3 -> add4::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, add5);     // global_cable4 -> add5::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, add7);     // global_cable7 -> add7::Value
		change1.getWrappedObject().getParameter().connectT(0, global_cable5);  // change1 -> global_cable5::Value
		peak1.getParameter().connectT(0, public_mod1);                         // peak1 -> public_mod1::Value
		peak1.getParameter().connectT(1, change1);                             // peak1 -> change1::Value
		global_cable25.getWrappedObject().getParameter().connectT(0, add22);   // global_cable25 -> add22::Value
		global_cable26.getWrappedObject().getParameter().connectT(0, add23);   // global_cable26 -> add23::Value
		global_cable27.getWrappedObject().getParameter().connectT(0, add24);   // global_cable27 -> add24::Value
		global_cable28.getWrappedObject().getParameter().connectT(0, add25);   // global_cable28 -> add25::Value
		global_cable29.getWrappedObject().getParameter().connectT(0, add26);   // global_cable29 -> add26::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, add9);     // global_cable8 -> add9::Value
		global_cable9.getWrappedObject().getParameter().connectT(0, add10);    // global_cable9 -> add10::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, add11);   // global_cable10 -> add11::Value
		change2.getWrappedObject().getParameter().connectT(0, global_cable11); // change2 -> global_cable11::Value
		peak2.getParameter().connectT(0, public_mod2);                         // peak2 -> public_mod2::Value
		peak2.getParameter().connectT(1, change2);                             // peak2 -> change2::Value
		global_cable30.getWrappedObject().getParameter().connectT(0, add28);   // global_cable30 -> add28::Value
		global_cable31.getWrappedObject().getParameter().connectT(0, add29);   // global_cable31 -> add29::Value
		global_cable32.getWrappedObject().getParameter().connectT(0, add30);   // global_cable32 -> add30::Value
		global_cable33.getWrappedObject().getParameter().connectT(0, add31);   // global_cable33 -> add31::Value
		global_cable34.getWrappedObject().getParameter().connectT(0, add32);   // global_cable34 -> add32::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add33);   // global_cable12 -> add33::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add34);   // global_cable13 -> add34::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add35);   // global_cable14 -> add35::Value
		change3.getWrappedObject().getParameter().connectT(0, global_cable35); // change3 -> global_cable35::Value
		peak3.getParameter().connectT(0, public_mod3);                         // peak3 -> public_mod3::Value
		peak3.getParameter().connectT(1, change3);                             // peak3 -> change3::Value
		
		// Public Mod Connection -------------------------------------------------------------------
		
		public_mod.connect(*this);
		public_mod1.connect(*this);
		public_mod2.connect(*this);
		public_mod3.connect(*this);
		
		// Default Values --------------------------------------------------------------------------
		
		; // branch::Index is automated
		
		add.setParameterT(0, 0.5); // math::add::Value
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		global_cable19.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add16::Value is automated
		
		global_cable18.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add15::Value is automated
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add14::Value is automated
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add13::Value is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add1::Value is automated
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add2::Value is automated
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add6::Value is automated
		
		; // change::Value is automated
		
		; // global_cable::Value is automated
		
		; // public_mod::Value is automated
		
		; // branch1::Index is automated
		
		add3.setParameterT(0, 0.5); // math::add::Value
		
		global_cable20.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add17::Value is automated
		
		global_cable21.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add18::Value is automated
		
		global_cable22.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add19::Value is automated
		
		global_cable23.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add20::Value is automated
		
		global_cable24.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add21::Value is automated
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add4::Value is automated
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add7::Value is automated
		
		; // change1::Value is automated
		
		; // global_cable5::Value is automated
		
		; // public_mod1::Value is automated
		
		; // branch2::Index is automated
		
		add8.setParameterT(0, 0.5); // math::add::Value
		
		global_cable25.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add22::Value is automated
		
		global_cable26.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add23::Value is automated
		
		global_cable27.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add24::Value is automated
		
		global_cable28.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add25::Value is automated
		
		global_cable29.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add26::Value is automated
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add9::Value is automated
		
		global_cable9.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add11::Value is automated
		
		; // change2::Value is automated
		
		; // global_cable11::Value is automated
		
		; // public_mod2::Value is automated
		
		; // branch3::Index is automated
		
		add27.setParameterT(0, 0.5); // math::add::Value
		
		global_cable30.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add28::Value is automated
		
		global_cable31.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add29::Value is automated
		
		global_cable32.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add30::Value is automated
		
		global_cable33.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add31::Value is automated
		
		global_cable34.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add32::Value is automated
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add33::Value is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add34::Value is automated
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add35::Value is automated
		
		; // change3::Value is automated
		
		; // global_cable35::Value is automated
		
		; // public_mod3::Value is automated
		
		this->setParameterT(0, 2.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
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
		this->getT(0).getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable19_t<NV>
		this->getT(0).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable18_t<NV>
		this->getT(0).getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable17_t<NV>
		this->getT(0).getT(0).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable16_t<NV>
		this->getT(0).getT(0).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable1_t<NV>
		this->getT(0).getT(0).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable2_t<NV>
		this->getT(0).getT(0).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable6_t<NV>
		this->getT(0).getT(0).getT(3).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable_t_index, parameter::empty>
		this->getT(0).getT(1).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable20_t<NV>
		this->getT(0).getT(1).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable21_t<NV>
		this->getT(0).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable22_t<NV>
		this->getT(0).getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable23_t<NV>
		this->getT(0).getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable24_t<NV>
		this->getT(0).getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable3_t<NV>
		this->getT(0).getT(1).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable4_t<NV>
		this->getT(0).getT(1).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable7_t<NV>
		this->getT(0).getT(1).getT(3).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable5_t_index, parameter::empty>
		this->getT(0).getT(2).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable25_t<NV>
		this->getT(0).getT(2).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable26_t<NV>
		this->getT(0).getT(2).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable27_t<NV>
		this->getT(0).getT(2).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable28_t<NV>
		this->getT(0).getT(2).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable29_t<NV>
		this->getT(0).getT(2).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable8_t<NV>
		this->getT(0).getT(2).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable9_t<NV>
		this->getT(0).getT(2).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable10_t<NV>
		this->getT(0).getT(2).getT(3).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable11_t_index, parameter::empty>
		this->getT(0).getT(3).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable30_t<NV>
		this->getT(0).getT(3).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable31_t<NV>
		this->getT(0).getT(3).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable32_t<NV>
		this->getT(0).getT(3).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable33_t<NV>
		this->getT(0).getT(3).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable34_t<NV>
		this->getT(0).getT(3).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable12_t<NV>
		this->getT(0).getT(3).getT(0).getT(7).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable13_t<NV>
		this->getT(0).getT(3).getT(0).getT(8).getT(0).connectToRuntimeTarget(addConnection, c); // NoteSelector_impl::global_cable14_t<NV>
		this->getT(0).getT(3).getT(3).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable35_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(1).setExternalData(b, index); // NoteSelector_impl::peak_t<NV>
		this->getT(0).getT(1).getT(1).setExternalData(b, index); // NoteSelector_impl::peak1_t<NV>
		this->getT(0).getT(2).getT(1).setExternalData(b, index); // NoteSelector_impl::peak2_t<NV>
		this->getT(0).getT(3).getT(1).setExternalData(b, index); // NoteSelector_impl::peak3_t<NV>
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


