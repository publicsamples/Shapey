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

namespace filtest_impl
{
// ==============================| Node & Parameter type declarations |==============================

template <int NV>
using minmax1_mod = parameter::chain<ranges::Identity, 
                                     parameter::plain<math::add<NV>, 0>, 
                                     parameter::plain<math::add<NV>, 0>, 
                                     parameter::plain<math::add<NV>, 0>, 
                                     parameter::plain<math::add<NV>, 0>, 
                                     parameter::plain<math::add<NV>, 0>, 
                                     parameter::plain<math::add<NV>, 0>, 
                                     parameter::plain<math::add<NV>, 0>, 
                                     parameter::plain<math::add<NV>, 0>, 
                                     parameter::plain<math::add<NV>, 0>, 
                                     parameter::plain<math::add<NV>, 0>, 
                                     parameter::plain<math::add<NV>, 0>, 
                                     parameter::plain<math::add<NV>, 0>>;

template <int NV>
using minmax1_t = control::minmax<NV, minmax1_mod<NV>>;
template <int NV>
using pma17_t = control::pma<NV, 
                             parameter::plain<minmax1_t<NV>, 0>>;
DECLARE_PARAMETER_RANGE(intensity_modRange, 
                        -1., 
                        1.);

template <int NV>
using intensity_mod = parameter::from0To1<pma17_t<NV>, 
                                          2, 
                                          intensity_modRange>;

template <int NV>
using intensity_t = control::intensity<NV, intensity_mod<NV>>;
template <int NV>
using ahdsr_multimod = parameter::list<parameter::plain<intensity_t<NV>, 0>, 
                                       parameter::empty>;

template <int NV>
using ahdsr_t = wrap::no_data<envelope::ahdsr<NV, ahdsr_multimod<NV>>>;

template <int NV>
using midi_t = wrap::mod<parameter::plain<pma17_t<NV>, 0>, 
                         control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using minmax6_t = control::minmax<NV, 
                                  parameter::plain<pma17_t<NV>, 1>>;

// Create a signal between 0...1 here --------------------------------------------------------------

template <int NV>
using mod_signal_t = container::chain<parameter::empty, 
                                      wrap::fix<1, wrap::no_process<math::sig2mod<NV>>>, 
                                      intensity_t<NV>, 
                                      minmax6_t<NV>, 
                                      pma17_t<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, midi_t<NV>>, 
                                  mod_signal_t<NV>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, ahdsr_t<NV>>, 
                                   chain2_t<NV>, 
                                   minmax1_t<NV>>;

template <int NV>
using ramp1_t = wrap::no_data<core::ramp<NV, false>>;
template <int NV>
using tempo_sync3_t = wrap::mod<parameter::plain<ramp1_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using split15_t = container::split<parameter::empty, 
                                   wrap::fix<1, tempo_sync3_t<NV>>>;

template <int NV> using minmax2_mod = minmax1_mod<NV>;

template <int NV>
using minmax2_t = control::minmax<NV, minmax2_mod<NV>>;
template <int NV>
using pma18_t = control::pma<NV, 
                             parameter::plain<minmax2_t<NV>, 0>>;
template <int NV>
using intensity1_mod = parameter::from0To1<pma18_t<NV>, 
                                           2, 
                                           intensity_modRange>;

template <int NV>
using intensity1_t = control::intensity<NV, intensity1_mod<NV>>;
template <int NV>
using simple_ar_multimod = parameter::list<parameter::plain<intensity1_t<NV>, 0>, 
                                           parameter::empty>;

template <int NV>
using simple_ar_t = wrap::no_data<envelope::simple_ar<NV, simple_ar_multimod<NV>>>;
template <int NV>
using input_toggle1_t = control::input_toggle<NV, 
                                              parameter::plain<simple_ar_t<NV>, 2>>;
template <int NV>
using peak2_t = wrap::mod<parameter::plain<input_toggle1_t<NV>, 2>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain165_t = container::chain<parameter::empty, 
                                    wrap::fix<1, input_toggle1_t<NV>>>;

template <int NV>
using tempo_sync4_t = wrap::mod<parameter::plain<simple_ar_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, tempo_sync4_t<NV>>>;

template <int NV>
using chain166_t = container::chain<parameter::empty, 
                                    wrap::fix<1, control::tempo_sync<NV>>>;

template <int NV>
using tempo_sync6_t = wrap::mod<parameter::plain<simple_ar_t<NV>, 1>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain185_t = container::chain<parameter::empty, 
                                    wrap::fix<1, tempo_sync6_t<NV>>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain165_t<NV>>, 
                                  chain3_t<NV>, 
                                  chain166_t<NV>, 
                                  chain185_t<NV>>;

template <int NV>
using midi1_t = wrap::mod<parameter::plain<pma18_t<NV>, 0>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<pma18_t<NV>, 1>>;

// Create a signal between 0...1 here --------------------------------------------------------------

template <int NV>
using mod_signal1_t = container::chain<parameter::empty, 
                                       wrap::fix<1, wrap::no_process<math::sig2mod<NV>>>, 
                                       intensity1_t<NV>, 
                                       minmax_t<NV>, 
                                       pma18_t<NV>>;

template <int NV>
using chain69_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi1_t<NV>>, 
                                   simple_ar_t<NV>, 
                                   math::clear<NV>, 
                                   mod_signal1_t<NV>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split15_t<NV>>, 
                                   ramp1_t<NV>, 
                                   math::rect<NV>, 
                                   peak2_t<NV>, 
                                   math::clear<NV>, 
                                   split7_t<NV>, 
                                   chain69_t<NV>, 
                                   minmax2_t<NV>>;

template <int NV> using cable_table1_mod = minmax1_mod<NV>;

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<cable_table1_mod<NV>>, 
                                  data::external::table<0>>;
template <int NV>
using ramp_t = wrap::mod<parameter::plain<cable_table1_t<NV>, 0>, 
                         wrap::no_data<core::ramp<NV, false>>>;
template <int NV>
using tempo_sync2_t = wrap::mod<parameter::plain<ramp_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain56_t = container::chain<parameter::empty, 
                                   wrap::fix<1, tempo_sync2_t<NV>>, 
                                   ramp_t<NV>, 
                                   math::clear<NV>, 
                                   cable_table1_t<NV>>;

template <int NV> using midi2_mod = minmax1_mod<NV>;

template <int NV>
using midi2_t = wrap::mod<midi2_mod<NV>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV> using midi3_mod = minmax1_mod<NV>;

template <int NV>
using midi3_t = wrap::mod<midi3_mod<NV>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV> using midi_cc1_mod = minmax1_mod<NV>;

template <int NV>
using midi_cc1_t = control::midi_cc<midi_cc1_mod<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain25_t<NV>>, 
                                  chain34_t<NV>, 
                                  chain56_t<NV>, 
                                  midi2_t<NV>, 
                                  midi3_t<NV>, 
                                  midi_cc1_t<NV>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::add<NV>>>;

template <int NV> using chain24_t = chain23_t<NV>;

template <int NV> using chain28_t = chain23_t<NV>;
using global_cable_t_index = runtime_target::indexers::fix_hash<2333884>;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable_t<NV>>, 
                                   math::add<NV>>;
using global_cable1_t_index = runtime_target::indexers::fix_hash<2333885>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable1_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using chain26_t = chain23_t<NV>;

template <int NV> using chain29_t = chain23_t<NV>;

template <int NV> using chain30_t = chain23_t<NV>;

template <int NV> using chain61_t = chain23_t<NV>;

template <int NV> using chain62_t = chain23_t<NV>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain23_t<NV>>, 
                                    chain24_t<NV>, 
                                    chain28_t<NV>, 
                                    chain19_t<NV>, 
                                    chain22_t<NV>, 
                                    chain26_t<NV>, 
                                    chain29_t<NV>, 
                                    chain30_t<NV>, 
                                    chain61_t<NV>, 
                                    chain62_t<NV>>;

template <int NV>
using oscillator8_t = wrap::data<core::oscillator<NV>, 
                                 data::external::displaybuffer<0>>;
template <int NV>
using oscillator1_t = wrap::no_data<core::oscillator<NV>>;

template <int NV>
using pma5_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<oscillator8_t<NV>, 5>, 
                                  parameter::plain<oscillator1_t<NV>, 5>>;

template <int NV>
using pma5_t = control::pma<NV, pma5_mod<NV>>;
DECLARE_PARAMETER_RANGE(pma10_modRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using pma10_mod = parameter::from0To1<pma5_t<NV>, 
                                      2, 
                                      pma10_modRange>;

template <int NV>
using pma10_t = control::pma<NV, pma10_mod<NV>>;
template <int NV>
using pma_mod = parameter::from0To1<pma10_t<NV>, 
                                    2, 
                                    pma10_modRange>;

template <int NV>
using pma_t = control::pma<NV, pma_mod<NV>>;
template <int NV>
using peak_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch4_t<NV>>, 
                                   peak_t<NV>, 
                                   pma_t<NV>, 
                                   math::clear<NV>>;

template <int NV> using chain38_t = chain23_t<NV>;

template <int NV> using chain39_t = chain23_t<NV>;

template <int NV> using chain47_t = chain23_t<NV>;
using global_cable4_t_index = global_cable_t_index;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable4_t<NV>>, 
                                   math::add<NV>>;
using global_cable5_t_index = global_cable1_t_index;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable5_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using chain44_t = chain23_t<NV>;

template <int NV> using chain45_t = chain23_t<NV>;

template <int NV> using chain46_t = chain23_t<NV>;

template <int NV> using chain60_t = chain23_t<NV>;

template <int NV> using chain59_t = chain23_t<NV>;
template <int NV>
using branch7_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain38_t<NV>>, 
                                    chain39_t<NV>, 
                                    chain47_t<NV>, 
                                    chain40_t<NV>, 
                                    chain41_t<NV>, 
                                    chain44_t<NV>, 
                                    chain45_t<NV>, 
                                    chain46_t<NV>, 
                                    chain60_t<NV>, 
                                    chain59_t<NV>>;

template <int NV>
using pma3_t = control::pma<NV, 
                            parameter::plain<control::minmax<NV, parameter::empty>, 0>>;
template <int NV>
using pma4_mod = parameter::from0To1<pma3_t<NV>, 
                                     2, 
                                     pma10_modRange>;

template <int NV>
using pma4_t = control::pma<NV, pma4_mod<NV>>;

template <int NV>
using input_toggle_mod = parameter::chain<ranges::Identity, 
                                          parameter::plain<pma4_t<NV>, 2>, 
                                          parameter::plain<oscillator8_t<NV>, 2>>;

template <int NV>
using input_toggle_t = control::input_toggle<NV, input_toggle_mod<NV>>;
template <int NV>
using converter_t = control::converter<parameter::plain<input_toggle_t<NV>, 2>, 
                                       conversion_logic::ms2freq>;

template <int NV>
using tempo_sync_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<converter_t<NV>, 0>, 
                                        parameter::plain<fx::sampleandhold<NV>, 0>>;

template <int NV>
using tempo_sync_t = wrap::mod<tempo_sync_mod<NV>, 
                               control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(pma2_modRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma2_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                     0, 
                                     pma2_modRange>;

template <int NV>
using pma2_t = control::pma<NV, pma2_mod<NV>>;
template <int NV>
using peak3_t = wrap::mod<parameter::plain<pma2_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch7_t<NV>>, 
                                   peak3_t<NV>, 
                                   pma2_t<NV>, 
                                   math::clear<NV>>;

template <int NV> using chain175_t = chain23_t<NV>;

template <int NV> using chain176_t = chain23_t<NV>;

template <int NV> using chain177_t = chain23_t<NV>;
using global_cable6_t_index = global_cable_t_index;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain178_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable6_t<NV>>, 
                                    math::add<NV>>;
using global_cable7_t_index = global_cable1_t_index;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain179_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable7_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using chain180_t = chain23_t<NV>;

template <int NV> using chain181_t = chain23_t<NV>;

template <int NV> using chain182_t = chain23_t<NV>;

template <int NV> using chain183_t = chain23_t<NV>;

template <int NV> using chain184_t = chain23_t<NV>;
template <int NV>
using branch19_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain175_t<NV>>, 
                                     chain176_t<NV>, 
                                     chain177_t<NV>, 
                                     chain178_t<NV>, 
                                     chain179_t<NV>, 
                                     chain180_t<NV>, 
                                     chain181_t<NV>, 
                                     chain182_t<NV>, 
                                     chain183_t<NV>, 
                                     chain184_t<NV>>;

template <int NV>
using smoothed_parameter3_t = wrap::mod<parameter::plain<oscillator8_t<NV>, 4>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using pma15_t = control::pma<NV, 
                             parameter::plain<smoothed_parameter3_t<NV>, 0>>;
template <int NV>
using peak16_t = wrap::mod<parameter::plain<pma15_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain174_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch19_t<NV>>, 
                                    peak16_t<NV>, 
                                    pma15_t<NV>, 
                                    math::clear<NV>>;

template <int NV> using chain64_t = chain23_t<NV>;

template <int NV> using chain65_t = chain23_t<NV>;

template <int NV> using chain114_t = chain23_t<NV>;
using global_cable12_t_index = global_cable_t_index;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain66_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   math::add<NV>>;
using global_cable13_t_index = global_cable1_t_index;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using chain70_t = chain23_t<NV>;

template <int NV> using chain71_t = chain23_t<NV>;

template <int NV> using chain72_t = chain23_t<NV>;

template <int NV> using chain154_t = chain23_t<NV>;

template <int NV> using chain153_t = chain23_t<NV>;
template <int NV>
using branch9_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain64_t<NV>>, 
                                    chain65_t<NV>, 
                                    chain114_t<NV>, 
                                    chain66_t<NV>, 
                                    chain67_t<NV>, 
                                    chain70_t<NV>, 
                                    chain71_t<NV>, 
                                    chain72_t<NV>, 
                                    chain154_t<NV>, 
                                    chain153_t<NV>>;

template <int NV>
using pma1_t = control::pma<NV, 
                            parameter::plain<input_toggle_t<NV>, 1>>;
template <int NV>
using peak5_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain63_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch9_t<NV>>, 
                                   peak5_t<NV>, 
                                   pma1_t<NV>, 
                                   math::clear<NV>>;

template <int NV> using chain161_t = chain23_t<NV>;

template <int NV> using chain162_t = chain23_t<NV>;

template <int NV> using chain163_t = chain23_t<NV>;
using global_cable14_t_index = global_cable_t_index;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain167_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable14_t<NV>>, 
                                    math::add<NV>>;
using global_cable15_t_index = global_cable1_t_index;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain168_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable15_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using chain169_t = chain23_t<NV>;

template <int NV> using chain170_t = chain23_t<NV>;

template <int NV> using chain171_t = chain23_t<NV>;

template <int NV> using chain172_t = chain23_t<NV>;

template <int NV> using chain173_t = chain23_t<NV>;
template <int NV>
using branch18_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain161_t<NV>>, 
                                     chain162_t<NV>, 
                                     chain163_t<NV>, 
                                     chain167_t<NV>, 
                                     chain168_t<NV>, 
                                     chain169_t<NV>, 
                                     chain170_t<NV>, 
                                     chain171_t<NV>, 
                                     chain172_t<NV>, 
                                     chain173_t<NV>>;

template <int NV>
using peak15_t = wrap::mod<parameter::plain<control::pma<NV, parameter::empty>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain160_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch18_t<NV>>, 
                                    peak15_t<NV>, 
                                    control::pma<NV, parameter::empty>, 
                                    math::clear<NV>>;

template <int NV> using chain74_t = chain23_t<NV>;

template <int NV> using chain75_t = chain23_t<NV>;

template <int NV> using chain115_t = chain23_t<NV>;
using global_cable16_t_index = global_cable_t_index;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain76_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>>;
using global_cable17_t_index = global_cable1_t_index;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain77_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using chain80_t = chain23_t<NV>;

template <int NV> using chain81_t = chain23_t<NV>;

template <int NV> using chain82_t = chain23_t<NV>;

template <int NV> using chain152_t = chain23_t<NV>;

template <int NV> using chain151_t = chain23_t<NV>;
template <int NV>
using branch10_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain74_t<NV>>, 
                                     chain75_t<NV>, 
                                     chain115_t<NV>, 
                                     chain76_t<NV>, 
                                     chain77_t<NV>, 
                                     chain80_t<NV>, 
                                     chain81_t<NV>, 
                                     chain82_t<NV>, 
                                     chain152_t<NV>, 
                                     chain151_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader_c0 = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      xfader_c0Range>;

template <int NV> using xfader_c1 = xfader_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::cosine_half>;
template <int NV>
using pma6_t = control::pma<NV, 
                            parameter::plain<xfader_t<NV>, 0>>;
template <int NV>
using peak6_t = wrap::mod<parameter::plain<pma6_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain73_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch10_t<NV>>, 
                                   peak6_t<NV>, 
                                   pma6_t<NV>, 
                                   math::clear<NV>>;

template <int NV> using chain85_t = chain23_t<NV>;

template <int NV> using chain86_t = chain23_t<NV>;

template <int NV> using chain159_t = chain23_t<NV>;
using global_cable20_t_index = global_cable_t_index;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain87_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable20_t<NV>>, 
                                   math::add<NV>>;
using global_cable21_t_index = global_cable1_t_index;

template <int NV>
using global_cable21_t = routing::global_cable<global_cable21_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain88_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable21_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using chain91_t = chain23_t<NV>;

template <int NV> using chain92_t = chain23_t<NV>;

template <int NV> using chain93_t = chain23_t<NV>;

template <int NV> using chain150_t = chain23_t<NV>;

template <int NV> using chain149_t = chain23_t<NV>;
template <int NV>
using branch11_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain85_t<NV>>, 
                                     chain86_t<NV>, 
                                     chain159_t<NV>, 
                                     chain87_t<NV>, 
                                     chain88_t<NV>, 
                                     chain91_t<NV>, 
                                     chain92_t<NV>, 
                                     chain93_t<NV>, 
                                     chain150_t<NV>, 
                                     chain149_t<NV>>;

namespace custom
{

struct expr
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 12.0 * value * input) * (2 - Math.PI);;
	}
};
}

DECLARE_PARAMETER_RANGE_STEP(cable_table_modRange, 
                             0., 
                             100., 
                             0.01);

template <int NV>
using cable_table_mod = parameter::from0To1<project::Comb<NV>, 
                                            1, 
                                            cable_table_modRange>;

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
using tempo_sync1_t = wrap::mod<parameter::plain<fx::sampleandhold<NV>, 0>, 
                                control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE(smoothed_parameter1_mod_0Range, 
                        0.11, 
                        1.);

template <int NV>
using smoothed_parameter1_mod_0 = parameter::from0To1<math::expr<NV, custom::expr>, 
                                                      0, 
                                                      smoothed_parameter1_mod_0Range>;

DECLARE_PARAMETER_RANGE_SKEW(smoothed_parameter1_mod_1Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using smoothed_parameter1_mod_1 = parameter::from0To1<filters::ring_mod<NV>, 
                                                      0, 
                                                      smoothed_parameter1_mod_1Range>;

DECLARE_PARAMETER_RANGE(smoothed_parameter1_mod_2Range, 
                        0.01, 
                        1.);

template <int NV>
using smoothed_parameter1_mod_2 = parameter::from0To1<math::div<NV>, 
                                                      0, 
                                                      smoothed_parameter1_mod_2Range>;

DECLARE_PARAMETER_RANGE_SKEW(smoothed_parameter1_mod_4Range, 
                             20., 
                             20000., 
                             0.229905);

using smoothed_parameter1_mod_4 = parameter::from0To1<core::fm, 
                                                      0, 
                                                      smoothed_parameter1_mod_4Range>;

template <int NV>
using smoothed_parameter1_mod_5 = parameter::from0To1<tempo_sync1_t<NV>, 
                                                      0, 
                                                      pma2_modRange>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter1_mod_6Range, 
                             0.5, 
                             16., 
                             0.1);

template <int NV>
using smoothed_parameter1_mod_6 = parameter::from0To1<fx::bitcrush<NV>, 
                                                      0, 
                                                      smoothed_parameter1_mod_6Range>;

template <int NV>
using smoothed_parameter1_mod_7 = parameter::from0To1<filters::svf_eq<NV>, 
                                                      0, 
                                                      smoothed_parameter1_mod_1Range>;

template <int NV>
using smoothed_parameter1_mod_8 = smoothed_parameter1_mod_7<NV>;

template <int NV>
using smoothed_parameter1_mod = parameter::chain<ranges::Identity, 
                                                 smoothed_parameter1_mod_0<NV>, 
                                                 smoothed_parameter1_mod_1<NV>, 
                                                 smoothed_parameter1_mod_2<NV>, 
                                                 parameter::plain<cable_table_t<NV>, 0>, 
                                                 smoothed_parameter1_mod_4, 
                                                 smoothed_parameter1_mod_5<NV>, 
                                                 smoothed_parameter1_mod_6<NV>, 
                                                 smoothed_parameter1_mod_7<NV>, 
                                                 smoothed_parameter1_mod_8<NV>, 
                                                 parameter::plain<math::mul<NV>, 0>, 
                                                 parameter::plain<math::sub<NV>, 0>, 
                                                 parameter::plain<math::pi<NV>, 0>>;

template <int NV>
using smoothed_parameter1_t = wrap::mod<smoothed_parameter1_mod<NV>, 
                                        control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using pma7_t = control::pma<NV, 
                            parameter::plain<smoothed_parameter1_t<NV>, 0>>;
template <int NV>
using peak7_t = wrap::mod<parameter::plain<pma7_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain84_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch11_t<NV>>, 
                                   peak7_t<NV>, 
                                   pma7_t<NV>, 
                                   math::clear<NV>>;

template <int NV> using chain105_t = chain23_t<NV>;

template <int NV> using chain106_t = chain23_t<NV>;

template <int NV> using chain116_t = chain23_t<NV>;
using global_cable28_t_index = global_cable_t_index;

template <int NV>
using global_cable28_t = routing::global_cable<global_cable28_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain107_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable28_t<NV>>, 
                                    math::add<NV>>;
using global_cable29_t_index = global_cable1_t_index;

template <int NV>
using global_cable29_t = routing::global_cable<global_cable29_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain108_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable29_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using chain111_t = chain23_t<NV>;

template <int NV> using chain112_t = chain23_t<NV>;

template <int NV> using chain113_t = chain23_t<NV>;

template <int NV> using chain148_t = chain23_t<NV>;

template <int NV> using chain147_t = chain23_t<NV>;
template <int NV>
using branch13_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain105_t<NV>>, 
                                     chain106_t<NV>, 
                                     chain116_t<NV>, 
                                     chain107_t<NV>, 
                                     chain108_t<NV>, 
                                     chain111_t<NV>, 
                                     chain112_t<NV>, 
                                     chain113_t<NV>, 
                                     chain148_t<NV>, 
                                     chain147_t<NV>>;

template <int NV> using pma9_mod_6 = xfader_c0<NV>;

template <int NV>
using pma9_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<wrap::no_process<math::map>, 1>, 
                                  parameter::plain<wrap::no_process<math::map>, 1>, 
                                  parameter::plain<wrap::no_process<math::map>, 1>, 
                                  parameter::plain<wrap::no_process<math::map>, 1>, 
                                  parameter::plain<wrap::no_process<math::map>, 1>, 
                                  parameter::plain<wrap::no_process<math::map>, 1>, 
                                  pma9_mod_6<NV>>;

template <int NV>
using pma9_t = control::pma<NV, pma9_mod<NV>>;
template <int NV>
using peak9_t = wrap::mod<parameter::plain<pma9_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain104_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch13_t<NV>>, 
                                    peak9_t<NV>, 
                                    pma9_t<NV>, 
                                    math::clear<NV>>;

template <int NV> using chain95_t = chain23_t<NV>;

template <int NV> using chain96_t = chain23_t<NV>;

template <int NV> using chain117_t = chain23_t<NV>;
using global_cable24_t_index = global_cable_t_index;

template <int NV>
using global_cable24_t = routing::global_cable<global_cable24_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain97_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable24_t<NV>>, 
                                   math::add<NV>>;
using global_cable25_t_index = global_cable1_t_index;

template <int NV>
using global_cable25_t = routing::global_cable<global_cable25_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain98_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable25_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using chain101_t = chain23_t<NV>;

template <int NV> using chain102_t = chain23_t<NV>;

template <int NV> using chain103_t = chain23_t<NV>;

template <int NV> using chain146_t = chain23_t<NV>;

template <int NV> using chain145_t = chain23_t<NV>;
template <int NV>
using branch12_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain95_t<NV>>, 
                                     chain96_t<NV>, 
                                     chain117_t<NV>, 
                                     chain97_t<NV>, 
                                     chain98_t<NV>, 
                                     chain101_t<NV>, 
                                     chain102_t<NV>, 
                                     chain103_t<NV>, 
                                     chain146_t<NV>, 
                                     chain145_t<NV>>;

template <int NV>
using minmax3_mod = parameter::chain<ranges::Identity, 
                                     parameter::plain<math::add<NV>, 0>, 
                                     parameter::plain<wrap::no_process<math::map>, 2>>;

template <int NV>
using minmax3_t = control::minmax<NV, minmax3_mod<NV>>;

template <int NV>
using minmax4_t = control::minmax<NV, 
                                  parameter::plain<math::add<NV>, 0>>;

template <int NV> using minmax12_mod = minmax3_mod<NV>;

template <int NV>
using minmax12_t = control::minmax<NV, minmax12_mod<NV>>;

template <int NV> using minmax10_mod = minmax3_mod<NV>;

template <int NV>
using minmax10_t = control::minmax<NV, minmax10_mod<NV>>;

template <int NV> using minmax9_mod = minmax3_mod<NV>;

template <int NV>
using minmax9_t = control::minmax<NV, minmax9_mod<NV>>;

template <int NV> using minmax8_mod = minmax3_mod<NV>;

template <int NV>
using minmax8_t = control::minmax<NV, minmax8_mod<NV>>;

template <int NV>
using minmax13_mod = parameter::chain<ranges::Identity, 
                                      parameter::plain<wrap::no_process<math::map>, 2>, 
                                      parameter::plain<math::add<NV>, 0>>;

template <int NV>
using minmax13_t = control::minmax<NV, minmax13_mod<NV>>;

template <int NV>
using smoothed_parameter_mod = parameter::chain<ranges::Identity, 
                                                parameter::plain<minmax3_t<NV>, 0>, 
                                                parameter::plain<minmax4_t<NV>, 0>, 
                                                parameter::plain<minmax12_t<NV>, 0>, 
                                                parameter::plain<minmax10_t<NV>, 0>, 
                                                parameter::plain<minmax9_t<NV>, 0>, 
                                                parameter::plain<minmax8_t<NV>, 0>, 
                                                parameter::plain<minmax13_t<NV>, 0>, 
                                                parameter::plain<math::add<NV>, 0>, 
                                                parameter::plain<wrap::no_process<math::add<NV>>, 0>>;

template <int NV>
using smoothed_parameter_t = wrap::mod<smoothed_parameter_mod<NV>, 
                                       control::smoothed_parameter<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using pma8_t = control::pma<NV, 
                            parameter::plain<smoothed_parameter_t<NV>, 0>>;
template <int NV>
using peak8_t = wrap::mod<parameter::plain<pma8_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain94_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch12_t<NV>>, 
                                   peak8_t<NV>, 
                                   pma8_t<NV>, 
                                   math::clear<NV>>;

template <int NV> using chain100_t = chain23_t<NV>;

template <int NV> using chain109_t = chain23_t<NV>;

template <int NV> using chain124_t = chain23_t<NV>;
using global_cable26_t_index = global_cable_t_index;

template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain110_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable26_t<NV>>, 
                                    math::add<NV>>;
using global_cable27_t_index = global_cable1_t_index;

template <int NV>
using global_cable27_t = routing::global_cable<global_cable27_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain125_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable27_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using chain135_t = chain23_t<NV>;

template <int NV> using chain136_t = chain23_t<NV>;

template <int NV> using chain142_t = chain23_t<NV>;

template <int NV> using chain156_t = chain23_t<NV>;

template <int NV> using chain157_t = chain23_t<NV>;
template <int NV>
using branch16_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain100_t<NV>>, 
                                     chain109_t<NV>, 
                                     chain124_t<NV>, 
                                     chain110_t<NV>, 
                                     chain125_t<NV>, 
                                     chain135_t<NV>, 
                                     chain136_t<NV>, 
                                     chain142_t<NV>, 
                                     chain156_t<NV>, 
                                     chain157_t<NV>>;

template <int NV>
using smoothed_parameter2_mod = parameter::chain<ranges::Identity, 
                                                 parameter::plain<math::add<NV>, 0>, 
                                                 parameter::plain<math::add<NV>, 0>, 
                                                 parameter::plain<math::add<NV>, 0>, 
                                                 parameter::plain<math::add<NV>, 0>, 
                                                 parameter::plain<math::add<NV>, 0>, 
                                                 parameter::plain<math::add<NV>, 0>, 
                                                 parameter::plain<math::add<NV>, 0>, 
                                                 parameter::plain<math::add<NV>, 0>>;

template <int NV>
using smoothed_parameter2_t = wrap::mod<smoothed_parameter2_mod<NV>, 
                                        control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
template <int NV>
using pma13_t = control::pma<NV, 
                             parameter::plain<smoothed_parameter2_t<NV>, 0>>;
template <int NV>
using peak14_t = wrap::mod<parameter::plain<pma13_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain99_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch16_t<NV>>, 
                                   peak14_t<NV>, 
                                   pma13_t<NV>, 
                                   math::clear<NV>>;

template <int NV> using chain119_t = chain23_t<NV>;

template <int NV> using chain120_t = chain23_t<NV>;

template <int NV> using chain121_t = chain23_t<NV>;
using global_cable32_t_index = global_cable_t_index;

template <int NV>
using global_cable32_t = routing::global_cable<global_cable32_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain122_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable32_t<NV>>, 
                                    math::add<NV>>;
using global_cable33_t_index = global_cable1_t_index;

template <int NV>
using global_cable33_t = routing::global_cable<global_cable33_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain123_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable33_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using chain126_t = chain23_t<NV>;

template <int NV> using chain127_t = chain23_t<NV>;

template <int NV> using chain128_t = chain23_t<NV>;

template <int NV> using chain140_t = chain23_t<NV>;

template <int NV> using chain141_t = chain23_t<NV>;
template <int NV>
using branch14_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain119_t<NV>>, 
                                     chain120_t<NV>, 
                                     chain121_t<NV>, 
                                     chain122_t<NV>, 
                                     chain123_t<NV>, 
                                     chain126_t<NV>, 
                                     chain127_t<NV>, 
                                     chain128_t<NV>, 
                                     chain140_t<NV>, 
                                     chain141_t<NV>>;

template <int NV>
using pma11_mod_0 = parameter::from0To1<filters::svf<NV>, 
                                        0, 
                                        smoothed_parameter1_mod_1Range>;

template <int NV> using pma11_mod_1 = pma11_mod_0<NV>;

template <int NV>
using pma11_mod = parameter::chain<ranges::Identity, 
                                   pma11_mod_0<NV>, 
                                   pma11_mod_1<NV>>;

template <int NV>
using pma11_t = control::pma<NV, pma11_mod<NV>>;
template <int NV>
using peak10_t = wrap::mod<parameter::plain<pma11_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain118_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch14_t<NV>>, 
                                    peak10_t<NV>, 
                                    pma11_t<NV>, 
                                    math::clear<NV>>;

template <int NV> using chain130_t = chain23_t<NV>;

template <int NV> using chain131_t = chain23_t<NV>;

template <int NV> using chain132_t = chain23_t<NV>;
using global_cable36_t_index = global_cable_t_index;

template <int NV>
using global_cable36_t = routing::global_cable<global_cable36_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain133_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable36_t<NV>>, 
                                    math::add<NV>>;
using global_cable37_t_index = global_cable1_t_index;

template <int NV>
using global_cable37_t = routing::global_cable<global_cable37_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain134_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable37_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using chain137_t = chain23_t<NV>;

template <int NV> using chain138_t = chain23_t<NV>;

template <int NV> using chain139_t = chain23_t<NV>;

template <int NV> using chain144_t = chain23_t<NV>;

template <int NV> using chain143_t = chain23_t<NV>;
template <int NV>
using branch15_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain130_t<NV>>, 
                                     chain131_t<NV>, 
                                     chain132_t<NV>, 
                                     chain133_t<NV>, 
                                     chain134_t<NV>, 
                                     chain137_t<NV>, 
                                     chain138_t<NV>, 
                                     chain139_t<NV>, 
                                     chain144_t<NV>, 
                                     chain143_t<NV>>;

template <int NV> using pma12_mod_0 = pma11_mod_0<NV>;

template <int NV> using pma12_mod_1 = pma11_mod_0<NV>;

template <int NV>
using pma12_mod = parameter::chain<ranges::Identity, 
                                   pma12_mod_0<NV>, 
                                   pma12_mod_1<NV>>;

template <int NV>
using pma12_t = control::pma<NV, pma12_mod<NV>>;
template <int NV>
using peak11_t = wrap::mod<parameter::plain<pma12_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain129_t = container::chain<parameter::empty, 
                                    wrap::fix<1, branch15_t<NV>>, 
                                    peak11_t<NV>, 
                                    pma12_t<NV>, 
                                    math::clear<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain18_t<NV>>, 
                                  chain37_t<NV>, 
                                  chain174_t<NV>, 
                                  chain63_t<NV>, 
                                  chain160_t<NV>, 
                                  chain73_t<NV>, 
                                  chain84_t<NV>, 
                                  chain104_t<NV>, 
                                  chain94_t<NV>, 
                                  chain99_t<NV>, 
                                  chain118_t<NV>, 
                                  chain129_t<NV>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split5_t<NV>>, 
                                      math::clear<NV>, 
                                      split6_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV>
using chain158_t = container::chain<parameter::empty, 
                                    wrap::fix<2, tempo_sync_t<NV>>, 
                                    converter_t<NV>, 
                                    input_toggle_t<NV>>;

template <int NV> using xfader2_c0 = xfader_c0<NV>;

template <int NV> using xfader2_c1 = xfader_c0<NV>;

template <int NV>
using xfader2_multimod = parameter::list<xfader2_c0<NV>, xfader2_c1<NV>>;

template <int NV>
using xfader2_t = control::xfader<xfader2_multimod<NV>, faders::linear>;

template <int NV>
using smoothed_parameter_unscaled_mod = parameter::chain<ranges::Identity, 
                                                         parameter::plain<oscillator8_t<NV>, 1>, 
                                                         parameter::plain<oscillator1_t<NV>, 1>>;

template <int NV>
using smoothed_parameter_unscaled_t = wrap::mod<smoothed_parameter_unscaled_mod<NV>, 
                                                control::smoothed_parameter_unscaled<NV, smoothers::linear_ramp<NV>>>;
template <int NV>
using converter1_t = control::converter<parameter::plain<smoothed_parameter_unscaled_t<NV>, 0>, 
                                        conversion_logic::midi2freq>;
template <int NV>
using midi5_t = wrap::mod<parameter::plain<converter1_t<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<2, pma3_t<NV>>, 
                                  pma4_t<NV>>;

template <int NV>
using split19_t = container::split<parameter::empty, 
                                   wrap::fix<2, pma5_t<NV>>, 
                                   pma10_t<NV>>;

template <int NV>
using no_midi2_t_ = container::chain<parameter::empty, 
                                     wrap::fix<2, oscillator8_t<NV>>>;

template <int NV>
using no_midi2_t = wrap::no_midi<no_midi2_t_<NV>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split9_t<NV>>, 
                                   split19_t<NV>, 
                                   control::minmax<NV, parameter::empty>, 
                                   no_midi2_t<NV>>;

template <int NV>
using chain192_t = container::chain<parameter::empty, 
                                    wrap::fix<2, chain48_t<NV>>, 
                                    core::gain<NV>>;

template <int NV>
using minmax7_t = control::minmax<NV, 
                                  parameter::plain<oscillator1_t<NV>, 2>>;
template <int NV>
using pma19_t = control::pma<NV, 
                             parameter::plain<minmax7_t<NV>, 0>>;

template <int NV>
using no_midi3_t_ = container::chain<parameter::empty, 
                                     wrap::fix<2, oscillator1_t<NV>>>;

template <int NV>
using no_midi3_t = wrap::no_midi<no_midi3_t_<NV>>;

template <int NV>
using peak17_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<pma3_t<NV>, 0>, 
                                    parameter::plain<pma5_t<NV>, 0>>;

template <int NV>
using peak17_t = wrap::mod<peak17_mod<NV>, 
                           wrap::no_data<core::peak>>;
using stereo_frame_cable = cable::frame<2>;

template <int NV>
using chain193_t = container::chain<parameter::empty, 
                                    wrap::fix<2, pma19_t<NV>>, 
                                    minmax7_t<NV>, 
                                    no_midi3_t<NV>, 
                                    peak17_t<NV>, 
                                    math::pi<NV>, 
                                    math::sub<NV>, 
                                    math::sub<NV>, 
                                    wrap::no_process<core::gain<NV>>, 
                                    core::gain<NV>, 
                                    routing::send<stereo_frame_cable>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain192_t<NV>>, 
                                  chain193_t<NV>>;

template <int NV>
using frame2_block1_t_ = container::chain<parameter::empty, 
                                          wrap::fix<2, midi5_t<NV>>, 
                                          smoothed_parameter_unscaled_t<NV>, 
                                          converter1_t<NV>, 
                                          split3_t<NV>>;

template <int NV>
using frame2_block1_t = wrap::frame<2, frame2_block1_t_<NV>>;

using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::empty>>;

using chain36_t = chain31_t;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain36_t>, 
                                    fx::sampleandhold<NV>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch6_t<NV>>>;
template <int NV>
using branch17_t = container::branch<parameter::empty, 
                                     wrap::fix<2, math::add<NV>>, 
                                     math::add<NV>, 
                                     math::add<NV>, 
                                     math::add<NV>, 
                                     math::add<NV>, 
                                     math::add<NV>, 
                                     math::add<NV>, 
                                     math::add<NV>>;

template <int NV>
using split13_t = container::split<parameter::empty, 
                                   wrap::fix<2, core::smoother<NV>>, 
                                   core::smoother<NV>>;
template <int NV>
using file_player6_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<0>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<2, smoothed_parameter2_t<NV>>, 
                                   branch17_t<NV>, 
                                   split13_t<NV>, 
                                   file_player6_t<NV>>;

template <int NV>
using chain207_t = container::chain<parameter::empty, 
                                    wrap::fix<2, chain42_t<NV>>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain31_t>, 
                                    chain33_t<NV>, 
                                    chain207_t<NV>>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain158_t<NV>>, 
                                   smoothed_parameter3_t<NV>, 
                                   xfader2_t<NV>, 
                                   frame2_block1_t<NV>, 
                                   branch5_t<NV>>;

using chain4_t = chain31_t;
using stereo_cable = cable::block<2>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, routing::send<stereo_cable>>, 
                                  math::clear<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain4_t>, 
                                  chain5_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(midi4_modRange, 
                             -64., 
                             64., 
                             0.1);

template <int NV>
using midi4_mod = parameter::from0To1<project::shfiter<NV>, 
                                      0, 
                                      midi4_modRange>;

template <int NV>
using midi4_t = wrap::mod<midi4_mod<NV>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, core::gain<NV>>>;

template <int NV> using split2_t = split13_t<NV>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr>>, 
                                   split2_t<NV>>;

template <int NV> using split4_t = split13_t<NV>;

template <int NV>
using chain197_t = container::chain<parameter::empty, 
                                    wrap::fix<2, math::mul<NV>>, 
                                    math::pi<NV>, 
                                    split4_t<NV>>;

template <int NV>
using chain199_t = container::chain<parameter::empty, 
                                    wrap::fix<2, math::pi<NV>>, 
                                    math::sub<NV>, 
                                    wrap::no_process<math::fmod<NV>>>;

template <int NV>
using chain200_t = container::chain<parameter::empty, 
                                    wrap::fix<2, math::pi<NV>>, 
                                    math::sub<NV>, 
                                    math::fmod<NV>>;

template <int NV>
using no_midi_t_ = container::chain<parameter::empty, 
                                    wrap::fix<2, filters::ring_mod<NV>>>;

template <int NV>
using no_midi_t = wrap::no_midi<no_midi_t_<NV>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<2, no_midi_t<NV>>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table_t<NV>>, 
                                   project::Comb<NV>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filters::svf_eq<NV>>>;

template <int NV> using chain155_t = chain27_t<NV>;

template <int NV> using split10_t = split13_t<NV>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::div<NV>>, 
                                   split10_t<NV>>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<2, wrap::no_process<core::phasor_fm<NV>>>, 
                                   core::fm, 
                                   core::mono2stereo, 
                                   math::tanh<NV>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync1_t<NV>>, 
                                   fx::sampleandhold<NV>>;

template <int NV> using split11_t = split13_t<NV>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<2, fx::bitcrush<NV>>, 
                                   split11_t<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain12_t<NV>>, 
                                    chain197_t<NV>, 
                                    chain199_t<NV>, 
                                    chain200_t<NV>, 
                                    chain17_t<NV>, 
                                    chain14_t<NV>, 
                                    chain27_t<NV>, 
                                    chain155_t<NV>, 
                                    chain16_t<NV>, 
                                    chain52_t<NV>, 
                                    chain54_t<NV>, 
                                    chain55_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, smoothed_parameter1_t<NV>>, 
                                  branch3_t<NV>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain_t<NV>>, 
                                 chain1_t<NV>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, xfader_t<NV>>, 
                                  split_t<NV>>;

template <int NV>
using soft_bypass_t_ = container::chain<parameter::empty, 
                                        wrap::fix<2, chain7_t<NV>>>;

template <int NV>
using soft_bypass_t = bypass::smoothed<20, soft_bypass_t_<NV>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<2, soft_bypass_t<NV>>>;

template <int NV>
using multi_t = container::multi<parameter::empty, 
                                 wrap::fix<1, core::smoother<NV>>, 
                                 wrap::fix<1, core::smoother<NV>>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, minmax3_t<NV>>, 
                                  wrap::no_process<math::map>, 
                                  math::add<NV>>;

template <int NV>
using chain89_t = container::chain<parameter::empty, 
                                   wrap::fix<2, minmax12_t<NV>>, 
                                   math::add<NV>, 
                                   wrap::no_process<math::map>>;

template <int NV>
using chain83_t = container::chain<parameter::empty, 
                                   wrap::fix<2, minmax10_t<NV>>, 
                                   math::add<NV>, 
                                   wrap::no_process<math::map>>;

template <int NV>
using chain79_t = container::chain<parameter::empty, 
                                   wrap::fix<2, minmax9_t<NV>>, 
                                   math::add<NV>, 
                                   wrap::no_process<math::map>>;

template <int NV>
using chain78_t = container::chain<parameter::empty, 
                                   wrap::fix<2, minmax8_t<NV>>, 
                                   wrap::no_process<math::map>, 
                                   math::add<NV>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<2, minmax4_t<NV>>, 
                                   math::add<NV>, 
                                   wrap::no_process<math::add<NV>>>;

template <int NV>
using chain90_t = container::chain<parameter::empty, 
                                   wrap::fix<2, minmax13_t<NV>>, 
                                   wrap::no_process<math::map>, 
                                   math::add<NV>>;
template <int NV>
using branch8_t = container::branch<parameter::empty, 
                                    wrap::fix<2, math::add<NV>>, 
                                    chain6_t<NV>, 
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
                                   wrap::fix<2, smoothed_parameter_t<NV>>, 
                                   multi_t<NV>, 
                                   chain8_t<NV>>;
template <int NV>
using file_player4_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<1>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   chain21_t<NV>, 
                                   wrap::no_process<core::mono2stereo>, 
                                   file_player4_t<NV>>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain11_t<NV>>>;

using chain9_t = chain31_t;

template <int NV>
using converter4_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<project::shfiter<NV>, 1>, 
                                        parameter::plain<project::shfiter<NV>, 2>>;

template <int NV>
using converter4_t = control::converter<converter4_mod<NV>, 
                                        conversion_logic::ms2samples>;
template <int NV>
using tempo_sync7_t = wrap::mod<parameter::plain<converter4_t<NV>, 0>, 
                                control::tempo_sync<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<2, tempo_sync7_t<NV>>, 
                                   converter4_t<NV>, 
                                   project::shfiter<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain9_t>, 
                                   chain10_t<NV>>;

template <int NV>
using no_midi1_t_ = container::chain<parameter::empty, 
                                     wrap::fix<2, filters::svf<NV>>, 
                                     filters::svf<NV>>;

template <int NV>
using no_midi1_t = wrap::no_midi<no_midi1_t_<NV>>;

template <int NV>
using chain164_t = container::chain<parameter::empty, 
                                    wrap::fix<2, no_midi1_t<NV>>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<2, filters::svf<NV>>, 
                                  filters::svf<NV>>;

template <int NV>
using chain186_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split8_t<NV>>>;
template <int NV>
using branch20_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain164_t<NV>>, 
                                     chain186_t<NV>>;

template <int NV>
using softbypass_switch5_t = container::chain<parameter::empty, 
                                              wrap::fix<2, branch20_t<NV>>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, modchain1_t<NV>>, 
                                       chain53_t<NV>, 
                                       split1_t<NV>, 
                                       midi4_t<NV>, 
                                       chain20_t<NV>, 
                                       chain68_t<NV>, 
                                       branch_t<NV>, 
                                       routing::receive<stereo_cable>, 
                                       softbypass_switch5_t<NV>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

namespace filtest_t_parameters
{
// Parameter list for filtest_impl::filtest_t ------------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(PosSmooth_InputRange, 
                             0., 
                             2000., 
                             0.231378);
DECLARE_PARAMETER_RANGE_SKEW(PosSmooth_0Range, 
                             0., 
                             24., 
                             0.231378);

template <int NV>
using PosSmooth_0 = parameter::from0To1<core::smoother<NV>, 
                                        0, 
                                        PosSmooth_0Range>;

template <int NV> using PosSmooth_1 = PosSmooth_0<NV>;

template <int NV>
using PosSmooth = parameter::chain<PosSmooth_InputRange, 
                                   PosSmooth_0<NV>, 
                                   PosSmooth_1<NV>>;

template <int NV> using MathSmooth_0 = PosSmooth_0<NV>;

template <int NV> using MathSmooth_1 = PosSmooth_0<NV>;

DECLARE_PARAMETER_RANGE_SKEW(MathSmooth_2Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using MathSmooth_2 = parameter::from0To1<filters::ring_mod<NV>, 
                                         1, 
                                         MathSmooth_2Range>;

template <int NV> using MathSmooth_3 = PosSmooth_0<NV>;

template <int NV> using MathSmooth_4 = PosSmooth_0<NV>;

DECLARE_PARAMETER_RANGE_STEP(MathSmooth_5Range, 
                             1., 
                             16., 
                             1.);

template <int NV>
using MathSmooth_5 = parameter::from0To1<filtest_impl::tempo_sync1_t<NV>, 
                                         1, 
                                         MathSmooth_5Range>;

template <int NV>
using MathSmooth_7 = parameter::from0To1<filters::svf_eq<NV>, 
                                         1, 
                                         MathSmooth_2Range>;

template <int NV> using MathSmooth_8 = MathSmooth_7<NV>;

DECLARE_PARAMETER_RANGE_STEP(MathSmooth_9Range, 
                             1., 
                             12., 
                             1.);

using MathSmooth_9 = parameter::from0To1<core::fm, 
                                         2, 
                                         MathSmooth_9Range>;

template <int NV> using MathSmooth_10 = PosSmooth_0<NV>;

template <int NV> using MathSmooth_11 = PosSmooth_0<NV>;

template <int NV> using MathSmooth_12 = PosSmooth_0<NV>;

template <int NV> using MathSmooth_13 = PosSmooth_0<NV>;

template <int NV>
using MathSmooth = parameter::chain<ranges::Identity, 
                                    MathSmooth_0<NV>, 
                                    MathSmooth_1<NV>, 
                                    MathSmooth_2<NV>, 
                                    MathSmooth_3<NV>, 
                                    MathSmooth_4<NV>, 
                                    MathSmooth_5<NV>, 
                                    parameter::plain<project::Comb<NV>, 0>, 
                                    MathSmooth_7<NV>, 
                                    MathSmooth_8<NV>, 
                                    MathSmooth_9, 
                                    MathSmooth_10<NV>, 
                                    MathSmooth_11<NV>, 
                                    MathSmooth_12<NV>, 
                                    MathSmooth_13<NV>, 
                                    parameter::plain<math::pi<NV>, 0>, 
                                    parameter::plain<math::sub<NV>, 0>>;

template <int NV>
using Blimey = parameter::from0To1<filtest_impl::pma_t<NV>, 
                                   2, 
                                   filtest_impl::pma10_modRange>;

DECLARE_PARAMETER_RANGE_STEP(BlimeyModSrc_InputRange, 
                             1., 
                             10., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(BlimeyModSrc_0Range, 
                             0., 
                             9., 
                             1.);

template <int NV>
using BlimeyModSrc_0 = parameter::from0To1<filtest_impl::branch4_t<NV>, 
                                           0, 
                                           BlimeyModSrc_0Range>;

template <int NV>
using BlimeyModSrc = parameter::chain<BlimeyModSrc_InputRange, 
                                      BlimeyModSrc_0<NV>>;

template <int NV>
using Pitch = parameter::from0To1<filtest_impl::pma1_t<NV>, 
                                  2, 
                                  filtest_impl::pma10_modRange>;

DECLARE_PARAMETER_RANGE_STEP(PitchSrc_InputRange, 
                             1., 
                             10., 
                             1.);
template <int NV>
using PitchSrc_0 = parameter::from0To1<filtest_impl::branch9_t<NV>, 
                                       0, 
                                       BlimeyModSrc_0Range>;

template <int NV>
using PitchSrc = parameter::chain<PitchSrc_InputRange, PitchSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Divide_InputRange, 
                             1., 
                             18., 
                             1.);
template <int NV>
using Divide_0 = parameter::from0To1<filtest_impl::pma2_t<NV>, 
                                     2, 
                                     filtest_impl::pma10_modRange>;

template <int NV>
using Divide = parameter::chain<Divide_InputRange, Divide_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(DivSrc_InputRange, 
                             1., 
                             10., 
                             1.);
template <int NV>
using DivSrc_0 = parameter::from0To1<filtest_impl::branch7_t<NV>, 
                                     0, 
                                     BlimeyModSrc_0Range>;

template <int NV>
using DivSrc = parameter::chain<DivSrc_InputRange, DivSrc_0<NV>>;

template <int NV>
using PitchSync = parameter::chain<ranges::Identity, 
                                   parameter::plain<filtest_impl::input_toggle_t<NV>, 0>, 
                                   parameter::plain<filtest_impl::branch6_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(InputMode_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(InputMode_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using InputMode_0 = parameter::from0To1<filtest_impl::branch5_t<NV>, 
                                        0, 
                                        InputMode_0Range>;

template <int NV>
using InputMode = parameter::chain<InputMode_InputRange, InputMode_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(OscMode_InputRange, 
                             1., 
                             5., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(OscMode_0Range, 
                             0., 
                             4., 
                             1.);

template <int NV>
using OscMode_0 = parameter::from0To1<filtest_impl::oscillator8_t<NV>, 
                                      0, 
                                      OscMode_0Range>;

template <int NV>
using OscMode_1 = parameter::from0To1<filtest_impl::oscillator1_t<NV>, 
                                      0, 
                                      OscMode_0Range>;

template <int NV>
using OscMode = parameter::chain<OscMode_InputRange, 
                                 OscMode_0<NV>, 
                                 OscMode_1<NV>>;

template <int NV>
using AdjustMix = parameter::from0To1<filtest_impl::pma6_t<NV>, 
                                      2, 
                                      filtest_impl::pma10_modRange>;

DECLARE_PARAMETER_RANGE_STEP(AdjustMixSrc_InputRange, 
                             1., 
                             10., 
                             1.);
template <int NV>
using AdjustMixSrc_0 = parameter::from0To1<filtest_impl::branch10_t<NV>, 
                                           0, 
                                           BlimeyModSrc_0Range>;

template <int NV>
using AdjustMixSrc = parameter::chain<AdjustMixSrc_InputRange, 
                                      AdjustMixSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(AdjustMode_InputRange, 
                             1., 
                             12., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(AdjustMode_0Range, 
                             0., 
                             11., 
                             1.);

template <int NV>
using AdjustMode_0 = parameter::from0To1<filtest_impl::branch3_t<NV>, 
                                         0, 
                                         AdjustMode_0Range>;

template <int NV>
using AdjustMode = parameter::chain<AdjustMode_InputRange, AdjustMode_0<NV>>;

DECLARE_PARAMETER_RANGE(AdjSrc_InputRange, 
                        1., 
                        10.);
template <int NV>
using AdjSrc_0 = parameter::from0To1<filtest_impl::branch11_t<NV>, 
                                     0, 
                                     BlimeyModSrc_0Range>;

template <int NV>
using AdjSrc = parameter::chain<AdjSrc_InputRange, AdjSrc_0<NV>>;

template <int NV>
using Position = parameter::from0To1<filtest_impl::pma8_t<NV>, 
                                     2, 
                                     filtest_impl::pma10_modRange>;

DECLARE_PARAMETER_RANGE_STEP(PosSrc_InputRange, 
                             1., 
                             10., 
                             1.);
template <int NV>
using PosSrc_0 = parameter::from0To1<filtest_impl::branch12_t<NV>, 
                                     0, 
                                     BlimeyModSrc_0Range>;

template <int NV>
using PosSrc = parameter::chain<PosSrc_InputRange, PosSrc_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Gain2Src_InputRange, 
                             1., 
                             10., 
                             1.);
template <int NV>
using Gain2Src_0 = parameter::from0To1<filtest_impl::branch13_t<NV>, 
                                       0, 
                                       BlimeyModSrc_0Range>;

template <int NV>
using Gain2Src = parameter::chain<Gain2Src_InputRange, Gain2Src_0<NV>>;

template <int NV>
using EnvMod1 = parameter::chain<ranges::Identity, 
                                 parameter::plain<filtest_impl::minmax_t<NV>, 0>, 
                                 parameter::plain<filtest_impl::minmax6_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(EnvDiv_InputRange, 
                        1., 
                        32.);
template <int NV>
using EnvDiv_0 = parameter::from0To1<control::tempo_sync<NV>, 
                                     1, 
                                     MathSmooth_5Range>;

template <int NV>
using EnvDiv_1 = parameter::from0To1<filtest_impl::tempo_sync4_t<NV>, 
                                     1, 
                                     MathSmooth_5Range>;

template <int NV>
using EnvDiv_2 = parameter::from0To1<filtest_impl::tempo_sync6_t<NV>, 
                                     1, 
                                     MathSmooth_5Range>;

template <int NV>
using EnvDiv = parameter::chain<EnvDiv_InputRange, 
                                EnvDiv_0<NV>, 
                                EnvDiv_1<NV>, 
                                EnvDiv_2<NV>>;

template <int NV>
using Env2Sync = parameter::chain<ranges::Identity, 
                                  parameter::plain<filtest_impl::tempo_sync6_t<NV>, 2>, 
                                  parameter::plain<control::tempo_sync<NV>, 2>, 
                                  parameter::plain<filtest_impl::tempo_sync4_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE(q_InputRange, 
                        0., 
                        1);
DECLARE_PARAMETER_RANGE_SKEW(q_0Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using q_0 = parameter::from0To1<filters::svf<NV>, 
                                1, 
                                q_0Range>;

template <int NV>
using q_1 = parameter::from0To1<filters::svf<NV>, 
                                1, 
                                MathSmooth_2Range>;

template <int NV> using q_2 = q_1<NV>;

template <int NV> using q_3 = q_1<NV>;

template <int NV>
using q = parameter::chain<q_InputRange, 
                           q_0<NV>, 
                           q_1<NV>, 
                           q_2<NV>, 
                           q_3<NV>>;

template <int NV>
using LP = parameter::from0To1<filtest_impl::pma11_t<NV>, 
                               2, 
                               filtest_impl::pma10_modRange>;

DECLARE_PARAMETER_RANGE_STEP(LpSrc_InputRange, 
                             1., 
                             10., 
                             1.);
template <int NV>
using LpSrc_0 = parameter::from0To1<filtest_impl::branch14_t<NV>, 
                                    0, 
                                    BlimeyModSrc_0Range>;

template <int NV>
using LpSrc = parameter::chain<LpSrc_InputRange, LpSrc_0<NV>>;

template <int NV>
using HP = parameter::from0To1<filtest_impl::pma12_t<NV>, 
                               2, 
                               filtest_impl::pma10_modRange>;

DECLARE_PARAMETER_RANGE(HpSrc_InputRange, 
                        1., 
                        10.);
template <int NV>
using HpSrc_0 = parameter::from0To1<filtest_impl::branch15_t<NV>, 
                                    0, 
                                    BlimeyModSrc_0Range>;

template <int NV>
using HpSrc = parameter::chain<HpSrc_InputRange, HpSrc_0<NV>>;

template <int NV>
using step = parameter::chain<ranges::Identity, 
                              parameter::plain<control::minmax<NV, parameter::empty>, 4>, 
                              parameter::plain<filtest_impl::minmax7_t<NV>, 4>>;

DECLARE_PARAMETER_RANGE_STEP(PostQuantise_InputRange, 
                             1., 
                             8., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(PostQuantise_0Range, 
                             0., 
                             7., 
                             1.);

template <int NV>
using PostQuantise_0 = parameter::from0To1<filtest_impl::branch8_t<NV>, 
                                           0, 
                                           PostQuantise_0Range>;

template <int NV>
using PostQuantise = parameter::chain<PostQuantise_InputRange, 
                                      PostQuantise_0<NV>>;

template <int NV>
using PositionOSc1 = parameter::from0To1<filtest_impl::pma13_t<NV>, 
                                         2, 
                                         filtest_impl::pma10_modRange>;

DECLARE_PARAMETER_RANGE(PositionOscModSrc_InputRange, 
                        1., 
                        10.);
template <int NV>
using PositionOscModSrc_0 = parameter::from0To1<filtest_impl::branch16_t<NV>, 
                                                0, 
                                                BlimeyModSrc_0Range>;

template <int NV>
using PositionOscModSrc = parameter::chain<PositionOscModSrc_InputRange, 
                                           PositionOscModSrc_0<NV>>;

template <int NV>
using PosSmoothOsc1 = parameter::chain<ranges::Identity, 
                                       parameter::plain<core::smoother<NV>, 0>, 
                                       parameter::plain<core::smoother<NV>, 0>>;

template <int NV>
using Osc2Ratio = parameter::from0To1<control::pma<NV, parameter::empty>, 
                                      2, 
                                      filtest_impl::pma10_modRange>;

DECLARE_PARAMETER_RANGE_STEP(PhaseModSrc_InputRange, 
                             1., 
                             10., 
                             1.);
template <int NV>
using PhaseModSrc_0 = parameter::from0To1<filtest_impl::branch19_t<NV>, 
                                          0, 
                                          BlimeyModSrc_0Range>;

template <int NV>
using PhaseModSrc = parameter::chain<PhaseModSrc_InputRange, PhaseModSrc_0<NV>>;

template <int NV>
using Osc2PitchModSrc = parameter::from0To1<filtest_impl::branch18_t<NV>, 
                                            0, 
                                            BlimeyModSrc_0Range>;

DECLARE_PARAMETER_RANGE_INV(TableLoop_InputRange, 
                            0., 
                            1.);

template <int NV>
using TableLoop = parameter::chain<TableLoop_InputRange, 
                                   parameter::plain<filtest_impl::ramp_t<NV>, 1>>;

template <int NV>
using detune = parameter::from0To1<filtest_impl::pma19_t<NV>, 
                                   2, 
                                   filtest_impl::pma10_modRange>;

DECLARE_PARAMETER_RANGE_STEP(GlideRange, 
                             0.1, 
                             1000., 
                             0.1);

template <int NV>
using Glide = parameter::from0To1<filtest_impl::smoothed_parameter_unscaled_t<NV>, 
                                  1, 
                                  GlideRange>;

template <int NV>
using PsXfTempo = parameter::from0To1<filtest_impl::tempo_sync7_t<NV>, 
                                      0, 
                                      filtest_impl::pma2_modRange>;

template <int NV>
using PsXfDivc = parameter::from0To1<filtest_impl::tempo_sync7_t<NV>, 
                                     1, 
                                     MathSmooth_5Range>;

template <int NV>
using Tempo = parameter::plain<filtest_impl::tempo_sync_t<NV>, 
                               1>;
template <int NV>
using BlimeyMod = parameter::plain<filtest_impl::pma_t<NV>, 
                                   1>;
template <int NV>
using PitchMod = parameter::plain<filtest_impl::pma1_t<NV>, 
                                  1>;
template <int NV>
using DivMod = parameter::plain<filtest_impl::pma2_t<NV>, 
                                1>;
using Fine = parameter::empty;
template <int NV>
using AdjustMixMod = parameter::plain<filtest_impl::pma6_t<NV>, 
                                      1>;
template <int NV>
using Adj = parameter::plain<filtest_impl::pma7_t<NV>, 
                             2>;
template <int NV>
using AdjMod = parameter::plain<filtest_impl::pma7_t<NV>, 
                                1>;
template <int NV>
using PosMod = parameter::plain<filtest_impl::pma8_t<NV>, 
                                1>;
using OutMode = Fine;
template <int NV>
using Gain2 = parameter::plain<filtest_impl::pma9_t<NV>, 
                               2>;
template <int NV>
using Gain2Mod = parameter::plain<filtest_impl::pma9_t<NV>, 
                                  1>;
template <int NV>
using a1 = parameter::plain<filtest_impl::ahdsr_t<NV>, 
                            0>;
template <int NV>
using h1 = parameter::plain<filtest_impl::ahdsr_t<NV>, 
                            2>;
template <int NV>
using d1 = parameter::plain<filtest_impl::ahdsr_t<NV>, 
                            3>;
template <int NV>
using s1 = parameter::plain<filtest_impl::ahdsr_t<NV>, 
                            4>;
template <int NV>
using r1 = parameter::plain<filtest_impl::ahdsr_t<NV>, 
                            5>;
template <int NV>
using a2 = parameter::plain<filtest_impl::tempo_sync4_t<NV>, 
                            3>;
template <int NV>
using h2 = parameter::plain<control::tempo_sync<NV>, 
                            3>;
template <int NV>
using d2 = parameter::plain<filtest_impl::tempo_sync6_t<NV>, 
                            3>;
template <int NV>
using FilterMode = parameter::plain<filtest_impl::branch20_t<NV>, 
                                    0>;
template <int NV>
using LpMod = parameter::plain<filtest_impl::pma11_t<NV>, 
                               1>;
template <int NV>
using HpMod = parameter::plain<filtest_impl::pma12_t<NV>, 
                               1>;
using PosMode = Fine;
using feed1 = Fine;
using feed2 = Fine;
template <int NV>
using PositionOsc1Mod = parameter::plain<filtest_impl::pma13_t<NV>, 
                                         1>;
using PostionSteposc1 = Fine;
template <int NV>
using ModPhase = parameter::plain<filtest_impl::pma15_t<NV>, 
                                  2>;
template <int NV>
using PhaseMod = parameter::plain<filtest_impl::pma15_t<NV>, 
                                  1>;
template <int NV>
using Osc2PitchMod = parameter::plain<control::pma<NV, parameter::empty>, 
                                      1>;
template <int NV>
using TableTempo = parameter::plain<filtest_impl::tempo_sync2_t<NV>, 
                                    0>;
template <int NV>
using TableDiv = parameter::plain<filtest_impl::tempo_sync2_t<NV>, 
                                  1>;
template <int NV>
using A2Tempo = parameter::plain<filtest_impl::tempo_sync4_t<NV>, 
                                 0>;
template <int NV>
using H2Tempo = parameter::plain<control::tempo_sync<NV>, 
                                 0>;
template <int NV>
using D2Tempo = parameter::plain<filtest_impl::tempo_sync6_t<NV>, 
                                 0>;
template <int NV>
using Env2Loop = parameter::plain<filtest_impl::input_toggle1_t<NV>, 
                                  0>;
template <int NV>
using Env2LoopTempo = parameter::plain<filtest_impl::tempo_sync3_t<NV>, 
                                       0>;
template <int NV>
using Env2LoopDiv = parameter::plain<filtest_impl::tempo_sync3_t<NV>, 
                                     1>;
using env2mod = Fine;
using q2 = Fine;
using Fmode1 = Fine;
using Fmode2 = Fine;
using blocksize = Fine;
using f1pan = Fine;
using f2pan = Fine;
using FXInputMod = Fine;
using FXInputCarrier = Fine;
using CarinputMod = Fine;
using CarInputFx = Fine;
using MasterCarrier = Fine;
using MasterSub = Fine;
using MasterMod = Fine;
using MasterFx = Fine;
template <int NV>
using SubMix = parameter::plain<filtest_impl::xfader2_t<NV>, 
                                0>;
template <int NV>
using SubFm = parameter::plain<filtest_impl::pma3_t<NV>, 
                               1>;
template <int NV>
using SubAm = parameter::plain<filtest_impl::pma5_t<NV>, 
                               1>;
using ModPostSwitch = Fine;
using inPutGain = parameter::plain<routing::receive<stereo_cable>, 
                                   0>;
template <int NV>
using PsOnOff = parameter::plain<filtest_impl::branch_t<NV>, 
                                 0>;
template <int NV>
using filtest_t_plist = parameter::list<Tempo<NV>, 
                                        PosSmooth<NV>, 
                                        MathSmooth<NV>, 
                                        Blimey<NV>, 
                                        BlimeyMod<NV>, 
                                        BlimeyModSrc<NV>, 
                                        Pitch<NV>, 
                                        PitchMod<NV>, 
                                        PitchSrc<NV>, 
                                        Divide<NV>, 
                                        DivMod<NV>, 
                                        DivSrc<NV>, 
                                        PitchSync<NV>, 
                                        Fine, 
                                        InputMode<NV>, 
                                        OscMode<NV>, 
                                        AdjustMix<NV>, 
                                        AdjustMixMod<NV>, 
                                        AdjustMixSrc<NV>, 
                                        AdjustMode<NV>, 
                                        Adj<NV>, 
                                        AdjMod<NV>, 
                                        AdjSrc<NV>, 
                                        Position<NV>, 
                                        PosMod<NV>, 
                                        PosSrc<NV>, 
                                        OutMode, 
                                        Gain2<NV>, 
                                        Gain2Mod<NV>, 
                                        Gain2Src<NV>, 
                                        a1<NV>, 
                                        h1<NV>, 
                                        d1<NV>, 
                                        s1<NV>, 
                                        r1<NV>, 
                                        EnvMod1<NV>, 
                                        a2<NV>, 
                                        h2<NV>, 
                                        d2<NV>, 
                                        EnvDiv<NV>, 
                                        Env2Sync<NV>, 
                                        q<NV>, 
                                        FilterMode<NV>, 
                                        LP<NV>, 
                                        LpMod<NV>, 
                                        LpSrc<NV>, 
                                        HP<NV>, 
                                        HpMod<NV>, 
                                        HpSrc<NV>, 
                                        step<NV>, 
                                        PosMode, 
                                        feed1, 
                                        feed2, 
                                        PostQuantise<NV>, 
                                        PositionOSc1<NV>, 
                                        PositionOsc1Mod<NV>, 
                                        PositionOscModSrc<NV>, 
                                        PostionSteposc1, 
                                        PosSmoothOsc1<NV>, 
                                        Osc2Ratio<NV>, 
                                        ModPhase<NV>, 
                                        PhaseMod<NV>, 
                                        PhaseModSrc<NV>, 
                                        Osc2PitchMod<NV>, 
                                        Osc2PitchModSrc<NV>, 
                                        TableTempo<NV>, 
                                        TableDiv<NV>, 
                                        TableLoop<NV>, 
                                        A2Tempo<NV>, 
                                        H2Tempo<NV>, 
                                        D2Tempo<NV>, 
                                        Env2Loop<NV>, 
                                        Env2LoopTempo<NV>, 
                                        Env2LoopDiv<NV>, 
                                        env2mod, 
                                        q2, 
                                        Fmode1, 
                                        Fmode2, 
                                        blocksize, 
                                        f1pan, 
                                        f2pan, 
                                        FXInputMod, 
                                        FXInputCarrier, 
                                        CarinputMod, 
                                        CarInputFx, 
                                        MasterCarrier, 
                                        MasterSub, 
                                        MasterMod, 
                                        MasterFx, 
                                        SubMix<NV>, 
                                        SubFm<NV>, 
                                        SubAm<NV>, 
                                        detune<NV>, 
                                        ModPostSwitch, 
                                        Glide<NV>, 
                                        inPutGain, 
                                        PsOnOff<NV>, 
                                        PsXfTempo<NV>, 
                                        PsXfDivc<NV>>;
}

template <int NV>
using filtest_t_ = container::chain<filtest_t_parameters::filtest_t_plist<NV>, 
                                    wrap::fix<2, fix8_block_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public filtest_impl::filtest_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 1;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 2;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 1;
		
		SNEX_METADATA_ID(filtest);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(1660)
		{
			0x005B, 0x0000, 0x5400, 0x6D65, 0x6F70, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0042, 0x3000, 0x0041, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0001, 0x0000, 0x6F50, 0x5373, 0x6F6D, 0x746F, 0x0068, 0x0000, 
            0x0000, 0x0000, 0x44FA, 0x0000, 0x0000, 0xEE69, 0x3E6C, 0xCCCD, 
            0x3DCC, 0x025B, 0x0000, 0x4D00, 0x7461, 0x5368, 0x6F6D, 0x746F, 
            0x0068, 0x0000, 0x0000, 0x0000, 0x3F80, 0xD70A, 0x3C23, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x035B, 0x0000, 0x4200, 0x696C, 0x656D, 
            0x0079, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x045B, 0x0000, 0x4200, 0x696C, 0x656D, 
            0x4D79, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0xC000, 
            0x0023, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0005, 0x0000, 0x6C42, 
            0x6D69, 0x7965, 0x6F4D, 0x5364, 0x6372, 0x0000, 0x8000, 0x003F, 
            0x2000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0006, 0x0000, 0x6950, 0x6374, 0x0068, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F00, 0x0000, 0x3F80, 0x0000, 0x0000, 0x075B, 
            0x0000, 0x5000, 0x7469, 0x6863, 0x6F4D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x085B, 0x0000, 0x5000, 0x7469, 0x6863, 0x7253, 0x0063, 0x0000, 
            0x3F80, 0x0000, 0x4120, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x095B, 0x0000, 0x4400, 0x7669, 0x6469, 0x0065, 0x0000, 
            0x3F80, 0x0000, 0x4190, 0x0000, 0x4110, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0A5B, 0x0000, 0x4400, 0x7669, 0x6F4D, 0x0064, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x23C0, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0B5B, 0x0000, 0x4400, 0x7669, 0x7253, 0x0063, 0x0000, 
            0x3F80, 0x0000, 0x4120, 0x0000, 0x40A0, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0C5B, 0x0000, 0x5000, 0x7469, 0x6863, 0x7953, 0x636E, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x000D, 0x0000, 0x6946, 0x656E, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x000E, 0x0000, 0x6E49, 0x7570, 0x4D74, 0x646F, 
            0x0065, 0x0000, 0x3F80, 0x0000, 0x4040, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0F5B, 0x0000, 0x4F00, 0x6373, 0x6F4D, 
            0x6564, 0x0000, 0x8000, 0x003F, 0xA000, 0x0040, 0x0000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x5B3F, 0x0010, 0x0000, 0x6441, 0x756A, 
            0x7473, 0x694D, 0x0078, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x115B, 0x0000, 0x4100, 
            0x6A64, 0x7375, 0x4D74, 0x7869, 0x6F4D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x23C0, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x125B, 0x0000, 0x4100, 0x6A64, 0x7375, 0x4D74, 0x7869, 0x7253, 
            0x0063, 0x0000, 0x3F80, 0x0000, 0x4120, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x135B, 0x0000, 0x4100, 0x6A64, 0x7375, 
            0x4D74, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 0x4140, 0x0000, 
            0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x145B, 0x0000, 0x4100, 
            0x6A64, 0x0000, 0x8000, 0x0024, 0x8000, 0x0A3F, 0x23D7, 0x003C, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0015, 0x0000, 0x6441, 0x4D6A, 
            0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0016, 0x0000, 0x6441, 0x536A, 
            0x6372, 0x0000, 0x8000, 0x003F, 0x2000, 0x0041, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0017, 0x0000, 0x6F50, 0x6973, 
            0x6974, 0x6E6F, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0018, 0x0000, 0x6F50, 
            0x4D73, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0019, 0x0000, 0x6F50, 
            0x5373, 0x6372, 0x0000, 0x8000, 0x003F, 0x2000, 0x0041, 0x4000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x001A, 0x0000, 0x754F, 
            0x4D74, 0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x1B5B, 0x0000, 0x4700, 
            0x6961, 0x326E, 0x0000, 0x8000, 0x0024, 0x8000, 0x003F, 0x8000, 
            0x0024, 0x8000, 0x003F, 0x0000, 0x5B00, 0x001C, 0x0000, 0x6147, 
            0x6E69, 0x4D32, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0xC000, 0x0023, 0x8000, 0x003F, 0x0000, 0x5B00, 0x001D, 0x0000, 
            0x6147, 0x6E69, 0x5332, 0x6372, 0x0000, 0x8000, 0x003F, 0x2000, 
            0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x001E, 
            0x0000, 0x3161, 0x0000, 0x0000, 0x0000, 0xEA60, 0x0046, 0x79C0, 
            0x7245, 0x4A6A, 0xCD3E, 0xCCCC, 0x5B3D, 0x001F, 0x0000, 0x3168, 
            0x0000, 0x0000, 0x0000, 0x1C40, 0x0046, 0x1C40, 0x7246, 0x4A6A, 
            0xCD3E, 0xCCCC, 0x5B3D, 0x0020, 0x0000, 0x3164, 0x0000, 0x0000, 
            0x0000, 0x1C40, 0x0046, 0x1C40, 0x7246, 0x4A6A, 0xCD3E, 0xCCCC, 
            0x5B3D, 0x0021, 0x0000, 0x3173, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0022, 
            0x0000, 0x3172, 0x0000, 0x0000, 0x0000, 0xEA60, 0x0046, 0x4B30, 
            0x7245, 0x4A6A, 0xCD3E, 0xCCCC, 0x5B3D, 0x0023, 0x0000, 0x6E45, 
            0x4D76, 0x646F, 0x0031, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x245B, 0x0000, 0x6100, 
            0x0032, 0x0000, 0x0000, 0x0000, 0x447A, 0x0000, 0x441E, 0x209B, 
            0x3E9A, 0xCCCD, 0x3DCC, 0x255B, 0x0000, 0x6800, 0x0032, 0x0000, 
            0x0000, 0x0000, 0x447A, 0x0000, 0x428E, 0x0000, 0x3F80, 0xCCCD, 
            0x3DCC, 0x265B, 0x0000, 0x6400, 0x0032, 0x0000, 0x0000, 0x0000, 
            0x447A, 0x0000, 0x447A, 0x209B, 0x3E9A, 0xCCCD, 0x3DCC, 0x275B, 
            0x0000, 0x4500, 0x766E, 0x6944, 0x0076, 0x0000, 0x3F80, 0x0000, 
            0x4200, 0x0000, 0x4120, 0x0000, 0x3F80, 0x0000, 0x0000, 0x285B, 
            0x0000, 0x4500, 0x766E, 0x5332, 0x6E79, 0x0063, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x295B, 0x0000, 0x7100, 0x0000, 0x0000, 0x0000, 0x2000, 0x0041, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x002A, 0x0000, 
            0x6946, 0x746C, 0x7265, 0x6F4D, 0x6564, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x002B, 0x0000, 0x504C, 0x0000, 0x0000, 0x0000, 0x8000, 0xA43F, 
            0x7D70, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x002C, 0x0000, 
            0x704C, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 
            0x23C0, 0x0000, 0x3F80, 0x0000, 0x0000, 0x2D5B, 0x0000, 0x4C00, 
            0x5370, 0x6372, 0x0000, 0x8000, 0x003F, 0x2000, 0x0041, 0x8000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x002E, 0x0000, 0x5048, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x002F, 0x0000, 0x7048, 0x6F4D, 0x0064, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0xD70A, 0xBC23, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x305B, 0x0000, 0x4800, 0x5370, 0x6372, 0x0000, 
            0x8000, 0x003F, 0x2000, 0x0041, 0x8000, 0x0040, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0031, 0x0000, 0x7473, 0x7065, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0032, 0x0000, 0x6F50, 0x4D73, 0x646F, 0x0065, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x3333, 0x3E68, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x335B, 0x0000, 0x6600, 0x6565, 0x3164, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0034, 0x0000, 0x6566, 0x6465, 0x0032, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0xCCCD, 0x3EB2, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x355B, 0x0000, 0x5000, 0x736F, 0x5174, 0x6175, 0x746E, 0x7369, 
            0x0065, 0x0000, 0x3F80, 0x0000, 0x4100, 0x0000, 0x4000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x365B, 0x0000, 0x5000, 0x736F, 0x7469, 
            0x6F69, 0x4F6E, 0x6353, 0x0031, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x5C29, 0x3E8F, 0x0000, 0x3F80, 0x0000, 0x0000, 0x375B, 0x0000, 
            0x5000, 0x736F, 0x7469, 0x6F69, 0x4F6E, 0x6373, 0x4D31, 0x646F, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0038, 0x0000, 0x6F50, 0x6973, 0x6974, 
            0x6E6F, 0x734F, 0x4D63, 0x646F, 0x7253, 0x0063, 0x0000, 0x3F80, 
            0x0000, 0x4120, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x395B, 0x0000, 0x5000, 0x736F, 0x6974, 0x6E6F, 0x7453, 0x7065, 
            0x736F, 0x3163, 0x0000, 0x8000, 0x003F, 0x0000, 0x0041, 0xA000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x003A, 0x0000, 0x6F50, 
            0x5373, 0x6F6D, 0x746F, 0x4F68, 0x6373, 0x0031, 0x0000, 0x0000, 
            0x0000, 0x41C0, 0x0000, 0x0000, 0xEE69, 0x3E6C, 0xCCCD, 0x3DCC, 
            0x3B5B, 0x0000, 0x4F00, 0x6373, 0x5232, 0x7461, 0x6F69, 0x0000, 
            0x0000, 0x0000, 0x8000, 0xD33F, 0x469B, 0x003D, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x003C, 0x0000, 0x6F4D, 0x5064, 0x6168, 0x6573, 
            0x0000, 0x8000, 0x0024, 0x8000, 0x293F, 0x8F5C, 0x003D, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x003D, 0x0000, 0x6850, 0x7361, 0x4D65, 
            0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0xC000, 0x0023, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x003E, 0x0000, 0x6850, 0x7361, 
            0x4D65, 0x646F, 0x7253, 0x0063, 0x0000, 0x3F80, 0x0000, 0x4120, 
            0x0000, 0x40A0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x3F5B, 0x0000, 
            0x4F00, 0x6373, 0x5032, 0x7469, 0x6863, 0x6F4D, 0x0064, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0xDE9C, 0x3F27, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x405B, 0x0000, 0x4F00, 0x6373, 0x5032, 0x7469, 0x6863, 
            0x6F4D, 0x5364, 0x6372, 0x0000, 0x0000, 0x0000, 0x8000, 0x963F, 
            0x7F4A, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0041, 0x0000, 
            0x6154, 0x6C62, 0x5465, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0042, 0x0000, 0x6154, 0x6C62, 0x4465, 0x7669, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x0041, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0043, 0x0000, 0x6154, 0x6C62, 0x4C65, 0x6F6F, 0x0070, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x445B, 0x0000, 0x4100, 0x5432, 0x6D65, 0x6F70, 
            0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0045, 0x0000, 0x3248, 0x6554, 0x706D, 
            0x006F, 0x0000, 0x0000, 0x0000, 0x4190, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x465B, 0x0000, 0x4400, 0x5432, 0x6D65, 
            0x6F70, 0x0000, 0x0000, 0x0000, 0x9000, 0x0041, 0x0000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x5B3F, 0x0047, 0x0000, 0x6E45, 0x3276, 
            0x6F4C, 0x706F, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0048, 0x0000, 0x6E45, 
            0x3276, 0x6F4C, 0x706F, 0x6554, 0x706D, 0x006F, 0x0000, 0x0000, 
            0x0000, 0x4190, 0x0000, 0x4130, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x495B, 0x0000, 0x4500, 0x766E, 0x4C32, 0x6F6F, 0x4470, 0x7669, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0041, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x004A, 0x0000, 0x6E65, 0x3276, 0x6F6D, 
            0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x01BA, 0xBF41, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x4B5B, 0x0000, 0x7100, 0x0032, 0x0000, 
            0x0000, 0x0000, 0x4120, 0x51EB, 0x40E8, 0x0000, 0x3F80, 0xD70A, 
            0x3C23, 0x4C5B, 0x0000, 0x4600, 0x6F6D, 0x6564, 0x0031, 0x0000, 
            0x3F80, 0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x4D5B, 0x0000, 0x4600, 0x6F6D, 0x6564, 0x0032, 0x0000, 
            0x3F80, 0x0000, 0x4000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x4E5B, 0x0000, 0x6200, 0x6F6C, 0x6B63, 0x6973, 0x657A, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0041, 0x0000, 0x0041, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x004F, 0x0000, 0x3166, 0x6170, 0x006E, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x0B21, 0x3F74, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x505B, 0x0000, 0x6600, 0x7032, 0x6E61, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0051, 0x0000, 0x5846, 0x6E49, 0x7570, 0x4D74, 
            0x646F, 0x0000, 0x0000, 0x0000, 0x8000, 0x3D3F, 0x170A, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0052, 0x0000, 0x5846, 0x6E49, 
            0x7570, 0x4374, 0x7261, 0x6972, 0x7265, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0053, 0x0000, 0x6143, 0x6972, 0x706E, 0x7475, 0x6F4D, 0x0064, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0xEB85, 0x3F11, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x545B, 0x0000, 0x4300, 0x7261, 0x6E49, 0x7570, 
            0x4674, 0x0078, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x555B, 0x0000, 0x4D00, 0x7361, 
            0x6574, 0x4372, 0x7261, 0x6972, 0x7265, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0056, 0x0000, 0x614D, 0x7473, 0x7265, 0x7553, 0x0062, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x575B, 0x0000, 0x4D00, 0x7361, 0x6574, 0x4D72, 0x646F, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0058, 0x0000, 0x614D, 0x7473, 0x7265, 
            0x7846, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0059, 0x0000, 0x7553, 0x4D62, 
            0x7869, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x005A, 0x0000, 0x7553, 0x4662, 
            0x006D, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x5B5B, 0x0000, 0x5300, 0x6275, 0x6D41, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x005C, 0x0000, 0x6564, 0x7574, 0x656E, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x8F3F, 0xF5C2, 0x003D, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x005D, 0x0000, 0x6F4D, 0x5064, 0x736F, 
            0x5374, 0x6977, 0x6374, 0x0068, 0x0000, 0x0000, 0x0000, 0x4000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x5E5B, 0x0000, 
            0x4700, 0x696C, 0x6564, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x005F, 0x0000, 
            0x6E69, 0x7550, 0x4774, 0x6961, 0x006E, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x605B, 
            0x0000, 0x5000, 0x4F73, 0x4F6E, 0x6666, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0061, 0x0000, 0x7350, 0x6658, 0x6554, 0x706D, 0x006F, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x625B, 0x0000, 0x5000, 0x5873, 0x4466, 0x7669, 0x0063, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& fix8_block = this->getT(0);                                                          // filtest_impl::fix8_block_t<NV>
		auto& modchain1 = this->getT(0).getT(0);                                                   // filtest_impl::modchain1_t<NV>
		auto& split5 = this->getT(0).getT(0).getT(0);                                              // filtest_impl::split5_t<NV>
		auto& chain25 = this->getT(0).getT(0).getT(0).getT(0);                                     // filtest_impl::chain25_t<NV>
		auto& ahdsr = this->getT(0).getT(0).getT(0).getT(0).getT(0);                               // filtest_impl::ahdsr_t<NV>
		auto& chain2 = this->getT(0).getT(0).getT(0).getT(0).getT(1);                              // filtest_impl::chain2_t<NV>
		auto& midi = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);                        // filtest_impl::midi_t<NV>
		auto& mod_signal = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);                  // filtest_impl::mod_signal_t<NV>
		auto& sig2mod1 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0);            // wrap::no_process<math::sig2mod<NV>>
		auto& intensity = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(1);           // filtest_impl::intensity_t<NV>
		auto& minmax6 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(2);             // filtest_impl::minmax6_t<NV>
		auto& pma17 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(3);               // filtest_impl::pma17_t<NV>
		auto& minmax1 = this->getT(0).getT(0).getT(0).getT(0).getT(2);                             // filtest_impl::minmax1_t<NV>
		auto& chain34 = this->getT(0).getT(0).getT(0).getT(1);                                     // filtest_impl::chain34_t<NV>
		auto& split15 = this->getT(0).getT(0).getT(0).getT(1).getT(0);                             // filtest_impl::split15_t<NV>
		auto& tempo_sync3 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);                 // filtest_impl::tempo_sync3_t<NV>
		auto& ramp1 = this->getT(0).getT(0).getT(0).getT(1).getT(1);                               // filtest_impl::ramp1_t<NV>
		auto& rect = this->getT(0).getT(0).getT(0).getT(1).getT(2);                                // math::rect<NV>
		auto& peak2 = this->getT(0).getT(0).getT(0).getT(1).getT(3);                               // filtest_impl::peak2_t<NV>
		auto& clear2 = this->getT(0).getT(0).getT(0).getT(1).getT(4);                              // math::clear<NV>
		auto& split7 = this->getT(0).getT(0).getT(0).getT(1).getT(5);                              // filtest_impl::split7_t<NV>
		auto& chain165 = this->getT(0).getT(0).getT(0).getT(1).getT(5).getT(0);                    // filtest_impl::chain165_t<NV>
		auto& input_toggle1 = this->getT(0).getT(0).getT(0).getT(1).getT(5).getT(0).getT(0);       // filtest_impl::input_toggle1_t<NV>
		auto& chain3 = this->getT(0).getT(0).getT(0).getT(1).getT(5).getT(1);                      // filtest_impl::chain3_t<NV>
		auto& tempo_sync4 = this->getT(0).getT(0).getT(0).getT(1).getT(5).getT(1).getT(0);         // filtest_impl::tempo_sync4_t<NV>
		auto& chain166 = this->getT(0).getT(0).getT(0).getT(1).getT(5).getT(2);                    // filtest_impl::chain166_t<NV>
		auto& tempo_sync5 = this->getT(0).getT(0).getT(0).getT(1).getT(5).getT(2).getT(0);         // control::tempo_sync<NV>
		auto& chain185 = this->getT(0).getT(0).getT(0).getT(1).getT(5).getT(3);                    // filtest_impl::chain185_t<NV>
		auto& tempo_sync6 = this->getT(0).getT(0).getT(0).getT(1).getT(5).getT(3).getT(0);         // filtest_impl::tempo_sync6_t<NV>
		auto& chain69 = this->getT(0).getT(0).getT(0).getT(1).getT(6);                             // filtest_impl::chain69_t<NV>
		auto& midi1 = this->getT(0).getT(0).getT(0).getT(1).getT(6).getT(0);                       // filtest_impl::midi1_t<NV>
		auto& simple_ar = this->getT(0).getT(0).getT(0).getT(1).getT(6).getT(1);                   // filtest_impl::simple_ar_t<NV>
		auto& clear16 = this->getT(0).getT(0).getT(0).getT(1).getT(6).getT(2);                     // math::clear<NV>
		auto& mod_signal1 = this->getT(0).getT(0).getT(0).getT(1).getT(6).getT(3);                 // filtest_impl::mod_signal1_t<NV>
		auto& sig2mod3 = this->getT(0).getT(0).getT(0).getT(1).getT(6).getT(3).getT(0);            // wrap::no_process<math::sig2mod<NV>>
		auto& intensity1 = this->getT(0).getT(0).getT(0).getT(1).getT(6).getT(3).getT(1);          // filtest_impl::intensity1_t<NV>
		auto& minmax = this->getT(0).getT(0).getT(0).getT(1).getT(6).getT(3).getT(2);              // filtest_impl::minmax_t<NV>
		auto& pma18 = this->getT(0).getT(0).getT(0).getT(1).getT(6).getT(3).getT(3);               // filtest_impl::pma18_t<NV>
		auto& minmax2 = this->getT(0).getT(0).getT(0).getT(1).getT(7);                             // filtest_impl::minmax2_t<NV>
		auto& chain56 = this->getT(0).getT(0).getT(0).getT(2);                                     // filtest_impl::chain56_t<NV>
		auto& tempo_sync2 = this->getT(0).getT(0).getT(0).getT(2).getT(0);                         // filtest_impl::tempo_sync2_t<NV>
		auto& ramp = this->getT(0).getT(0).getT(0).getT(2).getT(1);                                // filtest_impl::ramp_t<NV>
		auto& clear4 = this->getT(0).getT(0).getT(0).getT(2).getT(2);                              // math::clear<NV>
		auto& cable_table1 = this->getT(0).getT(0).getT(0).getT(2).getT(3);                        // filtest_impl::cable_table1_t<NV>
		auto& midi2 = this->getT(0).getT(0).getT(0).getT(3);                                       // filtest_impl::midi2_t<NV>
		auto& midi3 = this->getT(0).getT(0).getT(0).getT(4);                                       // filtest_impl::midi3_t<NV>
		auto& midi_cc1 = this->getT(0).getT(0).getT(0).getT(5);                                    // filtest_impl::midi_cc1_t<NV>
		auto& clear = this->getT(0).getT(0).getT(1);                                               // math::clear<NV>
		auto& split6 = this->getT(0).getT(0).getT(2);                                              // filtest_impl::split6_t<NV>
		auto& chain18 = this->getT(0).getT(0).getT(2).getT(0);                                     // filtest_impl::chain18_t<NV>
		auto& branch4 = this->getT(0).getT(0).getT(2).getT(0).getT(0);                             // filtest_impl::branch4_t<NV>
		auto& chain23 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0);                     // filtest_impl::chain23_t<NV>
		auto& add6 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0).getT(0);                // math::add<NV>
		auto& chain24 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1);                     // filtest_impl::chain24_t<NV>
		auto& add7 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1).getT(0);                // math::add<NV>
		auto& chain28 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(2);                     // filtest_impl::chain28_t<NV>
		auto& add11 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(2).getT(0);               // math::add<NV>
		auto& chain19 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(3);                     // filtest_impl::chain19_t<NV>
		auto& global_cable = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(3).getT(0);        // filtest_impl::global_cable_t<NV>
		auto& add = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(3).getT(1);                 // math::add<NV>
		auto& chain22 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(4);                     // filtest_impl::chain22_t<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(4).getT(0);       // filtest_impl::global_cable1_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(4).getT(1);                // math::add<NV>
		auto& chain26 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(5);                     // filtest_impl::chain26_t<NV>
		auto& add8 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(5).getT(0);                // math::add<NV>
		auto& chain29 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(6);                     // filtest_impl::chain29_t<NV>
		auto& add9 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(6).getT(0);                // math::add<NV>
		auto& chain30 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(7);                     // filtest_impl::chain30_t<NV>
		auto& add10 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(7).getT(0);               // math::add<NV>
		auto& chain61 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(8);                     // filtest_impl::chain61_t<NV>
		auto& add14 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(8).getT(0);               // math::add<NV>
		auto& chain62 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(9);                     // filtest_impl::chain62_t<NV>
		auto& add15 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(9).getT(0);               // math::add<NV>
		auto& peak = this->getT(0).getT(0).getT(2).getT(0).getT(1);                                // filtest_impl::peak_t<NV>
		auto& pma = this->getT(0).getT(0).getT(2).getT(0).getT(2);                                 // filtest_impl::pma_t<NV>
		auto& clear1 = this->getT(0).getT(0).getT(2).getT(0).getT(3);                              // math::clear<NV>
		auto& chain37 = this->getT(0).getT(0).getT(2).getT(1);                                     // filtest_impl::chain37_t<NV>
		auto& branch7 = this->getT(0).getT(0).getT(2).getT(1).getT(0);                             // filtest_impl::branch7_t<NV>
		auto& chain38 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0);                     // filtest_impl::chain38_t<NV>
		auto& add16 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).getT(0);               // math::add<NV>
		auto& chain39 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(1);                     // filtest_impl::chain39_t<NV>
		auto& add17 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(1).getT(0);               // math::add<NV>
		auto& chain47 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(2);                     // filtest_impl::chain47_t<NV>
		auto& add25 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(2).getT(0);               // math::add<NV>
		auto& chain40 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(3);                     // filtest_impl::chain40_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(3).getT(0);       // filtest_impl::global_cable4_t<NV>
		auto& add18 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(3).getT(1);               // math::add<NV>
		auto& chain41 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(4);                     // filtest_impl::chain41_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(4).getT(0);       // filtest_impl::global_cable5_t<NV>
		auto& add19 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(4).getT(1);               // math::add<NV>
		auto& chain44 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(5);                     // filtest_impl::chain44_t<NV>
		auto& add22 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(5).getT(0);               // math::add<NV>
		auto& chain45 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(6);                     // filtest_impl::chain45_t<NV>
		auto& add23 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(6).getT(0);               // math::add<NV>
		auto& chain46 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(7);                     // filtest_impl::chain46_t<NV>
		auto& add24 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(7).getT(0);               // math::add<NV>
		auto& chain60 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(8);                     // filtest_impl::chain60_t<NV>
		auto& add27 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(8).getT(0);               // math::add<NV>
		auto& chain59 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(9);                     // filtest_impl::chain59_t<NV>
		auto& add26 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(9).getT(0);               // math::add<NV>
		auto& peak3 = this->getT(0).getT(0).getT(2).getT(1).getT(1);                               // filtest_impl::peak3_t<NV>
		auto& pma2 = this->getT(0).getT(0).getT(2).getT(1).getT(2);                                // filtest_impl::pma2_t<NV>
		auto& clear5 = this->getT(0).getT(0).getT(2).getT(1).getT(3);                              // math::clear<NV>
		auto& chain174 = this->getT(0).getT(0).getT(2).getT(2);                                    // filtest_impl::chain174_t<NV>
		auto& branch19 = this->getT(0).getT(0).getT(2).getT(2).getT(0);                            // filtest_impl::branch19_t<NV>
		auto& chain175 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(0);                    // filtest_impl::chain175_t<NV>
		auto& add20 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(0).getT(0);               // math::add<NV>
		auto& chain176 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(1);                    // filtest_impl::chain176_t<NV>
		auto& add21 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(1).getT(0);               // math::add<NV>
		auto& chain177 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(2);                    // filtest_impl::chain177_t<NV>
		auto& add28 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(2).getT(0);               // math::add<NV>
		auto& chain178 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(3);                    // filtest_impl::chain178_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(3).getT(0);       // filtest_impl::global_cable6_t<NV>
		auto& add29 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(3).getT(1);               // math::add<NV>
		auto& chain179 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(4);                    // filtest_impl::chain179_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(4).getT(0);       // filtest_impl::global_cable7_t<NV>
		auto& add30 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(4).getT(1);               // math::add<NV>
		auto& chain180 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(5);                    // filtest_impl::chain180_t<NV>
		auto& add31 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(5).getT(0);               // math::add<NV>
		auto& chain181 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(6);                    // filtest_impl::chain181_t<NV>
		auto& add32 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(6).getT(0);               // math::add<NV>
		auto& chain182 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(7);                    // filtest_impl::chain182_t<NV>
		auto& add33 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(7).getT(0);               // math::add<NV>
		auto& chain183 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(8);                    // filtest_impl::chain183_t<NV>
		auto& add123 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(8).getT(0);              // math::add<NV>
		auto& chain184 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(9);                    // filtest_impl::chain184_t<NV>
		auto& add124 = this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(9).getT(0);              // math::add<NV>
		auto& peak16 = this->getT(0).getT(0).getT(2).getT(2).getT(1);                              // filtest_impl::peak16_t<NV>
		auto& pma15 = this->getT(0).getT(0).getT(2).getT(2).getT(2);                               // filtest_impl::pma15_t<NV>
		auto& clear6 = this->getT(0).getT(0).getT(2).getT(2).getT(3);                              // math::clear<NV>
		auto& chain63 = this->getT(0).getT(0).getT(2).getT(3);                                     // filtest_impl::chain63_t<NV>
		auto& branch9 = this->getT(0).getT(0).getT(2).getT(3).getT(0);                             // filtest_impl::branch9_t<NV>
		auto& chain64 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(0);                     // filtest_impl::chain64_t<NV>
		auto& add34 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(0).getT(0);               // math::add<NV>
		auto& chain65 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(1);                     // filtest_impl::chain65_t<NV>
		auto& add35 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(1).getT(0);               // math::add<NV>
		auto& chain114 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(2);                    // filtest_impl::chain114_t<NV>
		auto& add79 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(2).getT(0);               // math::add<NV>
		auto& chain66 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(3);                     // filtest_impl::chain66_t<NV>
		auto& global_cable12 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(3).getT(0);      // filtest_impl::global_cable12_t<NV>
		auto& add36 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(3).getT(1);               // math::add<NV>
		auto& chain67 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(4);                     // filtest_impl::chain67_t<NV>
		auto& global_cable13 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(4).getT(0);      // filtest_impl::global_cable13_t<NV>
		auto& add37 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(4).getT(1);               // math::add<NV>
		auto& chain70 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(5);                     // filtest_impl::chain70_t<NV>
		auto& add40 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(5).getT(0);               // math::add<NV>
		auto& chain71 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(6);                     // filtest_impl::chain71_t<NV>
		auto& add41 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(6).getT(0);               // math::add<NV>
		auto& chain72 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(7);                     // filtest_impl::chain72_t<NV>
		auto& add42 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(7).getT(0);               // math::add<NV>
		auto& chain154 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(8);                    // filtest_impl::chain154_t<NV>
		auto& add117 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(8).getT(0);              // math::add<NV>
		auto& chain153 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(9);                    // filtest_impl::chain153_t<NV>
		auto& add116 = this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(9).getT(0);              // math::add<NV>
		auto& peak5 = this->getT(0).getT(0).getT(2).getT(3).getT(1);                               // filtest_impl::peak5_t<NV>
		auto& pma1 = this->getT(0).getT(0).getT(2).getT(3).getT(2);                                // filtest_impl::pma1_t<NV>
		auto& clear7 = this->getT(0).getT(0).getT(2).getT(3).getT(3);                              // math::clear<NV>
		auto& chain160 = this->getT(0).getT(0).getT(2).getT(4);                                    // filtest_impl::chain160_t<NV>
		auto& branch18 = this->getT(0).getT(0).getT(2).getT(4).getT(0);                            // filtest_impl::branch18_t<NV>
		auto& chain161 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(0);                    // filtest_impl::chain161_t<NV>
		auto& add38 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(0).getT(0);               // math::add<NV>
		auto& chain162 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(1);                    // filtest_impl::chain162_t<NV>
		auto& add39 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(1).getT(0);               // math::add<NV>
		auto& chain163 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(2);                    // filtest_impl::chain163_t<NV>
		auto& add105 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(2).getT(0);              // math::add<NV>
		auto& chain167 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(3);                    // filtest_impl::chain167_t<NV>
		auto& global_cable14 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(3).getT(0);      // filtest_impl::global_cable14_t<NV>
		auto& add47 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(3).getT(1);               // math::add<NV>
		auto& chain168 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(4);                    // filtest_impl::chain168_t<NV>
		auto& global_cable15 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(4).getT(0);      // filtest_impl::global_cable15_t<NV>
		auto& add48 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(4).getT(1);               // math::add<NV>
		auto& chain169 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(5);                    // filtest_impl::chain169_t<NV>
		auto& add56 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(5).getT(0);               // math::add<NV>
		auto& chain170 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(6);                    // filtest_impl::chain170_t<NV>
		auto& add57 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(6).getT(0);               // math::add<NV>
		auto& chain171 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(7);                    // filtest_impl::chain171_t<NV>
		auto& add120 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(7).getT(0);              // math::add<NV>
		auto& chain172 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(8);                    // filtest_impl::chain172_t<NV>
		auto& add121 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(8).getT(0);              // math::add<NV>
		auto& chain173 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(9);                    // filtest_impl::chain173_t<NV>
		auto& add122 = this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(9).getT(0);              // math::add<NV>
		auto& peak15 = this->getT(0).getT(0).getT(2).getT(4).getT(1);                              // filtest_impl::peak15_t<NV>
		auto& pma14 = this->getT(0).getT(0).getT(2).getT(4).getT(2);                               // control::pma<NV, parameter::empty>
		auto& clear15 = this->getT(0).getT(0).getT(2).getT(4).getT(3);                             // math::clear<NV>
		auto& chain73 = this->getT(0).getT(0).getT(2).getT(5);                                     // filtest_impl::chain73_t<NV>
		auto& branch10 = this->getT(0).getT(0).getT(2).getT(5).getT(0);                            // filtest_impl::branch10_t<NV>
		auto& chain74 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(0);                     // filtest_impl::chain74_t<NV>
		auto& add43 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(0).getT(0);               // math::add<NV>
		auto& chain75 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(1);                     // filtest_impl::chain75_t<NV>
		auto& add44 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(1).getT(0);               // math::add<NV>
		auto& chain115 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(2);                    // filtest_impl::chain115_t<NV>
		auto& add80 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(2).getT(0);               // math::add<NV>
		auto& chain76 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(3);                     // filtest_impl::chain76_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(3).getT(0);      // filtest_impl::global_cable16_t<NV>
		auto& add45 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(3).getT(1);               // math::add<NV>
		auto& chain77 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(4);                     // filtest_impl::chain77_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(4).getT(0);      // filtest_impl::global_cable17_t<NV>
		auto& add46 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(4).getT(1);               // math::add<NV>
		auto& chain80 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(5);                     // filtest_impl::chain80_t<NV>
		auto& add49 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(5).getT(0);               // math::add<NV>
		auto& chain81 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(6);                     // filtest_impl::chain81_t<NV>
		auto& add50 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(6).getT(0);               // math::add<NV>
		auto& chain82 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(7);                     // filtest_impl::chain82_t<NV>
		auto& add51 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(7).getT(0);               // math::add<NV>
		auto& chain152 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(8);                    // filtest_impl::chain152_t<NV>
		auto& add115 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(8).getT(0);              // math::add<NV>
		auto& chain151 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(9);                    // filtest_impl::chain151_t<NV>
		auto& add114 = this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(9).getT(0);              // math::add<NV>
		auto& peak6 = this->getT(0).getT(0).getT(2).getT(5).getT(1);                               // filtest_impl::peak6_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(2).getT(5).getT(2);                                // filtest_impl::pma6_t<NV>
		auto& clear8 = this->getT(0).getT(0).getT(2).getT(5).getT(3);                              // math::clear<NV>
		auto& chain84 = this->getT(0).getT(0).getT(2).getT(6);                                     // filtest_impl::chain84_t<NV>
		auto& branch11 = this->getT(0).getT(0).getT(2).getT(6).getT(0);                            // filtest_impl::branch11_t<NV>
		auto& chain85 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(0);                     // filtest_impl::chain85_t<NV>
		auto& add52 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(0).getT(0);               // math::add<NV>
		auto& chain86 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(1);                     // filtest_impl::chain86_t<NV>
		auto& add53 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(1).getT(0);               // math::add<NV>
		auto& chain159 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(2);                    // filtest_impl::chain159_t<NV>
		auto& add139 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(2).getT(0);              // math::add<NV>
		auto& chain87 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(3);                     // filtest_impl::chain87_t<NV>
		auto& global_cable20 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(3).getT(0);      // filtest_impl::global_cable20_t<NV>
		auto& add54 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(3).getT(1);               // math::add<NV>
		auto& chain88 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(4);                     // filtest_impl::chain88_t<NV>
		auto& global_cable21 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(4).getT(0);      // filtest_impl::global_cable21_t<NV>
		auto& add55 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(4).getT(1);               // math::add<NV>
		auto& chain91 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(5);                     // filtest_impl::chain91_t<NV>
		auto& add58 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(5).getT(0);               // math::add<NV>
		auto& chain92 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(6);                     // filtest_impl::chain92_t<NV>
		auto& add59 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(6).getT(0);               // math::add<NV>
		auto& chain93 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(7);                     // filtest_impl::chain93_t<NV>
		auto& add60 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(7).getT(0);               // math::add<NV>
		auto& chain150 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(8);                    // filtest_impl::chain150_t<NV>
		auto& add113 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(8).getT(0);              // math::add<NV>
		auto& chain149 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(9);                    // filtest_impl::chain149_t<NV>
		auto& add112 = this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(9).getT(0);              // math::add<NV>
		auto& peak7 = this->getT(0).getT(0).getT(2).getT(6).getT(1);                               // filtest_impl::peak7_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(2).getT(6).getT(2);                                // filtest_impl::pma7_t<NV>
		auto& clear9 = this->getT(0).getT(0).getT(2).getT(6).getT(3);                              // math::clear<NV>
		auto& chain104 = this->getT(0).getT(0).getT(2).getT(7);                                    // filtest_impl::chain104_t<NV>
		auto& branch13 = this->getT(0).getT(0).getT(2).getT(7).getT(0);                            // filtest_impl::branch13_t<NV>
		auto& chain105 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(0);                    // filtest_impl::chain105_t<NV>
		auto& add70 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(0).getT(0);               // math::add<NV>
		auto& chain106 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(1);                    // filtest_impl::chain106_t<NV>
		auto& add71 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(1).getT(0);               // math::add<NV>
		auto& chain116 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(2);                    // filtest_impl::chain116_t<NV>
		auto& add81 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(2).getT(0);               // math::add<NV>
		auto& chain107 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(3);                    // filtest_impl::chain107_t<NV>
		auto& global_cable28 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(3).getT(0);      // filtest_impl::global_cable28_t<NV>
		auto& add72 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(3).getT(1);               // math::add<NV>
		auto& chain108 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(4);                    // filtest_impl::chain108_t<NV>
		auto& global_cable29 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(4).getT(0);      // filtest_impl::global_cable29_t<NV>
		auto& add73 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(4).getT(1);               // math::add<NV>
		auto& chain111 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(5);                    // filtest_impl::chain111_t<NV>
		auto& add76 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(5).getT(0);               // math::add<NV>
		auto& chain112 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(6);                    // filtest_impl::chain112_t<NV>
		auto& add77 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(6).getT(0);               // math::add<NV>
		auto& chain113 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(7);                    // filtest_impl::chain113_t<NV>
		auto& add78 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(7).getT(0);               // math::add<NV>
		auto& chain148 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(8);                    // filtest_impl::chain148_t<NV>
		auto& add111 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(8).getT(0);              // math::add<NV>
		auto& chain147 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(9);                    // filtest_impl::chain147_t<NV>
		auto& add110 = this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(9).getT(0);              // math::add<NV>
		auto& peak9 = this->getT(0).getT(0).getT(2).getT(7).getT(1);                               // filtest_impl::peak9_t<NV>
		auto& pma9 = this->getT(0).getT(0).getT(2).getT(7).getT(2);                                // filtest_impl::pma9_t<NV>
		auto& clear11 = this->getT(0).getT(0).getT(2).getT(7).getT(3);                             // math::clear<NV>
		auto& chain94 = this->getT(0).getT(0).getT(2).getT(8);                                     // filtest_impl::chain94_t<NV>
		auto& branch12 = this->getT(0).getT(0).getT(2).getT(8).getT(0);                            // filtest_impl::branch12_t<NV>
		auto& chain95 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(0);                     // filtest_impl::chain95_t<NV>
		auto& add61 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(0).getT(0);               // math::add<NV>
		auto& chain96 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(1);                     // filtest_impl::chain96_t<NV>
		auto& add62 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(1).getT(0);               // math::add<NV>
		auto& chain117 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(2);                    // filtest_impl::chain117_t<NV>
		auto& add82 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(2).getT(0);               // math::add<NV>
		auto& chain97 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(3);                     // filtest_impl::chain97_t<NV>
		auto& global_cable24 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(3).getT(0);      // filtest_impl::global_cable24_t<NV>
		auto& add63 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(3).getT(1);               // math::add<NV>
		auto& chain98 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(4);                     // filtest_impl::chain98_t<NV>
		auto& global_cable25 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(4).getT(0);      // filtest_impl::global_cable25_t<NV>
		auto& add64 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(4).getT(1);               // math::add<NV>
		auto& chain101 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(5);                    // filtest_impl::chain101_t<NV>
		auto& add67 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(5).getT(0);               // math::add<NV>
		auto& chain102 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(6);                    // filtest_impl::chain102_t<NV>
		auto& add68 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(6).getT(0);               // math::add<NV>
		auto& chain103 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(7);                    // filtest_impl::chain103_t<NV>
		auto& add69 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(7).getT(0);               // math::add<NV>
		auto& chain146 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(8);                    // filtest_impl::chain146_t<NV>
		auto& add109 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(8).getT(0);              // math::add<NV>
		auto& chain145 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(9);                    // filtest_impl::chain145_t<NV>
		auto& add108 = this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(9).getT(0);              // math::add<NV>
		auto& peak8 = this->getT(0).getT(0).getT(2).getT(8).getT(1);                               // filtest_impl::peak8_t<NV>
		auto& pma8 = this->getT(0).getT(0).getT(2).getT(8).getT(2);                                // filtest_impl::pma8_t<NV>
		auto& clear10 = this->getT(0).getT(0).getT(2).getT(8).getT(3);                             // math::clear<NV>
		auto& chain99 = this->getT(0).getT(0).getT(2).getT(9);                                     // filtest_impl::chain99_t<NV>
		auto& branch16 = this->getT(0).getT(0).getT(2).getT(9).getT(0);                            // filtest_impl::branch16_t<NV>
		auto& chain100 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(0);                    // filtest_impl::chain100_t<NV>
		auto& add65 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(0).getT(0);               // math::add<NV>
		auto& chain109 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(1);                    // filtest_impl::chain109_t<NV>
		auto& add66 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(1).getT(0);               // math::add<NV>
		auto& chain124 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(2);                    // filtest_impl::chain124_t<NV>
		auto& add88 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(2).getT(0);               // math::add<NV>
		auto& chain110 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(3);                    // filtest_impl::chain110_t<NV>
		auto& global_cable26 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(3).getT(0);      // filtest_impl::global_cable26_t<NV>
		auto& add74 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(3).getT(1);               // math::add<NV>
		auto& chain125 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(4);                    // filtest_impl::chain125_t<NV>
		auto& global_cable27 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(4).getT(0);      // filtest_impl::global_cable27_t<NV>
		auto& add75 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(4).getT(1);               // math::add<NV>
		auto& chain135 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(5);                    // filtest_impl::chain135_t<NV>
		auto& add89 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(5).getT(0);               // math::add<NV>
		auto& chain136 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(6);                    // filtest_impl::chain136_t<NV>
		auto& add98 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(6).getT(0);               // math::add<NV>
		auto& chain142 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(7);                    // filtest_impl::chain142_t<NV>
		auto& add99 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(7).getT(0);               // math::add<NV>
		auto& chain156 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(8);                    // filtest_impl::chain156_t<NV>
		auto& add118 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(8).getT(0);              // math::add<NV>
		auto& chain157 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(9);                    // filtest_impl::chain157_t<NV>
		auto& add119 = this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(9).getT(0);              // math::add<NV>
		auto& peak14 = this->getT(0).getT(0).getT(2).getT(9).getT(1);                              // filtest_impl::peak14_t<NV>
		auto& pma13 = this->getT(0).getT(0).getT(2).getT(9).getT(2);                               // filtest_impl::pma13_t<NV>
		auto& clear14 = this->getT(0).getT(0).getT(2).getT(9).getT(3);                             // math::clear<NV>
		auto& chain118 = this->getT(0).getT(0).getT(2).getT(10);                                   // filtest_impl::chain118_t<NV>
		auto& branch14 = this->getT(0).getT(0).getT(2).getT(10).getT(0);                           // filtest_impl::branch14_t<NV>
		auto& chain119 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(0);                   // filtest_impl::chain119_t<NV>
		auto& add83 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(0).getT(0);              // math::add<NV>
		auto& chain120 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(1);                   // filtest_impl::chain120_t<NV>
		auto& add84 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(1).getT(0);              // math::add<NV>
		auto& chain121 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(2);                   // filtest_impl::chain121_t<NV>
		auto& add85 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(2).getT(0);              // math::add<NV>
		auto& chain122 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(3);                   // filtest_impl::chain122_t<NV>
		auto& global_cable32 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(3).getT(0);     // filtest_impl::global_cable32_t<NV>
		auto& add86 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(3).getT(1);              // math::add<NV>
		auto& chain123 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(4);                   // filtest_impl::chain123_t<NV>
		auto& global_cable33 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(4).getT(0);     // filtest_impl::global_cable33_t<NV>
		auto& add87 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(4).getT(1);              // math::add<NV>
		auto& chain126 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(5);                   // filtest_impl::chain126_t<NV>
		auto& add90 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(5).getT(0);              // math::add<NV>
		auto& chain127 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(6);                   // filtest_impl::chain127_t<NV>
		auto& add91 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(6).getT(0);              // math::add<NV>
		auto& chain128 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(7);                   // filtest_impl::chain128_t<NV>
		auto& add92 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(7).getT(0);              // math::add<NV>
		auto& chain140 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(8);                   // filtest_impl::chain140_t<NV>
		auto& add103 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(8).getT(0);             // math::add<NV>
		auto& chain141 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(9);                   // filtest_impl::chain141_t<NV>
		auto& add104 = this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(9).getT(0);             // math::add<NV>
		auto& peak10 = this->getT(0).getT(0).getT(2).getT(10).getT(1);                             // filtest_impl::peak10_t<NV>
		auto& pma11 = this->getT(0).getT(0).getT(2).getT(10).getT(2);                              // filtest_impl::pma11_t<NV>
		auto& clear12 = this->getT(0).getT(0).getT(2).getT(10).getT(3);                            // math::clear<NV>
		auto& chain129 = this->getT(0).getT(0).getT(2).getT(11);                                   // filtest_impl::chain129_t<NV>
		auto& branch15 = this->getT(0).getT(0).getT(2).getT(11).getT(0);                           // filtest_impl::branch15_t<NV>
		auto& chain130 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(0);                   // filtest_impl::chain130_t<NV>
		auto& add93 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(0).getT(0);              // math::add<NV>
		auto& chain131 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(1);                   // filtest_impl::chain131_t<NV>
		auto& add94 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(1).getT(0);              // math::add<NV>
		auto& chain132 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(2);                   // filtest_impl::chain132_t<NV>
		auto& add95 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(2).getT(0);              // math::add<NV>
		auto& chain133 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(3);                   // filtest_impl::chain133_t<NV>
		auto& global_cable36 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(3).getT(0);     // filtest_impl::global_cable36_t<NV>
		auto& add96 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(3).getT(1);              // math::add<NV>
		auto& chain134 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(4);                   // filtest_impl::chain134_t<NV>
		auto& global_cable37 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(4).getT(0);     // filtest_impl::global_cable37_t<NV>
		auto& add97 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(4).getT(1);              // math::add<NV>
		auto& chain137 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(5);                   // filtest_impl::chain137_t<NV>
		auto& add100 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(5).getT(0);             // math::add<NV>
		auto& chain138 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(6);                   // filtest_impl::chain138_t<NV>
		auto& add101 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(6).getT(0);             // math::add<NV>
		auto& chain139 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(7);                   // filtest_impl::chain139_t<NV>
		auto& add102 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(7).getT(0);             // math::add<NV>
		auto& chain144 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(8);                   // filtest_impl::chain144_t<NV>
		auto& add107 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(8).getT(0);             // math::add<NV>
		auto& chain143 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(9);                   // filtest_impl::chain143_t<NV>
		auto& add106 = this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(9).getT(0);             // math::add<NV>
		auto& peak11 = this->getT(0).getT(0).getT(2).getT(11).getT(1);                             // filtest_impl::peak11_t<NV>
		auto& pma12 = this->getT(0).getT(0).getT(2).getT(11).getT(2);                              // filtest_impl::pma12_t<NV>
		auto& clear13 = this->getT(0).getT(0).getT(2).getT(11).getT(3);                            // math::clear<NV>
		auto& chain53 = this->getT(0).getT(1);                                                     // filtest_impl::chain53_t<NV>
		auto& chain158 = this->getT(0).getT(1).getT(0);                                            // filtest_impl::chain158_t<NV>
		auto& tempo_sync = this->getT(0).getT(1).getT(0).getT(0);                                  // filtest_impl::tempo_sync_t<NV>
		auto& converter = this->getT(0).getT(1).getT(0).getT(1);                                   // filtest_impl::converter_t<NV>
		auto& input_toggle = this->getT(0).getT(1).getT(0).getT(2);                                // filtest_impl::input_toggle_t<NV>
		auto& smoothed_parameter3 = this->getT(0).getT(1).getT(1);                                 // filtest_impl::smoothed_parameter3_t<NV>
		auto& xfader2 = this->getT(0).getT(1).getT(2);                                             // filtest_impl::xfader2_t<NV>
		auto& frame2_block1 = this->getT(0).getT(1).getT(3);                                       // filtest_impl::frame2_block1_t<NV>
		auto& midi5 = this->getT(0).getT(1).getT(3).getT(0);                                       // filtest_impl::midi5_t<NV>
		auto& smoothed_parameter_unscaled = this->getT(0).getT(1).getT(3).getT(1);                 // filtest_impl::smoothed_parameter_unscaled_t<NV>
		auto& converter1 = this->getT(0).getT(1).getT(3).getT(2);                                  // filtest_impl::converter1_t<NV>
		auto& split3 = this->getT(0).getT(1).getT(3).getT(3);                                      // filtest_impl::split3_t<NV>
		auto& chain192 = this->getT(0).getT(1).getT(3).getT(3).getT(0);                            // filtest_impl::chain192_t<NV>
		auto& chain48 = this->getT(0).getT(1).getT(3).getT(3).getT(0).getT(0);                     // filtest_impl::chain48_t<NV>
		auto& split9 = this->getT(0).getT(1).getT(3).getT(3).getT(0).getT(0).getT(0);              // filtest_impl::split9_t<NV>
		auto& pma3 = this->getT(0).getT(1).getT(3).getT(3).                                        // filtest_impl::pma3_t<NV>
                     getT(0).getT(0).getT(0).getT(0);
		auto& pma4 = this->getT(0).getT(1).getT(3).getT(3).                                        // filtest_impl::pma4_t<NV>
                     getT(0).getT(0).getT(0).getT(1);
		auto& split19 = this->getT(0).getT(1).getT(3).getT(3).getT(0).getT(0).getT(1);             // filtest_impl::split19_t<NV>
		auto& pma5 = this->getT(0).getT(1).getT(3).getT(3).                                        // filtest_impl::pma5_t<NV>
                     getT(0).getT(0).getT(1).getT(0);
		auto& pma10 = this->getT(0).getT(1).getT(3).getT(3).                                       // filtest_impl::pma10_t<NV>
                      getT(0).getT(0).getT(1).getT(1);
		auto& minmax14 = this->getT(0).getT(1).getT(3).getT(3).getT(0).getT(0).getT(2);            // control::minmax<NV, parameter::empty>
		auto& no_midi2 = this->getT(0).getT(1).getT(3).getT(3).getT(0).getT(0).getT(3);            // filtest_impl::no_midi2_t<NV>
		auto& oscillator8 = this->getT(0).getT(1).getT(3).getT(3).                                 // filtest_impl::oscillator8_t<NV>
                            getT(0).getT(0).getT(3).getT(0);
		auto& gain5 = this->getT(0).getT(1).getT(3).getT(3).getT(0).getT(1);                       // core::gain<NV>
		auto& chain193 = this->getT(0).getT(1).getT(3).getT(3).getT(1);                            // filtest_impl::chain193_t<NV>
		auto& pma19 = this->getT(0).getT(1).getT(3).getT(3).getT(1).getT(0);                       // filtest_impl::pma19_t<NV>
		auto& minmax7 = this->getT(0).getT(1).getT(3).getT(3).getT(1).getT(1);                     // filtest_impl::minmax7_t<NV>
		auto& no_midi3 = this->getT(0).getT(1).getT(3).getT(3).getT(1).getT(2);                    // filtest_impl::no_midi3_t<NV>
		auto& oscillator1 = this->getT(0).getT(1).getT(3).getT(3).getT(1).getT(2).getT(0);         // filtest_impl::oscillator1_t<NV>
		auto& peak17 = this->getT(0).getT(1).getT(3).getT(3).getT(1).getT(3);                      // filtest_impl::peak17_t<NV>
		auto& pi1 = this->getT(0).getT(1).getT(3).getT(3).getT(1).getT(4);                         // math::pi<NV>
		auto& sub = this->getT(0).getT(1).getT(3).getT(3).getT(1).getT(5);                         // math::sub<NV>
		auto& sub1 = this->getT(0).getT(1).getT(3).getT(3).getT(1).getT(6);                        // math::sub<NV>
		auto& gain = this->getT(0).getT(1).getT(3).getT(3).getT(1).getT(7);                        // wrap::no_process<core::gain<NV>>
		auto& gain6 = this->getT(0).getT(1).getT(3).getT(3).getT(1).getT(8);                       // core::gain<NV>
		auto& send5 = this->getT(0).getT(1).getT(3).getT(3).getT(1).getT(9);                       // routing::send<stereo_frame_cable>
		auto& branch5 = this->getT(0).getT(1).getT(4);                                             // filtest_impl::branch5_t<NV>
		auto& chain31 = this->getT(0).getT(1).getT(4).getT(0);                                     // filtest_impl::chain31_t
		auto& chain33 = this->getT(0).getT(1).getT(4).getT(1);                                     // filtest_impl::chain33_t<NV>
		auto& branch6 = this->getT(0).getT(1).getT(4).getT(1).getT(0);                             // filtest_impl::branch6_t<NV>
		auto& chain36 = this->getT(0).getT(1).getT(4).getT(1).getT(0).getT(0);                     // filtest_impl::chain36_t
		auto& sampleandhold = this->getT(0).getT(1).getT(4).getT(1).getT(0).getT(1);               // fx::sampleandhold<NV>
		auto& chain207 = this->getT(0).getT(1).getT(4).getT(2);                                    // filtest_impl::chain207_t<NV>
		auto& chain42 = this->getT(0).getT(1).getT(4).getT(2).getT(0);                             // filtest_impl::chain42_t<NV>
		auto& smoothed_parameter2 = this->getT(0).getT(1).getT(4).getT(2).getT(0).getT(0);         // filtest_impl::smoothed_parameter2_t<NV>
		auto& branch17 = this->getT(0).getT(1).getT(4).getT(2).getT(0).getT(1);                    // filtest_impl::branch17_t<NV>
		auto& add131 = this->getT(0).getT(1).getT(4).getT(2).getT(0).getT(1).getT(0);              // math::add<NV>
		auto& add132 = this->getT(0).getT(1).getT(4).getT(2).getT(0).getT(1).getT(1);              // math::add<NV>
		auto& add133 = this->getT(0).getT(1).getT(4).getT(2).getT(0).getT(1).getT(2);              // math::add<NV>
		auto& add134 = this->getT(0).getT(1).getT(4).getT(2).getT(0).getT(1).getT(3);              // math::add<NV>
		auto& add135 = this->getT(0).getT(1).getT(4).getT(2).getT(0).getT(1).getT(4);              // math::add<NV>
		auto& add136 = this->getT(0).getT(1).getT(4).getT(2).getT(0).getT(1).getT(5);              // math::add<NV>
		auto& add137 = this->getT(0).getT(1).getT(4).getT(2).getT(0).getT(1).getT(6);              // math::add<NV>
		auto& add138 = this->getT(0).getT(1).getT(4).getT(2).getT(0).getT(1).getT(7);              // math::add<NV>
		auto& split13 = this->getT(0).getT(1).getT(4).getT(2).getT(0).getT(2);                     // filtest_impl::split13_t<NV>
		auto& smoother12 = this->getT(0).getT(1).getT(4).getT(2).getT(0).getT(2).getT(0);          // core::smoother<NV>
		auto& smoother13 = this->getT(0).getT(1).getT(4).getT(2).getT(0).getT(2).getT(1);          // core::smoother<NV>
		auto& file_player6 = this->getT(0).getT(1).getT(4).getT(2).getT(0).getT(3);                // filtest_impl::file_player6_t<NV>
		auto& split1 = this->getT(0).getT(2);                                                      // filtest_impl::split1_t<NV>
		auto& chain4 = this->getT(0).getT(2).getT(0);                                              // filtest_impl::chain4_t
		auto& chain5 = this->getT(0).getT(2).getT(1);                                              // filtest_impl::chain5_t<NV>
		auto& send = this->getT(0).getT(2).getT(1).getT(0);                                        // routing::send<stereo_cable>
		auto& clear3 = this->getT(0).getT(2).getT(1).getT(1);                                      // math::clear<NV>
		auto& midi4 = this->getT(0).getT(3);                                                       // filtest_impl::midi4_t<NV>
		auto& chain20 = this->getT(0).getT(4);                                                     // filtest_impl::chain20_t<NV>
		auto& soft_bypass = this->getT(0).getT(4).getT(0);                                         // filtest_impl::soft_bypass_t<NV>
		auto& chain7 = this->getT(0).getT(4).getT(0).getT(0);                                      // filtest_impl::chain7_t<NV>
		auto& xfader = this->getT(0).getT(4).getT(0).getT(0).getT(0);                              // filtest_impl::xfader_t<NV>
		auto& split = this->getT(0).getT(4).getT(0).getT(0).getT(1);                               // filtest_impl::split_t<NV>
		auto& chain = this->getT(0).getT(4).getT(0).getT(0).getT(1).getT(0);                       // filtest_impl::chain_t<NV>
		auto& gain1 = this->getT(0).getT(4).getT(0).getT(0).getT(1).getT(0).getT(0);               // core::gain<NV>
		auto& chain1 = this->getT(0).getT(4).getT(0).getT(0).getT(1).getT(1);                      // filtest_impl::chain1_t<NV>
		auto& smoothed_parameter1 = this->getT(0).getT(4).getT(0).getT(0).getT(1).getT(1).getT(0); // filtest_impl::smoothed_parameter1_t<NV>
		auto& branch3 = this->getT(0).getT(4).getT(0).getT(0).getT(1).getT(1).getT(1);             // filtest_impl::branch3_t<NV>
		auto& chain12 = this->getT(0).getT(4).getT(0).getT(0).                                     // filtest_impl::chain12_t<NV>
                        getT(1).getT(1).getT(1).getT(0);
		auto& expr = this->getT(0).getT(4).getT(0).getT(0).                            // math::expr<NV, custom::expr>
                     getT(1).getT(1).getT(1).getT(0).
                     getT(0);
		auto& split2 = this->getT(0).getT(4).getT(0).getT(0).                          // filtest_impl::split2_t<NV>
                       getT(1).getT(1).getT(1).getT(0).
                       getT(1);
		auto& smoother = this->getT(0).getT(4).getT(0).getT(0).getT(1).                // core::smoother<NV>
                         getT(1).getT(1).getT(0).getT(1).getT(0);
		auto& smoother3 = this->getT(0).getT(4).getT(0).getT(0).getT(1).               // core::smoother<NV>
                          getT(1).getT(1).getT(0).getT(1).getT(1);
		auto& chain197 = this->getT(0).getT(4).getT(0).getT(0).                        // filtest_impl::chain197_t<NV>
                         getT(1).getT(1).getT(1).getT(1);
		auto& mul6 = this->getT(0).getT(4).getT(0).getT(0).                            // math::mul<NV>
                     getT(1).getT(1).getT(1).getT(1).
                     getT(0);
		auto& pi = this->getT(0).getT(4).getT(0).getT(0).                              // math::pi<NV>
                   getT(1).getT(1).getT(1).getT(1).
                   getT(1);
		auto& split4 = this->getT(0).getT(4).getT(0).getT(0).                          // filtest_impl::split4_t<NV>
                       getT(1).getT(1).getT(1).getT(1).
                       getT(2);
		auto& smoother1 = this->getT(0).getT(4).getT(0).getT(0).getT(1).               // core::smoother<NV>
                          getT(1).getT(1).getT(1).getT(2).getT(0);
		auto& smoother4 = this->getT(0).getT(4).getT(0).getT(0).getT(1).               // core::smoother<NV>
                          getT(1).getT(1).getT(1).getT(2).getT(1);
		auto& chain199 = this->getT(0).getT(4).getT(0).getT(0).                        // filtest_impl::chain199_t<NV>
                         getT(1).getT(1).getT(1).getT(2);
		auto& pi2 = this->getT(0).getT(4).getT(0).getT(0).                             // math::pi<NV>
                    getT(1).getT(1).getT(1).getT(2).
                    getT(0);
		auto& sub2 = this->getT(0).getT(4).getT(0).getT(0).                            // math::sub<NV>
                     getT(1).getT(1).getT(1).getT(2).
                     getT(1);
		auto& fmod = this->getT(0).getT(4).getT(0).getT(0).                            // wrap::no_process<math::fmod<NV>>
                     getT(1).getT(1).getT(1).getT(2).
                     getT(2);
		auto& chain200 = this->getT(0).getT(4).getT(0).getT(0).                        // filtest_impl::chain200_t<NV>
                         getT(1).getT(1).getT(1).getT(3);
		auto& pi3 = this->getT(0).getT(4).getT(0).getT(0).                             // math::pi<NV>
                    getT(1).getT(1).getT(1).getT(3).
                    getT(0);
		auto& sub3 = this->getT(0).getT(4).getT(0).getT(0).                            // math::sub<NV>
                     getT(1).getT(1).getT(1).getT(3).
                     getT(1);
		auto& fmod1 = this->getT(0).getT(4).getT(0).getT(0).                           // math::fmod<NV>
                      getT(1).getT(1).getT(1).getT(3).
                      getT(2);
		auto& chain17 = this->getT(0).getT(4).getT(0).getT(0).                         // filtest_impl::chain17_t<NV>
                        getT(1).getT(1).getT(1).getT(4);
		auto& no_midi = this->getT(0).getT(4).getT(0).getT(0).                         // filtest_impl::no_midi_t<NV>
                        getT(1).getT(1).getT(1).getT(4).
                        getT(0);
		auto& ring_mod2 = this->getT(0).getT(4).getT(0).getT(0).getT(1).               // filters::ring_mod<NV>
                          getT(1).getT(1).getT(4).getT(0).getT(0);
		auto& chain14 = this->getT(0).getT(4).getT(0).getT(0).                         // filtest_impl::chain14_t<NV>
                        getT(1).getT(1).getT(1).getT(5);
		auto& cable_table = this->getT(0).getT(4).getT(0).getT(0).                     // filtest_impl::cable_table_t<NV>
                            getT(1).getT(1).getT(1).getT(5).
                            getT(0);
		auto& faust2 = this->getT(0).getT(4).getT(0).getT(0).                          // project::Comb<NV>
                       getT(1).getT(1).getT(1).getT(5).
                       getT(1);
		auto& chain27 = this->getT(0).getT(4).getT(0).getT(0).                         // filtest_impl::chain27_t<NV>
                        getT(1).getT(1).getT(1).getT(6);
		auto& svf_eq = this->getT(0).getT(4).getT(0).getT(0).                          // filters::svf_eq<NV>
                       getT(1).getT(1).getT(1).getT(6).
                       getT(0);
		auto& chain155 = this->getT(0).getT(4).getT(0).getT(0).                        // filtest_impl::chain155_t<NV>
                         getT(1).getT(1).getT(1).getT(7);
		auto& svf_eq3 = this->getT(0).getT(4).getT(0).getT(0).                         // filters::svf_eq<NV>
                        getT(1).getT(1).getT(1).getT(7).
                        getT(0);
		auto& chain16 = this->getT(0).getT(4).getT(0).getT(0).                         // filtest_impl::chain16_t<NV>
                        getT(1).getT(1).getT(1).getT(8);
		auto& div2 = this->getT(0).getT(4).getT(0).getT(0).                            // math::div<NV>
                     getT(1).getT(1).getT(1).getT(8).
                     getT(0);
		auto& split10 = this->getT(0).getT(4).getT(0).getT(0).                         // filtest_impl::split10_t<NV>
                        getT(1).getT(1).getT(1).getT(8).
                        getT(1);
		auto& smoother6 = this->getT(0).getT(4).getT(0).getT(0).getT(1).               // core::smoother<NV>
                          getT(1).getT(1).getT(8).getT(1).getT(0);
		auto& smoother7 = this->getT(0).getT(4).getT(0).getT(0).getT(1).               // core::smoother<NV>
                          getT(1).getT(1).getT(8).getT(1).getT(1);
		auto& chain52 = this->getT(0).getT(4).getT(0).getT(0).                         // filtest_impl::chain52_t<NV>
                        getT(1).getT(1).getT(1).getT(9);
		auto& phasor_fm = this->getT(0).getT(4).getT(0).getT(0).                       // wrap::no_process<core::phasor_fm<NV>>
                          getT(1).getT(1).getT(1).getT(9).
                          getT(0);
		auto& fm = this->getT(0).getT(4).getT(0).getT(0).                              // core::fm
                   getT(1).getT(1).getT(1).getT(9).
                   getT(1);
		auto& mono2stereo = this->getT(0).getT(4).getT(0).getT(0).                     // core::mono2stereo
                            getT(1).getT(1).getT(1).getT(9).
                            getT(2);
		auto& tanh1 = this->getT(0).getT(4).getT(0).getT(0).                           // math::tanh<NV>
                      getT(1).getT(1).getT(1).getT(9).
                      getT(3);
		auto& chain54 = this->getT(0).getT(4).getT(0).getT(0).                         // filtest_impl::chain54_t<NV>
                        getT(1).getT(1).getT(1).getT(10);
		auto& tempo_sync1 = this->getT(0).getT(4).getT(0).getT(0).                     // filtest_impl::tempo_sync1_t<NV>
                            getT(1).getT(1).getT(1).getT(10).
                            getT(0);
		auto& sampleandhold1 = this->getT(0).getT(4).getT(0).getT(0).                  // fx::sampleandhold<NV>
                               getT(1).getT(1).getT(1).getT(10).
                               getT(1);
		auto& chain55 = this->getT(0).getT(4).getT(0).getT(0).                         // filtest_impl::chain55_t<NV>
                        getT(1).getT(1).getT(1).getT(11);
		auto& bitcrush = this->getT(0).getT(4).getT(0).getT(0).                        // fx::bitcrush<NV>
                         getT(1).getT(1).getT(1).getT(11).
                         getT(0);
		auto& split11 = this->getT(0).getT(4).getT(0).getT(0).                         // filtest_impl::split11_t<NV>
                        getT(1).getT(1).getT(1).getT(11).
                        getT(1);
		auto& smoother8 = this->getT(0).getT(4).getT(0).getT(0).getT(1).               // core::smoother<NV>
                          getT(1).getT(1).getT(11).getT(1).getT(0);
		auto& smoother9 = this->getT(0).getT(4).getT(0).getT(0).getT(1).               // core::smoother<NV>
                          getT(1).getT(1).getT(11).getT(1).getT(1);
		auto& gain2 = this->getT(0).getT(4).getT(0).getT(0).getT(1).getT(1).getT(2);   // core::gain<NV>
		auto& chain68 = this->getT(0).getT(5);                                         // filtest_impl::chain68_t<NV>
		auto& chain11 = this->getT(0).getT(5).getT(0);                                 // filtest_impl::chain11_t<NV>
		auto& gain3 = this->getT(0).getT(5).getT(0).getT(0);                           // core::gain<NV>
		auto& chain21 = this->getT(0).getT(5).getT(0).getT(1);                         // filtest_impl::chain21_t<NV>
		auto& smoothed_parameter = this->getT(0).getT(5).getT(0).getT(1).getT(0);      // filtest_impl::smoothed_parameter_t<NV>
		auto& multi = this->getT(0).getT(5).getT(0).getT(1).getT(1);                   // filtest_impl::multi_t<NV>
		auto& smoother10 = this->getT(0).getT(5).getT(0).getT(1).getT(1).getT(0);      // core::smoother<NV>
		auto& smoother11 = this->getT(0).getT(5).getT(0).getT(1).getT(1).getT(1);      // core::smoother<NV>
		auto& chain8 = this->getT(0).getT(5).getT(0).getT(1).getT(2);                  // filtest_impl::chain8_t<NV>
		auto& branch8 = this->getT(0).getT(5).getT(0).getT(1).getT(2).getT(0);         // filtest_impl::branch8_t<NV>
		auto& add1 = this->getT(0).getT(5).getT(0).getT(1).getT(2).getT(0).getT(0);    // math::add<NV>
		auto& chain6 = this->getT(0).getT(5).getT(0).getT(1).getT(2).getT(0).getT(1);  // filtest_impl::chain6_t<NV>
		auto& minmax3 = this->getT(0).getT(5).getT(0).getT(1).                         // filtest_impl::minmax3_t<NV>
                        getT(2).getT(0).getT(1).getT(0);
		auto& map6 = this->getT(0).getT(5).getT(0).getT(1).                            // wrap::no_process<math::map>
                     getT(2).getT(0).getT(1).getT(1);
		auto& add125 = this->getT(0).getT(5).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(0).getT(1).getT(2);
		auto& chain89 = this->getT(0).getT(5).getT(0).getT(1).getT(2).getT(0).getT(2); // filtest_impl::chain89_t<NV>
		auto& minmax12 = this->getT(0).getT(5).getT(0).getT(1).                        // filtest_impl::minmax12_t<NV>
                         getT(2).getT(0).getT(2).getT(0);
		auto& add126 = this->getT(0).getT(5).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(0).getT(2).getT(1);
		auto& map5 = this->getT(0).getT(5).getT(0).getT(1).                            // wrap::no_process<math::map>
                     getT(2).getT(0).getT(2).getT(2);
		auto& chain83 = this->getT(0).getT(5).getT(0).getT(1).getT(2).getT(0).getT(3); // filtest_impl::chain83_t<NV>
		auto& minmax10 = this->getT(0).getT(5).getT(0).getT(1).                        // filtest_impl::minmax10_t<NV>
                         getT(2).getT(0).getT(3).getT(0);
		auto& add127 = this->getT(0).getT(5).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(0).getT(3).getT(1);
		auto& map4 = this->getT(0).getT(5).getT(0).getT(1).                            // wrap::no_process<math::map>
                     getT(2).getT(0).getT(3).getT(2);
		auto& chain79 = this->getT(0).getT(5).getT(0).getT(1).getT(2).getT(0).getT(4); // filtest_impl::chain79_t<NV>
		auto& minmax9 = this->getT(0).getT(5).getT(0).getT(1).                         // filtest_impl::minmax9_t<NV>
                        getT(2).getT(0).getT(4).getT(0);
		auto& add128 = this->getT(0).getT(5).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(0).getT(4).getT(1);
		auto& map3 = this->getT(0).getT(5).getT(0).getT(1).                            // wrap::no_process<math::map>
                     getT(2).getT(0).getT(4).getT(2);
		auto& chain78 = this->getT(0).getT(5).getT(0).getT(1).getT(2).getT(0).getT(5); // filtest_impl::chain78_t<NV>
		auto& minmax8 = this->getT(0).getT(5).getT(0).getT(1).                         // filtest_impl::minmax8_t<NV>
                        getT(2).getT(0).getT(5).getT(0);
		auto& map2 = this->getT(0).getT(5).getT(0).getT(1).                            // wrap::no_process<math::map>
                     getT(2).getT(0).getT(5).getT(1);
		auto& add129 = this->getT(0).getT(5).getT(0).getT(1).                          // math::add<NV>
                       getT(2).getT(0).getT(5).getT(2);
		auto& chain43 = this->getT(0).getT(5).getT(0).getT(1).getT(2).getT(0).getT(6); // filtest_impl::chain43_t<NV>
		auto& minmax4 = this->getT(0).getT(5).getT(0).getT(1).                         // filtest_impl::minmax4_t<NV>
                        getT(2).getT(0).getT(6).getT(0);
		auto& add2 = this->getT(0).getT(5).getT(0).getT(1).                            // math::add<NV>
                     getT(2).getT(0).getT(6).getT(1);
		auto& add130 = this->getT(0).getT(5).getT(0).getT(1).                          // wrap::no_process<math::add<NV>>
                       getT(2).getT(0).getT(6).getT(2);
		auto& chain90 = this->getT(0).getT(5).getT(0).getT(1).getT(2).getT(0).getT(7); // filtest_impl::chain90_t<NV>
		auto& minmax13 = this->getT(0).getT(5).getT(0).getT(1).                        // filtest_impl::minmax13_t<NV>
                         getT(2).getT(0).getT(7).getT(0);
		auto& map1 = this->getT(0).getT(5).getT(0).getT(1).                 // wrap::no_process<math::map>
                     getT(2).getT(0).getT(7).getT(1);
		auto& add3 = this->getT(0).getT(5).getT(0).getT(1).                 // math::add<NV>
                     getT(2).getT(0).getT(7).getT(2);
		auto& mono2stereo1 = this->getT(0).getT(5).getT(0).getT(2);         // wrap::no_process<core::mono2stereo>
		auto& file_player4 = this->getT(0).getT(5).getT(0).getT(3);         // filtest_impl::file_player4_t<NV>
		auto& branch = this->getT(0).getT(6);                               // filtest_impl::branch_t<NV>
		auto& chain9 = this->getT(0).getT(6).getT(0);                       // filtest_impl::chain9_t
		auto& chain10 = this->getT(0).getT(6).getT(1);                      // filtest_impl::chain10_t<NV>
		auto& tempo_sync7 = this->getT(0).getT(6).getT(1).getT(0);          // filtest_impl::tempo_sync7_t<NV>
		auto& converter4 = this->getT(0).getT(6).getT(1).getT(1);           // filtest_impl::converter4_t<NV>
		auto& faust = this->getT(0).getT(6).getT(1).getT(2);                // project::shfiter<NV>
		auto& receive = this->getT(0).getT(7);                              // routing::receive<stereo_cable>
		auto& softbypass_switch5 = this->getT(0).getT(8);                   // filtest_impl::softbypass_switch5_t<NV>
		auto& branch20 = this->getT(0).getT(8).getT(0);                     // filtest_impl::branch20_t<NV>
		auto& chain164 = this->getT(0).getT(8).getT(0).getT(0);             // filtest_impl::chain164_t<NV>
		auto& no_midi1 = this->getT(0).getT(8).getT(0).getT(0).getT(0);     // filtest_impl::no_midi1_t<NV>
		auto& svf2 = this->getT(0).getT(8).getT(0).getT(0).getT(0).getT(0); // filters::svf<NV>
		auto& svf3 = this->getT(0).getT(8).getT(0).getT(0).getT(0).getT(1); // filters::svf<NV>
		auto& chain186 = this->getT(0).getT(8).getT(0).getT(1);             // filtest_impl::chain186_t<NV>
		auto& split8 = this->getT(0).getT(8).getT(0).getT(1).getT(0);       // filtest_impl::split8_t<NV>
		auto& svf = this->getT(0).getT(8).getT(0).getT(1).getT(0).getT(0);  // filters::svf<NV>
		auto& svf1 = this->getT(0).getT(8).getT(0).getT(1).getT(0).getT(1); // filters::svf<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, tempo_sync); // Tempo -> tempo_sync::Multiplier
		
		auto& PosSmooth_p = this->getParameterT(1);
		PosSmooth_p.connectT(0, smoother10); // PosSmooth -> smoother10::SmoothingTime
		PosSmooth_p.connectT(1, smoother11); // PosSmooth -> smoother11::SmoothingTime
		
		auto& MathSmooth_p = this->getParameterT(2);
		MathSmooth_p.connectT(0, smoother);    // MathSmooth -> smoother::SmoothingTime
		MathSmooth_p.connectT(1, smoother3);   // MathSmooth -> smoother3::SmoothingTime
		MathSmooth_p.connectT(2, ring_mod2);   // MathSmooth -> ring_mod2::Q
		MathSmooth_p.connectT(3, smoother6);   // MathSmooth -> smoother6::SmoothingTime
		MathSmooth_p.connectT(4, smoother7);   // MathSmooth -> smoother7::SmoothingTime
		MathSmooth_p.connectT(5, tempo_sync1); // MathSmooth -> tempo_sync1::Multiplier
		MathSmooth_p.connectT(6, faust2);      // MathSmooth -> faust2::aN
		MathSmooth_p.connectT(7, svf_eq);      // MathSmooth -> svf_eq::Q
		MathSmooth_p.connectT(8, svf_eq3);     // MathSmooth -> svf_eq3::Q
		MathSmooth_p.connectT(9, fm);          // MathSmooth -> fm::FreqMultiplier
		MathSmooth_p.connectT(10, smoother8);  // MathSmooth -> smoother8::SmoothingTime
		MathSmooth_p.connectT(11, smoother9);  // MathSmooth -> smoother9::SmoothingTime
		MathSmooth_p.connectT(12, smoother1);  // MathSmooth -> smoother1::SmoothingTime
		MathSmooth_p.connectT(13, smoother4);  // MathSmooth -> smoother4::SmoothingTime
		MathSmooth_p.connectT(14, pi2);        // MathSmooth -> pi2::Value
		MathSmooth_p.connectT(15, sub3);       // MathSmooth -> sub3::Value
		
		this->getParameterT(3).connectT(0, pma); // Blimey -> pma::Add
		
		this->getParameterT(4).connectT(0, pma); // BlimeyMod -> pma::Multiply
		
		this->getParameterT(5).connectT(0, branch4); // BlimeyModSrc -> branch4::Index
		
		this->getParameterT(6).connectT(0, pma1); // Pitch -> pma1::Add
		
		this->getParameterT(7).connectT(0, pma1); // PitchMod -> pma1::Multiply
		
		this->getParameterT(8).connectT(0, branch9); // PitchSrc -> branch9::Index
		
		this->getParameterT(9).connectT(0, pma2); // Divide -> pma2::Add
		
		this->getParameterT(10).connectT(0, pma2); // DivMod -> pma2::Multiply
		
		this->getParameterT(11).connectT(0, branch7); // DivSrc -> branch7::Index
		
		auto& PitchSync_p = this->getParameterT(12);
		PitchSync_p.connectT(0, input_toggle); // PitchSync -> input_toggle::Input
		PitchSync_p.connectT(1, branch6);      // PitchSync -> branch6::Index
		
		this->getParameterT(14).connectT(0, branch5); // InputMode -> branch5::Index
		
		auto& OscMode_p = this->getParameterT(15);
		OscMode_p.connectT(0, oscillator8); // OscMode -> oscillator8::Mode
		OscMode_p.connectT(1, oscillator1); // OscMode -> oscillator1::Mode
		
		this->getParameterT(16).connectT(0, pma6); // AdjustMix -> pma6::Add
		
		this->getParameterT(17).connectT(0, pma6); // AdjustMixMod -> pma6::Multiply
		
		this->getParameterT(18).connectT(0, branch10); // AdjustMixSrc -> branch10::Index
		
		this->getParameterT(19).connectT(0, branch3); // AdjustMode -> branch3::Index
		
		this->getParameterT(20).connectT(0, pma7); // Adj -> pma7::Add
		
		this->getParameterT(21).connectT(0, pma7); // AdjMod -> pma7::Multiply
		
		this->getParameterT(22).connectT(0, branch11); // AdjSrc -> branch11::Index
		
		this->getParameterT(23).connectT(0, pma8); // Position -> pma8::Add
		
		this->getParameterT(24).connectT(0, pma8); // PosMod -> pma8::Multiply
		
		this->getParameterT(25).connectT(0, branch12); // PosSrc -> branch12::Index
		
		this->getParameterT(27).connectT(0, pma9); // Gain2 -> pma9::Add
		
		this->getParameterT(28).connectT(0, pma9); // Gain2Mod -> pma9::Multiply
		
		this->getParameterT(29).connectT(0, branch13); // Gain2Src -> branch13::Index
		
		this->getParameterT(30).connectT(0, ahdsr); // a1 -> ahdsr::Attack
		
		this->getParameterT(31).connectT(0, ahdsr); // h1 -> ahdsr::Hold
		
		this->getParameterT(32).connectT(0, ahdsr); // d1 -> ahdsr::Decay
		
		this->getParameterT(33).connectT(0, ahdsr); // s1 -> ahdsr::Sustain
		
		this->getParameterT(34).connectT(0, ahdsr); // r1 -> ahdsr::Release
		
		auto& EnvMod1_p = this->getParameterT(35);
		EnvMod1_p.connectT(0, minmax);  // EnvMod1 -> minmax::Value
		EnvMod1_p.connectT(1, minmax6); // EnvMod1 -> minmax6::Value
		
		this->getParameterT(36).connectT(0, tempo_sync4); // a2 -> tempo_sync4::UnsyncedTime
		
		this->getParameterT(37).connectT(0, tempo_sync5); // h2 -> tempo_sync5::UnsyncedTime
		
		this->getParameterT(38).connectT(0, tempo_sync6); // d2 -> tempo_sync6::UnsyncedTime
		
		auto& EnvDiv_p = this->getParameterT(39);
		EnvDiv_p.connectT(0, tempo_sync5); // EnvDiv -> tempo_sync5::Multiplier
		EnvDiv_p.connectT(1, tempo_sync4); // EnvDiv -> tempo_sync4::Multiplier
		EnvDiv_p.connectT(2, tempo_sync6); // EnvDiv -> tempo_sync6::Multiplier
		
		auto& Env2Sync_p = this->getParameterT(40);
		Env2Sync_p.connectT(0, tempo_sync6); // Env2Sync -> tempo_sync6::Enabled
		Env2Sync_p.connectT(1, tempo_sync5); // Env2Sync -> tempo_sync5::Enabled
		Env2Sync_p.connectT(2, tempo_sync4); // Env2Sync -> tempo_sync4::Enabled
		
		auto& q_p = this->getParameterT(41);
		q_p.connectT(0, svf2); // q -> svf2::Q
		q_p.connectT(1, svf3); // q -> svf3::Q
		q_p.connectT(2, svf);  // q -> svf::Q
		q_p.connectT(3, svf1); // q -> svf1::Q
		
		this->getParameterT(42).connectT(0, branch20); // FilterMode -> branch20::Index
		
		this->getParameterT(43).connectT(0, pma11); // LP -> pma11::Add
		
		this->getParameterT(44).connectT(0, pma11); // LpMod -> pma11::Multiply
		
		this->getParameterT(45).connectT(0, branch14); // LpSrc -> branch14::Index
		
		this->getParameterT(46).connectT(0, pma12); // HP -> pma12::Add
		
		this->getParameterT(47).connectT(0, pma12); // HpMod -> pma12::Multiply
		
		this->getParameterT(48).connectT(0, branch15); // HpSrc -> branch15::Index
		
		auto& step_p = this->getParameterT(49);
		step_p.connectT(0, minmax14); // step -> minmax14::Step
		step_p.connectT(1, minmax7);  // step -> minmax7::Step
		
		this->getParameterT(53).connectT(0, branch8); // PostQuantise -> branch8::Index
		
		this->getParameterT(54).connectT(0, pma13); // PositionOSc1 -> pma13::Add
		
		this->getParameterT(55).connectT(0, pma13); // PositionOsc1Mod -> pma13::Multiply
		
		this->getParameterT(56).connectT(0, branch16); // PositionOscModSrc -> branch16::Index
		
		auto& PosSmoothOsc1_p = this->getParameterT(58);
		PosSmoothOsc1_p.connectT(0, smoother12); // PosSmoothOsc1 -> smoother12::SmoothingTime
		PosSmoothOsc1_p.connectT(1, smoother13); // PosSmoothOsc1 -> smoother13::SmoothingTime
		
		this->getParameterT(59).connectT(0, pma14); // Osc2Ratio -> pma14::Add
		
		this->getParameterT(60).connectT(0, pma15); // ModPhase -> pma15::Add
		
		this->getParameterT(61).connectT(0, pma15); // PhaseMod -> pma15::Multiply
		
		this->getParameterT(62).connectT(0, branch19); // PhaseModSrc -> branch19::Index
		
		this->getParameterT(63).connectT(0, pma14); // Osc2PitchMod -> pma14::Multiply
		
		this->getParameterT(64).connectT(0, branch18); // Osc2PitchModSrc -> branch18::Index
		
		this->getParameterT(65).connectT(0, tempo_sync2); // TableTempo -> tempo_sync2::Tempo
		
		this->getParameterT(66).connectT(0, tempo_sync2); // TableDiv -> tempo_sync2::Multiplier
		
		this->getParameterT(67).connectT(0, ramp); // TableLoop -> ramp::LoopStart
		
		this->getParameterT(68).connectT(0, tempo_sync4); // A2Tempo -> tempo_sync4::Tempo
		
		this->getParameterT(69).connectT(0, tempo_sync5); // H2Tempo -> tempo_sync5::Tempo
		
		this->getParameterT(70).connectT(0, tempo_sync6); // D2Tempo -> tempo_sync6::Tempo
		
		this->getParameterT(71).connectT(0, input_toggle1); // Env2Loop -> input_toggle1::Input
		
		this->getParameterT(72).connectT(0, tempo_sync3); // Env2LoopTempo -> tempo_sync3::Tempo
		
		this->getParameterT(73).connectT(0, tempo_sync3); // Env2LoopDiv -> tempo_sync3::Multiplier
		
		this->getParameterT(89).connectT(0, xfader2); // SubMix -> xfader2::Value
		
		this->getParameterT(90).connectT(0, pma3); // SubFm -> pma3::Multiply
		
		this->getParameterT(91).connectT(0, pma5); // SubAm -> pma5::Multiply
		
		this->getParameterT(92).connectT(0, pma19); // detune -> pma19::Add
		
		this->getParameterT(94).connectT(0, smoothed_parameter_unscaled); // Glide -> smoothed_parameter_unscaled::SmoothingTime
		
		this->getParameterT(95).connectT(0, receive); // inPutGain -> receive::Feedback
		
		this->getParameterT(96).connectT(0, branch); // PsOnOff -> branch::Index
		
		this->getParameterT(97).connectT(0, tempo_sync7); // PsXfTempo -> tempo_sync7::Tempo
		
		this->getParameterT(98).connectT(0, tempo_sync7); // PsXfDivc -> tempo_sync7::Multiplier
		
		// Modulation Connections ------------------------------------------------------------------
		
		minmax1.getWrappedObject().getParameter().connectT(0, add6);    // minmax1 -> add6::Value
		minmax1.getWrappedObject().getParameter().connectT(1, add16);   // minmax1 -> add16::Value
		minmax1.getWrappedObject().getParameter().connectT(2, add52);   // minmax1 -> add52::Value
		minmax1.getWrappedObject().getParameter().connectT(3, add43);   // minmax1 -> add43::Value
		minmax1.getWrappedObject().getParameter().connectT(4, add61);   // minmax1 -> add61::Value
		minmax1.getWrappedObject().getParameter().connectT(5, add70);   // minmax1 -> add70::Value
		minmax1.getWrappedObject().getParameter().connectT(6, add34);   // minmax1 -> add34::Value
		minmax1.getWrappedObject().getParameter().connectT(7, add83);   // minmax1 -> add83::Value
		minmax1.getWrappedObject().getParameter().connectT(8, add93);   // minmax1 -> add93::Value
		minmax1.getWrappedObject().getParameter().connectT(9, add38);   // minmax1 -> add38::Value
		minmax1.getWrappedObject().getParameter().connectT(10, add20);  // minmax1 -> add20::Value
		minmax1.getWrappedObject().getParameter().connectT(11, add65);  // minmax1 -> add65::Value
		pma17.getWrappedObject().getParameter().connectT(0, minmax1);   // pma17 -> minmax1::Value
		intensity.getWrappedObject().getParameter().connectT(0, pma17); // intensity -> pma17::Add
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(0).connectT(0, intensity);                 // ahdsr -> intensity::Value
		midi.getParameter().connectT(0, pma17);                          // midi -> pma17::Value
		minmax6.getWrappedObject().getParameter().connectT(0, pma17);    // minmax6 -> pma17::Multiply
		tempo_sync3.getParameter().connectT(0, ramp1);                   // tempo_sync3 -> ramp1::PeriodTime
		minmax2.getWrappedObject().getParameter().connectT(0, add7);     // minmax2 -> add7::Value
		minmax2.getWrappedObject().getParameter().connectT(1, add17);    // minmax2 -> add17::Value
		minmax2.getWrappedObject().getParameter().connectT(2, add53);    // minmax2 -> add53::Value
		minmax2.getWrappedObject().getParameter().connectT(3, add44);    // minmax2 -> add44::Value
		minmax2.getWrappedObject().getParameter().connectT(4, add62);    // minmax2 -> add62::Value
		minmax2.getWrappedObject().getParameter().connectT(5, add71);    // minmax2 -> add71::Value
		minmax2.getWrappedObject().getParameter().connectT(6, add35);    // minmax2 -> add35::Value
		minmax2.getWrappedObject().getParameter().connectT(7, add84);    // minmax2 -> add84::Value
		minmax2.getWrappedObject().getParameter().connectT(8, add94);    // minmax2 -> add94::Value
		minmax2.getWrappedObject().getParameter().connectT(9, add39);    // minmax2 -> add39::Value
		minmax2.getWrappedObject().getParameter().connectT(10, add21);   // minmax2 -> add21::Value
		minmax2.getWrappedObject().getParameter().connectT(11, add66);   // minmax2 -> add66::Value
		pma18.getWrappedObject().getParameter().connectT(0, minmax2);    // pma18 -> minmax2::Value
		intensity1.getWrappedObject().getParameter().connectT(0, pma18); // intensity1 -> pma18::Add
		auto& simple_ar_p = simple_ar.getWrappedObject().getParameter();
		simple_ar_p.getParameterT(0).connectT(0, intensity1);                     // simple_ar -> intensity1::Value
		input_toggle1.getWrappedObject().getParameter().connectT(0, simple_ar);   // input_toggle1 -> simple_ar::Gate
		peak2.getParameter().connectT(0, input_toggle1);                          // peak2 -> input_toggle1::Value2
		tempo_sync4.getParameter().connectT(0, simple_ar);                        // tempo_sync4 -> simple_ar::Attack
		tempo_sync6.getParameter().connectT(0, simple_ar);                        // tempo_sync6 -> simple_ar::Release
		midi1.getParameter().connectT(0, pma18);                                  // midi1 -> pma18::Value
		minmax.getWrappedObject().getParameter().connectT(0, pma18);              // minmax -> pma18::Multiply
		cable_table1.getWrappedObject().getParameter().connectT(0, add11);        // cable_table1 -> add11::Value
		cable_table1.getWrappedObject().getParameter().connectT(1, add25);        // cable_table1 -> add25::Value
		cable_table1.getWrappedObject().getParameter().connectT(2, add28);        // cable_table1 -> add28::Value
		cable_table1.getWrappedObject().getParameter().connectT(3, add79);        // cable_table1 -> add79::Value
		cable_table1.getWrappedObject().getParameter().connectT(4, add105);       // cable_table1 -> add105::Value
		cable_table1.getWrappedObject().getParameter().connectT(5, add80);        // cable_table1 -> add80::Value
		cable_table1.getWrappedObject().getParameter().connectT(6, add139);       // cable_table1 -> add139::Value
		cable_table1.getWrappedObject().getParameter().connectT(7, add81);        // cable_table1 -> add81::Value
		cable_table1.getWrappedObject().getParameter().connectT(8, add82);        // cable_table1 -> add82::Value
		cable_table1.getWrappedObject().getParameter().connectT(9, add88);        // cable_table1 -> add88::Value
		cable_table1.getWrappedObject().getParameter().connectT(10, add85);       // cable_table1 -> add85::Value
		cable_table1.getWrappedObject().getParameter().connectT(11, add95);       // cable_table1 -> add95::Value
		ramp.getParameter().connectT(0, cable_table1);                            // ramp -> cable_table1::Value
		tempo_sync2.getParameter().connectT(0, ramp);                             // tempo_sync2 -> ramp::PeriodTime
		midi2.getParameter().connectT(0, add8);                                   // midi2 -> add8::Value
		midi2.getParameter().connectT(1, add22);                                  // midi2 -> add22::Value
		midi2.getParameter().connectT(2, add49);                                  // midi2 -> add49::Value
		midi2.getParameter().connectT(3, add58);                                  // midi2 -> add58::Value
		midi2.getParameter().connectT(4, add67);                                  // midi2 -> add67::Value
		midi2.getParameter().connectT(5, add76);                                  // midi2 -> add76::Value
		midi2.getParameter().connectT(6, add40);                                  // midi2 -> add40::Value
		midi2.getParameter().connectT(7, add90);                                  // midi2 -> add90::Value
		midi2.getParameter().connectT(8, add100);                                 // midi2 -> add100::Value
		midi2.getParameter().connectT(9, add56);                                  // midi2 -> add56::Value
		midi2.getParameter().connectT(10, add31);                                 // midi2 -> add31::Value
		midi2.getParameter().connectT(11, add89);                                 // midi2 -> add89::Value
		midi3.getParameter().connectT(0, add9);                                   // midi3 -> add9::Value
		midi3.getParameter().connectT(1, add23);                                  // midi3 -> add23::Value
		midi3.getParameter().connectT(2, add50);                                  // midi3 -> add50::Value
		midi3.getParameter().connectT(3, add59);                                  // midi3 -> add59::Value
		midi3.getParameter().connectT(4, add68);                                  // midi3 -> add68::Value
		midi3.getParameter().connectT(5, add77);                                  // midi3 -> add77::Value
		midi3.getParameter().connectT(6, add41);                                  // midi3 -> add41::Value
		midi3.getParameter().connectT(7, add91);                                  // midi3 -> add91::Value
		midi3.getParameter().connectT(8, add101);                                 // midi3 -> add101::Value
		midi3.getParameter().connectT(9, add57);                                  // midi3 -> add57::Value
		midi3.getParameter().connectT(10, add32);                                 // midi3 -> add32::Value
		midi3.getParameter().connectT(11, add98);                                 // midi3 -> add98::Value
		midi_cc1.getWrappedObject().getParameter().connectT(0, add10);            // midi_cc1 -> add10::Value
		midi_cc1.getWrappedObject().getParameter().connectT(1, add24);            // midi_cc1 -> add24::Value
		midi_cc1.getWrappedObject().getParameter().connectT(2, add51);            // midi_cc1 -> add51::Value
		midi_cc1.getWrappedObject().getParameter().connectT(3, add60);            // midi_cc1 -> add60::Value
		midi_cc1.getWrappedObject().getParameter().connectT(4, add69);            // midi_cc1 -> add69::Value
		midi_cc1.getWrappedObject().getParameter().connectT(5, add78);            // midi_cc1 -> add78::Value
		midi_cc1.getWrappedObject().getParameter().connectT(6, add42);            // midi_cc1 -> add42::Value
		midi_cc1.getWrappedObject().getParameter().connectT(7, add92);            // midi_cc1 -> add92::Value
		midi_cc1.getWrappedObject().getParameter().connectT(8, add102);           // midi_cc1 -> add102::Value
		midi_cc1.getWrappedObject().getParameter().connectT(9, add120);           // midi_cc1 -> add120::Value
		midi_cc1.getWrappedObject().getParameter().connectT(10, add33);           // midi_cc1 -> add33::Value
		midi_cc1.getWrappedObject().getParameter().connectT(11, add99);           // midi_cc1 -> add99::Value
		global_cable.getWrappedObject().getParameter().connectT(0, add);          // global_cable -> add::Value
		global_cable1.getWrappedObject().getParameter().connectT(0, add5);        // global_cable1 -> add5::Value
		pma5.getWrappedObject().getParameter().connectT(0, oscillator8);          // pma5 -> oscillator8::Gain
		pma5.getWrappedObject().getParameter().connectT(1, oscillator1);          // pma5 -> oscillator1::Gain
		pma10.getWrappedObject().getParameter().connectT(0, pma5);                // pma10 -> pma5::Add
		pma.getWrappedObject().getParameter().connectT(0, pma10);                 // pma -> pma10::Add
		peak.getParameter().connectT(0, pma);                                     // peak -> pma::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, add18);       // global_cable4 -> add18::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add19);       // global_cable5 -> add19::Value
		pma3.getWrappedObject().getParameter().connectT(0, minmax14);             // pma3 -> minmax14::Value
		pma4.getWrappedObject().getParameter().connectT(0, pma3);                 // pma4 -> pma3::Add
		input_toggle.getWrappedObject().getParameter().connectT(0, pma4);         // input_toggle -> pma4::Add
		input_toggle.getWrappedObject().getParameter().connectT(1, oscillator8);  // input_toggle -> oscillator8::FreqRatio
		converter.getWrappedObject().getParameter().connectT(0, input_toggle);    // converter -> input_toggle::Value2
		tempo_sync.getParameter().connectT(0, converter);                         // tempo_sync -> converter::Value
		tempo_sync.getParameter().connectT(1, sampleandhold);                     // tempo_sync -> sampleandhold::Counter
		pma2.getWrappedObject().getParameter().connectT(0, tempo_sync);           // pma2 -> tempo_sync::Tempo
		peak3.getParameter().connectT(0, pma2);                                   // peak3 -> pma2::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add29);       // global_cable6 -> add29::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, add30);       // global_cable7 -> add30::Value
		smoothed_parameter3.getParameter().connectT(0, oscillator8);              // smoothed_parameter3 -> oscillator8::Phase
		pma15.getWrappedObject().getParameter().connectT(0, smoothed_parameter3); // pma15 -> smoothed_parameter3::Value
		peak16.getParameter().connectT(0, pma15);                                 // peak16 -> pma15::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add36);      // global_cable12 -> add36::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add37);      // global_cable13 -> add37::Value
		pma1.getWrappedObject().getParameter().connectT(0, input_toggle);         // pma1 -> input_toggle::Value1
		peak5.getParameter().connectT(0, pma1);                                   // peak5 -> pma1::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add47);      // global_cable14 -> add47::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add48);      // global_cable15 -> add48::Value
		peak15.getParameter().connectT(0, pma14);                                 // peak15 -> pma14::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add45);      // global_cable16 -> add45::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add46);      // global_cable17 -> add46::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain1);                             // xfader -> gain1::Gain
		xfader_p.getParameterT(1).connectT(0, gain2);                             // xfader -> gain2::Gain
		pma6.getWrappedObject().getParameter().connectT(0, xfader);               // pma6 -> xfader::Value
		peak6.getParameter().connectT(0, pma6);                                   // peak6 -> pma6::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add54);      // global_cable20 -> add54::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add55);      // global_cable21 -> add55::Value
		cable_table.getWrappedObject().getParameter().connectT(0, faust2);        // cable_table -> faust2::del
		tempo_sync1.getParameter().connectT(0, sampleandhold1);                   // tempo_sync1 -> sampleandhold1::Counter
		smoothed_parameter1.getParameter().connectT(0, expr);                     // smoothed_parameter1 -> expr::Value
		smoothed_parameter1.getParameter().connectT(1, ring_mod2);                // smoothed_parameter1 -> ring_mod2::Frequency
		smoothed_parameter1.getParameter().connectT(2, div2);                     // smoothed_parameter1 -> div2::Value
		smoothed_parameter1.getParameter().connectT(3, cable_table);              // smoothed_parameter1 -> cable_table::Value
		smoothed_parameter1.getParameter().connectT(4, fm);                       // smoothed_parameter1 -> fm::Frequency
		smoothed_parameter1.getParameter().connectT(5, tempo_sync1);              // smoothed_parameter1 -> tempo_sync1::Tempo
		smoothed_parameter1.getParameter().connectT(6, bitcrush);                 // smoothed_parameter1 -> bitcrush::BitDepth
		smoothed_parameter1.getParameter().connectT(7, svf_eq);                   // smoothed_parameter1 -> svf_eq::Frequency
		smoothed_parameter1.getParameter().connectT(8, svf_eq3);                  // smoothed_parameter1 -> svf_eq3::Frequency
		smoothed_parameter1.getParameter().connectT(9, mul6);                     // smoothed_parameter1 -> mul6::Value
		smoothed_parameter1.getParameter().connectT(10, sub2);                    // smoothed_parameter1 -> sub2::Value
		smoothed_parameter1.getParameter().connectT(11, pi3);                     // smoothed_parameter1 -> pi3::Value
		pma7.getWrappedObject().getParameter().connectT(0, smoothed_parameter1);  // pma7 -> smoothed_parameter1::Value
		peak7.getParameter().connectT(0, pma7);                                   // peak7 -> pma7::Value
		global_cable28.getWrappedObject().getParameter().connectT(0, add72);      // global_cable28 -> add72::Value
		global_cable29.getWrappedObject().getParameter().connectT(0, add73);      // global_cable29 -> add73::Value
		pma9.getWrappedObject().getParameter().connectT(0, map2);                 // pma9 -> map2::InputEnd
		pma9.getWrappedObject().getParameter().connectT(1, map1);                 // pma9 -> map1::InputEnd
		pma9.getWrappedObject().getParameter().connectT(2, map3);                 // pma9 -> map3::InputEnd
		pma9.getWrappedObject().getParameter().connectT(3, map4);                 // pma9 -> map4::InputEnd
		pma9.getWrappedObject().getParameter().connectT(4, map5);                 // pma9 -> map5::InputEnd
		pma9.getWrappedObject().getParameter().connectT(5, map6);                 // pma9 -> map6::InputEnd
		pma9.getWrappedObject().getParameter().connectT(6, gain3);                // pma9 -> gain3::Gain
		peak9.getParameter().connectT(0, pma9);                                   // peak9 -> pma9::Value
		global_cable24.getWrappedObject().getParameter().connectT(0, add63);      // global_cable24 -> add63::Value
		global_cable25.getWrappedObject().getParameter().connectT(0, add64);      // global_cable25 -> add64::Value
		minmax3.getWrappedObject().getParameter().connectT(0, add125);            // minmax3 -> add125::Value
		minmax3.getWrappedObject().getParameter().connectT(1, map6);              // minmax3 -> map6::OutputStart
		minmax4.getWrappedObject().getParameter().connectT(0, add2);              // minmax4 -> add2::Value
		minmax12.getWrappedObject().getParameter().connectT(0, add126);           // minmax12 -> add126::Value
		minmax12.getWrappedObject().getParameter().connectT(1, map5);             // minmax12 -> map5::OutputStart
		minmax10.getWrappedObject().getParameter().connectT(0, add127);           // minmax10 -> add127::Value
		minmax10.getWrappedObject().getParameter().connectT(1, map4);             // minmax10 -> map4::OutputStart
		minmax9.getWrappedObject().getParameter().connectT(0, add128);            // minmax9 -> add128::Value
		minmax9.getWrappedObject().getParameter().connectT(1, map3);              // minmax9 -> map3::OutputStart
		minmax8.getWrappedObject().getParameter().connectT(0, add129);            // minmax8 -> add129::Value
		minmax8.getWrappedObject().getParameter().connectT(1, map2);              // minmax8 -> map2::OutputStart
		minmax13.getWrappedObject().getParameter().connectT(0, map1);             // minmax13 -> map1::OutputStart
		minmax13.getWrappedObject().getParameter().connectT(1, add3);             // minmax13 -> add3::Value
		smoothed_parameter.getParameter().connectT(0, minmax3);                   // smoothed_parameter -> minmax3::Value
		smoothed_parameter.getParameter().connectT(1, minmax4);                   // smoothed_parameter -> minmax4::Value
		smoothed_parameter.getParameter().connectT(2, minmax12);                  // smoothed_parameter -> minmax12::Value
		smoothed_parameter.getParameter().connectT(3, minmax10);                  // smoothed_parameter -> minmax10::Value
		smoothed_parameter.getParameter().connectT(4, minmax9);                   // smoothed_parameter -> minmax9::Value
		smoothed_parameter.getParameter().connectT(5, minmax8);                   // smoothed_parameter -> minmax8::Value
		smoothed_parameter.getParameter().connectT(6, minmax13);                  // smoothed_parameter -> minmax13::Value
		smoothed_parameter.getParameter().connectT(7, add1);                      // smoothed_parameter -> add1::Value
		smoothed_parameter.getParameter().connectT(8, add130);                    // smoothed_parameter -> add130::Value
		pma8.getWrappedObject().getParameter().connectT(0, smoothed_parameter);   // pma8 -> smoothed_parameter::Value
		peak8.getParameter().connectT(0, pma8);                                   // peak8 -> pma8::Value
		global_cable26.getWrappedObject().getParameter().connectT(0, add74);      // global_cable26 -> add74::Value
		global_cable27.getWrappedObject().getParameter().connectT(0, add75);      // global_cable27 -> add75::Value
		smoothed_parameter2.getParameter().connectT(0, add131);                   // smoothed_parameter2 -> add131::Value
		smoothed_parameter2.getParameter().connectT(1, add132);                   // smoothed_parameter2 -> add132::Value
		smoothed_parameter2.getParameter().connectT(2, add133);                   // smoothed_parameter2 -> add133::Value
		smoothed_parameter2.getParameter().connectT(3, add134);                   // smoothed_parameter2 -> add134::Value
		smoothed_parameter2.getParameter().connectT(4, add135);                   // smoothed_parameter2 -> add135::Value
		smoothed_parameter2.getParameter().connectT(5, add136);                   // smoothed_parameter2 -> add136::Value
		smoothed_parameter2.getParameter().connectT(6, add137);                   // smoothed_parameter2 -> add137::Value
		smoothed_parameter2.getParameter().connectT(7, add138);                   // smoothed_parameter2 -> add138::Value
		pma13.getWrappedObject().getParameter().connectT(0, smoothed_parameter2); // pma13 -> smoothed_parameter2::Value
		peak14.getParameter().connectT(0, pma13);                                 // peak14 -> pma13::Value
		global_cable32.getWrappedObject().getParameter().connectT(0, add86);      // global_cable32 -> add86::Value
		global_cable33.getWrappedObject().getParameter().connectT(0, add87);      // global_cable33 -> add87::Value
		pma11.getWrappedObject().getParameter().connectT(0, svf2);                // pma11 -> svf2::Frequency
		pma11.getWrappedObject().getParameter().connectT(1, svf);                 // pma11 -> svf::Frequency
		peak10.getParameter().connectT(0, pma11);                                 // peak10 -> pma11::Value
		global_cable36.getWrappedObject().getParameter().connectT(0, add96);      // global_cable36 -> add96::Value
		global_cable37.getWrappedObject().getParameter().connectT(0, add97);      // global_cable37 -> add97::Value
		pma12.getWrappedObject().getParameter().connectT(0, svf1);                // pma12 -> svf1::Frequency
		pma12.getWrappedObject().getParameter().connectT(1, svf3);                // pma12 -> svf3::Frequency
		peak11.getParameter().connectT(0, pma12);                                 // peak11 -> pma12::Value
		auto& xfader2_p = xfader2.getWrappedObject().getParameter();
		xfader2_p.getParameterT(0).connectT(0, gain5);                                         // xfader2 -> gain5::Gain
		xfader2_p.getParameterT(1).connectT(0, gain6);                                         // xfader2 -> gain6::Gain
		smoothed_parameter_unscaled.getParameter().connectT(0, oscillator8);                   // smoothed_parameter_unscaled -> oscillator8::Frequency
		smoothed_parameter_unscaled.getParameter().connectT(1, oscillator1);                   // smoothed_parameter_unscaled -> oscillator1::Frequency
		converter1.getWrappedObject().getParameter().connectT(0, smoothed_parameter_unscaled); // converter1 -> smoothed_parameter_unscaled::Value
		midi5.getParameter().connectT(0, converter1);                                          // midi5 -> converter1::Value
		minmax7.getWrappedObject().getParameter().connectT(0, oscillator1);                    // minmax7 -> oscillator1::FreqRatio
		pma19.getWrappedObject().getParameter().connectT(0, minmax7);                          // pma19 -> minmax7::Value
		peak17.getParameter().connectT(0, pma3);                                               // peak17 -> pma3::Value
		peak17.getParameter().connectT(1, pma5);                                               // peak17 -> pma5::Value
		midi4.getParameter().connectT(0, faust);                                               // midi4 -> faust::shiftsemitones
		converter4.getWrappedObject().getParameter().connectT(0, faust);                       // converter4 -> faust::windowsamples
		converter4.getWrappedObject().getParameter().connectT(1, faust);                       // converter4 -> faust::xfadesamples
		tempo_sync7.getParameter().connectT(0, converter4);                                    // tempo_sync7 -> converter4::Value
		
		// Send Connections ------------------------------------------------------------------------
		
		send.connect(receive);
		
		// Default Values --------------------------------------------------------------------------
		
		;                            // ahdsr::Attack is automated
		ahdsr.setParameterT(1, 1.);  // envelope::ahdsr::AttackLevel
		;                            // ahdsr::Hold is automated
		;                            // ahdsr::Decay is automated
		;                            // ahdsr::Sustain is automated
		;                            // ahdsr::Release is automated
		ahdsr.setParameterT(6, 0.5); // envelope::ahdsr::AttackCurve
		ahdsr.setParameterT(7, 0.);  // envelope::ahdsr::Retrigger
		ahdsr.setParameterT(8, 0.);  // envelope::ahdsr::Gate
		
		sig2mod1.setParameterT(0, 0.); // math::sig2mod::Value
		
		;                               // intensity::Value is automated
		intensity.setParameterT(1, 1.); // control::intensity::Intensity
		
		;                              // minmax6::Value is automated
		minmax6.setParameterT(1, -1.); // control::minmax::Minimum
		minmax6.setParameterT(2, 1.);  // control::minmax::Maximum
		minmax6.setParameterT(3, 1.);  // control::minmax::Skew
		minmax6.setParameterT(4, 0.);  // control::minmax::Step
		minmax6.setParameterT(5, 1.);  // control::minmax::Polarity
		
		; // pma17::Value is automated
		; // pma17::Multiply is automated
		; // pma17::Add is automated
		
		;                             // minmax1::Value is automated
		minmax1.setParameterT(1, 0.); // control::minmax::Minimum
		minmax1.setParameterT(2, 1.); // control::minmax::Maximum
		minmax1.setParameterT(3, 1.); // control::minmax::Skew
		minmax1.setParameterT(4, 0.); // control::minmax::Step
		minmax1.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                   // tempo_sync3::Tempo is automated
		;                                   // tempo_sync3::Multiplier is automated
		tempo_sync3.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync3.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                           // ramp1::PeriodTime is automated
		ramp1.setParameterT(1, 0.); // core::ramp::LoopStart
		ramp1.setParameterT(2, 1.); // core::ramp::Gate
		
		rect.setParameterT(0, 0.); // math::rect::Value
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		;                                   // input_toggle1::Input is automated
		input_toggle1.setParameterT(1, 1.); // control::input_toggle::Value1
		;                                   // input_toggle1::Value2 is automated
		
		; // tempo_sync4::Tempo is automated
		; // tempo_sync4::Multiplier is automated
		; // tempo_sync4::Enabled is automated
		; // tempo_sync4::UnsyncedTime is automated
		
		; // tempo_sync5::Tempo is automated
		; // tempo_sync5::Multiplier is automated
		; // tempo_sync5::Enabled is automated
		; // tempo_sync5::UnsyncedTime is automated
		
		; // tempo_sync6::Tempo is automated
		; // tempo_sync6::Multiplier is automated
		; // tempo_sync6::Enabled is automated
		; // tempo_sync6::UnsyncedTime is automated
		
		;                               // simple_ar::Attack is automated
		;                               // simple_ar::Release is automated
		;                               // simple_ar::Gate is automated
		simple_ar.setParameterT(3, 0.); // envelope::simple_ar::AttackCurve
		
		clear16.setParameterT(0, 0.); // math::clear::Value
		
		sig2mod3.setParameterT(0, 0.); // math::sig2mod::Value
		
		;                                // intensity1::Value is automated
		intensity1.setParameterT(1, 1.); // control::intensity::Intensity
		
		;                             // minmax::Value is automated
		minmax.setParameterT(1, -1.); // control::minmax::Minimum
		minmax.setParameterT(2, 0.);  // control::minmax::Maximum
		minmax.setParameterT(3, 1.);  // control::minmax::Skew
		minmax.setParameterT(4, 0.);  // control::minmax::Step
		minmax.setParameterT(5, 1.);  // control::minmax::Polarity
		
		; // pma18::Value is automated
		; // pma18::Multiply is automated
		; // pma18::Add is automated
		
		;                             // minmax2::Value is automated
		minmax2.setParameterT(1, 0.); // control::minmax::Minimum
		minmax2.setParameterT(2, 1.); // control::minmax::Maximum
		minmax2.setParameterT(3, 1.); // control::minmax::Skew
		minmax2.setParameterT(4, 0.); // control::minmax::Step
		minmax2.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                                   // tempo_sync2::Tempo is automated
		;                                   // tempo_sync2::Multiplier is automated
		tempo_sync2.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync2.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                          // ramp::PeriodTime is automated
		;                          // ramp::LoopStart is automated
		ramp.setParameterT(2, 1.); // core::ramp::Gate
		
		clear4.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table1::Value is automated
		
		midi_cc1.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc1.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc1.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // branch4::Index is automated
		
		; // add6::Value is automated
		
		; // add7::Value is automated
		
		; // add11::Value is automated
		
		global_cable.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add::Value is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		; // add8::Value is automated
		
		; // add9::Value is automated
		
		; // add10::Value is automated
		
		add14.setParameterT(0, 0.); // math::add::Value
		
		add15.setParameterT(0, 0.); // math::add::Value
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // branch7::Index is automated
		
		; // add16::Value is automated
		
		; // add17::Value is automated
		
		; // add25::Value is automated
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add18::Value is automated
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add19::Value is automated
		
		; // add22::Value is automated
		
		; // add23::Value is automated
		
		; // add24::Value is automated
		
		add27.setParameterT(0, 0.); // math::add::Value
		
		add26.setParameterT(0, 0.); // math::add::Value
		
		; // pma2::Value is automated
		; // pma2::Multiply is automated
		; // pma2::Add is automated
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		; // branch19::Index is automated
		
		; // add20::Value is automated
		
		; // add21::Value is automated
		
		; // add28::Value is automated
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add29::Value is automated
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add30::Value is automated
		
		; // add31::Value is automated
		
		; // add32::Value is automated
		
		; // add33::Value is automated
		
		add123.setParameterT(0, 0.); // math::add::Value
		
		add124.setParameterT(0, 0.); // math::add::Value
		
		; // pma15::Value is automated
		; // pma15::Multiply is automated
		; // pma15::Add is automated
		
		clear6.setParameterT(0, 0.); // math::clear::Value
		
		; // branch9::Index is automated
		
		; // add34::Value is automated
		
		; // add35::Value is automated
		
		; // add79::Value is automated
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add36::Value is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add37::Value is automated
		
		; // add40::Value is automated
		
		; // add41::Value is automated
		
		; // add42::Value is automated
		
		add117.setParameterT(0, 0.); // math::add::Value
		
		add116.setParameterT(0, 0.); // math::add::Value
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		clear7.setParameterT(0, 0.); // math::clear::Value
		
		; // branch18::Index is automated
		
		; // add38::Value is automated
		
		; // add39::Value is automated
		
		; // add105::Value is automated
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add47::Value is automated
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add48::Value is automated
		
		; // add56::Value is automated
		
		; // add57::Value is automated
		
		; // add120::Value is automated
		
		add121.setParameterT(0, 0.); // math::add::Value
		
		add122.setParameterT(0, 0.); // math::add::Value
		
		; // pma14::Value is automated
		; // pma14::Multiply is automated
		; // pma14::Add is automated
		
		clear15.setParameterT(0, 0.); // math::clear::Value
		
		; // branch10::Index is automated
		
		; // add43::Value is automated
		
		; // add44::Value is automated
		
		; // add80::Value is automated
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add45::Value is automated
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add46::Value is automated
		
		; // add49::Value is automated
		
		; // add50::Value is automated
		
		; // add51::Value is automated
		
		add115.setParameterT(0, 0.); // math::add::Value
		
		add114.setParameterT(0, 0.); // math::add::Value
		
		; // pma6::Value is automated
		; // pma6::Multiply is automated
		; // pma6::Add is automated
		
		clear8.setParameterT(0, 0.); // math::clear::Value
		
		; // branch11::Index is automated
		
		; // add52::Value is automated
		
		; // add53::Value is automated
		
		; // add139::Value is automated
		
		global_cable20.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add54::Value is automated
		
		global_cable21.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add55::Value is automated
		
		; // add58::Value is automated
		
		; // add59::Value is automated
		
		; // add60::Value is automated
		
		add113.setParameterT(0, 0.); // math::add::Value
		
		add112.setParameterT(0, 0.); // math::add::Value
		
		; // pma7::Value is automated
		; // pma7::Multiply is automated
		; // pma7::Add is automated
		
		clear9.setParameterT(0, 0.); // math::clear::Value
		
		; // branch13::Index is automated
		
		; // add70::Value is automated
		
		; // add71::Value is automated
		
		; // add81::Value is automated
		
		global_cable28.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add72::Value is automated
		
		global_cable29.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add73::Value is automated
		
		; // add76::Value is automated
		
		; // add77::Value is automated
		
		; // add78::Value is automated
		
		add111.setParameterT(0, 0.); // math::add::Value
		
		add110.setParameterT(0, 0.); // math::add::Value
		
		; // pma9::Value is automated
		; // pma9::Multiply is automated
		; // pma9::Add is automated
		
		clear11.setParameterT(0, 0.); // math::clear::Value
		
		; // branch12::Index is automated
		
		; // add61::Value is automated
		
		; // add62::Value is automated
		
		; // add82::Value is automated
		
		global_cable24.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add63::Value is automated
		
		global_cable25.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add64::Value is automated
		
		; // add67::Value is automated
		
		; // add68::Value is automated
		
		; // add69::Value is automated
		
		add109.setParameterT(0, 0.); // math::add::Value
		
		add108.setParameterT(0, 0.); // math::add::Value
		
		; // pma8::Value is automated
		; // pma8::Multiply is automated
		; // pma8::Add is automated
		
		clear10.setParameterT(0, 0.); // math::clear::Value
		
		; // branch16::Index is automated
		
		; // add65::Value is automated
		
		; // add66::Value is automated
		
		; // add88::Value is automated
		
		global_cable26.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add74::Value is automated
		
		global_cable27.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add75::Value is automated
		
		; // add89::Value is automated
		
		; // add98::Value is automated
		
		; // add99::Value is automated
		
		add118.setParameterT(0, 0.); // math::add::Value
		
		add119.setParameterT(0, 0.); // math::add::Value
		
		; // pma13::Value is automated
		; // pma13::Multiply is automated
		; // pma13::Add is automated
		
		clear14.setParameterT(0, 0.); // math::clear::Value
		
		; // branch14::Index is automated
		
		; // add83::Value is automated
		
		; // add84::Value is automated
		
		; // add85::Value is automated
		
		global_cable32.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add86::Value is automated
		
		global_cable33.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add87::Value is automated
		
		; // add90::Value is automated
		
		; // add91::Value is automated
		
		; // add92::Value is automated
		
		add103.setParameterT(0, 0.); // math::add::Value
		
		add104.setParameterT(0, 0.); // math::add::Value
		
		; // pma11::Value is automated
		; // pma11::Multiply is automated
		; // pma11::Add is automated
		
		clear12.setParameterT(0, 0.); // math::clear::Value
		
		; // branch15::Index is automated
		
		; // add93::Value is automated
		
		; // add94::Value is automated
		
		; // add95::Value is automated
		
		global_cable36.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add96::Value is automated
		
		global_cable37.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add97::Value is automated
		
		; // add100::Value is automated
		
		; // add101::Value is automated
		
		; // add102::Value is automated
		
		add107.setParameterT(0, 0.); // math::add::Value
		
		add106.setParameterT(0, 0.); // math::add::Value
		
		; // pma12::Value is automated
		; // pma12::Multiply is automated
		; // pma12::Add is automated
		
		clear13.setParameterT(0, 0.); // math::clear::Value
		
		;                                   // tempo_sync::Tempo is automated
		;                                   // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 267.7); // control::tempo_sync::UnsyncedTime
		
		; // converter::Value is automated
		
		; // input_toggle::Input is automated
		; // input_toggle::Value1 is automated
		; // input_toggle::Value2 is automated
		
		;                                            // smoothed_parameter3::Value is automated
		smoothed_parameter3.setParameterT(1, 107.2); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter3.setParameterT(2, 1.);    // control::smoothed_parameter::Enabled
		
		; // xfader2::Value is automated
		
		;                                                 // smoothed_parameter_unscaled::Value is automated
		;                                                 // smoothed_parameter_unscaled::SmoothingTime is automated
		smoothed_parameter_unscaled.setParameterT(2, 1.); // control::smoothed_parameter_unscaled::Enabled
		
		; // converter1::Value is automated
		
		; // pma3::Value is automated
		; // pma3::Multiply is automated
		; // pma3::Add is automated
		
		pma4.setParameterT(0, 1.); // control::pma::Value
		pma4.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma4::Add is automated
		
		; // pma5::Value is automated
		; // pma5::Multiply is automated
		; // pma5::Add is automated
		
		pma10.setParameterT(0, 0.); // control::pma::Value
		pma10.setParameterT(1, 0.); // control::pma::Multiply
		;                           // pma10::Add is automated
		
		;                               // minmax14::Value is automated
		minmax14.setParameterT(1, 0.);  // control::minmax::Minimum
		minmax14.setParameterT(2, 16.); // control::minmax::Maximum
		minmax14.setParameterT(3, 1.);  // control::minmax::Skew
		;                               // minmax14::Step is automated
		minmax14.setParameterT(5, 0.);  // control::minmax::Polarity
		
		;                                 // oscillator8::Mode is automated
		;                                 // oscillator8::Frequency is automated
		;                                 // oscillator8::FreqRatio is automated
		oscillator8.setParameterT(3, 1.); // core::oscillator::Gate
		;                                 // oscillator8::Phase is automated
		;                                 // oscillator8::Gain is automated
		
		;                              // gain5::Gain is automated
		gain5.setParameterT(1, 0.);    // core::gain::Smoothing
		gain5.setParameterT(2, -100.); // core::gain::ResetValue
		
		pma19.setParameterT(0, 0.); // control::pma::Value
		pma19.setParameterT(1, 1.); // control::pma::Multiply
		;                           // pma19::Add is automated
		
		;                                  // minmax7::Value is automated
		minmax7.setParameterT(1, 0.5);     // control::minmax::Minimum
		minmax7.setParameterT(2, 2.);      // control::minmax::Maximum
		minmax7.setParameterT(3, 0.63093); // control::minmax::Skew
		;                                  // minmax7::Step is automated
		minmax7.setParameterT(5, 0.);      // control::minmax::Polarity
		
		;                                         // oscillator1::Mode is automated
		;                                         // oscillator1::Frequency is automated
		;                                         // oscillator1::FreqRatio is automated
		oscillator1.setParameterT(3, 1.);         // core::oscillator::Gate
		oscillator1.setParameterT(4, 0.00281934); // core::oscillator::Phase
		;                                         // oscillator1::Gain is automated
		
		pi1.setParameterT(0, 1.); // math::pi::Value
		
		sub.setParameterT(0, 0.983239); // math::sub::Value
		
		sub1.setParameterT(0, 1.); // math::sub::Value
		
		gain.setParameterT(0, -11.); // core::gain::Gain
		gain.setParameterT(1, 20.);  // core::gain::Smoothing
		gain.setParameterT(2, 0.);   // core::gain::ResetValue
		
		;                              // gain6::Gain is automated
		gain6.setParameterT(1, 10.8);  // core::gain::Smoothing
		gain6.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // branch5::Index is automated
		
		; // branch6::Index is automated
		
		; // sampleandhold::Counter is automated
		
		;                                          // smoothed_parameter2::Value is automated
		smoothed_parameter2.setParameterT(1, 0.1); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter2.setParameterT(2, 1.);  // control::smoothed_parameter::Enabled
		
		branch17.setParameterT(0, 0.); // container::branch::Index
		
		; // add131::Value is automated
		
		; // add132::Value is automated
		
		; // add133::Value is automated
		
		; // add134::Value is automated
		
		; // add135::Value is automated
		
		; // add136::Value is automated
		
		; // add137::Value is automated
		
		; // add138::Value is automated
		
		;                                // smoother12::SmoothingTime is automated
		smoother12.setParameterT(1, 1.); // core::smoother::DefaultValue
		
		;                                // smoother13::SmoothingTime is automated
		smoother13.setParameterT(1, 1.); // core::smoother::DefaultValue
		
		file_player6.setParameterT(0, 1.);   // core::file_player::PlaybackMode
		file_player6.setParameterT(1, 1.);   // core::file_player::Gate
		file_player6.setParameterT(2, 440.); // core::file_player::RootFrequency
		file_player6.setParameterT(3, 1.);   // core::file_player::FreqRatio
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // xfader::Value is automated
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 0.);    // core::gain::Smoothing
		gain1.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                          // smoothed_parameter1::Value is automated
		smoothed_parameter1.setParameterT(1, 0.1); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter1.setParameterT(2, 1.);  // control::smoothed_parameter::Enabled
		
		; // branch3::Index is automated
		
		; // expr::Value is automated
		
		;                              // smoother::SmoothingTime is automated
		smoother.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		;                               // smoother3::SmoothingTime is automated
		smoother3.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		; // mul6::Value is automated
		
		pi.setParameterT(0, 1.); // math::pi::Value
		
		;                               // smoother1::SmoothingTime is automated
		smoother1.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		;                               // smoother4::SmoothingTime is automated
		smoother4.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		; // pi2::Value is automated
		
		; // sub2::Value is automated
		
		fmod.setParameterT(0, 0.314201); // math::fmod::Value
		
		; // pi3::Value is automated
		
		; // sub3::Value is automated
		
		fmod1.setParameterT(0, 0.455914); // math::fmod::Value
		
		;                                     // ring_mod2::Frequency is automated
		;                                     // ring_mod2::Q is automated
		ring_mod2.setParameterT(2, -3.98306); // filters::ring_mod::Gain
		ring_mod2.setParameterT(3, 0.01);     // filters::ring_mod::Smoothing
		ring_mod2.setParameterT(4, 0.);       // filters::ring_mod::Mode
		ring_mod2.setParameterT(5, 1.);       // filters::ring_mod::Enabled
		
		; // cable_table::Value is automated
		
		; // faust2::aN is automated
		; // faust2::del is automated
		
		;                                   // svf_eq::Frequency is automated
		;                                   // svf_eq::Q is automated
		svf_eq.setParameterT(2, 0.);        // filters::svf_eq::Gain
		svf_eq.setParameterT(3, 0.0104336); // filters::svf_eq::Smoothing
		svf_eq.setParameterT(4, 0.);        // filters::svf_eq::Mode
		svf_eq.setParameterT(5, 1.);        // filters::svf_eq::Enabled
		
		;                               // svf_eq3::Frequency is automated
		;                               // svf_eq3::Q is automated
		svf_eq3.setParameterT(2, 0.);   // filters::svf_eq::Gain
		svf_eq3.setParameterT(3, 0.01); // filters::svf_eq::Smoothing
		svf_eq3.setParameterT(4, 1.);   // filters::svf_eq::Mode
		svf_eq3.setParameterT(5, 1.);   // filters::svf_eq::Enabled
		
		; // div2::Value is automated
		
		;                               // smoother6::SmoothingTime is automated
		smoother6.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		;                               // smoother7::SmoothingTime is automated
		smoother7.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		phasor_fm.setParameterT(0, 1.);       // core::phasor_fm::Gate
		phasor_fm.setParameterT(1, 20.);      // core::phasor_fm::Frequency
		phasor_fm.setParameterT(2, 1.);       // core::phasor_fm::FreqRatio
		phasor_fm.setParameterT(3, 0.936525); // core::phasor_fm::Phase
		
		;                        // fm::Frequency is automated
		fm.setParameterT(1, 0.); // core::fm::Modulator
		;                        // fm::FreqMultiplier is automated
		fm.setParameterT(3, 1.); // core::fm::Gate
		
		tanh1.setParameterT(0, 0.0245996); // math::tanh::Value
		
		;                                   // tempo_sync1::Tempo is automated
		;                                   // tempo_sync1::Multiplier is automated
		tempo_sync1.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync1.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // sampleandhold1::Counter is automated
		
		;                              // bitcrush::BitDepth is automated
		bitcrush.setParameterT(1, 1.); // fx::bitcrush::Mode
		
		;                               // smoother8::SmoothingTime is automated
		smoother8.setParameterT(1, 1.); // core::smoother::DefaultValue
		
		;                               // smoother9::SmoothingTime is automated
		smoother9.setParameterT(1, 1.); // core::smoother::DefaultValue
		
		;                              // gain2::Gain is automated
		gain2.setParameterT(1, 0.);    // core::gain::Smoothing
		gain2.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                              // gain3::Gain is automated
		gain3.setParameterT(1, 12.);   // core::gain::Smoothing
		gain3.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                         // smoothed_parameter::Value is automated
		smoothed_parameter.setParameterT(1, 0.1); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter.setParameterT(2, 1.);  // control::smoothed_parameter::Enabled
		
		;                                // smoother10::SmoothingTime is automated
		smoother10.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		;                                // smoother11::SmoothingTime is automated
		smoother11.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		; // branch8::Index is automated
		
		; // add1::Value is automated
		
		;                             // minmax3::Value is automated
		minmax3.setParameterT(1, 0.); // control::minmax::Minimum
		minmax3.setParameterT(2, 1.); // control::minmax::Maximum
		minmax3.setParameterT(3, 1.); // control::minmax::Skew
		minmax3.setParameterT(4, 0.); // control::minmax::Step
		minmax3.setParameterT(5, 0.); // control::minmax::Polarity
		
		map6.setParameterT(0, 0.); // math::map::InputStart
		;                          // map6::InputEnd is automated
		;                          // map6::OutputStart is automated
		map6.setParameterT(3, 1.); // math::map::OutputEnd
		
		; // add125::Value is automated
		
		;                                       // minmax12::Value is automated
		minmax12.setParameterT(1, 0.);          // control::minmax::Minimum
		minmax12.setParameterT(2, 1.);          // control::minmax::Maximum
		minmax12.setParameterT(3, 1.);          // control::minmax::Skew
		minmax12.setParameterT(4, 0.000976562); // control::minmax::Step
		minmax12.setParameterT(5, 0.);          // control::minmax::Polarity
		
		; // add126::Value is automated
		
		map5.setParameterT(0, 0.); // math::map::InputStart
		;                          // map5::InputEnd is automated
		;                          // map5::OutputStart is automated
		map5.setParameterT(3, 1.); // math::map::OutputEnd
		
		;                                      // minmax10::Value is automated
		minmax10.setParameterT(1, 0.);         // control::minmax::Minimum
		minmax10.setParameterT(2, 1.);         // control::minmax::Maximum
		minmax10.setParameterT(3, 1.);         // control::minmax::Skew
		minmax10.setParameterT(4, 0.00195312); // control::minmax::Step
		minmax10.setParameterT(5, 0.);         // control::minmax::Polarity
		
		; // add127::Value is automated
		
		map4.setParameterT(0, 0.); // math::map::InputStart
		;                          // map4::InputEnd is automated
		;                          // map4::OutputStart is automated
		map4.setParameterT(3, 1.); // math::map::OutputEnd
		
		;                                     // minmax9::Value is automated
		minmax9.setParameterT(1, 0.);         // control::minmax::Minimum
		minmax9.setParameterT(2, 1.);         // control::minmax::Maximum
		minmax9.setParameterT(3, 1.);         // control::minmax::Skew
		minmax9.setParameterT(4, 0.00390625); // control::minmax::Step
		minmax9.setParameterT(5, 0.);         // control::minmax::Polarity
		
		; // add128::Value is automated
		
		map3.setParameterT(0, 0.); // math::map::InputStart
		;                          // map3::InputEnd is automated
		;                          // map3::OutputStart is automated
		map3.setParameterT(3, 1.); // math::map::OutputEnd
		
		;                                    // minmax8::Value is automated
		minmax8.setParameterT(1, 0.);        // control::minmax::Minimum
		minmax8.setParameterT(2, 1.);        // control::minmax::Maximum
		minmax8.setParameterT(3, 1.);        // control::minmax::Skew
		minmax8.setParameterT(4, 0.0078125); // control::minmax::Step
		minmax8.setParameterT(5, 0.);        // control::minmax::Polarity
		
		map2.setParameterT(0, 0.); // math::map::InputStart
		;                          // map2::InputEnd is automated
		;                          // map2::OutputStart is automated
		map2.setParameterT(3, 1.); // math::map::OutputEnd
		
		; // add129::Value is automated
		
		;                                   // minmax4::Value is automated
		minmax4.setParameterT(1, 0.);       // control::minmax::Minimum
		minmax4.setParameterT(2, 1.);       // control::minmax::Maximum
		minmax4.setParameterT(3, 1.);       // control::minmax::Skew
		minmax4.setParameterT(4, 0.015625); // control::minmax::Step
		minmax4.setParameterT(5, 0.);       // control::minmax::Polarity
		
		; // add2::Value is automated
		
		; // add130::Value is automated
		
		;                                   // minmax13::Value is automated
		minmax13.setParameterT(1, 0.);      // control::minmax::Minimum
		minmax13.setParameterT(2, 1.);      // control::minmax::Maximum
		minmax13.setParameterT(3, 1.);      // control::minmax::Skew
		minmax13.setParameterT(4, 0.03125); // control::minmax::Step
		minmax13.setParameterT(5, 0.);      // control::minmax::Polarity
		
		map1.setParameterT(0, 0.); // math::map::InputStart
		;                          // map1::InputEnd is automated
		;                          // map1::OutputStart is automated
		map1.setParameterT(3, 1.); // math::map::OutputEnd
		
		; // add3::Value is automated
		
		file_player4.setParameterT(0, 1.);      // core::file_player::PlaybackMode
		file_player4.setParameterT(1, 1.);      // core::file_player::Gate
		file_player4.setParameterT(2, 790.031); // core::file_player::RootFrequency
		file_player4.setParameterT(3, 1.28);    // core::file_player::FreqRatio
		
		; // branch::Index is automated
		
		;                                   // tempo_sync7::Tempo is automated
		;                                   // tempo_sync7::Multiplier is automated
		tempo_sync7.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync7.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // converter4::Value is automated
		
		; // faust::shiftsemitones is automated
		; // faust::windowsamples is automated
		; // faust::xfadesamples is automated
		
		; // receive::Feedback is automated
		
		; // branch20::Index is automated
		
		;                            // svf2::Frequency is automated
		;                            // svf2::Q is automated
		svf2.setParameterT(2, 0.);   // filters::svf::Gain
		svf2.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf2.setParameterT(4, 0.);   // filters::svf::Mode
		svf2.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf3::Frequency is automated
		;                            // svf3::Q is automated
		svf3.setParameterT(2, 0.);   // filters::svf::Gain
		svf3.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf3.setParameterT(4, 1.);   // filters::svf::Mode
		svf3.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                           // svf::Frequency is automated
		;                           // svf::Q is automated
		svf.setParameterT(2, 0.);   // filters::svf::Gain
		svf.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf.setParameterT(4, 0.);   // filters::svf::Mode
		svf.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf1::Frequency is automated
		;                            // svf1::Q is automated
		svf1.setParameterT(2, 0.);   // filters::svf::Gain
		svf1.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf1.setParameterT(4, 1.);   // filters::svf::Mode
		svf1.setParameterT(5, 1.);   // filters::svf::Enabled
		
		this->setParameterT(0, 11.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 0.01);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 2.08167e-17);
		this->setParameterT(5, 1.);
		this->setParameterT(6, 0.5);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 9.);
		this->setParameterT(10, 2.08167e-17);
		this->setParameterT(11, 5.);
		this->setParameterT(12, 1.);
		this->setParameterT(13, -1.);
		this->setParameterT(14, 1.);
		this->setParameterT(15, 2.);
		this->setParameterT(16, 0.);
		this->setParameterT(17, 2.08167e-17);
		this->setParameterT(18, 1.);
		this->setParameterT(19, 7.);
		this->setParameterT(20, 0.01);
		this->setParameterT(21, 0.);
		this->setParameterT(22, 1.);
		this->setParameterT(23, 0.);
		this->setParameterT(24, 1.);
		this->setParameterT(25, 3.);
		this->setParameterT(26, 1.);
		this->setParameterT(27, 5.55112e-17);
		this->setParameterT(28, 2.08167e-17);
		this->setParameterT(29, 1.);
		this->setParameterT(30, 3996.);
		this->setParameterT(31, 10000.);
		this->setParameterT(32, 10000.);
		this->setParameterT(33, 0.);
		this->setParameterT(34, 3251.);
		this->setParameterT(35, 1.);
		this->setParameterT(36, 632.);
		this->setParameterT(37, 71.);
		this->setParameterT(38, 1000.);
		this->setParameterT(39, 10.);
		this->setParameterT(40, 1.);
		this->setParameterT(41, 0.);
		this->setParameterT(42, 0.);
		this->setParameterT(43, 0.99);
		this->setParameterT(44, 2.08167e-17);
		this->setParameterT(45, 4.);
		this->setParameterT(46, 0.);
		this->setParameterT(47, -0.01);
		this->setParameterT(48, 4.);
		this->setParameterT(49, 1.);
		this->setParameterT(50, 0.226758);
		this->setParameterT(51, 0.);
		this->setParameterT(52, 0.349219);
		this->setParameterT(53, 2.);
		this->setParameterT(54, 0.28);
		this->setParameterT(55, 0.);
		this->setParameterT(56, 1.);
		this->setParameterT(57, 5.);
		this->setParameterT(58, 0.);
		this->setParameterT(59, 0.0484885);
		this->setParameterT(60, 0.07);
		this->setParameterT(61, 2.08167e-17);
		this->setParameterT(62, 5.);
		this->setParameterT(63, 0.65574);
		this->setParameterT(64, 0.997232);
		this->setParameterT(65, 0.);
		this->setParameterT(66, 16.);
		this->setParameterT(67, 1.);
		this->setParameterT(68, 0.);
		this->setParameterT(69, 0.);
		this->setParameterT(70, 2.);
		this->setParameterT(71, 0.);
		this->setParameterT(72, 11.);
		this->setParameterT(73, 1.);
		this->setParameterT(74, -0.753933);
		this->setParameterT(75, 7.26);
		this->setParameterT(76, 1.);
		this->setParameterT(77, 1.);
		this->setParameterT(78, 8.);
		this->setParameterT(79, 0.953295);
		this->setParameterT(80, -1.);
		this->setParameterT(81, 0.59);
		this->setParameterT(82, 0.);
		this->setParameterT(83, 0.57);
		this->setParameterT(84, 1.);
		this->setParameterT(85, 1.);
		this->setParameterT(86, 0.);
		this->setParameterT(87, 0.);
		this->setParameterT(88, 0.);
		this->setParameterT(89, 0.);
		this->setParameterT(90, 1.);
		this->setParameterT(91, 0.);
		this->setParameterT(92, 0.12);
		this->setParameterT(93, 1.);
		this->setParameterT(94, 0.);
		this->setParameterT(95, 0.);
		this->setParameterT(96, 0.);
		this->setParameterT(97, 0.);
		this->setParameterT(98, 0.);
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
		
		this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable1_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable4_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable5_t<NV>
		this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable6_t<NV>
		this->getT(0).getT(0).getT(2).getT(2).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable7_t<NV>
		this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable12_t<NV>
		this->getT(0).getT(0).getT(2).getT(3).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable13_t<NV>
		this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable14_t<NV>
		this->getT(0).getT(0).getT(2).getT(4).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable15_t<NV>
		this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable16_t<NV>
		this->getT(0).getT(0).getT(2).getT(5).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable17_t<NV>
		this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable20_t<NV>
		this->getT(0).getT(0).getT(2).getT(6).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable21_t<NV>
		this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable28_t<NV>
		this->getT(0).getT(0).getT(2).getT(7).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable29_t<NV>
		this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable24_t<NV>
		this->getT(0).getT(0).getT(2).getT(8).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable25_t<NV>
		this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable26_t<NV>
		this->getT(0).getT(0).getT(2).getT(9).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c);  // filtest_impl::global_cable27_t<NV>
		this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable32_t<NV>
		this->getT(0).getT(0).getT(2).getT(10).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable33_t<NV>
		this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable36_t<NV>
		this->getT(0).getT(0).getT(2).getT(11).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable37_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index);                 // filtest_impl::ahdsr_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(1).setExternalData(b, index);                 // filtest_impl::ramp1_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(3).setExternalData(b, index);                 // filtest_impl::peak2_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(6).getT(1).setExternalData(b, index);         // filtest_impl::simple_ar_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(1).setExternalData(b, index);                 // filtest_impl::ramp_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(3).setExternalData(b, index);                 // filtest_impl::cable_table1_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(1).setExternalData(b, index);                 // filtest_impl::peak_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(1).setExternalData(b, index);                 // filtest_impl::peak3_t<NV>
		this->getT(0).getT(0).getT(2).getT(2).getT(1).setExternalData(b, index);                 // filtest_impl::peak16_t<NV>
		this->getT(0).getT(0).getT(2).getT(3).getT(1).setExternalData(b, index);                 // filtest_impl::peak5_t<NV>
		this->getT(0).getT(0).getT(2).getT(4).getT(1).setExternalData(b, index);                 // filtest_impl::peak15_t<NV>
		this->getT(0).getT(0).getT(2).getT(5).getT(1).setExternalData(b, index);                 // filtest_impl::peak6_t<NV>
		this->getT(0).getT(0).getT(2).getT(6).getT(1).setExternalData(b, index);                 // filtest_impl::peak7_t<NV>
		this->getT(0).getT(0).getT(2).getT(7).getT(1).setExternalData(b, index);                 // filtest_impl::peak9_t<NV>
		this->getT(0).getT(0).getT(2).getT(8).getT(1).setExternalData(b, index);                 // filtest_impl::peak8_t<NV>
		this->getT(0).getT(0).getT(2).getT(9).getT(1).setExternalData(b, index);                 // filtest_impl::peak14_t<NV>
		this->getT(0).getT(0).getT(2).getT(10).getT(1).setExternalData(b, index);                // filtest_impl::peak10_t<NV>
		this->getT(0).getT(0).getT(2).getT(11).getT(1).setExternalData(b, index);                // filtest_impl::peak11_t<NV>
		this->getT(0).getT(1).getT(3).getT(3).                                                   // filtest_impl::oscillator8_t<NV>
        getT(0).getT(0).getT(3).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(3).getT(3).getT(1).getT(2).getT(0).setExternalData(b, index); // filtest_impl::oscillator1_t<NV>
		this->getT(0).getT(1).getT(3).getT(3).getT(1).getT(3).setExternalData(b, index);         // filtest_impl::peak17_t<NV>
		this->getT(0).getT(1).getT(4).getT(2).getT(0).getT(3).setExternalData(b, index);         // filtest_impl::file_player6_t<NV>
		this->getT(0).getT(4).getT(0).getT(0).                                                   // filtest_impl::cable_table_t<NV>
        getT(1).getT(1).getT(1).getT(5).
        getT(0).setExternalData(b, index);
		this->getT(0).getT(5).getT(0).getT(3).setExternalData(b, index); // filtest_impl::file_player4_t<NV>
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
using filtest = wrap::node<filtest_impl::instance<NV>>;
}


