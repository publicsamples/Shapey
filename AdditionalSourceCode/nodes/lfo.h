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

DECLARE_PARAMETER_RANGE_SKEW(xfader2_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader2_c0 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       xfader2_c0Range>;

template <int NV> using xfader2_c1 = xfader2_c0<NV>;

template <int NV> using xfader2_c2 = xfader2_c0<NV>;

template <int NV> using xfader2_c3 = xfader2_c0<NV>;

template <int NV> using xfader2_c4 = xfader2_c0<NV>;

template <int NV> using xfader2_c5 = xfader2_c0<NV>;

template <int NV>
using xfader2_multimod = parameter::list<xfader2_c0<NV>, 
                                         xfader2_c1<NV>, 
                                         xfader2_c2<NV>, 
                                         xfader2_c3<NV>, 
                                         xfader2_c4<NV>, 
                                         xfader2_c5<NV>>;

template <int NV>
using xfader2_t = control::xfader<xfader2_multimod<NV>, faders::switcher>;
using global_cable1_t_index = runtime_target::indexers::fix_hash<2333884>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable1_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<2333885>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable3_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable8_t_index = runtime_target::indexers::fix_hash<2333886>;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable8_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using event_data_reader_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                      routing::event_data_reader<NV>>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader2_t = event_data_reader_t<NV>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader2_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader1_t = event_data_reader_t<NV>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader1_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain38_t<NV>>, 
                                  chain39_t<NV>, 
                                  chain40_t<NV>, 
                                  chain41_t<NV>, 
                                  chain42_t<NV>, 
                                  chain43_t<NV>>;

template <int NV>
using peak9_t = wrap::mod<parameter::plain<control::pma<NV, parameter::empty>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::pi<NV>>, 
                                   math::sin<NV>, 
                                   wrap::no_process<math::sig2mod<NV>>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, wrap::no_process<math::mul<NV>>>, 
                                   wrap::no_process<math::sig2mod<NV>>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::add<NV>>, 
                                   math::fmod<NV>, 
                                   math::sub<NV>, 
                                   math::abs<NV>, 
                                   math::mul<NV>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::mod_inv<NV>>, 
                                   math::rect<NV>>;
template <int NV>
using oscillator_t = wrap::no_data<core::oscillator<NV>>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, oscillator_t<NV>>>;

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::table<1>>;
template <int NV>
using input_toggle_t = control::input_toggle<NV, 
                                             parameter::plain<cable_table_t<NV>, 0>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, input_toggle_t<NV>>, 
                                   wrap::no_process<math::clear<NV>>, 
                                   cable_table_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using cable_pack_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                data::external::sliderpack<3>>;
template <int NV>
using input_toggle1_t = control::input_toggle<NV, 
                                              parameter::plain<cable_pack_t<NV>, 0>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, input_toggle1_t<NV>>, 
                                   wrap::no_process<math::clear<NV>>, 
                                   cable_pack_t<NV>, 
                                   math::add<NV>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain25_t<NV>>, 
                                    chain24_t<NV>, 
                                    chain14_t<NV>, 
                                    chain18_t<NV>, 
                                    chain31_t<NV>, 
                                    chain32_t<NV>, 
                                    chain33_t<NV>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch2_t<NV>>, 
                                   core::gain<NV>>;
DECLARE_PARAMETER_RANGE(pma3_modRange, 
                        0., 
                        40.);

template <int NV>
using pma3_mod = parameter::from0To1<chain11_t<NV>, 
                                     0, 
                                     pma3_modRange>;

template <int NV>
using pma3_t = control::pma<NV, pma3_mod<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, control::pma<NV, parameter::empty>>, 
                                  pma3_t<NV>>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split8_t<NV>>, 
                                   peak9_t<NV>, 
                                   split1_t<NV>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain52_t<NV>>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, xfader2_t<NV>>, 
                                     split7_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV> using xfader3_c0 = xfader2_c0<NV>;

template <int NV> using xfader3_c1 = xfader2_c0<NV>;

template <int NV> using xfader3_c2 = xfader2_c0<NV>;

template <int NV> using xfader3_c3 = xfader2_c0<NV>;

template <int NV> using xfader3_c4 = xfader2_c0<NV>;

template <int NV> using xfader3_c5 = xfader2_c0<NV>;

template <int NV>
using xfader3_multimod = parameter::list<xfader3_c0<NV>, 
                                         xfader3_c1<NV>, 
                                         xfader3_c2<NV>, 
                                         xfader3_c3<NV>, 
                                         xfader3_c4<NV>, 
                                         xfader3_c5<NV>>;

template <int NV>
using xfader3_t = control::xfader<xfader3_multimod<NV>, faders::switcher>;
using global_cable15_t_index = global_cable1_t_index;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain97_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable16_t_index = global_cable3_t_index;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain98_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable17_t_index = global_cable8_t_index;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain99_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader12_t = event_data_reader_t<NV>;

template <int NV>
using chain100_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader12_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader13_t = event_data_reader_t<NV>;

template <int NV>
using chain101_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader13_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader14_t = event_data_reader_t<NV>;

template <int NV>
using chain102_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader14_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using split13_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain97_t<NV>>, 
                                   chain98_t<NV>, 
                                   chain99_t<NV>, 
                                   chain100_t<NV>, 
                                   chain101_t<NV>, 
                                   chain102_t<NV>>;

template <int NV> using pma1_mod = xfader2_c0<NV>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;
template <int NV>
using peak12_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain96_t = container::chain<parameter::empty, 
                                   wrap::fix<1, split13_t<NV>>, 
                                   peak12_t<NV>, 
                                   pma1_t<NV>>;

template <int NV>
using split12_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain96_t<NV>>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, xfader3_t<NV>>, 
                                      split12_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV> using xfader4_c0 = xfader2_c0<NV>;

template <int NV> using xfader4_c1 = xfader2_c0<NV>;

template <int NV> using xfader4_c2 = xfader2_c0<NV>;

template <int NV> using xfader4_c3 = xfader2_c0<NV>;

template <int NV> using xfader4_c4 = xfader2_c0<NV>;

template <int NV> using xfader4_c5 = xfader2_c0<NV>;

template <int NV>
using xfader4_multimod = parameter::list<xfader4_c0<NV>, 
                                         xfader4_c1<NV>, 
                                         xfader4_c2<NV>, 
                                         xfader4_c3<NV>, 
                                         xfader4_c4<NV>, 
                                         xfader4_c5<NV>>;

template <int NV>
using xfader4_t = control::xfader<xfader4_multimod<NV>, faders::switcher>;
using global_cable18_t_index = global_cable1_t_index;

template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain104_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable18_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable19_t_index = global_cable3_t_index;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain105_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable19_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;
using global_cable20_t_index = global_cable8_t_index;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain106_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable20_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader15_t = event_data_reader_t<NV>;

template <int NV>
using chain107_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader15_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader16_t = event_data_reader_t<NV>;

template <int NV>
using chain108_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader16_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV> using event_data_reader17_t = event_data_reader_t<NV>;

template <int NV>
using chain109_t = container::chain<parameter::empty, 
                                    wrap::fix<1, event_data_reader17_t<NV>>, 
                                    math::add<NV>, 
                                    core::gain<NV>>;

template <int NV>
using split15_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain104_t<NV>>, 
                                   chain105_t<NV>, 
                                   chain106_t<NV>, 
                                   chain107_t<NV>, 
                                   chain108_t<NV>, 
                                   chain109_t<NV>>;

template <int NV> using peak13_t = peak9_t<NV>;

template <int NV>
using chain103_t = container::chain<parameter::empty, 
                                    wrap::fix<1, split15_t<NV>>, 
                                    peak13_t<NV>, 
                                    control::pma<NV, parameter::empty>>;

template <int NV>
using split14_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain103_t<NV>>>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, xfader4_t<NV>>, 
                                      split14_t<NV>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<1, modchain_t<NV>>, 
                                   modchain1_t<NV>, 
                                   modchain2_t<NV>>;

template <int NV>
using midichain_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split11_t<NV>>>;

template <int NV>
using midichain_t = wrap::event<midichain_t_<NV>>;

using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, core::empty>>;

DECLARE_PARAMETER_RANGE_STEP(simple_ar1_c0Range, 
                             -12., 
                             12., 
                             0.1);

template <int NV>
using simple_ar1_c0 = parameter::from0To1<core::gain<NV>, 
                                          0, 
                                          simple_ar1_c0Range>;

template <int NV>
using simple_ar1_multimod = parameter::list<simple_ar1_c0<NV>, parameter::empty>;

template <int NV>
using simple_ar1_t = wrap::no_data<envelope::simple_ar<NV, simple_ar1_multimod<NV>>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, simple_ar1_t<NV>>, 
                                   core::gain<NV>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain34_t>, 
                                    chain35_t<NV>>;

using global_cable_t_index = global_cable1_t_index;
using global_cable4_t_index = global_cable3_t_index;
using global_cable6_t_index = global_cable8_t_index;

template <int NV>
using peak7_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<routing::global_cable<global_cable_t_index, parameter::empty>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<routing::global_cable<global_cable4_t_index, parameter::empty>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<routing::global_cable<global_cable6_t_index, parameter::empty>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>>;

template <int NV>
using peak7_t = wrap::mod<peak7_mod<NV>, 
                          wrap::data<core::peak, data::external::displaybuffer<0>>>;

using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, routing::global_cable<global_cable_t_index, parameter::empty>>>;

using global_cable2_t_index = runtime_target::indexers::fix_hash<-1395393920>;
using change_mod = parameter::plain<routing::global_cable<global_cable2_t_index, parameter::empty>, 
                                    0>;
template <int NV>
using change_t = control::change<NV, change_mod>;
template <int NV>
using peak_t = wrap::mod<parameter::plain<change_t<NV>, 0>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::clear<NV>>, 
                                  math::add<NV>, 
                                  math::rect<NV>, 
                                  peak_t<NV>, 
                                  change_t<NV>, 
                                  routing::global_cable<global_cable2_t_index, parameter::empty>>;

using global_cable21_t_index = runtime_target::indexers::fix_hash<1752812596>;

namespace chain170_t_parameters
{
DECLARE_PARAMETER_RANGE_STEP(note_InputRange, 
                             0., 
                             127., 
                             1.);

using note = parameter::chain<note_InputRange, 
                              parameter::plain<routing::global_cable<global_cable21_t_index, parameter::empty>, 0>>;

}

using chain170_t = container::chain<chain170_t_parameters::note, 
                                    wrap::fix<1, routing::global_cable<global_cable21_t_index, parameter::empty>>>;
template <int NV>
using minmax2_t = control::minmax<NV, 
                                  parameter::plain<chain170_t, 0>>;
template <int NV>
using change3_t = control::change<NV, 
                                  parameter::plain<minmax2_t<NV>, 0>>;
template <int NV>
using peak14_t = wrap::mod<parameter::plain<change3_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain169_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax2_t<NV>>, 
                                    chain170_t>;

template <int NV>
using chain112_t = container::chain<parameter::empty, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    math::add<NV>, 
                                    peak14_t<NV>, 
                                    change3_t<NV>, 
                                    chain169_t<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<1, chain4_t>, 
                                 chain5_t<NV>, 
                                 chain112_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<1, split_t<NV>>>;

using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<1, routing::global_cable<global_cable4_t_index, parameter::empty>>>;

using global_cable5_t_index = runtime_target::indexers::fix_hash<-1395393919>;
using change1_mod = parameter::plain<routing::global_cable<global_cable5_t_index, parameter::empty>, 
                                     0>;
template <int NV>
using change1_t = control::change<NV, change1_mod>;
template <int NV>
using peak1_t = wrap::mod<parameter::plain<change1_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::clear<NV>>, 
                                  math::add<NV>, 
                                  math::rect<NV>, 
                                  peak1_t<NV>, 
                                  change1_t<NV>, 
                                  routing::global_cable<global_cable5_t_index, parameter::empty>>;

using global_cable22_t_index = runtime_target::indexers::fix_hash<1752812597>;

namespace chain172_t_parameters
{
DECLARE_PARAMETER_RANGE_STEP(note_InputRange, 
                             0., 
                             127., 
                             1.);

using note = parameter::chain<note_InputRange, 
                              parameter::plain<routing::global_cable<global_cable22_t_index, parameter::empty>, 0>>;

}

using chain172_t = container::chain<chain172_t_parameters::note, 
                                    wrap::fix<1, routing::global_cable<global_cable22_t_index, parameter::empty>>>;
template <int NV>
using minmax5_t = control::minmax<NV, 
                                  parameter::plain<chain172_t, 0>>;
template <int NV>
using change4_t = control::change<NV, 
                                  parameter::plain<minmax5_t<NV>, 0>>;
template <int NV>
using peak15_t = wrap::mod<parameter::plain<change4_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain171_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax5_t<NV>>, 
                                    chain172_t>;

template <int NV>
using chain113_t = container::chain<parameter::empty, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    math::add<NV>, 
                                    peak15_t<NV>, 
                                    change4_t<NV>, 
                                    chain171_t<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain6_t>, 
                                  chain7_t<NV>, 
                                  chain113_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, split2_t<NV>>>;

using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, routing::global_cable<global_cable6_t_index, parameter::empty>>>;

using global_cable7_t_index = runtime_target::indexers::fix_hash<-1395393918>;
using change2_mod = parameter::plain<routing::global_cable<global_cable7_t_index, parameter::empty>, 
                                     0>;
template <int NV>
using change2_t = control::change<NV, change2_mod>;
template <int NV>
using peak2_t = wrap::mod<parameter::plain<change2_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::clear<NV>>, 
                                  math::add<NV>, 
                                  math::rect<NV>, 
                                  peak2_t<NV>, 
                                  change2_t<NV>, 
                                  routing::global_cable<global_cable7_t_index, parameter::empty>>;

using global_cable23_t_index = runtime_target::indexers::fix_hash<1752812598>;

namespace chain174_t_parameters
{
DECLARE_PARAMETER_RANGE_STEP(note_InputRange, 
                             0., 
                             127., 
                             1.);

using note = parameter::chain<note_InputRange, 
                              parameter::plain<routing::global_cable<global_cable23_t_index, parameter::empty>, 0>>;

}

using chain174_t = container::chain<chain174_t_parameters::note, 
                                    wrap::fix<1, routing::global_cable<global_cable23_t_index, parameter::empty>>>;
template <int NV>
using minmax6_t = control::minmax<NV, 
                                  parameter::plain<chain174_t, 0>>;
template <int NV>
using change5_t = control::change<NV, 
                                  parameter::plain<minmax6_t<NV>, 0>>;
template <int NV>
using peak16_t = wrap::mod<parameter::plain<change5_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain173_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax6_t<NV>>, 
                                    chain174_t>;

template <int NV>
using chain114_t = container::chain<parameter::empty, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    math::add<NV>, 
                                    peak16_t<NV>, 
                                    change5_t<NV>, 
                                    chain173_t<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain8_t>, 
                                  chain9_t<NV>, 
                                  chain114_t<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, split3_t<NV>>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain_t<NV>>, 
                                   chain1_t<NV>, 
                                   chain2_t<NV>>;

namespace lfo_t_parameters
{
// Parameter list for lfo_impl::lfo_t --------------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(tempo_InputRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using tempo = parameter::chain<tempo_InputRange, 
                               parameter::plain<control::pma<NV, parameter::empty>, 2>>;

template <int NV>
using Clk = parameter::chain<ranges::Identity, 
                             parameter::plain<lfo_impl::input_toggle_t<NV>, 0>, 
                             parameter::plain<lfo_impl::input_toggle1_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(Freq_InputRange, 
                        0., 
                        40.);

template <int NV>
using Freq = parameter::chain<Freq_InputRange, 
                              parameter::plain<lfo_impl::pma3_t<NV>, 0>>;

template <int NV>
using TempoMod = parameter::chain<ranges::Identity, 
                                  parameter::plain<control::pma<NV, parameter::empty>, 1>, 
                                  parameter::plain<lfo_impl::pma3_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE(TempoSrc_InputRange, 
                        1., 
                        6.);

template <int NV>
using TempoSrc = parameter::chain<TempoSrc_InputRange, 
                                  parameter::plain<lfo_impl::xfader2_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(AdjustSrc_InputRange, 
                        1., 
                        6.);

template <int NV>
using AdjustSrc = parameter::chain<AdjustSrc_InputRange, 
                                   parameter::plain<lfo_impl::xfader3_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_STEP(Shape_InputRange, 
                             1., 
                             7., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Shape_0Range, 
                             0., 
                             6., 
                             1.);

template <int NV>
using Shape_0 = parameter::from0To1<lfo_impl::branch2_t<NV>, 
                                    0, 
                                    Shape_0Range>;

template <int NV>
using Shape = parameter::chain<Shape_InputRange, Shape_0<NV>>;

DECLARE_PARAMETER_RANGE(DivSrc_InputRange, 
                        1., 
                        6.);

template <int NV>
using DivSrc = parameter::chain<DivSrc_InputRange, 
                                parameter::plain<lfo_impl::xfader4_t<NV>, 0>>;

template <int NV>
using Min = parameter::chain<ranges::Identity, 
                             parameter::plain<lfo_impl::minmax2_t<NV>, 1>, 
                             parameter::plain<lfo_impl::minmax6_t<NV>, 1>, 
                             parameter::plain<lfo_impl::minmax5_t<NV>, 1>>;

template <int NV>
using Max = parameter::chain<ranges::Identity, 
                             parameter::plain<lfo_impl::minmax6_t<NV>, 2>, 
                             parameter::plain<lfo_impl::minmax5_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE(Step_InputRange, 
                        0., 
                        12.);
DECLARE_PARAMETER_RANGE(Step_0Range, 
                        0., 
                        12.);

template <int NV>
using Step_0 = parameter::from0To1<lfo_impl::minmax2_t<NV>, 
                                   4, 
                                   Step_0Range>;

DECLARE_PARAMETER_RANGE(Step_1Range, 
                        24., 
                        96.);

template <int NV>
using Step_1 = parameter::from0To1<lfo_impl::minmax2_t<NV>, 
                                   2, 
                                   Step_1Range>;

template <int NV>
using Step_2 = parameter::from0To1<lfo_impl::minmax6_t<NV>, 
                                   4, 
                                   Step_0Range>;

template <int NV>
using Step_3 = parameter::from0To1<lfo_impl::minmax5_t<NV>, 
                                   4, 
                                   Step_0Range>;

template <int NV>
using Step = parameter::chain<Step_InputRange, 
                              Step_0<NV>, 
                              Step_1<NV>, 
                              Step_2<NV>, 
                              Step_3<NV>>;

using div = parameter::empty;
using mode = div;
template <int NV>
using Dest = parameter::plain<lfo_impl::branch_t<NV>, 0>;
using AjustMode = div;
template <int NV>
using Div = parameter::plain<control::pma<NV, parameter::empty>, 
                             2>;
using Sync = div;
using phase = div;
using Fade = div;
using Trig = div;
template <int NV>
using Gate = parameter::plain<lfo_impl::branch3_t<NV>, 
                              0>;
template <int NV>
using Adjust = parameter::plain<lfo_impl::pma1_t<NV>, 2>;
template <int NV>
using AdjustMod = parameter::plain<lfo_impl::pma1_t<NV>, 1>;
template <int NV>
using DivMod = parameter::plain<control::pma<NV, parameter::empty>, 
                                1>;
template <int NV>
using lfo_t_plist = parameter::list<tempo<NV>, 
                                    div, 
                                    mode, 
                                    Dest<NV>, 
                                    AjustMode, 
                                    Clk<NV>, 
                                    Div<NV>, 
                                    Sync, 
                                    Freq<NV>, 
                                    phase, 
                                    Fade, 
                                    Trig, 
                                    Gate<NV>, 
                                    Adjust<NV>, 
                                    TempoMod<NV>, 
                                    TempoSrc<NV>, 
                                    AdjustMod<NV>, 
                                    AdjustSrc<NV>, 
                                    Shape<NV>, 
                                    DivMod<NV>, 
                                    DivSrc<NV>, 
                                    Min<NV>, 
                                    Max<NV>, 
                                    Step<NV>>;
}

template <int NV>
using lfo_t_ = container::chain<lfo_t_parameters::lfo_t_plist<NV>, 
                                wrap::fix<1, midichain_t<NV>>, 
                                chain11_t<NV>, 
                                branch3_t<NV>, 
                                peak7_t<NV>, 
                                wrap::no_process<math::sig2mod<NV>>, 
                                branch_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public lfo_impl::lfo_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 2;
		static const int NumSliderPacks = 4;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 1;
		
		SNEX_METADATA_ID(lfo);
		SNEX_METADATA_NUM_CHANNELS(1);
		SNEX_METADATA_ENCODED_PARAMETERS(374)
		{
			0x005B, 0x0000, 0x7400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0xC000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0001, 0x0000, 0x6964, 0x0076, 0x0000, 0x3F80, 0x0000, 0x4200, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x025B, 0x0000, 
            0x6D00, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 0x40A0, 0x0000, 
            0x4000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x035B, 0x0000, 0x4400, 
            0x7365, 0x0074, 0x0000, 0x0000, 0x0000, 0x4000, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x045B, 0x0000, 0x4100, 0x756A, 
            0x7473, 0x6F4D, 0x6564, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0005, 0x0000, 
            0x6C43, 0x006B, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x065B, 0x0000, 0x4400, 0x7669, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0007, 0x0000, 0x7953, 0x636E, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0008, 0x0000, 0x7246, 0x7165, 0x0000, 0x0000, 
            0x0000, 0x2000, 0x0042, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0009, 0x0000, 0x6870, 0x7361, 0x0065, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0A5B, 0x0000, 0x4600, 0x6461, 0x0065, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x999A, 0x3D37, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0B5B, 
            0x0000, 0x5400, 0x6972, 0x0067, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0C5B, 0x0000, 
            0x4700, 0x7461, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0D5B, 0x0000, 0x4100, 
            0x6A64, 0x7375, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0E5B, 0x0000, 0x5400, 
            0x6D65, 0x6F70, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0F5B, 0x0000, 
            0x5400, 0x6D65, 0x6F70, 0x7253, 0x0063, 0x0000, 0x3F80, 0x0000, 
            0x40C0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x105B, 
            0x0000, 0x4100, 0x6A64, 0x7375, 0x4D74, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0011, 0x0000, 0x6441, 0x756A, 0x7473, 0x7253, 0x0063, 
            0x0000, 0x3F80, 0x0000, 0x40C0, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x125B, 0x0000, 0x5300, 0x6168, 0x6570, 0x0000, 
            0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0013, 0x0000, 0x6944, 0x4D76, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0014, 0x0000, 0x6944, 0x5376, 0x6372, 0x0000, 
            0x8000, 0x003F, 0xC000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0015, 0x0000, 0x694D, 0x006E, 0x0000, 0x41C0, 
            0x0000, 0x42C0, 0x0000, 0x41C0, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x165B, 0x0000, 0x4D00, 0x7861, 0x0000, 0xC000, 0x0041, 0xC000, 
            0x0042, 0xC000, 0x0042, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0017, 
            0x0000, 0x7453, 0x7065, 0x0000, 0x0000, 0x0000, 0x4000, 0x0041, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& midichain = this->getT(0);                                                      // lfo_impl::midichain_t<NV>
		auto& split11 = this->getT(0).getT(0);                                                // lfo_impl::split11_t<NV>
		auto& modchain = this->getT(0).getT(0).getT(0);                                       // lfo_impl::modchain_t<NV>
		auto& xfader2 = this->getT(0).getT(0).getT(0).getT(0);                                // lfo_impl::xfader2_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(0).getT(1);                                 // lfo_impl::split7_t<NV>
		auto& chain52 = this->getT(0).getT(0).getT(0).getT(1).getT(0);                        // lfo_impl::chain52_t<NV>
		auto& split8 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);                 // lfo_impl::split8_t<NV>
		auto& chain38 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);        // lfo_impl::chain38_t<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(0).getT(1).                          // lfo_impl::global_cable1_t<NV>
                              getT(0).getT(0).getT(0).getT(0);
		auto& add10 = this->getT(0).getT(0).getT(0).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1);
		auto& gain6 = this->getT(0).getT(0).getT(0).getT(1).                                  // core::gain<NV>
                      getT(0).getT(0).getT(0).getT(2);
		auto& chain39 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1);        // lfo_impl::chain39_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(0).getT(1).                          // lfo_impl::global_cable3_t<NV>
                              getT(0).getT(0).getT(1).getT(0);
		auto& add11 = this->getT(0).getT(0).getT(0).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1);
		auto& gain9 = this->getT(0).getT(0).getT(0).getT(1).                                  // core::gain<NV>
                      getT(0).getT(0).getT(1).getT(2);
		auto& chain40 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).getT(2);        // lfo_impl::chain40_t<NV>
		auto& global_cable8 = this->getT(0).getT(0).getT(0).getT(1).                          // lfo_impl::global_cable8_t<NV>
                              getT(0).getT(0).getT(2).getT(0);
		auto& add12 = this->getT(0).getT(0).getT(0).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(2).getT(1);
		auto& gain8 = this->getT(0).getT(0).getT(0).getT(1).                                  // core::gain<NV>
                      getT(0).getT(0).getT(2).getT(2);
		auto& chain41 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).getT(3);        // lfo_impl::chain41_t<NV>
		auto& event_data_reader = this->getT(0).getT(0).getT(0).getT(1).                      // lfo_impl::event_data_reader_t<NV>
                                  getT(0).getT(0).getT(3).getT(0);
		auto& add13 = this->getT(0).getT(0).getT(0).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(3).getT(1);
		auto& gain7 = this->getT(0).getT(0).getT(0).getT(1).                                  // core::gain<NV>
                      getT(0).getT(0).getT(3).getT(2);
		auto& chain42 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).getT(4);        // lfo_impl::chain42_t<NV>
		auto& event_data_reader2 = this->getT(0).getT(0).getT(0).getT(1).                     // lfo_impl::event_data_reader2_t<NV>
                                   getT(0).getT(0).getT(4).getT(0);
		auto& add14 = this->getT(0).getT(0).getT(0).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(4).getT(1);
		auto& gain10 = this->getT(0).getT(0).getT(0).getT(1).                                 // core::gain<NV>
                       getT(0).getT(0).getT(4).getT(2);
		auto& chain43 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).getT(5);        // lfo_impl::chain43_t<NV>
		auto& event_data_reader1 = this->getT(0).getT(0).getT(0).getT(1).                     // lfo_impl::event_data_reader1_t<NV>
                                   getT(0).getT(0).getT(5).getT(0);
		auto& add15 = this->getT(0).getT(0).getT(0).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(5).getT(1);
		auto& gain29 = this->getT(0).getT(0).getT(0).getT(1).                                 // core::gain<NV>
                       getT(0).getT(0).getT(5).getT(2);
		auto& peak9 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);                  // lfo_impl::peak9_t<NV>
		auto& split1 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2);                 // lfo_impl::split1_t<NV>
		auto& pma = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2).getT(0);            // control::pma<NV, parameter::empty>
		auto& pma3 = this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(2).getT(1);           // lfo_impl::pma3_t<NV>
		auto& modchain1 = this->getT(0).getT(0).getT(1);                                      // lfo_impl::modchain1_t<NV>
		auto& xfader3 = this->getT(0).getT(0).getT(1).getT(0);                                // lfo_impl::xfader3_t<NV>
		auto& split12 = this->getT(0).getT(0).getT(1).getT(1);                                // lfo_impl::split12_t<NV>
		auto& chain96 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                        // lfo_impl::chain96_t<NV>
		auto& split13 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(0);                // lfo_impl::split13_t<NV>
		auto& chain97 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(0).getT(0);        // lfo_impl::chain97_t<NV>
		auto& global_cable15 = this->getT(0).getT(0).getT(1).getT(1).                         // lfo_impl::global_cable15_t<NV>
                               getT(0).getT(0).getT(0).getT(0);
		auto& add31 = this->getT(0).getT(0).getT(1).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1);
		auto& gain77 = this->getT(0).getT(0).getT(1).getT(1).                                 // core::gain<NV>
                       getT(0).getT(0).getT(0).getT(2);
		auto& chain98 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(0).getT(1);        // lfo_impl::chain98_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(1).getT(1).                         // lfo_impl::global_cable16_t<NV>
                               getT(0).getT(0).getT(1).getT(0);
		auto& add32 = this->getT(0).getT(0).getT(1).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1);
		auto& gain78 = this->getT(0).getT(0).getT(1).getT(1).                                 // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(2);
		auto& chain99 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(0).getT(2);        // lfo_impl::chain99_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(1).getT(1).                         // lfo_impl::global_cable17_t<NV>
                               getT(0).getT(0).getT(2).getT(0);
		auto& add33 = this->getT(0).getT(0).getT(1).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(2).getT(1);
		auto& gain79 = this->getT(0).getT(0).getT(1).getT(1).                                 // core::gain<NV>
                       getT(0).getT(0).getT(2).getT(2);
		auto& chain100 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(0).getT(3);       // lfo_impl::chain100_t<NV>
		auto& event_data_reader12 = this->getT(0).getT(0).getT(1).getT(1).                    // lfo_impl::event_data_reader12_t<NV>
                                    getT(0).getT(0).getT(3).getT(0);
		auto& add34 = this->getT(0).getT(0).getT(1).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(3).getT(1);
		auto& gain80 = this->getT(0).getT(0).getT(1).getT(1).                                 // core::gain<NV>
                       getT(0).getT(0).getT(3).getT(2);
		auto& chain101 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(0).getT(4);       // lfo_impl::chain101_t<NV>
		auto& event_data_reader13 = this->getT(0).getT(0).getT(1).getT(1).                    // lfo_impl::event_data_reader13_t<NV>
                                    getT(0).getT(0).getT(4).getT(0);
		auto& add35 = this->getT(0).getT(0).getT(1).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(4).getT(1);
		auto& gain81 = this->getT(0).getT(0).getT(1).getT(1).                                 // core::gain<NV>
                       getT(0).getT(0).getT(4).getT(2);
		auto& chain102 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(0).getT(5);       // lfo_impl::chain102_t<NV>
		auto& event_data_reader14 = this->getT(0).getT(0).getT(1).getT(1).                    // lfo_impl::event_data_reader14_t<NV>
                                    getT(0).getT(0).getT(5).getT(0);
		auto& add36 = this->getT(0).getT(0).getT(1).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(5).getT(1);
		auto& gain82 = this->getT(0).getT(0).getT(1).getT(1).                                 // core::gain<NV>
                       getT(0).getT(0).getT(5).getT(2);
		auto& peak12 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(1);                 // lfo_impl::peak12_t<NV>
		auto& pma1 = this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(2);                   // lfo_impl::pma1_t<NV>
		auto& modchain2 = this->getT(0).getT(0).getT(2);                                      // lfo_impl::modchain2_t<NV>
		auto& xfader4 = this->getT(0).getT(0).getT(2).getT(0);                                // lfo_impl::xfader4_t<NV>
		auto& split14 = this->getT(0).getT(0).getT(2).getT(1);                                // lfo_impl::split14_t<NV>
		auto& chain103 = this->getT(0).getT(0).getT(2).getT(1).getT(0);                       // lfo_impl::chain103_t<NV>
		auto& split15 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0);                // lfo_impl::split15_t<NV>
		auto& chain104 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).getT(0);       // lfo_impl::chain104_t<NV>
		auto& global_cable18 = this->getT(0).getT(0).getT(2).getT(1).                         // lfo_impl::global_cable18_t<NV>
                               getT(0).getT(0).getT(0).getT(0);
		auto& add37 = this->getT(0).getT(0).getT(2).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(0).getT(1);
		auto& gain83 = this->getT(0).getT(0).getT(2).getT(1).                                 // core::gain<NV>
                       getT(0).getT(0).getT(0).getT(2);
		auto& chain105 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).getT(1);       // lfo_impl::chain105_t<NV>
		auto& global_cable19 = this->getT(0).getT(0).getT(2).getT(1).                         // lfo_impl::global_cable19_t<NV>
                               getT(0).getT(0).getT(1).getT(0);
		auto& add38 = this->getT(0).getT(0).getT(2).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1);
		auto& gain84 = this->getT(0).getT(0).getT(2).getT(1).                                 // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(2);
		auto& chain106 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).getT(2);       // lfo_impl::chain106_t<NV>
		auto& global_cable20 = this->getT(0).getT(0).getT(2).getT(1).                         // lfo_impl::global_cable20_t<NV>
                               getT(0).getT(0).getT(2).getT(0);
		auto& add39 = this->getT(0).getT(0).getT(2).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(2).getT(1);
		auto& gain85 = this->getT(0).getT(0).getT(2).getT(1).                                 // core::gain<NV>
                       getT(0).getT(0).getT(2).getT(2);
		auto& chain107 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).getT(3);       // lfo_impl::chain107_t<NV>
		auto& event_data_reader15 = this->getT(0).getT(0).getT(2).getT(1).                    // lfo_impl::event_data_reader15_t<NV>
                                    getT(0).getT(0).getT(3).getT(0);
		auto& add40 = this->getT(0).getT(0).getT(2).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(3).getT(1);
		auto& gain86 = this->getT(0).getT(0).getT(2).getT(1).                                 // core::gain<NV>
                       getT(0).getT(0).getT(3).getT(2);
		auto& chain108 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).getT(4);       // lfo_impl::chain108_t<NV>
		auto& event_data_reader16 = this->getT(0).getT(0).getT(2).getT(1).                    // lfo_impl::event_data_reader16_t<NV>
                                    getT(0).getT(0).getT(4).getT(0);
		auto& add41 = this->getT(0).getT(0).getT(2).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(4).getT(1);
		auto& gain87 = this->getT(0).getT(0).getT(2).getT(1).                                 // core::gain<NV>
                       getT(0).getT(0).getT(4).getT(2);
		auto& chain109 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).getT(5);       // lfo_impl::chain109_t<NV>
		auto& event_data_reader17 = this->getT(0).getT(0).getT(2).getT(1).                    // lfo_impl::event_data_reader17_t<NV>
                                    getT(0).getT(0).getT(5).getT(0);
		auto& add42 = this->getT(0).getT(0).getT(2).getT(1).                                  // math::add<NV>
                      getT(0).getT(0).getT(5).getT(1);
		auto& gain88 = this->getT(0).getT(0).getT(2).getT(1).                                 // core::gain<NV>
                       getT(0).getT(0).getT(5).getT(2);
		auto& peak13 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(1);                 // lfo_impl::peak13_t<NV>
		auto& pma2 = this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(2);                   // control::pma<NV, parameter::empty>
		auto& chain11 = this->getT(1);                                                        // lfo_impl::chain11_t<NV>
		auto& branch2 = this->getT(1).getT(0);                                                // lfo_impl::branch2_t<NV>
		auto& chain25 = this->getT(1).getT(0).getT(0);                                        // lfo_impl::chain25_t<NV>
		auto& pi2 = this->getT(1).getT(0).getT(0).getT(0);                                    // math::pi<NV>
		auto& sin3 = this->getT(1).getT(0).getT(0).getT(1);                                   // math::sin<NV>
		auto& sig2mod4 = this->getT(1).getT(0).getT(0).getT(2);                               // wrap::no_process<math::sig2mod<NV>>
		auto& chain24 = this->getT(1).getT(0).getT(1);                                        // lfo_impl::chain24_t<NV>
		auto& mul2 = this->getT(1).getT(0).getT(1).getT(0);                                   // wrap::no_process<math::mul<NV>>
		auto& sig2mod3 = this->getT(1).getT(0).getT(1).getT(1);                               // wrap::no_process<math::sig2mod<NV>>
		auto& chain14 = this->getT(1).getT(0).getT(2);                                        // lfo_impl::chain14_t<NV>
		auto& add6 = this->getT(1).getT(0).getT(2).getT(0);                                   // math::add<NV>
		auto& fmod3 = this->getT(1).getT(0).getT(2).getT(1);                                  // math::fmod<NV>
		auto& sub = this->getT(1).getT(0).getT(2).getT(2);                                    // math::sub<NV>
		auto& abs = this->getT(1).getT(0).getT(2).getT(3);                                    // math::abs<NV>
		auto& mul1 = this->getT(1).getT(0).getT(2).getT(4);                                   // math::mul<NV>
		auto& chain18 = this->getT(1).getT(0).getT(3);                                        // lfo_impl::chain18_t<NV>
		auto& mod_inv1 = this->getT(1).getT(0).getT(3).getT(0);                               // math::mod_inv<NV>
		auto& rect3 = this->getT(1).getT(0).getT(3).getT(1);                                  // math::rect<NV>
		auto& chain31 = this->getT(1).getT(0).getT(4);                                        // lfo_impl::chain31_t<NV>
		auto& oscillator = this->getT(1).getT(0).getT(4).getT(0);                             // lfo_impl::oscillator_t<NV>
		auto& chain32 = this->getT(1).getT(0).getT(5);                                        // lfo_impl::chain32_t<NV>
		auto& input_toggle = this->getT(1).getT(0).getT(5).getT(0);                           // lfo_impl::input_toggle_t<NV>
		auto& clear1 = this->getT(1).getT(0).getT(5).getT(1);                                 // wrap::no_process<math::clear<NV>>
		auto& cable_table = this->getT(1).getT(0).getT(5).getT(2);                            // lfo_impl::cable_table_t<NV>
		auto& add8 = this->getT(1).getT(0).getT(5).getT(3);                                   // math::add<NV>
		auto& chain33 = this->getT(1).getT(0).getT(6);                                        // lfo_impl::chain33_t<NV>
		auto& input_toggle1 = this->getT(1).getT(0).getT(6).getT(0);                          // lfo_impl::input_toggle1_t<NV>
		auto& clear2 = this->getT(1).getT(0).getT(6).getT(1);                                 // wrap::no_process<math::clear<NV>>
		auto& cable_pack = this->getT(1).getT(0).getT(6).getT(2);                             // lfo_impl::cable_pack_t<NV>
		auto& add9 = this->getT(1).getT(0).getT(6).getT(3);                                   // math::add<NV>
		auto& gain89 = this->getT(1).getT(1);                                                 // core::gain<NV>
		auto& branch3 = this->getT(2);                                                        // lfo_impl::branch3_t<NV>
		auto& chain34 = this->getT(2).getT(0);                                                // lfo_impl::chain34_t
		auto& chain35 = this->getT(2).getT(1);                                                // lfo_impl::chain35_t<NV>
		auto& simple_ar1 = this->getT(2).getT(1).getT(0);                                     // lfo_impl::simple_ar1_t<NV>
		auto& gain51 = this->getT(2).getT(1).getT(1);                                         // core::gain<NV>
		auto& peak7 = this->getT(3);                                                          // lfo_impl::peak7_t<NV>
		auto& sig2mod = this->getT(4);                                                        // wrap::no_process<math::sig2mod<NV>>
		auto& branch = this->getT(5);                                                         // lfo_impl::branch_t<NV>
		auto& chain = this->getT(5).getT(0);                                                  // lfo_impl::chain_t<NV>
		auto& split = this->getT(5).getT(0).getT(0);                                          // lfo_impl::split_t<NV>
		auto& chain4 = this->getT(5).getT(0).getT(0).getT(0);                                 // lfo_impl::chain4_t
		auto& global_cable = this->getT(5).getT(0).getT(0).getT(0).getT(0);                   // routing::global_cable<global_cable_t_index, parameter::empty>
		auto& chain5 = this->getT(5).getT(0).getT(0).getT(1);                                 // lfo_impl::chain5_t<NV>
		auto& clear = this->getT(5).getT(0).getT(0).getT(1).getT(0);                          // math::clear<NV>
		auto& add = this->getT(5).getT(0).getT(0).getT(1).getT(1);                            // math::add<NV>
		auto& rect = this->getT(5).getT(0).getT(0).getT(1).getT(2);                           // math::rect<NV>
		auto& peak = this->getT(5).getT(0).getT(0).getT(1).getT(3);                           // lfo_impl::peak_t<NV>
		auto& change = this->getT(5).getT(0).getT(0).getT(1).getT(4);                         // lfo_impl::change_t<NV>
		auto& global_cable2 = this->getT(5).getT(0).getT(0).getT(1).getT(5);                  // routing::global_cable<global_cable2_t_index, parameter::empty>
		auto& chain112 = this->getT(5).getT(0).getT(0).getT(2);                               // lfo_impl::chain112_t<NV>
		auto& clear3 = this->getT(5).getT(0).getT(0).getT(2).getT(0);                         // math::clear<NV>
		auto& add43 = this->getT(5).getT(0).getT(0).getT(2).getT(1);                          // math::add<NV>
		auto& peak14 = this->getT(5).getT(0).getT(0).getT(2).getT(2);                         // lfo_impl::peak14_t<NV>
		auto& change3 = this->getT(5).getT(0).getT(0).getT(2).getT(3);                        // lfo_impl::change3_t<NV>
		auto& chain169 = this->getT(5).getT(0).getT(0).getT(2).getT(4);                       // lfo_impl::chain169_t<NV>
		auto& minmax2 = this->getT(5).getT(0).getT(0).getT(2).getT(4).getT(0);                // lfo_impl::minmax2_t<NV>
		auto& chain170 = this->getT(5).getT(0).getT(0).getT(2).getT(4).getT(1);               // lfo_impl::chain170_t
		auto& global_cable21 = this->getT(5).getT(0).getT(0).getT(2).getT(4).getT(1).getT(0); // routing::global_cable<global_cable21_t_index, parameter::empty>
		auto& chain1 = this->getT(5).getT(1);                                                 // lfo_impl::chain1_t<NV>
		auto& split2 = this->getT(5).getT(1).getT(0);                                         // lfo_impl::split2_t<NV>
		auto& chain6 = this->getT(5).getT(1).getT(0).getT(0);                                 // lfo_impl::chain6_t
		auto& global_cable4 = this->getT(5).getT(1).getT(0).getT(0).getT(0);                  // routing::global_cable<global_cable4_t_index, parameter::empty>
		auto& chain7 = this->getT(5).getT(1).getT(0).getT(1);                                 // lfo_impl::chain7_t<NV>
		auto& clear4 = this->getT(5).getT(1).getT(0).getT(1).getT(0);                         // math::clear<NV>
		auto& add1 = this->getT(5).getT(1).getT(0).getT(1).getT(1);                           // math::add<NV>
		auto& rect1 = this->getT(5).getT(1).getT(0).getT(1).getT(2);                          // math::rect<NV>
		auto& peak1 = this->getT(5).getT(1).getT(0).getT(1).getT(3);                          // lfo_impl::peak1_t<NV>
		auto& change1 = this->getT(5).getT(1).getT(0).getT(1).getT(4);                        // lfo_impl::change1_t<NV>
		auto& global_cable5 = this->getT(5).getT(1).getT(0).getT(1).getT(5);                  // routing::global_cable<global_cable5_t_index, parameter::empty>
		auto& chain113 = this->getT(5).getT(1).getT(0).getT(2);                               // lfo_impl::chain113_t<NV>
		auto& clear5 = this->getT(5).getT(1).getT(0).getT(2).getT(0);                         // math::clear<NV>
		auto& add44 = this->getT(5).getT(1).getT(0).getT(2).getT(1);                          // math::add<NV>
		auto& peak15 = this->getT(5).getT(1).getT(0).getT(2).getT(2);                         // lfo_impl::peak15_t<NV>
		auto& change4 = this->getT(5).getT(1).getT(0).getT(2).getT(3);                        // lfo_impl::change4_t<NV>
		auto& chain171 = this->getT(5).getT(1).getT(0).getT(2).getT(4);                       // lfo_impl::chain171_t<NV>
		auto& minmax5 = this->getT(5).getT(1).getT(0).getT(2).getT(4).getT(0);                // lfo_impl::minmax5_t<NV>
		auto& chain172 = this->getT(5).getT(1).getT(0).getT(2).getT(4).getT(1);               // lfo_impl::chain172_t
		auto& global_cable22 = this->getT(5).getT(1).getT(0).getT(2).getT(4).getT(1).getT(0); // routing::global_cable<global_cable22_t_index, parameter::empty>
		auto& chain2 = this->getT(5).getT(2);                                                 // lfo_impl::chain2_t<NV>
		auto& split3 = this->getT(5).getT(2).getT(0);                                         // lfo_impl::split3_t<NV>
		auto& chain8 = this->getT(5).getT(2).getT(0).getT(0);                                 // lfo_impl::chain8_t
		auto& global_cable6 = this->getT(5).getT(2).getT(0).getT(0).getT(0);                  // routing::global_cable<global_cable6_t_index, parameter::empty>
		auto& chain9 = this->getT(5).getT(2).getT(0).getT(1);                                 // lfo_impl::chain9_t<NV>
		auto& clear6 = this->getT(5).getT(2).getT(0).getT(1).getT(0);                         // math::clear<NV>
		auto& add2 = this->getT(5).getT(2).getT(0).getT(1).getT(1);                           // math::add<NV>
		auto& rect2 = this->getT(5).getT(2).getT(0).getT(1).getT(2);                          // math::rect<NV>
		auto& peak2 = this->getT(5).getT(2).getT(0).getT(1).getT(3);                          // lfo_impl::peak2_t<NV>
		auto& change2 = this->getT(5).getT(2).getT(0).getT(1).getT(4);                        // lfo_impl::change2_t<NV>
		auto& global_cable7 = this->getT(5).getT(2).getT(0).getT(1).getT(5);                  // routing::global_cable<global_cable7_t_index, parameter::empty>
		auto& chain114 = this->getT(5).getT(2).getT(0).getT(2);                               // lfo_impl::chain114_t<NV>
		auto& clear7 = this->getT(5).getT(2).getT(0).getT(2).getT(0);                         // math::clear<NV>
		auto& add45 = this->getT(5).getT(2).getT(0).getT(2).getT(1);                          // math::add<NV>
		auto& peak16 = this->getT(5).getT(2).getT(0).getT(2).getT(2);                         // lfo_impl::peak16_t<NV>
		auto& change5 = this->getT(5).getT(2).getT(0).getT(2).getT(3);                        // lfo_impl::change5_t<NV>
		auto& chain173 = this->getT(5).getT(2).getT(0).getT(2).getT(4);                       // lfo_impl::chain173_t<NV>
		auto& minmax6 = this->getT(5).getT(2).getT(0).getT(2).getT(4).getT(0);                // lfo_impl::minmax6_t<NV>
		auto& chain174 = this->getT(5).getT(2).getT(0).getT(2).getT(4).getT(1);               // lfo_impl::chain174_t
		auto& global_cable23 = this->getT(5).getT(2).getT(0).getT(2).getT(4).getT(1).getT(0); // routing::global_cable<global_cable23_t_index, parameter::empty>
		
		// Parameter Connections -------------------------------------------------------------------
		
		chain170.getParameterT(0).connectT(0, global_cable21); // note -> global_cable21::Value
		chain170.getParameterT(0).connectT(0, global_cable21); // note -> global_cable21::Value
		chain172.getParameterT(0).connectT(0, global_cable22); // note -> global_cable22::Value
		chain172.getParameterT(0).connectT(0, global_cable22); // note -> global_cable22::Value
		chain174.getParameterT(0).connectT(0, global_cable23); // note -> global_cable23::Value
		chain174.getParameterT(0).connectT(0, global_cable23); // note -> global_cable23::Value
		this->getParameterT(0).connectT(0, pma);               // tempo -> pma::Add
		
		this->getParameterT(3).connectT(0, branch); // Dest -> branch::Index
		
		auto& Clk_p = this->getParameterT(5);
		Clk_p.connectT(0, input_toggle);  // Clk -> input_toggle::Input
		Clk_p.connectT(1, input_toggle1); // Clk -> input_toggle1::Input
		
		this->getParameterT(6).connectT(0, pma2); // Div -> pma2::Add
		
		this->getParameterT(8).connectT(0, pma3); // Freq -> pma3::Value
		
		this->getParameterT(12).connectT(0, branch3); // Gate -> branch3::Index
		
		this->getParameterT(13).connectT(0, pma1); // Adjust -> pma1::Add
		
		auto& TempoMod_p = this->getParameterT(14);
		TempoMod_p.connectT(0, pma);  // TempoMod -> pma::Multiply
		TempoMod_p.connectT(1, pma3); // TempoMod -> pma3::Multiply
		
		this->getParameterT(15).connectT(0, xfader2); // TempoSrc -> xfader2::Value
		
		this->getParameterT(16).connectT(0, pma1); // AdjustMod -> pma1::Multiply
		
		this->getParameterT(17).connectT(0, xfader3); // AdjustSrc -> xfader3::Value
		
		this->getParameterT(18).connectT(0, branch2); // Shape -> branch2::Index
		
		this->getParameterT(19).connectT(0, pma2); // DivMod -> pma2::Multiply
		
		this->getParameterT(20).connectT(0, xfader4); // DivSrc -> xfader4::Value
		
		auto& Min_p = this->getParameterT(21);
		Min_p.connectT(0, minmax2); // Min -> minmax2::Minimum
		Min_p.connectT(1, minmax6); // Min -> minmax6::Minimum
		Min_p.connectT(2, minmax5); // Min -> minmax5::Minimum
		
		auto& Max_p = this->getParameterT(22);
		Max_p.connectT(0, minmax6); // Max -> minmax6::Maximum
		Max_p.connectT(1, minmax5); // Max -> minmax5::Maximum
		
		auto& Step_p = this->getParameterT(23);
		Step_p.connectT(0, minmax2); // Step -> minmax2::Step
		Step_p.connectT(1, minmax2); // Step -> minmax2::Maximum
		Step_p.connectT(2, minmax6); // Step -> minmax6::Step
		Step_p.connectT(3, minmax5); // Step -> minmax5::Step
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& xfader2_p = xfader2.getWrappedObject().getParameter();
		xfader2_p.getParameterT(0).connectT(0, gain6);                           // xfader2 -> gain6::Gain
		xfader2_p.getParameterT(1).connectT(0, gain9);                           // xfader2 -> gain9::Gain
		xfader2_p.getParameterT(2).connectT(0, gain8);                           // xfader2 -> gain8::Gain
		xfader2_p.getParameterT(3).connectT(0, gain7);                           // xfader2 -> gain7::Gain
		xfader2_p.getParameterT(4).connectT(0, gain10);                          // xfader2 -> gain10::Gain
		xfader2_p.getParameterT(5).connectT(0, gain29);                          // xfader2 -> gain29::Gain
		global_cable1.getWrappedObject().getParameter().connectT(0, add10);      // global_cable1 -> add10::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add11);      // global_cable3 -> add11::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, add12);      // global_cable8 -> add12::Value
		event_data_reader.getParameter().connectT(0, add13);                     // event_data_reader -> add13::Value
		event_data_reader2.getParameter().connectT(0, add14);                    // event_data_reader2 -> add14::Value
		event_data_reader1.getParameter().connectT(0, add15);                    // event_data_reader1 -> add15::Value
		peak9.getParameter().connectT(0, pma);                                   // peak9 -> pma::Value
		cable_table.getWrappedObject().getParameter().connectT(0, add8);         // cable_table -> add8::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, cable_table); // input_toggle -> cable_table::Value
		cable_pack.getWrappedObject().getParameter().connectT(0, add9);          // cable_pack -> add9::Value
		input_toggle1.getWrappedObject().getParameter().connectT(0, cable_pack); // input_toggle1 -> cable_pack::Value
		pma3.getWrappedObject().getParameter().connectT(0, chain11);             // pma3 -> chain11::freq
		auto& xfader3_p = xfader3.getWrappedObject().getParameter();
		xfader3_p.getParameterT(0).connectT(0, gain77);                      // xfader3 -> gain77::Gain
		xfader3_p.getParameterT(1).connectT(0, gain78);                      // xfader3 -> gain78::Gain
		xfader3_p.getParameterT(2).connectT(0, gain79);                      // xfader3 -> gain79::Gain
		xfader3_p.getParameterT(3).connectT(0, gain80);                      // xfader3 -> gain80::Gain
		xfader3_p.getParameterT(4).connectT(0, gain81);                      // xfader3 -> gain81::Gain
		xfader3_p.getParameterT(5).connectT(0, gain82);                      // xfader3 -> gain82::Gain
		global_cable15.getWrappedObject().getParameter().connectT(0, add31); // global_cable15 -> add31::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add32); // global_cable16 -> add32::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add33); // global_cable17 -> add33::Value
		event_data_reader12.getParameter().connectT(0, add34);               // event_data_reader12 -> add34::Value
		event_data_reader13.getParameter().connectT(0, add35);               // event_data_reader13 -> add35::Value
		event_data_reader14.getParameter().connectT(0, add36);               // event_data_reader14 -> add36::Value
		pma1.getWrappedObject().getParameter().connectT(0, gain89);          // pma1 -> gain89::Gain
		peak12.getParameter().connectT(0, pma1);                             // peak12 -> pma1::Value
		auto& xfader4_p = xfader4.getWrappedObject().getParameter();
		xfader4_p.getParameterT(0).connectT(0, gain83);                      // xfader4 -> gain83::Gain
		xfader4_p.getParameterT(1).connectT(0, gain84);                      // xfader4 -> gain84::Gain
		xfader4_p.getParameterT(2).connectT(0, gain85);                      // xfader4 -> gain85::Gain
		xfader4_p.getParameterT(3).connectT(0, gain86);                      // xfader4 -> gain86::Gain
		xfader4_p.getParameterT(4).connectT(0, gain87);                      // xfader4 -> gain87::Gain
		xfader4_p.getParameterT(5).connectT(0, gain88);                      // xfader4 -> gain88::Gain
		global_cable18.getWrappedObject().getParameter().connectT(0, add37); // global_cable18 -> add37::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add38); // global_cable19 -> add38::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add39); // global_cable20 -> add39::Value
		event_data_reader15.getParameter().connectT(0, add40);               // event_data_reader15 -> add40::Value
		event_data_reader16.getParameter().connectT(0, add41);               // event_data_reader16 -> add41::Value
		event_data_reader17.getParameter().connectT(0, add42);               // event_data_reader17 -> add42::Value
		peak13.getParameter().connectT(0, pma2);                             // peak13 -> pma2::Value
		auto& simple_ar1_p = simple_ar1.getWrappedObject().getParameter();
		simple_ar1_p.getParameterT(0).connectT(0, gain51);                    // simple_ar1 -> gain51::Gain
		peak7.getParameter().connectT(0, global_cable);                       // peak7 -> global_cable::Value
		peak7.getParameter().connectT(1, add);                                // peak7 -> add::Value
		peak7.getParameter().connectT(2, add43);                              // peak7 -> add43::Value
		peak7.getParameter().connectT(3, global_cable4);                      // peak7 -> global_cable4::Value
		peak7.getParameter().connectT(4, add1);                               // peak7 -> add1::Value
		peak7.getParameter().connectT(5, add44);                              // peak7 -> add44::Value
		peak7.getParameter().connectT(6, global_cable6);                      // peak7 -> global_cable6::Value
		peak7.getParameter().connectT(7, add2);                               // peak7 -> add2::Value
		peak7.getParameter().connectT(8, add45);                              // peak7 -> add45::Value
		change.getWrappedObject().getParameter().connectT(0, global_cable2);  // change -> global_cable2::Value
		peak.getParameter().connectT(0, change);                              // peak -> change::Value
		minmax2.getWrappedObject().getParameter().connectT(0, chain170);      // minmax2 -> chain170::note
		change3.getWrappedObject().getParameter().connectT(0, minmax2);       // change3 -> minmax2::Value
		peak14.getParameter().connectT(0, change3);                           // peak14 -> change3::Value
		change1.getWrappedObject().getParameter().connectT(0, global_cable5); // change1 -> global_cable5::Value
		peak1.getParameter().connectT(0, change1);                            // peak1 -> change1::Value
		minmax5.getWrappedObject().getParameter().connectT(0, chain172);      // minmax5 -> chain172::note
		change4.getWrappedObject().getParameter().connectT(0, minmax5);       // change4 -> minmax5::Value
		peak15.getParameter().connectT(0, change4);                           // peak15 -> change4::Value
		change2.getWrappedObject().getParameter().connectT(0, global_cable7); // change2 -> global_cable7::Value
		peak2.getParameter().connectT(0, change2);                            // peak2 -> change2::Value
		minmax6.getWrappedObject().getParameter().connectT(0, chain174);      // minmax6 -> chain174::note
		change5.getWrappedObject().getParameter().connectT(0, minmax6);       // change5 -> minmax6::Value
		peak16.getParameter().connectT(0, change5);                           // peak16 -> change5::Value
		
		// Default Values --------------------------------------------------------------------------
		
		; // xfader2::Value is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		;                            // gain6::Gain is automated
		gain6.setParameterT(1, 20.); // core::gain::Smoothing
		gain6.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add11::Value is automated
		
		;                            // gain9::Gain is automated
		gain9.setParameterT(1, 20.); // core::gain::Smoothing
		gain9.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		;                            // gain8::Gain is automated
		gain8.setParameterT(1, 20.); // core::gain::Smoothing
		gain8.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add13::Value is automated
		
		;                            // gain7::Gain is automated
		gain7.setParameterT(1, 20.); // core::gain::Smoothing
		gain7.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader2.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader2.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add14::Value is automated
		
		;                             // gain10::Gain is automated
		gain10.setParameterT(1, 20.); // core::gain::Smoothing
		gain10.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader1.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader1.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add15::Value is automated
		
		;                             // gain29::Gain is automated
		gain29.setParameterT(1, 20.); // core::gain::Smoothing
		gain29.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		;                                 // pma3::Value is automated
		;                                 // pma3::Multiply is automated
		pma3.setParameterT(2, 0.0829937); // control::pma::Add
		
		; // xfader3::Value is automated
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add31::Value is automated
		
		;                             // gain77::Gain is automated
		gain77.setParameterT(1, 20.); // core::gain::Smoothing
		gain77.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add32::Value is automated
		
		;                             // gain78::Gain is automated
		gain78.setParameterT(1, 20.); // core::gain::Smoothing
		gain78.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add33::Value is automated
		
		;                             // gain79::Gain is automated
		gain79.setParameterT(1, 20.); // core::gain::Smoothing
		gain79.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader12.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader12.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add34::Value is automated
		
		;                             // gain80::Gain is automated
		gain80.setParameterT(1, 20.); // core::gain::Smoothing
		gain80.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader13.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader13.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add35::Value is automated
		
		;                             // gain81::Gain is automated
		gain81.setParameterT(1, 20.); // core::gain::Smoothing
		gain81.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader14.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader14.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add36::Value is automated
		
		;                             // gain82::Gain is automated
		gain82.setParameterT(1, 20.); // core::gain::Smoothing
		gain82.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		; // xfader4::Value is automated
		
		global_cable18.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add37::Value is automated
		
		;                             // gain83::Gain is automated
		gain83.setParameterT(1, 20.); // core::gain::Smoothing
		gain83.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable19.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add38::Value is automated
		
		;                             // gain84::Gain is automated
		gain84.setParameterT(1, 20.); // core::gain::Smoothing
		gain84.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable20.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add39::Value is automated
		
		;                             // gain85::Gain is automated
		gain85.setParameterT(1, 20.); // core::gain::Smoothing
		gain85.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader15.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader15.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add40::Value is automated
		
		;                             // gain86::Gain is automated
		gain86.setParameterT(1, 20.); // core::gain::Smoothing
		gain86.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader16.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader16.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add41::Value is automated
		
		;                             // gain87::Gain is automated
		gain87.setParameterT(1, 20.); // core::gain::Smoothing
		gain87.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader17.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader17.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add42::Value is automated
		
		;                             // gain88::Gain is automated
		gain88.setParameterT(1, 20.); // core::gain::Smoothing
		gain88.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma2::Value is automated
		; // pma2::Multiply is automated
		; // pma2::Add is automated
		
		; // chain11::freq is automated
		
		; // branch2::Index is automated
		
		pi2.setParameterT(0, 1.); // math::pi::Value
		
		sin3.setParameterT(0, 0.); // math::sin::Value
		
		sig2mod4.setParameterT(0, 0.); // math::sig2mod::Value
		
		mul2.setParameterT(0, 1.); // math::mul::Value
		
		sig2mod3.setParameterT(0, 0.); // math::sig2mod::Value
		
		add6.setParameterT(0, 0.75); // math::add::Value
		
		fmod3.setParameterT(0, 1.); // math::fmod::Value
		
		sub.setParameterT(0, 0.5); // math::sub::Value
		
		abs.setParameterT(0, 0.); // math::abs::Value
		
		mul1.setParameterT(0, 2.); // math::mul::Value
		
		mod_inv1.setParameterT(0, 0.); // math::mod_inv::Value
		
		rect3.setParameterT(0, 0.); // math::rect::Value
		
		oscillator.setParameterT(0, 4.);   // core::oscillator::Mode
		oscillator.setParameterT(1, 220.); // core::oscillator::Frequency
		oscillator.setParameterT(2, 1.);   // core::oscillator::FreqRatio
		oscillator.setParameterT(3, 1.);   // core::oscillator::Gate
		oscillator.setParameterT(4, 0.);   // core::oscillator::Phase
		oscillator.setParameterT(5, 1.);   // core::oscillator::Gain
		
		;                                  // input_toggle::Input is automated
		input_toggle.setParameterT(1, 0.); // control::input_toggle::Value1
		input_toggle.setParameterT(2, 0.); // control::input_toggle::Value2
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_table::Value is automated
		
		; // add8::Value is automated
		
		;                                   // input_toggle1::Input is automated
		input_toggle1.setParameterT(1, 0.); // control::input_toggle::Value1
		input_toggle1.setParameterT(2, 0.); // control::input_toggle::Value2
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		; // cable_pack::Value is automated
		
		; // add9::Value is automated
		
		;                             // gain89::Gain is automated
		gain89.setParameterT(1, 20.); // core::gain::Smoothing
		gain89.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // branch3::Index is automated
		
		simple_ar1.setParameterT(0, 0.);       // envelope::simple_ar::Attack
		simple_ar1.setParameterT(1, 91.1);     // envelope::simple_ar::Release
		simple_ar1.setParameterT(2, 1.);       // envelope::simple_ar::Gate
		simple_ar1.setParameterT(3, 0.500456); // envelope::simple_ar::AttackCurve
		
		;                               // gain51::Gain is automated
		gain51.setParameterT(1, 0.);    // core::gain::Smoothing
		gain51.setParameterT(2, -100.); // core::gain::ResetValue
		
		sig2mod.setParameterT(0, 0.); // math::sig2mod::Value
		
		; // branch::Index is automated
		
		; // global_cable::Value is automated
		
		clear.setParameterT(0, 0.); // math::clear::Value
		
		; // add::Value is automated
		
		rect.setParameterT(0, 0.); // math::rect::Value
		
		; // change::Value is automated
		
		; // global_cable2::Value is automated
		
		clear3.setParameterT(0, 0.); // math::clear::Value
		
		; // add43::Value is automated
		
		; // change3::Value is automated
		
		;                             // minmax2::Value is automated
		;                             // minmax2::Minimum is automated
		;                             // minmax2::Maximum is automated
		minmax2.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax2::Step is automated
		minmax2.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // chain170::note is automated
		
		; // global_cable21::Value is automated
		
		; // global_cable4::Value is automated
		
		clear4.setParameterT(0, 0.); // math::clear::Value
		
		; // add1::Value is automated
		
		rect1.setParameterT(0, 0.); // math::rect::Value
		
		; // change1::Value is automated
		
		; // global_cable5::Value is automated
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		; // add44::Value is automated
		
		; // change4::Value is automated
		
		;                             // minmax5::Value is automated
		;                             // minmax5::Minimum is automated
		;                             // minmax5::Maximum is automated
		minmax5.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax5::Step is automated
		minmax5.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // chain172::note is automated
		
		; // global_cable22::Value is automated
		
		; // global_cable6::Value is automated
		
		clear6.setParameterT(0, 0.); // math::clear::Value
		
		; // add2::Value is automated
		
		rect2.setParameterT(0, 0.); // math::rect::Value
		
		; // change2::Value is automated
		
		; // global_cable7::Value is automated
		
		clear7.setParameterT(0, 0.); // math::clear::Value
		
		; // add45::Value is automated
		
		; // change5::Value is automated
		
		;                             // minmax6::Value is automated
		;                             // minmax6::Minimum is automated
		;                             // minmax6::Maximum is automated
		minmax6.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax6::Step is automated
		minmax6.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // chain174::note is automated
		
		; // global_cable23::Value is automated
		
		this->setParameterT(0, 6.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 2.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 0.0448242);
		this->setParameterT(11, 0.);
		this->setParameterT(12, 0.);
		this->setParameterT(13, 0.);
		this->setParameterT(14, 0.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 0.);
		this->setParameterT(17, 1.);
		this->setParameterT(18, 1.);
		this->setParameterT(19, 0.);
		this->setParameterT(20, 1.);
		this->setParameterT(21, 24.);
		this->setParameterT(22, 96.);
		this->setParameterT(23, 0.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool isProcessingHiseEvent() { return true; };
	
	static constexpr bool hasTail() { return false; };
	
	static constexpr bool isSuspendedOnSilence() { return true; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(1).                                                                  // lfo_impl::global_cable1_t<NV>
        getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(1).                                                                  // lfo_impl::global_cable3_t<NV>
        getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(1).                                                                  // lfo_impl::global_cable8_t<NV>
        getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).                                                                  // lfo_impl::global_cable15_t<NV>
        getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).                                                                  // lfo_impl::global_cable16_t<NV>
        getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(1).                                                                  // lfo_impl::global_cable17_t<NV>
        getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(1).                                                                  // lfo_impl::global_cable18_t<NV>
        getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(1).                                                                  // lfo_impl::global_cable19_t<NV>
        getT(0).getT(0).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(1).                                                                  // lfo_impl::global_cable20_t<NV>
        getT(0).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(5).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable_t_index, parameter::empty>
		this->getT(5).getT(0).getT(0).getT(1).getT(5).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable2_t_index, parameter::empty>
		this->getT(5).getT(0).getT(0).getT(2).getT(4).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable21_t_index, parameter::empty>
		this->getT(5).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable4_t_index, parameter::empty>
		this->getT(5).getT(1).getT(0).getT(1).getT(5).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable5_t_index, parameter::empty>
		this->getT(5).getT(1).getT(0).getT(2).getT(4).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable22_t_index, parameter::empty>
		this->getT(5).getT(2).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable6_t_index, parameter::empty>
		this->getT(5).getT(2).getT(0).getT(1).getT(5).connectToRuntimeTarget(addConnection, c);                 // routing::global_cable<global_cable7_t_index, parameter::empty>
		this->getT(5).getT(2).getT(0).getT(2).getT(4).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable23_t_index, parameter::empty>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(1).getT(0).getT(1).setExternalData(b, index); // lfo_impl::peak9_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(0).getT(1).setExternalData(b, index); // lfo_impl::peak12_t<NV>
		this->getT(0).getT(0).getT(2).getT(1).getT(0).getT(1).setExternalData(b, index); // lfo_impl::peak13_t<NV>
		this->getT(1).getT(0).getT(4).getT(0).setExternalData(b, index);                 // lfo_impl::oscillator_t<NV>
		this->getT(1).getT(0).getT(5).getT(2).setExternalData(b, index);                 // lfo_impl::cable_table_t<NV>
		this->getT(1).getT(0).getT(6).getT(2).setExternalData(b, index);                 // lfo_impl::cable_pack_t<NV>
		this->getT(2).getT(1).getT(0).setExternalData(b, index);                         // lfo_impl::simple_ar1_t<NV>
		this->getT(3).setExternalData(b, index);                                         // lfo_impl::peak7_t<NV>
		this->getT(5).getT(0).getT(0).getT(1).getT(3).setExternalData(b, index);         // lfo_impl::peak_t<NV>
		this->getT(5).getT(0).getT(0).getT(2).getT(2).setExternalData(b, index);         // lfo_impl::peak14_t<NV>
		this->getT(5).getT(1).getT(0).getT(1).getT(3).setExternalData(b, index);         // lfo_impl::peak1_t<NV>
		this->getT(5).getT(1).getT(0).getT(2).getT(2).setExternalData(b, index);         // lfo_impl::peak15_t<NV>
		this->getT(5).getT(2).getT(0).getT(1).getT(3).setExternalData(b, index);         // lfo_impl::peak2_t<NV>
		this->getT(5).getT(2).getT(0).getT(2).getT(2).setExternalData(b, index);         // lfo_impl::peak16_t<NV>
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


