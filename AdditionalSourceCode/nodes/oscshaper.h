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

namespace oscshaper_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(sliderbank_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using sliderbank_c0 = parameter::from0To1<core::gain<NV>, 
                                          0, 
                                          sliderbank_c0Range>;

template <int NV> using sliderbank_c1 = sliderbank_c0<NV>;

template <int NV> using sliderbank_c2 = sliderbank_c0<NV>;

template <int NV> using sliderbank_c3 = sliderbank_c0<NV>;

template <int NV> using sliderbank_c4 = sliderbank_c0<NV>;

template <int NV> using sliderbank_c5 = sliderbank_c0<NV>;

template <int NV> using sliderbank_c6 = sliderbank_c0<NV>;

template <int NV> using sliderbank_c7 = sliderbank_c0<NV>;

template <int NV>
using sliderbank_multimod = parameter::list<sliderbank_c0<NV>, 
                                            sliderbank_c1<NV>, 
                                            sliderbank_c2<NV>, 
                                            sliderbank_c3<NV>, 
                                            sliderbank_c4<NV>, 
                                            sliderbank_c5<NV>, 
                                            sliderbank_c6<NV>, 
                                            sliderbank_c7<NV>>;

template <int NV>
using sliderbank_t = wrap::data<control::sliderbank<sliderbank_multimod<NV>>, 
                                data::external::sliderpack<0>>;
using global_cable_t_index = runtime_target::indexers::fix_hash<2333884>;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable_t<NV>>, 
                                  math::add<NV>, 
                                  core::gain<NV>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<2333885>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable2_t<NV>>, 
                                  math::add<NV>, 
                                  core::gain<NV>>;
using global_cable1_t_index = runtime_target::indexers::fix_hash<2333886>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable1_t<NV>>, 
                                  math::add<NV>, 
                                  core::gain<NV>>;

template <int NV>
using event_data_reader_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                      routing::event_data_reader<NV>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, event_data_reader_t<NV>>, 
                                  math::add<NV>, 
                                  core::gain<NV>>;

template <int NV> using event_data_reader2_t = event_data_reader_t<NV>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader2_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader1_t = event_data_reader_t<NV>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, event_data_reader1_t<NV>>, 
                                  math::add<NV>, 
                                  core::gain<NV>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::event_data_reader<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using midi_cc10_t = control::midi_cc<parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc10_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc11_t = midi_cc10_t<NV>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc11_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc12_t = midi_cc10_t<NV>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc12_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc13_t = midi_cc10_t<NV>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc13_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using midi6_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi6_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using midi7_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi7_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using midi8_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi8_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain34_t<NV>>, 
                                    chain35_t<NV>, 
                                    chain36_t<NV>, 
                                    chain37_t<NV>, 
                                    chain38_t<NV>, 
                                    chain39_t<NV>, 
                                    chain40_t<NV>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch5_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain1_t<NV>>, 
                                  chain4_t<NV>, 
                                  chain3_t<NV>, 
                                  chain5_t<NV>, 
                                  chain10_t<NV>, 
                                  chain8_t<NV>, 
                                  chain12_t<NV>, 
                                  chain14_t<NV>>;

template <int NV> using xfader_c0 = sliderbank_c0<NV>;

template <int NV> using xfader_c1 = sliderbank_c0<NV>;

template <int NV> using xfader_c2 = sliderbank_c0<NV>;

template <int NV> using xfader_c3 = sliderbank_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, 
                                        xfader_c1<NV>, 
                                        xfader_c2<NV>, 
                                        xfader_c3<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::linear>;
template <int NV>
using pma_t = control::pma<NV, 
                           parameter::plain<xfader_t<NV>, 0>>;
template <int NV>
using peak_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank_t<NV>>, 
                                   split2_t<NV>, 
                                   peak_t<NV>, 
                                   pma_t<NV>>;

template <int NV> using sliderbank2_c0 = sliderbank_c0<NV>;

template <int NV> using sliderbank2_c1 = sliderbank_c0<NV>;

template <int NV> using sliderbank2_c2 = sliderbank_c0<NV>;

template <int NV> using sliderbank2_c3 = sliderbank_c0<NV>;

template <int NV> using sliderbank2_c4 = sliderbank_c0<NV>;

template <int NV> using sliderbank2_c5 = sliderbank_c0<NV>;

template <int NV> using sliderbank2_c6 = sliderbank_c0<NV>;

template <int NV> using sliderbank2_c7 = sliderbank_c0<NV>;

template <int NV>
using sliderbank2_multimod = parameter::list<sliderbank2_c0<NV>, 
                                             sliderbank2_c1<NV>, 
                                             sliderbank2_c2<NV>, 
                                             sliderbank2_c3<NV>, 
                                             sliderbank2_c4<NV>, 
                                             sliderbank2_c5<NV>, 
                                             sliderbank2_c6<NV>, 
                                             sliderbank2_c7<NV>>;

template <int NV>
using sliderbank2_t = wrap::data<control::sliderbank<sliderbank2_multimod<NV>>, 
                                 data::external::sliderpack<1>>;
using global_cable7_t_index = global_cable_t_index;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable7_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable8_t_index = global_cable2_t_index;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable8_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable9_t_index = global_cable1_t_index;

template <int NV>
using global_cable9_t = routing::global_cable<global_cable9_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable9_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader7_t = event_data_reader_t<NV>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader7_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader8_t = event_data_reader_t<NV>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader8_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader9_t = event_data_reader_t<NV>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader9_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader10_t = event_data_reader_t<NV>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader10_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc14_t = midi_cc10_t<NV>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc14_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc15_t = midi_cc10_t<NV>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc15_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc16_t = midi_cc10_t<NV>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc16_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc17_t = midi_cc10_t<NV>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc17_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi9_t = midi6_t<NV>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi9_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi10_t = midi7_t<NV>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi10_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi11_t = midi8_t<NV>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi11_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain41_t<NV>>, 
                                    chain42_t<NV>, 
                                    chain43_t<NV>, 
                                    chain44_t<NV>, 
                                    chain45_t<NV>, 
                                    chain46_t<NV>, 
                                    chain47_t<NV>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch6_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain26_t<NV>>, 
                                  chain27_t<NV>, 
                                  chain28_t<NV>, 
                                  chain29_t<NV>, 
                                  chain30_t<NV>, 
                                  chain31_t<NV>, 
                                  chain32_t<NV>, 
                                  chain33_t<NV>>;

DECLARE_PARAMETER_RANGE(pma4_mod_0Range, 
                        0.5, 
                        1.);

template <int NV>
using pma4_mod_0 = parameter::from0To1<math::pi<NV>, 
                                       0, 
                                       pma4_mod_0Range>;

DECLARE_PARAMETER_RANGE_STEP(pma4_mod_1Range, 
                             -15., 
                             24., 
                             0.1);

template <int NV>
using pma4_mod_1 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       pma4_mod_1Range>;

template <int NV> using pma4_mod_2 = pma4_mod_0<NV>;

DECLARE_PARAMETER_RANGE_STEP(pma4_mod_3Range, 
                             -20., 
                             24., 
                             0.1);

template <int NV>
using pma4_mod_3 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       pma4_mod_3Range>;

template <int NV>
using pma4_mod = parameter::chain<ranges::Identity, 
                                  pma4_mod_0<NV>, 
                                  pma4_mod_1<NV>, 
                                  pma4_mod_2<NV>, 
                                  pma4_mod_3<NV>>;

template <int NV>
using pma4_t = control::pma<NV, pma4_mod<NV>>;
template <int NV>
using peak2_t = wrap::mod<parameter::plain<pma4_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank2_t<NV>>, 
                                   split5_t<NV>, 
                                   peak2_t<NV>, 
                                   pma4_t<NV>>;

template <int NV> using sliderbank1_c0 = sliderbank_c0<NV>;

template <int NV> using sliderbank1_c1 = sliderbank_c0<NV>;

template <int NV> using sliderbank1_c2 = sliderbank_c0<NV>;

template <int NV> using sliderbank1_c3 = sliderbank_c0<NV>;

template <int NV> using sliderbank1_c4 = sliderbank_c0<NV>;

template <int NV> using sliderbank1_c5 = sliderbank_c0<NV>;

template <int NV> using sliderbank1_c6 = sliderbank_c0<NV>;

template <int NV> using sliderbank1_c7 = sliderbank_c0<NV>;

template <int NV>
using sliderbank1_multimod = parameter::list<sliderbank1_c0<NV>, 
                                             sliderbank1_c1<NV>, 
                                             sliderbank1_c2<NV>, 
                                             sliderbank1_c3<NV>, 
                                             sliderbank1_c4<NV>, 
                                             sliderbank1_c5<NV>, 
                                             sliderbank1_c6<NV>, 
                                             sliderbank1_c7<NV>>;

template <int NV>
using sliderbank1_t = wrap::data<control::sliderbank<sliderbank1_multimod<NV>>, 
                                 data::external::sliderpack<2>>;
using global_cable4_t_index = global_cable_t_index;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable4_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable5_t_index = global_cable2_t_index;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable5_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable6_t_index = global_cable1_t_index;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable6_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader4_t = event_data_reader_t<NV>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader4_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader5_t = event_data_reader_t<NV>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader5_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader6_t = event_data_reader_t<NV>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader6_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader11_t = event_data_reader_t<NV>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader11_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc18_t = midi_cc10_t<NV>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc18_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc19_t = midi_cc10_t<NV>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc19_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc20_t = midi_cc10_t<NV>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc20_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc21_t = midi_cc10_t<NV>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc21_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi12_t = midi6_t<NV>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi12_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi13_t = midi7_t<NV>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi13_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi14_t = midi8_t<NV>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi14_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch7_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain48_t<NV>>, 
                                    chain49_t<NV>, 
                                    chain50_t<NV>, 
                                    chain51_t<NV>, 
                                    chain52_t<NV>, 
                                    chain53_t<NV>, 
                                    chain54_t<NV>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch7_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain17_t<NV>>, 
                                  chain18_t<NV>, 
                                  chain19_t<NV>, 
                                  chain20_t<NV>, 
                                  chain21_t<NV>, 
                                  chain22_t<NV>, 
                                  chain23_t<NV>, 
                                  chain24_t<NV>>;

template <int NV> using pma3_mod = sliderbank_c0<NV>;

template <int NV>
using pma3_t = control::pma<NV, pma3_mod<NV>>;
template <int NV>
using peak1_t = wrap::mod<parameter::plain<pma3_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank1_t<NV>>, 
                                   split4_t<NV>, 
                                   peak1_t<NV>, 
                                   pma3_t<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain15_t<NV>>, 
                                  chain25_t<NV>, 
                                  chain16_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split3_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, math::pi<NV>>, 
                                 math::sin<NV>, 
                                 core::gain<NV>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>, 
                                  math::pi<NV>, 
                                  math::rect<NV>, 
                                  core::gain<NV>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::pi<NV>>, 
                                   math::fmod<NV>, 
                                   core::gain<NV>>;
using table4_t = wrap::data<math::table, 
                            data::external::table<0>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   math::pi<NV>, 
                                   table4_t, 
                                   core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain_t<NV>>, 
                                 chain9_t<NV>, 
                                 chain11_t<NV>, 
                                 chain13_t<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, modchain_t<NV>>, 
                                  xfader_t<NV>, 
                                  split_t<NV>, 
                                  core::gain<NV>, 
                                  filters::one_pole<NV>>;

namespace oscshaper_t_parameters
{
// Parameter list for oscshaper_impl::oscshaper_t --------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(XfStage_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(XfStage_0Range, 
                             3., 
                             6., 
                             1.);

template <int NV>
using XfStage_0 = parameter::from0To1<routing::event_data_reader<NV>, 
                                      0, 
                                      XfStage_0Range>;

template <int NV>
using XfStage = parameter::chain<XfStage_InputRange, XfStage_0<NV>>;

DECLARE_PARAMETER_RANGE(Midi1_InputRange, 
                        1., 
                        7.);
DECLARE_PARAMETER_RANGE_STEP(Midi1_0Range, 
                             0., 
                             6., 
                             1.);

template <int NV>
using Midi1_0 = parameter::from0To1<oscshaper_impl::branch5_t<NV>, 
                                    0, 
                                    Midi1_0Range>;

template <int NV>
using Midi1 = parameter::chain<Midi1_InputRange, Midi1_0<NV>>;

DECLARE_PARAMETER_RANGE(xf2_InputRange, 
                        1., 
                        4.);
template <int NV>
using xf2_0 = parameter::from0To1<oscshaper_impl::event_data_reader10_t<NV>, 
                                  0, 
                                  XfStage_0Range>;

template <int NV>
using xf2 = parameter::chain<xf2_InputRange, xf2_0<NV>>;

DECLARE_PARAMETER_RANGE(xf3_InputRange, 
                        1., 
                        4.);
template <int NV>
using xf3_0 = parameter::from0To1<oscshaper_impl::event_data_reader11_t<NV>, 
                                  0, 
                                  XfStage_0Range>;

template <int NV>
using xf3 = parameter::chain<xf3_InputRange, xf3_0<NV>>;

DECLARE_PARAMETER_RANGE(midi2_InputRange, 
                        1., 
                        7.);
template <int NV>
using midi2_0 = parameter::from0To1<oscshaper_impl::branch6_t<NV>, 
                                    0, 
                                    Midi1_0Range>;

template <int NV>
using midi2 = parameter::chain<midi2_InputRange, midi2_0<NV>>;

DECLARE_PARAMETER_RANGE(midi3_InputRange, 
                        1., 
                        7.);
template <int NV>
using midi3_0 = parameter::from0To1<oscshaper_impl::branch7_t<NV>, 
                                    0, 
                                    Midi1_0Range>;

template <int NV>
using midi3 = parameter::chain<midi3_InputRange, midi3_0<NV>>;

template <int NV>
using shaper = parameter::plain<oscshaper_impl::pma_t<NV>, 
                                2>;
template <int NV>
using width = parameter::plain<oscshaper_impl::pma4_t<NV>, 
                               2>;
template <int NV>
using out = parameter::plain<oscshaper_impl::pma3_t<NV>, 
                             2>;
template <int NV>
using shapemod = parameter::plain<oscshaper_impl::pma_t<NV>, 
                                  1>;
template <int NV>
using widthmod = parameter::plain<oscshaper_impl::pma4_t<NV>, 
                                  1>;
template <int NV>
using outmod = parameter::plain<oscshaper_impl::pma3_t<NV>, 
                                1>;
template <int NV>
using oscshaper_t_plist = parameter::list<shaper<NV>, 
                                          width<NV>, 
                                          out<NV>, 
                                          shapemod<NV>, 
                                          widthmod<NV>, 
                                          outmod<NV>, 
                                          XfStage<NV>, 
                                          Midi1<NV>, 
                                          xf2<NV>, 
                                          xf3<NV>, 
                                          midi2<NV>, 
                                          midi3<NV>>;
}

template <int NV>
using oscshaper_t_ = container::chain<oscshaper_t_parameters::oscshaper_t_plist<NV>, 
                                      wrap::fix<2, chain2_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public oscshaper_impl::oscshaper_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 1;
		static const int NumSliderPacks = 3;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(oscshaper);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(190)
		{
			0x005B, 0x0000, 0x7300, 0x6168, 0x6570, 0x0072, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0xCDEA, 0x3F63, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x015B, 0x0000, 0x7700, 0x6469, 0x6874, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x863F, 0xA12C, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0002, 0x0000, 0x756F, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x035B, 0x0000, 
            0x7300, 0x6168, 0x6570, 0x6F6D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0xF4DF, 0xBDCE, 0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 
            0x0000, 0x7700, 0x6469, 0x6874, 0x6F6D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x6666, 0x3CE6, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x055B, 0x0000, 0x6F00, 0x7475, 0x6F6D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x065B, 0x0000, 0x5800, 0x5366, 0x6174, 0x6567, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0007, 0x0000, 0x694D, 0x6964, 0x0031, 0x0000, 0x3F80, 
            0x0000, 0x40E0, 0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x085B, 0x0000, 0x7800, 0x3266, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0009, 
            0x0000, 0x6678, 0x0033, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0A5B, 0x0000, 0x6D00, 
            0x6469, 0x3269, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000B, 0x0000, 0x696D, 
            0x6964, 0x0033, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain2 = this->getT(0);                                                              // oscshaper_impl::chain2_t<NV>
		auto& modchain = this->getT(0).getT(0);                                                    // oscshaper_impl::modchain_t<NV>
		auto& split3 = this->getT(0).getT(0).getT(0);                                              // oscshaper_impl::split3_t<NV>
		auto& chain15 = this->getT(0).getT(0).getT(0).getT(0);                                     // oscshaper_impl::chain15_t<NV>
		auto& sliderbank = this->getT(0).getT(0).getT(0).getT(0).getT(0);                          // oscshaper_impl::sliderbank_t<NV>
		auto& split2 = this->getT(0).getT(0).getT(0).getT(0).getT(1);                              // oscshaper_impl::split2_t<NV>
		auto& chain1 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);                      // oscshaper_impl::chain1_t<NV>
		auto& global_cable = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);        // oscshaper_impl::global_cable_t<NV>
		auto& add = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);                 // math::add<NV>
		auto& gain = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(2);                // core::gain<NV>
		auto& chain4 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);                      // oscshaper_impl::chain4_t<NV>
		auto& global_cable2 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0);       // oscshaper_impl::global_cable2_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(1);                // math::add<NV>
		auto& gain9 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(2);               // core::gain<NV>
		auto& chain3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2);                      // oscshaper_impl::chain3_t<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(0);       // oscshaper_impl::global_cable1_t<NV>
		auto& add1 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(1);                // math::add<NV>
		auto& gain8 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(2);               // core::gain<NV>
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3);                      // oscshaper_impl::chain5_t<NV>
		auto& event_data_reader = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(0);   // oscshaper_impl::event_data_reader_t<NV>
		auto& add3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(1);                // math::add<NV>
		auto& gain7 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(2);               // core::gain<NV>
		auto& chain10 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(4);                     // oscshaper_impl::chain10_t<NV>
		auto& event_data_reader2 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(4).getT(0);  // oscshaper_impl::event_data_reader2_t<NV>
		auto& add7 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(4).getT(1);                // math::add<NV>
		auto& gain6 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(4).getT(2);               // core::gain<NV>
		auto& chain8 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5);                      // oscshaper_impl::chain8_t<NV>
		auto& event_data_reader1 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).getT(0);  // oscshaper_impl::event_data_reader1_t<NV>
		auto& add6 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).getT(1);                // math::add<NV>
		auto& gain5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).getT(2);               // core::gain<NV>
		auto& chain12 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(6);                     // oscshaper_impl::chain12_t<NV>
		auto& event_data_reader3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(6).getT(0);  // routing::event_data_reader<NV>
		auto& add8 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(6).getT(1);                // math::add<NV>
		auto& gain4 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(6).getT(2);               // core::gain<NV>
		auto& chain14 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(7);                     // oscshaper_impl::chain14_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(7).getT(0);             // oscshaper_impl::branch5_t<NV>
		auto& chain34 = this->getT(0).getT(0).getT(0).getT(0).                                     // oscshaper_impl::chain34_t<NV>
                        getT(1).getT(7).getT(0).getT(0);
		auto& midi_cc10 = this->getT(0).getT(0).getT(0).getT(0).                                   // oscshaper_impl::midi_cc10_t<NV>
                          getT(1).getT(7).getT(0).getT(0).
                          getT(0);
		auto& add50 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(0).
                      getT(1);
		auto& chain35 = this->getT(0).getT(0).getT(0).getT(0).                                     // oscshaper_impl::chain35_t<NV>
                        getT(1).getT(7).getT(0).getT(1);
		auto& midi_cc11 = this->getT(0).getT(0).getT(0).getT(0).                                   // oscshaper_impl::midi_cc11_t<NV>
                          getT(1).getT(7).getT(0).getT(1).
                          getT(0);
		auto& add51 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(1).
                      getT(1);
		auto& chain36 = this->getT(0).getT(0).getT(0).getT(0).                                     // oscshaper_impl::chain36_t<NV>
                        getT(1).getT(7).getT(0).getT(2);
		auto& midi_cc12 = this->getT(0).getT(0).getT(0).getT(0).                                   // oscshaper_impl::midi_cc12_t<NV>
                          getT(1).getT(7).getT(0).getT(2).
                          getT(0);
		auto& add52 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(2).
                      getT(1);
		auto& chain37 = this->getT(0).getT(0).getT(0).getT(0).                                     // oscshaper_impl::chain37_t<NV>
                        getT(1).getT(7).getT(0).getT(3);
		auto& midi_cc13 = this->getT(0).getT(0).getT(0).getT(0).                                   // oscshaper_impl::midi_cc13_t<NV>
                          getT(1).getT(7).getT(0).getT(3).
                          getT(0);
		auto& add53 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(3).
                      getT(1);
		auto& chain38 = this->getT(0).getT(0).getT(0).getT(0).                                     // oscshaper_impl::chain38_t<NV>
                        getT(1).getT(7).getT(0).getT(4);
		auto& midi6 = this->getT(0).getT(0).getT(0).getT(0).                                       // oscshaper_impl::midi6_t<NV>
                      getT(1).getT(7).getT(0).getT(4).
                      getT(0);
		auto& add54 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(4).
                      getT(1);
		auto& chain39 = this->getT(0).getT(0).getT(0).getT(0).                                     // oscshaper_impl::chain39_t<NV>
                        getT(1).getT(7).getT(0).getT(5);
		auto& midi7 = this->getT(0).getT(0).getT(0).getT(0).                                       // oscshaper_impl::midi7_t<NV>
                      getT(1).getT(7).getT(0).getT(5).
                      getT(0);
		auto& add55 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(5).
                      getT(1);
		auto& chain40 = this->getT(0).getT(0).getT(0).getT(0).                                     // oscshaper_impl::chain40_t<NV>
                        getT(1).getT(7).getT(0).getT(6);
		auto& midi8 = this->getT(0).getT(0).getT(0).getT(0).                                       // oscshaper_impl::midi8_t<NV>
                      getT(1).getT(7).getT(0).getT(6).
                      getT(0);
		auto& add56 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(6).
                      getT(1);
		auto& gain3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(7).getT(1);               // core::gain<NV>
		auto& peak = this->getT(0).getT(0).getT(0).getT(0).getT(2);                                // oscshaper_impl::peak_t<NV>
		auto& pma = this->getT(0).getT(0).getT(0).getT(0).getT(3);                                 // oscshaper_impl::pma_t<NV>
		auto& chain25 = this->getT(0).getT(0).getT(0).getT(1);                                     // oscshaper_impl::chain25_t<NV>
		auto& sliderbank2 = this->getT(0).getT(0).getT(0).getT(1).getT(0);                         // oscshaper_impl::sliderbank2_t<NV>
		auto& split5 = this->getT(0).getT(0).getT(0).getT(1).getT(1);                              // oscshaper_impl::split5_t<NV>
		auto& chain26 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(0);                     // oscshaper_impl::chain26_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).getT(0);       // oscshaper_impl::global_cable7_t<NV>
		auto& add18 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain23 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain27 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(1);                     // oscshaper_impl::chain27_t<NV>
		auto& global_cable8 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(1).getT(0);       // oscshaper_impl::global_cable8_t<NV>
		auto& add19 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(1).getT(1);               // math::add<NV>
		auto& gain24 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(1).getT(2);              // core::gain<NV>
		auto& chain28 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(2);                     // oscshaper_impl::chain28_t<NV>
		auto& global_cable9 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(2).getT(0);       // oscshaper_impl::global_cable9_t<NV>
		auto& add20 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(2).getT(1);               // math::add<NV>
		auto& gain25 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(2).getT(2);              // core::gain<NV>
		auto& chain29 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(3);                     // oscshaper_impl::chain29_t<NV>
		auto& event_data_reader7 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(3).getT(0);  // oscshaper_impl::event_data_reader7_t<NV>
		auto& add21 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(3).getT(1);               // math::add<NV>
		auto& gain27 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(3).getT(2);              // core::gain<NV>
		auto& chain30 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(4);                     // oscshaper_impl::chain30_t<NV>
		auto& event_data_reader8 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(4).getT(0);  // oscshaper_impl::event_data_reader8_t<NV>
		auto& add22 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(4).getT(1);               // math::add<NV>
		auto& gain28 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(4).getT(2);              // core::gain<NV>
		auto& chain31 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(5);                     // oscshaper_impl::chain31_t<NV>
		auto& event_data_reader9 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(5).getT(0);  // oscshaper_impl::event_data_reader9_t<NV>
		auto& add23 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(5).getT(1);               // math::add<NV>
		auto& gain29 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(5).getT(2);              // core::gain<NV>
		auto& chain32 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(6);                     // oscshaper_impl::chain32_t<NV>
		auto& event_data_reader10 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(6).getT(0); // oscshaper_impl::event_data_reader10_t<NV>
		auto& add24 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(6).getT(1);               // math::add<NV>
		auto& gain30 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(6).getT(2);              // core::gain<NV>
		auto& chain33 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(7);                     // oscshaper_impl::chain33_t<NV>
		auto& branch6 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(7).getT(0);             // oscshaper_impl::branch6_t<NV>
		auto& chain41 = this->getT(0).getT(0).getT(0).getT(1).                                     // oscshaper_impl::chain41_t<NV>
                        getT(1).getT(7).getT(0).getT(0);
		auto& midi_cc14 = this->getT(0).getT(0).getT(0).getT(1).                                   // oscshaper_impl::midi_cc14_t<NV>
                          getT(1).getT(7).getT(0).getT(0).
                          getT(0);
		auto& add57 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(0).
                      getT(1);
		auto& chain42 = this->getT(0).getT(0).getT(0).getT(1).                                     // oscshaper_impl::chain42_t<NV>
                        getT(1).getT(7).getT(0).getT(1);
		auto& midi_cc15 = this->getT(0).getT(0).getT(0).getT(1).                                   // oscshaper_impl::midi_cc15_t<NV>
                          getT(1).getT(7).getT(0).getT(1).
                          getT(0);
		auto& add58 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(1).
                      getT(1);
		auto& chain43 = this->getT(0).getT(0).getT(0).getT(1).                                     // oscshaper_impl::chain43_t<NV>
                        getT(1).getT(7).getT(0).getT(2);
		auto& midi_cc16 = this->getT(0).getT(0).getT(0).getT(1).                                   // oscshaper_impl::midi_cc16_t<NV>
                          getT(1).getT(7).getT(0).getT(2).
                          getT(0);
		auto& add59 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(2).
                      getT(1);
		auto& chain44 = this->getT(0).getT(0).getT(0).getT(1).                                     // oscshaper_impl::chain44_t<NV>
                        getT(1).getT(7).getT(0).getT(3);
		auto& midi_cc17 = this->getT(0).getT(0).getT(0).getT(1).                                   // oscshaper_impl::midi_cc17_t<NV>
                          getT(1).getT(7).getT(0).getT(3).
                          getT(0);
		auto& add60 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(3).
                      getT(1);
		auto& chain45 = this->getT(0).getT(0).getT(0).getT(1).                                     // oscshaper_impl::chain45_t<NV>
                        getT(1).getT(7).getT(0).getT(4);
		auto& midi9 = this->getT(0).getT(0).getT(0).getT(1).                                       // oscshaper_impl::midi9_t<NV>
                      getT(1).getT(7).getT(0).getT(4).
                      getT(0);
		auto& add61 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(4).
                      getT(1);
		auto& chain46 = this->getT(0).getT(0).getT(0).getT(1).                                     // oscshaper_impl::chain46_t<NV>
                        getT(1).getT(7).getT(0).getT(5);
		auto& midi10 = this->getT(0).getT(0).getT(0).getT(1).                                      // oscshaper_impl::midi10_t<NV>
                       getT(1).getT(7).getT(0).getT(5).
                       getT(0);
		auto& add62 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(5).
                      getT(1);
		auto& chain47 = this->getT(0).getT(0).getT(0).getT(1).                                     // oscshaper_impl::chain47_t<NV>
                        getT(1).getT(7).getT(0).getT(6);
		auto& midi11 = this->getT(0).getT(0).getT(0).getT(1).                                      // oscshaper_impl::midi11_t<NV>
                       getT(1).getT(7).getT(0).getT(6).
                       getT(0);
		auto& add63 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(6).
                      getT(1);
		auto& gain31 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(7).getT(1);              // core::gain<NV>
		auto& peak2 = this->getT(0).getT(0).getT(0).getT(1).getT(2);                               // oscshaper_impl::peak2_t<NV>
		auto& pma4 = this->getT(0).getT(0).getT(0).getT(1).getT(3);                                // oscshaper_impl::pma4_t<NV>
		auto& chain16 = this->getT(0).getT(0).getT(0).getT(2);                                     // oscshaper_impl::chain16_t<NV>
		auto& sliderbank1 = this->getT(0).getT(0).getT(0).getT(2).getT(0);                         // oscshaper_impl::sliderbank1_t<NV>
		auto& split4 = this->getT(0).getT(0).getT(0).getT(2).getT(1);                              // oscshaper_impl::split4_t<NV>
		auto& chain17 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0);                     // oscshaper_impl::chain17_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(0);       // oscshaper_impl::global_cable4_t<NV>
		auto& add10 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain10 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain18 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1);                     // oscshaper_impl::chain18_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1).getT(0);       // oscshaper_impl::global_cable5_t<NV>
		auto& add11 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1).getT(1);               // math::add<NV>
		auto& gain12 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1).getT(2);              // core::gain<NV>
		auto& chain19 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(2);                     // oscshaper_impl::chain19_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(2).getT(0);       // oscshaper_impl::global_cable6_t<NV>
		auto& add12 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(2).getT(1);               // math::add<NV>
		auto& gain17 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(2).getT(2);              // core::gain<NV>
		auto& chain20 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(3);                     // oscshaper_impl::chain20_t<NV>
		auto& event_data_reader4 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(3).getT(0);  // oscshaper_impl::event_data_reader4_t<NV>
		auto& add13 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(3).getT(1);               // math::add<NV>
		auto& gain18 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(3).getT(2);              // core::gain<NV>
		auto& chain21 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(4);                     // oscshaper_impl::chain21_t<NV>
		auto& event_data_reader5 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(4).getT(0);  // oscshaper_impl::event_data_reader5_t<NV>
		auto& add14 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(4).getT(1);               // math::add<NV>
		auto& gain19 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(4).getT(2);              // core::gain<NV>
		auto& chain22 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(5);                     // oscshaper_impl::chain22_t<NV>
		auto& event_data_reader6 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(5).getT(0);  // oscshaper_impl::event_data_reader6_t<NV>
		auto& add15 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(5).getT(1);               // math::add<NV>
		auto& gain20 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(5).getT(2);              // core::gain<NV>
		auto& chain23 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(6);                     // oscshaper_impl::chain23_t<NV>
		auto& event_data_reader11 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(6).getT(0); // oscshaper_impl::event_data_reader11_t<NV>
		auto& add16 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(6).getT(1);               // math::add<NV>
		auto& gain21 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(6).getT(2);              // core::gain<NV>
		auto& chain24 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(7);                     // oscshaper_impl::chain24_t<NV>
		auto& branch7 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(7).getT(0);             // oscshaper_impl::branch7_t<NV>
		auto& chain48 = this->getT(0).getT(0).getT(0).getT(2).                                     // oscshaper_impl::chain48_t<NV>
                        getT(1).getT(7).getT(0).getT(0);
		auto& midi_cc18 = this->getT(0).getT(0).getT(0).getT(2).                      // oscshaper_impl::midi_cc18_t<NV>
                          getT(1).getT(7).getT(0).getT(0).
                          getT(0);
		auto& add64 = this->getT(0).getT(0).getT(0).getT(2).                          // math::add<NV>
                      getT(1).getT(7).getT(0).getT(0).
                      getT(1);
		auto& chain49 = this->getT(0).getT(0).getT(0).getT(2).                        // oscshaper_impl::chain49_t<NV>
                        getT(1).getT(7).getT(0).getT(1);
		auto& midi_cc19 = this->getT(0).getT(0).getT(0).getT(2).                      // oscshaper_impl::midi_cc19_t<NV>
                          getT(1).getT(7).getT(0).getT(1).
                          getT(0);
		auto& add65 = this->getT(0).getT(0).getT(0).getT(2).                          // math::add<NV>
                      getT(1).getT(7).getT(0).getT(1).
                      getT(1);
		auto& chain50 = this->getT(0).getT(0).getT(0).getT(2).                        // oscshaper_impl::chain50_t<NV>
                        getT(1).getT(7).getT(0).getT(2);
		auto& midi_cc20 = this->getT(0).getT(0).getT(0).getT(2).                      // oscshaper_impl::midi_cc20_t<NV>
                          getT(1).getT(7).getT(0).getT(2).
                          getT(0);
		auto& add66 = this->getT(0).getT(0).getT(0).getT(2).                          // math::add<NV>
                      getT(1).getT(7).getT(0).getT(2).
                      getT(1);
		auto& chain51 = this->getT(0).getT(0).getT(0).getT(2).                        // oscshaper_impl::chain51_t<NV>
                        getT(1).getT(7).getT(0).getT(3);
		auto& midi_cc21 = this->getT(0).getT(0).getT(0).getT(2).                      // oscshaper_impl::midi_cc21_t<NV>
                          getT(1).getT(7).getT(0).getT(3).
                          getT(0);
		auto& add67 = this->getT(0).getT(0).getT(0).getT(2).                          // math::add<NV>
                      getT(1).getT(7).getT(0).getT(3).
                      getT(1);
		auto& chain52 = this->getT(0).getT(0).getT(0).getT(2).                        // oscshaper_impl::chain52_t<NV>
                        getT(1).getT(7).getT(0).getT(4);
		auto& midi12 = this->getT(0).getT(0).getT(0).getT(2).                         // oscshaper_impl::midi12_t<NV>
                       getT(1).getT(7).getT(0).getT(4).
                       getT(0);
		auto& add68 = this->getT(0).getT(0).getT(0).getT(2).                          // math::add<NV>
                      getT(1).getT(7).getT(0).getT(4).
                      getT(1);
		auto& chain53 = this->getT(0).getT(0).getT(0).getT(2).                        // oscshaper_impl::chain53_t<NV>
                        getT(1).getT(7).getT(0).getT(5);
		auto& midi13 = this->getT(0).getT(0).getT(0).getT(2).                         // oscshaper_impl::midi13_t<NV>
                       getT(1).getT(7).getT(0).getT(5).
                       getT(0);
		auto& add69 = this->getT(0).getT(0).getT(0).getT(2).                          // math::add<NV>
                      getT(1).getT(7).getT(0).getT(5).
                      getT(1);
		auto& chain54 = this->getT(0).getT(0).getT(0).getT(2).                        // oscshaper_impl::chain54_t<NV>
                        getT(1).getT(7).getT(0).getT(6);
		auto& midi14 = this->getT(0).getT(0).getT(0).getT(2).                         // oscshaper_impl::midi14_t<NV>
                       getT(1).getT(7).getT(0).getT(6).
                       getT(0);
		auto& add70 = this->getT(0).getT(0).getT(0).getT(2).                          // math::add<NV>
                      getT(1).getT(7).getT(0).getT(6).
                      getT(1);
		auto& gain22 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(7).getT(1); // core::gain<NV>
		auto& peak1 = this->getT(0).getT(0).getT(0).getT(2).getT(2);                  // oscshaper_impl::peak1_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(0).getT(2).getT(3);                   // oscshaper_impl::pma3_t<NV>
		auto& xfader = this->getT(0).getT(1);                                         // oscshaper_impl::xfader_t<NV>
		auto& split = this->getT(0).getT(2);                                          // oscshaper_impl::split_t<NV>
		auto& chain = this->getT(0).getT(2).getT(0);                                  // oscshaper_impl::chain_t<NV>
		auto& pi1 = this->getT(0).getT(2).getT(0).getT(0);                            // math::pi<NV>
		auto& sin3 = this->getT(0).getT(2).getT(0).getT(1);                           // math::sin<NV>
		auto& gain11 = this->getT(0).getT(2).getT(0).getT(2);                         // core::gain<NV>
		auto& chain9 = this->getT(0).getT(2).getT(1);                                 // oscshaper_impl::chain9_t<NV>
		auto& gain16 = this->getT(0).getT(2).getT(1).getT(0);                         // core::gain<NV>
		auto& pi4 = this->getT(0).getT(2).getT(1).getT(1);                            // math::pi<NV>
		auto& rect1 = this->getT(0).getT(2).getT(1).getT(2);                          // math::rect<NV>
		auto& gain13 = this->getT(0).getT(2).getT(1).getT(3);                         // core::gain<NV>
		auto& chain11 = this->getT(0).getT(2).getT(2);                                // oscshaper_impl::chain11_t<NV>
		auto& pi5 = this->getT(0).getT(2).getT(2).getT(0);                            // math::pi<NV>
		auto& fmod1 = this->getT(0).getT(2).getT(2).getT(1);                          // math::fmod<NV>
		auto& gain15 = this->getT(0).getT(2).getT(2).getT(2);                         // core::gain<NV>
		auto& chain13 = this->getT(0).getT(2).getT(3);                                // oscshaper_impl::chain13_t<NV>
		auto& gain14 = this->getT(0).getT(2).getT(3).getT(0);                         // core::gain<NV>
		auto& pi6 = this->getT(0).getT(2).getT(3).getT(1);                            // math::pi<NV>
		auto& table4 = this->getT(0).getT(2).getT(3).getT(2);                         // oscshaper_impl::table4_t
		auto& gain26 = this->getT(0).getT(2).getT(3).getT(3);                         // core::gain<NV>
		auto& gain1 = this->getT(0).getT(3);                                          // core::gain<NV>
		auto& one_pole = this->getT(0).getT(4);                                       // filters::one_pole<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma); // shaper -> pma::Add
		
		this->getParameterT(1).connectT(0, pma4); // width -> pma4::Add
		
		this->getParameterT(2).connectT(0, pma3); // out -> pma3::Add
		
		this->getParameterT(3).connectT(0, pma); // shapemod -> pma::Multiply
		
		this->getParameterT(4).connectT(0, pma4); // widthmod -> pma4::Multiply
		
		this->getParameterT(5).connectT(0, pma3); // outmod -> pma3::Multiply
		
		this->getParameterT(6).connectT(0, event_data_reader3); // XfStage -> event_data_reader3::SlotIndex
		
		this->getParameterT(7).connectT(0, branch5); // Midi1 -> branch5::Index
		
		this->getParameterT(8).connectT(0, event_data_reader10); // xf2 -> event_data_reader10::SlotIndex
		
		this->getParameterT(9).connectT(0, event_data_reader11); // xf3 -> event_data_reader11::SlotIndex
		
		this->getParameterT(10).connectT(0, branch6); // midi2 -> branch6::Index
		
		this->getParameterT(11).connectT(0, branch7); // midi3 -> branch7::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& sliderbank_p = sliderbank.getWrappedObject().getParameter();
		sliderbank_p.getParameterT(0).connectT(0, gain);                   // sliderbank -> gain::Gain
		sliderbank_p.getParameterT(1).connectT(0, gain9);                  // sliderbank -> gain9::Gain
		sliderbank_p.getParameterT(2).connectT(0, gain8);                  // sliderbank -> gain8::Gain
		sliderbank_p.getParameterT(3).connectT(0, gain7);                  // sliderbank -> gain7::Gain
		sliderbank_p.getParameterT(4).connectT(0, gain6);                  // sliderbank -> gain6::Gain
		sliderbank_p.getParameterT(5).connectT(0, gain5);                  // sliderbank -> gain5::Gain
		sliderbank_p.getParameterT(6).connectT(0, gain4);                  // sliderbank -> gain4::Gain
		sliderbank_p.getParameterT(7).connectT(0, gain3);                  // sliderbank -> gain3::Gain
		global_cable.getWrappedObject().getParameter().connectT(0, add);   // global_cable -> add::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add2); // global_cable2 -> add2::Value
		global_cable1.getWrappedObject().getParameter().connectT(0, add1); // global_cable1 -> add1::Value
		event_data_reader.getParameter().connectT(0, add3);                // event_data_reader -> add3::Value
		event_data_reader2.getParameter().connectT(0, add7);               // event_data_reader2 -> add7::Value
		event_data_reader1.getParameter().connectT(0, add6);               // event_data_reader1 -> add6::Value
		midi_cc10.getWrappedObject().getParameter().connectT(0, add50);    // midi_cc10 -> add50::Value
		midi_cc11.getWrappedObject().getParameter().connectT(0, add51);    // midi_cc11 -> add51::Value
		midi_cc12.getWrappedObject().getParameter().connectT(0, add52);    // midi_cc12 -> add52::Value
		midi_cc13.getWrappedObject().getParameter().connectT(0, add53);    // midi_cc13 -> add53::Value
		midi6.getParameter().connectT(0, add54);                           // midi6 -> add54::Value
		midi7.getParameter().connectT(0, add55);                           // midi7 -> add55::Value
		midi8.getParameter().connectT(0, add56);                           // midi8 -> add56::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain11);             // xfader -> gain11::Gain
		xfader_p.getParameterT(1).connectT(0, gain13);             // xfader -> gain13::Gain
		xfader_p.getParameterT(2).connectT(0, gain15);             // xfader -> gain15::Gain
		xfader_p.getParameterT(3).connectT(0, gain26);             // xfader -> gain26::Gain
		pma.getWrappedObject().getParameter().connectT(0, xfader); // pma -> xfader::Value
		peak.getParameter().connectT(0, pma);                      // peak -> pma::Value
		auto& sliderbank2_p = sliderbank2.getWrappedObject().getParameter();
		sliderbank2_p.getParameterT(0).connectT(0, gain23);                 // sliderbank2 -> gain23::Gain
		sliderbank2_p.getParameterT(1).connectT(0, gain24);                 // sliderbank2 -> gain24::Gain
		sliderbank2_p.getParameterT(2).connectT(0, gain25);                 // sliderbank2 -> gain25::Gain
		sliderbank2_p.getParameterT(3).connectT(0, gain27);                 // sliderbank2 -> gain27::Gain
		sliderbank2_p.getParameterT(4).connectT(0, gain28);                 // sliderbank2 -> gain28::Gain
		sliderbank2_p.getParameterT(5).connectT(0, gain29);                 // sliderbank2 -> gain29::Gain
		sliderbank2_p.getParameterT(6).connectT(0, gain30);                 // sliderbank2 -> gain30::Gain
		sliderbank2_p.getParameterT(7).connectT(0, gain31);                 // sliderbank2 -> gain31::Gain
		global_cable7.getWrappedObject().getParameter().connectT(0, add18); // global_cable7 -> add18::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, add19); // global_cable8 -> add19::Value
		global_cable9.getWrappedObject().getParameter().connectT(0, add20); // global_cable9 -> add20::Value
		event_data_reader7.getParameter().connectT(0, add21);               // event_data_reader7 -> add21::Value
		event_data_reader8.getParameter().connectT(0, add22);               // event_data_reader8 -> add22::Value
		event_data_reader9.getParameter().connectT(0, add23);               // event_data_reader9 -> add23::Value
		event_data_reader10.getParameter().connectT(0, add24);              // event_data_reader10 -> add24::Value
		midi_cc14.getWrappedObject().getParameter().connectT(0, add57);     // midi_cc14 -> add57::Value
		midi_cc15.getWrappedObject().getParameter().connectT(0, add58);     // midi_cc15 -> add58::Value
		midi_cc16.getWrappedObject().getParameter().connectT(0, add59);     // midi_cc16 -> add59::Value
		midi_cc17.getWrappedObject().getParameter().connectT(0, add60);     // midi_cc17 -> add60::Value
		midi9.getParameter().connectT(0, add61);                            // midi9 -> add61::Value
		midi10.getParameter().connectT(0, add62);                           // midi10 -> add62::Value
		midi11.getParameter().connectT(0, add63);                           // midi11 -> add63::Value
		pma4.getWrappedObject().getParameter().connectT(0, pi1);            // pma4 -> pi1::Value
		pma4.getWrappedObject().getParameter().connectT(1, gain16);         // pma4 -> gain16::Gain
		pma4.getWrappedObject().getParameter().connectT(2, pi5);            // pma4 -> pi5::Value
		pma4.getWrappedObject().getParameter().connectT(3, gain14);         // pma4 -> gain14::Gain
		peak2.getParameter().connectT(0, pma4);                             // peak2 -> pma4::Value
		auto& sliderbank1_p = sliderbank1.getWrappedObject().getParameter();
		sliderbank1_p.getParameterT(0).connectT(0, gain10);                 // sliderbank1 -> gain10::Gain
		sliderbank1_p.getParameterT(1).connectT(0, gain12);                 // sliderbank1 -> gain12::Gain
		sliderbank1_p.getParameterT(2).connectT(0, gain17);                 // sliderbank1 -> gain17::Gain
		sliderbank1_p.getParameterT(3).connectT(0, gain18);                 // sliderbank1 -> gain18::Gain
		sliderbank1_p.getParameterT(4).connectT(0, gain19);                 // sliderbank1 -> gain19::Gain
		sliderbank1_p.getParameterT(5).connectT(0, gain20);                 // sliderbank1 -> gain20::Gain
		sliderbank1_p.getParameterT(6).connectT(0, gain21);                 // sliderbank1 -> gain21::Gain
		sliderbank1_p.getParameterT(7).connectT(0, gain22);                 // sliderbank1 -> gain22::Gain
		global_cable4.getWrappedObject().getParameter().connectT(0, add10); // global_cable4 -> add10::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add11); // global_cable5 -> add11::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add12); // global_cable6 -> add12::Value
		event_data_reader4.getParameter().connectT(0, add13);               // event_data_reader4 -> add13::Value
		event_data_reader5.getParameter().connectT(0, add14);               // event_data_reader5 -> add14::Value
		event_data_reader6.getParameter().connectT(0, add15);               // event_data_reader6 -> add15::Value
		event_data_reader11.getParameter().connectT(0, add16);              // event_data_reader11 -> add16::Value
		midi_cc18.getWrappedObject().getParameter().connectT(0, add64);     // midi_cc18 -> add64::Value
		midi_cc19.getWrappedObject().getParameter().connectT(0, add65);     // midi_cc19 -> add65::Value
		midi_cc20.getWrappedObject().getParameter().connectT(0, add66);     // midi_cc20 -> add66::Value
		midi_cc21.getWrappedObject().getParameter().connectT(0, add67);     // midi_cc21 -> add67::Value
		midi12.getParameter().connectT(0, add68);                           // midi12 -> add68::Value
		midi13.getParameter().connectT(0, add69);                           // midi13 -> add69::Value
		midi14.getParameter().connectT(0, add70);                           // midi14 -> add70::Value
		pma3.getWrappedObject().getParameter().connectT(0, gain1);          // pma3 -> gain1::Gain
		peak1.getParameter().connectT(0, pma3);                             // peak1 -> pma3::Value
		
		// Default Values --------------------------------------------------------------------------
		
		sliderbank.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add::Value is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add2::Value is automated
		
		;                            // gain9::Gain is automated
		gain9.setParameterT(1, 20.); // core::gain::Smoothing
		gain9.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add1::Value is automated
		
		;                            // gain8::Gain is automated
		gain8.setParameterT(1, 20.); // core::gain::Smoothing
		gain8.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add3::Value is automated
		
		;                            // gain7::Gain is automated
		gain7.setParameterT(1, 20.); // core::gain::Smoothing
		gain7.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader2.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader2.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add7::Value is automated
		
		;                            // gain6::Gain is automated
		gain6.setParameterT(1, 20.); // core::gain::Smoothing
		gain6.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader1.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader1.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add6::Value is automated
		
		;                            // gain5::Gain is automated
		gain5.setParameterT(1, 20.); // core::gain::Smoothing
		gain5.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                        // event_data_reader3::SlotIndex is automated
		event_data_reader3.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		add8.setParameterT(0, 0.); // math::add::Value
		
		;                            // gain4::Gain is automated
		gain4.setParameterT(1, 20.); // core::gain::Smoothing
		gain4.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch5::Index is automated
		
		midi_cc10.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc10.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc10.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add50::Value is automated
		
		midi_cc11.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc11.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc11.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add51::Value is automated
		
		midi_cc12.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc12.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc12.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add52::Value is automated
		
		midi_cc13.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc13.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc13.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add53::Value is automated
		
		; // add54::Value is automated
		
		; // add55::Value is automated
		
		; // add56::Value is automated
		
		;                            // gain3::Gain is automated
		gain3.setParameterT(1, 20.); // core::gain::Smoothing
		gain3.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		sliderbank2.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add18::Value is automated
		
		;                             // gain23::Gain is automated
		gain23.setParameterT(1, 20.); // core::gain::Smoothing
		gain23.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add19::Value is automated
		
		;                             // gain24::Gain is automated
		gain24.setParameterT(1, 20.); // core::gain::Smoothing
		gain24.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable9.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add20::Value is automated
		
		;                             // gain25::Gain is automated
		gain25.setParameterT(1, 20.); // core::gain::Smoothing
		gain25.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader7.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader7.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add21::Value is automated
		
		;                             // gain27::Gain is automated
		gain27.setParameterT(1, 20.); // core::gain::Smoothing
		gain27.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader8.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader8.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add22::Value is automated
		
		;                             // gain28::Gain is automated
		gain28.setParameterT(1, 20.); // core::gain::Smoothing
		gain28.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader9.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader9.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add23::Value is automated
		
		;                             // gain29::Gain is automated
		gain29.setParameterT(1, 20.); // core::gain::Smoothing
		gain29.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader10::SlotIndex is automated
		event_data_reader10.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add24::Value is automated
		
		;                             // gain30::Gain is automated
		gain30.setParameterT(1, 20.); // core::gain::Smoothing
		gain30.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch6::Index is automated
		
		midi_cc14.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc14.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc14.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add57::Value is automated
		
		midi_cc15.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc15.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc15.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add58::Value is automated
		
		midi_cc16.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc16.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc16.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add59::Value is automated
		
		midi_cc17.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc17.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc17.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add60::Value is automated
		
		; // add61::Value is automated
		
		; // add62::Value is automated
		
		; // add63::Value is automated
		
		;                             // gain31::Gain is automated
		gain31.setParameterT(1, 20.); // core::gain::Smoothing
		gain31.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma4::Value is automated
		; // pma4::Multiply is automated
		; // pma4::Add is automated
		
		sliderbank1.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		;                             // gain10::Gain is automated
		gain10.setParameterT(1, 20.); // core::gain::Smoothing
		gain10.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add11::Value is automated
		
		;                             // gain12::Gain is automated
		gain12.setParameterT(1, 20.); // core::gain::Smoothing
		gain12.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		;                             // gain17::Gain is automated
		gain17.setParameterT(1, 20.); // core::gain::Smoothing
		gain17.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader4.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader4.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add13::Value is automated
		
		;                             // gain18::Gain is automated
		gain18.setParameterT(1, 20.); // core::gain::Smoothing
		gain18.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader5.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader5.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add14::Value is automated
		
		;                             // gain19::Gain is automated
		gain19.setParameterT(1, 20.); // core::gain::Smoothing
		gain19.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader6.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader6.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add15::Value is automated
		
		;                             // gain20::Gain is automated
		gain20.setParameterT(1, 20.); // core::gain::Smoothing
		gain20.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader11::SlotIndex is automated
		event_data_reader11.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add16::Value is automated
		
		;                             // gain21::Gain is automated
		gain21.setParameterT(1, 20.); // core::gain::Smoothing
		gain21.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch7::Index is automated
		
		midi_cc18.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc18.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc18.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add64::Value is automated
		
		midi_cc19.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc19.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc19.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add65::Value is automated
		
		midi_cc20.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc20.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc20.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add66::Value is automated
		
		midi_cc21.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc21.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc21.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add67::Value is automated
		
		; // add68::Value is automated
		
		; // add69::Value is automated
		
		; // add70::Value is automated
		
		;                             // gain22::Gain is automated
		gain22.setParameterT(1, 20.); // core::gain::Smoothing
		gain22.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma3::Value is automated
		; // pma3::Multiply is automated
		; // pma3::Add is automated
		
		; // xfader::Value is automated
		
		; // pi1::Value is automated
		
		sin3.setParameterT(0, 1.); // math::sin::Value
		
		;                              // gain11::Gain is automated
		gain11.setParameterT(1, 20.);  // core::gain::Smoothing
		gain11.setParameterT(2, -11.); // core::gain::ResetValue
		
		;                              // gain16::Gain is automated
		gain16.setParameterT(1, 20.);  // core::gain::Smoothing
		gain16.setParameterT(2, -12.); // core::gain::ResetValue
		
		pi4.setParameterT(0, 1.); // math::pi::Value
		
		rect1.setParameterT(0, 1.); // math::rect::Value
		
		;                              // gain13::Gain is automated
		gain13.setParameterT(1, 20.);  // core::gain::Smoothing
		gain13.setParameterT(2, -11.); // core::gain::ResetValue
		
		; // pi5::Value is automated
		
		fmod1.setParameterT(0, 0.0450156); // math::fmod::Value
		
		;                              // gain15::Gain is automated
		gain15.setParameterT(1, 20.);  // core::gain::Smoothing
		gain15.setParameterT(2, -8.8); // core::gain::ResetValue
		
		;                              // gain14::Gain is automated
		gain14.setParameterT(1, 10.8); // core::gain::Smoothing
		gain14.setParameterT(2, -11.); // core::gain::ResetValue
		
		pi6.setParameterT(0, 1.); // math::pi::Value
		
		;                              // gain26::Gain is automated
		gain26.setParameterT(1, 20.);  // core::gain::Smoothing
		gain26.setParameterT(2, -9.5); // core::gain::ResetValue
		
		;                             // gain1::Gain is automated
		gain1.setParameterT(1, 20.);  // core::gain::Smoothing
		gain1.setParameterT(2, -18.); // core::gain::ResetValue
		
		one_pole.setParameterT(0, 50.1457); // filters::one_pole::Frequency
		one_pole.setParameterT(1, 1.);      // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);      // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01);    // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 1.);      // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		this->setParameterT(0, 0.889861);
		this->setParameterT(1, 0.314793);
		this->setParameterT(2, 1.);
		this->setParameterT(3, -0.101053);
		this->setParameterT(4, 0.028125);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 2.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 1.);
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
		
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable2_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable1_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable7_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable8_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable9_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable4_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable5_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable6_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // oscshaper_impl::sliderbank_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index); // oscshaper_impl::peak_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).setExternalData(b, index); // oscshaper_impl::sliderbank2_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(2).setExternalData(b, index); // oscshaper_impl::peak2_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).setExternalData(b, index); // oscshaper_impl::sliderbank1_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(2).setExternalData(b, index); // oscshaper_impl::peak1_t<NV>
		this->getT(0).getT(2).getT(3).getT(2).setExternalData(b, index);         // oscshaper_impl::table4_t
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
using oscshaper = wrap::node<oscshaper_impl::instance<NV>>;
}


