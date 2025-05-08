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

namespace fx_impl
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
using midi1_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi1_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using midi_cc3_t = control::midi_cc<parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
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
                                  chain43_t<NV>, 
                                  chain45_t<NV>, 
                                  chain46_t<NV>>;

template <int NV> using xfader_c0 = sliderbank3_c0<NV>;

template <int NV> using xfader_c1 = sliderbank3_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::linear>;
template <int NV>
using pma1_t = control::pma<NV, 
                            parameter::plain<xfader_t<NV>, 0>>;
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
using global_cable16_t_index = global_cable3_t_index;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable17_t_index = global_cable11_t_index;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain56_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable18_t_index = global_cable10_t_index;

template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable18_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader16_t = event_data_reader3_t<NV>;

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader16_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader17_t = event_data_reader3_t<NV>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader17_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader18_t = event_data_reader3_t<NV>;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader18_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi6_t = midi1_t<NV>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi6_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc5_t = midi_cc3_t<NV>;

template <int NV>
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc5_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain55_t<NV>>, 
                                  chain56_t<NV>, 
                                  chain57_t<NV>, 
                                  chain58_t<NV>, 
                                  chain59_t<NV>, 
                                  chain60_t<NV>, 
                                  chain61_t<NV>, 
                                  chain62_t<NV>>;

DECLARE_PARAMETER_RANGE_STEP(pma5_mod_5Range, 
                             1, 
                             16., 
                             0.1);

template <int NV>
using pma5_mod_5 = parameter::from0To1<fx::bitcrush<NV>, 
                                       0, 
                                       pma5_mod_5Range>;

DECLARE_PARAMETER_RANGE_STEP(pma5_mod_6Range, 
                             1., 
                             64., 
                             1.);

template <int NV>
using pma5_mod_6 = parameter::from0To1<fx::sampleandhold<NV>, 
                                       0, 
                                       pma5_mod_6Range>;

DECLARE_PARAMETER_RANGE_SKEW(pma5_mod_7Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma5_mod_7 = parameter::from0To1<filters::ring_mod<NV>, 
                                       0, 
                                       pma5_mod_7Range>;

template <int NV>
using pma5_mod_8 = parameter::from0To1<filters::svf_eq<NV>, 
                                       0, 
                                       pma5_mod_7Range>;

template <int NV> using pma5_mod_9 = pma5_mod_8<NV>;

template <int NV>
using pma5_mod_10 = parameter::from0To1<filters::allpass<NV>, 
                                        0, 
                                        pma5_mod_7Range>;

DECLARE_PARAMETER_RANGE(pma5_mod_11Range, 
                        -18., 
                        18.);

template <int NV>
using pma5_mod_11 = parameter::from0To1<filters::svf_eq<NV>, 
                                        2, 
                                        pma5_mod_11Range>;

template <int NV>
using pma5_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<math::div<NV>, 0>, 
                                  parameter::plain<math::mul<NV>, 0>, 
                                  parameter::plain<math::sub<NV>, 0>, 
                                  parameter::plain<math::sub<NV>, 0>, 
                                  parameter::plain<math::pi<NV>, 0>, 
                                  pma5_mod_5<NV>, 
                                  pma5_mod_6<NV>, 
                                  pma5_mod_7<NV>, 
                                  pma5_mod_8<NV>, 
                                  pma5_mod_9<NV>, 
                                  pma5_mod_10<NV>, 
                                  pma5_mod_11<NV>>;

template <int NV>
using pma5_t = control::pma<NV, pma5_mod<NV>>;
template <int NV>
using peak5_t = wrap::mod<parameter::plain<pma5_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank4_t<NV>>, 
                                      split9_t<NV>, 
                                      peak5_t<NV>, 
                                      pma5_t<NV>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

template <int NV> using sliderbank5_c0 = sliderbank3_c0<NV>;

template <int NV> using sliderbank5_c1 = sliderbank3_c0<NV>;

template <int NV> using sliderbank5_c2 = sliderbank3_c0<NV>;

template <int NV> using sliderbank5_c3 = sliderbank3_c0<NV>;

template <int NV> using sliderbank5_c4 = sliderbank3_c0<NV>;

template <int NV> using sliderbank5_c5 = sliderbank3_c0<NV>;

template <int NV> using sliderbank5_c6 = sliderbank3_c0<NV>;

template <int NV> using sliderbank5_c7 = sliderbank3_c0<NV>;

template <int NV>
using sliderbank5_multimod = parameter::list<sliderbank5_c0<NV>, 
                                             sliderbank5_c1<NV>, 
                                             sliderbank5_c2<NV>, 
                                             sliderbank5_c3<NV>, 
                                             sliderbank5_c4<NV>, 
                                             sliderbank5_c5<NV>, 
                                             sliderbank5_c6<NV>, 
                                             sliderbank5_c7<NV>>;

template <int NV>
using sliderbank5_t = wrap::data<control::sliderbank<sliderbank5_multimod<NV>>, 
                                 data::external::sliderpack<2>>;
using global_cable13_t_index = global_cable3_t_index;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable14_t_index = global_cable11_t_index;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable15_t_index = global_cable10_t_index;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader13_t = event_data_reader3_t<NV>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader13_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader14_t = event_data_reader3_t<NV>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader14_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader15_t = event_data_reader3_t<NV>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader15_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi5_t = midi1_t<NV>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi5_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc4_t = midi_cc3_t<NV>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc4_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain47_t<NV>>, 
                                  chain48_t<NV>, 
                                  chain49_t<NV>, 
                                  chain50_t<NV>, 
                                  chain51_t<NV>, 
                                  chain52_t<NV>, 
                                  chain53_t<NV>, 
                                  chain54_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(pma2_mod_0Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using pma2_mod_0 = parameter::from0To1<filters::allpass<NV>, 
                                       1, 
                                       pma2_mod_0Range>;

template <int NV> using pma2_mod_1 = pma5_mod_11<NV>;

template <int NV>
using pma2_mod_2 = parameter::from0To1<filters::ring_mod<NV>, 
                                       1, 
                                       pma2_mod_0Range>;

template <int NV>
using pma2_mod_3 = parameter::from0To1<filters::one_pole<NV>, 
                                       0, 
                                       pma5_mod_7Range>;

template <int NV> using pma2_mod_4 = pma2_mod_3<NV>;

DECLARE_PARAMETER_RANGE_SKEW(pma2_mod_8Range, 
                             0., 
                             24., 
                             0.231378);

template <int NV>
using pma2_mod_8 = parameter::from0To1<core::smoother<NV>, 
                                       0, 
                                       pma2_mod_8Range>;

template <int NV> using pma2_mod_9 = pma2_mod_8<NV>;

template <int NV>
using pma2_mod = parameter::chain<ranges::Identity, 
                                  pma2_mod_0<NV>, 
                                  pma2_mod_1<NV>, 
                                  pma2_mod_2<NV>, 
                                  pma2_mod_3<NV>, 
                                  pma2_mod_4<NV>, 
                                  parameter::plain<math::fmod<NV>, 0>, 
                                  parameter::plain<math::pi<NV>, 0>, 
                                  parameter::plain<math::pi<NV>, 0>, 
                                  pma2_mod_8<NV>, 
                                  pma2_mod_9<NV>>;

template <int NV>
using pma2_t = control::pma<NV, pma2_mod<NV>>;
template <int NV>
using peak4_t = wrap::mod<parameter::plain<pma2_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank5_t<NV>>, 
                                      split7_t<NV>, 
                                      peak4_t<NV>, 
                                      pma2_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<2, modchain_t<NV>>, 
                                  modchain2_t<NV>, 
                                  modchain1_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>>;

template <int NV>
using chain197_t = container::chain<parameter::empty, 
                                    wrap::fix<2, math::div<NV>>, 
                                    core::smoother<NV>, 
                                    core::mono2stereo>;

template <int NV>
using chain198_t = container::chain<parameter::empty, 
                                    wrap::fix<2, math::mul<NV>>, 
                                    core::smoother<NV>, 
                                    core::mono2stereo>;

template <int NV>
using chain199_t = container::chain<parameter::empty, 
                                    wrap::fix<2, math::sub<NV>>, 
                                    math::pi<NV>>;

template <int NV>
using chain200_t = container::chain<parameter::empty, 
                                    wrap::fix<2, math::pi<NV>>, 
                                    math::sub<NV>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::fmod<NV>>, 
                                   math::pi<NV>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, fx::bitcrush<NV>>, 
                                  filters::one_pole<NV>>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, fx::sampleandhold<NV>>, 
                                  filters::one_pole<NV>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, filters::ring_mod<NV>>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filters::svf_eq<NV>>>;

template <int NV> using chain10_t = chain15_t<NV>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain15_t<NV>>, 
                                    chain10_t<NV>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filters::allpass<NV>>, 
                                   math::tanh<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain197_t<NV>>, 
                                    chain198_t<NV>, 
                                    chain199_t<NV>, 
                                    chain200_t<NV>, 
                                    chain13_t<NV>, 
                                    chain6_t<NV>, 
                                    chain8_t<NV>, 
                                    chain9_t<NV>, 
                                    branch3_t<NV>, 
                                    chain11_t<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, branch1_t<NV>>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain1_t<NV>>, 
                                 chain2_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, xfader_t<NV>>, 
                                 split_t<NV>>;

namespace fx_t_parameters
{
// Parameter list for fx_impl::fx_t ----------------------------------------------------------------

template <int NV>
using ModeonOff = parameter::chain<ranges::Identity, 
                                   parameter::plain<fx::bitcrush<NV>, 1>, 
                                   parameter::plain<fx_impl::branch3_t<NV>, 0>>;

template <int NV>
using q_0 = parameter::from0To1<filters::svf_eq<NV>, 
                                1, 
                                fx_impl::pma2_mod_0Range>;

template <int NV> using q_1 = q_0<NV>;

template <int NV>
using q = parameter::chain<ranges::Identity, 
                           q_0<NV>, 
                           q_1<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Type_InputRange, 
                             1., 
                             9., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Type_0Range, 
                             0., 
                             9., 
                             1.);

template <int NV>
using Type_0 = parameter::from0To1<fx_impl::branch1_t<NV>, 
                                   0, 
                                   Type_0Range>;

template <int NV>
using Type = parameter::chain<Type_InputRange, Type_0<NV>>;

template <int NV>
using TransformMix = parameter::plain<fx_impl::pma1_t<NV>, 2>;
template <int NV>
using TransformA = parameter::plain<fx_impl::pma5_t<NV>, 2>;
template <int NV>
using TransformB = parameter::plain<fx_impl::pma2_t<NV>, 2>;
template <int NV>
using MixMod = parameter::plain<fx_impl::pma1_t<NV>, 1>;
template <int NV>
using Amod = parameter::plain<fx_impl::pma5_t<NV>, 1>;
template <int NV>
using Bmod = parameter::plain<fx_impl::pma2_t<NV>, 1>;
template <int NV>
using fx_t_plist = parameter::list<TransformMix<NV>, 
                                   TransformA<NV>, 
                                   TransformB<NV>, 
                                   ModeonOff<NV>, 
                                   q<NV>, 
                                   Type<NV>, 
                                   MixMod<NV>, 
                                   Amod<NV>, 
                                   Bmod<NV>>;
}

template <int NV>
using fx_t_ = container::chain<fx_t_parameters::fx_t_plist<NV>, 
                               wrap::fix<2, split6_t<NV>>, 
                               chain_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public fx_impl::fx_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 3;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(fx);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(148)
		{
			0x005B, 0x0000, 0x5400, 0x6172, 0x736E, 0x6F66, 0x6D72, 0x694D, 
            0x0078, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x015B, 0x0000, 0x5400, 0x6172, 0x736E, 
            0x6F66, 0x6D72, 0x0041, 0x0000, 0x0000, 0x0000, 0x3F80, 0xCCCD, 
            0x3ECC, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 0x0000, 0x5400, 
            0x6172, 0x736E, 0x6F66, 0x6D72, 0x0042, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x035B, 
            0x0000, 0x4D00, 0x646F, 0x6F65, 0x4F6E, 0x6666, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x9C3F, 0x0CDE, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0004, 0x0000, 0x0071, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 
            0x5400, 0x7079, 0x0065, 0x0000, 0x3F80, 0x0000, 0x4110, 0x0000, 
            0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x065B, 0x0000, 0x4D00, 
            0x7869, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x075B, 0x0000, 0x4100, 
            0x6F6D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x085B, 0x0000, 0x4200, 0x6F6D, 
            0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& split6 = this->getT(0);                                                  // fx_impl::split6_t<NV>
		auto& modchain = this->getT(0).getT(0);                                        // fx_impl::modchain_t<NV>
		auto& sliderbank3 = this->getT(0).getT(0).getT(0);                             // fx_impl::sliderbank3_t<NV>
		auto& split1 = this->getT(0).getT(0).getT(1);                                  // fx_impl::split1_t<NV>
		auto& chain39 = this->getT(0).getT(0).getT(1).getT(0);                         // fx_impl::chain39_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(1).getT(0).getT(0);           // fx_impl::global_cable3_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                    // math::add<NV>
		auto& gain13 = this->getT(0).getT(0).getT(1).getT(0).getT(2);                  // core::gain<NV>
		auto& chain41 = this->getT(0).getT(0).getT(1).getT(1);                         // fx_impl::chain41_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(1).getT(1).getT(0);          // fx_impl::global_cable11_t<NV>
		auto& add26 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                   // math::add<NV>
		auto& gain15 = this->getT(0).getT(0).getT(1).getT(1).getT(2);                  // core::gain<NV>
		auto& chain40 = this->getT(0).getT(0).getT(1).getT(2);                         // fx_impl::chain40_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(1).getT(2).getT(0);          // fx_impl::global_cable10_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                    // math::add<NV>
		auto& gain14 = this->getT(0).getT(0).getT(1).getT(2).getT(2);                  // core::gain<NV>
		auto& chain42 = this->getT(0).getT(0).getT(1).getT(3);                         // fx_impl::chain42_t<NV>
		auto& event_data_reader3 = this->getT(0).getT(0).getT(1).getT(3).getT(0);      // fx_impl::event_data_reader3_t<NV>
		auto& add27 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                   // math::add<NV>
		auto& gain16 = this->getT(0).getT(0).getT(1).getT(3).getT(2);                  // core::gain<NV>
		auto& chain44 = this->getT(0).getT(0).getT(1).getT(4);                         // fx_impl::chain44_t<NV>
		auto& event_data_reader11 = this->getT(0).getT(0).getT(1).getT(4).getT(0);     // fx_impl::event_data_reader11_t<NV>
		auto& add29 = this->getT(0).getT(0).getT(1).getT(4).getT(1);                   // math::add<NV>
		auto& gain32 = this->getT(0).getT(0).getT(1).getT(4).getT(2);                  // core::gain<NV>
		auto& chain43 = this->getT(0).getT(0).getT(1).getT(5);                         // fx_impl::chain43_t<NV>
		auto& event_data_reader10 = this->getT(0).getT(0).getT(1).getT(5).getT(0);     // fx_impl::event_data_reader10_t<NV>
		auto& add28 = this->getT(0).getT(0).getT(1).getT(5).getT(1);                   // math::add<NV>
		auto& gain26 = this->getT(0).getT(0).getT(1).getT(5).getT(2);                  // core::gain<NV>
		auto& chain45 = this->getT(0).getT(0).getT(1).getT(6);                         // fx_impl::chain45_t<NV>
		auto& midi1 = this->getT(0).getT(0).getT(1).getT(6).getT(0);                   // fx_impl::midi1_t<NV>
		auto& add30 = this->getT(0).getT(0).getT(1).getT(6).getT(1);                   // math::add<NV>
		auto& gain33 = this->getT(0).getT(0).getT(1).getT(6).getT(2);                  // core::gain<NV>
		auto& chain46 = this->getT(0).getT(0).getT(1).getT(7);                         // fx_impl::chain46_t<NV>
		auto& midi_cc3 = this->getT(0).getT(0).getT(1).getT(7).getT(0);                // fx_impl::midi_cc3_t<NV>
		auto& add31 = this->getT(0).getT(0).getT(1).getT(7).getT(1);                   // math::add<NV>
		auto& gain34 = this->getT(0).getT(0).getT(1).getT(7).getT(2);                  // core::gain<NV>
		auto& peak3 = this->getT(0).getT(0).getT(2);                                   // fx_impl::peak3_t<NV>
		auto& pma1 = this->getT(0).getT(0).getT(3);                                    // fx_impl::pma1_t<NV>
		auto& modchain2 = this->getT(0).getT(1);                                       // fx_impl::modchain2_t<NV>
		auto& sliderbank4 = this->getT(0).getT(1).getT(0);                             // fx_impl::sliderbank4_t<NV>
		auto& split9 = this->getT(0).getT(1).getT(1);                                  // fx_impl::split9_t<NV>
		auto& chain55 = this->getT(0).getT(1).getT(1).getT(0);                         // fx_impl::chain55_t<NV>
		auto& global_cable16 = this->getT(0).getT(1).getT(1).getT(0).getT(0);          // fx_impl::global_cable16_t<NV>
		auto& add40 = this->getT(0).getT(1).getT(1).getT(0).getT(1);                   // math::add<NV>
		auto& gain43 = this->getT(0).getT(1).getT(1).getT(0).getT(2);                  // core::gain<NV>
		auto& chain56 = this->getT(0).getT(1).getT(1).getT(1);                         // fx_impl::chain56_t<NV>
		auto& global_cable17 = this->getT(0).getT(1).getT(1).getT(1).getT(0);          // fx_impl::global_cable17_t<NV>
		auto& add41 = this->getT(0).getT(1).getT(1).getT(1).getT(1);                   // math::add<NV>
		auto& gain44 = this->getT(0).getT(1).getT(1).getT(1).getT(2);                  // core::gain<NV>
		auto& chain57 = this->getT(0).getT(1).getT(1).getT(2);                         // fx_impl::chain57_t<NV>
		auto& global_cable18 = this->getT(0).getT(1).getT(1).getT(2).getT(0);          // fx_impl::global_cable18_t<NV>
		auto& add42 = this->getT(0).getT(1).getT(1).getT(2).getT(1);                   // math::add<NV>
		auto& gain45 = this->getT(0).getT(1).getT(1).getT(2).getT(2);                  // core::gain<NV>
		auto& chain58 = this->getT(0).getT(1).getT(1).getT(3);                         // fx_impl::chain58_t<NV>
		auto& event_data_reader16 = this->getT(0).getT(1).getT(1).getT(3).getT(0);     // fx_impl::event_data_reader16_t<NV>
		auto& add43 = this->getT(0).getT(1).getT(1).getT(3).getT(1);                   // math::add<NV>
		auto& gain46 = this->getT(0).getT(1).getT(1).getT(3).getT(2);                  // core::gain<NV>
		auto& chain59 = this->getT(0).getT(1).getT(1).getT(4);                         // fx_impl::chain59_t<NV>
		auto& event_data_reader17 = this->getT(0).getT(1).getT(1).getT(4).getT(0);     // fx_impl::event_data_reader17_t<NV>
		auto& add44 = this->getT(0).getT(1).getT(1).getT(4).getT(1);                   // math::add<NV>
		auto& gain47 = this->getT(0).getT(1).getT(1).getT(4).getT(2);                  // core::gain<NV>
		auto& chain60 = this->getT(0).getT(1).getT(1).getT(5);                         // fx_impl::chain60_t<NV>
		auto& event_data_reader18 = this->getT(0).getT(1).getT(1).getT(5).getT(0);     // fx_impl::event_data_reader18_t<NV>
		auto& add45 = this->getT(0).getT(1).getT(1).getT(5).getT(1);                   // math::add<NV>
		auto& gain48 = this->getT(0).getT(1).getT(1).getT(5).getT(2);                  // core::gain<NV>
		auto& chain61 = this->getT(0).getT(1).getT(1).getT(6);                         // fx_impl::chain61_t<NV>
		auto& midi6 = this->getT(0).getT(1).getT(1).getT(6).getT(0);                   // fx_impl::midi6_t<NV>
		auto& add46 = this->getT(0).getT(1).getT(1).getT(6).getT(1);                   // math::add<NV>
		auto& gain49 = this->getT(0).getT(1).getT(1).getT(6).getT(2);                  // core::gain<NV>
		auto& chain62 = this->getT(0).getT(1).getT(1).getT(7);                         // fx_impl::chain62_t<NV>
		auto& midi_cc5 = this->getT(0).getT(1).getT(1).getT(7).getT(0);                // fx_impl::midi_cc5_t<NV>
		auto& add47 = this->getT(0).getT(1).getT(1).getT(7).getT(1);                   // math::add<NV>
		auto& gain50 = this->getT(0).getT(1).getT(1).getT(7).getT(2);                  // core::gain<NV>
		auto& peak5 = this->getT(0).getT(1).getT(2);                                   // fx_impl::peak5_t<NV>
		auto& pma5 = this->getT(0).getT(1).getT(3);                                    // fx_impl::pma5_t<NV>
		auto& modchain1 = this->getT(0).getT(2);                                       // fx_impl::modchain1_t<NV>
		auto& sliderbank5 = this->getT(0).getT(2).getT(0);                             // fx_impl::sliderbank5_t<NV>
		auto& split7 = this->getT(0).getT(2).getT(1);                                  // fx_impl::split7_t<NV>
		auto& chain47 = this->getT(0).getT(2).getT(1).getT(0);                         // fx_impl::chain47_t<NV>
		auto& global_cable13 = this->getT(0).getT(2).getT(1).getT(0).getT(0);          // fx_impl::global_cable13_t<NV>
		auto& add32 = this->getT(0).getT(2).getT(1).getT(0).getT(1);                   // math::add<NV>
		auto& gain35 = this->getT(0).getT(2).getT(1).getT(0).getT(2);                  // core::gain<NV>
		auto& chain48 = this->getT(0).getT(2).getT(1).getT(1);                         // fx_impl::chain48_t<NV>
		auto& global_cable14 = this->getT(0).getT(2).getT(1).getT(1).getT(0);          // fx_impl::global_cable14_t<NV>
		auto& add33 = this->getT(0).getT(2).getT(1).getT(1).getT(1);                   // math::add<NV>
		auto& gain36 = this->getT(0).getT(2).getT(1).getT(1).getT(2);                  // core::gain<NV>
		auto& chain49 = this->getT(0).getT(2).getT(1).getT(2);                         // fx_impl::chain49_t<NV>
		auto& global_cable15 = this->getT(0).getT(2).getT(1).getT(2).getT(0);          // fx_impl::global_cable15_t<NV>
		auto& add34 = this->getT(0).getT(2).getT(1).getT(2).getT(1);                   // math::add<NV>
		auto& gain37 = this->getT(0).getT(2).getT(1).getT(2).getT(2);                  // core::gain<NV>
		auto& chain50 = this->getT(0).getT(2).getT(1).getT(3);                         // fx_impl::chain50_t<NV>
		auto& event_data_reader13 = this->getT(0).getT(2).getT(1).getT(3).getT(0);     // fx_impl::event_data_reader13_t<NV>
		auto& add35 = this->getT(0).getT(2).getT(1).getT(3).getT(1);                   // math::add<NV>
		auto& gain38 = this->getT(0).getT(2).getT(1).getT(3).getT(2);                  // core::gain<NV>
		auto& chain51 = this->getT(0).getT(2).getT(1).getT(4);                         // fx_impl::chain51_t<NV>
		auto& event_data_reader14 = this->getT(0).getT(2).getT(1).getT(4).getT(0);     // fx_impl::event_data_reader14_t<NV>
		auto& add36 = this->getT(0).getT(2).getT(1).getT(4).getT(1);                   // math::add<NV>
		auto& gain39 = this->getT(0).getT(2).getT(1).getT(4).getT(2);                  // core::gain<NV>
		auto& chain52 = this->getT(0).getT(2).getT(1).getT(5);                         // fx_impl::chain52_t<NV>
		auto& event_data_reader15 = this->getT(0).getT(2).getT(1).getT(5).getT(0);     // fx_impl::event_data_reader15_t<NV>
		auto& add37 = this->getT(0).getT(2).getT(1).getT(5).getT(1);                   // math::add<NV>
		auto& gain40 = this->getT(0).getT(2).getT(1).getT(5).getT(2);                  // core::gain<NV>
		auto& chain53 = this->getT(0).getT(2).getT(1).getT(6);                         // fx_impl::chain53_t<NV>
		auto& midi5 = this->getT(0).getT(2).getT(1).getT(6).getT(0);                   // fx_impl::midi5_t<NV>
		auto& add38 = this->getT(0).getT(2).getT(1).getT(6).getT(1);                   // math::add<NV>
		auto& gain41 = this->getT(0).getT(2).getT(1).getT(6).getT(2);                  // core::gain<NV>
		auto& chain54 = this->getT(0).getT(2).getT(1).getT(7);                         // fx_impl::chain54_t<NV>
		auto& midi_cc4 = this->getT(0).getT(2).getT(1).getT(7).getT(0);                // fx_impl::midi_cc4_t<NV>
		auto& add39 = this->getT(0).getT(2).getT(1).getT(7).getT(1);                   // math::add<NV>
		auto& gain42 = this->getT(0).getT(2).getT(1).getT(7).getT(2);                  // core::gain<NV>
		auto& peak4 = this->getT(0).getT(2).getT(2);                                   // fx_impl::peak4_t<NV>
		auto& pma2 = this->getT(0).getT(2).getT(3);                                    // fx_impl::pma2_t<NV>
		auto& chain = this->getT(1);                                                   // fx_impl::chain_t<NV>
		auto& xfader = this->getT(1).getT(0);                                          // fx_impl::xfader_t<NV>
		auto& split = this->getT(1).getT(1);                                           // fx_impl::split_t<NV>
		auto& chain1 = this->getT(1).getT(1).getT(0);                                  // fx_impl::chain1_t<NV>
		auto& gain = this->getT(1).getT(1).getT(0).getT(0);                            // core::gain<NV>
		auto& chain2 = this->getT(1).getT(1).getT(1);                                  // fx_impl::chain2_t<NV>
		auto& branch1 = this->getT(1).getT(1).getT(1).getT(0);                         // fx_impl::branch1_t<NV>
		auto& chain197 = this->getT(1).getT(1).getT(1).getT(0).getT(0);                // fx_impl::chain197_t<NV>
		auto& div = this->getT(1).getT(1).getT(1).getT(0).getT(0).getT(0);             // math::div<NV>
		auto& smoother2 = this->getT(1).getT(1).getT(1).getT(0).getT(0).getT(1);       // core::smoother<NV>
		auto& mono2stereo = this->getT(1).getT(1).getT(1).getT(0).getT(0).getT(2);     // core::mono2stereo
		auto& chain198 = this->getT(1).getT(1).getT(1).getT(0).getT(1);                // fx_impl::chain198_t<NV>
		auto& mul6 = this->getT(1).getT(1).getT(1).getT(0).getT(1).getT(0);            // math::mul<NV>
		auto& smoother3 = this->getT(1).getT(1).getT(1).getT(0).getT(1).getT(1);       // core::smoother<NV>
		auto& mono2stereo1 = this->getT(1).getT(1).getT(1).getT(0).getT(1).getT(2);    // core::mono2stereo
		auto& chain199 = this->getT(1).getT(1).getT(1).getT(0).getT(2);                // fx_impl::chain199_t<NV>
		auto& sub = this->getT(1).getT(1).getT(1).getT(0).getT(2).getT(0);             // math::sub<NV>
		auto& pi1 = this->getT(1).getT(1).getT(1).getT(0).getT(2).getT(1);             // math::pi<NV>
		auto& chain200 = this->getT(1).getT(1).getT(1).getT(0).getT(3);                // fx_impl::chain200_t<NV>
		auto& pi2 = this->getT(1).getT(1).getT(1).getT(0).getT(3).getT(0);             // math::pi<NV>
		auto& sub1 = this->getT(1).getT(1).getT(1).getT(0).getT(3).getT(1);            // math::sub<NV>
		auto& chain13 = this->getT(1).getT(1).getT(1).getT(0).getT(4);                 // fx_impl::chain13_t<NV>
		auto& fmod = this->getT(1).getT(1).getT(1).getT(0).getT(4).getT(0);            // math::fmod<NV>
		auto& pi = this->getT(1).getT(1).getT(1).getT(0).getT(4).getT(1);              // math::pi<NV>
		auto& chain6 = this->getT(1).getT(1).getT(1).getT(0).getT(5);                  // fx_impl::chain6_t<NV>
		auto& bitcrush = this->getT(1).getT(1).getT(1).getT(0).getT(5).getT(0);        // fx::bitcrush<NV>
		auto& one_pole = this->getT(1).getT(1).getT(1).getT(0).getT(5).getT(1);        // filters::one_pole<NV>
		auto& chain8 = this->getT(1).getT(1).getT(1).getT(0).getT(6);                  // fx_impl::chain8_t<NV>
		auto& sampleandhold = this->getT(1).getT(1).getT(1).getT(0).getT(6).getT(0);   // fx::sampleandhold<NV>
		auto& one_pole1 = this->getT(1).getT(1).getT(1).getT(0).getT(6).getT(1);       // filters::one_pole<NV>
		auto& chain9 = this->getT(1).getT(1).getT(1).getT(0).getT(7);                  // fx_impl::chain9_t<NV>
		auto& ring_mod = this->getT(1).getT(1).getT(1).getT(0).getT(7).getT(0);        // filters::ring_mod<NV>
		auto& branch3 = this->getT(1).getT(1).getT(1).getT(0).getT(8);                 // fx_impl::branch3_t<NV>
		auto& chain15 = this->getT(1).getT(1).getT(1).getT(0).getT(8).getT(0);         // fx_impl::chain15_t<NV>
		auto& svf_eq1 = this->getT(1).getT(1).getT(1).getT(0).getT(8).getT(0).getT(0); // filters::svf_eq<NV>
		auto& chain10 = this->getT(1).getT(1).getT(1).getT(0).getT(8).getT(1);         // fx_impl::chain10_t<NV>
		auto& svf_eq = this->getT(1).getT(1).getT(1).getT(0).getT(8).getT(1).getT(0);  // filters::svf_eq<NV>
		auto& chain11 = this->getT(1).getT(1).getT(1).getT(0).getT(9);                 // fx_impl::chain11_t<NV>
		auto& allpass1 = this->getT(1).getT(1).getT(1).getT(0).getT(9).getT(0);        // filters::allpass<NV>
		auto& tanh1 = this->getT(1).getT(1).getT(1).getT(0).getT(9).getT(1);           // math::tanh<NV>
		auto& gain1 = this->getT(1).getT(1).getT(1).getT(1);                           // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma1); // TransformMix -> pma1::Add
		
		this->getParameterT(1).connectT(0, pma5); // TransformA -> pma5::Add
		
		this->getParameterT(2).connectT(0, pma2); // TransformB -> pma2::Add
		
		auto& ModeonOff_p = this->getParameterT(3);
		ModeonOff_p.connectT(0, bitcrush); // ModeonOff -> bitcrush::Mode
		ModeonOff_p.connectT(1, branch3);  // ModeonOff -> branch3::Index
		
		auto& q_p = this->getParameterT(4);
		q_p.connectT(0, svf_eq1); // q -> svf_eq1::Q
		q_p.connectT(1, svf_eq);  // q -> svf_eq::Q
		
		this->getParameterT(5).connectT(0, branch1); // Type -> branch1::Index
		
		this->getParameterT(6).connectT(0, pma1); // MixMod -> pma1::Multiply
		
		this->getParameterT(7).connectT(0, pma5); // Amod -> pma5::Multiply
		
		this->getParameterT(8).connectT(0, pma2); // Bmod -> pma2::Multiply
		
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
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);                // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1);               // xfader -> gain1::Gain
		pma1.getWrappedObject().getParameter().connectT(0, xfader); // pma1 -> xfader::Value
		peak3.getParameter().connectT(0, pma1);                     // peak3 -> pma1::Value
		auto& sliderbank4_p = sliderbank4.getWrappedObject().getParameter();
		sliderbank4_p.getParameterT(0).connectT(0, gain43);                  // sliderbank4 -> gain43::Gain
		sliderbank4_p.getParameterT(1).connectT(0, gain44);                  // sliderbank4 -> gain44::Gain
		sliderbank4_p.getParameterT(2).connectT(0, gain45);                  // sliderbank4 -> gain45::Gain
		sliderbank4_p.getParameterT(3).connectT(0, gain46);                  // sliderbank4 -> gain46::Gain
		sliderbank4_p.getParameterT(4).connectT(0, gain47);                  // sliderbank4 -> gain47::Gain
		sliderbank4_p.getParameterT(5).connectT(0, gain48);                  // sliderbank4 -> gain48::Gain
		sliderbank4_p.getParameterT(6).connectT(0, gain49);                  // sliderbank4 -> gain49::Gain
		sliderbank4_p.getParameterT(7).connectT(0, gain50);                  // sliderbank4 -> gain50::Gain
		global_cable16.getWrappedObject().getParameter().connectT(0, add40); // global_cable16 -> add40::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add41); // global_cable17 -> add41::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, add42); // global_cable18 -> add42::Value
		event_data_reader16.getParameter().connectT(0, add43);               // event_data_reader16 -> add43::Value
		event_data_reader17.getParameter().connectT(0, add44);               // event_data_reader17 -> add44::Value
		event_data_reader18.getParameter().connectT(0, add45);               // event_data_reader18 -> add45::Value
		midi6.getParameter().connectT(0, add46);                             // midi6 -> add46::Value
		midi_cc5.getWrappedObject().getParameter().connectT(0, add47);       // midi_cc5 -> add47::Value
		pma5.getWrappedObject().getParameter().connectT(0, div);             // pma5 -> div::Value
		pma5.getWrappedObject().getParameter().connectT(1, mul6);            // pma5 -> mul6::Value
		pma5.getWrappedObject().getParameter().connectT(2, sub);             // pma5 -> sub::Value
		pma5.getWrappedObject().getParameter().connectT(3, sub1);            // pma5 -> sub1::Value
		pma5.getWrappedObject().getParameter().connectT(4, pi);              // pma5 -> pi::Value
		pma5.getWrappedObject().getParameter().connectT(5, bitcrush);        // pma5 -> bitcrush::BitDepth
		pma5.getWrappedObject().getParameter().connectT(6, sampleandhold);   // pma5 -> sampleandhold::Counter
		pma5.getWrappedObject().getParameter().connectT(7, ring_mod);        // pma5 -> ring_mod::Frequency
		pma5.getWrappedObject().getParameter().connectT(8, svf_eq1);         // pma5 -> svf_eq1::Frequency
		pma5.getWrappedObject().getParameter().connectT(9, svf_eq);          // pma5 -> svf_eq::Frequency
		pma5.getWrappedObject().getParameter().connectT(10, allpass1);       // pma5 -> allpass1::Frequency
		pma5.getWrappedObject().getParameter().connectT(11, svf_eq);         // pma5 -> svf_eq::Gain
		peak5.getParameter().connectT(0, pma5);                              // peak5 -> pma5::Value
		auto& sliderbank5_p = sliderbank5.getWrappedObject().getParameter();
		sliderbank5_p.getParameterT(0).connectT(0, gain35);                  // sliderbank5 -> gain35::Gain
		sliderbank5_p.getParameterT(1).connectT(0, gain36);                  // sliderbank5 -> gain36::Gain
		sliderbank5_p.getParameterT(2).connectT(0, gain37);                  // sliderbank5 -> gain37::Gain
		sliderbank5_p.getParameterT(3).connectT(0, gain38);                  // sliderbank5 -> gain38::Gain
		sliderbank5_p.getParameterT(4).connectT(0, gain39);                  // sliderbank5 -> gain39::Gain
		sliderbank5_p.getParameterT(5).connectT(0, gain40);                  // sliderbank5 -> gain40::Gain
		sliderbank5_p.getParameterT(6).connectT(0, gain41);                  // sliderbank5 -> gain41::Gain
		sliderbank5_p.getParameterT(7).connectT(0, gain42);                  // sliderbank5 -> gain42::Gain
		global_cable13.getWrappedObject().getParameter().connectT(0, add32); // global_cable13 -> add32::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add33); // global_cable14 -> add33::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add34); // global_cable15 -> add34::Value
		event_data_reader13.getParameter().connectT(0, add35);               // event_data_reader13 -> add35::Value
		event_data_reader14.getParameter().connectT(0, add36);               // event_data_reader14 -> add36::Value
		event_data_reader15.getParameter().connectT(0, add37);               // event_data_reader15 -> add37::Value
		midi5.getParameter().connectT(0, add38);                             // midi5 -> add38::Value
		midi_cc4.getWrappedObject().getParameter().connectT(0, add39);       // midi_cc4 -> add39::Value
		pma2.getWrappedObject().getParameter().connectT(0, allpass1);        // pma2 -> allpass1::Q
		pma2.getWrappedObject().getParameter().connectT(1, svf_eq1);         // pma2 -> svf_eq1::Gain
		pma2.getWrappedObject().getParameter().connectT(2, ring_mod);        // pma2 -> ring_mod::Q
		pma2.getWrappedObject().getParameter().connectT(3, one_pole1);       // pma2 -> one_pole1::Frequency
		pma2.getWrappedObject().getParameter().connectT(4, one_pole);        // pma2 -> one_pole::Frequency
		pma2.getWrappedObject().getParameter().connectT(5, fmod);            // pma2 -> fmod::Value
		pma2.getWrappedObject().getParameter().connectT(6, pi2);             // pma2 -> pi2::Value
		pma2.getWrappedObject().getParameter().connectT(7, pi1);             // pma2 -> pi1::Value
		pma2.getWrappedObject().getParameter().connectT(8, smoother3);       // pma2 -> smoother3::SmoothingTime
		pma2.getWrappedObject().getParameter().connectT(9, smoother2);       // pma2 -> smoother2::SmoothingTime
		peak4.getParameter().connectT(0, pma2);                              // peak4 -> pma2::Value
		
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
		
		sliderbank4.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add40::Value is automated
		
		;                             // gain43::Gain is automated
		gain43.setParameterT(1, 20.); // core::gain::Smoothing
		gain43.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add41::Value is automated
		
		;                             // gain44::Gain is automated
		gain44.setParameterT(1, 20.); // core::gain::Smoothing
		gain44.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable18.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add42::Value is automated
		
		;                             // gain45::Gain is automated
		gain45.setParameterT(1, 20.); // core::gain::Smoothing
		gain45.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader16.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader16.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add43::Value is automated
		
		;                             // gain46::Gain is automated
		gain46.setParameterT(1, 20.); // core::gain::Smoothing
		gain46.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader17.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader17.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add44::Value is automated
		
		;                             // gain47::Gain is automated
		gain47.setParameterT(1, 20.); // core::gain::Smoothing
		gain47.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader18.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader18.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add45::Value is automated
		
		;                             // gain48::Gain is automated
		gain48.setParameterT(1, 20.); // core::gain::Smoothing
		gain48.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add46::Value is automated
		
		;                             // gain49::Gain is automated
		gain49.setParameterT(1, 20.); // core::gain::Smoothing
		gain49.setParameterT(2, 0.);  // core::gain::ResetValue
		
		midi_cc5.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc5.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc5.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add47::Value is automated
		
		;                             // gain50::Gain is automated
		gain50.setParameterT(1, 20.); // core::gain::Smoothing
		gain50.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma5::Value is automated
		; // pma5::Multiply is automated
		; // pma5::Add is automated
		
		sliderbank5.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add32::Value is automated
		
		;                             // gain35::Gain is automated
		gain35.setParameterT(1, 20.); // core::gain::Smoothing
		gain35.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add33::Value is automated
		
		;                             // gain36::Gain is automated
		gain36.setParameterT(1, 20.); // core::gain::Smoothing
		gain36.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add34::Value is automated
		
		;                             // gain37::Gain is automated
		gain37.setParameterT(1, 20.); // core::gain::Smoothing
		gain37.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader13.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader13.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add35::Value is automated
		
		;                             // gain38::Gain is automated
		gain38.setParameterT(1, 20.); // core::gain::Smoothing
		gain38.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader14.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader14.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add36::Value is automated
		
		;                             // gain39::Gain is automated
		gain39.setParameterT(1, 20.); // core::gain::Smoothing
		gain39.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader15.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader15.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add37::Value is automated
		
		;                             // gain40::Gain is automated
		gain40.setParameterT(1, 20.); // core::gain::Smoothing
		gain40.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add38::Value is automated
		
		;                             // gain41::Gain is automated
		gain41.setParameterT(1, 20.); // core::gain::Smoothing
		gain41.setParameterT(2, 0.);  // core::gain::ResetValue
		
		midi_cc4.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc4.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc4.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add39::Value is automated
		
		;                             // gain42::Gain is automated
		gain42.setParameterT(1, 20.); // core::gain::Smoothing
		gain42.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma2::Value is automated
		; // pma2::Multiply is automated
		; // pma2::Add is automated
		
		; // xfader::Value is automated
		
		;                            // gain::Gain is automated
		gain.setParameterT(1, 20.);  // core::gain::Smoothing
		gain.setParameterT(2, -20.); // core::gain::ResetValue
		
		; // branch1::Index is automated
		
		; // div::Value is automated
		
		;                               // smoother2::SmoothingTime is automated
		smoother2.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		; // mul6::Value is automated
		
		;                               // smoother3::SmoothingTime is automated
		smoother3.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		; // sub::Value is automated
		
		; // pi1::Value is automated
		
		; // pi2::Value is automated
		
		; // sub1::Value is automated
		
		; // fmod::Value is automated
		
		; // pi::Value is automated
		
		; // bitcrush::BitDepth is automated
		; // bitcrush::Mode is automated
		
		;                                // one_pole::Frequency is automated
		one_pole.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // sampleandhold::Counter is automated
		
		;                                 // one_pole1::Frequency is automated
		one_pole1.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole1.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                    // ring_mod::Frequency is automated
		;                                    // ring_mod::Q is automated
		ring_mod.setParameterT(2, -4.44825); // filters::ring_mod::Gain
		ring_mod.setParameterT(3, 0.01);     // filters::ring_mod::Smoothing
		ring_mod.setParameterT(4, 0.);       // filters::ring_mod::Mode
		ring_mod.setParameterT(5, 1.);       // filters::ring_mod::Enabled
		
		; // branch3::Index is automated
		
		;                               // svf_eq1::Frequency is automated
		;                               // svf_eq1::Q is automated
		;                               // svf_eq1::Gain is automated
		svf_eq1.setParameterT(3, 0.01); // filters::svf_eq::Smoothing
		svf_eq1.setParameterT(4, 2.);   // filters::svf_eq::Mode
		svf_eq1.setParameterT(5, 1.);   // filters::svf_eq::Enabled
		
		;                              // svf_eq::Frequency is automated
		;                              // svf_eq::Q is automated
		;                              // svf_eq::Gain is automated
		svf_eq.setParameterT(3, 0.01); // filters::svf_eq::Smoothing
		svf_eq.setParameterT(4, 3.);   // filters::svf_eq::Mode
		svf_eq.setParameterT(5, 1.);   // filters::svf_eq::Enabled
		
		;                                // allpass1::Frequency is automated
		;                                // allpass1::Q is automated
		allpass1.setParameterT(2, 0.);   // filters::allpass::Gain
		allpass1.setParameterT(3, 0.01); // filters::allpass::Smoothing
		allpass1.setParameterT(4, 0.);   // filters::allpass::Mode
		allpass1.setParameterT(5, 1.);   // filters::allpass::Enabled
		
		tanh1.setParameterT(0, 0.95891); // math::tanh::Value
		
		;                             // gain1::Gain is automated
		gain1.setParameterT(1, 20.);  // core::gain::Smoothing
		gain1.setParameterT(2, -19.); // core::gain::ResetValue
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 0.4);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.550272);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 7.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 0.);
		this->setParameterT(8, 0.);
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
		
		this->getT(0).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // fx_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // fx_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // fx_impl::global_cable10_t<NV>
		this->getT(0).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // fx_impl::global_cable16_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // fx_impl::global_cable17_t<NV>
		this->getT(0).getT(1).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // fx_impl::global_cable18_t<NV>
		this->getT(0).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // fx_impl::global_cable13_t<NV>
		this->getT(0).getT(2).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // fx_impl::global_cable14_t<NV>
		this->getT(0).getT(2).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // fx_impl::global_cable15_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).setExternalData(b, index); // fx_impl::sliderbank3_t<NV>
		this->getT(0).getT(0).getT(2).setExternalData(b, index); // fx_impl::peak3_t<NV>
		this->getT(0).getT(1).getT(0).setExternalData(b, index); // fx_impl::sliderbank4_t<NV>
		this->getT(0).getT(1).getT(2).setExternalData(b, index); // fx_impl::peak5_t<NV>
		this->getT(0).getT(2).getT(0).setExternalData(b, index); // fx_impl::sliderbank5_t<NV>
		this->getT(0).getT(2).getT(2).setExternalData(b, index); // fx_impl::peak4_t<NV>
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
using fx = wrap::node<fx_impl::instance<NV>>;
}


