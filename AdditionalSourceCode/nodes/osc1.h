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
using global_cable14_t_index = runtime_target::indexers::fix_hash<2333887>;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
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
                                        parameter::plain<core::phasor_fm<NV>, 1>>;

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
using converter_t = control::converter<parameter::plain<core::phasor_fm<NV>, 2>, 
                                       conversion_logic::st2pitch>;
template <int NV>
using minmax2_t = control::minmax<NV, 
                                  parameter::plain<converter_t<NV>, 0>>;

template <int NV>
using peak_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<minmax2_t<NV>, 0>, 
                                  parameter::plain<control::minmax<NV, parameter::empty>, 0>>;

template <int NV>
using peak_t = wrap::mod<peak_mod<NV>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch3_t<NV>>, 
                                   core::smoother<NV>, 
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
using global_cable25_t_index = global_cable14_t_index;

template <int NV>
using global_cable25_t = routing::global_cable<global_cable25_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable25_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader12_t = event_data_reader11_t<NV>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader12_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader13_t = event_data_reader11_t<NV>;

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
                                 data::external::sliderpack<3>>;
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
using global_cable26_t_index = global_cable14_t_index;

template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain66_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable26_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader16_t = event_data_reader11_t<NV>;

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader16_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader17_t = event_data_reader11_t<NV>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader17_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader18_t = event_data_reader11_t<NV>;

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

template <int NV> using pma4_mod = sliderbank3_c0<NV>;

template <int NV>
using pma4_t = control::pma<NV, pma4_mod<NV>>;
template <int NV>
using peak6_t = wrap::mod<parameter::plain<pma4_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain4_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank6_t<NV>>, 
                                      split6_t<NV>, 
                                      peak6_t<NV>, 
                                      pma4_t<NV>>;

template <int NV>
using modchain4_t = wrap::control_rate<modchain4_t_<NV>>;

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
                                 data::external::sliderpack<2>>;
using global_cable9_t_index = global_cable3_t_index;

template <int NV>
using global_cable9_t = routing::global_cable<global_cable9_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain116_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable9_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable22_t_index = global_cable11_t_index;

template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain117_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable22_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable23_t_index = global_cable10_t_index;

template <int NV>
using global_cable23_t = routing::global_cable<global_cable23_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain118_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable23_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable29_t_index = global_cable14_t_index;

template <int NV>
using global_cable29_t = routing::global_cable<global_cable29_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain119_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable29_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader25_t = event_data_reader11_t<NV>;

template <int NV>
using chain120_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader25_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader26_t = event_data_reader11_t<NV>;

template <int NV>
using chain121_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader26_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader27_t = event_data_reader11_t<NV>;

template <int NV>
using chain122_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader27_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc26_t = midi_cc10_t<NV>;

template <int NV>
using chain124_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc26_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc27_t = midi_cc10_t<NV>;

template <int NV>
using chain125_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc27_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc28_t = midi_cc10_t<NV>;

template <int NV>
using chain126_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc28_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc29_t = midi_cc10_t<NV>;

template <int NV>
using chain127_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc29_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi18_t = midi6_t<NV>;

template <int NV>
using chain128_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi18_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi19_t = midi7_t<NV>;

template <int NV>
using chain129_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi19_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi20_t = midi8_t<NV>;

template <int NV>
using chain130_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi20_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch9_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain124_t<NV>>, 
                                    chain125_t<NV>, 
                                    chain126_t<NV>, 
                                    chain127_t<NV>, 
                                    chain128_t<NV>, 
                                    chain129_t<NV>, 
                                    chain130_t<NV>>;

template <int NV>
using chain123_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch9_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain116_t<NV>>, 
                                   chain117_t<NV>, 
                                   chain118_t<NV>, 
                                   chain119_t<NV>, 
                                   chain120_t<NV>, 
                                   chain121_t<NV>, 
                                   chain122_t<NV>, 
                                   chain123_t<NV>>;

template <int NV> using xfader2_c0 = sliderbank3_c0<NV>;

template <int NV> using xfader2_c1 = sliderbank3_c0<NV>;

template <int NV> using xfader2_c2 = sliderbank3_c0<NV>;

template <int NV> using xfader2_c3 = sliderbank3_c0<NV>;

template <int NV> using xfader2_c4 = sliderbank3_c0<NV>;

template <int NV> using xfader2_c5 = sliderbank3_c0<NV>;

template <int NV> using xfader2_c6 = sliderbank3_c0<NV>;

template <int NV> using xfader2_c7 = sliderbank3_c0<NV>;

template <int NV>
using xfader2_multimod = parameter::list<xfader2_c0<NV>, 
                                         xfader2_c1<NV>, 
                                         xfader2_c2<NV>, 
                                         xfader2_c3<NV>, 
                                         xfader2_c4<NV>, 
                                         xfader2_c5<NV>, 
                                         xfader2_c6<NV>, 
                                         xfader2_c7<NV>>;

template <int NV>
using xfader2_t = control::xfader<xfader2_multimod<NV>, faders::linear>;
template <int NV>
using pma12_t = control::pma<NV, 
                             parameter::plain<xfader2_t<NV>, 0>>;
template <int NV>
using peak9_t = wrap::mod<parameter::plain<pma12_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain7_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank9_t<NV>>, 
                                      split11_t<NV>, 
                                      peak9_t<NV>, 
                                      pma12_t<NV>>;

template <int NV>
using modchain7_t = wrap::control_rate<modchain7_t_<NV>>;

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
                                 data::external::sliderpack<4>>;
using global_cable8_t_index = global_cable3_t_index;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain101_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable8_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable20_t_index = global_cable11_t_index;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain102_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable20_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable21_t_index = global_cable10_t_index;

template <int NV>
using global_cable21_t = routing::global_cable<global_cable21_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain103_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable21_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable28_t_index = global_cable14_t_index;

template <int NV>
using global_cable28_t = routing::global_cable<global_cable28_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain104_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable28_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader22_t = event_data_reader11_t<NV>;

template <int NV>
using chain105_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader22_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader23_t = event_data_reader11_t<NV>;

template <int NV>
using chain106_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader23_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader24_t = event_data_reader11_t<NV>;

template <int NV>
using chain107_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader24_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc22_t = midi_cc10_t<NV>;

template <int NV>
using chain109_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc22_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc23_t = midi_cc10_t<NV>;

template <int NV>
using chain110_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc23_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc24_t = midi_cc10_t<NV>;

template <int NV>
using chain111_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc24_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc25_t = midi_cc10_t<NV>;

template <int NV>
using chain112_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc25_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi15_t = midi6_t<NV>;

template <int NV>
using chain113_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi15_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi16_t = midi7_t<NV>;

template <int NV>
using chain114_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi16_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi17_t = midi8_t<NV>;

template <int NV>
using chain115_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi17_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch8_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain109_t<NV>>, 
                                    chain110_t<NV>, 
                                    chain111_t<NV>, 
                                    chain112_t<NV>, 
                                    chain113_t<NV>, 
                                    chain114_t<NV>, 
                                    chain115_t<NV>>;

template <int NV>
using chain108_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch8_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split10_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain101_t<NV>>, 
                                   chain102_t<NV>, 
                                   chain103_t<NV>, 
                                   chain104_t<NV>, 
                                   chain105_t<NV>, 
                                   chain106_t<NV>, 
                                   chain107_t<NV>, 
                                   chain108_t<NV>>;

namespace custom
{

struct expr6
{
	static float op(float input, float value)
	{
		return (1.0 - value) * input + value * Math.tan(Math.PI * 4.0 * value * input);
		;
	}
};
}

template <int NV> using xfader3_c0 = sliderbank3_c0<NV>;

template <int NV> using xfader3_c1 = sliderbank3_c0<NV>;

template <int NV>
using xfader3_multimod = parameter::list<xfader3_c0<NV>, xfader3_c1<NV>>;

template <int NV>
using xfader3_t = control::xfader<xfader3_multimod<NV>, faders::linear>;

struct cable_table1_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00196075f, 0.00392157f, 0.00588232f, 0.00784314f, 0.00980389f,
		0.0117646f, 0.0137255f, 0.0156862f, 0.017647f, 0.0196078f, 0.0215685f,
		0.0235294f, 0.0254901f, 0.0274509f, 0.0294117f, 0.0313724f, 0.0333332f,
		0.035294f, 0.0372548f, 0.0392156f, 0.0411763f, 0.0431371f, 0.0450979f,
		0.0470586f, 0.0490194f, 0.0509802f, 0.052941f, 0.0549018f, 0.0568625f,
		0.0588233f, 0.0607841f, 0.0627449f, 0.0647056f, 0.0666664f, 0.0686272f,
		0.070588f, 0.0725487f, 0.0745095f, 0.0764703f, 0.0784311f, 0.0803919f,
		0.0823526f, 0.0843134f, 0.0862741f, 0.088235f, 0.0901957f, 0.0921565f,
		0.0941173f, 0.096078f, 0.0980389f, 0.0999996f, 0.10196f, 0.103921f,
		0.105882f, 0.107843f, 0.109803f, 0.111764f, 0.113725f, 0.115686f,
		0.117647f, 0.119607f, 0.121568f, 0.123529f, 0.12549f, 0.12745f,
		0.129411f, 0.131372f, 0.133333f, 0.135294f, 0.137254f, 0.139215f,
		0.141176f, 0.143137f, 0.145097f, 0.147058f, 0.149019f, 0.15098f,
		0.152941f, 0.154901f, 0.156862f, 0.158823f, 0.160784f, 0.162745f,
		0.164705f, 0.166666f, 0.168627f, 0.170588f, 0.172548f, 0.174509f,
		0.17647f, 0.178431f, 0.180391f, 0.182352f, 0.184313f, 0.186274f,
		0.188235f, 0.190195f, 0.192156f, 0.194117f, 0.196078f, 0.198038f,
		0.199999f, 0.20196f, 0.203921f, 0.205882f, 0.207842f, 0.209803f,
		0.211764f, 0.213725f, 0.215685f, 0.217646f, 0.219607f, 0.221568f,
		0.223529f, 0.225489f, 0.22745f, 0.229411f, 0.231372f, 0.233332f,
		0.235293f, 0.237254f, 0.239215f, 0.241176f, 0.243136f, 0.245097f,
		0.247058f, 0.249019f, 0.250979f, 0.25294f, 0.254901f, 0.256862f,
		0.258823f, 0.260783f, 0.262744f, 0.264705f, 0.266666f, 0.268626f,
		0.270587f, 0.272548f, 0.274509f, 0.27647f, 0.27843f, 0.280391f,
		0.282352f, 0.284313f, 0.286273f, 0.288234f, 0.290195f, 0.292156f,
		0.294116f, 0.296077f, 0.298038f, 0.299999f, 0.30196f, 0.30392f,
		0.305881f, 0.307842f, 0.309803f, 0.311764f, 0.313724f, 0.315685f,
		0.317646f, 0.319607f, 0.321567f, 0.323528f, 0.325489f, 0.32745f,
		0.32941f, 0.331371f, 0.333332f, 0.335293f, 0.337254f, 0.339214f,
		0.341175f, 0.343136f, 0.345097f, 0.347057f, 0.349018f, 0.350979f,
		0.35294f, 0.354901f, 0.356861f, 0.358822f, 0.360783f, 0.362744f,
		0.364704f, 0.366665f, 0.368626f, 0.370587f, 0.372548f, 0.374508f,
		0.376469f, 0.37843f, 0.380391f, 0.382352f, 0.384312f, 0.386273f,
		0.388234f, 0.390195f, 0.392155f, 0.394116f, 0.396077f, 0.398038f,
		0.399998f, 0.401959f, 0.40392f, 0.405881f, 0.407842f, 0.409802f,
		0.411763f, 0.413724f, 0.415685f, 0.417645f, 0.419606f, 0.421567f,
		0.423528f, 0.425489f, 0.427449f, 0.42941f, 0.431371f, 0.433332f,
		0.435292f, 0.437253f, 0.439214f, 0.441175f, 0.443136f, 0.445096f,
		0.447057f, 0.449018f, 0.450979f, 0.45294f, 0.4549f, 0.456861f,
		0.458822f, 0.460783f, 0.462743f, 0.464704f, 0.466665f, 0.468626f,
		0.470586f, 0.472547f, 0.474508f, 0.476469f, 0.47843f, 0.48039f,
		0.482351f, 0.484312f, 0.486273f, 0.488233f, 0.490194f, 0.492155f,
		0.494116f, 0.496077f, 0.498037f, 0.499998f, 0.501959f, 0.50392f,
		0.50588f, 0.507841f, 0.509802f, 0.511763f, 0.513724f, 0.515684f,
		0.517645f, 0.519606f, 0.521567f, 0.523527f, 0.525488f, 0.527449f,
		0.52941f, 0.531371f, 0.533331f, 0.535292f, 0.537253f, 0.539214f,
		0.541174f, 0.543135f, 0.545096f, 0.547057f, 0.549017f, 0.550978f,
		0.552939f, 0.5549f, 0.556861f, 0.558821f, 0.560782f, 0.562743f,
		0.564704f, 0.566664f, 0.568625f, 0.570586f, 0.572547f, 0.574508f,
		0.576468f, 0.578429f, 0.58039f, 0.582351f, 0.584311f, 0.586272f,
		0.588233f, 0.590194f, 0.592155f, 0.594115f, 0.596076f, 0.598037f,
		0.599998f, 0.601958f, 0.603919f, 0.60588f, 0.607841f, 0.609802f,
		0.611762f, 0.613723f, 0.615684f, 0.617645f, 0.619606f, 0.621566f,
		0.623527f, 0.625488f, 0.627449f, 0.629409f, 0.63137f, 0.633331f,
		0.635292f, 0.637253f, 0.639213f, 0.641174f, 0.643135f, 0.645096f,
		0.647056f, 0.649017f, 0.650978f, 0.652939f, 0.654899f, 0.65686f,
		0.658821f, 0.660782f, 0.662743f, 0.664703f, 0.666664f, 0.668625f,
		0.670586f, 0.672546f, 0.674507f, 0.676468f, 0.678429f, 0.68039f,
		0.68235f, 0.684311f, 0.686272f, 0.688233f, 0.690193f, 0.692154f,
		0.694115f, 0.696076f, 0.698037f, 0.699997f, 0.701958f, 0.703919f,
		0.70588f, 0.70784f, 0.709801f, 0.711762f, 0.713723f, 0.715684f,
		0.717644f, 0.719605f, 0.721566f, 0.723527f, 0.725487f, 0.727448f,
		0.729409f, 0.73137f, 0.733331f, 0.735291f, 0.737252f, 0.739213f,
		0.741174f, 0.743134f, 0.745095f, 0.747056f, 0.749017f, 0.750978f,
		0.752938f, 0.754899f, 0.75686f, 0.758821f, 0.760781f, 0.762742f,
		0.764703f, 0.766664f, 0.768624f, 0.770585f, 0.772546f, 0.774507f,
		0.776468f, 0.778428f, 0.780389f, 0.78235f, 0.784311f, 0.786272f,
		0.788232f, 0.790193f, 0.792154f, 0.794115f, 0.796075f, 0.798036f,
		0.799997f, 0.801958f, 0.803918f, 0.805879f, 0.80784f, 0.809801f,
		0.811762f, 0.813722f, 0.815683f, 0.817644f, 0.819605f, 0.821566f,
		0.823526f, 0.825487f, 0.827448f, 0.829409f, 0.831369f, 0.83333f,
		0.835291f, 0.837252f, 0.839212f, 0.841173f, 0.843134f, 0.845095f,
		0.847056f, 0.849016f, 0.850977f, 0.852938f, 0.854899f, 0.85686f,
		0.85882f, 0.860781f, 0.862742f, 0.864703f, 0.866663f, 0.868624f,
		0.870585f, 0.872546f, 0.874506f, 0.876467f, 0.878428f, 0.880389f,
		0.88235f, 0.88431f, 0.886271f, 0.888232f, 0.890193f, 0.892154f,
		0.894114f, 0.896075f, 0.898036f, 0.899997f, 0.901957f, 0.903918f,
		0.905879f, 0.90784f, 0.9098f, 0.911761f, 0.913722f, 0.915683f,
		0.917644f, 0.919604f, 0.921565f, 0.923526f, 0.925487f, 0.927447f,
		0.929408f, 0.931369f, 0.93333f, 0.935291f, 0.937251f, 0.939212f,
		0.941173f, 0.943134f, 0.945094f, 0.947055f, 0.949016f, 0.950977f,
		0.952938f, 0.954898f, 0.956859f, 0.95882f, 0.960781f, 0.962741f,
		0.964702f, 0.966663f, 0.968624f, 0.970585f, 0.972545f, 0.974506f,
		0.976467f, 0.978428f, 0.980388f, 0.982349f, 0.98431f, 0.986271f,
		0.988232f, 0.990192f, 0.992153f, 0.994114f, 0.996075f, 0.998035f,
		0.999996f, 1.f
	};
};

using cable_table1_t = wrap::data<control::cable_table<parameter::empty>, 
                                  data::embedded::table<cable_table1_t_data>>;

DECLARE_PARAMETER_RANGE(clone_cable2_0Range, 
                        -1., 
                        1.);

template <int NV>
using clone_cable2_0 = parameter::from0To1<jdsp::jpanner<NV>, 
                                           0, 
                                           clone_cable2_0Range>;

DECLARE_PARAMETER_RANGE_STEP(clone_cable2_1Range, 
                             -16., 
                             16., 
                             0.5);

template <int NV>
using clone_cable2_1 = parameter::from0To1<core::gain<NV>, 
                                           0, 
                                           clone_cable2_1Range>;

template <int NV>
using clone_cable2_cc = parameter::clonechain<parameter::cloned<clone_cable2_0<NV>>, 
                                              parameter::cloned<clone_cable2_1<NV>>>;
template <int NV>
using clone_cable2_t = control::clone_cable<clone_cable2_cc<NV>, duplilogic::spread>;

namespace custom
{

struct expr9
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 2.0 * value * input);;
	}
};
}

template <int NV>
using clone_cable4_cable_mod = parameter::cloned<parameter::plain<math::expr<NV, custom::expr9>, 0>>;
template <int NV>
using clone_cable4_t = control::clone_cable<clone_cable4_cable_mod<NV>, 
                                            duplilogic::nyquist>;
DECLARE_PARAMETER_RANGE_STEP(pma6_mod_0Range, 
                             -20., 
                             24., 
                             0.1);

template <int NV>
using pma6_mod_0 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       pma6_mod_0Range>;

DECLARE_PARAMETER_RANGE_STEP(pma6_mod_1Range, 
                             -12., 
                             12., 
                             0.1);

template <int NV>
using pma6_mod_1 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       pma6_mod_1Range>;

template <int NV> using pma6_mod_2 = pma6_mod_1<NV>;

template <int NV> using pma6_mod_3 = pma6_mod_1<NV>;

DECLARE_PARAMETER_RANGE(pma6_mod_4Range, 
                        0.11, 
                        1.);

template <int NV>
using pma6_mod_4 = parameter::from0To1<math::expr<NV, custom::expr6>, 
                                       0, 
                                       pma6_mod_4Range>;

DECLARE_PARAMETER_RANGE_SKEW(pma6_mod_5Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma6_mod_5 = parameter::from0To1<wrap::no_process<fx::phase_delay<NV>>, 
                                       0, 
                                       pma6_mod_5Range>;

template <int NV> using pma6_mod_7 = pma6_mod_1<NV>;

template <int NV>
using pma6_mod_9 = parameter::from0To1<clone_cable2_t<NV>, 
                                       1, 
                                       clone_cable2_0Range>;

DECLARE_PARAMETER_RANGE_STEP(pma6_mod_11Range, 
                             -6., 
                             24., 
                             0.1);

template <int NV>
using pma6_mod_11 = parameter::from0To1<core::gain<NV>, 
                                        0, 
                                        pma6_mod_11Range>;

template <int NV>
using pma6_mod = parameter::chain<ranges::Identity, 
                                  pma6_mod_0<NV>, 
                                  pma6_mod_1<NV>, 
                                  pma6_mod_2<NV>, 
                                  pma6_mod_3<NV>, 
                                  pma6_mod_4<NV>, 
                                  pma6_mod_5<NV>, 
                                  parameter::plain<xfader3_t<NV>, 0>, 
                                  pma6_mod_7<NV>, 
                                  parameter::plain<cable_table1_t, 0>, 
                                  pma6_mod_9<NV>, 
                                  parameter::plain<clone_cable4_t<NV>, 1>, 
                                  pma6_mod_11<NV>>;

template <int NV>
using pma6_t = control::pma<NV, pma6_mod<NV>>;
template <int NV>
using pma10_t = control::pma<NV, 
                             parameter::plain<pma6_t<NV>, 2>>;
template <int NV>
using peak8_t = wrap::mod<parameter::plain<pma10_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain6_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank8_t<NV>>, 
                                      split10_t<NV>, 
                                      peak8_t<NV>, 
                                      pma10_t<NV>>;

template <int NV>
using modchain6_t = wrap::control_rate<modchain6_t_<NV>>;

template <int NV> using sliderbank18_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank18_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank18_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank18_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank18_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank18_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank18_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank18_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank18_multimod = parameter::list<sliderbank18_c0<NV>, 
                                              sliderbank18_c1<NV>, 
                                              sliderbank18_c2<NV>, 
                                              sliderbank18_c3<NV>, 
                                              sliderbank18_c4<NV>, 
                                              sliderbank18_c5<NV>, 
                                              sliderbank18_c6<NV>, 
                                              sliderbank18_c7<NV>>;

template <int NV>
using sliderbank18_t = wrap::data<control::sliderbank<sliderbank18_multimod<NV>>, 
                                  data::external::sliderpack<7>>;
using global_cable63_t_index = global_cable3_t_index;

template <int NV>
using global_cable63_t = routing::global_cable<global_cable63_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain300_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable63_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable64_t_index = global_cable11_t_index;

template <int NV>
using global_cable64_t = routing::global_cable<global_cable64_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain301_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable64_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable65_t_index = global_cable10_t_index;

template <int NV>
using global_cable65_t = routing::global_cable<global_cable65_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain302_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable65_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable66_t_index = global_cable14_t_index;

template <int NV>
using global_cable66_t = routing::global_cable<global_cable66_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain303_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable66_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader55_t = event_data_reader11_t<NV>;

template <int NV>
using chain304_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader55_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader56_t = event_data_reader11_t<NV>;

template <int NV>
using chain305_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader56_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader57_t = event_data_reader11_t<NV>;

template <int NV>
using chain306_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader57_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc66_t = midi_cc10_t<NV>;

template <int NV>
using chain308_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc66_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc67_t = midi_cc10_t<NV>;

template <int NV>
using chain309_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc67_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc68_t = midi_cc10_t<NV>;

template <int NV>
using chain310_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc68_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc69_t = midi_cc10_t<NV>;

template <int NV>
using chain311_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc69_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi49_t = midi6_t<NV>;

template <int NV>
using chain312_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi49_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi50_t = midi7_t<NV>;

template <int NV>
using chain313_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi50_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi51_t = midi8_t<NV>;

template <int NV>
using chain314_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi51_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch28_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain308_t<NV>>, 
                                     chain309_t<NV>, 
                                     chain310_t<NV>, 
                                     chain311_t<NV>, 
                                     chain312_t<NV>, 
                                     chain313_t<NV>, 
                                     chain314_t<NV>>;

template <int NV>
using chain307_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch28_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split41_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain300_t<NV>>, 
                                   chain301_t<NV>, 
                                   chain302_t<NV>, 
                                   chain303_t<NV>, 
                                   chain304_t<NV>, 
                                   chain305_t<NV>, 
                                   chain306_t<NV>, 
                                   chain307_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(pma24_mod_0Range, 
                             -24., 
                             24., 
                             0.1);

template <int NV>
using pma24_mod_0 = parameter::from0To1<project::shfiter<NV>, 
                                        0, 
                                        pma24_mod_0Range>;

template <int NV> using pma24_mod_1 = pma24_mod_0<NV>;

template <int NV>
using pma24_mod = parameter::chain<ranges::Identity, 
                                   pma24_mod_0<NV>, 
                                   pma24_mod_1<NV>>;

template <int NV>
using pma24_t = control::pma<NV, pma24_mod<NV>>;
template <int NV>
using peak23_t = wrap::mod<parameter::plain<pma24_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain19_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank18_t<NV>>, 
                                       split41_t<NV>, 
                                       peak23_t<NV>, 
                                       pma24_t<NV>>;

template <int NV>
using modchain19_t = wrap::control_rate<modchain19_t_<NV>>;

template <int NV> using sliderbank19_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank19_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank19_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank19_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank19_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank19_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank19_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank19_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank19_multimod = parameter::list<sliderbank19_c0<NV>, 
                                              sliderbank19_c1<NV>, 
                                              sliderbank19_c2<NV>, 
                                              sliderbank19_c3<NV>, 
                                              sliderbank19_c4<NV>, 
                                              sliderbank19_c5<NV>, 
                                              sliderbank19_c6<NV>, 
                                              sliderbank19_c7<NV>>;

template <int NV>
using sliderbank19_t = wrap::data<control::sliderbank<sliderbank19_multimod<NV>>, 
                                  data::external::sliderpack<8>>;
using global_cable67_t_index = global_cable3_t_index;

template <int NV>
using global_cable67_t = routing::global_cable<global_cable67_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain315_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable67_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable68_t_index = global_cable11_t_index;

template <int NV>
using global_cable68_t = routing::global_cable<global_cable68_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain316_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable68_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable69_t_index = global_cable10_t_index;

template <int NV>
using global_cable69_t = routing::global_cable<global_cable69_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain317_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable69_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable70_t_index = global_cable14_t_index;

template <int NV>
using global_cable70_t = routing::global_cable<global_cable70_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain318_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable70_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader58_t = event_data_reader11_t<NV>;

template <int NV>
using chain319_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader58_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader59_t = event_data_reader11_t<NV>;

template <int NV>
using chain320_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader59_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader60_t = event_data_reader11_t<NV>;

template <int NV>
using chain321_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader60_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc70_t = midi_cc10_t<NV>;

template <int NV>
using chain323_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc70_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc71_t = midi_cc10_t<NV>;

template <int NV>
using chain324_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc71_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc72_t = midi_cc10_t<NV>;

template <int NV>
using chain325_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc72_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc73_t = midi_cc10_t<NV>;

template <int NV>
using chain326_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc73_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi52_t = midi6_t<NV>;

template <int NV>
using chain327_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi52_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi53_t = midi7_t<NV>;

template <int NV>
using chain328_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi53_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi54_t = midi8_t<NV>;

template <int NV>
using chain329_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi54_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch29_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain323_t<NV>>, 
                                     chain324_t<NV>, 
                                     chain325_t<NV>, 
                                     chain326_t<NV>, 
                                     chain327_t<NV>, 
                                     chain328_t<NV>, 
                                     chain329_t<NV>>;

template <int NV>
using chain322_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch29_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split42_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain315_t<NV>>, 
                                   chain316_t<NV>, 
                                   chain317_t<NV>, 
                                   chain318_t<NV>, 
                                   chain319_t<NV>, 
                                   chain320_t<NV>, 
                                   chain321_t<NV>, 
                                   chain322_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(pma26_mod_0Range, 
                             50., 
                             10000., 
                             1.);

template <int NV>
using pma26_mod_0 = parameter::from0To1<project::shfiter<NV>, 
                                        1, 
                                        pma26_mod_0Range>;

template <int NV>
using pma26_mod_1 = parameter::from0To1<project::ps2<NV>, 
                                        1, 
                                        pma26_mod_0Range>;

template <int NV> using pma26_mod_2 = pma26_mod_0<NV>;

template <int NV>
using pma26_mod = parameter::chain<ranges::Identity, 
                                   pma26_mod_0<NV>, 
                                   pma26_mod_1<NV>, 
                                   pma26_mod_2<NV>>;

template <int NV>
using pma26_t = control::pma<NV, pma26_mod<NV>>;
template <int NV>
using peak24_t = wrap::mod<parameter::plain<pma26_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain20_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank19_t<NV>>, 
                                       split42_t<NV>, 
                                       peak24_t<NV>, 
                                       pma26_t<NV>>;

template <int NV>
using modchain20_t = wrap::control_rate<modchain20_t_<NV>>;

template <int NV> using sliderbank20_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank20_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank20_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank20_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank20_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank20_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank20_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank20_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank20_multimod = parameter::list<sliderbank20_c0<NV>, 
                                              sliderbank20_c1<NV>, 
                                              sliderbank20_c2<NV>, 
                                              sliderbank20_c3<NV>, 
                                              sliderbank20_c4<NV>, 
                                              sliderbank20_c5<NV>, 
                                              sliderbank20_c6<NV>, 
                                              sliderbank20_c7<NV>>;

template <int NV>
using sliderbank20_t = wrap::data<control::sliderbank<sliderbank20_multimod<NV>>, 
                                  data::external::sliderpack<9>>;
using global_cable71_t_index = global_cable3_t_index;

template <int NV>
using global_cable71_t = routing::global_cable<global_cable71_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain330_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable71_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable72_t_index = global_cable11_t_index;

template <int NV>
using global_cable72_t = routing::global_cable<global_cable72_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain331_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable72_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable73_t_index = global_cable10_t_index;

template <int NV>
using global_cable73_t = routing::global_cable<global_cable73_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain332_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable73_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable74_t_index = global_cable14_t_index;

template <int NV>
using global_cable74_t = routing::global_cable<global_cable74_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain333_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable74_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader61_t = event_data_reader11_t<NV>;

template <int NV>
using chain334_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader61_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader62_t = event_data_reader11_t<NV>;

template <int NV>
using chain335_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader62_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader63_t = event_data_reader11_t<NV>;

template <int NV>
using chain336_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader63_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc74_t = midi_cc10_t<NV>;

template <int NV>
using chain338_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc74_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc75_t = midi_cc10_t<NV>;

template <int NV>
using chain339_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc75_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc76_t = midi_cc10_t<NV>;

template <int NV>
using chain340_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc76_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc77_t = midi_cc10_t<NV>;

template <int NV>
using chain341_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc77_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi55_t = midi6_t<NV>;

template <int NV>
using chain342_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi55_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi56_t = midi7_t<NV>;

template <int NV>
using chain343_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi56_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi57_t = midi8_t<NV>;

template <int NV>
using chain344_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi57_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch30_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain338_t<NV>>, 
                                     chain339_t<NV>, 
                                     chain340_t<NV>, 
                                     chain341_t<NV>, 
                                     chain342_t<NV>, 
                                     chain343_t<NV>, 
                                     chain344_t<NV>>;

template <int NV>
using chain337_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch30_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split43_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain330_t<NV>>, 
                                   chain331_t<NV>, 
                                   chain332_t<NV>, 
                                   chain333_t<NV>, 
                                   chain334_t<NV>, 
                                   chain335_t<NV>, 
                                   chain336_t<NV>, 
                                   chain337_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(pma40_mod_0Range, 
                             1., 
                             10000., 
                             1.);

template <int NV>
using pma40_mod_0 = parameter::from0To1<project::shfiter<NV>, 
                                        2, 
                                        pma40_mod_0Range>;

template <int NV> using pma40_mod_1 = pma40_mod_0<NV>;

template <int NV>
using pma40_mod_2 = parameter::from0To1<project::ps2<NV>, 
                                        2, 
                                        pma40_mod_0Range>;

template <int NV>
using pma40_mod = parameter::chain<ranges::Identity, 
                                   pma40_mod_0<NV>, 
                                   pma40_mod_1<NV>, 
                                   pma40_mod_2<NV>>;

template <int NV>
using pma40_t = control::pma<NV, pma40_mod<NV>>;
template <int NV>
using peak25_t = wrap::mod<parameter::plain<pma40_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain21_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank20_t<NV>>, 
                                       split43_t<NV>, 
                                       peak25_t<NV>, 
                                       pma40_t<NV>>;

template <int NV>
using modchain21_t = wrap::control_rate<modchain21_t_<NV>>;

template <int NV> using sliderbank21_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank21_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank21_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank21_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank21_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank21_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank21_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank21_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank21_multimod = parameter::list<sliderbank21_c0<NV>, 
                                              sliderbank21_c1<NV>, 
                                              sliderbank21_c2<NV>, 
                                              sliderbank21_c3<NV>, 
                                              sliderbank21_c4<NV>, 
                                              sliderbank21_c5<NV>, 
                                              sliderbank21_c6<NV>, 
                                              sliderbank21_c7<NV>>;

template <int NV>
using sliderbank21_t = wrap::data<control::sliderbank<sliderbank21_multimod<NV>>, 
                                  data::external::sliderpack<6>>;
using global_cable75_t_index = global_cable3_t_index;

template <int NV>
using global_cable75_t = routing::global_cable<global_cable75_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain345_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable75_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable76_t_index = global_cable11_t_index;

template <int NV>
using global_cable76_t = routing::global_cable<global_cable76_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain346_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable76_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable77_t_index = global_cable10_t_index;

template <int NV>
using global_cable77_t = routing::global_cable<global_cable77_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain347_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable77_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable78_t_index = global_cable14_t_index;

template <int NV>
using global_cable78_t = routing::global_cable<global_cable78_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain348_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable78_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader64_t = event_data_reader11_t<NV>;

template <int NV>
using chain349_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader64_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader65_t = event_data_reader11_t<NV>;

template <int NV>
using chain350_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader65_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader66_t = event_data_reader11_t<NV>;

template <int NV>
using chain351_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader66_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc78_t = midi_cc10_t<NV>;

template <int NV>
using chain353_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc78_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc79_t = midi_cc10_t<NV>;

template <int NV>
using chain354_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc79_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc80_t = midi_cc10_t<NV>;

template <int NV>
using chain355_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc80_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc81_t = midi_cc10_t<NV>;

template <int NV>
using chain356_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc81_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi58_t = midi6_t<NV>;

template <int NV>
using chain357_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi58_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi59_t = midi7_t<NV>;

template <int NV>
using chain358_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi59_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi60_t = midi8_t<NV>;

template <int NV>
using chain359_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi60_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch31_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain353_t<NV>>, 
                                     chain354_t<NV>, 
                                     chain355_t<NV>, 
                                     chain356_t<NV>, 
                                     chain357_t<NV>, 
                                     chain358_t<NV>, 
                                     chain359_t<NV>>;

template <int NV>
using chain352_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch31_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split44_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain345_t<NV>>, 
                                   chain346_t<NV>, 
                                   chain347_t<NV>, 
                                   chain348_t<NV>, 
                                   chain349_t<NV>, 
                                   chain350_t<NV>, 
                                   chain351_t<NV>, 
                                   chain352_t<NV>>;

template <int NV> using pma27_mod = sliderbank3_c0<NV>;

template <int NV>
using pma27_t = control::pma<NV, pma27_mod<NV>>;
template <int NV>
using peak26_t = wrap::mod<parameter::plain<pma27_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain22_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank21_t<NV>>, 
                                       split44_t<NV>, 
                                       peak26_t<NV>, 
                                       pma27_t<NV>>;

template <int NV>
using modchain22_t = wrap::control_rate<modchain22_t_<NV>>;

template <int NV> using sliderbank22_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank22_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank22_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank22_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank22_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank22_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank22_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank22_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank22_multimod = parameter::list<sliderbank22_c0<NV>, 
                                              sliderbank22_c1<NV>, 
                                              sliderbank22_c2<NV>, 
                                              sliderbank22_c3<NV>, 
                                              sliderbank22_c4<NV>, 
                                              sliderbank22_c5<NV>, 
                                              sliderbank22_c6<NV>, 
                                              sliderbank22_c7<NV>>;

template <int NV>
using sliderbank22_t = wrap::data<control::sliderbank<sliderbank22_multimod<NV>>, 
                                  data::external::sliderpack<10>>;
using global_cable79_t_index = global_cable3_t_index;

template <int NV>
using global_cable79_t = routing::global_cable<global_cable79_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain360_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable79_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable80_t_index = global_cable11_t_index;

template <int NV>
using global_cable80_t = routing::global_cable<global_cable80_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain361_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable80_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable81_t_index = global_cable10_t_index;

template <int NV>
using global_cable81_t = routing::global_cable<global_cable81_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain362_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable81_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable82_t_index = global_cable14_t_index;

template <int NV>
using global_cable82_t = routing::global_cable<global_cable82_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain363_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable82_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader67_t = event_data_reader11_t<NV>;

template <int NV>
using chain364_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader67_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader68_t = event_data_reader11_t<NV>;

template <int NV>
using chain365_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader68_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader69_t = event_data_reader11_t<NV>;

template <int NV>
using chain366_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader69_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc82_t = midi_cc10_t<NV>;

template <int NV>
using chain368_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc82_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc83_t = midi_cc10_t<NV>;

template <int NV>
using chain369_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc83_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc84_t = midi_cc10_t<NV>;

template <int NV>
using chain370_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc84_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc85_t = midi_cc10_t<NV>;

template <int NV>
using chain371_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc85_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi61_t = midi6_t<NV>;

template <int NV>
using chain372_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi61_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi62_t = midi7_t<NV>;

template <int NV>
using chain373_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi62_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi63_t = midi8_t<NV>;

template <int NV>
using chain374_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi63_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch32_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain368_t<NV>>, 
                                     chain369_t<NV>, 
                                     chain370_t<NV>, 
                                     chain371_t<NV>, 
                                     chain372_t<NV>, 
                                     chain373_t<NV>, 
                                     chain374_t<NV>>;

template <int NV>
using chain367_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch32_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split45_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain360_t<NV>>, 
                                   chain361_t<NV>, 
                                   chain362_t<NV>, 
                                   chain363_t<NV>, 
                                   chain364_t<NV>, 
                                   chain365_t<NV>, 
                                   chain366_t<NV>, 
                                   chain367_t<NV>>;

template <int NV>
using minmax6_t = control::minmax<NV, 
                                  parameter::plain<math::add<NV>, 0>>;

template <int NV> using minmax7_t = minmax6_t<NV>;

template <int NV> using minmax14_t = minmax6_t<NV>;

template <int NV> using minmax11_t = minmax6_t<NV>;

template <int NV> using minmax15_t = minmax6_t<NV>;

template <int NV> using minmax16_t = minmax6_t<NV>;

template <int NV> using minmax17_t = minmax6_t<NV>;

template <int NV> using minmax18_t = minmax6_t<NV>;
using cable_table16_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::external::table<4>>;

template <int NV>
using pma21_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<minmax6_t<NV>, 0>, 
                                   parameter::plain<minmax7_t<NV>, 0>, 
                                   parameter::plain<minmax14_t<NV>, 0>, 
                                   parameter::plain<minmax11_t<NV>, 0>, 
                                   parameter::plain<minmax15_t<NV>, 0>, 
                                   parameter::plain<minmax16_t<NV>, 0>, 
                                   parameter::plain<minmax17_t<NV>, 0>, 
                                   parameter::plain<minmax18_t<NV>, 0>, 
                                   parameter::plain<cable_table16_t, 0>>;

template <int NV>
using pma21_t = control::pma<NV, pma21_mod<NV>>;
template <int NV>
using cable_table17_t = wrap::data<control::cable_table<parameter::plain<pma21_t<NV>, 0>>, 
                                   data::external::table<1>>;
template <int NV>
using ramp1_t = wrap::mod<parameter::plain<cable_table17_t<NV>, 0>, 
                          wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using tempo_sync6_t = wrap::mod<parameter::plain<ramp1_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using clock_ramp1_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                wrap::no_data<core::clock_ramp<NV, false>>>;
template <int NV>
using pma28_mod_0 = parameter::from0To1<tempo_sync6_t<NV>, 
                                        0, 
                                        pma8_modRange>;

template <int NV>
using pma28_mod_1 = parameter::from0To1<clock_ramp1_t<NV>, 
                                        0, 
                                        pma8_modRange>;

template <int NV>
using pma28_mod = parameter::chain<ranges::Identity, 
                                   pma28_mod_0<NV>, 
                                   pma28_mod_1<NV>>;

template <int NV>
using pma28_t = control::pma<NV, pma28_mod<NV>>;
template <int NV>
using peak27_t = wrap::mod<parameter::plain<pma28_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain23_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank22_t<NV>>, 
                                       split45_t<NV>, 
                                       peak27_t<NV>, 
                                       pma28_t<NV>>;

template <int NV>
using modchain23_t = wrap::control_rate<modchain23_t_<NV>>;

template <int NV> using sliderbank23_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank23_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank23_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank23_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank23_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank23_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank23_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank23_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank23_multimod = parameter::list<sliderbank23_c0<NV>, 
                                              sliderbank23_c1<NV>, 
                                              sliderbank23_c2<NV>, 
                                              sliderbank23_c3<NV>, 
                                              sliderbank23_c4<NV>, 
                                              sliderbank23_c5<NV>, 
                                              sliderbank23_c6<NV>, 
                                              sliderbank23_c7<NV>>;

template <int NV>
using sliderbank23_t = wrap::data<control::sliderbank<sliderbank23_multimod<NV>>, 
                                  data::external::sliderpack<11>>;
using global_cable83_t_index = global_cable3_t_index;

template <int NV>
using global_cable83_t = routing::global_cable<global_cable83_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain375_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable83_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable84_t_index = global_cable11_t_index;

template <int NV>
using global_cable84_t = routing::global_cable<global_cable84_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain376_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable84_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable85_t_index = global_cable10_t_index;

template <int NV>
using global_cable85_t = routing::global_cable<global_cable85_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain377_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable85_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable86_t_index = global_cable14_t_index;

template <int NV>
using global_cable86_t = routing::global_cable<global_cable86_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain378_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable86_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader70_t = event_data_reader11_t<NV>;

template <int NV>
using chain379_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader70_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader71_t = event_data_reader11_t<NV>;

template <int NV>
using chain380_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader71_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader72_t = event_data_reader11_t<NV>;

template <int NV>
using chain381_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader72_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc86_t = midi_cc10_t<NV>;

template <int NV>
using chain383_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc86_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc87_t = midi_cc10_t<NV>;

template <int NV>
using chain384_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc87_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc88_t = midi_cc10_t<NV>;

template <int NV>
using chain385_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc88_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc89_t = midi_cc10_t<NV>;

template <int NV>
using chain386_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc89_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi64_t = midi6_t<NV>;

template <int NV>
using chain387_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi64_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi65_t = midi7_t<NV>;

template <int NV>
using chain388_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi65_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi66_t = midi8_t<NV>;

template <int NV>
using chain389_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi66_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch33_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain383_t<NV>>, 
                                     chain384_t<NV>, 
                                     chain385_t<NV>, 
                                     chain386_t<NV>, 
                                     chain387_t<NV>, 
                                     chain388_t<NV>, 
                                     chain389_t<NV>>;

template <int NV>
using chain382_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch33_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split46_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain375_t<NV>>, 
                                   chain376_t<NV>, 
                                   chain377_t<NV>, 
                                   chain378_t<NV>, 
                                   chain379_t<NV>, 
                                   chain380_t<NV>, 
                                   chain381_t<NV>, 
                                   chain382_t<NV>>;

namespace custom
{

struct expr10
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 2.0 * value * input);;
	}
};
}

template <int NV>
using pma29_t = control::pma<NV, 
                             parameter::plain<math::expr<NV, custom::expr10>, 0>>;
template <int NV>
using peak28_t = wrap::mod<parameter::plain<pma29_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain24_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank23_t<NV>>, 
                                       split46_t<NV>, 
                                       peak28_t<NV>, 
                                       pma29_t<NV>>;

template <int NV>
using modchain24_t = wrap::control_rate<modchain24_t_<NV>>;

template <int NV> using sliderbank24_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank24_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank24_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank24_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank24_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank24_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank24_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank24_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank24_multimod = parameter::list<sliderbank24_c0<NV>, 
                                              sliderbank24_c1<NV>, 
                                              sliderbank24_c2<NV>, 
                                              sliderbank24_c3<NV>, 
                                              sliderbank24_c4<NV>, 
                                              sliderbank24_c5<NV>, 
                                              sliderbank24_c6<NV>, 
                                              sliderbank24_c7<NV>>;

template <int NV>
using sliderbank24_t = wrap::data<control::sliderbank<sliderbank24_multimod<NV>>, 
                                  data::external::sliderpack<12>>;
using global_cable87_t_index = global_cable3_t_index;

template <int NV>
using global_cable87_t = routing::global_cable<global_cable87_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain390_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable87_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable88_t_index = global_cable11_t_index;

template <int NV>
using global_cable88_t = routing::global_cable<global_cable88_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain391_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable88_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable89_t_index = global_cable10_t_index;

template <int NV>
using global_cable89_t = routing::global_cable<global_cable89_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain392_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable89_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable90_t_index = global_cable14_t_index;

template <int NV>
using global_cable90_t = routing::global_cable<global_cable90_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain393_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable90_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader73_t = event_data_reader11_t<NV>;

template <int NV>
using chain394_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader73_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader74_t = event_data_reader11_t<NV>;

template <int NV>
using chain395_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader74_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader75_t = event_data_reader11_t<NV>;

template <int NV>
using chain396_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader75_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc90_t = midi_cc10_t<NV>;

template <int NV>
using chain398_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc90_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc91_t = midi_cc10_t<NV>;

template <int NV>
using chain399_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc91_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc92_t = midi_cc10_t<NV>;

template <int NV>
using chain400_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc92_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc93_t = midi_cc10_t<NV>;

template <int NV>
using chain401_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc93_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi67_t = midi6_t<NV>;

template <int NV>
using chain402_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi67_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi68_t = midi7_t<NV>;

template <int NV>
using chain403_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi68_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi69_t = midi8_t<NV>;

template <int NV>
using chain404_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi69_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch34_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain398_t<NV>>, 
                                     chain399_t<NV>, 
                                     chain400_t<NV>, 
                                     chain401_t<NV>, 
                                     chain402_t<NV>, 
                                     chain403_t<NV>, 
                                     chain404_t<NV>>;

template <int NV>
using chain397_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch34_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split47_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain390_t<NV>>, 
                                   chain391_t<NV>, 
                                   chain392_t<NV>, 
                                   chain393_t<NV>, 
                                   chain394_t<NV>, 
                                   chain395_t<NV>, 
                                   chain396_t<NV>, 
                                   chain397_t<NV>>;

template <int NV> using xfader1_c0 = sliderbank3_c0<NV>;

template <int NV> using xfader1_c1 = sliderbank3_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, xfader1_c1<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::linear>;
template <int NV>
using pma30_t = control::pma<NV, 
                             parameter::plain<xfader1_t<NV>, 0>>;
template <int NV>
using peak29_t = wrap::mod<parameter::plain<pma30_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain25_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank24_t<NV>>, 
                                       split47_t<NV>, 
                                       peak29_t<NV>, 
                                       pma30_t<NV>>;

template <int NV>
using modchain25_t = wrap::control_rate<modchain25_t_<NV>>;

template <int NV> using sliderbank26_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank26_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank26_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank26_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank26_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank26_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank26_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank26_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank26_multimod = parameter::list<sliderbank26_c0<NV>, 
                                              sliderbank26_c1<NV>, 
                                              sliderbank26_c2<NV>, 
                                              sliderbank26_c3<NV>, 
                                              sliderbank26_c4<NV>, 
                                              sliderbank26_c5<NV>, 
                                              sliderbank26_c6<NV>, 
                                              sliderbank26_c7<NV>>;

template <int NV>
using sliderbank26_t = wrap::data<control::sliderbank<sliderbank26_multimod<NV>>, 
                                  data::external::sliderpack<13>>;
using global_cable95_t_index = global_cable3_t_index;

template <int NV>
using global_cable95_t = routing::global_cable<global_cable95_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain420_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable95_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable96_t_index = global_cable11_t_index;

template <int NV>
using global_cable96_t = routing::global_cable<global_cable96_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain421_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable96_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable97_t_index = global_cable10_t_index;

template <int NV>
using global_cable97_t = routing::global_cable<global_cable97_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain422_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable97_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable98_t_index = global_cable14_t_index;

template <int NV>
using global_cable98_t = routing::global_cable<global_cable98_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain423_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable98_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader79_t = event_data_reader11_t<NV>;

template <int NV>
using chain424_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader79_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader80_t = event_data_reader11_t<NV>;

template <int NV>
using chain425_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader80_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader81_t = event_data_reader11_t<NV>;

template <int NV>
using chain427_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader81_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc98_t = midi_cc10_t<NV>;

template <int NV>
using chain429_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc98_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc99_t = midi_cc10_t<NV>;

template <int NV>
using chain430_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc99_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc100_t = midi_cc10_t<NV>;

template <int NV>
using chain431_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc100_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc101_t = midi_cc10_t<NV>;

template <int NV>
using chain432_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc101_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi73_t = midi6_t<NV>;

template <int NV>
using chain433_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi73_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi74_t = midi7_t<NV>;

template <int NV>
using chain434_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi74_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi75_t = midi8_t<NV>;

template <int NV>
using chain435_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi75_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch36_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain429_t<NV>>, 
                                     chain430_t<NV>, 
                                     chain431_t<NV>, 
                                     chain432_t<NV>, 
                                     chain433_t<NV>, 
                                     chain434_t<NV>, 
                                     chain435_t<NV>>;

template <int NV>
using chain428_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch36_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split50_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain420_t<NV>>, 
                                   chain421_t<NV>, 
                                   chain422_t<NV>, 
                                   chain423_t<NV>, 
                                   chain424_t<NV>, 
                                   chain425_t<NV>, 
                                   chain427_t<NV>, 
                                   chain428_t<NV>>;

template <int NV> using xfader_c0 = sliderbank3_c0<NV>;

template <int NV> using xfader_c1 = sliderbank3_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::linear>;
template <int NV>
using pma33_t = control::pma<NV, 
                             parameter::plain<xfader_t<NV>, 0>>;
template <int NV>
using peak31_t = wrap::mod<parameter::plain<pma33_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain27_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank26_t<NV>>, 
                                       split50_t<NV>, 
                                       peak31_t<NV>, 
                                       pma33_t<NV>>;

template <int NV>
using modchain27_t = wrap::control_rate<modchain27_t_<NV>>;

template <int NV> using sliderbank25_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank25_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank25_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank25_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank25_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank25_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank25_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank25_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank25_multimod = parameter::list<sliderbank25_c0<NV>, 
                                              sliderbank25_c1<NV>, 
                                              sliderbank25_c2<NV>, 
                                              sliderbank25_c3<NV>, 
                                              sliderbank25_c4<NV>, 
                                              sliderbank25_c5<NV>, 
                                              sliderbank25_c6<NV>, 
                                              sliderbank25_c7<NV>>;

template <int NV>
using sliderbank25_t = wrap::data<control::sliderbank<sliderbank25_multimod<NV>>, 
                                  data::external::sliderpack<14>>;
using global_cable91_t_index = global_cable3_t_index;

template <int NV>
using global_cable91_t = routing::global_cable<global_cable91_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain405_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable91_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable92_t_index = global_cable11_t_index;

template <int NV>
using global_cable92_t = routing::global_cable<global_cable92_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain406_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable92_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable93_t_index = global_cable10_t_index;

template <int NV>
using global_cable93_t = routing::global_cable<global_cable93_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain407_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable93_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable94_t_index = global_cable14_t_index;

template <int NV>
using global_cable94_t = routing::global_cable<global_cable94_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain408_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable94_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader76_t = event_data_reader11_t<NV>;

template <int NV>
using chain409_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader76_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader77_t = event_data_reader11_t<NV>;

template <int NV>
using chain410_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader77_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader78_t = event_data_reader11_t<NV>;

template <int NV>
using chain411_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader78_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc94_t = midi_cc10_t<NV>;

template <int NV>
using chain413_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc94_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc95_t = midi_cc10_t<NV>;

template <int NV>
using chain414_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc95_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc96_t = midi_cc10_t<NV>;

template <int NV>
using chain415_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc96_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc97_t = midi_cc10_t<NV>;

template <int NV>
using chain416_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc97_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi70_t = midi6_t<NV>;

template <int NV>
using chain417_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi70_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi71_t = midi7_t<NV>;

template <int NV>
using chain418_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi71_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi72_t = midi8_t<NV>;

template <int NV>
using chain419_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi72_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch35_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain413_t<NV>>, 
                                     chain414_t<NV>, 
                                     chain415_t<NV>, 
                                     chain416_t<NV>, 
                                     chain417_t<NV>, 
                                     chain418_t<NV>, 
                                     chain419_t<NV>>;

template <int NV>
using chain412_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch35_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split49_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain405_t<NV>>, 
                                   chain406_t<NV>, 
                                   chain407_t<NV>, 
                                   chain408_t<NV>, 
                                   chain409_t<NV>, 
                                   chain410_t<NV>, 
                                   chain411_t<NV>, 
                                   chain412_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(cable_table3_modRange, 
                             0., 
                             100., 
                             0.01);

template <int NV>
using cable_table3_mod = parameter::from0To1<project::Comb<NV>, 
                                             1, 
                                             cable_table3_modRange>;

struct cable_table3_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998043f, 0.996086f, 0.994129f, 0.992172f, 0.990215f,
		0.988258f, 0.986301f, 0.984344f, 0.982387f, 0.980431f, 0.978474f,
		0.976517f, 0.97456f, 0.972603f, 0.970646f, 0.968689f, 0.966732f,
		0.964775f, 0.962818f, 0.960861f, 0.958904f, 0.956947f, 0.95499f,
		0.953033f, 0.951076f, 0.949119f, 0.947162f, 0.945205f, 0.943249f,
		0.941292f, 0.939335f, 0.937378f, 0.935421f, 0.933464f, 0.931507f,
		0.92955f, 0.927593f, 0.925636f, 0.923679f, 0.921722f, 0.919765f,
		0.917808f, 0.915851f, 0.913894f, 0.911937f, 0.90998f, 0.908023f,
		0.906067f, 0.90411f, 0.902153f, 0.900196f, 0.898239f, 0.896282f,
		0.894325f, 0.892368f, 0.890411f, 0.888454f, 0.886497f, 0.88454f,
		0.882583f, 0.880626f, 0.878669f, 0.876712f, 0.874755f, 0.872798f,
		0.870842f, 0.868885f, 0.866928f, 0.864971f, 0.863014f, 0.861057f,
		0.8591f, 0.857143f, 0.855186f, 0.853229f, 0.851272f, 0.849315f,
		0.847358f, 0.845401f, 0.843444f, 0.841487f, 0.83953f, 0.837573f,
		0.835616f, 0.833659f, 0.831703f, 0.829746f, 0.827789f, 0.825832f,
		0.823875f, 0.821918f, 0.819961f, 0.818004f, 0.816047f, 0.81409f,
		0.812133f, 0.810176f, 0.808219f, 0.806262f, 0.804305f, 0.802348f,
		0.800391f, 0.798434f, 0.796477f, 0.794521f, 0.792564f, 0.790607f,
		0.78865f, 0.786693f, 0.784736f, 0.782779f, 0.780822f, 0.778865f,
		0.776908f, 0.774951f, 0.772994f, 0.771037f, 0.76908f, 0.767123f,
		0.765166f, 0.763209f, 0.761252f, 0.759295f, 0.757339f, 0.755382f,
		0.753425f, 0.751468f, 0.749511f, 0.747554f, 0.745597f, 0.74364f,
		0.741683f, 0.739726f, 0.737769f, 0.735812f, 0.733855f, 0.731898f,
		0.729941f, 0.727984f, 0.726027f, 0.72407f, 0.722113f, 0.720157f,
		0.7182f, 0.716243f, 0.714286f, 0.712329f, 0.710372f, 0.708415f,
		0.706458f, 0.704501f, 0.702544f, 0.700587f, 0.69863f, 0.696673f,
		0.694716f, 0.692759f, 0.690802f, 0.688845f, 0.686888f, 0.684932f,
		0.682975f, 0.681018f, 0.679061f, 0.677104f, 0.675147f, 0.67319f,
		0.671233f, 0.669276f, 0.667319f, 0.665362f, 0.663405f, 0.661448f,
		0.659491f, 0.657534f, 0.655577f, 0.65362f, 0.651663f, 0.649706f,
		0.64775f, 0.645793f, 0.643836f, 0.641879f, 0.639922f, 0.637965f,
		0.636008f, 0.634051f, 0.632094f, 0.630137f, 0.62818f, 0.626223f,
		0.624266f, 0.622309f, 0.620352f, 0.618395f, 0.616438f, 0.614481f,
		0.612524f, 0.610568f, 0.608611f, 0.606654f, 0.604697f, 0.60274f,
		0.600783f, 0.598826f, 0.596869f, 0.594912f, 0.592955f, 0.590998f,
		0.589041f, 0.587084f, 0.585127f, 0.58317f, 0.581213f, 0.579256f,
		0.577299f, 0.575342f, 0.573385f, 0.571429f, 0.569472f, 0.567515f,
		0.565558f, 0.563601f, 0.561644f, 0.559687f, 0.55773f, 0.555773f,
		0.553816f, 0.551859f, 0.549902f, 0.547945f, 0.545988f, 0.544031f,
		0.542074f, 0.540117f, 0.53816f, 0.536204f, 0.534247f, 0.53229f,
		0.530333f, 0.528376f, 0.526419f, 0.524462f, 0.522505f, 0.520548f,
		0.518591f, 0.516634f, 0.514677f, 0.51272f, 0.510763f, 0.508806f,
		0.506849f, 0.504892f, 0.502935f, 0.500978f, 0.499022f, 0.497065f,
		0.495108f, 0.493151f, 0.491194f, 0.489237f, 0.48728f, 0.485323f,
		0.483366f, 0.481409f, 0.479452f, 0.477495f, 0.475538f, 0.473581f,
		0.471624f, 0.469667f, 0.46771f, 0.465753f, 0.463796f, 0.46184f,
		0.459883f, 0.457926f, 0.455969f, 0.454012f, 0.452055f, 0.450098f,
		0.448141f, 0.446184f, 0.444227f, 0.44227f, 0.440313f, 0.438356f,
		0.436399f, 0.434442f, 0.432485f, 0.430528f, 0.428571f, 0.426614f,
		0.424658f, 0.422701f, 0.420744f, 0.418787f, 0.41683f, 0.414873f,
		0.412916f, 0.410959f, 0.409002f, 0.407045f, 0.405088f, 0.403131f,
		0.401174f, 0.399217f, 0.39726f, 0.395303f, 0.393346f, 0.391389f,
		0.389432f, 0.387476f, 0.385519f, 0.383562f, 0.381605f, 0.379648f,
		0.377691f, 0.375734f, 0.373777f, 0.37182f, 0.369863f, 0.367906f,
		0.365949f, 0.363992f, 0.362035f, 0.360078f, 0.358121f, 0.356164f,
		0.354207f, 0.352251f, 0.350294f, 0.348337f, 0.34638f, 0.344423f,
		0.342466f, 0.340509f, 0.338552f, 0.336595f, 0.334638f, 0.332681f,
		0.330724f, 0.328767f, 0.32681f, 0.324853f, 0.322896f, 0.320939f,
		0.318982f, 0.317025f, 0.315068f, 0.313112f, 0.311155f, 0.309198f,
		0.307241f, 0.305284f, 0.303327f, 0.30137f, 0.299413f, 0.297456f,
		0.295499f, 0.293542f, 0.291585f, 0.289628f, 0.287671f, 0.285714f,
		0.283757f, 0.2818f, 0.279843f, 0.277887f, 0.27593f, 0.273973f,
		0.272016f, 0.270059f, 0.268102f, 0.266145f, 0.264188f, 0.262231f,
		0.260274f, 0.258317f, 0.25636f, 0.254403f, 0.252446f, 0.250489f,
		0.248532f, 0.246575f, 0.244618f, 0.242661f, 0.240704f, 0.238748f,
		0.236791f, 0.234834f, 0.232877f, 0.23092f, 0.228963f, 0.227006f,
		0.225049f, 0.223092f, 0.221135f, 0.219178f, 0.217221f, 0.215264f,
		0.213307f, 0.21135f, 0.209393f, 0.207436f, 0.205479f, 0.203523f,
		0.201566f, 0.199609f, 0.197652f, 0.195695f, 0.193738f, 0.191781f,
		0.189824f, 0.187867f, 0.18591f, 0.183953f, 0.181996f, 0.180039f,
		0.178082f, 0.176125f, 0.174168f, 0.172211f, 0.170254f, 0.168297f,
		0.166341f, 0.164384f, 0.162427f, 0.16047f, 0.158513f, 0.156556f,
		0.154599f, 0.152642f, 0.150685f, 0.148728f, 0.146771f, 0.144814f,
		0.142857f, 0.1409f, 0.138943f, 0.136986f, 0.135029f, 0.133072f,
		0.131115f, 0.129158f, 0.127202f, 0.125245f, 0.123288f, 0.121331f,
		0.119374f, 0.117417f, 0.11546f, 0.113503f, 0.111546f, 0.109589f,
		0.107632f, 0.105675f, 0.103718f, 0.101761f, 0.0998043f, 0.0978474f,
		0.0958903f, 0.0939335f, 0.0919765f, 0.0900196f, 0.0880627f, 0.0861056f,
		0.0841488f, 0.0821917f, 0.0802348f, 0.0782779f, 0.0763209f, 0.0743641f,
		0.072407f, 0.0704501f, 0.0684931f, 0.0665362f, 0.0645792f, 0.0626223f,
		0.0606654f, 0.0587084f, 0.0567515f, 0.0547945f, 0.0528376f, 0.0508806f,
		0.0489237f, 0.0469668f, 0.0450097f, 0.0430529f, 0.0410959f, 0.039139f,
		0.037182f, 0.035225f, 0.0332682f, 0.0313111f, 0.0293542f, 0.0273973f,
		0.0254403f, 0.0234835f, 0.0215264f, 0.0195695f, 0.0176125f, 0.0156556f,
		0.0136986f, 0.0117417f, 0.00978482f, 0.00782776f, 0.00587088f, 0.00391382f,
		0.00195694f, 0.f
	};
};

template <int NV>
using cable_table3_t = wrap::data<control::cable_table<cable_table3_mod<NV>>, 
                                  data::embedded::table<cable_table3_t_data>>;

template <int NV> using cable_table_mod = cable_table3_mod<NV>;

struct cable_table_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998043f, 0.996086f, 0.994129f, 0.992172f, 0.990215f,
		0.988258f, 0.986301f, 0.984344f, 0.982387f, 0.980431f, 0.978474f,
		0.976517f, 0.97456f, 0.972603f, 0.970646f, 0.968689f, 0.966732f,
		0.964775f, 0.962818f, 0.960861f, 0.958904f, 0.956947f, 0.95499f,
		0.953033f, 0.951076f, 0.949119f, 0.947162f, 0.945205f, 0.943249f,
		0.941292f, 0.939335f, 0.937378f, 0.935421f, 0.933464f, 0.931507f,
		0.92955f, 0.927593f, 0.925636f, 0.923679f, 0.921722f, 0.919765f,
		0.917808f, 0.915851f, 0.913894f, 0.911937f, 0.90998f, 0.908023f,
		0.906067f, 0.90411f, 0.902153f, 0.900196f, 0.898239f, 0.896282f,
		0.894325f, 0.892368f, 0.890411f, 0.888454f, 0.886497f, 0.88454f,
		0.882583f, 0.880626f, 0.878669f, 0.876712f, 0.874755f, 0.872798f,
		0.870842f, 0.868885f, 0.866928f, 0.864971f, 0.863014f, 0.861057f,
		0.8591f, 0.857143f, 0.855186f, 0.853229f, 0.851272f, 0.849315f,
		0.847358f, 0.845401f, 0.843444f, 0.841487f, 0.83953f, 0.837573f,
		0.835616f, 0.833659f, 0.831703f, 0.829746f, 0.827789f, 0.825832f,
		0.823875f, 0.821918f, 0.819961f, 0.818004f, 0.816047f, 0.81409f,
		0.812133f, 0.810176f, 0.808219f, 0.806262f, 0.804305f, 0.802348f,
		0.800391f, 0.798434f, 0.796477f, 0.794521f, 0.792564f, 0.790607f,
		0.78865f, 0.786693f, 0.784736f, 0.782779f, 0.780822f, 0.778865f,
		0.776908f, 0.774951f, 0.772994f, 0.771037f, 0.76908f, 0.767123f,
		0.765166f, 0.763209f, 0.761252f, 0.759295f, 0.757339f, 0.755382f,
		0.753425f, 0.751468f, 0.749511f, 0.747554f, 0.745597f, 0.74364f,
		0.741683f, 0.739726f, 0.737769f, 0.735812f, 0.733855f, 0.731898f,
		0.729941f, 0.727984f, 0.726027f, 0.72407f, 0.722113f, 0.720157f,
		0.7182f, 0.716243f, 0.714286f, 0.712329f, 0.710372f, 0.708415f,
		0.706458f, 0.704501f, 0.702544f, 0.700587f, 0.69863f, 0.696673f,
		0.694716f, 0.692759f, 0.690802f, 0.688845f, 0.686888f, 0.684932f,
		0.682975f, 0.681018f, 0.679061f, 0.677104f, 0.675147f, 0.67319f,
		0.671233f, 0.669276f, 0.667319f, 0.665362f, 0.663405f, 0.661448f,
		0.659491f, 0.657534f, 0.655577f, 0.65362f, 0.651663f, 0.649706f,
		0.64775f, 0.645793f, 0.643836f, 0.641879f, 0.639922f, 0.637965f,
		0.636008f, 0.634051f, 0.632094f, 0.630137f, 0.62818f, 0.626223f,
		0.624266f, 0.622309f, 0.620352f, 0.618395f, 0.616438f, 0.614481f,
		0.612524f, 0.610568f, 0.608611f, 0.606654f, 0.604697f, 0.60274f,
		0.600783f, 0.598826f, 0.596869f, 0.594912f, 0.592955f, 0.590998f,
		0.589041f, 0.587084f, 0.585127f, 0.58317f, 0.581213f, 0.579256f,
		0.577299f, 0.575342f, 0.573385f, 0.571429f, 0.569472f, 0.567515f,
		0.565558f, 0.563601f, 0.561644f, 0.559687f, 0.55773f, 0.555773f,
		0.553816f, 0.551859f, 0.549902f, 0.547945f, 0.545988f, 0.544031f,
		0.542074f, 0.540117f, 0.53816f, 0.536204f, 0.534247f, 0.53229f,
		0.530333f, 0.528376f, 0.526419f, 0.524462f, 0.522505f, 0.520548f,
		0.518591f, 0.516634f, 0.514677f, 0.51272f, 0.510763f, 0.508806f,
		0.506849f, 0.504892f, 0.502935f, 0.500978f, 0.499022f, 0.497065f,
		0.495108f, 0.493151f, 0.491194f, 0.489237f, 0.48728f, 0.485323f,
		0.483366f, 0.481409f, 0.479452f, 0.477495f, 0.475538f, 0.473581f,
		0.471624f, 0.469667f, 0.46771f, 0.465753f, 0.463796f, 0.46184f,
		0.459883f, 0.457926f, 0.455969f, 0.454012f, 0.452055f, 0.450098f,
		0.448141f, 0.446184f, 0.444227f, 0.44227f, 0.440313f, 0.438356f,
		0.436399f, 0.434442f, 0.432485f, 0.430528f, 0.428571f, 0.426614f,
		0.424658f, 0.422701f, 0.420744f, 0.418787f, 0.41683f, 0.414873f,
		0.412916f, 0.410959f, 0.409002f, 0.407045f, 0.405088f, 0.403131f,
		0.401174f, 0.399217f, 0.39726f, 0.395303f, 0.393346f, 0.391389f,
		0.389432f, 0.387476f, 0.385519f, 0.383562f, 0.381605f, 0.379648f,
		0.377691f, 0.375734f, 0.373777f, 0.37182f, 0.369863f, 0.367906f,
		0.365949f, 0.363992f, 0.362035f, 0.360078f, 0.358121f, 0.356164f,
		0.354207f, 0.352251f, 0.350294f, 0.348337f, 0.34638f, 0.344423f,
		0.342466f, 0.340509f, 0.338552f, 0.336595f, 0.334638f, 0.332681f,
		0.330724f, 0.328767f, 0.32681f, 0.324853f, 0.322896f, 0.320939f,
		0.318982f, 0.317025f, 0.315068f, 0.313112f, 0.311155f, 0.309198f,
		0.307241f, 0.305284f, 0.303327f, 0.30137f, 0.299413f, 0.297456f,
		0.295499f, 0.293542f, 0.291585f, 0.289628f, 0.287671f, 0.285714f,
		0.283757f, 0.2818f, 0.279843f, 0.277887f, 0.27593f, 0.273973f,
		0.272016f, 0.270059f, 0.268102f, 0.266145f, 0.264188f, 0.262231f,
		0.260274f, 0.258317f, 0.25636f, 0.254403f, 0.252446f, 0.250489f,
		0.248532f, 0.246575f, 0.244618f, 0.242661f, 0.240704f, 0.238748f,
		0.236791f, 0.234834f, 0.232877f, 0.23092f, 0.228963f, 0.227006f,
		0.225049f, 0.223092f, 0.221135f, 0.219178f, 0.217221f, 0.215264f,
		0.213307f, 0.21135f, 0.209393f, 0.207436f, 0.205479f, 0.203523f,
		0.201566f, 0.199609f, 0.197652f, 0.195695f, 0.193738f, 0.191781f,
		0.189824f, 0.187867f, 0.18591f, 0.183953f, 0.181996f, 0.180039f,
		0.178082f, 0.176125f, 0.174168f, 0.172211f, 0.170254f, 0.168297f,
		0.166341f, 0.164384f, 0.162427f, 0.16047f, 0.158513f, 0.156556f,
		0.154599f, 0.152642f, 0.150685f, 0.148728f, 0.146771f, 0.144814f,
		0.142857f, 0.1409f, 0.138943f, 0.136986f, 0.135029f, 0.133072f,
		0.131115f, 0.129158f, 0.127202f, 0.125245f, 0.123288f, 0.121331f,
		0.119374f, 0.117417f, 0.11546f, 0.113503f, 0.111546f, 0.109589f,
		0.107632f, 0.105675f, 0.103718f, 0.101761f, 0.0998043f, 0.0978474f,
		0.0958903f, 0.0939335f, 0.0919765f, 0.0900196f, 0.0880627f, 0.0861056f,
		0.0841488f, 0.0821917f, 0.0802348f, 0.0782779f, 0.0763209f, 0.0743641f,
		0.072407f, 0.0704501f, 0.0684931f, 0.0665362f, 0.0645792f, 0.0626223f,
		0.0606654f, 0.0587084f, 0.0567515f, 0.0547945f, 0.0528376f, 0.0508806f,
		0.0489237f, 0.0469668f, 0.0450097f, 0.0430529f, 0.0410959f, 0.039139f,
		0.037182f, 0.035225f, 0.0332682f, 0.0313111f, 0.0293542f, 0.0273973f,
		0.0254403f, 0.0234835f, 0.0215264f, 0.0195695f, 0.0176125f, 0.0156556f,
		0.0136986f, 0.0117417f, 0.00978482f, 0.00782776f, 0.00587088f, 0.00391382f,
		0.00195694f, 0.f
	};
};

template <int NV>
using cable_table_t = wrap::data<control::cable_table<cable_table_mod<NV>>, 
                                 data::embedded::table<cable_table_t_data>>;

template <int NV>
using pma32_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<project::klp<NV>, 1>, 
                                   parameter::plain<project::klp<NV>, 1>, 
                                   parameter::plain<project::klp<NV>, 1>, 
                                   parameter::plain<project::klp<NV>, 1>, 
                                   parameter::plain<project::khp<NV>, 1>, 
                                   parameter::plain<cable_table3_t<NV>, 0>, 
                                   parameter::plain<cable_table_t<NV>, 0>>;

template <int NV>
using pma32_t = control::pma<NV, pma32_mod<NV>>;
template <int NV>
using peak30_t = wrap::mod<parameter::plain<pma32_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using pma37_t = control::pma<NV, 
                             parameter::plain<pma32_t<NV>, 2>>;

template <int NV>
using modchain26_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank25_t<NV>>, 
                                       split49_t<NV>, 
                                       peak30_t<NV>, 
                                       pma37_t<NV>, 
                                       pma32_t<NV>>;

template <int NV>
using modchain26_t = wrap::control_rate<modchain26_t_<NV>>;

template <int NV> using sliderbank27_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank27_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank27_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank27_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank27_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank27_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank27_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank27_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank27_multimod = parameter::list<sliderbank27_c0<NV>, 
                                              sliderbank27_c1<NV>, 
                                              sliderbank27_c2<NV>, 
                                              sliderbank27_c3<NV>, 
                                              sliderbank27_c4<NV>, 
                                              sliderbank27_c5<NV>, 
                                              sliderbank27_c6<NV>, 
                                              sliderbank27_c7<NV>>;

template <int NV>
using sliderbank27_t = wrap::data<control::sliderbank<sliderbank27_multimod<NV>>, 
                                  data::external::sliderpack<15>>;
using global_cable99_t_index = global_cable3_t_index;

template <int NV>
using global_cable99_t = routing::global_cable<global_cable99_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain436_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable99_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable100_t_index = global_cable11_t_index;

template <int NV>
using global_cable100_t = routing::global_cable<global_cable100_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain437_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable100_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable101_t_index = global_cable10_t_index;

template <int NV>
using global_cable101_t = routing::global_cable<global_cable101_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain438_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable101_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable102_t_index = global_cable14_t_index;

template <int NV>
using global_cable102_t = routing::global_cable<global_cable102_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain439_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable102_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader82_t = event_data_reader11_t<NV>;

template <int NV>
using chain440_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader82_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader83_t = event_data_reader11_t<NV>;

template <int NV>
using chain441_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader83_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader84_t = event_data_reader11_t<NV>;

template <int NV>
using chain442_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader84_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc102_t = midi_cc10_t<NV>;

template <int NV>
using chain444_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc102_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc103_t = midi_cc10_t<NV>;

template <int NV>
using chain445_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc103_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc104_t = midi_cc10_t<NV>;

template <int NV>
using chain446_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc104_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc105_t = midi_cc10_t<NV>;

template <int NV>
using chain447_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc105_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi76_t = midi6_t<NV>;

template <int NV>
using chain448_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi76_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi77_t = midi7_t<NV>;

template <int NV>
using chain449_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi77_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi78_t = midi8_t<NV>;

template <int NV>
using chain450_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi78_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch37_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain444_t<NV>>, 
                                     chain445_t<NV>, 
                                     chain446_t<NV>, 
                                     chain447_t<NV>, 
                                     chain448_t<NV>, 
                                     chain449_t<NV>, 
                                     chain450_t<NV>>;

template <int NV>
using chain443_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch37_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split51_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain436_t<NV>>, 
                                   chain437_t<NV>, 
                                   chain438_t<NV>, 
                                   chain439_t<NV>, 
                                   chain440_t<NV>, 
                                   chain441_t<NV>, 
                                   chain442_t<NV>, 
                                   chain443_t<NV>>;

template <int NV> using cable_table4_mod = cable_table3_mod<NV>;

struct cable_table4_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998043f, 0.996086f, 0.994129f, 0.992172f, 0.990215f,
		0.988258f, 0.986301f, 0.984344f, 0.982387f, 0.980431f, 0.978474f,
		0.976517f, 0.97456f, 0.972603f, 0.970646f, 0.968689f, 0.966732f,
		0.964775f, 0.962818f, 0.960861f, 0.958904f, 0.956947f, 0.95499f,
		0.953033f, 0.951076f, 0.949119f, 0.947162f, 0.945205f, 0.943249f,
		0.941292f, 0.939335f, 0.937378f, 0.935421f, 0.933464f, 0.931507f,
		0.92955f, 0.927593f, 0.925636f, 0.923679f, 0.921722f, 0.919765f,
		0.917808f, 0.915851f, 0.913894f, 0.911937f, 0.90998f, 0.908023f,
		0.906067f, 0.90411f, 0.902153f, 0.900196f, 0.898239f, 0.896282f,
		0.894325f, 0.892368f, 0.890411f, 0.888454f, 0.886497f, 0.88454f,
		0.882583f, 0.880626f, 0.878669f, 0.876712f, 0.874755f, 0.872798f,
		0.870842f, 0.868885f, 0.866928f, 0.864971f, 0.863014f, 0.861057f,
		0.8591f, 0.857143f, 0.855186f, 0.853229f, 0.851272f, 0.849315f,
		0.847358f, 0.845401f, 0.843444f, 0.841487f, 0.83953f, 0.837573f,
		0.835616f, 0.833659f, 0.831703f, 0.829746f, 0.827789f, 0.825832f,
		0.823875f, 0.821918f, 0.819961f, 0.818004f, 0.816047f, 0.81409f,
		0.812133f, 0.810176f, 0.808219f, 0.806262f, 0.804305f, 0.802348f,
		0.800391f, 0.798434f, 0.796477f, 0.794521f, 0.792564f, 0.790607f,
		0.78865f, 0.786693f, 0.784736f, 0.782779f, 0.780822f, 0.778865f,
		0.776908f, 0.774951f, 0.772994f, 0.771037f, 0.76908f, 0.767123f,
		0.765166f, 0.763209f, 0.761252f, 0.759295f, 0.757339f, 0.755382f,
		0.753425f, 0.751468f, 0.749511f, 0.747554f, 0.745597f, 0.74364f,
		0.741683f, 0.739726f, 0.737769f, 0.735812f, 0.733855f, 0.731898f,
		0.729941f, 0.727984f, 0.726027f, 0.72407f, 0.722113f, 0.720157f,
		0.7182f, 0.716243f, 0.714286f, 0.712329f, 0.710372f, 0.708415f,
		0.706458f, 0.704501f, 0.702544f, 0.700587f, 0.69863f, 0.696673f,
		0.694716f, 0.692759f, 0.690802f, 0.688845f, 0.686888f, 0.684932f,
		0.682975f, 0.681018f, 0.679061f, 0.677104f, 0.675147f, 0.67319f,
		0.671233f, 0.669276f, 0.667319f, 0.665362f, 0.663405f, 0.661448f,
		0.659491f, 0.657534f, 0.655577f, 0.65362f, 0.651663f, 0.649706f,
		0.64775f, 0.645793f, 0.643836f, 0.641879f, 0.639922f, 0.637965f,
		0.636008f, 0.634051f, 0.632094f, 0.630137f, 0.62818f, 0.626223f,
		0.624266f, 0.622309f, 0.620352f, 0.618395f, 0.616438f, 0.614481f,
		0.612524f, 0.610568f, 0.608611f, 0.606654f, 0.604697f, 0.60274f,
		0.600783f, 0.598826f, 0.596869f, 0.594912f, 0.592955f, 0.590998f,
		0.589041f, 0.587084f, 0.585127f, 0.58317f, 0.581213f, 0.579256f,
		0.577299f, 0.575342f, 0.573385f, 0.571429f, 0.569472f, 0.567515f,
		0.565558f, 0.563601f, 0.561644f, 0.559687f, 0.55773f, 0.555773f,
		0.553816f, 0.551859f, 0.549902f, 0.547945f, 0.545988f, 0.544031f,
		0.542074f, 0.540117f, 0.53816f, 0.536204f, 0.534247f, 0.53229f,
		0.530333f, 0.528376f, 0.526419f, 0.524462f, 0.522505f, 0.520548f,
		0.518591f, 0.516634f, 0.514677f, 0.51272f, 0.510763f, 0.508806f,
		0.506849f, 0.504892f, 0.502935f, 0.500978f, 0.499022f, 0.497065f,
		0.495108f, 0.493151f, 0.491194f, 0.489237f, 0.48728f, 0.485323f,
		0.483366f, 0.481409f, 0.479452f, 0.477495f, 0.475538f, 0.473581f,
		0.471624f, 0.469667f, 0.46771f, 0.465753f, 0.463796f, 0.46184f,
		0.459883f, 0.457926f, 0.455969f, 0.454012f, 0.452055f, 0.450098f,
		0.448141f, 0.446184f, 0.444227f, 0.44227f, 0.440313f, 0.438356f,
		0.436399f, 0.434442f, 0.432485f, 0.430528f, 0.428571f, 0.426614f,
		0.424658f, 0.422701f, 0.420744f, 0.418787f, 0.41683f, 0.414873f,
		0.412916f, 0.410959f, 0.409002f, 0.407045f, 0.405088f, 0.403131f,
		0.401174f, 0.399217f, 0.39726f, 0.395303f, 0.393346f, 0.391389f,
		0.389432f, 0.387476f, 0.385519f, 0.383562f, 0.381605f, 0.379648f,
		0.377691f, 0.375734f, 0.373777f, 0.37182f, 0.369863f, 0.367906f,
		0.365949f, 0.363992f, 0.362035f, 0.360078f, 0.358121f, 0.356164f,
		0.354207f, 0.352251f, 0.350294f, 0.348337f, 0.34638f, 0.344423f,
		0.342466f, 0.340509f, 0.338552f, 0.336595f, 0.334638f, 0.332681f,
		0.330724f, 0.328767f, 0.32681f, 0.324853f, 0.322896f, 0.320939f,
		0.318982f, 0.317025f, 0.315068f, 0.313112f, 0.311155f, 0.309198f,
		0.307241f, 0.305284f, 0.303327f, 0.30137f, 0.299413f, 0.297456f,
		0.295499f, 0.293542f, 0.291585f, 0.289628f, 0.287671f, 0.285714f,
		0.283757f, 0.2818f, 0.279843f, 0.277887f, 0.27593f, 0.273973f,
		0.272016f, 0.270059f, 0.268102f, 0.266145f, 0.264188f, 0.262231f,
		0.260274f, 0.258317f, 0.25636f, 0.254403f, 0.252446f, 0.250489f,
		0.248532f, 0.246575f, 0.244618f, 0.242661f, 0.240704f, 0.238748f,
		0.236791f, 0.234834f, 0.232877f, 0.23092f, 0.228963f, 0.227006f,
		0.225049f, 0.223092f, 0.221135f, 0.219178f, 0.217221f, 0.215264f,
		0.213307f, 0.21135f, 0.209393f, 0.207436f, 0.205479f, 0.203523f,
		0.201566f, 0.199609f, 0.197652f, 0.195695f, 0.193738f, 0.191781f,
		0.189824f, 0.187867f, 0.18591f, 0.183953f, 0.181996f, 0.180039f,
		0.178082f, 0.176125f, 0.174168f, 0.172211f, 0.170254f, 0.168297f,
		0.166341f, 0.164384f, 0.162427f, 0.16047f, 0.158513f, 0.156556f,
		0.154599f, 0.152642f, 0.150685f, 0.148728f, 0.146771f, 0.144814f,
		0.142857f, 0.1409f, 0.138943f, 0.136986f, 0.135029f, 0.133072f,
		0.131115f, 0.129158f, 0.127202f, 0.125245f, 0.123288f, 0.121331f,
		0.119374f, 0.117417f, 0.11546f, 0.113503f, 0.111546f, 0.109589f,
		0.107632f, 0.105675f, 0.103718f, 0.101761f, 0.0998043f, 0.0978474f,
		0.0958903f, 0.0939335f, 0.0919765f, 0.0900196f, 0.0880627f, 0.0861056f,
		0.0841488f, 0.0821917f, 0.0802348f, 0.0782779f, 0.0763209f, 0.0743641f,
		0.072407f, 0.0704501f, 0.0684931f, 0.0665362f, 0.0645792f, 0.0626223f,
		0.0606654f, 0.0587084f, 0.0567515f, 0.0547945f, 0.0528376f, 0.0508806f,
		0.0489237f, 0.0469668f, 0.0450097f, 0.0430529f, 0.0410959f, 0.039139f,
		0.037182f, 0.035225f, 0.0332682f, 0.0313111f, 0.0293542f, 0.0273973f,
		0.0254403f, 0.0234835f, 0.0215264f, 0.0195695f, 0.0176125f, 0.0156556f,
		0.0136986f, 0.0117417f, 0.00978482f, 0.00782776f, 0.00587088f, 0.00391382f,
		0.00195694f, 0.f
	};
};

template <int NV>
using cable_table4_t = wrap::data<control::cable_table<cable_table4_mod<NV>>, 
                                  data::embedded::table<cable_table4_t_data>>;

template <int NV> using cable_table2_mod = cable_table3_mod<NV>;

struct cable_table2_t_data
{
	span<float, 512> data =
	{
		1.f, 0.998043f, 0.996086f, 0.994129f, 0.992172f, 0.990215f,
		0.988258f, 0.986301f, 0.984344f, 0.982387f, 0.980431f, 0.978474f,
		0.976517f, 0.97456f, 0.972603f, 0.970646f, 0.968689f, 0.966732f,
		0.964775f, 0.962818f, 0.960861f, 0.958904f, 0.956947f, 0.95499f,
		0.953033f, 0.951076f, 0.949119f, 0.947162f, 0.945205f, 0.943249f,
		0.941292f, 0.939335f, 0.937378f, 0.935421f, 0.933464f, 0.931507f,
		0.92955f, 0.927593f, 0.925636f, 0.923679f, 0.921722f, 0.919765f,
		0.917808f, 0.915851f, 0.913894f, 0.911937f, 0.90998f, 0.908023f,
		0.906067f, 0.90411f, 0.902153f, 0.900196f, 0.898239f, 0.896282f,
		0.894325f, 0.892368f, 0.890411f, 0.888454f, 0.886497f, 0.88454f,
		0.882583f, 0.880626f, 0.878669f, 0.876712f, 0.874755f, 0.872798f,
		0.870842f, 0.868885f, 0.866928f, 0.864971f, 0.863014f, 0.861057f,
		0.8591f, 0.857143f, 0.855186f, 0.853229f, 0.851272f, 0.849315f,
		0.847358f, 0.845401f, 0.843444f, 0.841487f, 0.83953f, 0.837573f,
		0.835616f, 0.833659f, 0.831703f, 0.829746f, 0.827789f, 0.825832f,
		0.823875f, 0.821918f, 0.819961f, 0.818004f, 0.816047f, 0.81409f,
		0.812133f, 0.810176f, 0.808219f, 0.806262f, 0.804305f, 0.802348f,
		0.800391f, 0.798434f, 0.796477f, 0.794521f, 0.792564f, 0.790607f,
		0.78865f, 0.786693f, 0.784736f, 0.782779f, 0.780822f, 0.778865f,
		0.776908f, 0.774951f, 0.772994f, 0.771037f, 0.76908f, 0.767123f,
		0.765166f, 0.763209f, 0.761252f, 0.759295f, 0.757339f, 0.755382f,
		0.753425f, 0.751468f, 0.749511f, 0.747554f, 0.745597f, 0.74364f,
		0.741683f, 0.739726f, 0.737769f, 0.735812f, 0.733855f, 0.731898f,
		0.729941f, 0.727984f, 0.726027f, 0.72407f, 0.722113f, 0.720157f,
		0.7182f, 0.716243f, 0.714286f, 0.712329f, 0.710372f, 0.708415f,
		0.706458f, 0.704501f, 0.702544f, 0.700587f, 0.69863f, 0.696673f,
		0.694716f, 0.692759f, 0.690802f, 0.688845f, 0.686888f, 0.684932f,
		0.682975f, 0.681018f, 0.679061f, 0.677104f, 0.675147f, 0.67319f,
		0.671233f, 0.669276f, 0.667319f, 0.665362f, 0.663405f, 0.661448f,
		0.659491f, 0.657534f, 0.655577f, 0.65362f, 0.651663f, 0.649706f,
		0.64775f, 0.645793f, 0.643836f, 0.641879f, 0.639922f, 0.637965f,
		0.636008f, 0.634051f, 0.632094f, 0.630137f, 0.62818f, 0.626223f,
		0.624266f, 0.622309f, 0.620352f, 0.618395f, 0.616438f, 0.614481f,
		0.612524f, 0.610568f, 0.608611f, 0.606654f, 0.604697f, 0.60274f,
		0.600783f, 0.598826f, 0.596869f, 0.594912f, 0.592955f, 0.590998f,
		0.589041f, 0.587084f, 0.585127f, 0.58317f, 0.581213f, 0.579256f,
		0.577299f, 0.575342f, 0.573385f, 0.571429f, 0.569472f, 0.567515f,
		0.565558f, 0.563601f, 0.561644f, 0.559687f, 0.55773f, 0.555773f,
		0.553816f, 0.551859f, 0.549902f, 0.547945f, 0.545988f, 0.544031f,
		0.542074f, 0.540117f, 0.53816f, 0.536204f, 0.534247f, 0.53229f,
		0.530333f, 0.528376f, 0.526419f, 0.524462f, 0.522505f, 0.520548f,
		0.518591f, 0.516634f, 0.514677f, 0.51272f, 0.510763f, 0.508806f,
		0.506849f, 0.504892f, 0.502935f, 0.500978f, 0.499022f, 0.497065f,
		0.495108f, 0.493151f, 0.491194f, 0.489237f, 0.48728f, 0.485323f,
		0.483366f, 0.481409f, 0.479452f, 0.477495f, 0.475538f, 0.473581f,
		0.471624f, 0.469667f, 0.46771f, 0.465753f, 0.463796f, 0.46184f,
		0.459883f, 0.457926f, 0.455969f, 0.454012f, 0.452055f, 0.450098f,
		0.448141f, 0.446184f, 0.444227f, 0.44227f, 0.440313f, 0.438356f,
		0.436399f, 0.434442f, 0.432485f, 0.430528f, 0.428571f, 0.426614f,
		0.424658f, 0.422701f, 0.420744f, 0.418787f, 0.41683f, 0.414873f,
		0.412916f, 0.410959f, 0.409002f, 0.407045f, 0.405088f, 0.403131f,
		0.401174f, 0.399217f, 0.39726f, 0.395303f, 0.393346f, 0.391389f,
		0.389432f, 0.387476f, 0.385519f, 0.383562f, 0.381605f, 0.379648f,
		0.377691f, 0.375734f, 0.373777f, 0.37182f, 0.369863f, 0.367906f,
		0.365949f, 0.363992f, 0.362035f, 0.360078f, 0.358121f, 0.356164f,
		0.354207f, 0.352251f, 0.350294f, 0.348337f, 0.34638f, 0.344423f,
		0.342466f, 0.340509f, 0.338552f, 0.336595f, 0.334638f, 0.332681f,
		0.330724f, 0.328767f, 0.32681f, 0.324853f, 0.322896f, 0.320939f,
		0.318982f, 0.317025f, 0.315068f, 0.313112f, 0.311155f, 0.309198f,
		0.307241f, 0.305284f, 0.303327f, 0.30137f, 0.299413f, 0.297456f,
		0.295499f, 0.293542f, 0.291585f, 0.289628f, 0.287671f, 0.285714f,
		0.283757f, 0.2818f, 0.279843f, 0.277887f, 0.27593f, 0.273973f,
		0.272016f, 0.270059f, 0.268102f, 0.266145f, 0.264188f, 0.262231f,
		0.260274f, 0.258317f, 0.25636f, 0.254403f, 0.252446f, 0.250489f,
		0.248532f, 0.246575f, 0.244618f, 0.242661f, 0.240704f, 0.238748f,
		0.236791f, 0.234834f, 0.232877f, 0.23092f, 0.228963f, 0.227006f,
		0.225049f, 0.223092f, 0.221135f, 0.219178f, 0.217221f, 0.215264f,
		0.213307f, 0.21135f, 0.209393f, 0.207436f, 0.205479f, 0.203523f,
		0.201566f, 0.199609f, 0.197652f, 0.195695f, 0.193738f, 0.191781f,
		0.189824f, 0.187867f, 0.18591f, 0.183953f, 0.181996f, 0.180039f,
		0.178082f, 0.176125f, 0.174168f, 0.172211f, 0.170254f, 0.168297f,
		0.166341f, 0.164384f, 0.162427f, 0.16047f, 0.158513f, 0.156556f,
		0.154599f, 0.152642f, 0.150685f, 0.148728f, 0.146771f, 0.144814f,
		0.142857f, 0.1409f, 0.138943f, 0.136986f, 0.135029f, 0.133072f,
		0.131115f, 0.129158f, 0.127202f, 0.125245f, 0.123288f, 0.121331f,
		0.119374f, 0.117417f, 0.11546f, 0.113503f, 0.111546f, 0.109589f,
		0.107632f, 0.105675f, 0.103718f, 0.101761f, 0.0998043f, 0.0978474f,
		0.0958903f, 0.0939335f, 0.0919765f, 0.0900196f, 0.0880627f, 0.0861056f,
		0.0841488f, 0.0821917f, 0.0802348f, 0.0782779f, 0.0763209f, 0.0743641f,
		0.072407f, 0.0704501f, 0.0684931f, 0.0665362f, 0.0645792f, 0.0626223f,
		0.0606654f, 0.0587084f, 0.0567515f, 0.0547945f, 0.0528376f, 0.0508806f,
		0.0489237f, 0.0469668f, 0.0450097f, 0.0430529f, 0.0410959f, 0.039139f,
		0.037182f, 0.035225f, 0.0332682f, 0.0313111f, 0.0293542f, 0.0273973f,
		0.0254403f, 0.0234835f, 0.0215264f, 0.0195695f, 0.0176125f, 0.0156556f,
		0.0136986f, 0.0117417f, 0.00978482f, 0.00782776f, 0.00587088f, 0.00391382f,
		0.00195694f, 0.f
	};
};

template <int NV>
using cable_table2_t = wrap::data<control::cable_table<cable_table2_mod<NV>>, 
                                  data::embedded::table<cable_table2_t_data>>;

template <int NV>
using pma34_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<project::khp2<NV>, 1>, 
                                   parameter::plain<project::khp2<NV>, 1>, 
                                   parameter::plain<project::klp<NV>, 1>, 
                                   parameter::plain<project::klp<NV>, 1>, 
                                   parameter::plain<project::khp<NV>, 1>, 
                                   parameter::plain<cable_table4_t<NV>, 0>, 
                                   parameter::plain<cable_table2_t<NV>, 0>>;

template <int NV>
using pma34_t = control::pma<NV, pma34_mod<NV>>;
template <int NV>
using peak32_t = wrap::mod<parameter::plain<pma34_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using pma38_t = control::pma<NV, 
                             parameter::plain<pma34_t<NV>, 2>>;

template <int NV>
using modchain28_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank27_t<NV>>, 
                                       split51_t<NV>, 
                                       peak32_t<NV>, 
                                       pma38_t<NV>, 
                                       pma34_t<NV>>;

template <int NV>
using modchain28_t = wrap::control_rate<modchain28_t_<NV>>;

template <int NV> using sliderbank28_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank28_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank28_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank28_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank28_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank28_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank28_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank28_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank28_multimod = parameter::list<sliderbank28_c0<NV>, 
                                              sliderbank28_c1<NV>, 
                                              sliderbank28_c2<NV>, 
                                              sliderbank28_c3<NV>, 
                                              sliderbank28_c4<NV>, 
                                              sliderbank28_c5<NV>, 
                                              sliderbank28_c6<NV>, 
                                              sliderbank28_c7<NV>>;

template <int NV>
using sliderbank28_t = wrap::data<control::sliderbank<sliderbank28_multimod<NV>>, 
                                  data::external::sliderpack<16>>;
using global_cable103_t_index = global_cable3_t_index;

template <int NV>
using global_cable103_t = routing::global_cable<global_cable103_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain451_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable103_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable104_t_index = global_cable11_t_index;

template <int NV>
using global_cable104_t = routing::global_cable<global_cable104_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain452_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable104_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable105_t_index = global_cable10_t_index;

template <int NV>
using global_cable105_t = routing::global_cable<global_cable105_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain453_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable105_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable106_t_index = global_cable14_t_index;

template <int NV>
using global_cable106_t = routing::global_cable<global_cable106_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain454_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable106_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader85_t = event_data_reader11_t<NV>;

template <int NV>
using chain455_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader85_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader86_t = event_data_reader11_t<NV>;

template <int NV>
using chain456_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader86_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader87_t = event_data_reader11_t<NV>;

template <int NV>
using chain457_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader87_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc106_t = midi_cc10_t<NV>;

template <int NV>
using chain459_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc106_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc107_t = midi_cc10_t<NV>;

template <int NV>
using chain460_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc107_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc108_t = midi_cc10_t<NV>;

template <int NV>
using chain461_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc108_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc109_t = midi_cc10_t<NV>;

template <int NV>
using chain462_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc109_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi79_t = midi6_t<NV>;

template <int NV>
using chain463_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi79_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi80_t = midi7_t<NV>;

template <int NV>
using chain464_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi80_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi81_t = midi8_t<NV>;

template <int NV>
using chain465_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi81_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch38_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain459_t<NV>>, 
                                     chain460_t<NV>, 
                                     chain461_t<NV>, 
                                     chain462_t<NV>, 
                                     chain463_t<NV>, 
                                     chain464_t<NV>, 
                                     chain465_t<NV>>;

template <int NV>
using chain458_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch38_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split52_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain451_t<NV>>, 
                                   chain452_t<NV>, 
                                   chain453_t<NV>, 
                                   chain454_t<NV>, 
                                   chain455_t<NV>, 
                                   chain456_t<NV>, 
                                   chain457_t<NV>, 
                                   chain458_t<NV>>;
using peak33_t = wrap::no_data<core::peak>;

template <int NV> using pma_mod = sliderbank3_c0<NV>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
template <int NV>
using pma39_t = control::pma<NV, 
                             parameter::plain<pma_t<NV>, 2>>;

template <int NV>
using modchain29_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank28_t<NV>>, 
                                       split52_t<NV>, 
                                       peak33_t, 
                                       pma39_t<NV>>;

template <int NV>
using modchain29_t = wrap::control_rate<modchain29_t_<NV>>;

template <int NV> using sliderbank29_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank29_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank29_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank29_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank29_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank29_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank29_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank29_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank29_multimod = parameter::list<sliderbank29_c0<NV>, 
                                              sliderbank29_c1<NV>, 
                                              sliderbank29_c2<NV>, 
                                              sliderbank29_c3<NV>, 
                                              sliderbank29_c4<NV>, 
                                              sliderbank29_c5<NV>, 
                                              sliderbank29_c6<NV>, 
                                              sliderbank29_c7<NV>>;

template <int NV>
using sliderbank29_t = wrap::data<control::sliderbank<sliderbank29_multimod<NV>>, 
                                  data::external::sliderpack<17>>;
using global_cable107_t_index = global_cable3_t_index;

template <int NV>
using global_cable107_t = routing::global_cable<global_cable107_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain466_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable107_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable108_t_index = global_cable11_t_index;

template <int NV>
using global_cable108_t = routing::global_cable<global_cable108_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain467_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable108_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable109_t_index = global_cable10_t_index;

template <int NV>
using global_cable109_t = routing::global_cable<global_cable109_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain468_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable109_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable110_t_index = global_cable14_t_index;

template <int NV>
using global_cable110_t = routing::global_cable<global_cable110_t_index, 
                                                parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain469_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable110_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader88_t = event_data_reader11_t<NV>;

template <int NV>
using chain470_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader88_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader89_t = event_data_reader11_t<NV>;

template <int NV>
using chain471_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader89_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader90_t = event_data_reader11_t<NV>;

template <int NV>
using chain472_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader90_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc110_t = midi_cc10_t<NV>;

template <int NV>
using chain474_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc110_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc111_t = midi_cc10_t<NV>;

template <int NV>
using chain475_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc111_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc112_t = midi_cc10_t<NV>;

template <int NV>
using chain476_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc112_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc113_t = midi_cc10_t<NV>;

template <int NV>
using chain477_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc113_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi82_t = midi6_t<NV>;

template <int NV>
using chain478_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi82_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi83_t = midi7_t<NV>;

template <int NV>
using chain479_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi83_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi84_t = midi8_t<NV>;

template <int NV>
using chain480_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi84_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch39_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain474_t<NV>>, 
                                     chain475_t<NV>, 
                                     chain476_t<NV>, 
                                     chain477_t<NV>, 
                                     chain478_t<NV>, 
                                     chain479_t<NV>, 
                                     chain480_t<NV>>;

template <int NV>
using chain473_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch39_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split53_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain466_t<NV>>, 
                                   chain467_t<NV>, 
                                   chain468_t<NV>, 
                                   chain469_t<NV>, 
                                   chain470_t<NV>, 
                                   chain471_t<NV>, 
                                   chain472_t<NV>, 
                                   chain473_t<NV>>;

template <int NV> using pma36_mod = clone_cable2_0<NV>;

template <int NV>
using pma36_t = control::pma<NV, pma36_mod<NV>>;
template <int NV>
using peak34_t = wrap::mod<parameter::plain<pma36_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain30_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, sliderbank29_t<NV>>, 
                                       split53_t<NV>, 
                                       peak34_t<NV>, 
                                       pma36_t<NV>>;

template <int NV>
using modchain30_t = wrap::control_rate<modchain30_t_<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, modchain1_t<NV>>, 
                                  modchain2_t<NV>, 
                                  modchain4_t<NV>, 
                                  modchain7_t<NV>, 
                                  modchain6_t<NV>, 
                                  modchain19_t<NV>, 
                                  modchain20_t<NV>, 
                                  modchain21_t<NV>, 
                                  modchain22_t<NV>, 
                                  modchain23_t<NV>, 
                                  modchain24_t<NV>, 
                                  modchain25_t<NV>, 
                                  modchain27_t<NV>, 
                                  modchain26_t<NV>, 
                                  modchain28_t<NV>, 
                                  modchain29_t<NV>, 
                                  modchain30_t<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, minmax2_t<NV>>, 
                                  converter_t<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, control::minmax<NV, parameter::empty>>>;

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

template <int NV>
using fix8_block1_t_ = container::chain<parameter::empty, 
                                        wrap::fix<2, branch1_t<NV>>>;

template <int NV>
using fix8_block1_t = wrap::fix_block<8, fix8_block1_t_<NV>>;
using peak1_t = peak33_t;

template <int NV>
using chain74_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::sub<NV>>, 
                                   math::abs<NV>, 
                                   math::mul<NV>>;

template <int NV>
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain74_t<NV>>, 
                                   core::gain<NV>>;
namespace custom
{

struct expr3
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 2.0 * value * input);;
	}
};
}

template <int NV>
using chain75_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr3>>, 
                                   core::gain<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain62_t<NV>>, 
                                  chain75_t<NV>>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader3_t<NV>>, 
                                   split8_t<NV>, 
                                   core::gain<NV>>;

template <int NV>
using chain76_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   math::rect<NV>, 
                                   core::gain<NV>>;
using oscilloscope1_t = wrap::no_data<analyse::oscilloscope>;

template <int NV>
using chain78_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   math::fmod<NV>, 
                                   wrap::no_process<math::mul<NV>>, 
                                   math::pi<NV>, 
                                   oscilloscope1_t>;

template <int NV>
using chain77_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain78_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using chain79_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   math::expr<NV, custom::expr6>, 
                                   math::sin<NV>, 
                                   core::gain<NV>>;
namespace custom
{

struct expr7
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 12.0 * value * input) * (2 - Math.PI);;
	}
};
}

template <int NV>
using chain80_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::pi<NV>>, 
                                   wrap::no_process<math::sin<NV>>, 
                                   core::gain<NV>, 
                                   math::sin<NV>, 
                                   math::expr<NV, custom::expr7>, 
                                   core::gain<NV>>;
namespace custom
{

struct expr8
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 12.0 * value * input) * (2 - Math.PI);;
	}
};
}

template <int NV>
using chain81_t = container::chain<parameter::empty, 
                                   wrap::fix<2, wrap::no_process<math::pi<NV>>>, 
                                   wrap::no_process<fx::phase_delay<NV>>, 
                                   core::gain<NV>, 
                                   math::expr<NV, custom::expr8>, 
                                   math::sin<NV>, 
                                   core::gain<NV>>;

DECLARE_PARAMETER_RANGE_STEP(clone_pack1_modRange, 
                             0., 
                             2.6, 
                             0.1);

template <int NV>
using clone_pack1_mod = parameter::from0To1<math::pi<NV>, 
                                            0, 
                                            clone_pack1_modRange>;

struct clone_pack1_t_data
{
	span<float, 16> data =
	{
		0.06f, 0.06f, 0.82f, 1.f, 1.f, 1.f,
		0.82f, 0.63f, 0.47f, 0.2f, 1.f, 1.f,
		0.85f, 0.78f, 0.65f, 0.44f
	};
};

template <int NV>
using clone_pack1_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack1_mod<NV>>>, 
                                 data::embedded::sliderpack<clone_pack1_t_data>>;

template <int NV>
using clone_child16_t = container::chain<parameter::empty, 
                                         wrap::fix<2, math::pi<NV>>, 
                                         wrap::no_process<math::sub<NV>>, 
                                         math::expr<NV, custom::expr9>, 
                                         wrap::no_process<math::fmod<NV>>, 
                                         math::add<NV>, 
                                         wrap::no_process<math::rect<NV>>, 
                                         core::gain<NV>, 
                                         jdsp::jpanner<NV>, 
                                         wrap::no_process<math::square<NV>>, 
                                         math::sin<NV>>;
template <int NV>
using clone1_t = wrap::fix_clonecopy<clone_child16_t<NV>, 16>;

template <int NV>
using chain84_t = container::chain<parameter::empty, 
                                   wrap::fix<2, clone_cable2_t<NV>>, 
                                   clone_cable4_t<NV>, 
                                   clone_pack1_t<NV>, 
                                   clone1_t<NV>, 
                                   cable_table1_t, 
                                   math::sin<NV>>;

template <int NV>
using chain83_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain84_t<NV>>>;

template <int NV>
using chain82_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain83_t<NV>>, 
                                   core::gain<NV>>;
using table5_t = wrap::data<math::table, 
                            data::external::table<0>>;

template <int NV>
using chain85_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   math::pi<NV>, 
                                   table5_t, 
                                   core::gain<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain59_t<NV>>, 
                                  chain76_t<NV>, 
                                  chain77_t<NV>, 
                                  chain79_t<NV>, 
                                  chain80_t<NV>, 
                                  chain81_t<NV>, 
                                  chain82_t<NV>, 
                                  chain85_t<NV>>;

using cable_table18_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::external::table<2>>;

template <int NV>
using pma23_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma21_t<NV>, 2>, 
                                   parameter::plain<cable_table18_t, 0>>;

template <int NV>
using pma23_t = control::pma<NV, pma23_mod<NV>>;

template <int NV>
using peak5_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<pma23_t<NV>, 0>, 
                                   parameter::plain<pma37_t<NV>, 0>, 
                                   parameter::plain<pma38_t<NV>, 0>, 
                                   parameter::plain<pma39_t<NV>, 0>>;

template <int NV>
using peak5_t = wrap::mod<peak5_mod<NV>, 
                          wrap::data<core::peak, data::external::displaybuffer<0>>>;

template <int NV>
using fix8_block2_t_ = container::chain<parameter::empty, 
                                        wrap::fix<2, peak5_t<NV>>>;

template <int NV>
using fix8_block2_t = wrap::fix_block<8, fix8_block2_t_<NV>>;

template <int NV>
using chain426_t = container::chain<parameter::empty, 
                                    wrap::fix<2, core::gain<NV>>>;

template <int NV>
using chain266_t = container::chain<parameter::empty, 
                                    wrap::fix<1, tempo_sync6_t<NV>>, 
                                    ramp1_t<NV>, 
                                    math::add<NV>>;

template <int NV>
using chain267_t = container::chain<parameter::empty, 
                                    wrap::fix<1, clock_ramp1_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch24_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain266_t<NV>>, 
                                     chain267_t<NV>>;

template <int NV>
using chain265_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch24_t<NV>>>;
using peak19_t = peak33_t;

template <int NV>
using chain268_t = container::chain<parameter::empty, 
                                    wrap::fix<1, cable_table17_t<NV>>, 
                                    wrap::no_process<math::add<NV>>>;

template <int NV>
using chain264_t = container::chain<parameter::empty, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    chain265_t<NV>, 
                                    peak19_t, 
                                    math::clear<NV>, 
                                    chain268_t<NV>, 
                                    cable_table16_t, 
                                    math::clear<NV>, 
                                    pma21_t<NV>>;

template <int NV> using sliderbank16_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank16_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank16_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank16_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank16_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank16_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank16_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank16_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank16_multimod = parameter::list<sliderbank16_c0<NV>, 
                                              sliderbank16_c1<NV>, 
                                              sliderbank16_c2<NV>, 
                                              sliderbank16_c3<NV>, 
                                              sliderbank16_c4<NV>, 
                                              sliderbank16_c5<NV>, 
                                              sliderbank16_c6<NV>, 
                                              sliderbank16_c7<NV>>;

template <int NV>
using sliderbank16_t = wrap::data<control::sliderbank<sliderbank16_multimod<NV>>, 
                                  data::external::sliderpack<5>>;
using global_cable55_t_index = global_cable3_t_index;

template <int NV>
using global_cable55_t = routing::global_cable<global_cable55_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain270_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable55_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable56_t_index = global_cable11_t_index;

template <int NV>
using global_cable56_t = routing::global_cable<global_cable56_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain271_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable56_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable57_t_index = global_cable10_t_index;

template <int NV>
using global_cable57_t = routing::global_cable<global_cable57_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain272_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable57_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable58_t_index = global_cable14_t_index;

template <int NV>
using global_cable58_t = routing::global_cable<global_cable58_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain273_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable58_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader49_t = event_data_reader11_t<NV>;

template <int NV>
using chain274_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader49_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader50_t = event_data_reader11_t<NV>;

template <int NV>
using chain275_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader50_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader51_t = event_data_reader11_t<NV>;

template <int NV>
using chain276_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader51_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using midi_cc58_t = midi_cc10_t<NV>;

template <int NV>
using chain278_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc58_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc59_t = midi_cc10_t<NV>;

template <int NV>
using chain279_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc59_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc60_t = midi_cc10_t<NV>;

template <int NV>
using chain280_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc60_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi_cc61_t = midi_cc10_t<NV>;

template <int NV>
using chain281_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi_cc61_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi43_t = midi6_t<NV>;

template <int NV>
using chain282_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi43_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi44_t = midi7_t<NV>;

template <int NV>
using chain283_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi44_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using midi45_t = midi8_t<NV>;

template <int NV>
using chain284_t = container::chain<parameter::empty, 
                                    wrap::fix<1, midi45_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch26_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain278_t<NV>>, 
                                     chain279_t<NV>, 
                                     chain280_t<NV>, 
                                     chain281_t<NV>, 
                                     chain282_t<NV>, 
                                     chain283_t<NV>, 
                                     chain284_t<NV>>;

template <int NV>
using chain277_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch26_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using split38_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain270_t<NV>>, 
                                   chain271_t<NV>, 
                                   chain272_t<NV>, 
                                   chain273_t<NV>, 
                                   chain274_t<NV>, 
                                   chain275_t<NV>, 
                                   chain276_t<NV>, 
                                   chain277_t<NV>>;

template <int NV>
using pma22_t = control::pma<NV, 
                             parameter::plain<pma23_t<NV>, 2>>;
template <int NV>
using peak21_t = wrap::mod<parameter::plain<pma22_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;
using cable_table19_t = wrap::data<control::cable_table<parameter::empty>, 
                                   data::external::table<3>>;

template <int NV>
using chain269_t = container::chain<parameter::empty, 
                                    wrap::fix<1, sliderbank16_t<NV>>, 
                                    split38_t<NV>, 
                                    peak21_t<NV>, 
                                    pma22_t<NV>, 
                                    pma23_t<NV>, 
                                    cable_table18_t, 
                                    cable_table19_t>;

template <int NV>
using split37_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain264_t<NV>>, 
                                   chain269_t<NV>>;

template <int NV>
using modchain17_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, split37_t<NV>>>;

template <int NV>
using modchain17_t = wrap::control_rate<modchain17_t_<NV>>;

template <int NV>
using chain250_t = container::chain<parameter::empty, 
                                    wrap::fix<1, math::add<NV>>>;

template <int NV>
using chain251_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax6_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain252_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax7_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain253_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax14_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain254_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax11_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain255_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax15_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain256_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax16_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain257_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax17_t<NV>>, 
                                    math::add<NV>>;

template <int NV>
using chain258_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax18_t<NV>>, 
                                    math::add<NV>>;
template <int NV>
using branch21_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain250_t<NV>>, 
                                     chain251_t<NV>, 
                                     chain252_t<NV>, 
                                     chain253_t<NV>, 
                                     chain254_t<NV>, 
                                     chain255_t<NV>, 
                                     chain256_t<NV>, 
                                     chain257_t<NV>, 
                                     chain258_t<NV>>;

template <int NV>
using peak18_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using modchain16_t_ = container::chain<parameter::empty, 
                                       wrap::fix<1, branch21_t<NV>>, 
                                       peak18_t<NV>>;

template <int NV>
using modchain16_t = wrap::control_rate<modchain16_t_<NV>>;

template <int NV>
using chain249_t = container::chain<parameter::empty, 
                                    wrap::fix<2, modchain16_t<NV>>>;

template <int NV>
using chain248_t = container::chain<parameter::empty, 
                                    wrap::fix<2, chain249_t<NV>>>;
using peak2_t = wrap::no_data<wrap::no_process<core::peak>>;
template <int NV>
using file_player6_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<1>>;
template <int NV>
using file_player7_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<0>>;
template <int NV>
using branch22_t = container::branch<parameter::empty, 
                                     wrap::fix<2, file_player6_t<NV>>, 
                                     file_player7_t<NV>>;

template <int NV>
using chain247_t = container::chain<parameter::empty, 
                                    wrap::fix<2, modchain17_t<NV>>, 
                                    core::gain<NV>, 
                                    chain248_t<NV>, 
                                    peak2_t, 
                                    math::expr<NV, custom::expr10>, 
                                    math::add<NV>, 
                                    branch22_t<NV>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, chain247_t<NV>>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

template <int NV>
using chain261_t = container::chain<parameter::empty, 
                                    wrap::fix<2, wrap::no_process<math::tanh<NV>>>>;
using stereo_cable = cable::block<2>;

template <int NV>
using chain262_t = container::chain<parameter::empty, 
                                    wrap::fix<2, routing::receive<stereo_cable>>, 
                                    project::shfiter<NV>, 
                                    routing::send<stereo_cable>>;

DECLARE_PARAMETER_RANGE_STEP(cable_table15_modRange, 
                             -64., 
                             64., 
                             1.);

template <int NV>
using cable_table15_mod = parameter::from0To1<project::ps2<NV>, 
                                              0, 
                                              cable_table15_modRange>;

struct cable_table15_t_data
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
using cable_table15_t = wrap::data<control::cable_table<cable_table15_mod<NV>>, 
                                   data::embedded::table<cable_table15_t_data>>;
template <int NV>
using midi42_t = wrap::mod<parameter::plain<cable_table15_t<NV>, 0>, 
                           control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain263_t = container::chain<parameter::empty, 
                                    wrap::fix<2, midi42_t<NV>>, 
                                    cable_table15_t<NV>, 
                                    routing::receive<stereo_cable>, 
                                    project::ps2<NV>, 
                                    project::shfiter<NV>, 
                                    routing::send<stereo_cable>>;
template <int NV>
using branch23_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain261_t<NV>>, 
                                     chain262_t<NV>, 
                                     chain263_t<NV>>;

template <int NV>
using chain73_t = container::chain<parameter::empty, 
                                   wrap::fix<2, fix8_block_t<NV>>, 
                                   branch23_t<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split48_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain426_t<NV>>, 
                                   chain73_t<NV>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split48_t<NV>>>;

template <int NV> using chain14_t = chain426_t<NV>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, project::klp<NV>>, 
                                   project::khp2<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, project::klp<NV>>, 
                                  project::khp2<NV>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split1_t<NV>>>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table_t<NV>>, 
                                   project::Comb<NV>, 
                                   project::klp<NV>>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table2_t<NV>>, 
                                   project::klp<NV>, 
                                   project::Comb<NV>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<2, project::klp<NV>>, 
                                   jdsp::jpanner<NV>>;

template <int NV> using chain56_t = chain55_t<NV>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain55_t<NV>>, 
                                  chain56_t<NV>>;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<2, project::khp<NV>>, 
                                   jdsp::jpanner<NV>>;

template <int NV> using chain61_t = chain60_t<NV>;

template <int NV>
using split13_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain60_t<NV>>, 
                                   chain61_t<NV>>;

template <int NV>
using chain71_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table3_t<NV>>, 
                                   project::Comb<NV>, 
                                   jdsp::jpanner<NV>>;

template <int NV>
using chain72_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table4_t<NV>>, 
                                   project::Comb<NV>, 
                                   jdsp::jpanner<NV>>;

template <int NV>
using split14_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain71_t<NV>>, 
                                   chain72_t<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain16_t<NV>>, 
                                   chain35_t<NV>, 
                                   chain36_t<NV>, 
                                   chain37_t<NV>, 
                                   split9_t<NV>, 
                                   split13_t<NV>, 
                                   split14_t<NV>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch_t<NV>>>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain15_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split12_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain14_t<NV>>, 
                                   chain57_t<NV>>;

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader_t<NV>>, 
                                   split12_t<NV>>;

template <int NV>
using peak7_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using frame2_block_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, peak7_t<NV>>, 
                                         pma_t<NV>, 
                                         core::gain<NV>>;

template <int NV>
using frame2_block_t = wrap::frame<2, frame2_block_t_<NV>>;

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

template <int NV>
using pitchmode_1 = parameter::from0To1<osc1_impl::branch3_t<NV>, 
                                        0, 
                                        pitchmode_0Range>;

template <int NV>
using pitchmode = parameter::chain<pitchmode_InputRange, 
                                   pitchmode_0<NV>, 
                                   pitchmode_1<NV>>;

template <int NV>
using step = parameter::chain<ranges::Identity, 
                              parameter::plain<osc1_impl::minmax2_t<NV>, 4>, 
                              parameter::plain<control::minmax<NV, parameter::empty>, 4>>;

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

DECLARE_PARAMETER_RANGE_SKEW(BendRange, 
                             0., 
                             20000., 
                             0.231378);

template <int NV>
using Bend = parameter::from0To1<core::smoother<NV>, 
                                 0, 
                                 BendRange>;

DECLARE_PARAMETER_RANGE(Shape_InputRange, 
                        1., 
                        8.);

template <int NV>
using Shape = parameter::chain<Shape_InputRange, 
                               parameter::plain<osc1_impl::pma12_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE(XfShape_InputRange, 
                        1., 
                        4.);
template <int NV>
using XfShape_0 = parameter::from0To1<osc1_impl::event_data_reader27_t<NV>, 
                                      0, 
                                      XfstagePitch_0Range>;

template <int NV>
using XfShape = parameter::chain<XfShape_InputRange, XfShape_0<NV>>;

DECLARE_PARAMETER_RANGE(MidiShape_InputRange, 
                        1., 
                        7.);
template <int NV>
using MidiShape_0 = parameter::from0To1<osc1_impl::branch9_t<NV>, 
                                        0, 
                                        MidiSlotPitch_0Range>;

template <int NV>
using MidiShape = parameter::chain<MidiShape_InputRange, MidiShape_0<NV>>;

DECLARE_PARAMETER_RANGE(XfWidth_InputRange, 
                        1., 
                        7.);
template <int NV>
using XfWidth_0 = parameter::from0To1<osc1_impl::event_data_reader24_t<NV>, 
                                      0, 
                                      XfstagePitch_0Range>;

template <int NV>
using XfWidth = parameter::chain<XfWidth_InputRange, XfWidth_0<NV>>;

DECLARE_PARAMETER_RANGE(MidiWidth_InputRange, 
                        1., 
                        7.);
template <int NV>
using MidiWidth_0 = parameter::from0To1<osc1_impl::branch8_t<NV>, 
                                        0, 
                                        MidiSlotPitch_0Range>;

template <int NV>
using MidiWidth = parameter::chain<MidiWidth_InputRange, MidiWidth_0<NV>>;

template <int NV>
using Position = parameter::chain<ranges::Identity, 
                                  parameter::plain<osc1_impl::pma22_t<NV>, 2>, 
                                  parameter::plain<osc1_impl::cable_table19_t, 0>>;

DECLARE_PARAMETER_RANGE_STEP(QuantisePositiion_InputRange, 
                             1., 
                             9., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(QuantisePositiion_0Range, 
                             0., 
                             8., 
                             1.);

template <int NV>
using QuantisePositiion_0 = parameter::from0To1<osc1_impl::branch21_t<NV>, 
                                                0, 
                                                QuantisePositiion_0Range>;

template <int NV>
using QuantisePositiion = parameter::chain<QuantisePositiion_InputRange, 
                                           QuantisePositiion_0<NV>>;

DECLARE_PARAMETER_RANGE(FilePitch_InputRange, 
                        -24., 
                        24.);

template <int NV>
using FilePitch = parameter::chain<FilePitch_InputRange, 
                                   parameter::plain<osc1_impl::pma24_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(PtichShiftOn_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(PtichShiftOn_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using PtichShiftOn_0 = parameter::from0To1<osc1_impl::branch23_t<NV>, 
                                           0, 
                                           PtichShiftOn_0Range>;

template <int NV>
using PtichShiftOn = parameter::chain<PtichShiftOn_InputRange, 
                                      PtichShiftOn_0<NV>>;

DECLARE_PARAMETER_RANGE(PitchWin_InputRange, 
                        50., 
                        10000.);

template <int NV>
using PitchWin = parameter::chain<PitchWin_InputRange, 
                                  parameter::plain<osc1_impl::pma26_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE(PitchXf_InputRange, 
                        0., 
                        10000.);

template <int NV>
using PitchXf = parameter::chain<PitchXf_InputRange, 
                                 parameter::plain<osc1_impl::pma40_t<NV>, 2>>;

template <int NV>
using FileMix_1 = parameter::from0To1<osc1_impl::pma30_t<NV>, 
                                      1, 
                                      osc1_impl::clone_cable2_0Range>;

template <int NV>
using FileMix = parameter::chain<ranges::Identity, 
                                 parameter::plain<osc1_impl::pma30_t<NV>, 2>, 
                                 FileMix_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileTempo_InputRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using FileTempo = parameter::chain<FileTempo_InputRange, 
                                   parameter::plain<osc1_impl::pma28_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(FileDiv_InputRange, 
                             1., 
                             32., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(FileDiv_0Range, 
                             1., 
                             32., 
                             1.);

template <int NV>
using FileDiv_0 = parameter::from0To1<osc1_impl::tempo_sync6_t<NV>, 
                                      1, 
                                      FileDiv_0Range>;

DECLARE_PARAMETER_RANGE_STEP(FileDiv_1Range, 
                             1., 
                             16., 
                             1.);

template <int NV>
using FileDiv_1 = parameter::from0To1<osc1_impl::clock_ramp1_t<NV>, 
                                      1, 
                                      FileDiv_1Range>;

template <int NV>
using FileDiv = parameter::chain<FileDiv_InputRange, 
                                 FileDiv_0<NV>, 
                                 FileDiv_1<NV>>;

using FileFb = parameter::chain<ranges::Identity, 
                                parameter::plain<routing::receive<stereo_cable>, 0>, 
                                parameter::plain<routing::receive<stereo_cable>, 0>>;

template <int NV>
using FileXfSmooth = parameter::from0To1<osc1_impl::event_data_reader72_t<NV>, 
                                         0, 
                                         XfstagePitch_0Range>;

DECLARE_PARAMETER_RANGE(FileXfPitch_InputRange, 
                        1., 
                        4.);
template <int NV>
using FileXfPitch_0 = parameter::from0To1<osc1_impl::event_data_reader57_t<NV>, 
                                          0, 
                                          XfstagePitch_0Range>;

template <int NV>
using FileXfPitch = parameter::chain<FileXfPitch_InputRange, FileXfPitch_0<NV>>;

DECLARE_PARAMETER_RANGE(FileXfpos2_InputRange, 
                        1., 
                        4.);
template <int NV>
using FileXfpos2_0 = parameter::from0To1<osc1_impl::event_data_reader51_t<NV>, 
                                         0, 
                                         XfstagePitch_0Range>;

template <int NV>
using FileXfpos2 = parameter::chain<FileXfpos2_InputRange, FileXfpos2_0<NV>>;

DECLARE_PARAMETER_RANGE(FileXfpostempo_InputRange, 
                        1., 
                        4.);
template <int NV>
using FileXfpostempo_0 = parameter::from0To1<osc1_impl::event_data_reader69_t<NV>, 
                                             0, 
                                             XfstagePitch_0Range>;

template <int NV>
using FileXfpostempo = parameter::chain<FileXfpostempo_InputRange, 
                                        FileXfpostempo_0<NV>>;

DECLARE_PARAMETER_RANGE(FileXfmix_InputRange, 
                        1., 
                        4.);
template <int NV>
using FileXfmix_0 = parameter::from0To1<osc1_impl::event_data_reader75_t<NV>, 
                                        0, 
                                        XfstagePitch_0Range>;

template <int NV>
using FileXfmix = parameter::chain<FileXfmix_InputRange, FileXfmix_0<NV>>;

DECLARE_PARAMETER_RANGE(FileXfpitchfade_InputRange, 
                        1., 
                        4.);
template <int NV>
using FileXfpitchfade_0 = parameter::from0To1<osc1_impl::event_data_reader63_t<NV>, 
                                              0, 
                                              XfstagePitch_0Range>;

template <int NV>
using FileXfpitchfade = parameter::chain<FileXfpitchfade_InputRange, 
                                         FileXfpitchfade_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileXfwindow_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV>
using FileXfwindow_0 = parameter::from0To1<osc1_impl::event_data_reader60_t<NV>, 
                                           0, 
                                           XfstagePitch_0Range>;

template <int NV>
using FileXfwindow = parameter::chain<FileXfwindow_InputRange, 
                                      FileXfwindow_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileMidiSmooth_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using FileMidiSmooth_0 = parameter::from0To1<osc1_impl::branch33_t<NV>, 
                                             0, 
                                             MidiSlotPitch_0Range>;

template <int NV>
using FileMidiSmooth = parameter::chain<FileMidiSmooth_InputRange, 
                                        FileMidiSmooth_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileMidiPitch_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV>
using FileMidiPitch_0 = parameter::from0To1<osc1_impl::branch28_t<NV>, 
                                            0, 
                                            MidiSlotPitch_0Range>;

template <int NV>
using FileMidiPitch = parameter::chain<FileMidiPitch_InputRange, 
                                       FileMidiPitch_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileMidipos2_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using FileMidipos2_0 = parameter::from0To1<osc1_impl::branch26_t<NV>, 
                                           0, 
                                           MidiSlotPitch_0Range>;

template <int NV>
using FileMidipos2 = parameter::chain<FileMidipos2_InputRange, 
                                      FileMidipos2_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileMidipostempo_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using FileMidipostempo_0 = parameter::from0To1<osc1_impl::branch32_t<NV>, 
                                               0, 
                                               MidiSlotPitch_0Range>;

template <int NV>
using FileMidipostempo = parameter::chain<FileMidipostempo_InputRange, 
                                          FileMidipostempo_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileMidimix_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using FileMidimix_0 = parameter::from0To1<osc1_impl::branch34_t<NV>, 
                                          0, 
                                          MidiSlotPitch_0Range>;

template <int NV>
using FileMidimix = parameter::chain<FileMidimix_InputRange, FileMidimix_0<NV>>;

DECLARE_PARAMETER_RANGE(FileMidipitchfade_InputRange, 
                        1., 
                        7.);
template <int NV>
using FileMidipitchfade_0 = parameter::from0To1<osc1_impl::branch30_t<NV>, 
                                                0, 
                                                MidiSlotPitch_0Range>;

template <int NV>
using FileMidipitchfade = parameter::chain<FileMidipitchfade_InputRange, 
                                           FileMidipitchfade_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileMidiwindow_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using FileMidiwindow_0 = parameter::from0To1<osc1_impl::branch29_t<NV>, 
                                             0, 
                                             MidiSlotPitch_0Range>;

template <int NV>
using FileMidiwindow = parameter::chain<FileMidiwindow_InputRange, 
                                        FileMidiwindow_0<NV>>;

DECLARE_PARAMETER_RANGE(FileMidiInput_InputRange, 
                        1., 
                        7.);
template <int NV>
using FileMidiInput_0 = parameter::from0To1<osc1_impl::branch31_t<NV>, 
                                            0, 
                                            MidiSlotPitch_0Range>;

template <int NV>
using FileMidiInput = parameter::chain<FileMidiInput_InputRange, 
                                       FileMidiInput_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(FileXfInput_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV>
using FileXfInput_0 = parameter::from0To1<osc1_impl::event_data_reader66_t<NV>, 
                                          0, 
                                          XfstagePitch_0Range>;

template <int NV>
using FileXfInput = parameter::chain<FileXfInput_InputRange, FileXfInput_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Q_0Range, 
                             0.5, 
                             10., 
                             0.01);

template <int NV>
using Q_0 = parameter::from0To1<project::klp<NV>, 
                                0, 
                                Q_0Range>;

template <int NV> using Q_1 = Q_0<NV>;

template <int NV> using Q_3 = Q_0<NV>;

template <int NV> using Q_4 = Q_0<NV>;

template <int NV>
using Q_5 = parameter::from0To1<project::khp<NV>, 
                                0, 
                                Q_0Range>;

template <int NV>
using Q = parameter::chain<ranges::Identity, 
                           Q_0<NV>, 
                           Q_1<NV>, 
                           parameter::plain<project::Comb<NV>, 0>, 
                           Q_3<NV>, 
                           Q_4<NV>, 
                           Q_5<NV>, 
                           parameter::plain<project::Comb<NV>, 0>>;

DECLARE_PARAMETER_RANGE_SKEW(Cut1_InputRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using Cut1 = parameter::chain<Cut1_InputRange, 
                              parameter::plain<osc1_impl::pma37_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_SKEW(Cut2_InputRange, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using Cut2 = parameter::chain<Cut2_InputRange, 
                              parameter::plain<osc1_impl::pma38_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE(Pan_InputRange, 
                        -1., 
                        1.);

template <int NV>
using Pan = parameter::chain<Pan_InputRange, 
                             parameter::plain<osc1_impl::pma36_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE(FilterXfMix_InputRange, 
                        1., 
                        4.);
template <int NV>
using FilterXfMix_0 = parameter::from0To1<osc1_impl::event_data_reader81_t<NV>, 
                                          0, 
                                          XfstagePitch_0Range>;

template <int NV>
using FilterXfMix = parameter::chain<FilterXfMix_InputRange, FilterXfMix_0<NV>>;

DECLARE_PARAMETER_RANGE(FilterXfCut1_InputRange, 
                        1., 
                        4.);
template <int NV>
using FilterXfCut1_0 = parameter::from0To1<osc1_impl::event_data_reader78_t<NV>, 
                                           0, 
                                           XfstagePitch_0Range>;

template <int NV>
using FilterXfCut1 = parameter::chain<FilterXfCut1_InputRange, 
                                      FilterXfCut1_0<NV>>;

DECLARE_PARAMETER_RANGE(FilterXfCut2_InputRange, 
                        1., 
                        4.);
template <int NV>
using FilterXfCut2_0 = parameter::from0To1<osc1_impl::event_data_reader84_t<NV>, 
                                           0, 
                                           XfstagePitch_0Range>;

template <int NV>
using FilterXfCut2 = parameter::chain<FilterXfCut2_InputRange, 
                                      FilterXfCut2_0<NV>>;

DECLARE_PARAMETER_RANGE(FilterXfGain_InputRange, 
                        1., 
                        4.);
template <int NV>
using FilterXfGain_0 = parameter::from0To1<osc1_impl::event_data_reader87_t<NV>, 
                                           0, 
                                           XfstagePitch_0Range>;

template <int NV>
using FilterXfGain = parameter::chain<FilterXfGain_InputRange, 
                                      FilterXfGain_0<NV>>;

DECLARE_PARAMETER_RANGE(FilterXfPan_InputRange, 
                        1., 
                        4.);
template <int NV>
using FilterXfPan_0 = parameter::from0To1<osc1_impl::event_data_reader90_t<NV>, 
                                          0, 
                                          XfstagePitch_0Range>;

template <int NV>
using FilterXfPan = parameter::chain<FilterXfPan_InputRange, FilterXfPan_0<NV>>;

DECLARE_PARAMETER_RANGE(FilterMidiMix_InputRange, 
                        1., 
                        7.);
template <int NV>
using FilterMidiMix_0 = parameter::from0To1<osc1_impl::branch36_t<NV>, 
                                            0, 
                                            MidiSlotPitch_0Range>;

template <int NV>
using FilterMidiMix = parameter::chain<FilterMidiMix_InputRange, 
                                       FilterMidiMix_0<NV>>;

DECLARE_PARAMETER_RANGE(FilterMidiCut1_InputRange, 
                        1., 
                        7.);
template <int NV>
using FilterMidiCut1_0 = parameter::from0To1<osc1_impl::branch35_t<NV>, 
                                             0, 
                                             MidiSlotPitch_0Range>;

template <int NV>
using FilterMidiCut1 = parameter::chain<FilterMidiCut1_InputRange, 
                                        FilterMidiCut1_0<NV>>;

DECLARE_PARAMETER_RANGE(FilterMidiCut2_InputRange, 
                        1., 
                        7.);
template <int NV>
using FilterMidiCut2_0 = parameter::from0To1<osc1_impl::branch37_t<NV>, 
                                             0, 
                                             MidiSlotPitch_0Range>;

template <int NV>
using FilterMidiCut2 = parameter::chain<FilterMidiCut2_InputRange, 
                                        FilterMidiCut2_0<NV>>;

DECLARE_PARAMETER_RANGE(FilterMidiGain_InputRange, 
                        1., 
                        7.);
template <int NV>
using FilterMidiGain_0 = parameter::from0To1<osc1_impl::branch38_t<NV>, 
                                             0, 
                                             MidiSlotPitch_0Range>;

template <int NV>
using FilterMidiGain = parameter::chain<FilterMidiGain_InputRange, 
                                        FilterMidiGain_0<NV>>;

DECLARE_PARAMETER_RANGE(FilterMidiPan_InputRange, 
                        1., 
                        7.);
template <int NV>
using FilterMidiPan_0 = parameter::from0To1<osc1_impl::branch39_t<NV>, 
                                            0, 
                                            MidiSlotPitch_0Range>;

template <int NV>
using FilterMidiPan = parameter::chain<FilterMidiPan_InputRange, 
                                       FilterMidiPan_0<NV>>;

template <int NV>
using osc2Gain = parameter::chain<ranges::Identity, 
                                  parameter::plain<osc1_impl::pma39_t<NV>, 1>, 
                                  parameter::plain<osc1_impl::pma_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE_STEP(FilterMode_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using FilterMode_0 = parameter::from0To1<osc1_impl::branch_t<NV>, 
                                         0, 
                                         MidiSlotPitch_0Range>;

template <int NV>
using FilterMode = parameter::chain<FilterMode_InputRange, FilterMode_0<NV>>;

template <int NV> using q2_1 = Q_5<NV>;

template <int NV> using q2_2 = Q_0<NV>;

template <int NV> using q2_4 = Q_0<NV>;

template <int NV>
using q2_5 = parameter::from0To1<project::khp2<NV>, 
                                 0, 
                                 Q_0Range>;

template <int NV> using q2_6 = q2_5<NV>;

template <int NV>
using q2 = parameter::chain<ranges::Identity, 
                            parameter::plain<project::Comb<NV>, 0>, 
                            q2_1<NV>, 
                            q2_2<NV>, 
                            parameter::plain<project::Comb<NV>, 0>, 
                            q2_4<NV>, 
                            q2_5<NV>, 
                            q2_6<NV>>;

template <int NV>
using div = parameter::plain<osc1_impl::tempo_sync_t<NV>, 
                             1>;
template <int NV>
using Input = parameter::plain<osc1_impl::pma2_t<NV>, 2>;
template <int NV>
using InputMod = parameter::plain<osc1_impl::pma2_t<NV>, 1>;
template <int NV>
using OutPut = parameter::plain<osc1_impl::pma4_t<NV>, 2>;
template <int NV>
using OutMod = parameter::plain<osc1_impl::pma4_t<NV>, 1>;
template <int NV>
using sync = parameter::plain<osc1_impl::tempo_sync_t<NV>, 
                              2>;
template <int NV>
using LfoUnsync = parameter::plain<osc1_impl::minmax_t<NV>, 
                                   0>;
template <int NV>
using ShapeMod = parameter::plain<osc1_impl::pma12_t<NV>, 1>;
template <int NV>
using WidhMod = parameter::plain<osc1_impl::pma10_t<NV>, 1>;
template <int NV>
using Width = parameter::plain<osc1_impl::pma10_t<NV>, 2>;
template <int NV>
using PositionMod = parameter::plain<osc1_impl::pma22_t<NV>, 1>;
template <int NV>
using PositionIntMod = parameter::plain<osc1_impl::pma21_t<NV>, 1>;
template <int NV>
using PosSmooth = parameter::plain<osc1_impl::pma29_t<NV>, 2>;
template <int NV>
using SmoothMod = parameter::plain<osc1_impl::pma29_t<NV>, 1>;
template <int NV>
using FilePitchMod = parameter::plain<osc1_impl::pma24_t<NV>, 1>;
template <int NV>
using WinMod = parameter::plain<osc1_impl::pma26_t<NV>, 1>;
template <int NV>
using PitchXfMod = parameter::plain<osc1_impl::pma40_t<NV>, 1>;
template <int NV>
using FileInput = parameter::plain<osc1_impl::pma27_t<NV>, 2>;
template <int NV>
using FileInputMod = parameter::plain<osc1_impl::pma27_t<NV>, 1>;
template <int NV>
using FileModTempo = parameter::plain<osc1_impl::pma28_t<NV>, 1>;
using fileMixMod = parameter::empty;
template <int NV>
using FileClk = parameter::plain<osc1_impl::branch24_t<NV>, 
                                 0>;
template <int NV>
using FileUser = parameter::plain<osc1_impl::branch22_t<NV>, 
                                  0>;
template <int NV>
using Osc2Pos = parameter::plain<osc1_impl::pma23_t<NV>, 1>;
using Osc2In = fileMixMod;
template <int NV>
using FilterMix = parameter::plain<osc1_impl::pma33_t<NV>, 2>;
template <int NV>
using FilterMod = parameter::plain<osc1_impl::pma33_t<NV>, 1>;
template <int NV>
using Cut1Mod = parameter::plain<osc1_impl::pma32_t<NV>, 1>;
template <int NV>
using Cut2Mod = parameter::plain<osc1_impl::pma34_t<NV>, 1>;
template <int NV>
using Gain = parameter::plain<osc1_impl::pma39_t<NV>, 2>;
using GainMod = fileMixMod;
template <int NV>
using PanMod = parameter::plain<osc1_impl::pma36_t<NV>, 1>;
template <int NV>
using FilterOsc = parameter::plain<osc1_impl::pma37_t<NV>, 1>;
template <int NV>
using Osc2Filter2 = parameter::plain<osc1_impl::pma38_t<NV>, 1>;
template <int NV>
using PreFilterGain = parameter::plain<core::gain<NV>, 0>;
template <int NV>
using OneShot = parameter::plain<osc1_impl::ramp1_t<NV>, 1>;
template <int NV>
using osc1_t_plist = parameter::list<Pitch<NV>, 
                                     tempo<NV>, 
                                     div<NV>, 
                                     pitchmode<NV>, 
                                     step<NV>, 
                                     Input<NV>, 
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
                                     MidiSlotOut<NV>, 
                                     Bend<NV>, 
                                     ShapeMod<NV>, 
                                     Shape<NV>, 
                                     WidhMod<NV>, 
                                     Width<NV>, 
                                     XfShape<NV>, 
                                     MidiShape<NV>, 
                                     XfWidth<NV>, 
                                     MidiWidth<NV>, 
                                     PositionMod<NV>, 
                                     Position<NV>, 
                                     PositionIntMod<NV>, 
                                     QuantisePositiion<NV>, 
                                     PosSmooth<NV>, 
                                     SmoothMod<NV>, 
                                     FilePitch<NV>, 
                                     PtichShiftOn<NV>, 
                                     FilePitchMod<NV>, 
                                     PitchWin<NV>, 
                                     WinMod<NV>, 
                                     PitchXf<NV>, 
                                     PitchXfMod<NV>, 
                                     FileInput<NV>, 
                                     FileInputMod<NV>, 
                                     FileModTempo<NV>, 
                                     FileMix<NV>, 
                                     fileMixMod, 
                                     FileTempo<NV>, 
                                     FileDiv<NV>, 
                                     FileClk<NV>, 
                                     FileUser<NV>, 
                                     FileFb, 
                                     FileXfSmooth<NV>, 
                                     FileXfPitch<NV>, 
                                     FileXfpos2<NV>, 
                                     FileXfpostempo<NV>, 
                                     FileXfmix<NV>, 
                                     FileXfpitchfade<NV>, 
                                     FileXfwindow<NV>, 
                                     FileMidiSmooth<NV>, 
                                     FileMidiPitch<NV>, 
                                     FileMidipos2<NV>, 
                                     FileMidipostempo<NV>, 
                                     FileMidimix<NV>, 
                                     FileMidipitchfade<NV>, 
                                     FileMidiwindow<NV>, 
                                     FileMidiInput<NV>, 
                                     FileXfInput<NV>, 
                                     Osc2Pos<NV>, 
                                     Osc2In, 
                                     Q<NV>, 
                                     FilterMix<NV>, 
                                     FilterMod<NV>, 
                                     Cut1<NV>, 
                                     Cut1Mod<NV>, 
                                     Cut2<NV>, 
                                     Cut2Mod<NV>, 
                                     Gain<NV>, 
                                     GainMod, 
                                     Pan<NV>, 
                                     PanMod<NV>, 
                                     FilterXfMix<NV>, 
                                     FilterXfCut1<NV>, 
                                     FilterXfCut2<NV>, 
                                     FilterXfGain<NV>, 
                                     FilterXfPan<NV>, 
                                     FilterMidiMix<NV>, 
                                     FilterMidiCut1<NV>, 
                                     FilterMidiCut2<NV>, 
                                     FilterMidiGain<NV>, 
                                     FilterMidiPan<NV>, 
                                     FilterOsc<NV>, 
                                     Osc2Filter2<NV>, 
                                     osc2Gain<NV>, 
                                     PreFilterGain<NV>, 
                                     FilterMode<NV>, 
                                     q2<NV>, 
                                     OneShot<NV>>;
}

template <int NV>
using osc1_t_ = container::chain<osc1_t_parameters::osc1_t_plist<NV>, 
                                 wrap::fix<2, split2_t<NV>>, 
                                 core::gain<NV>, 
                                 modchain_t<NV>, 
                                 fix8_block1_t<NV>, 
                                 core::mono2stereo, 
                                 peak1_t, 
                                 xfader2_t<NV>, 
                                 pma6_t<NV>, 
                                 split5_t<NV>, 
                                 fix8_block2_t<NV>, 
                                 core::gain<NV>, 
                                 filters::one_pole<NV>, 
                                 xfader1_t<NV>, 
                                 chain38_t<NV>, 
                                 core::gain<NV>, 
                                 chain58_t<NV>, 
                                 frame2_block_t<NV>, 
                                 jdsp::jpanner<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public osc1_impl::osc1_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 5;
		static const int NumSliderPacks = 18;
		static const int NumAudioFiles = 2;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 1;
		
		SNEX_METADATA_ID(osc1);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(1706)
		{
			0x005B, 0x0000, 0x5000, 0x7469, 0x6863, 0x0000, 0xC000, 0x00C1, 
            0xC000, 0x0041, 0xC000, 0x00C1, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x6574, 0x706D, 0x006F, 0x0000, 0x0000, 0x0000, 
            0x4190, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 
            0x0000, 0x6400, 0x7669, 0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 
            0x0000, 0x0042, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0003, 0x0000, 
            0x6970, 0x6374, 0x6D68, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 
            0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x045B, 
            0x0000, 0x7300, 0x6574, 0x0070, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 
            0x4900, 0x706E, 0x7475, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0006, 0x0000, 
            0x6950, 0x6374, 0x4D68, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0007, 
            0x0000, 0x6E49, 0x7570, 0x4D74, 0x646F, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0008, 0x0000, 0x754F, 0x5074, 0x7475, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x0A3F, 0xA3D7, 0x003C, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0009, 0x0000, 0x754F, 0x4D74, 0x646F, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x000A, 0x0000, 0x6168, 0x6D72, 0x0000, 0x8000, 0x003F, 0x8000, 
            0xAE41, 0x0947, 0x0041, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000B, 
            0x0000, 0x7973, 0x636E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000C, 0x0000, 
            0x664C, 0x556F, 0x736E, 0x6E79, 0x0063, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0xCDEA, 0x3F3B, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0D5B, 
            0x0000, 0x5800, 0x7366, 0x6174, 0x6567, 0x6950, 0x6374, 0x0068, 
            0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0E5B, 0x0000, 0x4D00, 0x6469, 0x5369, 0x6F6C, 
            0x5074, 0x7469, 0x6863, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000F, 0x0000, 
            0x6658, 0x7473, 0x6761, 0x4965, 0x706E, 0x7475, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0010, 0x0000, 0x694D, 0x6964, 0x6C53, 0x746F, 0x6E49, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0011, 0x0000, 0x6658, 0x7473, 0x6761, 
            0x4F65, 0x7475, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0012, 0x0000, 0x694D, 
            0x6964, 0x6C53, 0x746F, 0x754F, 0x0074, 0x0000, 0x3F80, 0x0000, 
            0x40E0, 0x34CD, 0x4098, 0x0000, 0x3F80, 0x0000, 0x0000, 0x135B, 
            0x0000, 0x4200, 0x6E65, 0x0064, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x145B, 0x0000, 
            0x5300, 0x6168, 0x6570, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x155B, 
            0x0000, 0x5300, 0x6168, 0x6570, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0016, 
            0x0000, 0x6957, 0x6864, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x175B, 
            0x0000, 0x5700, 0x6469, 0x6874, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0018, 
            0x0000, 0x6658, 0x6853, 0x7061, 0x0065, 0x0000, 0x3F80, 0x0000, 
            0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x195B, 
            0x0000, 0x4D00, 0x6469, 0x5369, 0x6168, 0x6570, 0x0000, 0x8000, 
            0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x001A, 0x0000, 0x6658, 0x6957, 0x7464, 0x0068, 0x0000, 
            0x3F80, 0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x1B5B, 0x0000, 0x4D00, 0x6469, 0x5769, 0x6469, 0x6874, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x001C, 0x0000, 0x6F50, 0x6973, 0x6974, 
            0x6E6F, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x1D5B, 0x0000, 0x5000, 
            0x736F, 0x7469, 0x6F69, 0x006E, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0xD70A, 0x3C23, 0x0000, 0x3F80, 0x0000, 0x0000, 0x1E5B, 0x0000, 
            0x5000, 0x736F, 0x7469, 0x6F69, 0x496E, 0x746E, 0x6F4D, 0x0064, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x1F5B, 0x0000, 0x5100, 0x6175, 0x746E, 0x7369, 
            0x5065, 0x736F, 0x7469, 0x6969, 0x6E6F, 0x0000, 0x8000, 0x003F, 
            0x1000, 0x0041, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0020, 0x0000, 0x6F50, 0x5373, 0x6F6D, 0x746F, 0x0068, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x215B, 0x0000, 0x5300, 0x6F6D, 0x746F, 0x4D68, 0x646F, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0022, 0x0000, 0x6946, 0x656C, 0x6950, 
            0x6374, 0x0068, 0x0000, 0xC1C0, 0x0000, 0x41C0, 0x0003, 0x3FC0, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x235B, 0x0000, 0x5000, 0x6974, 
            0x6863, 0x6853, 0x6669, 0x4F74, 0x006E, 0x0000, 0x3F80, 0x0000, 
            0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x245B, 
            0x0000, 0x4600, 0x6C69, 0x5065, 0x7469, 0x6863, 0x6F4D, 0x0064, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x255B, 0x0000, 0x5000, 0x7469, 0x6863, 0x6957, 
            0x006E, 0x0000, 0x4248, 0x4000, 0x461C, 0x6666, 0x42C0, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x265B, 0x0000, 0x5700, 0x6E69, 0x6F4D, 
            0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0xD70A, 0x3C23, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x275B, 0x0000, 0x5000, 0x7469, 0x6863, 
            0x6658, 0x0000, 0x0000, 0x0000, 0x1C40, 0x0A46, 0x1C12, 0x0046, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0028, 0x0000, 0x6950, 0x6374, 
            0x5868, 0x4D66, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0029, 0x0000, 
            0x6946, 0x656C, 0x6E49, 0x7570, 0x0074, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x51EC, 0x3DB8, 0x0000, 0x3F80, 0x0000, 0x0000, 0x2A5B, 
            0x0000, 0x4600, 0x6C69, 0x4965, 0x706E, 0x7475, 0x6F4D, 0x0064, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x2B5B, 0x0000, 0x4600, 0x6C69, 0x4D65, 0x646F, 
            0x6554, 0x706D, 0x006F, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x2C5B, 0x0000, 0x4600, 
            0x6C69, 0x4D65, 0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x002D, 0x0000, 
            0x6966, 0x656C, 0x694D, 0x4D78, 0x646F, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x002E, 0x0000, 0x6946, 0x656C, 0x6554, 0x706D, 0x006F, 0x0000, 
            0x0000, 0x0000, 0x4190, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x2F5B, 0x0000, 0x4600, 0x6C69, 0x4465, 0x7669, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0042, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0030, 0x0000, 0x6946, 0x656C, 0x6C43, 0x006B, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x315B, 0x0000, 0x4600, 0x6C69, 0x5565, 0x6573, 
            0x0072, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x325B, 0x0000, 0x4600, 0x6C69, 0x4665, 
            0x0062, 0x0000, 0x0000, 0x0000, 0x3F80, 0x51EC, 0x3E38, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x335B, 0x0000, 0x4600, 0x6C69, 0x5865, 
            0x5366, 0x6F6D, 0x746F, 0x0068, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x345B, 0x0000, 
            0x4600, 0x6C69, 0x5865, 0x5066, 0x7469, 0x6863, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0035, 0x0000, 0x6946, 0x656C, 0x6658, 0x6F70, 0x3273, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0036, 0x0000, 0x6946, 0x656C, 0x6658, 
            0x6F70, 0x7473, 0x6D65, 0x6F70, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0037, 
            0x0000, 0x6946, 0x656C, 0x6658, 0x696D, 0x0078, 0x0000, 0x3F80, 
            0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x385B, 0x0000, 0x4600, 0x6C69, 0x5865, 0x7066, 0x7469, 0x6863, 
            0x6166, 0x6564, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0039, 0x0000, 0x6946, 
            0x656C, 0x6658, 0x6977, 0x646E, 0x776F, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x0040, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x003A, 0x0000, 0x6946, 0x656C, 0x694D, 0x6964, 0x6D53, 0x6F6F, 
            0x6874, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x5B3F, 0x003B, 0x0000, 0x6946, 0x656C, 
            0x694D, 0x6964, 0x6950, 0x6374, 0x0068, 0x0000, 0x3F80, 0x0000, 
            0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x3C5B, 
            0x0000, 0x4600, 0x6C69, 0x4D65, 0x6469, 0x7069, 0x736F, 0x0032, 
            0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 0x40A0, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x3D5B, 0x0000, 0x4600, 0x6C69, 0x4D65, 0x6469, 
            0x7069, 0x736F, 0x6574, 0x706D, 0x006F, 0x0000, 0x3F80, 0x0000, 
            0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x3E5B, 
            0x0000, 0x4600, 0x6C69, 0x4D65, 0x6469, 0x6D69, 0x7869, 0x0000, 
            0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x003F, 0x0000, 0x6946, 0x656C, 0x694D, 0x6964, 
            0x6970, 0x6374, 0x6668, 0x6461, 0x0065, 0x0000, 0x3F80, 0x0000, 
            0x40E0, 0xDBB7, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x405B, 
            0x0000, 0x4600, 0x6C69, 0x4D65, 0x6469, 0x7769, 0x6E69, 0x6F64, 
            0x0077, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 0x40A0, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x415B, 0x0000, 0x4600, 0x6C69, 0x4D65, 
            0x6469, 0x4969, 0x706E, 0x7475, 0x0000, 0x8000, 0x003F, 0xE000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0042, 
            0x0000, 0x6946, 0x656C, 0x6658, 0x6E49, 0x7570, 0x0074, 0x0000, 
            0x3F80, 0x0000, 0x4080, 0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x435B, 0x0000, 0x4F00, 0x6373, 0x5032, 0x736F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0044, 0x0000, 0x734F, 0x3263, 0x6E49, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0045, 0x0000, 0x0051, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F00, 0x0000, 0x3F80, 0x0000, 0x0000, 0x465B, 
            0x0000, 0x4600, 0x6C69, 0x6574, 0x4D72, 0x7869, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0047, 0x0000, 0x6946, 0x746C, 0x7265, 0x6F4D, 0x0064, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x485B, 0x0000, 0x4300, 0x7475, 0x0031, 0x0000, 
            0x41A0, 0x4000, 0x469C, 0x0000, 0x41A0, 0x6C1A, 0x3E6B, 0x0000, 
            0x0000, 0x495B, 0x0000, 0x4300, 0x7475, 0x4D31, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x8F3F, 0x35C2, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x004A, 0x0000, 0x7543, 0x3274, 0x0000, 0xA000, 
            0x0041, 0x9C40, 0x0046, 0xA000, 0x1A41, 0x6B6C, 0x003E, 0x0000, 
            0x5B00, 0x004B, 0x0000, 0x7543, 0x3274, 0x6F4D, 0x0064, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x4C5B, 0x0000, 0x4700, 0x6961, 0x006E, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x47AE, 0x3EE1, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x4D5B, 0x0000, 0x4700, 0x6961, 0x4D6E, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x004E, 0x0000, 0x6150, 0x006E, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x4F5B, 
            0x0000, 0x5000, 0x6E61, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x505B, 
            0x0000, 0x4600, 0x6C69, 0x6574, 0x5872, 0x4D66, 0x7869, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0051, 0x0000, 0x6946, 0x746C, 0x7265, 0x6658, 
            0x7543, 0x3174, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0052, 0x0000, 0x6946, 
            0x746C, 0x7265, 0x6658, 0x7543, 0x3274, 0x0000, 0x8000, 0x003F, 
            0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0053, 0x0000, 0x6946, 0x746C, 0x7265, 0x6658, 0x6147, 0x6E69, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0054, 0x0000, 0x6946, 0x746C, 0x7265, 
            0x6658, 0x6150, 0x006E, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x555B, 0x0000, 0x4600, 
            0x6C69, 0x6574, 0x4D72, 0x6469, 0x4D69, 0x7869, 0x0000, 0x8000, 
            0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0056, 0x0000, 0x6946, 0x746C, 0x7265, 0x694D, 0x6964, 
            0x7543, 0x3174, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0057, 0x0000, 0x6946, 
            0x746C, 0x7265, 0x694D, 0x6964, 0x7543, 0x3274, 0x0000, 0x8000, 
            0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0058, 0x0000, 0x6946, 0x746C, 0x7265, 0x694D, 0x6964, 
            0x6147, 0x6E69, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0059, 0x0000, 0x6946, 
            0x746C, 0x7265, 0x694D, 0x6964, 0x6150, 0x006E, 0x0000, 0x3F80, 
            0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x5A5B, 0x0000, 0x4600, 0x6C69, 0x6574, 0x4F72, 0x6373, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x005B, 0x0000, 0x734F, 0x3263, 0x6946, 0x746C, 
            0x7265, 0x0032, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x5C5B, 0x0000, 0x6F00, 0x6373, 
            0x4732, 0x6961, 0x006E, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x5D5B, 0x0000, 0x5000, 
            0x6572, 0x6946, 0x746C, 0x7265, 0x6147, 0x6E69, 0x0000, 0xC800, 
            0x00C2, 0xC000, 0x0141, 0xA000, 0x3E41, 0xAD83, 0xCD40, 0xCCCC, 
            0x5B3D, 0x005E, 0x0000, 0x6946, 0x746C, 0x7265, 0x6F4D, 0x6564, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0xE000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x005F, 0x0000, 0x3271, 0x0000, 0x0000, 
            0x0000, 0x8000, 0xC33F, 0x28F5, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0060, 0x0000, 0x6E4F, 0x5365, 0x6F68, 0x0074, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& split2 = this->getT(0);                                                        // osc1_impl::split2_t<NV>
		auto& modchain1 = this->getT(0).getT(0);                                             // osc1_impl::modchain1_t<NV>
		auto& sliderbank3 = this->getT(0).getT(0).getT(0);                                   // osc1_impl::sliderbank3_t<NV>
		auto& split3 = this->getT(0).getT(0).getT(1);                                        // osc1_impl::split3_t<NV>
		auto& chain39 = this->getT(0).getT(0).getT(1).getT(0);                               // osc1_impl::chain39_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(1).getT(0).getT(0);                 // osc1_impl::global_cable3_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                          // math::add<NV>
		auto& gain13 = this->getT(0).getT(0).getT(1).getT(0).getT(2);                        // core::gain<NV>
		auto& chain41 = this->getT(0).getT(0).getT(1).getT(1);                               // osc1_impl::chain41_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                // osc1_impl::global_cable11_t<NV>
		auto& add26 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                         // math::add<NV>
		auto& gain15 = this->getT(0).getT(0).getT(1).getT(1).getT(2);                        // core::gain<NV>
		auto& chain40 = this->getT(0).getT(0).getT(1).getT(2);                               // osc1_impl::chain40_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(1).getT(2).getT(0);                // osc1_impl::global_cable10_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                          // math::add<NV>
		auto& gain14 = this->getT(0).getT(0).getT(1).getT(2).getT(2);                        // core::gain<NV>
		auto& chain42 = this->getT(0).getT(0).getT(1).getT(3);                               // osc1_impl::chain42_t<NV>
		auto& global_cable14 = this->getT(0).getT(0).getT(1).getT(3).getT(0);                // osc1_impl::global_cable14_t<NV>
		auto& add27 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                         // math::add<NV>
		auto& gain16 = this->getT(0).getT(0).getT(1).getT(3).getT(2);                        // core::gain<NV>
		auto& chain44 = this->getT(0).getT(0).getT(1).getT(4);                               // osc1_impl::chain44_t<NV>
		auto& event_data_reader11 = this->getT(0).getT(0).getT(1).getT(4).getT(0);           // osc1_impl::event_data_reader11_t<NV>
		auto& add29 = this->getT(0).getT(0).getT(1).getT(4).getT(1);                         // math::add<NV>
		auto& gain32 = this->getT(0).getT(0).getT(1).getT(4).getT(2);                        // core::gain<NV>
		auto& chain43 = this->getT(0).getT(0).getT(1).getT(5);                               // osc1_impl::chain43_t<NV>
		auto& event_data_reader10 = this->getT(0).getT(0).getT(1).getT(5).getT(0);           // osc1_impl::event_data_reader10_t<NV>
		auto& add28 = this->getT(0).getT(0).getT(1).getT(5).getT(1);                         // math::add<NV>
		auto& gain26 = this->getT(0).getT(0).getT(1).getT(5).getT(2);                        // core::gain<NV>
		auto& chain45 = this->getT(0).getT(0).getT(1).getT(6);                               // osc1_impl::chain45_t<NV>
		auto& event_data_reader14 = this->getT(0).getT(0).getT(1).getT(6).getT(0);           // routing::event_data_reader<NV>
		auto& add30 = this->getT(0).getT(0).getT(1).getT(6).getT(1);                         // math::add<NV>
		auto& gain33 = this->getT(0).getT(0).getT(1).getT(6).getT(2);                        // core::gain<NV>
		auto& chain46 = this->getT(0).getT(0).getT(1).getT(7);                               // osc1_impl::chain46_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(1).getT(7).getT(0);                       // osc1_impl::branch5_t<NV>
		auto& chain13 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(0);               // osc1_impl::chain13_t<NV>
		auto& midi_cc10 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc10_t<NV>
		auto& add50 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(0).getT(1);         // math::add<NV>
		auto& chain18 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(1);               // osc1_impl::chain18_t<NV>
		auto& midi_cc11 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc11_t<NV>
		auto& add51 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(1).getT(1);         // math::add<NV>
		auto& chain22 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(2);               // osc1_impl::chain22_t<NV>
		auto& midi_cc12 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc12_t<NV>
		auto& add52 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(2).getT(1);         // math::add<NV>
		auto& chain24 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(3);               // osc1_impl::chain24_t<NV>
		auto& midi_cc13 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc13_t<NV>
		auto& add53 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(3).getT(1);         // math::add<NV>
		auto& chain25 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(4);               // osc1_impl::chain25_t<NV>
		auto& midi6 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(4).getT(0);         // osc1_impl::midi6_t<NV>
		auto& add54 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(4).getT(1);         // math::add<NV>
		auto& chain26 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(5);               // osc1_impl::chain26_t<NV>
		auto& midi7 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(5).getT(0);         // osc1_impl::midi7_t<NV>
		auto& add55 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(5).getT(1);         // math::add<NV>
		auto& chain27 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(6);               // osc1_impl::chain27_t<NV>
		auto& midi8 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(6).getT(0);         // osc1_impl::midi8_t<NV>
		auto& add56 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(6).getT(1);         // math::add<NV>
		auto& gain34 = this->getT(0).getT(0).getT(1).getT(7).getT(1);                        // core::gain<NV>
		auto& peak3 = this->getT(0).getT(0).getT(2);                                         // osc1_impl::peak3_t<NV>
		auto& clear = this->getT(0).getT(0).getT(3);                                         // math::clear<NV>
		auto& chain20 = this->getT(0).getT(0).getT(4);                                       // osc1_impl::chain20_t<NV>
		auto& branch3 = this->getT(0).getT(0).getT(4).getT(0);                               // osc1_impl::branch3_t<NV>
		auto& chain17 = this->getT(0).getT(0).getT(4).getT(0).getT(0);                       // osc1_impl::chain17_t<NV>
		auto& pma1 = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(0);                  // osc1_impl::pma1_t<NV>
		auto& add = this->getT(0).getT(0).getT(4).getT(0).getT(0).getT(1);                   // math::add<NV>
		auto& chain19 = this->getT(0).getT(0).getT(4).getT(0).getT(1);                       // osc1_impl::chain19_t<NV>
		auto& pma9 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(0);                  // osc1_impl::pma9_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(4).getT(0).getT(1).getT(1);                  // math::add<NV>
		auto& chain21 = this->getT(0).getT(0).getT(4).getT(0).getT(2);                       // osc1_impl::chain21_t<NV>
		auto& pma8 = this->getT(0).getT(0).getT(4).getT(0).getT(2).getT(0);                  // osc1_impl::pma8_t<NV>
		auto& chain23 = this->getT(0).getT(0).getT(4).getT(0).getT(3);                       // osc1_impl::chain23_t<NV>
		auto& minmax = this->getT(0).getT(0).getT(4).getT(0).getT(3).getT(0);                // osc1_impl::minmax_t<NV>
		auto& pma11 = this->getT(0).getT(0).getT(4).getT(0).getT(3).getT(1);                 // osc1_impl::pma11_t<NV>
		auto& smoother = this->getT(0).getT(0).getT(4).getT(1);                              // core::smoother<NV>
		auto& peak = this->getT(0).getT(0).getT(4).getT(2);                                  // osc1_impl::peak_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(5);                                        // osc1_impl::split7_t
		auto& modchain2 = this->getT(0).getT(1);                                             // osc1_impl::modchain2_t<NV>
		auto& sliderbank4 = this->getT(0).getT(1).getT(0);                                   // osc1_impl::sliderbank4_t<NV>
		auto& split4 = this->getT(0).getT(1).getT(1);                                        // osc1_impl::split4_t<NV>
		auto& chain47 = this->getT(0).getT(1).getT(1).getT(0);                               // osc1_impl::chain47_t<NV>
		auto& global_cable4 = this->getT(0).getT(1).getT(1).getT(0).getT(0);                 // osc1_impl::global_cable4_t<NV>
		auto& add6 = this->getT(0).getT(1).getT(1).getT(0).getT(1);                          // math::add<NV>
		auto& gain17 = this->getT(0).getT(1).getT(1).getT(0).getT(2);                        // core::gain<NV>
		auto& chain48 = this->getT(0).getT(1).getT(1).getT(1);                               // osc1_impl::chain48_t<NV>
		auto& global_cable12 = this->getT(0).getT(1).getT(1).getT(1).getT(0);                // osc1_impl::global_cable12_t<NV>
		auto& add32 = this->getT(0).getT(1).getT(1).getT(1).getT(1);                         // math::add<NV>
		auto& gain18 = this->getT(0).getT(1).getT(1).getT(1).getT(2);                        // core::gain<NV>
		auto& chain49 = this->getT(0).getT(1).getT(1).getT(2);                               // osc1_impl::chain49_t<NV>
		auto& global_cable13 = this->getT(0).getT(1).getT(1).getT(2).getT(0);                // osc1_impl::global_cable13_t<NV>
		auto& add7 = this->getT(0).getT(1).getT(1).getT(2).getT(1);                          // math::add<NV>
		auto& gain19 = this->getT(0).getT(1).getT(1).getT(2).getT(2);                        // core::gain<NV>
		auto& chain50 = this->getT(0).getT(1).getT(1).getT(3);                               // osc1_impl::chain50_t<NV>
		auto& global_cable25 = this->getT(0).getT(1).getT(1).getT(3).getT(0);                // osc1_impl::global_cable25_t<NV>
		auto& add33 = this->getT(0).getT(1).getT(1).getT(3).getT(1);                         // math::add<NV>
		auto& gain20 = this->getT(0).getT(1).getT(1).getT(3).getT(2);                        // core::gain<NV>
		auto& chain51 = this->getT(0).getT(1).getT(1).getT(4);                               // osc1_impl::chain51_t<NV>
		auto& event_data_reader12 = this->getT(0).getT(1).getT(1).getT(4).getT(0);           // osc1_impl::event_data_reader12_t<NV>
		auto& add34 = this->getT(0).getT(1).getT(1).getT(4).getT(1);                         // math::add<NV>
		auto& gain35 = this->getT(0).getT(1).getT(1).getT(4).getT(2);                        // core::gain<NV>
		auto& chain52 = this->getT(0).getT(1).getT(1).getT(5);                               // osc1_impl::chain52_t<NV>
		auto& event_data_reader13 = this->getT(0).getT(1).getT(1).getT(5).getT(0);           // osc1_impl::event_data_reader13_t<NV>
		auto& add35 = this->getT(0).getT(1).getT(1).getT(5).getT(1);                         // math::add<NV>
		auto& gain27 = this->getT(0).getT(1).getT(1).getT(5).getT(2);                        // core::gain<NV>
		auto& chain53 = this->getT(0).getT(1).getT(1).getT(6);                               // osc1_impl::chain53_t<NV>
		auto& event_data_reader15 = this->getT(0).getT(1).getT(1).getT(6).getT(0);           // routing::event_data_reader<NV>
		auto& add36 = this->getT(0).getT(1).getT(1).getT(6).getT(1);                         // math::add<NV>
		auto& gain36 = this->getT(0).getT(1).getT(1).getT(6).getT(2);                        // core::gain<NV>
		auto& chain54 = this->getT(0).getT(1).getT(1).getT(7);                               // osc1_impl::chain54_t<NV>
		auto& branch4 = this->getT(0).getT(1).getT(1).getT(7).getT(0);                       // osc1_impl::branch4_t<NV>
		auto& chain = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(0);                 // osc1_impl::chain_t<NV>
		auto& midi_cc3 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(0).getT(0);      // osc1_impl::midi_cc3_t<NV>
		auto& add31 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(0).getT(1);         // math::add<NV>
		auto& chain4 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(1);                // osc1_impl::chain4_t<NV>
		auto& midi_cc5 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(1).getT(0);      // osc1_impl::midi_cc5_t<NV>
		auto& add38 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(1).getT(1);         // math::add<NV>
		auto& chain5 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(2);                // osc1_impl::chain5_t<NV>
		auto& midi_cc7 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(2).getT(0);      // osc1_impl::midi_cc7_t<NV>
		auto& add39 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(2).getT(1);         // math::add<NV>
		auto& chain6 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(3);                // osc1_impl::chain6_t<NV>
		auto& midi_cc8 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(3).getT(0);      // osc1_impl::midi_cc8_t<NV>
		auto& add40 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(3).getT(1);         // math::add<NV>
		auto& chain7 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(4);                // osc1_impl::chain7_t<NV>
		auto& midi1 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(4).getT(0);         // osc1_impl::midi1_t<NV>
		auto& add41 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(4).getT(1);         // math::add<NV>
		auto& chain9 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(5);                // osc1_impl::chain9_t<NV>
		auto& midi3 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(5).getT(0);         // osc1_impl::midi3_t<NV>
		auto& add42 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(5).getT(1);         // math::add<NV>
		auto& chain11 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(6);               // osc1_impl::chain11_t<NV>
		auto& midi5 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(6).getT(0);         // osc1_impl::midi5_t<NV>
		auto& add43 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(6).getT(1);         // math::add<NV>
		auto& gain37 = this->getT(0).getT(1).getT(1).getT(7).getT(1);                        // core::gain<NV>
		auto& peak4 = this->getT(0).getT(1).getT(2);                                         // osc1_impl::peak4_t<NV>
		auto& pma2 = this->getT(0).getT(1).getT(3);                                          // osc1_impl::pma2_t<NV>
		auto& modchain4 = this->getT(0).getT(2);                                             // osc1_impl::modchain4_t<NV>
		auto& sliderbank6 = this->getT(0).getT(2).getT(0);                                   // osc1_impl::sliderbank6_t<NV>
		auto& split6 = this->getT(0).getT(2).getT(1);                                        // osc1_impl::split6_t<NV>
		auto& chain63 = this->getT(0).getT(2).getT(1).getT(0);                               // osc1_impl::chain63_t<NV>
		auto& global_cable6 = this->getT(0).getT(2).getT(1).getT(0).getT(0);                 // osc1_impl::global_cable6_t<NV>
		auto& add10 = this->getT(0).getT(2).getT(1).getT(0).getT(1);                         // math::add<NV>
		auto& gain25 = this->getT(0).getT(2).getT(1).getT(0).getT(2);                        // core::gain<NV>
		auto& chain64 = this->getT(0).getT(2).getT(1).getT(1);                               // osc1_impl::chain64_t<NV>
		auto& global_cable16 = this->getT(0).getT(2).getT(1).getT(1).getT(0);                // osc1_impl::global_cable16_t<NV>
		auto& add44 = this->getT(0).getT(2).getT(1).getT(1).getT(1);                         // math::add<NV>
		auto& gain29 = this->getT(0).getT(2).getT(1).getT(1).getT(2);                        // core::gain<NV>
		auto& chain65 = this->getT(0).getT(2).getT(1).getT(2);                               // osc1_impl::chain65_t<NV>
		auto& global_cable17 = this->getT(0).getT(2).getT(1).getT(2).getT(0);                // osc1_impl::global_cable17_t<NV>
		auto& add11 = this->getT(0).getT(2).getT(1).getT(2).getT(1);                         // math::add<NV>
		auto& gain30 = this->getT(0).getT(2).getT(1).getT(2).getT(2);                        // core::gain<NV>
		auto& chain66 = this->getT(0).getT(2).getT(1).getT(3);                               // osc1_impl::chain66_t<NV>
		auto& global_cable26 = this->getT(0).getT(2).getT(1).getT(3).getT(0);                // osc1_impl::global_cable26_t<NV>
		auto& add45 = this->getT(0).getT(2).getT(1).getT(3).getT(1);                         // math::add<NV>
		auto& gain31 = this->getT(0).getT(2).getT(1).getT(3).getT(2);                        // core::gain<NV>
		auto& chain67 = this->getT(0).getT(2).getT(1).getT(4);                               // osc1_impl::chain67_t<NV>
		auto& event_data_reader16 = this->getT(0).getT(2).getT(1).getT(4).getT(0);           // osc1_impl::event_data_reader16_t<NV>
		auto& add46 = this->getT(0).getT(2).getT(1).getT(4).getT(1);                         // math::add<NV>
		auto& gain41 = this->getT(0).getT(2).getT(1).getT(4).getT(2);                        // core::gain<NV>
		auto& chain68 = this->getT(0).getT(2).getT(1).getT(5);                               // osc1_impl::chain68_t<NV>
		auto& event_data_reader17 = this->getT(0).getT(2).getT(1).getT(5).getT(0);           // osc1_impl::event_data_reader17_t<NV>
		auto& add47 = this->getT(0).getT(2).getT(1).getT(5).getT(1);                         // math::add<NV>
		auto& gain42 = this->getT(0).getT(2).getT(1).getT(5).getT(2);                        // core::gain<NV>
		auto& chain69 = this->getT(0).getT(2).getT(1).getT(6);                               // osc1_impl::chain69_t<NV>
		auto& event_data_reader18 = this->getT(0).getT(2).getT(1).getT(6).getT(0);           // osc1_impl::event_data_reader18_t<NV>
		auto& add48 = this->getT(0).getT(2).getT(1).getT(6).getT(1);                         // math::add<NV>
		auto& gain43 = this->getT(0).getT(2).getT(1).getT(6).getT(2);                        // core::gain<NV>
		auto& chain70 = this->getT(0).getT(2).getT(1).getT(7);                               // osc1_impl::chain70_t<NV>
		auto& branch6 = this->getT(0).getT(2).getT(1).getT(7).getT(0);                       // osc1_impl::branch6_t<NV>
		auto& chain28 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(0);               // osc1_impl::chain28_t<NV>
		auto& midi_cc14 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc14_t<NV>
		auto& add57 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(0).getT(1);         // math::add<NV>
		auto& chain29 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(1);               // osc1_impl::chain29_t<NV>
		auto& midi_cc15 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc15_t<NV>
		auto& add58 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(1).getT(1);         // math::add<NV>
		auto& chain30 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(2);               // osc1_impl::chain30_t<NV>
		auto& midi_cc16 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc16_t<NV>
		auto& add59 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(2).getT(1);         // math::add<NV>
		auto& chain31 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(3);               // osc1_impl::chain31_t<NV>
		auto& midi_cc17 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc17_t<NV>
		auto& add60 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(3).getT(1);         // math::add<NV>
		auto& chain32 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(4);               // osc1_impl::chain32_t<NV>
		auto& midi9 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(4).getT(0);         // osc1_impl::midi9_t<NV>
		auto& add61 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(4).getT(1);         // math::add<NV>
		auto& chain33 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(5);               // osc1_impl::chain33_t<NV>
		auto& midi10 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(5).getT(0);        // osc1_impl::midi10_t<NV>
		auto& add62 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(5).getT(1);         // math::add<NV>
		auto& chain34 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(6);               // osc1_impl::chain34_t<NV>
		auto& midi11 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(6).getT(0);        // osc1_impl::midi11_t<NV>
		auto& add63 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(6).getT(1);         // math::add<NV>
		auto& gain44 = this->getT(0).getT(2).getT(1).getT(7).getT(1);                        // core::gain<NV>
		auto& peak6 = this->getT(0).getT(2).getT(2);                                         // osc1_impl::peak6_t<NV>
		auto& pma4 = this->getT(0).getT(2).getT(3);                                          // osc1_impl::pma4_t<NV>
		auto& modchain7 = this->getT(0).getT(3);                                             // osc1_impl::modchain7_t<NV>
		auto& sliderbank9 = this->getT(0).getT(3).getT(0);                                   // osc1_impl::sliderbank9_t<NV>
		auto& split11 = this->getT(0).getT(3).getT(1);                                       // osc1_impl::split11_t<NV>
		auto& chain116 = this->getT(0).getT(3).getT(1).getT(0);                              // osc1_impl::chain116_t<NV>
		auto& global_cable9 = this->getT(0).getT(3).getT(1).getT(0).getT(0);                 // osc1_impl::global_cable9_t<NV>
		auto& add16 = this->getT(0).getT(3).getT(1).getT(0).getT(1);                         // math::add<NV>
		auto& gain81 = this->getT(0).getT(3).getT(1).getT(0).getT(2);                        // core::gain<NV>
		auto& chain117 = this->getT(0).getT(3).getT(1).getT(1);                              // osc1_impl::chain117_t<NV>
		auto& global_cable22 = this->getT(0).getT(3).getT(1).getT(1).getT(0);                // osc1_impl::global_cable22_t<NV>
		auto& add87 = this->getT(0).getT(3).getT(1).getT(1).getT(1);                         // math::add<NV>
		auto& gain82 = this->getT(0).getT(3).getT(1).getT(1).getT(2);                        // core::gain<NV>
		auto& chain118 = this->getT(0).getT(3).getT(1).getT(2);                              // osc1_impl::chain118_t<NV>
		auto& global_cable23 = this->getT(0).getT(3).getT(1).getT(2).getT(0);                // osc1_impl::global_cable23_t<NV>
		auto& add17 = this->getT(0).getT(3).getT(1).getT(2).getT(1);                         // math::add<NV>
		auto& gain83 = this->getT(0).getT(3).getT(1).getT(2).getT(2);                        // core::gain<NV>
		auto& chain119 = this->getT(0).getT(3).getT(1).getT(3);                              // osc1_impl::chain119_t<NV>
		auto& global_cable29 = this->getT(0).getT(3).getT(1).getT(3).getT(0);                // osc1_impl::global_cable29_t<NV>
		auto& add88 = this->getT(0).getT(3).getT(1).getT(3).getT(1);                         // math::add<NV>
		auto& gain84 = this->getT(0).getT(3).getT(1).getT(3).getT(2);                        // core::gain<NV>
		auto& chain120 = this->getT(0).getT(3).getT(1).getT(4);                              // osc1_impl::chain120_t<NV>
		auto& event_data_reader25 = this->getT(0).getT(3).getT(1).getT(4).getT(0);           // osc1_impl::event_data_reader25_t<NV>
		auto& add89 = this->getT(0).getT(3).getT(1).getT(4).getT(1);                         // math::add<NV>
		auto& gain85 = this->getT(0).getT(3).getT(1).getT(4).getT(2);                        // core::gain<NV>
		auto& chain121 = this->getT(0).getT(3).getT(1).getT(5);                              // osc1_impl::chain121_t<NV>
		auto& event_data_reader26 = this->getT(0).getT(3).getT(1).getT(5).getT(0);           // osc1_impl::event_data_reader26_t<NV>
		auto& add90 = this->getT(0).getT(3).getT(1).getT(5).getT(1);                         // math::add<NV>
		auto& gain86 = this->getT(0).getT(3).getT(1).getT(5).getT(2);                        // core::gain<NV>
		auto& chain122 = this->getT(0).getT(3).getT(1).getT(6);                              // osc1_impl::chain122_t<NV>
		auto& event_data_reader27 = this->getT(0).getT(3).getT(1).getT(6).getT(0);           // osc1_impl::event_data_reader27_t<NV>
		auto& add91 = this->getT(0).getT(3).getT(1).getT(6).getT(1);                         // math::add<NV>
		auto& gain87 = this->getT(0).getT(3).getT(1).getT(6).getT(2);                        // core::gain<NV>
		auto& chain123 = this->getT(0).getT(3).getT(1).getT(7);                              // osc1_impl::chain123_t<NV>
		auto& branch9 = this->getT(0).getT(3).getT(1).getT(7).getT(0);                       // osc1_impl::branch9_t<NV>
		auto& chain124 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(0);              // osc1_impl::chain124_t<NV>
		auto& midi_cc26 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc26_t<NV>
		auto& add92 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(0).getT(1);         // math::add<NV>
		auto& chain125 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(1);              // osc1_impl::chain125_t<NV>
		auto& midi_cc27 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc27_t<NV>
		auto& add93 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(1).getT(1);         // math::add<NV>
		auto& chain126 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(2);              // osc1_impl::chain126_t<NV>
		auto& midi_cc28 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc28_t<NV>
		auto& add94 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(2).getT(1);         // math::add<NV>
		auto& chain127 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(3);              // osc1_impl::chain127_t<NV>
		auto& midi_cc29 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc29_t<NV>
		auto& add95 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(3).getT(1);         // math::add<NV>
		auto& chain128 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(4);              // osc1_impl::chain128_t<NV>
		auto& midi18 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(4).getT(0);        // osc1_impl::midi18_t<NV>
		auto& add96 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(4).getT(1);         // math::add<NV>
		auto& chain129 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(5);              // osc1_impl::chain129_t<NV>
		auto& midi19 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(5).getT(0);        // osc1_impl::midi19_t<NV>
		auto& add97 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(5).getT(1);         // math::add<NV>
		auto& chain130 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(6);              // osc1_impl::chain130_t<NV>
		auto& midi20 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(6).getT(0);        // osc1_impl::midi20_t<NV>
		auto& add98 = this->getT(0).getT(3).getT(1).getT(7).getT(0).getT(6).getT(1);         // math::add<NV>
		auto& gain88 = this->getT(0).getT(3).getT(1).getT(7).getT(1);                        // core::gain<NV>
		auto& peak9 = this->getT(0).getT(3).getT(2);                                         // osc1_impl::peak9_t<NV>
		auto& pma12 = this->getT(0).getT(3).getT(3);                                         // osc1_impl::pma12_t<NV>
		auto& modchain6 = this->getT(0).getT(4);                                             // osc1_impl::modchain6_t<NV>
		auto& sliderbank8 = this->getT(0).getT(4).getT(0);                                   // osc1_impl::sliderbank8_t<NV>
		auto& split10 = this->getT(0).getT(4).getT(1);                                       // osc1_impl::split10_t<NV>
		auto& chain101 = this->getT(0).getT(4).getT(1).getT(0);                              // osc1_impl::chain101_t<NV>
		auto& global_cable8 = this->getT(0).getT(4).getT(1).getT(0).getT(0);                 // osc1_impl::global_cable8_t<NV>
		auto& add14 = this->getT(0).getT(4).getT(1).getT(0).getT(1);                         // math::add<NV>
		auto& gain73 = this->getT(0).getT(4).getT(1).getT(0).getT(2);                        // core::gain<NV>
		auto& chain102 = this->getT(0).getT(4).getT(1).getT(1);                              // osc1_impl::chain102_t<NV>
		auto& global_cable20 = this->getT(0).getT(4).getT(1).getT(1).getT(0);                // osc1_impl::global_cable20_t<NV>
		auto& add75 = this->getT(0).getT(4).getT(1).getT(1).getT(1);                         // math::add<NV>
		auto& gain74 = this->getT(0).getT(4).getT(1).getT(1).getT(2);                        // core::gain<NV>
		auto& chain103 = this->getT(0).getT(4).getT(1).getT(2);                              // osc1_impl::chain103_t<NV>
		auto& global_cable21 = this->getT(0).getT(4).getT(1).getT(2).getT(0);                // osc1_impl::global_cable21_t<NV>
		auto& add15 = this->getT(0).getT(4).getT(1).getT(2).getT(1);                         // math::add<NV>
		auto& gain75 = this->getT(0).getT(4).getT(1).getT(2).getT(2);                        // core::gain<NV>
		auto& chain104 = this->getT(0).getT(4).getT(1).getT(3);                              // osc1_impl::chain104_t<NV>
		auto& global_cable28 = this->getT(0).getT(4).getT(1).getT(3).getT(0);                // osc1_impl::global_cable28_t<NV>
		auto& add76 = this->getT(0).getT(4).getT(1).getT(3).getT(1);                         // math::add<NV>
		auto& gain76 = this->getT(0).getT(4).getT(1).getT(3).getT(2);                        // core::gain<NV>
		auto& chain105 = this->getT(0).getT(4).getT(1).getT(4);                              // osc1_impl::chain105_t<NV>
		auto& event_data_reader22 = this->getT(0).getT(4).getT(1).getT(4).getT(0);           // osc1_impl::event_data_reader22_t<NV>
		auto& add77 = this->getT(0).getT(4).getT(1).getT(4).getT(1);                         // math::add<NV>
		auto& gain77 = this->getT(0).getT(4).getT(1).getT(4).getT(2);                        // core::gain<NV>
		auto& chain106 = this->getT(0).getT(4).getT(1).getT(5);                              // osc1_impl::chain106_t<NV>
		auto& event_data_reader23 = this->getT(0).getT(4).getT(1).getT(5).getT(0);           // osc1_impl::event_data_reader23_t<NV>
		auto& add78 = this->getT(0).getT(4).getT(1).getT(5).getT(1);                         // math::add<NV>
		auto& gain78 = this->getT(0).getT(4).getT(1).getT(5).getT(2);                        // core::gain<NV>
		auto& chain107 = this->getT(0).getT(4).getT(1).getT(6);                              // osc1_impl::chain107_t<NV>
		auto& event_data_reader24 = this->getT(0).getT(4).getT(1).getT(6).getT(0);           // osc1_impl::event_data_reader24_t<NV>
		auto& add79 = this->getT(0).getT(4).getT(1).getT(6).getT(1);                         // math::add<NV>
		auto& gain79 = this->getT(0).getT(4).getT(1).getT(6).getT(2);                        // core::gain<NV>
		auto& chain108 = this->getT(0).getT(4).getT(1).getT(7);                              // osc1_impl::chain108_t<NV>
		auto& branch8 = this->getT(0).getT(4).getT(1).getT(7).getT(0);                       // osc1_impl::branch8_t<NV>
		auto& chain109 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(0);              // osc1_impl::chain109_t<NV>
		auto& midi_cc22 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc22_t<NV>
		auto& add80 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(0).getT(1);         // math::add<NV>
		auto& chain110 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(1);              // osc1_impl::chain110_t<NV>
		auto& midi_cc23 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc23_t<NV>
		auto& add81 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(1).getT(1);         // math::add<NV>
		auto& chain111 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(2);              // osc1_impl::chain111_t<NV>
		auto& midi_cc24 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc24_t<NV>
		auto& add82 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(2).getT(1);         // math::add<NV>
		auto& chain112 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(3);              // osc1_impl::chain112_t<NV>
		auto& midi_cc25 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc25_t<NV>
		auto& add83 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(3).getT(1);         // math::add<NV>
		auto& chain113 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(4);              // osc1_impl::chain113_t<NV>
		auto& midi15 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(4).getT(0);        // osc1_impl::midi15_t<NV>
		auto& add84 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(4).getT(1);         // math::add<NV>
		auto& chain114 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(5);              // osc1_impl::chain114_t<NV>
		auto& midi16 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(5).getT(0);        // osc1_impl::midi16_t<NV>
		auto& add85 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(5).getT(1);         // math::add<NV>
		auto& chain115 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(6);              // osc1_impl::chain115_t<NV>
		auto& midi17 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(6).getT(0);        // osc1_impl::midi17_t<NV>
		auto& add86 = this->getT(0).getT(4).getT(1).getT(7).getT(0).getT(6).getT(1);         // math::add<NV>
		auto& gain80 = this->getT(0).getT(4).getT(1).getT(7).getT(1);                        // core::gain<NV>
		auto& peak8 = this->getT(0).getT(4).getT(2);                                         // osc1_impl::peak8_t<NV>
		auto& pma10 = this->getT(0).getT(4).getT(3);                                         // osc1_impl::pma10_t<NV>
		auto& modchain19 = this->getT(0).getT(5);                                            // osc1_impl::modchain19_t<NV>
		auto& sliderbank18 = this->getT(0).getT(5).getT(0);                                  // osc1_impl::sliderbank18_t<NV>
		auto& split41 = this->getT(0).getT(5).getT(1);                                       // osc1_impl::split41_t<NV>
		auto& chain300 = this->getT(0).getT(5).getT(1).getT(0);                              // osc1_impl::chain300_t<NV>
		auto& global_cable63 = this->getT(0).getT(5).getT(1).getT(0).getT(0);                // osc1_impl::global_cable63_t<NV>
		auto& add254 = this->getT(0).getT(5).getT(1).getT(0).getT(1);                        // math::add<NV>
		auto& gain148 = this->getT(0).getT(5).getT(1).getT(0).getT(2);                       // core::gain<NV>
		auto& chain301 = this->getT(0).getT(5).getT(1).getT(1);                              // osc1_impl::chain301_t<NV>
		auto& global_cable64 = this->getT(0).getT(5).getT(1).getT(1).getT(0);                // osc1_impl::global_cable64_t<NV>
		auto& add255 = this->getT(0).getT(5).getT(1).getT(1).getT(1);                        // math::add<NV>
		auto& gain149 = this->getT(0).getT(5).getT(1).getT(1).getT(2);                       // core::gain<NV>
		auto& chain302 = this->getT(0).getT(5).getT(1).getT(2);                              // osc1_impl::chain302_t<NV>
		auto& global_cable65 = this->getT(0).getT(5).getT(1).getT(2).getT(0);                // osc1_impl::global_cable65_t<NV>
		auto& add256 = this->getT(0).getT(5).getT(1).getT(2).getT(1);                        // math::add<NV>
		auto& gain150 = this->getT(0).getT(5).getT(1).getT(2).getT(2);                       // core::gain<NV>
		auto& chain303 = this->getT(0).getT(5).getT(1).getT(3);                              // osc1_impl::chain303_t<NV>
		auto& global_cable66 = this->getT(0).getT(5).getT(1).getT(3).getT(0);                // osc1_impl::global_cable66_t<NV>
		auto& add257 = this->getT(0).getT(5).getT(1).getT(3).getT(1);                        // math::add<NV>
		auto& gain151 = this->getT(0).getT(5).getT(1).getT(3).getT(2);                       // core::gain<NV>
		auto& chain304 = this->getT(0).getT(5).getT(1).getT(4);                              // osc1_impl::chain304_t<NV>
		auto& event_data_reader55 = this->getT(0).getT(5).getT(1).getT(4).getT(0);           // osc1_impl::event_data_reader55_t<NV>
		auto& add258 = this->getT(0).getT(5).getT(1).getT(4).getT(1);                        // math::add<NV>
		auto& gain152 = this->getT(0).getT(5).getT(1).getT(4).getT(2);                       // core::gain<NV>
		auto& chain305 = this->getT(0).getT(5).getT(1).getT(5);                              // osc1_impl::chain305_t<NV>
		auto& event_data_reader56 = this->getT(0).getT(5).getT(1).getT(5).getT(0);           // osc1_impl::event_data_reader56_t<NV>
		auto& add259 = this->getT(0).getT(5).getT(1).getT(5).getT(1);                        // math::add<NV>
		auto& gain153 = this->getT(0).getT(5).getT(1).getT(5).getT(2);                       // core::gain<NV>
		auto& chain306 = this->getT(0).getT(5).getT(1).getT(6);                              // osc1_impl::chain306_t<NV>
		auto& event_data_reader57 = this->getT(0).getT(5).getT(1).getT(6).getT(0);           // osc1_impl::event_data_reader57_t<NV>
		auto& add260 = this->getT(0).getT(5).getT(1).getT(6).getT(1);                        // math::add<NV>
		auto& gain154 = this->getT(0).getT(5).getT(1).getT(6).getT(2);                       // core::gain<NV>
		auto& chain307 = this->getT(0).getT(5).getT(1).getT(7);                              // osc1_impl::chain307_t<NV>
		auto& branch28 = this->getT(0).getT(5).getT(1).getT(7).getT(0);                      // osc1_impl::branch28_t<NV>
		auto& chain308 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(0);              // osc1_impl::chain308_t<NV>
		auto& midi_cc66 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc66_t<NV>
		auto& add261 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(0).getT(1);        // math::add<NV>
		auto& chain309 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(1);              // osc1_impl::chain309_t<NV>
		auto& midi_cc67 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc67_t<NV>
		auto& add262 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(1).getT(1);        // math::add<NV>
		auto& chain310 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(2);              // osc1_impl::chain310_t<NV>
		auto& midi_cc68 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc68_t<NV>
		auto& add263 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(2).getT(1);        // math::add<NV>
		auto& chain311 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(3);              // osc1_impl::chain311_t<NV>
		auto& midi_cc69 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc69_t<NV>
		auto& add264 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(3).getT(1);        // math::add<NV>
		auto& chain312 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(4);              // osc1_impl::chain312_t<NV>
		auto& midi49 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(4).getT(0);        // osc1_impl::midi49_t<NV>
		auto& add265 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(4).getT(1);        // math::add<NV>
		auto& chain313 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(5);              // osc1_impl::chain313_t<NV>
		auto& midi50 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(5).getT(0);        // osc1_impl::midi50_t<NV>
		auto& add266 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(5).getT(1);        // math::add<NV>
		auto& chain314 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(6);              // osc1_impl::chain314_t<NV>
		auto& midi51 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(6).getT(0);        // osc1_impl::midi51_t<NV>
		auto& add267 = this->getT(0).getT(5).getT(1).getT(7).getT(0).getT(6).getT(1);        // math::add<NV>
		auto& gain155 = this->getT(0).getT(5).getT(1).getT(7).getT(1);                       // core::gain<NV>
		auto& peak23 = this->getT(0).getT(5).getT(2);                                        // osc1_impl::peak23_t<NV>
		auto& pma24 = this->getT(0).getT(5).getT(3);                                         // osc1_impl::pma24_t<NV>
		auto& modchain20 = this->getT(0).getT(6);                                            // osc1_impl::modchain20_t<NV>
		auto& sliderbank19 = this->getT(0).getT(6).getT(0);                                  // osc1_impl::sliderbank19_t<NV>
		auto& split42 = this->getT(0).getT(6).getT(1);                                       // osc1_impl::split42_t<NV>
		auto& chain315 = this->getT(0).getT(6).getT(1).getT(0);                              // osc1_impl::chain315_t<NV>
		auto& global_cable67 = this->getT(0).getT(6).getT(1).getT(0).getT(0);                // osc1_impl::global_cable67_t<NV>
		auto& add268 = this->getT(0).getT(6).getT(1).getT(0).getT(1);                        // math::add<NV>
		auto& gain156 = this->getT(0).getT(6).getT(1).getT(0).getT(2);                       // core::gain<NV>
		auto& chain316 = this->getT(0).getT(6).getT(1).getT(1);                              // osc1_impl::chain316_t<NV>
		auto& global_cable68 = this->getT(0).getT(6).getT(1).getT(1).getT(0);                // osc1_impl::global_cable68_t<NV>
		auto& add269 = this->getT(0).getT(6).getT(1).getT(1).getT(1);                        // math::add<NV>
		auto& gain157 = this->getT(0).getT(6).getT(1).getT(1).getT(2);                       // core::gain<NV>
		auto& chain317 = this->getT(0).getT(6).getT(1).getT(2);                              // osc1_impl::chain317_t<NV>
		auto& global_cable69 = this->getT(0).getT(6).getT(1).getT(2).getT(0);                // osc1_impl::global_cable69_t<NV>
		auto& add270 = this->getT(0).getT(6).getT(1).getT(2).getT(1);                        // math::add<NV>
		auto& gain158 = this->getT(0).getT(6).getT(1).getT(2).getT(2);                       // core::gain<NV>
		auto& chain318 = this->getT(0).getT(6).getT(1).getT(3);                              // osc1_impl::chain318_t<NV>
		auto& global_cable70 = this->getT(0).getT(6).getT(1).getT(3).getT(0);                // osc1_impl::global_cable70_t<NV>
		auto& add271 = this->getT(0).getT(6).getT(1).getT(3).getT(1);                        // math::add<NV>
		auto& gain159 = this->getT(0).getT(6).getT(1).getT(3).getT(2);                       // core::gain<NV>
		auto& chain319 = this->getT(0).getT(6).getT(1).getT(4);                              // osc1_impl::chain319_t<NV>
		auto& event_data_reader58 = this->getT(0).getT(6).getT(1).getT(4).getT(0);           // osc1_impl::event_data_reader58_t<NV>
		auto& add272 = this->getT(0).getT(6).getT(1).getT(4).getT(1);                        // math::add<NV>
		auto& gain160 = this->getT(0).getT(6).getT(1).getT(4).getT(2);                       // core::gain<NV>
		auto& chain320 = this->getT(0).getT(6).getT(1).getT(5);                              // osc1_impl::chain320_t<NV>
		auto& event_data_reader59 = this->getT(0).getT(6).getT(1).getT(5).getT(0);           // osc1_impl::event_data_reader59_t<NV>
		auto& add273 = this->getT(0).getT(6).getT(1).getT(5).getT(1);                        // math::add<NV>
		auto& gain161 = this->getT(0).getT(6).getT(1).getT(5).getT(2);                       // core::gain<NV>
		auto& chain321 = this->getT(0).getT(6).getT(1).getT(6);                              // osc1_impl::chain321_t<NV>
		auto& event_data_reader60 = this->getT(0).getT(6).getT(1).getT(6).getT(0);           // osc1_impl::event_data_reader60_t<NV>
		auto& add274 = this->getT(0).getT(6).getT(1).getT(6).getT(1);                        // math::add<NV>
		auto& gain162 = this->getT(0).getT(6).getT(1).getT(6).getT(2);                       // core::gain<NV>
		auto& chain322 = this->getT(0).getT(6).getT(1).getT(7);                              // osc1_impl::chain322_t<NV>
		auto& branch29 = this->getT(0).getT(6).getT(1).getT(7).getT(0);                      // osc1_impl::branch29_t<NV>
		auto& chain323 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(0);              // osc1_impl::chain323_t<NV>
		auto& midi_cc70 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc70_t<NV>
		auto& add275 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(0).getT(1);        // math::add<NV>
		auto& chain324 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(1);              // osc1_impl::chain324_t<NV>
		auto& midi_cc71 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc71_t<NV>
		auto& add276 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(1).getT(1);        // math::add<NV>
		auto& chain325 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(2);              // osc1_impl::chain325_t<NV>
		auto& midi_cc72 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc72_t<NV>
		auto& add277 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(2).getT(1);        // math::add<NV>
		auto& chain326 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(3);              // osc1_impl::chain326_t<NV>
		auto& midi_cc73 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc73_t<NV>
		auto& add278 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(3).getT(1);        // math::add<NV>
		auto& chain327 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(4);              // osc1_impl::chain327_t<NV>
		auto& midi52 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(4).getT(0);        // osc1_impl::midi52_t<NV>
		auto& add279 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(4).getT(1);        // math::add<NV>
		auto& chain328 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(5);              // osc1_impl::chain328_t<NV>
		auto& midi53 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(5).getT(0);        // osc1_impl::midi53_t<NV>
		auto& add280 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(5).getT(1);        // math::add<NV>
		auto& chain329 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(6);              // osc1_impl::chain329_t<NV>
		auto& midi54 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(6).getT(0);        // osc1_impl::midi54_t<NV>
		auto& add281 = this->getT(0).getT(6).getT(1).getT(7).getT(0).getT(6).getT(1);        // math::add<NV>
		auto& gain163 = this->getT(0).getT(6).getT(1).getT(7).getT(1);                       // core::gain<NV>
		auto& peak24 = this->getT(0).getT(6).getT(2);                                        // osc1_impl::peak24_t<NV>
		auto& pma26 = this->getT(0).getT(6).getT(3);                                         // osc1_impl::pma26_t<NV>
		auto& modchain21 = this->getT(0).getT(7);                                            // osc1_impl::modchain21_t<NV>
		auto& sliderbank20 = this->getT(0).getT(7).getT(0);                                  // osc1_impl::sliderbank20_t<NV>
		auto& split43 = this->getT(0).getT(7).getT(1);                                       // osc1_impl::split43_t<NV>
		auto& chain330 = this->getT(0).getT(7).getT(1).getT(0);                              // osc1_impl::chain330_t<NV>
		auto& global_cable71 = this->getT(0).getT(7).getT(1).getT(0).getT(0);                // osc1_impl::global_cable71_t<NV>
		auto& add282 = this->getT(0).getT(7).getT(1).getT(0).getT(1);                        // math::add<NV>
		auto& gain164 = this->getT(0).getT(7).getT(1).getT(0).getT(2);                       // core::gain<NV>
		auto& chain331 = this->getT(0).getT(7).getT(1).getT(1);                              // osc1_impl::chain331_t<NV>
		auto& global_cable72 = this->getT(0).getT(7).getT(1).getT(1).getT(0);                // osc1_impl::global_cable72_t<NV>
		auto& add283 = this->getT(0).getT(7).getT(1).getT(1).getT(1);                        // math::add<NV>
		auto& gain165 = this->getT(0).getT(7).getT(1).getT(1).getT(2);                       // core::gain<NV>
		auto& chain332 = this->getT(0).getT(7).getT(1).getT(2);                              // osc1_impl::chain332_t<NV>
		auto& global_cable73 = this->getT(0).getT(7).getT(1).getT(2).getT(0);                // osc1_impl::global_cable73_t<NV>
		auto& add284 = this->getT(0).getT(7).getT(1).getT(2).getT(1);                        // math::add<NV>
		auto& gain166 = this->getT(0).getT(7).getT(1).getT(2).getT(2);                       // core::gain<NV>
		auto& chain333 = this->getT(0).getT(7).getT(1).getT(3);                              // osc1_impl::chain333_t<NV>
		auto& global_cable74 = this->getT(0).getT(7).getT(1).getT(3).getT(0);                // osc1_impl::global_cable74_t<NV>
		auto& add285 = this->getT(0).getT(7).getT(1).getT(3).getT(1);                        // math::add<NV>
		auto& gain167 = this->getT(0).getT(7).getT(1).getT(3).getT(2);                       // core::gain<NV>
		auto& chain334 = this->getT(0).getT(7).getT(1).getT(4);                              // osc1_impl::chain334_t<NV>
		auto& event_data_reader61 = this->getT(0).getT(7).getT(1).getT(4).getT(0);           // osc1_impl::event_data_reader61_t<NV>
		auto& add286 = this->getT(0).getT(7).getT(1).getT(4).getT(1);                        // math::add<NV>
		auto& gain168 = this->getT(0).getT(7).getT(1).getT(4).getT(2);                       // core::gain<NV>
		auto& chain335 = this->getT(0).getT(7).getT(1).getT(5);                              // osc1_impl::chain335_t<NV>
		auto& event_data_reader62 = this->getT(0).getT(7).getT(1).getT(5).getT(0);           // osc1_impl::event_data_reader62_t<NV>
		auto& add287 = this->getT(0).getT(7).getT(1).getT(5).getT(1);                        // math::add<NV>
		auto& gain169 = this->getT(0).getT(7).getT(1).getT(5).getT(2);                       // core::gain<NV>
		auto& chain336 = this->getT(0).getT(7).getT(1).getT(6);                              // osc1_impl::chain336_t<NV>
		auto& event_data_reader63 = this->getT(0).getT(7).getT(1).getT(6).getT(0);           // osc1_impl::event_data_reader63_t<NV>
		auto& add288 = this->getT(0).getT(7).getT(1).getT(6).getT(1);                        // math::add<NV>
		auto& gain170 = this->getT(0).getT(7).getT(1).getT(6).getT(2);                       // core::gain<NV>
		auto& chain337 = this->getT(0).getT(7).getT(1).getT(7);                              // osc1_impl::chain337_t<NV>
		auto& branch30 = this->getT(0).getT(7).getT(1).getT(7).getT(0);                      // osc1_impl::branch30_t<NV>
		auto& chain338 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(0);              // osc1_impl::chain338_t<NV>
		auto& midi_cc74 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc74_t<NV>
		auto& add289 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(0).getT(1);        // math::add<NV>
		auto& chain339 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(1);              // osc1_impl::chain339_t<NV>
		auto& midi_cc75 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc75_t<NV>
		auto& add290 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(1).getT(1);        // math::add<NV>
		auto& chain340 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(2);              // osc1_impl::chain340_t<NV>
		auto& midi_cc76 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc76_t<NV>
		auto& add291 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(2).getT(1);        // math::add<NV>
		auto& chain341 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(3);              // osc1_impl::chain341_t<NV>
		auto& midi_cc77 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc77_t<NV>
		auto& add292 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(3).getT(1);        // math::add<NV>
		auto& chain342 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(4);              // osc1_impl::chain342_t<NV>
		auto& midi55 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(4).getT(0);        // osc1_impl::midi55_t<NV>
		auto& add293 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(4).getT(1);        // math::add<NV>
		auto& chain343 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(5);              // osc1_impl::chain343_t<NV>
		auto& midi56 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(5).getT(0);        // osc1_impl::midi56_t<NV>
		auto& add294 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(5).getT(1);        // math::add<NV>
		auto& chain344 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(6);              // osc1_impl::chain344_t<NV>
		auto& midi57 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(6).getT(0);        // osc1_impl::midi57_t<NV>
		auto& add295 = this->getT(0).getT(7).getT(1).getT(7).getT(0).getT(6).getT(1);        // math::add<NV>
		auto& gain171 = this->getT(0).getT(7).getT(1).getT(7).getT(1);                       // core::gain<NV>
		auto& peak25 = this->getT(0).getT(7).getT(2);                                        // osc1_impl::peak25_t<NV>
		auto& pma40 = this->getT(0).getT(7).getT(3);                                         // osc1_impl::pma40_t<NV>
		auto& modchain22 = this->getT(0).getT(8);                                            // osc1_impl::modchain22_t<NV>
		auto& sliderbank21 = this->getT(0).getT(8).getT(0);                                  // osc1_impl::sliderbank21_t<NV>
		auto& split44 = this->getT(0).getT(8).getT(1);                                       // osc1_impl::split44_t<NV>
		auto& chain345 = this->getT(0).getT(8).getT(1).getT(0);                              // osc1_impl::chain345_t<NV>
		auto& global_cable75 = this->getT(0).getT(8).getT(1).getT(0).getT(0);                // osc1_impl::global_cable75_t<NV>
		auto& add296 = this->getT(0).getT(8).getT(1).getT(0).getT(1);                        // math::add<NV>
		auto& gain172 = this->getT(0).getT(8).getT(1).getT(0).getT(2);                       // core::gain<NV>
		auto& chain346 = this->getT(0).getT(8).getT(1).getT(1);                              // osc1_impl::chain346_t<NV>
		auto& global_cable76 = this->getT(0).getT(8).getT(1).getT(1).getT(0);                // osc1_impl::global_cable76_t<NV>
		auto& add297 = this->getT(0).getT(8).getT(1).getT(1).getT(1);                        // math::add<NV>
		auto& gain173 = this->getT(0).getT(8).getT(1).getT(1).getT(2);                       // core::gain<NV>
		auto& chain347 = this->getT(0).getT(8).getT(1).getT(2);                              // osc1_impl::chain347_t<NV>
		auto& global_cable77 = this->getT(0).getT(8).getT(1).getT(2).getT(0);                // osc1_impl::global_cable77_t<NV>
		auto& add298 = this->getT(0).getT(8).getT(1).getT(2).getT(1);                        // math::add<NV>
		auto& gain174 = this->getT(0).getT(8).getT(1).getT(2).getT(2);                       // core::gain<NV>
		auto& chain348 = this->getT(0).getT(8).getT(1).getT(3);                              // osc1_impl::chain348_t<NV>
		auto& global_cable78 = this->getT(0).getT(8).getT(1).getT(3).getT(0);                // osc1_impl::global_cable78_t<NV>
		auto& add299 = this->getT(0).getT(8).getT(1).getT(3).getT(1);                        // math::add<NV>
		auto& gain175 = this->getT(0).getT(8).getT(1).getT(3).getT(2);                       // core::gain<NV>
		auto& chain349 = this->getT(0).getT(8).getT(1).getT(4);                              // osc1_impl::chain349_t<NV>
		auto& event_data_reader64 = this->getT(0).getT(8).getT(1).getT(4).getT(0);           // osc1_impl::event_data_reader64_t<NV>
		auto& add300 = this->getT(0).getT(8).getT(1).getT(4).getT(1);                        // math::add<NV>
		auto& gain176 = this->getT(0).getT(8).getT(1).getT(4).getT(2);                       // core::gain<NV>
		auto& chain350 = this->getT(0).getT(8).getT(1).getT(5);                              // osc1_impl::chain350_t<NV>
		auto& event_data_reader65 = this->getT(0).getT(8).getT(1).getT(5).getT(0);           // osc1_impl::event_data_reader65_t<NV>
		auto& add301 = this->getT(0).getT(8).getT(1).getT(5).getT(1);                        // math::add<NV>
		auto& gain177 = this->getT(0).getT(8).getT(1).getT(5).getT(2);                       // core::gain<NV>
		auto& chain351 = this->getT(0).getT(8).getT(1).getT(6);                              // osc1_impl::chain351_t<NV>
		auto& event_data_reader66 = this->getT(0).getT(8).getT(1).getT(6).getT(0);           // osc1_impl::event_data_reader66_t<NV>
		auto& add302 = this->getT(0).getT(8).getT(1).getT(6).getT(1);                        // math::add<NV>
		auto& gain178 = this->getT(0).getT(8).getT(1).getT(6).getT(2);                       // core::gain<NV>
		auto& chain352 = this->getT(0).getT(8).getT(1).getT(7);                              // osc1_impl::chain352_t<NV>
		auto& branch31 = this->getT(0).getT(8).getT(1).getT(7).getT(0);                      // osc1_impl::branch31_t<NV>
		auto& chain353 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(0);              // osc1_impl::chain353_t<NV>
		auto& midi_cc78 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc78_t<NV>
		auto& add303 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(0).getT(1);        // math::add<NV>
		auto& chain354 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(1);              // osc1_impl::chain354_t<NV>
		auto& midi_cc79 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc79_t<NV>
		auto& add304 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(1).getT(1);        // math::add<NV>
		auto& chain355 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(2);              // osc1_impl::chain355_t<NV>
		auto& midi_cc80 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc80_t<NV>
		auto& add305 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(2).getT(1);        // math::add<NV>
		auto& chain356 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(3);              // osc1_impl::chain356_t<NV>
		auto& midi_cc81 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc81_t<NV>
		auto& add306 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(3).getT(1);        // math::add<NV>
		auto& chain357 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(4);              // osc1_impl::chain357_t<NV>
		auto& midi58 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(4).getT(0);        // osc1_impl::midi58_t<NV>
		auto& add307 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(4).getT(1);        // math::add<NV>
		auto& chain358 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(5);              // osc1_impl::chain358_t<NV>
		auto& midi59 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(5).getT(0);        // osc1_impl::midi59_t<NV>
		auto& add308 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(5).getT(1);        // math::add<NV>
		auto& chain359 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(6);              // osc1_impl::chain359_t<NV>
		auto& midi60 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(6).getT(0);        // osc1_impl::midi60_t<NV>
		auto& add309 = this->getT(0).getT(8).getT(1).getT(7).getT(0).getT(6).getT(1);        // math::add<NV>
		auto& gain179 = this->getT(0).getT(8).getT(1).getT(7).getT(1);                       // core::gain<NV>
		auto& peak26 = this->getT(0).getT(8).getT(2);                                        // osc1_impl::peak26_t<NV>
		auto& pma27 = this->getT(0).getT(8).getT(3);                                         // osc1_impl::pma27_t<NV>
		auto& modchain23 = this->getT(0).getT(9);                                            // osc1_impl::modchain23_t<NV>
		auto& sliderbank22 = this->getT(0).getT(9).getT(0);                                  // osc1_impl::sliderbank22_t<NV>
		auto& split45 = this->getT(0).getT(9).getT(1);                                       // osc1_impl::split45_t<NV>
		auto& chain360 = this->getT(0).getT(9).getT(1).getT(0);                              // osc1_impl::chain360_t<NV>
		auto& global_cable79 = this->getT(0).getT(9).getT(1).getT(0).getT(0);                // osc1_impl::global_cable79_t<NV>
		auto& add310 = this->getT(0).getT(9).getT(1).getT(0).getT(1);                        // math::add<NV>
		auto& gain180 = this->getT(0).getT(9).getT(1).getT(0).getT(2);                       // core::gain<NV>
		auto& chain361 = this->getT(0).getT(9).getT(1).getT(1);                              // osc1_impl::chain361_t<NV>
		auto& global_cable80 = this->getT(0).getT(9).getT(1).getT(1).getT(0);                // osc1_impl::global_cable80_t<NV>
		auto& add311 = this->getT(0).getT(9).getT(1).getT(1).getT(1);                        // math::add<NV>
		auto& gain181 = this->getT(0).getT(9).getT(1).getT(1).getT(2);                       // core::gain<NV>
		auto& chain362 = this->getT(0).getT(9).getT(1).getT(2);                              // osc1_impl::chain362_t<NV>
		auto& global_cable81 = this->getT(0).getT(9).getT(1).getT(2).getT(0);                // osc1_impl::global_cable81_t<NV>
		auto& add312 = this->getT(0).getT(9).getT(1).getT(2).getT(1);                        // math::add<NV>
		auto& gain182 = this->getT(0).getT(9).getT(1).getT(2).getT(2);                       // core::gain<NV>
		auto& chain363 = this->getT(0).getT(9).getT(1).getT(3);                              // osc1_impl::chain363_t<NV>
		auto& global_cable82 = this->getT(0).getT(9).getT(1).getT(3).getT(0);                // osc1_impl::global_cable82_t<NV>
		auto& add313 = this->getT(0).getT(9).getT(1).getT(3).getT(1);                        // math::add<NV>
		auto& gain183 = this->getT(0).getT(9).getT(1).getT(3).getT(2);                       // core::gain<NV>
		auto& chain364 = this->getT(0).getT(9).getT(1).getT(4);                              // osc1_impl::chain364_t<NV>
		auto& event_data_reader67 = this->getT(0).getT(9).getT(1).getT(4).getT(0);           // osc1_impl::event_data_reader67_t<NV>
		auto& add314 = this->getT(0).getT(9).getT(1).getT(4).getT(1);                        // math::add<NV>
		auto& gain184 = this->getT(0).getT(9).getT(1).getT(4).getT(2);                       // core::gain<NV>
		auto& chain365 = this->getT(0).getT(9).getT(1).getT(5);                              // osc1_impl::chain365_t<NV>
		auto& event_data_reader68 = this->getT(0).getT(9).getT(1).getT(5).getT(0);           // osc1_impl::event_data_reader68_t<NV>
		auto& add315 = this->getT(0).getT(9).getT(1).getT(5).getT(1);                        // math::add<NV>
		auto& gain185 = this->getT(0).getT(9).getT(1).getT(5).getT(2);                       // core::gain<NV>
		auto& chain366 = this->getT(0).getT(9).getT(1).getT(6);                              // osc1_impl::chain366_t<NV>
		auto& event_data_reader69 = this->getT(0).getT(9).getT(1).getT(6).getT(0);           // osc1_impl::event_data_reader69_t<NV>
		auto& add316 = this->getT(0).getT(9).getT(1).getT(6).getT(1);                        // math::add<NV>
		auto& gain186 = this->getT(0).getT(9).getT(1).getT(6).getT(2);                       // core::gain<NV>
		auto& chain367 = this->getT(0).getT(9).getT(1).getT(7);                              // osc1_impl::chain367_t<NV>
		auto& branch32 = this->getT(0).getT(9).getT(1).getT(7).getT(0);                      // osc1_impl::branch32_t<NV>
		auto& chain368 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(0);              // osc1_impl::chain368_t<NV>
		auto& midi_cc82 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(0).getT(0);     // osc1_impl::midi_cc82_t<NV>
		auto& add317 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(0).getT(1);        // math::add<NV>
		auto& chain369 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(1);              // osc1_impl::chain369_t<NV>
		auto& midi_cc83 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(1).getT(0);     // osc1_impl::midi_cc83_t<NV>
		auto& add318 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(1).getT(1);        // math::add<NV>
		auto& chain370 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(2);              // osc1_impl::chain370_t<NV>
		auto& midi_cc84 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(2).getT(0);     // osc1_impl::midi_cc84_t<NV>
		auto& add319 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(2).getT(1);        // math::add<NV>
		auto& chain371 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(3);              // osc1_impl::chain371_t<NV>
		auto& midi_cc85 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(3).getT(0);     // osc1_impl::midi_cc85_t<NV>
		auto& add320 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(3).getT(1);        // math::add<NV>
		auto& chain372 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(4);              // osc1_impl::chain372_t<NV>
		auto& midi61 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(4).getT(0);        // osc1_impl::midi61_t<NV>
		auto& add321 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(4).getT(1);        // math::add<NV>
		auto& chain373 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(5);              // osc1_impl::chain373_t<NV>
		auto& midi62 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(5).getT(0);        // osc1_impl::midi62_t<NV>
		auto& add322 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(5).getT(1);        // math::add<NV>
		auto& chain374 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(6);              // osc1_impl::chain374_t<NV>
		auto& midi63 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(6).getT(0);        // osc1_impl::midi63_t<NV>
		auto& add323 = this->getT(0).getT(9).getT(1).getT(7).getT(0).getT(6).getT(1);        // math::add<NV>
		auto& gain187 = this->getT(0).getT(9).getT(1).getT(7).getT(1);                       // core::gain<NV>
		auto& peak27 = this->getT(0).getT(9).getT(2);                                        // osc1_impl::peak27_t<NV>
		auto& pma28 = this->getT(0).getT(9).getT(3);                                         // osc1_impl::pma28_t<NV>
		auto& modchain24 = this->getT(0).getT(10);                                           // osc1_impl::modchain24_t<NV>
		auto& sliderbank23 = this->getT(0).getT(10).getT(0);                                 // osc1_impl::sliderbank23_t<NV>
		auto& split46 = this->getT(0).getT(10).getT(1);                                      // osc1_impl::split46_t<NV>
		auto& chain375 = this->getT(0).getT(10).getT(1).getT(0);                             // osc1_impl::chain375_t<NV>
		auto& global_cable83 = this->getT(0).getT(10).getT(1).getT(0).getT(0);               // osc1_impl::global_cable83_t<NV>
		auto& add324 = this->getT(0).getT(10).getT(1).getT(0).getT(1);                       // math::add<NV>
		auto& gain188 = this->getT(0).getT(10).getT(1).getT(0).getT(2);                      // core::gain<NV>
		auto& chain376 = this->getT(0).getT(10).getT(1).getT(1);                             // osc1_impl::chain376_t<NV>
		auto& global_cable84 = this->getT(0).getT(10).getT(1).getT(1).getT(0);               // osc1_impl::global_cable84_t<NV>
		auto& add325 = this->getT(0).getT(10).getT(1).getT(1).getT(1);                       // math::add<NV>
		auto& gain189 = this->getT(0).getT(10).getT(1).getT(1).getT(2);                      // core::gain<NV>
		auto& chain377 = this->getT(0).getT(10).getT(1).getT(2);                             // osc1_impl::chain377_t<NV>
		auto& global_cable85 = this->getT(0).getT(10).getT(1).getT(2).getT(0);               // osc1_impl::global_cable85_t<NV>
		auto& add326 = this->getT(0).getT(10).getT(1).getT(2).getT(1);                       // math::add<NV>
		auto& gain190 = this->getT(0).getT(10).getT(1).getT(2).getT(2);                      // core::gain<NV>
		auto& chain378 = this->getT(0).getT(10).getT(1).getT(3);                             // osc1_impl::chain378_t<NV>
		auto& global_cable86 = this->getT(0).getT(10).getT(1).getT(3).getT(0);               // osc1_impl::global_cable86_t<NV>
		auto& add327 = this->getT(0).getT(10).getT(1).getT(3).getT(1);                       // math::add<NV>
		auto& gain191 = this->getT(0).getT(10).getT(1).getT(3).getT(2);                      // core::gain<NV>
		auto& chain379 = this->getT(0).getT(10).getT(1).getT(4);                             // osc1_impl::chain379_t<NV>
		auto& event_data_reader70 = this->getT(0).getT(10).getT(1).getT(4).getT(0);          // osc1_impl::event_data_reader70_t<NV>
		auto& add328 = this->getT(0).getT(10).getT(1).getT(4).getT(1);                       // math::add<NV>
		auto& gain192 = this->getT(0).getT(10).getT(1).getT(4).getT(2);                      // core::gain<NV>
		auto& chain380 = this->getT(0).getT(10).getT(1).getT(5);                             // osc1_impl::chain380_t<NV>
		auto& event_data_reader71 = this->getT(0).getT(10).getT(1).getT(5).getT(0);          // osc1_impl::event_data_reader71_t<NV>
		auto& add329 = this->getT(0).getT(10).getT(1).getT(5).getT(1);                       // math::add<NV>
		auto& gain193 = this->getT(0).getT(10).getT(1).getT(5).getT(2);                      // core::gain<NV>
		auto& chain381 = this->getT(0).getT(10).getT(1).getT(6);                             // osc1_impl::chain381_t<NV>
		auto& event_data_reader72 = this->getT(0).getT(10).getT(1).getT(6).getT(0);          // osc1_impl::event_data_reader72_t<NV>
		auto& add330 = this->getT(0).getT(10).getT(1).getT(6).getT(1);                       // math::add<NV>
		auto& gain194 = this->getT(0).getT(10).getT(1).getT(6).getT(2);                      // core::gain<NV>
		auto& chain382 = this->getT(0).getT(10).getT(1).getT(7);                             // osc1_impl::chain382_t<NV>
		auto& branch33 = this->getT(0).getT(10).getT(1).getT(7).getT(0);                     // osc1_impl::branch33_t<NV>
		auto& chain383 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(0);             // osc1_impl::chain383_t<NV>
		auto& midi_cc86 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(0).getT(0);    // osc1_impl::midi_cc86_t<NV>
		auto& add331 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(0).getT(1);       // math::add<NV>
		auto& chain384 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(1);             // osc1_impl::chain384_t<NV>
		auto& midi_cc87 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(1).getT(0);    // osc1_impl::midi_cc87_t<NV>
		auto& add332 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(1).getT(1);       // math::add<NV>
		auto& chain385 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(2);             // osc1_impl::chain385_t<NV>
		auto& midi_cc88 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(2).getT(0);    // osc1_impl::midi_cc88_t<NV>
		auto& add333 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(2).getT(1);       // math::add<NV>
		auto& chain386 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(3);             // osc1_impl::chain386_t<NV>
		auto& midi_cc89 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(3).getT(0);    // osc1_impl::midi_cc89_t<NV>
		auto& add334 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(3).getT(1);       // math::add<NV>
		auto& chain387 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(4);             // osc1_impl::chain387_t<NV>
		auto& midi64 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(4).getT(0);       // osc1_impl::midi64_t<NV>
		auto& add335 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(4).getT(1);       // math::add<NV>
		auto& chain388 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(5);             // osc1_impl::chain388_t<NV>
		auto& midi65 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(5).getT(0);       // osc1_impl::midi65_t<NV>
		auto& add336 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(5).getT(1);       // math::add<NV>
		auto& chain389 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(6);             // osc1_impl::chain389_t<NV>
		auto& midi66 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(6).getT(0);       // osc1_impl::midi66_t<NV>
		auto& add337 = this->getT(0).getT(10).getT(1).getT(7).getT(0).getT(6).getT(1);       // math::add<NV>
		auto& gain195 = this->getT(0).getT(10).getT(1).getT(7).getT(1);                      // core::gain<NV>
		auto& peak28 = this->getT(0).getT(10).getT(2);                                       // osc1_impl::peak28_t<NV>
		auto& pma29 = this->getT(0).getT(10).getT(3);                                        // osc1_impl::pma29_t<NV>
		auto& modchain25 = this->getT(0).getT(11);                                           // osc1_impl::modchain25_t<NV>
		auto& sliderbank24 = this->getT(0).getT(11).getT(0);                                 // osc1_impl::sliderbank24_t<NV>
		auto& split47 = this->getT(0).getT(11).getT(1);                                      // osc1_impl::split47_t<NV>
		auto& chain390 = this->getT(0).getT(11).getT(1).getT(0);                             // osc1_impl::chain390_t<NV>
		auto& global_cable87 = this->getT(0).getT(11).getT(1).getT(0).getT(0);               // osc1_impl::global_cable87_t<NV>
		auto& add338 = this->getT(0).getT(11).getT(1).getT(0).getT(1);                       // math::add<NV>
		auto& gain196 = this->getT(0).getT(11).getT(1).getT(0).getT(2);                      // core::gain<NV>
		auto& chain391 = this->getT(0).getT(11).getT(1).getT(1);                             // osc1_impl::chain391_t<NV>
		auto& global_cable88 = this->getT(0).getT(11).getT(1).getT(1).getT(0);               // osc1_impl::global_cable88_t<NV>
		auto& add339 = this->getT(0).getT(11).getT(1).getT(1).getT(1);                       // math::add<NV>
		auto& gain197 = this->getT(0).getT(11).getT(1).getT(1).getT(2);                      // core::gain<NV>
		auto& chain392 = this->getT(0).getT(11).getT(1).getT(2);                             // osc1_impl::chain392_t<NV>
		auto& global_cable89 = this->getT(0).getT(11).getT(1).getT(2).getT(0);               // osc1_impl::global_cable89_t<NV>
		auto& add340 = this->getT(0).getT(11).getT(1).getT(2).getT(1);                       // math::add<NV>
		auto& gain198 = this->getT(0).getT(11).getT(1).getT(2).getT(2);                      // core::gain<NV>
		auto& chain393 = this->getT(0).getT(11).getT(1).getT(3);                             // osc1_impl::chain393_t<NV>
		auto& global_cable90 = this->getT(0).getT(11).getT(1).getT(3).getT(0);               // osc1_impl::global_cable90_t<NV>
		auto& add341 = this->getT(0).getT(11).getT(1).getT(3).getT(1);                       // math::add<NV>
		auto& gain199 = this->getT(0).getT(11).getT(1).getT(3).getT(2);                      // core::gain<NV>
		auto& chain394 = this->getT(0).getT(11).getT(1).getT(4);                             // osc1_impl::chain394_t<NV>
		auto& event_data_reader73 = this->getT(0).getT(11).getT(1).getT(4).getT(0);          // osc1_impl::event_data_reader73_t<NV>
		auto& add342 = this->getT(0).getT(11).getT(1).getT(4).getT(1);                       // math::add<NV>
		auto& gain200 = this->getT(0).getT(11).getT(1).getT(4).getT(2);                      // core::gain<NV>
		auto& chain395 = this->getT(0).getT(11).getT(1).getT(5);                             // osc1_impl::chain395_t<NV>
		auto& event_data_reader74 = this->getT(0).getT(11).getT(1).getT(5).getT(0);          // osc1_impl::event_data_reader74_t<NV>
		auto& add343 = this->getT(0).getT(11).getT(1).getT(5).getT(1);                       // math::add<NV>
		auto& gain201 = this->getT(0).getT(11).getT(1).getT(5).getT(2);                      // core::gain<NV>
		auto& chain396 = this->getT(0).getT(11).getT(1).getT(6);                             // osc1_impl::chain396_t<NV>
		auto& event_data_reader75 = this->getT(0).getT(11).getT(1).getT(6).getT(0);          // osc1_impl::event_data_reader75_t<NV>
		auto& add344 = this->getT(0).getT(11).getT(1).getT(6).getT(1);                       // math::add<NV>
		auto& gain202 = this->getT(0).getT(11).getT(1).getT(6).getT(2);                      // core::gain<NV>
		auto& chain397 = this->getT(0).getT(11).getT(1).getT(7);                             // osc1_impl::chain397_t<NV>
		auto& branch34 = this->getT(0).getT(11).getT(1).getT(7).getT(0);                     // osc1_impl::branch34_t<NV>
		auto& chain398 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(0);             // osc1_impl::chain398_t<NV>
		auto& midi_cc90 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(0).getT(0);    // osc1_impl::midi_cc90_t<NV>
		auto& add345 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(0).getT(1);       // math::add<NV>
		auto& chain399 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(1);             // osc1_impl::chain399_t<NV>
		auto& midi_cc91 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(1).getT(0);    // osc1_impl::midi_cc91_t<NV>
		auto& add346 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(1).getT(1);       // math::add<NV>
		auto& chain400 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(2);             // osc1_impl::chain400_t<NV>
		auto& midi_cc92 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(2).getT(0);    // osc1_impl::midi_cc92_t<NV>
		auto& add347 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(2).getT(1);       // math::add<NV>
		auto& chain401 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(3);             // osc1_impl::chain401_t<NV>
		auto& midi_cc93 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(3).getT(0);    // osc1_impl::midi_cc93_t<NV>
		auto& add348 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(3).getT(1);       // math::add<NV>
		auto& chain402 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(4);             // osc1_impl::chain402_t<NV>
		auto& midi67 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(4).getT(0);       // osc1_impl::midi67_t<NV>
		auto& add349 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(4).getT(1);       // math::add<NV>
		auto& chain403 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(5);             // osc1_impl::chain403_t<NV>
		auto& midi68 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(5).getT(0);       // osc1_impl::midi68_t<NV>
		auto& add350 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(5).getT(1);       // math::add<NV>
		auto& chain404 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(6);             // osc1_impl::chain404_t<NV>
		auto& midi69 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(6).getT(0);       // osc1_impl::midi69_t<NV>
		auto& add351 = this->getT(0).getT(11).getT(1).getT(7).getT(0).getT(6).getT(1);       // math::add<NV>
		auto& gain203 = this->getT(0).getT(11).getT(1).getT(7).getT(1);                      // core::gain<NV>
		auto& peak29 = this->getT(0).getT(11).getT(2);                                       // osc1_impl::peak29_t<NV>
		auto& pma30 = this->getT(0).getT(11).getT(3);                                        // osc1_impl::pma30_t<NV>
		auto& modchain27 = this->getT(0).getT(12);                                           // osc1_impl::modchain27_t<NV>
		auto& sliderbank26 = this->getT(0).getT(12).getT(0);                                 // osc1_impl::sliderbank26_t<NV>
		auto& split50 = this->getT(0).getT(12).getT(1);                                      // osc1_impl::split50_t<NV>
		auto& chain420 = this->getT(0).getT(12).getT(1).getT(0);                             // osc1_impl::chain420_t<NV>
		auto& global_cable95 = this->getT(0).getT(12).getT(1).getT(0).getT(0);               // osc1_impl::global_cable95_t<NV>
		auto& add366 = this->getT(0).getT(12).getT(1).getT(0).getT(1);                       // math::add<NV>
		auto& gain212 = this->getT(0).getT(12).getT(1).getT(0).getT(2);                      // core::gain<NV>
		auto& chain421 = this->getT(0).getT(12).getT(1).getT(1);                             // osc1_impl::chain421_t<NV>
		auto& global_cable96 = this->getT(0).getT(12).getT(1).getT(1).getT(0);               // osc1_impl::global_cable96_t<NV>
		auto& add367 = this->getT(0).getT(12).getT(1).getT(1).getT(1);                       // math::add<NV>
		auto& gain213 = this->getT(0).getT(12).getT(1).getT(1).getT(2);                      // core::gain<NV>
		auto& chain422 = this->getT(0).getT(12).getT(1).getT(2);                             // osc1_impl::chain422_t<NV>
		auto& global_cable97 = this->getT(0).getT(12).getT(1).getT(2).getT(0);               // osc1_impl::global_cable97_t<NV>
		auto& add368 = this->getT(0).getT(12).getT(1).getT(2).getT(1);                       // math::add<NV>
		auto& gain214 = this->getT(0).getT(12).getT(1).getT(2).getT(2);                      // core::gain<NV>
		auto& chain423 = this->getT(0).getT(12).getT(1).getT(3);                             // osc1_impl::chain423_t<NV>
		auto& global_cable98 = this->getT(0).getT(12).getT(1).getT(3).getT(0);               // osc1_impl::global_cable98_t<NV>
		auto& add369 = this->getT(0).getT(12).getT(1).getT(3).getT(1);                       // math::add<NV>
		auto& gain215 = this->getT(0).getT(12).getT(1).getT(3).getT(2);                      // core::gain<NV>
		auto& chain424 = this->getT(0).getT(12).getT(1).getT(4);                             // osc1_impl::chain424_t<NV>
		auto& event_data_reader79 = this->getT(0).getT(12).getT(1).getT(4).getT(0);          // osc1_impl::event_data_reader79_t<NV>
		auto& add370 = this->getT(0).getT(12).getT(1).getT(4).getT(1);                       // math::add<NV>
		auto& gain216 = this->getT(0).getT(12).getT(1).getT(4).getT(2);                      // core::gain<NV>
		auto& chain425 = this->getT(0).getT(12).getT(1).getT(5);                             // osc1_impl::chain425_t<NV>
		auto& event_data_reader80 = this->getT(0).getT(12).getT(1).getT(5).getT(0);          // osc1_impl::event_data_reader80_t<NV>
		auto& add371 = this->getT(0).getT(12).getT(1).getT(5).getT(1);                       // math::add<NV>
		auto& gain217 = this->getT(0).getT(12).getT(1).getT(5).getT(2);                      // core::gain<NV>
		auto& chain427 = this->getT(0).getT(12).getT(1).getT(6);                             // osc1_impl::chain427_t<NV>
		auto& event_data_reader81 = this->getT(0).getT(12).getT(1).getT(6).getT(0);          // osc1_impl::event_data_reader81_t<NV>
		auto& add372 = this->getT(0).getT(12).getT(1).getT(6).getT(1);                       // math::add<NV>
		auto& gain218 = this->getT(0).getT(12).getT(1).getT(6).getT(2);                      // core::gain<NV>
		auto& chain428 = this->getT(0).getT(12).getT(1).getT(7);                             // osc1_impl::chain428_t<NV>
		auto& branch36 = this->getT(0).getT(12).getT(1).getT(7).getT(0);                     // osc1_impl::branch36_t<NV>
		auto& chain429 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(0);             // osc1_impl::chain429_t<NV>
		auto& midi_cc98 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(0).getT(0);    // osc1_impl::midi_cc98_t<NV>
		auto& add373 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(0).getT(1);       // math::add<NV>
		auto& chain430 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(1);             // osc1_impl::chain430_t<NV>
		auto& midi_cc99 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(1).getT(0);    // osc1_impl::midi_cc99_t<NV>
		auto& add374 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(1).getT(1);       // math::add<NV>
		auto& chain431 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(2);             // osc1_impl::chain431_t<NV>
		auto& midi_cc100 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(2).getT(0);   // osc1_impl::midi_cc100_t<NV>
		auto& add375 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(2).getT(1);       // math::add<NV>
		auto& chain432 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(3);             // osc1_impl::chain432_t<NV>
		auto& midi_cc101 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(3).getT(0);   // osc1_impl::midi_cc101_t<NV>
		auto& add376 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(3).getT(1);       // math::add<NV>
		auto& chain433 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(4);             // osc1_impl::chain433_t<NV>
		auto& midi73 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(4).getT(0);       // osc1_impl::midi73_t<NV>
		auto& add377 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(4).getT(1);       // math::add<NV>
		auto& chain434 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(5);             // osc1_impl::chain434_t<NV>
		auto& midi74 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(5).getT(0);       // osc1_impl::midi74_t<NV>
		auto& add378 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(5).getT(1);       // math::add<NV>
		auto& chain435 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(6);             // osc1_impl::chain435_t<NV>
		auto& midi75 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(6).getT(0);       // osc1_impl::midi75_t<NV>
		auto& add379 = this->getT(0).getT(12).getT(1).getT(7).getT(0).getT(6).getT(1);       // math::add<NV>
		auto& gain219 = this->getT(0).getT(12).getT(1).getT(7).getT(1);                      // core::gain<NV>
		auto& peak31 = this->getT(0).getT(12).getT(2);                                       // osc1_impl::peak31_t<NV>
		auto& pma33 = this->getT(0).getT(12).getT(3);                                        // osc1_impl::pma33_t<NV>
		auto& modchain26 = this->getT(0).getT(13);                                           // osc1_impl::modchain26_t<NV>
		auto& sliderbank25 = this->getT(0).getT(13).getT(0);                                 // osc1_impl::sliderbank25_t<NV>
		auto& split49 = this->getT(0).getT(13).getT(1);                                      // osc1_impl::split49_t<NV>
		auto& chain405 = this->getT(0).getT(13).getT(1).getT(0);                             // osc1_impl::chain405_t<NV>
		auto& global_cable91 = this->getT(0).getT(13).getT(1).getT(0).getT(0);               // osc1_impl::global_cable91_t<NV>
		auto& add352 = this->getT(0).getT(13).getT(1).getT(0).getT(1);                       // math::add<NV>
		auto& gain204 = this->getT(0).getT(13).getT(1).getT(0).getT(2);                      // core::gain<NV>
		auto& chain406 = this->getT(0).getT(13).getT(1).getT(1);                             // osc1_impl::chain406_t<NV>
		auto& global_cable92 = this->getT(0).getT(13).getT(1).getT(1).getT(0);               // osc1_impl::global_cable92_t<NV>
		auto& add353 = this->getT(0).getT(13).getT(1).getT(1).getT(1);                       // math::add<NV>
		auto& gain205 = this->getT(0).getT(13).getT(1).getT(1).getT(2);                      // core::gain<NV>
		auto& chain407 = this->getT(0).getT(13).getT(1).getT(2);                             // osc1_impl::chain407_t<NV>
		auto& global_cable93 = this->getT(0).getT(13).getT(1).getT(2).getT(0);               // osc1_impl::global_cable93_t<NV>
		auto& add354 = this->getT(0).getT(13).getT(1).getT(2).getT(1);                       // math::add<NV>
		auto& gain206 = this->getT(0).getT(13).getT(1).getT(2).getT(2);                      // core::gain<NV>
		auto& chain408 = this->getT(0).getT(13).getT(1).getT(3);                             // osc1_impl::chain408_t<NV>
		auto& global_cable94 = this->getT(0).getT(13).getT(1).getT(3).getT(0);               // osc1_impl::global_cable94_t<NV>
		auto& add355 = this->getT(0).getT(13).getT(1).getT(3).getT(1);                       // math::add<NV>
		auto& gain207 = this->getT(0).getT(13).getT(1).getT(3).getT(2);                      // core::gain<NV>
		auto& chain409 = this->getT(0).getT(13).getT(1).getT(4);                             // osc1_impl::chain409_t<NV>
		auto& event_data_reader76 = this->getT(0).getT(13).getT(1).getT(4).getT(0);          // osc1_impl::event_data_reader76_t<NV>
		auto& add356 = this->getT(0).getT(13).getT(1).getT(4).getT(1);                       // math::add<NV>
		auto& gain208 = this->getT(0).getT(13).getT(1).getT(4).getT(2);                      // core::gain<NV>
		auto& chain410 = this->getT(0).getT(13).getT(1).getT(5);                             // osc1_impl::chain410_t<NV>
		auto& event_data_reader77 = this->getT(0).getT(13).getT(1).getT(5).getT(0);          // osc1_impl::event_data_reader77_t<NV>
		auto& add357 = this->getT(0).getT(13).getT(1).getT(5).getT(1);                       // math::add<NV>
		auto& gain209 = this->getT(0).getT(13).getT(1).getT(5).getT(2);                      // core::gain<NV>
		auto& chain411 = this->getT(0).getT(13).getT(1).getT(6);                             // osc1_impl::chain411_t<NV>
		auto& event_data_reader78 = this->getT(0).getT(13).getT(1).getT(6).getT(0);          // osc1_impl::event_data_reader78_t<NV>
		auto& add358 = this->getT(0).getT(13).getT(1).getT(6).getT(1);                       // math::add<NV>
		auto& gain210 = this->getT(0).getT(13).getT(1).getT(6).getT(2);                      // core::gain<NV>
		auto& chain412 = this->getT(0).getT(13).getT(1).getT(7);                             // osc1_impl::chain412_t<NV>
		auto& branch35 = this->getT(0).getT(13).getT(1).getT(7).getT(0);                     // osc1_impl::branch35_t<NV>
		auto& chain413 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(0);             // osc1_impl::chain413_t<NV>
		auto& midi_cc94 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(0).getT(0);    // osc1_impl::midi_cc94_t<NV>
		auto& add359 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(0).getT(1);       // math::add<NV>
		auto& chain414 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(1);             // osc1_impl::chain414_t<NV>
		auto& midi_cc95 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(1).getT(0);    // osc1_impl::midi_cc95_t<NV>
		auto& add360 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(1).getT(1);       // math::add<NV>
		auto& chain415 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(2);             // osc1_impl::chain415_t<NV>
		auto& midi_cc96 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(2).getT(0);    // osc1_impl::midi_cc96_t<NV>
		auto& add361 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(2).getT(1);       // math::add<NV>
		auto& chain416 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(3);             // osc1_impl::chain416_t<NV>
		auto& midi_cc97 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(3).getT(0);    // osc1_impl::midi_cc97_t<NV>
		auto& add362 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(3).getT(1);       // math::add<NV>
		auto& chain417 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(4);             // osc1_impl::chain417_t<NV>
		auto& midi70 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(4).getT(0);       // osc1_impl::midi70_t<NV>
		auto& add363 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(4).getT(1);       // math::add<NV>
		auto& chain418 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(5);             // osc1_impl::chain418_t<NV>
		auto& midi71 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(5).getT(0);       // osc1_impl::midi71_t<NV>
		auto& add364 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(5).getT(1);       // math::add<NV>
		auto& chain419 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(6);             // osc1_impl::chain419_t<NV>
		auto& midi72 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(6).getT(0);       // osc1_impl::midi72_t<NV>
		auto& add365 = this->getT(0).getT(13).getT(1).getT(7).getT(0).getT(6).getT(1);       // math::add<NV>
		auto& gain211 = this->getT(0).getT(13).getT(1).getT(7).getT(1);                      // core::gain<NV>
		auto& peak30 = this->getT(0).getT(13).getT(2);                                       // osc1_impl::peak30_t<NV>
		auto& pma37 = this->getT(0).getT(13).getT(3);                                        // osc1_impl::pma37_t<NV>
		auto& pma32 = this->getT(0).getT(13).getT(4);                                        // osc1_impl::pma32_t<NV>
		auto& modchain28 = this->getT(0).getT(14);                                           // osc1_impl::modchain28_t<NV>
		auto& sliderbank27 = this->getT(0).getT(14).getT(0);                                 // osc1_impl::sliderbank27_t<NV>
		auto& split51 = this->getT(0).getT(14).getT(1);                                      // osc1_impl::split51_t<NV>
		auto& chain436 = this->getT(0).getT(14).getT(1).getT(0);                             // osc1_impl::chain436_t<NV>
		auto& global_cable99 = this->getT(0).getT(14).getT(1).getT(0).getT(0);               // osc1_impl::global_cable99_t<NV>
		auto& add380 = this->getT(0).getT(14).getT(1).getT(0).getT(1);                       // math::add<NV>
		auto& gain220 = this->getT(0).getT(14).getT(1).getT(0).getT(2);                      // core::gain<NV>
		auto& chain437 = this->getT(0).getT(14).getT(1).getT(1);                             // osc1_impl::chain437_t<NV>
		auto& global_cable100 = this->getT(0).getT(14).getT(1).getT(1).getT(0);              // osc1_impl::global_cable100_t<NV>
		auto& add381 = this->getT(0).getT(14).getT(1).getT(1).getT(1);                       // math::add<NV>
		auto& gain221 = this->getT(0).getT(14).getT(1).getT(1).getT(2);                      // core::gain<NV>
		auto& chain438 = this->getT(0).getT(14).getT(1).getT(2);                             // osc1_impl::chain438_t<NV>
		auto& global_cable101 = this->getT(0).getT(14).getT(1).getT(2).getT(0);              // osc1_impl::global_cable101_t<NV>
		auto& add382 = this->getT(0).getT(14).getT(1).getT(2).getT(1);                       // math::add<NV>
		auto& gain222 = this->getT(0).getT(14).getT(1).getT(2).getT(2);                      // core::gain<NV>
		auto& chain439 = this->getT(0).getT(14).getT(1).getT(3);                             // osc1_impl::chain439_t<NV>
		auto& global_cable102 = this->getT(0).getT(14).getT(1).getT(3).getT(0);              // osc1_impl::global_cable102_t<NV>
		auto& add383 = this->getT(0).getT(14).getT(1).getT(3).getT(1);                       // math::add<NV>
		auto& gain223 = this->getT(0).getT(14).getT(1).getT(3).getT(2);                      // core::gain<NV>
		auto& chain440 = this->getT(0).getT(14).getT(1).getT(4);                             // osc1_impl::chain440_t<NV>
		auto& event_data_reader82 = this->getT(0).getT(14).getT(1).getT(4).getT(0);          // osc1_impl::event_data_reader82_t<NV>
		auto& add384 = this->getT(0).getT(14).getT(1).getT(4).getT(1);                       // math::add<NV>
		auto& gain224 = this->getT(0).getT(14).getT(1).getT(4).getT(2);                      // core::gain<NV>
		auto& chain441 = this->getT(0).getT(14).getT(1).getT(5);                             // osc1_impl::chain441_t<NV>
		auto& event_data_reader83 = this->getT(0).getT(14).getT(1).getT(5).getT(0);          // osc1_impl::event_data_reader83_t<NV>
		auto& add385 = this->getT(0).getT(14).getT(1).getT(5).getT(1);                       // math::add<NV>
		auto& gain225 = this->getT(0).getT(14).getT(1).getT(5).getT(2);                      // core::gain<NV>
		auto& chain442 = this->getT(0).getT(14).getT(1).getT(6);                             // osc1_impl::chain442_t<NV>
		auto& event_data_reader84 = this->getT(0).getT(14).getT(1).getT(6).getT(0);          // osc1_impl::event_data_reader84_t<NV>
		auto& add386 = this->getT(0).getT(14).getT(1).getT(6).getT(1);                       // math::add<NV>
		auto& gain226 = this->getT(0).getT(14).getT(1).getT(6).getT(2);                      // core::gain<NV>
		auto& chain443 = this->getT(0).getT(14).getT(1).getT(7);                             // osc1_impl::chain443_t<NV>
		auto& branch37 = this->getT(0).getT(14).getT(1).getT(7).getT(0);                     // osc1_impl::branch37_t<NV>
		auto& chain444 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(0);             // osc1_impl::chain444_t<NV>
		auto& midi_cc102 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(0).getT(0);   // osc1_impl::midi_cc102_t<NV>
		auto& add387 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(0).getT(1);       // math::add<NV>
		auto& chain445 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(1);             // osc1_impl::chain445_t<NV>
		auto& midi_cc103 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(1).getT(0);   // osc1_impl::midi_cc103_t<NV>
		auto& add388 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(1).getT(1);       // math::add<NV>
		auto& chain446 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(2);             // osc1_impl::chain446_t<NV>
		auto& midi_cc104 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(2).getT(0);   // osc1_impl::midi_cc104_t<NV>
		auto& add389 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(2).getT(1);       // math::add<NV>
		auto& chain447 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(3);             // osc1_impl::chain447_t<NV>
		auto& midi_cc105 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(3).getT(0);   // osc1_impl::midi_cc105_t<NV>
		auto& add390 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(3).getT(1);       // math::add<NV>
		auto& chain448 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(4);             // osc1_impl::chain448_t<NV>
		auto& midi76 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(4).getT(0);       // osc1_impl::midi76_t<NV>
		auto& add391 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(4).getT(1);       // math::add<NV>
		auto& chain449 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(5);             // osc1_impl::chain449_t<NV>
		auto& midi77 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(5).getT(0);       // osc1_impl::midi77_t<NV>
		auto& add392 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(5).getT(1);       // math::add<NV>
		auto& chain450 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(6);             // osc1_impl::chain450_t<NV>
		auto& midi78 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(6).getT(0);       // osc1_impl::midi78_t<NV>
		auto& add393 = this->getT(0).getT(14).getT(1).getT(7).getT(0).getT(6).getT(1);       // math::add<NV>
		auto& gain227 = this->getT(0).getT(14).getT(1).getT(7).getT(1);                      // core::gain<NV>
		auto& peak32 = this->getT(0).getT(14).getT(2);                                       // osc1_impl::peak32_t<NV>
		auto& pma38 = this->getT(0).getT(14).getT(3);                                        // osc1_impl::pma38_t<NV>
		auto& pma34 = this->getT(0).getT(14).getT(4);                                        // osc1_impl::pma34_t<NV>
		auto& modchain29 = this->getT(0).getT(15);                                           // osc1_impl::modchain29_t<NV>
		auto& sliderbank28 = this->getT(0).getT(15).getT(0);                                 // osc1_impl::sliderbank28_t<NV>
		auto& split52 = this->getT(0).getT(15).getT(1);                                      // osc1_impl::split52_t<NV>
		auto& chain451 = this->getT(0).getT(15).getT(1).getT(0);                             // osc1_impl::chain451_t<NV>
		auto& global_cable103 = this->getT(0).getT(15).getT(1).getT(0).getT(0);              // osc1_impl::global_cable103_t<NV>
		auto& add394 = this->getT(0).getT(15).getT(1).getT(0).getT(1);                       // math::add<NV>
		auto& gain228 = this->getT(0).getT(15).getT(1).getT(0).getT(2);                      // core::gain<NV>
		auto& chain452 = this->getT(0).getT(15).getT(1).getT(1);                             // osc1_impl::chain452_t<NV>
		auto& global_cable104 = this->getT(0).getT(15).getT(1).getT(1).getT(0);              // osc1_impl::global_cable104_t<NV>
		auto& add395 = this->getT(0).getT(15).getT(1).getT(1).getT(1);                       // math::add<NV>
		auto& gain229 = this->getT(0).getT(15).getT(1).getT(1).getT(2);                      // core::gain<NV>
		auto& chain453 = this->getT(0).getT(15).getT(1).getT(2);                             // osc1_impl::chain453_t<NV>
		auto& global_cable105 = this->getT(0).getT(15).getT(1).getT(2).getT(0);              // osc1_impl::global_cable105_t<NV>
		auto& add396 = this->getT(0).getT(15).getT(1).getT(2).getT(1);                       // math::add<NV>
		auto& gain230 = this->getT(0).getT(15).getT(1).getT(2).getT(2);                      // core::gain<NV>
		auto& chain454 = this->getT(0).getT(15).getT(1).getT(3);                             // osc1_impl::chain454_t<NV>
		auto& global_cable106 = this->getT(0).getT(15).getT(1).getT(3).getT(0);              // osc1_impl::global_cable106_t<NV>
		auto& add397 = this->getT(0).getT(15).getT(1).getT(3).getT(1);                       // math::add<NV>
		auto& gain231 = this->getT(0).getT(15).getT(1).getT(3).getT(2);                      // core::gain<NV>
		auto& chain455 = this->getT(0).getT(15).getT(1).getT(4);                             // osc1_impl::chain455_t<NV>
		auto& event_data_reader85 = this->getT(0).getT(15).getT(1).getT(4).getT(0);          // osc1_impl::event_data_reader85_t<NV>
		auto& add398 = this->getT(0).getT(15).getT(1).getT(4).getT(1);                       // math::add<NV>
		auto& gain232 = this->getT(0).getT(15).getT(1).getT(4).getT(2);                      // core::gain<NV>
		auto& chain456 = this->getT(0).getT(15).getT(1).getT(5);                             // osc1_impl::chain456_t<NV>
		auto& event_data_reader86 = this->getT(0).getT(15).getT(1).getT(5).getT(0);          // osc1_impl::event_data_reader86_t<NV>
		auto& add399 = this->getT(0).getT(15).getT(1).getT(5).getT(1);                       // math::add<NV>
		auto& gain233 = this->getT(0).getT(15).getT(1).getT(5).getT(2);                      // core::gain<NV>
		auto& chain457 = this->getT(0).getT(15).getT(1).getT(6);                             // osc1_impl::chain457_t<NV>
		auto& event_data_reader87 = this->getT(0).getT(15).getT(1).getT(6).getT(0);          // osc1_impl::event_data_reader87_t<NV>
		auto& add400 = this->getT(0).getT(15).getT(1).getT(6).getT(1);                       // math::add<NV>
		auto& gain234 = this->getT(0).getT(15).getT(1).getT(6).getT(2);                      // core::gain<NV>
		auto& chain458 = this->getT(0).getT(15).getT(1).getT(7);                             // osc1_impl::chain458_t<NV>
		auto& branch38 = this->getT(0).getT(15).getT(1).getT(7).getT(0);                     // osc1_impl::branch38_t<NV>
		auto& chain459 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(0);             // osc1_impl::chain459_t<NV>
		auto& midi_cc106 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(0).getT(0);   // osc1_impl::midi_cc106_t<NV>
		auto& add401 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(0).getT(1);       // math::add<NV>
		auto& chain460 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(1);             // osc1_impl::chain460_t<NV>
		auto& midi_cc107 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(1).getT(0);   // osc1_impl::midi_cc107_t<NV>
		auto& add402 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(1).getT(1);       // math::add<NV>
		auto& chain461 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(2);             // osc1_impl::chain461_t<NV>
		auto& midi_cc108 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(2).getT(0);   // osc1_impl::midi_cc108_t<NV>
		auto& add403 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(2).getT(1);       // math::add<NV>
		auto& chain462 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(3);             // osc1_impl::chain462_t<NV>
		auto& midi_cc109 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(3).getT(0);   // osc1_impl::midi_cc109_t<NV>
		auto& add404 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(3).getT(1);       // math::add<NV>
		auto& chain463 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(4);             // osc1_impl::chain463_t<NV>
		auto& midi79 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(4).getT(0);       // osc1_impl::midi79_t<NV>
		auto& add405 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(4).getT(1);       // math::add<NV>
		auto& chain464 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(5);             // osc1_impl::chain464_t<NV>
		auto& midi80 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(5).getT(0);       // osc1_impl::midi80_t<NV>
		auto& add406 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(5).getT(1);       // math::add<NV>
		auto& chain465 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(6);             // osc1_impl::chain465_t<NV>
		auto& midi81 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(6).getT(0);       // osc1_impl::midi81_t<NV>
		auto& add407 = this->getT(0).getT(15).getT(1).getT(7).getT(0).getT(6).getT(1);       // math::add<NV>
		auto& gain235 = this->getT(0).getT(15).getT(1).getT(7).getT(1);                      // core::gain<NV>
		auto& peak33 = this->getT(0).getT(15).getT(2);                                       // osc1_impl::peak33_t
		auto& pma39 = this->getT(0).getT(15).getT(3);                                        // osc1_impl::pma39_t<NV>
		auto& modchain30 = this->getT(0).getT(16);                                           // osc1_impl::modchain30_t<NV>
		auto& sliderbank29 = this->getT(0).getT(16).getT(0);                                 // osc1_impl::sliderbank29_t<NV>
		auto& split53 = this->getT(0).getT(16).getT(1);                                      // osc1_impl::split53_t<NV>
		auto& chain466 = this->getT(0).getT(16).getT(1).getT(0);                             // osc1_impl::chain466_t<NV>
		auto& global_cable107 = this->getT(0).getT(16).getT(1).getT(0).getT(0);              // osc1_impl::global_cable107_t<NV>
		auto& add408 = this->getT(0).getT(16).getT(1).getT(0).getT(1);                       // math::add<NV>
		auto& gain251 = this->getT(0).getT(16).getT(1).getT(0).getT(2);                      // core::gain<NV>
		auto& chain467 = this->getT(0).getT(16).getT(1).getT(1);                             // osc1_impl::chain467_t<NV>
		auto& global_cable108 = this->getT(0).getT(16).getT(1).getT(1).getT(0);              // osc1_impl::global_cable108_t<NV>
		auto& add409 = this->getT(0).getT(16).getT(1).getT(1).getT(1);                       // math::add<NV>
		auto& gain252 = this->getT(0).getT(16).getT(1).getT(1).getT(2);                      // core::gain<NV>
		auto& chain468 = this->getT(0).getT(16).getT(1).getT(2);                             // osc1_impl::chain468_t<NV>
		auto& global_cable109 = this->getT(0).getT(16).getT(1).getT(2).getT(0);              // osc1_impl::global_cable109_t<NV>
		auto& add410 = this->getT(0).getT(16).getT(1).getT(2).getT(1);                       // math::add<NV>
		auto& gain253 = this->getT(0).getT(16).getT(1).getT(2).getT(2);                      // core::gain<NV>
		auto& chain469 = this->getT(0).getT(16).getT(1).getT(3);                             // osc1_impl::chain469_t<NV>
		auto& global_cable110 = this->getT(0).getT(16).getT(1).getT(3).getT(0);              // osc1_impl::global_cable110_t<NV>
		auto& add411 = this->getT(0).getT(16).getT(1).getT(3).getT(1);                       // math::add<NV>
		auto& gain254 = this->getT(0).getT(16).getT(1).getT(3).getT(2);                      // core::gain<NV>
		auto& chain470 = this->getT(0).getT(16).getT(1).getT(4);                             // osc1_impl::chain470_t<NV>
		auto& event_data_reader88 = this->getT(0).getT(16).getT(1).getT(4).getT(0);          // osc1_impl::event_data_reader88_t<NV>
		auto& add412 = this->getT(0).getT(16).getT(1).getT(4).getT(1);                       // math::add<NV>
		auto& gain255 = this->getT(0).getT(16).getT(1).getT(4).getT(2);                      // core::gain<NV>
		auto& chain471 = this->getT(0).getT(16).getT(1).getT(5);                             // osc1_impl::chain471_t<NV>
		auto& event_data_reader89 = this->getT(0).getT(16).getT(1).getT(5).getT(0);          // osc1_impl::event_data_reader89_t<NV>
		auto& add413 = this->getT(0).getT(16).getT(1).getT(5).getT(1);                       // math::add<NV>
		auto& gain256 = this->getT(0).getT(16).getT(1).getT(5).getT(2);                      // core::gain<NV>
		auto& chain472 = this->getT(0).getT(16).getT(1).getT(6);                             // osc1_impl::chain472_t<NV>
		auto& event_data_reader90 = this->getT(0).getT(16).getT(1).getT(6).getT(0);          // osc1_impl::event_data_reader90_t<NV>
		auto& add414 = this->getT(0).getT(16).getT(1).getT(6).getT(1);                       // math::add<NV>
		auto& gain257 = this->getT(0).getT(16).getT(1).getT(6).getT(2);                      // core::gain<NV>
		auto& chain473 = this->getT(0).getT(16).getT(1).getT(7);                             // osc1_impl::chain473_t<NV>
		auto& branch39 = this->getT(0).getT(16).getT(1).getT(7).getT(0);                     // osc1_impl::branch39_t<NV>
		auto& chain474 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(0);             // osc1_impl::chain474_t<NV>
		auto& midi_cc110 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(0).getT(0);   // osc1_impl::midi_cc110_t<NV>
		auto& add415 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(0).getT(1);       // math::add<NV>
		auto& chain475 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(1);             // osc1_impl::chain475_t<NV>
		auto& midi_cc111 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(1).getT(0);   // osc1_impl::midi_cc111_t<NV>
		auto& add416 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(1).getT(1);       // math::add<NV>
		auto& chain476 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(2);             // osc1_impl::chain476_t<NV>
		auto& midi_cc112 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(2).getT(0);   // osc1_impl::midi_cc112_t<NV>
		auto& add417 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(2).getT(1);       // math::add<NV>
		auto& chain477 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(3);             // osc1_impl::chain477_t<NV>
		auto& midi_cc113 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(3).getT(0);   // osc1_impl::midi_cc113_t<NV>
		auto& add418 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(3).getT(1);       // math::add<NV>
		auto& chain478 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(4);             // osc1_impl::chain478_t<NV>
		auto& midi82 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(4).getT(0);       // osc1_impl::midi82_t<NV>
		auto& add419 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(4).getT(1);       // math::add<NV>
		auto& chain479 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(5);             // osc1_impl::chain479_t<NV>
		auto& midi83 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(5).getT(0);       // osc1_impl::midi83_t<NV>
		auto& add420 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(5).getT(1);       // math::add<NV>
		auto& chain480 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(6);             // osc1_impl::chain480_t<NV>
		auto& midi84 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(6).getT(0);       // osc1_impl::midi84_t<NV>
		auto& add421 = this->getT(0).getT(16).getT(1).getT(7).getT(0).getT(6).getT(1);       // math::add<NV>
		auto& gain258 = this->getT(0).getT(16).getT(1).getT(7).getT(1);                      // core::gain<NV>
		auto& peak34 = this->getT(0).getT(16).getT(2);                                       // osc1_impl::peak34_t<NV>
		auto& pma36 = this->getT(0).getT(16).getT(3);                                        // osc1_impl::pma36_t<NV>
		auto& gain = this->getT(1);                                                          // core::gain<NV>
		auto& modchain = this->getT(2);                                                      // osc1_impl::modchain_t<NV>
		auto& split = this->getT(2).getT(0);                                                 // osc1_impl::split_t<NV>
		auto& chain8 = this->getT(2).getT(0).getT(0);                                        // osc1_impl::chain8_t<NV>
		auto& minmax2 = this->getT(2).getT(0).getT(0).getT(0);                               // osc1_impl::minmax2_t<NV>
		auto& converter = this->getT(2).getT(0).getT(0).getT(1);                             // osc1_impl::converter_t<NV>
		auto& chain10 = this->getT(2).getT(0).getT(1);                                       // osc1_impl::chain10_t<NV>
		auto& minmax1 = this->getT(2).getT(0).getT(1).getT(0);                               // control::minmax<NV, parameter::empty>
		auto& chain12 = this->getT(2).getT(0).getT(2);                                       // osc1_impl::chain12_t<NV>
		auto& tempo_sync = this->getT(2).getT(0).getT(2).getT(0);                            // osc1_impl::tempo_sync_t<NV>
		auto& converter5 = this->getT(2).getT(0).getT(2).getT(1);                            // osc1_impl::converter5_t<NV>
		auto& fix8_block1 = this->getT(3);                                                   // osc1_impl::fix8_block1_t<NV>
		auto& branch1 = this->getT(3).getT(0);                                               // osc1_impl::branch1_t<NV>
		auto& chain1 = this->getT(3).getT(0).getT(0);                                        // osc1_impl::chain1_t<NV>
		auto& phasor_fm = this->getT(3).getT(0).getT(0).getT(0);                             // core::phasor_fm<NV>
		auto& chain3 = this->getT(3).getT(0).getT(1);                                        // osc1_impl::chain3_t<NV>
		auto& phasor_fm5 = this->getT(3).getT(0).getT(1).getT(0);                            // core::phasor_fm<NV>
		auto& chain2 = this->getT(3).getT(0).getT(2);                                        // osc1_impl::chain2_t<NV>
		auto& phasor_fm3 = this->getT(3).getT(0).getT(2).getT(0);                            // core::phasor_fm<NV>
		auto& no_midi = this->getT(3).getT(0).getT(3);                                       // osc1_impl::no_midi_t<NV>
		auto& phasor_fm1 = this->getT(3).getT(0).getT(3).getT(0);                            // core::phasor_fm<NV>
		auto& mono2stereo = this->getT(4);                                                   // core::mono2stereo
		auto& peak1 = this->getT(5);                                                         // osc1_impl::peak1_t
		auto& xfader2 = this->getT(6);                                                       // osc1_impl::xfader2_t<NV>
		auto& pma6 = this->getT(7);                                                          // osc1_impl::pma6_t<NV>
		auto& split5 = this->getT(8);                                                        // osc1_impl::split5_t<NV>
		auto& chain59 = this->getT(8).getT(0);                                               // osc1_impl::chain59_t<NV>
		auto& xfader3 = this->getT(8).getT(0).getT(0);                                       // osc1_impl::xfader3_t<NV>
		auto& split8 = this->getT(8).getT(0).getT(1);                                        // osc1_impl::split8_t<NV>
		auto& chain62 = this->getT(8).getT(0).getT(1).getT(0);                               // osc1_impl::chain62_t<NV>
		auto& chain74 = this->getT(8).getT(0).getT(1).getT(0).getT(0);                       // osc1_impl::chain74_t<NV>
		auto& sub1 = this->getT(8).getT(0).getT(1).getT(0).getT(0).getT(0);                  // math::sub<NV>
		auto& abs1 = this->getT(8).getT(0).getT(1).getT(0).getT(0).getT(1);                  // math::abs<NV>
		auto& mul2 = this->getT(8).getT(0).getT(1).getT(0).getT(0).getT(2);                  // math::mul<NV>
		auto& gain49 = this->getT(8).getT(0).getT(1).getT(0).getT(1);                        // core::gain<NV>
		auto& chain75 = this->getT(8).getT(0).getT(1).getT(1);                               // osc1_impl::chain75_t<NV>
		auto& expr3 = this->getT(8).getT(0).getT(1).getT(1).getT(0);                         // math::expr<NV, custom::expr3>
		auto& gain50 = this->getT(8).getT(0).getT(1).getT(1).getT(1);                        // core::gain<NV>
		auto& gain12 = this->getT(8).getT(0).getT(2);                                        // core::gain<NV>
		auto& chain76 = this->getT(8).getT(1);                                               // osc1_impl::chain76_t<NV>
		auto& gain51 = this->getT(8).getT(1).getT(0);                                        // core::gain<NV>
		auto& rect2 = this->getT(8).getT(1).getT(1);                                         // math::rect<NV>
		auto& gain52 = this->getT(8).getT(1).getT(2);                                        // core::gain<NV>
		auto& chain77 = this->getT(8).getT(2);                                               // osc1_impl::chain77_t<NV>
		auto& chain78 = this->getT(8).getT(2).getT(0);                                       // osc1_impl::chain78_t<NV>
		auto& gain53 = this->getT(8).getT(2).getT(0).getT(0);                                // core::gain<NV>
		auto& fmod2 = this->getT(8).getT(2).getT(0).getT(1);                                 // math::fmod<NV>
		auto& mul3 = this->getT(8).getT(2).getT(0).getT(2);                                  // wrap::no_process<math::mul<NV>>
		auto& pi8 = this->getT(8).getT(2).getT(0).getT(3);                                   // math::pi<NV>
		auto& oscilloscope1 = this->getT(8).getT(2).getT(0).getT(4);                         // osc1_impl::oscilloscope1_t
		auto& gain55 = this->getT(8).getT(2).getT(1);                                        // core::gain<NV>
		auto& chain79 = this->getT(8).getT(3);                                               // osc1_impl::chain79_t<NV>
		auto& gain56 = this->getT(8).getT(3).getT(0);                                        // core::gain<NV>
		auto& expr6 = this->getT(8).getT(3).getT(1);                                         // math::expr<NV, custom::expr6>
		auto& sin7 = this->getT(8).getT(3).getT(2);                                          // math::sin<NV>
		auto& gain57 = this->getT(8).getT(3).getT(3);                                        // core::gain<NV>
		auto& chain80 = this->getT(8).getT(4);                                               // osc1_impl::chain80_t<NV>
		auto& pi9 = this->getT(8).getT(4).getT(0);                                           // math::pi<NV>
		auto& sin1 = this->getT(8).getT(4).getT(1);                                          // wrap::no_process<math::sin<NV>>
		auto& gain58 = this->getT(8).getT(4).getT(2);                                        // core::gain<NV>
		auto& sin9 = this->getT(8).getT(4).getT(3);                                          // math::sin<NV>
		auto& expr7 = this->getT(8).getT(4).getT(4);                                         // math::expr<NV, custom::expr7>
		auto& gain3 = this->getT(8).getT(4).getT(5);                                         // core::gain<NV>
		auto& chain81 = this->getT(8).getT(5);                                               // osc1_impl::chain81_t<NV>
		auto& pi3 = this->getT(8).getT(5).getT(0);                                           // wrap::no_process<math::pi<NV>>
		auto& phase_delay1 = this->getT(8).getT(5).getT(1);                                  // wrap::no_process<fx::phase_delay<NV>>
		auto& gain59 = this->getT(8).getT(5).getT(2);                                        // core::gain<NV>
		auto& expr8 = this->getT(8).getT(5).getT(3);                                         // math::expr<NV, custom::expr8>
		auto& sin10 = this->getT(8).getT(5).getT(4);                                         // math::sin<NV>
		auto& gain60 = this->getT(8).getT(5).getT(5);                                        // core::gain<NV>
		auto& chain82 = this->getT(8).getT(6);                                               // osc1_impl::chain82_t<NV>
		auto& chain83 = this->getT(8).getT(6).getT(0);                                       // osc1_impl::chain83_t<NV>
		auto& chain84 = this->getT(8).getT(6).getT(0).getT(0);                               // osc1_impl::chain84_t<NV>
		auto& clone_cable2 = this->getT(8).getT(6).getT(0).getT(0).getT(0);                  // osc1_impl::clone_cable2_t<NV>
		auto& clone_cable4 = this->getT(8).getT(6).getT(0).getT(0).getT(1);                  // osc1_impl::clone_cable4_t<NV>
		auto& clone_pack1 = this->getT(8).getT(6).getT(0).getT(0).getT(2);                   // osc1_impl::clone_pack1_t<NV>
		auto& clone1 = this->getT(8).getT(6).getT(0).getT(0).getT(3);                        // osc1_impl::clone1_t<NV>                        // osc1_impl::clone_child16_t<NV>
		auto pi11 = this->getT(8).getT(6).getT(0).getT(0).getT(3).getT(0);                   // math::pi<NV>
		auto sub18 = this->getT(8).getT(6).getT(0).getT(0).getT(3).getT(1);                  // wrap::no_process<math::sub<NV>>
		auto expr9 = this->getT(8).getT(6).getT(0).getT(0).getT(3).getT(2);                  // math::expr<NV, custom::expr9>
		auto fmod1 = this->getT(8).getT(6).getT(0).getT(0).getT(3).getT(3);                  // wrap::no_process<math::fmod<NV>>
		auto add9 = this->getT(8).getT(6).getT(0).getT(0).getT(3).getT(4);                   // math::add<NV>
		auto rect3 = this->getT(8).getT(6).getT(0).getT(0).getT(3).getT(5);                  // wrap::no_process<math::rect<NV>>
		auto gain61 = this->getT(8).getT(6).getT(0).getT(0).getT(3).getT(6);                 // core::gain<NV>
		auto jpanner1 = this->getT(8).getT(6).getT(0).getT(0).getT(3).getT(7);               // jdsp::jpanner<NV>
		auto square1 = this->getT(8).getT(6).getT(0).getT(0).getT(3).getT(8);                // wrap::no_process<math::square<NV>>
		auto sin13 = this->getT(8).getT(6).getT(0).getT(0).getT(3).getT(9);                  // math::sin<NV>
		auto& cable_table1 = this->getT(8).getT(6).getT(0).getT(0).getT(4);                  // osc1_impl::cable_table1_t
		auto& sin14 = this->getT(8).getT(6).getT(0).getT(0).getT(5);                         // math::sin<NV>
		auto& gain62 = this->getT(8).getT(6).getT(1);                                        // core::gain<NV>
		auto& chain85 = this->getT(8).getT(7);                                               // osc1_impl::chain85_t<NV>
		auto& gain63 = this->getT(8).getT(7).getT(0);                                        // core::gain<NV>
		auto& pi12 = this->getT(8).getT(7).getT(1);                                          // math::pi<NV>
		auto& table5 = this->getT(8).getT(7).getT(2);                                        // osc1_impl::table5_t
		auto& gain64 = this->getT(8).getT(7).getT(3);                                        // core::gain<NV>
		auto& fix8_block2 = this->getT(9);                                                   // osc1_impl::fix8_block2_t<NV>
		auto& peak5 = this->getT(9).getT(0);                                                 // osc1_impl::peak5_t<NV>
		auto& gain4 = this->getT(10);                                                        // core::gain<NV>
		auto& one_pole1 = this->getT(11);                                                    // filters::one_pole<NV>
		auto& xfader1 = this->getT(12);                                                      // osc1_impl::xfader1_t<NV>
		auto& chain38 = this->getT(13);                                                      // osc1_impl::chain38_t<NV>
		auto& split48 = this->getT(13).getT(0);                                              // osc1_impl::split48_t<NV>
		auto& chain426 = this->getT(13).getT(0).getT(0);                                     // osc1_impl::chain426_t<NV>
		auto& gain7 = this->getT(13).getT(0).getT(0).getT(0);                                // core::gain<NV>
		auto& chain73 = this->getT(13).getT(0).getT(1);                                      // osc1_impl::chain73_t<NV>
		auto& fix8_block = this->getT(13).getT(0).getT(1).getT(0);                           // osc1_impl::fix8_block_t<NV>
		auto& chain247 = this->getT(13).getT(0).getT(1).getT(0).getT(0);                     // osc1_impl::chain247_t<NV>
		auto& modchain17 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0);           // osc1_impl::modchain17_t<NV>
		auto& split37 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).getT(0);      // osc1_impl::split37_t<NV>
		auto& chain264 = this->getT(13).getT(0).getT(1).getT(0).                             // osc1_impl::chain264_t<NV>
                         getT(0).getT(0).getT(0).getT(0);
		auto& clear5 = this->getT(13).getT(0).getT(1).getT(0).                               // math::clear<NV>
                       getT(0).getT(0).getT(0).getT(0).
                       getT(0);
		auto& chain265 = this->getT(13).getT(0).getT(1).getT(0).                             // osc1_impl::chain265_t<NV>
                         getT(0).getT(0).getT(0).getT(0).
                         getT(1);
		auto& branch24 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::branch24_t<NV>
                         getT(0).getT(0).getT(0).getT(1).getT(0);
		auto& chain266 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain266_t<NV>
                         getT(0).getT(0).getT(0).getT(1).getT(0).
                         getT(0);
		auto& tempo_sync6 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).          // osc1_impl::tempo_sync6_t<NV>
                            getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);
		auto& ramp1 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).                // osc1_impl::ramp1_t<NV>
                      getT(0).getT(0).getT(1).getT(0).getT(0).getT(1);
		auto& add223 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).               // math::add<NV>
                       getT(0).getT(0).getT(1).getT(0).getT(0).getT(2);
		auto& chain267 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain267_t<NV>
                         getT(0).getT(0).getT(0).getT(1).getT(0).
                         getT(1);
		auto& clock_ramp1 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).          // osc1_impl::clock_ramp1_t<NV>
                            getT(0).getT(0).getT(1).getT(0).getT(1).getT(0);
		auto& add224 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).               // math::add<NV>
                       getT(0).getT(0).getT(1).getT(0).getT(1).getT(1);
		auto& peak19 = this->getT(13).getT(0).getT(1).getT(0).                               // osc1_impl::peak19_t
                       getT(0).getT(0).getT(0).getT(0).
                       getT(2);
		auto& clear6 = this->getT(13).getT(0).getT(1).getT(0).                               // math::clear<NV>
                       getT(0).getT(0).getT(0).getT(0).
                       getT(3);
		auto& chain268 = this->getT(13).getT(0).getT(1).getT(0).                             // osc1_impl::chain268_t<NV>
                         getT(0).getT(0).getT(0).getT(0).
                         getT(4);
		auto& cable_table17 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                // osc1_impl::cable_table17_t<NV>
                              getT(0).getT(0).getT(0).getT(4).getT(0);
		auto& add225 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // wrap::no_process<math::add<NV>>
                       getT(0).getT(0).getT(0).getT(4).getT(1);
		auto& cable_table16 = this->getT(13).getT(0).getT(1).getT(0).                        // osc1_impl::cable_table16_t
                              getT(0).getT(0).getT(0).getT(0).
                              getT(5);
		auto& clear7 = this->getT(13).getT(0).getT(1).getT(0).                               // math::clear<NV>
                       getT(0).getT(0).getT(0).getT(0).
                       getT(6);
		auto& pma21 = this->getT(13).getT(0).getT(1).getT(0).                                // osc1_impl::pma21_t<NV>
                      getT(0).getT(0).getT(0).getT(0).
                      getT(7);
		auto& chain269 = this->getT(13).getT(0).getT(1).getT(0).                             // osc1_impl::chain269_t<NV>
                         getT(0).getT(0).getT(0).getT(1);
		auto& sliderbank16 = this->getT(13).getT(0).getT(1).getT(0).                         // osc1_impl::sliderbank16_t<NV>
                             getT(0).getT(0).getT(0).getT(1).
                             getT(0);
		auto& split38 = this->getT(13).getT(0).getT(1).getT(0).                              // osc1_impl::split38_t<NV>
                        getT(0).getT(0).getT(0).getT(1).
                        getT(1);
		auto& chain270 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain270_t<NV>
                         getT(0).getT(0).getT(1).getT(1).getT(0);
		auto& global_cable55 = this->getT(13).getT(0).getT(1).getT(0).getT(0).               // osc1_impl::global_cable55_t<NV>
                               getT(0).getT(0).getT(1).getT(1).getT(0).
                               getT(0);
		auto& add226 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // math::add<NV>
                       getT(0).getT(0).getT(1).getT(1).getT(0).
                       getT(1);
		auto& gain132 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                      // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(1).getT(0).
                        getT(2);
		auto& chain271 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain271_t<NV>
                         getT(0).getT(0).getT(1).getT(1).getT(1);
		auto& global_cable56 = this->getT(13).getT(0).getT(1).getT(0).getT(0).               // osc1_impl::global_cable56_t<NV>
                               getT(0).getT(0).getT(1).getT(1).getT(1).
                               getT(0);
		auto& add227 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // math::add<NV>
                       getT(0).getT(0).getT(1).getT(1).getT(1).
                       getT(1);
		auto& gain133 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                      // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(1).getT(1).
                        getT(2);
		auto& chain272 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain272_t<NV>
                         getT(0).getT(0).getT(1).getT(1).getT(2);
		auto& global_cable57 = this->getT(13).getT(0).getT(1).getT(0).getT(0).               // osc1_impl::global_cable57_t<NV>
                               getT(0).getT(0).getT(1).getT(1).getT(2).
                               getT(0);
		auto& add228 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // math::add<NV>
                       getT(0).getT(0).getT(1).getT(1).getT(2).
                       getT(1);
		auto& gain134 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                      // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(1).getT(2).
                        getT(2);
		auto& chain273 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain273_t<NV>
                         getT(0).getT(0).getT(1).getT(1).getT(3);
		auto& global_cable58 = this->getT(13).getT(0).getT(1).getT(0).getT(0).               // osc1_impl::global_cable58_t<NV>
                               getT(0).getT(0).getT(1).getT(1).getT(3).
                               getT(0);
		auto& add229 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // math::add<NV>
                       getT(0).getT(0).getT(1).getT(1).getT(3).
                       getT(1);
		auto& gain135 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                      // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(1).getT(3).
                        getT(2);
		auto& chain274 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain274_t<NV>
                         getT(0).getT(0).getT(1).getT(1).getT(4);
		auto& event_data_reader49 = this->getT(13).getT(0).getT(1).getT(0).getT(0).          // osc1_impl::event_data_reader49_t<NV>
                                    getT(0).getT(0).getT(1).getT(1).getT(4).
                                    getT(0);
		auto& add230 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // math::add<NV>
                       getT(0).getT(0).getT(1).getT(1).getT(4).
                       getT(1);
		auto& gain136 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                      // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(1).getT(4).
                        getT(2);
		auto& chain275 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain275_t<NV>
                         getT(0).getT(0).getT(1).getT(1).getT(5);
		auto& event_data_reader50 = this->getT(13).getT(0).getT(1).getT(0).getT(0).          // osc1_impl::event_data_reader50_t<NV>
                                    getT(0).getT(0).getT(1).getT(1).getT(5).
                                    getT(0);
		auto& add231 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // math::add<NV>
                       getT(0).getT(0).getT(1).getT(1).getT(5).
                       getT(1);
		auto& gain137 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                      // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(1).getT(5).
                        getT(2);
		auto& chain276 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain276_t<NV>
                         getT(0).getT(0).getT(1).getT(1).getT(6);
		auto& event_data_reader51 = this->getT(13).getT(0).getT(1).getT(0).getT(0).          // osc1_impl::event_data_reader51_t<NV>
                                    getT(0).getT(0).getT(1).getT(1).getT(6).
                                    getT(0);
		auto& add232 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // math::add<NV>
                       getT(0).getT(0).getT(1).getT(1).getT(6).
                       getT(1);
		auto& gain138 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                      // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(1).getT(6).
                        getT(2);
		auto& chain277 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain277_t<NV>
                         getT(0).getT(0).getT(1).getT(1).getT(7);
		auto& branch26 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::branch26_t<NV>
                         getT(0).getT(0).getT(1).getT(1).getT(7).
                         getT(0);
		auto& chain278 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).             // osc1_impl::chain278_t<NV>
                         getT(0).getT(1).getT(1).getT(7).getT(0).getT(0);
		auto& midi_cc58 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).            // osc1_impl::midi_cc58_t<NV>
                          getT(0).getT(1).getT(1).getT(7).getT(0).getT(0).
                          getT(0);
		auto& add233 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).               // math::add<NV>
                       getT(0).getT(1).getT(1).getT(7).getT(0).getT(0).
                       getT(1);
		auto& chain279 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).             // osc1_impl::chain279_t<NV>
                         getT(0).getT(1).getT(1).getT(7).getT(0).getT(1);
		auto& midi_cc59 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).            // osc1_impl::midi_cc59_t<NV>
                          getT(0).getT(1).getT(1).getT(7).getT(0).getT(1).
                          getT(0);
		auto& add234 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).               // math::add<NV>
                       getT(0).getT(1).getT(1).getT(7).getT(0).getT(1).
                       getT(1);
		auto& chain280 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).             // osc1_impl::chain280_t<NV>
                         getT(0).getT(1).getT(1).getT(7).getT(0).getT(2);
		auto& midi_cc60 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).            // osc1_impl::midi_cc60_t<NV>
                          getT(0).getT(1).getT(1).getT(7).getT(0).getT(2).
                          getT(0);
		auto& add235 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).               // math::add<NV>
                       getT(0).getT(1).getT(1).getT(7).getT(0).getT(2).
                       getT(1);
		auto& chain281 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).             // osc1_impl::chain281_t<NV>
                         getT(0).getT(1).getT(1).getT(7).getT(0).getT(3);
		auto& midi_cc61 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).            // osc1_impl::midi_cc61_t<NV>
                          getT(0).getT(1).getT(1).getT(7).getT(0).getT(3).
                          getT(0);
		auto& add236 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).               // math::add<NV>
                       getT(0).getT(1).getT(1).getT(7).getT(0).getT(3).
                       getT(1);
		auto& chain282 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).             // osc1_impl::chain282_t<NV>
                         getT(0).getT(1).getT(1).getT(7).getT(0).getT(4);
		auto& midi43 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).               // osc1_impl::midi43_t<NV>
                       getT(0).getT(1).getT(1).getT(7).getT(0).getT(4).
                       getT(0);
		auto& add237 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).               // math::add<NV>
                       getT(0).getT(1).getT(1).getT(7).getT(0).getT(4).
                       getT(1);
		auto& chain283 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).             // osc1_impl::chain283_t<NV>
                         getT(0).getT(1).getT(1).getT(7).getT(0).getT(5);
		auto& midi44 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).               // osc1_impl::midi44_t<NV>
                       getT(0).getT(1).getT(1).getT(7).getT(0).getT(5).
                       getT(0);
		auto& add238 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).               // math::add<NV>
                       getT(0).getT(1).getT(1).getT(7).getT(0).getT(5).
                       getT(1);
		auto& chain284 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).             // osc1_impl::chain284_t<NV>
                         getT(0).getT(1).getT(1).getT(7).getT(0).getT(6);
		auto& midi45 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).               // osc1_impl::midi45_t<NV>
                       getT(0).getT(1).getT(1).getT(7).getT(0).getT(6).
                       getT(0);
		auto& add239 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).               // math::add<NV>
                       getT(0).getT(1).getT(1).getT(7).getT(0).getT(6).
                       getT(1);
		auto& gain139 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                      // core::gain<NV>
                        getT(0).getT(0).getT(1).getT(1).getT(7).
                        getT(1);
		auto& peak21 = this->getT(13).getT(0).getT(1).getT(0).                               // osc1_impl::peak21_t<NV>
                       getT(0).getT(0).getT(0).getT(1).
                       getT(2);
		auto& pma22 = this->getT(13).getT(0).getT(1).getT(0).                                // osc1_impl::pma22_t<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(3);
		auto& pma23 = this->getT(13).getT(0).getT(1).getT(0).                                // osc1_impl::pma23_t<NV>
                      getT(0).getT(0).getT(0).getT(1).
                      getT(4);
		auto& cable_table18 = this->getT(13).getT(0).getT(1).getT(0).                        // osc1_impl::cable_table18_t
                              getT(0).getT(0).getT(0).getT(1).
                              getT(5);
		auto& cable_table19 = this->getT(13).getT(0).getT(1).getT(0).                        // osc1_impl::cable_table19_t
                              getT(0).getT(0).getT(0).getT(1).
                              getT(6);
		auto& gain6 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(1);                // core::gain<NV>
		auto& chain248 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(2);             // osc1_impl::chain248_t<NV>
		auto& chain249 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(2).getT(0);     // osc1_impl::chain249_t<NV>
		auto& modchain16 = this->getT(13).getT(0).getT(1).getT(0).                           // osc1_impl::modchain16_t<NV>
                           getT(0).getT(2).getT(0).getT(0);
		auto& branch21 = this->getT(13).getT(0).getT(1).getT(0).                             // osc1_impl::branch21_t<NV>
                         getT(0).getT(2).getT(0).getT(0).
                         getT(0);
		auto& chain250 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain250_t<NV>
                         getT(2).getT(0).getT(0).getT(0).getT(0);
		auto& add213 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // math::add<NV>
                       getT(2).getT(0).getT(0).getT(0).getT(0).
                       getT(0);
		auto& chain251 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain251_t<NV>
                         getT(2).getT(0).getT(0).getT(0).getT(1);
		auto& minmax6 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                      // osc1_impl::minmax6_t<NV>
                        getT(2).getT(0).getT(0).getT(0).getT(1).
                        getT(0);
		auto& add214 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // math::add<NV>
                       getT(2).getT(0).getT(0).getT(0).getT(1).
                       getT(1);
		auto& chain252 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain252_t<NV>
                         getT(2).getT(0).getT(0).getT(0).getT(2);
		auto& minmax7 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                      // osc1_impl::minmax7_t<NV>
                        getT(2).getT(0).getT(0).getT(0).getT(2).
                        getT(0);
		auto& add215 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // math::add<NV>
                       getT(2).getT(0).getT(0).getT(0).getT(2).
                       getT(1);
		auto& chain253 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain253_t<NV>
                         getT(2).getT(0).getT(0).getT(0).getT(3);
		auto& minmax14 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::minmax14_t<NV>
                         getT(2).getT(0).getT(0).getT(0).getT(3).
                         getT(0);
		auto& add216 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // math::add<NV>
                       getT(2).getT(0).getT(0).getT(0).getT(3).
                       getT(1);
		auto& chain254 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain254_t<NV>
                         getT(2).getT(0).getT(0).getT(0).getT(4);
		auto& minmax11 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::minmax11_t<NV>
                         getT(2).getT(0).getT(0).getT(0).getT(4).
                         getT(0);
		auto& add217 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // math::add<NV>
                       getT(2).getT(0).getT(0).getT(0).getT(4).
                       getT(1);
		auto& chain255 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain255_t<NV>
                         getT(2).getT(0).getT(0).getT(0).getT(5);
		auto& minmax15 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::minmax15_t<NV>
                         getT(2).getT(0).getT(0).getT(0).getT(5).
                         getT(0);
		auto& add218 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // math::add<NV>
                       getT(2).getT(0).getT(0).getT(0).getT(5).
                       getT(1);
		auto& chain256 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain256_t<NV>
                         getT(2).getT(0).getT(0).getT(0).getT(6);
		auto& minmax16 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::minmax16_t<NV>
                         getT(2).getT(0).getT(0).getT(0).getT(6).
                         getT(0);
		auto& add219 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // math::add<NV>
                       getT(2).getT(0).getT(0).getT(0).getT(6).
                       getT(1);
		auto& chain257 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain257_t<NV>
                         getT(2).getT(0).getT(0).getT(0).getT(7);
		auto& minmax17 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::minmax17_t<NV>
                         getT(2).getT(0).getT(0).getT(0).getT(7).
                         getT(0);
		auto& add220 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // math::add<NV>
                       getT(2).getT(0).getT(0).getT(0).getT(7).
                       getT(1);
		auto& chain258 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::chain258_t<NV>
                         getT(2).getT(0).getT(0).getT(0).getT(8);
		auto& minmax18 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                     // osc1_impl::minmax18_t<NV>
                         getT(2).getT(0).getT(0).getT(0).getT(8).
                         getT(0);
		auto& add221 = this->getT(13).getT(0).getT(1).getT(0).getT(0).                       // math::add<NV>
                       getT(2).getT(0).getT(0).getT(0).getT(8).
                       getT(1);
		auto& peak18 = this->getT(13).getT(0).getT(1).getT(0).                               // osc1_impl::peak18_t<NV>
                       getT(0).getT(2).getT(0).getT(0).
                       getT(1);
		auto& peak2 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(3);                // osc1_impl::peak2_t
		auto& expr10 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(4);               // math::expr<NV, custom::expr10>
		auto& add222 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(5);               // math::add<NV>
		auto& branch22 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(6);             // osc1_impl::branch22_t<NV>
		auto& file_player6 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(6).getT(0); // osc1_impl::file_player6_t<NV>
		auto& file_player7 = this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(6).getT(1); // osc1_impl::file_player7_t<NV>
		auto& branch23 = this->getT(13).getT(0).getT(1).getT(1);                             // osc1_impl::branch23_t<NV>
		auto& chain261 = this->getT(13).getT(0).getT(1).getT(1).getT(0);                     // osc1_impl::chain261_t<NV>
		auto& tanh2 = this->getT(13).getT(0).getT(1).getT(1).getT(0).getT(0);                // wrap::no_process<math::tanh<NV>>
		auto& chain262 = this->getT(13).getT(0).getT(1).getT(1).getT(1);                     // osc1_impl::chain262_t<NV>
		auto& receive2 = this->getT(13).getT(0).getT(1).getT(1).getT(1).getT(0);             // routing::receive<stereo_cable>
		auto& faust3 = this->getT(13).getT(0).getT(1).getT(1).getT(1).getT(1);               // project::shfiter<NV>
		auto& send2 = this->getT(13).getT(0).getT(1).getT(1).getT(1).getT(2);                // routing::send<stereo_cable>
		auto& chain263 = this->getT(13).getT(0).getT(1).getT(1).getT(2);                     // osc1_impl::chain263_t<NV>
		auto& midi42 = this->getT(13).getT(0).getT(1).getT(1).getT(2).getT(0);               // osc1_impl::midi42_t<NV>
		auto& cable_table15 = this->getT(13).getT(0).getT(1).getT(1).getT(2).getT(1);        // osc1_impl::cable_table15_t<NV>
		auto& receive3 = this->getT(13).getT(0).getT(1).getT(1).getT(2).getT(2);             // routing::receive<stereo_cable>
		auto& faust4 = this->getT(13).getT(0).getT(1).getT(1).getT(2).getT(3);               // project::ps2<NV>
		auto& faust5 = this->getT(13).getT(0).getT(1).getT(1).getT(2).getT(4);               // project::shfiter<NV>
		auto& send3 = this->getT(13).getT(0).getT(1).getT(1).getT(2).getT(5);                // routing::send<stereo_cable>
		auto& gain8 = this->getT(13).getT(0).getT(1).getT(2);                                // core::gain<NV>
		auto& gain9 = this->getT(14);                                                        // core::gain<NV>
		auto& chain58 = this->getT(15);                                                      // osc1_impl::chain58_t<NV>
		auto& xfader = this->getT(15).getT(0);                                               // osc1_impl::xfader_t<NV>
		auto& split12 = this->getT(15).getT(1);                                              // osc1_impl::split12_t<NV>
		auto& chain14 = this->getT(15).getT(1).getT(0);                                      // osc1_impl::chain14_t<NV>
		auto& gain1 = this->getT(15).getT(1).getT(0).getT(0);                                // core::gain<NV>
		auto& chain57 = this->getT(15).getT(1).getT(1);                                      // osc1_impl::chain57_t<NV>
		auto& chain15 = this->getT(15).getT(1).getT(1).getT(0);                              // osc1_impl::chain15_t<NV>
		auto& branch = this->getT(15).getT(1).getT(1).getT(0).getT(0);                       // osc1_impl::branch_t<NV>
		auto& chain16 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(0);              // osc1_impl::chain16_t<NV>
		auto& faust = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(0).getT(0);        // project::klp<NV>
		auto& faust1 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(0).getT(1);       // project::khp2<NV>
		auto& chain35 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(1);              // osc1_impl::chain35_t<NV>
		auto& split1 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(1).getT(0);       // osc1_impl::split1_t<NV>
		auto& faust2 = this->getT(15).getT(1).getT(1).getT(0).                               // project::klp<NV>
                       getT(0).getT(1).getT(0).getT(0);
		auto& faust6 = this->getT(15).getT(1).getT(1).getT(0).                               // project::khp2<NV>
                       getT(0).getT(1).getT(0).getT(1);
		auto& chain36 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(2);              // osc1_impl::chain36_t<NV>
		auto& cable_table = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(2).getT(0);  // osc1_impl::cable_table_t<NV>
		auto& faust8 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(2).getT(1);       // project::Comb<NV>
		auto& faust7 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(2).getT(2);       // project::klp<NV>
		auto& chain37 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(3);              // osc1_impl::chain37_t<NV>
		auto& cable_table2 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(3).getT(0); // osc1_impl::cable_table2_t<NV>
		auto& faust10 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(3).getT(1);      // project::klp<NV>
		auto& faust9 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(3).getT(2);       // project::Comb<NV>
		auto& split9 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(4);               // osc1_impl::split9_t<NV>
		auto& chain55 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(4).getT(0);      // osc1_impl::chain55_t<NV>
		auto& faust11 = this->getT(15).getT(1).getT(1).getT(0).                              // project::klp<NV>
                        getT(0).getT(4).getT(0).getT(0);
		auto& jpanner = this->getT(15).getT(1).getT(1).getT(0).                         // jdsp::jpanner<NV>
                        getT(0).getT(4).getT(0).getT(1);
		auto& chain56 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(4).getT(1); // osc1_impl::chain56_t<NV>
		auto& faust12 = this->getT(15).getT(1).getT(1).getT(0).                         // project::klp<NV>
                        getT(0).getT(4).getT(1).getT(0);
		auto& jpanner2 = this->getT(15).getT(1).getT(1).getT(0).                        // jdsp::jpanner<NV>
                         getT(0).getT(4).getT(1).getT(1);
		auto& split13 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(5);         // osc1_impl::split13_t<NV>
		auto& chain60 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(5).getT(0); // osc1_impl::chain60_t<NV>
		auto& faust13 = this->getT(15).getT(1).getT(1).getT(0).                         // project::khp<NV>
                        getT(0).getT(5).getT(0).getT(0);
		auto& jpanner4 = this->getT(15).getT(1).getT(1).getT(0).                        // jdsp::jpanner<NV>
                         getT(0).getT(5).getT(0).getT(1);
		auto& chain61 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(5).getT(1); // osc1_impl::chain61_t<NV>
		auto& faust14 = this->getT(15).getT(1).getT(1).getT(0).                         // project::khp<NV>
                        getT(0).getT(5).getT(1).getT(0);
		auto& jpanner5 = this->getT(15).getT(1).getT(1).getT(0).                        // jdsp::jpanner<NV>
                         getT(0).getT(5).getT(1).getT(1);
		auto& split14 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(6);         // osc1_impl::split14_t<NV>
		auto& chain71 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(6).getT(0); // osc1_impl::chain71_t<NV>
		auto& cable_table3 = this->getT(15).getT(1).getT(1).getT(0).                    // osc1_impl::cable_table3_t<NV>
                             getT(0).getT(6).getT(0).getT(0);
		auto& faust15 = this->getT(15).getT(1).getT(1).getT(0).                         // project::Comb<NV>
                        getT(0).getT(6).getT(0).getT(1);
		auto& jpanner6 = this->getT(15).getT(1).getT(1).getT(0).                        // jdsp::jpanner<NV>
                         getT(0).getT(6).getT(0).getT(2);
		auto& chain72 = this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(6).getT(1); // osc1_impl::chain72_t<NV>
		auto& cable_table4 = this->getT(15).getT(1).getT(1).getT(0).                    // osc1_impl::cable_table4_t<NV>
                             getT(0).getT(6).getT(1).getT(0);
		auto& faust16 = this->getT(15).getT(1).getT(1).getT(0).   // project::Comb<NV>
                        getT(0).getT(6).getT(1).getT(1);
		auto& jpanner7 = this->getT(15).getT(1).getT(1).getT(0).  // jdsp::jpanner<NV>
                         getT(0).getT(6).getT(1).getT(2);
		auto& gain2 = this->getT(15).getT(1).getT(1).getT(1); // core::gain<NV>
		auto& frame2_block = this->getT(16);                  // osc1_impl::frame2_block_t<NV>
		auto& peak7 = this->getT(16).getT(0);                 // osc1_impl::peak7_t<NV>
		auto& pma = this->getT(16).getT(1);                   // osc1_impl::pma_t<NV>
		auto& gain5 = this->getT(16).getT(2);                 // core::gain<NV>
		auto& jpanner3 = this->getT(17);                      // jdsp::jpanner<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma1); // Pitch -> pma1::Add
		
		this->getParameterT(1).connectT(0, pma8); // tempo -> pma8::Add
		
		this->getParameterT(2).connectT(0, tempo_sync); // div -> tempo_sync::Multiplier
		
		auto& pitchmode_p = this->getParameterT(3);
		pitchmode_p.connectT(0, branch1); // pitchmode -> branch1::Index
		pitchmode_p.connectT(1, branch3); // pitchmode -> branch3::Index
		
		auto& step_p = this->getParameterT(4);
		step_p.connectT(0, minmax2); // step -> minmax2::Step
		step_p.connectT(1, minmax1); // step -> minmax1::Step
		
		this->getParameterT(5).connectT(0, pma2); // Input -> pma2::Add
		
		auto& PitchMod_p = this->getParameterT(6);
		PitchMod_p.connectT(0, pma1);  // PitchMod -> pma1::Multiply
		PitchMod_p.connectT(1, pma9);  // PitchMod -> pma9::Multiply
		PitchMod_p.connectT(2, pma8);  // PitchMod -> pma8::Multiply
		PitchMod_p.connectT(3, pma11); // PitchMod -> pma11::Multiply
		
		this->getParameterT(7).connectT(0, pma2); // InputMod -> pma2::Multiply
		
		this->getParameterT(8).connectT(0, pma4); // OutPut -> pma4::Add
		
		this->getParameterT(9).connectT(0, pma4); // OutMod -> pma4::Multiply
		
		this->getParameterT(10).connectT(0, pma9); // harm -> pma9::Add
		
		this->getParameterT(11).connectT(0, tempo_sync); // sync -> tempo_sync::Enabled
		
		this->getParameterT(12).connectT(0, minmax); // LfoUnsync -> minmax::Value
		
		this->getParameterT(13).connectT(0, event_data_reader14); // XfstagePitch -> event_data_reader14::SlotIndex
		
		this->getParameterT(14).connectT(0, branch5); // MidiSlotPitch -> branch5::Index
		
		this->getParameterT(15).connectT(0, event_data_reader15); // XfstageInput -> event_data_reader15::SlotIndex
		
		this->getParameterT(16).connectT(0, branch4); // MidiSlotIn -> branch4::Index
		
		this->getParameterT(17).connectT(0, event_data_reader18); // XfstageOut -> event_data_reader18::SlotIndex
		
		this->getParameterT(18).connectT(0, branch6); // MidiSlotOut -> branch6::Index
		
		this->getParameterT(19).connectT(0, smoother); // Bend -> smoother::SmoothingTime
		
		this->getParameterT(20).connectT(0, pma12); // ShapeMod -> pma12::Multiply
		
		this->getParameterT(21).connectT(0, pma12); // Shape -> pma12::Add
		
		this->getParameterT(22).connectT(0, pma10); // WidhMod -> pma10::Multiply
		
		this->getParameterT(23).connectT(0, pma10); // Width -> pma10::Add
		
		this->getParameterT(24).connectT(0, event_data_reader27); // XfShape -> event_data_reader27::SlotIndex
		
		this->getParameterT(25).connectT(0, branch9); // MidiShape -> branch9::Index
		
		this->getParameterT(26).connectT(0, event_data_reader24); // XfWidth -> event_data_reader24::SlotIndex
		
		this->getParameterT(27).connectT(0, branch8); // MidiWidth -> branch8::Index
		
		this->getParameterT(28).connectT(0, pma22); // PositionMod -> pma22::Multiply
		
		auto& Position_p = this->getParameterT(29);
		Position_p.connectT(0, pma22);         // Position -> pma22::Add
		Position_p.connectT(1, cable_table19); // Position -> cable_table19::Value
		
		this->getParameterT(30).connectT(0, pma21); // PositionIntMod -> pma21::Multiply
		
		this->getParameterT(31).connectT(0, branch21); // QuantisePositiion -> branch21::Index
		
		this->getParameterT(32).connectT(0, pma29); // PosSmooth -> pma29::Add
		
		this->getParameterT(33).connectT(0, pma29); // SmoothMod -> pma29::Multiply
		
		this->getParameterT(34).connectT(0, pma24); // FilePitch -> pma24::Add
		
		this->getParameterT(35).connectT(0, branch23); // PtichShiftOn -> branch23::Index
		
		this->getParameterT(36).connectT(0, pma24); // FilePitchMod -> pma24::Multiply
		
		this->getParameterT(37).connectT(0, pma26); // PitchWin -> pma26::Add
		
		this->getParameterT(38).connectT(0, pma26); // WinMod -> pma26::Multiply
		
		this->getParameterT(39).connectT(0, pma40); // PitchXf -> pma40::Add
		
		this->getParameterT(40).connectT(0, pma40); // PitchXfMod -> pma40::Multiply
		
		this->getParameterT(41).connectT(0, pma27); // FileInput -> pma27::Add
		
		this->getParameterT(42).connectT(0, pma27); // FileInputMod -> pma27::Multiply
		
		this->getParameterT(43).connectT(0, pma28); // FileModTempo -> pma28::Multiply
		
		auto& FileMix_p = this->getParameterT(44);
		FileMix_p.connectT(0, pma30); // FileMix -> pma30::Add
		FileMix_p.connectT(1, pma30); // FileMix -> pma30::Multiply
		
		this->getParameterT(46).connectT(0, pma28); // FileTempo -> pma28::Add
		
		auto& FileDiv_p = this->getParameterT(47);
		FileDiv_p.connectT(0, tempo_sync6); // FileDiv -> tempo_sync6::Multiplier
		FileDiv_p.connectT(1, clock_ramp1); // FileDiv -> clock_ramp1::Multiplier
		
		this->getParameterT(48).connectT(0, branch24); // FileClk -> branch24::Index
		
		this->getParameterT(49).connectT(0, branch22); // FileUser -> branch22::Index
		
		auto& FileFb_p = this->getParameterT(50);
		FileFb_p.connectT(0, receive2); // FileFb -> receive2::Feedback
		FileFb_p.connectT(1, receive3); // FileFb -> receive3::Feedback
		
		this->getParameterT(51).connectT(0, event_data_reader72); // FileXfSmooth -> event_data_reader72::SlotIndex
		
		this->getParameterT(52).connectT(0, event_data_reader57); // FileXfPitch -> event_data_reader57::SlotIndex
		
		this->getParameterT(53).connectT(0, event_data_reader51); // FileXfpos2 -> event_data_reader51::SlotIndex
		
		this->getParameterT(54).connectT(0, event_data_reader69); // FileXfpostempo -> event_data_reader69::SlotIndex
		
		this->getParameterT(55).connectT(0, event_data_reader75); // FileXfmix -> event_data_reader75::SlotIndex
		
		this->getParameterT(56).connectT(0, event_data_reader63); // FileXfpitchfade -> event_data_reader63::SlotIndex
		
		this->getParameterT(57).connectT(0, event_data_reader60); // FileXfwindow -> event_data_reader60::SlotIndex
		
		this->getParameterT(58).connectT(0, branch33); // FileMidiSmooth -> branch33::Index
		
		this->getParameterT(59).connectT(0, branch28); // FileMidiPitch -> branch28::Index
		
		this->getParameterT(60).connectT(0, branch26); // FileMidipos2 -> branch26::Index
		
		this->getParameterT(61).connectT(0, branch32); // FileMidipostempo -> branch32::Index
		
		this->getParameterT(62).connectT(0, branch34); // FileMidimix -> branch34::Index
		
		this->getParameterT(63).connectT(0, branch30); // FileMidipitchfade -> branch30::Index
		
		this->getParameterT(64).connectT(0, branch29); // FileMidiwindow -> branch29::Index
		
		this->getParameterT(65).connectT(0, branch31); // FileMidiInput -> branch31::Index
		
		this->getParameterT(66).connectT(0, event_data_reader66); // FileXfInput -> event_data_reader66::SlotIndex
		
		this->getParameterT(67).connectT(0, pma23); // Osc2Pos -> pma23::Multiply
		
		auto& Q_p = this->getParameterT(69);
		Q_p.connectT(0, faust);   // Q -> faust::Q
		Q_p.connectT(1, faust2);  // Q -> faust2::Q
		Q_p.connectT(2, faust8);  // Q -> faust8::aN
		Q_p.connectT(3, faust10); // Q -> faust10::Q
		Q_p.connectT(4, faust11); // Q -> faust11::Q
		Q_p.connectT(5, faust13); // Q -> faust13::Q
		Q_p.connectT(6, faust15); // Q -> faust15::aN
		
		this->getParameterT(70).connectT(0, pma33); // FilterMix -> pma33::Add
		
		this->getParameterT(71).connectT(0, pma33); // FilterMod -> pma33::Multiply
		
		this->getParameterT(72).connectT(0, pma37); // Cut1 -> pma37::Add
		
		this->getParameterT(73).connectT(0, pma32); // Cut1Mod -> pma32::Multiply
		
		this->getParameterT(74).connectT(0, pma38); // Cut2 -> pma38::Add
		
		this->getParameterT(75).connectT(0, pma34); // Cut2Mod -> pma34::Multiply
		
		this->getParameterT(76).connectT(0, pma39); // Gain -> pma39::Add
		
		this->getParameterT(78).connectT(0, pma36); // Pan -> pma36::Add
		
		this->getParameterT(79).connectT(0, pma36); // PanMod -> pma36::Multiply
		
		this->getParameterT(80).connectT(0, event_data_reader81); // FilterXfMix -> event_data_reader81::SlotIndex
		
		this->getParameterT(81).connectT(0, event_data_reader78); // FilterXfCut1 -> event_data_reader78::SlotIndex
		
		this->getParameterT(82).connectT(0, event_data_reader84); // FilterXfCut2 -> event_data_reader84::SlotIndex
		
		this->getParameterT(83).connectT(0, event_data_reader87); // FilterXfGain -> event_data_reader87::SlotIndex
		
		this->getParameterT(84).connectT(0, event_data_reader90); // FilterXfPan -> event_data_reader90::SlotIndex
		
		this->getParameterT(85).connectT(0, branch36); // FilterMidiMix -> branch36::Index
		
		this->getParameterT(86).connectT(0, branch35); // FilterMidiCut1 -> branch35::Index
		
		this->getParameterT(87).connectT(0, branch37); // FilterMidiCut2 -> branch37::Index
		
		this->getParameterT(88).connectT(0, branch38); // FilterMidiGain -> branch38::Index
		
		this->getParameterT(89).connectT(0, branch39); // FilterMidiPan -> branch39::Index
		
		this->getParameterT(90).connectT(0, pma37); // FilterOsc -> pma37::Multiply
		
		this->getParameterT(91).connectT(0, pma38); // Osc2Filter2 -> pma38::Multiply
		
		auto& osc2Gain_p = this->getParameterT(92);
		osc2Gain_p.connectT(0, pma39); // osc2Gain -> pma39::Multiply
		osc2Gain_p.connectT(1, pma);   // osc2Gain -> pma::Multiply
		
		this->getParameterT(93).connectT(0, gain9); // PreFilterGain -> gain9::Gain
		
		this->getParameterT(94).connectT(0, branch); // FilterMode -> branch::Index
		
		auto& q2_p = this->getParameterT(95);
		q2_p.connectT(0, faust16); // q2 -> faust16::aN
		q2_p.connectT(1, faust14); // q2 -> faust14::Q
		q2_p.connectT(2, faust12); // q2 -> faust12::Q
		q2_p.connectT(3, faust9);  // q2 -> faust9::aN
		q2_p.connectT(4, faust7);  // q2 -> faust7::Q
		q2_p.connectT(5, faust6);  // q2 -> faust6::Q
		q2_p.connectT(6, faust1);  // q2 -> faust1::Q
		
		this->getParameterT(96).connectT(0, ramp1); // OneShot -> ramp1::LoopStart
		
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
		global_cable14.getWrappedObject().getParameter().connectT(0, add27);  // global_cable14 -> add27::Value
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
		converter5.getWrappedObject().getParameter().connectT(1, phasor_fm1); // converter5 -> phasor_fm1::Frequency
		tempo_sync.getParameter().connectT(0, converter5);                    // tempo_sync -> converter5::Value
		pma8.getWrappedObject().getParameter().connectT(0, tempo_sync);       // pma8 -> tempo_sync::Tempo
		pma11.getWrappedObject().getParameter().connectT(0, tempo_sync);      // pma11 -> tempo_sync::UnsyncedTime
		peak3.getParameter().connectT(0, pma1);                               // peak3 -> pma1::Value
		peak3.getParameter().connectT(1, pma9);                               // peak3 -> pma9::Value
		peak3.getParameter().connectT(2, pma8);                               // peak3 -> pma8::Value
		peak3.getParameter().connectT(3, pma11);                              // peak3 -> pma11::Value
		minmax.getWrappedObject().getParameter().connectT(0, pma11);          // minmax -> pma11::Add
		converter.getWrappedObject().getParameter().connectT(0, phasor_fm);   // converter -> phasor_fm::FreqRatio
		minmax2.getWrappedObject().getParameter().connectT(0, converter);     // minmax2 -> converter::Value
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
		global_cable25.getWrappedObject().getParameter().connectT(0, add33); // global_cable25 -> add33::Value
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
		global_cable26.getWrappedObject().getParameter().connectT(0, add45); // global_cable26 -> add45::Value
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
		pma4.getWrappedObject().getParameter().connectT(0, gain4);           // pma4 -> gain4::Gain
		peak6.getParameter().connectT(0, pma4);                              // peak6 -> pma4::Value
		auto& sliderbank9_p = sliderbank9.getWrappedObject().getParameter();
		sliderbank9_p.getParameterT(0).connectT(0, gain81);                  // sliderbank9 -> gain81::Gain
		sliderbank9_p.getParameterT(1).connectT(0, gain82);                  // sliderbank9 -> gain82::Gain
		sliderbank9_p.getParameterT(2).connectT(0, gain83);                  // sliderbank9 -> gain83::Gain
		sliderbank9_p.getParameterT(3).connectT(0, gain84);                  // sliderbank9 -> gain84::Gain
		sliderbank9_p.getParameterT(4).connectT(0, gain85);                  // sliderbank9 -> gain85::Gain
		sliderbank9_p.getParameterT(5).connectT(0, gain86);                  // sliderbank9 -> gain86::Gain
		sliderbank9_p.getParameterT(6).connectT(0, gain87);                  // sliderbank9 -> gain87::Gain
		sliderbank9_p.getParameterT(7).connectT(0, gain88);                  // sliderbank9 -> gain88::Gain
		global_cable9.getWrappedObject().getParameter().connectT(0, add16);  // global_cable9 -> add16::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add87); // global_cable22 -> add87::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add17); // global_cable23 -> add17::Value
		global_cable29.getWrappedObject().getParameter().connectT(0, add88); // global_cable29 -> add88::Value
		event_data_reader25.getParameter().connectT(0, add89);               // event_data_reader25 -> add89::Value
		event_data_reader26.getParameter().connectT(0, add90);               // event_data_reader26 -> add90::Value
		event_data_reader27.getParameter().connectT(0, add91);               // event_data_reader27 -> add91::Value
		midi_cc26.getWrappedObject().getParameter().connectT(0, add92);      // midi_cc26 -> add92::Value
		midi_cc27.getWrappedObject().getParameter().connectT(0, add93);      // midi_cc27 -> add93::Value
		midi_cc28.getWrappedObject().getParameter().connectT(0, add94);      // midi_cc28 -> add94::Value
		midi_cc29.getWrappedObject().getParameter().connectT(0, add95);      // midi_cc29 -> add95::Value
		midi18.getParameter().connectT(0, add96);                            // midi18 -> add96::Value
		midi19.getParameter().connectT(0, add97);                            // midi19 -> add97::Value
		midi20.getParameter().connectT(0, add98);                            // midi20 -> add98::Value
		auto& xfader2_p = xfader2.getWrappedObject().getParameter();
		xfader2_p.getParameterT(0).connectT(0, gain12);               // xfader2 -> gain12::Gain
		xfader2_p.getParameterT(1).connectT(0, gain52);               // xfader2 -> gain52::Gain
		xfader2_p.getParameterT(2).connectT(0, gain55);               // xfader2 -> gain55::Gain
		xfader2_p.getParameterT(3).connectT(0, gain57);               // xfader2 -> gain57::Gain
		xfader2_p.getParameterT(4).connectT(0, gain3);                // xfader2 -> gain3::Gain
		xfader2_p.getParameterT(5).connectT(0, gain60);               // xfader2 -> gain60::Gain
		xfader2_p.getParameterT(6).connectT(0, gain62);               // xfader2 -> gain62::Gain
		xfader2_p.getParameterT(7).connectT(0, gain64);               // xfader2 -> gain64::Gain
		pma12.getWrappedObject().getParameter().connectT(0, xfader2); // pma12 -> xfader2::Value
		peak9.getParameter().connectT(0, pma12);                      // peak9 -> pma12::Value
		auto& sliderbank8_p = sliderbank8.getWrappedObject().getParameter();
		sliderbank8_p.getParameterT(0).connectT(0, gain73);                  // sliderbank8 -> gain73::Gain
		sliderbank8_p.getParameterT(1).connectT(0, gain74);                  // sliderbank8 -> gain74::Gain
		sliderbank8_p.getParameterT(2).connectT(0, gain75);                  // sliderbank8 -> gain75::Gain
		sliderbank8_p.getParameterT(3).connectT(0, gain76);                  // sliderbank8 -> gain76::Gain
		sliderbank8_p.getParameterT(4).connectT(0, gain77);                  // sliderbank8 -> gain77::Gain
		sliderbank8_p.getParameterT(5).connectT(0, gain78);                  // sliderbank8 -> gain78::Gain
		sliderbank8_p.getParameterT(6).connectT(0, gain79);                  // sliderbank8 -> gain79::Gain
		sliderbank8_p.getParameterT(7).connectT(0, gain80);                  // sliderbank8 -> gain80::Gain
		global_cable8.getWrappedObject().getParameter().connectT(0, add14);  // global_cable8 -> add14::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add75); // global_cable20 -> add75::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add15); // global_cable21 -> add15::Value
		global_cable28.getWrappedObject().getParameter().connectT(0, add76); // global_cable28 -> add76::Value
		event_data_reader22.getParameter().connectT(0, add77);               // event_data_reader22 -> add77::Value
		event_data_reader23.getParameter().connectT(0, add78);               // event_data_reader23 -> add78::Value
		event_data_reader24.getParameter().connectT(0, add79);               // event_data_reader24 -> add79::Value
		midi_cc22.getWrappedObject().getParameter().connectT(0, add80);      // midi_cc22 -> add80::Value
		midi_cc23.getWrappedObject().getParameter().connectT(0, add81);      // midi_cc23 -> add81::Value
		midi_cc24.getWrappedObject().getParameter().connectT(0, add82);      // midi_cc24 -> add82::Value
		midi_cc25.getWrappedObject().getParameter().connectT(0, add83);      // midi_cc25 -> add83::Value
		midi15.getParameter().connectT(0, add84);                            // midi15 -> add84::Value
		midi16.getParameter().connectT(0, add85);                            // midi16 -> add85::Value
		midi17.getParameter().connectT(0, add86);                            // midi17 -> add86::Value
		auto& xfader3_p = xfader3.getWrappedObject().getParameter();
		xfader3_p.getParameterT(0).connectT(0, gain49);                       // xfader3 -> gain49::Gain
		xfader3_p.getParameterT(1).connectT(0, gain50);                       // xfader3 -> gain50::Gain
		clone_cable2.getWrappedObject().getParameter().connectT(0, jpanner1); // clone_cable2 -> jpanner1::Pan
		clone_cable2.getWrappedObject().getParameter().connectT(1, gain61);   // clone_cable2 -> gain61::Gain
		clone_cable4.getWrappedObject().getParameter().connectT(0, expr9);    // clone_cable4 -> expr9::Value
		pma6.getWrappedObject().getParameter().connectT(0, gain63);           // pma6 -> gain63::Gain
		pma6.getWrappedObject().getParameter().connectT(1, gain59);           // pma6 -> gain59::Gain
		pma6.getWrappedObject().getParameter().connectT(2, gain53);           // pma6 -> gain53::Gain
		pma6.getWrappedObject().getParameter().connectT(3, gain56);           // pma6 -> gain56::Gain
		pma6.getWrappedObject().getParameter().connectT(4, expr6);            // pma6 -> expr6::Value
		pma6.getWrappedObject().getParameter().connectT(5, phase_delay1);     // pma6 -> phase_delay1::Frequency
		pma6.getWrappedObject().getParameter().connectT(6, xfader3);          // pma6 -> xfader3::Value
		pma6.getWrappedObject().getParameter().connectT(7, gain58);           // pma6 -> gain58::Gain
		pma6.getWrappedObject().getParameter().connectT(8, cable_table1);     // pma6 -> cable_table1::Value
		pma6.getWrappedObject().getParameter().connectT(9, clone_cable2);     // pma6 -> clone_cable2::Value
		pma6.getWrappedObject().getParameter().connectT(10, clone_cable4);    // pma6 -> clone_cable4::Value
		pma6.getWrappedObject().getParameter().connectT(11, gain51);          // pma6 -> gain51::Gain
		pma10.getWrappedObject().getParameter().connectT(0, pma6);            // pma10 -> pma6::Add
		peak8.getParameter().connectT(0, pma10);                              // peak8 -> pma10::Value
		auto& sliderbank18_p = sliderbank18.getWrappedObject().getParameter();
		sliderbank18_p.getParameterT(0).connectT(0, gain148);                 // sliderbank18 -> gain148::Gain
		sliderbank18_p.getParameterT(1).connectT(0, gain149);                 // sliderbank18 -> gain149::Gain
		sliderbank18_p.getParameterT(2).connectT(0, gain150);                 // sliderbank18 -> gain150::Gain
		sliderbank18_p.getParameterT(3).connectT(0, gain151);                 // sliderbank18 -> gain151::Gain
		sliderbank18_p.getParameterT(4).connectT(0, gain152);                 // sliderbank18 -> gain152::Gain
		sliderbank18_p.getParameterT(5).connectT(0, gain153);                 // sliderbank18 -> gain153::Gain
		sliderbank18_p.getParameterT(6).connectT(0, gain154);                 // sliderbank18 -> gain154::Gain
		sliderbank18_p.getParameterT(7).connectT(0, gain155);                 // sliderbank18 -> gain155::Gain
		global_cable63.getWrappedObject().getParameter().connectT(0, add254); // global_cable63 -> add254::Value
		global_cable64.getWrappedObject().getParameter().connectT(0, add255); // global_cable64 -> add255::Value
		global_cable65.getWrappedObject().getParameter().connectT(0, add256); // global_cable65 -> add256::Value
		global_cable66.getWrappedObject().getParameter().connectT(0, add257); // global_cable66 -> add257::Value
		event_data_reader55.getParameter().connectT(0, add258);               // event_data_reader55 -> add258::Value
		event_data_reader56.getParameter().connectT(0, add259);               // event_data_reader56 -> add259::Value
		event_data_reader57.getParameter().connectT(0, add260);               // event_data_reader57 -> add260::Value
		midi_cc66.getWrappedObject().getParameter().connectT(0, add261);      // midi_cc66 -> add261::Value
		midi_cc67.getWrappedObject().getParameter().connectT(0, add262);      // midi_cc67 -> add262::Value
		midi_cc68.getWrappedObject().getParameter().connectT(0, add263);      // midi_cc68 -> add263::Value
		midi_cc69.getWrappedObject().getParameter().connectT(0, add264);      // midi_cc69 -> add264::Value
		midi49.getParameter().connectT(0, add265);                            // midi49 -> add265::Value
		midi50.getParameter().connectT(0, add266);                            // midi50 -> add266::Value
		midi51.getParameter().connectT(0, add267);                            // midi51 -> add267::Value
		pma24.getWrappedObject().getParameter().connectT(0, faust3);          // pma24 -> faust3::shiftnote
		pma24.getWrappedObject().getParameter().connectT(1, faust5);          // pma24 -> faust5::shiftnote
		peak23.getParameter().connectT(0, pma24);                             // peak23 -> pma24::Value
		auto& sliderbank19_p = sliderbank19.getWrappedObject().getParameter();
		sliderbank19_p.getParameterT(0).connectT(0, gain156);                 // sliderbank19 -> gain156::Gain
		sliderbank19_p.getParameterT(1).connectT(0, gain157);                 // sliderbank19 -> gain157::Gain
		sliderbank19_p.getParameterT(2).connectT(0, gain158);                 // sliderbank19 -> gain158::Gain
		sliderbank19_p.getParameterT(3).connectT(0, gain159);                 // sliderbank19 -> gain159::Gain
		sliderbank19_p.getParameterT(4).connectT(0, gain160);                 // sliderbank19 -> gain160::Gain
		sliderbank19_p.getParameterT(5).connectT(0, gain161);                 // sliderbank19 -> gain161::Gain
		sliderbank19_p.getParameterT(6).connectT(0, gain162);                 // sliderbank19 -> gain162::Gain
		sliderbank19_p.getParameterT(7).connectT(0, gain163);                 // sliderbank19 -> gain163::Gain
		global_cable67.getWrappedObject().getParameter().connectT(0, add268); // global_cable67 -> add268::Value
		global_cable68.getWrappedObject().getParameter().connectT(0, add269); // global_cable68 -> add269::Value
		global_cable69.getWrappedObject().getParameter().connectT(0, add270); // global_cable69 -> add270::Value
		global_cable70.getWrappedObject().getParameter().connectT(0, add271); // global_cable70 -> add271::Value
		event_data_reader58.getParameter().connectT(0, add272);               // event_data_reader58 -> add272::Value
		event_data_reader59.getParameter().connectT(0, add273);               // event_data_reader59 -> add273::Value
		event_data_reader60.getParameter().connectT(0, add274);               // event_data_reader60 -> add274::Value
		midi_cc70.getWrappedObject().getParameter().connectT(0, add275);      // midi_cc70 -> add275::Value
		midi_cc71.getWrappedObject().getParameter().connectT(0, add276);      // midi_cc71 -> add276::Value
		midi_cc72.getWrappedObject().getParameter().connectT(0, add277);      // midi_cc72 -> add277::Value
		midi_cc73.getWrappedObject().getParameter().connectT(0, add278);      // midi_cc73 -> add278::Value
		midi52.getParameter().connectT(0, add279);                            // midi52 -> add279::Value
		midi53.getParameter().connectT(0, add280);                            // midi53 -> add280::Value
		midi54.getParameter().connectT(0, add281);                            // midi54 -> add281::Value
		pma26.getWrappedObject().getParameter().connectT(0, faust3);          // pma26 -> faust3::windowsamples
		pma26.getWrappedObject().getParameter().connectT(1, faust4);          // pma26 -> faust4::windowsamples
		pma26.getWrappedObject().getParameter().connectT(2, faust5);          // pma26 -> faust5::windowsamples
		peak24.getParameter().connectT(0, pma26);                             // peak24 -> pma26::Value
		auto& sliderbank20_p = sliderbank20.getWrappedObject().getParameter();
		sliderbank20_p.getParameterT(0).connectT(0, gain164);                 // sliderbank20 -> gain164::Gain
		sliderbank20_p.getParameterT(1).connectT(0, gain165);                 // sliderbank20 -> gain165::Gain
		sliderbank20_p.getParameterT(2).connectT(0, gain166);                 // sliderbank20 -> gain166::Gain
		sliderbank20_p.getParameterT(3).connectT(0, gain167);                 // sliderbank20 -> gain167::Gain
		sliderbank20_p.getParameterT(4).connectT(0, gain168);                 // sliderbank20 -> gain168::Gain
		sliderbank20_p.getParameterT(5).connectT(0, gain169);                 // sliderbank20 -> gain169::Gain
		sliderbank20_p.getParameterT(6).connectT(0, gain170);                 // sliderbank20 -> gain170::Gain
		sliderbank20_p.getParameterT(7).connectT(0, gain171);                 // sliderbank20 -> gain171::Gain
		global_cable71.getWrappedObject().getParameter().connectT(0, add282); // global_cable71 -> add282::Value
		global_cable72.getWrappedObject().getParameter().connectT(0, add283); // global_cable72 -> add283::Value
		global_cable73.getWrappedObject().getParameter().connectT(0, add284); // global_cable73 -> add284::Value
		global_cable74.getWrappedObject().getParameter().connectT(0, add285); // global_cable74 -> add285::Value
		event_data_reader61.getParameter().connectT(0, add286);               // event_data_reader61 -> add286::Value
		event_data_reader62.getParameter().connectT(0, add287);               // event_data_reader62 -> add287::Value
		event_data_reader63.getParameter().connectT(0, add288);               // event_data_reader63 -> add288::Value
		midi_cc74.getWrappedObject().getParameter().connectT(0, add289);      // midi_cc74 -> add289::Value
		midi_cc75.getWrappedObject().getParameter().connectT(0, add290);      // midi_cc75 -> add290::Value
		midi_cc76.getWrappedObject().getParameter().connectT(0, add291);      // midi_cc76 -> add291::Value
		midi_cc77.getWrappedObject().getParameter().connectT(0, add292);      // midi_cc77 -> add292::Value
		midi55.getParameter().connectT(0, add293);                            // midi55 -> add293::Value
		midi56.getParameter().connectT(0, add294);                            // midi56 -> add294::Value
		midi57.getParameter().connectT(0, add295);                            // midi57 -> add295::Value
		pma40.getWrappedObject().getParameter().connectT(0, faust3);          // pma40 -> faust3::xfadesamples
		pma40.getWrappedObject().getParameter().connectT(1, faust5);          // pma40 -> faust5::xfadesamples
		pma40.getWrappedObject().getParameter().connectT(2, faust4);          // pma40 -> faust4::xfadesamples
		peak25.getParameter().connectT(0, pma40);                             // peak25 -> pma40::Value
		auto& sliderbank21_p = sliderbank21.getWrappedObject().getParameter();
		sliderbank21_p.getParameterT(0).connectT(0, gain172);                 // sliderbank21 -> gain172::Gain
		sliderbank21_p.getParameterT(1).connectT(0, gain173);                 // sliderbank21 -> gain173::Gain
		sliderbank21_p.getParameterT(2).connectT(0, gain174);                 // sliderbank21 -> gain174::Gain
		sliderbank21_p.getParameterT(3).connectT(0, gain175);                 // sliderbank21 -> gain175::Gain
		sliderbank21_p.getParameterT(4).connectT(0, gain176);                 // sliderbank21 -> gain176::Gain
		sliderbank21_p.getParameterT(5).connectT(0, gain177);                 // sliderbank21 -> gain177::Gain
		sliderbank21_p.getParameterT(6).connectT(0, gain178);                 // sliderbank21 -> gain178::Gain
		sliderbank21_p.getParameterT(7).connectT(0, gain179);                 // sliderbank21 -> gain179::Gain
		global_cable75.getWrappedObject().getParameter().connectT(0, add296); // global_cable75 -> add296::Value
		global_cable76.getWrappedObject().getParameter().connectT(0, add297); // global_cable76 -> add297::Value
		global_cable77.getWrappedObject().getParameter().connectT(0, add298); // global_cable77 -> add298::Value
		global_cable78.getWrappedObject().getParameter().connectT(0, add299); // global_cable78 -> add299::Value
		event_data_reader64.getParameter().connectT(0, add300);               // event_data_reader64 -> add300::Value
		event_data_reader65.getParameter().connectT(0, add301);               // event_data_reader65 -> add301::Value
		event_data_reader66.getParameter().connectT(0, add302);               // event_data_reader66 -> add302::Value
		midi_cc78.getWrappedObject().getParameter().connectT(0, add303);      // midi_cc78 -> add303::Value
		midi_cc79.getWrappedObject().getParameter().connectT(0, add304);      // midi_cc79 -> add304::Value
		midi_cc80.getWrappedObject().getParameter().connectT(0, add305);      // midi_cc80 -> add305::Value
		midi_cc81.getWrappedObject().getParameter().connectT(0, add306);      // midi_cc81 -> add306::Value
		midi58.getParameter().connectT(0, add307);                            // midi58 -> add307::Value
		midi59.getParameter().connectT(0, add308);                            // midi59 -> add308::Value
		midi60.getParameter().connectT(0, add309);                            // midi60 -> add309::Value
		pma27.getWrappedObject().getParameter().connectT(0, gain6);           // pma27 -> gain6::Gain
		peak26.getParameter().connectT(0, pma27);                             // peak26 -> pma27::Value
		auto& sliderbank22_p = sliderbank22.getWrappedObject().getParameter();
		sliderbank22_p.getParameterT(0).connectT(0, gain180);                 // sliderbank22 -> gain180::Gain
		sliderbank22_p.getParameterT(1).connectT(0, gain181);                 // sliderbank22 -> gain181::Gain
		sliderbank22_p.getParameterT(2).connectT(0, gain182);                 // sliderbank22 -> gain182::Gain
		sliderbank22_p.getParameterT(3).connectT(0, gain183);                 // sliderbank22 -> gain183::Gain
		sliderbank22_p.getParameterT(4).connectT(0, gain184);                 // sliderbank22 -> gain184::Gain
		sliderbank22_p.getParameterT(5).connectT(0, gain185);                 // sliderbank22 -> gain185::Gain
		sliderbank22_p.getParameterT(6).connectT(0, gain186);                 // sliderbank22 -> gain186::Gain
		sliderbank22_p.getParameterT(7).connectT(0, gain187);                 // sliderbank22 -> gain187::Gain
		global_cable79.getWrappedObject().getParameter().connectT(0, add310); // global_cable79 -> add310::Value
		global_cable80.getWrappedObject().getParameter().connectT(0, add311); // global_cable80 -> add311::Value
		global_cable81.getWrappedObject().getParameter().connectT(0, add312); // global_cable81 -> add312::Value
		global_cable82.getWrappedObject().getParameter().connectT(0, add313); // global_cable82 -> add313::Value
		event_data_reader67.getParameter().connectT(0, add314);               // event_data_reader67 -> add314::Value
		event_data_reader68.getParameter().connectT(0, add315);               // event_data_reader68 -> add315::Value
		event_data_reader69.getParameter().connectT(0, add316);               // event_data_reader69 -> add316::Value
		midi_cc82.getWrappedObject().getParameter().connectT(0, add317);      // midi_cc82 -> add317::Value
		midi_cc83.getWrappedObject().getParameter().connectT(0, add318);      // midi_cc83 -> add318::Value
		midi_cc84.getWrappedObject().getParameter().connectT(0, add319);      // midi_cc84 -> add319::Value
		midi_cc85.getWrappedObject().getParameter().connectT(0, add320);      // midi_cc85 -> add320::Value
		midi61.getParameter().connectT(0, add321);                            // midi61 -> add321::Value
		midi62.getParameter().connectT(0, add322);                            // midi62 -> add322::Value
		midi63.getParameter().connectT(0, add323);                            // midi63 -> add323::Value
		minmax6.getWrappedObject().getParameter().connectT(0, add214);        // minmax6 -> add214::Value
		minmax7.getWrappedObject().getParameter().connectT(0, add215);        // minmax7 -> add215::Value
		minmax14.getWrappedObject().getParameter().connectT(0, add216);       // minmax14 -> add216::Value
		minmax11.getWrappedObject().getParameter().connectT(0, add217);       // minmax11 -> add217::Value
		minmax15.getWrappedObject().getParameter().connectT(0, add218);       // minmax15 -> add218::Value
		minmax16.getWrappedObject().getParameter().connectT(0, add219);       // minmax16 -> add219::Value
		minmax17.getWrappedObject().getParameter().connectT(0, add220);       // minmax17 -> add220::Value
		minmax18.getWrappedObject().getParameter().connectT(0, add221);       // minmax18 -> add221::Value
		pma21.getWrappedObject().getParameter().connectT(0, add213);          // pma21 -> add213::Value
		pma21.getWrappedObject().getParameter().connectT(1, minmax6);         // pma21 -> minmax6::Value
		pma21.getWrappedObject().getParameter().connectT(2, minmax7);         // pma21 -> minmax7::Value
		pma21.getWrappedObject().getParameter().connectT(3, minmax14);        // pma21 -> minmax14::Value
		pma21.getWrappedObject().getParameter().connectT(4, minmax11);        // pma21 -> minmax11::Value
		pma21.getWrappedObject().getParameter().connectT(5, minmax15);        // pma21 -> minmax15::Value
		pma21.getWrappedObject().getParameter().connectT(6, minmax16);        // pma21 -> minmax16::Value
		pma21.getWrappedObject().getParameter().connectT(7, minmax17);        // pma21 -> minmax17::Value
		pma21.getWrappedObject().getParameter().connectT(8, minmax18);        // pma21 -> minmax18::Value
		pma21.getWrappedObject().getParameter().connectT(9, cable_table16);   // pma21 -> cable_table16::Value
		cable_table17.getWrappedObject().getParameter().connectT(0, pma21);   // cable_table17 -> pma21::Value
		ramp1.getParameter().connectT(0, cable_table17);                      // ramp1 -> cable_table17::Value
		tempo_sync6.getParameter().connectT(0, ramp1);                        // tempo_sync6 -> ramp1::PeriodTime
		clock_ramp1.getParameter().connectT(0, add224);                       // clock_ramp1 -> add224::Value
		pma28.getWrappedObject().getParameter().connectT(0, tempo_sync6);     // pma28 -> tempo_sync6::Tempo
		pma28.getWrappedObject().getParameter().connectT(1, clock_ramp1);     // pma28 -> clock_ramp1::Tempo
		peak27.getParameter().connectT(0, pma28);                             // peak27 -> pma28::Value
		auto& sliderbank23_p = sliderbank23.getWrappedObject().getParameter();
		sliderbank23_p.getParameterT(0).connectT(0, gain188);                 // sliderbank23 -> gain188::Gain
		sliderbank23_p.getParameterT(1).connectT(0, gain189);                 // sliderbank23 -> gain189::Gain
		sliderbank23_p.getParameterT(2).connectT(0, gain190);                 // sliderbank23 -> gain190::Gain
		sliderbank23_p.getParameterT(3).connectT(0, gain191);                 // sliderbank23 -> gain191::Gain
		sliderbank23_p.getParameterT(4).connectT(0, gain192);                 // sliderbank23 -> gain192::Gain
		sliderbank23_p.getParameterT(5).connectT(0, gain193);                 // sliderbank23 -> gain193::Gain
		sliderbank23_p.getParameterT(6).connectT(0, gain194);                 // sliderbank23 -> gain194::Gain
		sliderbank23_p.getParameterT(7).connectT(0, gain195);                 // sliderbank23 -> gain195::Gain
		global_cable83.getWrappedObject().getParameter().connectT(0, add324); // global_cable83 -> add324::Value
		global_cable84.getWrappedObject().getParameter().connectT(0, add325); // global_cable84 -> add325::Value
		global_cable85.getWrappedObject().getParameter().connectT(0, add326); // global_cable85 -> add326::Value
		global_cable86.getWrappedObject().getParameter().connectT(0, add327); // global_cable86 -> add327::Value
		event_data_reader70.getParameter().connectT(0, add328);               // event_data_reader70 -> add328::Value
		event_data_reader71.getParameter().connectT(0, add329);               // event_data_reader71 -> add329::Value
		event_data_reader72.getParameter().connectT(0, add330);               // event_data_reader72 -> add330::Value
		midi_cc86.getWrappedObject().getParameter().connectT(0, add331);      // midi_cc86 -> add331::Value
		midi_cc87.getWrappedObject().getParameter().connectT(0, add332);      // midi_cc87 -> add332::Value
		midi_cc88.getWrappedObject().getParameter().connectT(0, add333);      // midi_cc88 -> add333::Value
		midi_cc89.getWrappedObject().getParameter().connectT(0, add334);      // midi_cc89 -> add334::Value
		midi64.getParameter().connectT(0, add335);                            // midi64 -> add335::Value
		midi65.getParameter().connectT(0, add336);                            // midi65 -> add336::Value
		midi66.getParameter().connectT(0, add337);                            // midi66 -> add337::Value
		pma29.getWrappedObject().getParameter().connectT(0, expr10);          // pma29 -> expr10::Value
		peak28.getParameter().connectT(0, pma29);                             // peak28 -> pma29::Value
		auto& sliderbank24_p = sliderbank24.getWrappedObject().getParameter();
		sliderbank24_p.getParameterT(0).connectT(0, gain196);                 // sliderbank24 -> gain196::Gain
		sliderbank24_p.getParameterT(1).connectT(0, gain197);                 // sliderbank24 -> gain197::Gain
		sliderbank24_p.getParameterT(2).connectT(0, gain198);                 // sliderbank24 -> gain198::Gain
		sliderbank24_p.getParameterT(3).connectT(0, gain199);                 // sliderbank24 -> gain199::Gain
		sliderbank24_p.getParameterT(4).connectT(0, gain200);                 // sliderbank24 -> gain200::Gain
		sliderbank24_p.getParameterT(5).connectT(0, gain201);                 // sliderbank24 -> gain201::Gain
		sliderbank24_p.getParameterT(6).connectT(0, gain202);                 // sliderbank24 -> gain202::Gain
		sliderbank24_p.getParameterT(7).connectT(0, gain203);                 // sliderbank24 -> gain203::Gain
		global_cable87.getWrappedObject().getParameter().connectT(0, add338); // global_cable87 -> add338::Value
		global_cable88.getWrappedObject().getParameter().connectT(0, add339); // global_cable88 -> add339::Value
		global_cable89.getWrappedObject().getParameter().connectT(0, add340); // global_cable89 -> add340::Value
		global_cable90.getWrappedObject().getParameter().connectT(0, add341); // global_cable90 -> add341::Value
		event_data_reader73.getParameter().connectT(0, add342);               // event_data_reader73 -> add342::Value
		event_data_reader74.getParameter().connectT(0, add343);               // event_data_reader74 -> add343::Value
		event_data_reader75.getParameter().connectT(0, add344);               // event_data_reader75 -> add344::Value
		midi_cc90.getWrappedObject().getParameter().connectT(0, add345);      // midi_cc90 -> add345::Value
		midi_cc91.getWrappedObject().getParameter().connectT(0, add346);      // midi_cc91 -> add346::Value
		midi_cc92.getWrappedObject().getParameter().connectT(0, add347);      // midi_cc92 -> add347::Value
		midi_cc93.getWrappedObject().getParameter().connectT(0, add348);      // midi_cc93 -> add348::Value
		midi67.getParameter().connectT(0, add349);                            // midi67 -> add349::Value
		midi68.getParameter().connectT(0, add350);                            // midi68 -> add350::Value
		midi69.getParameter().connectT(0, add351);                            // midi69 -> add351::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain7);                // xfader1 -> gain7::Gain
		xfader1_p.getParameterT(1).connectT(0, gain8);                // xfader1 -> gain8::Gain
		pma30.getWrappedObject().getParameter().connectT(0, xfader1); // pma30 -> xfader1::Value
		peak29.getParameter().connectT(0, pma30);                     // peak29 -> pma30::Value
		auto& sliderbank26_p = sliderbank26.getWrappedObject().getParameter();
		sliderbank26_p.getParameterT(0).connectT(0, gain212);                 // sliderbank26 -> gain212::Gain
		sliderbank26_p.getParameterT(1).connectT(0, gain213);                 // sliderbank26 -> gain213::Gain
		sliderbank26_p.getParameterT(2).connectT(0, gain214);                 // sliderbank26 -> gain214::Gain
		sliderbank26_p.getParameterT(3).connectT(0, gain215);                 // sliderbank26 -> gain215::Gain
		sliderbank26_p.getParameterT(4).connectT(0, gain216);                 // sliderbank26 -> gain216::Gain
		sliderbank26_p.getParameterT(5).connectT(0, gain217);                 // sliderbank26 -> gain217::Gain
		sliderbank26_p.getParameterT(6).connectT(0, gain218);                 // sliderbank26 -> gain218::Gain
		sliderbank26_p.getParameterT(7).connectT(0, gain219);                 // sliderbank26 -> gain219::Gain
		global_cable95.getWrappedObject().getParameter().connectT(0, add366); // global_cable95 -> add366::Value
		global_cable96.getWrappedObject().getParameter().connectT(0, add367); // global_cable96 -> add367::Value
		global_cable97.getWrappedObject().getParameter().connectT(0, add368); // global_cable97 -> add368::Value
		global_cable98.getWrappedObject().getParameter().connectT(0, add369); // global_cable98 -> add369::Value
		event_data_reader79.getParameter().connectT(0, add370);               // event_data_reader79 -> add370::Value
		event_data_reader80.getParameter().connectT(0, add371);               // event_data_reader80 -> add371::Value
		event_data_reader81.getParameter().connectT(0, add372);               // event_data_reader81 -> add372::Value
		midi_cc98.getWrappedObject().getParameter().connectT(0, add373);      // midi_cc98 -> add373::Value
		midi_cc99.getWrappedObject().getParameter().connectT(0, add374);      // midi_cc99 -> add374::Value
		midi_cc100.getWrappedObject().getParameter().connectT(0, add375);     // midi_cc100 -> add375::Value
		midi_cc101.getWrappedObject().getParameter().connectT(0, add376);     // midi_cc101 -> add376::Value
		midi73.getParameter().connectT(0, add377);                            // midi73 -> add377::Value
		midi74.getParameter().connectT(0, add378);                            // midi74 -> add378::Value
		midi75.getParameter().connectT(0, add379);                            // midi75 -> add379::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain1);                // xfader -> gain1::Gain
		xfader_p.getParameterT(1).connectT(0, gain2);                // xfader -> gain2::Gain
		pma33.getWrappedObject().getParameter().connectT(0, xfader); // pma33 -> xfader::Value
		peak31.getParameter().connectT(0, pma33);                    // peak31 -> pma33::Value
		auto& sliderbank25_p = sliderbank25.getWrappedObject().getParameter();
		sliderbank25_p.getParameterT(0).connectT(0, gain204);                 // sliderbank25 -> gain204::Gain
		sliderbank25_p.getParameterT(1).connectT(0, gain205);                 // sliderbank25 -> gain205::Gain
		sliderbank25_p.getParameterT(2).connectT(0, gain206);                 // sliderbank25 -> gain206::Gain
		sliderbank25_p.getParameterT(3).connectT(0, gain207);                 // sliderbank25 -> gain207::Gain
		sliderbank25_p.getParameterT(4).connectT(0, gain208);                 // sliderbank25 -> gain208::Gain
		sliderbank25_p.getParameterT(5).connectT(0, gain209);                 // sliderbank25 -> gain209::Gain
		sliderbank25_p.getParameterT(6).connectT(0, gain210);                 // sliderbank25 -> gain210::Gain
		sliderbank25_p.getParameterT(7).connectT(0, gain211);                 // sliderbank25 -> gain211::Gain
		global_cable91.getWrappedObject().getParameter().connectT(0, add352); // global_cable91 -> add352::Value
		global_cable92.getWrappedObject().getParameter().connectT(0, add353); // global_cable92 -> add353::Value
		global_cable93.getWrappedObject().getParameter().connectT(0, add354); // global_cable93 -> add354::Value
		global_cable94.getWrappedObject().getParameter().connectT(0, add355); // global_cable94 -> add355::Value
		event_data_reader76.getParameter().connectT(0, add356);               // event_data_reader76 -> add356::Value
		event_data_reader77.getParameter().connectT(0, add357);               // event_data_reader77 -> add357::Value
		event_data_reader78.getParameter().connectT(0, add358);               // event_data_reader78 -> add358::Value
		midi_cc94.getWrappedObject().getParameter().connectT(0, add359);      // midi_cc94 -> add359::Value
		midi_cc95.getWrappedObject().getParameter().connectT(0, add360);      // midi_cc95 -> add360::Value
		midi_cc96.getWrappedObject().getParameter().connectT(0, add361);      // midi_cc96 -> add361::Value
		midi_cc97.getWrappedObject().getParameter().connectT(0, add362);      // midi_cc97 -> add362::Value
		midi70.getParameter().connectT(0, add363);                            // midi70 -> add363::Value
		midi71.getParameter().connectT(0, add364);                            // midi71 -> add364::Value
		midi72.getParameter().connectT(0, add365);                            // midi72 -> add365::Value
		cable_table3.getWrappedObject().getParameter().connectT(0, faust15);  // cable_table3 -> faust15::del
		cable_table.getWrappedObject().getParameter().connectT(0, faust8);    // cable_table -> faust8::del
		pma32.getWrappedObject().getParameter().connectT(0, faust);           // pma32 -> faust::freq
		pma32.getWrappedObject().getParameter().connectT(1, faust2);          // pma32 -> faust2::freq
		pma32.getWrappedObject().getParameter().connectT(2, faust10);         // pma32 -> faust10::freq
		pma32.getWrappedObject().getParameter().connectT(3, faust11);         // pma32 -> faust11::freq
		pma32.getWrappedObject().getParameter().connectT(4, faust13);         // pma32 -> faust13::freq
		pma32.getWrappedObject().getParameter().connectT(5, cable_table3);    // pma32 -> cable_table3::Value
		pma32.getWrappedObject().getParameter().connectT(6, cable_table);     // pma32 -> cable_table::Value
		peak30.getParameter().connectT(0, pma32);                             // peak30 -> pma32::Value
		pma37.getWrappedObject().getParameter().connectT(0, pma32);           // pma37 -> pma32::Add
		auto& sliderbank27_p = sliderbank27.getWrappedObject().getParameter();
		sliderbank27_p.getParameterT(0).connectT(0, gain220);                  // sliderbank27 -> gain220::Gain
		sliderbank27_p.getParameterT(1).connectT(0, gain221);                  // sliderbank27 -> gain221::Gain
		sliderbank27_p.getParameterT(2).connectT(0, gain222);                  // sliderbank27 -> gain222::Gain
		sliderbank27_p.getParameterT(3).connectT(0, gain223);                  // sliderbank27 -> gain223::Gain
		sliderbank27_p.getParameterT(4).connectT(0, gain224);                  // sliderbank27 -> gain224::Gain
		sliderbank27_p.getParameterT(5).connectT(0, gain225);                  // sliderbank27 -> gain225::Gain
		sliderbank27_p.getParameterT(6).connectT(0, gain226);                  // sliderbank27 -> gain226::Gain
		sliderbank27_p.getParameterT(7).connectT(0, gain227);                  // sliderbank27 -> gain227::Gain
		global_cable99.getWrappedObject().getParameter().connectT(0, add380);  // global_cable99 -> add380::Value
		global_cable100.getWrappedObject().getParameter().connectT(0, add381); // global_cable100 -> add381::Value
		global_cable101.getWrappedObject().getParameter().connectT(0, add382); // global_cable101 -> add382::Value
		global_cable102.getWrappedObject().getParameter().connectT(0, add383); // global_cable102 -> add383::Value
		event_data_reader82.getParameter().connectT(0, add384);                // event_data_reader82 -> add384::Value
		event_data_reader83.getParameter().connectT(0, add385);                // event_data_reader83 -> add385::Value
		event_data_reader84.getParameter().connectT(0, add386);                // event_data_reader84 -> add386::Value
		midi_cc102.getWrappedObject().getParameter().connectT(0, add387);      // midi_cc102 -> add387::Value
		midi_cc103.getWrappedObject().getParameter().connectT(0, add388);      // midi_cc103 -> add388::Value
		midi_cc104.getWrappedObject().getParameter().connectT(0, add389);      // midi_cc104 -> add389::Value
		midi_cc105.getWrappedObject().getParameter().connectT(0, add390);      // midi_cc105 -> add390::Value
		midi76.getParameter().connectT(0, add391);                             // midi76 -> add391::Value
		midi77.getParameter().connectT(0, add392);                             // midi77 -> add392::Value
		midi78.getParameter().connectT(0, add393);                             // midi78 -> add393::Value
		cable_table4.getWrappedObject().getParameter().connectT(0, faust16);   // cable_table4 -> faust16::del
		cable_table2.getWrappedObject().getParameter().connectT(0, faust9);    // cable_table2 -> faust9::del
		pma34.getWrappedObject().getParameter().connectT(0, faust1);           // pma34 -> faust1::freq
		pma34.getWrappedObject().getParameter().connectT(1, faust6);           // pma34 -> faust6::freq
		pma34.getWrappedObject().getParameter().connectT(2, faust7);           // pma34 -> faust7::freq
		pma34.getWrappedObject().getParameter().connectT(3, faust12);          // pma34 -> faust12::freq
		pma34.getWrappedObject().getParameter().connectT(4, faust14);          // pma34 -> faust14::freq
		pma34.getWrappedObject().getParameter().connectT(5, cable_table4);     // pma34 -> cable_table4::Value
		pma34.getWrappedObject().getParameter().connectT(6, cable_table2);     // pma34 -> cable_table2::Value
		peak32.getParameter().connectT(0, pma34);                              // peak32 -> pma34::Value
		pma38.getWrappedObject().getParameter().connectT(0, pma34);            // pma38 -> pma34::Add
		auto& sliderbank28_p = sliderbank28.getWrappedObject().getParameter();
		sliderbank28_p.getParameterT(0).connectT(0, gain228);                  // sliderbank28 -> gain228::Gain
		sliderbank28_p.getParameterT(1).connectT(0, gain229);                  // sliderbank28 -> gain229::Gain
		sliderbank28_p.getParameterT(2).connectT(0, gain230);                  // sliderbank28 -> gain230::Gain
		sliderbank28_p.getParameterT(3).connectT(0, gain231);                  // sliderbank28 -> gain231::Gain
		sliderbank28_p.getParameterT(4).connectT(0, gain232);                  // sliderbank28 -> gain232::Gain
		sliderbank28_p.getParameterT(5).connectT(0, gain233);                  // sliderbank28 -> gain233::Gain
		sliderbank28_p.getParameterT(6).connectT(0, gain234);                  // sliderbank28 -> gain234::Gain
		sliderbank28_p.getParameterT(7).connectT(0, gain235);                  // sliderbank28 -> gain235::Gain
		global_cable103.getWrappedObject().getParameter().connectT(0, add394); // global_cable103 -> add394::Value
		global_cable104.getWrappedObject().getParameter().connectT(0, add395); // global_cable104 -> add395::Value
		global_cable105.getWrappedObject().getParameter().connectT(0, add396); // global_cable105 -> add396::Value
		global_cable106.getWrappedObject().getParameter().connectT(0, add397); // global_cable106 -> add397::Value
		event_data_reader85.getParameter().connectT(0, add398);                // event_data_reader85 -> add398::Value
		event_data_reader86.getParameter().connectT(0, add399);                // event_data_reader86 -> add399::Value
		event_data_reader87.getParameter().connectT(0, add400);                // event_data_reader87 -> add400::Value
		midi_cc106.getWrappedObject().getParameter().connectT(0, add401);      // midi_cc106 -> add401::Value
		midi_cc107.getWrappedObject().getParameter().connectT(0, add402);      // midi_cc107 -> add402::Value
		midi_cc108.getWrappedObject().getParameter().connectT(0, add403);      // midi_cc108 -> add403::Value
		midi_cc109.getWrappedObject().getParameter().connectT(0, add404);      // midi_cc109 -> add404::Value
		midi79.getParameter().connectT(0, add405);                             // midi79 -> add405::Value
		midi80.getParameter().connectT(0, add406);                             // midi80 -> add406::Value
		midi81.getParameter().connectT(0, add407);                             // midi81 -> add407::Value
		pma.getWrappedObject().getParameter().connectT(0, gain5);              // pma -> gain5::Gain
		pma39.getWrappedObject().getParameter().connectT(0, pma);              // pma39 -> pma::Add
		auto& sliderbank29_p = sliderbank29.getWrappedObject().getParameter();
		sliderbank29_p.getParameterT(0).connectT(0, gain251);                  // sliderbank29 -> gain251::Gain
		sliderbank29_p.getParameterT(1).connectT(0, gain252);                  // sliderbank29 -> gain252::Gain
		sliderbank29_p.getParameterT(2).connectT(0, gain253);                  // sliderbank29 -> gain253::Gain
		sliderbank29_p.getParameterT(3).connectT(0, gain254);                  // sliderbank29 -> gain254::Gain
		sliderbank29_p.getParameterT(4).connectT(0, gain255);                  // sliderbank29 -> gain255::Gain
		sliderbank29_p.getParameterT(5).connectT(0, gain256);                  // sliderbank29 -> gain256::Gain
		sliderbank29_p.getParameterT(6).connectT(0, gain257);                  // sliderbank29 -> gain257::Gain
		sliderbank29_p.getParameterT(7).connectT(0, gain258);                  // sliderbank29 -> gain258::Gain
		global_cable107.getWrappedObject().getParameter().connectT(0, add408); // global_cable107 -> add408::Value
		global_cable108.getWrappedObject().getParameter().connectT(0, add409); // global_cable108 -> add409::Value
		global_cable109.getWrappedObject().getParameter().connectT(0, add410); // global_cable109 -> add410::Value
		global_cable110.getWrappedObject().getParameter().connectT(0, add411); // global_cable110 -> add411::Value
		event_data_reader88.getParameter().connectT(0, add412);                // event_data_reader88 -> add412::Value
		event_data_reader89.getParameter().connectT(0, add413);                // event_data_reader89 -> add413::Value
		event_data_reader90.getParameter().connectT(0, add414);                // event_data_reader90 -> add414::Value
		midi_cc110.getWrappedObject().getParameter().connectT(0, add415);      // midi_cc110 -> add415::Value
		midi_cc111.getWrappedObject().getParameter().connectT(0, add416);      // midi_cc111 -> add416::Value
		midi_cc112.getWrappedObject().getParameter().connectT(0, add417);      // midi_cc112 -> add417::Value
		midi_cc113.getWrappedObject().getParameter().connectT(0, add418);      // midi_cc113 -> add418::Value
		midi82.getParameter().connectT(0, add419);                             // midi82 -> add419::Value
		midi83.getParameter().connectT(0, add420);                             // midi83 -> add420::Value
		midi84.getParameter().connectT(0, add421);                             // midi84 -> add421::Value
		pma36.getWrappedObject().getParameter().connectT(0, jpanner3);         // pma36 -> jpanner3::Pan
		peak34.getParameter().connectT(0, pma36);                              // peak34 -> pma36::Value
		clone_pack1.getWrappedObject().getParameter().connectT(0, pi11);       // clone_pack1 -> pi11::Value
		pma23.getWrappedObject().getParameter().connectT(0, pma21);            // pma23 -> pma21::Add
		pma23.getWrappedObject().getParameter().connectT(1, cable_table18);    // pma23 -> cable_table18::Value
		peak5.getParameter().connectT(0, pma23);                               // peak5 -> pma23::Value
		peak5.getParameter().connectT(1, pma37);                               // peak5 -> pma37::Value
		peak5.getParameter().connectT(2, pma38);                               // peak5 -> pma38::Value
		peak5.getParameter().connectT(3, pma39);                               // peak5 -> pma39::Value
		auto& sliderbank16_p = sliderbank16.getWrappedObject().getParameter();
		sliderbank16_p.getParameterT(0).connectT(0, gain132);                 // sliderbank16 -> gain132::Gain
		sliderbank16_p.getParameterT(1).connectT(0, gain133);                 // sliderbank16 -> gain133::Gain
		sliderbank16_p.getParameterT(2).connectT(0, gain134);                 // sliderbank16 -> gain134::Gain
		sliderbank16_p.getParameterT(3).connectT(0, gain135);                 // sliderbank16 -> gain135::Gain
		sliderbank16_p.getParameterT(4).connectT(0, gain136);                 // sliderbank16 -> gain136::Gain
		sliderbank16_p.getParameterT(5).connectT(0, gain137);                 // sliderbank16 -> gain137::Gain
		sliderbank16_p.getParameterT(6).connectT(0, gain138);                 // sliderbank16 -> gain138::Gain
		sliderbank16_p.getParameterT(7).connectT(0, gain139);                 // sliderbank16 -> gain139::Gain
		global_cable55.getWrappedObject().getParameter().connectT(0, add226); // global_cable55 -> add226::Value
		global_cable56.getWrappedObject().getParameter().connectT(0, add227); // global_cable56 -> add227::Value
		global_cable57.getWrappedObject().getParameter().connectT(0, add228); // global_cable57 -> add228::Value
		global_cable58.getWrappedObject().getParameter().connectT(0, add229); // global_cable58 -> add229::Value
		event_data_reader49.getParameter().connectT(0, add230);               // event_data_reader49 -> add230::Value
		event_data_reader50.getParameter().connectT(0, add231);               // event_data_reader50 -> add231::Value
		event_data_reader51.getParameter().connectT(0, add232);               // event_data_reader51 -> add232::Value
		midi_cc58.getWrappedObject().getParameter().connectT(0, add233);      // midi_cc58 -> add233::Value
		midi_cc59.getWrappedObject().getParameter().connectT(0, add234);      // midi_cc59 -> add234::Value
		midi_cc60.getWrappedObject().getParameter().connectT(0, add235);      // midi_cc60 -> add235::Value
		midi_cc61.getWrappedObject().getParameter().connectT(0, add236);      // midi_cc61 -> add236::Value
		midi43.getParameter().connectT(0, add237);                            // midi43 -> add237::Value
		midi44.getParameter().connectT(0, add238);                            // midi44 -> add238::Value
		midi45.getParameter().connectT(0, add239);                            // midi45 -> add239::Value
		pma22.getWrappedObject().getParameter().connectT(0, pma23);           // pma22 -> pma23::Add
		peak21.getParameter().connectT(0, pma22);                             // peak21 -> pma22::Value
		peak18.getParameter().connectT(0, add222);                            // peak18 -> add222::Value
		cable_table15.getWrappedObject().getParameter().connectT(0, faust4);  // cable_table15 -> faust4::shiftfreq
		midi42.getParameter().connectT(0, cable_table15);                     // midi42 -> cable_table15::Value
		peak7.getParameter().connectT(0, pma);                                // peak7 -> pma::Value
		
		// Send Connections ------------------------------------------------------------------------
		
		send2.connect(receive2);
		send3.connect(receive3);
		
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
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
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
		
		;                              // smoother::SmoothingTime is automated
		smoother.setParameterT(1, 0.); // core::smoother::DefaultValue
		
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
		
		global_cable25.setParameterT(0, 1.); // routing::global_cable::Value
		
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
		
		global_cable26.setParameterT(0, 1.); // routing::global_cable::Value
		
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
		
		sliderbank9.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable9.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add16::Value is automated
		
		;                             // gain81::Gain is automated
		gain81.setParameterT(1, 20.); // core::gain::Smoothing
		gain81.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable22.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add87::Value is automated
		
		;                             // gain82::Gain is automated
		gain82.setParameterT(1, 20.); // core::gain::Smoothing
		gain82.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable23.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add17::Value is automated
		
		;                             // gain83::Gain is automated
		gain83.setParameterT(1, 20.); // core::gain::Smoothing
		gain83.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable29.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add88::Value is automated
		
		;                             // gain84::Gain is automated
		gain84.setParameterT(1, 20.); // core::gain::Smoothing
		gain84.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader25.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader25.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add89::Value is automated
		
		;                             // gain85::Gain is automated
		gain85.setParameterT(1, 20.); // core::gain::Smoothing
		gain85.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader26.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader26.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add90::Value is automated
		
		;                             // gain86::Gain is automated
		gain86.setParameterT(1, 20.); // core::gain::Smoothing
		gain86.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader27::SlotIndex is automated
		event_data_reader27.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add91::Value is automated
		
		;                             // gain87::Gain is automated
		gain87.setParameterT(1, 20.); // core::gain::Smoothing
		gain87.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch9::Index is automated
		
		midi_cc26.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc26.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc26.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add92::Value is automated
		
		midi_cc27.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc27.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc27.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add93::Value is automated
		
		midi_cc28.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc28.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc28.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add94::Value is automated
		
		midi_cc29.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc29.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc29.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add95::Value is automated
		
		; // add96::Value is automated
		
		; // add97::Value is automated
		
		; // add98::Value is automated
		
		;                             // gain88::Gain is automated
		gain88.setParameterT(1, 20.); // core::gain::Smoothing
		gain88.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma12::Value is automated
		; // pma12::Multiply is automated
		; // pma12::Add is automated
		
		sliderbank8.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add14::Value is automated
		
		;                             // gain73::Gain is automated
		gain73.setParameterT(1, 20.); // core::gain::Smoothing
		gain73.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable20.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add75::Value is automated
		
		;                             // gain74::Gain is automated
		gain74.setParameterT(1, 20.); // core::gain::Smoothing
		gain74.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable21.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add15::Value is automated
		
		;                             // gain75::Gain is automated
		gain75.setParameterT(1, 20.); // core::gain::Smoothing
		gain75.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable28.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add76::Value is automated
		
		;                             // gain76::Gain is automated
		gain76.setParameterT(1, 20.); // core::gain::Smoothing
		gain76.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader22.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader22.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add77::Value is automated
		
		;                             // gain77::Gain is automated
		gain77.setParameterT(1, 20.); // core::gain::Smoothing
		gain77.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader23.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader23.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add78::Value is automated
		
		;                             // gain78::Gain is automated
		gain78.setParameterT(1, 20.); // core::gain::Smoothing
		gain78.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader24::SlotIndex is automated
		event_data_reader24.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add79::Value is automated
		
		;                             // gain79::Gain is automated
		gain79.setParameterT(1, 20.); // core::gain::Smoothing
		gain79.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch8::Index is automated
		
		midi_cc22.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc22.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc22.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add80::Value is automated
		
		midi_cc23.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc23.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc23.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add81::Value is automated
		
		midi_cc24.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc24.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc24.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add82::Value is automated
		
		midi_cc25.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc25.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc25.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add83::Value is automated
		
		; // add84::Value is automated
		
		; // add85::Value is automated
		
		; // add86::Value is automated
		
		;                             // gain80::Gain is automated
		gain80.setParameterT(1, 20.); // core::gain::Smoothing
		gain80.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma10::Value is automated
		; // pma10::Multiply is automated
		; // pma10::Add is automated
		
		sliderbank18.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable63.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add254::Value is automated
		
		;                              // gain148::Gain is automated
		gain148.setParameterT(1, 20.); // core::gain::Smoothing
		gain148.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable64.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add255::Value is automated
		
		;                              // gain149::Gain is automated
		gain149.setParameterT(1, 20.); // core::gain::Smoothing
		gain149.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable65.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add256::Value is automated
		
		;                              // gain150::Gain is automated
		gain150.setParameterT(1, 20.); // core::gain::Smoothing
		gain150.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable66.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add257::Value is automated
		
		;                              // gain151::Gain is automated
		gain151.setParameterT(1, 20.); // core::gain::Smoothing
		gain151.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader55.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader55.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add258::Value is automated
		
		;                              // gain152::Gain is automated
		gain152.setParameterT(1, 20.); // core::gain::Smoothing
		gain152.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader56.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader56.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add259::Value is automated
		
		;                              // gain153::Gain is automated
		gain153.setParameterT(1, 20.); // core::gain::Smoothing
		gain153.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader57::SlotIndex is automated
		event_data_reader57.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add260::Value is automated
		
		;                              // gain154::Gain is automated
		gain154.setParameterT(1, 20.); // core::gain::Smoothing
		gain154.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch28::Index is automated
		
		midi_cc66.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc66.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc66.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add261::Value is automated
		
		midi_cc67.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc67.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc67.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add262::Value is automated
		
		midi_cc68.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc68.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc68.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add263::Value is automated
		
		midi_cc69.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc69.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc69.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add264::Value is automated
		
		; // add265::Value is automated
		
		; // add266::Value is automated
		
		; // add267::Value is automated
		
		;                              // gain155::Gain is automated
		gain155.setParameterT(1, 20.); // core::gain::Smoothing
		gain155.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma24::Value is automated
		; // pma24::Multiply is automated
		; // pma24::Add is automated
		
		sliderbank19.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable67.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add268::Value is automated
		
		;                              // gain156::Gain is automated
		gain156.setParameterT(1, 20.); // core::gain::Smoothing
		gain156.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable68.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add269::Value is automated
		
		;                              // gain157::Gain is automated
		gain157.setParameterT(1, 20.); // core::gain::Smoothing
		gain157.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable69.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add270::Value is automated
		
		;                              // gain158::Gain is automated
		gain158.setParameterT(1, 20.); // core::gain::Smoothing
		gain158.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable70.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add271::Value is automated
		
		;                              // gain159::Gain is automated
		gain159.setParameterT(1, 20.); // core::gain::Smoothing
		gain159.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader58.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader58.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add272::Value is automated
		
		;                              // gain160::Gain is automated
		gain160.setParameterT(1, 20.); // core::gain::Smoothing
		gain160.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader59.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader59.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add273::Value is automated
		
		;                              // gain161::Gain is automated
		gain161.setParameterT(1, 20.); // core::gain::Smoothing
		gain161.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader60::SlotIndex is automated
		event_data_reader60.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add274::Value is automated
		
		;                              // gain162::Gain is automated
		gain162.setParameterT(1, 20.); // core::gain::Smoothing
		gain162.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch29::Index is automated
		
		midi_cc70.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc70.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc70.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add275::Value is automated
		
		midi_cc71.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc71.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc71.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add276::Value is automated
		
		midi_cc72.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc72.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc72.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add277::Value is automated
		
		midi_cc73.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc73.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc73.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add278::Value is automated
		
		; // add279::Value is automated
		
		; // add280::Value is automated
		
		; // add281::Value is automated
		
		;                              // gain163::Gain is automated
		gain163.setParameterT(1, 20.); // core::gain::Smoothing
		gain163.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma26::Value is automated
		; // pma26::Multiply is automated
		; // pma26::Add is automated
		
		sliderbank20.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable71.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add282::Value is automated
		
		;                              // gain164::Gain is automated
		gain164.setParameterT(1, 20.); // core::gain::Smoothing
		gain164.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable72.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add283::Value is automated
		
		;                              // gain165::Gain is automated
		gain165.setParameterT(1, 20.); // core::gain::Smoothing
		gain165.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable73.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add284::Value is automated
		
		;                              // gain166::Gain is automated
		gain166.setParameterT(1, 20.); // core::gain::Smoothing
		gain166.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable74.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add285::Value is automated
		
		;                              // gain167::Gain is automated
		gain167.setParameterT(1, 20.); // core::gain::Smoothing
		gain167.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader61.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader61.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add286::Value is automated
		
		;                              // gain168::Gain is automated
		gain168.setParameterT(1, 20.); // core::gain::Smoothing
		gain168.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader62.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader62.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add287::Value is automated
		
		;                              // gain169::Gain is automated
		gain169.setParameterT(1, 20.); // core::gain::Smoothing
		gain169.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader63::SlotIndex is automated
		event_data_reader63.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add288::Value is automated
		
		;                              // gain170::Gain is automated
		gain170.setParameterT(1, 20.); // core::gain::Smoothing
		gain170.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch30::Index is automated
		
		midi_cc74.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc74.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc74.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add289::Value is automated
		
		midi_cc75.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc75.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc75.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add290::Value is automated
		
		midi_cc76.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc76.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc76.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add291::Value is automated
		
		midi_cc77.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc77.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc77.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add292::Value is automated
		
		; // add293::Value is automated
		
		; // add294::Value is automated
		
		; // add295::Value is automated
		
		;                              // gain171::Gain is automated
		gain171.setParameterT(1, 20.); // core::gain::Smoothing
		gain171.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma40::Value is automated
		; // pma40::Multiply is automated
		; // pma40::Add is automated
		
		sliderbank21.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable75.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add296::Value is automated
		
		;                              // gain172::Gain is automated
		gain172.setParameterT(1, 20.); // core::gain::Smoothing
		gain172.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable76.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add297::Value is automated
		
		;                              // gain173::Gain is automated
		gain173.setParameterT(1, 20.); // core::gain::Smoothing
		gain173.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable77.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add298::Value is automated
		
		;                              // gain174::Gain is automated
		gain174.setParameterT(1, 20.); // core::gain::Smoothing
		gain174.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable78.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add299::Value is automated
		
		;                              // gain175::Gain is automated
		gain175.setParameterT(1, 20.); // core::gain::Smoothing
		gain175.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader64.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader64.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add300::Value is automated
		
		;                              // gain176::Gain is automated
		gain176.setParameterT(1, 20.); // core::gain::Smoothing
		gain176.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader65.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader65.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add301::Value is automated
		
		;                              // gain177::Gain is automated
		gain177.setParameterT(1, 20.); // core::gain::Smoothing
		gain177.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader66::SlotIndex is automated
		event_data_reader66.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add302::Value is automated
		
		;                              // gain178::Gain is automated
		gain178.setParameterT(1, 20.); // core::gain::Smoothing
		gain178.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch31::Index is automated
		
		midi_cc78.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc78.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc78.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add303::Value is automated
		
		midi_cc79.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc79.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc79.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add304::Value is automated
		
		midi_cc80.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc80.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc80.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add305::Value is automated
		
		midi_cc81.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc81.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc81.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add306::Value is automated
		
		; // add307::Value is automated
		
		; // add308::Value is automated
		
		; // add309::Value is automated
		
		;                              // gain179::Gain is automated
		gain179.setParameterT(1, 20.); // core::gain::Smoothing
		gain179.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma27::Value is automated
		; // pma27::Multiply is automated
		; // pma27::Add is automated
		
		sliderbank22.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable79.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add310::Value is automated
		
		;                              // gain180::Gain is automated
		gain180.setParameterT(1, 20.); // core::gain::Smoothing
		gain180.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable80.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add311::Value is automated
		
		;                              // gain181::Gain is automated
		gain181.setParameterT(1, 20.); // core::gain::Smoothing
		gain181.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable81.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add312::Value is automated
		
		;                              // gain182::Gain is automated
		gain182.setParameterT(1, 20.); // core::gain::Smoothing
		gain182.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable82.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add313::Value is automated
		
		;                              // gain183::Gain is automated
		gain183.setParameterT(1, 20.); // core::gain::Smoothing
		gain183.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader67.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader67.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add314::Value is automated
		
		;                              // gain184::Gain is automated
		gain184.setParameterT(1, 20.); // core::gain::Smoothing
		gain184.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader68.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader68.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add315::Value is automated
		
		;                              // gain185::Gain is automated
		gain185.setParameterT(1, 20.); // core::gain::Smoothing
		gain185.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader69::SlotIndex is automated
		event_data_reader69.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add316::Value is automated
		
		;                              // gain186::Gain is automated
		gain186.setParameterT(1, 20.); // core::gain::Smoothing
		gain186.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch32::Index is automated
		
		midi_cc82.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc82.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc82.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add317::Value is automated
		
		midi_cc83.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc83.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc83.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add318::Value is automated
		
		midi_cc84.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc84.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc84.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add319::Value is automated
		
		midi_cc85.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc85.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc85.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add320::Value is automated
		
		; // add321::Value is automated
		
		; // add322::Value is automated
		
		; // add323::Value is automated
		
		;                              // gain187::Gain is automated
		gain187.setParameterT(1, 20.); // core::gain::Smoothing
		gain187.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma28::Value is automated
		; // pma28::Multiply is automated
		; // pma28::Add is automated
		
		sliderbank23.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable83.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add324::Value is automated
		
		;                              // gain188::Gain is automated
		gain188.setParameterT(1, 20.); // core::gain::Smoothing
		gain188.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable84.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add325::Value is automated
		
		;                              // gain189::Gain is automated
		gain189.setParameterT(1, 20.); // core::gain::Smoothing
		gain189.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable85.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add326::Value is automated
		
		;                              // gain190::Gain is automated
		gain190.setParameterT(1, 20.); // core::gain::Smoothing
		gain190.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable86.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add327::Value is automated
		
		;                              // gain191::Gain is automated
		gain191.setParameterT(1, 20.); // core::gain::Smoothing
		gain191.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader70.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader70.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add328::Value is automated
		
		;                              // gain192::Gain is automated
		gain192.setParameterT(1, 20.); // core::gain::Smoothing
		gain192.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader71.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader71.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add329::Value is automated
		
		;                              // gain193::Gain is automated
		gain193.setParameterT(1, 20.); // core::gain::Smoothing
		gain193.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader72::SlotIndex is automated
		event_data_reader72.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add330::Value is automated
		
		;                              // gain194::Gain is automated
		gain194.setParameterT(1, 20.); // core::gain::Smoothing
		gain194.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch33::Index is automated
		
		midi_cc86.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc86.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc86.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add331::Value is automated
		
		midi_cc87.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc87.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc87.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add332::Value is automated
		
		midi_cc88.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc88.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc88.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add333::Value is automated
		
		midi_cc89.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc89.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc89.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add334::Value is automated
		
		; // add335::Value is automated
		
		; // add336::Value is automated
		
		; // add337::Value is automated
		
		;                              // gain195::Gain is automated
		gain195.setParameterT(1, 20.); // core::gain::Smoothing
		gain195.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma29::Value is automated
		; // pma29::Multiply is automated
		; // pma29::Add is automated
		
		sliderbank24.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable87.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add338::Value is automated
		
		;                              // gain196::Gain is automated
		gain196.setParameterT(1, 20.); // core::gain::Smoothing
		gain196.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable88.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add339::Value is automated
		
		;                              // gain197::Gain is automated
		gain197.setParameterT(1, 20.); // core::gain::Smoothing
		gain197.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable89.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add340::Value is automated
		
		;                              // gain198::Gain is automated
		gain198.setParameterT(1, 20.); // core::gain::Smoothing
		gain198.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable90.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add341::Value is automated
		
		;                              // gain199::Gain is automated
		gain199.setParameterT(1, 20.); // core::gain::Smoothing
		gain199.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader73.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader73.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add342::Value is automated
		
		;                              // gain200::Gain is automated
		gain200.setParameterT(1, 20.); // core::gain::Smoothing
		gain200.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader74.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader74.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add343::Value is automated
		
		;                              // gain201::Gain is automated
		gain201.setParameterT(1, 20.); // core::gain::Smoothing
		gain201.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader75::SlotIndex is automated
		event_data_reader75.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add344::Value is automated
		
		;                              // gain202::Gain is automated
		gain202.setParameterT(1, 20.); // core::gain::Smoothing
		gain202.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch34::Index is automated
		
		midi_cc90.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc90.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc90.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add345::Value is automated
		
		midi_cc91.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc91.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc91.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add346::Value is automated
		
		midi_cc92.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc92.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc92.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add347::Value is automated
		
		midi_cc93.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc93.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc93.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add348::Value is automated
		
		; // add349::Value is automated
		
		; // add350::Value is automated
		
		; // add351::Value is automated
		
		;                              // gain203::Gain is automated
		gain203.setParameterT(1, 20.); // core::gain::Smoothing
		gain203.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma30::Value is automated
		; // pma30::Multiply is automated
		; // pma30::Add is automated
		
		sliderbank26.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable95.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add366::Value is automated
		
		;                              // gain212::Gain is automated
		gain212.setParameterT(1, 20.); // core::gain::Smoothing
		gain212.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable96.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add367::Value is automated
		
		;                              // gain213::Gain is automated
		gain213.setParameterT(1, 20.); // core::gain::Smoothing
		gain213.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable97.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add368::Value is automated
		
		;                              // gain214::Gain is automated
		gain214.setParameterT(1, 20.); // core::gain::Smoothing
		gain214.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable98.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add369::Value is automated
		
		;                              // gain215::Gain is automated
		gain215.setParameterT(1, 20.); // core::gain::Smoothing
		gain215.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader79.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader79.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add370::Value is automated
		
		;                              // gain216::Gain is automated
		gain216.setParameterT(1, 20.); // core::gain::Smoothing
		gain216.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader80.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader80.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add371::Value is automated
		
		;                              // gain217::Gain is automated
		gain217.setParameterT(1, 20.); // core::gain::Smoothing
		gain217.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader81::SlotIndex is automated
		event_data_reader81.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add372::Value is automated
		
		;                              // gain218::Gain is automated
		gain218.setParameterT(1, 20.); // core::gain::Smoothing
		gain218.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch36::Index is automated
		
		midi_cc98.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc98.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc98.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add373::Value is automated
		
		midi_cc99.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc99.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc99.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add374::Value is automated
		
		midi_cc100.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc100.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc100.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add375::Value is automated
		
		midi_cc101.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc101.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc101.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add376::Value is automated
		
		; // add377::Value is automated
		
		; // add378::Value is automated
		
		; // add379::Value is automated
		
		;                              // gain219::Gain is automated
		gain219.setParameterT(1, 20.); // core::gain::Smoothing
		gain219.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma33::Value is automated
		; // pma33::Multiply is automated
		; // pma33::Add is automated
		
		sliderbank25.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable91.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add352::Value is automated
		
		;                              // gain204::Gain is automated
		gain204.setParameterT(1, 20.); // core::gain::Smoothing
		gain204.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable92.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add353::Value is automated
		
		;                              // gain205::Gain is automated
		gain205.setParameterT(1, 20.); // core::gain::Smoothing
		gain205.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable93.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add354::Value is automated
		
		;                              // gain206::Gain is automated
		gain206.setParameterT(1, 20.); // core::gain::Smoothing
		gain206.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable94.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add355::Value is automated
		
		;                              // gain207::Gain is automated
		gain207.setParameterT(1, 20.); // core::gain::Smoothing
		gain207.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader76.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader76.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add356::Value is automated
		
		;                              // gain208::Gain is automated
		gain208.setParameterT(1, 20.); // core::gain::Smoothing
		gain208.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader77.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader77.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add357::Value is automated
		
		;                              // gain209::Gain is automated
		gain209.setParameterT(1, 20.); // core::gain::Smoothing
		gain209.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader78::SlotIndex is automated
		event_data_reader78.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add358::Value is automated
		
		;                              // gain210::Gain is automated
		gain210.setParameterT(1, 20.); // core::gain::Smoothing
		gain210.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch35::Index is automated
		
		midi_cc94.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc94.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc94.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add359::Value is automated
		
		midi_cc95.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc95.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc95.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add360::Value is automated
		
		midi_cc96.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc96.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc96.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add361::Value is automated
		
		midi_cc97.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc97.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc97.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add362::Value is automated
		
		; // add363::Value is automated
		
		; // add364::Value is automated
		
		; // add365::Value is automated
		
		;                              // gain211::Gain is automated
		gain211.setParameterT(1, 20.); // core::gain::Smoothing
		gain211.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma37::Value is automated
		; // pma37::Multiply is automated
		; // pma37::Add is automated
		
		; // pma32::Value is automated
		; // pma32::Multiply is automated
		; // pma32::Add is automated
		
		sliderbank27.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable99.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add380::Value is automated
		
		;                              // gain220::Gain is automated
		gain220.setParameterT(1, 20.); // core::gain::Smoothing
		gain220.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable100.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add381::Value is automated
		
		;                              // gain221::Gain is automated
		gain221.setParameterT(1, 20.); // core::gain::Smoothing
		gain221.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable101.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add382::Value is automated
		
		;                              // gain222::Gain is automated
		gain222.setParameterT(1, 20.); // core::gain::Smoothing
		gain222.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable102.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add383::Value is automated
		
		;                              // gain223::Gain is automated
		gain223.setParameterT(1, 20.); // core::gain::Smoothing
		gain223.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader82.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader82.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add384::Value is automated
		
		;                              // gain224::Gain is automated
		gain224.setParameterT(1, 20.); // core::gain::Smoothing
		gain224.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader83.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader83.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add385::Value is automated
		
		;                              // gain225::Gain is automated
		gain225.setParameterT(1, 20.); // core::gain::Smoothing
		gain225.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader84::SlotIndex is automated
		event_data_reader84.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add386::Value is automated
		
		;                              // gain226::Gain is automated
		gain226.setParameterT(1, 20.); // core::gain::Smoothing
		gain226.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch37::Index is automated
		
		midi_cc102.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc102.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc102.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add387::Value is automated
		
		midi_cc103.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc103.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc103.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add388::Value is automated
		
		midi_cc104.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc104.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc104.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add389::Value is automated
		
		midi_cc105.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc105.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc105.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add390::Value is automated
		
		; // add391::Value is automated
		
		; // add392::Value is automated
		
		; // add393::Value is automated
		
		;                              // gain227::Gain is automated
		gain227.setParameterT(1, 20.); // core::gain::Smoothing
		gain227.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma38::Value is automated
		; // pma38::Multiply is automated
		; // pma38::Add is automated
		
		; // pma34::Value is automated
		; // pma34::Multiply is automated
		; // pma34::Add is automated
		
		sliderbank28.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable103.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add394::Value is automated
		
		;                              // gain228::Gain is automated
		gain228.setParameterT(1, 20.); // core::gain::Smoothing
		gain228.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable104.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add395::Value is automated
		
		;                              // gain229::Gain is automated
		gain229.setParameterT(1, 20.); // core::gain::Smoothing
		gain229.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable105.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add396::Value is automated
		
		;                              // gain230::Gain is automated
		gain230.setParameterT(1, 20.); // core::gain::Smoothing
		gain230.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable106.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add397::Value is automated
		
		;                              // gain231::Gain is automated
		gain231.setParameterT(1, 20.); // core::gain::Smoothing
		gain231.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader85.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader85.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add398::Value is automated
		
		;                              // gain232::Gain is automated
		gain232.setParameterT(1, 20.); // core::gain::Smoothing
		gain232.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader86.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader86.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add399::Value is automated
		
		;                              // gain233::Gain is automated
		gain233.setParameterT(1, 20.); // core::gain::Smoothing
		gain233.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader87::SlotIndex is automated
		event_data_reader87.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add400::Value is automated
		
		;                              // gain234::Gain is automated
		gain234.setParameterT(1, 20.); // core::gain::Smoothing
		gain234.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch38::Index is automated
		
		midi_cc106.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc106.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc106.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add401::Value is automated
		
		midi_cc107.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc107.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc107.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add402::Value is automated
		
		midi_cc108.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc108.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc108.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add403::Value is automated
		
		midi_cc109.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc109.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc109.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add404::Value is automated
		
		; // add405::Value is automated
		
		; // add406::Value is automated
		
		; // add407::Value is automated
		
		;                              // gain235::Gain is automated
		gain235.setParameterT(1, 20.); // core::gain::Smoothing
		gain235.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma39::Value is automated
		; // pma39::Multiply is automated
		; // pma39::Add is automated
		
		sliderbank29.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable107.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add408::Value is automated
		
		;                              // gain251::Gain is automated
		gain251.setParameterT(1, 20.); // core::gain::Smoothing
		gain251.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable108.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add409::Value is automated
		
		;                              // gain252::Gain is automated
		gain252.setParameterT(1, 20.); // core::gain::Smoothing
		gain252.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable109.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add410::Value is automated
		
		;                              // gain253::Gain is automated
		gain253.setParameterT(1, 20.); // core::gain::Smoothing
		gain253.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable110.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add411::Value is automated
		
		;                              // gain254::Gain is automated
		gain254.setParameterT(1, 20.); // core::gain::Smoothing
		gain254.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader88.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader88.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add412::Value is automated
		
		;                              // gain255::Gain is automated
		gain255.setParameterT(1, 20.); // core::gain::Smoothing
		gain255.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader89.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader89.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add413::Value is automated
		
		;                              // gain256::Gain is automated
		gain256.setParameterT(1, 20.); // core::gain::Smoothing
		gain256.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader90::SlotIndex is automated
		event_data_reader90.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add414::Value is automated
		
		;                              // gain257::Gain is automated
		gain257.setParameterT(1, 20.); // core::gain::Smoothing
		gain257.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch39::Index is automated
		
		midi_cc110.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc110.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc110.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add415::Value is automated
		
		midi_cc111.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc111.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc111.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add416::Value is automated
		
		midi_cc112.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc112.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc112.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add417::Value is automated
		
		midi_cc113.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc113.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc113.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add418::Value is automated
		
		; // add419::Value is automated
		
		; // add420::Value is automated
		
		; // add421::Value is automated
		
		;                              // gain258::Gain is automated
		gain258.setParameterT(1, 20.); // core::gain::Smoothing
		gain258.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma36::Value is automated
		; // pma36::Multiply is automated
		; // pma36::Add is automated
		
		;                             // gain::Gain is automated
		gain.setParameterT(1, 0.);    // core::gain::Smoothing
		gain.setParameterT(2, -100.); // core::gain::ResetValue
		
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
		
		; // branch1::Index is automated
		
		phasor_fm.setParameterT(0, 1.);   // core::phasor_fm::Gate
		phasor_fm.setParameterT(1, 110.); // core::phasor_fm::Frequency
		;                                 // phasor_fm::FreqRatio is automated
		phasor_fm.setParameterT(3, 0.);   // core::phasor_fm::Phase
		
		phasor_fm5.setParameterT(0, 1.);   // core::phasor_fm::Gate
		phasor_fm5.setParameterT(1, 220.); // core::phasor_fm::Frequency
		phasor_fm5.setParameterT(2, 0.);   // core::phasor_fm::FreqRatio
		phasor_fm5.setParameterT(3, 1.);   // core::phasor_fm::Phase
		
		phasor_fm3.setParameterT(0, 1.);   // core::phasor_fm::Gate
		phasor_fm3.setParameterT(1, 110.); // core::phasor_fm::Frequency
		;                                  // phasor_fm3::FreqRatio is automated
		phasor_fm3.setParameterT(3, 0.);   // core::phasor_fm::Phase
		
		phasor_fm1.setParameterT(0, 1.);      // core::phasor_fm::Gate
		;                                     // phasor_fm1::Frequency is automated
		phasor_fm1.setParameterT(2, 0.96103); // core::phasor_fm::FreqRatio
		phasor_fm1.setParameterT(3, 0.);      // core::phasor_fm::Phase
		
		; // xfader2::Value is automated
		
		pma6.setParameterT(0, 0.); // control::pma::Value
		pma6.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma6::Add is automated
		
		; // xfader3::Value is automated
		
		sub1.setParameterT(0, 0.5); // math::sub::Value
		
		abs1.setParameterT(0, 1.); // math::abs::Value
		
		mul2.setParameterT(0, 2.); // math::mul::Value
		
		;                               // gain49::Gain is automated
		gain49.setParameterT(1, 19.1);  // core::gain::Smoothing
		gain49.setParameterT(2, -100.); // core::gain::ResetValue
		
		expr3.setParameterT(0, 1.); // math::expr::Value
		
		;                              // gain50::Gain is automated
		gain50.setParameterT(1, 19.8); // core::gain::Smoothing
		gain50.setParameterT(2, -22.); // core::gain::ResetValue
		
		;                              // gain12::Gain is automated
		gain12.setParameterT(1, 0.);   // core::gain::Smoothing
		gain12.setParameterT(2, -13.); // core::gain::ResetValue
		
		;                              // gain51::Gain is automated
		gain51.setParameterT(1, 20.6); // core::gain::Smoothing
		gain51.setParameterT(2, -12.); // core::gain::ResetValue
		
		rect2.setParameterT(0, 1.); // math::rect::Value
		
		;                               // gain52::Gain is automated
		gain52.setParameterT(1, 20.);   // core::gain::Smoothing
		gain52.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // gain53::Gain is automated
		gain53.setParameterT(1, 20.); // core::gain::Smoothing
		gain53.setParameterT(2, 0.);  // core::gain::ResetValue
		
		fmod2.setParameterT(0, 1.); // math::fmod::Value
		
		mul3.setParameterT(0, 1.); // math::mul::Value
		
		pi8.setParameterT(0, 1.); // math::pi::Value
		
		;                               // gain55::Gain is automated
		gain55.setParameterT(1, 0.);    // core::gain::Smoothing
		gain55.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                              // gain56::Gain is automated
		gain56.setParameterT(1, 7);    // core::gain::Smoothing
		gain56.setParameterT(2, -12.); // core::gain::ResetValue
		
		; // expr6::Value is automated
		
		sin7.setParameterT(0, 1.); // math::sin::Value
		
		;                               // gain57::Gain is automated
		gain57.setParameterT(1, 0.);    // core::gain::Smoothing
		gain57.setParameterT(2, -100.); // core::gain::ResetValue
		
		pi9.setParameterT(0, 0.5); // math::pi::Value
		
		sin1.setParameterT(0, 1.); // math::sin::Value
		
		;                              // gain58::Gain is automated
		gain58.setParameterT(1, 20.);  // core::gain::Smoothing
		gain58.setParameterT(2, -12.); // core::gain::ResetValue
		
		sin9.setParameterT(0, 1.); // math::sin::Value
		
		expr7.setParameterT(0, 1.); // math::expr::Value
		
		;                              // gain3::Gain is automated
		gain3.setParameterT(1, 0.);    // core::gain::Smoothing
		gain3.setParameterT(2, -100.); // core::gain::ResetValue
		
		pi3.setParameterT(0, 0.465825); // math::pi::Value
		
		; // phase_delay1::Frequency is automated
		
		;                              // gain59::Gain is automated
		gain59.setParameterT(1, 20.);  // core::gain::Smoothing
		gain59.setParameterT(2, -12.); // core::gain::ResetValue
		
		expr8.setParameterT(0, 0.479197); // math::expr::Value
		
		sin10.setParameterT(0, 1.); // math::sin::Value
		
		;                               // gain60::Gain is automated
		gain60.setParameterT(1, 0.);    // core::gain::Smoothing
		gain60.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                  // clone_cable2::NumClones is deactivated
		;                                  // clone_cable2::Value is automated
		clone_cable2.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable4::NumClones is deactivated
		;                                  // clone_cable4::Value is automated
		clone_cable4.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		clone_pack1.setParameterT(0, 16.); // control::clone_pack::NumClones
		clone_pack1.setParameterT(1, 1.);  // control::clone_pack::Value
		
		clone1.setParameterT(0, 16.); // container::clone::NumClones
		clone1.setParameterT(1, 2.);  // container::clone::SplitSignal
		
		; // pi11::Value is automated
		
		sub18.setParameterT(0, 1.); // math::sub::Value
		
		; // expr9::Value is automated
		
		fmod1.setParameterT(0, 1.); // math::fmod::Value
		
		add9.setParameterT(0, 1.); // math::add::Value
		
		rect3.setParameterT(0, 0.); // math::rect::Value
		
		;                               // gain61::Gain is automated
		gain61.setParameterT(1, 408.9); // core::gain::Smoothing
		gain61.setParameterT(2, -12.);  // core::gain::ResetValue
		
		;                              // jpanner1::Pan is automated
		jpanner1.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		square1.setParameterT(0, 1.); // math::square::Value
		
		sin13.setParameterT(0, 0.675095); // math::sin::Value
		
		; // cable_table1::Value is automated
		
		sin14.setParameterT(0, 1.); // math::sin::Value
		
		;                               // gain62::Gain is automated
		gain62.setParameterT(1, 0.);    // core::gain::Smoothing
		gain62.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                              // gain63::Gain is automated
		gain63.setParameterT(1, 10.8); // core::gain::Smoothing
		gain63.setParameterT(2, -11.); // core::gain::ResetValue
		
		pi12.setParameterT(0, 1.); // math::pi::Value
		
		;                              // gain64::Gain is automated
		gain64.setParameterT(1, 20.);  // core::gain::Smoothing
		gain64.setParameterT(2, -9.5); // core::gain::ResetValue
		
		;                              // gain4::Gain is automated
		gain4.setParameterT(1, 20.);   // core::gain::Smoothing
		gain4.setParameterT(2, -100.); // core::gain::ResetValue
		
		one_pole1.setParameterT(0, 50.1457); // filters::one_pole::Frequency
		one_pole1.setParameterT(1, 1.);      // filters::one_pole::Q
		one_pole1.setParameterT(2, 0.);      // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.01);    // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 1.);      // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		; // xfader1::Value is automated
		
		;                             // gain7::Gain is automated
		gain7.setParameterT(1, 20.);  // core::gain::Smoothing
		gain7.setParameterT(2, -46.); // core::gain::ResetValue
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		; // branch24::Index is automated
		
		;                                    // tempo_sync6::Tempo is automated
		;                                    // tempo_sync6::Multiplier is automated
		tempo_sync6.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync6.setParameterT(3, 1000.); // control::tempo_sync::UnsyncedTime
		
		;                           // ramp1::PeriodTime is automated
		;                           // ramp1::LoopStart is automated
		ramp1.setParameterT(2, 1.); // core::ramp::Gate
		
		add223.setParameterT(0, 0.); // math::add::Value
		
		;                                 // clock_ramp1::Tempo is automated
		;                                 // clock_ramp1::Multiplier is automated
		clock_ramp1.setParameterT(2, 0.); // core::clock_ramp::AddToSignal
		clock_ramp1.setParameterT(3, 1.); // core::clock_ramp::UpdateMode
		clock_ramp1.setParameterT(4, 0.); // core::clock_ramp::Inactive
		
		; // add224::Value is automated
		
		clear6.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table17::Value is automated
		
		add225.setParameterT(0, 0.); // math::add::Value
		
		; // cable_table16::Value is automated
		
		clear7.setParameterT(0, 0.0039375); // math::clear::Value
		
		; // pma21::Value is automated
		; // pma21::Multiply is automated
		; // pma21::Add is automated
		
		sliderbank16.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable55.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add226::Value is automated
		
		;                              // gain132::Gain is automated
		gain132.setParameterT(1, 20.); // core::gain::Smoothing
		gain132.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable56.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add227::Value is automated
		
		;                              // gain133::Gain is automated
		gain133.setParameterT(1, 20.); // core::gain::Smoothing
		gain133.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable57.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add228::Value is automated
		
		;                              // gain134::Gain is automated
		gain134.setParameterT(1, 20.); // core::gain::Smoothing
		gain134.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable58.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add229::Value is automated
		
		;                              // gain135::Gain is automated
		gain135.setParameterT(1, 20.); // core::gain::Smoothing
		gain135.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader49.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader49.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add230::Value is automated
		
		;                              // gain136::Gain is automated
		gain136.setParameterT(1, 20.); // core::gain::Smoothing
		gain136.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader50.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader50.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add231::Value is automated
		
		;                              // gain137::Gain is automated
		gain137.setParameterT(1, 20.); // core::gain::Smoothing
		gain137.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader51::SlotIndex is automated
		event_data_reader51.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add232::Value is automated
		
		;                              // gain138::Gain is automated
		gain138.setParameterT(1, 20.); // core::gain::Smoothing
		gain138.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch26::Index is automated
		
		midi_cc58.setParameterT(0, 128.); // control::midi_cc::CCNumber
		midi_cc58.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc58.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add233::Value is automated
		
		midi_cc59.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc59.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc59.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // add234::Value is automated
		
		midi_cc60.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc60.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc60.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add235::Value is automated
		
		midi_cc61.setParameterT(0, 2.); // control::midi_cc::CCNumber
		midi_cc61.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc61.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add236::Value is automated
		
		; // add237::Value is automated
		
		; // add238::Value is automated
		
		; // add239::Value is automated
		
		;                              // gain139::Gain is automated
		gain139.setParameterT(1, 20.); // core::gain::Smoothing
		gain139.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma22::Value is automated
		; // pma22::Multiply is automated
		; // pma22::Add is automated
		
		; // pma23::Value is automated
		; // pma23::Multiply is automated
		; // pma23::Add is automated
		
		; // cable_table18::Value is automated
		
		; // cable_table19::Value is automated
		
		;                              // gain6::Gain is automated
		gain6.setParameterT(1, 0.);    // core::gain::Smoothing
		gain6.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // branch21::Index is automated
		
		; // add213::Value is automated
		
		;                             // minmax6::Value is automated
		minmax6.setParameterT(1, 0.); // control::minmax::Minimum
		minmax6.setParameterT(2, 1.); // control::minmax::Maximum
		minmax6.setParameterT(3, 1.); // control::minmax::Skew
		minmax6.setParameterT(4, 0.); // control::minmax::Step
		minmax6.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add214::Value is automated
		
		;                             // minmax7::Value is automated
		minmax7.setParameterT(1, 0.); // control::minmax::Minimum
		minmax7.setParameterT(2, 1.); // control::minmax::Maximum
		minmax7.setParameterT(3, 1.); // control::minmax::Skew
		minmax7.setParameterT(4, 0.); // control::minmax::Step
		minmax7.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add215::Value is automated
		
		;                                       // minmax14::Value is automated
		minmax14.setParameterT(1, 0.);          // control::minmax::Minimum
		minmax14.setParameterT(2, 1.);          // control::minmax::Maximum
		minmax14.setParameterT(3, 1.);          // control::minmax::Skew
		minmax14.setParameterT(4, 0.000976562); // control::minmax::Step
		minmax14.setParameterT(5, 0.);          // control::minmax::Polarity
		
		; // add216::Value is automated
		
		;                                      // minmax11::Value is automated
		minmax11.setParameterT(1, 0.);         // control::minmax::Minimum
		minmax11.setParameterT(2, 1.);         // control::minmax::Maximum
		minmax11.setParameterT(3, 1.);         // control::minmax::Skew
		minmax11.setParameterT(4, 0.00195312); // control::minmax::Step
		minmax11.setParameterT(5, 0.);         // control::minmax::Polarity
		
		; // add217::Value is automated
		
		;                                     // minmax15::Value is automated
		minmax15.setParameterT(1, 0.);        // control::minmax::Minimum
		minmax15.setParameterT(2, 1.);        // control::minmax::Maximum
		minmax15.setParameterT(3, 1.);        // control::minmax::Skew
		minmax15.setParameterT(4, 0.0117188); // control::minmax::Step
		minmax15.setParameterT(5, 0.);        // control::minmax::Polarity
		
		; // add218::Value is automated
		
		;                              // minmax16::Value is automated
		minmax16.setParameterT(1, 0.); // control::minmax::Minimum
		minmax16.setParameterT(2, 1.); // control::minmax::Maximum
		minmax16.setParameterT(3, 1.); // control::minmax::Skew
		minmax16.setParameterT(4, 0.); // control::minmax::Step
		minmax16.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // add219::Value is automated
		
		;                                   // minmax17::Value is automated
		minmax17.setParameterT(1, 0.);      // control::minmax::Minimum
		minmax17.setParameterT(2, 1.);      // control::minmax::Maximum
		minmax17.setParameterT(3, 1.);      // control::minmax::Skew
		minmax17.setParameterT(4, 0.01562); // control::minmax::Step
		minmax17.setParameterT(5, 0.);      // control::minmax::Polarity
		
		; // add220::Value is automated
		
		;                                // minmax18::Value is automated
		minmax18.setParameterT(1, 0.);   // control::minmax::Minimum
		minmax18.setParameterT(2, 1.);   // control::minmax::Maximum
		minmax18.setParameterT(3, 1.);   // control::minmax::Skew
		minmax18.setParameterT(4, 0.03); // control::minmax::Step
		minmax18.setParameterT(5, 0.);   // control::minmax::Polarity
		
		; // add221::Value is automated
		
		; // expr10::Value is automated
		
		; // add222::Value is automated
		
		; // branch22::Index is automated
		
		file_player6.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player6.setParameterT(1, 1.);      // core::file_player::Gate
		file_player6.setParameterT(2, 790.031); // core::file_player::RootFrequency
		file_player6.setParameterT(3, 1.16);    // core::file_player::FreqRatio
		
		file_player7.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player7.setParameterT(1, 1.);      // core::file_player::Gate
		file_player7.setParameterT(2, 790.031); // core::file_player::RootFrequency
		file_player7.setParameterT(3, 1.16);    // core::file_player::FreqRatio
		
		; // branch23::Index is automated
		
		tanh2.setParameterT(0, 0.733733); // math::tanh::Value
		
		; // receive2::Feedback is automated
		
		; // faust3::shiftnote is automated
		; // faust3::windowsamples is automated
		; // faust3::xfadesamples is automated
		
		; // cable_table15::Value is automated
		
		; // receive3::Feedback is automated
		
		; // faust4::shiftfreq is automated
		; // faust4::windowsamples is automated
		; // faust4::xfadesamples is automated
		
		; // faust5::shiftnote is automated
		; // faust5::windowsamples is automated
		; // faust5::xfadesamples is automated
		
		;                              // gain8::Gain is automated
		gain8.setParameterT(1, 0.);    // core::gain::Smoothing
		gain8.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                            // gain9::Gain is automated
		gain9.setParameterT(1, 20.); // core::gain::Smoothing
		gain9.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // xfader::Value is automated
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch::Index is automated
		
		; // faust::Q is automated
		; // faust::freq is automated
		
		; // faust1::Q is automated
		; // faust1::freq is automated
		
		; // faust2::Q is automated
		; // faust2::freq is automated
		
		; // faust6::Q is automated
		; // faust6::freq is automated
		
		; // cable_table::Value is automated
		
		; // faust8::aN is automated
		; // faust8::del is automated
		
		; // faust7::Q is automated
		; // faust7::freq is automated
		
		; // cable_table2::Value is automated
		
		; // faust10::Q is automated
		; // faust10::freq is automated
		
		; // faust9::aN is automated
		; // faust9::del is automated
		
		; // faust11::Q is automated
		; // faust11::freq is automated
		
		jpanner.setParameterT(0, -1.); // jdsp::jpanner::Pan
		jpanner.setParameterT(1, 1.);  // jdsp::jpanner::Rule
		
		; // faust12::Q is automated
		; // faust12::freq is automated
		
		jpanner2.setParameterT(0, 1.); // jdsp::jpanner::Pan
		jpanner2.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		; // faust13::Q is automated
		; // faust13::freq is automated
		
		jpanner4.setParameterT(0, -1.); // jdsp::jpanner::Pan
		jpanner4.setParameterT(1, 1.);  // jdsp::jpanner::Rule
		
		; // faust14::Q is automated
		; // faust14::freq is automated
		
		jpanner5.setParameterT(0, 10.); // jdsp::jpanner::Pan
		jpanner5.setParameterT(1, 1.);  // jdsp::jpanner::Rule
		
		; // cable_table3::Value is automated
		
		; // faust15::aN is automated
		; // faust15::del is automated
		
		jpanner6.setParameterT(0, -1.); // jdsp::jpanner::Pan
		jpanner6.setParameterT(1, 1.);  // jdsp::jpanner::Rule
		
		; // cable_table4::Value is automated
		
		; // faust16::aN is automated
		; // faust16::del is automated
		
		jpanner7.setParameterT(0, 10.); // jdsp::jpanner::Pan
		jpanner7.setParameterT(1, 1.);  // jdsp::jpanner::Rule
		
		;                            // gain2::Gain is automated
		gain2.setParameterT(1, 20.); // core::gain::Smoothing
		gain2.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		;                              // gain5::Gain is automated
		gain5.setParameterT(1, 3);     // core::gain::Smoothing
		gain5.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                              // jpanner3::Pan is automated
		jpanner3.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		this->setParameterT(0, -24.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 32.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 0.02);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 8.58);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 0.733611);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 1.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 1.);
		this->setParameterT(18, 4.75645);
		this->setParameterT(19, 0.);
		this->setParameterT(20, -1.);
		this->setParameterT(21, 1.);
		this->setParameterT(22, 0.);
		this->setParameterT(23, 0.);
		this->setParameterT(24, 1.);
		this->setParameterT(25, 1.);
		this->setParameterT(26, 1.);
		this->setParameterT(27, 1.);
		this->setParameterT(28, 0.);
		this->setParameterT(29, 0.01);
		this->setParameterT(30, 1.);
		this->setParameterT(31, 4.);
		this->setParameterT(32, 1.);
		this->setParameterT(33, 0.);
		this->setParameterT(34, 1.5);
		this->setParameterT(35, 1.);
		this->setParameterT(36, 0.);
		this->setParameterT(37, 96.2);
		this->setParameterT(38, 0.01);
		this->setParameterT(39, 9988.51);
		this->setParameterT(40, 0.);
		this->setParameterT(41, 0.09);
		this->setParameterT(42, 0.);
		this->setParameterT(43, 0.);
		this->setParameterT(44, 1.);
		this->setParameterT(45, 1.);
		this->setParameterT(46, 0.);
		this->setParameterT(47, 1.);
		this->setParameterT(48, 0.);
		this->setParameterT(49, 0.);
		this->setParameterT(50, 0.18);
		this->setParameterT(51, 0.);
		this->setParameterT(52, 1.);
		this->setParameterT(53, 1.);
		this->setParameterT(54, 1.);
		this->setParameterT(55, 1.);
		this->setParameterT(56, 1.);
		this->setParameterT(57, 3.);
		this->setParameterT(58, 1.);
		this->setParameterT(59, 1.);
		this->setParameterT(60, 5.);
		this->setParameterT(61, 1.);
		this->setParameterT(62, 1.);
		this->setParameterT(63, 1.00671);
		this->setParameterT(64, 5.);
		this->setParameterT(65, 1.);
		this->setParameterT(66, 3.);
		this->setParameterT(67, 0.);
		this->setParameterT(68, 0.);
		this->setParameterT(69, 0.5);
		this->setParameterT(70, 1.);
		this->setParameterT(71, 0.);
		this->setParameterT(72, 20.);
		this->setParameterT(73, 0.71);
		this->setParameterT(74, 20.);
		this->setParameterT(75, 0.);
		this->setParameterT(76, 0.44);
		this->setParameterT(77, 0.);
		this->setParameterT(78, 0.);
		this->setParameterT(79, 0.);
		this->setParameterT(80, 1.);
		this->setParameterT(81, 1.);
		this->setParameterT(82, 1.);
		this->setParameterT(83, 1.);
		this->setParameterT(84, 1.);
		this->setParameterT(85, 1.);
		this->setParameterT(86, 1.);
		this->setParameterT(87, 1.);
		this->setParameterT(88, 1.);
		this->setParameterT(89, 1.);
		this->setParameterT(90, 0.);
		this->setParameterT(91, 0.);
		this->setParameterT(92, 0.);
		this->setParameterT(93, 20.);
		this->setParameterT(94, 7.);
		this->setParameterT(95, 0.66);
		this->setParameterT(96, 0.);
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
		
		this->getT(0).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable10_t<NV>
		this->getT(0).getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable14_t<NV>
		this->getT(0).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable4_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable12_t<NV>
		this->getT(0).getT(1).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable13_t<NV>
		this->getT(0).getT(1).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable25_t<NV>
		this->getT(0).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable6_t<NV>
		this->getT(0).getT(2).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable16_t<NV>
		this->getT(0).getT(2).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable17_t<NV>
		this->getT(0).getT(2).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable26_t<NV>
		this->getT(0).getT(3).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable9_t<NV>
		this->getT(0).getT(3).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable22_t<NV>
		this->getT(0).getT(3).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable23_t<NV>
		this->getT(0).getT(3).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable29_t<NV>
		this->getT(0).getT(4).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable8_t<NV>
		this->getT(0).getT(4).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable20_t<NV>
		this->getT(0).getT(4).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable21_t<NV>
		this->getT(0).getT(4).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable28_t<NV>
		this->getT(0).getT(5).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable63_t<NV>
		this->getT(0).getT(5).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable64_t<NV>
		this->getT(0).getT(5).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable65_t<NV>
		this->getT(0).getT(5).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable66_t<NV>
		this->getT(0).getT(6).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable67_t<NV>
		this->getT(0).getT(6).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable68_t<NV>
		this->getT(0).getT(6).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable69_t<NV>
		this->getT(0).getT(6).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable70_t<NV>
		this->getT(0).getT(7).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable71_t<NV>
		this->getT(0).getT(7).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable72_t<NV>
		this->getT(0).getT(7).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable73_t<NV>
		this->getT(0).getT(7).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable74_t<NV>
		this->getT(0).getT(8).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable75_t<NV>
		this->getT(0).getT(8).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable76_t<NV>
		this->getT(0).getT(8).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable77_t<NV>
		this->getT(0).getT(8).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable78_t<NV>
		this->getT(0).getT(9).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable79_t<NV>
		this->getT(0).getT(9).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable80_t<NV>
		this->getT(0).getT(9).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable81_t<NV>
		this->getT(0).getT(9).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // osc1_impl::global_cable82_t<NV>
		this->getT(0).getT(10).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable83_t<NV>
		this->getT(0).getT(10).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable84_t<NV>
		this->getT(0).getT(10).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable85_t<NV>
		this->getT(0).getT(10).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable86_t<NV>
		this->getT(0).getT(11).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable87_t<NV>
		this->getT(0).getT(11).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable88_t<NV>
		this->getT(0).getT(11).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable89_t<NV>
		this->getT(0).getT(11).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable90_t<NV>
		this->getT(0).getT(12).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable95_t<NV>
		this->getT(0).getT(12).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable96_t<NV>
		this->getT(0).getT(12).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable97_t<NV>
		this->getT(0).getT(12).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable98_t<NV>
		this->getT(0).getT(13).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable91_t<NV>
		this->getT(0).getT(13).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable92_t<NV>
		this->getT(0).getT(13).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable93_t<NV>
		this->getT(0).getT(13).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable94_t<NV>
		this->getT(0).getT(14).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable99_t<NV>
		this->getT(0).getT(14).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable100_t<NV>
		this->getT(0).getT(14).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable101_t<NV>
		this->getT(0).getT(14).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable102_t<NV>
		this->getT(0).getT(15).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable103_t<NV>
		this->getT(0).getT(15).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable104_t<NV>
		this->getT(0).getT(15).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable105_t<NV>
		this->getT(0).getT(15).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable106_t<NV>
		this->getT(0).getT(16).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable107_t<NV>
		this->getT(0).getT(16).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable108_t<NV>
		this->getT(0).getT(16).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable109_t<NV>
		this->getT(0).getT(16).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // osc1_impl::global_cable110_t<NV>
		this->getT(13).getT(0).getT(1).getT(0).getT(0).                                          // osc1_impl::global_cable55_t<NV>
        getT(0).getT(0).getT(1).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(13).getT(0).getT(1).getT(0).getT(0).  // osc1_impl::global_cable56_t<NV>
        getT(0).getT(0).getT(1).getT(1).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(13).getT(0).getT(1).getT(0).getT(0).  // osc1_impl::global_cable57_t<NV>
        getT(0).getT(0).getT(1).getT(1).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(13).getT(0).getT(1).getT(0).getT(0).  // osc1_impl::global_cable58_t<NV>
        getT(0).getT(0).getT(1).getT(1).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).setExternalData(b, index);                                  // osc1_impl::sliderbank3_t<NV>
		this->getT(0).getT(0).getT(2).setExternalData(b, index);                                  // osc1_impl::peak3_t<NV>
		this->getT(0).getT(0).getT(4).getT(2).setExternalData(b, index);                          // osc1_impl::peak_t<NV>
		this->getT(0).getT(1).getT(0).setExternalData(b, index);                                  // osc1_impl::sliderbank4_t<NV>
		this->getT(0).getT(1).getT(2).setExternalData(b, index);                                  // osc1_impl::peak4_t<NV>
		this->getT(0).getT(2).getT(0).setExternalData(b, index);                                  // osc1_impl::sliderbank6_t<NV>
		this->getT(0).getT(2).getT(2).setExternalData(b, index);                                  // osc1_impl::peak6_t<NV>
		this->getT(0).getT(3).getT(0).setExternalData(b, index);                                  // osc1_impl::sliderbank9_t<NV>
		this->getT(0).getT(3).getT(2).setExternalData(b, index);                                  // osc1_impl::peak9_t<NV>
		this->getT(0).getT(4).getT(0).setExternalData(b, index);                                  // osc1_impl::sliderbank8_t<NV>
		this->getT(0).getT(4).getT(2).setExternalData(b, index);                                  // osc1_impl::peak8_t<NV>
		this->getT(0).getT(5).getT(0).setExternalData(b, index);                                  // osc1_impl::sliderbank18_t<NV>
		this->getT(0).getT(5).getT(2).setExternalData(b, index);                                  // osc1_impl::peak23_t<NV>
		this->getT(0).getT(6).getT(0).setExternalData(b, index);                                  // osc1_impl::sliderbank19_t<NV>
		this->getT(0).getT(6).getT(2).setExternalData(b, index);                                  // osc1_impl::peak24_t<NV>
		this->getT(0).getT(7).getT(0).setExternalData(b, index);                                  // osc1_impl::sliderbank20_t<NV>
		this->getT(0).getT(7).getT(2).setExternalData(b, index);                                  // osc1_impl::peak25_t<NV>
		this->getT(0).getT(8).getT(0).setExternalData(b, index);                                  // osc1_impl::sliderbank21_t<NV>
		this->getT(0).getT(8).getT(2).setExternalData(b, index);                                  // osc1_impl::peak26_t<NV>
		this->getT(0).getT(9).getT(0).setExternalData(b, index);                                  // osc1_impl::sliderbank22_t<NV>
		this->getT(0).getT(9).getT(2).setExternalData(b, index);                                  // osc1_impl::peak27_t<NV>
		this->getT(0).getT(10).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank23_t<NV>
		this->getT(0).getT(10).getT(2).setExternalData(b, index);                                 // osc1_impl::peak28_t<NV>
		this->getT(0).getT(11).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank24_t<NV>
		this->getT(0).getT(11).getT(2).setExternalData(b, index);                                 // osc1_impl::peak29_t<NV>
		this->getT(0).getT(12).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank26_t<NV>
		this->getT(0).getT(12).getT(2).setExternalData(b, index);                                 // osc1_impl::peak31_t<NV>
		this->getT(0).getT(13).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank25_t<NV>
		this->getT(0).getT(13).getT(2).setExternalData(b, index);                                 // osc1_impl::peak30_t<NV>
		this->getT(0).getT(14).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank27_t<NV>
		this->getT(0).getT(14).getT(2).setExternalData(b, index);                                 // osc1_impl::peak32_t<NV>
		this->getT(0).getT(15).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank28_t<NV>
		this->getT(0).getT(15).getT(2).setExternalData(b, index);                                 // osc1_impl::peak33_t
		this->getT(0).getT(16).getT(0).setExternalData(b, index);                                 // osc1_impl::sliderbank29_t<NV>
		this->getT(0).getT(16).getT(2).setExternalData(b, index);                                 // osc1_impl::peak34_t<NV>
		this->getT(5).setExternalData(b, index);                                                  // osc1_impl::peak1_t
		this->getT(8).getT(2).getT(0).getT(4).setExternalData(b, index);                          // osc1_impl::oscilloscope1_t
		this->getT(8).getT(6).getT(0).getT(0).getT(2).setExternalData(b, index);                  // osc1_impl::clone_pack1_t<NV>
		this->getT(8).getT(6).getT(0).getT(0).getT(4).setExternalData(b, index);                  // osc1_impl::cable_table1_t
		this->getT(8).getT(7).getT(2).setExternalData(b, index);                                  // osc1_impl::table5_t
		this->getT(9).getT(0).setExternalData(b, index);                                          // osc1_impl::peak5_t<NV>
		this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).                                   // osc1_impl::ramp1_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).setExternalData(b, index);
		this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(0).                                   // osc1_impl::clock_ramp1_t<NV>
        getT(0).getT(0).getT(1).getT(0).getT(1).getT(0).setExternalData(b, index);
		this->getT(13).getT(0).getT(1).getT(0).                                                   // osc1_impl::peak19_t
        getT(0).getT(0).getT(0).getT(0).
        getT(2).setExternalData(b, index);
		this->getT(13).getT(0).getT(1).getT(0).getT(0).                                           // osc1_impl::cable_table17_t<NV>
        getT(0).getT(0).getT(0).getT(4).getT(0).setExternalData(b, index);
		this->getT(13).getT(0).getT(1).getT(0).                                                   // osc1_impl::cable_table16_t
        getT(0).getT(0).getT(0).getT(0).
        getT(5).setExternalData(b, index);
		this->getT(13).getT(0).getT(1).getT(0).                                                   // osc1_impl::sliderbank16_t<NV>
        getT(0).getT(0).getT(0).getT(1).
        getT(0).setExternalData(b, index);
		this->getT(13).getT(0).getT(1).getT(0).                                                   // osc1_impl::peak21_t<NV>
        getT(0).getT(0).getT(0).getT(1).
        getT(2).setExternalData(b, index);
		this->getT(13).getT(0).getT(1).getT(0).                                                   // osc1_impl::cable_table18_t
        getT(0).getT(0).getT(0).getT(1).
        getT(5).setExternalData(b, index);
		this->getT(13).getT(0).getT(1).getT(0).                                                   // osc1_impl::cable_table19_t
        getT(0).getT(0).getT(0).getT(1).
        getT(6).setExternalData(b, index);
		this->getT(13).getT(0).getT(1).getT(0).                                                   // osc1_impl::peak18_t<NV>
        getT(0).getT(2).getT(0).getT(0).
        getT(1).setExternalData(b, index);
		this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(3).setExternalData(b, index);         // osc1_impl::peak2_t
		this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(6).getT(0).setExternalData(b, index); // osc1_impl::file_player6_t<NV>
		this->getT(13).getT(0).getT(1).getT(0).getT(0).getT(6).getT(1).setExternalData(b, index); // osc1_impl::file_player7_t<NV>
		this->getT(13).getT(0).getT(1).getT(1).getT(2).getT(1).setExternalData(b, index);         // osc1_impl::cable_table15_t<NV>
		this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(2).getT(0).setExternalData(b, index); // osc1_impl::cable_table_t<NV>
		this->getT(15).getT(1).getT(1).getT(0).getT(0).getT(3).getT(0).setExternalData(b, index); // osc1_impl::cable_table2_t<NV>
		this->getT(15).getT(1).getT(1).getT(0).                                                   // osc1_impl::cable_table3_t<NV>
        getT(0).getT(6).getT(0).getT(0).setExternalData(b, index);
		this->getT(15).getT(1).getT(1).getT(0).           // osc1_impl::cable_table4_t<NV>
        getT(0).getT(6).getT(1).getT(0).setExternalData(b, index);
		this->getT(16).getT(0).setExternalData(b, index); // osc1_impl::peak7_t<NV>
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


