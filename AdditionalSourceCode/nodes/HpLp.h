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

namespace HpLp_impl
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
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader10_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader12_t = event_data_reader3_t<NV>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader12_t<NV>>, 
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

template <int NV> using xfader_c0 = sliderbank3_c0<NV>;

template <int NV> using xfader_c1 = sliderbank3_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::overlap>;
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
using global_cable6_t_index = global_cable3_t_index;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable6_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable13_t_index = global_cable11_t_index;

template <int NV>
using global_cable13_t = routing::global_cable<global_cable13_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable13_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable14_t_index = global_cable10_t_index;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader6_t = event_data_reader3_t<NV>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader6_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader13_t = event_data_reader3_t<NV>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader13_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader14_t = event_data_reader3_t<NV>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader14_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader17_t = event_data_reader3_t<NV>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader17_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc14_t = midi_cc10_t<NV>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
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
                                    wrap::fix<1, chain16_t<NV>>, 
                                    chain19_t<NV>, 
                                    chain23_t<NV>, 
                                    chain28_t<NV>, 
                                    chain29_t<NV>, 
                                    chain30_t<NV>, 
                                    chain31_t<NV>>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch6_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain43_t<NV>>, 
                                  chain48_t<NV>, 
                                  chain49_t<NV>, 
                                  chain50_t<NV>, 
                                  chain51_t<NV>, 
                                  chain52_t<NV>, 
                                  chain53_t<NV>, 
                                  chain54_t<NV>>;

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
DECLARE_PARAMETER_RANGE_SKEW(pma2_mod_0Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma2_mod_0 = parameter::from0To1<filters::svf_eq<NV>, 
                                       0, 
                                       pma2_mod_0Range>;

template <int NV>
using pma2_mod_2 = parameter::from0To1<filters::ladder<NV>, 
                                       0, 
                                       pma2_mod_0Range>;

template <int NV> using pma2_mod_3 = pma2_mod_2<NV>;

template <int NV> using pma2_mod_4 = pma2_mod_0<NV>;

template <int NV>
using pma2_mod_5 = parameter::from0To1<filters::allpass<NV>, 
                                       0, 
                                       pma2_mod_0Range>;

template <int NV>
using pma2_mod = parameter::chain<ranges::Identity, 
                                  pma2_mod_0<NV>, 
                                  parameter::plain<cable_table_t<NV>, 0>, 
                                  pma2_mod_2<NV>, 
                                  pma2_mod_3<NV>, 
                                  pma2_mod_4<NV>, 
                                  pma2_mod_5<NV>>;

template <int NV>
using pma2_t = control::pma<NV, pma2_mod<NV>>;
template <int NV>
using peak4_t = wrap::mod<parameter::plain<pma2_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank4_t<NV>>, 
                                      split4_t<NV>, 
                                      peak4_t<NV>, 
                                      pma2_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

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
using global_cable7_t_index = global_cable3_t_index;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable7_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable15_t_index = global_cable11_t_index;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain56_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable16_t_index = global_cable10_t_index;

template <int NV>
using global_cable16_t = routing::global_cable<global_cable16_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable16_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader7_t = event_data_reader3_t<NV>;

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader7_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader15_t = event_data_reader3_t<NV>;

template <int NV>
using chain59_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader15_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader16_t = event_data_reader3_t<NV>;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader16_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::event_data_reader<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc18_t = midi_cc10_t<NV>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
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

template <int NV> using midi14_t = midi7_t<NV>;

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
                                    wrap::fix<1, chain17_t<NV>>, 
                                    chain20_t<NV>, 
                                    chain32_t<NV>, 
                                    chain33_t<NV>, 
                                    chain34_t<NV>, 
                                    chain35_t<NV>, 
                                    chain36_t<NV>>;

template <int NV>
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch7_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain55_t<NV>>, 
                                  chain56_t<NV>, 
                                  chain57_t<NV>, 
                                  chain58_t<NV>, 
                                  chain59_t<NV>, 
                                  chain60_t<NV>, 
                                  chain61_t<NV>, 
                                  chain62_t<NV>>;

template <int NV>
using pma5_mod_0 = parameter::from0To1<filters::svf<NV>, 
                                       0, 
                                       pma2_mod_0Range>;

template <int NV> using pma5_mod_1 = pma5_mod_0<NV>;

template <int NV> using pma5_mod_2 = pma2_mod_0<NV>;

template <int NV> using pma5_mod_3 = pma2_mod_0<NV>;

template <int NV>
using pma5_mod_4 = parameter::from0To1<filters::one_pole<NV>, 
                                       0, 
                                       pma2_mod_0Range>;

template <int NV> using pma5_mod_5 = pma5_mod_4<NV>;

template <int NV>
using pma5_mod = parameter::chain<ranges::Identity, 
                                  pma5_mod_0<NV>, 
                                  pma5_mod_1<NV>, 
                                  pma5_mod_2<NV>, 
                                  pma5_mod_3<NV>, 
                                  pma5_mod_4<NV>, 
                                  pma5_mod_5<NV>>;

template <int NV>
using pma5_t = control::pma<NV, pma5_mod<NV>>;
template <int NV>
using peak5_t = wrap::mod<parameter::plain<pma5_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using modchain2_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, sliderbank5_t<NV>>, 
                                      split5_t<NV>, 
                                      peak5_t<NV>, 
                                      pma5_t<NV>>;

template <int NV>
using modchain2_t = wrap::control_rate<modchain2_t_<NV>>;

template <int NV>
using split6_t = container::split<parameter::empty, 
                                  wrap::fix<2, modchain_t<NV>>, 
                                  modchain1_t<NV>, 
                                  modchain2_t<NV>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>>;

template <int NV>
using no_midi1_t_ = container::chain<parameter::empty, 
                                     wrap::fix<2, filters::ladder<NV>>, 
                                     filters::svf<NV>>;

template <int NV>
using no_midi1_t = wrap::no_midi<no_midi1_t_<NV>>;

template <int NV>
using chain164_t = container::chain<parameter::empty, 
                                    wrap::fix<2, no_midi1_t<NV>>>;

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<2, filters::ladder<NV>>, 
                                  filters::svf<NV>>;

template <int NV>
using chain186_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split8_t<NV>>>;
template <int NV>
using branch20_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain164_t<NV>>, 
                                     chain186_t<NV>>;

template <int NV>
using no_midi2_t_ = container::chain<parameter::empty, 
                                     wrap::fix<2, filters::svf_eq<NV>>, 
                                     filters::svf_eq<NV>>;

template <int NV>
using no_midi2_t = wrap::no_midi<no_midi2_t_<NV>>;

template <int NV>
using chain165_t = container::chain<parameter::empty, 
                                    wrap::fix<2, no_midi2_t<NV>>>;

template <int NV>
using split9_t = container::split<parameter::empty, 
                                  wrap::fix<2, filters::svf_eq<NV>>, 
                                  filters::svf_eq<NV>>;

template <int NV>
using chain187_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split9_t<NV>>>;
template <int NV>
using branch21_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain165_t<NV>>, 
                                     chain187_t<NV>>;

template <int NV>
using no_midi3_t_ = container::chain<parameter::empty, 
                                     wrap::fix<2, project::Comb<NV>>, 
                                     filters::one_pole<NV>>;

template <int NV>
using no_midi3_t = wrap::no_midi<no_midi3_t_<NV>>;

template <int NV>
using chain166_t = container::chain<parameter::empty, 
                                    wrap::fix<2, no_midi3_t<NV>>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<2, filters::allpass<NV>>, 
                                  filters::one_pole<NV>, 
                                  wrap::no_process<math::tanh<NV>>>;

template <int NV>
using split10_t = container::split<parameter::empty, 
                                   wrap::fix<2, chain4_t<NV>>>;

template <int NV>
using chain188_t = container::chain<parameter::empty, 
                                    wrap::fix<2, split10_t<NV>>>;
template <int NV>
using branch22_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain166_t<NV>>, 
                                     chain188_t<NV>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, branch20_t<NV>>, 
                                   branch21_t<NV>, 
                                   branch22_t<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, branch_t<NV>>, 
                                  core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain1_t<NV>>, 
                                 chain2_t<NV>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, xfader_t<NV>>, 
                                 cable_table_t<NV>, 
                                 split_t<NV>>;

template <int NV>
using frame2_block_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, chain_t<NV>>>;

template <int NV>
using frame2_block_t = wrap::frame<2, frame2_block_t_<NV>>;

namespace HpLp_t_parameters
{
// Parameter list for HpLp_impl::HpLp_t ------------------------------------------------------------

template <int NV>
using Mode = parameter::chain<ranges::Identity, 
                              parameter::plain<HpLp_impl::branch20_t<NV>, 0>, 
                              parameter::plain<HpLp_impl::branch21_t<NV>, 0>, 
                              parameter::plain<HpLp_impl::branch22_t<NV>, 0>>;

DECLARE_PARAMETER_RANGE_SKEW(Q_0Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using Q_0 = parameter::from0To1<filters::svf_eq<NV>, 
                                1, 
                                Q_0Range>;

DECLARE_PARAMETER_RANGE_SKEW(Q_1Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using Q_1 = parameter::from0To1<filters::svf_eq<NV>, 
                                1, 
                                Q_1Range>;

template <int NV>
using Q_2 = parameter::from0To1<filters::svf<NV>, 
                                1, 
                                Q_0Range>;

template <int NV>
using Q_3 = parameter::from0To1<filters::ladder<NV>, 
                                1, 
                                Q_0Range>;

template <int NV> using Q_4 = Q_3<NV>;

template <int NV> using Q_5 = Q_2<NV>;

template <int NV> using Q_6 = Q_0<NV>;

template <int NV> using Q_7 = Q_0<NV>;

DECLARE_PARAMETER_RANGE(Q_8Range, 
                        -18., 
                        18.);

template <int NV>
using Q_8 = parameter::from0To1<filters::svf_eq<NV>, 
                                2, 
                                Q_8Range>;

template <int NV> using Q_9 = Q_8<NV>;

template <int NV> using Q_10 = Q_8<NV>;

template <int NV> using Q_11 = Q_8<NV>;

template <int NV>
using Q_12 = parameter::from0To1<filters::allpass<NV>, 
                                 1, 
                                 Q_0Range>;

template <int NV>
using Q_14 = parameter::from0To1<filters::one_pole<NV>, 
                                 1, 
                                 Q_0Range>;

template <int NV> using Q_15 = Q_14<NV>;

template <int NV>
using Q = parameter::chain<ranges::Identity, 
                           Q_0<NV>, 
                           Q_1<NV>, 
                           Q_2<NV>, 
                           Q_3<NV>, 
                           Q_4<NV>, 
                           Q_5<NV>, 
                           Q_6<NV>, 
                           Q_7<NV>, 
                           Q_8<NV>, 
                           Q_9<NV>, 
                           Q_10<NV>, 
                           Q_11<NV>, 
                           Q_12<NV>, 
                           parameter::plain<project::Comb<NV>, 0>, 
                           Q_14<NV>, 
                           Q_15<NV>>;

DECLARE_PARAMETER_RANGE_STEP(type_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(type_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using type_0 = parameter::from0To1<HpLp_impl::branch_t<NV>, 
                                   0, 
                                   type_0Range>;

template <int NV>
using type = parameter::chain<type_InputRange, type_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(XfStage_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(XfStage_0Range, 
                             3., 
                             6., 
                             1.);

template <int NV>
using XfStage_0 = parameter::from0To1<HpLp_impl::event_data_reader12_t<NV>, 
                                      0, 
                                      XfStage_0Range>;

template <int NV>
using XfStage = parameter::chain<XfStage_InputRange, XfStage_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(MIDI1_InputRange, 
                             1., 
                             7., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(MIDI1_0Range, 
                             0., 
                             6., 
                             1.);

template <int NV>
using MIDI1_0 = parameter::from0To1<HpLp_impl::branch5_t<NV>, 
                                    0, 
                                    MIDI1_0Range>;

template <int NV>
using MIDI1 = parameter::chain<MIDI1_InputRange, MIDI1_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(MIDI2_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using MIDI2_0 = parameter::from0To1<HpLp_impl::branch6_t<NV>, 
                                    0, 
                                    MIDI1_0Range>;

template <int NV>
using MIDI2 = parameter::chain<MIDI2_InputRange, MIDI2_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(MID3_InputRange, 
                             1., 
                             7., 
                             1.);
template <int NV>
using MID3_0 = parameter::from0To1<HpLp_impl::branch7_t<NV>, 
                                   0, 
                                   MIDI1_0Range>;

template <int NV>
using MID3 = parameter::chain<MID3_InputRange, MID3_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(XF2_InputRange, 
                             1., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(XF2_0Range, 
                             2., 
                             5., 
                             1.);

template <int NV>
using XF2_0 = parameter::from0To1<HpLp_impl::event_data_reader17_t<NV>, 
                                  0, 
                                  XF2_0Range>;

template <int NV>
using XF2 = parameter::chain<XF2_InputRange, XF2_0<NV>>;

DECLARE_PARAMETER_RANGE_STEP(XF3_InputRange, 
                             1., 
                             4., 
                             1.);
template <int NV>
using XF3_0 = parameter::from0To1<routing::event_data_reader<NV>, 
                                  0, 
                                  XfStage_0Range>;

template <int NV>
using XF3 = parameter::chain<XF3_InputRange, XF3_0<NV>>;

template <int NV>
using TransformMix = parameter::plain<HpLp_impl::pma1_t<NV>, 2>;
template <int NV>
using TransformA = parameter::plain<HpLp_impl::pma2_t<NV>, 2>;
template <int NV>
using TransformB = parameter::plain<HpLp_impl::pma5_t<NV>, 2>;
template <int NV>
using MixMod = parameter::plain<HpLp_impl::pma1_t<NV>, 1>;
template <int NV>
using Amod = parameter::plain<HpLp_impl::pma2_t<NV>, 1>;
template <int NV>
using bmod = parameter::plain<HpLp_impl::pma5_t<NV>, 1>;
template <int NV>
using HpLp_t_plist = parameter::list<TransformMix<NV>, 
                                     TransformA<NV>, 
                                     TransformB<NV>, 
                                     Mode<NV>, 
                                     Q<NV>, 
                                     type<NV>, 
                                     MixMod<NV>, 
                                     Amod<NV>, 
                                     bmod<NV>, 
                                     XfStage<NV>, 
                                     MIDI1<NV>, 
                                     MIDI2<NV>, 
                                     MID3<NV>, 
                                     XF2<NV>, 
                                     XF3<NV>>;
}

template <int NV>
using HpLp_t_ = container::chain<HpLp_t_parameters::HpLp_t_plist<NV>, 
                                 wrap::fix<2, split6_t<NV>>, 
                                 frame2_block_t<NV>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public HpLp_impl::HpLp_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 3;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(HpLp);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(238)
		{
			0x005B, 0x0000, 0x5400, 0x6172, 0x736E, 0x6F66, 0x6D72, 0x694D, 
            0x0078, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x015B, 0x0000, 0x5400, 0x6172, 0x736E, 
            0x6F66, 0x6D72, 0x0041, 0x0000, 0x0000, 0x0000, 0x3F80, 0xD37A, 
            0x3F17, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 0x0000, 0x5400, 
            0x6172, 0x736E, 0x6F66, 0x6D72, 0x0042, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0xA6F5, 0x3EAC, 0x0000, 0x3F80, 0x0000, 0x0000, 0x035B, 
            0x0000, 0x4D00, 0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x045B, 0x0000, 
            0x5100, 0x0000, 0x0000, 0x0000, 0x8000, 0xD33F, 0x0B1B, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0005, 0x0000, 0x7974, 0x6570, 
            0x0000, 0x8000, 0x003F, 0x4000, 0x0040, 0x0000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0006, 0x0000, 0x694D, 0x4D78, 0x646F, 
            0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0007, 0x0000, 0x6D41, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x663F, 0xE666, 0x00BC, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0008, 0x0000, 0x6D62, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0009, 0x0000, 0x6658, 0x7453, 0x6761, 0x0065, 0x0000, 
            0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0A5B, 0x0000, 0x4D00, 0x4449, 0x3149, 0x0000, 0x8000, 
            0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x000B, 0x0000, 0x494D, 0x4944, 0x0032, 0x0000, 0x3F80, 
            0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0C5B, 0x0000, 0x4D00, 0x4449, 0x0033, 0x0000, 0x3F80, 0x0000, 
            0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0D5B, 
            0x0000, 0x5800, 0x3246, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x000E, 0x0000, 
            0x4658, 0x0033, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& split6 = this->getT(0);                                                    // HpLp_impl::split6_t<NV>
		auto& modchain = this->getT(0).getT(0);                                          // HpLp_impl::modchain_t<NV>
		auto& sliderbank3 = this->getT(0).getT(0).getT(0);                               // HpLp_impl::sliderbank3_t<NV>
		auto& split1 = this->getT(0).getT(0).getT(1);                                    // HpLp_impl::split1_t<NV>
		auto& chain39 = this->getT(0).getT(0).getT(1).getT(0);                           // HpLp_impl::chain39_t<NV>
		auto& global_cable3 = this->getT(0).getT(0).getT(1).getT(0).getT(0);             // HpLp_impl::global_cable3_t<NV>
		auto& add4 = this->getT(0).getT(0).getT(1).getT(0).getT(1);                      // math::add<NV>
		auto& gain13 = this->getT(0).getT(0).getT(1).getT(0).getT(2);                    // core::gain<NV>
		auto& chain41 = this->getT(0).getT(0).getT(1).getT(1);                           // HpLp_impl::chain41_t<NV>
		auto& global_cable11 = this->getT(0).getT(0).getT(1).getT(1).getT(0);            // HpLp_impl::global_cable11_t<NV>
		auto& add26 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                     // math::add<NV>
		auto& gain15 = this->getT(0).getT(0).getT(1).getT(1).getT(2);                    // core::gain<NV>
		auto& chain40 = this->getT(0).getT(0).getT(1).getT(2);                           // HpLp_impl::chain40_t<NV>
		auto& global_cable10 = this->getT(0).getT(0).getT(1).getT(2).getT(0);            // HpLp_impl::global_cable10_t<NV>
		auto& add5 = this->getT(0).getT(0).getT(1).getT(2).getT(1);                      // math::add<NV>
		auto& gain14 = this->getT(0).getT(0).getT(1).getT(2).getT(2);                    // core::gain<NV>
		auto& chain42 = this->getT(0).getT(0).getT(1).getT(3);                           // HpLp_impl::chain42_t<NV>
		auto& event_data_reader3 = this->getT(0).getT(0).getT(1).getT(3).getT(0);        // HpLp_impl::event_data_reader3_t<NV>
		auto& add27 = this->getT(0).getT(0).getT(1).getT(3).getT(1);                     // math::add<NV>
		auto& gain16 = this->getT(0).getT(0).getT(1).getT(3).getT(2);                    // core::gain<NV>
		auto& chain44 = this->getT(0).getT(0).getT(1).getT(4);                           // HpLp_impl::chain44_t<NV>
		auto& event_data_reader11 = this->getT(0).getT(0).getT(1).getT(4).getT(0);       // HpLp_impl::event_data_reader11_t<NV>
		auto& add29 = this->getT(0).getT(0).getT(1).getT(4).getT(1);                     // math::add<NV>
		auto& gain32 = this->getT(0).getT(0).getT(1).getT(4).getT(2);                    // core::gain<NV>
		auto& chain45 = this->getT(0).getT(0).getT(1).getT(5);                           // HpLp_impl::chain45_t<NV>
		auto& event_data_reader10 = this->getT(0).getT(0).getT(1).getT(5).getT(0);       // HpLp_impl::event_data_reader10_t<NV>
		auto& add28 = this->getT(0).getT(0).getT(1).getT(5).getT(1);                     // math::add<NV>
		auto& gain26 = this->getT(0).getT(0).getT(1).getT(5).getT(2);                    // core::gain<NV>
		auto& chain46 = this->getT(0).getT(0).getT(1).getT(6);                           // HpLp_impl::chain46_t<NV>
		auto& event_data_reader12 = this->getT(0).getT(0).getT(1).getT(6).getT(0);       // HpLp_impl::event_data_reader12_t<NV>
		auto& add30 = this->getT(0).getT(0).getT(1).getT(6).getT(1);                     // math::add<NV>
		auto& gain33 = this->getT(0).getT(0).getT(1).getT(6).getT(2);                    // core::gain<NV>
		auto& chain47 = this->getT(0).getT(0).getT(1).getT(7);                           // HpLp_impl::chain47_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(1).getT(7).getT(0);                   // HpLp_impl::branch5_t<NV>
		auto& chain13 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(0);           // HpLp_impl::chain13_t<NV>
		auto& midi_cc10 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(0).getT(0); // HpLp_impl::midi_cc10_t<NV>
		auto& add50 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(0).getT(1);     // math::add<NV>
		auto& chain18 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(1);           // HpLp_impl::chain18_t<NV>
		auto& midi_cc11 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(1).getT(0); // HpLp_impl::midi_cc11_t<NV>
		auto& add51 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(1).getT(1);     // math::add<NV>
		auto& chain22 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(2);           // HpLp_impl::chain22_t<NV>
		auto& midi_cc12 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(2).getT(0); // HpLp_impl::midi_cc12_t<NV>
		auto& add52 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(2).getT(1);     // math::add<NV>
		auto& chain24 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(3);           // HpLp_impl::chain24_t<NV>
		auto& midi_cc13 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(3).getT(0); // HpLp_impl::midi_cc13_t<NV>
		auto& add53 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(3).getT(1);     // math::add<NV>
		auto& chain25 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(4);           // HpLp_impl::chain25_t<NV>
		auto& midi7 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(4).getT(0);     // HpLp_impl::midi7_t<NV>
		auto& add54 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(4).getT(1);     // math::add<NV>
		auto& chain26 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(5);           // HpLp_impl::chain26_t<NV>
		auto& midi8 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(5).getT(0);     // HpLp_impl::midi8_t<NV>
		auto& add55 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(5).getT(1);     // math::add<NV>
		auto& chain27 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(6);           // HpLp_impl::chain27_t<NV>
		auto& midi9 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(6).getT(0);     // HpLp_impl::midi9_t<NV>
		auto& add56 = this->getT(0).getT(0).getT(1).getT(7).getT(0).getT(6).getT(1);     // math::add<NV>
		auto& gain34 = this->getT(0).getT(0).getT(1).getT(7).getT(1);                    // core::gain<NV>
		auto& peak3 = this->getT(0).getT(0).getT(2);                                     // HpLp_impl::peak3_t<NV>
		auto& pma1 = this->getT(0).getT(0).getT(3);                                      // HpLp_impl::pma1_t<NV>
		auto& modchain1 = this->getT(0).getT(1);                                         // HpLp_impl::modchain1_t<NV>
		auto& sliderbank4 = this->getT(0).getT(1).getT(0);                               // HpLp_impl::sliderbank4_t<NV>
		auto& split4 = this->getT(0).getT(1).getT(1);                                    // HpLp_impl::split4_t<NV>
		auto& chain43 = this->getT(0).getT(1).getT(1).getT(0);                           // HpLp_impl::chain43_t<NV>
		auto& global_cable6 = this->getT(0).getT(1).getT(1).getT(0).getT(0);             // HpLp_impl::global_cable6_t<NV>
		auto& add10 = this->getT(0).getT(1).getT(1).getT(0).getT(1);                     // math::add<NV>
		auto& gain25 = this->getT(0).getT(1).getT(1).getT(0).getT(2);                    // core::gain<NV>
		auto& chain48 = this->getT(0).getT(1).getT(1).getT(1);                           // HpLp_impl::chain48_t<NV>
		auto& global_cable13 = this->getT(0).getT(1).getT(1).getT(1).getT(0);            // HpLp_impl::global_cable13_t<NV>
		auto& add32 = this->getT(0).getT(1).getT(1).getT(1).getT(1);                     // math::add<NV>
		auto& gain29 = this->getT(0).getT(1).getT(1).getT(1).getT(2);                    // core::gain<NV>
		auto& chain49 = this->getT(0).getT(1).getT(1).getT(2);                           // HpLp_impl::chain49_t<NV>
		auto& global_cable14 = this->getT(0).getT(1).getT(1).getT(2).getT(0);            // HpLp_impl::global_cable14_t<NV>
		auto& add11 = this->getT(0).getT(1).getT(1).getT(2).getT(1);                     // math::add<NV>
		auto& gain30 = this->getT(0).getT(1).getT(1).getT(2).getT(2);                    // core::gain<NV>
		auto& chain50 = this->getT(0).getT(1).getT(1).getT(3);                           // HpLp_impl::chain50_t<NV>
		auto& event_data_reader6 = this->getT(0).getT(1).getT(1).getT(3).getT(0);        // HpLp_impl::event_data_reader6_t<NV>
		auto& add33 = this->getT(0).getT(1).getT(1).getT(3).getT(1);                     // math::add<NV>
		auto& gain31 = this->getT(0).getT(1).getT(1).getT(3).getT(2);                    // core::gain<NV>
		auto& chain51 = this->getT(0).getT(1).getT(1).getT(4);                           // HpLp_impl::chain51_t<NV>
		auto& event_data_reader13 = this->getT(0).getT(1).getT(1).getT(4).getT(0);       // HpLp_impl::event_data_reader13_t<NV>
		auto& add34 = this->getT(0).getT(1).getT(1).getT(4).getT(1);                     // math::add<NV>
		auto& gain35 = this->getT(0).getT(1).getT(1).getT(4).getT(2);                    // core::gain<NV>
		auto& chain52 = this->getT(0).getT(1).getT(1).getT(5);                           // HpLp_impl::chain52_t<NV>
		auto& event_data_reader14 = this->getT(0).getT(1).getT(1).getT(5).getT(0);       // HpLp_impl::event_data_reader14_t<NV>
		auto& add35 = this->getT(0).getT(1).getT(1).getT(5).getT(1);                     // math::add<NV>
		auto& gain36 = this->getT(0).getT(1).getT(1).getT(5).getT(2);                    // core::gain<NV>
		auto& chain53 = this->getT(0).getT(1).getT(1).getT(6);                           // HpLp_impl::chain53_t<NV>
		auto& event_data_reader17 = this->getT(0).getT(1).getT(1).getT(6).getT(0);       // HpLp_impl::event_data_reader17_t<NV>
		auto& add36 = this->getT(0).getT(1).getT(1).getT(6).getT(1);                     // math::add<NV>
		auto& gain37 = this->getT(0).getT(1).getT(1).getT(6).getT(2);                    // core::gain<NV>
		auto& chain54 = this->getT(0).getT(1).getT(1).getT(7);                           // HpLp_impl::chain54_t<NV>
		auto& branch6 = this->getT(0).getT(1).getT(1).getT(7).getT(0);                   // HpLp_impl::branch6_t<NV>
		auto& chain16 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(0);           // HpLp_impl::chain16_t<NV>
		auto& midi_cc14 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(0).getT(0); // HpLp_impl::midi_cc14_t<NV>
		auto& add57 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(0).getT(1);     // math::add<NV>
		auto& chain19 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(1);           // HpLp_impl::chain19_t<NV>
		auto& midi_cc15 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(1).getT(0); // HpLp_impl::midi_cc15_t<NV>
		auto& add58 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(1).getT(1);     // math::add<NV>
		auto& chain23 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(2);           // HpLp_impl::chain23_t<NV>
		auto& midi_cc16 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(2).getT(0); // HpLp_impl::midi_cc16_t<NV>
		auto& add59 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(2).getT(1);     // math::add<NV>
		auto& chain28 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(3);           // HpLp_impl::chain28_t<NV>
		auto& midi_cc17 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(3).getT(0); // HpLp_impl::midi_cc17_t<NV>
		auto& add60 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(3).getT(1);     // math::add<NV>
		auto& chain29 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(4);           // HpLp_impl::chain29_t<NV>
		auto& midi10 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(4).getT(0);    // HpLp_impl::midi10_t<NV>
		auto& add61 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(4).getT(1);     // math::add<NV>
		auto& chain30 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(5);           // HpLp_impl::chain30_t<NV>
		auto& midi11 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(5).getT(0);    // HpLp_impl::midi11_t<NV>
		auto& add62 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(5).getT(1);     // math::add<NV>
		auto& chain31 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(6);           // HpLp_impl::chain31_t<NV>
		auto& midi12 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(6).getT(0);    // HpLp_impl::midi12_t<NV>
		auto& add63 = this->getT(0).getT(1).getT(1).getT(7).getT(0).getT(6).getT(1);     // math::add<NV>
		auto& gain38 = this->getT(0).getT(1).getT(1).getT(7).getT(1);                    // core::gain<NV>
		auto& peak4 = this->getT(0).getT(1).getT(2);                                     // HpLp_impl::peak4_t<NV>
		auto& pma2 = this->getT(0).getT(1).getT(3);                                      // HpLp_impl::pma2_t<NV>
		auto& modchain2 = this->getT(0).getT(2);                                         // HpLp_impl::modchain2_t<NV>
		auto& sliderbank5 = this->getT(0).getT(2).getT(0);                               // HpLp_impl::sliderbank5_t<NV>
		auto& split5 = this->getT(0).getT(2).getT(1);                                    // HpLp_impl::split5_t<NV>
		auto& chain55 = this->getT(0).getT(2).getT(1).getT(0);                           // HpLp_impl::chain55_t<NV>
		auto& global_cable7 = this->getT(0).getT(2).getT(1).getT(0).getT(0);             // HpLp_impl::global_cable7_t<NV>
		auto& add12 = this->getT(0).getT(2).getT(1).getT(0).getT(1);                     // math::add<NV>
		auto& gain39 = this->getT(0).getT(2).getT(1).getT(0).getT(2);                    // core::gain<NV>
		auto& chain56 = this->getT(0).getT(2).getT(1).getT(1);                           // HpLp_impl::chain56_t<NV>
		auto& global_cable15 = this->getT(0).getT(2).getT(1).getT(1).getT(0);            // HpLp_impl::global_cable15_t<NV>
		auto& add38 = this->getT(0).getT(2).getT(1).getT(1).getT(1);                     // math::add<NV>
		auto& gain40 = this->getT(0).getT(2).getT(1).getT(1).getT(2);                    // core::gain<NV>
		auto& chain57 = this->getT(0).getT(2).getT(1).getT(2);                           // HpLp_impl::chain57_t<NV>
		auto& global_cable16 = this->getT(0).getT(2).getT(1).getT(2).getT(0);            // HpLp_impl::global_cable16_t<NV>
		auto& add13 = this->getT(0).getT(2).getT(1).getT(2).getT(1);                     // math::add<NV>
		auto& gain41 = this->getT(0).getT(2).getT(1).getT(2).getT(2);                    // core::gain<NV>
		auto& chain58 = this->getT(0).getT(2).getT(1).getT(3);                           // HpLp_impl::chain58_t<NV>
		auto& event_data_reader7 = this->getT(0).getT(2).getT(1).getT(3).getT(0);        // HpLp_impl::event_data_reader7_t<NV>
		auto& add39 = this->getT(0).getT(2).getT(1).getT(3).getT(1);                     // math::add<NV>
		auto& gain42 = this->getT(0).getT(2).getT(1).getT(3).getT(2);                    // core::gain<NV>
		auto& chain59 = this->getT(0).getT(2).getT(1).getT(4);                           // HpLp_impl::chain59_t<NV>
		auto& event_data_reader15 = this->getT(0).getT(2).getT(1).getT(4).getT(0);       // HpLp_impl::event_data_reader15_t<NV>
		auto& add40 = this->getT(0).getT(2).getT(1).getT(4).getT(1);                     // math::add<NV>
		auto& gain43 = this->getT(0).getT(2).getT(1).getT(4).getT(2);                    // core::gain<NV>
		auto& chain60 = this->getT(0).getT(2).getT(1).getT(5);                           // HpLp_impl::chain60_t<NV>
		auto& event_data_reader16 = this->getT(0).getT(2).getT(1).getT(5).getT(0);       // HpLp_impl::event_data_reader16_t<NV>
		auto& add41 = this->getT(0).getT(2).getT(1).getT(5).getT(1);                     // math::add<NV>
		auto& gain44 = this->getT(0).getT(2).getT(1).getT(5).getT(2);                    // core::gain<NV>
		auto& chain61 = this->getT(0).getT(2).getT(1).getT(6);                           // HpLp_impl::chain61_t<NV>
		auto& event_data_reader18 = this->getT(0).getT(2).getT(1).getT(6).getT(0);       // routing::event_data_reader<NV>
		auto& add42 = this->getT(0).getT(2).getT(1).getT(6).getT(1);                     // math::add<NV>
		auto& gain45 = this->getT(0).getT(2).getT(1).getT(6).getT(2);                    // core::gain<NV>
		auto& chain62 = this->getT(0).getT(2).getT(1).getT(7);                           // HpLp_impl::chain62_t<NV>
		auto& branch7 = this->getT(0).getT(2).getT(1).getT(7).getT(0);                   // HpLp_impl::branch7_t<NV>
		auto& chain17 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(0);           // HpLp_impl::chain17_t<NV>
		auto& midi_cc18 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(0).getT(0); // HpLp_impl::midi_cc18_t<NV>
		auto& add64 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(0).getT(1);     // math::add<NV>
		auto& chain20 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(1);           // HpLp_impl::chain20_t<NV>
		auto& midi_cc19 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(1).getT(0); // HpLp_impl::midi_cc19_t<NV>
		auto& add65 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(1).getT(1);     // math::add<NV>
		auto& chain32 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(2);           // HpLp_impl::chain32_t<NV>
		auto& midi_cc20 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(2).getT(0); // HpLp_impl::midi_cc20_t<NV>
		auto& add66 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(2).getT(1);     // math::add<NV>
		auto& chain33 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(3);           // HpLp_impl::chain33_t<NV>
		auto& midi_cc21 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(3).getT(0); // HpLp_impl::midi_cc21_t<NV>
		auto& add67 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(3).getT(1);     // math::add<NV>
		auto& chain34 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(4);           // HpLp_impl::chain34_t<NV>
		auto& midi13 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(4).getT(0);    // HpLp_impl::midi13_t<NV>
		auto& add68 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(4).getT(1);     // math::add<NV>
		auto& chain35 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(5);           // HpLp_impl::chain35_t<NV>
		auto& midi14 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(5).getT(0);    // HpLp_impl::midi14_t<NV>
		auto& add69 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(5).getT(1);     // math::add<NV>
		auto& chain36 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(6);           // HpLp_impl::chain36_t<NV>
		auto& midi15 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(6).getT(0);    // HpLp_impl::midi15_t<NV>
		auto& add70 = this->getT(0).getT(2).getT(1).getT(7).getT(0).getT(6).getT(1);     // math::add<NV>
		auto& gain46 = this->getT(0).getT(2).getT(1).getT(7).getT(1);                    // core::gain<NV>
		auto& peak5 = this->getT(0).getT(2).getT(2);                                     // HpLp_impl::peak5_t<NV>
		auto& pma5 = this->getT(0).getT(2).getT(3);                                      // HpLp_impl::pma5_t<NV>
		auto& frame2_block = this->getT(1);                                              // HpLp_impl::frame2_block_t<NV>
		auto& chain = this->getT(1).getT(0);                                             // HpLp_impl::chain_t<NV>
		auto& xfader = this->getT(1).getT(0).getT(0);                                    // HpLp_impl::xfader_t<NV>
		auto& cable_table = this->getT(1).getT(0).getT(1);                               // HpLp_impl::cable_table_t<NV>
		auto& split = this->getT(1).getT(0).getT(2);                                     // HpLp_impl::split_t<NV>
		auto& chain1 = this->getT(1).getT(0).getT(2).getT(0);                            // HpLp_impl::chain1_t<NV>
		auto& gain = this->getT(1).getT(0).getT(2).getT(0).getT(0);                      // core::gain<NV>
		auto& chain2 = this->getT(1).getT(0).getT(2).getT(1);                            // HpLp_impl::chain2_t<NV>
		auto& branch = this->getT(1).getT(0).getT(2).getT(1).getT(0);                    // HpLp_impl::branch_t<NV>
		auto& branch20 = this->getT(1).getT(0).getT(2).getT(1).getT(0).getT(0);          // HpLp_impl::branch20_t<NV>
		auto& chain164 = this->getT(1).getT(0).getT(2).getT(1).getT(0).getT(0).getT(0);  // HpLp_impl::chain164_t<NV>
		auto& no_midi1 = this->getT(1).getT(0).getT(2).getT(1).                          // HpLp_impl::no_midi1_t<NV>
                         getT(0).getT(0).getT(0).getT(0);
		auto& ladder1 = this->getT(1).getT(0).getT(2).getT(1).                          // filters::ladder<NV>
                        getT(0).getT(0).getT(0).getT(0).
                        getT(0);
		auto& svf = this->getT(1).getT(0).getT(2).getT(1).                              // filters::svf<NV>
                    getT(0).getT(0).getT(0).getT(0).
                    getT(1);
		auto& chain186 = this->getT(1).getT(0).getT(2).getT(1).getT(0).getT(0).getT(1); // HpLp_impl::chain186_t<NV>
		auto& split8 = this->getT(1).getT(0).getT(2).getT(1).                           // HpLp_impl::split8_t<NV>
                       getT(0).getT(0).getT(1).getT(0);
		auto& ladder2 = this->getT(1).getT(0).getT(2).getT(1).                          // filters::ladder<NV>
                        getT(0).getT(0).getT(1).getT(0).
                        getT(0);
		auto& svf1 = this->getT(1).getT(0).getT(2).getT(1).                             // filters::svf<NV>
                     getT(0).getT(0).getT(1).getT(0).
                     getT(1);
		auto& branch21 = this->getT(1).getT(0).getT(2).getT(1).getT(0).getT(1);         // HpLp_impl::branch21_t<NV>
		auto& chain165 = this->getT(1).getT(0).getT(2).getT(1).getT(0).getT(1).getT(0); // HpLp_impl::chain165_t<NV>
		auto& no_midi2 = this->getT(1).getT(0).getT(2).getT(1).                         // HpLp_impl::no_midi2_t<NV>
                         getT(0).getT(1).getT(0).getT(0);
		auto& svf_eq1 = this->getT(1).getT(0).getT(2).getT(1).                          // filters::svf_eq<NV>
                        getT(0).getT(1).getT(0).getT(0).
                        getT(0);
		auto& svf_eq = this->getT(1).getT(0).getT(2).getT(1).                           // filters::svf_eq<NV>
                       getT(0).getT(1).getT(0).getT(0).
                       getT(1);
		auto& chain187 = this->getT(1).getT(0).getT(2).getT(1).getT(0).getT(1).getT(1); // HpLp_impl::chain187_t<NV>
		auto& split9 = this->getT(1).getT(0).getT(2).getT(1).                           // HpLp_impl::split9_t<NV>
                       getT(0).getT(1).getT(1).getT(0);
		auto& svf_eq2 = this->getT(1).getT(0).getT(2).getT(1).                          // filters::svf_eq<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(0);
		auto& svf_eq3 = this->getT(1).getT(0).getT(2).getT(1).                          // filters::svf_eq<NV>
                        getT(0).getT(1).getT(1).getT(0).
                        getT(1);
		auto& branch22 = this->getT(1).getT(0).getT(2).getT(1).getT(0).getT(2);         // HpLp_impl::branch22_t<NV>
		auto& chain166 = this->getT(1).getT(0).getT(2).getT(1).getT(0).getT(2).getT(0); // HpLp_impl::chain166_t<NV>
		auto& no_midi3 = this->getT(1).getT(0).getT(2).getT(1).                         // HpLp_impl::no_midi3_t<NV>
                         getT(0).getT(2).getT(0).getT(0);
		auto& faust4 = this->getT(1).getT(0).getT(2).getT(1).                           // project::Comb<NV>
                       getT(0).getT(2).getT(0).getT(0).
                       getT(0);
		auto& one_pole = this->getT(1).getT(0).getT(2).getT(1).                         // filters::one_pole<NV>
                         getT(0).getT(2).getT(0).getT(0).
                         getT(1);
		auto& chain188 = this->getT(1).getT(0).getT(2).getT(1).getT(0).getT(2).getT(1); // HpLp_impl::chain188_t<NV>
		auto& split10 = this->getT(1).getT(0).getT(2).getT(1).                          // HpLp_impl::split10_t<NV>
                        getT(0).getT(2).getT(1).getT(0);
		auto& chain4 = this->getT(1).getT(0).getT(2).getT(1).             // HpLp_impl::chain4_t<NV>
                       getT(0).getT(2).getT(1).getT(0).
                       getT(0);
		auto& allpass1 = this->getT(1).getT(0).getT(2).getT(1).getT(0).   // filters::allpass<NV>
                         getT(2).getT(1).getT(0).getT(0).getT(0);
		auto& one_pole1 = this->getT(1).getT(0).getT(2).getT(1).getT(0).  // filters::one_pole<NV>
                          getT(2).getT(1).getT(0).getT(0).getT(1);
		auto& tanh1 = this->getT(1).getT(0).getT(2).getT(1).getT(0).  // wrap::no_process<math::tanh<NV>>
                      getT(2).getT(1).getT(0).getT(0).getT(2);
		auto& gain1 = this->getT(1).getT(0).getT(2).getT(1).getT(1); // core::gain<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma1); // TransformMix -> pma1::Add
		
		this->getParameterT(1).connectT(0, pma2); // TransformA -> pma2::Add
		
		this->getParameterT(2).connectT(0, pma5); // TransformB -> pma5::Add
		
		auto& Mode_p = this->getParameterT(3);
		Mode_p.connectT(0, branch20); // Mode -> branch20::Index
		Mode_p.connectT(1, branch21); // Mode -> branch21::Index
		Mode_p.connectT(2, branch22); // Mode -> branch22::Index
		
		auto& Q_p = this->getParameterT(4);
		Q_p.connectT(0, svf_eq1);    // Q -> svf_eq1::Q
		Q_p.connectT(1, svf_eq);     // Q -> svf_eq::Q
		Q_p.connectT(2, svf1);       // Q -> svf1::Q
		Q_p.connectT(3, ladder2);    // Q -> ladder2::Q
		Q_p.connectT(4, ladder1);    // Q -> ladder1::Q
		Q_p.connectT(5, svf);        // Q -> svf::Q
		Q_p.connectT(6, svf_eq3);    // Q -> svf_eq3::Q
		Q_p.connectT(7, svf_eq2);    // Q -> svf_eq2::Q
		Q_p.connectT(8, svf_eq2);    // Q -> svf_eq2::Gain
		Q_p.connectT(9, svf_eq3);    // Q -> svf_eq3::Gain
		Q_p.connectT(10, svf_eq1);   // Q -> svf_eq1::Gain
		Q_p.connectT(11, svf_eq);    // Q -> svf_eq::Gain
		Q_p.connectT(12, allpass1);  // Q -> allpass1::Q
		Q_p.connectT(13, faust4);    // Q -> faust4::aN
		Q_p.connectT(14, one_pole);  // Q -> one_pole::Q
		Q_p.connectT(15, one_pole1); // Q -> one_pole1::Q
		
		this->getParameterT(5).connectT(0, branch); // type -> branch::Index
		
		this->getParameterT(6).connectT(0, pma1); // MixMod -> pma1::Multiply
		
		this->getParameterT(7).connectT(0, pma2); // Amod -> pma2::Multiply
		
		this->getParameterT(8).connectT(0, pma5); // bmod -> pma5::Multiply
		
		this->getParameterT(9).connectT(0, event_data_reader12); // XfStage -> event_data_reader12::SlotIndex
		
		this->getParameterT(10).connectT(0, branch5); // MIDI1 -> branch5::Index
		
		this->getParameterT(11).connectT(0, branch6); // MIDI2 -> branch6::Index
		
		this->getParameterT(12).connectT(0, branch7); // MID3 -> branch7::Index
		
		this->getParameterT(13).connectT(0, event_data_reader17); // XF2 -> event_data_reader17::SlotIndex
		
		this->getParameterT(14).connectT(0, event_data_reader18); // XF3 -> event_data_reader18::SlotIndex
		
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
		event_data_reader12.getParameter().connectT(0, add30);               // event_data_reader12 -> add30::Value
		midi_cc10.getWrappedObject().getParameter().connectT(0, add50);      // midi_cc10 -> add50::Value
		midi_cc11.getWrappedObject().getParameter().connectT(0, add51);      // midi_cc11 -> add51::Value
		midi_cc12.getWrappedObject().getParameter().connectT(0, add52);      // midi_cc12 -> add52::Value
		midi_cc13.getWrappedObject().getParameter().connectT(0, add53);      // midi_cc13 -> add53::Value
		midi7.getParameter().connectT(0, add54);                             // midi7 -> add54::Value
		midi8.getParameter().connectT(0, add55);                             // midi8 -> add55::Value
		midi9.getParameter().connectT(0, add56);                             // midi9 -> add56::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain);                // xfader -> gain::Gain
		xfader_p.getParameterT(1).connectT(0, gain1);               // xfader -> gain1::Gain
		pma1.getWrappedObject().getParameter().connectT(0, xfader); // pma1 -> xfader::Value
		peak3.getParameter().connectT(0, pma1);                     // peak3 -> pma1::Value
		auto& sliderbank4_p = sliderbank4.getWrappedObject().getParameter();
		sliderbank4_p.getParameterT(0).connectT(0, gain25);                  // sliderbank4 -> gain25::Gain
		sliderbank4_p.getParameterT(1).connectT(0, gain29);                  // sliderbank4 -> gain29::Gain
		sliderbank4_p.getParameterT(2).connectT(0, gain30);                  // sliderbank4 -> gain30::Gain
		sliderbank4_p.getParameterT(3).connectT(0, gain31);                  // sliderbank4 -> gain31::Gain
		sliderbank4_p.getParameterT(4).connectT(0, gain35);                  // sliderbank4 -> gain35::Gain
		sliderbank4_p.getParameterT(5).connectT(0, gain36);                  // sliderbank4 -> gain36::Gain
		sliderbank4_p.getParameterT(6).connectT(0, gain37);                  // sliderbank4 -> gain37::Gain
		sliderbank4_p.getParameterT(7).connectT(0, gain38);                  // sliderbank4 -> gain38::Gain
		global_cable6.getWrappedObject().getParameter().connectT(0, add10);  // global_cable6 -> add10::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add32); // global_cable13 -> add32::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add11); // global_cable14 -> add11::Value
		event_data_reader6.getParameter().connectT(0, add33);                // event_data_reader6 -> add33::Value
		event_data_reader13.getParameter().connectT(0, add34);               // event_data_reader13 -> add34::Value
		event_data_reader14.getParameter().connectT(0, add35);               // event_data_reader14 -> add35::Value
		event_data_reader17.getParameter().connectT(0, add36);               // event_data_reader17 -> add36::Value
		midi_cc14.getWrappedObject().getParameter().connectT(0, add57);      // midi_cc14 -> add57::Value
		midi_cc15.getWrappedObject().getParameter().connectT(0, add58);      // midi_cc15 -> add58::Value
		midi_cc16.getWrappedObject().getParameter().connectT(0, add59);      // midi_cc16 -> add59::Value
		midi_cc17.getWrappedObject().getParameter().connectT(0, add60);      // midi_cc17 -> add60::Value
		midi10.getParameter().connectT(0, add61);                            // midi10 -> add61::Value
		midi11.getParameter().connectT(0, add62);                            // midi11 -> add62::Value
		midi12.getParameter().connectT(0, add63);                            // midi12 -> add63::Value
		cable_table.getWrappedObject().getParameter().connectT(0, faust4);   // cable_table -> faust4::del
		pma2.getWrappedObject().getParameter().connectT(0, svf_eq1);         // pma2 -> svf_eq1::Frequency
		pma2.getWrappedObject().getParameter().connectT(1, cable_table);     // pma2 -> cable_table::Value
		pma2.getWrappedObject().getParameter().connectT(2, ladder2);         // pma2 -> ladder2::Frequency
		pma2.getWrappedObject().getParameter().connectT(3, ladder1);         // pma2 -> ladder1::Frequency
		pma2.getWrappedObject().getParameter().connectT(4, svf_eq2);         // pma2 -> svf_eq2::Frequency
		pma2.getWrappedObject().getParameter().connectT(5, allpass1);        // pma2 -> allpass1::Frequency
		peak4.getParameter().connectT(0, pma2);                              // peak4 -> pma2::Value
		auto& sliderbank5_p = sliderbank5.getWrappedObject().getParameter();
		sliderbank5_p.getParameterT(0).connectT(0, gain39);                  // sliderbank5 -> gain39::Gain
		sliderbank5_p.getParameterT(1).connectT(0, gain40);                  // sliderbank5 -> gain40::Gain
		sliderbank5_p.getParameterT(2).connectT(0, gain41);                  // sliderbank5 -> gain41::Gain
		sliderbank5_p.getParameterT(3).connectT(0, gain42);                  // sliderbank5 -> gain42::Gain
		sliderbank5_p.getParameterT(4).connectT(0, gain43);                  // sliderbank5 -> gain43::Gain
		sliderbank5_p.getParameterT(5).connectT(0, gain44);                  // sliderbank5 -> gain44::Gain
		sliderbank5_p.getParameterT(6).connectT(0, gain45);                  // sliderbank5 -> gain45::Gain
		sliderbank5_p.getParameterT(7).connectT(0, gain46);                  // sliderbank5 -> gain46::Gain
		global_cable7.getWrappedObject().getParameter().connectT(0, add12);  // global_cable7 -> add12::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add38); // global_cable15 -> add38::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add13); // global_cable16 -> add13::Value
		event_data_reader7.getParameter().connectT(0, add39);                // event_data_reader7 -> add39::Value
		event_data_reader15.getParameter().connectT(0, add40);               // event_data_reader15 -> add40::Value
		event_data_reader16.getParameter().connectT(0, add41);               // event_data_reader16 -> add41::Value
		midi_cc18.getWrappedObject().getParameter().connectT(0, add64);      // midi_cc18 -> add64::Value
		midi_cc19.getWrappedObject().getParameter().connectT(0, add65);      // midi_cc19 -> add65::Value
		midi_cc20.getWrappedObject().getParameter().connectT(0, add66);      // midi_cc20 -> add66::Value
		midi_cc21.getWrappedObject().getParameter().connectT(0, add67);      // midi_cc21 -> add67::Value
		midi13.getParameter().connectT(0, add68);                            // midi13 -> add68::Value
		midi14.getParameter().connectT(0, add69);                            // midi14 -> add69::Value
		midi15.getParameter().connectT(0, add70);                            // midi15 -> add70::Value
		pma5.getWrappedObject().getParameter().connectT(0, svf);             // pma5 -> svf::Frequency
		pma5.getWrappedObject().getParameter().connectT(1, svf1);            // pma5 -> svf1::Frequency
		pma5.getWrappedObject().getParameter().connectT(2, svf_eq3);         // pma5 -> svf_eq3::Frequency
		pma5.getWrappedObject().getParameter().connectT(3, svf_eq);          // pma5 -> svf_eq::Frequency
		pma5.getWrappedObject().getParameter().connectT(4, one_pole);        // pma5 -> one_pole::Frequency
		pma5.getWrappedObject().getParameter().connectT(5, one_pole1);       // pma5 -> one_pole1::Frequency
		peak5.getParameter().connectT(0, pma5);                              // peak5 -> pma5::Value
		
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
		
		event_data_reader10.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader10.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add28::Value is automated
		
		;                             // gain26::Gain is automated
		gain26.setParameterT(1, 20.); // core::gain::Smoothing
		gain26.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader12::SlotIndex is automated
		event_data_reader12.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add30::Value is automated
		
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
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		sliderbank4.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		;                             // gain25::Gain is automated
		gain25.setParameterT(1, 20.); // core::gain::Smoothing
		gain25.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add32::Value is automated
		
		;                             // gain29::Gain is automated
		gain29.setParameterT(1, 20.); // core::gain::Smoothing
		gain29.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add11::Value is automated
		
		;                             // gain30::Gain is automated
		gain30.setParameterT(1, 20.); // core::gain::Smoothing
		gain30.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader6.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader6.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add33::Value is automated
		
		;                             // gain31::Gain is automated
		gain31.setParameterT(1, 20.); // core::gain::Smoothing
		gain31.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader13.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader13.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add34::Value is automated
		
		;                             // gain35::Gain is automated
		gain35.setParameterT(1, 20.); // core::gain::Smoothing
		gain35.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader14.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader14.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add35::Value is automated
		
		;                             // gain36::Gain is automated
		gain36.setParameterT(1, 20.); // core::gain::Smoothing
		gain36.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader17::SlotIndex is automated
		event_data_reader17.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add36::Value is automated
		
		;                             // gain37::Gain is automated
		gain37.setParameterT(1, 20.); // core::gain::Smoothing
		gain37.setParameterT(2, 0.);  // core::gain::ResetValue
		
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
		
		;                             // gain38::Gain is automated
		gain38.setParameterT(1, 20.); // core::gain::Smoothing
		gain38.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma2::Value is automated
		; // pma2::Multiply is automated
		; // pma2::Add is automated
		
		sliderbank5.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		;                             // gain39::Gain is automated
		gain39.setParameterT(1, 20.); // core::gain::Smoothing
		gain39.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add38::Value is automated
		
		;                             // gain40::Gain is automated
		gain40.setParameterT(1, 20.); // core::gain::Smoothing
		gain40.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add13::Value is automated
		
		;                             // gain41::Gain is automated
		gain41.setParameterT(1, 20.); // core::gain::Smoothing
		gain41.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader7.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader7.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add39::Value is automated
		
		;                             // gain42::Gain is automated
		gain42.setParameterT(1, 20.); // core::gain::Smoothing
		gain42.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader15.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader15.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add40::Value is automated
		
		;                             // gain43::Gain is automated
		gain43.setParameterT(1, 20.); // core::gain::Smoothing
		gain43.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader16.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader16.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add41::Value is automated
		
		;                             // gain44::Gain is automated
		gain44.setParameterT(1, 20.); // core::gain::Smoothing
		gain44.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader18::SlotIndex is automated
		event_data_reader18.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		add42.setParameterT(0, 0.); // math::add::Value
		
		;                             // gain45::Gain is automated
		gain45.setParameterT(1, 20.); // core::gain::Smoothing
		gain45.setParameterT(2, 0.);  // core::gain::ResetValue
		
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
		
		;                             // gain46::Gain is automated
		gain46.setParameterT(1, 20.); // core::gain::Smoothing
		gain46.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma5::Value is automated
		; // pma5::Multiply is automated
		; // pma5::Add is automated
		
		; // xfader::Value is automated
		
		; // cable_table::Value is automated
		
		;                            // gain::Gain is automated
		gain.setParameterT(1, 20.);  // core::gain::Smoothing
		gain.setParameterT(2, -24.); // core::gain::ResetValue
		
		; // branch::Index is automated
		
		; // branch20::Index is automated
		
		;                                     // ladder1::Frequency is automated
		;                                     // ladder1::Q is automated
		ladder1.setParameterT(2, 0.);         // filters::ladder::Gain
		ladder1.setParameterT(3, 0.00683656); // filters::ladder::Smoothing
		ladder1.setParameterT(4, 0.);         // filters::ladder::Mode
		ladder1.setParameterT(5, 1.);         // filters::ladder::Enabled
		
		;                                 // svf::Frequency is automated
		;                                 // svf::Q is automated
		svf.setParameterT(2, 0.);         // filters::svf::Gain
		svf.setParameterT(3, 0.00171344); // filters::svf::Smoothing
		svf.setParameterT(4, 1.);         // filters::svf::Mode
		svf.setParameterT(5, 1.);         // filters::svf::Enabled
		
		;                                     // ladder2::Frequency is automated
		;                                     // ladder2::Q is automated
		ladder2.setParameterT(2, 0.);         // filters::ladder::Gain
		ladder2.setParameterT(3, 0.00598922); // filters::ladder::Smoothing
		ladder2.setParameterT(4, 0.);         // filters::ladder::Mode
		ladder2.setParameterT(5, 1.);         // filters::ladder::Enabled
		
		;                            // svf1::Frequency is automated
		;                            // svf1::Q is automated
		svf1.setParameterT(2, 0.);   // filters::svf::Gain
		svf1.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf1.setParameterT(4, 1.);   // filters::svf::Mode
		svf1.setParameterT(5, 1.);   // filters::svf::Enabled
		
		; // branch21::Index is automated
		
		;                               // svf_eq1::Frequency is automated
		;                               // svf_eq1::Q is automated
		;                               // svf_eq1::Gain is automated
		svf_eq1.setParameterT(3, 0.01); // filters::svf_eq::Smoothing
		svf_eq1.setParameterT(4, 0.);   // filters::svf_eq::Mode
		svf_eq1.setParameterT(5, 1.);   // filters::svf_eq::Enabled
		
		;                                    // svf_eq::Frequency is automated
		;                                    // svf_eq::Q is automated
		;                                    // svf_eq::Gain is automated
		svf_eq.setParameterT(3, 0.00683875); // filters::svf_eq::Smoothing
		svf_eq.setParameterT(4, 3.);         // filters::svf_eq::Mode
		svf_eq.setParameterT(5, 1.);         // filters::svf_eq::Enabled
		
		;                               // svf_eq2::Frequency is automated
		;                               // svf_eq2::Q is automated
		;                               // svf_eq2::Gain is automated
		svf_eq2.setParameterT(3, 0.01); // filters::svf_eq::Smoothing
		svf_eq2.setParameterT(4, 2.);   // filters::svf_eq::Mode
		svf_eq2.setParameterT(5, 1.);   // filters::svf_eq::Enabled
		
		;                                     // svf_eq3::Frequency is automated
		;                                     // svf_eq3::Q is automated
		;                                     // svf_eq3::Gain is automated
		svf_eq3.setParameterT(3, 0.00683875); // filters::svf_eq::Smoothing
		svf_eq3.setParameterT(4, 3.);         // filters::svf_eq::Mode
		svf_eq3.setParameterT(5, 1.);         // filters::svf_eq::Enabled
		
		; // branch22::Index is automated
		
		; // faust4::aN is automated
		; // faust4::del is automated
		
		;                                // one_pole::Frequency is automated
		;                                // one_pole::Q is automated
		one_pole.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		;                                      // allpass1::Frequency is automated
		;                                      // allpass1::Q is automated
		allpass1.setParameterT(2, 0.);         // filters::allpass::Gain
		allpass1.setParameterT(3, 0.00774579); // filters::allpass::Smoothing
		allpass1.setParameterT(4, 0.);         // filters::allpass::Mode
		allpass1.setParameterT(5, 1.);         // filters::allpass::Enabled
		
		;                                 // one_pole1::Frequency is automated
		;                                 // one_pole1::Q is automated
		one_pole1.setParameterT(2, 0.);   // filters::one_pole::Gain
		one_pole1.setParameterT(3, 0.01); // filters::one_pole::Smoothing
		one_pole1.setParameterT(4, 0.);   // filters::one_pole::Mode
		one_pole1.setParameterT(5, 1.);   // filters::one_pole::Enabled
		
		tanh1.setParameterT(0, 0.106592); // math::tanh::Value
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 17.1);  // core::gain::Smoothing
		gain1.setParameterT(2, -100.); // core::gain::ResetValue
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 0.593071);
		this->setParameterT(2, 0.337211);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 0.543393);
		this->setParameterT(5, 2.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, -0.028125);
		this->setParameterT(8, 0.);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 1.);
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
		
		this->getT(0).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // HpLp_impl::global_cable3_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // HpLp_impl::global_cable11_t<NV>
		this->getT(0).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // HpLp_impl::global_cable10_t<NV>
		this->getT(0).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // HpLp_impl::global_cable6_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // HpLp_impl::global_cable13_t<NV>
		this->getT(0).getT(1).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // HpLp_impl::global_cable14_t<NV>
		this->getT(0).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // HpLp_impl::global_cable7_t<NV>
		this->getT(0).getT(2).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // HpLp_impl::global_cable15_t<NV>
		this->getT(0).getT(2).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // HpLp_impl::global_cable16_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).setExternalData(b, index); // HpLp_impl::sliderbank3_t<NV>
		this->getT(0).getT(0).getT(2).setExternalData(b, index); // HpLp_impl::peak3_t<NV>
		this->getT(0).getT(1).getT(0).setExternalData(b, index); // HpLp_impl::sliderbank4_t<NV>
		this->getT(0).getT(1).getT(2).setExternalData(b, index); // HpLp_impl::peak4_t<NV>
		this->getT(0).getT(2).getT(0).setExternalData(b, index); // HpLp_impl::sliderbank5_t<NV>
		this->getT(0).getT(2).getT(2).setExternalData(b, index); // HpLp_impl::peak5_t<NV>
		this->getT(1).getT(0).getT(1).setExternalData(b, index); // HpLp_impl::cable_table_t<NV>
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
using HpLp = wrap::node<HpLp_impl::instance<NV>>;
}


