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
using midi5_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi5_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using midi_cc4_t = control::midi_cc<parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain62_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc4_t<NV>>, 
                                   math::add<NV>, 
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

template <int NV> using midi4_t = midi5_t<NV>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi4_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc3_t = midi_cc4_t<NV>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc3_t<NV>>, 
                                   math::add<NV>, 
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

DECLARE_PARAMETER_RANGE_STEP(cable_table1_modRange, 
                             0., 
                             100., 
                             0.01);

template <int NV>
using cable_table1_mod = parameter::from0To1<project::Comb<NV>, 
                                             1, 
                                             cable_table1_modRange>;

struct cable_table1_t_data
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
using cable_table1_t = wrap::data<control::cable_table<cable_table1_mod<NV>>, 
                                  data::embedded::table<cable_table1_t_data>>;
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
using pma5_mod_10 = parameter::from0To1<filters::allpass<NV>, 
                                        0, 
                                        pma5_mod_7Range>;

template <int NV>
using pma5_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<math::div<NV>, 0>, 
                                  parameter::plain<math::mul<NV>, 0>, 
                                  parameter::plain<math::sub<NV>, 0>, 
                                  parameter::plain<math::pi<NV>, 0>, 
                                  parameter::plain<math::pi<NV>, 0>, 
                                  pma5_mod_5<NV>, 
                                  pma5_mod_6<NV>, 
                                  pma5_mod_7<NV>, 
                                  parameter::plain<project::klp<NV>, 1>, 
                                  parameter::plain<project::khp<NV>, 1>, 
                                  pma5_mod_10<NV>, 
                                  parameter::plain<cable_table1_t<NV>, 0>>;

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

template <int NV> using event_data_reader18_t = event_data_reader13_t<NV>;

template <int NV>
using chain69_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader18_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi6_t = midi5_t<NV>;

template <int NV>
using chain70_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi6_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc5_t = midi_cc4_t<NV>;

template <int NV>
using chain71_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc5_t<NV>>, 
                                   math::add<NV>, 
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
using pma7_mod_1 = parameter::from0To1<filters::allpass<NV>, 
                                       1, 
                                       pma7_mod_1Range>;

DECLARE_PARAMETER_RANGE_STEP(pma7_mod_3Range, 
                             0.5, 
                             10., 
                             0.01);

template <int NV>
using pma7_mod_3 = parameter::from0To1<project::khp<NV>, 
                                       0, 
                                       pma7_mod_3Range>;

template <int NV>
using pma7_mod_4 = parameter::from0To1<project::klp<NV>, 
                                       0, 
                                       pma7_mod_3Range>;

template <int NV>
using pma7_mod_5 = parameter::from0To1<filters::ring_mod<NV>, 
                                       1, 
                                       pma7_mod_1Range>;

template <int NV>
using pma7_mod_6 = parameter::from0To1<filters::one_pole<NV>, 
                                       0, 
                                       pma5_mod_7Range>;

template <int NV> using pma7_mod_7 = pma7_mod_6<NV>;

template <int NV> using pma7_mod_11 = pma7_mod_0<NV>;

template <int NV>
using pma7_mod = parameter::chain<ranges::Identity, 
                                  pma7_mod_0<NV>, 
                                  pma7_mod_1<NV>, 
                                  parameter::plain<project::Comb<NV>, 0>, 
                                  pma7_mod_3<NV>, 
                                  pma7_mod_4<NV>, 
                                  pma7_mod_5<NV>, 
                                  pma7_mod_6<NV>, 
                                  pma7_mod_7<NV>, 
                                  parameter::plain<math::fmod<NV>, 0>, 
                                  parameter::plain<math::sub<NV>, 0>, 
                                  parameter::plain<math::pi<NV>, 0>, 
                                  pma7_mod_11<NV>>;

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
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::pi<NV>>, 
                                   math::fmod<NV>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<2, fx::bitcrush<NV>>, 
                                   filters::one_pole<NV>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<2, fx::sampleandhold<NV>>, 
                                   filters::one_pole<NV>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filters::ring_mod<NV>>>;

template <int NV>
using no_midi1_t_ = container::chain<parameter::empty, 
                                     wrap::fix<2, project::klp<NV>>>;

template <int NV>
using no_midi1_t = wrap::no_midi<no_midi1_t_<NV>>;

template <int NV>
using no_midi2_t_ = container::chain<parameter::empty, 
                                     wrap::fix<2, project::khp<NV>>>;

template <int NV>
using no_midi2_t = wrap::no_midi<no_midi2_t_<NV>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table1_t<NV>>, 
                                   project::Comb<NV>>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filters::allpass<NV>>, 
                                   math::tanh<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain197_t<NV>>, 
                                    chain198_t<NV>, 
                                    chain199_t<NV>, 
                                    chain200_t<NV>, 
                                    chain37_t<NV>, 
                                    chain38_t<NV>, 
                                    chain39_t<NV>, 
                                    chain40_t<NV>, 
                                    no_midi1_t<NV>, 
                                    no_midi2_t<NV>, 
                                    chain43_t<NV>, 
                                    chain44_t<NV>>;

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
                             12., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(FxMope_0Range, 
                             0., 
                             11., 
                             1.);

template <int NV>
using FxMope_0 = parameter::from0To1<TransFX_impl::branch1_t<NV>, 
                                     0, 
                                     FxMope_0Range>;

template <int NV>
using FxMope = parameter::chain<FxMope_InputRange, FxMope_0<NV>>;

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
                                        bMod<NV>>;
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
		SNEX_METADATA_ENCODED_PARAMETERS(112)
		{
			0x005B, 0x0000, 0x4600, 0x4D78, 0x706F, 0x0065, 0x0000, 0x3F80, 
            0x0000, 0x4140, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x015B, 0x0000, 0x4600, 0x4D78, 0x7869, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0002, 0x0000, 0x694D, 0x4D78, 0x646F, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0003, 0x0000, 0x7846, 0x6150, 0x6172, 0x416D, 0x0000, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0004, 0x0000, 0x7846, 0x6150, 0x6172, 0x426D, 0x0000, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x0005, 0x0000, 0x6D41, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0006, 0x0000, 0x4D62, 0x646F, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000
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
		auto& midi5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(6).getT(0);               // TransFX_impl::midi5_t<NV>
		auto& add40 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(6).getT(1);               // math::add<NV>
		auto& gain48 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(6).getT(2);              // core::gain<NV>
		auto& chain62 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(7);                     // TransFX_impl::chain62_t<NV>
		auto& midi_cc4 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(7).getT(0);            // TransFX_impl::midi_cc4_t<NV>
		auto& add41 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(7).getT(1);               // math::add<NV>
		auto& gain49 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(7).getT(2);              // core::gain<NV>
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
		auto& midi4 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(6).getT(0);               // TransFX_impl::midi4_t<NV>
		auto& add32 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(6).getT(1);               // math::add<NV>
		auto& gain40 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(6).getT(2);              // core::gain<NV>
		auto& chain53 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(7);                     // TransFX_impl::chain53_t<NV>
		auto& midi_cc3 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(7).getT(0);            // TransFX_impl::midi_cc3_t<NV>
		auto& add33 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(7).getT(1);               // math::add<NV>
		auto& gain41 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(7).getT(2);              // core::gain<NV>
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
		auto& event_data_reader18 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(5).getT(0); // TransFX_impl::event_data_reader18_t<NV>
		auto& add47 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(5).getT(1);               // math::add<NV>
		auto& gain55 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(5).getT(2);              // core::gain<NV>
		auto& chain70 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(6);                     // TransFX_impl::chain70_t<NV>
		auto& midi6 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(6).getT(0);               // TransFX_impl::midi6_t<NV>
		auto& add48 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(6).getT(1);               // math::add<NV>
		auto& gain56 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(6).getT(2);              // core::gain<NV>
		auto& chain71 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(7);                     // TransFX_impl::chain71_t<NV>
		auto& midi_cc5 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(7).getT(0);            // TransFX_impl::midi_cc5_t<NV>
		auto& add49 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(7).getT(1);               // math::add<NV>
		auto& gain57 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(7).getT(2);              // core::gain<NV>
		auto& peak5 = this->getT(0).getT(0).getT(0).getT(2).getT(2);                               // TransFX_impl::peak5_t<NV>
		auto& pma7 = this->getT(0).getT(0).getT(0).getT(2).getT(3);                                // TransFX_impl::pma7_t<NV>
		auto& chain6 = this->getT(0).getT(1);                                                      // TransFX_impl::chain6_t<NV>
		auto& xfader1 = this->getT(0).getT(1).getT(0);                                             // TransFX_impl::xfader1_t<NV>
		auto& split1 = this->getT(0).getT(1).getT(1);                                              // TransFX_impl::split1_t<NV>
		auto& chain7 = this->getT(0).getT(1).getT(1).getT(0);                                      // TransFX_impl::chain7_t<NV>
		auto& gain2 = this->getT(0).getT(1).getT(1).getT(0).getT(0);                               // core::gain<NV>
		auto& chain34 = this->getT(0).getT(1).getT(1).getT(1);                                     // TransFX_impl::chain34_t<NV>
		auto& branch1 = this->getT(0).getT(1).getT(1).getT(1).getT(0);                             // TransFX_impl::branch1_t<NV>
		auto& chain197 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(0);                    // TransFX_impl::chain197_t<NV>
		auto& div = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(0).getT(0);                 // math::div<NV>
		auto& smoother2 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(0).getT(1);           // core::smoother<NV>
		auto& mono2stereo = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(0).getT(2);         // core::mono2stereo
		auto& chain198 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(1);                    // TransFX_impl::chain198_t<NV>
		auto& mul6 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(1).getT(0);                // math::mul<NV>
		auto& smoother3 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(1).getT(1);           // core::smoother<NV>
		auto& mono2stereo1 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(1).getT(2);        // core::mono2stereo
		auto& chain199 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(2);                    // TransFX_impl::chain199_t<NV>
		auto& sub = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(2).getT(0);                 // math::sub<NV>
		auto& pi2 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(2).getT(1);                 // math::pi<NV>
		auto& chain200 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(3);                    // TransFX_impl::chain200_t<NV>
		auto& pi3 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(3).getT(0);                 // math::pi<NV>
		auto& sub1 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(3).getT(1);                // math::sub<NV>
		auto& chain37 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(4);                     // TransFX_impl::chain37_t<NV>
		auto& pi7 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(4).getT(0);                 // math::pi<NV>
		auto& fmod2 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(4).getT(1);               // math::fmod<NV>
		auto& chain38 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(5);                     // TransFX_impl::chain38_t<NV>
		auto& bitcrush = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(5).getT(0);            // fx::bitcrush<NV>
		auto& one_pole1 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(5).getT(1);           // filters::one_pole<NV>
		auto& chain39 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(6);                     // TransFX_impl::chain39_t<NV>
		auto& sampleandhold = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(6).getT(0);       // fx::sampleandhold<NV>
		auto& one_pole2 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(6).getT(1);           // filters::one_pole<NV>
		auto& chain40 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(7);                     // TransFX_impl::chain40_t<NV>
		auto& ring_mod = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(7).getT(0);            // filters::ring_mod<NV>
		auto& no_midi1 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(8);                    // TransFX_impl::no_midi1_t<NV>
		auto& faust = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(8).getT(0);               // project::klp<NV>
		auto& no_midi2 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(9);                    // TransFX_impl::no_midi2_t<NV>
		auto& faust6 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(9).getT(0);              // project::khp<NV>
		auto& chain43 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(10);                    // TransFX_impl::chain43_t<NV>
		auto& cable_table1 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(10).getT(0);       // TransFX_impl::cable_table1_t<NV>
		auto& faust5 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(10).getT(1);             // project::Comb<NV>
		auto& chain44 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(11);                    // TransFX_impl::chain44_t<NV>
		auto& allpass1 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(11).getT(0);           // filters::allpass<NV>
		auto& tanh1 = this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(11).getT(1);              // math::tanh<NV>
		auto& gain32 = this->getT(0).getT(1).getT(1).getT(1).getT(1);                              // core::gain<NV>
		auto& one_pole = this->getT(0).getT(2);                                                    // filters::one_pole<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, branch1); // FxMope -> branch1::Index
		
		this->getParameterT(1).connectT(0, pma6); // FxMix -> pma6::Add
		
		this->getParameterT(2).connectT(0, pma6); // MixMod -> pma6::Multiply
		
		this->getParameterT(3).connectT(0, pma5); // FxParamA -> pma5::Add
		
		this->getParameterT(4).connectT(0, pma7); // FxParamB -> pma7::Add
		
		this->getParameterT(5).connectT(0, pma5); // Amod -> pma5::Multiply
		
		this->getParameterT(6).connectT(0, pma7); // bMod -> pma7::Multiply
		
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
		midi5.getParameter().connectT(0, add40);                             // midi5 -> add40::Value
		midi_cc4.getWrappedObject().getParameter().connectT(0, add41);       // midi_cc4 -> add41::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain2);               // xfader1 -> gain2::Gain
		xfader1_p.getParameterT(1).connectT(0, gain32);              // xfader1 -> gain32::Gain
		pma6.getWrappedObject().getParameter().connectT(0, xfader1); // pma6 -> xfader1::Value
		peak4.getParameter().connectT(0, pma6);                      // peak4 -> pma6::Value
		auto& sliderbank3_p = sliderbank3.getWrappedObject().getParameter();
		sliderbank3_p.getParameterT(0).connectT(0, gain34);                  // sliderbank3 -> gain34::Gain
		sliderbank3_p.getParameterT(1).connectT(0, gain35);                  // sliderbank3 -> gain35::Gain
		sliderbank3_p.getParameterT(2).connectT(0, gain36);                  // sliderbank3 -> gain36::Gain
		sliderbank3_p.getParameterT(3).connectT(0, gain37);                  // sliderbank3 -> gain37::Gain
		sliderbank3_p.getParameterT(4).connectT(0, gain38);                  // sliderbank3 -> gain38::Gain
		sliderbank3_p.getParameterT(5).connectT(0, gain39);                  // sliderbank3 -> gain39::Gain
		sliderbank3_p.getParameterT(6).connectT(0, gain40);                  // sliderbank3 -> gain40::Gain
		sliderbank3_p.getParameterT(7).connectT(0, gain41);                  // sliderbank3 -> gain41::Gain
		global_cable10.getWrappedObject().getParameter().connectT(0, add26); // global_cable10 -> add26::Value
		global_cable11.getWrappedObject().getParameter().connectT(0, add27); // global_cable11 -> add27::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add28); // global_cable12 -> add28::Value
		event_data_reader10.getParameter().connectT(0, add29);               // event_data_reader10 -> add29::Value
		event_data_reader11.getParameter().connectT(0, add30);               // event_data_reader11 -> add30::Value
		event_data_reader12.getParameter().connectT(0, add31);               // event_data_reader12 -> add31::Value
		midi4.getParameter().connectT(0, add32);                             // midi4 -> add32::Value
		midi_cc3.getWrappedObject().getParameter().connectT(0, add33);       // midi_cc3 -> add33::Value
		cable_table1.getWrappedObject().getParameter().connectT(0, faust5);  // cable_table1 -> faust5::del
		pma5.getWrappedObject().getParameter().connectT(0, div);             // pma5 -> div::Value
		pma5.getWrappedObject().getParameter().connectT(1, mul6);            // pma5 -> mul6::Value
		pma5.getWrappedObject().getParameter().connectT(2, sub);             // pma5 -> sub::Value
		pma5.getWrappedObject().getParameter().connectT(3, pi3);             // pma5 -> pi3::Value
		pma5.getWrappedObject().getParameter().connectT(4, pi7);             // pma5 -> pi7::Value
		pma5.getWrappedObject().getParameter().connectT(5, bitcrush);        // pma5 -> bitcrush::BitDepth
		pma5.getWrappedObject().getParameter().connectT(6, sampleandhold);   // pma5 -> sampleandhold::Counter
		pma5.getWrappedObject().getParameter().connectT(7, ring_mod);        // pma5 -> ring_mod::Frequency
		pma5.getWrappedObject().getParameter().connectT(8, faust);           // pma5 -> faust::freq
		pma5.getWrappedObject().getParameter().connectT(9, faust6);          // pma5 -> faust6::freq
		pma5.getWrappedObject().getParameter().connectT(10, allpass1);       // pma5 -> allpass1::Frequency
		pma5.getWrappedObject().getParameter().connectT(11, cable_table1);   // pma5 -> cable_table1::Value
		peak3.getParameter().connectT(0, pma5);                              // peak3 -> pma5::Value
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
		event_data_reader18.getParameter().connectT(0, add47);               // event_data_reader18 -> add47::Value
		midi6.getParameter().connectT(0, add48);                             // midi6 -> add48::Value
		midi_cc5.getWrappedObject().getParameter().connectT(0, add49);       // midi_cc5 -> add49::Value
		pma7.getWrappedObject().getParameter().connectT(0, smoother2);       // pma7 -> smoother2::SmoothingTime
		pma7.getWrappedObject().getParameter().connectT(1, allpass1);        // pma7 -> allpass1::Q
		pma7.getWrappedObject().getParameter().connectT(2, faust5);          // pma7 -> faust5::aN
		pma7.getWrappedObject().getParameter().connectT(3, faust6);          // pma7 -> faust6::Q
		pma7.getWrappedObject().getParameter().connectT(4, faust);           // pma7 -> faust::Q
		pma7.getWrappedObject().getParameter().connectT(5, ring_mod);        // pma7 -> ring_mod::Q
		pma7.getWrappedObject().getParameter().connectT(6, one_pole2);       // pma7 -> one_pole2::Frequency
		pma7.getWrappedObject().getParameter().connectT(7, one_pole1);       // pma7 -> one_pole1::Frequency
		pma7.getWrappedObject().getParameter().connectT(8, fmod2);           // pma7 -> fmod2::Value
		pma7.getWrappedObject().getParameter().connectT(9, sub1);            // pma7 -> sub1::Value
		pma7.getWrappedObject().getParameter().connectT(10, pi2);            // pma7 -> pi2::Value
		pma7.getWrappedObject().getParameter().connectT(11, smoother3);      // pma7 -> smoother3::SmoothingTime
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
		
		event_data_reader15.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader15.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add39::Value is automated
		
		;                             // gain47::Gain is automated
		gain47.setParameterT(1, 20.); // core::gain::Smoothing
		gain47.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add40::Value is automated
		
		;                             // gain48::Gain is automated
		gain48.setParameterT(1, 20.); // core::gain::Smoothing
		gain48.setParameterT(2, 0.);  // core::gain::ResetValue
		
		midi_cc4.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc4.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc4.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add41::Value is automated
		
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
		
		event_data_reader12.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader12.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add31::Value is automated
		
		;                             // gain39::Gain is automated
		gain39.setParameterT(1, 20.); // core::gain::Smoothing
		gain39.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add32::Value is automated
		
		;                             // gain40::Gain is automated
		gain40.setParameterT(1, 20.); // core::gain::Smoothing
		gain40.setParameterT(2, 0.);  // core::gain::ResetValue
		
		midi_cc3.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc3.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc3.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add33::Value is automated
		
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
		
		event_data_reader18.setParameterT(0, 2.); // routing::event_data_reader::SlotIndex
		event_data_reader18.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add47::Value is automated
		
		;                             // gain55::Gain is automated
		gain55.setParameterT(1, 20.); // core::gain::Smoothing
		gain55.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // add48::Value is automated
		
		;                             // gain56::Gain is automated
		gain56.setParameterT(1, 20.); // core::gain::Smoothing
		gain56.setParameterT(2, 0.);  // core::gain::ResetValue
		
		midi_cc5.setParameterT(0, 1.); // control::midi_cc::CCNumber
		midi_cc5.setParameterT(1, 0.); // control::midi_cc::EnableMPE
		midi_cc5.setParameterT(2, 0.); // control::midi_cc::DefaultValue
		
		; // add49::Value is automated
		
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
		
		; // div::Value is automated
		
		;                               // smoother2::SmoothingTime is automated
		smoother2.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		; // mul6::Value is automated
		
		;                               // smoother3::SmoothingTime is automated
		smoother3.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		; // sub::Value is automated
		
		; // pi2::Value is automated
		
		; // pi3::Value is automated
		
		; // sub1::Value is automated
		
		; // pi7::Value is automated
		
		; // fmod2::Value is automated
		
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
		
		;                                    // ring_mod::Frequency is automated
		;                                    // ring_mod::Q is automated
		ring_mod.setParameterT(2, -4.44825); // filters::ring_mod::Gain
		ring_mod.setParameterT(3, 0.01);     // filters::ring_mod::Smoothing
		ring_mod.setParameterT(4, 0.);       // filters::ring_mod::Mode
		ring_mod.setParameterT(5, 1.);       // filters::ring_mod::Enabled
		
		; // faust::Q is automated
		; // faust::freq is automated
		
		; // faust6::Q is automated
		; // faust6::freq is automated
		
		; // cable_table1::Value is automated
		
		; // faust5::aN is automated
		; // faust5::del is automated
		
		;                                // allpass1::Frequency is automated
		;                                // allpass1::Q is automated
		allpass1.setParameterT(2, 0.);   // filters::allpass::Gain
		allpass1.setParameterT(3, 0.01); // filters::allpass::Smoothing
		allpass1.setParameterT(4, 0.);   // filters::allpass::Mode
		allpass1.setParameterT(5, 1.);   // filters::allpass::Enabled
		
		tanh1.setParameterT(0, 0.95891); // math::tanh::Value
		
		;                              // gain32::Gain is automated
		gain32.setParameterT(1, 20.);  // core::gain::Smoothing
		gain32.setParameterT(2, -20.); // core::gain::ResetValue
		
		one_pole.setParameterT(0, 50.1457); // filters::one_pole::Frequency
		one_pole.setParameterT(1, 1.);      // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);      // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01);    // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 1.);      // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 0.);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.);
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
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index);                  // TransFX_impl::sliderbank4_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index);                  // TransFX_impl::peak4_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);                  // TransFX_impl::sliderbank3_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(2).setExternalData(b, index);                  // TransFX_impl::peak3_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).setExternalData(b, index);                  // TransFX_impl::sliderbank5_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(2).setExternalData(b, index);                  // TransFX_impl::peak5_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).getT(0).getT(10).getT(0).setExternalData(b, index); // TransFX_impl::cable_table1_t<NV>
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


