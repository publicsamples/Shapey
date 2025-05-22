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

namespace TransFX_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(sliderbank4_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using sliderbank4_c0 = parameter::from0To1<core::gain<NV>, 
                                           0, 
                                           sliderbank4_c0Range>;

template <int NV> using sliderbank4_c1 = sliderbank4_c0<NV>;

template <int NV> using sliderbank4_c2 = sliderbank4_c0<NV>;

template <int NV> using sliderbank4_c3 = sliderbank4_c0<NV>;

template <int NV> using sliderbank4_c4 = sliderbank4_c0<NV>;

template <int NV> using sliderbank4_c5 = sliderbank4_c0<NV>;

template <int NV> using sliderbank4_c6 = sliderbank4_c0<NV>;

template <int NV> using sliderbank4_c7 = sliderbank4_c0<NV>;

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
                                 data::external::sliderpack<0>>;
using global_cable13_t_index = runtime_target::indexers::fix_hash<2333884>;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable14_t_index = runtime_target::indexers::fix_hash<2333885>;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain56_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable15_t_index = runtime_target::indexers::fix_hash<2333886>;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using event_data_reader13_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                        routing::event_data_reader<NV>>;

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader13_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader14_t = event_data_reader13_t<NV>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader14_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader15_t = event_data_reader13_t<NV>;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader15_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
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
using midi7_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi7_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi8_t = midi7_t<NV>;

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
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch5_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain55_t<NV>>, 
                                  chain56_t<NV>, 
                                  chain57_t<NV>, 
                                  chain58_t<NV>, 
                                  chain59_t<NV>, 
                                  chain60_t<NV>, 
                                  chain61_t<NV>, 
                                  chain62_t<NV>>;

template <int NV> using xfader1_c0 = sliderbank4_c0<NV>;

template <int NV> using xfader1_c1 = sliderbank4_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, xfader1_c1<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::rms>;
template <int NV>
using pma6_t = control::pma<NV, 
                            parameter::plain<xfader1_t<NV>, 0>>;
template <int NV>
using peak4_t = wrap::mod<parameter::plain<pma6_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank4_t<NV>>, 
                                   split7_t<NV>, 
                                   peak4_t<NV>, 
                                   pma6_t<NV>>;

template <int NV> using sliderbank3_c0 = sliderbank4_c0<NV>;

template <int NV> using sliderbank3_c1 = sliderbank4_c0<NV>;

template <int NV> using sliderbank3_c2 = sliderbank4_c0<NV>;

template <int NV> using sliderbank3_c3 = sliderbank4_c0<NV>;

template <int NV> using sliderbank3_c4 = sliderbank4_c0<NV>;

template <int NV> using sliderbank3_c5 = sliderbank4_c0<NV>;

template <int NV> using sliderbank3_c6 = sliderbank4_c0<NV>;

template <int NV> using sliderbank3_c7 = sliderbank4_c0<NV>;

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
using global_cable10_t_index = global_cable13_t_index;

template <int NV>
using global_cable10_t = routing::global_cable<global_cable10_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable10_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable11_t_index = global_cable14_t_index;

template <int NV>
using global_cable11_t = routing::global_cable<global_cable11_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable11_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable12_t_index = global_cable15_t_index;

template <int NV>
using global_cable12_t = routing::global_cable<global_cable12_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable12_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader10_t = event_data_reader13_t<NV>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader10_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader11_t = event_data_reader13_t<NV>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader11_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader12_t = event_data_reader13_t<NV>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader12_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader20_t = event_data_reader13_t<NV>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader20_t<NV>>, 
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

template <int NV> using midi11_t = midi7_t<NV>;

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
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch6_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain46_t<NV>>, 
                                  chain47_t<NV>, 
                                  chain48_t<NV>, 
                                  chain49_t<NV>, 
                                  chain50_t<NV>, 
                                  chain51_t<NV>, 
                                  chain52_t<NV>, 
                                  chain53_t<NV>>;

namespace custom
{

struct expr3
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 12.0 * value * input) * (2 - Math.PI);;
	}
};
}

namespace custom
{

struct expr2
{
	static float op(float input, float value)
	{
		return input * Math.cos(Math.PI * 12.0 * value * input) * (8 - Math.PI);;
	}
};
}

template <int NV>
using converter_t = control::converter<parameter::plain<fx::sampleandhold<NV>, 0>, 
                                       conversion_logic::ms2samples>;
template <int NV>
using tempo_sync_t = wrap::mod<parameter::plain<converter_t<NV>, 0>, 
                               control::tempo_sync<NV>>;
DECLARE_PARAMETER_RANGE_STEP(cable_table_modRange, 
                             1., 
                             16., 
                             1.);

template <int NV>
using cable_table_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                            1, 
                                            cable_table_modRange>;

struct cable_table_t_data
{
	span<float, 512> data =
	{
		1.f, 0.996086f, 0.992172f, 0.988258f, 0.984344f, 0.980431f,
		0.976517f, 0.972603f, 0.968689f, 0.964775f, 0.960861f, 0.956947f,
		0.953033f, 0.949119f, 0.945205f, 0.941292f, 0.937378f, 0.933464f,
		0.92955f, 0.925636f, 0.921722f, 0.917808f, 0.913894f, 0.90998f,
		0.906067f, 0.902153f, 0.898239f, 0.894325f, 0.890411f, 0.886497f,
		0.882583f, 0.878669f, 0.874755f, 0.870842f, 0.866928f, 0.863014f,
		0.8591f, 0.855186f, 0.851272f, 0.847358f, 0.843444f, 0.83953f,
		0.835616f, 0.831703f, 0.827789f, 0.823875f, 0.819961f, 0.816047f,
		0.812133f, 0.808219f, 0.804305f, 0.800391f, 0.796477f, 0.792564f,
		0.78865f, 0.784736f, 0.780822f, 0.776908f, 0.772994f, 0.76908f,
		0.765166f, 0.761252f, 0.757339f, 0.753425f, 0.749511f, 0.745597f,
		0.741683f, 0.737769f, 0.733855f, 0.729941f, 0.726027f, 0.722113f,
		0.7182f, 0.714286f, 0.710372f, 0.706458f, 0.702544f, 0.69863f,
		0.694716f, 0.690802f, 0.686888f, 0.682975f, 0.679061f, 0.675147f,
		0.671233f, 0.667319f, 0.663405f, 0.659491f, 0.655577f, 0.651663f,
		0.64775f, 0.643836f, 0.639922f, 0.636008f, 0.632094f, 0.62818f,
		0.624266f, 0.620352f, 0.616438f, 0.612524f, 0.608611f, 0.604697f,
		0.600783f, 0.596869f, 0.592955f, 0.589041f, 0.585127f, 0.581213f,
		0.577299f, 0.573385f, 0.569472f, 0.565558f, 0.561644f, 0.55773f,
		0.553816f, 0.549902f, 0.545988f, 0.542074f, 0.53816f, 0.534247f,
		0.530333f, 0.526419f, 0.522505f, 0.518591f, 0.514677f, 0.510763f,
		0.506849f, 0.502935f, 0.499022f, 0.495108f, 0.491194f, 0.48728f,
		0.483366f, 0.479452f, 0.475538f, 0.471624f, 0.46771f, 0.463796f,
		0.459883f, 0.455969f, 0.452055f, 0.448141f, 0.444227f, 0.440313f,
		0.436399f, 0.432485f, 0.428571f, 0.424658f, 0.420744f, 0.41683f,
		0.412916f, 0.409002f, 0.405088f, 0.401174f, 0.39726f, 0.393346f,
		0.389432f, 0.385519f, 0.381605f, 0.377691f, 0.373777f, 0.369863f,
		0.365949f, 0.362035f, 0.358121f, 0.354207f, 0.350294f, 0.34638f,
		0.342466f, 0.338552f, 0.334638f, 0.330724f, 0.32681f, 0.322896f,
		0.318982f, 0.315068f, 0.311155f, 0.307241f, 0.303327f, 0.299413f,
		0.295499f, 0.291585f, 0.287671f, 0.283757f, 0.279843f, 0.27593f,
		0.272016f, 0.268102f, 0.264188f, 0.260274f, 0.25636f, 0.252446f,
		0.248532f, 0.244618f, 0.240704f, 0.236791f, 0.232877f, 0.228963f,
		0.225049f, 0.221135f, 0.217221f, 0.213307f, 0.209393f, 0.205479f,
		0.201566f, 0.197652f, 0.193738f, 0.189824f, 0.18591f, 0.181996f,
		0.178082f, 0.174168f, 0.170254f, 0.166341f, 0.162427f, 0.158513f,
		0.154599f, 0.150685f, 0.146771f, 0.142857f, 0.138943f, 0.135029f,
		0.131115f, 0.127202f, 0.123288f, 0.119374f, 0.11546f, 0.111546f,
		0.107632f, 0.103718f, 0.0998043f, 0.0958903f, 0.0919765f, 0.0880627f,
		0.0841488f, 0.0802348f, 0.0763209f, 0.072407f, 0.0684931f, 0.0645792f,
		0.0606654f, 0.0567515f, 0.0528376f, 0.0489237f, 0.0450097f, 0.0410959f,
		0.037182f, 0.0332682f, 0.0293542f, 0.0254403f, 0.0215264f, 0.0176125f,
		0.0136986f, 0.00978482f, 0.00587088f, 0.00195694f, 0.f, 0.f,
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
using cable_table_t = wrap::data<control::cable_table<cable_table_mod<NV>>, 
                                 data::embedded::table<cable_table_t_data>>;

DECLARE_PARAMETER_RANGE_STEP(cable_table2_modRange, 
                             0., 
                             18., 
                             1.);

template <int NV>
using cable_table2_mod = parameter::from0To1<tempo_sync_t<NV>, 
                                             0, 
                                             cable_table2_modRange>;

struct cable_table2_t_data
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
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
		0.f, 0.f, 0.f, 0.f, 0.00195694f, 0.00587082f,
		0.0097847f, 0.0136986f, 0.0176126f, 0.0215265f, 0.0254403f, 0.0293542f,
		0.0332681f, 0.037182f, 0.0410959f, 0.0450097f, 0.0489237f, 0.0528376f,
		0.0567515f, 0.0606654f, 0.0645792f, 0.0684931f, 0.072407f, 0.0763209f,
		0.0802349f, 0.0841488f, 0.0880626f, 0.0919765f, 0.0958904f, 0.0998043f,
		0.103718f, 0.107632f, 0.111546f, 0.11546f, 0.119374f, 0.123288f,
		0.127202f, 0.131115f, 0.135029f, 0.138943f, 0.142857f, 0.146771f,
		0.150685f, 0.154599f, 0.158513f, 0.162427f, 0.16634f, 0.170254f,
		0.174168f, 0.178082f, 0.181996f, 0.18591f, 0.189824f, 0.193738f,
		0.197652f, 0.201566f, 0.20548f, 0.209393f, 0.213307f, 0.217221f,
		0.221135f, 0.225049f, 0.228963f, 0.232877f, 0.236791f, 0.240705f,
		0.244618f, 0.248532f, 0.252446f, 0.25636f, 0.260274f, 0.264188f,
		0.268102f, 0.272016f, 0.27593f, 0.279843f, 0.283757f, 0.287671f,
		0.291585f, 0.295499f, 0.299413f, 0.303327f, 0.307241f, 0.311155f,
		0.315068f, 0.318982f, 0.322896f, 0.32681f, 0.330724f, 0.334638f,
		0.338552f, 0.342466f, 0.34638f, 0.350294f, 0.354207f, 0.358121f,
		0.362035f, 0.365949f, 0.369863f, 0.373777f, 0.377691f, 0.381605f,
		0.385519f, 0.389432f, 0.393346f, 0.39726f, 0.401174f, 0.405088f,
		0.409002f, 0.412916f, 0.41683f, 0.420744f, 0.424658f, 0.428571f,
		0.432485f, 0.436399f, 0.440313f, 0.444227f, 0.448141f, 0.452055f,
		0.455969f, 0.459883f, 0.463796f, 0.46771f, 0.471624f, 0.475538f,
		0.479452f, 0.483366f, 0.48728f, 0.491194f, 0.495108f, 0.499022f,
		0.502935f, 0.506849f, 0.510763f, 0.514677f, 0.518591f, 0.522505f,
		0.526419f, 0.530333f, 0.534247f, 0.53816f, 0.542074f, 0.545988f,
		0.549902f, 0.553816f, 0.55773f, 0.561644f, 0.565558f, 0.569472f,
		0.573385f, 0.577299f, 0.581213f, 0.585127f, 0.589041f, 0.592955f,
		0.596869f, 0.600783f, 0.604697f, 0.608611f, 0.612525f, 0.616438f,
		0.620352f, 0.624266f, 0.62818f, 0.632094f, 0.636008f, 0.639922f,
		0.643836f, 0.64775f, 0.651663f, 0.655577f, 0.659491f, 0.663405f,
		0.667319f, 0.671233f, 0.675147f, 0.679061f, 0.682975f, 0.686888f,
		0.690802f, 0.694716f, 0.69863f, 0.702544f, 0.706458f, 0.710372f,
		0.714286f, 0.7182f, 0.722113f, 0.726027f, 0.729941f, 0.733855f,
		0.737769f, 0.741683f, 0.745597f, 0.749511f, 0.753425f, 0.757339f,
		0.761252f, 0.765166f, 0.76908f, 0.772994f, 0.776908f, 0.780822f,
		0.784736f, 0.78865f, 0.792564f, 0.796477f, 0.800391f, 0.804305f,
		0.808219f, 0.812133f, 0.816047f, 0.819961f, 0.823875f, 0.827789f,
		0.831703f, 0.835616f, 0.83953f, 0.843444f, 0.847358f, 0.851272f,
		0.855186f, 0.8591f, 0.863014f, 0.866928f, 0.870842f, 0.874755f,
		0.878669f, 0.882583f, 0.886497f, 0.890411f, 0.894325f, 0.898239f,
		0.902153f, 0.906067f, 0.90998f, 0.913894f, 0.917808f, 0.921722f,
		0.925636f, 0.92955f, 0.933464f, 0.937378f, 0.941292f, 0.945205f,
		0.949119f, 0.953033f, 0.956947f, 0.960861f, 0.964775f, 0.968689f,
		0.972603f, 0.976517f, 0.98043f, 0.984344f, 0.988258f, 0.992172f,
		0.996086f, 1.f
	};
};

template <int NV>
using cable_table2_t = wrap::data<control::cable_table<cable_table2_mod<NV>>, 
                                  data::embedded::table<cable_table2_t_data>>;
DECLARE_PARAMETER_RANGE_STEP(pma5_mod_0Range, 
                             1, 
                             16., 
                             0.1);

template <int NV>
using pma5_mod_0 = parameter::from0To1<fx::bitcrush<NV>, 
                                       0, 
                                       pma5_mod_0Range>;

DECLARE_PARAMETER_RANGE_STEP(pma5_mod_1Range, 
                             1., 
                             64., 
                             1.);

template <int NV>
using pma5_mod_1 = parameter::from0To1<fx::sampleandhold<NV>, 
                                       0, 
                                       pma5_mod_1Range>;

DECLARE_PARAMETER_RANGE_SKEW(pma5_mod_2Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma5_mod_2 = parameter::from0To1<filters::ring_mod<NV>, 
                                       0, 
                                       pma5_mod_2Range>;

DECLARE_PARAMETER_RANGE(pma5_mod_3Range, 
                        0.11, 
                        1.);

template <int NV>
using pma5_mod_3 = parameter::from0To1<math::expr<NV, custom::expr3>, 
                                       0, 
                                       pma5_mod_3Range>;

template <int NV>
using pma5_mod_4 = parameter::from0To1<math::expr<NV, custom::expr2>, 
                                       0, 
                                       pma5_mod_3Range>;

template <int NV>
using pma5_mod = parameter::chain<ranges::Identity, 
                                  pma5_mod_0<NV>, 
                                  pma5_mod_1<NV>, 
                                  pma5_mod_2<NV>, 
                                  pma5_mod_3<NV>, 
                                  pma5_mod_4<NV>, 
                                  parameter::plain<cable_table_t<NV>, 0>, 
                                  parameter::plain<cable_table2_t<NV>, 0>>;

template <int NV>
using pma5_t = control::pma<NV, pma5_mod<NV>>;
template <int NV>
using peak3_t = wrap::mod<parameter::plain<pma5_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank3_t<NV>>, 
                                   split6_t<NV>, 
                                   peak3_t<NV>, 
                                   pma5_t<NV>>;

template <int NV> using sliderbank5_c0 = sliderbank4_c0<NV>;

template <int NV> using sliderbank5_c1 = sliderbank4_c0<NV>;

template <int NV> using sliderbank5_c2 = sliderbank4_c0<NV>;

template <int NV> using sliderbank5_c3 = sliderbank4_c0<NV>;

template <int NV> using sliderbank5_c4 = sliderbank4_c0<NV>;

template <int NV> using sliderbank5_c5 = sliderbank4_c0<NV>;

template <int NV> using sliderbank5_c6 = sliderbank4_c0<NV>;

template <int NV> using sliderbank5_c7 = sliderbank4_c0<NV>;

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
using global_cable16_t_index = global_cable13_t_index;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain64_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable17_t_index = global_cable14_t_index;

template <int NV>
using global_cable17_t = routing::global_cable<global_cable17_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain65_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable17_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable18_t_index = global_cable15_t_index;

template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain66_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable18_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader16_t = event_data_reader13_t<NV>;

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader16_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader17_t = event_data_reader13_t<NV>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader17_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader21_t = event_data_reader13_t<NV>;

template <int NV>
using chain69_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader21_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader18_t = event_data_reader13_t<NV>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader18_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc18_t = midi_cc10_t<NV>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
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
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi13_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi14_t = midi7_t<NV>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi14_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi15_t = midi9_t<NV>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi15_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch7_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain15_t<NV>>, 
                                    chain20_t<NV>, 
                                    chain32_t<NV>, 
                                    chain33_t<NV>, 
                                    chain35_t<NV>, 
                                    chain36_t<NV>, 
                                    chain41_t<NV>>;

template <int NV>
using chain71_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch7_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain64_t<NV>>, 
                                  chain65_t<NV>, 
                                  chain66_t<NV>, 
                                  chain67_t<NV>, 
                                  chain68_t<NV>, 
                                  chain69_t<NV>, 
                                  chain70_t<NV>, 
                                  chain71_t<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(pma7_mod_0Range, 
                             0., 
                             24., 
                             0.231378);

template <int NV>
using pma7_mod_0 = parameter::from0To1<core::smoother<NV>, 
                                       0, 
                                       pma7_mod_0Range>;

DECLARE_PARAMETER_RANGE_SKEW(pma7_mod_1Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using pma7_mod_1 = parameter::from0To1<filters::ring_mod<NV>, 
                                       1, 
                                       pma7_mod_1Range>;

template <int NV>
using pma7_mod_2 = parameter::from0To1<filters::one_pole<NV>, 
                                       0, 
                                       pma5_mod_2Range>;

template <int NV> using pma7_mod_3 = pma7_mod_2<NV>;

template <int NV> using pma7_mod_4 = pma7_mod_2<NV>;

template <int NV>
using pma7_mod = parameter::chain<ranges::Identity, 
                                  pma7_mod_0<NV>, 
                                  pma7_mod_1<NV>, 
                                  pma7_mod_2<NV>, 
                                  pma7_mod_3<NV>, 
                                  pma7_mod_4<NV>>;

template <int NV>
using pma7_t = control::pma<NV, pma7_mod<NV>>;
template <int NV>
using peak5_t = wrap::mod<parameter::plain<pma7_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain63_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank5_t<NV>>, 
                                   split9_t<NV>, 
                                   peak5_t<NV>, 
                                   pma7_t<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain54_t<NV>>, 
                                  chain45_t<NV>, 
                                  chain63_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split3_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>>;

template <int NV>
using chain197_t = container::chain<parameter::empty, 
                                    wrap::fix<2, math::expr<NV, custom::expr3>>, 
                                    filters::one_pole<NV>, 
                                    core::smoother<NV>>;

template <int NV>
using chain198_t = container::chain<parameter::empty, 
                                    wrap::fix<2, math::expr<NV, custom::expr2>>, 
                                    math::tanh<NV>, 
                                    filters::one_pole<NV>, 
                                    core::mono2stereo>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<2, fx::bitcrush<NV>>, 
                                   filters::one_pole<NV>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<2, fx::sampleandhold<NV>>, 
                                   filters::one_pole<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, cable_table_t<NV>>, 
                                 cable_table2_t<NV>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<2, split_t<NV>>, 
                                   tempo_sync_t<NV>, 
                                   converter_t<NV>, 
                                   fx::sampleandhold<NV>, 
                                   filters::one_pole<NV>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filters::ring_mod<NV>>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain197_t<NV>>, 
                                    chain198_t<NV>, 
                                    chain38_t<NV>, 
                                    chain39_t<NV>, 
                                    chain42_t<NV>, 
                                    chain40_t<NV>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch1_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain7_t<NV>>, 
                                  chain34_t<NV>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, xfader1_t<NV>>, 
                                  split1_t<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, modchain_t<NV>>, 
                                  chain6_t<NV>, 
                                  filters::one_pole<NV>>;

namespace TransFX_t_parameters
{
// Parameter list for TransFX_impl::TransFX_t ------------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(FxMope_InputRange, 
                             1., 
                             6., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(FxMope_0Range, 
                             0., 
                             5., 
                             1.);

template <int NV>
using FxMope_0 = parameter::from0To1<TransFX_impl::branch1_t<NV>, 
                                     0, 
                                     FxMope_0Range>;

template <int NV>
using FxMope = parameter::chain<FxMope_InputRange, FxMope_0<NV>>;

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

DECLARE_PARAMETER_RANGE_STEP(Midi1_InputRange, 
                             1., 
                             7., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(Midi1_0Range, 
                             0., 
                             6., 
                             1.);

template <int NV>
using Midi1_0 = parameter::from0To1<TransFX_impl::branch5_t<NV>, 
                                    0, 
                                    Midi1_0Range>;

template <int NV>
using Midi1 = parameter::chain<Midi1_InputRange, Midi1_0<NV>>;

DECLARE_PARAMETER_RANGE(Xf2_InputRange, 
                        1., 
                        4.);
template <int NV>
using Xf2_0 = parameter::from0To1<TransFX_impl::event_data_reader20_t<NV>, 
                                  0, 
                                  XfStage_0Range>;

template <int NV>
using Xf2 = parameter::chain<Xf2_InputRange, Xf2_0<NV>>;

DECLARE_PARAMETER_RANGE(Mid2_InputRange, 
                        1., 
                        7.);
template <int NV>
using Mid2_0 = parameter::from0To1<TransFX_impl::branch6_t<NV>, 
                                   0, 
                                   Midi1_0Range>;

template <int NV>
using Mid2 = parameter::chain<Mid2_InputRange, Mid2_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(xf3_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV>
using xf3_0 = parameter::from0To1<TransFX_impl::event_data_reader18_t<NV>, 
                                  0, 
                                  XfStage_0Range>;

template <int NV>
using xf3 = parameter::chain<xf3_InputRange, xf3_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(mid3_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using mid3_0 = parameter::from0To1<TransFX_impl::branch7_t<NV>, 
                                   0, 
                                   Midi1_0Range>;

template <int NV>
using mid3 = parameter::chain<mid3_InputRange, mid3_0<NV>>;

template <int NV>
using FxMix = parameter::plain<TransFX_impl::pma6_t<NV>, 
                               2>;
template <int NV>
using MixMod = parameter::plain<TransFX_impl::pma6_t<NV>, 
                                1>;
template <int NV>
using FxParamA = parameter::plain<TransFX_impl::pma5_t<NV>, 
                                  2>;
template <int NV>
using FxParamB = parameter::plain<TransFX_impl::pma7_t<NV>, 
                                  2>;
template <int NV>
using Amod = parameter::plain<TransFX_impl::pma5_t<NV>, 
                              1>;
template <int NV>
using bMod = parameter::plain<TransFX_impl::pma7_t<NV>, 
                              1>;
template <int NV>
using TransFX_t_plist = parameter::list<FxMope<NV>, 
                                        FxMix<NV>, 
                                        MixMod<NV>, 
                                        FxParamA<NV>, 
                                        FxParamB<NV>, 
                                        Amod<NV>, 
                                        bMod<NV>, 
                                        XfStage<NV>, 
                                        Midi1<NV>, 
                                        Xf2<NV>, 
                                        Mid2<NV>, 
                                        xf3<NV>, 
                                        mid3<NV>>;
}

template <int NV>
using TransFX_t_ = container::chain<TransFX_t_parameters::TransFX_t_plist<NV>, 
                                    wrap::fix<2, chain2_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public TransFX_impl::TransFX_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 3;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(TransFX);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(204)
		{
			0x005B, 0x0000, 0x4600, 0x4D78, 0x706F, 0x0065, 0x0000, 0x3F80, 
            0x0000, 0x40C0, 0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x015B, 0x0000, 0x4600, 0x4D78, 0x7869, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0002, 0x0000, 0x694D, 0x4D78, 0x646F, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0003, 0x0000, 0x7846, 0x6150, 0x6172, 0x416D, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0004, 0x0000, 0x7846, 0x6150, 0x6172, 0x426D, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0005, 0x0000, 0x6D41, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0006, 0x0000, 0x4D62, 0x646F, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0007, 0x0000, 0x6658, 0x7453, 0x6761, 0x0065, 0x0000, 0x3F80, 
            0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x085B, 0x0000, 0x4D00, 0x6469, 0x3169, 0x0000, 0x8000, 0x003F, 
            0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0009, 0x0000, 0x6658, 0x0032, 0x0000, 0x3F80, 0x0000, 0x4080, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0A5B, 0x0000, 
            0x4D00, 0x6469, 0x0032, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0B5B, 0x0000, 0x7800, 
            0x3366, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x5B3F, 0x000C, 0x0000, 0x696D, 0x3364, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain2 = this->getT(0);                                                              // TransFX_impl::chain2_t<NV>
		auto& modchain = this->getT(0).getT(0);                                                    // TransFX_impl::modchain_t<NV>
		auto& split3 = this->getT(0).getT(0).getT(0);                                              // TransFX_impl::split3_t<NV>
		auto& chain54 = this->getT(0).getT(0).getT(0).getT(0);                                     // TransFX_impl::chain54_t<NV>
		auto& sliderbank4 = this->getT(0).getT(0).getT(0).getT(0).getT(0);                         // TransFX_impl::sliderbank4_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(0).getT(0).getT(1);                              // TransFX_impl::split7_t<NV>
		auto& chain55 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);                     // TransFX_impl::chain55_t<NV>
		auto& global_cable13 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);      // TransFX_impl::global_cable13_t<NV>
		auto& add34 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain42 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain56 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);                     // TransFX_impl::chain56_t<NV>
		auto& global_cable14 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0);      // TransFX_impl::global_cable14_t<NV>
		auto& add35 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(1);               // math::add<NV>
		auto& gain43 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(2);              // core::gain<NV>
		auto& chain57 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2);                     // TransFX_impl::chain57_t<NV>
		auto& global_cable15 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(0);      // TransFX_impl::global_cable15_t<NV>
		auto& add36 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(1);               // math::add<NV>
		auto& gain44 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(2);              // core::gain<NV>
		auto& chain58 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3);                     // TransFX_impl::chain58_t<NV>
		auto& event_data_reader13 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(0); // TransFX_impl::event_data_reader13_t<NV>
		auto& add37 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(1);               // math::add<NV>
		auto& gain45 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(2);              // core::gain<NV>
		auto& chain59 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(4);                     // TransFX_impl::chain59_t<NV>
		auto& event_data_reader14 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(4).getT(0); // TransFX_impl::event_data_reader14_t<NV>
		auto& add38 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(4).getT(1);               // math::add<NV>
		auto& gain46 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(4).getT(2);              // core::gain<NV>
		auto& chain60 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5);                     // TransFX_impl::chain60_t<NV>
		auto& event_data_reader15 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).getT(0); // TransFX_impl::event_data_reader15_t<NV>
		auto& add39 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).getT(1);               // math::add<NV>
		auto& gain47 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).getT(2);              // core::gain<NV>
		auto& chain61 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(6);                     // TransFX_impl::chain61_t<NV>
		auto& event_data_reader19 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(6).getT(0); // routing::event_data_reader<NV>
		auto& add40 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(6).getT(1);               // math::add<NV>
		auto& gain48 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(6).getT(2);              // core::gain<NV>
		auto& chain62 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(7);                     // TransFX_impl::chain62_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(7).getT(0);             // TransFX_impl::branch5_t<NV>
		auto& chain13 = this->getT(0).getT(0).getT(0).getT(0).                                     // TransFX_impl::chain13_t<NV>
                        getT(1).getT(7).getT(0).getT(0);
		auto& midi_cc10 = this->getT(0).getT(0).getT(0).getT(0).                                   // TransFX_impl::midi_cc10_t<NV>
                          getT(1).getT(7).getT(0).getT(0).
                          getT(0);
		auto& add50 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(0).
                      getT(1);
		auto& chain18 = this->getT(0).getT(0).getT(0).getT(0).                                     // TransFX_impl::chain18_t<NV>
                        getT(1).getT(7).getT(0).getT(1);
		auto& midi_cc11 = this->getT(0).getT(0).getT(0).getT(0).                                   // TransFX_impl::midi_cc11_t<NV>
                          getT(1).getT(7).getT(0).getT(1).
                          getT(0);
		auto& add51 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(1).
                      getT(1);
		auto& chain22 = this->getT(0).getT(0).getT(0).getT(0).                                     // TransFX_impl::chain22_t<NV>
                        getT(1).getT(7).getT(0).getT(2);
		auto& midi_cc12 = this->getT(0).getT(0).getT(0).getT(0).                                   // TransFX_impl::midi_cc12_t<NV>
                          getT(1).getT(7).getT(0).getT(2).
                          getT(0);
		auto& add52 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(2).
                      getT(1);
		auto& chain24 = this->getT(0).getT(0).getT(0).getT(0).                                     // TransFX_impl::chain24_t<NV>
                        getT(1).getT(7).getT(0).getT(3);
		auto& midi_cc13 = this->getT(0).getT(0).getT(0).getT(0).                                   // TransFX_impl::midi_cc13_t<NV>
                          getT(1).getT(7).getT(0).getT(3).
                          getT(0);
		auto& add53 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(3).
                      getT(1);
		auto& chain25 = this->getT(0).getT(0).getT(0).getT(0).                                     // TransFX_impl::chain25_t<NV>
                        getT(1).getT(7).getT(0).getT(4);
		auto& midi7 = this->getT(0).getT(0).getT(0).getT(0).                                       // TransFX_impl::midi7_t<NV>
                      getT(1).getT(7).getT(0).getT(4).
                      getT(0);
		auto& add54 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(4).
                      getT(1);
		auto& chain26 = this->getT(0).getT(0).getT(0).getT(0).                                     // TransFX_impl::chain26_t<NV>
                        getT(1).getT(7).getT(0).getT(5);
		auto& midi8 = this->getT(0).getT(0).getT(0).getT(0).                                       // TransFX_impl::midi8_t<NV>
                      getT(1).getT(7).getT(0).getT(5).
                      getT(0);
		auto& add55 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(5).
                      getT(1);
		auto& chain27 = this->getT(0).getT(0).getT(0).getT(0).                                     // TransFX_impl::chain27_t<NV>
                        getT(1).getT(7).getT(0).getT(6);
		auto& midi9 = this->getT(0).getT(0).getT(0).getT(0).                                       // TransFX_impl::midi9_t<NV>
                      getT(1).getT(7).getT(0).getT(6).
                      getT(0);
		auto& add56 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(6).
                      getT(1);
		auto& gain49 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(7).getT(1);              // core::gain<NV>
		auto& peak4 = this->getT(0).getT(0).getT(0).getT(0).getT(2);                               // TransFX_impl::peak4_t<NV>
		auto& pma6 = this->getT(0).getT(0).getT(0).getT(0).getT(3);                                // TransFX_impl::pma6_t<NV>
		auto& chain45 = this->getT(0).getT(0).getT(0).getT(1);                                     // TransFX_impl::chain45_t<NV>
		auto& sliderbank3 = this->getT(0).getT(0).getT(0).getT(1).getT(0);                         // TransFX_impl::sliderbank3_t<NV>
		auto& split6 = this->getT(0).getT(0).getT(0).getT(1).getT(1);                              // TransFX_impl::split6_t<NV>
		auto& chain46 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(0);                     // TransFX_impl::chain46_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).getT(0);      // TransFX_impl::global_cable10_t<NV>
		auto& add26 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain34 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain47 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(1);                     // TransFX_impl::chain47_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(1).getT(0);      // TransFX_impl::global_cable11_t<NV>
		auto& add27 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(1).getT(1);               // math::add<NV>
		auto& gain35 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(1).getT(2);              // core::gain<NV>
		auto& chain48 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(2);                     // TransFX_impl::chain48_t<NV>
		auto& global_cable12 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(2).getT(0);      // TransFX_impl::global_cable12_t<NV>
		auto& add28 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(2).getT(1);               // math::add<NV>
		auto& gain36 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(2).getT(2);              // core::gain<NV>
		auto& chain49 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(3);                     // TransFX_impl::chain49_t<NV>
		auto& event_data_reader10 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(3).getT(0); // TransFX_impl::event_data_reader10_t<NV>
		auto& add29 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(3).getT(1);               // math::add<NV>
		auto& gain37 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(3).getT(2);              // core::gain<NV>
		auto& chain50 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(4);                     // TransFX_impl::chain50_t<NV>
		auto& event_data_reader11 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(4).getT(0); // TransFX_impl::event_data_reader11_t<NV>
		auto& add30 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(4).getT(1);               // math::add<NV>
		auto& gain38 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(4).getT(2);              // core::gain<NV>
		auto& chain51 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(5);                     // TransFX_impl::chain51_t<NV>
		auto& event_data_reader12 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(5).getT(0); // TransFX_impl::event_data_reader12_t<NV>
		auto& add31 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(5).getT(1);               // math::add<NV>
		auto& gain39 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(5).getT(2);              // core::gain<NV>
		auto& chain52 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(6);                     // TransFX_impl::chain52_t<NV>
		auto& event_data_reader20 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(6).getT(0); // TransFX_impl::event_data_reader20_t<NV>
		auto& add32 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(6).getT(1);               // math::add<NV>
		auto& gain40 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(6).getT(2);              // core::gain<NV>
		auto& chain53 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(7);                     // TransFX_impl::chain53_t<NV>
		auto& branch6 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(7).getT(0);             // TransFX_impl::branch6_t<NV>
		auto& chain14 = this->getT(0).getT(0).getT(0).getT(1).                                     // TransFX_impl::chain14_t<NV>
                        getT(1).getT(7).getT(0).getT(0);
		auto& midi_cc14 = this->getT(0).getT(0).getT(0).getT(1).                                   // TransFX_impl::midi_cc14_t<NV>
                          getT(1).getT(7).getT(0).getT(0).
                          getT(0);
		auto& add57 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(0).
                      getT(1);
		auto& chain19 = this->getT(0).getT(0).getT(0).getT(1).                                     // TransFX_impl::chain19_t<NV>
                        getT(1).getT(7).getT(0).getT(1);
		auto& midi_cc15 = this->getT(0).getT(0).getT(0).getT(1).                                   // TransFX_impl::midi_cc15_t<NV>
                          getT(1).getT(7).getT(0).getT(1).
                          getT(0);
		auto& add58 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(1).
                      getT(1);
		auto& chain23 = this->getT(0).getT(0).getT(0).getT(1).                                     // TransFX_impl::chain23_t<NV>
                        getT(1).getT(7).getT(0).getT(2);
		auto& midi_cc16 = this->getT(0).getT(0).getT(0).getT(1).                                   // TransFX_impl::midi_cc16_t<NV>
                          getT(1).getT(7).getT(0).getT(2).
                          getT(0);
		auto& add59 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(2).
                      getT(1);
		auto& chain28 = this->getT(0).getT(0).getT(0).getT(1).                                     // TransFX_impl::chain28_t<NV>
                        getT(1).getT(7).getT(0).getT(3);
		auto& midi_cc17 = this->getT(0).getT(0).getT(0).getT(1).                                   // TransFX_impl::midi_cc17_t<NV>
                          getT(1).getT(7).getT(0).getT(3).
                          getT(0);
		auto& add60 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(3).
                      getT(1);
		auto& chain29 = this->getT(0).getT(0).getT(0).getT(1).                                     // TransFX_impl::chain29_t<NV>
                        getT(1).getT(7).getT(0).getT(4);
		auto& midi10 = this->getT(0).getT(0).getT(0).getT(1).                                      // TransFX_impl::midi10_t<NV>
                       getT(1).getT(7).getT(0).getT(4).
                       getT(0);
		auto& add61 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(4).
                      getT(1);
		auto& chain30 = this->getT(0).getT(0).getT(0).getT(1).                                     // TransFX_impl::chain30_t<NV>
                        getT(1).getT(7).getT(0).getT(5);
		auto& midi11 = this->getT(0).getT(0).getT(0).getT(1).                                      // TransFX_impl::midi11_t<NV>
                       getT(1).getT(7).getT(0).getT(5).
                       getT(0);
		auto& add62 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(5).
                      getT(1);
		auto& chain31 = this->getT(0).getT(0).getT(0).getT(1).                                     // TransFX_impl::chain31_t<NV>
                        getT(1).getT(7).getT(0).getT(6);
		auto& midi12 = this->getT(0).getT(0).getT(0).getT(1).                                      // TransFX_impl::midi12_t<NV>
                       getT(1).getT(7).getT(0).getT(6).
                       getT(0);
		auto& add63 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(6).
                      getT(1);
		auto& gain41 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(7).getT(1);              // core::gain<NV>
		auto& peak3 = this->getT(0).getT(0).getT(0).getT(1).getT(2);                               // TransFX_impl::peak3_t<NV>
		auto& pma5 = this->getT(0).getT(0).getT(0).getT(1).getT(3);                                // TransFX_impl::pma5_t<NV>
		auto& chain63 = this->getT(0).getT(0).getT(0).getT(2);                                     // TransFX_impl::chain63_t<NV>
		auto& sliderbank5 = this->getT(0).getT(0).getT(0).getT(2).getT(0);                         // TransFX_impl::sliderbank5_t<NV>
		auto& split9 = this->getT(0).getT(0).getT(0).getT(2).getT(1);                              // TransFX_impl::split9_t<NV>
		auto& chain64 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0);                     // TransFX_impl::chain64_t<NV>
		auto& global_cable16 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(0);      // TransFX_impl::global_cable16_t<NV>
		auto& add42 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain50 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain65 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1);                     // TransFX_impl::chain65_t<NV>
		auto& global_cable17 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1).getT(0);      // TransFX_impl::global_cable17_t<NV>
		auto& add43 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1).getT(1);               // math::add<NV>
		auto& gain51 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1).getT(2);              // core::gain<NV>
		auto& chain66 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(2);                     // TransFX_impl::chain66_t<NV>
		auto& global_cable18 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(2).getT(0);      // TransFX_impl::global_cable18_t<NV>
		auto& add44 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(2).getT(1);               // math::add<NV>
		auto& gain52 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(2).getT(2);              // core::gain<NV>
		auto& chain67 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(3);                     // TransFX_impl::chain67_t<NV>
		auto& event_data_reader16 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(3).getT(0); // TransFX_impl::event_data_reader16_t<NV>
		auto& add45 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(3).getT(1);               // math::add<NV>
		auto& gain53 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(3).getT(2);              // core::gain<NV>
		auto& chain68 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(4);                     // TransFX_impl::chain68_t<NV>
		auto& event_data_reader17 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(4).getT(0); // TransFX_impl::event_data_reader17_t<NV>
		auto& add46 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(4).getT(1);               // math::add<NV>
		auto& gain54 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(4).getT(2);              // core::gain<NV>
		auto& chain69 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(5);                     // TransFX_impl::chain69_t<NV>
		auto& event_data_reader21 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(5).getT(0); // TransFX_impl::event_data_reader21_t<NV>
		auto& add47 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(5).getT(1);               // math::add<NV>
		auto& gain55 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(5).getT(2);              // core::gain<NV>
		auto& chain70 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(6);                     // TransFX_impl::chain70_t<NV>
		auto& event_data_reader18 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(6).getT(0); // TransFX_impl::event_data_reader18_t<NV>
		auto& add48 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(6).getT(1);               // math::add<NV>
		auto& gain56 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(6).getT(2);              // core::gain<NV>
		auto& chain71 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(7);                     // TransFX_impl::chain71_t<NV>
		auto& branch7 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(7).getT(0);             // TransFX_impl::branch7_t<NV>
		auto& chain15 = this->getT(0).getT(0).getT(0).getT(2).                                     // TransFX_impl::chain15_t<NV>
                        getT(1).getT(7).getT(0).getT(0);
		auto& midi_cc18 = this->getT(0).getT(0).getT(0).getT(2).                              // TransFX_impl::midi_cc18_t<NV>
                          getT(1).getT(7).getT(0).getT(0).
                          getT(0);
		auto& add64 = this->getT(0).getT(0).getT(0).getT(2).                                  // math::add<NV>
                      getT(1).getT(7).getT(0).getT(0).
                      getT(1);
		auto& chain20 = this->getT(0).getT(0).getT(0).getT(2).                                // TransFX_impl::chain20_t<NV>
                        getT(1).getT(7).getT(0).getT(1);
		auto& midi_cc19 = this->getT(0).getT(0).getT(0).getT(2).                              // TransFX_impl::midi_cc19_t<NV>
                          getT(1).getT(7).getT(0).getT(1).
                          getT(0);
		auto& add65 = this->getT(0).getT(0).getT(0).getT(2).                                  // math::add<NV>
                      getT(1).getT(7).getT(0).getT(1).
                      getT(1);
		auto& chain32 = this->getT(0).getT(0).getT(0).getT(2).                                // TransFX_impl::chain32_t<NV>
                        getT(1).getT(7).getT(0).getT(2);
		auto& midi_cc20 = this->getT(0).getT(0).getT(0).getT(2).                              // TransFX_impl::midi_cc20_t<NV>
                          getT(1).getT(7).getT(0).getT(2).
                          getT(0);
		auto& add66 = this->getT(0).getT(0).getT(0).getT(2).                                  // math::add<NV>
                      getT(1).getT(7).getT(0).getT(2).
                      getT(1);
		auto& chain33 = this->getT(0).getT(0).getT(0).getT(2).                                // TransFX_impl::chain33_t<NV>
                        getT(1).getT(7).getT(0).getT(3);
		auto& midi_cc21 = this->getT(0).getT(0).getT(0).getT(2).                              // TransFX_impl::midi_cc21_t<NV>
                          getT(1).getT(7).getT(0).getT(3).
                          getT(0);
		auto& add67 = this->getT(0).getT(0).getT(0).getT(2).                                  // math::add<NV>
                      getT(1).getT(7).getT(0).getT(3).
                      getT(1);
		auto& chain35 = this->getT(0).getT(0).getT(0).getT(2).                                // TransFX_impl::chain35_t<NV>
                        getT(1).getT(7).getT(0).getT(4);
		auto& midi13 = this->getT(0).getT(0).getT(0).getT(2).                                 // TransFX_impl::midi13_t<NV>
                       getT(1).getT(7).getT(0).getT(4).
                       getT(0);
		auto& add68 = this->getT(0).getT(0).getT(0).getT(2).                                  // math::add<NV>
                      getT(1).getT(7).getT(0).getT(4).
                      getT(1);
		auto& chain36 = this->getT(0).getT(0).getT(0).getT(2).                                // TransFX_impl::chain36_t<NV>
                        getT(1).getT(7).getT(0).getT(5);
		auto& midi14 = this->getT(0).getT(0).getT(0).getT(2).                                 // TransFX_impl::midi14_t<NV>
                       getT(1).getT(7).getT(0).getT(5).
                       getT(0);
		auto& add69 = this->getT(0).getT(0).getT(0).getT(2).                                  // math::add<NV>
                      getT(1).getT(7).getT(0).getT(5).
                      getT(1);
		auto& chain41 = this->getT(0).getT(0).getT(0).getT(2).                                // TransFX_impl::chain41_t<NV>
                        getT(1).getT(7).getT(0).getT(6);
		auto& midi15 = this->getT(0).getT(0).getT(0).getT(2).                                 // TransFX_impl::midi15_t<NV>
                       getT(1).getT(7).getT(0).getT(6).
                       getT(0);
		auto& add70 = this->getT(0).getT(0).getT(0).getT(2).                                  // math::add<NV>
                      getT(1).getT(7).getT(0).getT(6).
                      getT(1);
		auto& gain57 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(7).getT(1);         // core::gain<NV>
		auto& peak5 = this->getT(0).getT(0).getT(0).getT(2).getT(2);                          // TransFX_impl::peak5_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(0).getT(2).getT(3);                           // TransFX_impl::pma7_t<NV>
		auto& chain6 = this->getT(0).getT(1);                                                 // TransFX_impl::chain6_t<NV>
		auto& xfader1 = this->getT(0).getT(1).getT(0);                                        // TransFX_impl::xfader1_t<NV>
		auto& split1 = this->getT(0).getT(1).getT(1);                                         // TransFX_impl::split1_t<NV>
		auto& chain7 = this->getT(0).getT(1).getT(1).getT(0);                                 // TransFX_impl::chain7_t<NV>
		auto& gain2 = this->getT(0).getT(1).getT(1).getT(0).getT(0);                          // core::gain<NV>
		auto& chain34 = this->getT(0).getT(1).getT(1).getT(1);                                // TransFX_impl::chain34_t<NV>
		auto& branch1 = this->getT(0).getT(1).getT(1).getT(1).getT(0);                        // TransFX_impl::branch1_t<NV>
		auto& chain197 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(0);               // TransFX_impl::chain197_t<NV>
		auto& expr3 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(0).getT(0);          // math::expr<NV, custom::expr3>
		auto& one_pole5 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(0).getT(1);      // filters::one_pole<NV>
		auto& smoother2 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(0).getT(2);      // core::smoother<NV>
		auto& chain198 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(1);               // TransFX_impl::chain198_t<NV>
		auto& expr2 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(1).getT(0);          // math::expr<NV, custom::expr2>
		auto& tanh = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(1).getT(1);           // math::tanh<NV>
		auto& one_pole4 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(1).getT(2);      // filters::one_pole<NV>
		auto& mono2stereo1 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(1).getT(3);   // core::mono2stereo
		auto& chain38 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(2);                // TransFX_impl::chain38_t<NV>
		auto& bitcrush = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(2).getT(0);       // fx::bitcrush<NV>
		auto& one_pole1 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(2).getT(1);      // filters::one_pole<NV>
		auto& chain39 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(3);                // TransFX_impl::chain39_t<NV>
		auto& sampleandhold = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(3).getT(0);  // fx::sampleandhold<NV>
		auto& one_pole2 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(3).getT(1);      // filters::one_pole<NV>
		auto& chain42 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(4);                // TransFX_impl::chain42_t<NV>
		auto& split = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(4).getT(0);          // TransFX_impl::split_t<NV>
		auto& cable_table = this->getT(0).getT(1).getT(1).getT(1).                            // TransFX_impl::cable_table_t<NV>
                            getT(0).getT(4).getT(0).getT(0);
		auto& cable_table2 = this->getT(0).getT(1).getT(1).getT(1).                           // TransFX_impl::cable_table2_t<NV>
                             getT(0).getT(4).getT(0).getT(1);
		auto& tempo_sync = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(4).getT(1);     // TransFX_impl::tempo_sync_t<NV>
		auto& converter = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(4).getT(2);      // TransFX_impl::converter_t<NV>
		auto& sampleandhold1 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(4).getT(3); // fx::sampleandhold<NV>
		auto& one_pole6 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(4).getT(4);      // filters::one_pole<NV>
		auto& chain40 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(5);                // TransFX_impl::chain40_t<NV>
		auto& ring_mod = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(5).getT(0);       // filters::ring_mod<NV>
		auto& gain32 = this->getT(0).getT(1).getT(1).getT(1).getT(1);                         // core::gain<NV>
		auto& one_pole = this->getT(0).getT(2);                                               // filters::one_pole<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, branch1); // FxMope -> branch1::Index
		
		this->getParameterT(1).connectT(0, pma6); // FxMix -> pma6::Add
		
		this->getParameterT(2).connectT(0, pma6); // MixMod -> pma6::Multiply
		
		this->getParameterT(3).connectT(0, pma5); // FxParamA -> pma5::Add
		
		this->getParameterT(4).connectT(0, pma7); // FxParamB -> pma7::Add
		
		this->getParameterT(5).connectT(0, pma5); // Amod -> pma5::Multiply
		
		this->getParameterT(6).connectT(0, pma7); // bMod -> pma7::Multiply
		
		this->getParameterT(7).connectT(0, event_data_reader19); // XfStage -> event_data_reader19::SlotIndex
		
		this->getParameterT(8).connectT(0, branch5); // Midi1 -> branch5::Index
		
		this->getParameterT(9).connectT(0, event_data_reader20); // Xf2 -> event_data_reader20::SlotIndex
		
		this->getParameterT(10).connectT(0, branch6); // Mid2 -> branch6::Index
		
		this->getParameterT(11).connectT(0, event_data_reader18); // xf3 -> event_data_reader18::SlotIndex
		
		this->getParameterT(12).connectT(0, branch7); // mid3 -> branch7::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& sliderbank4_p = sliderbank4.getWrappedObject().getParameter();
		sliderbank4_p.getParameterT(0).connectT(0, gain42);                  // sliderbank4 -> gain42::Gain
		sliderbank4_p.getParameterT(1).connectT(0, gain43);                  // sliderbank4 -> gain43::Gain
		sliderbank4_p.getParameterT(2).connectT(0, gain44);                  // sliderbank4 -> gain44::Gain
		sliderbank4_p.getParameterT(3).connectT(0, gain45);                  // sliderbank4 -> gain45::Gain
		sliderbank4_p.getParameterT(4).connectT(0, gain46);                  // sliderbank4 -> gain46::Gain
		sliderbank4_p.getParameterT(5).connectT(0, gain47);                  // sliderbank4 -> gain47::Gain
		sliderbank4_p.getParameterT(6).connectT(0, gain48);                  // sliderbank4 -> gain48::Gain
		sliderbank4_p.getParameterT(7).connectT(0, gain49);                  // sliderbank4 -> gain49::Gain
		global_cable13.getWrappedObject().getParameter().connectT(0, add34); // global_cable13 -> add34::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add35); // global_cable14 -> add35::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add36); // global_cable15 -> add36::Value
		event_data_reader13.getParameter().connectT(0, add37);               // event_data_reader13 -> add37::Value
		event_data_reader14.getParameter().connectT(0, add38);               // event_data_reader14 -> add38::Value
		event_data_reader15.getParameter().connectT(0, add39);               // event_data_reader15 -> add39::Value
		midi_cc10.getWrappedObject().getParameter().connectT(0, add50);      // midi_cc10 -> add50::Value
		midi_cc11.getWrappedObject().getParameter().connectT(0, add51);      // midi_cc11 -> add51::Value
		midi_cc12.getWrappedObject().getParameter().connectT(0, add52);      // midi_cc12 -> add52::Value
		midi_cc13.getWrappedObject().getParameter().connectT(0, add53);      // midi_cc13 -> add53::Value
		midi7.getParameter().connectT(0, add54);                             // midi7 -> add54::Value
		midi8.getParameter().connectT(0, add55);                             // midi8 -> add55::Value
		midi9.getParameter().connectT(0, add56);                             // midi9 -> add56::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain2);               // xfader1 -> gain2::Gain
		xfader1_p.getParameterT(1).connectT(0, gain32);              // xfader1 -> gain32::Gain
		pma6.getWrappedObject().getParameter().connectT(0, xfader1); // pma6 -> xfader1::Value
		peak4.getParameter().connectT(0, pma6);                      // peak4 -> pma6::Value
		auto& sliderbank3_p = sliderbank3.getWrappedObject().getParameter();
		sliderbank3_p.getParameterT(0).connectT(0, gain34);                      // sliderbank3 -> gain34::Gain
		sliderbank3_p.getParameterT(1).connectT(0, gain35);                      // sliderbank3 -> gain35::Gain
		sliderbank3_p.getParameterT(2).connectT(0, gain36);                      // sliderbank3 -> gain36::Gain
		sliderbank3_p.getParameterT(3).connectT(0, gain37);                      // sliderbank3 -> gain37::Gain
		sliderbank3_p.getParameterT(4).connectT(0, gain38);                      // sliderbank3 -> gain38::Gain
		sliderbank3_p.getParameterT(5).connectT(0, gain39);                      // sliderbank3 -> gain39::Gain
		sliderbank3_p.getParameterT(6).connectT(0, gain40);                      // sliderbank3 -> gain40::Gain
		sliderbank3_p.getParameterT(7).connectT(0, gain41);                      // sliderbank3 -> gain41::Gain
		global_cable10.getWrappedObject().getParameter().connectT(0, add26);     // global_cable10 -> add26::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add27);     // global_cable11 -> add27::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add28);     // global_cable12 -> add28::Value
		event_data_reader10.getParameter().connectT(0, add29);                   // event_data_reader10 -> add29::Value
		event_data_reader11.getParameter().connectT(0, add30);                   // event_data_reader11 -> add30::Value
		event_data_reader12.getParameter().connectT(0, add31);                   // event_data_reader12 -> add31::Value
		event_data_reader20.getParameter().connectT(0, add32);                   // event_data_reader20 -> add32::Value
		midi_cc14.getWrappedObject().getParameter().connectT(0, add57);          // midi_cc14 -> add57::Value
		midi_cc15.getWrappedObject().getParameter().connectT(0, add58);          // midi_cc15 -> add58::Value
		midi_cc16.getWrappedObject().getParameter().connectT(0, add59);          // midi_cc16 -> add59::Value
		midi_cc17.getWrappedObject().getParameter().connectT(0, add60);          // midi_cc17 -> add60::Value
		midi10.getParameter().connectT(0, add61);                                // midi10 -> add61::Value
		midi11.getParameter().connectT(0, add62);                                // midi11 -> add62::Value
		midi12.getParameter().connectT(0, add63);                                // midi12 -> add63::Value
		converter.getWrappedObject().getParameter().connectT(0, sampleandhold1); // converter -> sampleandhold1::Counter
		tempo_sync.getParameter().connectT(0, converter);                        // tempo_sync -> converter::Value
		cable_table.getWrappedObject().getParameter().connectT(0, tempo_sync);   // cable_table -> tempo_sync::Multiplier
		cable_table2.getWrappedObject().getParameter().connectT(0, tempo_sync);  // cable_table2 -> tempo_sync::Tempo
		pma5.getWrappedObject().getParameter().connectT(0, bitcrush);            // pma5 -> bitcrush::BitDepth
		pma5.getWrappedObject().getParameter().connectT(1, sampleandhold);       // pma5 -> sampleandhold::Counter
		pma5.getWrappedObject().getParameter().connectT(2, ring_mod);            // pma5 -> ring_mod::Frequency
		pma5.getWrappedObject().getParameter().connectT(3, expr3);               // pma5 -> expr3::Value
		pma5.getWrappedObject().getParameter().connectT(4, expr2);               // pma5 -> expr2::Value
		pma5.getWrappedObject().getParameter().connectT(5, cable_table);         // pma5 -> cable_table::Value
		pma5.getWrappedObject().getParameter().connectT(6, cable_table2);        // pma5 -> cable_table2::Value
		peak3.getParameter().connectT(0, pma5);                                  // peak3 -> pma5::Value
		auto& sliderbank5_p = sliderbank5.getWrappedObject().getParameter();
		sliderbank5_p.getParameterT(0).connectT(0, gain50);                  // sliderbank5 -> gain50::Gain
		sliderbank5_p.getParameterT(1).connectT(0, gain51);                  // sliderbank5 -> gain51::Gain
		sliderbank5_p.getParameterT(2).connectT(0, gain52);                  // sliderbank5 -> gain52::Gain
		sliderbank5_p.getParameterT(3).connectT(0, gain53);                  // sliderbank5 -> gain53::Gain
		sliderbank5_p.getParameterT(4).connectT(0, gain54);                  // sliderbank5 -> gain54::Gain
		sliderbank5_p.getParameterT(5).connectT(0, gain55);                  // sliderbank5 -> gain55::Gain
		sliderbank5_p.getParameterT(6).connectT(0, gain56);                  // sliderbank5 -> gain56::Gain
		sliderbank5_p.getParameterT(7).connectT(0, gain57);                  // sliderbank5 -> gain57::Gain
		global_cable16.getWrappedObject().getParameter().connectT(0, add42); // global_cable16 -> add42::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add43); // global_cable17 -> add43::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, add44); // global_cable18 -> add44::Value
		event_data_reader16.getParameter().connectT(0, add45);               // event_data_reader16 -> add45::Value
		event_data_reader17.getParameter().connectT(0, add46);               // event_data_reader17 -> add46::Value
		event_data_reader21.getParameter().connectT(0, add47);               // event_data_reader21 -> add47::Value
		event_data_reader18.getParameter().connectT(0, add48);               // event_data_reader18 -> add48::Value
		midi_cc18.getWrappedObject().getParameter().connectT(0, add64);      // midi_cc18 -> add64::Value
		midi_cc19.getWrappedObject().getParameter().connectT(0, add65);      // midi_cc19 -> add65::Value
		midi_cc20.getWrappedObject().getParameter().connectT(0, add66);      // midi_cc20 -> add66::Value
		midi_cc21.getWrappedObject().getParameter().connectT(0, add67);      // midi_cc21 -> add67::Value
		midi13.getParameter().connectT(0, add68);                            // midi13 -> add68::Value
		midi14.getParameter().connectT(0, add69);                            // midi14 -> add69::Value
		midi15.getParameter().connectT(0, add70);                            // midi15 -> add70::Value
		pma7.getWrappedObject().getParameter().connectT(0, smoother2);       // pma7 -> smoother2::SmoothingTime
		pma7.getWrappedObject().getParameter().connectT(1, ring_mod);        // pma7 -> ring_mod::Q
		pma7.getWrappedObject().getParameter().connectT(2, one_pole2);       // pma7 -> one_pole2::Frequency
		pma7.getWrappedObject().getParameter().connectT(3, one_pole1);       // pma7 -> one_pole1::Frequency
		pma7.getWrappedObject().getParameter().connectT(4, one_pole6);       // pma7 -> one_pole6::Frequency
		peak5.getParameter().connectT(0, pma7);                              // peak5 -> pma7::Value
		
		// Default Values --------------------------------------------------------------------------
		
		sliderbank4.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add34::Value is automated
		
		;                             // gain42::Gain is automated
		gain42.setParameterT(1, 20.); // core::gain::Smoothing
		gain42.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add35::Value is automated
		
		;                             // gain43::Gain is automated
		gain43.setParameterT(1, 20.); // core::gain::Smoothing
		gain43.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add36::Value is automated
		
		;                             // gain44::Gain is automated
		gain44.setParameterT(1, 20.); // core::gain::Smoothing
		gain44.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader13.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader13.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add37::Value is automated
		
		;                             // gain45::Gain is automated
		gain45.setParameterT(1, 20.); // core::gain::Smoothing
		gain45.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader14.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader14.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add38::Value is automated
		
		;                             // gain46::Gain is automated
		gain46.setParameterT(1, 20.); // core::gain::Smoothing
		gain46.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader15.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader15.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add39::Value is automated
		
		;                             // gain47::Gain is automated
		gain47.setParameterT(1, 20.); // core::gain::Smoothing
		gain47.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader19::SlotIndex is automated
		event_data_reader19.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		add40.setParameterT(0, 0.); // math::add::Value
		
		;                             // gain48::Gain is automated
		gain48.setParameterT(1, 20.); // core::gain::Smoothing
		gain48.setParameterT(2, 0.);  // core::gain::ResetValue
		
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
		
		;                             // gain49::Gain is automated
		gain49.setParameterT(1, 20.); // core::gain::Smoothing
		gain49.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma6::Value is automated
		; // pma6::Multiply is automated
		; // pma6::Add is automated
		
		sliderbank3.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable10.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add26::Value is automated
		
		;                             // gain34::Gain is automated
		gain34.setParameterT(1, 20.); // core::gain::Smoothing
		gain34.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable11.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add27::Value is automated
		
		;                             // gain35::Gain is automated
		gain35.setParameterT(1, 20.); // core::gain::Smoothing
		gain35.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add28::Value is automated
		
		;                             // gain36::Gain is automated
		gain36.setParameterT(1, 20.); // core::gain::Smoothing
		gain36.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader10.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader10.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add29::Value is automated
		
		;                             // gain37::Gain is automated
		gain37.setParameterT(1, 20.); // core::gain::Smoothing
		gain37.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader11.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader11.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add30::Value is automated
		
		;                             // gain38::Gain is automated
		gain38.setParameterT(1, 20.); // core::gain::Smoothing
		gain38.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader12.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader12.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add31::Value is automated
		
		;                             // gain39::Gain is automated
		gain39.setParameterT(1, 20.); // core::gain::Smoothing
		gain39.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader20::SlotIndex is automated
		event_data_reader20.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add32::Value is automated
		
		;                             // gain40::Gain is automated
		gain40.setParameterT(1, 20.); // core::gain::Smoothing
		gain40.setParameterT(2, 0.);  // core::gain::ResetValue
		
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
		
		;                             // gain41::Gain is automated
		gain41.setParameterT(1, 20.); // core::gain::Smoothing
		gain41.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma5::Value is automated
		; // pma5::Multiply is automated
		; // pma5::Add is automated
		
		sliderbank5.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add42::Value is automated
		
		;                             // gain50::Gain is automated
		gain50.setParameterT(1, 20.); // core::gain::Smoothing
		gain50.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add43::Value is automated
		
		;                             // gain51::Gain is automated
		gain51.setParameterT(1, 20.); // core::gain::Smoothing
		gain51.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable18.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add44::Value is automated
		
		;                             // gain52::Gain is automated
		gain52.setParameterT(1, 20.); // core::gain::Smoothing
		gain52.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader16.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader16.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add45::Value is automated
		
		;                             // gain53::Gain is automated
		gain53.setParameterT(1, 20.); // core::gain::Smoothing
		gain53.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader17.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader17.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add46::Value is automated
		
		;                             // gain54::Gain is automated
		gain54.setParameterT(1, 20.); // core::gain::Smoothing
		gain54.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader21.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader21.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add47::Value is automated
		
		;                             // gain55::Gain is automated
		gain55.setParameterT(1, 20.); // core::gain::Smoothing
		gain55.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader18::SlotIndex is automated
		event_data_reader18.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add48::Value is automated
		
		;                             // gain56::Gain is automated
		gain56.setParameterT(1, 20.); // core::gain::Smoothing
		gain56.setParameterT(2, 0.);  // core::gain::ResetValue
		
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
		
		;                             // gain57::Gain is automated
		gain57.setParameterT(1, 20.); // core::gain::Smoothing
		gain57.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma7::Value is automated
		; // pma7::Multiply is automated
		; // pma7::Add is automated
		
		; // xfader1::Value is automated
		
		;                             // gain2::Gain is automated
		gain2.setParameterT(1, 20.);  // core::gain::Smoothing
		gain2.setParameterT(2, -19.); // core::gain::ResetValue
		
		; // branch1::Index is automated
		
		; // expr3::Value is automated
		
		one_pole5.setParameterT(0, 0.);   // filters::one_pole::Frequency
		one_pole5.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole5.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole5.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole5.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole5.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                               // smoother2::SmoothingTime is automated
		smoother2.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		; // expr2::Value is automated
		
		tanh.setParameterT(0, 1.); // math::tanh::Value
		
		one_pole4.setParameterT(0, 0.);   // filters::one_pole::Frequency
		one_pole4.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole4.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole4.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole4.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole4.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                              // bitcrush::BitDepth is automated
		bitcrush.setParameterT(1, 0.); // fx::bitcrush::Mode
		
		;                                 // one_pole1::Frequency is automated
		one_pole1.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole1.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // sampleandhold::Counter is automated
		
		;                                 // one_pole2::Frequency is automated
		one_pole2.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole2.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole2.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole2.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole2.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		; // cable_table::Value is automated
		
		; // cable_table2::Value is automated
		
		;                                  // tempo_sync::Tempo is automated
		;                                  // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);   // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 200.); // control::tempo_sync::UnsyncedTime
		
		; // converter::Value is automated
		
		; // sampleandhold1::Counter is automated
		
		;                                 // one_pole6::Frequency is automated
		one_pole6.setParameterT(1, 1.);   // filters::one_pole::Q
		one_pole6.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole6.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole6.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole6.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                    // ring_mod::Frequency is automated
		;                                    // ring_mod::Q is automated
		ring_mod.setParameterT(2, -4.44825); // filters::ring_mod::Gain
		ring_mod.setParameterT(3, 0.01);     // filters::ring_mod::Smoothing
		ring_mod.setParameterT(4, 0.);       // filters::ring_mod::Mode
		ring_mod.setParameterT(5, 1.);       // filters::ring_mod::Enabled
		
		;                              // gain32::Gain is automated
		gain32.setParameterT(1, 20.);  // core::gain::Smoothing
		gain32.setParameterT(2, -20.); // core::gain::ResetValue
		
		one_pole.setParameterT(0, 50.1457); // filters::one_pole::Frequency
		one_pole.setParameterT(1, 1.);      // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);      // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01);    // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 1.);      // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		this->setParameterT(0, 4.);
		this->setParameterT(1, 1.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 1.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 1.);
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
		
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // TransFX_impl::global_cable13_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // TransFX_impl::global_cable14_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // TransFX_impl::global_cable15_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // TransFX_impl::global_cable10_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // TransFX_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // TransFX_impl::global_cable12_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // TransFX_impl::global_cable16_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // TransFX_impl::global_cable17_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // TransFX_impl::global_cable18_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index); // TransFX_impl::sliderbank4_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index); // TransFX_impl::peak4_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).setExternalData(b, index); // TransFX_impl::sliderbank3_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(2).setExternalData(b, index); // TransFX_impl::peak3_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).setExternalData(b, index); // TransFX_impl::sliderbank5_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(2).setExternalData(b, index); // TransFX_impl::peak5_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).                                   // TransFX_impl::cable_table_t<NV>
        getT(0).getT(4).getT(0).getT(0).setExternalData(b, index);
		this->getT(0).getT(1).getT(1).getT(1).  // TransFX_impl::cable_table2_t<NV>
        getT(0).getT(4).getT(0).getT(1).setExternalData(b, index);
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
using TransFX = wrap::node<TransFX_impl::instance<NV>>;
}


