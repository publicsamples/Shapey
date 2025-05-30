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

template <int NV>
using ramp_t = wrap::no_data<core::ramp<NV, false>>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                               control::tempo_sync<NV>>;

template <int NV>
using chain113_t = container::chain<parameter::empty, 
                                    wrap::fix<1, tempo_sync_t<NV>>, 
                                    ramp_t<NV>, 
                                    math::add<NV>>;

template <int NV>
using clock_ramp_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                               wrap::no_data<core::clock_ramp<NV, false>>>;

template <int NV>
using chain114_t = container::chain<parameter::empty, 
                                    wrap::fix<1, clock_ramp_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain113_t<NV>>, 
                                    chain114_t<NV>>;

template <int NV>
using chain112_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch3_t<NV>>>;

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::table<0>>;

template <int NV>
using cable_pack_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                data::external::sliderpack<0>>;

template <int NV>
using peak2_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<cable_table_t<NV>, 0>, 
                                   parameter::plain<cable_pack_t<NV>, 0>>;

template <int NV>
using peak2_t = wrap::mod<peak2_mod<NV>, 
                          wrap::no_data<core::peak>>;
using pack_resizer_t = wrap::data<control::pack_resizer, 
                                  data::external::sliderpack<0>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, cable_table_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, cable_pack_t<NV>>, 
                                  math::add<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain7_t<NV>>, 
                                    chain9_t<NV>>;

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
using cable_table7_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<2>>;

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
                                  parameter::plain<minmax13_t<NV>, 0>, 
                                  parameter::plain<cable_table7_t, 0>>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;
template <int NV>
using peak1_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::clear<NV>>, 
                                  chain112_t<NV>, 
                                  peak2_t<NV>, 
                                  math::clear<NV>, 
                                  pack_resizer_t, 
                                  branch1_t<NV>, 
                                  peak1_t<NV>, 
                                  math::clear<NV>, 
                                  pma1_t<NV>, 
                                  cable_table7_t>;

using split4_t = container::split<parameter::empty, 
                                  wrap::fix<1, core::empty>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, chain5_t<NV>>, 
                                     split4_t>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

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
                                 data::external::sliderpack<1>>;
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
using global_cable25_t_index = runtime_target::indexers::fix_hash<2333887>;

template <int NV>
using global_cable25_t = routing::global_cable<global_cable25_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable25_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using event_data_reader11_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                        routing::event_data_reader<NV>>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader11_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader10_t = event_data_reader11_t<NV>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader10_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader13_t = event_data_reader11_t<NV>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader13_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using midi_cc10_t = control::midi_cc<parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc10_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc11_t = midi_cc10_t<NV>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc11_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc12_t = midi_cc10_t<NV>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc12_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc13_t = midi_cc10_t<NV>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc13_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using midi7_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi7_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using midi8_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi8_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using midi9_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi9_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain13_t<NV>>, 
                                    chain18_t<NV>, 
                                    chain22_t<NV>, 
                                    chain24_t<NV>, 
                                    chain25_t<NV>, 
                                    chain26_t<NV>, 
                                    chain27_t<NV>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch5_t<NV>>, 
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

using cable_table6_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<1>>;

template <int NV>
using pma2_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<pma1_t<NV>, 2>, 
                                  parameter::plain<cable_table6_t, 0>>;

template <int NV>
using pma2_t = control::pma<NV, pma2_mod<NV>>;
template <int NV>
using peak3_t = wrap::mod<parameter::plain<pma2_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;
using cable_table8_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::external::table<3>>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank3_t<NV>>, 
                                      split1_t<NV>, 
                                      peak3_t<NV>, 
                                      pma2_t<NV>, 
                                      cable_table6_t, 
                                      cable_table8_t>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

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
                                 data::external::sliderpack<2>>;
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
using global_cable26_t_index = global_cable25_t_index;

template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain75_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable26_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader20_t = event_data_reader11_t<NV>;

template <int NV>
using chain76_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader20_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader21_t = event_data_reader11_t<NV>;

template <int NV>
using chain77_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader21_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader22_t = event_data_reader11_t<NV>;

template <int NV>
using chain80_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader22_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc14_t = midi_cc10_t<NV>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc14_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc15_t = midi_cc10_t<NV>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc15_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc16_t = midi_cc10_t<NV>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc16_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc17_t = midi_cc10_t<NV>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc17_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi10_t = midi7_t<NV>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi10_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi11_t = midi8_t<NV>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi11_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi12_t = midi9_t<NV>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi12_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain14_t<NV>>, 
                                    chain19_t<NV>, 
                                    chain23_t<NV>, 
                                    chain28_t<NV>, 
                                    chain29_t<NV>, 
                                    chain30_t<NV>, 
                                    chain31_t<NV>>;

template <int NV>
using chain81_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch6_t<NV>>, 
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

DECLARE_PARAMETER_RANGE_STEP(pma4_mod_0Range, 
                             -24., 
                             24., 
                             0.1);

template <int NV>
using pma4_mod_0 = parameter::from0To1<project::shfiter<NV>, 
                                       0, 
                                       pma4_mod_0Range>;

template <int NV> using pma4_mod_1 = pma4_mod_0<NV>;

template <int NV>
using pma4_mod = parameter::chain<ranges::Identity, 
                                  pma4_mod_0<NV>, 
                                  pma4_mod_1<NV>>;

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
                                 data::external::sliderpack<3>>;
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
using global_cable27_t_index = global_cable25_t_index;

template <int NV>
using global_cable27_t = routing::global_cable<global_cable27_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable27_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader12_t = event_data_reader11_t<NV>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader12_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader19_t = event_data_reader11_t<NV>;

template <int NV>
using chain69_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader19_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::event_data_reader<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc18_t = midi_cc10_t<NV>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc18_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc19_t = midi_cc10_t<NV>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc19_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc20_t = midi_cc10_t<NV>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc20_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc21_t = midi_cc10_t<NV>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc21_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi13_t = midi7_t<NV>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi13_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi14_t = midi8_t<NV>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi14_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi15_t = midi9_t<NV>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi15_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch7_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain16_t<NV>>, 
                                    chain20_t<NV>, 
                                    chain32_t<NV>, 
                                    chain33_t<NV>, 
                                    chain34_t<NV>, 
                                    chain35_t<NV>, 
                                    chain36_t<NV>>;

template <int NV>
using chain71_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch7_t<NV>>, 
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

using chain145_t = container::chain<parameter::empty, 
                                    wrap::fix<2, core::empty>>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain145_t>, 
                                    math::clear<NV>>;

struct cable_table9_t_data
{
	span<float, 512> data =
	{
		0.988764f, 0.99064f, 0.992517f, 0.994393f, 0.996269f, 0.998146f,
		0.998933f, 0.907846f, 0.816759f, 0.725672f, 0.634585f, 0.543498f,
		0.452411f, 0.361324f, 0.270237f, 0.17915f, 0.0880626f, 0.f,
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
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f
	};
};

template <int NV>
using cable_table9_t = wrap::data<control::cable_table<parameter::plain<branch4_t<NV>, 0>>, 
                                  data::embedded::table<cable_table9_t_data>>;
DECLARE_PARAMETER_RANGE_STEP(pma3_mod_0Range, 
                             -100., 
                             24., 
                             0.1);

template <int NV>
using pma3_mod_0 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       pma3_mod_0Range>;

template <int NV>
using pma3_mod = parameter::chain<ranges::Identity, 
                                  pma3_mod_0<NV>, 
                                  parameter::plain<cable_table9_t<NV>, 0>>;

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

template <int NV> using sliderbank9_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank9_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank9_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank9_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank9_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank9_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank9_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank9_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank9_multimod = parameter::list<sliderbank9_c0<NV>, 
                                             sliderbank9_c1<NV>, 
                                             sliderbank9_c2<NV>, 
                                             sliderbank9_c3<NV>, 
                                             sliderbank9_c4<NV>, 
                                             sliderbank9_c5<NV>, 
                                             sliderbank9_c6<NV>, 
                                             sliderbank9_c7<NV>>;

template <int NV>
using sliderbank9_t = wrap::data<control::sliderbank<sliderbank9_multimod<NV>>, 
                                 data::external::sliderpack<4>>;
using global_cable7_t_index = global_cable3_t_index;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain93_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable7_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable14_t_index = global_cable11_t_index;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain94_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable23_t_index = global_cable10_t_index;

template <int NV>
using global_cable23_t = routing::global_cable<global_cable23_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain95_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable23_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable28_t_index = global_cable25_t_index;

template <int NV>
using global_cable28_t = routing::global_cable<global_cable28_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain96_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable28_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader15_t = event_data_reader11_t<NV>;

template <int NV>
using chain97_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader15_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader26_t = event_data_reader11_t<NV>;

template <int NV>
using chain98_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader26_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using chain99_t = chain70_t<NV>;

template <int NV> using midi_cc26_t = midi_cc10_t<NV>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc26_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc27_t = midi_cc10_t<NV>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc27_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc28_t = midi_cc10_t<NV>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc28_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc29_t = midi_cc10_t<NV>;

template <int NV>
using chain56_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc29_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi19_t = midi7_t<NV>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi19_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi20_t = midi8_t<NV>;

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi20_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi21_t = midi9_t<NV>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi21_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch10_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain53_t<NV>>, 
                                     chain54_t<NV>, 
                                     chain55_t<NV>, 
                                     chain56_t<NV>, 
                                     chain57_t<NV>, 
                                     chain58_t<NV>, 
                                     chain59_t<NV>>;

template <int NV>
using chain100_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch10_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain93_t<NV>>, 
                                  chain94_t<NV>, 
                                  chain95_t<NV>, 
                                  chain96_t<NV>, 
                                  chain97_t<NV>, 
                                  chain98_t<NV>, 
                                  chain99_t<NV>, 
                                  chain100_t<NV>>;

template <int NV>
using converter_mod = parameter::chain<ranges::Identity, 
                                       parameter::plain<project::shfiter<NV>, 1>, 
                                       parameter::plain<project::ps2<NV>, 1>, 
                                       parameter::plain<project::shfiter<NV>, 1>>;

template <int NV>
using converter_t = control::converter<converter_mod<NV>, 
                                       conversion_logic::ms2samples>;
template <int NV>
using tempo_sync1_t = wrap::mod<parameter::plain<converter_t<NV>, 0>, 
                                control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(cable_table2_modRange, 
                             1., 
                             16., 
                             1.);

template <int NV>
using cable_table2_mod = parameter::from0To1<tempo_sync1_t<NV>, 
                                             1, 
                                             cable_table2_modRange>;

struct cable_table2_t_data
{
	span<float, 512> data =
	{
		1.f, 0.995586f, 0.991172f, 0.986758f, 0.982344f, 0.97793f,
		0.973517f, 0.969103f, 0.964689f, 0.960275f, 0.955861f, 0.951447f,
		0.947033f, 0.942619f, 0.938205f, 0.933791f, 0.929377f, 0.924964f,
		0.92055f, 0.916136f, 0.911722f, 0.907308f, 0.902894f, 0.89848f,
		0.894066f, 0.889652f, 0.885238f, 0.880825f, 0.876411f, 0.871997f,
		0.867583f, 0.863169f, 0.858755f, 0.854341f, 0.849927f, 0.845513f,
		0.841099f, 0.836685f, 0.832272f, 0.827858f, 0.823444f, 0.81903f,
		0.814616f, 0.810202f, 0.805788f, 0.801374f, 0.79696f, 0.792546f,
		0.788132f, 0.783719f, 0.779305f, 0.774891f, 0.770477f, 0.766063f,
		0.761649f, 0.757235f, 0.752821f, 0.748407f, 0.743993f, 0.739579f,
		0.735166f, 0.730752f, 0.726338f, 0.721924f, 0.71751f, 0.713096f,
		0.708682f, 0.704268f, 0.699854f, 0.69544f, 0.691027f, 0.686613f,
		0.682199f, 0.677785f, 0.673371f, 0.668957f, 0.664543f, 0.660129f,
		0.655715f, 0.651301f, 0.646887f, 0.642474f, 0.63806f, 0.633646f,
		0.629232f, 0.624818f, 0.620404f, 0.61599f, 0.611576f, 0.607162f,
		0.602748f, 0.598334f, 0.593921f, 0.589507f, 0.585093f, 0.580679f,
		0.576265f, 0.571851f, 0.567437f, 0.563023f, 0.558609f, 0.554195f,
		0.549782f, 0.545368f, 0.540954f, 0.53654f, 0.532126f, 0.527712f,
		0.523298f, 0.518884f, 0.51447f, 0.510056f, 0.505642f, 0.501228f,
		0.496815f, 0.492401f, 0.487987f, 0.483573f, 0.479159f, 0.474745f,
		0.470331f, 0.465917f, 0.461503f, 0.457089f, 0.452676f, 0.448262f,
		0.443848f, 0.439434f, 0.43502f, 0.430606f, 0.426192f, 0.421778f,
		0.417364f, 0.41295f, 0.408536f, 0.404123f, 0.399709f, 0.395295f,
		0.390881f, 0.386467f, 0.382053f, 0.377639f, 0.373225f, 0.368811f,
		0.364397f, 0.359984f, 0.35557f, 0.351156f, 0.346742f, 0.342328f,
		0.337914f, 0.3335f, 0.329086f, 0.324672f, 0.320258f, 0.315844f,
		0.311431f, 0.307017f, 0.302603f, 0.298189f, 0.293775f, 0.289361f,
		0.284947f, 0.280533f, 0.276119f, 0.271705f, 0.267291f, 0.262877f,
		0.258464f, 0.25405f, 0.249636f, 0.245222f, 0.240808f, 0.236394f,
		0.23198f, 0.227566f, 0.223152f, 0.218738f, 0.214325f, 0.209911f,
		0.205497f, 0.201083f, 0.196669f, 0.192255f, 0.187841f, 0.183427f,
		0.179013f, 0.174599f, 0.170186f, 0.165772f, 0.161358f, 0.156944f,
		0.15253f, 0.148116f, 0.143702f, 0.139288f, 0.134874f, 0.13046f,
		0.126046f, 0.121632f, 0.117219f, 0.112805f, 0.108391f, 0.103977f,
		0.099563f, 0.0951491f, 0.0907351f, 0.0863212f, 0.0819074f, 0.0774935f,
		0.0730795f, 0.0686656f, 0.0642517f, 0.0598379f, 0.0554239f, 0.05101f,
		0.0465961f, 0.0421821f, 0.0377682f, 0.0333543f, 0.0289405f, 0.0245265f,
		0.0201126f, 0.0156987f, 0.0112848f, 0.00687093f, 0.00245696f, 0.f,
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
		0.f, 0.f
	};
};

template <int NV>
using cable_table2_t = wrap::data<control::cable_table<cable_table2_mod<NV>>, 
                                  data::embedded::table<cable_table2_t_data>>;

DECLARE_PARAMETER_RANGE_STEP(cable_table3_modRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using cable_table3_mod = parameter::from0To1<tempo_sync1_t<NV>, 
                                             0, 
                                             cable_table3_modRange>;

struct cable_table3_t_data
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
		0.f, 0.00143951f, 0.00483602f, 0.00823247f, 0.0116289f, 0.0150254f,
		0.0184219f, 0.0218183f, 0.0252148f, 0.0286112f, 0.0320077f, 0.0354041f,
		0.0388006f, 0.042197f, 0.0455936f, 0.04899f, 0.0523865f, 0.0557829f,
		0.0591794f, 0.0625759f, 0.0659723f, 0.0693688f, 0.0727653f, 0.0761617f,
		0.0795582f, 0.0829546f, 0.0863512f, 0.0897476f, 0.0931441f, 0.0965405f,
		0.099937f, 0.103333f, 0.10673f, 0.110126f, 0.113523f, 0.116919f,
		0.120316f, 0.123712f, 0.127109f, 0.130505f, 0.133902f, 0.137298f,
		0.140694f, 0.144091f, 0.147488f, 0.150884f, 0.15428f, 0.157677f,
		0.161073f, 0.16447f, 0.167866f, 0.171263f, 0.174659f, 0.178056f,
		0.181452f, 0.184849f, 0.188245f, 0.191642f, 0.195038f, 0.198434f,
		0.201831f, 0.205227f, 0.208624f, 0.21202f, 0.215417f, 0.218813f,
		0.22221f, 0.225606f, 0.229003f, 0.232399f, 0.235796f, 0.239192f,
		0.242588f, 0.245985f, 0.249381f, 0.252778f, 0.256174f, 0.259571f,
		0.262967f, 0.266364f, 0.26976f, 0.273157f, 0.276553f, 0.27995f,
		0.283346f, 0.286743f, 0.290139f, 0.293535f, 0.296932f, 0.300328f,
		0.303725f, 0.307121f, 0.310518f, 0.313914f, 0.317311f, 0.320707f,
		0.324104f, 0.3275f, 0.330896f, 0.334293f, 0.33769f, 0.341086f,
		0.344482f, 0.347879f, 0.351275f, 0.354672f, 0.358068f, 0.361465f,
		0.364861f, 0.368258f, 0.371654f, 0.375051f, 0.378447f, 0.381844f,
		0.38524f, 0.388636f, 0.392033f, 0.395429f, 0.398826f, 0.402222f,
		0.405619f, 0.409015f, 0.412412f, 0.415808f, 0.419205f, 0.422601f,
		0.425998f, 0.429394f, 0.43279f, 0.436187f, 0.439583f, 0.44298f,
		0.446376f, 0.449773f, 0.453169f, 0.456566f, 0.459962f, 0.463359f,
		0.466755f, 0.470152f, 0.473548f, 0.476945f, 0.480341f, 0.483737f,
		0.487134f, 0.49053f, 0.493927f, 0.497323f, 0.50072f, 0.504116f,
		0.507513f, 0.510909f, 0.514306f, 0.517702f, 0.521098f, 0.524495f,
		0.527892f, 0.531288f, 0.534684f, 0.538081f, 0.541477f, 0.544874f,
		0.54827f, 0.551667f, 0.555063f, 0.55846f, 0.561856f, 0.565253f,
		0.568649f, 0.572046f, 0.575442f, 0.578838f, 0.582235f, 0.585631f,
		0.589028f, 0.592424f, 0.595821f, 0.599217f, 0.602614f, 0.60601f,
		0.609407f, 0.612803f, 0.6162f, 0.619596f, 0.622992f, 0.626389f,
		0.629785f, 0.633182f, 0.636578f, 0.639975f, 0.643371f, 0.646768f,
		0.650164f, 0.653561f, 0.656957f, 0.660354f, 0.66375f, 0.667147f,
		0.670543f, 0.673939f, 0.677336f, 0.680732f, 0.684129f, 0.687525f,
		0.690922f, 0.694318f, 0.697715f, 0.701111f, 0.704508f, 0.707904f,
		0.7113f, 0.714697f, 0.718094f, 0.72149f, 0.724886f, 0.728283f,
		0.731679f, 0.735076f, 0.738472f, 0.741869f, 0.745265f, 0.748662f,
		0.752058f, 0.755455f, 0.758851f, 0.762248f, 0.765644f, 0.76904f,
		0.772437f, 0.775833f, 0.77923f, 0.782626f, 0.786023f, 0.789419f,
		0.792816f, 0.796212f, 0.799609f, 0.803005f, 0.806402f, 0.809798f,
		0.813195f, 0.816591f, 0.819987f, 0.823384f, 0.82678f, 0.830177f,
		0.833573f, 0.83697f, 0.840366f, 0.843763f, 0.847159f, 0.850556f,
		0.853952f, 0.857349f, 0.860745f, 0.864141f, 0.867538f, 0.870934f,
		0.874331f, 0.877727f, 0.881124f, 0.88452f, 0.887917f, 0.891313f,
		0.89471f, 0.898106f, 0.901503f, 0.904899f, 0.908296f, 0.911692f,
		0.915088f, 0.918485f, 0.921881f, 0.925278f, 0.928674f, 0.932071f,
		0.935467f, 0.938864f, 0.94226f, 0.945657f, 0.949053f, 0.95245f,
		0.955846f, 0.959242f, 0.962639f, 0.966035f, 0.969432f, 0.972828f,
		0.976225f, 0.979621f, 0.983018f, 0.986414f, 0.989811f, 0.993207f,
		0.996604f, 1.f
	};
};

template <int NV>
using cable_table3_t = wrap::data<control::cable_table<cable_table3_mod<NV>>, 
                                  data::embedded::table<cable_table3_t_data>>;

template <int NV>
using pma7_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_table2_t<NV>, 0>, 
                                  parameter::plain<cable_table3_t<NV>, 0>>;

template <int NV>
using pma7_t = control::pma<NV, pma7_mod<NV>>;

DECLARE_PARAMETER_RANGE_STEP(pma10_modRange, 
                             0., 
                             1000., 
                             0.1);

template <int NV>
using pma10_mod = parameter::from0To1<tempo_sync1_t<NV>, 
                                      3, 
                                      pma10_modRange>;

template <int NV>
using pma10_t = control::pma<NV, pma10_mod<NV>>;

template <int NV>
using peak9_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma7_t<NV>, 0>, 
                                   parameter::plain<pma10_t<NV>, 0>>;

template <int NV>
using peak9_t = wrap::mod<peak9_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using split14_t = container::split<parameter::empty, 
                                   wrap::fix<1, peak9_t<NV>>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<1, pma10_t<NV>>, 
                                  pma7_t<NV>>;

template <int NV>
using modchain6_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank9_t<NV>>, 
                                      split8_t<NV>, 
                                      split14_t<NV>, 
                                      split9_t<NV>>;

template <int NV>
using modchain6_t = wrap::control_rate<modchain6_t_<NV>>;

template <int NV> using sliderbank8_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank8_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank8_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank8_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank8_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank8_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank8_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank8_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank8_multimod = parameter::list<sliderbank8_c0<NV>, 
                                             sliderbank8_c1<NV>, 
                                             sliderbank8_c2<NV>, 
                                             sliderbank8_c3<NV>, 
                                             sliderbank8_c4<NV>, 
                                             sliderbank8_c5<NV>, 
                                             sliderbank8_c6<NV>, 
                                             sliderbank8_c7<NV>>;

template <int NV>
using sliderbank8_t = wrap::data<control::sliderbank<sliderbank8_multimod<NV>>, 
                                 data::external::sliderpack<5>>;
using global_cable6_t_index = global_cable3_t_index;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain82_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable6_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable13_t_index = global_cable11_t_index;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain84_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable22_t_index = global_cable10_t_index;

template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain85_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable22_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable29_t_index = global_cable25_t_index;

template <int NV>
using global_cable29_t = routing::global_cable<global_cable29_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain86_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable29_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader14_t = event_data_reader11_t<NV>;

template <int NV>
using chain87_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader14_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader24_t = event_data_reader11_t<NV>;

template <int NV>
using chain88_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader24_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using chain91_t = chain70_t<NV>;

template <int NV> using midi_cc22_t = midi_cc10_t<NV>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc22_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc23_t = midi_cc10_t<NV>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc23_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc24_t = midi_cc10_t<NV>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc24_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc25_t = midi_cc10_t<NV>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc25_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi16_t = midi7_t<NV>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi16_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi17_t = midi8_t<NV>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi17_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi18_t = midi9_t<NV>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi18_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch9_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain37_t<NV>>, 
                                    chain38_t<NV>, 
                                    chain48_t<NV>, 
                                    chain49_t<NV>, 
                                    chain50_t<NV>, 
                                    chain51_t<NV>, 
                                    chain52_t<NV>>;

template <int NV>
using chain92_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch9_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain82_t<NV>>, 
                                  chain84_t<NV>, 
                                  chain85_t<NV>, 
                                  chain86_t<NV>, 
                                  chain87_t<NV>, 
                                  chain88_t<NV>, 
                                  chain91_t<NV>, 
                                  chain92_t<NV>>;

template <int NV>
using converter1_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<project::ps2<NV>, 2>, 
                                        parameter::plain<project::shfiter<NV>, 2>, 
                                        parameter::plain<project::shfiter<NV>, 2>>;

template <int NV>
using converter1_t = control::converter<converter1_mod<NV>, 
                                        conversion_logic::ms2samples>;
template <int NV>
using tempo_sync3_t = wrap::mod<parameter::plain<converter1_t<NV>, 0>, 
                                control::tempo_sync<NV>>;
template <int NV>
using cable_table4_mod = parameter::from0To1<tempo_sync3_t<NV>, 
                                             1, 
                                             cable_table2_modRange>;

struct cable_table4_t_data
{
	span<float, 512> data =
	{
		1.f, 0.995586f, 0.991172f, 0.986758f, 0.982344f, 0.97793f,
		0.973517f, 0.969103f, 0.964689f, 0.960275f, 0.955861f, 0.951447f,
		0.947033f, 0.942619f, 0.938205f, 0.933791f, 0.929377f, 0.924964f,
		0.92055f, 0.916136f, 0.911722f, 0.907308f, 0.902894f, 0.89848f,
		0.894066f, 0.889652f, 0.885238f, 0.880825f, 0.876411f, 0.871997f,
		0.867583f, 0.863169f, 0.858755f, 0.854341f, 0.849927f, 0.845513f,
		0.841099f, 0.836685f, 0.832272f, 0.827858f, 0.823444f, 0.81903f,
		0.814616f, 0.810202f, 0.805788f, 0.801374f, 0.79696f, 0.792546f,
		0.788132f, 0.783719f, 0.779305f, 0.774891f, 0.770477f, 0.766063f,
		0.761649f, 0.757235f, 0.752821f, 0.748407f, 0.743993f, 0.739579f,
		0.735166f, 0.730752f, 0.726338f, 0.721924f, 0.71751f, 0.713096f,
		0.708682f, 0.704268f, 0.699854f, 0.69544f, 0.691027f, 0.686613f,
		0.682199f, 0.677785f, 0.673371f, 0.668957f, 0.664543f, 0.660129f,
		0.655715f, 0.651301f, 0.646887f, 0.642474f, 0.63806f, 0.633646f,
		0.629232f, 0.624818f, 0.620404f, 0.61599f, 0.611576f, 0.607162f,
		0.602748f, 0.598334f, 0.593921f, 0.589507f, 0.585093f, 0.580679f,
		0.576265f, 0.571851f, 0.567437f, 0.563023f, 0.558609f, 0.554195f,
		0.549782f, 0.545368f, 0.540954f, 0.53654f, 0.532126f, 0.527712f,
		0.523298f, 0.518884f, 0.51447f, 0.510056f, 0.505642f, 0.501228f,
		0.496815f, 0.492401f, 0.487987f, 0.483573f, 0.479159f, 0.474745f,
		0.470331f, 0.465917f, 0.461503f, 0.457089f, 0.452676f, 0.448262f,
		0.443848f, 0.439434f, 0.43502f, 0.430606f, 0.426192f, 0.421778f,
		0.417364f, 0.41295f, 0.408536f, 0.404123f, 0.399709f, 0.395295f,
		0.390881f, 0.386467f, 0.382053f, 0.377639f, 0.373225f, 0.368811f,
		0.364397f, 0.359984f, 0.35557f, 0.351156f, 0.346742f, 0.342328f,
		0.337914f, 0.3335f, 0.329086f, 0.324672f, 0.320258f, 0.315844f,
		0.311431f, 0.307017f, 0.302603f, 0.298189f, 0.293775f, 0.289361f,
		0.284947f, 0.280533f, 0.276119f, 0.271705f, 0.267291f, 0.262877f,
		0.258464f, 0.25405f, 0.249636f, 0.245222f, 0.240808f, 0.236394f,
		0.23198f, 0.227566f, 0.223152f, 0.218738f, 0.214325f, 0.209911f,
		0.205497f, 0.201083f, 0.196669f, 0.192255f, 0.187841f, 0.183427f,
		0.179013f, 0.174599f, 0.170186f, 0.165772f, 0.161358f, 0.156944f,
		0.15253f, 0.148116f, 0.143702f, 0.139288f, 0.134874f, 0.13046f,
		0.126046f, 0.121632f, 0.117219f, 0.112805f, 0.108391f, 0.103977f,
		0.099563f, 0.0951491f, 0.0907351f, 0.0863212f, 0.0819074f, 0.0774935f,
		0.0730795f, 0.0686656f, 0.0642517f, 0.0598379f, 0.0554239f, 0.05101f,
		0.0465961f, 0.0421821f, 0.0377682f, 0.0333543f, 0.0289405f, 0.0245265f,
		0.0201126f, 0.0156987f, 0.0112848f, 0.00687093f, 0.00245696f, 0.f,
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
		0.f, 0.f
	};
};

template <int NV>
using cable_table4_t = wrap::data<control::cable_table<cable_table4_mod<NV>>, 
                                  data::embedded::table<cable_table4_t_data>>;

template <int NV>
using cable_table5_mod = parameter::from0To1<tempo_sync3_t<NV>, 
                                             0, 
                                             cable_table3_modRange>;

struct cable_table5_t_data
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
		0.f, 0.00143951f, 0.00483602f, 0.00823247f, 0.0116289f, 0.0150254f,
		0.0184219f, 0.0218183f, 0.0252148f, 0.0286112f, 0.0320077f, 0.0354041f,
		0.0388006f, 0.042197f, 0.0455936f, 0.04899f, 0.0523865f, 0.0557829f,
		0.0591794f, 0.0625759f, 0.0659723f, 0.0693688f, 0.0727653f, 0.0761617f,
		0.0795582f, 0.0829546f, 0.0863512f, 0.0897476f, 0.0931441f, 0.0965405f,
		0.099937f, 0.103333f, 0.10673f, 0.110126f, 0.113523f, 0.116919f,
		0.120316f, 0.123712f, 0.127109f, 0.130505f, 0.133902f, 0.137298f,
		0.140694f, 0.144091f, 0.147488f, 0.150884f, 0.15428f, 0.157677f,
		0.161073f, 0.16447f, 0.167866f, 0.171263f, 0.174659f, 0.178056f,
		0.181452f, 0.184849f, 0.188245f, 0.191642f, 0.195038f, 0.198434f,
		0.201831f, 0.205227f, 0.208624f, 0.21202f, 0.215417f, 0.218813f,
		0.22221f, 0.225606f, 0.229003f, 0.232399f, 0.235796f, 0.239192f,
		0.242588f, 0.245985f, 0.249381f, 0.252778f, 0.256174f, 0.259571f,
		0.262967f, 0.266364f, 0.26976f, 0.273157f, 0.276553f, 0.27995f,
		0.283346f, 0.286743f, 0.290139f, 0.293535f, 0.296932f, 0.300328f,
		0.303725f, 0.307121f, 0.310518f, 0.313914f, 0.317311f, 0.320707f,
		0.324104f, 0.3275f, 0.330896f, 0.334293f, 0.33769f, 0.341086f,
		0.344482f, 0.347879f, 0.351275f, 0.354672f, 0.358068f, 0.361465f,
		0.364861f, 0.368258f, 0.371654f, 0.375051f, 0.378447f, 0.381844f,
		0.38524f, 0.388636f, 0.392033f, 0.395429f, 0.398826f, 0.402222f,
		0.405619f, 0.409015f, 0.412412f, 0.415808f, 0.419205f, 0.422601f,
		0.425998f, 0.429394f, 0.43279f, 0.436187f, 0.439583f, 0.44298f,
		0.446376f, 0.449773f, 0.453169f, 0.456566f, 0.459962f, 0.463359f,
		0.466755f, 0.470152f, 0.473548f, 0.476945f, 0.480341f, 0.483737f,
		0.487134f, 0.49053f, 0.493927f, 0.497323f, 0.50072f, 0.504116f,
		0.507513f, 0.510909f, 0.514306f, 0.517702f, 0.521098f, 0.524495f,
		0.527892f, 0.531288f, 0.534684f, 0.538081f, 0.541477f, 0.544874f,
		0.54827f, 0.551667f, 0.555063f, 0.55846f, 0.561856f, 0.565253f,
		0.568649f, 0.572046f, 0.575442f, 0.578838f, 0.582235f, 0.585631f,
		0.589028f, 0.592424f, 0.595821f, 0.599217f, 0.602614f, 0.60601f,
		0.609407f, 0.612803f, 0.6162f, 0.619596f, 0.622992f, 0.626389f,
		0.629785f, 0.633182f, 0.636578f, 0.639975f, 0.643371f, 0.646768f,
		0.650164f, 0.653561f, 0.656957f, 0.660354f, 0.66375f, 0.667147f,
		0.670543f, 0.673939f, 0.677336f, 0.680732f, 0.684129f, 0.687525f,
		0.690922f, 0.694318f, 0.697715f, 0.701111f, 0.704508f, 0.707904f,
		0.7113f, 0.714697f, 0.718094f, 0.72149f, 0.724886f, 0.728283f,
		0.731679f, 0.735076f, 0.738472f, 0.741869f, 0.745265f, 0.748662f,
		0.752058f, 0.755455f, 0.758851f, 0.762248f, 0.765644f, 0.76904f,
		0.772437f, 0.775833f, 0.77923f, 0.782626f, 0.786023f, 0.789419f,
		0.792816f, 0.796212f, 0.799609f, 0.803005f, 0.806402f, 0.809798f,
		0.813195f, 0.816591f, 0.819987f, 0.823384f, 0.82678f, 0.830177f,
		0.833573f, 0.83697f, 0.840366f, 0.843763f, 0.847159f, 0.850556f,
		0.853952f, 0.857349f, 0.860745f, 0.864141f, 0.867538f, 0.870934f,
		0.874331f, 0.877727f, 0.881124f, 0.88452f, 0.887917f, 0.891313f,
		0.89471f, 0.898106f, 0.901503f, 0.904899f, 0.908296f, 0.911692f,
		0.915088f, 0.918485f, 0.921881f, 0.925278f, 0.928674f, 0.932071f,
		0.935467f, 0.938864f, 0.94226f, 0.945657f, 0.949053f, 0.95245f,
		0.955846f, 0.959242f, 0.962639f, 0.966035f, 0.969432f, 0.972828f,
		0.976225f, 0.979621f, 0.983018f, 0.986414f, 0.989811f, 0.993207f,
		0.996604f, 1.f
	};
};

template <int NV>
using cable_table5_t = wrap::data<control::cable_table<cable_table5_mod<NV>>, 
                                  data::embedded::table<cable_table5_t_data>>;

template <int NV>
using pma9_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<cable_table4_t<NV>, 0>, 
                                  parameter::plain<cable_table5_t<NV>, 0>>;

template <int NV>
using pma9_t = control::pma<NV, pma9_mod<NV>>;

template <int NV>
using pma11_mod = parameter::from0To1<tempo_sync3_t<NV>, 
                                      3, 
                                      pma10_modRange>;

template <int NV>
using pma11_t = control::pma<NV, pma11_mod<NV>>;

template <int NV>
using peak8_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma9_t<NV>, 0>, 
                                   parameter::plain<pma11_t<NV>, 0>>;

template <int NV>
using peak8_t = wrap::mod<peak8_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using split13_t = container::split<parameter::empty, 
                                   wrap::fix<1, peak8_t<NV>>>;

template <int NV>
using split10_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma11_t<NV>>, 
                                   pma9_t<NV>>;

template <int NV>
using modchain5_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank8_t<NV>>, 
                                      split7_t<NV>, 
                                      split13_t<NV>, 
                                      split10_t<NV>>;

template <int NV>
using modchain5_t = wrap::control_rate<modchain5_t_<NV>>;

template <int NV> using sliderbank10_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank10_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank10_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank10_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank10_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank10_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank10_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank10_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank10_multimod = parameter::list<sliderbank10_c0<NV>, 
                                              sliderbank10_c1<NV>, 
                                              sliderbank10_c2<NV>, 
                                              sliderbank10_c3<NV>, 
                                              sliderbank10_c4<NV>, 
                                              sliderbank10_c5<NV>, 
                                              sliderbank10_c6<NV>, 
                                              sliderbank10_c7<NV>>;

template <int NV>
using sliderbank10_t = wrap::data<control::sliderbank<sliderbank10_multimod<NV>>, 
                                  data::external::sliderpack<6>>;
using global_cable8_t_index = global_cable3_t_index;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain101_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable8_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable15_t_index = global_cable11_t_index;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain102_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable15_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable24_t_index = global_cable10_t_index;

template <int NV>
using global_cable24_t = routing::global_cable<global_cable24_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain103_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable24_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable30_t_index = global_cable25_t_index;

template <int NV>
using global_cable30_t = routing::global_cable<global_cable30_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain104_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable30_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader16_t = event_data_reader11_t<NV>;

template <int NV>
using chain105_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader16_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader28_t = event_data_reader11_t<NV>;

template <int NV>
using chain106_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader28_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain107_t = chain70_t<NV>;

template <int NV> using midi_cc30_t = midi_cc10_t<NV>;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc30_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc31_t = midi_cc10_t<NV>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc31_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc32_t = midi_cc10_t<NV>;

template <int NV>
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc32_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc33_t = midi_cc10_t<NV>;

template <int NV>
using chain63_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc33_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi22_t = midi7_t<NV>;

template <int NV>
using chain109_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi22_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi23_t = midi8_t<NV>;

template <int NV>
using chain110_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi23_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi24_t = midi9_t<NV>;

template <int NV>
using chain111_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi24_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch11_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain60_t<NV>>, 
                                     chain61_t<NV>, 
                                     chain62_t<NV>, 
                                     chain63_t<NV>, 
                                     chain109_t<NV>, 
                                     chain110_t<NV>, 
                                     chain111_t<NV>>;

template <int NV>
using chain108_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch11_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split15_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain101_t<NV>>, 
                                   chain102_t<NV>, 
                                   chain103_t<NV>, 
                                   chain104_t<NV>, 
                                   chain105_t<NV>, 
                                   chain106_t<NV>, 
                                   chain107_t<NV>, 
                                   chain108_t<NV>>;

template <int NV>
using pma12_mod_0 = parameter::from0To1<tempo_sync_t<NV>, 
                                        0, 
                                        cable_table3_modRange>;

template <int NV>
using pma12_mod_1 = parameter::from0To1<clock_ramp_t<NV>, 
                                        0, 
                                        cable_table3_modRange>;

template <int NV>
using pma12_mod = parameter::chain<ranges::Identity, 
                                   pma12_mod_0<NV>, 
                                   pma12_mod_1<NV>>;

template <int NV>
using pma12_t = control::pma<NV, pma12_mod<NV>>;
template <int NV>
using peak10_t = wrap::mod<parameter::plain<pma12_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using split16_t = container::split<parameter::empty, 
                                   wrap::fix<1, peak10_t<NV>>>;

template <int NV>
using split17_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma12_t<NV>>>;

template <int NV>
using modchain7_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank10_t<NV>>, 
                                      split15_t<NV>, 
                                      split16_t<NV>, 
                                      split17_t<NV>>;

template <int NV>
using modchain7_t = wrap::control_rate<modchain7_t_<NV>>;

template <int NV> using sliderbank11_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank11_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank11_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank11_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank11_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank11_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank11_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank11_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank11_multimod = parameter::list<sliderbank11_c0<NV>, 
                                              sliderbank11_c1<NV>, 
                                              sliderbank11_c2<NV>, 
                                              sliderbank11_c3<NV>, 
                                              sliderbank11_c4<NV>, 
                                              sliderbank11_c5<NV>, 
                                              sliderbank11_c6<NV>, 
                                              sliderbank11_c7<NV>>;

template <int NV>
using sliderbank11_t = wrap::data<control::sliderbank<sliderbank11_multimod<NV>>, 
                                  data::external::sliderpack<7>>;
using global_cable9_t_index = global_cable3_t_index;

template <int NV>
using global_cable9_t = routing::global_cable<global_cable9_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain115_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable9_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable16_t_index = global_cable11_t_index;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain116_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable16_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable31_t_index = global_cable10_t_index;

template <int NV>
using global_cable31_t = routing::global_cable<global_cable31_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain117_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable31_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable32_t_index = global_cable25_t_index;

template <int NV>
using global_cable32_t = routing::global_cable<global_cable32_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain118_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable32_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader17_t = event_data_reader11_t<NV>;

template <int NV>
using chain119_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader17_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader30_t = event_data_reader11_t<NV>;

template <int NV>
using chain120_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader30_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain121_t = chain70_t<NV>;

template <int NV> using midi_cc34_t = midi_cc10_t<NV>;

template <int NV>
using chain123_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc34_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc35_t = midi_cc10_t<NV>;

template <int NV>
using chain124_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc35_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc36_t = midi_cc10_t<NV>;

template <int NV>
using chain125_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc36_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc37_t = midi_cc10_t<NV>;

template <int NV>
using chain126_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc37_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi25_t = midi7_t<NV>;

template <int NV>
using chain127_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi25_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi26_t = midi8_t<NV>;

template <int NV>
using chain128_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi26_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi27_t = midi9_t<NV>;

template <int NV>
using chain129_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi27_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch12_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain123_t<NV>>, 
                                     chain124_t<NV>, 
                                     chain125_t<NV>, 
                                     chain126_t<NV>, 
                                     chain127_t<NV>, 
                                     chain128_t<NV>, 
                                     chain129_t<NV>>;

template <int NV>
using chain122_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch12_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split18_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain115_t<NV>>, 
                                   chain116_t<NV>, 
                                   chain117_t<NV>, 
                                   chain118_t<NV>, 
                                   chain119_t<NV>, 
                                   chain120_t<NV>, 
                                   chain121_t<NV>, 
                                   chain122_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(pma14_modRange, 
                             0., 
                             2000., 
                             0.231378);

template <int NV>
using pma14_mod = parameter::from0To1<core::smoother<NV>, 
                                      0, 
                                      pma14_modRange>;

template <int NV>
using pma14_t = control::pma<NV, pma14_mod<NV>>;
template <int NV>
using peak11_t = wrap::mod<parameter::plain<pma14_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using split19_t = container::split<parameter::empty, 
                                   wrap::fix<1, peak11_t<NV>>>;

template <int NV>
using split20_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma14_t<NV>>>;

template <int NV>
using modchain8_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank11_t<NV>>, 
                                      split18_t<NV>, 
                                      split19_t<NV>, 
                                      split20_t<NV>>;

template <int NV>
using modchain8_t = wrap::control_rate<modchain8_t_<NV>>;

template <int NV> using sliderbank12_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank12_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank12_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank12_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank12_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank12_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank12_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank12_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank12_multimod = parameter::list<sliderbank12_c0<NV>, 
                                              sliderbank12_c1<NV>, 
                                              sliderbank12_c2<NV>, 
                                              sliderbank12_c3<NV>, 
                                              sliderbank12_c4<NV>, 
                                              sliderbank12_c5<NV>, 
                                              sliderbank12_c6<NV>, 
                                              sliderbank12_c7<NV>>;

template <int NV>
using sliderbank12_t = wrap::data<control::sliderbank<sliderbank12_multimod<NV>>, 
                                  data::external::sliderpack<8>>;
using global_cable17_t_index = global_cable3_t_index;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain130_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable17_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable18_t_index = global_cable11_t_index;

template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain131_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable18_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable33_t_index = global_cable10_t_index;

template <int NV>
using global_cable33_t = routing::global_cable<global_cable33_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain132_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable33_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable34_t_index = global_cable25_t_index;

template <int NV>
using global_cable34_t = routing::global_cable<global_cable34_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain133_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable34_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader18_t = event_data_reader11_t<NV>;

template <int NV>
using chain134_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader18_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader32_t = event_data_reader11_t<NV>;

template <int NV>
using chain135_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader32_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using chain136_t = chain70_t<NV>;

template <int NV> using midi_cc38_t = midi_cc10_t<NV>;

template <int NV>
using chain138_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc38_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc39_t = midi_cc10_t<NV>;

template <int NV>
using chain139_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc39_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc40_t = midi_cc10_t<NV>;

template <int NV>
using chain140_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc40_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc41_t = midi_cc10_t<NV>;

template <int NV>
using chain141_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc41_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi28_t = midi7_t<NV>;

template <int NV>
using chain142_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi28_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi29_t = midi8_t<NV>;

template <int NV>
using chain143_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi29_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi30_t = midi9_t<NV>;

template <int NV>
using chain144_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi30_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch13_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain138_t<NV>>, 
                                     chain139_t<NV>, 
                                     chain140_t<NV>, 
                                     chain141_t<NV>, 
                                     chain142_t<NV>, 
                                     chain143_t<NV>, 
                                     chain144_t<NV>>;

template <int NV>
using chain137_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch13_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split21_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain130_t<NV>>, 
                                   chain131_t<NV>, 
                                   chain132_t<NV>, 
                                   chain133_t<NV>, 
                                   chain134_t<NV>, 
                                   chain135_t<NV>, 
                                   chain136_t<NV>, 
                                   chain137_t<NV>>;

template <int NV> using xfader_c0 = sliderbank3_c0<NV>;

template <int NV> using xfader_c1 = sliderbank3_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::rms>;
template <int NV>
using pma15_t = control::pma<NV, 
                             parameter::plain<xfader_t<NV>, 0>>;
template <int NV>
using peak12_t = wrap::mod<parameter::plain<pma15_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using split22_t = container::split<parameter::empty, 
                                   wrap::fix<1, peak12_t<NV>>>;

template <int NV>
using split23_t = container::split<parameter::empty, 
                                   wrap::fix<1, pma15_t<NV>>>;

template <int NV>
using modchain9_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank12_t<NV>>, 
                                      split21_t<NV>, 
                                      split22_t<NV>, 
                                      split23_t<NV>>;

template <int NV>
using modchain9_t = wrap::control_rate<modchain9_t_<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<2, modchain_t<NV>>, 
                                  modchain2_t<NV>, 
                                  modchain4_t<NV>, 
                                  modchain3_t<NV>, 
                                  modchain6_t<NV>, 
                                  modchain5_t<NV>, 
                                  modchain7_t<NV>, 
                                  modchain8_t<NV>, 
                                  modchain9_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, core::gain<NV>>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, minmax3_t<NV>>, 
                                  math::add<NV>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, minmax5_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain89_t = container::chain<parameter::empty, 
                                   wrap::fix<1, minmax12_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain83_t = container::chain<parameter::empty, 
                                   wrap::fix<1, minmax10_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain79_t = container::chain<parameter::empty, 
                                   wrap::fix<1, minmax9_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain78_t = container::chain<parameter::empty, 
                                   wrap::fix<1, minmax8_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, minmax4_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain90_t = container::chain<parameter::empty, 
                                   wrap::fix<1, minmax13_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch8_t = container::branch<parameter::empty, 
                                    wrap::fix<1, math::add<NV>>, 
                                    chain6_t<NV>, 
                                    chain15_t<NV>, 
                                    chain89_t<NV>, 
                                    chain83_t<NV>, 
                                    chain79_t<NV>, 
                                    chain78_t<NV>, 
                                    chain43_t<NV>, 
                                    chain90_t<NV>>;

template <int NV>
using peak_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, branch8_t<NV>>, 
                                      peak_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, modchain1_t<NV>>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<2, wrap::no_process<core::mono2stereo>>, 
                                   chain8_t<NV>>;
using oscilloscope_t = wrap::no_data<analyse::oscilloscope>;
template <int NV>
using file_player4_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<1>>;
template <int NV>
using file_player5_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<0>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, file_player4_t<NV>>, 
                                    file_player5_t<NV>>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<2, cable_table2_t<NV>>, 
                                   cable_table3_t<NV>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split11_t<NV>>, 
                                   tempo_sync1_t<NV>, 
                                   converter_t<NV>>;

template <int NV>
using split12_t = container::split<parameter::empty, 
                                   wrap::fix<2, cable_table4_t<NV>>, 
                                   cable_table5_t<NV>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split12_t<NV>>, 
                                   tempo_sync3_t<NV>, 
                                   converter1_t<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain12_t<NV>>, 
                                  chain17_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, wrap::no_process<math::tanh<NV>>>>;
using stereo_cable = cable::block<2>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, routing::receive<stereo_cable>>, 
                                  project::shfiter<NV>, 
                                  routing::send<stereo_cable>>;

DECLARE_PARAMETER_RANGE_STEP(cable_table1_modRange, 
                             -64., 
                             64., 
                             1.);

template <int NV>
using cable_table1_mod = parameter::from0To1<project::ps2<NV>, 
                                             0, 
                                             cable_table1_modRange>;

struct cable_table1_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00211084f, 0.00422174f, 0.00633258f, 0.00844347f, 0.0105543f,
		0.0126652f, 0.0147761f, 0.0168869f, 0.0189978f, 0.0211086f, 0.0232195f,
		0.0253304f, 0.0274413f, 0.0295521f, 0.0316629f, 0.0337738f, 0.0358847f,
		0.0379956f, 0.0401064f, 0.0422173f, 0.0443282f, 0.046439f, 0.0485499f,
		0.0506607f, 0.0527716f, 0.0548825f, 0.0569934f, 0.0591042f, 0.061215f,
		0.0633259f, 0.0654368f, 0.0675477f, 0.0696585f, 0.0717694f, 0.0738803f,
		0.0759911f, 0.078102f, 0.0802128f, 0.0823237f, 0.0844346f, 0.0865455f,
		0.0886563f, 0.0907671f, 0.092878f, 0.0949889f, 0.0970998f, 0.0992106f,
		0.101321f, 0.103432f, 0.105543f, 0.107654f, 0.109765f, 0.111876f,
		0.113987f, 0.116098f, 0.118208f, 0.120319f, 0.12243f, 0.124541f,
		0.126652f, 0.128763f, 0.130874f, 0.132984f, 0.135095f, 0.137206f,
		0.139317f, 0.141428f, 0.143539f, 0.14565f, 0.147761f, 0.149871f,
		0.151982f, 0.154093f, 0.156204f, 0.158315f, 0.160426f, 0.162537f,
		0.164647f, 0.166758f, 0.168869f, 0.17098f, 0.173091f, 0.175202f,
		0.177313f, 0.179423f, 0.181534f, 0.183645f, 0.185756f, 0.187867f,
		0.189978f, 0.192089f, 0.1942f, 0.19631f, 0.198421f, 0.200532f,
		0.202643f, 0.204754f, 0.206865f, 0.208976f, 0.211086f, 0.213197f,
		0.215308f, 0.217419f, 0.21953f, 0.221641f, 0.223752f, 0.225863f,
		0.227973f, 0.230084f, 0.232195f, 0.234306f, 0.236417f, 0.238528f,
		0.240638f, 0.242749f, 0.24486f, 0.246971f, 0.249082f, 0.251193f,
		0.253304f, 0.255415f, 0.257525f, 0.259636f, 0.261747f, 0.263858f,
		0.265969f, 0.26808f, 0.270191f, 0.272301f, 0.274412f, 0.276523f,
		0.278634f, 0.280745f, 0.282856f, 0.284967f, 0.287078f, 0.289188f,
		0.291299f, 0.29341f, 0.295521f, 0.297632f, 0.299743f, 0.301854f,
		0.303992f, 0.306199f, 0.308407f, 0.310614f, 0.312821f, 0.315029f,
		0.317236f, 0.319444f, 0.321651f, 0.323859f, 0.326066f, 0.328273f,
		0.330481f, 0.332688f, 0.334896f, 0.337103f, 0.339311f, 0.341518f,
		0.343726f, 0.345933f, 0.34814f, 0.350348f, 0.352555f, 0.354763f,
		0.35697f, 0.359178f, 0.361385f, 0.363593f, 0.3658f, 0.368007f,
		0.370215f, 0.372422f, 0.37463f, 0.376837f, 0.379045f, 0.381252f,
		0.383459f, 0.385667f, 0.387874f, 0.390082f, 0.392289f, 0.394497f,
		0.396704f, 0.398912f, 0.401119f, 0.403326f, 0.405534f, 0.407741f,
		0.409949f, 0.412156f, 0.414364f, 0.416445f, 0.418321f, 0.420198f,
		0.422074f, 0.42395f, 0.425827f, 0.427703f, 0.429579f, 0.431456f,
		0.433332f, 0.435208f, 0.437085f, 0.438961f, 0.440837f, 0.442713f,
		0.44459f, 0.446466f, 0.448342f, 0.450219f, 0.452095f, 0.453971f,
		0.455848f, 0.457724f, 0.4596f, 0.461477f, 0.463353f, 0.465229f,
		0.467106f, 0.468982f, 0.470858f, 0.472735f, 0.474611f, 0.476487f,
		0.478364f, 0.48024f, 0.482116f, 0.483993f, 0.485869f, 0.487745f,
		0.489622f, 0.491498f, 0.493374f, 0.495251f, 0.497127f, 0.499003f,
		0.50088f, 0.502756f, 0.504632f, 0.506508f, 0.508385f, 0.510261f,
		0.512137f, 0.514014f, 0.51589f, 0.517766f, 0.519643f, 0.521519f,
		0.523395f, 0.525272f, 0.527148f, 0.529024f, 0.530901f, 0.532777f,
		0.534653f, 0.53653f, 0.538406f, 0.540282f, 0.542159f, 0.544035f,
		0.545911f, 0.547788f, 0.549664f, 0.55154f, 0.553417f, 0.555293f,
		0.557169f, 0.559046f, 0.560922f, 0.562798f, 0.564674f, 0.566551f,
		0.568427f, 0.570303f, 0.57218f, 0.574056f, 0.575932f, 0.577809f,
		0.579685f, 0.581561f, 0.583438f, 0.585314f, 0.58719f, 0.589067f,
		0.590943f, 0.592819f, 0.594696f, 0.596595f, 0.598511f, 0.600427f,
		0.602343f, 0.60426f, 0.606176f, 0.608092f, 0.610008f, 0.611925f,
		0.613841f, 0.615757f, 0.617673f, 0.61959f, 0.621506f, 0.623422f,
		0.625338f, 0.627255f, 0.629171f, 0.631087f, 0.633003f, 0.63492f,
		0.636836f, 0.638752f, 0.640668f, 0.642585f, 0.644501f, 0.646417f,
		0.648333f, 0.65025f, 0.652166f, 0.654082f, 0.655998f, 0.657915f,
		0.659831f, 0.661747f, 0.663663f, 0.66558f, 0.667496f, 0.669412f,
		0.671328f, 0.673244f, 0.675161f, 0.677077f, 0.678993f, 0.68091f,
		0.682826f, 0.684742f, 0.686705f, 0.688691f, 0.690678f, 0.692665f,
		0.694652f, 0.696638f, 0.698625f, 0.700612f, 0.702598f, 0.704585f,
		0.706572f, 0.708558f, 0.710545f, 0.712532f, 0.714518f, 0.716505f,
		0.718492f, 0.720479f, 0.722465f, 0.724452f, 0.726439f, 0.728425f,
		0.730412f, 0.732399f, 0.734385f, 0.736372f, 0.738359f, 0.740346f,
		0.742332f, 0.744319f, 0.746306f, 0.748292f, 0.750279f, 0.752266f,
		0.754252f, 0.756239f, 0.758226f, 0.760213f, 0.762199f, 0.764186f,
		0.766173f, 0.768159f, 0.770146f, 0.772133f, 0.774119f, 0.776106f,
		0.778093f, 0.780079f, 0.782066f, 0.784053f, 0.78604f, 0.787992f,
		0.789934f, 0.791875f, 0.793817f, 0.795759f, 0.7977f, 0.799642f,
		0.801584f, 0.803526f, 0.805467f, 0.807409f, 0.809351f, 0.811292f,
		0.813234f, 0.81516f, 0.817041f, 0.818923f, 0.820804f, 0.822686f,
		0.824567f, 0.826448f, 0.82833f, 0.830211f, 0.832093f, 0.833974f,
		0.835855f, 0.837737f, 0.839618f, 0.8415f, 0.843351f, 0.845174f,
		0.846997f, 0.84882f, 0.850643f, 0.852466f, 0.854289f, 0.856112f,
		0.857935f, 0.859758f, 0.861582f, 0.863405f, 0.865228f, 0.867051f,
		0.868874f, 0.870667f, 0.872433f, 0.8742f, 0.875967f, 0.877733f,
		0.8795f, 0.881266f, 0.883033f, 0.8848f, 0.886566f, 0.888333f,
		0.890099f, 0.891866f, 0.893633f, 0.895399f, 0.897149f, 0.898861f,
		0.900573f, 0.902285f, 0.903996f, 0.905708f, 0.90742f, 0.909132f,
		0.910844f, 0.912556f, 0.914268f, 0.91598f, 0.917692f, 0.919403f,
		0.921115f, 0.922827f, 0.924494f, 0.926153f, 0.927812f, 0.929471f,
		0.93113f, 0.932789f, 0.934447f, 0.936106f, 0.937765f, 0.939424f,
		0.941083f, 0.942742f, 0.944401f, 0.946059f, 0.947718f, 0.94937f,
		0.950977f, 0.952585f, 0.954192f, 0.9558f, 0.957407f, 0.959015f,
		0.960622f, 0.962229f, 0.963837f, 0.965444f, 0.967052f, 0.968659f,
		0.970267f, 0.971874f, 0.973481f, 0.975079f, 0.976637f, 0.978194f,
		0.979752f, 0.98131f, 0.982867f, 0.984425f, 0.985982f, 0.98754f,
		0.989097f, 0.990655f, 0.992212f, 0.99377f, 0.995327f, 0.996885f,
		0.998442f, 1.f
	};
};

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<cable_table1_mod<NV>>, 
                                  data::embedded::table<cable_table1_t_data>>;
template <int NV>
using midi4_t = wrap::mod<parameter::plain<cable_table1_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<2, midi4_t<NV>>, 
                                   cable_table1_t<NV>, 
                                   project::ps2<NV>, 
                                   project::shfiter<NV>, 
                                   routing::receive<stereo_cable>, 
                                   routing::send<stereo_cable>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain1_t<NV>>, 
                                   chain2_t<NV>, 
                                   chain10_t<NV>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain21_t<NV>>, 
                                   oscilloscope_t, 
                                   core::smoother<NV>, 
                                   math::add<NV>, 
                                   branch2_t<NV>, 
                                   split5_t<NV>, 
                                   branch_t<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<2, cable_table9_t<NV>>, 
                                  branch4_t<NV>, 
                                  core::gain<NV>, 
                                  chain11_t<NV>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain_t<NV>>, 
                                 chain3_t<NV>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, xfader_t<NV>>, 
                                  split_t<NV>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, split6_t<NV>>, 
                                       chain4_t<NV>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

namespace files_t_parameters
{
// Parameter list for files_impl::files_t ----------------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(smooth_InputRange, 
                             0., 
                             2000., 
                             0.231378);

template <int NV>
using smooth = parameter::chain<smooth_InputRange, 
                                parameter::plain<files_impl::pma14_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(quant_InputRange, 
                             1., 
                             9., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(quant_0Range, 
                             0., 
                             8., 
                             1.);

template <int NV>
using quant_0 = parameter::from0To1<files_impl::branch8_t<NV>, 
                                    0, 
                                    quant_0Range>;

template <int NV>
using quant = parameter::chain<quant_InputRange, quant_0<NV>>;

template <int NV>
using Position = parameter::chain<ranges::Identity, 
                                  parameter::plain<files_impl::pma2_t<NV>, 2>, 
                                  parameter::plain<files_impl::cable_table8_t, 0>>;

DECLARE_PARAMETER_RANGE(Win_InputRange, 
                        0., 
                        1000.);

template <int NV>
using Win = parameter::chain<Win_InputRange, 
                             parameter::plain<files_impl::pma10_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE(Xf_InputRange, 
                        0., 
                        1000.);

template <int NV>
using Xf = parameter::chain<Xf_InputRange, 
                            parameter::plain<files_impl::pma11_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(shift_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(shift_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using shift_0 = parameter::from0To1<files_impl::branch_t<NV>, 
                                    0, 
                                    shift_0Range>;

template <int NV>
using shift = parameter::chain<shift_InputRange, shift_0<NV>>;

DECLARE_PARAMETER_RANGE(pitch_InputRange, 
                        -24., 
                        24.);

template <int NV>
using pitch = parameter::chain<pitch_InputRange, 
                               parameter::plain<files_impl::pma4_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(XfStage_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(XfStage_0Range, 
                             3., 
                             6., 
                             1.);

template <int NV>
using XfStage_0 = parameter::from0To1<files_impl::event_data_reader13_t<NV>, 
                                      0, 
                                      XfStage_0Range>;

template <int NV>
using XfStage = parameter::chain<XfStage_InputRange, XfStage_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(intmodtempo_InputRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using intmodtempo = parameter::chain<intmodtempo_InputRange, 
                                     parameter::plain<files_impl::pma12_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(InmodDiv_InputRange, 
                             1., 
                             32., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(InmodDiv_0Range, 
                             1., 
                             32., 
                             1.);

template <int NV>
using InmodDiv_0 = parameter::from0To1<files_impl::tempo_sync_t<NV>, 
                                       1, 
                                       InmodDiv_0Range>;

template <int NV>
using InmodDiv_1 = parameter::from0To1<files_impl::clock_ramp_t<NV>, 
                                       1, 
                                       files_impl::cable_table2_modRange>;

template <int NV>
using InmodDiv = parameter::chain<InmodDiv_InputRange, 
                                  InmodDiv_0<NV>, 
                                  InmodDiv_1<NV>>;

using fb = parameter::chain<ranges::Identity, 
                            parameter::plain<routing::receive<stereo_cable>, 0>, 
                            parameter::plain<routing::receive<stereo_cable>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(Midi1_InputRange, 
                             1., 
                             7., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Midi1_0Range, 
                             0., 
                             6., 
                             1.);

template <int NV>
using Midi1_0 = parameter::from0To1<files_impl::branch5_t<NV>, 
                                    0, 
                                    Midi1_0Range>;

template <int NV>
using Midi1 = parameter::chain<Midi1_InputRange, Midi1_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Midi2_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using Midi2_0 = parameter::from0To1<files_impl::branch6_t<NV>, 
                                    0, 
                                    Midi1_0Range>;

template <int NV>
using Midi2 = parameter::chain<Midi2_InputRange, Midi2_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Midi3_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using Midi3_0 = parameter::from0To1<files_impl::branch7_t<NV>, 
                                    0, 
                                    Midi1_0Range>;

template <int NV>
using Midi3 = parameter::chain<Midi3_InputRange, Midi3_0<NV>>;

DECLARE_PARAMETER_RANGE(xf2_InputRange, 
                        1., 
                        4.);
template <int NV>
using xf2_0 = parameter::from0To1<files_impl::event_data_reader22_t<NV>, 
                                  0, 
                                  XfStage_0Range>;

template <int NV>
using xf2 = parameter::chain<xf2_InputRange, xf2_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(xf3_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV>
using xf3_0 = parameter::from0To1<routing::event_data_reader<NV>, 
                                  0, 
                                  XfStage_0Range>;

template <int NV>
using xf3 = parameter::chain<xf3_InputRange, xf3_0<NV>>;

template <int NV>
using WinSync = parameter::chain<ranges::Identity, 
                                 parameter::plain<files_impl::tempo_sync1_t<NV>, 2>, 
                                 parameter::plain<files_impl::tempo_sync3_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(WinTempo_InputRange, 
                             -16., 
                             18., 
                             1.);

template <int NV>
using WinTempo = parameter::chain<WinTempo_InputRange, 
                                  parameter::plain<files_impl::pma7_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(XfTempo_InputRange, 
                             -16., 
                             18., 
                             1.);

template <int NV>
using XfTempo = parameter::chain<XfTempo_InputRange, 
                                 parameter::plain<files_impl::pma9_t<NV>, 2>>;

template <int NV>
using XfMod = parameter::chain<ranges::Identity, 
                               parameter::plain<files_impl::pma9_t<NV>, 1>, 
                               parameter::plain<files_impl::pma11_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(xf4_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV> using xf4_0 = xf3_0<NV>;

template <int NV>
using xf4 = parameter::chain<xf4_InputRange, xf4_0<NV>>;

DECLARE_PARAMETER_RANGE(xf5_InputRange, 
                        1., 
                        4.);
template <int NV> using xf5_0 = xf3_0<NV>;

template <int NV>
using xf5 = parameter::chain<xf5_InputRange, xf5_0<NV>>;

DECLARE_PARAMETER_RANGE(midi4_InputRange, 
                        1., 
                        7.);
template <int NV>
using midi4_0 = parameter::from0To1<files_impl::branch10_t<NV>, 
                                    0, 
                                    Midi1_0Range>;

template <int NV>
using midi4 = parameter::chain<midi4_InputRange, midi4_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(mid5_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using mid5_0 = parameter::from0To1<files_impl::branch9_t<NV>, 
                                   0, 
                                   Midi1_0Range>;

template <int NV>
using mid5 = parameter::chain<mid5_InputRange, mid5_0<NV>>;

DECLARE_PARAMETER_RANGE(Midi6_InputRange, 
                        1., 
                        7.);
template <int NV>
using Midi6_0 = parameter::from0To1<files_impl::branch11_t<NV>, 
                                    0, 
                                    Midi1_0Range>;

template <int NV>
using Midi6 = parameter::chain<Midi6_InputRange, Midi6_0<NV>>;

DECLARE_PARAMETER_RANGE(Midi7_InputRange, 
                        1., 
                        7.);
template <int NV>
using Midi7_0 = parameter::from0To1<files_impl::branch12_t<NV>, 
                                    0, 
                                    Midi1_0Range>;

template <int NV>
using Midi7 = parameter::chain<Midi7_InputRange, Midi7_0<NV>>;

DECLARE_PARAMETER_RANGE(Midi8_InputRange, 
                        1., 
                        7.);
template <int NV>
using Midi8_0 = parameter::from0To1<files_impl::branch13_t<NV>, 
                                    0, 
                                    Midi1_0Range>;

template <int NV>
using Midi8 = parameter::chain<Midi8_InputRange, Midi8_0<NV>>;

DECLARE_PARAMETER_RANGE(XfStage6_InputRange, 
                        1., 
                        4.);
template <int NV> using XfStage6_0 = xf3_0<NV>;

template <int NV>
using XfStage6 = parameter::chain<XfStage6_InputRange, XfStage6_0<NV>>;

DECLARE_PARAMETER_RANGE(XfStage7_InputRange, 
                        1., 
                        4.);
template <int NV> using XfStage7_0 = xf3_0<NV>;

template <int NV>
using XfStage7 = parameter::chain<XfStage7_InputRange, XfStage7_0<NV>>;

DECLARE_PARAMETER_RANGE(XfStage8_InputRange, 
                        1., 
                        4.);
template <int NV> using XfStage8_0 = xf3_0<NV>;

template <int NV>
using XfStage8 = parameter::chain<XfStage8_InputRange, XfStage8_0<NV>>;

template <int NV>
using Input = parameter::plain<files_impl::pma3_t<NV>, 2>;
template <int NV>
using Mix = parameter::plain<files_impl::pma15_t<NV>, 
                             2>;
template <int NV>
using PositionTempoMod = parameter::plain<files_impl::pma2_t<NV>, 1>;
template <int NV>
using PitchMod = parameter::plain<files_impl::pma4_t<NV>, 1>;
template <int NV>
using InputMod = parameter::plain<files_impl::pma3_t<NV>, 1>;
template <int NV>
using IntMod = parameter::plain<files_impl::pma1_t<NV>, 1>;
using IntModSteps = parameter::plain<files_impl::pack_resizer_t, 
                                     0>;
template <int NV>
using IntmodOne = parameter::plain<files_impl::ramp_t<NV>, 1>;
template <int NV>
using tablestep = parameter::plain<files_impl::branch1_t<NV>, 
                                   0>;
template <int NV>
using UserMode = parameter::plain<files_impl::branch2_t<NV>, 
                                  0>;
template <int NV>
using WinMod = parameter::plain<files_impl::pma7_t<NV>, 1>;
template <int NV>
using InmodClk = parameter::plain<files_impl::branch3_t<NV>, 
                                  0>;
template <int NV>
using InTempoMod = parameter::plain<files_impl::pma12_t<NV>, 
                                    1>;
template <int NV>
using SmoothMod = parameter::plain<files_impl::pma14_t<NV>, 
                                   1>;
template <int NV>
using MixMod = parameter::plain<files_impl::pma15_t<NV>, 
                                1>;
template <int NV>
using files_t_plist = parameter::list<smooth<NV>, 
                                      quant<NV>, 
                                      Position<NV>, 
                                      Input<NV>, 
                                      Win<NV>, 
                                      Xf<NV>, 
                                      shift<NV>, 
                                      pitch<NV>, 
                                      Mix<NV>, 
                                      PositionTempoMod<NV>, 
                                      PitchMod<NV>, 
                                      InputMod<NV>, 
                                      XfStage<NV>, 
                                      IntMod<NV>, 
                                      IntModSteps, 
                                      IntmodOne<NV>, 
                                      intmodtempo<NV>, 
                                      InmodDiv<NV>, 
                                      fb, 
                                      tablestep<NV>, 
                                      Midi1<NV>, 
                                      Midi2<NV>, 
                                      Midi3<NV>, 
                                      xf2<NV>, 
                                      xf3<NV>, 
                                      UserMode<NV>, 
                                      WinSync<NV>, 
                                      WinTempo<NV>, 
                                      XfTempo<NV>, 
                                      WinMod<NV>, 
                                      XfMod<NV>, 
                                      xf4<NV>, 
                                      xf5<NV>, 
                                      midi4<NV>, 
                                      mid5<NV>, 
                                      InmodClk<NV>, 
                                      InTempoMod<NV>, 
                                      SmoothMod<NV>, 
                                      MixMod<NV>, 
                                      Midi6<NV>, 
                                      Midi7<NV>, 
                                      Midi8<NV>, 
                                      XfStage6<NV>, 
                                      XfStage7<NV>, 
                                      XfStage8<NV>>;
}

template <int NV>
using files_t_ = container::chain<files_t_parameters::files_t_plist<NV>, 
                                  wrap::fix<2, fix8_block_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public files_impl::files_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 4;
		static const int NumSliderPacks = 9;
		static const int NumAudioFiles = 2;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(files);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(730)
		{
			0x005B, 0x0000, 0x7300, 0x6F6D, 0x746F, 0x0068, 0x0000, 0x0000, 
            0x0000, 0x44FA, 0x0000, 0x0000, 0xEE69, 0x3E6C, 0xCCCD, 0x3DCC, 
            0x015B, 0x0000, 0x7100, 0x6175, 0x746E, 0x0000, 0x8000, 0x003F, 
            0x1000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0002, 0x0000, 0x6F50, 0x6973, 0x6974, 0x6E6F, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0003, 0x0000, 0x6E49, 0x7570, 0x0074, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x045B, 0x0000, 0x5700, 0x6E69, 0x0000, 0x0000, 0x0000, 0x7A00, 
            0x0044, 0x2000, 0x0041, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0005, 
            0x0000, 0x6658, 0x0000, 0x0000, 0x0000, 0x7A00, 0x0044, 0x2000, 
            0x0041, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0006, 0x0000, 0x6873, 
            0x6669, 0x0074, 0x0000, 0x3F80, 0x0000, 0x4040, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x075B, 0x0000, 0x7000, 0x7469, 
            0x6863, 0x0000, 0xC000, 0x00C1, 0xC000, 0x6D41, 0x6666, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0008, 0x0000, 0x694D, 0x0078, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0xCCCD, 0x3ECC, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x095B, 0x0000, 0x5000, 0x736F, 0x7469, 0x6F69, 
            0x546E, 0x6D65, 0x6F70, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0A5B, 
            0x0000, 0x5000, 0x7469, 0x6863, 0x6F4D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0B5B, 0x0000, 0x4900, 0x706E, 0x7475, 0x6F4D, 0x0064, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0C5B, 0x0000, 0x5800, 0x5366, 0x6174, 0x6567, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x000D, 0x0000, 0x6E49, 0x4D74, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x000E, 0x0000, 0x6E49, 0x4D74, 0x646F, 0x7453, 
            0x7065, 0x0073, 0x0000, 0x4080, 0x0000, 0x4280, 0x0000, 0x4120, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0F5B, 0x0000, 0x4900, 0x746E, 
            0x6F6D, 0x4F64, 0x656E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0010, 0x0000, 
            0x6E69, 0x6D74, 0x646F, 0x6574, 0x706D, 0x006F, 0x0000, 0x0000, 
            0x0000, 0x4190, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x115B, 0x0000, 0x4900, 0x6D6E, 0x646F, 0x6944, 0x0076, 0x0000, 
            0x3F80, 0x0000, 0x4200, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x125B, 0x0000, 0x6600, 0x0062, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x6666, 0x3F66, 0x0000, 0x3F80, 0x0000, 0x0000, 0x135B, 
            0x0000, 0x7400, 0x6261, 0x656C, 0x7473, 0x7065, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0014, 0x0000, 0x694D, 0x6964, 0x0031, 0x0000, 0x3F80, 
            0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x155B, 0x0000, 0x4D00, 0x6469, 0x3269, 0x0000, 0x8000, 0x003F, 
            0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0016, 0x0000, 0x694D, 0x6964, 0x0033, 0x0000, 0x3F80, 0x0000, 
            0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x175B, 
            0x0000, 0x7800, 0x3266, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0018, 0x0000, 
            0x6678, 0x0033, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x195B, 0x0000, 0x5500, 0x6573, 
            0x4D72, 0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x1A5B, 0x0000, 0x5700, 
            0x6E69, 0x7953, 0x636E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x001B, 0x0000, 
            0x6957, 0x546E, 0x6D65, 0x6F70, 0x0000, 0x8000, 0x00C1, 0x9000, 
            0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x001C, 
            0x0000, 0x6658, 0x6554, 0x706D, 0x006F, 0x0000, 0xC180, 0x0000, 
            0x4190, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x1D5B, 
            0x0000, 0x5700, 0x6E69, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x1E5B, 
            0x0000, 0x5800, 0x4D66, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x001F, 
            0x0000, 0x6678, 0x0034, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x205B, 0x0000, 0x7800, 
            0x3566, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0021, 0x0000, 0x696D, 0x6964, 
            0x0034, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x225B, 0x0000, 0x6D00, 0x6469, 0x0035, 
            0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x235B, 0x0000, 0x4900, 0x6D6E, 0x646F, 0x6C43, 
            0x006B, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x245B, 0x0000, 0x4900, 0x546E, 0x6D65, 
            0x6F70, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x255B, 0x0000, 0x5300, 
            0x6F6D, 0x746F, 0x4D68, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0026, 
            0x0000, 0x694D, 0x4D78, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0027, 
            0x0000, 0x694D, 0x6964, 0x0036, 0x0000, 0x3F80, 0x0000, 0x40E0, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x285B, 0x0000, 
            0x4D00, 0x6469, 0x3769, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0029, 0x0000, 
            0x694D, 0x6964, 0x0038, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x2A5B, 0x0000, 0x5800, 
            0x5366, 0x6174, 0x6567, 0x0036, 0x0000, 0x3F80, 0x0000, 0x4080, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x2B5B, 0x0000, 
            0x5800, 0x5366, 0x6174, 0x6567, 0x0037, 0x0000, 0x3F80, 0x0000, 
            0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x2C5B, 
            0x0000, 0x5800, 0x5366, 0x6174, 0x6567, 0x0038, 0x0000, 0x3F80, 
            0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& fix8_block = this->getT(0);                                                   // files_impl::fix8_block_t<NV>
		auto& split6 = this->getT(0).getT(0);                                               // files_impl::split6_t<NV>
		auto& modchain = this->getT(0).getT(0).getT(0);                                     // files_impl::modchain_t<NV>
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(0);                               // files_impl::chain5_t<NV>
		auto& clear = this->getT(0).getT(0).getT(0).getT(0).getT(0);                        // math::clear<NV>
		auto& chain112 = this->getT(0).getT(0).getT(0).getT(0).getT(1);                     // files_impl::chain112_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);              // files_impl::branch3_t<NV>
		auto& chain113 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);     // files_impl::chain113_t<NV>
		auto& tempo_sync = this->getT(0).getT(0).getT(0).getT(0).                           // files_impl::tempo_sync_t<NV>
                           getT(1).getT(0).getT(0).getT(0);
		auto& ramp = this->getT(0).getT(0).getT(0).getT(0).                                 // files_impl::ramp_t<NV>
                     getT(1).getT(0).getT(0).getT(1);
		auto& add17 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                      getT(1).getT(0).getT(0).getT(2);
		auto& chain114 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);     // files_impl::chain114_t<NV>
		auto& clock_ramp = this->getT(0).getT(0).getT(0).getT(0).                           // files_impl::clock_ramp_t<NV>
                           getT(1).getT(0).getT(1).getT(0);
		auto& add18 = this->getT(0).getT(0).getT(0).getT(0).                                // math::add<NV>
                      getT(1).getT(0).getT(1).getT(1);
		auto& peak2 = this->getT(0).getT(0).getT(0).getT(0).getT(2);                        // files_impl::peak2_t<NV>
		auto& clear2 = this->getT(0).getT(0).getT(0).getT(0).getT(3);                       // math::clear<NV>
		auto& pack_resizer = this->getT(0).getT(0).getT(0).getT(0).getT(4);                 // files_impl::pack_resizer_t
		auto& branch1 = this->getT(0).getT(0).getT(0).getT(0).getT(5);                      // files_impl::branch1_t<NV>
		auto& chain7 = this->getT(0).getT(0).getT(0).getT(0).getT(5).getT(0);               // files_impl::chain7_t<NV>
		auto& cable_table = this->getT(0).getT(0).getT(0).getT(0).getT(5).getT(0).getT(0);  // files_impl::cable_table_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(0).getT(0).getT(5).getT(0).getT(1);         // math::add<NV>
		auto& chain9 = this->getT(0).getT(0).getT(0).getT(0).getT(5).getT(1);               // files_impl::chain9_t<NV>
		auto& cable_pack = this->getT(0).getT(0).getT(0).getT(0).getT(5).getT(1).getT(0);   // files_impl::cable_pack_t<NV>
		auto& add10 = this->getT(0).getT(0).getT(0).getT(0).getT(5).getT(1).getT(1);        // math::add<NV>
		auto& peak1 = this->getT(0).getT(0).getT(0).getT(0).getT(6);                        // files_impl::peak1_t<NV>
		auto& clear1 = this->getT(0).getT(0).getT(0).getT(0).getT(7);                       // math::clear<NV>
		auto& pma1 = this->getT(0).getT(0).getT(0).getT(0).getT(8);                         // files_impl::pma1_t<NV>
		auto& cable_table7 = this->getT(0).getT(0).getT(0).getT(0).getT(9);                 // files_impl::cable_table7_t
		auto& split4 = this->getT(0).getT(0).getT(0).getT(1);                               // files_impl::split4_t
		auto& modchain2 = this->getT(0).getT(0).getT(1);                                    // files_impl::modchain2_t<NV>
		auto& sliderbank3 = this->getT(0).getT(0).getT(1).getT(0);                          // files_impl::sliderbank3_t<NV>
		auto& split1 = this->getT(0).getT(0).getT(1).getT(1);                               // files_impl::split1_t<NV>
		auto& chain39 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                      // files_impl::chain39_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(0);        // files_impl::global_cable3_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(1);                 // math::add<NV>
		auto& gain13 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(2);               // core::gain<NV>
		auto& chain41 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                      // files_impl::chain41_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0);       // files_impl::global_cable11_t<NV>
		auto& add26 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(1);                // math::add<NV>
		auto& gain15 = this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(2);               // core::gain<NV>
		auto& chain40 = this->getT(0).getT(0).getT(1).getT(1).getT(2);                      // files_impl::chain40_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0);       // files_impl::global_cable10_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(1);                 // math::add<NV>
		auto& gain14 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(2);               // core::gain<NV>
		auto& chain42 = this->getT(0).getT(0).getT(1).getT(1).getT(3);                      // files_impl::chain42_t<NV>
		auto& global_cable25 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(0);       // files_impl::global_cable25_t<NV>
		auto& add27 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(1);                // math::add<NV>
		auto& gain16 = this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(2);               // core::gain<NV>
		auto& chain44 = this->getT(0).getT(0).getT(1).getT(1).getT(4);                      // files_impl::chain44_t<NV>
		auto& event_data_reader11 = this->getT(0).getT(0).getT(1).getT(1).getT(4).getT(0);  // files_impl::event_data_reader11_t<NV>
		auto& add29 = this->getT(0).getT(0).getT(1).getT(1).getT(4).getT(1);                // math::add<NV>
		auto& gain32 = this->getT(0).getT(0).getT(1).getT(1).getT(4).getT(2);               // core::gain<NV>
		auto& chain45 = this->getT(0).getT(0).getT(1).getT(1).getT(5);                      // files_impl::chain45_t<NV>
		auto& event_data_reader10 = this->getT(0).getT(0).getT(1).getT(1).getT(5).getT(0);  // files_impl::event_data_reader10_t<NV>
		auto& add28 = this->getT(0).getT(0).getT(1).getT(1).getT(5).getT(1);                // math::add<NV>
		auto& gain26 = this->getT(0).getT(0).getT(1).getT(1).getT(5).getT(2);               // core::gain<NV>
		auto& chain46 = this->getT(0).getT(0).getT(1).getT(1).getT(6);                      // files_impl::chain46_t<NV>
		auto& event_data_reader13 = this->getT(0).getT(0).getT(1).getT(1).getT(6).getT(0);  // files_impl::event_data_reader13_t<NV>
		auto& add30 = this->getT(0).getT(0).getT(1).getT(1).getT(6).getT(1);                // math::add<NV>
		auto& gain33 = this->getT(0).getT(0).getT(1).getT(1).getT(6).getT(2);               // core::gain<NV>
		auto& chain47 = this->getT(0).getT(0).getT(1).getT(1).getT(7);                      // files_impl::chain47_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(1).getT(1).getT(7).getT(0);              // files_impl::branch5_t<NV>
		auto& chain13 = this->getT(0).getT(0).getT(1).getT(1).getT(7).getT(0).getT(0);      // files_impl::chain13_t<NV>
		auto& midi_cc10 = this->getT(0).getT(0).getT(1).getT(1).                            // files_impl::midi_cc10_t<NV>
                          getT(7).getT(0).getT(0).getT(0);
		auto& add60 = this->getT(0).getT(0).getT(1).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(0).getT(1);
		auto& chain18 = this->getT(0).getT(0).getT(1).getT(1).getT(7).getT(0).getT(1);      // files_impl::chain18_t<NV>
		auto& midi_cc11 = this->getT(0).getT(0).getT(1).getT(1).                            // files_impl::midi_cc11_t<NV>
                          getT(7).getT(0).getT(1).getT(0);
		auto& add61 = this->getT(0).getT(0).getT(1).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(1).getT(1);
		auto& chain22 = this->getT(0).getT(0).getT(1).getT(1).getT(7).getT(0).getT(2);      // files_impl::chain22_t<NV>
		auto& midi_cc12 = this->getT(0).getT(0).getT(1).getT(1).                            // files_impl::midi_cc12_t<NV>
                          getT(7).getT(0).getT(2).getT(0);
		auto& add62 = this->getT(0).getT(0).getT(1).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(2).getT(1);
		auto& chain24 = this->getT(0).getT(0).getT(1).getT(1).getT(7).getT(0).getT(3);      // files_impl::chain24_t<NV>
		auto& midi_cc13 = this->getT(0).getT(0).getT(1).getT(1).                            // files_impl::midi_cc13_t<NV>
                          getT(7).getT(0).getT(3).getT(0);
		auto& add63 = this->getT(0).getT(0).getT(1).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(3).getT(1);
		auto& chain25 = this->getT(0).getT(0).getT(1).getT(1).getT(7).getT(0).getT(4);      // files_impl::chain25_t<NV>
		auto& midi7 = this->getT(0).getT(0).getT(1).getT(1).                                // files_impl::midi7_t<NV>
                      getT(7).getT(0).getT(4).getT(0);
		auto& add64 = this->getT(0).getT(0).getT(1).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(4).getT(1);
		auto& chain26 = this->getT(0).getT(0).getT(1).getT(1).getT(7).getT(0).getT(5);      // files_impl::chain26_t<NV>
		auto& midi8 = this->getT(0).getT(0).getT(1).getT(1).                                // files_impl::midi8_t<NV>
                      getT(7).getT(0).getT(5).getT(0);
		auto& add65 = this->getT(0).getT(0).getT(1).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(5).getT(1);
		auto& chain27 = this->getT(0).getT(0).getT(1).getT(1).getT(7).getT(0).getT(6);      // files_impl::chain27_t<NV>
		auto& midi9 = this->getT(0).getT(0).getT(1).getT(1).                                // files_impl::midi9_t<NV>
                      getT(7).getT(0).getT(6).getT(0);
		auto& add66 = this->getT(0).getT(0).getT(1).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(6).getT(1);
		auto& gain34 = this->getT(0).getT(0).getT(1).getT(1).getT(7).getT(1);               // core::gain<NV>
		auto& peak3 = this->getT(0).getT(0).getT(1).getT(2);                                // files_impl::peak3_t<NV>
		auto& pma2 = this->getT(0).getT(0).getT(1).getT(3);                                 // files_impl::pma2_t<NV>
		auto& cable_table6 = this->getT(0).getT(0).getT(1).getT(4);                         // files_impl::cable_table6_t
		auto& cable_table8 = this->getT(0).getT(0).getT(1).getT(5);                         // files_impl::cable_table8_t
		auto& modchain4 = this->getT(0).getT(0).getT(2);                                    // files_impl::modchain4_t<NV>
		auto& sliderbank7 = this->getT(0).getT(0).getT(2).getT(0);                          // files_impl::sliderbank7_t<NV>
		auto& split3 = this->getT(0).getT(0).getT(2).getT(1);                               // files_impl::split3_t<NV>
		auto& chain72 = this->getT(0).getT(0).getT(2).getT(1).getT(0);                      // files_impl::chain72_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0);        // files_impl::global_cable5_t<NV>
		auto& add8 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(1);                 // math::add<NV>
		auto& gain21 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(2);               // core::gain<NV>
		auto& chain73 = this->getT(0).getT(0).getT(2).getT(1).getT(1);                      // files_impl::chain73_t<NV>
		auto& global_cable20 = this->getT(0).getT(0).getT(2).getT(1).getT(1).getT(0);       // files_impl::global_cable20_t<NV>
		auto& add54 = this->getT(0).getT(0).getT(2).getT(1).getT(1).getT(1);                // math::add<NV>
		auto& gain22 = this->getT(0).getT(0).getT(2).getT(1).getT(1).getT(2);               // core::gain<NV>
		auto& chain74 = this->getT(0).getT(0).getT(2).getT(1).getT(2);                      // files_impl::chain74_t<NV>
		auto& global_cable21 = this->getT(0).getT(0).getT(2).getT(1).getT(2).getT(0);       // files_impl::global_cable21_t<NV>
		auto& add9 = this->getT(0).getT(0).getT(2).getT(1).getT(2).getT(1);                 // math::add<NV>
		auto& gain23 = this->getT(0).getT(0).getT(2).getT(1).getT(2).getT(2);               // core::gain<NV>
		auto& chain75 = this->getT(0).getT(0).getT(2).getT(1).getT(3);                      // files_impl::chain75_t<NV>
		auto& global_cable26 = this->getT(0).getT(0).getT(2).getT(1).getT(3).getT(0);       // files_impl::global_cable26_t<NV>
		auto& add55 = this->getT(0).getT(0).getT(2).getT(1).getT(3).getT(1);                // math::add<NV>
		auto& gain24 = this->getT(0).getT(0).getT(2).getT(1).getT(3).getT(2);               // core::gain<NV>
		auto& chain76 = this->getT(0).getT(0).getT(2).getT(1).getT(4);                      // files_impl::chain76_t<NV>
		auto& event_data_reader20 = this->getT(0).getT(0).getT(2).getT(1).getT(4).getT(0);  // files_impl::event_data_reader20_t<NV>
		auto& add56 = this->getT(0).getT(0).getT(2).getT(1).getT(4).getT(1);                // math::add<NV>
		auto& gain54 = this->getT(0).getT(0).getT(2).getT(1).getT(4).getT(2);               // core::gain<NV>
		auto& chain77 = this->getT(0).getT(0).getT(2).getT(1).getT(5);                      // files_impl::chain77_t<NV>
		auto& event_data_reader21 = this->getT(0).getT(0).getT(2).getT(1).getT(5).getT(0);  // files_impl::event_data_reader21_t<NV>
		auto& add57 = this->getT(0).getT(0).getT(2).getT(1).getT(5).getT(1);                // math::add<NV>
		auto& gain28 = this->getT(0).getT(0).getT(2).getT(1).getT(5).getT(2);               // core::gain<NV>
		auto& chain80 = this->getT(0).getT(0).getT(2).getT(1).getT(6);                      // files_impl::chain80_t<NV>
		auto& event_data_reader22 = this->getT(0).getT(0).getT(2).getT(1).getT(6).getT(0);  // files_impl::event_data_reader22_t<NV>
		auto& add58 = this->getT(0).getT(0).getT(2).getT(1).getT(6).getT(1);                // math::add<NV>
		auto& gain55 = this->getT(0).getT(0).getT(2).getT(1).getT(6).getT(2);               // core::gain<NV>
		auto& chain81 = this->getT(0).getT(0).getT(2).getT(1).getT(7);                      // files_impl::chain81_t<NV>
		auto& branch6 = this->getT(0).getT(0).getT(2).getT(1).getT(7).getT(0);              // files_impl::branch6_t<NV>
		auto& chain14 = this->getT(0).getT(0).getT(2).getT(1).getT(7).getT(0).getT(0);      // files_impl::chain14_t<NV>
		auto& midi_cc14 = this->getT(0).getT(0).getT(2).getT(1).                            // files_impl::midi_cc14_t<NV>
                          getT(7).getT(0).getT(0).getT(0);
		auto& add67 = this->getT(0).getT(0).getT(2).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(0).getT(1);
		auto& chain19 = this->getT(0).getT(0).getT(2).getT(1).getT(7).getT(0).getT(1);      // files_impl::chain19_t<NV>
		auto& midi_cc15 = this->getT(0).getT(0).getT(2).getT(1).                            // files_impl::midi_cc15_t<NV>
                          getT(7).getT(0).getT(1).getT(0);
		auto& add68 = this->getT(0).getT(0).getT(2).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(1).getT(1);
		auto& chain23 = this->getT(0).getT(0).getT(2).getT(1).getT(7).getT(0).getT(2);      // files_impl::chain23_t<NV>
		auto& midi_cc16 = this->getT(0).getT(0).getT(2).getT(1).                            // files_impl::midi_cc16_t<NV>
                          getT(7).getT(0).getT(2).getT(0);
		auto& add69 = this->getT(0).getT(0).getT(2).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(2).getT(1);
		auto& chain28 = this->getT(0).getT(0).getT(2).getT(1).getT(7).getT(0).getT(3);      // files_impl::chain28_t<NV>
		auto& midi_cc17 = this->getT(0).getT(0).getT(2).getT(1).                            // files_impl::midi_cc17_t<NV>
                          getT(7).getT(0).getT(3).getT(0);
		auto& add70 = this->getT(0).getT(0).getT(2).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(3).getT(1);
		auto& chain29 = this->getT(0).getT(0).getT(2).getT(1).getT(7).getT(0).getT(4);      // files_impl::chain29_t<NV>
		auto& midi10 = this->getT(0).getT(0).getT(2).getT(1).                               // files_impl::midi10_t<NV>
                       getT(7).getT(0).getT(4).getT(0);
		auto& add71 = this->getT(0).getT(0).getT(2).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(4).getT(1);
		auto& chain30 = this->getT(0).getT(0).getT(2).getT(1).getT(7).getT(0).getT(5);      // files_impl::chain30_t<NV>
		auto& midi11 = this->getT(0).getT(0).getT(2).getT(1).                               // files_impl::midi11_t<NV>
                       getT(7).getT(0).getT(5).getT(0);
		auto& add72 = this->getT(0).getT(0).getT(2).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(5).getT(1);
		auto& chain31 = this->getT(0).getT(0).getT(2).getT(1).getT(7).getT(0).getT(6);      // files_impl::chain31_t<NV>
		auto& midi12 = this->getT(0).getT(0).getT(2).getT(1).                               // files_impl::midi12_t<NV>
                       getT(7).getT(0).getT(6).getT(0);
		auto& add73 = this->getT(0).getT(0).getT(2).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(6).getT(1);
		auto& gain56 = this->getT(0).getT(0).getT(2).getT(1).getT(7).getT(1);               // core::gain<NV>
		auto& peak7 = this->getT(0).getT(0).getT(2).getT(2);                                // files_impl::peak7_t<NV>
		auto& pma4 = this->getT(0).getT(0).getT(2).getT(3);                                 // files_impl::pma4_t<NV>
		auto& modchain3 = this->getT(0).getT(0).getT(3);                                    // files_impl::modchain3_t<NV>
		auto& sliderbank6 = this->getT(0).getT(0).getT(3).getT(0);                          // files_impl::sliderbank6_t<NV>
		auto& split2 = this->getT(0).getT(0).getT(3).getT(1);                               // files_impl::split2_t<NV>
		auto& chain64 = this->getT(0).getT(0).getT(3).getT(1).getT(0);                      // files_impl::chain64_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(3).getT(1).getT(0).getT(0);        // files_impl::global_cable4_t<NV>
		auto& add6 = this->getT(0).getT(0).getT(3).getT(1).getT(0).getT(1);                 // math::add<NV>
		auto& gain17 = this->getT(0).getT(0).getT(3).getT(1).getT(0).getT(2);               // core::gain<NV>
		auto& chain65 = this->getT(0).getT(0).getT(3).getT(1).getT(1);                      // files_impl::chain65_t<NV>
		auto& global_cable12 = this->getT(0).getT(0).getT(3).getT(1).getT(1).getT(0);       // files_impl::global_cable12_t<NV>
		auto& add48 = this->getT(0).getT(0).getT(3).getT(1).getT(1).getT(1);                // math::add<NV>
		auto& gain18 = this->getT(0).getT(0).getT(3).getT(1).getT(1).getT(2);               // core::gain<NV>
		auto& chain66 = this->getT(0).getT(0).getT(3).getT(1).getT(2);                      // files_impl::chain66_t<NV>
		auto& global_cable19 = this->getT(0).getT(0).getT(3).getT(1).getT(2).getT(0);       // files_impl::global_cable19_t<NV>
		auto& add7 = this->getT(0).getT(0).getT(3).getT(1).getT(2).getT(1);                 // math::add<NV>
		auto& gain19 = this->getT(0).getT(0).getT(3).getT(1).getT(2).getT(2);               // core::gain<NV>
		auto& chain67 = this->getT(0).getT(0).getT(3).getT(1).getT(3);                      // files_impl::chain67_t<NV>
		auto& global_cable27 = this->getT(0).getT(0).getT(3).getT(1).getT(3).getT(0);       // files_impl::global_cable27_t<NV>
		auto& add49 = this->getT(0).getT(0).getT(3).getT(1).getT(3).getT(1);                // math::add<NV>
		auto& gain20 = this->getT(0).getT(0).getT(3).getT(1).getT(3).getT(2);               // core::gain<NV>
		auto& chain68 = this->getT(0).getT(0).getT(3).getT(1).getT(4);                      // files_impl::chain68_t<NV>
		auto& event_data_reader12 = this->getT(0).getT(0).getT(3).getT(1).getT(4).getT(0);  // files_impl::event_data_reader12_t<NV>
		auto& add50 = this->getT(0).getT(0).getT(3).getT(1).getT(4).getT(1);                // math::add<NV>
		auto& gain51 = this->getT(0).getT(0).getT(3).getT(1).getT(4).getT(2);               // core::gain<NV>
		auto& chain69 = this->getT(0).getT(0).getT(3).getT(1).getT(5);                      // files_impl::chain69_t<NV>
		auto& event_data_reader19 = this->getT(0).getT(0).getT(3).getT(1).getT(5).getT(0);  // files_impl::event_data_reader19_t<NV>
		auto& add51 = this->getT(0).getT(0).getT(3).getT(1).getT(5).getT(1);                // math::add<NV>
		auto& gain27 = this->getT(0).getT(0).getT(3).getT(1).getT(5).getT(2);               // core::gain<NV>
		auto& chain70 = this->getT(0).getT(0).getT(3).getT(1).getT(6);                      // files_impl::chain70_t<NV>
		auto& event_data_reader23 = this->getT(0).getT(0).getT(3).getT(1).getT(6).getT(0);  // routing::event_data_reader<NV>
		auto& add52 = this->getT(0).getT(0).getT(3).getT(1).getT(6).getT(1);                // math::add<NV>
		auto& gain52 = this->getT(0).getT(0).getT(3).getT(1).getT(6).getT(2);               // core::gain<NV>
		auto& chain71 = this->getT(0).getT(0).getT(3).getT(1).getT(7);                      // files_impl::chain71_t<NV>
		auto& branch7 = this->getT(0).getT(0).getT(3).getT(1).getT(7).getT(0);              // files_impl::branch7_t<NV>
		auto& chain16 = this->getT(0).getT(0).getT(3).getT(1).getT(7).getT(0).getT(0);      // files_impl::chain16_t<NV>
		auto& midi_cc18 = this->getT(0).getT(0).getT(3).getT(1).                            // files_impl::midi_cc18_t<NV>
                          getT(7).getT(0).getT(0).getT(0);
		auto& add74 = this->getT(0).getT(0).getT(3).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(0).getT(1);
		auto& chain20 = this->getT(0).getT(0).getT(3).getT(1).getT(7).getT(0).getT(1);      // files_impl::chain20_t<NV>
		auto& midi_cc19 = this->getT(0).getT(0).getT(3).getT(1).                            // files_impl::midi_cc19_t<NV>
                          getT(7).getT(0).getT(1).getT(0);
		auto& add75 = this->getT(0).getT(0).getT(3).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(1).getT(1);
		auto& chain32 = this->getT(0).getT(0).getT(3).getT(1).getT(7).getT(0).getT(2);      // files_impl::chain32_t<NV>
		auto& midi_cc20 = this->getT(0).getT(0).getT(3).getT(1).                            // files_impl::midi_cc20_t<NV>
                          getT(7).getT(0).getT(2).getT(0);
		auto& add76 = this->getT(0).getT(0).getT(3).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(2).getT(1);
		auto& chain33 = this->getT(0).getT(0).getT(3).getT(1).getT(7).getT(0).getT(3);      // files_impl::chain33_t<NV>
		auto& midi_cc21 = this->getT(0).getT(0).getT(3).getT(1).                            // files_impl::midi_cc21_t<NV>
                          getT(7).getT(0).getT(3).getT(0);
		auto& add77 = this->getT(0).getT(0).getT(3).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(3).getT(1);
		auto& chain34 = this->getT(0).getT(0).getT(3).getT(1).getT(7).getT(0).getT(4);      // files_impl::chain34_t<NV>
		auto& midi13 = this->getT(0).getT(0).getT(3).getT(1).                               // files_impl::midi13_t<NV>
                       getT(7).getT(0).getT(4).getT(0);
		auto& add78 = this->getT(0).getT(0).getT(3).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(4).getT(1);
		auto& chain35 = this->getT(0).getT(0).getT(3).getT(1).getT(7).getT(0).getT(5);      // files_impl::chain35_t<NV>
		auto& midi14 = this->getT(0).getT(0).getT(3).getT(1).                               // files_impl::midi14_t<NV>
                       getT(7).getT(0).getT(5).getT(0);
		auto& add79 = this->getT(0).getT(0).getT(3).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(5).getT(1);
		auto& chain36 = this->getT(0).getT(0).getT(3).getT(1).getT(7).getT(0).getT(6);      // files_impl::chain36_t<NV>
		auto& midi15 = this->getT(0).getT(0).getT(3).getT(1).                               // files_impl::midi15_t<NV>
                       getT(7).getT(0).getT(6).getT(0);
		auto& add80 = this->getT(0).getT(0).getT(3).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(6).getT(1);
		auto& gain53 = this->getT(0).getT(0).getT(3).getT(1).getT(7).getT(1);               // core::gain<NV>
		auto& peak6 = this->getT(0).getT(0).getT(3).getT(2);                                // files_impl::peak6_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(3).getT(3);                                 // files_impl::pma3_t<NV>
		auto& modchain6 = this->getT(0).getT(0).getT(4);                                    // files_impl::modchain6_t<NV>
		auto& sliderbank9 = this->getT(0).getT(0).getT(4).getT(0);                          // files_impl::sliderbank9_t<NV>
		auto& split8 = this->getT(0).getT(0).getT(4).getT(1);                               // files_impl::split8_t<NV>
		auto& chain93 = this->getT(0).getT(0).getT(4).getT(1).getT(0);                      // files_impl::chain93_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(4).getT(1).getT(0).getT(0);        // files_impl::global_cable7_t<NV>
		auto& add13 = this->getT(0).getT(0).getT(4).getT(1).getT(0).getT(1);                // math::add<NV>
		auto& gain36 = this->getT(0).getT(0).getT(4).getT(1).getT(0).getT(2);               // core::gain<NV>
		auto& chain94 = this->getT(0).getT(0).getT(4).getT(1).getT(1);                      // files_impl::chain94_t<NV>
		auto& global_cable14 = this->getT(0).getT(0).getT(4).getT(1).getT(1).getT(0);       // files_impl::global_cable14_t<NV>
		auto& add91 = this->getT(0).getT(0).getT(4).getT(1).getT(1).getT(1);                // math::add<NV>
		auto& gain37 = this->getT(0).getT(0).getT(4).getT(1).getT(1).getT(2);               // core::gain<NV>
		auto& chain95 = this->getT(0).getT(0).getT(4).getT(1).getT(2);                      // files_impl::chain95_t<NV>
		auto& global_cable23 = this->getT(0).getT(0).getT(4).getT(1).getT(2).getT(0);       // files_impl::global_cable23_t<NV>
		auto& add14 = this->getT(0).getT(0).getT(4).getT(1).getT(2).getT(1);                // math::add<NV>
		auto& gain38 = this->getT(0).getT(0).getT(4).getT(1).getT(2).getT(2);               // core::gain<NV>
		auto& chain96 = this->getT(0).getT(0).getT(4).getT(1).getT(3);                      // files_impl::chain96_t<NV>
		auto& global_cable28 = this->getT(0).getT(0).getT(4).getT(1).getT(3).getT(0);       // files_impl::global_cable28_t<NV>
		auto& add92 = this->getT(0).getT(0).getT(4).getT(1).getT(3).getT(1);                // math::add<NV>
		auto& gain39 = this->getT(0).getT(0).getT(4).getT(1).getT(3).getT(2);               // core::gain<NV>
		auto& chain97 = this->getT(0).getT(0).getT(4).getT(1).getT(4);                      // files_impl::chain97_t<NV>
		auto& event_data_reader15 = this->getT(0).getT(0).getT(4).getT(1).getT(4).getT(0);  // files_impl::event_data_reader15_t<NV>
		auto& add93 = this->getT(0).getT(0).getT(4).getT(1).getT(4).getT(1);                // math::add<NV>
		auto& gain60 = this->getT(0).getT(0).getT(4).getT(1).getT(4).getT(2);               // core::gain<NV>
		auto& chain98 = this->getT(0).getT(0).getT(4).getT(1).getT(5);                      // files_impl::chain98_t<NV>
		auto& event_data_reader26 = this->getT(0).getT(0).getT(4).getT(1).getT(5).getT(0);  // files_impl::event_data_reader26_t<NV>
		auto& add94 = this->getT(0).getT(0).getT(4).getT(1).getT(5).getT(1);                // math::add<NV>
		auto& gain40 = this->getT(0).getT(0).getT(4).getT(1).getT(5).getT(2);               // core::gain<NV>
		auto& chain99 = this->getT(0).getT(0).getT(4).getT(1).getT(6);                      // files_impl::chain99_t<NV>
		auto& event_data_reader27 = this->getT(0).getT(0).getT(4).getT(1).getT(6).getT(0);  // routing::event_data_reader<NV>
		auto& add95 = this->getT(0).getT(0).getT(4).getT(1).getT(6).getT(1);                // math::add<NV>
		auto& gain61 = this->getT(0).getT(0).getT(4).getT(1).getT(6).getT(2);               // core::gain<NV>
		auto& chain100 = this->getT(0).getT(0).getT(4).getT(1).getT(7);                     // files_impl::chain100_t<NV>
		auto& branch10 = this->getT(0).getT(0).getT(4).getT(1).getT(7).getT(0);             // files_impl::branch10_t<NV>
		auto& chain53 = this->getT(0).getT(0).getT(4).getT(1).getT(7).getT(0).getT(0);      // files_impl::chain53_t<NV>
		auto& midi_cc26 = this->getT(0).getT(0).getT(4).getT(1).                            // files_impl::midi_cc26_t<NV>
                          getT(7).getT(0).getT(0).getT(0);
		auto& add96 = this->getT(0).getT(0).getT(4).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(0).getT(1);
		auto& chain54 = this->getT(0).getT(0).getT(4).getT(1).getT(7).getT(0).getT(1);      // files_impl::chain54_t<NV>
		auto& midi_cc27 = this->getT(0).getT(0).getT(4).getT(1).                            // files_impl::midi_cc27_t<NV>
                          getT(7).getT(0).getT(1).getT(0);
		auto& add97 = this->getT(0).getT(0).getT(4).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(1).getT(1);
		auto& chain55 = this->getT(0).getT(0).getT(4).getT(1).getT(7).getT(0).getT(2);      // files_impl::chain55_t<NV>
		auto& midi_cc28 = this->getT(0).getT(0).getT(4).getT(1).                            // files_impl::midi_cc28_t<NV>
                          getT(7).getT(0).getT(2).getT(0);
		auto& add98 = this->getT(0).getT(0).getT(4).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(2).getT(1);
		auto& chain56 = this->getT(0).getT(0).getT(4).getT(1).getT(7).getT(0).getT(3);      // files_impl::chain56_t<NV>
		auto& midi_cc29 = this->getT(0).getT(0).getT(4).getT(1).                            // files_impl::midi_cc29_t<NV>
                          getT(7).getT(0).getT(3).getT(0);
		auto& add99 = this->getT(0).getT(0).getT(4).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(3).getT(1);
		auto& chain57 = this->getT(0).getT(0).getT(4).getT(1).getT(7).getT(0).getT(4);      // files_impl::chain57_t<NV>
		auto& midi19 = this->getT(0).getT(0).getT(4).getT(1).                               // files_impl::midi19_t<NV>
                       getT(7).getT(0).getT(4).getT(0);
		auto& add100 = this->getT(0).getT(0).getT(4).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(4).getT(1);
		auto& chain58 = this->getT(0).getT(0).getT(4).getT(1).getT(7).getT(0).getT(5);      // files_impl::chain58_t<NV>
		auto& midi20 = this->getT(0).getT(0).getT(4).getT(1).                               // files_impl::midi20_t<NV>
                       getT(7).getT(0).getT(5).getT(0);
		auto& add101 = this->getT(0).getT(0).getT(4).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(5).getT(1);
		auto& chain59 = this->getT(0).getT(0).getT(4).getT(1).getT(7).getT(0).getT(6);      // files_impl::chain59_t<NV>
		auto& midi21 = this->getT(0).getT(0).getT(4).getT(1).                               // files_impl::midi21_t<NV>
                       getT(7).getT(0).getT(6).getT(0);
		auto& add102 = this->getT(0).getT(0).getT(4).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(6).getT(1);
		auto& gain62 = this->getT(0).getT(0).getT(4).getT(1).getT(7).getT(1);               // core::gain<NV>
		auto& split14 = this->getT(0).getT(0).getT(4).getT(2);                              // files_impl::split14_t<NV>
		auto& peak9 = this->getT(0).getT(0).getT(4).getT(2).getT(0);                        // files_impl::peak9_t<NV>
		auto& split9 = this->getT(0).getT(0).getT(4).getT(3);                               // files_impl::split9_t<NV>
		auto& pma10 = this->getT(0).getT(0).getT(4).getT(3).getT(0);                        // files_impl::pma10_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(4).getT(3).getT(1);                         // files_impl::pma7_t<NV>
		auto& modchain5 = this->getT(0).getT(0).getT(5);                                    // files_impl::modchain5_t<NV>
		auto& sliderbank8 = this->getT(0).getT(0).getT(5).getT(0);                          // files_impl::sliderbank8_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(5).getT(1);                               // files_impl::split7_t<NV>
		auto& chain82 = this->getT(0).getT(0).getT(5).getT(1).getT(0);                      // files_impl::chain82_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(5).getT(1).getT(0).getT(0);        // files_impl::global_cable6_t<NV>
		auto& add11 = this->getT(0).getT(0).getT(5).getT(1).getT(0).getT(1);                // math::add<NV>
		auto& gain25 = this->getT(0).getT(0).getT(5).getT(1).getT(0).getT(2);               // core::gain<NV>
		auto& chain84 = this->getT(0).getT(0).getT(5).getT(1).getT(1);                      // files_impl::chain84_t<NV>
		auto& global_cable13 = this->getT(0).getT(0).getT(5).getT(1).getT(1).getT(0);       // files_impl::global_cable13_t<NV>
		auto& add53 = this->getT(0).getT(0).getT(5).getT(1).getT(1).getT(1);                // math::add<NV>
		auto& gain29 = this->getT(0).getT(0).getT(5).getT(1).getT(1).getT(2);               // core::gain<NV>
		auto& chain85 = this->getT(0).getT(0).getT(5).getT(1).getT(2);                      // files_impl::chain85_t<NV>
		auto& global_cable22 = this->getT(0).getT(0).getT(5).getT(1).getT(2).getT(0);       // files_impl::global_cable22_t<NV>
		auto& add12 = this->getT(0).getT(0).getT(5).getT(1).getT(2).getT(1);                // math::add<NV>
		auto& gain30 = this->getT(0).getT(0).getT(5).getT(1).getT(2).getT(2);               // core::gain<NV>
		auto& chain86 = this->getT(0).getT(0).getT(5).getT(1).getT(3);                      // files_impl::chain86_t<NV>
		auto& global_cable29 = this->getT(0).getT(0).getT(5).getT(1).getT(3).getT(0);       // files_impl::global_cable29_t<NV>
		auto& add59 = this->getT(0).getT(0).getT(5).getT(1).getT(3).getT(1);                // math::add<NV>
		auto& gain31 = this->getT(0).getT(0).getT(5).getT(1).getT(3).getT(2);               // core::gain<NV>
		auto& chain87 = this->getT(0).getT(0).getT(5).getT(1).getT(4);                      // files_impl::chain87_t<NV>
		auto& event_data_reader14 = this->getT(0).getT(0).getT(5).getT(1).getT(4).getT(0);  // files_impl::event_data_reader14_t<NV>
		auto& add81 = this->getT(0).getT(0).getT(5).getT(1).getT(4).getT(1);                // math::add<NV>
		auto& gain57 = this->getT(0).getT(0).getT(5).getT(1).getT(4).getT(2);               // core::gain<NV>
		auto& chain88 = this->getT(0).getT(0).getT(5).getT(1).getT(5);                      // files_impl::chain88_t<NV>
		auto& event_data_reader24 = this->getT(0).getT(0).getT(5).getT(1).getT(5).getT(0);  // files_impl::event_data_reader24_t<NV>
		auto& add82 = this->getT(0).getT(0).getT(5).getT(1).getT(5).getT(1);                // math::add<NV>
		auto& gain35 = this->getT(0).getT(0).getT(5).getT(1).getT(5).getT(2);               // core::gain<NV>
		auto& chain91 = this->getT(0).getT(0).getT(5).getT(1).getT(6);                      // files_impl::chain91_t<NV>
		auto& event_data_reader25 = this->getT(0).getT(0).getT(5).getT(1).getT(6).getT(0);  // routing::event_data_reader<NV>
		auto& add83 = this->getT(0).getT(0).getT(5).getT(1).getT(6).getT(1);                // math::add<NV>
		auto& gain58 = this->getT(0).getT(0).getT(5).getT(1).getT(6).getT(2);               // core::gain<NV>
		auto& chain92 = this->getT(0).getT(0).getT(5).getT(1).getT(7);                      // files_impl::chain92_t<NV>
		auto& branch9 = this->getT(0).getT(0).getT(5).getT(1).getT(7).getT(0);              // files_impl::branch9_t<NV>
		auto& chain37 = this->getT(0).getT(0).getT(5).getT(1).getT(7).getT(0).getT(0);      // files_impl::chain37_t<NV>
		auto& midi_cc22 = this->getT(0).getT(0).getT(5).getT(1).                            // files_impl::midi_cc22_t<NV>
                          getT(7).getT(0).getT(0).getT(0);
		auto& add84 = this->getT(0).getT(0).getT(5).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(0).getT(1);
		auto& chain38 = this->getT(0).getT(0).getT(5).getT(1).getT(7).getT(0).getT(1);      // files_impl::chain38_t<NV>
		auto& midi_cc23 = this->getT(0).getT(0).getT(5).getT(1).                            // files_impl::midi_cc23_t<NV>
                          getT(7).getT(0).getT(1).getT(0);
		auto& add85 = this->getT(0).getT(0).getT(5).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(1).getT(1);
		auto& chain48 = this->getT(0).getT(0).getT(5).getT(1).getT(7).getT(0).getT(2);      // files_impl::chain48_t<NV>
		auto& midi_cc24 = this->getT(0).getT(0).getT(5).getT(1).                            // files_impl::midi_cc24_t<NV>
                          getT(7).getT(0).getT(2).getT(0);
		auto& add86 = this->getT(0).getT(0).getT(5).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(2).getT(1);
		auto& chain49 = this->getT(0).getT(0).getT(5).getT(1).getT(7).getT(0).getT(3);      // files_impl::chain49_t<NV>
		auto& midi_cc25 = this->getT(0).getT(0).getT(5).getT(1).                            // files_impl::midi_cc25_t<NV>
                          getT(7).getT(0).getT(3).getT(0);
		auto& add87 = this->getT(0).getT(0).getT(5).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(3).getT(1);
		auto& chain50 = this->getT(0).getT(0).getT(5).getT(1).getT(7).getT(0).getT(4);      // files_impl::chain50_t<NV>
		auto& midi16 = this->getT(0).getT(0).getT(5).getT(1).                               // files_impl::midi16_t<NV>
                       getT(7).getT(0).getT(4).getT(0);
		auto& add88 = this->getT(0).getT(0).getT(5).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(4).getT(1);
		auto& chain51 = this->getT(0).getT(0).getT(5).getT(1).getT(7).getT(0).getT(5);      // files_impl::chain51_t<NV>
		auto& midi17 = this->getT(0).getT(0).getT(5).getT(1).                               // files_impl::midi17_t<NV>
                       getT(7).getT(0).getT(5).getT(0);
		auto& add89 = this->getT(0).getT(0).getT(5).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(5).getT(1);
		auto& chain52 = this->getT(0).getT(0).getT(5).getT(1).getT(7).getT(0).getT(6);      // files_impl::chain52_t<NV>
		auto& midi18 = this->getT(0).getT(0).getT(5).getT(1).                               // files_impl::midi18_t<NV>
                       getT(7).getT(0).getT(6).getT(0);
		auto& add90 = this->getT(0).getT(0).getT(5).getT(1).                                // math::add<NV>
                      getT(7).getT(0).getT(6).getT(1);
		auto& gain59 = this->getT(0).getT(0).getT(5).getT(1).getT(7).getT(1);               // core::gain<NV>
		auto& split13 = this->getT(0).getT(0).getT(5).getT(2);                              // files_impl::split13_t<NV>
		auto& peak8 = this->getT(0).getT(0).getT(5).getT(2).getT(0);                        // files_impl::peak8_t<NV>
		auto& split10 = this->getT(0).getT(0).getT(5).getT(3);                              // files_impl::split10_t<NV>
		auto& pma11 = this->getT(0).getT(0).getT(5).getT(3).getT(0);                        // files_impl::pma11_t<NV>
		auto& pma9 = this->getT(0).getT(0).getT(5).getT(3).getT(1);                         // files_impl::pma9_t<NV>
		auto& modchain7 = this->getT(0).getT(0).getT(6);                                    // files_impl::modchain7_t<NV>
		auto& sliderbank10 = this->getT(0).getT(0).getT(6).getT(0);                         // files_impl::sliderbank10_t<NV>
		auto& split15 = this->getT(0).getT(0).getT(6).getT(1);                              // files_impl::split15_t<NV>
		auto& chain101 = this->getT(0).getT(0).getT(6).getT(1).getT(0);                     // files_impl::chain101_t<NV>
		auto& global_cable8 = this->getT(0).getT(0).getT(6).getT(1).getT(0).getT(0);        // files_impl::global_cable8_t<NV>
		auto& add15 = this->getT(0).getT(0).getT(6).getT(1).getT(0).getT(1);                // math::add<NV>
		auto& gain41 = this->getT(0).getT(0).getT(6).getT(1).getT(0).getT(2);               // core::gain<NV>
		auto& chain102 = this->getT(0).getT(0).getT(6).getT(1).getT(1);                     // files_impl::chain102_t<NV>
		auto& global_cable15 = this->getT(0).getT(0).getT(6).getT(1).getT(1).getT(0);       // files_impl::global_cable15_t<NV>
		auto& add103 = this->getT(0).getT(0).getT(6).getT(1).getT(1).getT(1);               // math::add<NV>
		auto& gain42 = this->getT(0).getT(0).getT(6).getT(1).getT(1).getT(2);               // core::gain<NV>
		auto& chain103 = this->getT(0).getT(0).getT(6).getT(1).getT(2);                     // files_impl::chain103_t<NV>
		auto& global_cable24 = this->getT(0).getT(0).getT(6).getT(1).getT(2).getT(0);       // files_impl::global_cable24_t<NV>
		auto& add16 = this->getT(0).getT(0).getT(6).getT(1).getT(2).getT(1);                // math::add<NV>
		auto& gain43 = this->getT(0).getT(0).getT(6).getT(1).getT(2).getT(2);               // core::gain<NV>
		auto& chain104 = this->getT(0).getT(0).getT(6).getT(1).getT(3);                     // files_impl::chain104_t<NV>
		auto& global_cable30 = this->getT(0).getT(0).getT(6).getT(1).getT(3).getT(0);       // files_impl::global_cable30_t<NV>
		auto& add104 = this->getT(0).getT(0).getT(6).getT(1).getT(3).getT(1);               // math::add<NV>
		auto& gain44 = this->getT(0).getT(0).getT(6).getT(1).getT(3).getT(2);               // core::gain<NV>
		auto& chain105 = this->getT(0).getT(0).getT(6).getT(1).getT(4);                     // files_impl::chain105_t<NV>
		auto& event_data_reader16 = this->getT(0).getT(0).getT(6).getT(1).getT(4).getT(0);  // files_impl::event_data_reader16_t<NV>
		auto& add105 = this->getT(0).getT(0).getT(6).getT(1).getT(4).getT(1);               // math::add<NV>
		auto& gain63 = this->getT(0).getT(0).getT(6).getT(1).getT(4).getT(2);               // core::gain<NV>
		auto& chain106 = this->getT(0).getT(0).getT(6).getT(1).getT(5);                     // files_impl::chain106_t<NV>
		auto& event_data_reader28 = this->getT(0).getT(0).getT(6).getT(1).getT(5).getT(0);  // files_impl::event_data_reader28_t<NV>
		auto& add106 = this->getT(0).getT(0).getT(6).getT(1).getT(5).getT(1);               // math::add<NV>
		auto& gain45 = this->getT(0).getT(0).getT(6).getT(1).getT(5).getT(2);               // core::gain<NV>
		auto& chain107 = this->getT(0).getT(0).getT(6).getT(1).getT(6);                     // files_impl::chain107_t<NV>
		auto& event_data_reader29 = this->getT(0).getT(0).getT(6).getT(1).getT(6).getT(0);  // routing::event_data_reader<NV>
		auto& add107 = this->getT(0).getT(0).getT(6).getT(1).getT(6).getT(1);               // math::add<NV>
		auto& gain64 = this->getT(0).getT(0).getT(6).getT(1).getT(6).getT(2);               // core::gain<NV>
		auto& chain108 = this->getT(0).getT(0).getT(6).getT(1).getT(7);                     // files_impl::chain108_t<NV>
		auto& branch11 = this->getT(0).getT(0).getT(6).getT(1).getT(7).getT(0);             // files_impl::branch11_t<NV>
		auto& chain60 = this->getT(0).getT(0).getT(6).getT(1).getT(7).getT(0).getT(0);      // files_impl::chain60_t<NV>
		auto& midi_cc30 = this->getT(0).getT(0).getT(6).getT(1).                            // files_impl::midi_cc30_t<NV>
                          getT(7).getT(0).getT(0).getT(0);
		auto& add108 = this->getT(0).getT(0).getT(6).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(0).getT(1);
		auto& chain61 = this->getT(0).getT(0).getT(6).getT(1).getT(7).getT(0).getT(1);      // files_impl::chain61_t<NV>
		auto& midi_cc31 = this->getT(0).getT(0).getT(6).getT(1).                            // files_impl::midi_cc31_t<NV>
                          getT(7).getT(0).getT(1).getT(0);
		auto& add109 = this->getT(0).getT(0).getT(6).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(1).getT(1);
		auto& chain62 = this->getT(0).getT(0).getT(6).getT(1).getT(7).getT(0).getT(2);      // files_impl::chain62_t<NV>
		auto& midi_cc32 = this->getT(0).getT(0).getT(6).getT(1).                            // files_impl::midi_cc32_t<NV>
                          getT(7).getT(0).getT(2).getT(0);
		auto& add110 = this->getT(0).getT(0).getT(6).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(2).getT(1);
		auto& chain63 = this->getT(0).getT(0).getT(6).getT(1).getT(7).getT(0).getT(3);      // files_impl::chain63_t<NV>
		auto& midi_cc33 = this->getT(0).getT(0).getT(6).getT(1).                            // files_impl::midi_cc33_t<NV>
                          getT(7).getT(0).getT(3).getT(0);
		auto& add111 = this->getT(0).getT(0).getT(6).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(3).getT(1);
		auto& chain109 = this->getT(0).getT(0).getT(6).getT(1).getT(7).getT(0).getT(4);     // files_impl::chain109_t<NV>
		auto& midi22 = this->getT(0).getT(0).getT(6).getT(1).                               // files_impl::midi22_t<NV>
                       getT(7).getT(0).getT(4).getT(0);
		auto& add112 = this->getT(0).getT(0).getT(6).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(4).getT(1);
		auto& chain110 = this->getT(0).getT(0).getT(6).getT(1).getT(7).getT(0).getT(5);     // files_impl::chain110_t<NV>
		auto& midi23 = this->getT(0).getT(0).getT(6).getT(1).                               // files_impl::midi23_t<NV>
                       getT(7).getT(0).getT(5).getT(0);
		auto& add113 = this->getT(0).getT(0).getT(6).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(5).getT(1);
		auto& chain111 = this->getT(0).getT(0).getT(6).getT(1).getT(7).getT(0).getT(6);     // files_impl::chain111_t<NV>
		auto& midi24 = this->getT(0).getT(0).getT(6).getT(1).                               // files_impl::midi24_t<NV>
                       getT(7).getT(0).getT(6).getT(0);
		auto& add114 = this->getT(0).getT(0).getT(6).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(6).getT(1);
		auto& gain65 = this->getT(0).getT(0).getT(6).getT(1).getT(7).getT(1);               // core::gain<NV>
		auto& split16 = this->getT(0).getT(0).getT(6).getT(2);                              // files_impl::split16_t<NV>
		auto& peak10 = this->getT(0).getT(0).getT(6).getT(2).getT(0);                       // files_impl::peak10_t<NV>
		auto& split17 = this->getT(0).getT(0).getT(6).getT(3);                              // files_impl::split17_t<NV>
		auto& pma12 = this->getT(0).getT(0).getT(6).getT(3).getT(0);                        // files_impl::pma12_t<NV>
		auto& modchain8 = this->getT(0).getT(0).getT(7);                                    // files_impl::modchain8_t<NV>
		auto& sliderbank11 = this->getT(0).getT(0).getT(7).getT(0);                         // files_impl::sliderbank11_t<NV>
		auto& split18 = this->getT(0).getT(0).getT(7).getT(1);                              // files_impl::split18_t<NV>
		auto& chain115 = this->getT(0).getT(0).getT(7).getT(1).getT(0);                     // files_impl::chain115_t<NV>
		auto& global_cable9 = this->getT(0).getT(0).getT(7).getT(1).getT(0).getT(0);        // files_impl::global_cable9_t<NV>
		auto& add19 = this->getT(0).getT(0).getT(7).getT(1).getT(0).getT(1);                // math::add<NV>
		auto& gain46 = this->getT(0).getT(0).getT(7).getT(1).getT(0).getT(2);               // core::gain<NV>
		auto& chain116 = this->getT(0).getT(0).getT(7).getT(1).getT(1);                     // files_impl::chain116_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(7).getT(1).getT(1).getT(0);       // files_impl::global_cable16_t<NV>
		auto& add115 = this->getT(0).getT(0).getT(7).getT(1).getT(1).getT(1);               // math::add<NV>
		auto& gain47 = this->getT(0).getT(0).getT(7).getT(1).getT(1).getT(2);               // core::gain<NV>
		auto& chain117 = this->getT(0).getT(0).getT(7).getT(1).getT(2);                     // files_impl::chain117_t<NV>
		auto& global_cable31 = this->getT(0).getT(0).getT(7).getT(1).getT(2).getT(0);       // files_impl::global_cable31_t<NV>
		auto& add20 = this->getT(0).getT(0).getT(7).getT(1).getT(2).getT(1);                // math::add<NV>
		auto& gain48 = this->getT(0).getT(0).getT(7).getT(1).getT(2).getT(2);               // core::gain<NV>
		auto& chain118 = this->getT(0).getT(0).getT(7).getT(1).getT(3);                     // files_impl::chain118_t<NV>
		auto& global_cable32 = this->getT(0).getT(0).getT(7).getT(1).getT(3).getT(0);       // files_impl::global_cable32_t<NV>
		auto& add116 = this->getT(0).getT(0).getT(7).getT(1).getT(3).getT(1);               // math::add<NV>
		auto& gain49 = this->getT(0).getT(0).getT(7).getT(1).getT(3).getT(2);               // core::gain<NV>
		auto& chain119 = this->getT(0).getT(0).getT(7).getT(1).getT(4);                     // files_impl::chain119_t<NV>
		auto& event_data_reader17 = this->getT(0).getT(0).getT(7).getT(1).getT(4).getT(0);  // files_impl::event_data_reader17_t<NV>
		auto& add117 = this->getT(0).getT(0).getT(7).getT(1).getT(4).getT(1);               // math::add<NV>
		auto& gain66 = this->getT(0).getT(0).getT(7).getT(1).getT(4).getT(2);               // core::gain<NV>
		auto& chain120 = this->getT(0).getT(0).getT(7).getT(1).getT(5);                     // files_impl::chain120_t<NV>
		auto& event_data_reader30 = this->getT(0).getT(0).getT(7).getT(1).getT(5).getT(0);  // files_impl::event_data_reader30_t<NV>
		auto& add118 = this->getT(0).getT(0).getT(7).getT(1).getT(5).getT(1);               // math::add<NV>
		auto& gain50 = this->getT(0).getT(0).getT(7).getT(1).getT(5).getT(2);               // core::gain<NV>
		auto& chain121 = this->getT(0).getT(0).getT(7).getT(1).getT(6);                     // files_impl::chain121_t<NV>
		auto& event_data_reader31 = this->getT(0).getT(0).getT(7).getT(1).getT(6).getT(0);  // routing::event_data_reader<NV>
		auto& add119 = this->getT(0).getT(0).getT(7).getT(1).getT(6).getT(1);               // math::add<NV>
		auto& gain67 = this->getT(0).getT(0).getT(7).getT(1).getT(6).getT(2);               // core::gain<NV>
		auto& chain122 = this->getT(0).getT(0).getT(7).getT(1).getT(7);                     // files_impl::chain122_t<NV>
		auto& branch12 = this->getT(0).getT(0).getT(7).getT(1).getT(7).getT(0);             // files_impl::branch12_t<NV>
		auto& chain123 = this->getT(0).getT(0).getT(7).getT(1).getT(7).getT(0).getT(0);     // files_impl::chain123_t<NV>
		auto& midi_cc34 = this->getT(0).getT(0).getT(7).getT(1).                            // files_impl::midi_cc34_t<NV>
                          getT(7).getT(0).getT(0).getT(0);
		auto& add120 = this->getT(0).getT(0).getT(7).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(0).getT(1);
		auto& chain124 = this->getT(0).getT(0).getT(7).getT(1).getT(7).getT(0).getT(1);     // files_impl::chain124_t<NV>
		auto& midi_cc35 = this->getT(0).getT(0).getT(7).getT(1).                            // files_impl::midi_cc35_t<NV>
                          getT(7).getT(0).getT(1).getT(0);
		auto& add121 = this->getT(0).getT(0).getT(7).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(1).getT(1);
		auto& chain125 = this->getT(0).getT(0).getT(7).getT(1).getT(7).getT(0).getT(2);     // files_impl::chain125_t<NV>
		auto& midi_cc36 = this->getT(0).getT(0).getT(7).getT(1).                            // files_impl::midi_cc36_t<NV>
                          getT(7).getT(0).getT(2).getT(0);
		auto& add122 = this->getT(0).getT(0).getT(7).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(2).getT(1);
		auto& chain126 = this->getT(0).getT(0).getT(7).getT(1).getT(7).getT(0).getT(3);     // files_impl::chain126_t<NV>
		auto& midi_cc37 = this->getT(0).getT(0).getT(7).getT(1).                            // files_impl::midi_cc37_t<NV>
                          getT(7).getT(0).getT(3).getT(0);
		auto& add123 = this->getT(0).getT(0).getT(7).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(3).getT(1);
		auto& chain127 = this->getT(0).getT(0).getT(7).getT(1).getT(7).getT(0).getT(4);     // files_impl::chain127_t<NV>
		auto& midi25 = this->getT(0).getT(0).getT(7).getT(1).                               // files_impl::midi25_t<NV>
                       getT(7).getT(0).getT(4).getT(0);
		auto& add124 = this->getT(0).getT(0).getT(7).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(4).getT(1);
		auto& chain128 = this->getT(0).getT(0).getT(7).getT(1).getT(7).getT(0).getT(5);     // files_impl::chain128_t<NV>
		auto& midi26 = this->getT(0).getT(0).getT(7).getT(1).                               // files_impl::midi26_t<NV>
                       getT(7).getT(0).getT(5).getT(0);
		auto& add132 = this->getT(0).getT(0).getT(7).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(5).getT(1);
		auto& chain129 = this->getT(0).getT(0).getT(7).getT(1).getT(7).getT(0).getT(6);     // files_impl::chain129_t<NV>
		auto& midi27 = this->getT(0).getT(0).getT(7).getT(1).                               // files_impl::midi27_t<NV>
                       getT(7).getT(0).getT(6).getT(0);
		auto& add133 = this->getT(0).getT(0).getT(7).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(6).getT(1);
		auto& gain68 = this->getT(0).getT(0).getT(7).getT(1).getT(7).getT(1);               // core::gain<NV>
		auto& split19 = this->getT(0).getT(0).getT(7).getT(2);                              // files_impl::split19_t<NV>
		auto& peak11 = this->getT(0).getT(0).getT(7).getT(2).getT(0);                       // files_impl::peak11_t<NV>
		auto& split20 = this->getT(0).getT(0).getT(7).getT(3);                              // files_impl::split20_t<NV>
		auto& pma14 = this->getT(0).getT(0).getT(7).getT(3).getT(0);                        // files_impl::pma14_t<NV>
		auto& modchain9 = this->getT(0).getT(0).getT(8);                                    // files_impl::modchain9_t<NV>
		auto& sliderbank12 = this->getT(0).getT(0).getT(8).getT(0);                         // files_impl::sliderbank12_t<NV>
		auto& split21 = this->getT(0).getT(0).getT(8).getT(1);                              // files_impl::split21_t<NV>
		auto& chain130 = this->getT(0).getT(0).getT(8).getT(1).getT(0);                     // files_impl::chain130_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(8).getT(1).getT(0).getT(0);       // files_impl::global_cable17_t<NV>
		auto& add21 = this->getT(0).getT(0).getT(8).getT(1).getT(0).getT(1);                // math::add<NV>
		auto& gain69 = this->getT(0).getT(0).getT(8).getT(1).getT(0).getT(2);               // core::gain<NV>
		auto& chain131 = this->getT(0).getT(0).getT(8).getT(1).getT(1);                     // files_impl::chain131_t<NV>
		auto& global_cable18 = this->getT(0).getT(0).getT(8).getT(1).getT(1).getT(0);       // files_impl::global_cable18_t<NV>
		auto& add134 = this->getT(0).getT(0).getT(8).getT(1).getT(1).getT(1);               // math::add<NV>
		auto& gain70 = this->getT(0).getT(0).getT(8).getT(1).getT(1).getT(2);               // core::gain<NV>
		auto& chain132 = this->getT(0).getT(0).getT(8).getT(1).getT(2);                     // files_impl::chain132_t<NV>
		auto& global_cable33 = this->getT(0).getT(0).getT(8).getT(1).getT(2).getT(0);       // files_impl::global_cable33_t<NV>
		auto& add22 = this->getT(0).getT(0).getT(8).getT(1).getT(2).getT(1);                // math::add<NV>
		auto& gain71 = this->getT(0).getT(0).getT(8).getT(1).getT(2).getT(2);               // core::gain<NV>
		auto& chain133 = this->getT(0).getT(0).getT(8).getT(1).getT(3);                     // files_impl::chain133_t<NV>
		auto& global_cable34 = this->getT(0).getT(0).getT(8).getT(1).getT(3).getT(0);       // files_impl::global_cable34_t<NV>
		auto& add135 = this->getT(0).getT(0).getT(8).getT(1).getT(3).getT(1);               // math::add<NV>
		auto& gain72 = this->getT(0).getT(0).getT(8).getT(1).getT(3).getT(2);               // core::gain<NV>
		auto& chain134 = this->getT(0).getT(0).getT(8).getT(1).getT(4);                     // files_impl::chain134_t<NV>
		auto& event_data_reader18 = this->getT(0).getT(0).getT(8).getT(1).getT(4).getT(0);  // files_impl::event_data_reader18_t<NV>
		auto& add136 = this->getT(0).getT(0).getT(8).getT(1).getT(4).getT(1);               // math::add<NV>
		auto& gain73 = this->getT(0).getT(0).getT(8).getT(1).getT(4).getT(2);               // core::gain<NV>
		auto& chain135 = this->getT(0).getT(0).getT(8).getT(1).getT(5);                     // files_impl::chain135_t<NV>
		auto& event_data_reader32 = this->getT(0).getT(0).getT(8).getT(1).getT(5).getT(0);  // files_impl::event_data_reader32_t<NV>
		auto& add137 = this->getT(0).getT(0).getT(8).getT(1).getT(5).getT(1);               // math::add<NV>
		auto& gain74 = this->getT(0).getT(0).getT(8).getT(1).getT(5).getT(2);               // core::gain<NV>
		auto& chain136 = this->getT(0).getT(0).getT(8).getT(1).getT(6);                     // files_impl::chain136_t<NV>
		auto& event_data_reader33 = this->getT(0).getT(0).getT(8).getT(1).getT(6).getT(0);  // routing::event_data_reader<NV>
		auto& add138 = this->getT(0).getT(0).getT(8).getT(1).getT(6).getT(1);               // math::add<NV>
		auto& gain75 = this->getT(0).getT(0).getT(8).getT(1).getT(6).getT(2);               // core::gain<NV>
		auto& chain137 = this->getT(0).getT(0).getT(8).getT(1).getT(7);                     // files_impl::chain137_t<NV>
		auto& branch13 = this->getT(0).getT(0).getT(8).getT(1).getT(7).getT(0);             // files_impl::branch13_t<NV>
		auto& chain138 = this->getT(0).getT(0).getT(8).getT(1).getT(7).getT(0).getT(0);     // files_impl::chain138_t<NV>
		auto& midi_cc38 = this->getT(0).getT(0).getT(8).getT(1).                            // files_impl::midi_cc38_t<NV>
                          getT(7).getT(0).getT(0).getT(0);
		auto& add139 = this->getT(0).getT(0).getT(8).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(0).getT(1);
		auto& chain139 = this->getT(0).getT(0).getT(8).getT(1).getT(7).getT(0).getT(1);     // files_impl::chain139_t<NV>
		auto& midi_cc39 = this->getT(0).getT(0).getT(8).getT(1).                            // files_impl::midi_cc39_t<NV>
                          getT(7).getT(0).getT(1).getT(0);
		auto& add140 = this->getT(0).getT(0).getT(8).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(1).getT(1);
		auto& chain140 = this->getT(0).getT(0).getT(8).getT(1).getT(7).getT(0).getT(2);     // files_impl::chain140_t<NV>
		auto& midi_cc40 = this->getT(0).getT(0).getT(8).getT(1).                            // files_impl::midi_cc40_t<NV>
                          getT(7).getT(0).getT(2).getT(0);
		auto& add141 = this->getT(0).getT(0).getT(8).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(2).getT(1);
		auto& chain141 = this->getT(0).getT(0).getT(8).getT(1).getT(7).getT(0).getT(3);     // files_impl::chain141_t<NV>
		auto& midi_cc41 = this->getT(0).getT(0).getT(8).getT(1).                            // files_impl::midi_cc41_t<NV>
                          getT(7).getT(0).getT(3).getT(0);
		auto& add142 = this->getT(0).getT(0).getT(8).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(3).getT(1);
		auto& chain142 = this->getT(0).getT(0).getT(8).getT(1).getT(7).getT(0).getT(4);     // files_impl::chain142_t<NV>
		auto& midi28 = this->getT(0).getT(0).getT(8).getT(1).                               // files_impl::midi28_t<NV>
                       getT(7).getT(0).getT(4).getT(0);
		auto& add143 = this->getT(0).getT(0).getT(8).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(4).getT(1);
		auto& chain143 = this->getT(0).getT(0).getT(8).getT(1).getT(7).getT(0).getT(5);     // files_impl::chain143_t<NV>
		auto& midi29 = this->getT(0).getT(0).getT(8).getT(1).                               // files_impl::midi29_t<NV>
                       getT(7).getT(0).getT(5).getT(0);
		auto& add144 = this->getT(0).getT(0).getT(8).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(5).getT(1);
		auto& chain144 = this->getT(0).getT(0).getT(8).getT(1).getT(7).getT(0).getT(6);     // files_impl::chain144_t<NV>
		auto& midi30 = this->getT(0).getT(0).getT(8).getT(1).                               // files_impl::midi30_t<NV>
                       getT(7).getT(0).getT(6).getT(0);
		auto& add145 = this->getT(0).getT(0).getT(8).getT(1).                               // math::add<NV>
                       getT(7).getT(0).getT(6).getT(1);
		auto& gain76 = this->getT(0).getT(0).getT(8).getT(1).getT(7).getT(1);               // core::gain<NV>
		auto& split22 = this->getT(0).getT(0).getT(8).getT(2);                              // files_impl::split22_t<NV>
		auto& peak12 = this->getT(0).getT(0).getT(8).getT(2).getT(0);                       // files_impl::peak12_t<NV>
		auto& split23 = this->getT(0).getT(0).getT(8).getT(3);                              // files_impl::split23_t<NV>
		auto& pma15 = this->getT(0).getT(0).getT(8).getT(3).getT(0);                        // files_impl::pma15_t<NV>
		auto& chain4 = this->getT(0).getT(1);                                               // files_impl::chain4_t<NV>
		auto& xfader = this->getT(0).getT(1).getT(0);                                       // files_impl::xfader_t<NV>
		auto& split = this->getT(0).getT(1).getT(1);                                        // files_impl::split_t<NV>
		auto& chain = this->getT(0).getT(1).getT(1).getT(0);                                // files_impl::chain_t<NV>
		auto& gain1 = this->getT(0).getT(1).getT(1).getT(0).getT(0);                        // core::gain<NV>
		auto& chain3 = this->getT(0).getT(1).getT(1).getT(1);                               // files_impl::chain3_t<NV>
		auto& cable_table9 = this->getT(0).getT(1).getT(1).getT(1).getT(0);                 // files_impl::cable_table9_t<NV>
		auto& branch4 = this->getT(0).getT(1).getT(1).getT(1).getT(1);                      // files_impl::branch4_t<NV>
		auto& chain145 = this->getT(0).getT(1).getT(1).getT(1).getT(1).getT(0);             // files_impl::chain145_t
		auto& clear4 = this->getT(0).getT(1).getT(1).getT(1).getT(1).getT(1);               // math::clear<NV>
		auto& gain3 = this->getT(0).getT(1).getT(1).getT(1).getT(2);                        // core::gain<NV>
		auto& chain11 = this->getT(0).getT(1).getT(1).getT(1).getT(3);                      // files_impl::chain11_t<NV>
		auto& chain21 = this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(0);              // files_impl::chain21_t<NV>
		auto& mono2stereo = this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(0).getT(0);  // wrap::no_process<core::mono2stereo>
		auto& chain8 = this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(0).getT(1);       // files_impl::chain8_t<NV>
		auto& modchain1 = this->getT(0).getT(1).getT(1).getT(1).                            // files_impl::modchain1_t<NV>
                          getT(3).getT(0).getT(1).getT(0);
		auto& branch8 = this->getT(0).getT(1).getT(1).getT(1).                              // files_impl::branch8_t<NV>
                        getT(3).getT(0).getT(1).getT(0).
                        getT(0);
		auto& add1 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                         // math::add<NV>
                     getT(0).getT(1).getT(0).getT(0).getT(0);
		auto& chain6 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                       // files_impl::chain6_t<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(1);
		auto& minmax3 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                      // files_impl::minmax3_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(1).
                        getT(0);
		auto& add125 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                       // math::add<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(1).
                       getT(1);
		auto& chain15 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                      // files_impl::chain15_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2);
		auto& minmax5 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                      // files_impl::minmax5_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(2).
                        getT(0);
		auto& add131 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                       // math::add<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(2).
                       getT(1);
		auto& chain89 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                      // files_impl::chain89_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(3);
		auto& minmax12 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                     // files_impl::minmax12_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(3).
                         getT(0);
		auto& add126 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                       // math::add<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(3).
                       getT(1);
		auto& chain83 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                      // files_impl::chain83_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(4);
		auto& minmax10 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                     // files_impl::minmax10_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(4).
                         getT(0);
		auto& add127 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                       // math::add<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(4).
                       getT(1);
		auto& chain79 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                      // files_impl::chain79_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(5);
		auto& minmax9 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                      // files_impl::minmax9_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(5).
                        getT(0);
		auto& add128 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                       // math::add<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(5).
                       getT(1);
		auto& chain78 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                      // files_impl::chain78_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(6);
		auto& minmax8 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                      // files_impl::minmax8_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(6).
                        getT(0);
		auto& add129 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                       // math::add<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(6).
                       getT(1);
		auto& chain43 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                      // files_impl::chain43_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(7);
		auto& minmax4 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                      // files_impl::minmax4_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(7).
                        getT(0);
		auto& add130 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                       // math::add<NV>
                       getT(0).getT(1).getT(0).getT(0).getT(7).
                       getT(1);
		auto& chain90 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                      // files_impl::chain90_t<NV>
                        getT(0).getT(1).getT(0).getT(0).getT(8);
		auto& minmax13 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                     // files_impl::minmax13_t<NV>
                         getT(0).getT(1).getT(0).getT(0).getT(8).
                         getT(0);
		auto& add3 = this->getT(0).getT(1).getT(1).getT(1).getT(3).                         // math::add<NV>
                     getT(0).getT(1).getT(0).getT(0).getT(8).
                     getT(1);
		auto& peak = this->getT(0).getT(1).getT(1).getT(1).                                 // files_impl::peak_t<NV>
                     getT(3).getT(0).getT(1).getT(0).
                     getT(1);
		auto& oscilloscope = this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(1);         // files_impl::oscilloscope_t
		auto& smoother10 = this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(2);           // core::smoother<NV>
		auto& add = this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(3);                  // math::add<NV>
		auto& branch2 = this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(4);              // files_impl::branch2_t<NV>
		auto& file_player4 = this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(4).getT(0); // files_impl::file_player4_t<NV>
		auto& file_player5 = this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(4).getT(1); // files_impl::file_player5_t<NV>
		auto& split5 = this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(5);               // files_impl::split5_t<NV>
		auto& chain12 = this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(5).getT(0);      // files_impl::chain12_t<NV>
		auto& split11 = this->getT(0).getT(1).getT(1).getT(1).                              // files_impl::split11_t<NV>
                        getT(3).getT(5).getT(0).getT(0);
		auto& cable_table2 = this->getT(0).getT(1).getT(1).getT(1).                    // files_impl::cable_table2_t<NV>
                             getT(3).getT(5).getT(0).getT(0).
                             getT(0);
		auto& cable_table3 = this->getT(0).getT(1).getT(1).getT(1).                    // files_impl::cable_table3_t<NV>
                             getT(3).getT(5).getT(0).getT(0).
                             getT(1);
		auto& tempo_sync1 = this->getT(0).getT(1).getT(1).getT(1).                     // files_impl::tempo_sync1_t<NV>
                            getT(3).getT(5).getT(0).getT(1);
		auto& converter = this->getT(0).getT(1).getT(1).getT(1).                       // files_impl::converter_t<NV>
                          getT(3).getT(5).getT(0).getT(2);
		auto& chain17 = this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(5).getT(1); // files_impl::chain17_t<NV>
		auto& split12 = this->getT(0).getT(1).getT(1).getT(1).                         // files_impl::split12_t<NV>
                        getT(3).getT(5).getT(1).getT(0);
		auto& cable_table4 = this->getT(0).getT(1).getT(1).getT(1).                    // files_impl::cable_table4_t<NV>
                             getT(3).getT(5).getT(1).getT(0).
                             getT(0);
		auto& cable_table5 = this->getT(0).getT(1).getT(1).getT(1).                    // files_impl::cable_table5_t<NV>
                             getT(3).getT(5).getT(1).getT(0).
                             getT(1);
		auto& tempo_sync3 = this->getT(0).getT(1).getT(1).getT(1).                     // files_impl::tempo_sync3_t<NV>
                            getT(3).getT(5).getT(1).getT(1);
		auto& converter1 = this->getT(0).getT(1).getT(1).getT(1).                      // files_impl::converter1_t<NV>
                           getT(3).getT(5).getT(1).getT(2);
		auto& branch = this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(6);          // files_impl::branch_t<NV>
		auto& chain1 = this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(6).getT(0);  // files_impl::chain1_t<NV>
		auto& tanh1 = this->getT(0).getT(1).getT(1).getT(1).                           // wrap::no_process<math::tanh<NV>>
                      getT(3).getT(6).getT(0).getT(0);
		auto& chain2 = this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(6).getT(1);  // files_impl::chain2_t<NV>
		auto& receive = this->getT(0).getT(1).getT(1).getT(1).                         // routing::receive<stereo_cable>
                        getT(3).getT(6).getT(1).getT(0);
		auto& faust = this->getT(0).getT(1).getT(1).getT(1).                           // project::shfiter<NV>
                      getT(3).getT(6).getT(1).getT(1);
		auto& send = this->getT(0).getT(1).getT(1).getT(1).                            // routing::send<stereo_cable>
                     getT(3).getT(6).getT(1).getT(2);
		auto& chain10 = this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(6).getT(2); // files_impl::chain10_t<NV>
		auto& midi4 = this->getT(0).getT(1).getT(1).getT(1).                           // files_impl::midi4_t<NV>
                      getT(3).getT(6).getT(2).getT(0);
		auto& cable_table1 = this->getT(0).getT(1).getT(1).getT(1).  // files_impl::cable_table1_t<NV>
                             getT(3).getT(6).getT(2).getT(1);
		auto& faust1 = this->getT(0).getT(1).getT(1).getT(1).        // project::ps2<NV>
                       getT(3).getT(6).getT(2).getT(2);
		auto& faust2 = this->getT(0).getT(1).getT(1).getT(1).        // project::shfiter<NV>
                       getT(3).getT(6).getT(2).getT(3);
		auto& receive1 = this->getT(0).getT(1).getT(1).getT(1).      // routing::receive<stereo_cable>
                         getT(3).getT(6).getT(2).getT(4);
		auto& send1 = this->getT(0).getT(1).getT(1).getT(1).         // routing::send<stereo_cable>
                      getT(3).getT(6).getT(2).getT(5);
		auto& gain2 = this->getT(0).getT(1).getT(1).getT(1).getT(4); // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma14); // smooth -> pma14::Add
		
		this->getParameterT(1).connectT(0, branch8); // quant -> branch8::Index
		
		auto& Position_p = this->getParameterT(2);
		Position_p.connectT(0, pma2);         // Position -> pma2::Add
		Position_p.connectT(1, cable_table8); // Position -> cable_table8::Value
		
		this->getParameterT(3).connectT(0, pma3); // Input -> pma3::Add
		
		this->getParameterT(4).connectT(0, pma10); // Win -> pma10::Add
		
		this->getParameterT(5).connectT(0, pma11); // Xf -> pma11::Add
		
		this->getParameterT(6).connectT(0, branch); // shift -> branch::Index
		
		this->getParameterT(7).connectT(0, pma4); // pitch -> pma4::Add
		
		this->getParameterT(8).connectT(0, pma15); // Mix -> pma15::Add
		
		this->getParameterT(9).connectT(0, pma2); // PositionTempoMod -> pma2::Multiply
		
		this->getParameterT(10).connectT(0, pma4); // PitchMod -> pma4::Multiply
		
		this->getParameterT(11).connectT(0, pma3); // InputMod -> pma3::Multiply
		
		this->getParameterT(12).connectT(0, event_data_reader13); // XfStage -> event_data_reader13::SlotIndex
		
		this->getParameterT(13).connectT(0, pma1); // IntMod -> pma1::Multiply
		
		this->getParameterT(14).connectT(0, pack_resizer); // IntModSteps -> pack_resizer::NumSliders
		
		this->getParameterT(15).connectT(0, ramp); // IntmodOne -> ramp::LoopStart
		
		this->getParameterT(16).connectT(0, pma12); // intmodtempo -> pma12::Add
		
		auto& InmodDiv_p = this->getParameterT(17);
		InmodDiv_p.connectT(0, tempo_sync); // InmodDiv -> tempo_sync::Multiplier
		InmodDiv_p.connectT(1, clock_ramp); // InmodDiv -> clock_ramp::Multiplier
		
		auto& fb_p = this->getParameterT(18);
		fb_p.connectT(0, receive);  // fb -> receive::Feedback
		fb_p.connectT(1, receive1); // fb -> receive1::Feedback
		
		this->getParameterT(19).connectT(0, branch1); // tablestep -> branch1::Index
		
		this->getParameterT(20).connectT(0, branch5); // Midi1 -> branch5::Index
		
		this->getParameterT(21).connectT(0, branch6); // Midi2 -> branch6::Index
		
		this->getParameterT(22).connectT(0, branch7); // Midi3 -> branch7::Index
		
		this->getParameterT(23).connectT(0, event_data_reader22); // xf2 -> event_data_reader22::SlotIndex
		
		this->getParameterT(24).connectT(0, event_data_reader23); // xf3 -> event_data_reader23::SlotIndex
		
		this->getParameterT(25).connectT(0, branch2); // UserMode -> branch2::Index
		
		auto& WinSync_p = this->getParameterT(26);
		WinSync_p.connectT(0, tempo_sync1); // WinSync -> tempo_sync1::Enabled
		WinSync_p.connectT(1, tempo_sync3); // WinSync -> tempo_sync3::Enabled
		
		this->getParameterT(27).connectT(0, pma7); // WinTempo -> pma7::Add
		
		this->getParameterT(28).connectT(0, pma9); // XfTempo -> pma9::Add
		
		this->getParameterT(29).connectT(0, pma7); // WinMod -> pma7::Multiply
		
		auto& XfMod_p = this->getParameterT(30);
		XfMod_p.connectT(0, pma9);  // XfMod -> pma9::Multiply
		XfMod_p.connectT(1, pma11); // XfMod -> pma11::Multiply
		
		this->getParameterT(31).connectT(0, event_data_reader27); // xf4 -> event_data_reader27::SlotIndex
		
		this->getParameterT(32).connectT(0, event_data_reader25); // xf5 -> event_data_reader25::SlotIndex
		
		this->getParameterT(33).connectT(0, branch10); // midi4 -> branch10::Index
		
		this->getParameterT(34).connectT(0, branch9); // mid5 -> branch9::Index
		
		this->getParameterT(35).connectT(0, branch3); // InmodClk -> branch3::Index
		
		this->getParameterT(36).connectT(0, pma12); // InTempoMod -> pma12::Multiply
		
		this->getParameterT(37).connectT(0, pma14); // SmoothMod -> pma14::Multiply
		
		this->getParameterT(38).connectT(0, pma15); // MixMod -> pma15::Multiply
		
		this->getParameterT(39).connectT(0, branch11); // Midi6 -> branch11::Index
		
		this->getParameterT(40).connectT(0, branch12); // Midi7 -> branch12::Index
		
		this->getParameterT(41).connectT(0, branch13); // Midi8 -> branch13::Index
		
		this->getParameterT(42).connectT(0, event_data_reader29); // XfStage6 -> event_data_reader29::SlotIndex
		
		this->getParameterT(43).connectT(0, event_data_reader31); // XfStage7 -> event_data_reader31::SlotIndex
		
		this->getParameterT(44).connectT(0, event_data_reader33); // XfStage8 -> event_data_reader33::SlotIndex
		
		// Modulation Connections ------------------------------------------------------------------
		
		tempo_sync.getParameter().connectT(0, ramp);                      // tempo_sync -> ramp::PeriodTime
		clock_ramp.getParameter().connectT(0, add18);                     // clock_ramp -> add18::Value
		cable_table.getWrappedObject().getParameter().connectT(0, add2);  // cable_table -> add2::Value
		cable_pack.getWrappedObject().getParameter().connectT(0, add10);  // cable_pack -> add10::Value
		peak2.getParameter().connectT(0, cable_table);                    // peak2 -> cable_table::Value
		peak2.getParameter().connectT(1, cable_pack);                     // peak2 -> cable_pack::Value
		minmax3.getWrappedObject().getParameter().connectT(0, add125);    // minmax3 -> add125::Value
		minmax5.getWrappedObject().getParameter().connectT(0, add131);    // minmax5 -> add131::Value
		minmax12.getWrappedObject().getParameter().connectT(0, add126);   // minmax12 -> add126::Value
		minmax10.getWrappedObject().getParameter().connectT(0, add127);   // minmax10 -> add127::Value
		minmax9.getWrappedObject().getParameter().connectT(0, add128);    // minmax9 -> add128::Value
		minmax8.getWrappedObject().getParameter().connectT(0, add129);    // minmax8 -> add129::Value
		minmax4.getWrappedObject().getParameter().connectT(0, add130);    // minmax4 -> add130::Value
		minmax13.getWrappedObject().getParameter().connectT(0, add3);     // minmax13 -> add3::Value
		pma1.getWrappedObject().getParameter().connectT(0, add1);         // pma1 -> add1::Value
		pma1.getWrappedObject().getParameter().connectT(1, minmax3);      // pma1 -> minmax3::Value
		pma1.getWrappedObject().getParameter().connectT(2, minmax5);      // pma1 -> minmax5::Value
		pma1.getWrappedObject().getParameter().connectT(3, minmax12);     // pma1 -> minmax12::Value
		pma1.getWrappedObject().getParameter().connectT(4, minmax10);     // pma1 -> minmax10::Value
		pma1.getWrappedObject().getParameter().connectT(5, minmax9);      // pma1 -> minmax9::Value
		pma1.getWrappedObject().getParameter().connectT(6, minmax8);      // pma1 -> minmax8::Value
		pma1.getWrappedObject().getParameter().connectT(7, minmax4);      // pma1 -> minmax4::Value
		pma1.getWrappedObject().getParameter().connectT(8, minmax13);     // pma1 -> minmax13::Value
		pma1.getWrappedObject().getParameter().connectT(9, cable_table7); // pma1 -> cable_table7::Value
		peak1.getParameter().connectT(0, pma1);                           // peak1 -> pma1::Value
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
		global_cable25.getWrappedObject().getParameter().connectT(0, add27); // global_cable25 -> add27::Value
		event_data_reader11.getParameter().connectT(0, add29);               // event_data_reader11 -> add29::Value
		event_data_reader10.getParameter().connectT(0, add28);               // event_data_reader10 -> add28::Value
		event_data_reader13.getParameter().connectT(0, add30);               // event_data_reader13 -> add30::Value
		midi_cc10.getWrappedObject().getParameter().connectT(0, add60);      // midi_cc10 -> add60::Value
		midi_cc11.getWrappedObject().getParameter().connectT(0, add61);      // midi_cc11 -> add61::Value
		midi_cc12.getWrappedObject().getParameter().connectT(0, add62);      // midi_cc12 -> add62::Value
		midi_cc13.getWrappedObject().getParameter().connectT(0, add63);      // midi_cc13 -> add63::Value
		midi7.getParameter().connectT(0, add64);                             // midi7 -> add64::Value
		midi8.getParameter().connectT(0, add65);                             // midi8 -> add65::Value
		midi9.getParameter().connectT(0, add66);                             // midi9 -> add66::Value
		pma2.getWrappedObject().getParameter().connectT(0, pma1);            // pma2 -> pma1::Add
		pma2.getWrappedObject().getParameter().connectT(1, cable_table6);    // pma2 -> cable_table6::Value
		peak3.getParameter().connectT(0, pma2);                              // peak3 -> pma2::Value
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
		global_cable26.getWrappedObject().getParameter().connectT(0, add55); // global_cable26 -> add55::Value
		event_data_reader20.getParameter().connectT(0, add56);               // event_data_reader20 -> add56::Value
		event_data_reader21.getParameter().connectT(0, add57);               // event_data_reader21 -> add57::Value
		event_data_reader22.getParameter().connectT(0, add58);               // event_data_reader22 -> add58::Value
		midi_cc14.getWrappedObject().getParameter().connectT(0, add67);      // midi_cc14 -> add67::Value
		midi_cc15.getWrappedObject().getParameter().connectT(0, add68);      // midi_cc15 -> add68::Value
		midi_cc16.getWrappedObject().getParameter().connectT(0, add69);      // midi_cc16 -> add69::Value
		midi_cc17.getWrappedObject().getParameter().connectT(0, add70);      // midi_cc17 -> add70::Value
		midi10.getParameter().connectT(0, add71);                            // midi10 -> add71::Value
		midi11.getParameter().connectT(0, add72);                            // midi11 -> add72::Value
		midi12.getParameter().connectT(0, add73);                            // midi12 -> add73::Value
		pma4.getWrappedObject().getParameter().connectT(0, faust);           // pma4 -> faust::shiftnote
		pma4.getWrappedObject().getParameter().connectT(1, faust2);          // pma4 -> faust2::shiftnote
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
		global_cable27.getWrappedObject().getParameter().connectT(0, add49); // global_cable27 -> add49::Value
		event_data_reader12.getParameter().connectT(0, add50);               // event_data_reader12 -> add50::Value
		event_data_reader19.getParameter().connectT(0, add51);               // event_data_reader19 -> add51::Value
		midi_cc18.getWrappedObject().getParameter().connectT(0, add74);      // midi_cc18 -> add74::Value
		midi_cc19.getWrappedObject().getParameter().connectT(0, add75);      // midi_cc19 -> add75::Value
		midi_cc20.getWrappedObject().getParameter().connectT(0, add76);      // midi_cc20 -> add76::Value
		midi_cc21.getWrappedObject().getParameter().connectT(0, add77);      // midi_cc21 -> add77::Value
		midi13.getParameter().connectT(0, add78);                            // midi13 -> add78::Value
		midi14.getParameter().connectT(0, add79);                            // midi14 -> add79::Value
		midi15.getParameter().connectT(0, add80);                            // midi15 -> add80::Value
		cable_table9.getWrappedObject().getParameter().connectT(0, branch4); // cable_table9 -> branch4::Index
		pma3.getWrappedObject().getParameter().connectT(0, gain3);           // pma3 -> gain3::Gain
		pma3.getWrappedObject().getParameter().connectT(1, cable_table9);    // pma3 -> cable_table9::Value
		peak6.getParameter().connectT(0, pma3);                              // peak6 -> pma3::Value
		auto& sliderbank9_p = sliderbank9.getWrappedObject().getParameter();
		sliderbank9_p.getParameterT(0).connectT(0, gain36);                      // sliderbank9 -> gain36::Gain
		sliderbank9_p.getParameterT(1).connectT(0, gain37);                      // sliderbank9 -> gain37::Gain
		sliderbank9_p.getParameterT(2).connectT(0, gain38);                      // sliderbank9 -> gain38::Gain
		sliderbank9_p.getParameterT(3).connectT(0, gain39);                      // sliderbank9 -> gain39::Gain
		sliderbank9_p.getParameterT(4).connectT(0, gain60);                      // sliderbank9 -> gain60::Gain
		sliderbank9_p.getParameterT(5).connectT(0, gain40);                      // sliderbank9 -> gain40::Gain
		sliderbank9_p.getParameterT(6).connectT(0, gain61);                      // sliderbank9 -> gain61::Gain
		sliderbank9_p.getParameterT(7).connectT(0, gain62);                      // sliderbank9 -> gain62::Gain
		global_cable7.getWrappedObject().getParameter().connectT(0, add13);      // global_cable7 -> add13::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add91);     // global_cable14 -> add91::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add14);     // global_cable23 -> add14::Value
		global_cable28.getWrappedObject().getParameter().connectT(0, add92);     // global_cable28 -> add92::Value
		event_data_reader15.getParameter().connectT(0, add93);                   // event_data_reader15 -> add93::Value
		event_data_reader26.getParameter().connectT(0, add94);                   // event_data_reader26 -> add94::Value
		midi_cc26.getWrappedObject().getParameter().connectT(0, add96);          // midi_cc26 -> add96::Value
		midi_cc27.getWrappedObject().getParameter().connectT(0, add97);          // midi_cc27 -> add97::Value
		midi_cc28.getWrappedObject().getParameter().connectT(0, add98);          // midi_cc28 -> add98::Value
		midi_cc29.getWrappedObject().getParameter().connectT(0, add99);          // midi_cc29 -> add99::Value
		midi19.getParameter().connectT(0, add100);                               // midi19 -> add100::Value
		midi20.getParameter().connectT(0, add101);                               // midi20 -> add101::Value
		midi21.getParameter().connectT(0, add102);                               // midi21 -> add102::Value
		converter.getWrappedObject().getParameter().connectT(0, faust);          // converter -> faust::windowsamples
		converter.getWrappedObject().getParameter().connectT(1, faust1);         // converter -> faust1::windowsamples
		converter.getWrappedObject().getParameter().connectT(2, faust2);         // converter -> faust2::windowsamples
		tempo_sync1.getParameter().connectT(0, converter);                       // tempo_sync1 -> converter::Value
		cable_table2.getWrappedObject().getParameter().connectT(0, tempo_sync1); // cable_table2 -> tempo_sync1::Multiplier
		cable_table3.getWrappedObject().getParameter().connectT(0, tempo_sync1); // cable_table3 -> tempo_sync1::Tempo
		pma7.getWrappedObject().getParameter().connectT(0, cable_table2);        // pma7 -> cable_table2::Value
		pma7.getWrappedObject().getParameter().connectT(1, cable_table3);        // pma7 -> cable_table3::Value
		pma10.getWrappedObject().getParameter().connectT(0, tempo_sync1);        // pma10 -> tempo_sync1::UnsyncedTime
		peak9.getParameter().connectT(0, pma7);                                  // peak9 -> pma7::Value
		peak9.getParameter().connectT(1, pma10);                                 // peak9 -> pma10::Value
		auto& sliderbank8_p = sliderbank8.getWrappedObject().getParameter();
		sliderbank8_p.getParameterT(0).connectT(0, gain25);                      // sliderbank8 -> gain25::Gain
		sliderbank8_p.getParameterT(1).connectT(0, gain29);                      // sliderbank8 -> gain29::Gain
		sliderbank8_p.getParameterT(2).connectT(0, gain30);                      // sliderbank8 -> gain30::Gain
		sliderbank8_p.getParameterT(3).connectT(0, gain31);                      // sliderbank8 -> gain31::Gain
		sliderbank8_p.getParameterT(4).connectT(0, gain57);                      // sliderbank8 -> gain57::Gain
		sliderbank8_p.getParameterT(5).connectT(0, gain35);                      // sliderbank8 -> gain35::Gain
		sliderbank8_p.getParameterT(6).connectT(0, gain58);                      // sliderbank8 -> gain58::Gain
		sliderbank8_p.getParameterT(7).connectT(0, gain59);                      // sliderbank8 -> gain59::Gain
		global_cable6.getWrappedObject().getParameter().connectT(0, add11);      // global_cable6 -> add11::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add53);     // global_cable13 -> add53::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add12);     // global_cable22 -> add12::Value
		global_cable29.getWrappedObject().getParameter().connectT(0, add59);     // global_cable29 -> add59::Value
		event_data_reader14.getParameter().connectT(0, add81);                   // event_data_reader14 -> add81::Value
		event_data_reader24.getParameter().connectT(0, add82);                   // event_data_reader24 -> add82::Value
		midi_cc22.getWrappedObject().getParameter().connectT(0, add84);          // midi_cc22 -> add84::Value
		midi_cc23.getWrappedObject().getParameter().connectT(0, add85);          // midi_cc23 -> add85::Value
		midi_cc24.getWrappedObject().getParameter().connectT(0, add86);          // midi_cc24 -> add86::Value
		midi_cc25.getWrappedObject().getParameter().connectT(0, add87);          // midi_cc25 -> add87::Value
		midi16.getParameter().connectT(0, add88);                                // midi16 -> add88::Value
		midi17.getParameter().connectT(0, add89);                                // midi17 -> add89::Value
		midi18.getParameter().connectT(0, add90);                                // midi18 -> add90::Value
		converter1.getWrappedObject().getParameter().connectT(0, faust1);        // converter1 -> faust1::xfadesamples
		converter1.getWrappedObject().getParameter().connectT(1, faust2);        // converter1 -> faust2::xfadesamples
		converter1.getWrappedObject().getParameter().connectT(2, faust);         // converter1 -> faust::xfadesamples
		tempo_sync3.getParameter().connectT(0, converter1);                      // tempo_sync3 -> converter1::Value
		cable_table4.getWrappedObject().getParameter().connectT(0, tempo_sync3); // cable_table4 -> tempo_sync3::Multiplier
		cable_table5.getWrappedObject().getParameter().connectT(0, tempo_sync3); // cable_table5 -> tempo_sync3::Tempo
		pma9.getWrappedObject().getParameter().connectT(0, cable_table4);        // pma9 -> cable_table4::Value
		pma9.getWrappedObject().getParameter().connectT(1, cable_table5);        // pma9 -> cable_table5::Value
		pma11.getWrappedObject().getParameter().connectT(0, tempo_sync3);        // pma11 -> tempo_sync3::UnsyncedTime
		peak8.getParameter().connectT(0, pma9);                                  // peak8 -> pma9::Value
		peak8.getParameter().connectT(1, pma11);                                 // peak8 -> pma11::Value
		auto& sliderbank10_p = sliderbank10.getWrappedObject().getParameter();
		sliderbank10_p.getParameterT(0).connectT(0, gain41);                  // sliderbank10 -> gain41::Gain
		sliderbank10_p.getParameterT(1).connectT(0, gain42);                  // sliderbank10 -> gain42::Gain
		sliderbank10_p.getParameterT(2).connectT(0, gain43);                  // sliderbank10 -> gain43::Gain
		sliderbank10_p.getParameterT(3).connectT(0, gain44);                  // sliderbank10 -> gain44::Gain
		sliderbank10_p.getParameterT(4).connectT(0, gain63);                  // sliderbank10 -> gain63::Gain
		sliderbank10_p.getParameterT(5).connectT(0, gain45);                  // sliderbank10 -> gain45::Gain
		sliderbank10_p.getParameterT(6).connectT(0, gain64);                  // sliderbank10 -> gain64::Gain
		sliderbank10_p.getParameterT(7).connectT(0, gain65);                  // sliderbank10 -> gain65::Gain
		global_cable8.getWrappedObject().getParameter().connectT(0, add15);   // global_cable8 -> add15::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add103); // global_cable15 -> add103::Value
		global_cable24.getWrappedObject().getParameter().connectT(0, add16);  // global_cable24 -> add16::Value
		global_cable30.getWrappedObject().getParameter().connectT(0, add104); // global_cable30 -> add104::Value
		event_data_reader16.getParameter().connectT(0, add105);               // event_data_reader16 -> add105::Value
		event_data_reader28.getParameter().connectT(0, add106);               // event_data_reader28 -> add106::Value
		midi_cc30.getWrappedObject().getParameter().connectT(0, add108);      // midi_cc30 -> add108::Value
		midi_cc31.getWrappedObject().getParameter().connectT(0, add109);      // midi_cc31 -> add109::Value
		midi_cc32.getWrappedObject().getParameter().connectT(0, add110);      // midi_cc32 -> add110::Value
		midi_cc33.getWrappedObject().getParameter().connectT(0, add111);      // midi_cc33 -> add111::Value
		midi22.getParameter().connectT(0, add112);                            // midi22 -> add112::Value
		midi23.getParameter().connectT(0, add113);                            // midi23 -> add113::Value
		midi24.getParameter().connectT(0, add114);                            // midi24 -> add114::Value
		pma12.getWrappedObject().getParameter().connectT(0, tempo_sync);      // pma12 -> tempo_sync::Tempo
		pma12.getWrappedObject().getParameter().connectT(1, clock_ramp);      // pma12 -> clock_ramp::Tempo
		peak10.getParameter().connectT(0, pma12);                             // peak10 -> pma12::Value
		auto& sliderbank11_p = sliderbank11.getWrappedObject().getParameter();
		sliderbank11_p.getParameterT(0).connectT(0, gain46);                  // sliderbank11 -> gain46::Gain
		sliderbank11_p.getParameterT(1).connectT(0, gain47);                  // sliderbank11 -> gain47::Gain
		sliderbank11_p.getParameterT(2).connectT(0, gain48);                  // sliderbank11 -> gain48::Gain
		sliderbank11_p.getParameterT(3).connectT(0, gain49);                  // sliderbank11 -> gain49::Gain
		sliderbank11_p.getParameterT(4).connectT(0, gain66);                  // sliderbank11 -> gain66::Gain
		sliderbank11_p.getParameterT(5).connectT(0, gain50);                  // sliderbank11 -> gain50::Gain
		sliderbank11_p.getParameterT(6).connectT(0, gain67);                  // sliderbank11 -> gain67::Gain
		sliderbank11_p.getParameterT(7).connectT(0, gain68);                  // sliderbank11 -> gain68::Gain
		global_cable9.getWrappedObject().getParameter().connectT(0, add19);   // global_cable9 -> add19::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add115); // global_cable16 -> add115::Value
		global_cable31.getWrappedObject().getParameter().connectT(0, add20);  // global_cable31 -> add20::Value
		global_cable32.getWrappedObject().getParameter().connectT(0, add116); // global_cable32 -> add116::Value
		event_data_reader17.getParameter().connectT(0, add117);               // event_data_reader17 -> add117::Value
		event_data_reader30.getParameter().connectT(0, add118);               // event_data_reader30 -> add118::Value
		midi_cc34.getWrappedObject().getParameter().connectT(0, add120);      // midi_cc34 -> add120::Value
		midi_cc35.getWrappedObject().getParameter().connectT(0, add121);      // midi_cc35 -> add121::Value
		midi_cc36.getWrappedObject().getParameter().connectT(0, add122);      // midi_cc36 -> add122::Value
		midi_cc37.getWrappedObject().getParameter().connectT(0, add123);      // midi_cc37 -> add123::Value
		midi25.getParameter().connectT(0, add124);                            // midi25 -> add124::Value
		midi26.getParameter().connectT(0, add132);                            // midi26 -> add132::Value
		midi27.getParameter().connectT(0, add133);                            // midi27 -> add133::Value
		pma14.getWrappedObject().getParameter().connectT(0, smoother10);      // pma14 -> smoother10::SmoothingTime
		peak11.getParameter().connectT(0, pma14);                             // peak11 -> pma14::Value
		auto& sliderbank12_p = sliderbank12.getWrappedObject().getParameter();
		sliderbank12_p.getParameterT(0).connectT(0, gain69);                  // sliderbank12 -> gain69::Gain
		sliderbank12_p.getParameterT(1).connectT(0, gain70);                  // sliderbank12 -> gain70::Gain
		sliderbank12_p.getParameterT(2).connectT(0, gain71);                  // sliderbank12 -> gain71::Gain
		sliderbank12_p.getParameterT(3).connectT(0, gain72);                  // sliderbank12 -> gain72::Gain
		sliderbank12_p.getParameterT(4).connectT(0, gain73);                  // sliderbank12 -> gain73::Gain
		sliderbank12_p.getParameterT(5).connectT(0, gain74);                  // sliderbank12 -> gain74::Gain
		sliderbank12_p.getParameterT(6).connectT(0, gain75);                  // sliderbank12 -> gain75::Gain
		sliderbank12_p.getParameterT(7).connectT(0, gain76);                  // sliderbank12 -> gain76::Gain
		global_cable17.getWrappedObject().getParameter().connectT(0, add21);  // global_cable17 -> add21::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, add134); // global_cable18 -> add134::Value
		global_cable33.getWrappedObject().getParameter().connectT(0, add22);  // global_cable33 -> add22::Value
		global_cable34.getWrappedObject().getParameter().connectT(0, add135); // global_cable34 -> add135::Value
		event_data_reader18.getParameter().connectT(0, add136);               // event_data_reader18 -> add136::Value
		event_data_reader32.getParameter().connectT(0, add137);               // event_data_reader32 -> add137::Value
		midi_cc38.getWrappedObject().getParameter().connectT(0, add139);      // midi_cc38 -> add139::Value
		midi_cc39.getWrappedObject().getParameter().connectT(0, add140);      // midi_cc39 -> add140::Value
		midi_cc40.getWrappedObject().getParameter().connectT(0, add141);      // midi_cc40 -> add141::Value
		midi_cc41.getWrappedObject().getParameter().connectT(0, add142);      // midi_cc41 -> add142::Value
		midi28.getParameter().connectT(0, add143);                            // midi28 -> add143::Value
		midi29.getParameter().connectT(0, add144);                            // midi29 -> add144::Value
		midi30.getParameter().connectT(0, add145);                            // midi30 -> add145::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain1);                       // xfader -> gain1::Gain
		xfader_p.getParameterT(1).connectT(0, gain2);                       // xfader -> gain2::Gain
		pma15.getWrappedObject().getParameter().connectT(0, xfader);        // pma15 -> xfader::Value
		peak12.getParameter().connectT(0, pma15);                           // peak12 -> pma15::Value
		peak.getParameter().connectT(0, add);                               // peak -> add::Value
		cable_table1.getWrappedObject().getParameter().connectT(0, faust1); // cable_table1 -> faust1::shiftfreq
		midi4.getParameter().connectT(0, cable_table1);                     // midi4 -> cable_table1::Value
		
		// Send Connections ------------------------------------------------------------------------
		
		send.connect(receive);
		send1.connect(receive1);
		
		// Default Values --------------------------------------------------------------------------
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // branch3::Index is automated
		
		;                                   // tempo_sync::Tempo is automated
		;                                   // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 1000.); // control::tempo_sync::UnsyncedTime
		
		;                          // ramp::PeriodTime is automated
		;                          // ramp::LoopStart is automated
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		add17.setParameterT(0, 0.); // math::add::Value
		
		;                                // clock_ramp::Tempo is automated
		;                                // clock_ramp::Multiplier is automated
		clock_ramp.setParameterT(2, 0.); // core::clock_ramp::AddToSignal
		clock_ramp.setParameterT(3, 1.); // core::clock_ramp::UpdateMode
		clock_ramp.setParameterT(4, 0.); // core::clock_ramp::Inactive
		
		; // add18::Value is automated
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // pack_resizer::NumSliders is automated
		
		; // branch1::Index is automated
		
		; // cable_table::Value is automated
		
		; // add2::Value is automated
		
		; // cable_pack::Value is automated
		
		; // add10::Value is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		; // cable_table7::Value is automated
		
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
		
		global_cable25.setParameterT(0, 1.); // routing::global_cable::Value
		
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
		
		;                                         // event_data_reader13::SlotIndex is automated
		event_data_reader13.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add30::Value is automated
		
		;                             // gain33::Gain is automated
		gain33.setParameterT(1, 20.); // core::gain::Smoothing
		gain33.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch5::Index is automated
		
		midi_cc10.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc10.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc10.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add60::Value is automated
		
		midi_cc11.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc11.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc11.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add61::Value is automated
		
		midi_cc12.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc12.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc12.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add62::Value is automated
		
		midi_cc13.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc13.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc13.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add63::Value is automated
		
		; // add64::Value is automated
		
		; // add65::Value is automated
		
		; // add66::Value is automated
		
		;                             // gain34::Gain is automated
		gain34.setParameterT(1, 20.); // core::gain::Smoothing
		gain34.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma2::Value is automated
		; // pma2::Multiply is automated
		; // pma2::Add is automated
		
		; // cable_table6::Value is automated
		
		; // cable_table8::Value is automated
		
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
		
		global_cable26.setParameterT(0, 1.); // routing::global_cable::Value
		
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
		
		event_data_reader21.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader21.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add57::Value is automated
		
		;                             // gain28::Gain is automated
		gain28.setParameterT(1, 20.); // core::gain::Smoothing
		gain28.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader22::SlotIndex is automated
		event_data_reader22.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add58::Value is automated
		
		;                             // gain55::Gain is automated
		gain55.setParameterT(1, 20.); // core::gain::Smoothing
		gain55.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch6::Index is automated
		
		midi_cc14.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc14.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc14.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add67::Value is automated
		
		midi_cc15.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc15.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc15.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add68::Value is automated
		
		midi_cc16.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc16.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc16.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add69::Value is automated
		
		midi_cc17.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc17.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc17.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add70::Value is automated
		
		; // add71::Value is automated
		
		; // add72::Value is automated
		
		; // add73::Value is automated
		
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
		
		global_cable27.setParameterT(0, 1.); // routing::global_cable::Value
		
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
		
		event_data_reader19.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader19.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add51::Value is automated
		
		;                             // gain27::Gain is automated
		gain27.setParameterT(1, 20.); // core::gain::Smoothing
		gain27.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader23::SlotIndex is automated
		event_data_reader23.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		add52.setParameterT(0, 0.); // math::add::Value
		
		;                             // gain52::Gain is automated
		gain52.setParameterT(1, 20.); // core::gain::Smoothing
		gain52.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch7::Index is automated
		
		midi_cc18.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc18.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc18.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add74::Value is automated
		
		midi_cc19.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc19.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc19.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add75::Value is automated
		
		midi_cc20.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc20.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc20.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add76::Value is automated
		
		midi_cc21.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc21.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc21.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add77::Value is automated
		
		; // add78::Value is automated
		
		; // add79::Value is automated
		
		; // add80::Value is automated
		
		;                             // gain53::Gain is automated
		gain53.setParameterT(1, 20.); // core::gain::Smoothing
		gain53.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma3::Value is automated
		; // pma3::Multiply is automated
		; // pma3::Add is automated
		
		sliderbank9.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add13::Value is automated
		
		;                             // gain36::Gain is automated
		gain36.setParameterT(1, 20.); // core::gain::Smoothing
		gain36.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add91::Value is automated
		
		;                             // gain37::Gain is automated
		gain37.setParameterT(1, 20.); // core::gain::Smoothing
		gain37.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable23.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add14::Value is automated
		
		;                             // gain38::Gain is automated
		gain38.setParameterT(1, 20.); // core::gain::Smoothing
		gain38.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable28.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add92::Value is automated
		
		;                             // gain39::Gain is automated
		gain39.setParameterT(1, 20.); // core::gain::Smoothing
		gain39.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader15.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader15.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add93::Value is automated
		
		;                             // gain60::Gain is automated
		gain60.setParameterT(1, 20.); // core::gain::Smoothing
		gain60.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader26.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader26.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add94::Value is automated
		
		;                             // gain40::Gain is automated
		gain40.setParameterT(1, 20.); // core::gain::Smoothing
		gain40.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader27::SlotIndex is automated
		event_data_reader27.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		add95.setParameterT(0, 0.); // math::add::Value
		
		;                             // gain61::Gain is automated
		gain61.setParameterT(1, 20.); // core::gain::Smoothing
		gain61.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch10::Index is automated
		
		midi_cc26.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc26.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc26.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add96::Value is automated
		
		midi_cc27.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc27.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc27.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add97::Value is automated
		
		midi_cc28.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc28.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc28.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add98::Value is automated
		
		midi_cc29.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc29.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc29.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add99::Value is automated
		
		; // add100::Value is automated
		
		; // add101::Value is automated
		
		; // add102::Value is automated
		
		;                             // gain62::Gain is automated
		gain62.setParameterT(1, 20.); // core::gain::Smoothing
		gain62.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                           // pma10::Value is automated
		pma10.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma10::Add is automated
		
		; // pma7::Value is automated
		; // pma7::Multiply is automated
		; // pma7::Add is automated
		
		sliderbank8.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add11::Value is automated
		
		;                             // gain25::Gain is automated
		gain25.setParameterT(1, 20.); // core::gain::Smoothing
		gain25.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add53::Value is automated
		
		;                             // gain29::Gain is automated
		gain29.setParameterT(1, 20.); // core::gain::Smoothing
		gain29.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable22.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		;                             // gain30::Gain is automated
		gain30.setParameterT(1, 20.); // core::gain::Smoothing
		gain30.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable29.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add59::Value is automated
		
		;                             // gain31::Gain is automated
		gain31.setParameterT(1, 20.); // core::gain::Smoothing
		gain31.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader14.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader14.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add81::Value is automated
		
		;                             // gain57::Gain is automated
		gain57.setParameterT(1, 20.); // core::gain::Smoothing
		gain57.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader24.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader24.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add82::Value is automated
		
		;                             // gain35::Gain is automated
		gain35.setParameterT(1, 20.); // core::gain::Smoothing
		gain35.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader25::SlotIndex is automated
		event_data_reader25.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		add83.setParameterT(0, 0.); // math::add::Value
		
		;                             // gain58::Gain is automated
		gain58.setParameterT(1, 20.); // core::gain::Smoothing
		gain58.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch9::Index is automated
		
		midi_cc22.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc22.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc22.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add84::Value is automated
		
		midi_cc23.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc23.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc23.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add85::Value is automated
		
		midi_cc24.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc24.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc24.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add86::Value is automated
		
		midi_cc25.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc25.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc25.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add87::Value is automated
		
		; // add88::Value is automated
		
		; // add89::Value is automated
		
		; // add90::Value is automated
		
		;                             // gain59::Gain is automated
		gain59.setParameterT(1, 20.); // core::gain::Smoothing
		gain59.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma11::Value is automated
		; // pma11::Multiply is automated
		; // pma11::Add is automated
		
		; // pma9::Value is automated
		; // pma9::Multiply is automated
		; // pma9::Add is automated
		
		sliderbank10.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add15::Value is automated
		
		;                             // gain41::Gain is automated
		gain41.setParameterT(1, 20.); // core::gain::Smoothing
		gain41.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add103::Value is automated
		
		;                             // gain42::Gain is automated
		gain42.setParameterT(1, 20.); // core::gain::Smoothing
		gain42.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable24.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add16::Value is automated
		
		;                             // gain43::Gain is automated
		gain43.setParameterT(1, 20.); // core::gain::Smoothing
		gain43.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable30.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add104::Value is automated
		
		;                             // gain44::Gain is automated
		gain44.setParameterT(1, 20.); // core::gain::Smoothing
		gain44.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader16.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader16.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add105::Value is automated
		
		;                             // gain63::Gain is automated
		gain63.setParameterT(1, 20.); // core::gain::Smoothing
		gain63.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader28.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader28.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add106::Value is automated
		
		;                             // gain45::Gain is automated
		gain45.setParameterT(1, 20.); // core::gain::Smoothing
		gain45.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader29::SlotIndex is automated
		event_data_reader29.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		add107.setParameterT(0, 0.); // math::add::Value
		
		;                             // gain64::Gain is automated
		gain64.setParameterT(1, 20.); // core::gain::Smoothing
		gain64.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch11::Index is automated
		
		midi_cc30.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc30.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc30.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add108::Value is automated
		
		midi_cc31.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc31.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc31.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add109::Value is automated
		
		midi_cc32.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc32.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc32.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add110::Value is automated
		
		midi_cc33.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc33.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc33.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add111::Value is automated
		
		; // add112::Value is automated
		
		; // add113::Value is automated
		
		; // add114::Value is automated
		
		;                             // gain65::Gain is automated
		gain65.setParameterT(1, 20.); // core::gain::Smoothing
		gain65.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma12::Value is automated
		; // pma12::Multiply is automated
		; // pma12::Add is automated
		
		sliderbank11.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable9.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add19::Value is automated
		
		;                             // gain46::Gain is automated
		gain46.setParameterT(1, 20.); // core::gain::Smoothing
		gain46.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add115::Value is automated
		
		;                             // gain47::Gain is automated
		gain47.setParameterT(1, 20.); // core::gain::Smoothing
		gain47.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable31.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add20::Value is automated
		
		;                             // gain48::Gain is automated
		gain48.setParameterT(1, 20.); // core::gain::Smoothing
		gain48.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable32.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add116::Value is automated
		
		;                             // gain49::Gain is automated
		gain49.setParameterT(1, 20.); // core::gain::Smoothing
		gain49.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader17.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader17.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add117::Value is automated
		
		;                             // gain66::Gain is automated
		gain66.setParameterT(1, 20.); // core::gain::Smoothing
		gain66.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader30.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader30.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add118::Value is automated
		
		;                             // gain50::Gain is automated
		gain50.setParameterT(1, 20.); // core::gain::Smoothing
		gain50.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader31::SlotIndex is automated
		event_data_reader31.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		add119.setParameterT(0, 0.); // math::add::Value
		
		;                             // gain67::Gain is automated
		gain67.setParameterT(1, 20.); // core::gain::Smoothing
		gain67.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch12::Index is automated
		
		midi_cc34.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc34.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc34.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add120::Value is automated
		
		midi_cc35.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc35.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc35.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add121::Value is automated
		
		midi_cc36.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc36.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc36.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add122::Value is automated
		
		midi_cc37.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc37.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc37.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add123::Value is automated
		
		; // add124::Value is automated
		
		; // add132::Value is automated
		
		; // add133::Value is automated
		
		;                             // gain68::Gain is automated
		gain68.setParameterT(1, 20.); // core::gain::Smoothing
		gain68.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma14::Value is automated
		; // pma14::Multiply is automated
		; // pma14::Add is automated
		
		sliderbank12.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add21::Value is automated
		
		;                             // gain69::Gain is automated
		gain69.setParameterT(1, 20.); // core::gain::Smoothing
		gain69.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable18.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add134::Value is automated
		
		;                             // gain70::Gain is automated
		gain70.setParameterT(1, 20.); // core::gain::Smoothing
		gain70.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable33.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add22::Value is automated
		
		;                             // gain71::Gain is automated
		gain71.setParameterT(1, 20.); // core::gain::Smoothing
		gain71.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable34.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add135::Value is automated
		
		;                             // gain72::Gain is automated
		gain72.setParameterT(1, 20.); // core::gain::Smoothing
		gain72.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader18.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader18.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add136::Value is automated
		
		;                             // gain73::Gain is automated
		gain73.setParameterT(1, 20.); // core::gain::Smoothing
		gain73.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader32.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader32.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add137::Value is automated
		
		;                             // gain74::Gain is automated
		gain74.setParameterT(1, 20.); // core::gain::Smoothing
		gain74.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader33::SlotIndex is automated
		event_data_reader33.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		add138.setParameterT(0, 0.); // math::add::Value
		
		;                             // gain75::Gain is automated
		gain75.setParameterT(1, 20.); // core::gain::Smoothing
		gain75.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch13::Index is automated
		
		midi_cc38.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc38.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc38.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add139::Value is automated
		
		midi_cc39.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc39.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc39.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add140::Value is automated
		
		midi_cc40.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc40.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc40.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add141::Value is automated
		
		midi_cc41.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc41.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc41.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add142::Value is automated
		
		; // add143::Value is automated
		
		; // add144::Value is automated
		
		; // add145::Value is automated
		
		;                             // gain76::Gain is automated
		gain76.setParameterT(1, 20.); // core::gain::Smoothing
		gain76.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma15::Value is automated
		; // pma15::Multiply is automated
		; // pma15::Add is automated
		
		; // xfader::Value is automated
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 0.);    // core::gain::Smoothing
		gain1.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // cable_table9::Value is automated
		
		; // branch4::Index is automated
		
		clear4.setParameterT(0, 0.); // math::clear::Value
		
		;                              // gain3::Gain is automated
		gain3.setParameterT(1, 0.);    // core::gain::Smoothing
		gain3.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // branch8::Index is automated
		
		; // add1::Value is automated
		
		;                             // minmax3::Value is automated
		minmax3.setParameterT(1, 0.); // control::minmax::Minimum
		minmax3.setParameterT(2, 1.); // control::minmax::Maximum
		minmax3.setParameterT(3, 1.); // control::minmax::Skew
		minmax3.setParameterT(4, 0.); // control::minmax::Step
		minmax3.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add125::Value is automated
		
		;                             // minmax5::Value is automated
		minmax5.setParameterT(1, 0.); // control::minmax::Minimum
		minmax5.setParameterT(2, 1.); // control::minmax::Maximum
		minmax5.setParameterT(3, 1.); // control::minmax::Skew
		minmax5.setParameterT(4, 0.); // control::minmax::Step
		minmax5.setParameterT(5, 0.); // control::minmax::Polarity
		
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
		
		;                                    // minmax9::Value is automated
		minmax9.setParameterT(1, 0.);        // control::minmax::Minimum
		minmax9.setParameterT(2, 1.);        // control::minmax::Maximum
		minmax9.setParameterT(3, 1.);        // control::minmax::Skew
		minmax9.setParameterT(4, 0.0117188); // control::minmax::Step
		minmax9.setParameterT(5, 0.);        // control::minmax::Polarity
		
		; // add128::Value is automated
		
		;                             // minmax8::Value is automated
		minmax8.setParameterT(1, 0.); // control::minmax::Minimum
		minmax8.setParameterT(2, 1.); // control::minmax::Maximum
		minmax8.setParameterT(3, 1.); // control::minmax::Skew
		minmax8.setParameterT(4, 0.); // control::minmax::Step
		minmax8.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add129::Value is automated
		
		;                                  // minmax4::Value is automated
		minmax4.setParameterT(1, 0.);      // control::minmax::Minimum
		minmax4.setParameterT(2, 1.);      // control::minmax::Maximum
		minmax4.setParameterT(3, 1.);      // control::minmax::Skew
		minmax4.setParameterT(4, 0.01562); // control::minmax::Step
		minmax4.setParameterT(5, 0.);      // control::minmax::Polarity
		
		; // add130::Value is automated
		
		;                                // minmax13::Value is automated
		minmax13.setParameterT(1, 0.);   // control::minmax::Minimum
		minmax13.setParameterT(2, 1.);   // control::minmax::Maximum
		minmax13.setParameterT(3, 1.);   // control::minmax::Skew
		minmax13.setParameterT(4, 0.03); // control::minmax::Step
		minmax13.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // add3::Value is automated
		
		;                                // smoother10::SmoothingTime is automated
		smoother10.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		; // add::Value is automated
		
		; // branch2::Index is automated
		
		file_player4.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player4.setParameterT(1, 1.);      // core::file_player::Gate
		file_player4.setParameterT(2, 790.031); // core::file_player::RootFrequency
		file_player4.setParameterT(3, 1.16);    // core::file_player::FreqRatio
		
		file_player5.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player5.setParameterT(1, 1.);      // core::file_player::Gate
		file_player5.setParameterT(2, 790.031); // core::file_player::RootFrequency
		file_player5.setParameterT(3, 1.16);    // core::file_player::FreqRatio
		
		; // cable_table2::Value is automated
		
		; // cable_table3::Value is automated
		
		; // tempo_sync1::Tempo is automated
		; // tempo_sync1::Multiplier is automated
		; // tempo_sync1::Enabled is automated
		; // tempo_sync1::UnsyncedTime is automated
		
		; // converter::Value is automated
		
		; // cable_table4::Value is automated
		
		; // cable_table5::Value is automated
		
		; // tempo_sync3::Tempo is automated
		; // tempo_sync3::Multiplier is automated
		; // tempo_sync3::Enabled is automated
		; // tempo_sync3::UnsyncedTime is automated
		
		; // converter1::Value is automated
		
		; // branch::Index is automated
		
		tanh1.setParameterT(0, 0.733733); // math::tanh::Value
		
		; // receive::Feedback is automated
		
		; // faust::shiftnote is automated
		; // faust::windowsamples is automated
		; // faust::xfadesamples is automated
		
		; // cable_table1::Value is automated
		
		; // faust1::shiftfreq is automated
		; // faust1::windowsamples is automated
		; // faust1::xfadesamples is automated
		
		; // faust2::shiftnote is automated
		; // faust2::windowsamples is automated
		; // faust2::xfadesamples is automated
		
		; // receive1::Feedback is automated
		
		;                              // gain2::Gain is automated
		gain2.setParameterT(1, 0.);    // core::gain::Smoothing
		gain2.setParameterT(2, -100.); // core::gain::ResetValue
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 10.);
		this->setParameterT(5, 10.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 0.9);
		this->setParameterT(8, 0.4);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 0.);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 10.);
		this->setParameterT(15, 0.);
		this->setParameterT(16, 0.);
		this->setParameterT(17, 1.);
		this->setParameterT(18, 0.9);
		this->setParameterT(19, 0.);
		this->setParameterT(20, 1.);
		this->setParameterT(21, 1.);
		this->setParameterT(22, 1.);
		this->setParameterT(23, 1.);
		this->setParameterT(24, 1.);
		this->setParameterT(25, 0.);
		this->setParameterT(26, 0.);
		this->setParameterT(27, 0.);
		this->setParameterT(28, 0.);
		this->setParameterT(29, 0.);
		this->setParameterT(30, 0.);
		this->setParameterT(31, 1.);
		this->setParameterT(32, 1.);
		this->setParameterT(33, 1.);
		this->setParameterT(34, 1.);
		this->setParameterT(35, 0.);
		this->setParameterT(36, 0.);
		this->setParameterT(37, 0.);
		this->setParameterT(38, 0.);
		this->setParameterT(39, 1.);
		this->setParameterT(40, 1.);
		this->setParameterT(41, 1.);
		this->setParameterT(42, 1.);
		this->setParameterT(43, 1.);
		this->setParameterT(44, 1.);
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
		
		this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable10_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable25_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable5_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable20_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable21_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable26_t<NV>
		this->getT(0).getT(0).getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable4_t<NV>
		this->getT(0).getT(0).getT(3).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable12_t<NV>
		this->getT(0).getT(0).getT(3).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable19_t<NV>
		this->getT(0).getT(0).getT(3).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable27_t<NV>
		this->getT(0).getT(0).getT(4).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable7_t<NV>
		this->getT(0).getT(0).getT(4).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable14_t<NV>
		this->getT(0).getT(0).getT(4).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable23_t<NV>
		this->getT(0).getT(0).getT(4).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable28_t<NV>
		this->getT(0).getT(0).getT(5).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable6_t<NV>
		this->getT(0).getT(0).getT(5).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable13_t<NV>
		this->getT(0).getT(0).getT(5).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable22_t<NV>
		this->getT(0).getT(0).getT(5).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable29_t<NV>
		this->getT(0).getT(0).getT(6).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable8_t<NV>
		this->getT(0).getT(0).getT(6).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable15_t<NV>
		this->getT(0).getT(0).getT(6).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable24_t<NV>
		this->getT(0).getT(0).getT(6).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable30_t<NV>
		this->getT(0).getT(0).getT(7).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable9_t<NV>
		this->getT(0).getT(0).getT(7).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable16_t<NV>
		this->getT(0).getT(0).getT(7).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable31_t<NV>
		this->getT(0).getT(0).getT(7).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable32_t<NV>
		this->getT(0).getT(0).getT(8).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable17_t<NV>
		this->getT(0).getT(0).getT(8).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable18_t<NV>
		this->getT(0).getT(0).getT(8).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable33_t<NV>
		this->getT(0).getT(0).getT(8).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // files_impl::global_cable34_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).                                                   // files_impl::ramp_t<NV>
        getT(1).getT(0).getT(0).getT(1).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).                                                   // files_impl::clock_ramp_t<NV>
        getT(1).getT(0).getT(1).getT(0).setExternalData(b, index);
		this->getT(0).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index);                 // files_impl::peak2_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(4).setExternalData(b, index);                 // files_impl::pack_resizer_t
		this->getT(0).getT(0).getT(0).getT(0).getT(5).getT(0).getT(0).setExternalData(b, index); // files_impl::cable_table_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(5).getT(1).getT(0).setExternalData(b, index); // files_impl::cable_pack_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(6).setExternalData(b, index);                 // files_impl::peak1_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(9).setExternalData(b, index);                 // files_impl::cable_table7_t
		this->getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);                         // files_impl::sliderbank3_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).setExternalData(b, index);                         // files_impl::peak3_t<NV>
		this->getT(0).getT(0).getT(1).getT(4).setExternalData(b, index);                         // files_impl::cable_table6_t
		this->getT(0).getT(0).getT(1).getT(5).setExternalData(b, index);                         // files_impl::cable_table8_t
		this->getT(0).getT(0).getT(2).getT(0).setExternalData(b, index);                         // files_impl::sliderbank7_t<NV>
		this->getT(0).getT(0).getT(2).getT(2).setExternalData(b, index);                         // files_impl::peak7_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).setExternalData(b, index);                         // files_impl::sliderbank6_t<NV>
		this->getT(0).getT(0).getT(3).getT(2).setExternalData(b, index);                         // files_impl::peak6_t<NV>
		this->getT(0).getT(0).getT(4).getT(0).setExternalData(b, index);                         // files_impl::sliderbank9_t<NV>
		this->getT(0).getT(0).getT(4).getT(2).getT(0).setExternalData(b, index);                 // files_impl::peak9_t<NV>
		this->getT(0).getT(0).getT(5).getT(0).setExternalData(b, index);                         // files_impl::sliderbank8_t<NV>
		this->getT(0).getT(0).getT(5).getT(2).getT(0).setExternalData(b, index);                 // files_impl::peak8_t<NV>
		this->getT(0).getT(0).getT(6).getT(0).setExternalData(b, index);                         // files_impl::sliderbank10_t<NV>
		this->getT(0).getT(0).getT(6).getT(2).getT(0).setExternalData(b, index);                 // files_impl::peak10_t<NV>
		this->getT(0).getT(0).getT(7).getT(0).setExternalData(b, index);                         // files_impl::sliderbank11_t<NV>
		this->getT(0).getT(0).getT(7).getT(2).getT(0).setExternalData(b, index);                 // files_impl::peak11_t<NV>
		this->getT(0).getT(0).getT(8).getT(0).setExternalData(b, index);                         // files_impl::sliderbank12_t<NV>
		this->getT(0).getT(0).getT(8).getT(2).getT(0).setExternalData(b, index);                 // files_impl::peak12_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).getT(0).setExternalData(b, index);                 // files_impl::cable_table9_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).                                                   // files_impl::peak_t<NV>
        getT(3).getT(0).getT(1).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(1).setExternalData(b, index);         // files_impl::oscilloscope_t
		this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(4).getT(0).setExternalData(b, index); // files_impl::file_player4_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).getT(3).getT(4).getT(1).setExternalData(b, index); // files_impl::file_player5_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).                                                   // files_impl::cable_table2_t<NV>
        getT(3).getT(5).getT(0).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(1).  // files_impl::cable_table3_t<NV>
        getT(3).getT(5).getT(0).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(1).  // files_impl::cable_table4_t<NV>
        getT(3).getT(5).getT(1).getT(0).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(1).  // files_impl::cable_table5_t<NV>
        getT(3).getT(5).getT(1).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(1).  // files_impl::cable_table1_t<NV>
        getT(3).getT(6).getT(2).getT(1).setExternalData(b, index);
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


