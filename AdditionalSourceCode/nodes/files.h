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

namespace files_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(sliderbank3_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using sliderbank3_c0 = parameter::from0To1<core::gain<NV>, 
                                           0, 
                                           sliderbank3_c0Range>;

template <int NV> using sliderbank3_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank3_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank3_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank3_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank3_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank3_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank3_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank3_multimod = parameter::list<sliderbank3_c0<NV>, 
                                             sliderbank3_c1<NV>, 
                                             sliderbank3_c2<NV>, 
                                             sliderbank3_c3<NV>, 
                                             sliderbank3_c4<NV>, 
                                             sliderbank3_c5<NV>, 
                                             sliderbank3_c6<NV>, 
                                             sliderbank3_c7<NV>>;

template <int NV>
using sliderbank3_t = wrap::data<control::sliderbank<sliderbank3_multimod<NV>>, 
                                 data::external::sliderpack<0>>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<2333884>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable3_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable11_t_index = runtime_target::indexers::fix_hash<2333885>;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable11_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable10_t_index = runtime_target::indexers::fix_hash<2333886>;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable10_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using event_data_reader3_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader3_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader11_t = event_data_reader3_t<NV>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader11_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader10_t = event_data_reader3_t<NV>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader10_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using midi1_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi1_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using midi_cc3_t = control::midi_cc<parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc3_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain39_t<NV>>, 
                                  chain41_t<NV>, 
                                  chain40_t<NV>, 
                                  chain42_t<NV>, 
                                  chain44_t<NV>, 
                                  chain45_t<NV>, 
                                  chain46_t<NV>, 
                                  chain47_t<NV>>;

template <int NV>
using minmax3_t = control::minmax<NV, 
                                  parameter::plain<math::add<NV>, 0>>;

template <int NV> using minmax5_t = minmax3_t<NV>;

template <int NV> using minmax12_t = minmax3_t<NV>;

template <int NV> using minmax10_t = minmax3_t<NV>;

template <int NV> using minmax9_t = minmax3_t<NV>;

template <int NV> using minmax8_t = minmax3_t<NV>;

template <int NV> using minmax4_t = minmax3_t<NV>;

template <int NV> using minmax13_t = minmax3_t<NV>;

template <int NV>
using pma1_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<math::add<NV>, 0>, 
                                  parameter::plain<minmax3_t<NV>, 0>, 
                                  parameter::plain<minmax5_t<NV>, 0>, 
                                  parameter::plain<minmax12_t<NV>, 0>, 
                                  parameter::plain<minmax10_t<NV>, 0>, 
                                  parameter::plain<minmax9_t<NV>, 0>, 
                                  parameter::plain<minmax8_t<NV>, 0>, 
                                  parameter::plain<minmax4_t<NV>, 0>, 
                                  parameter::plain<minmax13_t<NV>, 0>>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;
template <int NV>
using peak3_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, sliderbank3_t<NV>>, 
                                     split1_t<NV>, 
                                     peak3_t<NV>, 
                                     pma1_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV> using sliderbank7_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank7_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank7_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank7_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank7_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank7_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank7_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank7_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank7_multimod = parameter::list<sliderbank7_c0<NV>, 
                                             sliderbank7_c1<NV>, 
                                             sliderbank7_c2<NV>, 
                                             sliderbank7_c3<NV>, 
                                             sliderbank7_c4<NV>, 
                                             sliderbank7_c5<NV>, 
                                             sliderbank7_c6<NV>, 
                                             sliderbank7_c7<NV>>;

template <int NV>
using sliderbank7_t = wrap::data<control::sliderbank<sliderbank7_multimod<NV>>, 
                                 data::external::sliderpack<1>>;
using global_cable5_t_index = global_cable3_t_index;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain72_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable5_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable20_t_index = global_cable11_t_index;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain73_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable20_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable21_t_index = global_cable10_t_index;

template <int NV>
using global_cable21_t = routing::global_cable<global_cable21_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain74_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable21_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader5_t = event_data_reader3_t<NV>;

template <int NV>
using chain75_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader5_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader20_t = event_data_reader3_t<NV>;

template <int NV>
using chain76_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader20_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader21_t = event_data_reader3_t<NV>;

template <int NV>
using chain77_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader21_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi3_t = midi1_t<NV>;

template <int NV>
using chain80_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi3_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc7_t = midi_cc3_t<NV>;

template <int NV>
using chain81_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc7_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain72_t<NV>>, 
                                  chain73_t<NV>, 
                                  chain74_t<NV>, 
                                  chain75_t<NV>, 
                                  chain76_t<NV>, 
                                  chain77_t<NV>, 
                                  chain80_t<NV>, 
                                  chain81_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(pma4_modRange, 
                             -24., 
                             24., 
                             0.1);

template <int NV>
using pma4_mod = parameter::from0To1<project::shfiter<NV>, 
                                     0, 
                                     pma4_modRange>;

template <int NV>
using pma4_t = control::pma<NV, pma4_mod<NV>>;
template <int NV>
using peak7_t = wrap::mod<parameter::plain<pma4_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain4_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank7_t<NV>>, 
                                      split3_t<NV>, 
                                      peak7_t<NV>, 
                                      pma4_t<NV>>;

template <int NV>
using modchain4_t = wrap::control_rate<modchain4_t_<NV>>;

template <int NV> using sliderbank6_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank6_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank6_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank6_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank6_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank6_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank6_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank6_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank6_multimod = parameter::list<sliderbank6_c0<NV>, 
                                             sliderbank6_c1<NV>, 
                                             sliderbank6_c2<NV>, 
                                             sliderbank6_c3<NV>, 
                                             sliderbank6_c4<NV>, 
                                             sliderbank6_c5<NV>, 
                                             sliderbank6_c6<NV>, 
                                             sliderbank6_c7<NV>>;

template <int NV>
using sliderbank6_t = wrap::data<control::sliderbank<sliderbank6_multimod<NV>>, 
                                 data::external::sliderpack<2>>;
using global_cable4_t_index = global_cable3_t_index;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain64_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable4_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable12_t_index = global_cable11_t_index;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain65_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable19_t_index = global_cable10_t_index;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain66_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable19_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader4_t = event_data_reader3_t<NV>;

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader4_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader12_t = event_data_reader3_t<NV>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader12_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader19_t = event_data_reader3_t<NV>;

template <int NV>
using chain69_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader19_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi2_t = midi1_t<NV>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi2_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc6_t = midi_cc3_t<NV>;

template <int NV>
using chain71_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc6_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain64_t<NV>>, 
                                  chain65_t<NV>, 
                                  chain66_t<NV>, 
                                  chain67_t<NV>, 
                                  chain68_t<NV>, 
                                  chain69_t<NV>, 
                                  chain70_t<NV>, 
                                  chain71_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(pma3_modRange, 
                             -100., 
                             24., 
                             5.42227);

template <int NV>
using pma3_mod = parameter::from0To1<core::gain<NV>, 
                                     0, 
                                     pma3_modRange>;

template <int NV>
using pma3_t = control::pma<NV, pma3_mod<NV>>;
template <int NV>
using peak6_t = wrap::mod<parameter::plain<pma3_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain3_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank6_t<NV>>, 
                                      split2_t<NV>, 
                                      peak6_t<NV>, 
                                      pma3_t<NV>>;

template <int NV>
using modchain3_t = wrap::control_rate<modchain3_t_<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<2, modchain_t<NV>>, 
                                  modchain4_t<NV>, 
                                  modchain3_t<NV>>;

template <int NV> using xfader_c0 = sliderbank3_c0<NV>;

template <int NV> using xfader_c1 = sliderbank3_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::overlap>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, core::gain<NV>>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax3_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, minmax5_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain89_t = container::chain<parameter::empty, 
                                   wrap::fix<2, minmax12_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain83_t = container::chain<parameter::empty, 
                                   wrap::fix<2, minmax10_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain79_t = container::chain<parameter::empty, 
                                   wrap::fix<2, minmax9_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain78_t = container::chain<parameter::empty, 
                                   wrap::fix<2, minmax8_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<2, minmax4_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain90_t = container::chain<parameter::empty, 
                                   wrap::fix<2, minmax13_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch8_t = container::branch<parameter::empty, 
                                    wrap::fix<2, math::add<NV>>, 
                                    chain6_t<NV>, 
                                    chain15_t<NV>, 
                                    chain89_t<NV>, 
                                    chain83_t<NV>, 
                                    chain79_t<NV>, 
                                    chain78_t<NV>, 
                                    chain43_t<NV>, 
                                    chain90_t<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, branch8_t<NV>>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::smoother<NV>>, 
                                   core::mono2stereo, 
                                   chain8_t<NV>>;

template <int NV>
using file_player4_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<1>>;
template <int NV>
using converter_t = control::converter<parameter::plain<file_player4_t<NV>, 3>, 
                                       conversion_logic::midi2freq>;
template <int NV>
using midi_t = wrap::mod<parameter::plain<converter_t<NV>, 0>, 
                         control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   chain21_t<NV>, 
                                   midi_t<NV>, 
                                   converter_t<NV>, 
                                   file_player4_t<NV>>;

using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::empty>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, project::shfiter<NV>>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain1_t>, 
                                   chain2_t<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, chain11_t<NV>>, 
                                  branch_t<NV>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain_t<NV>>, 
                                 chain3_t<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, xfader_t<NV>>, 
                                  split_t<NV>>;

namespace files_t_parameters
{
// Parameter list for files_impl::files_t ----------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(modeRange, 
                             1., 
                             2., 
                             1.);

template <int NV>
using mode = parameter::from0To1<files_impl::file_player4_t<NV>, 
                                 0, 
                                 modeRange>;

template <int NV>
using smooth = parameter::plain<core::smoother<NV>, 0>;
template <int NV>
using quant = parameter::plain<files_impl::branch8_t<NV>, 
                               0>;
template <int NV>
using Position = parameter::plain<files_impl::pma1_t<NV>, 2>;
template <int NV>
using Input = parameter::plain<files_impl::pma3_t<NV>, 2>;
template <int NV>
using Win = parameter::plain<project::shfiter<NV>, 1>;
template <int NV>
using Xf = parameter::plain<project::shfiter<NV>, 2>;
template <int NV>
using shift = parameter::plain<files_impl::branch_t<NV>, 
                               0>;
template <int NV>
using pitch = parameter::plain<files_impl::pma4_t<NV>, 2>;
template <int NV>
using Mix = parameter::plain<files_impl::xfader_t<NV>, 
                             0>;
template <int NV>
using PositionMod = parameter::plain<files_impl::pma1_t<NV>, 1>;
template <int NV>
using PitchMod = parameter::plain<files_impl::pma4_t<NV>, 1>;
template <int NV>
using InputMod = parameter::plain<files_impl::pma3_t<NV>, 1>;
template <int NV>
using files_t_plist = parameter::list<smooth<NV>, 
                                      quant<NV>, 
                                      Position<NV>, 
                                      Input<NV>, 
                                      mode<NV>, 
                                      Win<NV>, 
                                      Xf<NV>, 
                                      shift<NV>, 
                                      pitch<NV>, 
                                      Mix<NV>, 
                                      PositionMod<NV>, 
                                      PitchMod<NV>, 
                                      InputMod<NV>>;
}

template <int NV>
using files_t_ = container::chain<files_t_parameters::files_t_plist<NV>, 
                                  wrap::fix<2, split6_t<NV>>, 
                                  chain4_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public files_impl::files_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 3;
		static const int NumAudioFiles = 2;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(files);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(206)
		{
			0x005B, 0x0000, 0x7300, 0x6F6D, 0x746F, 0x0068, 0x0000, 0x0000, 
            0x0000, 0x41C0, 0x0000, 0x0000, 0xEE69, 0x3E6C, 0xCCCD, 0x3DCC, 
            0x015B, 0x0000, 0x7100, 0x6175, 0x746E, 0x0000, 0x0000, 0x0000, 
            0x0000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0002, 0x0000, 0x6F50, 0x6973, 0x6974, 0x6E6F, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0003, 0x0000, 0x6E49, 0x7570, 0x0074, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x1643, 0x3F35, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x045B, 0x0000, 0x6D00, 0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 
            0x0000, 0x5700, 0x6E69, 0x0000, 0x4800, 0x0042, 0x1C40, 0x0046, 
            0x9B40, 0x0045, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0006, 0x0000, 
            0x6658, 0x0000, 0x8000, 0x003F, 0x1C40, 0x0046, 0x3980, 0x0045, 
            0x8000, 0x003F, 0x8000, 0x5B3F, 0x0007, 0x0000, 0x6873, 0x6669, 
            0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x085B, 0x0000, 0x7000, 0x7469, 0x6863, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x2B3F, 0x0031, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0009, 0x0000, 0x694D, 0x0078, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0A5B, 0x0000, 0x5000, 0x736F, 0x7469, 0x6F69, 0x4D6E, 
            0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x000B, 0x0000, 0x6950, 0x6374, 
            0x4D68, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000C, 0x0000, 0x6E49, 
            0x7570, 0x4D74, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& split6 = this->getT(0);                                                  // files_impl::split6_t<NV>
		auto& modchain = this->getT(0).getT(0);                                        // files_impl::modchain_t<NV>
		auto& sliderbank3 = this->getT(0).getT(0).getT(0);                             // files_impl::sliderbank3_t<NV>
		auto& split1 = this->getT(0).getT(0).getT(1);                                  // files_impl::split1_t<NV>
		auto& chain39 = this->getT(0).getT(0).getT(1).getT(0);                         // files_impl::chain39_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(1).getT(0).getT(0);           // files_impl::global_cable3_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                    // math::add<NV>
		auto& gain13 = this->getT(0).getT(0).getT(1).getT(0).getT(2);                  // core::gain<NV>
		auto& chain41 = this->getT(0).getT(0).getT(1).getT(1);                         // files_impl::chain41_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(1).getT(1).getT(0);          // files_impl::global_cable11_t<NV>
		auto& add26 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                   // math::add<NV>
		auto& gain15 = this->getT(0).getT(0).getT(1).getT(1).getT(2);                  // core::gain<NV>
		auto& chain40 = this->getT(0).getT(0).getT(1).getT(2);                         // files_impl::chain40_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(1).getT(2).getT(0);          // files_impl::global_cable10_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                    // math::add<NV>
		auto& gain14 = this->getT(0).getT(0).getT(1).getT(2).getT(2);                  // core::gain<NV>
		auto& chain42 = this->getT(0).getT(0).getT(1).getT(3);                         // files_impl::chain42_t<NV>
		auto& event_data_reader3 = this->getT(0).getT(0).getT(1).getT(3).getT(0);      // files_impl::event_data_reader3_t<NV>
		auto& add27 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                   // math::add<NV>
		auto& gain16 = this->getT(0).getT(0).getT(1).getT(3).getT(2);                  // core::gain<NV>
		auto& chain44 = this->getT(0).getT(0).getT(1).getT(4);                         // files_impl::chain44_t<NV>
		auto& event_data_reader11 = this->getT(0).getT(0).getT(1).getT(4).getT(0);     // files_impl::event_data_reader11_t<NV>
		auto& add29 = this->getT(0).getT(0).getT(1).getT(4).getT(1);                   // math::add<NV>
		auto& gain32 = this->getT(0).getT(0).getT(1).getT(4).getT(2);                  // core::gain<NV>
		auto& chain45 = this->getT(0).getT(0).getT(1).getT(5);                         // files_impl::chain45_t<NV>
		auto& event_data_reader10 = this->getT(0).getT(0).getT(1).getT(5).getT(0);     // files_impl::event_data_reader10_t<NV>
		auto& add28 = this->getT(0).getT(0).getT(1).getT(5).getT(1);                   // math::add<NV>
		auto& gain26 = this->getT(0).getT(0).getT(1).getT(5).getT(2);                  // core::gain<NV>
		auto& chain46 = this->getT(0).getT(0).getT(1).getT(6);                         // files_impl::chain46_t<NV>
		auto& midi1 = this->getT(0).getT(0).getT(1).getT(6).getT(0);                   // files_impl::midi1_t<NV>
		auto& add30 = this->getT(0).getT(0).getT(1).getT(6).getT(1);                   // math::add<NV>
		auto& gain33 = this->getT(0).getT(0).getT(1).getT(6).getT(2);                  // core::gain<NV>
		auto& chain47 = this->getT(0).getT(0).getT(1).getT(7);                         // files_impl::chain47_t<NV>
		auto& midi_cc3 = this->getT(0).getT(0).getT(1).getT(7).getT(0);                // files_impl::midi_cc3_t<NV>
		auto& add31 = this->getT(0).getT(0).getT(1).getT(7).getT(1);                   // math::add<NV>
		auto& gain34 = this->getT(0).getT(0).getT(1).getT(7).getT(2);                  // core::gain<NV>
		auto& peak3 = this->getT(0).getT(0).getT(2);                                   // files_impl::peak3_t<NV>
		auto& pma1 = this->getT(0).getT(0).getT(3);                                    // files_impl::pma1_t<NV>
		auto& modchain4 = this->getT(0).getT(1);                                       // files_impl::modchain4_t<NV>
		auto& sliderbank7 = this->getT(0).getT(1).getT(0);                             // files_impl::sliderbank7_t<NV>
		auto& split3 = this->getT(0).getT(1).getT(1);                                  // files_impl::split3_t<NV>
		auto& chain72 = this->getT(0).getT(1).getT(1).getT(0);                         // files_impl::chain72_t<NV>
		auto& global_cable5 = this->getT(0).getT(1).getT(1).getT(0).getT(0);           // files_impl::global_cable5_t<NV>
		auto& add8 = this->getT(0).getT(1).getT(1).getT(0).getT(1);                    // math::add<NV>
		auto& gain21 = this->getT(0).getT(1).getT(1).getT(0).getT(2);                  // core::gain<NV>
		auto& chain73 = this->getT(0).getT(1).getT(1).getT(1);                         // files_impl::chain73_t<NV>
		auto& global_cable20 = this->getT(0).getT(1).getT(1).getT(1).getT(0);          // files_impl::global_cable20_t<NV>
		auto& add54 = this->getT(0).getT(1).getT(1).getT(1).getT(1);                   // math::add<NV>
		auto& gain22 = this->getT(0).getT(1).getT(1).getT(1).getT(2);                  // core::gain<NV>
		auto& chain74 = this->getT(0).getT(1).getT(1).getT(2);                         // files_impl::chain74_t<NV>
		auto& global_cable21 = this->getT(0).getT(1).getT(1).getT(2).getT(0);          // files_impl::global_cable21_t<NV>
		auto& add9 = this->getT(0).getT(1).getT(1).getT(2).getT(1);                    // math::add<NV>
		auto& gain23 = this->getT(0).getT(1).getT(1).getT(2).getT(2);                  // core::gain<NV>
		auto& chain75 = this->getT(0).getT(1).getT(1).getT(3);                         // files_impl::chain75_t<NV>
		auto& event_data_reader5 = this->getT(0).getT(1).getT(1).getT(3).getT(0);      // files_impl::event_data_reader5_t<NV>
		auto& add55 = this->getT(0).getT(1).getT(1).getT(3).getT(1);                   // math::add<NV>
		auto& gain24 = this->getT(0).getT(1).getT(1).getT(3).getT(2);                  // core::gain<NV>
		auto& chain76 = this->getT(0).getT(1).getT(1).getT(4);                         // files_impl::chain76_t<NV>
		auto& event_data_reader20 = this->getT(0).getT(1).getT(1).getT(4).getT(0);     // files_impl::event_data_reader20_t<NV>
		auto& add56 = this->getT(0).getT(1).getT(1).getT(4).getT(1);                   // math::add<NV>
		auto& gain54 = this->getT(0).getT(1).getT(1).getT(4).getT(2);                  // core::gain<NV>
		auto& chain77 = this->getT(0).getT(1).getT(1).getT(5);                         // files_impl::chain77_t<NV>
		auto& event_data_reader21 = this->getT(0).getT(1).getT(1).getT(5).getT(0);     // files_impl::event_data_reader21_t<NV>
		auto& add57 = this->getT(0).getT(1).getT(1).getT(5).getT(1);                   // math::add<NV>
		auto& gain28 = this->getT(0).getT(1).getT(1).getT(5).getT(2);                  // core::gain<NV>
		auto& chain80 = this->getT(0).getT(1).getT(1).getT(6);                         // files_impl::chain80_t<NV>
		auto& midi3 = this->getT(0).getT(1).getT(1).getT(6).getT(0);                   // files_impl::midi3_t<NV>
		auto& add58 = this->getT(0).getT(1).getT(1).getT(6).getT(1);                   // math::add<NV>
		auto& gain55 = this->getT(0).getT(1).getT(1).getT(6).getT(2);                  // core::gain<NV>
		auto& chain81 = this->getT(0).getT(1).getT(1).getT(7);                         // files_impl::chain81_t<NV>
		auto& midi_cc7 = this->getT(0).getT(1).getT(1).getT(7).getT(0);                // files_impl::midi_cc7_t<NV>
		auto& add59 = this->getT(0).getT(1).getT(1).getT(7).getT(1);                   // math::add<NV>
		auto& gain56 = this->getT(0).getT(1).getT(1).getT(7).getT(2);                  // core::gain<NV>
		auto& peak7 = this->getT(0).getT(1).getT(2);                                   // files_impl::peak7_t<NV>
		auto& pma4 = this->getT(0).getT(1).getT(3);                                    // files_impl::pma4_t<NV>
		auto& modchain3 = this->getT(0).getT(2);                                       // files_impl::modchain3_t<NV>
		auto& sliderbank6 = this->getT(0).getT(2).getT(0);                             // files_impl::sliderbank6_t<NV>
		auto& split2 = this->getT(0).getT(2).getT(1);                                  // files_impl::split2_t<NV>
		auto& chain64 = this->getT(0).getT(2).getT(1).getT(0);                         // files_impl::chain64_t<NV>
		auto& global_cable4 = this->getT(0).getT(2).getT(1).getT(0).getT(0);           // files_impl::global_cable4_t<NV>
		auto& add6 = this->getT(0).getT(2).getT(1).getT(0).getT(1);                    // math::add<NV>
		auto& gain17 = this->getT(0).getT(2).getT(1).getT(0).getT(2);                  // core::gain<NV>
		auto& chain65 = this->getT(0).getT(2).getT(1).getT(1);                         // files_impl::chain65_t<NV>
		auto& global_cable12 = this->getT(0).getT(2).getT(1).getT(1).getT(0);          // files_impl::global_cable12_t<NV>
		auto& add48 = this->getT(0).getT(2).getT(1).getT(1).getT(1);                   // math::add<NV>
		auto& gain18 = this->getT(0).getT(2).getT(1).getT(1).getT(2);                  // core::gain<NV>
		auto& chain66 = this->getT(0).getT(2).getT(1).getT(2);                         // files_impl::chain66_t<NV>
		auto& global_cable19 = this->getT(0).getT(2).getT(1).getT(2).getT(0);          // files_impl::global_cable19_t<NV>
		auto& add7 = this->getT(0).getT(2).getT(1).getT(2).getT(1);                    // math::add<NV>
		auto& gain19 = this->getT(0).getT(2).getT(1).getT(2).getT(2);                  // core::gain<NV>
		auto& chain67 = this->getT(0).getT(2).getT(1).getT(3);                         // files_impl::chain67_t<NV>
		auto& event_data_reader4 = this->getT(0).getT(2).getT(1).getT(3).getT(0);      // files_impl::event_data_reader4_t<NV>
		auto& add49 = this->getT(0).getT(2).getT(1).getT(3).getT(1);                   // math::add<NV>
		auto& gain20 = this->getT(0).getT(2).getT(1).getT(3).getT(2);                  // core::gain<NV>
		auto& chain68 = this->getT(0).getT(2).getT(1).getT(4);                         // files_impl::chain68_t<NV>
		auto& event_data_reader12 = this->getT(0).getT(2).getT(1).getT(4).getT(0);     // files_impl::event_data_reader12_t<NV>
		auto& add50 = this->getT(0).getT(2).getT(1).getT(4).getT(1);                   // math::add<NV>
		auto& gain51 = this->getT(0).getT(2).getT(1).getT(4).getT(2);                  // core::gain<NV>
		auto& chain69 = this->getT(0).getT(2).getT(1).getT(5);                         // files_impl::chain69_t<NV>
		auto& event_data_reader19 = this->getT(0).getT(2).getT(1).getT(5).getT(0);     // files_impl::event_data_reader19_t<NV>
		auto& add51 = this->getT(0).getT(2).getT(1).getT(5).getT(1);                   // math::add<NV>
		auto& gain27 = this->getT(0).getT(2).getT(1).getT(5).getT(2);                  // core::gain<NV>
		auto& chain70 = this->getT(0).getT(2).getT(1).getT(6);                         // files_impl::chain70_t<NV>
		auto& midi2 = this->getT(0).getT(2).getT(1).getT(6).getT(0);                   // files_impl::midi2_t<NV>
		auto& add52 = this->getT(0).getT(2).getT(1).getT(6).getT(1);                   // math::add<NV>
		auto& gain52 = this->getT(0).getT(2).getT(1).getT(6).getT(2);                  // core::gain<NV>
		auto& chain71 = this->getT(0).getT(2).getT(1).getT(7);                         // files_impl::chain71_t<NV>
		auto& midi_cc6 = this->getT(0).getT(2).getT(1).getT(7).getT(0);                // files_impl::midi_cc6_t<NV>
		auto& add53 = this->getT(0).getT(2).getT(1).getT(7).getT(1);                   // math::add<NV>
		auto& gain53 = this->getT(0).getT(2).getT(1).getT(7).getT(2);                  // core::gain<NV>
		auto& peak6 = this->getT(0).getT(2).getT(2);                                   // files_impl::peak6_t<NV>
		auto& pma3 = this->getT(0).getT(2).getT(3);                                    // files_impl::pma3_t<NV>
		auto& chain4 = this->getT(1);                                                  // files_impl::chain4_t<NV>
		auto& xfader = this->getT(1).getT(0);                                          // files_impl::xfader_t<NV>
		auto& split = this->getT(1).getT(1);                                           // files_impl::split_t<NV>
		auto& chain = this->getT(1).getT(1).getT(0);                                   // files_impl::chain_t<NV>
		auto& gain1 = this->getT(1).getT(1).getT(0).getT(0);                           // core::gain<NV>
		auto& chain3 = this->getT(1).getT(1).getT(1);                                  // files_impl::chain3_t<NV>
		auto& chain11 = this->getT(1).getT(1).getT(1).getT(0);                         // files_impl::chain11_t<NV>
		auto& gain3 = this->getT(1).getT(1).getT(1).getT(0).getT(0);                   // core::gain<NV>
		auto& chain21 = this->getT(1).getT(1).getT(1).getT(0).getT(1);                 // files_impl::chain21_t<NV>
		auto& smoother10 = this->getT(1).getT(1).getT(1).getT(0).getT(1).getT(0);      // core::smoother<NV>
		auto& mono2stereo = this->getT(1).getT(1).getT(1).getT(0).getT(1).getT(1);     // core::mono2stereo
		auto& chain8 = this->getT(1).getT(1).getT(1).getT(0).getT(1).getT(2);          // files_impl::chain8_t<NV>
		auto& branch8 = this->getT(1).getT(1).getT(1).getT(0).getT(1).getT(2).getT(0); // files_impl::branch8_t<NV>
		auto& add1 = this->getT(1).getT(1).getT(1).getT(0).                            // math::add<NV>
                     getT(1).getT(2).getT(0).getT(0);
		auto& chain6 = this->getT(1).getT(1).getT(1).getT(0).                // files_impl::chain6_t<NV>
                       getT(1).getT(2).getT(0).getT(1);
		auto& minmax3 = this->getT(1).getT(1).getT(1).getT(0).               // files_impl::minmax3_t<NV>
                        getT(1).getT(2).getT(0).getT(1).
                        getT(0);
		auto& add125 = this->getT(1).getT(1).getT(1).getT(0).                // math::add<NV>
                       getT(1).getT(2).getT(0).getT(1).
                       getT(1);
		auto& chain15 = this->getT(1).getT(1).getT(1).getT(0).               // files_impl::chain15_t<NV>
                        getT(1).getT(2).getT(0).getT(2);
		auto& minmax5 = this->getT(1).getT(1).getT(1).getT(0).               // files_impl::minmax5_t<NV>
                        getT(1).getT(2).getT(0).getT(2).
                        getT(0);
		auto& add131 = this->getT(1).getT(1).getT(1).getT(0).                // math::add<NV>
                       getT(1).getT(2).getT(0).getT(2).
                       getT(1);
		auto& chain89 = this->getT(1).getT(1).getT(1).getT(0).               // files_impl::chain89_t<NV>
                        getT(1).getT(2).getT(0).getT(3);
		auto& minmax12 = this->getT(1).getT(1).getT(1).getT(0).              // files_impl::minmax12_t<NV>
                         getT(1).getT(2).getT(0).getT(3).
                         getT(0);
		auto& add126 = this->getT(1).getT(1).getT(1).getT(0).                // math::add<NV>
                       getT(1).getT(2).getT(0).getT(3).
                       getT(1);
		auto& chain83 = this->getT(1).getT(1).getT(1).getT(0).               // files_impl::chain83_t<NV>
                        getT(1).getT(2).getT(0).getT(4);
		auto& minmax10 = this->getT(1).getT(1).getT(1).getT(0).              // files_impl::minmax10_t<NV>
                         getT(1).getT(2).getT(0).getT(4).
                         getT(0);
		auto& add127 = this->getT(1).getT(1).getT(1).getT(0).                // math::add<NV>
                       getT(1).getT(2).getT(0).getT(4).
                       getT(1);
		auto& chain79 = this->getT(1).getT(1).getT(1).getT(0).               // files_impl::chain79_t<NV>
                        getT(1).getT(2).getT(0).getT(5);
		auto& minmax9 = this->getT(1).getT(1).getT(1).getT(0).               // files_impl::minmax9_t<NV>
                        getT(1).getT(2).getT(0).getT(5).
                        getT(0);
		auto& add128 = this->getT(1).getT(1).getT(1).getT(0).                // math::add<NV>
                       getT(1).getT(2).getT(0).getT(5).
                       getT(1);
		auto& chain78 = this->getT(1).getT(1).getT(1).getT(0).               // files_impl::chain78_t<NV>
                        getT(1).getT(2).getT(0).getT(6);
		auto& minmax8 = this->getT(1).getT(1).getT(1).getT(0).               // files_impl::minmax8_t<NV>
                        getT(1).getT(2).getT(0).getT(6).
                        getT(0);
		auto& add129 = this->getT(1).getT(1).getT(1).getT(0).                // math::add<NV>
                       getT(1).getT(2).getT(0).getT(6).
                       getT(1);
		auto& chain43 = this->getT(1).getT(1).getT(1).getT(0).               // files_impl::chain43_t<NV>
                        getT(1).getT(2).getT(0).getT(7);
		auto& minmax4 = this->getT(1).getT(1).getT(1).getT(0).               // files_impl::minmax4_t<NV>
                        getT(1).getT(2).getT(0).getT(7).
                        getT(0);
		auto& add130 = this->getT(1).getT(1).getT(1).getT(0).                // math::add<NV>
                       getT(1).getT(2).getT(0).getT(7).
                       getT(1);
		auto& chain90 = this->getT(1).getT(1).getT(1).getT(0).               // files_impl::chain90_t<NV>
                        getT(1).getT(2).getT(0).getT(8);
		auto& minmax13 = this->getT(1).getT(1).getT(1).getT(0).              // files_impl::minmax13_t<NV>
                         getT(1).getT(2).getT(0).getT(8).
                         getT(0);
		auto& add3 = this->getT(1).getT(1).getT(1).getT(0).                  // math::add<NV>
                     getT(1).getT(2).getT(0).getT(8).
                     getT(1);
		auto& midi = this->getT(1).getT(1).getT(1).getT(0).getT(2);          // files_impl::midi_t<NV>
		auto& converter = this->getT(1).getT(1).getT(1).getT(0).getT(3);     // files_impl::converter_t<NV>
		auto& file_player4 = this->getT(1).getT(1).getT(1).getT(0).getT(4);  // files_impl::file_player4_t<NV>
		auto& branch = this->getT(1).getT(1).getT(1).getT(1);                // files_impl::branch_t<NV>
		auto& chain1 = this->getT(1).getT(1).getT(1).getT(1).getT(0);        // files_impl::chain1_t
		auto& chain2 = this->getT(1).getT(1).getT(1).getT(1).getT(1);        // files_impl::chain2_t<NV>
		auto& faust = this->getT(1).getT(1).getT(1).getT(1).getT(1).getT(0); // project::shfiter<NV>
		auto& gain2 = this->getT(1).getT(1).getT(1).getT(2);                 // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, smoother10); // smooth -> smoother10::SmoothingTime
		
		this->getParameterT(1).connectT(0, branch8); // quant -> branch8::Index
		
		this->getParameterT(2).connectT(0, pma1); // Position -> pma1::Add
		
		this->getParameterT(3).connectT(0, pma3); // Input -> pma3::Add
		
		this->getParameterT(4).connectT(0, file_player4); // mode -> file_player4::PlaybackMode
		
		this->getParameterT(5).connectT(0, faust); // Win -> faust::windowsamples
		
		this->getParameterT(6).connectT(0, faust); // Xf -> faust::xfadesamples
		
		this->getParameterT(7).connectT(0, branch); // shift -> branch::Index
		
		this->getParameterT(8).connectT(0, pma4); // pitch -> pma4::Add
		
		this->getParameterT(9).connectT(0, xfader); // Mix -> xfader::Value
		
		this->getParameterT(10).connectT(0, pma1); // PositionMod -> pma1::Multiply
		
		this->getParameterT(11).connectT(0, pma4); // PitchMod -> pma4::Multiply
		
		this->getParameterT(12).connectT(0, pma3); // InputMod -> pma3::Multiply
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& sliderbank3_p = sliderbank3.getWrappedObject().getParameter();
		sliderbank3_p.getParameterT(0).connectT(0, gain13);                  // sliderbank3 -> gain13::Gain
		sliderbank3_p.getParameterT(1).connectT(0, gain15);                  // sliderbank3 -> gain15::Gain
		sliderbank3_p.getParameterT(2).connectT(0, gain14);                  // sliderbank3 -> gain14::Gain
		sliderbank3_p.getParameterT(3).connectT(0, gain16);                  // sliderbank3 -> gain16::Gain
		sliderbank3_p.getParameterT(4).connectT(0, gain32);                  // sliderbank3 -> gain32::Gain
		sliderbank3_p.getParameterT(5).connectT(0, gain26);                  // sliderbank3 -> gain26::Gain
		sliderbank3_p.getParameterT(6).connectT(0, gain33);                  // sliderbank3 -> gain33::Gain
		sliderbank3_p.getParameterT(7).connectT(0, gain34);                  // sliderbank3 -> gain34::Gain
		global_cable3.getWrappedObject().getParameter().connectT(0, add4);   // global_cable3 -> add4::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add26); // global_cable11 -> add26::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, add5);  // global_cable10 -> add5::Value
		event_data_reader3.getParameter().connectT(0, add27);                // event_data_reader3 -> add27::Value
		event_data_reader11.getParameter().connectT(0, add29);               // event_data_reader11 -> add29::Value
		event_data_reader10.getParameter().connectT(0, add28);               // event_data_reader10 -> add28::Value
		midi1.getParameter().connectT(0, add30);                             // midi1 -> add30::Value
		midi_cc3.getWrappedObject().getParameter().connectT(0, add31);       // midi_cc3 -> add31::Value
		minmax3.getWrappedObject().getParameter().connectT(0, add125);       // minmax3 -> add125::Value
		minmax5.getWrappedObject().getParameter().connectT(0, add131);       // minmax5 -> add131::Value
		minmax12.getWrappedObject().getParameter().connectT(0, add126);      // minmax12 -> add126::Value
		minmax10.getWrappedObject().getParameter().connectT(0, add127);      // minmax10 -> add127::Value
		minmax9.getWrappedObject().getParameter().connectT(0, add128);       // minmax9 -> add128::Value
		minmax8.getWrappedObject().getParameter().connectT(0, add129);       // minmax8 -> add129::Value
		minmax4.getWrappedObject().getParameter().connectT(0, add130);       // minmax4 -> add130::Value
		minmax13.getWrappedObject().getParameter().connectT(0, add3);        // minmax13 -> add3::Value
		pma1.getWrappedObject().getParameter().connectT(0, add1);            // pma1 -> add1::Value
		pma1.getWrappedObject().getParameter().connectT(1, minmax3);         // pma1 -> minmax3::Value
		pma1.getWrappedObject().getParameter().connectT(2, minmax5);         // pma1 -> minmax5::Value
		pma1.getWrappedObject().getParameter().connectT(3, minmax12);        // pma1 -> minmax12::Value
		pma1.getWrappedObject().getParameter().connectT(4, minmax10);        // pma1 -> minmax10::Value
		pma1.getWrappedObject().getParameter().connectT(5, minmax9);         // pma1 -> minmax9::Value
		pma1.getWrappedObject().getParameter().connectT(6, minmax8);         // pma1 -> minmax8::Value
		pma1.getWrappedObject().getParameter().connectT(7, minmax4);         // pma1 -> minmax4::Value
		pma1.getWrappedObject().getParameter().connectT(8, minmax13);        // pma1 -> minmax13::Value
		peak3.getParameter().connectT(0, pma1);                              // peak3 -> pma1::Value
		auto& sliderbank7_p = sliderbank7.getWrappedObject().getParameter();
		sliderbank7_p.getParameterT(0).connectT(0, gain21);                  // sliderbank7 -> gain21::Gain
		sliderbank7_p.getParameterT(1).connectT(0, gain22);                  // sliderbank7 -> gain22::Gain
		sliderbank7_p.getParameterT(2).connectT(0, gain23);                  // sliderbank7 -> gain23::Gain
		sliderbank7_p.getParameterT(3).connectT(0, gain24);                  // sliderbank7 -> gain24::Gain
		sliderbank7_p.getParameterT(4).connectT(0, gain54);                  // sliderbank7 -> gain54::Gain
		sliderbank7_p.getParameterT(5).connectT(0, gain28);                  // sliderbank7 -> gain28::Gain
		sliderbank7_p.getParameterT(6).connectT(0, gain55);                  // sliderbank7 -> gain55::Gain
		sliderbank7_p.getParameterT(7).connectT(0, gain56);                  // sliderbank7 -> gain56::Gain
		global_cable5.getWrappedObject().getParameter().connectT(0, add8);   // global_cable5 -> add8::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add54); // global_cable20 -> add54::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add9);  // global_cable21 -> add9::Value
		event_data_reader5.getParameter().connectT(0, add55);                // event_data_reader5 -> add55::Value
		event_data_reader20.getParameter().connectT(0, add56);               // event_data_reader20 -> add56::Value
		event_data_reader21.getParameter().connectT(0, add57);               // event_data_reader21 -> add57::Value
		midi3.getParameter().connectT(0, add58);                             // midi3 -> add58::Value
		midi_cc7.getWrappedObject().getParameter().connectT(0, add59);       // midi_cc7 -> add59::Value
		pma4.getWrappedObject().getParameter().connectT(0, faust);           // pma4 -> faust::shiftsemitones
		peak7.getParameter().connectT(0, pma4);                              // peak7 -> pma4::Value
		auto& sliderbank6_p = sliderbank6.getWrappedObject().getParameter();
		sliderbank6_p.getParameterT(0).connectT(0, gain17);                  // sliderbank6 -> gain17::Gain
		sliderbank6_p.getParameterT(1).connectT(0, gain18);                  // sliderbank6 -> gain18::Gain
		sliderbank6_p.getParameterT(2).connectT(0, gain19);                  // sliderbank6 -> gain19::Gain
		sliderbank6_p.getParameterT(3).connectT(0, gain20);                  // sliderbank6 -> gain20::Gain
		sliderbank6_p.getParameterT(4).connectT(0, gain51);                  // sliderbank6 -> gain51::Gain
		sliderbank6_p.getParameterT(5).connectT(0, gain27);                  // sliderbank6 -> gain27::Gain
		sliderbank6_p.getParameterT(6).connectT(0, gain52);                  // sliderbank6 -> gain52::Gain
		sliderbank6_p.getParameterT(7).connectT(0, gain53);                  // sliderbank6 -> gain53::Gain
		global_cable4.getWrappedObject().getParameter().connectT(0, add6);   // global_cable4 -> add6::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add48); // global_cable12 -> add48::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add7);  // global_cable19 -> add7::Value
		event_data_reader4.getParameter().connectT(0, add49);                // event_data_reader4 -> add49::Value
		event_data_reader12.getParameter().connectT(0, add50);               // event_data_reader12 -> add50::Value
		event_data_reader19.getParameter().connectT(0, add51);               // event_data_reader19 -> add51::Value
		midi2.getParameter().connectT(0, add52);                             // midi2 -> add52::Value
		midi_cc6.getWrappedObject().getParameter().connectT(0, add53);       // midi_cc6 -> add53::Value
		pma3.getWrappedObject().getParameter().connectT(0, gain3);           // pma3 -> gain3::Gain
		peak6.getParameter().connectT(0, pma3);                              // peak6 -> pma3::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain1);                          // xfader -> gain1::Gain
		xfader_p.getParameterT(1).connectT(0, gain2);                          // xfader -> gain2::Gain
		converter.getWrappedObject().getParameter().connectT(0, file_player4); // converter -> file_player4::FreqRatio
		midi.getParameter().connectT(0, converter);                            // midi -> converter::Value
		
		// Default Values --------------------------------------------------------------------------
		
		sliderbank3.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add4::Value is automated
		
		;                             // gain13::Gain is automated
		gain13.setParameterT(1, 20.); // core::gain::Smoothing
		gain13.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add26::Value is automated
		
		;                             // gain15::Gain is automated
		gain15.setParameterT(1, 20.); // core::gain::Smoothing
		gain15.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		;                             // gain14::Gain is automated
		gain14.setParameterT(1, 20.); // core::gain::Smoothing
		gain14.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader3.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader3.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add27::Value is automated
		
		;                             // gain16::Gain is automated
		gain16.setParameterT(1, 20.); // core::gain::Smoothing
		gain16.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader11.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader11.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add29::Value is automated
		
		;                             // gain32::Gain is automated
		gain32.setParameterT(1, 20.); // core::gain::Smoothing
		gain32.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader10.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader10.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add28::Value is automated
		
		;                             // gain26::Gain is automated
		gain26.setParameterT(1, 20.); // core::gain::Smoothing
		gain26.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add30::Value is automated
		
		;                             // gain33::Gain is automated
		gain33.setParameterT(1, 20.); // core::gain::Smoothing
		gain33.setParameterT(2, 0.);  // core::gain::ResetValue
		
		midi_cc3.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc3.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc3.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add31::Value is automated
		
		;                             // gain34::Gain is automated
		gain34.setParameterT(1, 20.); // core::gain::Smoothing
		gain34.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		sliderbank7.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add8::Value is automated
		
		;                             // gain21::Gain is automated
		gain21.setParameterT(1, 20.); // core::gain::Smoothing
		gain21.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable20.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add54::Value is automated
		
		;                             // gain22::Gain is automated
		gain22.setParameterT(1, 20.); // core::gain::Smoothing
		gain22.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable21.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add9::Value is automated
		
		;                             // gain23::Gain is automated
		gain23.setParameterT(1, 20.); // core::gain::Smoothing
		gain23.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader5.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader5.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add55::Value is automated
		
		;                             // gain24::Gain is automated
		gain24.setParameterT(1, 20.); // core::gain::Smoothing
		gain24.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader20.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader20.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add56::Value is automated
		
		;                             // gain54::Gain is automated
		gain54.setParameterT(1, 20.); // core::gain::Smoothing
		gain54.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader21.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader21.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add57::Value is automated
		
		;                             // gain28::Gain is automated
		gain28.setParameterT(1, 20.); // core::gain::Smoothing
		gain28.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add58::Value is automated
		
		;                             // gain55::Gain is automated
		gain55.setParameterT(1, 20.); // core::gain::Smoothing
		gain55.setParameterT(2, 0.);  // core::gain::ResetValue
		
		midi_cc7.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc7.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc7.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add59::Value is automated
		
		;                             // gain56::Gain is automated
		gain56.setParameterT(1, 20.); // core::gain::Smoothing
		gain56.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma4::Value is automated
		; // pma4::Multiply is automated
		; // pma4::Add is automated
		
		sliderbank6.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add6::Value is automated
		
		;                             // gain17::Gain is automated
		gain17.setParameterT(1, 20.); // core::gain::Smoothing
		gain17.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add48::Value is automated
		
		;                             // gain18::Gain is automated
		gain18.setParameterT(1, 20.); // core::gain::Smoothing
		gain18.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable19.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add7::Value is automated
		
		;                             // gain19::Gain is automated
		gain19.setParameterT(1, 20.); // core::gain::Smoothing
		gain19.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader4.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader4.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add49::Value is automated
		
		;                             // gain20::Gain is automated
		gain20.setParameterT(1, 20.); // core::gain::Smoothing
		gain20.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader12.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader12.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add50::Value is automated
		
		;                             // gain51::Gain is automated
		gain51.setParameterT(1, 20.); // core::gain::Smoothing
		gain51.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader19.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader19.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add51::Value is automated
		
		;                             // gain27::Gain is automated
		gain27.setParameterT(1, 20.); // core::gain::Smoothing
		gain27.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add52::Value is automated
		
		;                             // gain52::Gain is automated
		gain52.setParameterT(1, 20.); // core::gain::Smoothing
		gain52.setParameterT(2, 0.);  // core::gain::ResetValue
		
		midi_cc6.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc6.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc6.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add53::Value is automated
		
		;                             // gain53::Gain is automated
		gain53.setParameterT(1, 20.); // core::gain::Smoothing
		gain53.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma3::Value is automated
		; // pma3::Multiply is automated
		; // pma3::Add is automated
		
		; // xfader::Value is automated
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                              // gain3::Gain is automated
		gain3.setParameterT(1, 12.);   // core::gain::Smoothing
		gain3.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                // smoother10::SmoothingTime is automated
		smoother10.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		; // branch8::Index is automated
		
		; // add1::Value is automated
		
		;                             // minmax3::Value is automated
		minmax3.setParameterT(1, 0.); // control::minmax::Minimum
		minmax3.setParameterT(2, 1.); // control::minmax::Maximum
		minmax3.setParameterT(3, 1.); // control::minmax::Skew
		minmax3.setParameterT(4, 0.); // control::minmax::Step
		minmax3.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add125::Value is automated
		
		;                                      // minmax5::Value is automated
		minmax5.setParameterT(1, 0.);          // control::minmax::Minimum
		minmax5.setParameterT(2, 1.);          // control::minmax::Maximum
		minmax5.setParameterT(3, 1.);          // control::minmax::Skew
		minmax5.setParameterT(4, 0.000488281); // control::minmax::Step
		minmax5.setParameterT(5, 0.);          // control::minmax::Polarity
		
		; // add131::Value is automated
		
		;                                       // minmax12::Value is automated
		minmax12.setParameterT(1, 0.);          // control::minmax::Minimum
		minmax12.setParameterT(2, 1.);          // control::minmax::Maximum
		minmax12.setParameterT(3, 1.);          // control::minmax::Skew
		minmax12.setParameterT(4, 0.000976562); // control::minmax::Step
		minmax12.setParameterT(5, 0.);          // control::minmax::Polarity
		
		; // add126::Value is automated
		
		;                                      // minmax10::Value is automated
		minmax10.setParameterT(1, 0.);         // control::minmax::Minimum
		minmax10.setParameterT(2, 1.);         // control::minmax::Maximum
		minmax10.setParameterT(3, 1.);         // control::minmax::Skew
		minmax10.setParameterT(4, 0.00195312); // control::minmax::Step
		minmax10.setParameterT(5, 0.);         // control::minmax::Polarity
		
		; // add127::Value is automated
		
		;                                     // minmax9::Value is automated
		minmax9.setParameterT(1, 0.);         // control::minmax::Minimum
		minmax9.setParameterT(2, 1.);         // control::minmax::Maximum
		minmax9.setParameterT(3, 1.);         // control::minmax::Skew
		minmax9.setParameterT(4, 0.00390625); // control::minmax::Step
		minmax9.setParameterT(5, 0.);         // control::minmax::Polarity
		
		; // add128::Value is automated
		
		;                                    // minmax8::Value is automated
		minmax8.setParameterT(1, 0.);        // control::minmax::Minimum
		minmax8.setParameterT(2, 1.);        // control::minmax::Maximum
		minmax8.setParameterT(3, 1.);        // control::minmax::Skew
		minmax8.setParameterT(4, 0.0078125); // control::minmax::Step
		minmax8.setParameterT(5, 0.);        // control::minmax::Polarity
		
		; // add129::Value is automated
		
		;                                   // minmax4::Value is automated
		minmax4.setParameterT(1, 0.);       // control::minmax::Minimum
		minmax4.setParameterT(2, 1.);       // control::minmax::Maximum
		minmax4.setParameterT(3, 1.);       // control::minmax::Skew
		minmax4.setParameterT(4, 0.015625); // control::minmax::Step
		minmax4.setParameterT(5, 0.);       // control::minmax::Polarity
		
		; // add130::Value is automated
		
		;                                   // minmax13::Value is automated
		minmax13.setParameterT(1, 0.);      // control::minmax::Minimum
		minmax13.setParameterT(2, 1.);      // control::minmax::Maximum
		minmax13.setParameterT(3, 1.);      // control::minmax::Skew
		minmax13.setParameterT(4, 0.03125); // control::minmax::Step
		minmax13.setParameterT(5, 0.);      // control::minmax::Polarity
		
		; // add3::Value is automated
		
		; // converter::Value is automated
		
		;                                       // file_player4::PlaybackMode is automated
		file_player4.setParameterT(1, 1.);      // core::file_player::Gate
		file_player4.setParameterT(2, 790.031); // core::file_player::RootFrequency
		;                                       // file_player4::FreqRatio is automated
		
		; // branch::Index is automated
		
		; // faust::shiftsemitones is automated
		; // faust::windowsamples is automated
		; // faust::xfadesamples is automated
		
		;                            // gain2::Gain is automated
		gain2.setParameterT(1, 20.); // core::gain::Smoothing
		gain2.setParameterT(2, 0.);  // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.707371);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 4968.);
		this->setParameterT(6, 2968.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 0.50075);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 0.);
		this->setParameterT(12, 0.);
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
		
		this->getT(0).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable10_t<NV>
		this->getT(0).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable5_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable20_t<NV>
		this->getT(0).getT(1).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable21_t<NV>
		this->getT(0).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable4_t<NV>
		this->getT(0).getT(2).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable12_t<NV>
		this->getT(0).getT(2).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable19_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).setExternalData(b, index);                 // files_impl::sliderbank3_t<NV>
		this->getT(0).getT(0).getT(2).setExternalData(b, index);                 // files_impl::peak3_t<NV>
		this->getT(0).getT(1).getT(0).setExternalData(b, index);                 // files_impl::sliderbank7_t<NV>
		this->getT(0).getT(1).getT(2).setExternalData(b, index);                 // files_impl::peak7_t<NV>
		this->getT(0).getT(2).getT(0).setExternalData(b, index);                 // files_impl::sliderbank6_t<NV>
		this->getT(0).getT(2).getT(2).setExternalData(b, index);                 // files_impl::peak6_t<NV>
		this->getT(1).getT(1).getT(1).getT(0).getT(4).setExternalData(b, index); // files_impl::file_player4_t<NV>
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
using files = wrap::node<files_impl::instance<NV>>;
}


