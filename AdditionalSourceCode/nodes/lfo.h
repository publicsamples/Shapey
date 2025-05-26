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

template <int NV>
using event_data_reader4_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader4_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader5_t = event_data_reader4_t<NV>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader5_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader6_t = event_data_reader4_t<NV>;

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

template <int NV> using event_data_reader10_t = event_data_reader4_t<NV>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader10_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader11_t = event_data_reader4_t<NV>;

template <int NV>
using chain71_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader11_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader12_t = event_data_reader4_t<NV>;

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

template <int NV> using pma3_mod_6 = pma3_mod_5<NV>;

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

template <int NV> using event_data_reader7_t = event_data_reader4_t<NV>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader7_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader8_t = event_data_reader4_t<NV>;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader8_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader9_t = event_data_reader4_t<NV>;

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

template <int NV> using event_data_reader13_t = event_data_reader4_t<NV>;

template <int NV>
using chain79_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader13_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader14_t = event_data_reader4_t<NV>;

template <int NV>
using chain80_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader14_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader15_t = event_data_reader4_t<NV>;

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

struct cable_table1_t_data
{
	span<float, 512> data =
	{
		1.f, 0.996024f, 0.992048f, 0.988072f, 0.984096f, 0.98012f,
		0.976144f, 0.972168f, 0.968192f, 0.964216f, 0.96024f, 0.956264f,
		0.952288f, 0.948312f, 0.944336f, 0.94036f, 0.936384f, 0.932408f,
		0.928432f, 0.924456f, 0.92048f, 0.916504f, 0.912528f, 0.908552f,
		0.904576f, 0.900599f, 0.896623f, 0.892648f, 0.888671f, 0.884695f,
		0.880719f, 0.876743f, 0.872767f, 0.868791f, 0.864815f, 0.860839f,
		0.856863f, 0.852887f, 0.848911f, 0.844935f, 0.840959f, 0.836983f,
		0.833007f, 0.829031f, 0.825055f, 0.821079f, 0.817103f, 0.813127f,
		0.809151f, 0.805175f, 0.801199f, 0.797223f, 0.793247f, 0.789271f,
		0.785295f, 0.781319f, 0.777343f, 0.773367f, 0.769391f, 0.765415f,
		0.761439f, 0.757463f, 0.753487f, 0.749511f, 0.745535f, 0.741559f,
		0.737583f, 0.733607f, 0.729631f, 0.725655f, 0.721679f, 0.717703f,
		0.713727f, 0.709751f, 0.705775f, 0.701799f, 0.697823f, 0.693846f,
		0.68987f, 0.685894f, 0.681918f, 0.677942f, 0.673966f, 0.66999f,
		0.666014f, 0.662038f, 0.658062f, 0.654086f, 0.65011f, 0.646134f,
		0.642158f, 0.638182f, 0.634206f, 0.63023f, 0.626254f, 0.622278f,
		0.618302f, 0.614326f, 0.61035f, 0.606374f, 0.602398f, 0.598422f,
		0.594446f, 0.59047f, 0.586494f, 0.582518f, 0.578542f, 0.574566f,
		0.57059f, 0.566614f, 0.562638f, 0.558662f, 0.554686f, 0.55071f,
		0.546734f, 0.542758f, 0.538782f, 0.534806f, 0.53083f, 0.526854f,
		0.522878f, 0.518902f, 0.514926f, 0.51095f, 0.506974f, 0.502998f,
		0.499022f, 0.495046f, 0.491069f, 0.487094f, 0.483117f, 0.479141f,
		0.475165f, 0.471189f, 0.467213f, 0.463237f, 0.459261f, 0.455285f,
		0.451309f, 0.447333f, 0.443357f, 0.439381f, 0.435405f, 0.431429f,
		0.427453f, 0.423477f, 0.419501f, 0.415525f, 0.411549f, 0.407573f,
		0.403597f, 0.399621f, 0.395645f, 0.391669f, 0.387693f, 0.383717f,
		0.379741f, 0.375765f, 0.371789f, 0.367813f, 0.363837f, 0.359861f,
		0.355885f, 0.351909f, 0.347933f, 0.343957f, 0.339981f, 0.336005f,
		0.332029f, 0.328053f, 0.324077f, 0.320101f, 0.316125f, 0.312149f,
		0.308173f, 0.304197f, 0.300221f, 0.296245f, 0.292269f, 0.288292f,
		0.284316f, 0.28034f, 0.276364f, 0.272388f, 0.268412f, 0.264436f,
		0.26046f, 0.256484f, 0.252508f, 0.248532f, 0.244556f, 0.24058f,
		0.236604f, 0.232628f, 0.228652f, 0.224676f, 0.2207f, 0.216724f,
		0.212748f, 0.208772f, 0.204796f, 0.20082f, 0.196844f, 0.192868f,
		0.188892f, 0.184916f, 0.18094f, 0.176964f, 0.172988f, 0.169012f,
		0.165036f, 0.16106f, 0.157084f, 0.153108f, 0.149132f, 0.145156f,
		0.14118f, 0.137204f, 0.133228f, 0.129252f, 0.125276f, 0.1213f,
		0.117324f, 0.113348f, 0.109372f, 0.105396f, 0.10142f, 0.0974436f,
		0.0934675f, 0.0894916f, 0.0855155f, 0.0815395f, 0.0775635f, 0.0735875f,
		0.0696114f, 0.0656354f, 0.0616595f, 0.0576833f, 0.0537073f, 0.0497313f,
		0.0457554f, 0.0417793f, 0.0378032f, 0.0338273f, 0.0298512f, 0.0258753f,
		0.0218992f, 0.0179232f, 0.0139471f, 0.0099712f, 0.00599515f, 0.00201905f,
		0.0547943f, 0.166122f, 0.277452f, 0.38878f, 0.500109f, 0.611437f,
		0.722765f, 0.834093f, 0.945424f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f
	};
};

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<parameter::plain<pma5_t<NV>, 2>>, 
                                  data::embedded::table<cable_table1_t_data>>;

template <int NV>
using modchain3_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split13_t<NV>>, 
                                      cable_table1_t<NV>, 
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
using wrapevent_data_reader41_t_ = container::chain<parameter::empty, 
                                                    wrap::fix<2, split8_t<NV>>>;

template <int NV>
using wrapevent_data_reader41_t = wrap::event<wrapevent_data_reader41_t_<NV>>;

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
using peak9_t = wrap::data<core::peak, 
                           data::external::displaybuffer<0>>;

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
                                   core::smoother<NV>, 
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

using split1_t = container::split<parameter::empty, 
                                  wrap::fix<1, core::empty>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch2_t<NV>>, 
                                   peak9_t, 
                                   branch4_t<NV>, 
                                   split1_t>;

using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, core::empty>>;

template <int NV> using simple_ar1_c0 = pma3_mod_1<NV>;

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

using global_cable_t_index = global_cable9_t_index;
using global_cable4_t_index = global_cable11_t_index;
using global_cable6_t_index = global_cable10_t_index;

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
                          wrap::data<core::peak, data::external::displaybuffer<1>>>;

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

template <int NV>
using modchain4_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, branch1_t<NV>>, 
                                      peak3_t, 
                                      chain11_t<NV>, 
                                      branch3_t<NV>, 
                                      peak7_t<NV>, 
                                      wrap::no_process<math::sig2mod<NV>>, 
                                      branch_t<NV>>;

template <int NV>
using modchain4_t = wrap::control_rate<modchain4_t_<NV>>;

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
                             parameter::plain<lfo_impl::minmax5_t<NV>, 1>>;

template <int NV>
using Max = parameter::chain<ranges::Identity, 
                             parameter::plain<lfo_impl::minmax6_t<NV>, 2>, 
                             parameter::plain<lfo_impl::minmax5_t<NV>, 2>, 
                             parameter::plain<lfo_impl::minmax2_t<NV>, 2>>;

template <int NV>
using Step = parameter::chain<ranges::Identity, 
                              parameter::plain<lfo_impl::minmax2_t<NV>, 4>, 
                              parameter::plain<lfo_impl::minmax6_t<NV>, 4>, 
                              parameter::plain<lfo_impl::minmax5_t<NV>, 4>>;

DECLARE_PARAMETER_RANGE(GateMod_InputRange, 
                        -1., 
                        1.);
DECLARE_PARAMETER_RANGE(GateMod_1Range, 
                        -1., 
                        1.);

template <int NV>
using GateMod_1 = parameter::from0To1<lfo_impl::pma5_t<NV>, 
                                      1, 
                                      GateMod_1Range>;

template <int NV>
using GateMod = parameter::chain<GateMod_InputRange, 
                                 parameter::plain<lfo_impl::cable_table1_t<NV>, 0>, 
                                 GateMod_1<NV>>;

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
template <int NV>
using Gate = parameter::plain<lfo_impl::branch3_t<NV>, 
                              0>;
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
                                    Gate<NV>, 
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
                                wrap::fix<2, wrapevent_data_reader41_t<NV>>, 
                                modchain4_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public lfo_impl::lfo_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 2;
		static const int NumSliderPacks = 4;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 2;
		
		SNEX_METADATA_ID(lfo);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(300)
		{
			0x005B, 0x0000, 0x7400, 0x6D65, 0x6F70, 0x0000, 0x0000, 0x0000, 
            0x9000, 0x0041, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0001, 0x0000, 0x6544, 0x7473, 0x0000, 0x0000, 0x0000, 0x0000, 
            0x0040, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0002, 
            0x0000, 0x6A41, 0x7375, 0x4D74, 0x646F, 0x0065, 0x0000, 0x3F80, 
            0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x035B, 0x0000, 0x4300, 0x6B6C, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0004, 
            0x0000, 0x6944, 0x0076, 0x0000, 0x3F80, 0x0000, 0x4200, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 0x4700, 
            0x7461, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x065B, 0x0000, 0x4100, 0x6A64, 
            0x7375, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F53, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x075B, 0x0000, 0x5300, 0x6168, 
            0x6570, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0xE000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x5B3F, 0x0008, 0x0000, 0x694D, 0x006E, 
            0x0000, 0x41C0, 0x0000, 0x42C0, 0x0000, 0x4214, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x095B, 0x0000, 0x4D00, 0x7861, 0x0000, 0xC000, 
            0x0041, 0xC000, 0xD342, 0x9B0B, 0x0042, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x000A, 0x0000, 0x7453, 0x7065, 0x0000, 0x0000, 0x0000, 
            0x4000, 0x2141, 0x428B, 0x0040, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x000B, 0x0000, 0x6554, 0x706D, 0x4D6F, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0xFA3F, 0xD27E, 0x003D, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x000C, 0x0000, 0x6441, 0x4D6A, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x000D, 0x0000, 0x6147, 0x6574, 0x6F4D, 0x0064, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0E5B, 0x0000, 0x4400, 0x7669, 0x6F4D, 0x0064, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0F5B, 0x0000, 0x7400, 0x6D65, 0x6F70, 0x7253, 0x0063, 
            0x0000, 0x3F80, 0x0000, 0x40C0, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x105B, 0x0000, 0x4100, 0x6A64, 0x7253, 0x0063, 
            0x0000, 0x3F80, 0x0000, 0x40C0, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x115B, 0x0000, 0x4700, 0x7461, 0x5365, 0x6372, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0012, 0x0000, 0x6944, 0x7376, 0x6372, 
            0x0000, 0x8000, 0x003F, 0xC000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& wrapevent_data_reader41 = this->getT(0);                                  // lfo_impl::wrapevent_data_reader41_t<NV>
		auto& split8 = this->getT(0).getT(0);                                           // lfo_impl::split8_t<NV>
		auto& modchain = this->getT(0).getT(0).getT(0);                                 // lfo_impl::modchain_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(0).getT(0);                           // lfo_impl::split7_t<NV>
		auto& chain29 = this->getT(0).getT(0).getT(0).getT(0).getT(0);                  // lfo_impl::chain29_t<NV>
		auto& xfader = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(0);           // lfo_impl::xfader_t<NV>
		auto& split5 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1);           // lfo_impl::split5_t<NV>
		auto& chain30 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);  // lfo_impl::chain30_t<NV>
		auto& global_cable9 = this->getT(0).getT(0).getT(0).getT(0).                    // lfo_impl::global_cable9_t<NV>
                              getT(0).getT(1).getT(0).getT(0);
		auto& add13 = this->getT(0).getT(0).getT(0).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(0).getT(1);
		auto& gain1 = this->getT(0).getT(0).getT(0).getT(0).                            // core::gain<NV>
                      getT(0).getT(1).getT(0).getT(2);
		auto& chain44 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);  // lfo_impl::chain44_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(0).getT(0).                   // lfo_impl::global_cable11_t<NV>
                               getT(0).getT(1).getT(1).getT(0);
		auto& add14 = this->getT(0).getT(0).getT(0).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(1).getT(1);
		auto& gain10 = this->getT(0).getT(0).getT(0).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(1).getT(2);
		auto& chain43 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(2);  // lfo_impl::chain43_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(0).getT(0).                   // lfo_impl::global_cable10_t<NV>
                               getT(0).getT(1).getT(2).getT(0);
		auto& add15 = this->getT(0).getT(0).getT(0).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(2).getT(1);
		auto& gain12 = this->getT(0).getT(0).getT(0).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(2).getT(2);
		auto& chain45 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(3);  // lfo_impl::chain45_t<NV>
		auto& event_data_reader4 = this->getT(0).getT(0).getT(0).getT(0).               // lfo_impl::event_data_reader4_t<NV>
                                   getT(0).getT(1).getT(3).getT(0);
		auto& add16 = this->getT(0).getT(0).getT(0).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(3).getT(1);
		auto& gain17 = this->getT(0).getT(0).getT(0).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(3).getT(2);
		auto& chain46 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(4);  // lfo_impl::chain46_t<NV>
		auto& event_data_reader5 = this->getT(0).getT(0).getT(0).getT(0).               // lfo_impl::event_data_reader5_t<NV>
                                   getT(0).getT(1).getT(4).getT(0);
		auto& add17 = this->getT(0).getT(0).getT(0).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(4).getT(1);
		auto& gain18 = this->getT(0).getT(0).getT(0).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(4).getT(2);
		auto& chain47 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(1).getT(5);  // lfo_impl::chain47_t<NV>
		auto& event_data_reader6 = this->getT(0).getT(0).getT(0).getT(0).               // lfo_impl::event_data_reader6_t<NV>
                                   getT(0).getT(1).getT(5).getT(0);
		auto& add18 = this->getT(0).getT(0).getT(0).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(5).getT(1);
		auto& gain25 = this->getT(0).getT(0).getT(0).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(5).getT(2);
		auto& peak5 = this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2);            // lfo_impl::peak5_t<NV>
		auto& pma1 = this->getT(0).getT(0).getT(0).getT(1);                             // lfo_impl::pma1_t<NV>
		auto& modchain2 = this->getT(0).getT(0).getT(1);                                // lfo_impl::modchain2_t<NV>
		auto& split11 = this->getT(0).getT(0).getT(1).getT(0);                          // lfo_impl::split11_t<NV>
		auto& chain62 = this->getT(0).getT(0).getT(1).getT(0).getT(0);                  // lfo_impl::chain62_t<NV>
		auto& xfader2 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(0);          // lfo_impl::xfader2_t<NV>
		auto& split12 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1);          // lfo_impl::split12_t<NV>
		auto& chain63 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).getT(0);  // lfo_impl::chain63_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(1).getT(0).                   // lfo_impl::global_cable16_t<NV>
                               getT(0).getT(1).getT(0).getT(0);
		auto& add25 = this->getT(0).getT(0).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(0).getT(1);
		auto& gain42 = this->getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(0).getT(2);
		auto& chain64 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).getT(1);  // lfo_impl::chain64_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(1).getT(0).                   // lfo_impl::global_cable17_t<NV>
                               getT(0).getT(1).getT(1).getT(0);
		auto& add26 = this->getT(0).getT(0).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(1).getT(1);
		auto& gain52 = this->getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(1).getT(2);
		auto& chain69 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).getT(2);  // lfo_impl::chain69_t<NV>
		auto& global_cable18 = this->getT(0).getT(0).getT(1).getT(0).                   // lfo_impl::global_cable18_t<NV>
                               getT(0).getT(1).getT(2).getT(0);
		auto& add27 = this->getT(0).getT(0).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(2).getT(1);
		auto& gain53 = this->getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(2).getT(2);
		auto& chain70 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).getT(3);  // lfo_impl::chain70_t<NV>
		auto& event_data_reader10 = this->getT(0).getT(0).getT(1).getT(0).              // lfo_impl::event_data_reader10_t<NV>
                                    getT(0).getT(1).getT(3).getT(0);
		auto& add28 = this->getT(0).getT(0).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(3).getT(1);
		auto& gain54 = this->getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(3).getT(2);
		auto& chain71 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).getT(4);  // lfo_impl::chain71_t<NV>
		auto& event_data_reader11 = this->getT(0).getT(0).getT(1).getT(0).              // lfo_impl::event_data_reader11_t<NV>
                                    getT(0).getT(1).getT(4).getT(0);
		auto& add29 = this->getT(0).getT(0).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(4).getT(1);
		auto& gain55 = this->getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(4).getT(2);
		auto& chain72 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(1).getT(5);  // lfo_impl::chain72_t<NV>
		auto& event_data_reader12 = this->getT(0).getT(0).getT(1).getT(0).              // lfo_impl::event_data_reader12_t<NV>
                                    getT(0).getT(1).getT(5).getT(0);
		auto& add30 = this->getT(0).getT(0).getT(1).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(5).getT(1);
		auto& gain56 = this->getT(0).getT(0).getT(1).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(5).getT(2);
		auto& peak8 = this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(2);            // lfo_impl::peak8_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(1).getT(1);                             // lfo_impl::pma3_t<NV>
		auto& modchain1 = this->getT(0).getT(0).getT(2);                                // lfo_impl::modchain1_t<NV>
		auto& split9 = this->getT(0).getT(0).getT(2).getT(0);                           // lfo_impl::split9_t<NV>
		auto& chain53 = this->getT(0).getT(0).getT(2).getT(0).getT(0);                  // lfo_impl::chain53_t<NV>
		auto& xfader1 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(0);          // lfo_impl::xfader1_t<NV>
		auto& split10 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1);          // lfo_impl::split10_t<NV>
		auto& chain54 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1).getT(0);  // lfo_impl::chain54_t<NV>
		auto& global_cable13 = this->getT(0).getT(0).getT(2).getT(0).                   // lfo_impl::global_cable13_t<NV>
                               getT(0).getT(1).getT(0).getT(0);
		auto& add19 = this->getT(0).getT(0).getT(2).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(0).getT(1);
		auto& gain28 = this->getT(0).getT(0).getT(2).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(0).getT(2);
		auto& chain55 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1).getT(1);  // lfo_impl::chain55_t<NV>
		auto& global_cable14 = this->getT(0).getT(0).getT(2).getT(0).                   // lfo_impl::global_cable14_t<NV>
                               getT(0).getT(1).getT(1).getT(0);
		auto& add20 = this->getT(0).getT(0).getT(2).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(1).getT(1);
		auto& gain29 = this->getT(0).getT(0).getT(2).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(1).getT(2);
		auto& chain58 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1).getT(2);  // lfo_impl::chain58_t<NV>
		auto& global_cable15 = this->getT(0).getT(0).getT(2).getT(0).                   // lfo_impl::global_cable15_t<NV>
                               getT(0).getT(1).getT(2).getT(0);
		auto& add21 = this->getT(0).getT(0).getT(2).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(2).getT(1);
		auto& gain30 = this->getT(0).getT(0).getT(2).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(2).getT(2);
		auto& chain59 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1).getT(3);  // lfo_impl::chain59_t<NV>
		auto& event_data_reader7 = this->getT(0).getT(0).getT(2).getT(0).               // lfo_impl::event_data_reader7_t<NV>
                                   getT(0).getT(1).getT(3).getT(0);
		auto& add22 = this->getT(0).getT(0).getT(2).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(3).getT(1);
		auto& gain31 = this->getT(0).getT(0).getT(2).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(3).getT(2);
		auto& chain60 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1).getT(4);  // lfo_impl::chain60_t<NV>
		auto& event_data_reader8 = this->getT(0).getT(0).getT(2).getT(0).               // lfo_impl::event_data_reader8_t<NV>
                                   getT(0).getT(1).getT(4).getT(0);
		auto& add23 = this->getT(0).getT(0).getT(2).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(4).getT(1);
		auto& gain32 = this->getT(0).getT(0).getT(2).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(4).getT(2);
		auto& chain61 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(1).getT(5);  // lfo_impl::chain61_t<NV>
		auto& event_data_reader9 = this->getT(0).getT(0).getT(2).getT(0).               // lfo_impl::event_data_reader9_t<NV>
                                   getT(0).getT(1).getT(5).getT(0);
		auto& add24 = this->getT(0).getT(0).getT(2).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(5).getT(1);
		auto& gain41 = this->getT(0).getT(0).getT(2).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(5).getT(2);
		auto& peak6 = this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(2);            // lfo_impl::peak6_t<NV>
		auto& pma2 = this->getT(0).getT(0).getT(2).getT(1);                             // control::pma<NV, parameter::empty>
		auto& modchain3 = this->getT(0).getT(0).getT(3);                                // lfo_impl::modchain3_t<NV>
		auto& split13 = this->getT(0).getT(0).getT(3).getT(0);                          // lfo_impl::split13_t<NV>
		auto& chain75 = this->getT(0).getT(0).getT(3).getT(0).getT(0);                  // lfo_impl::chain75_t<NV>
		auto& xfader3 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(0);          // lfo_impl::xfader3_t<NV>
		auto& split14 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(1);          // lfo_impl::split14_t<NV>
		auto& chain76 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(1).getT(0);  // lfo_impl::chain76_t<NV>
		auto& global_cable19 = this->getT(0).getT(0).getT(3).getT(0).                   // lfo_impl::global_cable19_t<NV>
                               getT(0).getT(1).getT(0).getT(0);
		auto& add31 = this->getT(0).getT(0).getT(3).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(0).getT(1);
		auto& gain58 = this->getT(0).getT(0).getT(3).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(0).getT(2);
		auto& chain77 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(1).getT(1);  // lfo_impl::chain77_t<NV>
		auto& global_cable20 = this->getT(0).getT(0).getT(3).getT(0).                   // lfo_impl::global_cable20_t<NV>
                               getT(0).getT(1).getT(1).getT(0);
		auto& add32 = this->getT(0).getT(0).getT(3).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(1).getT(1);
		auto& gain59 = this->getT(0).getT(0).getT(3).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(1).getT(2);
		auto& chain78 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(1).getT(2);  // lfo_impl::chain78_t<NV>
		auto& global_cable24 = this->getT(0).getT(0).getT(3).getT(0).                   // lfo_impl::global_cable24_t<NV>
                               getT(0).getT(1).getT(2).getT(0);
		auto& add33 = this->getT(0).getT(0).getT(3).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(2).getT(1);
		auto& gain60 = this->getT(0).getT(0).getT(3).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(2).getT(2);
		auto& chain79 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(1).getT(3);  // lfo_impl::chain79_t<NV>
		auto& event_data_reader13 = this->getT(0).getT(0).getT(3).getT(0).              // lfo_impl::event_data_reader13_t<NV>
                                    getT(0).getT(1).getT(3).getT(0);
		auto& add34 = this->getT(0).getT(0).getT(3).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(3).getT(1);
		auto& gain61 = this->getT(0).getT(0).getT(3).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(3).getT(2);
		auto& chain80 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(1).getT(4);  // lfo_impl::chain80_t<NV>
		auto& event_data_reader14 = this->getT(0).getT(0).getT(3).getT(0).              // lfo_impl::event_data_reader14_t<NV>
                                    getT(0).getT(1).getT(4).getT(0);
		auto& add35 = this->getT(0).getT(0).getT(3).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(4).getT(1);
		auto& gain62 = this->getT(0).getT(0).getT(3).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(4).getT(2);
		auto& chain81 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(1).getT(5);  // lfo_impl::chain81_t<NV>
		auto& event_data_reader15 = this->getT(0).getT(0).getT(3).getT(0).              // lfo_impl::event_data_reader15_t<NV>
                                    getT(0).getT(1).getT(5).getT(0);
		auto& add36 = this->getT(0).getT(0).getT(3).getT(0).                            // math::add<NV>
                      getT(0).getT(1).getT(5).getT(1);
		auto& gain63 = this->getT(0).getT(0).getT(3).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(5).getT(2);
		auto& chain82 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(1).getT(6);  // lfo_impl::chain82_t<NV>
		auto& midi = this->getT(0).getT(0).getT(3).getT(0).                             // lfo_impl::midi_t<NV>
                     getT(0).getT(1).getT(6).getT(0);
		auto& add3 = this->getT(0).getT(0).getT(3).getT(0).                             // math::add<NV>
                     getT(0).getT(1).getT(6).getT(1);
		auto& gain64 = this->getT(0).getT(0).getT(3).getT(0).                           // core::gain<NV>
                       getT(0).getT(1).getT(6).getT(2);
		auto& peak10 = this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(2);           // lfo_impl::peak10_t<NV>
		auto& cable_table1 = this->getT(0).getT(0).getT(3).getT(1);                     // lfo_impl::cable_table1_t<NV>
		auto& pma5 = this->getT(0).getT(0).getT(3).getT(2);                             // lfo_impl::pma5_t<NV>
		auto& modchain4 = this->getT(1);                                                // lfo_impl::modchain4_t<NV>
		auto& branch1 = this->getT(1).getT(0);                                          // lfo_impl::branch1_t<NV>
		auto& chain3 = this->getT(1).getT(0).getT(0);                                   // lfo_impl::chain3_t<NV>
		auto& tempo_sync = this->getT(1).getT(0).getT(0).getT(0);                       // lfo_impl::tempo_sync_t<NV>
		auto& ramp = this->getT(1).getT(0).getT(0).getT(1);                             // lfo_impl::ramp_t<NV>
		auto& clock_ramp = this->getT(1).getT(0).getT(1);                               // lfo_impl::clock_ramp_t<NV>
		auto& peak3 = this->getT(1).getT(1);                                            // lfo_impl::peak3_t
		auto& chain11 = this->getT(1).getT(2);                                          // lfo_impl::chain11_t<NV>
		auto& branch2 = this->getT(1).getT(2).getT(0);                                  // lfo_impl::branch2_t<NV>
		auto& chain25 = this->getT(1).getT(2).getT(0).getT(0);                          // lfo_impl::chain25_t<NV>
		auto& pi2 = this->getT(1).getT(2).getT(0).getT(0).getT(0);                      // math::pi<NV>
		auto& sin3 = this->getT(1).getT(2).getT(0).getT(0).getT(1);                     // math::sin<NV>
		auto& sig2mod4 = this->getT(1).getT(2).getT(0).getT(0).getT(2);                 // wrap::no_process<math::sig2mod<NV>>
		auto& chain24 = this->getT(1).getT(2).getT(0).getT(1);                          // lfo_impl::chain24_t<NV>
		auto& mul2 = this->getT(1).getT(2).getT(0).getT(1).getT(0);                     // wrap::no_process<math::mul<NV>>
		auto& sig2mod3 = this->getT(1).getT(2).getT(0).getT(1).getT(1);                 // wrap::no_process<math::sig2mod<NV>>
		auto& chain14 = this->getT(1).getT(2).getT(0).getT(2);                          // lfo_impl::chain14_t<NV>
		auto& add6 = this->getT(1).getT(2).getT(0).getT(2).getT(0);                     // math::add<NV>
		auto& fmod3 = this->getT(1).getT(2).getT(0).getT(2).getT(1);                    // math::fmod<NV>
		auto& sub = this->getT(1).getT(2).getT(0).getT(2).getT(2);                      // math::sub<NV>
		auto& abs = this->getT(1).getT(2).getT(0).getT(2).getT(3);                      // math::abs<NV>
		auto& mul1 = this->getT(1).getT(2).getT(0).getT(2).getT(4);                     // math::mul<NV>
		auto& chain18 = this->getT(1).getT(2).getT(0).getT(3);                          // lfo_impl::chain18_t<NV>
		auto& mod_inv1 = this->getT(1).getT(2).getT(0).getT(3).getT(0);                 // math::mod_inv<NV>
		auto& rect3 = this->getT(1).getT(2).getT(0).getT(3).getT(1);                    // math::rect<NV>
		auto& chain31 = this->getT(1).getT(2).getT(0).getT(4);                          // lfo_impl::chain31_t<NV>
		auto& oscillator = this->getT(1).getT(2).getT(0).getT(4).getT(0);               // lfo_impl::oscillator_t<NV>
		auto& sig2mod1 = this->getT(1).getT(2).getT(0).getT(4).getT(1);                 // math::sig2mod<NV>
		auto& chain32 = this->getT(1).getT(2).getT(0).getT(5);                          // lfo_impl::chain32_t<NV>
		auto& clear1 = this->getT(1).getT(2).getT(0).getT(5).getT(0);                   // wrap::no_process<math::clear<NV>>
		auto& input_toggle = this->getT(1).getT(2).getT(0).getT(5).getT(1);             // lfo_impl::input_toggle_t<NV>
		auto& cable_table = this->getT(1).getT(2).getT(0).getT(5).getT(2);              // lfo_impl::cable_table_t<NV>
		auto& add8 = this->getT(1).getT(2).getT(0).getT(5).getT(3);                     // math::add<NV>
		auto& chain33 = this->getT(1).getT(2).getT(0).getT(6);                          // lfo_impl::chain33_t<NV>
		auto& clear2 = this->getT(1).getT(2).getT(0).getT(6).getT(0);                   // math::clear<NV>
		auto& input_toggle1 = this->getT(1).getT(2).getT(0).getT(6).getT(1);            // lfo_impl::input_toggle1_t<NV>
		auto& cable_pack = this->getT(1).getT(2).getT(0).getT(6).getT(2);               // lfo_impl::cable_pack_t<NV>
		auto& add9 = this->getT(1).getT(2).getT(0).getT(6).getT(3);                     // math::add<NV>
		auto& peak9 = this->getT(1).getT(2).getT(1);                                    // lfo_impl::peak9_t
		auto& branch4 = this->getT(1).getT(2).getT(2);                                  // lfo_impl::branch4_t<NV>
		auto& chain73 = this->getT(1).getT(2).getT(2).getT(0);                          // lfo_impl::chain73_t<NV>
		auto& pma4 = this->getT(1).getT(2).getT(2).getT(0).getT(0);                     // lfo_impl::pma4_t<NV>
		auto& gain57 = this->getT(1).getT(2).getT(2).getT(0).getT(1);                   // core::gain<NV>
		auto& chain74 = this->getT(1).getT(2).getT(2).getT(1);                          // lfo_impl::chain74_t<NV>
		auto& smoother1 = this->getT(1).getT(2).getT(2).getT(1).getT(0);                // core::smoother<NV>
		auto& sig2mod5 = this->getT(1).getT(2).getT(2).getT(1).getT(1);                 // wrap::no_process<math::sig2mod<NV>>
		auto& sin13 = this->getT(1).getT(2).getT(2).getT(1).getT(2);                    // wrap::no_process<math::sin<NV>>
		auto& chain22 = this->getT(1).getT(2).getT(2).getT(2);                          // lfo_impl::chain22_t<NV>
		auto& branch6 = this->getT(1).getT(2).getT(2).getT(2).getT(0);                  // lfo_impl::branch6_t<NV>
		auto& sampleandhold = this->getT(1).getT(2).getT(2).getT(2).getT(0).getT(0);    // fx::sampleandhold<NV>
		auto& sampleandhold2 = this->getT(1).getT(2).getT(2).getT(2).getT(0).getT(1);   // fx::sampleandhold<NV>
		auto& smoother = this->getT(1).getT(2).getT(2).getT(2).getT(1);                 // core::smoother<NV>
		auto& sig2mod2 = this->getT(1).getT(2).getT(2).getT(2).getT(2);                 // wrap::no_process<math::sig2mod<NV>>
		auto& sin4 = this->getT(1).getT(2).getT(2).getT(2).getT(3);                     // wrap::no_process<math::sin<NV>>
		auto& chain26 = this->getT(1).getT(2).getT(2).getT(3);                          // lfo_impl::chain26_t<NV>
		auto& gain37 = this->getT(1).getT(2).getT(2).getT(3).getT(0);                   // core::gain<NV>
		auto& pi5 = this->getT(1).getT(2).getT(2).getT(3).getT(1);                      // math::pi<NV>
		auto& fmod2 = this->getT(1).getT(2).getT(2).getT(3).getT(2);                    // math::fmod<NV>
		auto& chain65 = this->getT(1).getT(2).getT(2).getT(4);                          // lfo_impl::chain65_t<NV>
		auto& expr4 = this->getT(1).getT(2).getT(2).getT(4).getT(0);                    // math::expr<NV, custom::expr4>
		auto& chain27 = this->getT(1).getT(2).getT(2).getT(5);                          // lfo_impl::chain27_t<NV>
		auto& sin = this->getT(1).getT(2).getT(2).getT(5).getT(0);                      // wrap::no_process<math::sin<NV>>
		auto& expr1 = this->getT(1).getT(2).getT(2).getT(5).getT(1);                    // math::expr<NV, custom::expr1>
		auto& chain56 = this->getT(1).getT(2).getT(2).getT(6);                          // lfo_impl::chain56_t<NV>
		auto& expr2 = this->getT(1).getT(2).getT(2).getT(6).getT(0);                    // math::expr<NV, custom::expr2>
		auto& split1 = this->getT(1).getT(2).getT(3);                                   // lfo_impl::split1_t
		auto& branch3 = this->getT(1).getT(3);                                          // lfo_impl::branch3_t<NV>
		auto& chain34 = this->getT(1).getT(3).getT(0);                                  // lfo_impl::chain34_t
		auto& chain35 = this->getT(1).getT(3).getT(1);                                  // lfo_impl::chain35_t<NV>
		auto& simple_ar1 = this->getT(1).getT(3).getT(1).getT(0);                       // lfo_impl::simple_ar1_t<NV>
		auto& gain51 = this->getT(1).getT(3).getT(1).getT(1);                           // core::gain<NV>
		auto& peak7 = this->getT(1).getT(4);                                            // lfo_impl::peak7_t<NV>
		auto& sig2mod = this->getT(1).getT(5);                                          // wrap::no_process<math::sig2mod<NV>>
		auto& branch = this->getT(1).getT(6);                                           // lfo_impl::branch_t<NV>
		auto& chain = this->getT(1).getT(6).getT(0);                                    // lfo_impl::chain_t<NV>
		auto& split = this->getT(1).getT(6).getT(0).getT(0);                            // lfo_impl::split_t<NV>
		auto& chain4 = this->getT(1).getT(6).getT(0).getT(0).getT(0);                   // lfo_impl::chain4_t
		auto& global_cable = this->getT(1).getT(6).getT(0).getT(0).getT(0).getT(0);     // routing::global_cable<global_cable_t_index, parameter::empty>
		auto& chain5 = this->getT(1).getT(6).getT(0).getT(0).getT(1);                   // lfo_impl::chain5_t<NV>
		auto& clear = this->getT(1).getT(6).getT(0).getT(0).getT(1).getT(0);            // math::clear<NV>
		auto& add = this->getT(1).getT(6).getT(0).getT(0).getT(1).getT(1);              // math::add<NV>
		auto& rect = this->getT(1).getT(6).getT(0).getT(0).getT(1).getT(2);             // math::rect<NV>
		auto& peak = this->getT(1).getT(6).getT(0).getT(0).getT(1).getT(3);             // lfo_impl::peak_t<NV>
		auto& change = this->getT(1).getT(6).getT(0).getT(0).getT(1).getT(4);           // lfo_impl::change_t<NV>
		auto& global_cable2 = this->getT(1).getT(6).getT(0).getT(0).getT(1).getT(5);    // routing::global_cable<global_cable2_t_index, parameter::empty>
		auto& chain112 = this->getT(1).getT(6).getT(0).getT(0).getT(2);                 // lfo_impl::chain112_t<NV>
		auto& clear3 = this->getT(1).getT(6).getT(0).getT(0).getT(2).getT(0);           // math::clear<NV>
		auto& add43 = this->getT(1).getT(6).getT(0).getT(0).getT(2).getT(1);            // math::add<NV>
		auto& peak14 = this->getT(1).getT(6).getT(0).getT(0).getT(2).getT(2);           // lfo_impl::peak14_t<NV>
		auto& change3 = this->getT(1).getT(6).getT(0).getT(0).getT(2).getT(3);          // lfo_impl::change3_t<NV>
		auto& chain169 = this->getT(1).getT(6).getT(0).getT(0).getT(2).getT(4);         // lfo_impl::chain169_t<NV>
		auto& minmax2 = this->getT(1).getT(6).getT(0).getT(0).getT(2).getT(4).getT(0);  // lfo_impl::minmax2_t<NV>
		auto& chain170 = this->getT(1).getT(6).getT(0).getT(0).getT(2).getT(4).getT(1); // lfo_impl::chain170_t
		auto& global_cable21 = this->getT(1).getT(6).getT(0).getT(0).                   // routing::global_cable<global_cable21_t_index, parameter::empty>
                               getT(2).getT(4).getT(1).getT(0);
		auto& chain1 = this->getT(1).getT(6).getT(1);                                   // lfo_impl::chain1_t<NV>
		auto& split2 = this->getT(1).getT(6).getT(1).getT(0);                           // lfo_impl::split2_t<NV>
		auto& chain6 = this->getT(1).getT(6).getT(1).getT(0).getT(0);                   // lfo_impl::chain6_t
		auto& global_cable4 = this->getT(1).getT(6).getT(1).getT(0).getT(0).getT(0);    // routing::global_cable<global_cable4_t_index, parameter::empty>
		auto& chain7 = this->getT(1).getT(6).getT(1).getT(0).getT(1);                   // lfo_impl::chain7_t<NV>
		auto& clear4 = this->getT(1).getT(6).getT(1).getT(0).getT(1).getT(0);           // math::clear<NV>
		auto& add1 = this->getT(1).getT(6).getT(1).getT(0).getT(1).getT(1);             // math::add<NV>
		auto& rect1 = this->getT(1).getT(6).getT(1).getT(0).getT(1).getT(2);            // math::rect<NV>
		auto& peak1 = this->getT(1).getT(6).getT(1).getT(0).getT(1).getT(3);            // lfo_impl::peak1_t<NV>
		auto& change1 = this->getT(1).getT(6).getT(1).getT(0).getT(1).getT(4);          // lfo_impl::change1_t<NV>
		auto& global_cable5 = this->getT(1).getT(6).getT(1).getT(0).getT(1).getT(5);    // routing::global_cable<global_cable5_t_index, parameter::empty>
		auto& chain113 = this->getT(1).getT(6).getT(1).getT(0).getT(2);                 // lfo_impl::chain113_t<NV>
		auto& clear5 = this->getT(1).getT(6).getT(1).getT(0).getT(2).getT(0);           // math::clear<NV>
		auto& add44 = this->getT(1).getT(6).getT(1).getT(0).getT(2).getT(1);            // math::add<NV>
		auto& peak15 = this->getT(1).getT(6).getT(1).getT(0).getT(2).getT(2);           // lfo_impl::peak15_t<NV>
		auto& change4 = this->getT(1).getT(6).getT(1).getT(0).getT(2).getT(3);          // lfo_impl::change4_t<NV>
		auto& chain171 = this->getT(1).getT(6).getT(1).getT(0).getT(2).getT(4);         // lfo_impl::chain171_t<NV>
		auto& minmax5 = this->getT(1).getT(6).getT(1).getT(0).getT(2).getT(4).getT(0);  // lfo_impl::minmax5_t<NV>
		auto& chain172 = this->getT(1).getT(6).getT(1).getT(0).getT(2).getT(4).getT(1); // lfo_impl::chain172_t
		auto& global_cable22 = this->getT(1).getT(6).getT(1).getT(0).                   // routing::global_cable<global_cable22_t_index, parameter::empty>
                               getT(2).getT(4).getT(1).getT(0);
		auto& chain2 = this->getT(1).getT(6).getT(2);                                   // lfo_impl::chain2_t<NV>
		auto& split3 = this->getT(1).getT(6).getT(2).getT(0);                           // lfo_impl::split3_t<NV>
		auto& chain8 = this->getT(1).getT(6).getT(2).getT(0).getT(0);                   // lfo_impl::chain8_t
		auto& global_cable6 = this->getT(1).getT(6).getT(2).getT(0).getT(0).getT(0);    // routing::global_cable<global_cable6_t_index, parameter::empty>
		auto& chain9 = this->getT(1).getT(6).getT(2).getT(0).getT(1);                   // lfo_impl::chain9_t<NV>
		auto& clear6 = this->getT(1).getT(6).getT(2).getT(0).getT(1).getT(0);           // math::clear<NV>
		auto& add2 = this->getT(1).getT(6).getT(2).getT(0).getT(1).getT(1);             // math::add<NV>
		auto& rect2 = this->getT(1).getT(6).getT(2).getT(0).getT(1).getT(2);            // math::rect<NV>
		auto& peak2 = this->getT(1).getT(6).getT(2).getT(0).getT(1).getT(3);            // lfo_impl::peak2_t<NV>
		auto& change2 = this->getT(1).getT(6).getT(2).getT(0).getT(1).getT(4);          // lfo_impl::change2_t<NV>
		auto& global_cable7 = this->getT(1).getT(6).getT(2).getT(0).getT(1).getT(5);    // routing::global_cable<global_cable7_t_index, parameter::empty>
		auto& chain114 = this->getT(1).getT(6).getT(2).getT(0).getT(2);                 // lfo_impl::chain114_t<NV>
		auto& clear7 = this->getT(1).getT(6).getT(2).getT(0).getT(2).getT(0);           // math::clear<NV>
		auto& add45 = this->getT(1).getT(6).getT(2).getT(0).getT(2).getT(1);            // math::add<NV>
		auto& peak16 = this->getT(1).getT(6).getT(2).getT(0).getT(2).getT(2);           // lfo_impl::peak16_t<NV>
		auto& change5 = this->getT(1).getT(6).getT(2).getT(0).getT(2).getT(3);          // lfo_impl::change5_t<NV>
		auto& chain173 = this->getT(1).getT(6).getT(2).getT(0).getT(2).getT(4);         // lfo_impl::chain173_t<NV>
		auto& minmax6 = this->getT(1).getT(6).getT(2).getT(0).getT(2).getT(4).getT(0);  // lfo_impl::minmax6_t<NV>
		auto& chain174 = this->getT(1).getT(6).getT(2).getT(0).getT(2).getT(4).getT(1); // lfo_impl::chain174_t
		auto& global_cable23 = this->getT(1).getT(6).getT(2).getT(0).                   // routing::global_cable<global_cable23_t_index, parameter::empty>
                               getT(2).getT(4).getT(1).getT(0);
		
		// Parameter Connections -------------------------------------------------------------------
		
		chain170.getParameterT(0).connectT(0, global_cable21); // note -> global_cable21::Value
		chain170.getParameterT(0).connectT(0, global_cable21); // note -> global_cable21::Value
		chain172.getParameterT(0).connectT(0, global_cable22); // note -> global_cable22::Value
		chain172.getParameterT(0).connectT(0, global_cable22); // note -> global_cable22::Value
		chain174.getParameterT(0).connectT(0, global_cable23); // note -> global_cable23::Value
		chain174.getParameterT(0).connectT(0, global_cable23); // note -> global_cable23::Value
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
		
		this->getParameterT(5).connectT(0, branch3); // Gate -> branch3::Index
		
		this->getParameterT(6).connectT(0, pma3); // Adjust -> pma3::Add
		
		this->getParameterT(7).connectT(0, branch2); // Shape -> branch2::Index
		
		auto& Min_p = this->getParameterT(8);
		Min_p.connectT(0, minmax2); // Min -> minmax2::Minimum
		Min_p.connectT(1, minmax6); // Min -> minmax6::Minimum
		Min_p.connectT(2, minmax5); // Min -> minmax5::Minimum
		
		auto& Max_p = this->getParameterT(9);
		Max_p.connectT(0, minmax6); // Max -> minmax6::Maximum
		Max_p.connectT(1, minmax5); // Max -> minmax5::Maximum
		Max_p.connectT(2, minmax2); // Max -> minmax2::Maximum
		
		auto& Step_p = this->getParameterT(10);
		Step_p.connectT(0, minmax2); // Step -> minmax2::Step
		Step_p.connectT(1, minmax6); // Step -> minmax6::Step
		Step_p.connectT(2, minmax5); // Step -> minmax5::Step
		
		this->getParameterT(11).connectT(0, pma1); // TempoMod -> pma1::Multiply
		
		this->getParameterT(12).connectT(0, pma3); // AdjMod -> pma3::Multiply
		
		auto& GateMod_p = this->getParameterT(13);
		GateMod_p.connectT(0, cable_table1); // GateMod -> cable_table1::Value
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
		event_data_reader4.getParameter().connectT(0, add16);                    // event_data_reader4 -> add16::Value
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
		event_data_reader10.getParameter().connectT(0, add28);               // event_data_reader10 -> add28::Value
		event_data_reader11.getParameter().connectT(0, add29);               // event_data_reader11 -> add29::Value
		event_data_reader12.getParameter().connectT(0, add30);               // event_data_reader12 -> add30::Value
		pma4.getWrappedObject().getParameter().connectT(0, gain57);          // pma4 -> gain57::Gain
		pma3.getWrappedObject().getParameter().connectT(0, pma4);            // pma3 -> pma4::Add
		pma3.getWrappedObject().getParameter().connectT(1, gain37);          // pma3 -> gain37::Gain
		pma3.getWrappedObject().getParameter().connectT(2, expr4);           // pma3 -> expr4::Value
		pma3.getWrappedObject().getParameter().connectT(3, expr1);           // pma3 -> expr1::Value
		pma3.getWrappedObject().getParameter().connectT(4, expr2);           // pma3 -> expr2::Value
		pma3.getWrappedObject().getParameter().connectT(5, smoother);        // pma3 -> smoother::SmoothingTime
		pma3.getWrappedObject().getParameter().connectT(6, smoother1);       // pma3 -> smoother1::SmoothingTime
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
		event_data_reader7.getParameter().connectT(0, add22);                // event_data_reader7 -> add22::Value
		event_data_reader8.getParameter().connectT(0, add23);                // event_data_reader8 -> add23::Value
		event_data_reader9.getParameter().connectT(0, add24);                // event_data_reader9 -> add24::Value
		peak6.getParameter().connectT(0, pma2);                              // peak6 -> pma2::Value
		auto& xfader3_p = xfader3.getWrappedObject().getParameter();
		xfader3_p.getParameterT(0).connectT(0, gain58);                      // xfader3 -> gain58::Gain
		xfader3_p.getParameterT(1).connectT(0, gain59);                      // xfader3 -> gain59::Gain
		xfader3_p.getParameterT(2).connectT(0, gain60);                      // xfader3 -> gain60::Gain
		xfader3_p.getParameterT(3).connectT(0, gain61);                      // xfader3 -> gain61::Gain
		xfader3_p.getParameterT(4).connectT(0, gain62);                      // xfader3 -> gain62::Gain
		xfader3_p.getParameterT(5).connectT(0, gain63);                      // xfader3 -> gain63::Gain
		xfader3_p.getParameterT(6).connectT(0, gain64);                      // xfader3 -> gain64::Gain
		global_cable19.getWrappedObject().getParameter().connectT(0, add31); // global_cable19 -> add31::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add32); // global_cable20 -> add32::Value
		global_cable24.getWrappedObject().getParameter().connectT(0, add33); // global_cable24 -> add33::Value
		event_data_reader13.getParameter().connectT(0, add34);               // event_data_reader13 -> add34::Value
		event_data_reader14.getParameter().connectT(0, add35);               // event_data_reader14 -> add35::Value
		event_data_reader15.getParameter().connectT(0, add36);               // event_data_reader15 -> add36::Value
		midi.getParameter().connectT(0, add3);                               // midi -> add3::Value
		pma5.getWrappedObject().getParameter().connectT(0, ramp);            // pma5 -> ramp::Gate
		peak10.getParameter().connectT(0, pma5);                             // peak10 -> pma5::Value
		cable_table1.getWrappedObject().getParameter().connectT(0, pma5);    // cable_table1 -> pma5::Add
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
		
		event_data_reader4.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader4.setParameterT(1, 0.); // routing::event_data_reader::Static
		
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
		
		event_data_reader10.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader10.setParameterT(1, 0.); // routing::event_data_reader::Static
		
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
		
		event_data_reader7.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader7.setParameterT(1, 0.); // routing::event_data_reader::Static
		
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
		
		event_data_reader13.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader13.setParameterT(1, 0.); // routing::event_data_reader::Static
		
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
		
		; // cable_table1::Value is automated
		
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
		clock_ramp.setParameterT(2, 0.); // core::clock_ramp::AddToSignal
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
		
		;                              // smoother::SmoothingTime is automated
		smoother.setParameterT(1, 0.); // core::smoother::DefaultValue
		
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
		
		this->setParameterT(0, 0.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.824219);
		this->setParameterT(7, 7.);
		this->setParameterT(8, 37.);
		this->setParameterT(9, 77.5231);
		this->setParameterT(10, 3.03974);
		this->setParameterT(11, 0.102781);
		this->setParameterT(12, 0.);
		this->setParameterT(13, 0.);
		this->setParameterT(14, 0.);
		this->setParameterT(15, 1.);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 1.);
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
	
	static constexpr bool hasTail() { return false; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void connectToRuntimeTarget(bool addConnection, const runtime_target::connection& c)
	{
		// Runtime target Connections --------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).                                                          // lfo_impl::global_cable9_t<NV>
        getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).                                                          // lfo_impl::global_cable11_t<NV>
        getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(0).getT(0).                                                          // lfo_impl::global_cable10_t<NV>
        getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(0).                                                          // lfo_impl::global_cable16_t<NV>
        getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(0).                                                          // lfo_impl::global_cable17_t<NV>
        getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(1).getT(0).                                                          // lfo_impl::global_cable18_t<NV>
        getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(0).                                                          // lfo_impl::global_cable13_t<NV>
        getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(0).                                                          // lfo_impl::global_cable14_t<NV>
        getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(2).getT(0).                                                          // lfo_impl::global_cable15_t<NV>
        getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).                                                          // lfo_impl::global_cable19_t<NV>
        getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).                                                          // lfo_impl::global_cable20_t<NV>
        getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(0).getT(0).getT(3).getT(0).                                                          // lfo_impl::global_cable24_t<NV>
        getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(6).getT(0).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable_t_index, parameter::empty>
		this->getT(1).getT(6).getT(0).getT(0).getT(1).getT(5).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable2_t_index, parameter::empty>
		this->getT(1).getT(6).getT(0).getT(0).                                                          // routing::global_cable<global_cable21_t_index, parameter::empty>
        getT(2).getT(4).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(6).getT(1).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable4_t_index, parameter::empty>
		this->getT(1).getT(6).getT(1).getT(0).getT(1).getT(5).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable5_t_index, parameter::empty>
		this->getT(1).getT(6).getT(1).getT(0).                                                          // routing::global_cable<global_cable22_t_index, parameter::empty>
        getT(2).getT(4).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
		this->getT(1).getT(6).getT(2).getT(0).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable6_t_index, parameter::empty>
		this->getT(1).getT(6).getT(2).getT(0).getT(1).getT(5).connectToRuntimeTarget(addConnection, c); // routing::global_cable<global_cable7_t_index, parameter::empty>
		this->getT(1).getT(6).getT(2).getT(0).                                                          // routing::global_cable<global_cable23_t_index, parameter::empty>
        getT(2).getT(4).getT(1).getT(0).connectToRuntimeTarget(addConnection, c);
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index); // lfo_impl::peak5_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).getT(0).getT(2).setExternalData(b, index); // lfo_impl::peak8_t<NV>
		this->getT(0).getT(0).getT(2).getT(0).getT(0).getT(2).setExternalData(b, index); // lfo_impl::peak6_t<NV>
		this->getT(0).getT(0).getT(3).getT(0).getT(0).getT(2).setExternalData(b, index); // lfo_impl::peak10_t<NV>
		this->getT(0).getT(0).getT(3).getT(1).setExternalData(b, index);                 // lfo_impl::cable_table1_t<NV>
		this->getT(1).getT(0).getT(0).getT(1).setExternalData(b, index);                 // lfo_impl::ramp_t<NV>
		this->getT(1).getT(0).getT(1).setExternalData(b, index);                         // lfo_impl::clock_ramp_t<NV>
		this->getT(1).getT(1).setExternalData(b, index);                                 // lfo_impl::peak3_t
		this->getT(1).getT(2).getT(0).getT(4).getT(0).setExternalData(b, index);         // lfo_impl::oscillator_t<NV>
		this->getT(1).getT(2).getT(0).getT(5).getT(2).setExternalData(b, index);         // lfo_impl::cable_table_t<NV>
		this->getT(1).getT(2).getT(0).getT(6).getT(2).setExternalData(b, index);         // lfo_impl::cable_pack_t<NV>
		this->getT(1).getT(2).getT(1).setExternalData(b, index);                         // lfo_impl::peak9_t
		this->getT(1).getT(3).getT(1).getT(0).setExternalData(b, index);                 // lfo_impl::simple_ar1_t<NV>
		this->getT(1).getT(4).setExternalData(b, index);                                 // lfo_impl::peak7_t<NV>
		this->getT(1).getT(6).getT(0).getT(0).getT(1).getT(3).setExternalData(b, index); // lfo_impl::peak_t<NV>
		this->getT(1).getT(6).getT(0).getT(0).getT(2).getT(2).setExternalData(b, index); // lfo_impl::peak14_t<NV>
		this->getT(1).getT(6).getT(1).getT(0).getT(1).getT(3).setExternalData(b, index); // lfo_impl::peak1_t<NV>
		this->getT(1).getT(6).getT(1).getT(0).getT(2).getT(2).setExternalData(b, index); // lfo_impl::peak15_t<NV>
		this->getT(1).getT(6).getT(2).getT(0).getT(1).getT(3).setExternalData(b, index); // lfo_impl::peak2_t<NV>
		this->getT(1).getT(6).getT(2).getT(0).getT(2).getT(2).setExternalData(b, index); // lfo_impl::peak16_t<NV>
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


