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

DECLARE_PARAMETER_RANGE_SKEW(xfader_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using xfader_c0 = parameter::from0To1<core::gain<NV>, 
                                      0, 
                                      xfader_c0Range>;

template <int NV> using xfader_c1 = xfader_c0<NV>;

template <int NV> using xfader_c2 = xfader_c0<NV>;

template <int NV> using xfader_c3 = xfader_c0<NV>;

template <int NV> using xfader_c4 = xfader_c0<NV>;

template <int NV> using xfader_c5 = xfader_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, 
                                        xfader_c1<NV>, 
                                        xfader_c2<NV>, 
                                        xfader_c3<NV>, 
                                        xfader_c4<NV>, 
                                        xfader_c5<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::switcher>;
using global_cable9_t_index = runtime_target::indexers::fix_hash<2333884>;

template <int NV>
using global_cable9_t = routing::global_cable<global_cable9_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable9_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable11_t_index = runtime_target::indexers::fix_hash<2333885>;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable11_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable10_t_index = runtime_target::indexers::fix_hash<2333886>;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable10_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable12_t_index = runtime_target::indexers::fix_hash<2333887>;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using event_data_reader5_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader5_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader6_t = event_data_reader5_t<NV>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader6_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain30_t<NV>>, 
                                  chain44_t<NV>, 
                                  chain43_t<NV>, 
                                  chain45_t<NV>, 
                                  chain46_t<NV>, 
                                  chain47_t<NV>>;

template <int NV>
using cable_table_t = wrap::data<control::cable_table<parameter::plain<math::add<NV>, 0>>, 
                                 data::external::table<1>>;
template <int NV>
using input_toggle_t = control::input_toggle<NV, 
                                             parameter::plain<cable_table_t<NV>, 0>>;

template <int NV>
using cable_pack_t = wrap::data<control::cable_pack<parameter::plain<math::add<NV>, 0>>, 
                                data::external::sliderpack<3>>;
template <int NV>
using input_toggle1_t = control::input_toggle<NV, 
                                              parameter::plain<cable_pack_t<NV>, 0>>;

template <int NV>
using ramp_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<input_toggle_t<NV>, 1>, 
                                  parameter::plain<input_toggle1_t<NV>, 1>>;

template <int NV>
using ramp_t = wrap::mod<ramp_mod<NV>, 
                         wrap::no_data<core::ramp<NV, false>>>;

template <int NV>
using tempo_sync_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<ramp_t<NV>, 0>, 
                                        parameter::plain<fx::sampleandhold<NV>, 0>>;

template <int NV>
using tempo_sync_t = wrap::mod<tempo_sync_mod<NV>, 
                               control::tempo_sync<NV>>;

DECLARE_PARAMETER_RANGE_STEP(clock_ramp_mod_1Range, 
                             1., 
                             64., 
                             1.);

template <int NV>
using clock_ramp_mod_1 = parameter::from0To1<fx::sampleandhold<NV>, 
                                             0, 
                                             clock_ramp_mod_1Range>;

template <int NV>
using clock_ramp_mod = parameter::chain<ranges::Identity, 
                                        parameter::plain<input_toggle_t<NV>, 2>, 
                                        clock_ramp_mod_1<NV>>;

template <int NV>
using clock_ramp_t = wrap::mod<clock_ramp_mod<NV>, 
                               wrap::no_data<core::clock_ramp<NV, false>>>;
DECLARE_PARAMETER_RANGE_STEP(pma1_mod_0Range, 
                             0., 
                             18., 
                             1.);

template <int NV>
using pma1_mod_0 = parameter::from0To1<tempo_sync_t<NV>, 
                                       0, 
                                       pma1_mod_0Range>;

template <int NV>
using pma1_mod_1 = parameter::from0To1<clock_ramp_t<NV>, 
                                       0, 
                                       pma1_mod_0Range>;

template <int NV>
using pma1_mod = parameter::chain<ranges::Identity, 
                                  pma1_mod_0<NV>, 
                                  pma1_mod_1<NV>>;

template <int NV>
using pma1_t = control::pma<NV, pma1_mod<NV>>;
template <int NV>
using peak5_t = wrap::mod<parameter::plain<pma1_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, xfader_t<NV>>, 
                                   split5_t<NV>, 
                                   peak5_t<NV>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain29_t<NV>>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split7_t<NV>>, 
                                     pma1_t<NV>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV> using xfader2_c0 = xfader_c0<NV>;

template <int NV> using xfader2_c1 = xfader_c0<NV>;

template <int NV> using xfader2_c2 = xfader_c0<NV>;

template <int NV> using xfader2_c3 = xfader_c0<NV>;

template <int NV> using xfader2_c4 = xfader_c0<NV>;

template <int NV> using xfader2_c5 = xfader_c0<NV>;

template <int NV>
using xfader2_multimod = parameter::list<xfader2_c0<NV>, 
                                         xfader2_c1<NV>, 
                                         xfader2_c2<NV>, 
                                         xfader2_c3<NV>, 
                                         xfader2_c4<NV>, 
                                         xfader2_c5<NV>>;

template <int NV>
using xfader2_t = control::xfader<xfader2_multimod<NV>, faders::switcher>;
using global_cable16_t_index = global_cable9_t_index;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain63_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable17_t_index = global_cable11_t_index;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain64_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable18_t_index = global_cable10_t_index;

template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain69_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable18_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable22_t_index = global_cable12_t_index;

template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable22_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader11_t = event_data_reader5_t<NV>;

template <int NV>
using chain71_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader11_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader12_t = event_data_reader5_t<NV>;

template <int NV>
using chain72_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader12_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split12_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain63_t<NV>>, 
                                   chain64_t<NV>, 
                                   chain69_t<NV>, 
                                   chain70_t<NV>, 
                                   chain71_t<NV>, 
                                   chain72_t<NV>>;

template <int NV> using pma4_mod = xfader_c0<NV>;

template <int NV>
using pma4_t = control::pma<NV, pma4_mod<NV>>;
namespace custom
{

struct expr4
{
	static float op(float input, float value)
	{
		return (1.0 - value) * input + value * Math.tan(Math.PI * 4.0 * value * input);
		;
	}
};
}

namespace custom
{

struct expr1
{
	static float op(float input, float value)
	{
		return input * Math.asin(Math.PI * 1.0 * value * input) * (1 - Math.PI);;
	}
};
}

namespace custom
{

struct expr2
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 12.0 * value * input) * (2 - Math.PI);;
	}
};
}

DECLARE_PARAMETER_RANGE_STEP(pma3_mod_1Range, 
                             -12., 
                             12., 
                             0.1);

template <int NV>
using pma3_mod_1 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       pma3_mod_1Range>;

DECLARE_PARAMETER_RANGE(pma3_mod_2Range, 
                        0.11, 
                        1.);

template <int NV>
using pma3_mod_2 = parameter::from0To1<math::expr<NV, custom::expr4>, 
                                       0, 
                                       pma3_mod_2Range>;

template <int NV>
using pma3_mod_3 = parameter::from0To1<math::expr<NV, custom::expr1>, 
                                       0, 
                                       pma3_mod_2Range>;

template <int NV>
using pma3_mod_4 = parameter::from0To1<math::expr<NV, custom::expr2>, 
                                       0, 
                                       pma3_mod_2Range>;

DECLARE_PARAMETER_RANGE_SKEW(pma3_mod_5Range, 
                             0., 
                             2000., 
                             0.231378);

template <int NV>
using pma3_mod_5 = parameter::from0To1<core::smoother<NV>, 
                                       0, 
                                       pma3_mod_5Range>;

template <int NV> using pma3_mod_6 = xfader_c0<NV>;

template <int NV>
using pma3_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<pma4_t<NV>, 2>, 
                                  pma3_mod_1<NV>, 
                                  pma3_mod_2<NV>, 
                                  pma3_mod_3<NV>, 
                                  pma3_mod_4<NV>, 
                                  pma3_mod_5<NV>, 
                                  pma3_mod_6<NV>>;

template <int NV>
using pma3_t = control::pma<NV, pma3_mod<NV>>;
template <int NV>
using peak8_t = wrap::mod<parameter::plain<pma3_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<1, xfader2_t<NV>>, 
                                   split12_t<NV>, 
                                   peak8_t<NV>>;

template <int NV>
using split11_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain62_t<NV>>>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split11_t<NV>>, 
                                      pma3_t<NV>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

template <int NV> using xfader1_c0 = xfader_c0<NV>;

template <int NV> using xfader1_c1 = xfader_c0<NV>;

template <int NV> using xfader1_c2 = xfader_c0<NV>;

template <int NV> using xfader1_c3 = xfader_c0<NV>;

template <int NV> using xfader1_c4 = xfader_c0<NV>;

template <int NV> using xfader1_c5 = xfader_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, 
                                         xfader1_c1<NV>, 
                                         xfader1_c2<NV>, 
                                         xfader1_c3<NV>, 
                                         xfader1_c4<NV>, 
                                         xfader1_c5<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::switcher>;
using global_cable13_t_index = global_cable9_t_index;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable14_t_index = global_cable11_t_index;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable15_t_index = global_cable10_t_index;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable23_t_index = global_cable12_t_index;

template <int NV>
using global_cable23_t = routing::global_cable<global_cable23_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable23_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader8_t = event_data_reader5_t<NV>;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader8_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader9_t = event_data_reader5_t<NV>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader9_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split10_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain54_t<NV>>, 
                                   chain55_t<NV>, 
                                   chain58_t<NV>, 
                                   chain59_t<NV>, 
                                   chain60_t<NV>, 
                                   chain61_t<NV>>;

template <int NV>
using peak6_t = wrap::mod<parameter::plain<control::pma<NV, parameter::empty>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, xfader1_t<NV>>, 
                                   split10_t<NV>, 
                                   peak6_t<NV>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain53_t<NV>>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split9_t<NV>>, 
                                      control::pma<NV, parameter::empty>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

template <int NV> using xfader3_c0 = xfader_c0<NV>;

template <int NV> using xfader3_c1 = xfader_c0<NV>;

template <int NV> using xfader3_c2 = xfader_c0<NV>;

template <int NV> using xfader3_c3 = xfader_c0<NV>;

template <int NV> using xfader3_c4 = xfader_c0<NV>;

template <int NV> using xfader3_c5 = xfader_c0<NV>;

template <int NV> using xfader3_c6 = xfader_c0<NV>;

template <int NV>
using xfader3_multimod = parameter::list<xfader3_c0<NV>, 
                                         xfader3_c1<NV>, 
                                         xfader3_c2<NV>, 
                                         xfader3_c3<NV>, 
                                         xfader3_c4<NV>, 
                                         xfader3_c5<NV>, 
                                         xfader3_c6<NV>>;

template <int NV>
using xfader3_t = control::xfader<xfader3_multimod<NV>, faders::switcher>;
using global_cable19_t_index = global_cable9_t_index;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain76_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable19_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable20_t_index = global_cable11_t_index;

template <int NV>
using global_cable20_t = routing::global_cable<global_cable20_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain77_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable20_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable24_t_index = global_cable10_t_index;

template <int NV>
using global_cable24_t = routing::global_cable<global_cable24_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain78_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable24_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable25_t_index = global_cable12_t_index;

template <int NV>
using global_cable25_t = routing::global_cable<global_cable25_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain79_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable25_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader14_t = event_data_reader5_t<NV>;

template <int NV>
using chain80_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader14_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader15_t = event_data_reader5_t<NV>;

template <int NV>
using chain81_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader15_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using midi_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                         control::midi<midi_logic::gate<NV>>>;

template <int NV>
using chain82_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using split14_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain76_t<NV>>, 
                                   chain77_t<NV>, 
                                   chain78_t<NV>, 
                                   chain79_t<NV>, 
                                   chain80_t<NV>, 
                                   chain81_t<NV>, 
                                   chain82_t<NV>>;

template <int NV>
using pma5_t = control::pma<NV, 
                            parameter::plain<ramp_t<NV>, 2>>;
template <int NV>
using peak10_t = wrap::mod<parameter::plain<pma5_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain75_t = container::chain<parameter::empty, 
                                   wrap::fix<1, xfader3_t<NV>>, 
                                   split14_t<NV>, 
                                   peak10_t<NV>>;

template <int NV>
using split13_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain75_t<NV>>>;

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
using cable_table2_t = wrap::data<control::cable_table<parameter::plain<pma5_t<NV>, 2>>, 
                                  data::embedded::table<cable_table2_t_data>>;

template <int NV>
using modchain3_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split13_t<NV>>, 
                                      cable_table2_t<NV>, 
                                      pma5_t<NV>>;

template <int NV>
using modchain3_t = wrap::control_rate<modchain3_t_<NV>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<2, modchain_t<NV>>, 
                                  modchain2_t<NV>, 
                                  modchain1_t<NV>, 
                                  modchain3_t<NV>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, tempo_sync_t<NV>>, 
                                  ramp_t<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain3_t<NV>>, 
                                    clock_ramp_t<NV>>;
using peak3_t = wrap::no_data<core::peak>;

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
                                   wrap::fix<1, oscillator_t<NV>>, 
                                   math::sig2mod<NV>>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, wrap::no_process<math::clear<NV>>>, 
                                   input_toggle_t<NV>, 
                                   cable_table_t<NV>, 
                                   math::add<NV>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   input_toggle1_t<NV>, 
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
using peak9_t = peak3_t;

template <int NV>
using chain73_t = container::chain<parameter::empty, 
                                   wrap::fix<1, pma4_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using chain74_t = container::chain<parameter::empty, 
                                   wrap::fix<1, core::smoother<NV>>, 
                                   wrap::no_process<math::sig2mod<NV>>, 
                                   wrap::no_process<math::sin<NV>>>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<1, fx::sampleandhold<NV>>, 
                                    fx::sampleandhold<NV>>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch6_t<NV>>, 
                                   core::gain<NV>, 
                                   wrap::no_process<math::sig2mod<NV>>, 
                                   wrap::no_process<math::sin<NV>>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, core::gain<NV>>, 
                                   math::pi<NV>, 
                                   math::fmod<NV>>;

template <int NV>
using chain65_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::expr<NV, custom::expr4>>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, wrap::no_process<math::sin<NV>>>, 
                                   math::expr<NV, custom::expr1>>;

template <int NV>
using chain56_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::expr<NV, custom::expr2>>>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain73_t<NV>>, 
                                    chain74_t<NV>, 
                                    chain22_t<NV>, 
                                    chain26_t<NV>, 
                                    chain65_t<NV>, 
                                    chain27_t<NV>, 
                                    chain56_t<NV>>;
using peak11_t = wrap::data<core::peak, 
                            data::external::displaybuffer<0>>;

using global_cable_t_index = global_cable9_t_index;

template <int NV>
using peak1_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<routing::global_cable<global_cable_t_index, parameter::empty>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>>;

template <int NV>
using peak1_t = wrap::mod<peak1_mod<NV>, 
                          wrap::no_data<core::peak>>;

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
                                 wrap::fix<1, peak1_t<NV>>, 
                                 split_t<NV>>;

using global_cable8_t_index = global_cable11_t_index;

template <int NV>
using peak12_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<routing::global_cable<global_cable8_t_index, parameter::empty>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>>;

template <int NV>
using peak12_t = wrap::mod<peak12_mod<NV>, 
                           wrap::no_data<core::peak>>;

using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::global_cable<global_cable8_t_index, parameter::empty>>>;

using global_cable29_t_index = runtime_target::indexers::fix_hash<-1395393919>;
using change8_mod = parameter::plain<routing::global_cable<global_cable29_t_index, parameter::empty>, 
                                     0>;
template <int NV>
using change8_t = control::change<NV, change8_mod>;
template <int NV>
using peak13_t = wrap::mod<parameter::plain<change8_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   math::add<NV>, 
                                   math::rect<NV>, 
                                   peak13_t<NV>, 
                                   change8_t<NV>, 
                                   routing::global_cable<global_cable29_t_index, parameter::empty>>;

using global_cable30_t_index = runtime_target::indexers::fix_hash<1752812597>;

namespace chain178_t_parameters
{
DECLARE_PARAMETER_RANGE_STEP(note_InputRange, 
                             0., 
                             127., 
                             1.);

using note = parameter::chain<note_InputRange, 
                              parameter::plain<routing::global_cable<global_cable30_t_index, parameter::empty>, 0>>;

}

using chain178_t = container::chain<chain178_t_parameters::note, 
                                    wrap::fix<1, routing::global_cable<global_cable30_t_index, parameter::empty>>>;
template <int NV>
using minmax6_t = control::minmax<NV, 
                                  parameter::plain<chain178_t, 0>>;
template <int NV>
using change9_t = control::change<NV, 
                                  parameter::plain<minmax6_t<NV>, 0>>;
template <int NV>
using peak18_t = wrap::mod<parameter::plain<change9_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain177_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax6_t<NV>>, 
                                    chain178_t>;

template <int NV>
using chain116_t = container::chain<parameter::empty, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    math::add<NV>, 
                                    peak18_t<NV>, 
                                    change9_t<NV>, 
                                    chain177_t<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain17_t>, 
                                  chain19_t<NV>, 
                                  chain116_t<NV>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak12_t<NV>>, 
                                   split6_t<NV>>;

using global_cable31_t_index = global_cable10_t_index;

template <int NV>
using peak19_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<routing::global_cable<global_cable31_t_index, parameter::empty>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>>;

template <int NV>
using peak19_t = wrap::mod<peak19_mod<NV>, 
                           wrap::no_data<core::peak>>;

using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::global_cable<global_cable31_t_index, parameter::empty>>>;

using global_cable32_t_index = runtime_target::indexers::fix_hash<-1395393918>;
using change10_mod = parameter::plain<routing::global_cable<global_cable32_t_index, parameter::empty>, 
                                      0>;
template <int NV>
using change10_t = control::change<NV, change10_mod>;
template <int NV>
using peak20_t = wrap::mod<parameter::plain<change10_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   math::add<NV>, 
                                   math::rect<NV>, 
                                   peak20_t<NV>, 
                                   change10_t<NV>, 
                                   routing::global_cable<global_cable32_t_index, parameter::empty>>;

using global_cable33_t_index = runtime_target::indexers::fix_hash<1752812598>;

namespace chain180_t_parameters
{
DECLARE_PARAMETER_RANGE_STEP(note_InputRange, 
                             0., 
                             127., 
                             1.);

using note = parameter::chain<note_InputRange, 
                              parameter::plain<routing::global_cable<global_cable33_t_index, parameter::empty>, 0>>;

}

using chain180_t = container::chain<chain180_t_parameters::note, 
                                    wrap::fix<1, routing::global_cable<global_cable33_t_index, parameter::empty>>>;
template <int NV>
using minmax7_t = control::minmax<NV, 
                                  parameter::plain<chain180_t, 0>>;
template <int NV>
using change11_t = control::change<NV, 
                                   parameter::plain<minmax7_t<NV>, 0>>;
template <int NV>
using peak21_t = wrap::mod<parameter::plain<change11_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain179_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax7_t<NV>>, 
                                    chain180_t>;

template <int NV>
using chain117_t = container::chain<parameter::empty, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    math::add<NV>, 
                                    peak21_t<NV>, 
                                    change11_t<NV>, 
                                    chain179_t<NV>>;

template <int NV>
using split15_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain21_t>, 
                                   chain23_t<NV>, 
                                   chain117_t<NV>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak19_t<NV>>, 
                                   split15_t<NV>>;

using global_cable34_t_index = global_cable12_t_index;

template <int NV>
using peak22_mod = parameter::chain<ranges::Identity, 
                                    parameter::plain<routing::global_cable<global_cable34_t_index, parameter::empty>, 0>, 
                                    parameter::plain<math::add<NV>, 0>, 
                                    parameter::plain<math::add<NV>, 0>>;

template <int NV>
using peak22_t = wrap::mod<peak22_mod<NV>, 
                           wrap::no_data<core::peak>>;

using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::global_cable<global_cable34_t_index, parameter::empty>>>;

using global_cable35_t_index = runtime_target::indexers::fix_hash<-1395393917>;
using change12_mod = parameter::plain<routing::global_cable<global_cable35_t_index, parameter::empty>, 
                                      0>;
template <int NV>
using change12_t = control::change<NV, change12_mod>;
template <int NV>
using peak23_t = wrap::mod<parameter::plain<change12_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, math::clear<NV>>, 
                                   math::add<NV>, 
                                   math::rect<NV>, 
                                   peak23_t<NV>, 
                                   change12_t<NV>, 
                                   routing::global_cable<global_cable35_t_index, parameter::empty>>;

using global_cable36_t_index = runtime_target::indexers::fix_hash<1752812599>;

namespace chain182_t_parameters
{
DECLARE_PARAMETER_RANGE_STEP(note_InputRange, 
                             0., 
                             127., 
                             1.);

using note = parameter::chain<note_InputRange, 
                              parameter::plain<routing::global_cable<global_cable36_t_index, parameter::empty>, 0>>;

}

using chain182_t = container::chain<chain182_t_parameters::note, 
                                    wrap::fix<1, routing::global_cable<global_cable36_t_index, parameter::empty>>>;
template <int NV>
using minmax8_t = control::minmax<NV, 
                                  parameter::plain<chain182_t, 0>>;
template <int NV>
using change13_t = control::change<NV, 
                                   parameter::plain<minmax8_t<NV>, 0>>;
template <int NV>
using peak24_t = wrap::mod<parameter::plain<change13_t<NV>, 0>, 
                           wrap::no_data<core::peak>>;

template <int NV>
using chain181_t = container::chain<parameter::empty, 
                                    wrap::fix<1, minmax8_t<NV>>, 
                                    chain182_t>;

template <int NV>
using chain118_t = container::chain<parameter::empty, 
                                    wrap::fix<1, math::clear<NV>>, 
                                    math::add<NV>, 
                                    peak24_t<NV>, 
                                    change13_t<NV>, 
                                    chain181_t<NV>>;

template <int NV>
using split16_t = container::split<parameter::empty, 
                                   wrap::fix<1, chain34_t>, 
                                   chain35_t<NV>, 
                                   chain118_t<NV>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, peak22_t<NV>>, 
                                   split16_t<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<1, chain_t<NV>>, 
                                   chain16_t<NV>, 
                                   chain20_t<NV>, 
                                   chain28_t<NV>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch2_t<NV>>, 
                                   peak9_t, 
                                   branch4_t<NV>, 
                                   peak11_t, 
                                   branch_t<NV>>;

template <int NV>
using modchain4_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, branch1_t<NV>>, 
                                      peak3_t, 
                                      chain11_t<NV>>;

template <int NV>
using modchain4_t = wrap::control_rate<modchain4_t_<NV>>;

template <int NV>
using fix8_block_t = container::chain<parameter::empty, 
                                      wrap::fix<2, split8_t<NV>>, 
                                      modchain4_t<NV>, 
                                      math::clear<NV>>;

template <int NV>
using wrapevent_data_reader41_t_ = container::chain<parameter::empty, 
                                                    wrap::fix<2, fix8_block_t<NV>>>;

template <int NV>
using wrapevent_data_reader41_t = wrap::event<wrapevent_data_reader41_t_<NV>>;

namespace lfo_t_parameters
{
// Parameter list for lfo_impl::lfo_t --------------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(tempo_InputRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using tempo = parameter::chain<tempo_InputRange, 
                               parameter::plain<lfo_impl::pma1_t<NV>, 2>>;

DECLARE_PARAMETER_RANGE_STEP(AjustMode_InputRange, 
                             1., 
                             7., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(AjustMode_0Range, 
                             0., 
                             6., 
                             1.);

template <int NV>
using AjustMode_0 = parameter::from0To1<lfo_impl::branch4_t<NV>, 
                                        0, 
                                        AjustMode_0Range>;

template <int NV>
using AjustMode = parameter::chain<AjustMode_InputRange, AjustMode_0<NV>>;

template <int NV>
using Clk = parameter::chain<ranges::Identity, 
                             parameter::plain<lfo_impl::input_toggle_t<NV>, 0>, 
                             parameter::plain<lfo_impl::input_toggle1_t<NV>, 0>, 
                             parameter::plain<lfo_impl::branch1_t<NV>, 0>, 
                             parameter::plain<lfo_impl::branch6_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(Div_InputRange, 
                        1., 
                        32.);
DECLARE_PARAMETER_RANGE_STEP(Div_1Range, 
                             1., 
                             16., 
                             1.);

template <int NV>
using Div_1 = parameter::from0To1<lfo_impl::tempo_sync_t<NV>, 
                                  1, 
                                  Div_1Range>;

template <int NV>
using Div_2 = parameter::from0To1<lfo_impl::clock_ramp_t<NV>, 
                                  1, 
                                  Div_1Range>;

template <int NV>
using Div = parameter::chain<Div_InputRange, 
                             parameter::plain<control::pma<NV, parameter::empty>, 2>, 
                             Div_1<NV>, 
                             Div_2<NV>>;

DECLARE_PARAMETER_RANGE_STEP(Shape_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using Shape_0 = parameter::from0To1<lfo_impl::branch2_t<NV>, 
                                    0, 
                                    AjustMode_0Range>;

template <int NV>
using Shape = parameter::chain<Shape_InputRange, Shape_0<NV>>;

template <int NV>
using Min = parameter::chain<ranges::Identity, 
                             parameter::plain<lfo_impl::minmax2_t<NV>, 1>, 
                             parameter::plain<lfo_impl::minmax6_t<NV>, 1>, 
                             parameter::plain<lfo_impl::minmax7_t<NV>, 1>, 
                             parameter::plain<lfo_impl::minmax8_t<NV>, 1>>;

template <int NV>
using Max = parameter::chain<ranges::Identity, 
                             parameter::plain<lfo_impl::minmax2_t<NV>, 2>, 
                             parameter::plain<lfo_impl::minmax6_t<NV>, 2>, 
                             parameter::plain<lfo_impl::minmax7_t<NV>, 2>, 
                             parameter::plain<lfo_impl::minmax8_t<NV>, 2>>;

template <int NV>
using Step = parameter::chain<ranges::Identity, 
                              parameter::plain<lfo_impl::minmax2_t<NV>, 4>, 
                              parameter::plain<lfo_impl::minmax6_t<NV>, 4>, 
                              parameter::plain<lfo_impl::minmax7_t<NV>, 4>, 
                              parameter::plain<lfo_impl::minmax8_t<NV>, 4>>;

template <int NV>
using GateMod = parameter::chain<ranges::Identity, 
                                 parameter::plain<lfo_impl::cable_table2_t<NV>, 0>, 
                                 parameter::plain<lfo_impl::pma5_t<NV>, 1>>;

DECLARE_PARAMETER_RANGE(tempoSrc_InputRange, 
                        1., 
                        6.);

template <int NV>
using tempoSrc = parameter::chain<tempoSrc_InputRange, 
                                  parameter::plain<lfo_impl::xfader_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(AdjSrc_InputRange, 
                        1., 
                        6.);

template <int NV>
using AdjSrc = parameter::chain<AdjSrc_InputRange, 
                                parameter::plain<lfo_impl::xfader2_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(GateSrc_InputRange, 
                        1., 
                        7.);

template <int NV>
using GateSrc = parameter::chain<GateSrc_InputRange, 
                                 parameter::plain<lfo_impl::xfader3_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE(Divsrc_InputRange, 
                        1., 
                        6.);

template <int NV>
using Divsrc = parameter::chain<Divsrc_InputRange, 
                                parameter::plain<lfo_impl::xfader1_t<NV>, 0>>;

template <int NV>
using Dest = parameter::plain<lfo_impl::branch_t<NV>, 0>;
using Gate = parameter::empty;
template <int NV>
using Adjust = parameter::plain<lfo_impl::pma3_t<NV>, 2>;
template <int NV>
using TempoMod = parameter::plain<lfo_impl::pma1_t<NV>, 1>;
template <int NV>
using AdjMod = parameter::plain<lfo_impl::pma3_t<NV>, 1>;
template <int NV>
using DivMod = parameter::plain<control::pma<NV, parameter::empty>, 
                                1>;
template <int NV>
using lfo_t_plist = parameter::list<tempo<NV>, 
                                    Dest<NV>, 
                                    AjustMode<NV>, 
                                    Clk<NV>, 
                                    Div<NV>, 
                                    Gate, 
                                    Adjust<NV>, 
                                    Shape<NV>, 
                                    Min<NV>, 
                                    Max<NV>, 
                                    Step<NV>, 
                                    TempoMod<NV>, 
                                    AdjMod<NV>, 
                                    GateMod<NV>, 
                                    DivMod<NV>, 
                                    tempoSrc<NV>, 
                                    AdjSrc<NV>, 
                                    GateSrc<NV>, 
                                    Divsrc<NV>>;
}

template <int NV>
using lfo_t_ = container::chain<lfo_t_parameters::lfo_t_plist<NV>, 
                                wrap::fix<2, math::clear<NV>>, 
                                wrapevent_data_reader41_t<NV>>;

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
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(300)
		{
			0x005B, 0x0000, 0x7400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0001, 0x0000, 0x6544, 0x7473, 0x0000, 0x0000, 0x0000, 0x4000, 
            0x0040, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0002, 
            0x0000, 0x6A41, 0x7375, 0x4D74, 0x646F, 0x0065, 0x0000, 0x3F80, 
            0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x035B, 0x0000, 0x4300, 0x6B6C, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0004, 
            0x0000, 0x6944, 0x0076, 0x0000, 0x3F80, 0x0000, 0x4200, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 0x4700, 
            0x7461, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x065B, 0x0000, 0x4100, 0x6A64, 
            0x7375, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0xA164, 0x3F73, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x075B, 0x0000, 0x5300, 0x6168, 
            0x6570, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x5B3F, 0x0008, 0x0000, 0x694D, 0x006E, 
            0x0000, 0x41C0, 0x0000, 0x42C0, 0x0000, 0x41C0, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x095B, 0x0000, 0x4D00, 0x7861, 0x0000, 0xC000, 
            0x0041, 0xC000, 0x0042, 0xC000, 0x0042, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x000A, 0x0000, 0x7453, 0x7065, 0x0000, 0x0000, 0x0000, 
            0x4000, 0x0041, 0x4000, 0x0041, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x000B, 0x0000, 0x6554, 0x706D, 0x4D6F, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x000C, 0x0000, 0x6441, 0x4D6A, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x383F, 0x32BD, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x000D, 0x0000, 0x6147, 0x6574, 0x6F4D, 0x0064, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0E5B, 0x0000, 0x4400, 0x7669, 0x6F4D, 0x0064, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0F5B, 0x0000, 0x7400, 0x6D65, 0x6F70, 0x7253, 0x0063, 
            0x0000, 0x3F80, 0x0000, 0x40C0, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x105B, 0x0000, 0x4100, 0x6A64, 0x7253, 0x0063, 
            0x0000, 0x3F80, 0x0000, 0x40C0, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x115B, 0x0000, 0x4700, 0x7461, 0x5365, 0x6372, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0xE000, 0x0040, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0012, 0x0000, 0x6944, 0x7376, 0x6372, 
            0x0000, 0x8000, 0x003F, 0xC000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& clear11 = this->getT(0);                                                       // math::clear<NV>
		auto& wrapevent_data_reader41 = this->getT(1);                                       // lfo_impl::wrapevent_data_reader41_t<NV>
		auto& fix8_block = this->getT(1).getT(0);                                            // lfo_impl::fix8_block_t<NV>
		auto& split8 = this->getT(1).getT(0).getT(0);                                        // lfo_impl::split8_t<NV>
		auto& modchain = this->getT(1).getT(0).getT(0).getT(0);                              // lfo_impl::modchain_t<NV>
		auto& split7 = this->getT(1).getT(0).getT(0).getT(0).getT(0);                        // lfo_impl::split7_t<NV>
		auto& chain29 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(0);               // lfo_impl::chain29_t<NV>
		auto& xfader = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);        // lfo_impl::xfader_t<NV>
		auto& split5 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);        // lfo_impl::split5_t<NV>
		auto& chain30 = this->getT(1).getT(0).getT(0).getT(0).                               // lfo_impl::chain30_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& global_cable9 = this->getT(1).getT(0).getT(0).getT(0).                         // lfo_impl::global_cable9_t<NV>
                              getT(0).getT(0).getT(1).getT(0).
                              getT(0);
		auto& add13 = this->getT(1).getT(0).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& gain1 = this->getT(1).getT(0).getT(0).getT(0).                                 // core::gain<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(2);
		auto& chain44 = this->getT(1).getT(0).getT(0).getT(0).                               // lfo_impl::chain44_t<NV>
                        getT(0).getT(0).getT(1).getT(1);
		auto& global_cable11 = this->getT(1).getT(0).getT(0).getT(0).                        // lfo_impl::global_cable11_t<NV>
                               getT(0).getT(0).getT(1).getT(1).
                               getT(0);
		auto& add14 = this->getT(1).getT(0).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& gain10 = this->getT(1).getT(0).getT(0).getT(0).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(2);
		auto& chain43 = this->getT(1).getT(0).getT(0).getT(0).                               // lfo_impl::chain43_t<NV>
                        getT(0).getT(0).getT(1).getT(2);
		auto& global_cable10 = this->getT(1).getT(0).getT(0).getT(0).                        // lfo_impl::global_cable10_t<NV>
                               getT(0).getT(0).getT(1).getT(2).
                               getT(0);
		auto& add15 = this->getT(1).getT(0).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& gain12 = this->getT(1).getT(0).getT(0).getT(0).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(2);
		auto& chain45 = this->getT(1).getT(0).getT(0).getT(0).                               // lfo_impl::chain45_t<NV>
                        getT(0).getT(0).getT(1).getT(3);
		auto& global_cable12 = this->getT(1).getT(0).getT(0).getT(0).                        // lfo_impl::global_cable12_t<NV>
                               getT(0).getT(0).getT(1).getT(3).
                               getT(0);
		auto& add16 = this->getT(1).getT(0).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& gain17 = this->getT(1).getT(0).getT(0).getT(0).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(3).
                       getT(2);
		auto& chain46 = this->getT(1).getT(0).getT(0).getT(0).                               // lfo_impl::chain46_t<NV>
                        getT(0).getT(0).getT(1).getT(4);
		auto& event_data_reader5 = this->getT(1).getT(0).getT(0).getT(0).                    // lfo_impl::event_data_reader5_t<NV>
                                   getT(0).getT(0).getT(1).getT(4).
                                   getT(0);
		auto& add17 = this->getT(1).getT(0).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& gain18 = this->getT(1).getT(0).getT(0).getT(0).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(4).
                       getT(2);
		auto& chain47 = this->getT(1).getT(0).getT(0).getT(0).                               // lfo_impl::chain47_t<NV>
                        getT(0).getT(0).getT(1).getT(5);
		auto& event_data_reader6 = this->getT(1).getT(0).getT(0).getT(0).                    // lfo_impl::event_data_reader6_t<NV>
                                   getT(0).getT(0).getT(1).getT(5).
                                   getT(0);
		auto& add18 = this->getT(1).getT(0).getT(0).getT(0).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& gain25 = this->getT(1).getT(0).getT(0).getT(0).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(5).
                       getT(2);
		auto& peak5 = this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(0).getT(2);         // lfo_impl::peak5_t<NV>
		auto& pma1 = this->getT(1).getT(0).getT(0).getT(0).getT(1);                          // lfo_impl::pma1_t<NV>
		auto& modchain2 = this->getT(1).getT(0).getT(0).getT(1);                             // lfo_impl::modchain2_t<NV>
		auto& split11 = this->getT(1).getT(0).getT(0).getT(1).getT(0);                       // lfo_impl::split11_t<NV>
		auto& chain62 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0);               // lfo_impl::chain62_t<NV>
		auto& xfader2 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);       // lfo_impl::xfader2_t<NV>
		auto& split12 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(1);       // lfo_impl::split12_t<NV>
		auto& chain63 = this->getT(1).getT(0).getT(0).getT(1).                               // lfo_impl::chain63_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& global_cable16 = this->getT(1).getT(0).getT(0).getT(1).                        // lfo_impl::global_cable16_t<NV>
                               getT(0).getT(0).getT(1).getT(0).
                               getT(0);
		auto& add25 = this->getT(1).getT(0).getT(0).getT(1).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& gain42 = this->getT(1).getT(0).getT(0).getT(1).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(2);
		auto& chain64 = this->getT(1).getT(0).getT(0).getT(1).                               // lfo_impl::chain64_t<NV>
                        getT(0).getT(0).getT(1).getT(1);
		auto& global_cable17 = this->getT(1).getT(0).getT(0).getT(1).                        // lfo_impl::global_cable17_t<NV>
                               getT(0).getT(0).getT(1).getT(1).
                               getT(0);
		auto& add26 = this->getT(1).getT(0).getT(0).getT(1).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& gain52 = this->getT(1).getT(0).getT(0).getT(1).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(2);
		auto& chain69 = this->getT(1).getT(0).getT(0).getT(1).                               // lfo_impl::chain69_t<NV>
                        getT(0).getT(0).getT(1).getT(2);
		auto& global_cable18 = this->getT(1).getT(0).getT(0).getT(1).                        // lfo_impl::global_cable18_t<NV>
                               getT(0).getT(0).getT(1).getT(2).
                               getT(0);
		auto& add27 = this->getT(1).getT(0).getT(0).getT(1).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& gain53 = this->getT(1).getT(0).getT(0).getT(1).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(2);
		auto& chain70 = this->getT(1).getT(0).getT(0).getT(1).                               // lfo_impl::chain70_t<NV>
                        getT(0).getT(0).getT(1).getT(3);
		auto& global_cable22 = this->getT(1).getT(0).getT(0).getT(1).                        // lfo_impl::global_cable22_t<NV>
                               getT(0).getT(0).getT(1).getT(3).
                               getT(0);
		auto& add28 = this->getT(1).getT(0).getT(0).getT(1).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& gain54 = this->getT(1).getT(0).getT(0).getT(1).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(3).
                       getT(2);
		auto& chain71 = this->getT(1).getT(0).getT(0).getT(1).                               // lfo_impl::chain71_t<NV>
                        getT(0).getT(0).getT(1).getT(4);
		auto& event_data_reader11 = this->getT(1).getT(0).getT(0).getT(1).                   // lfo_impl::event_data_reader11_t<NV>
                                    getT(0).getT(0).getT(1).getT(4).
                                    getT(0);
		auto& add29 = this->getT(1).getT(0).getT(0).getT(1).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& gain55 = this->getT(1).getT(0).getT(0).getT(1).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(4).
                       getT(2);
		auto& chain72 = this->getT(1).getT(0).getT(0).getT(1).                               // lfo_impl::chain72_t<NV>
                        getT(0).getT(0).getT(1).getT(5);
		auto& event_data_reader12 = this->getT(1).getT(0).getT(0).getT(1).                   // lfo_impl::event_data_reader12_t<NV>
                                    getT(0).getT(0).getT(1).getT(5).
                                    getT(0);
		auto& add30 = this->getT(1).getT(0).getT(0).getT(1).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& gain56 = this->getT(1).getT(0).getT(0).getT(1).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(5).
                       getT(2);
		auto& peak8 = this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(2);         // lfo_impl::peak8_t<NV>
		auto& pma3 = this->getT(1).getT(0).getT(0).getT(1).getT(1);                          // lfo_impl::pma3_t<NV>
		auto& modchain1 = this->getT(1).getT(0).getT(0).getT(2);                             // lfo_impl::modchain1_t<NV>
		auto& split9 = this->getT(1).getT(0).getT(0).getT(2).getT(0);                        // lfo_impl::split9_t<NV>
		auto& chain53 = this->getT(1).getT(0).getT(0).getT(2).getT(0).getT(0);               // lfo_impl::chain53_t<NV>
		auto& xfader1 = this->getT(1).getT(0).getT(0).getT(2).getT(0).getT(0).getT(0);       // lfo_impl::xfader1_t<NV>
		auto& split10 = this->getT(1).getT(0).getT(0).getT(2).getT(0).getT(0).getT(1);       // lfo_impl::split10_t<NV>
		auto& chain54 = this->getT(1).getT(0).getT(0).getT(2).                               // lfo_impl::chain54_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& global_cable13 = this->getT(1).getT(0).getT(0).getT(2).                        // lfo_impl::global_cable13_t<NV>
                               getT(0).getT(0).getT(1).getT(0).
                               getT(0);
		auto& add19 = this->getT(1).getT(0).getT(0).getT(2).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& gain28 = this->getT(1).getT(0).getT(0).getT(2).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(2);
		auto& chain55 = this->getT(1).getT(0).getT(0).getT(2).                               // lfo_impl::chain55_t<NV>
                        getT(0).getT(0).getT(1).getT(1);
		auto& global_cable14 = this->getT(1).getT(0).getT(0).getT(2).                        // lfo_impl::global_cable14_t<NV>
                               getT(0).getT(0).getT(1).getT(1).
                               getT(0);
		auto& add20 = this->getT(1).getT(0).getT(0).getT(2).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& gain29 = this->getT(1).getT(0).getT(0).getT(2).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(2);
		auto& chain58 = this->getT(1).getT(0).getT(0).getT(2).                               // lfo_impl::chain58_t<NV>
                        getT(0).getT(0).getT(1).getT(2);
		auto& global_cable15 = this->getT(1).getT(0).getT(0).getT(2).                        // lfo_impl::global_cable15_t<NV>
                               getT(0).getT(0).getT(1).getT(2).
                               getT(0);
		auto& add21 = this->getT(1).getT(0).getT(0).getT(2).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& gain30 = this->getT(1).getT(0).getT(0).getT(2).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(2);
		auto& chain59 = this->getT(1).getT(0).getT(0).getT(2).                               // lfo_impl::chain59_t<NV>
                        getT(0).getT(0).getT(1).getT(3);
		auto& global_cable23 = this->getT(1).getT(0).getT(0).getT(2).                        // lfo_impl::global_cable23_t<NV>
                               getT(0).getT(0).getT(1).getT(3).
                               getT(0);
		auto& add22 = this->getT(1).getT(0).getT(0).getT(2).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& gain31 = this->getT(1).getT(0).getT(0).getT(2).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(3).
                       getT(2);
		auto& chain60 = this->getT(1).getT(0).getT(0).getT(2).                               // lfo_impl::chain60_t<NV>
                        getT(0).getT(0).getT(1).getT(4);
		auto& event_data_reader8 = this->getT(1).getT(0).getT(0).getT(2).                    // lfo_impl::event_data_reader8_t<NV>
                                   getT(0).getT(0).getT(1).getT(4).
                                   getT(0);
		auto& add23 = this->getT(1).getT(0).getT(0).getT(2).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& gain32 = this->getT(1).getT(0).getT(0).getT(2).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(4).
                       getT(2);
		auto& chain61 = this->getT(1).getT(0).getT(0).getT(2).                               // lfo_impl::chain61_t<NV>
                        getT(0).getT(0).getT(1).getT(5);
		auto& event_data_reader9 = this->getT(1).getT(0).getT(0).getT(2).                    // lfo_impl::event_data_reader9_t<NV>
                                   getT(0).getT(0).getT(1).getT(5).
                                   getT(0);
		auto& add24 = this->getT(1).getT(0).getT(0).getT(2).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& gain41 = this->getT(1).getT(0).getT(0).getT(2).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(5).
                       getT(2);
		auto& peak6 = this->getT(1).getT(0).getT(0).getT(2).getT(0).getT(0).getT(2);         // lfo_impl::peak6_t<NV>
		auto& pma2 = this->getT(1).getT(0).getT(0).getT(2).getT(1);                          // control::pma<NV, parameter::empty>
		auto& modchain3 = this->getT(1).getT(0).getT(0).getT(3);                             // lfo_impl::modchain3_t<NV>
		auto& split13 = this->getT(1).getT(0).getT(0).getT(3).getT(0);                       // lfo_impl::split13_t<NV>
		auto& chain75 = this->getT(1).getT(0).getT(0).getT(3).getT(0).getT(0);               // lfo_impl::chain75_t<NV>
		auto& xfader3 = this->getT(1).getT(0).getT(0).getT(3).getT(0).getT(0).getT(0);       // lfo_impl::xfader3_t<NV>
		auto& split14 = this->getT(1).getT(0).getT(0).getT(3).getT(0).getT(0).getT(1);       // lfo_impl::split14_t<NV>
		auto& chain76 = this->getT(1).getT(0).getT(0).getT(3).                               // lfo_impl::chain76_t<NV>
                        getT(0).getT(0).getT(1).getT(0);
		auto& global_cable19 = this->getT(1).getT(0).getT(0).getT(3).                        // lfo_impl::global_cable19_t<NV>
                               getT(0).getT(0).getT(1).getT(0).
                               getT(0);
		auto& add31 = this->getT(1).getT(0).getT(0).getT(3).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(0).
                      getT(1);
		auto& gain58 = this->getT(1).getT(0).getT(0).getT(3).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(0).
                       getT(2);
		auto& chain77 = this->getT(1).getT(0).getT(0).getT(3).                               // lfo_impl::chain77_t<NV>
                        getT(0).getT(0).getT(1).getT(1);
		auto& global_cable20 = this->getT(1).getT(0).getT(0).getT(3).                        // lfo_impl::global_cable20_t<NV>
                               getT(0).getT(0).getT(1).getT(1).
                               getT(0);
		auto& add32 = this->getT(1).getT(0).getT(0).getT(3).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(1).
                      getT(1);
		auto& gain59 = this->getT(1).getT(0).getT(0).getT(3).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(1).
                       getT(2);
		auto& chain78 = this->getT(1).getT(0).getT(0).getT(3).                               // lfo_impl::chain78_t<NV>
                        getT(0).getT(0).getT(1).getT(2);
		auto& global_cable24 = this->getT(1).getT(0).getT(0).getT(3).                        // lfo_impl::global_cable24_t<NV>
                               getT(0).getT(0).getT(1).getT(2).
                               getT(0);
		auto& add33 = this->getT(1).getT(0).getT(0).getT(3).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(2).
                      getT(1);
		auto& gain60 = this->getT(1).getT(0).getT(0).getT(3).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(2).
                       getT(2);
		auto& chain79 = this->getT(1).getT(0).getT(0).getT(3).                               // lfo_impl::chain79_t<NV>
                        getT(0).getT(0).getT(1).getT(3);
		auto& global_cable25 = this->getT(1).getT(0).getT(0).getT(3).                        // lfo_impl::global_cable25_t<NV>
                               getT(0).getT(0).getT(1).getT(3).
                               getT(0);
		auto& add34 = this->getT(1).getT(0).getT(0).getT(3).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(3).
                      getT(1);
		auto& gain61 = this->getT(1).getT(0).getT(0).getT(3).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(3).
                       getT(2);
		auto& chain80 = this->getT(1).getT(0).getT(0).getT(3).                               // lfo_impl::chain80_t<NV>
                        getT(0).getT(0).getT(1).getT(4);
		auto& event_data_reader14 = this->getT(1).getT(0).getT(0).getT(3).                   // lfo_impl::event_data_reader14_t<NV>
                                    getT(0).getT(0).getT(1).getT(4).
                                    getT(0);
		auto& add35 = this->getT(1).getT(0).getT(0).getT(3).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(4).
                      getT(1);
		auto& gain62 = this->getT(1).getT(0).getT(0).getT(3).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(4).
                       getT(2);
		auto& chain81 = this->getT(1).getT(0).getT(0).getT(3).                               // lfo_impl::chain81_t<NV>
                        getT(0).getT(0).getT(1).getT(5);
		auto& event_data_reader15 = this->getT(1).getT(0).getT(0).getT(3).                   // lfo_impl::event_data_reader15_t<NV>
                                    getT(0).getT(0).getT(1).getT(5).
                                    getT(0);
		auto& add36 = this->getT(1).getT(0).getT(0).getT(3).                                 // math::add<NV>
                      getT(0).getT(0).getT(1).getT(5).
                      getT(1);
		auto& gain63 = this->getT(1).getT(0).getT(0).getT(3).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(5).
                       getT(2);
		auto& chain82 = this->getT(1).getT(0).getT(0).getT(3).                               // lfo_impl::chain82_t<NV>
                        getT(0).getT(0).getT(1).getT(6);
		auto& midi = this->getT(1).getT(0).getT(0).getT(3).                                  // lfo_impl::midi_t<NV>
                     getT(0).getT(0).getT(1).getT(6).
                     getT(0);
		auto& add3 = this->getT(1).getT(0).getT(0).getT(3).                                  // math::add<NV>
                     getT(0).getT(0).getT(1).getT(6).
                     getT(1);
		auto& gain64 = this->getT(1).getT(0).getT(0).getT(3).                                // core::gain<NV>
                       getT(0).getT(0).getT(1).getT(6).
                       getT(2);
		auto& peak10 = this->getT(1).getT(0).getT(0).getT(3).getT(0).getT(0).getT(2);        // lfo_impl::peak10_t<NV>
		auto& cable_table2 = this->getT(1).getT(0).getT(0).getT(3).getT(1);                  // lfo_impl::cable_table2_t<NV>
		auto& pma5 = this->getT(1).getT(0).getT(0).getT(3).getT(2);                          // lfo_impl::pma5_t<NV>
		auto& modchain4 = this->getT(1).getT(0).getT(1);                                     // lfo_impl::modchain4_t<NV>
		auto& branch1 = this->getT(1).getT(0).getT(1).getT(0);                               // lfo_impl::branch1_t<NV>
		auto& chain3 = this->getT(1).getT(0).getT(1).getT(0).getT(0);                        // lfo_impl::chain3_t<NV>
		auto& tempo_sync = this->getT(1).getT(0).getT(1).getT(0).getT(0).getT(0);            // lfo_impl::tempo_sync_t<NV>
		auto& ramp = this->getT(1).getT(0).getT(1).getT(0).getT(0).getT(1);                  // lfo_impl::ramp_t<NV>
		auto& clock_ramp = this->getT(1).getT(0).getT(1).getT(0).getT(1);                    // lfo_impl::clock_ramp_t<NV>
		auto& peak3 = this->getT(1).getT(0).getT(1).getT(1);                                 // lfo_impl::peak3_t
		auto& chain11 = this->getT(1).getT(0).getT(1).getT(2);                               // lfo_impl::chain11_t<NV>
		auto& branch2 = this->getT(1).getT(0).getT(1).getT(2).getT(0);                       // lfo_impl::branch2_t<NV>
		auto& chain25 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(0);               // lfo_impl::chain25_t<NV>
		auto& pi2 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(0).getT(0);           // math::pi<NV>
		auto& sin3 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(0).getT(1);          // math::sin<NV>
		auto& sig2mod4 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(0).getT(2);      // wrap::no_process<math::sig2mod<NV>>
		auto& chain24 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(1);               // lfo_impl::chain24_t<NV>
		auto& mul2 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(1).getT(0);          // wrap::no_process<math::mul<NV>>
		auto& sig2mod3 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(1).getT(1);      // wrap::no_process<math::sig2mod<NV>>
		auto& chain14 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(2);               // lfo_impl::chain14_t<NV>
		auto& add6 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(2).getT(0);          // math::add<NV>
		auto& fmod3 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(2).getT(1);         // math::fmod<NV>
		auto& sub = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(2).getT(2);           // math::sub<NV>
		auto& abs = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(2).getT(3);           // math::abs<NV>
		auto& mul1 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(2).getT(4);          // math::mul<NV>
		auto& chain18 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(3);               // lfo_impl::chain18_t<NV>
		auto& mod_inv1 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(3).getT(0);      // math::mod_inv<NV>
		auto& rect3 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(3).getT(1);         // math::rect<NV>
		auto& chain31 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(4);               // lfo_impl::chain31_t<NV>
		auto& oscillator = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(4).getT(0);    // lfo_impl::oscillator_t<NV>
		auto& sig2mod1 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(4).getT(1);      // math::sig2mod<NV>
		auto& chain32 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(5);               // lfo_impl::chain32_t<NV>
		auto& clear1 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(5).getT(0);        // wrap::no_process<math::clear<NV>>
		auto& input_toggle = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(5).getT(1);  // lfo_impl::input_toggle_t<NV>
		auto& cable_table = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(5).getT(2);   // lfo_impl::cable_table_t<NV>
		auto& add8 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(5).getT(3);          // math::add<NV>
		auto& chain33 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(6);               // lfo_impl::chain33_t<NV>
		auto& clear2 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(6).getT(0);        // math::clear<NV>
		auto& input_toggle1 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(6).getT(1); // lfo_impl::input_toggle1_t<NV>
		auto& cable_pack = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(6).getT(2);    // lfo_impl::cable_pack_t<NV>
		auto& add9 = this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(6).getT(3);          // math::add<NV>
		auto& peak9 = this->getT(1).getT(0).getT(1).getT(2).getT(1);                         // lfo_impl::peak9_t
		auto& branch4 = this->getT(1).getT(0).getT(1).getT(2).getT(2);                       // lfo_impl::branch4_t<NV>
		auto& chain73 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(0);               // lfo_impl::chain73_t<NV>
		auto& pma4 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(0).getT(0);          // lfo_impl::pma4_t<NV>
		auto& gain57 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(0).getT(1);        // core::gain<NV>
		auto& chain74 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(1);               // lfo_impl::chain74_t<NV>
		auto& smoother1 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(1).getT(0);     // core::smoother<NV>
		auto& sig2mod5 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(1).getT(1);      // wrap::no_process<math::sig2mod<NV>>
		auto& sin13 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(1).getT(2);         // wrap::no_process<math::sin<NV>>
		auto& chain22 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(2);               // lfo_impl::chain22_t<NV>
		auto& branch6 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(2).getT(0);       // lfo_impl::branch6_t<NV>
		auto& sampleandhold = this->getT(1).getT(0).getT(1).getT(2).                         // fx::sampleandhold<NV>
                              getT(2).getT(2).getT(0).getT(0);
		auto& sampleandhold2 = this->getT(1).getT(0).getT(1).getT(2).                   // fx::sampleandhold<NV>
                               getT(2).getT(2).getT(0).getT(1);
		auto& gain = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(2).getT(1);     // core::gain<NV>
		auto& sig2mod2 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(2).getT(2); // wrap::no_process<math::sig2mod<NV>>
		auto& sin4 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(2).getT(3);     // wrap::no_process<math::sin<NV>>
		auto& chain26 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(3);          // lfo_impl::chain26_t<NV>
		auto& gain37 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(3).getT(0);   // core::gain<NV>
		auto& pi5 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(3).getT(1);      // math::pi<NV>
		auto& fmod2 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(3).getT(2);    // math::fmod<NV>
		auto& chain65 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(4);          // lfo_impl::chain65_t<NV>
		auto& expr4 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(4).getT(0);    // math::expr<NV, custom::expr4>
		auto& chain27 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(5);          // lfo_impl::chain27_t<NV>
		auto& sin = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(5).getT(0);      // wrap::no_process<math::sin<NV>>
		auto& expr1 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(5).getT(1);    // math::expr<NV, custom::expr1>
		auto& chain56 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(6);          // lfo_impl::chain56_t<NV>
		auto& expr2 = this->getT(1).getT(0).getT(1).getT(2).getT(2).getT(6).getT(0);    // math::expr<NV, custom::expr2>
		auto& peak11 = this->getT(1).getT(0).getT(1).getT(2).getT(3);                   // lfo_impl::peak11_t
		auto& branch = this->getT(1).getT(0).getT(1).getT(2).getT(4);                   // lfo_impl::branch_t<NV>
		auto& chain = this->getT(1).getT(0).getT(1).getT(2).getT(4).getT(0);            // lfo_impl::chain_t<NV>
		auto& peak1 = this->getT(1).getT(0).getT(1).getT(2).getT(4).getT(0).getT(0);    // lfo_impl::peak1_t<NV>
		auto& split = this->getT(1).getT(0).getT(1).getT(2).getT(4).getT(0).getT(1);    // lfo_impl::split_t<NV>
		auto& chain4 = this->getT(1).getT(0).getT(1).getT(2).                           // lfo_impl::chain4_t
                       getT(4).getT(0).getT(1).getT(0);
		auto& global_cable = this->getT(1).getT(0).getT(1).getT(2).                    // routing::global_cable<global_cable_t_index, parameter::empty>
                             getT(4).getT(0).getT(1).getT(0).
                             getT(0);
		auto& chain5 = this->getT(1).getT(0).getT(1).getT(2).                          // lfo_impl::chain5_t<NV>
                       getT(4).getT(0).getT(1).getT(1);
		auto& clear = this->getT(1).getT(0).getT(1).getT(2).                           // math::clear<NV>
                      getT(4).getT(0).getT(1).getT(1).
                      getT(0);
		auto& add = this->getT(1).getT(0).getT(1).getT(2).                             // math::add<NV>
                    getT(4).getT(0).getT(1).getT(1).
                    getT(1);
		auto& rect = this->getT(1).getT(0).getT(1).getT(2).                            // math::rect<NV>
                     getT(4).getT(0).getT(1).getT(1).
                     getT(2);
		auto& peak = this->getT(1).getT(0).getT(1).getT(2).                            // lfo_impl::peak_t<NV>
                     getT(4).getT(0).getT(1).getT(1).
                     getT(3);
		auto& change = this->getT(1).getT(0).getT(1).getT(2).                          // lfo_impl::change_t<NV>
                       getT(4).getT(0).getT(1).getT(1).
                       getT(4);
		auto& global_cable2 = this->getT(1).getT(0).getT(1).getT(2).                   // routing::global_cable<global_cable2_t_index, parameter::empty>
                              getT(4).getT(0).getT(1).getT(1).
                              getT(5);
		auto& chain112 = this->getT(1).getT(0).getT(1).getT(2).                        // lfo_impl::chain112_t<NV>
                         getT(4).getT(0).getT(1).getT(2);
		auto& clear3 = this->getT(1).getT(0).getT(1).getT(2).                          // math::clear<NV>
                       getT(4).getT(0).getT(1).getT(2).
                       getT(0);
		auto& add43 = this->getT(1).getT(0).getT(1).getT(2).                           // math::add<NV>
                      getT(4).getT(0).getT(1).getT(2).
                      getT(1);
		auto& peak14 = this->getT(1).getT(0).getT(1).getT(2).                          // lfo_impl::peak14_t<NV>
                       getT(4).getT(0).getT(1).getT(2).
                       getT(2);
		auto& change3 = this->getT(1).getT(0).getT(1).getT(2).                         // lfo_impl::change3_t<NV>
                        getT(4).getT(0).getT(1).getT(2).
                        getT(3);
		auto& chain169 = this->getT(1).getT(0).getT(1).getT(2).                        // lfo_impl::chain169_t<NV>
                         getT(4).getT(0).getT(1).getT(2).
                         getT(4);
		auto& minmax2 = this->getT(1).getT(0).getT(1).getT(2).getT(4).                 // lfo_impl::minmax2_t<NV>
                        getT(0).getT(1).getT(2).getT(4).getT(0);
		auto& chain170 = this->getT(1).getT(0).getT(1).getT(2).getT(4).                // lfo_impl::chain170_t
                         getT(0).getT(1).getT(2).getT(4).getT(1);
		auto& global_cable21 = this->getT(1).getT(0).getT(1).getT(2).getT(4).          // routing::global_cable<global_cable21_t_index, parameter::empty>
                               getT(0).getT(1).getT(2).getT(4).getT(1).
                               getT(0);
		auto& chain16 = this->getT(1).getT(0).getT(1).getT(2).getT(4).getT(1);         // lfo_impl::chain16_t<NV>
		auto& peak12 = this->getT(1).getT(0).getT(1).getT(2).getT(4).getT(1).getT(0);  // lfo_impl::peak12_t<NV>
		auto& split6 = this->getT(1).getT(0).getT(1).getT(2).getT(4).getT(1).getT(1);  // lfo_impl::split6_t<NV>
		auto& chain17 = this->getT(1).getT(0).getT(1).getT(2).                         // lfo_impl::chain17_t
                        getT(4).getT(1).getT(1).getT(0);
		auto& global_cable8 = this->getT(1).getT(0).getT(1).getT(2).                   // routing::global_cable<global_cable8_t_index, parameter::empty>
                              getT(4).getT(1).getT(1).getT(0).
                              getT(0);
		auto& chain19 = this->getT(1).getT(0).getT(1).getT(2).                         // lfo_impl::chain19_t<NV>
                        getT(4).getT(1).getT(1).getT(1);
		auto& clear12 = this->getT(1).getT(0).getT(1).getT(2).                         // math::clear<NV>
                        getT(4).getT(1).getT(1).getT(1).
                        getT(0);
		auto& add5 = this->getT(1).getT(0).getT(1).getT(2).                            // math::add<NV>
                     getT(4).getT(1).getT(1).getT(1).
                     getT(1);
		auto& rect5 = this->getT(1).getT(0).getT(1).getT(2).                           // math::rect<NV>
                      getT(4).getT(1).getT(1).getT(1).
                      getT(2);
		auto& peak13 = this->getT(1).getT(0).getT(1).getT(2).                          // lfo_impl::peak13_t<NV>
                       getT(4).getT(1).getT(1).getT(1).
                       getT(3);
		auto& change8 = this->getT(1).getT(0).getT(1).getT(2).                         // lfo_impl::change8_t<NV>
                        getT(4).getT(1).getT(1).getT(1).
                        getT(4);
		auto& global_cable29 = this->getT(1).getT(0).getT(1).getT(2).                  // routing::global_cable<global_cable29_t_index, parameter::empty>
                               getT(4).getT(1).getT(1).getT(1).
                               getT(5);
		auto& chain116 = this->getT(1).getT(0).getT(1).getT(2).                        // lfo_impl::chain116_t<NV>
                         getT(4).getT(1).getT(1).getT(2);
		auto& clear13 = this->getT(1).getT(0).getT(1).getT(2).                         // math::clear<NV>
                        getT(4).getT(1).getT(1).getT(2).
                        getT(0);
		auto& add47 = this->getT(1).getT(0).getT(1).getT(2).                           // math::add<NV>
                      getT(4).getT(1).getT(1).getT(2).
                      getT(1);
		auto& peak18 = this->getT(1).getT(0).getT(1).getT(2).                          // lfo_impl::peak18_t<NV>
                       getT(4).getT(1).getT(1).getT(2).
                       getT(2);
		auto& change9 = this->getT(1).getT(0).getT(1).getT(2).                         // lfo_impl::change9_t<NV>
                        getT(4).getT(1).getT(1).getT(2).
                        getT(3);
		auto& chain177 = this->getT(1).getT(0).getT(1).getT(2).                        // lfo_impl::chain177_t<NV>
                         getT(4).getT(1).getT(1).getT(2).
                         getT(4);
		auto& minmax6 = this->getT(1).getT(0).getT(1).getT(2).getT(4).                 // lfo_impl::minmax6_t<NV>
                        getT(1).getT(1).getT(2).getT(4).getT(0);
		auto& chain178 = this->getT(1).getT(0).getT(1).getT(2).getT(4).                // lfo_impl::chain178_t
                         getT(1).getT(1).getT(2).getT(4).getT(1);
		auto& global_cable30 = this->getT(1).getT(0).getT(1).getT(2).getT(4).          // routing::global_cable<global_cable30_t_index, parameter::empty>
                               getT(1).getT(1).getT(2).getT(4).getT(1).
                               getT(0);
		auto& chain20 = this->getT(1).getT(0).getT(1).getT(2).getT(4).getT(2);         // lfo_impl::chain20_t<NV>
		auto& peak19 = this->getT(1).getT(0).getT(1).getT(2).getT(4).getT(2).getT(0);  // lfo_impl::peak19_t<NV>
		auto& split15 = this->getT(1).getT(0).getT(1).getT(2).getT(4).getT(2).getT(1); // lfo_impl::split15_t<NV>
		auto& chain21 = this->getT(1).getT(0).getT(1).getT(2).                         // lfo_impl::chain21_t
                        getT(4).getT(2).getT(1).getT(0);
		auto& global_cable31 = this->getT(1).getT(0).getT(1).getT(2).                  // routing::global_cable<global_cable31_t_index, parameter::empty>
                               getT(4).getT(2).getT(1).getT(0).
                               getT(0);
		auto& chain23 = this->getT(1).getT(0).getT(1).getT(2).                         // lfo_impl::chain23_t<NV>
                        getT(4).getT(2).getT(1).getT(1);
		auto& clear14 = this->getT(1).getT(0).getT(1).getT(2).                         // math::clear<NV>
                        getT(4).getT(2).getT(1).getT(1).
                        getT(0);
		auto& add7 = this->getT(1).getT(0).getT(1).getT(2).                            // math::add<NV>
                     getT(4).getT(2).getT(1).getT(1).
                     getT(1);
		auto& rect6 = this->getT(1).getT(0).getT(1).getT(2).                           // math::rect<NV>
                      getT(4).getT(2).getT(1).getT(1).
                      getT(2);
		auto& peak20 = this->getT(1).getT(0).getT(1).getT(2).                          // lfo_impl::peak20_t<NV>
                       getT(4).getT(2).getT(1).getT(1).
                       getT(3);
		auto& change10 = this->getT(1).getT(0).getT(1).getT(2).                        // lfo_impl::change10_t<NV>
                         getT(4).getT(2).getT(1).getT(1).
                         getT(4);
		auto& global_cable32 = this->getT(1).getT(0).getT(1).getT(2).                  // routing::global_cable<global_cable32_t_index, parameter::empty>
                               getT(4).getT(2).getT(1).getT(1).
                               getT(5);
		auto& chain117 = this->getT(1).getT(0).getT(1).getT(2).                        // lfo_impl::chain117_t<NV>
                         getT(4).getT(2).getT(1).getT(2);
		auto& clear15 = this->getT(1).getT(0).getT(1).getT(2).                         // math::clear<NV>
                        getT(4).getT(2).getT(1).getT(2).
                        getT(0);
		auto& add48 = this->getT(1).getT(0).getT(1).getT(2).                           // math::add<NV>
                      getT(4).getT(2).getT(1).getT(2).
                      getT(1);
		auto& peak21 = this->getT(1).getT(0).getT(1).getT(2).                          // lfo_impl::peak21_t<NV>
                       getT(4).getT(2).getT(1).getT(2).
                       getT(2);
		auto& change11 = this->getT(1).getT(0).getT(1).getT(2).                        // lfo_impl::change11_t<NV>
                         getT(4).getT(2).getT(1).getT(2).
                         getT(3);
		auto& chain179 = this->getT(1).getT(0).getT(1).getT(2).                        // lfo_impl::chain179_t<NV>
                         getT(4).getT(2).getT(1).getT(2).
                         getT(4);
		auto& minmax7 = this->getT(1).getT(0).getT(1).getT(2).getT(4).                 // lfo_impl::minmax7_t<NV>
                        getT(2).getT(1).getT(2).getT(4).getT(0);
		auto& chain180 = this->getT(1).getT(0).getT(1).getT(2).getT(4).                // lfo_impl::chain180_t
                         getT(2).getT(1).getT(2).getT(4).getT(1);
		auto& global_cable33 = this->getT(1).getT(0).getT(1).getT(2).getT(4).          // routing::global_cable<global_cable33_t_index, parameter::empty>
                               getT(2).getT(1).getT(2).getT(4).getT(1).
                               getT(0);
		auto& chain28 = this->getT(1).getT(0).getT(1).getT(2).getT(4).getT(3);         // lfo_impl::chain28_t<NV>
		auto& peak22 = this->getT(1).getT(0).getT(1).getT(2).getT(4).getT(3).getT(0);  // lfo_impl::peak22_t<NV>
		auto& split16 = this->getT(1).getT(0).getT(1).getT(2).getT(4).getT(3).getT(1); // lfo_impl::split16_t<NV>
		auto& chain34 = this->getT(1).getT(0).getT(1).getT(2).                         // lfo_impl::chain34_t
                        getT(4).getT(3).getT(1).getT(0);
		auto& global_cable34 = this->getT(1).getT(0).getT(1).getT(2).          // routing::global_cable<global_cable34_t_index, parameter::empty>
                               getT(4).getT(3).getT(1).getT(0).
                               getT(0);
		auto& chain35 = this->getT(1).getT(0).getT(1).getT(2).                 // lfo_impl::chain35_t<NV>
                        getT(4).getT(3).getT(1).getT(1);
		auto& clear16 = this->getT(1).getT(0).getT(1).getT(2).                 // math::clear<NV>
                        getT(4).getT(3).getT(1).getT(1).
                        getT(0);
		auto& add10 = this->getT(1).getT(0).getT(1).getT(2).                   // math::add<NV>
                      getT(4).getT(3).getT(1).getT(1).
                      getT(1);
		auto& rect7 = this->getT(1).getT(0).getT(1).getT(2).                   // math::rect<NV>
                      getT(4).getT(3).getT(1).getT(1).
                      getT(2);
		auto& peak23 = this->getT(1).getT(0).getT(1).getT(2).                  // lfo_impl::peak23_t<NV>
                       getT(4).getT(3).getT(1).getT(1).
                       getT(3);
		auto& change12 = this->getT(1).getT(0).getT(1).getT(2).                // lfo_impl::change12_t<NV>
                         getT(4).getT(3).getT(1).getT(1).
                         getT(4);
		auto& global_cable35 = this->getT(1).getT(0).getT(1).getT(2).          // routing::global_cable<global_cable35_t_index, parameter::empty>
                               getT(4).getT(3).getT(1).getT(1).
                               getT(5);
		auto& chain118 = this->getT(1).getT(0).getT(1).getT(2).                // lfo_impl::chain118_t<NV>
                         getT(4).getT(3).getT(1).getT(2);
		auto& clear17 = this->getT(1).getT(0).getT(1).getT(2).                 // math::clear<NV>
                        getT(4).getT(3).getT(1).getT(2).
                        getT(0);
		auto& add49 = this->getT(1).getT(0).getT(1).getT(2).                   // math::add<NV>
                      getT(4).getT(3).getT(1).getT(2).
                      getT(1);
		auto& peak24 = this->getT(1).getT(0).getT(1).getT(2).                  // lfo_impl::peak24_t<NV>
                       getT(4).getT(3).getT(1).getT(2).
                       getT(2);
		auto& change13 = this->getT(1).getT(0).getT(1).getT(2).                // lfo_impl::change13_t<NV>
                         getT(4).getT(3).getT(1).getT(2).
                         getT(3);
		auto& chain181 = this->getT(1).getT(0).getT(1).getT(2).                // lfo_impl::chain181_t<NV>
                         getT(4).getT(3).getT(1).getT(2).
                         getT(4);
		auto& minmax8 = this->getT(1).getT(0).getT(1).getT(2).getT(4).         // lfo_impl::minmax8_t<NV>
                        getT(3).getT(1).getT(2).getT(4).getT(0);
		auto& chain182 = this->getT(1).getT(0).getT(1).getT(2).getT(4).        // lfo_impl::chain182_t
                         getT(3).getT(1).getT(2).getT(4).getT(1);
		auto& global_cable36 = this->getT(1).getT(0).getT(1).getT(2).getT(4).  // routing::global_cable<global_cable36_t_index, parameter::empty>
                               getT(3).getT(1).getT(2).getT(4).getT(1).
                               getT(0);
		auto& clear10 = this->getT(1).getT(0).getT(2); // math::clear<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		chain170.getParameterT(0).connectT(0, global_cable21); // note -> global_cable21::Value
		chain170.getParameterT(0).connectT(0, global_cable21); // note -> global_cable21::Value
		chain178.getParameterT(0).connectT(0, global_cable30); // note -> global_cable30::Value
		chain178.getParameterT(0).connectT(0, global_cable30); // note -> global_cable30::Value
		chain180.getParameterT(0).connectT(0, global_cable33); // note -> global_cable33::Value
		chain180.getParameterT(0).connectT(0, global_cable33); // note -> global_cable33::Value
		chain182.getParameterT(0).connectT(0, global_cable36); // note -> global_cable36::Value
		chain182.getParameterT(0).connectT(0, global_cable36); // note -> global_cable36::Value
		this->getParameterT(0).connectT(0, pma1);              // tempo -> pma1::Add
		
		this->getParameterT(1).connectT(0, branch); // Dest -> branch::Index
		
		this->getParameterT(2).connectT(0, branch4); // AjustMode -> branch4::Index
		
		auto& Clk_p = this->getParameterT(3);
		Clk_p.connectT(0, input_toggle);  // Clk -> input_toggle::Input
		Clk_p.connectT(1, input_toggle1); // Clk -> input_toggle1::Input
		Clk_p.connectT(2, branch1);       // Clk -> branch1::Index
		Clk_p.connectT(3, branch6);       // Clk -> branch6::Index
		
		auto& Div_p = this->getParameterT(4);
		Div_p.connectT(0, pma2);       // Div -> pma2::Add
		Div_p.connectT(1, tempo_sync); // Div -> tempo_sync::Multiplier
		Div_p.connectT(2, clock_ramp); // Div -> clock_ramp::Multiplier
		
		this->getParameterT(6).connectT(0, pma3); // Adjust -> pma3::Add
		
		this->getParameterT(7).connectT(0, branch2); // Shape -> branch2::Index
		
		auto& Min_p = this->getParameterT(8);
		Min_p.connectT(0, minmax2); // Min -> minmax2::Minimum
		Min_p.connectT(1, minmax6); // Min -> minmax6::Minimum
		Min_p.connectT(2, minmax7); // Min -> minmax7::Minimum
		Min_p.connectT(3, minmax8); // Min -> minmax8::Minimum
		
		auto& Max_p = this->getParameterT(9);
		Max_p.connectT(0, minmax2); // Max -> minmax2::Maximum
		Max_p.connectT(1, minmax6); // Max -> minmax6::Maximum
		Max_p.connectT(2, minmax7); // Max -> minmax7::Maximum
		Max_p.connectT(3, minmax8); // Max -> minmax8::Maximum
		
		auto& Step_p = this->getParameterT(10);
		Step_p.connectT(0, minmax2); // Step -> minmax2::Step
		Step_p.connectT(1, minmax6); // Step -> minmax6::Step
		Step_p.connectT(2, minmax7); // Step -> minmax7::Step
		Step_p.connectT(3, minmax8); // Step -> minmax8::Step
		
		this->getParameterT(11).connectT(0, pma1); // TempoMod -> pma1::Multiply
		
		this->getParameterT(12).connectT(0, pma3); // AdjMod -> pma3::Multiply
		
		auto& GateMod_p = this->getParameterT(13);
		GateMod_p.connectT(0, cable_table2); // GateMod -> cable_table2::Value
		GateMod_p.connectT(1, pma5);         // GateMod -> pma5::Multiply
		
		this->getParameterT(14).connectT(0, pma2); // DivMod -> pma2::Multiply
		
		this->getParameterT(15).connectT(0, xfader); // tempoSrc -> xfader::Value
		
		this->getParameterT(16).connectT(0, xfader2); // AdjSrc -> xfader2::Value
		
		this->getParameterT(17).connectT(0, xfader3); // GateSrc -> xfader3::Value
		
		this->getParameterT(18).connectT(0, xfader1); // Divsrc -> xfader1::Value
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain1);                            // xfader -> gain1::Gain
		xfader_p.getParameterT(1).connectT(0, gain10);                           // xfader -> gain10::Gain
		xfader_p.getParameterT(2).connectT(0, gain12);                           // xfader -> gain12::Gain
		xfader_p.getParameterT(3).connectT(0, gain17);                           // xfader -> gain17::Gain
		xfader_p.getParameterT(4).connectT(0, gain18);                           // xfader -> gain18::Gain
		xfader_p.getParameterT(5).connectT(0, gain25);                           // xfader -> gain25::Gain
		global_cable9.getWrappedObject().getParameter().connectT(0, add13);      // global_cable9 -> add13::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add14);     // global_cable11 -> add14::Value
		global_cable10.getWrappedObject().getParameter().connectT(0, add15);     // global_cable10 -> add15::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add16);     // global_cable12 -> add16::Value
		event_data_reader5.getParameter().connectT(0, add17);                    // event_data_reader5 -> add17::Value
		event_data_reader6.getParameter().connectT(0, add18);                    // event_data_reader6 -> add18::Value
		cable_table.getWrappedObject().getParameter().connectT(0, add8);         // cable_table -> add8::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, cable_table); // input_toggle -> cable_table::Value
		cable_pack.getWrappedObject().getParameter().connectT(0, add9);          // cable_pack -> add9::Value
		input_toggle1.getWrappedObject().getParameter().connectT(0, cable_pack); // input_toggle1 -> cable_pack::Value
		ramp.getParameter().connectT(0, input_toggle);                           // ramp -> input_toggle::Value1
		ramp.getParameter().connectT(1, input_toggle1);                          // ramp -> input_toggle1::Value1
		tempo_sync.getParameter().connectT(0, ramp);                             // tempo_sync -> ramp::PeriodTime
		tempo_sync.getParameter().connectT(1, sampleandhold);                    // tempo_sync -> sampleandhold::Counter
		clock_ramp.getParameter().connectT(0, input_toggle);                     // clock_ramp -> input_toggle::Value2
		clock_ramp.getParameter().connectT(1, sampleandhold2);                   // clock_ramp -> sampleandhold2::Counter
		pma1.getWrappedObject().getParameter().connectT(0, tempo_sync);          // pma1 -> tempo_sync::Tempo
		pma1.getWrappedObject().getParameter().connectT(1, clock_ramp);          // pma1 -> clock_ramp::Tempo
		peak5.getParameter().connectT(0, pma1);                                  // peak5 -> pma1::Value
		auto& xfader2_p = xfader2.getWrappedObject().getParameter();
		xfader2_p.getParameterT(0).connectT(0, gain42);                      // xfader2 -> gain42::Gain
		xfader2_p.getParameterT(1).connectT(0, gain52);                      // xfader2 -> gain52::Gain
		xfader2_p.getParameterT(2).connectT(0, gain53);                      // xfader2 -> gain53::Gain
		xfader2_p.getParameterT(3).connectT(0, gain54);                      // xfader2 -> gain54::Gain
		xfader2_p.getParameterT(4).connectT(0, gain55);                      // xfader2 -> gain55::Gain
		xfader2_p.getParameterT(5).connectT(0, gain56);                      // xfader2 -> gain56::Gain
		global_cable16.getWrappedObject().getParameter().connectT(0, add25); // global_cable16 -> add25::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add26); // global_cable17 -> add26::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, add27); // global_cable18 -> add27::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add28); // global_cable22 -> add28::Value
		event_data_reader11.getParameter().connectT(0, add29);               // event_data_reader11 -> add29::Value
		event_data_reader12.getParameter().connectT(0, add30);               // event_data_reader12 -> add30::Value
		pma4.getWrappedObject().getParameter().connectT(0, gain57);          // pma4 -> gain57::Gain
		pma3.getWrappedObject().getParameter().connectT(0, pma4);            // pma3 -> pma4::Add
		pma3.getWrappedObject().getParameter().connectT(1, gain37);          // pma3 -> gain37::Gain
		pma3.getWrappedObject().getParameter().connectT(2, expr4);           // pma3 -> expr4::Value
		pma3.getWrappedObject().getParameter().connectT(3, expr1);           // pma3 -> expr1::Value
		pma3.getWrappedObject().getParameter().connectT(4, expr2);           // pma3 -> expr2::Value
		pma3.getWrappedObject().getParameter().connectT(5, smoother1);       // pma3 -> smoother1::SmoothingTime
		pma3.getWrappedObject().getParameter().connectT(6, gain);            // pma3 -> gain::Gain
		peak8.getParameter().connectT(0, pma3);                              // peak8 -> pma3::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain28);                      // xfader1 -> gain28::Gain
		xfader1_p.getParameterT(1).connectT(0, gain29);                      // xfader1 -> gain29::Gain
		xfader1_p.getParameterT(2).connectT(0, gain30);                      // xfader1 -> gain30::Gain
		xfader1_p.getParameterT(3).connectT(0, gain31);                      // xfader1 -> gain31::Gain
		xfader1_p.getParameterT(4).connectT(0, gain32);                      // xfader1 -> gain32::Gain
		xfader1_p.getParameterT(5).connectT(0, gain41);                      // xfader1 -> gain41::Gain
		global_cable13.getWrappedObject().getParameter().connectT(0, add19); // global_cable13 -> add19::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add20); // global_cable14 -> add20::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add21); // global_cable15 -> add21::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add22); // global_cable23 -> add22::Value
		event_data_reader8.getParameter().connectT(0, add23);                // event_data_reader8 -> add23::Value
		event_data_reader9.getParameter().connectT(0, add24);                // event_data_reader9 -> add24::Value
		peak6.getParameter().connectT(0, pma2);                              // peak6 -> pma2::Value
		auto& xfader3_p = xfader3.getWrappedObject().getParameter();
		xfader3_p.getParameterT(0).connectT(0, gain58);                         // xfader3 -> gain58::Gain
		xfader3_p.getParameterT(1).connectT(0, gain59);                         // xfader3 -> gain59::Gain
		xfader3_p.getParameterT(2).connectT(0, gain60);                         // xfader3 -> gain60::Gain
		xfader3_p.getParameterT(3).connectT(0, gain61);                         // xfader3 -> gain61::Gain
		xfader3_p.getParameterT(4).connectT(0, gain62);                         // xfader3 -> gain62::Gain
		xfader3_p.getParameterT(5).connectT(0, gain63);                         // xfader3 -> gain63::Gain
		xfader3_p.getParameterT(6).connectT(0, gain64);                         // xfader3 -> gain64::Gain
		global_cable19.getWrappedObject().getParameter().connectT(0, add31);    // global_cable19 -> add31::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add32);    // global_cable20 -> add32::Value
		global_cable24.getWrappedObject().getParameter().connectT(0, add33);    // global_cable24 -> add33::Value
		global_cable25.getWrappedObject().getParameter().connectT(0, add34);    // global_cable25 -> add34::Value
		event_data_reader14.getParameter().connectT(0, add35);                  // event_data_reader14 -> add35::Value
		event_data_reader15.getParameter().connectT(0, add36);                  // event_data_reader15 -> add36::Value
		midi.getParameter().connectT(0, add3);                                  // midi -> add3::Value
		pma5.getWrappedObject().getParameter().connectT(0, ramp);               // pma5 -> ramp::Gate
		peak10.getParameter().connectT(0, pma5);                                // peak10 -> pma5::Value
		cable_table2.getWrappedObject().getParameter().connectT(0, pma5);       // cable_table2 -> pma5::Add
		peak1.getParameter().connectT(0, global_cable);                         // peak1 -> global_cable::Value
		peak1.getParameter().connectT(1, add);                                  // peak1 -> add::Value
		peak1.getParameter().connectT(2, add43);                                // peak1 -> add43::Value
		change.getWrappedObject().getParameter().connectT(0, global_cable2);    // change -> global_cable2::Value
		peak.getParameter().connectT(0, change);                                // peak -> change::Value
		minmax2.getWrappedObject().getParameter().connectT(0, chain170);        // minmax2 -> chain170::note
		change3.getWrappedObject().getParameter().connectT(0, minmax2);         // change3 -> minmax2::Value
		peak14.getParameter().connectT(0, change3);                             // peak14 -> change3::Value
		peak12.getParameter().connectT(0, global_cable8);                       // peak12 -> global_cable8::Value
		peak12.getParameter().connectT(1, add5);                                // peak12 -> add5::Value
		peak12.getParameter().connectT(2, add47);                               // peak12 -> add47::Value
		change8.getWrappedObject().getParameter().connectT(0, global_cable29);  // change8 -> global_cable29::Value
		peak13.getParameter().connectT(0, change8);                             // peak13 -> change8::Value
		minmax6.getWrappedObject().getParameter().connectT(0, chain178);        // minmax6 -> chain178::note
		change9.getWrappedObject().getParameter().connectT(0, minmax6);         // change9 -> minmax6::Value
		peak18.getParameter().connectT(0, change9);                             // peak18 -> change9::Value
		peak19.getParameter().connectT(0, global_cable31);                      // peak19 -> global_cable31::Value
		peak19.getParameter().connectT(1, add7);                                // peak19 -> add7::Value
		peak19.getParameter().connectT(2, add48);                               // peak19 -> add48::Value
		change10.getWrappedObject().getParameter().connectT(0, global_cable32); // change10 -> global_cable32::Value
		peak20.getParameter().connectT(0, change10);                            // peak20 -> change10::Value
		minmax7.getWrappedObject().getParameter().connectT(0, chain180);        // minmax7 -> chain180::note
		change11.getWrappedObject().getParameter().connectT(0, minmax7);        // change11 -> minmax7::Value
		peak21.getParameter().connectT(0, change11);                            // peak21 -> change11::Value
		peak22.getParameter().connectT(0, global_cable34);                      // peak22 -> global_cable34::Value
		peak22.getParameter().connectT(1, add10);                               // peak22 -> add10::Value
		peak22.getParameter().connectT(2, add49);                               // peak22 -> add49::Value
		change12.getWrappedObject().getParameter().connectT(0, global_cable35); // change12 -> global_cable35::Value
		peak23.getParameter().connectT(0, change12);                            // peak23 -> change12::Value
		minmax8.getWrappedObject().getParameter().connectT(0, chain182);        // minmax8 -> chain182::note
		change13.getWrappedObject().getParameter().connectT(0, minmax8);        // change13 -> minmax8::Value
		peak24.getParameter().connectT(0, change13);                            // peak24 -> change13::Value
		
		// Default Values --------------------------------------------------------------------------
		
		clear11.setParameterT(0, 0.); // math::clear::Value
		
		; // xfader::Value is automated
		
		global_cable9.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add13::Value is automated
		
		;                            // gain1::Gain is automated
		gain1.setParameterT(1, 20.); // core::gain::Smoothing
		gain1.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add14::Value is automated
		
		;                             // gain10::Gain is automated
		gain10.setParameterT(1, 20.); // core::gain::Smoothing
		gain10.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add15::Value is automated
		
		;                             // gain12::Gain is automated
		gain12.setParameterT(1, 20.); // core::gain::Smoothing
		gain12.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add16::Value is automated
		
		;                             // gain17::Gain is automated
		gain17.setParameterT(1, 20.); // core::gain::Smoothing
		gain17.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader5.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader5.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add17::Value is automated
		
		;                             // gain18::Gain is automated
		gain18.setParameterT(1, 20.); // core::gain::Smoothing
		gain18.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader6.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader6.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add18::Value is automated
		
		;                             // gain25::Gain is automated
		gain25.setParameterT(1, 20.); // core::gain::Smoothing
		gain25.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		; // xfader2::Value is automated
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add25::Value is automated
		
		;                             // gain42::Gain is automated
		gain42.setParameterT(1, 20.); // core::gain::Smoothing
		gain42.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add26::Value is automated
		
		;                             // gain52::Gain is automated
		gain52.setParameterT(1, 20.); // core::gain::Smoothing
		gain52.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable18.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add27::Value is automated
		
		;                             // gain53::Gain is automated
		gain53.setParameterT(1, 20.); // core::gain::Smoothing
		gain53.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable22.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add28::Value is automated
		
		;                             // gain54::Gain is automated
		gain54.setParameterT(1, 20.); // core::gain::Smoothing
		gain54.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader11.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader11.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add29::Value is automated
		
		;                             // gain55::Gain is automated
		gain55.setParameterT(1, 20.); // core::gain::Smoothing
		gain55.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader12.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader12.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add30::Value is automated
		
		;                             // gain56::Gain is automated
		gain56.setParameterT(1, 20.); // core::gain::Smoothing
		gain56.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma3::Value is automated
		; // pma3::Multiply is automated
		; // pma3::Add is automated
		
		; // xfader1::Value is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add19::Value is automated
		
		;                             // gain28::Gain is automated
		gain28.setParameterT(1, 20.); // core::gain::Smoothing
		gain28.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add20::Value is automated
		
		;                             // gain29::Gain is automated
		gain29.setParameterT(1, 20.); // core::gain::Smoothing
		gain29.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add21::Value is automated
		
		;                             // gain30::Gain is automated
		gain30.setParameterT(1, 20.); // core::gain::Smoothing
		gain30.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable23.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add22::Value is automated
		
		;                             // gain31::Gain is automated
		gain31.setParameterT(1, 20.); // core::gain::Smoothing
		gain31.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader8.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader8.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add23::Value is automated
		
		;                             // gain32::Gain is automated
		gain32.setParameterT(1, 20.); // core::gain::Smoothing
		gain32.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader9.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader9.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add24::Value is automated
		
		;                             // gain41::Gain is automated
		gain41.setParameterT(1, 20.); // core::gain::Smoothing
		gain41.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma2::Value is automated
		; // pma2::Multiply is automated
		; // pma2::Add is automated
		
		; // xfader3::Value is automated
		
		global_cable19.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add31::Value is automated
		
		;                             // gain58::Gain is automated
		gain58.setParameterT(1, 20.); // core::gain::Smoothing
		gain58.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable20.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add32::Value is automated
		
		;                             // gain59::Gain is automated
		gain59.setParameterT(1, 20.); // core::gain::Smoothing
		gain59.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable24.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add33::Value is automated
		
		;                             // gain60::Gain is automated
		gain60.setParameterT(1, 20.); // core::gain::Smoothing
		gain60.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable25.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add34::Value is automated
		
		;                             // gain61::Gain is automated
		gain61.setParameterT(1, 20.); // core::gain::Smoothing
		gain61.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader14.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader14.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add35::Value is automated
		
		;                             // gain62::Gain is automated
		gain62.setParameterT(1, 20.); // core::gain::Smoothing
		gain62.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader15.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader15.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add36::Value is automated
		
		;                             // gain63::Gain is automated
		gain63.setParameterT(1, 20.); // core::gain::Smoothing
		gain63.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add3::Value is automated
		
		;                             // gain64::Gain is automated
		gain64.setParameterT(1, 20.); // core::gain::Smoothing
		gain64.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // cable_table2::Value is automated
		
		; // pma5::Value is automated
		; // pma5::Multiply is automated
		; // pma5::Add is automated
		
		; // branch1::Index is automated
		
		;                                  // tempo_sync::Tempo is automated
		;                                  // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		;                          // ramp::PeriodTime is automated
		ramp.setParameterT(1, 0.); // core::ramp::LoopStart
		;                          // ramp::Gate is automated
		
		;                                // clock_ramp::Tempo is automated
		;                                // clock_ramp::Multiplier is automated
		clock_ramp.setParameterT(2, 1.); // core::clock_ramp::AddToSignal
		clock_ramp.setParameterT(3, 1.); // core::clock_ramp::UpdateMode
		clock_ramp.setParameterT(4, 0.); // core::clock_ramp::Inactive
		
		chain11.setParameterT(0, 11.9328); // container::chain::freq
		
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
		
		sig2mod1.setParameterT(0, 0.); // math::sig2mod::Value
		
		clear1.setParameterT(0, 0.); // math::clear::Value
		
		; // input_toggle::Input is automated
		; // input_toggle::Value1 is automated
		; // input_toggle::Value2 is automated
		
		; // cable_table::Value is automated
		
		; // add8::Value is automated
		
		clear2.setParameterT(0, 0.); // math::clear::Value
		
		;                                   // input_toggle1::Input is automated
		;                                   // input_toggle1::Value1 is automated
		input_toggle1.setParameterT(2, 0.); // control::input_toggle::Value2
		
		; // cable_pack::Value is automated
		
		; // add9::Value is automated
		
		; // branch4::Index is automated
		
		pma4.setParameterT(0, 0.); // control::pma::Value
		pma4.setParameterT(1, 1.); // control::pma::Multiply
		;                          // pma4::Add is automated
		
		;                               // gain57::Gain is automated
		gain57.setParameterT(1, 0.);    // core::gain::Smoothing
		gain57.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                               // smoother1::SmoothingTime is automated
		smoother1.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		sig2mod5.setParameterT(0, 0.); // math::sig2mod::Value
		
		sin13.setParameterT(0, 1.); // math::sin::Value
		
		; // branch6::Index is automated
		
		; // sampleandhold::Counter is automated
		
		; // sampleandhold2::Counter is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		sig2mod2.setParameterT(0, 0.); // math::sig2mod::Value
		
		sin4.setParameterT(0, 1.); // math::sin::Value
		
		;                             // gain37::Gain is automated
		gain37.setParameterT(1, 20.); // core::gain::Smoothing
		gain37.setParameterT(2, 0.);  // core::gain::ResetValue
		
		pi5.setParameterT(0, 1.); // math::pi::Value
		
		fmod2.setParameterT(0, 1.); // math::fmod::Value
		
		; // expr4::Value is automated
		
		sin.setParameterT(0, 1.); // math::sin::Value
		
		; // expr1::Value is automated
		
		; // expr2::Value is automated
		
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
		
		; // global_cable8::Value is automated
		
		clear12.setParameterT(0, 0.); // math::clear::Value
		
		; // add5::Value is automated
		
		rect5.setParameterT(0, 0.); // math::rect::Value
		
		; // change8::Value is automated
		
		; // global_cable29::Value is automated
		
		clear13.setParameterT(0, 0.); // math::clear::Value
		
		; // add47::Value is automated
		
		; // change9::Value is automated
		
		;                             // minmax6::Value is automated
		;                             // minmax6::Minimum is automated
		;                             // minmax6::Maximum is automated
		minmax6.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax6::Step is automated
		minmax6.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // chain178::note is automated
		
		; // global_cable30::Value is automated
		
		; // global_cable31::Value is automated
		
		clear14.setParameterT(0, 0.); // math::clear::Value
		
		; // add7::Value is automated
		
		rect6.setParameterT(0, 0.); // math::rect::Value
		
		; // change10::Value is automated
		
		; // global_cable32::Value is automated
		
		clear15.setParameterT(0, 0.); // math::clear::Value
		
		; // add48::Value is automated
		
		; // change11::Value is automated
		
		;                             // minmax7::Value is automated
		;                             // minmax7::Minimum is automated
		;                             // minmax7::Maximum is automated
		minmax7.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax7::Step is automated
		minmax7.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // chain180::note is automated
		
		; // global_cable33::Value is automated
		
		; // global_cable34::Value is automated
		
		clear16.setParameterT(0, 0.); // math::clear::Value
		
		; // add10::Value is automated
		
		rect7.setParameterT(0, 0.); // math::rect::Value
		
		; // change12::Value is automated
		
		; // global_cable35::Value is automated
		
		clear17.setParameterT(0, 0.); // math::clear::Value
		
		; // add49::Value is automated
		
		; // change13::Value is automated
		
		;                             // minmax8::Value is automated
		;                             // minmax8::Minimum is automated
		;                             // minmax8::Maximum is automated
		minmax8.setParameterT(3, 1.); // control::minmax::Skew
		;                             // minmax8::Step is automated
		minmax8.setParameterT(5, 0.); // control::minmax::Polarity
		
		; // chain182::note is automated
		
		; // global_cable36::Value is automated
		
		clear10.setParameterT(0, 0.); // math::clear::Value
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.951681);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 24.);
		this->setParameterT(9, 96.);
		this->setParameterT(10, 12.);
		this->setParameterT(11, 0.);
		this->setParameterT(12, 0.6982);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 0.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 7.);
		this->setParameterT(18, 1.);
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
		
		this->getT(1).getT(0).getT(0).getT(0).          // lfo_impl::global_cable9_t<NV>
        getT(0).getT(0).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(0).          // lfo_impl::global_cable11_t<NV>
        getT(0).getT(0).getT(1).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(0).          // lfo_impl::global_cable10_t<NV>
        getT(0).getT(0).getT(1).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(0).          // lfo_impl::global_cable12_t<NV>
        getT(0).getT(0).getT(1).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(1).          // lfo_impl::global_cable16_t<NV>
        getT(0).getT(0).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(1).          // lfo_impl::global_cable17_t<NV>
        getT(0).getT(0).getT(1).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(1).          // lfo_impl::global_cable18_t<NV>
        getT(0).getT(0).getT(1).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(1).          // lfo_impl::global_cable22_t<NV>
        getT(0).getT(0).getT(1).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(2).          // lfo_impl::global_cable13_t<NV>
        getT(0).getT(0).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(2).          // lfo_impl::global_cable14_t<NV>
        getT(0).getT(0).getT(1).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(2).          // lfo_impl::global_cable15_t<NV>
        getT(0).getT(0).getT(1).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(2).          // lfo_impl::global_cable23_t<NV>
        getT(0).getT(0).getT(1).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(3).          // lfo_impl::global_cable19_t<NV>
        getT(0).getT(0).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(3).          // lfo_impl::global_cable20_t<NV>
        getT(0).getT(0).getT(1).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(3).          // lfo_impl::global_cable24_t<NV>
        getT(0).getT(0).getT(1).getT(2).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(0).getT(3).          // lfo_impl::global_cable25_t<NV>
        getT(0).getT(0).getT(1).getT(3).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(1).getT(2).          // routing::global_cable<global_cable_t_index, parameter::empty>
        getT(4).getT(0).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(1).getT(2).          // routing::global_cable<global_cable2_t_index, parameter::empty>
        getT(4).getT(0).getT(1).getT(1).
        getT(5).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(1).getT(2).getT(4).  // routing::global_cable<global_cable21_t_index, parameter::empty>
        getT(0).getT(1).getT(2).getT(4).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(1).getT(2).          // routing::global_cable<global_cable8_t_index, parameter::empty>
        getT(4).getT(1).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(1).getT(2).          // routing::global_cable<global_cable29_t_index, parameter::empty>
        getT(4).getT(1).getT(1).getT(1).
        getT(5).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(1).getT(2).getT(4).  // routing::global_cable<global_cable30_t_index, parameter::empty>
        getT(1).getT(1).getT(2).getT(4).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(1).getT(2).          // routing::global_cable<global_cable31_t_index, parameter::empty>
        getT(4).getT(2).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(1).getT(2).          // routing::global_cable<global_cable32_t_index, parameter::empty>
        getT(4).getT(2).getT(1).getT(1).
        getT(5).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(1).getT(2).getT(4).  // routing::global_cable<global_cable33_t_index, parameter::empty>
        getT(2).getT(1).getT(2).getT(4).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(1).getT(2).          // routing::global_cable<global_cable34_t_index, parameter::empty>
        getT(4).getT(3).getT(1).getT(0).
        getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(1).getT(2).          // routing::global_cable<global_cable35_t_index, parameter::empty>
        getT(4).getT(3).getT(1).getT(1).
        getT(5).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(0).getT(1).getT(2).getT(4).  // routing::global_cable<global_cable36_t_index, parameter::empty>
        getT(3).getT(1).getT(2).getT(4).getT(1).
        getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(1).getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index); // lfo_impl::peak5_t<NV>
		this->getT(1).getT(0).getT(0).getT(1).getT(0).getT(0).getT(2).setExternalData(b, index); // lfo_impl::peak8_t<NV>
		this->getT(1).getT(0).getT(0).getT(2).getT(0).getT(0).getT(2).setExternalData(b, index); // lfo_impl::peak6_t<NV>
		this->getT(1).getT(0).getT(0).getT(3).getT(0).getT(0).getT(2).setExternalData(b, index); // lfo_impl::peak10_t<NV>
		this->getT(1).getT(0).getT(0).getT(3).getT(1).setExternalData(b, index);                 // lfo_impl::cable_table2_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(0).getT(1).setExternalData(b, index);         // lfo_impl::ramp_t<NV>
		this->getT(1).getT(0).getT(1).getT(0).getT(1).setExternalData(b, index);                 // lfo_impl::clock_ramp_t<NV>
		this->getT(1).getT(0).getT(1).getT(1).setExternalData(b, index);                         // lfo_impl::peak3_t
		this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(4).getT(0).setExternalData(b, index); // lfo_impl::oscillator_t<NV>
		this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(5).getT(2).setExternalData(b, index); // lfo_impl::cable_table_t<NV>
		this->getT(1).getT(0).getT(1).getT(2).getT(0).getT(6).getT(2).setExternalData(b, index); // lfo_impl::cable_pack_t<NV>
		this->getT(1).getT(0).getT(1).getT(2).getT(1).setExternalData(b, index);                 // lfo_impl::peak9_t
		this->getT(1).getT(0).getT(1).getT(2).getT(3).setExternalData(b, index);                 // lfo_impl::peak11_t
		this->getT(1).getT(0).getT(1).getT(2).getT(4).getT(0).getT(0).setExternalData(b, index); // lfo_impl::peak1_t<NV>
		this->getT(1).getT(0).getT(1).getT(2).                                                   // lfo_impl::peak_t<NV>
        getT(4).getT(0).getT(1).getT(1).
        getT(3).setExternalData(b, index);
		this->getT(1).getT(0).getT(1).getT(2).                                                   // lfo_impl::peak14_t<NV>
        getT(4).getT(0).getT(1).getT(2).
        getT(2).setExternalData(b, index);
		this->getT(1).getT(0).getT(1).getT(2).getT(4).getT(1).getT(0).setExternalData(b, index); // lfo_impl::peak12_t<NV>
		this->getT(1).getT(0).getT(1).getT(2).                                                   // lfo_impl::peak13_t<NV>
        getT(4).getT(1).getT(1).getT(1).
        getT(3).setExternalData(b, index);
		this->getT(1).getT(0).getT(1).getT(2).                                                   // lfo_impl::peak18_t<NV>
        getT(4).getT(1).getT(1).getT(2).
        getT(2).setExternalData(b, index);
		this->getT(1).getT(0).getT(1).getT(2).getT(4).getT(2).getT(0).setExternalData(b, index); // lfo_impl::peak19_t<NV>
		this->getT(1).getT(0).getT(1).getT(2).                                                   // lfo_impl::peak20_t<NV>
        getT(4).getT(2).getT(1).getT(1).
        getT(3).setExternalData(b, index);
		this->getT(1).getT(0).getT(1).getT(2).                                                   // lfo_impl::peak21_t<NV>
        getT(4).getT(2).getT(1).getT(2).
        getT(2).setExternalData(b, index);
		this->getT(1).getT(0).getT(1).getT(2).getT(4).getT(3).getT(0).setExternalData(b, index); // lfo_impl::peak22_t<NV>
		this->getT(1).getT(0).getT(1).getT(2).                                                   // lfo_impl::peak23_t<NV>
        getT(4).getT(3).getT(1).getT(1).
        getT(3).setExternalData(b, index);
		this->getT(1).getT(0).getT(1).getT(2).  // lfo_impl::peak24_t<NV>
        getT(4).getT(3).getT(1).getT(2).
        getT(2).setExternalData(b, index);
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


