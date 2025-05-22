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

namespace osc1_impl
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
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader10_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::event_data_reader<NV>>, 
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
using midi6_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi6_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using midi7_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi7_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using midi8_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi8_t<NV>>, 
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
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch5_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain39_t<NV>>, 
                                  chain41_t<NV>, 
                                  chain40_t<NV>, 
                                  chain42_t<NV>, 
                                  chain44_t<NV>, 
                                  chain43_t<NV>, 
                                  chain45_t<NV>, 
                                  chain46_t<NV>>;

template <int NV>
using pma1_t = control::pma<NV, 
                            parameter::plain<math::add<NV>, 0>>;

template <int NV> using pma9_t = pma1_t<NV>;

template <int NV>
using converter5_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<core::phasor_fm<NV>, 2>, 
                                        parameter::plain<core::fm, 2>, 
                                        parameter::plain<core::phasor_fm<NV>, 2>, 
                                        parameter::plain<core::fm, 2>>;

template <int NV>
using converter5_t = control::converter<converter5_mod<NV>, 
                                        conversion_logic::ms2freq>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<converter5_t<NV>, 0>, 
                               control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(pma8_modRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma8_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                     0, 
                                     pma8_modRange>;

template <int NV>
using pma8_t = control::pma<NV, pma8_mod<NV>>;

DECLARE_PARAMETER_RANGE_STEP(pma11_modRange, 
                             5., 
                             2000., 
                             0.1);

template <int NV>
using pma11_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                      3, 
                                      pma11_modRange>;

template <int NV>
using pma11_t = control::pma<NV, pma11_mod<NV>>;

template <int NV>
using peak3_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma1_t<NV>, 0>, 
                                   parameter::plain<pma9_t<NV>, 0>, 
                                   parameter::plain<pma8_t<NV>, 0>, 
                                   parameter::plain<pma11_t<NV>, 0>>;

template <int NV>
using peak3_t = wrap::mod<peak3_mod<NV>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma1_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma9_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma8_t<NV>>>;

template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<pma11_t<NV>, 2>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, minmax_t<NV>>, 
                                   pma11_t<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain17_t<NV>>, 
                                    chain19_t<NV>, 
                                    chain21_t<NV>, 
                                    chain23_t<NV>>;

template <int NV>
using converter_mod = parameter::chain<ranges::Identity, 
                                       parameter::plain<core::phasor_fm<NV>, 2>, 
                                       parameter::plain<core::fm, 2>>;

template <int NV>
using converter_t = control::converter<converter_mod<NV>, 
                                       conversion_logic::st2pitch>;
template <int NV>
using minmax2_t = control::minmax<NV, 
                                  parameter::plain<converter_t<NV>, 0>>;

template <int NV> using minmax1_mod = converter_mod<NV>;

template <int NV>
using minmax1_t = control::minmax<NV, minmax1_mod<NV>>;

template <int NV>
using peak_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<minmax2_t<NV>, 0>, 
                                  parameter::plain<minmax1_t<NV>, 0>>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch3_t<NV>>, 
                                   peak_t<NV>>;

using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, core::empty>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank3_t<NV>>, 
                                      split3_t<NV>, 
                                      peak3_t<NV>, 
                                      math::clear<NV>, 
                                      chain20_t<NV>, 
                                      split7_t>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV> using sliderbank4_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank4_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank4_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank4_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank4_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank4_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank4_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank4_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank4_multimod = parameter::list<sliderbank4_c0<NV>, 
                                             sliderbank4_c1<NV>, 
                                             sliderbank4_c2<NV>, 
                                             sliderbank4_c3<NV>, 
                                             sliderbank4_c4<NV>, 
                                             sliderbank4_c5<NV>, 
                                             sliderbank4_c6<NV>, 
                                             sliderbank4_c7<NV>>;

template <int NV>
using sliderbank4_t = wrap::data<control::sliderbank<sliderbank4_multimod<NV>>, 
                                 data::external::sliderpack<1>>;
using global_cable4_t_index = global_cable3_t_index;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable4_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable12_t_index = global_cable11_t_index;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable13_t_index = global_cable10_t_index;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader4_t = event_data_reader3_t<NV>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader4_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader12_t = event_data_reader3_t<NV>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader12_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader13_t = event_data_reader3_t<NV>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader13_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using chain53_t = chain45_t<NV>;

template <int NV> using midi_cc3_t = midi_cc10_t<NV>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, midi_cc3_t<NV>>, 
                                 math::add<NV>>;

template <int NV> using midi_cc5_t = midi_cc10_t<NV>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_cc5_t<NV>>, 
                                  math::add<NV>>;

template <int NV> using midi_cc7_t = midi_cc10_t<NV>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_cc7_t<NV>>, 
                                  math::add<NV>>;

template <int NV> using midi_cc8_t = midi_cc10_t<NV>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_cc8_t<NV>>, 
                                  math::add<NV>>;

template <int NV> using midi1_t = midi6_t<NV>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi1_t<NV>>, 
                                  math::add<NV>>;

template <int NV> using midi3_t = midi7_t<NV>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi3_t<NV>>, 
                                  math::add<NV>>;

template <int NV> using midi5_t = midi8_t<NV>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi5_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain_t<NV>>, 
                                    chain4_t<NV>, 
                                    chain5_t<NV>, 
                                    chain6_t<NV>, 
                                    chain7_t<NV>, 
                                    chain9_t<NV>, 
                                    chain11_t<NV>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch4_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain47_t<NV>>, 
                                  chain48_t<NV>, 
                                  chain49_t<NV>, 
                                  chain50_t<NV>, 
                                  chain51_t<NV>, 
                                  chain52_t<NV>, 
                                  chain53_t<NV>, 
                                  chain54_t<NV>>;

template <int NV> using pma2_mod = sliderbank3_c0<NV>;

template <int NV>
using pma2_t = control::pma<NV, pma2_mod<NV>>;
template <int NV>
using peak4_t = wrap::mod<parameter::plain<pma2_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank4_t<NV>>, 
                                      split4_t<NV>, 
                                      peak4_t<NV>, 
                                      pma2_t<NV>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

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
using global_cable6_t_index = global_cable3_t_index;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain63_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable6_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable16_t_index = global_cable11_t_index;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain64_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable17_t_index = global_cable10_t_index;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain65_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader6_t = event_data_reader3_t<NV>;

template <int NV>
using chain66_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader6_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader16_t = event_data_reader3_t<NV>;

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader16_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader17_t = event_data_reader3_t<NV>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader17_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader18_t = event_data_reader3_t<NV>;

template <int NV>
using chain69_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader18_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc14_t = midi_cc10_t<NV>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc14_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc15_t = midi_cc10_t<NV>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc15_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc16_t = midi_cc10_t<NV>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc16_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc17_t = midi_cc10_t<NV>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc17_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi9_t = midi6_t<NV>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi9_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi10_t = midi7_t<NV>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi10_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi11_t = midi8_t<NV>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi11_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain28_t<NV>>, 
                                    chain29_t<NV>, 
                                    chain30_t<NV>, 
                                    chain31_t<NV>, 
                                    chain32_t<NV>, 
                                    chain33_t<NV>, 
                                    chain34_t<NV>>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch6_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain63_t<NV>>, 
                                  chain64_t<NV>, 
                                  chain65_t<NV>, 
                                  chain66_t<NV>, 
                                  chain67_t<NV>, 
                                  chain68_t<NV>, 
                                  chain69_t<NV>, 
                                  chain70_t<NV>>;

template <int NV>
using peak6_t = wrap::mod<parameter::plain<control::pma<NV, parameter::empty>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain4_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank6_t<NV>>, 
                                      split6_t<NV>, 
                                      peak6_t<NV>, 
                                      control::pma<NV, parameter::empty>>;

template <int NV>
using modchain4_t = wrap::control_rate<modchain4_t_<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, modchain1_t<NV>>, 
                                  modchain2_t<NV>, 
                                  modchain4_t<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, minmax2_t<NV>>, 
                                  converter_t<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, minmax1_t<NV>>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, tempo_sync_t<NV>>, 
                                   converter5_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, chain8_t<NV>>, 
                                 chain10_t<NV>, 
                                 chain12_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::phasor_fm<NV>>>;

template <int NV> using chain3_t = chain1_t<NV>;

template <int NV> using chain2_t = chain1_t<NV>;

template <int NV> using no_midi_t_ = chain1_t<NV>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain1_t<NV>>, 
                                    chain3_t<NV>, 
                                    chain2_t<NV>, 
                                    no_midi_t<NV>>;

using chain14_t = container::chain<parameter::empty, wrap::fix<2, core::fm>>;

using chain15_t = chain14_t;

using chain16_t = chain14_t;

using no_midi1_t_ = chain14_t;

using no_midi1_t = wrap::no_midi<no_midi1_t_>;
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain14_t>, 
                                    chain15_t, 
                                    chain16_t, 
                                    no_midi1_t>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, branch1_t<NV>>, 
                                   branch2_t>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, modchain_t<NV>>, 
                                       branch_t<NV>, 
                                       core::mono2stereo>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

namespace osc1_t_parameters
{
// Parameter list for osc1_impl::osc1_t ------------------------------------------------------------

DECLARE_PARAMETER_RANGE(Pitch_InputRange, 
                        -24., 
                        24.);

template <int NV>
using Pitch = parameter::chain<Pitch_InputRange, 
                               parameter::plain<osc1_impl::pma1_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE(tempo_InputRange, 
                        0., 
                        18.);

template <int NV>
using tempo = parameter::chain<tempo_InputRange, 
                               parameter::plain<osc1_impl::pma8_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(pitchmode_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(pitchmode_0Range, 
                             0., 
                             3., 
                             1.);

template <int NV>
using pitchmode_0 = parameter::from0To1<osc1_impl::branch1_t<NV>, 
                                        0, 
                                        pitchmode_0Range>;

using pitchmode_1 = parameter::from0To1<osc1_impl::branch2_t, 
                                        0, 
                                        pitchmode_0Range>;

template <int NV>
using pitchmode_2 = parameter::from0To1<osc1_impl::branch3_t<NV>, 
                                        0, 
                                        pitchmode_0Range>;

template <int NV>
using pitchmode = parameter::chain<pitchmode_InputRange, 
                                   pitchmode_0<NV>, 
                                   pitchmode_1, 
                                   pitchmode_2<NV>>;

template <int NV>
using step = parameter::chain<ranges::Identity, 
                              parameter::plain<osc1_impl::minmax2_t<NV>, 4>, 
                              parameter::plain<osc1_impl::minmax1_t<NV>, 4>>;

template <int NV>
using PitchMod = parameter::chain<ranges::Identity, 
                                  parameter::plain<osc1_impl::pma1_t<NV>, 1>, 
                                  parameter::plain<osc1_impl::pma9_t<NV>, 1>, 
                                  parameter::plain<osc1_impl::pma8_t<NV>, 1>, 
                                  parameter::plain<osc1_impl::pma11_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE(harm_InputRange, 
                        1., 
                        16.);

template <int NV>
using harm = parameter::chain<harm_InputRange, 
                              parameter::plain<osc1_impl::pma9_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE(XfstagePitch_InputRange, 
                        1., 
                        4.);
DECLARE_PARAMETER_RANGE_STEP(XfstagePitch_0Range, 
                             3., 
                             6., 
                             1.);

template <int NV>
using XfstagePitch_0 = parameter::from0To1<routing::event_data_reader<NV>, 
                                           0, 
                                           XfstagePitch_0Range>;

template <int NV>
using XfstagePitch = parameter::chain<XfstagePitch_InputRange, 
                                      XfstagePitch_0<NV>>;

DECLARE_PARAMETER_RANGE(MidiSlotPitch_InputRange, 
                        1., 
                        7.);
DECLARE_PARAMETER_RANGE_STEP(MidiSlotPitch_0Range, 
                             0., 
                             6., 
                             1.);

template <int NV>
using MidiSlotPitch_0 = parameter::from0To1<osc1_impl::branch5_t<NV>, 
                                            0, 
                                            MidiSlotPitch_0Range>;

template <int NV>
using MidiSlotPitch = parameter::chain<MidiSlotPitch_InputRange, 
                                       MidiSlotPitch_0<NV>>;

DECLARE_PARAMETER_RANGE(XfstageInput_InputRange, 
                        1., 
                        4.);
template <int NV> using XfstageInput_0 = XfstagePitch_0<NV>;

template <int NV>
using XfstageInput = parameter::chain<XfstageInput_InputRange, 
                                      XfstageInput_0<NV>>;

DECLARE_PARAMETER_RANGE(MidiSlotIn_InputRange, 
                        1., 
                        7.);
template <int NV>
using MidiSlotIn_0 = parameter::from0To1<osc1_impl::branch4_t<NV>, 
                                         0, 
                                         MidiSlotPitch_0Range>;

template <int NV>
using MidiSlotIn = parameter::chain<MidiSlotIn_InputRange, MidiSlotIn_0<NV>>;

DECLARE_PARAMETER_RANGE(XfstageOut_InputRange, 
                        1., 
                        4.);
template <int NV>
using XfstageOut_0 = parameter::from0To1<osc1_impl::event_data_reader18_t<NV>, 
                                         0, 
                                         XfstagePitch_0Range>;

template <int NV>
using XfstageOut = parameter::chain<XfstageOut_InputRange, XfstageOut_0<NV>>;

DECLARE_PARAMETER_RANGE(MidiSlotOut_InputRange, 
                        1., 
                        7.);
template <int NV>
using MidiSlotOut_0 = parameter::from0To1<osc1_impl::branch6_t<NV>, 
                                          0, 
                                          MidiSlotPitch_0Range>;

template <int NV>
using MidiSlotOut = parameter::chain<MidiSlotOut_InputRange, MidiSlotOut_0<NV>>;

template <int NV>
using div = parameter::plain<osc1_impl::tempo_sync_t<NV>, 
                             1>;
template <int NV>
using Input = parameter::plain<osc1_impl::pma2_t<NV>, 2>;
template <int NV>
using Shape = parameter::plain<osc1_impl::branch_t<NV>, 
                               0>;
template <int NV>
using InputMod = parameter::plain<osc1_impl::pma2_t<NV>, 1>;
template <int NV>
using OutPut = parameter::plain<control::pma<NV, parameter::empty>, 
                                2>;
template <int NV>
using OutMod = parameter::plain<control::pma<NV, parameter::empty>, 
                                1>;
template <int NV>
using sync = parameter::plain<osc1_impl::tempo_sync_t<NV>, 
                              2>;
template <int NV>
using LfoUnsync = parameter::plain<osc1_impl::minmax_t<NV>, 
                                   0>;
template <int NV>
using osc1_t_plist = parameter::list<Pitch<NV>, 
                                     tempo<NV>, 
                                     div<NV>, 
                                     pitchmode<NV>, 
                                     step<NV>, 
                                     Input<NV>, 
                                     Shape<NV>, 
                                     PitchMod<NV>, 
                                     InputMod<NV>, 
                                     OutPut<NV>, 
                                     OutMod<NV>, 
                                     harm<NV>, 
                                     sync<NV>, 
                                     LfoUnsync<NV>, 
                                     XfstagePitch<NV>, 
                                     MidiSlotPitch<NV>, 
                                     XfstageInput<NV>, 
                                     MidiSlotIn<NV>, 
                                     XfstageOut<NV>, 
                                     MidiSlotOut<NV>>;
}

template <int NV>
using osc1_t_ = container::chain<osc1_t_parameters::osc1_t_plist<NV>, 
                                 wrap::fix<2, split2_t<NV>>, 
                                 core::gain<NV>, 
                                 fix8_block_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public osc1_impl::osc1_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 3;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(osc1);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(336)
		{
			0x005B, 0x0000, 0x5000, 0x7469, 0x6863, 0x0000, 0xC000, 0x00C1, 
            0xC000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x6574, 0x706D, 0x006F, 0x0000, 0x0000, 0x0000, 
            0x4190, 0x4859, 0x410C, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 
            0x0000, 0x6400, 0x7669, 0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0003, 0x0000, 
            0x6970, 0x6374, 0x6D68, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 
            0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x045B, 
            0x0000, 0x7300, 0x6574, 0x0070, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 
            0x4900, 0x706E, 0x7475, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0006, 0x0000, 
            0x6853, 0x7061, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x075B, 0x0000, 0x5000, 
            0x7469, 0x6863, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x085B, 0x0000, 
            0x4900, 0x706E, 0x7475, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x095B, 
            0x0000, 0x4F00, 0x7475, 0x7550, 0x0074, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0xDE9C, 0x3DD8, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0A5B, 
            0x0000, 0x4F00, 0x7475, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0B5B, 
            0x0000, 0x6800, 0x7261, 0x006D, 0x0000, 0x3F80, 0x0000, 0x4180, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0C5B, 0x0000, 
            0x7300, 0x6E79, 0x0063, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0D5B, 0x0000, 0x4C00, 
            0x6F66, 0x6E55, 0x7973, 0x636E, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000E, 
            0x0000, 0x6658, 0x7473, 0x6761, 0x5065, 0x7469, 0x6863, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x000F, 0x0000, 0x694D, 0x6964, 0x6C53, 0x746F, 
            0x6950, 0x6374, 0x0068, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x105B, 0x0000, 0x5800, 
            0x7366, 0x6174, 0x6567, 0x6E49, 0x7570, 0x0074, 0x0000, 0x3F80, 
            0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x115B, 0x0000, 0x4D00, 0x6469, 0x5369, 0x6F6C, 0x4974, 0x006E, 
            0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x125B, 0x0000, 0x5800, 0x7366, 0x6174, 0x6567, 
            0x754F, 0x0074, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x135B, 0x0000, 0x4D00, 0x6469, 
            0x5369, 0x6F6C, 0x4F74, 0x7475, 0x0000, 0x8000, 0x003F, 0xE000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& split2 = this->getT(0);                                                    // osc1_impl::split2_t<NV>
		auto& modchain1 = this->getT(0).getT(0);                                         // osc1_impl::modchain1_t<NV>
		auto& sliderbank3 = this->getT(0).getT(0).getT(0);                               // osc1_impl::sliderbank3_t<NV>
		auto& split3 = this->getT(0).getT(0).getT(1);                                    // osc1_impl::split3_t<NV>
		auto& chain39 = this->getT(0).getT(0).getT(1).getT(0);                           // osc1_impl::chain39_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(1).getT(0).getT(0);             // osc1_impl::global_cable3_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                      // math::add<NV>
		auto& gain13 = this->getT(0).getT(0).getT(1).getT(0).getT(2);                    // core::gain<NV>
		auto& chain41 = this->getT(0).getT(0).getT(1).getT(1);                           // osc1_impl::chain41_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(1).getT(1).getT(0);            // osc1_impl::global_cable11_t<NV>
		auto& add26 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                     // math::add<NV>
		auto& gain15 = this->getT(0).getT(0).getT(1).getT(1).getT(2);                    // core::gain<NV>
		auto& chain40 = this->getT(0).getT(0).getT(1).getT(2);                           // osc1_impl::chain40_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(1).getT(2).getT(0);            // osc1_impl::global_cable10_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                      // math::add<NV>
		auto& gain14 = this->getT(0).getT(0).getT(1).getT(2).getT(2);                    // core::gain<NV>
		auto& chain42 = this->getT(0).getT(0).getT(1).getT(3);                           // osc1_impl::chain42_t<NV>
		auto& event_data_reader3 = this->getT(0).getT(0).getT(1).getT(3).getT(0);        // osc1_impl::event_data_reader3_t<NV>
		auto& add27 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                     // math::add<NV>
		auto& gain16 = this->getT(0).getT(0).getT(1).getT(3).getT(2);                    // core::gain<NV>
		auto& chain44 = this->getT(0).getT(0).getT(1).getT(4);                           // osc1_impl::chain44_t<NV>
		auto& event_data_reader11 = this->getT(0).getT(0).getT(1).getT(4).getT(0);       // osc1_impl::event_data_reader11_t<NV>
		auto& add29 = this->getT(0).getT(0).getT(1).getT(4).getT(1);                     // math::add<NV>
		auto& gain32 = this->getT(0).getT(0).getT(1).getT(4).getT(2);                    // core::gain<NV>
		auto& chain43 = this->getT(0).getT(0).getT(1).getT(5);                           // osc1_impl::chain43_t<NV>
		auto& event_data_reader10 = this->getT(0).getT(0).getT(1).getT(5).getT(0);       // osc1_impl::event_data_reader10_t<NV>
		auto& add28 = this->getT(0).getT(0).getT(1).getT(5).getT(1);                     // math::add<NV>
		auto& gain26 = this->getT(0).getT(0).getT(1).getT(5).getT(2);                    // core::gain<NV>
		auto& chain45 = this->getT(0).getT(0).getT(1).getT(6);                           // osc1_impl::chain45_t<NV>
		auto& event_data_reader14 = this->getT(0).getT(0).getT(1).getT(6).getT(0);       // routing::event_data_reader<NV>
		auto& add30 = this->getT(0).getT(0).getT(1).getT(6).getT(1);                     // math::add<NV>
		auto& gain33 = this->getT(0).getT(0).getT(1).getT(6).getT(2);                    // core::gain<NV>
		auto& chain46 = this->getT(0).getT(0).getT(1).getT(7);                           // osc1_impl::chain46_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(1).getT(7).getT(0);                   // osc1_impl::branch5_t<NV>
		auto& chain13 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(0);           // osc1_impl::chain13_t<NV>
		auto& midi_cc10 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(0).getT(0); // osc1_impl::midi_cc10_t<NV>
		auto& add50 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(0).getT(1);     // math::add<NV>
		auto& chain18 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(1);           // osc1_impl::chain18_t<NV>
		auto& midi_cc11 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(1).getT(0); // osc1_impl::midi_cc11_t<NV>
		auto& add51 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(1).getT(1);     // math::add<NV>
		auto& chain22 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(2);           // osc1_impl::chain22_t<NV>
		auto& midi_cc12 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(2).getT(0); // osc1_impl::midi_cc12_t<NV>
		auto& add52 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(2).getT(1);     // math::add<NV>
		auto& chain24 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(3);           // osc1_impl::chain24_t<NV>
		auto& midi_cc13 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(3).getT(0); // osc1_impl::midi_cc13_t<NV>
		auto& add53 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(3).getT(1);     // math::add<NV>
		auto& chain25 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(4);           // osc1_impl::chain25_t<NV>
		auto& midi6 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(4).getT(0);     // osc1_impl::midi6_t<NV>
		auto& add54 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(4).getT(1);     // math::add<NV>
		auto& chain26 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(5);           // osc1_impl::chain26_t<NV>
		auto& midi7 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(5).getT(0);     // osc1_impl::midi7_t<NV>
		auto& add55 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(5).getT(1);     // math::add<NV>
		auto& chain27 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(6);           // osc1_impl::chain27_t<NV>
		auto& midi8 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(6).getT(0);     // osc1_impl::midi8_t<NV>
		auto& add56 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(6).getT(1);     // math::add<NV>
		auto& gain34 = this->getT(0).getT(0).getT(1).getT(7).getT(1);                    // core::gain<NV>
		auto& peak3 = this->getT(0).getT(0).getT(2);                                     // osc1_impl::peak3_t<NV>
		auto& clear = this->getT(0).getT(0).getT(3);                                     // math::clear<NV>
		auto& chain20 = this->getT(0).getT(0).getT(4);                                   // osc1_impl::chain20_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(4).getT(0);                           // osc1_impl::branch3_t<NV>
		auto& chain17 = this->getT(0).getT(0).getT(4).getT(0).getT(0);                   // osc1_impl::chain17_t<NV>
		auto& pma1 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(0);              // osc1_impl::pma1_t<NV>
		auto& add = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(1);               // math::add<NV>
		auto& chain19 = this->getT(0).getT(0).getT(4).getT(0).getT(1);                   // osc1_impl::chain19_t<NV>
		auto& pma9 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(0);              // osc1_impl::pma9_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(1);              // math::add<NV>
		auto& chain21 = this->getT(0).getT(0).getT(4).getT(0).getT(2);                   // osc1_impl::chain21_t<NV>
		auto& pma8 = this->getT(0).getT(0).getT(4).getT(0).getT(2).getT(0);              // osc1_impl::pma8_t<NV>
		auto& chain23 = this->getT(0).getT(0).getT(4).getT(0).getT(3);                   // osc1_impl::chain23_t<NV>
		auto& minmax = this->getT(0).getT(0).getT(4).getT(0).getT(3).getT(0);            // osc1_impl::minmax_t<NV>
		auto& pma11 = this->getT(0).getT(0).getT(4).getT(0).getT(3).getT(1);             // osc1_impl::pma11_t<NV>
		auto& peak = this->getT(0).getT(0).getT(4).getT(1);                              // osc1_impl::peak_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(5);                                    // osc1_impl::split7_t
		auto& modchain2 = this->getT(0).getT(1);                                         // osc1_impl::modchain2_t<NV>
		auto& sliderbank4 = this->getT(0).getT(1).getT(0);                               // osc1_impl::sliderbank4_t<NV>
		auto& split4 = this->getT(0).getT(1).getT(1);                                    // osc1_impl::split4_t<NV>
		auto& chain47 = this->getT(0).getT(1).getT(1).getT(0);                           // osc1_impl::chain47_t<NV>
		auto& global_cable4 = this->getT(0).getT(1).getT(1).getT(0).getT(0);             // osc1_impl::global_cable4_t<NV>
		auto& add6 = this->getT(0).getT(1).getT(1).getT(0).getT(1);                      // math::add<NV>
		auto& gain17 = this->getT(0).getT(1).getT(1).getT(0).getT(2);                    // core::gain<NV>
		auto& chain48 = this->getT(0).getT(1).getT(1).getT(1);                           // osc1_impl::chain48_t<NV>
		auto& global_cable12 = this->getT(0).getT(1).getT(1).getT(1).getT(0);            // osc1_impl::global_cable12_t<NV>
		auto& add32 = this->getT(0).getT(1).getT(1).getT(1).getT(1);                     // math::add<NV>
		auto& gain18 = this->getT(0).getT(1).getT(1).getT(1).getT(2);                    // core::gain<NV>
		auto& chain49 = this->getT(0).getT(1).getT(1).getT(2);                           // osc1_impl::chain49_t<NV>
		auto& global_cable13 = this->getT(0).getT(1).getT(1).getT(2).getT(0);            // osc1_impl::global_cable13_t<NV>
		auto& add7 = this->getT(0).getT(1).getT(1).getT(2).getT(1);                      // math::add<NV>
		auto& gain19 = this->getT(0).getT(1).getT(1).getT(2).getT(2);                    // core::gain<NV>
		auto& chain50 = this->getT(0).getT(1).getT(1).getT(3);                           // osc1_impl::chain50_t<NV>
		auto& event_data_reader4 = this->getT(0).getT(1).getT(1).getT(3).getT(0);        // osc1_impl::event_data_reader4_t<NV>
		auto& add33 = this->getT(0).getT(1).getT(1).getT(3).getT(1);                     // math::add<NV>
		auto& gain20 = this->getT(0).getT(1).getT(1).getT(3).getT(2);                    // core::gain<NV>
		auto& chain51 = this->getT(0).getT(1).getT(1).getT(4);                           // osc1_impl::chain51_t<NV>
		auto& event_data_reader12 = this->getT(0).getT(1).getT(1).getT(4).getT(0);       // osc1_impl::event_data_reader12_t<NV>
		auto& add34 = this->getT(0).getT(1).getT(1).getT(4).getT(1);                     // math::add<NV>
		auto& gain35 = this->getT(0).getT(1).getT(1).getT(4).getT(2);                    // core::gain<NV>
		auto& chain52 = this->getT(0).getT(1).getT(1).getT(5);                           // osc1_impl::chain52_t<NV>
		auto& event_data_reader13 = this->getT(0).getT(1).getT(1).getT(5).getT(0);       // osc1_impl::event_data_reader13_t<NV>
		auto& add35 = this->getT(0).getT(1).getT(1).getT(5).getT(1);                     // math::add<NV>
		auto& gain27 = this->getT(0).getT(1).getT(1).getT(5).getT(2);                    // core::gain<NV>
		auto& chain53 = this->getT(0).getT(1).getT(1).getT(6);                           // osc1_impl::chain53_t<NV>
		auto& event_data_reader15 = this->getT(0).getT(1).getT(1).getT(6).getT(0);       // routing::event_data_reader<NV>
		auto& add36 = this->getT(0).getT(1).getT(1).getT(6).getT(1);                     // math::add<NV>
		auto& gain36 = this->getT(0).getT(1).getT(1).getT(6).getT(2);                    // core::gain<NV>
		auto& chain54 = this->getT(0).getT(1).getT(1).getT(7);                           // osc1_impl::chain54_t<NV>
		auto& branch4 = this->getT(0).getT(1).getT(1).getT(7).getT(0);                   // osc1_impl::branch4_t<NV>
		auto& chain = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(0);             // osc1_impl::chain_t<NV>
		auto& midi_cc3 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(0).getT(0);  // osc1_impl::midi_cc3_t<NV>
		auto& add31 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(0).getT(1);     // math::add<NV>
		auto& chain4 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(1);            // osc1_impl::chain4_t<NV>
		auto& midi_cc5 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(1).getT(0);  // osc1_impl::midi_cc5_t<NV>
		auto& add38 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(1).getT(1);     // math::add<NV>
		auto& chain5 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(2);            // osc1_impl::chain5_t<NV>
		auto& midi_cc7 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(2).getT(0);  // osc1_impl::midi_cc7_t<NV>
		auto& add39 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(2).getT(1);     // math::add<NV>
		auto& chain6 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(3);            // osc1_impl::chain6_t<NV>
		auto& midi_cc8 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(3).getT(0);  // osc1_impl::midi_cc8_t<NV>
		auto& add40 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(3).getT(1);     // math::add<NV>
		auto& chain7 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(4);            // osc1_impl::chain7_t<NV>
		auto& midi1 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(4).getT(0);     // osc1_impl::midi1_t<NV>
		auto& add41 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(4).getT(1);     // math::add<NV>
		auto& chain9 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(5);            // osc1_impl::chain9_t<NV>
		auto& midi3 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(5).getT(0);     // osc1_impl::midi3_t<NV>
		auto& add42 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(5).getT(1);     // math::add<NV>
		auto& chain11 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(6);           // osc1_impl::chain11_t<NV>
		auto& midi5 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(6).getT(0);     // osc1_impl::midi5_t<NV>
		auto& add43 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(6).getT(1);     // math::add<NV>
		auto& gain37 = this->getT(0).getT(1).getT(1).getT(7).getT(1);                    // core::gain<NV>
		auto& peak4 = this->getT(0).getT(1).getT(2);                                     // osc1_impl::peak4_t<NV>
		auto& pma2 = this->getT(0).getT(1).getT(3);                                      // osc1_impl::pma2_t<NV>
		auto& modchain4 = this->getT(0).getT(2);                                         // osc1_impl::modchain4_t<NV>
		auto& sliderbank6 = this->getT(0).getT(2).getT(0);                               // osc1_impl::sliderbank6_t<NV>
		auto& split6 = this->getT(0).getT(2).getT(1);                                    // osc1_impl::split6_t<NV>
		auto& chain63 = this->getT(0).getT(2).getT(1).getT(0);                           // osc1_impl::chain63_t<NV>
		auto& global_cable6 = this->getT(0).getT(2).getT(1).getT(0).getT(0);             // osc1_impl::global_cable6_t<NV>
		auto& add10 = this->getT(0).getT(2).getT(1).getT(0).getT(1);                     // math::add<NV>
		auto& gain25 = this->getT(0).getT(2).getT(1).getT(0).getT(2);                    // core::gain<NV>
		auto& chain64 = this->getT(0).getT(2).getT(1).getT(1);                           // osc1_impl::chain64_t<NV>
		auto& global_cable16 = this->getT(0).getT(2).getT(1).getT(1).getT(0);            // osc1_impl::global_cable16_t<NV>
		auto& add44 = this->getT(0).getT(2).getT(1).getT(1).getT(1);                     // math::add<NV>
		auto& gain29 = this->getT(0).getT(2).getT(1).getT(1).getT(2);                    // core::gain<NV>
		auto& chain65 = this->getT(0).getT(2).getT(1).getT(2);                           // osc1_impl::chain65_t<NV>
		auto& global_cable17 = this->getT(0).getT(2).getT(1).getT(2).getT(0);            // osc1_impl::global_cable17_t<NV>
		auto& add11 = this->getT(0).getT(2).getT(1).getT(2).getT(1);                     // math::add<NV>
		auto& gain30 = this->getT(0).getT(2).getT(1).getT(2).getT(2);                    // core::gain<NV>
		auto& chain66 = this->getT(0).getT(2).getT(1).getT(3);                           // osc1_impl::chain66_t<NV>
		auto& event_data_reader6 = this->getT(0).getT(2).getT(1).getT(3).getT(0);        // osc1_impl::event_data_reader6_t<NV>
		auto& add45 = this->getT(0).getT(2).getT(1).getT(3).getT(1);                     // math::add<NV>
		auto& gain31 = this->getT(0).getT(2).getT(1).getT(3).getT(2);                    // core::gain<NV>
		auto& chain67 = this->getT(0).getT(2).getT(1).getT(4);                           // osc1_impl::chain67_t<NV>
		auto& event_data_reader16 = this->getT(0).getT(2).getT(1).getT(4).getT(0);       // osc1_impl::event_data_reader16_t<NV>
		auto& add46 = this->getT(0).getT(2).getT(1).getT(4).getT(1);                     // math::add<NV>
		auto& gain41 = this->getT(0).getT(2).getT(1).getT(4).getT(2);                    // core::gain<NV>
		auto& chain68 = this->getT(0).getT(2).getT(1).getT(5);                           // osc1_impl::chain68_t<NV>
		auto& event_data_reader17 = this->getT(0).getT(2).getT(1).getT(5).getT(0);       // osc1_impl::event_data_reader17_t<NV>
		auto& add47 = this->getT(0).getT(2).getT(1).getT(5).getT(1);                     // math::add<NV>
		auto& gain42 = this->getT(0).getT(2).getT(1).getT(5).getT(2);                    // core::gain<NV>
		auto& chain69 = this->getT(0).getT(2).getT(1).getT(6);                           // osc1_impl::chain69_t<NV>
		auto& event_data_reader18 = this->getT(0).getT(2).getT(1).getT(6).getT(0);       // osc1_impl::event_data_reader18_t<NV>
		auto& add48 = this->getT(0).getT(2).getT(1).getT(6).getT(1);                     // math::add<NV>
		auto& gain43 = this->getT(0).getT(2).getT(1).getT(6).getT(2);                    // core::gain<NV>
		auto& chain70 = this->getT(0).getT(2).getT(1).getT(7);                           // osc1_impl::chain70_t<NV>
		auto& branch6 = this->getT(0).getT(2).getT(1).getT(7).getT(0);                   // osc1_impl::branch6_t<NV>
		auto& chain28 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(0);           // osc1_impl::chain28_t<NV>
		auto& midi_cc14 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(0).getT(0); // osc1_impl::midi_cc14_t<NV>
		auto& add57 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(0).getT(1);     // math::add<NV>
		auto& chain29 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(1);           // osc1_impl::chain29_t<NV>
		auto& midi_cc15 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(1).getT(0); // osc1_impl::midi_cc15_t<NV>
		auto& add58 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(1).getT(1);     // math::add<NV>
		auto& chain30 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(2);           // osc1_impl::chain30_t<NV>
		auto& midi_cc16 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(2).getT(0); // osc1_impl::midi_cc16_t<NV>
		auto& add59 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(2).getT(1);     // math::add<NV>
		auto& chain31 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(3);           // osc1_impl::chain31_t<NV>
		auto& midi_cc17 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(3).getT(0); // osc1_impl::midi_cc17_t<NV>
		auto& add60 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(3).getT(1);     // math::add<NV>
		auto& chain32 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(4);           // osc1_impl::chain32_t<NV>
		auto& midi9 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(4).getT(0);     // osc1_impl::midi9_t<NV>
		auto& add61 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(4).getT(1);     // math::add<NV>
		auto& chain33 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(5);           // osc1_impl::chain33_t<NV>
		auto& midi10 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(5).getT(0);    // osc1_impl::midi10_t<NV>
		auto& add62 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(5).getT(1);     // math::add<NV>
		auto& chain34 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(6);           // osc1_impl::chain34_t<NV>
		auto& midi11 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(6).getT(0);    // osc1_impl::midi11_t<NV>
		auto& add63 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(6).getT(1);     // math::add<NV>
		auto& gain44 = this->getT(0).getT(2).getT(1).getT(7).getT(1);                    // core::gain<NV>
		auto& peak6 = this->getT(0).getT(2).getT(2);                                     // osc1_impl::peak6_t<NV>
		auto& pma4 = this->getT(0).getT(2).getT(3);                                      // control::pma<NV, parameter::empty>
		auto& gain = this->getT(1);                                                      // core::gain<NV>
		auto& fix8_block = this->getT(2);                                                // osc1_impl::fix8_block_t<NV>
		auto& modchain = this->getT(2).getT(0);                                          // osc1_impl::modchain_t<NV>
		auto& split = this->getT(2).getT(0).getT(0);                                     // osc1_impl::split_t<NV>
		auto& chain8 = this->getT(2).getT(0).getT(0).getT(0);                            // osc1_impl::chain8_t<NV>
		auto& minmax2 = this->getT(2).getT(0).getT(0).getT(0).getT(0);                   // osc1_impl::minmax2_t<NV>
		auto& converter = this->getT(2).getT(0).getT(0).getT(0).getT(1);                 // osc1_impl::converter_t<NV>
		auto& chain10 = this->getT(2).getT(0).getT(0).getT(1);                           // osc1_impl::chain10_t<NV>
		auto& minmax1 = this->getT(2).getT(0).getT(0).getT(1).getT(0);                   // osc1_impl::minmax1_t<NV>
		auto& chain12 = this->getT(2).getT(0).getT(0).getT(2);                           // osc1_impl::chain12_t<NV>
		auto& tempo_sync = this->getT(2).getT(0).getT(0).getT(2).getT(0);                // osc1_impl::tempo_sync_t<NV>
		auto& converter5 = this->getT(2).getT(0).getT(0).getT(2).getT(1);                // osc1_impl::converter5_t<NV>
		auto& branch = this->getT(2).getT(1);                                            // osc1_impl::branch_t<NV>
		auto& branch1 = this->getT(2).getT(1).getT(0);                                   // osc1_impl::branch1_t<NV>
		auto& chain1 = this->getT(2).getT(1).getT(0).getT(0);                            // osc1_impl::chain1_t<NV>
		auto& phasor_fm = this->getT(2).getT(1).getT(0).getT(0).getT(0);                 // core::phasor_fm<NV>
		auto& chain3 = this->getT(2).getT(1).getT(0).getT(1);                            // osc1_impl::chain3_t<NV>
		auto& phasor_fm4 = this->getT(2).getT(1).getT(0).getT(1).getT(0);                // core::phasor_fm<NV>
		auto& chain2 = this->getT(2).getT(1).getT(0).getT(2);                            // osc1_impl::chain2_t<NV>
		auto& phasor_fm3 = this->getT(2).getT(1).getT(0).getT(2).getT(0);                // core::phasor_fm<NV>
		auto& no_midi = this->getT(2).getT(1).getT(0).getT(3);                           // osc1_impl::no_midi_t<NV>
		auto& phasor_fm1 = this->getT(2).getT(1).getT(0).getT(3).getT(0);                // core::phasor_fm<NV>
		auto& branch2 = this->getT(2).getT(1).getT(1);                                   // osc1_impl::branch2_t
		auto& chain14 = this->getT(2).getT(1).getT(1).getT(0);                           // osc1_impl::chain14_t
		auto& fm = this->getT(2).getT(1).getT(1).getT(0).getT(0);                        // core::fm
		auto& chain15 = this->getT(2).getT(1).getT(1).getT(1);                           // osc1_impl::chain15_t
		auto& fm3 = this->getT(2).getT(1).getT(1).getT(1).getT(0);                       // core::fm
		auto& chain16 = this->getT(2).getT(1).getT(1).getT(2);                           // osc1_impl::chain16_t
		auto& fm2 = this->getT(2).getT(1).getT(1).getT(2).getT(0);                       // core::fm
		auto& no_midi1 = this->getT(2).getT(1).getT(1).getT(3);                          // osc1_impl::no_midi1_t
		auto& fm1 = this->getT(2).getT(1).getT(1).getT(3).getT(0);                       // core::fm
		auto& mono2stereo = this->getT(2).getT(2);                                       // core::mono2stereo
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma1); // Pitch -> pma1::Add
		
		this->getParameterT(1).connectT(0, pma8); // tempo -> pma8::Add
		
		this->getParameterT(2).connectT(0, tempo_sync); // div -> tempo_sync::Multiplier
		
		auto& pitchmode_p = this->getParameterT(3);
		pitchmode_p.connectT(0, branch1); // pitchmode -> branch1::Index
		pitchmode_p.connectT(1, branch2); // pitchmode -> branch2::Index
		pitchmode_p.connectT(2, branch3); // pitchmode -> branch3::Index
		
		auto& step_p = this->getParameterT(4);
		step_p.connectT(0, minmax2); // step -> minmax2::Step
		step_p.connectT(1, minmax1); // step -> minmax1::Step
		
		this->getParameterT(5).connectT(0, pma2); // Input -> pma2::Add
		
		this->getParameterT(6).connectT(0, branch); // Shape -> branch::Index
		
		auto& PitchMod_p = this->getParameterT(7);
		PitchMod_p.connectT(0, pma1);  // PitchMod -> pma1::Multiply
		PitchMod_p.connectT(1, pma9);  // PitchMod -> pma9::Multiply
		PitchMod_p.connectT(2, pma8);  // PitchMod -> pma8::Multiply
		PitchMod_p.connectT(3, pma11); // PitchMod -> pma11::Multiply
		
		this->getParameterT(8).connectT(0, pma2); // InputMod -> pma2::Multiply
		
		this->getParameterT(9).connectT(0, pma4); // OutPut -> pma4::Add
		
		this->getParameterT(10).connectT(0, pma4); // OutMod -> pma4::Multiply
		
		this->getParameterT(11).connectT(0, pma9); // harm -> pma9::Add
		
		this->getParameterT(12).connectT(0, tempo_sync); // sync -> tempo_sync::Enabled
		
		this->getParameterT(13).connectT(0, minmax); // LfoUnsync -> minmax::Value
		
		this->getParameterT(14).connectT(0, event_data_reader14); // XfstagePitch -> event_data_reader14::SlotIndex
		
		this->getParameterT(15).connectT(0, branch5); // MidiSlotPitch -> branch5::Index
		
		this->getParameterT(16).connectT(0, event_data_reader15); // XfstageInput -> event_data_reader15::SlotIndex
		
		this->getParameterT(17).connectT(0, branch4); // MidiSlotIn -> branch4::Index
		
		this->getParameterT(18).connectT(0, event_data_reader18); // XfstageOut -> event_data_reader18::SlotIndex
		
		this->getParameterT(19).connectT(0, branch6); // MidiSlotOut -> branch6::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& sliderbank3_p = sliderbank3.getWrappedObject().getParameter();
		sliderbank3_p.getParameterT(0).connectT(0, gain13);                   // sliderbank3 -> gain13::Gain
		sliderbank3_p.getParameterT(1).connectT(0, gain15);                   // sliderbank3 -> gain15::Gain
		sliderbank3_p.getParameterT(2).connectT(0, gain14);                   // sliderbank3 -> gain14::Gain
		sliderbank3_p.getParameterT(3).connectT(0, gain16);                   // sliderbank3 -> gain16::Gain
		sliderbank3_p.getParameterT(4).connectT(0, gain32);                   // sliderbank3 -> gain32::Gain
		sliderbank3_p.getParameterT(5).connectT(0, gain26);                   // sliderbank3 -> gain26::Gain
		sliderbank3_p.getParameterT(6).connectT(0, gain33);                   // sliderbank3 -> gain33::Gain
		sliderbank3_p.getParameterT(7).connectT(0, gain34);                   // sliderbank3 -> gain34::Gain
		global_cable3.getWrappedObject().getParameter().connectT(0, add4);    // global_cable3 -> add4::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add26);  // global_cable11 -> add26::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, add5);   // global_cable10 -> add5::Value
		event_data_reader3.getParameter().connectT(0, add27);                 // event_data_reader3 -> add27::Value
		event_data_reader11.getParameter().connectT(0, add29);                // event_data_reader11 -> add29::Value
		event_data_reader10.getParameter().connectT(0, add28);                // event_data_reader10 -> add28::Value
		midi_cc10.getWrappedObject().getParameter().connectT(0, add50);       // midi_cc10 -> add50::Value
		midi_cc11.getWrappedObject().getParameter().connectT(0, add51);       // midi_cc11 -> add51::Value
		midi_cc12.getWrappedObject().getParameter().connectT(0, add52);       // midi_cc12 -> add52::Value
		midi_cc13.getWrappedObject().getParameter().connectT(0, add53);       // midi_cc13 -> add53::Value
		midi6.getParameter().connectT(0, add54);                              // midi6 -> add54::Value
		midi7.getParameter().connectT(0, add55);                              // midi7 -> add55::Value
		midi8.getParameter().connectT(0, add56);                              // midi8 -> add56::Value
		pma1.getWrappedObject().getParameter().connectT(0, add);              // pma1 -> add::Value
		pma9.getWrappedObject().getParameter().connectT(0, add2);             // pma9 -> add2::Value
		converter5.getWrappedObject().getParameter().connectT(0, phasor_fm3); // converter5 -> phasor_fm3::FreqRatio
		converter5.getWrappedObject().getParameter().connectT(1, fm2);        // converter5 -> fm2::FreqMultiplier
		converter5.getWrappedObject().getParameter().connectT(2, phasor_fm1); // converter5 -> phasor_fm1::FreqRatio
		converter5.getWrappedObject().getParameter().connectT(3, fm1);        // converter5 -> fm1::FreqMultiplier
		tempo_sync.getParameter().connectT(0, converter5);                    // tempo_sync -> converter5::Value
		pma8.getWrappedObject().getParameter().connectT(0, tempo_sync);       // pma8 -> tempo_sync::Tempo
		pma11.getWrappedObject().getParameter().connectT(0, tempo_sync);      // pma11 -> tempo_sync::UnsyncedTime
		peak3.getParameter().connectT(0, pma1);                               // peak3 -> pma1::Value
		peak3.getParameter().connectT(1, pma9);                               // peak3 -> pma9::Value
		peak3.getParameter().connectT(2, pma8);                               // peak3 -> pma8::Value
		peak3.getParameter().connectT(3, pma11);                              // peak3 -> pma11::Value
		minmax.getWrappedObject().getParameter().connectT(0, pma11);          // minmax -> pma11::Add
		converter.getWrappedObject().getParameter().connectT(0, phasor_fm);   // converter -> phasor_fm::FreqRatio
		converter.getWrappedObject().getParameter().connectT(1, fm);          // converter -> fm::FreqMultiplier
		minmax2.getWrappedObject().getParameter().connectT(0, converter);     // minmax2 -> converter::Value
		minmax1.getWrappedObject().getParameter().connectT(0, phasor_fm4);    // minmax1 -> phasor_fm4::FreqRatio
		minmax1.getWrappedObject().getParameter().connectT(1, fm3);           // minmax1 -> fm3::FreqMultiplier
		peak.getParameter().connectT(0, minmax2);                             // peak -> minmax2::Value
		peak.getParameter().connectT(1, minmax1);                             // peak -> minmax1::Value
		auto& sliderbank4_p = sliderbank4.getWrappedObject().getParameter();
		sliderbank4_p.getParameterT(0).connectT(0, gain17);                  // sliderbank4 -> gain17::Gain
		sliderbank4_p.getParameterT(1).connectT(0, gain18);                  // sliderbank4 -> gain18::Gain
		sliderbank4_p.getParameterT(2).connectT(0, gain19);                  // sliderbank4 -> gain19::Gain
		sliderbank4_p.getParameterT(3).connectT(0, gain20);                  // sliderbank4 -> gain20::Gain
		sliderbank4_p.getParameterT(4).connectT(0, gain35);                  // sliderbank4 -> gain35::Gain
		sliderbank4_p.getParameterT(5).connectT(0, gain27);                  // sliderbank4 -> gain27::Gain
		sliderbank4_p.getParameterT(6).connectT(0, gain36);                  // sliderbank4 -> gain36::Gain
		sliderbank4_p.getParameterT(7).connectT(0, gain37);                  // sliderbank4 -> gain37::Gain
		global_cable4.getWrappedObject().getParameter().connectT(0, add6);   // global_cable4 -> add6::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add32); // global_cable12 -> add32::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add7);  // global_cable13 -> add7::Value
		event_data_reader4.getParameter().connectT(0, add33);                // event_data_reader4 -> add33::Value
		event_data_reader12.getParameter().connectT(0, add34);               // event_data_reader12 -> add34::Value
		event_data_reader13.getParameter().connectT(0, add35);               // event_data_reader13 -> add35::Value
		midi_cc3.getWrappedObject().getParameter().connectT(0, add31);       // midi_cc3 -> add31::Value
		midi_cc5.getWrappedObject().getParameter().connectT(0, add38);       // midi_cc5 -> add38::Value
		midi_cc7.getWrappedObject().getParameter().connectT(0, add39);       // midi_cc7 -> add39::Value
		midi_cc8.getWrappedObject().getParameter().connectT(0, add40);       // midi_cc8 -> add40::Value
		midi1.getParameter().connectT(0, add41);                             // midi1 -> add41::Value
		midi3.getParameter().connectT(0, add42);                             // midi3 -> add42::Value
		midi5.getParameter().connectT(0, add43);                             // midi5 -> add43::Value
		pma2.getWrappedObject().getParameter().connectT(0, gain);            // pma2 -> gain::Gain
		peak4.getParameter().connectT(0, pma2);                              // peak4 -> pma2::Value
		auto& sliderbank6_p = sliderbank6.getWrappedObject().getParameter();
		sliderbank6_p.getParameterT(0).connectT(0, gain25);                  // sliderbank6 -> gain25::Gain
		sliderbank6_p.getParameterT(1).connectT(0, gain29);                  // sliderbank6 -> gain29::Gain
		sliderbank6_p.getParameterT(2).connectT(0, gain30);                  // sliderbank6 -> gain30::Gain
		sliderbank6_p.getParameterT(3).connectT(0, gain31);                  // sliderbank6 -> gain31::Gain
		sliderbank6_p.getParameterT(4).connectT(0, gain41);                  // sliderbank6 -> gain41::Gain
		sliderbank6_p.getParameterT(5).connectT(0, gain42);                  // sliderbank6 -> gain42::Gain
		sliderbank6_p.getParameterT(6).connectT(0, gain43);                  // sliderbank6 -> gain43::Gain
		sliderbank6_p.getParameterT(7).connectT(0, gain44);                  // sliderbank6 -> gain44::Gain
		global_cable6.getWrappedObject().getParameter().connectT(0, add10);  // global_cable6 -> add10::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add44); // global_cable16 -> add44::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add11); // global_cable17 -> add11::Value
		event_data_reader6.getParameter().connectT(0, add45);                // event_data_reader6 -> add45::Value
		event_data_reader16.getParameter().connectT(0, add46);               // event_data_reader16 -> add46::Value
		event_data_reader17.getParameter().connectT(0, add47);               // event_data_reader17 -> add47::Value
		event_data_reader18.getParameter().connectT(0, add48);               // event_data_reader18 -> add48::Value
		midi_cc14.getWrappedObject().getParameter().connectT(0, add57);      // midi_cc14 -> add57::Value
		midi_cc15.getWrappedObject().getParameter().connectT(0, add58);      // midi_cc15 -> add58::Value
		midi_cc16.getWrappedObject().getParameter().connectT(0, add59);      // midi_cc16 -> add59::Value
		midi_cc17.getWrappedObject().getParameter().connectT(0, add60);      // midi_cc17 -> add60::Value
		midi9.getParameter().connectT(0, add61);                             // midi9 -> add61::Value
		midi10.getParameter().connectT(0, add62);                            // midi10 -> add62::Value
		midi11.getParameter().connectT(0, add63);                            // midi11 -> add63::Value
		peak6.getParameter().connectT(0, pma4);                              // peak6 -> pma4::Value
		
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
		
		;                                         // event_data_reader14::SlotIndex is automated
		event_data_reader14.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		add30.setParameterT(0, 0.); // math::add::Value
		
		;                             // gain33::Gain is automated
		gain33.setParameterT(1, 20.); // core::gain::Smoothing
		gain33.setParameterT(2, 0.);  // core::gain::ResetValue
		
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
		
		;                             // gain34::Gain is automated
		gain34.setParameterT(1, 20.); // core::gain::Smoothing
		gain34.setParameterT(2, 0.);  // core::gain::ResetValue
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // branch3::Index is automated
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		; // add::Value is automated
		
		; // pma9::Value is automated
		; // pma9::Multiply is automated
		; // pma9::Add is automated
		
		; // add2::Value is automated
		
		; // pma8::Value is automated
		; // pma8::Multiply is automated
		; // pma8::Add is automated
		
		;                            // minmax::Value is automated
		minmax.setParameterT(1, 0.); // control::minmax::Minimum
		minmax.setParameterT(2, 1.); // control::minmax::Maximum
		minmax.setParameterT(3, 1.); // control::minmax::Skew
		minmax.setParameterT(4, 0.); // control::minmax::Step
		minmax.setParameterT(5, 1.); // control::minmax::Polarity
		
		; // pma11::Value is automated
		; // pma11::Multiply is automated
		; // pma11::Add is automated
		
		sliderbank4.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add6::Value is automated
		
		;                             // gain17::Gain is automated
		gain17.setParameterT(1, 20.); // core::gain::Smoothing
		gain17.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add32::Value is automated
		
		;                             // gain18::Gain is automated
		gain18.setParameterT(1, 20.); // core::gain::Smoothing
		gain18.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add7::Value is automated
		
		;                             // gain19::Gain is automated
		gain19.setParameterT(1, 20.); // core::gain::Smoothing
		gain19.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader4.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader4.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add33::Value is automated
		
		;                             // gain20::Gain is automated
		gain20.setParameterT(1, 20.); // core::gain::Smoothing
		gain20.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader12.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader12.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add34::Value is automated
		
		;                             // gain35::Gain is automated
		gain35.setParameterT(1, 20.); // core::gain::Smoothing
		gain35.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader13.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader13.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add35::Value is automated
		
		;                             // gain27::Gain is automated
		gain27.setParameterT(1, 20.); // core::gain::Smoothing
		gain27.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader15::SlotIndex is automated
		event_data_reader15.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		add36.setParameterT(0, 0.); // math::add::Value
		
		;                             // gain36::Gain is automated
		gain36.setParameterT(1, 20.); // core::gain::Smoothing
		gain36.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch4::Index is automated
		
		midi_cc3.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc3.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc3.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add31::Value is automated
		
		midi_cc5.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc5.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc5.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add38::Value is automated
		
		midi_cc7.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc7.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc7.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add39::Value is automated
		
		midi_cc8.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc8.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc8.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add40::Value is automated
		
		; // add41::Value is automated
		
		; // add42::Value is automated
		
		; // add43::Value is automated
		
		;                             // gain37::Gain is automated
		gain37.setParameterT(1, 20.); // core::gain::Smoothing
		gain37.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma2::Value is automated
		; // pma2::Multiply is automated
		; // pma2::Add is automated
		
		sliderbank6.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		;                             // gain25::Gain is automated
		gain25.setParameterT(1, 20.); // core::gain::Smoothing
		gain25.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add44::Value is automated
		
		;                             // gain29::Gain is automated
		gain29.setParameterT(1, 20.); // core::gain::Smoothing
		gain29.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add11::Value is automated
		
		;                             // gain30::Gain is automated
		gain30.setParameterT(1, 20.); // core::gain::Smoothing
		gain30.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader6.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader6.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add45::Value is automated
		
		;                             // gain31::Gain is automated
		gain31.setParameterT(1, 20.); // core::gain::Smoothing
		gain31.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader16.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader16.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add46::Value is automated
		
		;                             // gain41::Gain is automated
		gain41.setParameterT(1, 20.); // core::gain::Smoothing
		gain41.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader17.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader17.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add47::Value is automated
		
		;                             // gain42::Gain is automated
		gain42.setParameterT(1, 20.); // core::gain::Smoothing
		gain42.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader18::SlotIndex is automated
		event_data_reader18.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add48::Value is automated
		
		;                             // gain43::Gain is automated
		gain43.setParameterT(1, 20.); // core::gain::Smoothing
		gain43.setParameterT(2, 0.);  // core::gain::ResetValue
		
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
		
		;                             // gain44::Gain is automated
		gain44.setParameterT(1, 20.); // core::gain::Smoothing
		gain44.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma4::Value is automated
		; // pma4::Multiply is automated
		; // pma4::Add is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                               // minmax2::Value is automated
		minmax2.setParameterT(1, -24.); // control::minmax::Minimum
		minmax2.setParameterT(2, 24.);  // control::minmax::Maximum
		minmax2.setParameterT(3, 1.);   // control::minmax::Skew
		;                               // minmax2::Step is automated
		minmax2.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // converter::Value is automated
		
		;                              // minmax1::Value is automated
		minmax1.setParameterT(1, 1.);  // control::minmax::Minimum
		minmax1.setParameterT(2, 16.); // control::minmax::Maximum
		minmax1.setParameterT(3, 1.);  // control::minmax::Skew
		;                              // minmax1::Step is automated
		minmax1.setParameterT(5, 0.);  // control::minmax::Polarity
		
		; // tempo_sync::Tempo is automated
		; // tempo_sync::Multiplier is automated
		; // tempo_sync::Enabled is automated
		; // tempo_sync::UnsyncedTime is automated
		
		; // converter5::Value is automated
		
		; // branch::Index is automated
		
		; // branch1::Index is automated
		
		phasor_fm.setParameterT(0, 1.);   // core::phasor_fm::Gate
		phasor_fm.setParameterT(1, 110.); // core::phasor_fm::Frequency
		;                                 // phasor_fm::FreqRatio is automated
		phasor_fm.setParameterT(3, 0.);   // core::phasor_fm::Phase
		
		phasor_fm4.setParameterT(0, 1.);    // core::phasor_fm::Gate
		phasor_fm4.setParameterT(1, 167.6); // core::phasor_fm::Frequency
		;                                   // phasor_fm4::FreqRatio is automated
		phasor_fm4.setParameterT(3, 0.);    // core::phasor_fm::Phase
		
		phasor_fm3.setParameterT(0, 1.);   // core::phasor_fm::Gate
		phasor_fm3.setParameterT(1, 110.); // core::phasor_fm::Frequency
		;                                  // phasor_fm3::FreqRatio is automated
		phasor_fm3.setParameterT(3, 0.);   // core::phasor_fm::Phase
		
		phasor_fm1.setParameterT(0, 1.); // core::phasor_fm::Gate
		phasor_fm1.setParameterT(1, 0.); // core::phasor_fm::Frequency
		;                                // phasor_fm1::FreqRatio is automated
		phasor_fm1.setParameterT(3, 0.); // core::phasor_fm::Phase
		
		; // branch2::Index is automated
		
		fm.setParameterT(0, 110.); // core::fm::Frequency
		fm.setParameterT(1, 1.);   // core::fm::Modulator
		;                          // fm::FreqMultiplier is automated
		fm.setParameterT(3, 1.);   // core::fm::Gate
		
		fm3.setParameterT(0, 110.); // core::fm::Frequency
		fm3.setParameterT(1, 1.);   // core::fm::Modulator
		;                           // fm3::FreqMultiplier is automated
		fm3.setParameterT(3, 1.);   // core::fm::Gate
		
		fm2.setParameterT(0, 110.); // core::fm::Frequency
		fm2.setParameterT(1, 1.);   // core::fm::Modulator
		;                           // fm2::FreqMultiplier is automated
		fm2.setParameterT(3, 1.);   // core::fm::Gate
		
		fm1.setParameterT(0, 0.); // core::fm::Frequency
		fm1.setParameterT(1, 1.); // core::fm::Modulator
		;                         // fm1::FreqMultiplier is automated
		fm1.setParameterT(3, 1.); // core::fm::Gate
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 8.76766);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 0.105893);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 0.);
		this->setParameterT(13, 0.);
		this->setParameterT(14, 1.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 1.);
		this->setParameterT(18, 1.);
		this->setParameterT(19, 1.);
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
		
		this->getT(0).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable10_t<NV>
		this->getT(0).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable4_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable12_t<NV>
		this->getT(0).getT(1).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable13_t<NV>
		this->getT(0).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable6_t<NV>
		this->getT(0).getT(2).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable16_t<NV>
		this->getT(0).getT(2).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable17_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).setExternalData(b, index);         // osc1_impl::sliderbank3_t<NV>
		this->getT(0).getT(0).getT(2).setExternalData(b, index);         // osc1_impl::peak3_t<NV>
		this->getT(0).getT(0).getT(4).getT(1).setExternalData(b, index); // osc1_impl::peak_t<NV>
		this->getT(0).getT(1).getT(0).setExternalData(b, index);         // osc1_impl::sliderbank4_t<NV>
		this->getT(0).getT(1).getT(2).setExternalData(b, index);         // osc1_impl::peak4_t<NV>
		this->getT(0).getT(2).getT(0).setExternalData(b, index);         // osc1_impl::sliderbank6_t<NV>
		this->getT(0).getT(2).getT(2).setExternalData(b, index);         // osc1_impl::peak6_t<NV>
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
using osc1 = wrap::node<osc1_impl::instance<NV>>;
}


