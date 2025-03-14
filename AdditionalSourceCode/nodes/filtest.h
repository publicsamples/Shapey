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
using ahdsr_multimod = parameter::list<parameter::plain<math::add<NV>, 0>, 
                                       parameter::empty>;

template <int NV>
using ahdsr_t = wrap::no_data<envelope::ahdsr<NV, ahdsr_multimod<NV>>>;

DECLARE_PARAMETER_RANGE_SKEW(pma3_modRange, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using pma3_mod = parameter::from0To1<core::gain<NV>, 
                                     0, 
                                     pma3_modRange>;

template <int NV>
using pma3_t = control::pma<NV, pma3_mod<NV>>;
DECLARE_PARAMETER_RANGE(cable_table2_modRange, 
                        5.55112e-17, 
                        1.);

template <int NV>
using cable_table2_mod = parameter::from0To1<pma3_t<NV>, 
                                             2, 
                                             cable_table2_modRange>;

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
using split7_t = container::split<parameter::empty, 
                                  wrap::fix<1, pma3_t<NV>>>;

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
                                     parameter::plain<math::add<NV>, 0>>;

template <int NV>
using minmax1_t = control::minmax<NV, minmax1_mod<NV>>;
template <int NV>
using peak2_t = wrap::mod<parameter::plain<minmax1_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::add<NV>>, 
                                  cable_table2_t<NV>, 
                                  split7_t<NV>, 
                                  core::gain<NV>, 
                                  peak2_t<NV>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, ahdsr_t<NV>>, 
                                   chain2_t<NV>, 
                                   minmax1_t<NV>>;

template <int NV> using ahdsr2_multimod = ahdsr_multimod<NV>;

template <int NV>
using ahdsr2_t = wrap::data<envelope::ahdsr<NV, ahdsr2_multimod<NV>>, 
                            data::external::displaybuffer<1>>;

template <int NV> using pma10_mod = pma3_mod<NV>;

template <int NV>
using pma10_t = control::pma<NV, pma10_mod<NV>>;
template <int NV>
using cable_table3_mod = parameter::from0To1<pma10_t<NV>, 
                                             2, 
                                             cable_table2_modRange>;

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

template <int NV>
using split8_t = container::split<parameter::empty, 
                                  wrap::fix<1, pma10_t<NV>>>;

template <int NV> using minmax2_mod = minmax1_mod<NV>;

template <int NV>
using minmax2_t = control::minmax<NV, minmax2_mod<NV>>;
template <int NV>
using peak4_t = wrap::mod<parameter::plain<minmax2_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, math::add<NV>>, 
                                  cable_table3_t<NV>, 
                                  split8_t<NV>, 
                                  core::gain<NV>, 
                                  peak4_t<NV>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, ahdsr2_t<NV>>, 
                                   chain3_t<NV>, 
                                   minmax2_t<NV>>;

template <int NV>
using midi2_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<pma3_t<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>>;

template <int NV>
using midi2_t = wrap::mod<midi2_mod<NV>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using midi3_mod = parameter::chain<ranges::Identity, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<pma10_t<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>>;

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
using global_cable2_t_index = runtime_target::indexers::fix_hash<-1797510589>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable2_t<NV>>, 
                                   math::add<NV>>;
using global_cable3_t_index = runtime_target::indexers::fix_hash<-1797510588>;

template <int NV>
using global_cable3_t = routing::global_cable<global_cable3_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable3_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using chain26_t = chain23_t<NV>;

template <int NV> using chain29_t = chain23_t<NV>;

template <int NV> using chain30_t = chain23_t<NV>;
template <int NV>
using branch4_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain23_t<NV>>, 
                                    chain24_t<NV>, 
                                    chain28_t<NV>, 
                                    chain19_t<NV>, 
                                    chain22_t<NV>, 
                                    chain21_t<NV>, 
                                    chain20_t<NV>, 
                                    chain26_t<NV>, 
                                    chain29_t<NV>, 
                                    chain30_t<NV>>;

template <int NV>
using oscillator8_t = wrap::no_data<core::oscillator<NV>>;

template <int NV>
using pma_mod = parameter::chain<ranges::Identity, 
                                 parameter::plain<oscillator8_t<NV>, 5>, 
                                 parameter::plain<math::mul<NV>, 0>>;

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
using global_cable6_t_index = global_cable2_t_index;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable6_t<NV>>, 
                                   math::add<NV>>;
using global_cable7_t_index = global_cable3_t_index;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable7_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using chain44_t = chain23_t<NV>;

template <int NV> using chain45_t = chain23_t<NV>;

template <int NV> using chain46_t = chain23_t<NV>;
template <int NV>
using branch7_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain38_t<NV>>, 
                                    chain39_t<NV>, 
                                    chain47_t<NV>, 
                                    chain40_t<NV>, 
                                    chain41_t<NV>, 
                                    chain42_t<NV>, 
                                    chain43_t<NV>, 
                                    chain44_t<NV>, 
                                    chain45_t<NV>, 
                                    chain46_t<NV>>;

template <int NV>
using file_player_t = wrap::data<core::file_player<NV>, 
                                 data::external::audiofile<0>>;

template <int NV>
using minmax_t = control::minmax<NV, 
                                 parameter::plain<oscillator8_t<NV>, 2>>;
DECLARE_PARAMETER_RANGE_STEP(pma4_mod_0Range, 
                             0., 
                             2., 
                             0.01);

template <int NV>
using pma4_mod_0 = parameter::from0To1<file_player_t<NV>, 
                                       3, 
                                       pma4_mod_0Range>;

template <int NV>
using pma4_mod = parameter::chain<ranges::Identity, 
                                  pma4_mod_0<NV>, 
                                  parameter::plain<minmax_t<NV>, 0>>;

template <int NV>
using pma4_t = control::pma<NV, pma4_mod<NV>>;
template <int NV>
using input_toggle_t = control::input_toggle<parameter::plain<pma4_t<NV>, 2>>;
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
using global_cable14_t_index = global_cable2_t_index;

template <int NV>
using global_cable14_t = routing::global_cable<global_cable14_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable14_t<NV>>, 
                                   math::add<NV>>;
using global_cable15_t_index = global_cable3_t_index;

template <int NV>
using global_cable15_t = routing::global_cable<global_cable15_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain69_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable15_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using chain70_t = chain23_t<NV>;

template <int NV> using chain71_t = chain23_t<NV>;

template <int NV> using chain72_t = chain23_t<NV>;
template <int NV>
using branch9_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain64_t<NV>>, 
                                    chain65_t<NV>, 
                                    chain114_t<NV>, 
                                    chain66_t<NV>, 
                                    chain67_t<NV>, 
                                    chain68_t<NV>, 
                                    chain69_t<NV>, 
                                    chain70_t<NV>, 
                                    chain71_t<NV>, 
                                    chain72_t<NV>>;

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
using global_cable18_t_index = global_cable2_t_index;

template <int NV>
using global_cable18_t = routing::global_cable<global_cable18_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain78_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable18_t<NV>>, 
                                   math::add<NV>>;
using global_cable19_t_index = global_cable3_t_index;

template <int NV>
using global_cable19_t = routing::global_cable<global_cable19_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain79_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable19_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using chain80_t = chain23_t<NV>;

template <int NV> using chain81_t = chain23_t<NV>;

template <int NV> using chain82_t = chain23_t<NV>;
template <int NV>
using branch10_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain74_t<NV>>, 
                                     chain75_t<NV>, 
                                     chain115_t<NV>, 
                                     chain76_t<NV>, 
                                     chain77_t<NV>, 
                                     chain78_t<NV>, 
                                     chain79_t<NV>, 
                                     chain80_t<NV>, 
                                     chain81_t<NV>, 
                                     chain82_t<NV>>;

template <int NV> using xfader_c0 = pma3_mod<NV>;

template <int NV> using xfader_c1 = pma3_mod<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, xfader_c1<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::linear>;
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
using global_cable22_t_index = global_cable2_t_index;

template <int NV>
using global_cable22_t = routing::global_cable<global_cable22_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain89_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable22_t<NV>>, 
                                   math::add<NV>>;
using global_cable23_t_index = global_cable3_t_index;

template <int NV>
using global_cable23_t = routing::global_cable<global_cable23_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain90_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable23_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using chain91_t = chain23_t<NV>;

template <int NV> using chain92_t = chain23_t<NV>;

template <int NV> using chain93_t = chain23_t<NV>;
template <int NV>
using branch11_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain85_t<NV>>, 
                                     chain86_t<NV>, 
                                     chain87_t<NV>, 
                                     chain88_t<NV>, 
                                     chain89_t<NV>, 
                                     chain90_t<NV>, 
                                     chain91_t<NV>, 
                                     chain92_t<NV>, 
                                     chain93_t<NV>>;

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
                             1., 
                             64., 
                             1.);

template <int NV>
using cable_table_mod = parameter::from0To1<project::g<NV>, 
                                            1, 
                                            cable_table_modRange>;

struct cable_table_t_data
{
	span<float, 512> data =
	{
		1.f, 0.996071f, 0.992141f, 0.988212f, 0.984283f, 0.980354f,
		0.976425f, 0.972495f, 0.968566f, 0.964637f, 0.960708f, 0.956778f,
		0.952849f, 0.94892f, 0.944991f, 0.941061f, 0.937132f, 0.933203f,
		0.929274f, 0.925344f, 0.921415f, 0.917486f, 0.913557f, 0.909627f,
		0.905698f, 0.901769f, 0.89784f, 0.89391f, 0.889981f, 0.886052f,
		0.882123f, 0.878193f, 0.874264f, 0.870335f, 0.866406f, 0.862476f,
		0.858547f, 0.854618f, 0.850689f, 0.84676f, 0.84283f, 0.838901f,
		0.834972f, 0.831043f, 0.827113f, 0.823184f, 0.819255f, 0.815326f,
		0.811396f, 0.807467f, 0.803538f, 0.799609f, 0.795679f, 0.79175f,
		0.787821f, 0.783892f, 0.779962f, 0.776033f, 0.772104f, 0.768175f,
		0.764245f, 0.760316f, 0.756387f, 0.752458f, 0.748528f, 0.744599f,
		0.74067f, 0.736741f, 0.732811f, 0.728882f, 0.724953f, 0.721024f,
		0.717095f, 0.713165f, 0.709236f, 0.705307f, 0.701378f, 0.697448f,
		0.693519f, 0.68959f, 0.685661f, 0.681731f, 0.677802f, 0.673873f,
		0.669944f, 0.666014f, 0.662085f, 0.658156f, 0.654227f, 0.650297f,
		0.646368f, 0.642439f, 0.63851f, 0.63458f, 0.630651f, 0.626722f,
		0.622793f, 0.618863f, 0.614934f, 0.611005f, 0.607076f, 0.603146f,
		0.599217f, 0.595288f, 0.591359f, 0.587429f, 0.5835f, 0.579571f,
		0.575642f, 0.571712f, 0.567783f, 0.563854f, 0.559925f, 0.555996f,
		0.552066f, 0.548137f, 0.544208f, 0.540279f, 0.536349f, 0.53242f,
		0.528491f, 0.524562f, 0.520632f, 0.516703f, 0.512774f, 0.508845f,
		0.504915f, 0.500986f, 0.497057f, 0.493128f, 0.489198f, 0.485269f,
		0.48134f, 0.477411f, 0.473481f, 0.469552f, 0.465623f, 0.461694f,
		0.457764f, 0.453835f, 0.449906f, 0.445977f, 0.442047f, 0.438118f,
		0.434189f, 0.43026f, 0.42633f, 0.422401f, 0.418472f, 0.414543f,
		0.410614f, 0.406684f, 0.402755f, 0.398826f, 0.394897f, 0.390967f,
		0.387038f, 0.383109f, 0.37918f, 0.37525f, 0.371321f, 0.367392f,
		0.363463f, 0.359533f, 0.355604f, 0.351675f, 0.347746f, 0.343816f,
		0.339887f, 0.335958f, 0.332029f, 0.328099f, 0.32417f, 0.320241f,
		0.316312f, 0.312382f, 0.308453f, 0.304524f, 0.300595f, 0.296665f,
		0.292736f, 0.288807f, 0.284878f, 0.280949f, 0.277019f, 0.27309f,
		0.269161f, 0.265231f, 0.261302f, 0.257373f, 0.253444f, 0.249515f,
		0.245585f, 0.241656f, 0.237727f, 0.233798f, 0.229868f, 0.225939f,
		0.22201f, 0.218081f, 0.214151f, 0.210222f, 0.206293f, 0.202364f,
		0.198434f, 0.194505f, 0.190576f, 0.186647f, 0.182717f, 0.178788f,
		0.174859f, 0.17093f, 0.167f, 0.163071f, 0.159142f, 0.155213f,
		0.151284f, 0.147354f, 0.143425f, 0.139496f, 0.135567f, 0.131637f,
		0.127708f, 0.123779f, 0.11985f, 0.11592f, 0.111991f, 0.108062f,
		0.104133f, 0.100203f, 0.0962741f, 0.0923448f, 0.0884156f, 0.0844864f,
		0.0805571f, 0.0766279f, 0.0726987f, 0.0687694f, 0.0648401f, 0.0609109f,
		0.0569817f, 0.0530524f, 0.0491231f, 0.0451939f, 0.0412647f, 0.0373355f,
		0.0334062f, 0.029477f, 0.0255477f, 0.0216185f, 0.0176892f, 0.0137599f,
		0.00983077f, 0.00590158f, 0.00197226f, 0.00194174f, 0.00584036f, 0.00973904f,
		0.0136377f, 0.0175363f, 0.0214351f, 0.0253338f, 0.0292324f, 0.0331311f,
		0.0370297f, 0.0409284f, 0.044827f, 0.0487257f, 0.0526244f, 0.0565231f,
		0.0604217f, 0.0643204f, 0.068219f, 0.0721177f, 0.0760163f, 0.079915f,
		0.0838137f, 0.0877124f, 0.091611f, 0.0955097f, 0.0994083f, 0.103307f,
		0.107206f, 0.111104f, 0.115003f, 0.118902f, 0.1228f, 0.126699f,
		0.130598f, 0.134496f, 0.138395f, 0.142294f, 0.146192f, 0.150091f,
		0.15399f, 0.157888f, 0.161787f, 0.165686f, 0.169584f, 0.173483f,
		0.177382f, 0.18128f, 0.185179f, 0.189078f, 0.192976f, 0.196875f,
		0.200774f, 0.204672f, 0.208571f, 0.21247f, 0.216368f, 0.220267f,
		0.224166f, 0.228064f, 0.231963f, 0.235862f, 0.23976f, 0.243659f,
		0.247558f, 0.251456f, 0.255355f, 0.259254f, 0.263152f, 0.267051f,
		0.27095f, 0.274848f, 0.278747f, 0.282646f, 0.286544f, 0.290443f,
		0.294342f, 0.29824f, 0.302139f, 0.306038f, 0.309936f, 0.313835f,
		0.317734f, 0.321632f, 0.325531f, 0.32943f, 0.333328f, 0.337227f,
		0.341126f, 0.345024f, 0.348923f, 0.352822f, 0.35672f, 0.360619f,
		0.364518f, 0.368416f, 0.372315f, 0.376214f, 0.380112f, 0.384011f,
		0.38791f, 0.391808f, 0.395707f, 0.399606f, 0.403504f, 0.407403f,
		0.411302f, 0.4152f, 0.419099f, 0.422997f, 0.426896f, 0.430795f,
		0.434694f, 0.438592f, 0.442491f, 0.446389f, 0.450288f, 0.454187f,
		0.458086f, 0.461984f, 0.465883f, 0.469782f, 0.47368f, 0.477579f,
		0.481477f, 0.485376f, 0.489275f, 0.493173f, 0.497072f, 0.500971f,
		0.50487f, 0.508768f, 0.512667f, 0.516565f, 0.520464f, 0.524363f,
		0.528261f, 0.53216f, 0.536059f, 0.539957f, 0.543856f, 0.547755f,
		0.551654f, 0.555552f, 0.559451f, 0.563349f, 0.567248f, 0.571147f,
		0.575045f, 0.578944f, 0.582843f, 0.586742f, 0.59064f, 0.594539f,
		0.598437f, 0.602336f, 0.606235f, 0.610133f, 0.614032f, 0.617931f,
		0.621829f, 0.625728f, 0.629627f, 0.633525f, 0.637424f, 0.641323f,
		0.645222f, 0.64912f, 0.653019f, 0.656917f, 0.660816f, 0.664715f,
		0.668613f, 0.672512f, 0.676411f, 0.680309f, 0.684208f, 0.688107f,
		0.692005f, 0.695904f, 0.699803f, 0.703701f, 0.7076f, 0.711499f,
		0.715397f, 0.719296f, 0.723195f, 0.727093f, 0.730992f, 0.734891f,
		0.738789f, 0.742688f, 0.746587f, 0.750485f, 0.754384f, 0.758283f,
		0.762181f, 0.76608f, 0.769979f, 0.773877f, 0.777776f, 0.781675f,
		0.785573f, 0.789472f, 0.793371f, 0.797269f, 0.801168f, 0.805067f,
		0.808965f, 0.812864f, 0.816763f, 0.820661f, 0.82456f, 0.828459f,
		0.832357f, 0.836256f, 0.840155f, 0.844053f, 0.847952f, 0.851851f,
		0.855749f, 0.859648f, 0.863547f, 0.867445f, 0.871344f, 0.875243f,
		0.879141f, 0.88304f, 0.886939f, 0.890837f, 0.894736f, 0.898635f,
		0.902533f, 0.906432f, 0.910331f, 0.914229f, 0.918128f, 0.922027f,
		0.925925f, 0.929824f, 0.933723f, 0.937621f, 0.94152f, 0.945419f,
		0.949317f, 0.953216f, 0.957115f, 0.961013f, 0.964912f, 0.968811f,
		0.972709f, 0.976608f, 0.980507f, 0.984405f, 0.988304f, 0.992203f,
		0.996101f, 1.f
	};
};

template <int NV>
using cable_table_t = wrap::data<control::cable_table<cable_table_mod<NV>>, 
                                 data::embedded::table<cable_table_t_data>>;

struct cable_table1_t_data
{
	span<float, 512> data =
	{
		1.f, 0.996055f, 0.992111f, 0.988166f, 0.984221f, 0.980276f,
		0.976332f, 0.972387f, 0.968442f, 0.964498f, 0.960553f, 0.956608f,
		0.952663f, 0.948719f, 0.944774f, 0.940829f, 0.936885f, 0.93294f,
		0.928995f, 0.92505f, 0.921106f, 0.917161f, 0.913216f, 0.909272f,
		0.905327f, 0.901382f, 0.897437f, 0.893493f, 0.889548f, 0.885603f,
		0.881659f, 0.877714f, 0.873769f, 0.869824f, 0.86588f, 0.861935f,
		0.85799f, 0.854046f, 0.850101f, 0.846156f, 0.842211f, 0.838267f,
		0.834322f, 0.830377f, 0.826433f, 0.822488f, 0.818543f, 0.814599f,
		0.810654f, 0.806709f, 0.802764f, 0.79882f, 0.794875f, 0.79093f,
		0.786986f, 0.783041f, 0.779096f, 0.775151f, 0.771207f, 0.767262f,
		0.763317f, 0.759373f, 0.755428f, 0.751483f, 0.747538f, 0.743594f,
		0.739649f, 0.735704f, 0.73176f, 0.727815f, 0.72387f, 0.719925f,
		0.715981f, 0.712036f, 0.708091f, 0.704147f, 0.700202f, 0.696257f,
		0.692312f, 0.688368f, 0.684423f, 0.680478f, 0.676534f, 0.672589f,
		0.668644f, 0.664699f, 0.660755f, 0.65681f, 0.652865f, 0.648921f,
		0.644976f, 0.641031f, 0.637087f, 0.633142f, 0.629197f, 0.625252f,
		0.621308f, 0.617363f, 0.613418f, 0.609473f, 0.605529f, 0.601584f,
		0.597639f, 0.593695f, 0.58975f, 0.585805f, 0.58186f, 0.577916f,
		0.573971f, 0.570026f, 0.566082f, 0.562137f, 0.558192f, 0.554247f,
		0.550303f, 0.546358f, 0.542413f, 0.538469f, 0.534524f, 0.530579f,
		0.526635f, 0.52269f, 0.518745f, 0.5148f, 0.510856f, 0.506911f,
		0.502966f, 0.499022f, 0.495077f, 0.491132f, 0.487187f, 0.483243f,
		0.479298f, 0.475353f, 0.471409f, 0.467464f, 0.463519f, 0.459574f,
		0.45563f, 0.451685f, 0.44774f, 0.443796f, 0.439851f, 0.435906f,
		0.431961f, 0.428017f, 0.424072f, 0.420127f, 0.416183f, 0.412238f,
		0.408293f, 0.404348f, 0.400404f, 0.396459f, 0.392514f, 0.38857f,
		0.384625f, 0.38068f, 0.376735f, 0.372791f, 0.368846f, 0.364901f,
		0.360957f, 0.357012f, 0.353067f, 0.349122f, 0.345178f, 0.341233f,
		0.337288f, 0.333344f, 0.329399f, 0.325454f, 0.321509f, 0.317565f,
		0.31362f, 0.309675f, 0.305731f, 0.301786f, 0.297841f, 0.293896f,
		0.289952f, 0.286007f, 0.282062f, 0.278118f, 0.274173f, 0.270228f,
		0.266283f, 0.262339f, 0.258394f, 0.254449f, 0.250505f, 0.24656f,
		0.242615f, 0.238671f, 0.234726f, 0.230781f, 0.226836f, 0.222892f,
		0.218947f, 0.215002f, 0.211058f, 0.207113f, 0.203168f, 0.199223f,
		0.195279f, 0.191334f, 0.187389f, 0.183444f, 0.1795f, 0.175555f,
		0.17161f, 0.167666f, 0.163721f, 0.159776f, 0.155832f, 0.151887f,
		0.147942f, 0.143997f, 0.140053f, 0.136108f, 0.132163f, 0.128219f,
		0.124274f, 0.120329f, 0.116384f, 0.11244f, 0.108495f, 0.10455f,
		0.100606f, 0.0966609f, 0.0927162f, 0.0887714f, 0.0848268f, 0.0808821f,
		0.0769373f, 0.0729926f, 0.0690479f, 0.0651032f, 0.0611584f, 0.0572137f,
		0.0532691f, 0.0493243f, 0.0453796f, 0.0414349f, 0.0374902f, 0.0335455f,
		0.0296007f, 0.0256561f, 0.0217113f, 0.0177667f, 0.0138219f, 0.00987715f,
		0.00593251f, 0.00198787f, 0.0019266f, 0.00581014f, 0.00969368f, 0.0135772f,
		0.0174608f, 0.0213443f, 0.025228f, 0.0291115f, 0.032995f, 0.0368786f,
		0.0407621f, 0.0446457f, 0.0485292f, 0.0524127f, 0.0562964f, 0.0601799f,
		0.0640635f, 0.067947f, 0.0718306f, 0.0757141f, 0.0795977f, 0.0834812f,
		0.0873649f, 0.0912484f, 0.0951319f, 0.0990155f, 0.102899f, 0.106783f,
		0.110666f, 0.11455f, 0.118433f, 0.122317f, 0.1262f, 0.130084f,
		0.133967f, 0.137851f, 0.141735f, 0.145618f, 0.149502f, 0.153385f,
		0.157269f, 0.161152f, 0.165036f, 0.168919f, 0.172803f, 0.176686f,
		0.18057f, 0.184454f, 0.188337f, 0.192221f, 0.196104f, 0.199988f,
		0.203871f, 0.207755f, 0.211639f, 0.215522f, 0.219406f, 0.223289f,
		0.227173f, 0.231056f, 0.23494f, 0.238823f, 0.242707f, 0.246591f,
		0.250474f, 0.254358f, 0.258241f, 0.262125f, 0.266008f, 0.269892f,
		0.273775f, 0.277659f, 0.281543f, 0.285426f, 0.28931f, 0.293193f,
		0.297077f, 0.30096f, 0.304844f, 0.308727f, 0.312611f, 0.316494f,
		0.320378f, 0.324262f, 0.328145f, 0.332029f, 0.335912f, 0.339796f,
		0.343679f, 0.347563f, 0.351447f, 0.35533f, 0.359214f, 0.363097f,
		0.366981f, 0.370864f, 0.374748f, 0.378631f, 0.382515f, 0.386398f,
		0.390282f, 0.394166f, 0.398049f, 0.401933f, 0.405816f, 0.4097f,
		0.413583f, 0.417467f, 0.42135f, 0.425234f, 0.429118f, 0.433001f,
		0.436885f, 0.440768f, 0.444652f, 0.448535f, 0.452419f, 0.456302f,
		0.460186f, 0.46407f, 0.467953f, 0.471837f, 0.47572f, 0.479604f,
		0.483487f, 0.487371f, 0.491254f, 0.495138f, 0.499022f, 0.502905f,
		0.506789f, 0.510672f, 0.514556f, 0.518439f, 0.522323f, 0.526206f,
		0.53009f, 0.533974f, 0.537857f, 0.541741f, 0.545624f, 0.549508f,
		0.553391f, 0.557275f, 0.561158f, 0.565042f, 0.568925f, 0.572809f,
		0.576693f, 0.580576f, 0.58446f, 0.588343f, 0.592227f, 0.59611f,
		0.599994f, 0.603877f, 0.607761f, 0.611645f, 0.615528f, 0.619412f,
		0.623295f, 0.627179f, 0.631062f, 0.634946f, 0.638829f, 0.642713f,
		0.646597f, 0.65048f, 0.654364f, 0.658247f, 0.662131f, 0.666014f,
		0.669898f, 0.673781f, 0.677665f, 0.681549f, 0.685432f, 0.689316f,
		0.693199f, 0.697083f, 0.700966f, 0.70485f, 0.708733f, 0.712617f,
		0.716501f, 0.720384f, 0.724268f, 0.728151f, 0.732035f, 0.735918f,
		0.739802f, 0.743685f, 0.747569f, 0.751453f, 0.755336f, 0.75922f,
		0.763103f, 0.766987f, 0.77087f, 0.774754f, 0.778637f, 0.782521f,
		0.786404f, 0.790288f, 0.794172f, 0.798055f, 0.801939f, 0.805822f,
		0.809706f, 0.813589f, 0.817473f, 0.821356f, 0.82524f, 0.829124f,
		0.833007f, 0.836891f, 0.840774f, 0.844658f, 0.848541f, 0.852425f,
		0.856308f, 0.860192f, 0.864076f, 0.867959f, 0.871843f, 0.875726f,
		0.87961f, 0.883493f, 0.887377f, 0.89126f, 0.895144f, 0.899028f,
		0.902911f, 0.906795f, 0.910678f, 0.914562f, 0.918445f, 0.922329f,
		0.926212f, 0.930096f, 0.93398f, 0.937863f, 0.941747f, 0.94563f,
		0.949514f, 0.953397f, 0.957281f, 0.961165f, 0.965048f, 0.968932f,
		0.972815f, 0.976699f, 0.980582f, 0.984466f, 0.988349f, 0.992233f,
		0.996117f, 1.f
	};
};

template <int NV>
using cable_table1_t = wrap::data<control::cable_table<parameter::plain<project::granular<NV>, 0>>, 
                                  data::embedded::table<cable_table1_t_data>>;
DECLARE_PARAMETER_RANGE(smoothed_parameter1_mod_0Range, 
                        0.11, 
                        1.);

template <int NV>
using smoothed_parameter1_mod_0 = parameter::from0To1<math::expr<NV, custom::expr>, 
                                                      0, 
                                                      smoothed_parameter1_mod_0Range>;

DECLARE_PARAMETER_RANGE(smoothed_parameter1_mod_1Range, 
                        0.02, 
                        0.75);

template <int NV>
using smoothed_parameter1_mod_1 = parameter::from0To1<math::fmod<NV>, 
                                                      0, 
                                                      smoothed_parameter1_mod_1Range>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter1_mod_2Range, 
                             1., 
                             16., 
                             1.);

template <int NV>
using smoothed_parameter1_mod_2 = parameter::from0To1<core::phasor_fm<NV>, 
                                                      2, 
                                                      smoothed_parameter1_mod_2Range>;

DECLARE_PARAMETER_RANGE_SKEW(smoothed_parameter1_mod_4Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using smoothed_parameter1_mod_4 = parameter::from0To1<filters::ring_mod<NV>, 
                                                      0, 
                                                      smoothed_parameter1_mod_4Range>;

DECLARE_PARAMETER_RANGE(smoothed_parameter1_mod_5Range, 
                        0.01, 
                        1.);

template <int NV>
using smoothed_parameter1_mod_5 = parameter::from0To1<math::div<NV>, 
                                                      0, 
                                                      smoothed_parameter1_mod_5Range>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter1_mod_7Range, 
                             0.5, 
                             10., 
                             0.1);

template <int NV>
using smoothed_parameter1_mod_7 = parameter::from0To1<project::g<NV>, 
                                                      0, 
                                                      smoothed_parameter1_mod_7Range>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter1_mod_8Range, 
                             0.01, 
                             0.5, 
                             0.01);

template <int NV>
using smoothed_parameter1_mod_8 = parameter::from0To1<project::g<NV>, 
                                                      2, 
                                                      smoothed_parameter1_mod_8Range>;

DECLARE_PARAMETER_RANGE_STEP(smoothed_parameter1_mod_10Range, 
                             4., 
                             12000., 
                             0.001);

template <int NV>
using smoothed_parameter1_mod_10 = parameter::from0To1<project::granular<NV>, 
                                                       4, 
                                                       smoothed_parameter1_mod_10Range>;

template <int NV>
using smoothed_parameter1_mod = parameter::chain<ranges::Identity, 
                                                 smoothed_parameter1_mod_0<NV>, 
                                                 smoothed_parameter1_mod_1<NV>, 
                                                 smoothed_parameter1_mod_2<NV>, 
                                                 parameter::plain<math::mul<NV>, 0>, 
                                                 smoothed_parameter1_mod_4<NV>, 
                                                 smoothed_parameter1_mod_5<NV>, 
                                                 parameter::plain<cable_table_t<NV>, 0>, 
                                                 smoothed_parameter1_mod_7<NV>, 
                                                 smoothed_parameter1_mod_8<NV>, 
                                                 parameter::plain<project::granular<NV>, 2>, 
                                                 smoothed_parameter1_mod_10<NV>, 
                                                 parameter::plain<cable_table1_t<NV>, 0>>;

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
using global_cable26_t_index = global_cable2_t_index;

template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain99_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable26_t<NV>>, 
                                   math::add<NV>>;
using global_cable27_t_index = global_cable3_t_index;

template <int NV>
using global_cable27_t = routing::global_cable<global_cable27_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain100_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable27_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using chain101_t = chain23_t<NV>;

template <int NV> using chain102_t = chain23_t<NV>;

template <int NV> using chain103_t = chain23_t<NV>;
template <int NV>
using branch12_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain95_t<NV>>, 
                                     chain96_t<NV>, 
                                     chain117_t<NV>, 
                                     chain97_t<NV>, 
                                     chain98_t<NV>, 
                                     chain99_t<NV>, 
                                     chain100_t<NV>, 
                                     chain101_t<NV>, 
                                     chain102_t<NV>, 
                                     chain103_t<NV>>;

template <int NV>
using smoothed_parameter_mod = parameter::chain<ranges::Identity, 
                                                parameter::plain<math::add<NV>, 0>, 
                                                parameter::plain<wrap::no_process<math::add<NV>>, 0>>;

template <int NV>
using smoothed_parameter_t = wrap::mod<smoothed_parameter_mod<NV>, 
                                       control::smoothed_parameter<NV, smoothers::low_pass<NV>>>;
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
using global_cable30_t_index = global_cable2_t_index;

template <int NV>
using global_cable30_t = routing::global_cable<global_cable30_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain109_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable30_t<NV>>, 
                                    math::add<NV>>;
using global_cable31_t_index = global_cable3_t_index;

template <int NV>
using global_cable31_t = routing::global_cable<global_cable31_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain110_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable31_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using chain111_t = chain23_t<NV>;

template <int NV> using chain112_t = chain23_t<NV>;

template <int NV> using chain113_t = chain23_t<NV>;
template <int NV>
using branch13_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain105_t<NV>>, 
                                     chain106_t<NV>, 
                                     chain116_t<NV>, 
                                     chain107_t<NV>, 
                                     chain108_t<NV>, 
                                     chain109_t<NV>, 
                                     chain110_t<NV>, 
                                     chain111_t<NV>, 
                                     chain112_t<NV>, 
                                     chain113_t<NV>>;

template <int NV>
using pma9_mod_1 = parameter::from0To1<wrap::no_process<core::gain<NV>>, 
                                       0, 
                                       pma3_modRange>;

template <int NV> using pma9_mod_2 = pma9_mod_1<NV>;

template <int NV>
using pma9_mod = parameter::chain<ranges::Identity, 
                                  parameter::plain<math::mul<NV>, 0>, 
                                  pma9_mod_1<NV>, 
                                  pma9_mod_2<NV>, 
                                  parameter::plain<math::mul<NV>, 0>>;

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
using global_cable34_t_index = global_cable2_t_index;

template <int NV>
using global_cable34_t = routing::global_cable<global_cable34_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain124_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable34_t<NV>>, 
                                    math::add<NV>>;
using global_cable35_t_index = global_cable3_t_index;

template <int NV>
using global_cable35_t = routing::global_cable<global_cable35_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain125_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable35_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using chain126_t = chain23_t<NV>;

template <int NV> using chain127_t = chain23_t<NV>;

template <int NV> using chain128_t = chain23_t<NV>;
template <int NV>
using branch14_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain119_t<NV>>, 
                                     chain120_t<NV>, 
                                     chain121_t<NV>, 
                                     chain122_t<NV>, 
                                     chain123_t<NV>, 
                                     chain124_t<NV>, 
                                     chain125_t<NV>, 
                                     chain126_t<NV>, 
                                     chain127_t<NV>, 
                                     chain128_t<NV>>;

template <int NV>
using pma11_mod_0 = parameter::from0To1<filters::ladder<NV>, 
                                        0, 
                                        smoothed_parameter1_mod_4Range>;

template <int NV> using pma11_mod_1 = pma11_mod_0<NV>;

template <int NV> using pma11_mod_2 = pma11_mod_0<NV>;

template <int NV>
using pma11_mod = parameter::chain<ranges::Identity, 
                                   pma11_mod_0<NV>, 
                                   pma11_mod_1<NV>, 
                                   pma11_mod_2<NV>>;

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
using global_cable38_t_index = global_cable2_t_index;

template <int NV>
using global_cable38_t = routing::global_cable<global_cable38_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain135_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable38_t<NV>>, 
                                    math::add<NV>>;
using global_cable39_t_index = global_cable3_t_index;

template <int NV>
using global_cable39_t = routing::global_cable<global_cable39_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain136_t = container::chain<parameter::empty, 
                                    wrap::fix<1, global_cable39_t<NV>>, 
                                    math::add<NV>>;

template <int NV> using chain137_t = chain23_t<NV>;

template <int NV> using chain138_t = chain23_t<NV>;

template <int NV> using chain139_t = chain23_t<NV>;
template <int NV>
using branch15_t = container::branch<parameter::empty, 
                                     wrap::fix<1, chain130_t<NV>>, 
                                     chain131_t<NV>, 
                                     chain132_t<NV>, 
                                     chain133_t<NV>, 
                                     chain134_t<NV>, 
                                     chain135_t<NV>, 
                                     chain136_t<NV>, 
                                     chain137_t<NV>, 
                                     chain138_t<NV>, 
                                     chain139_t<NV>>;

template <int NV>
using pma12_mod_0 = parameter::from0To1<filters::svf<NV>, 
                                        0, 
                                        smoothed_parameter1_mod_4Range>;

template <int NV> using pma12_mod_1 = pma12_mod_0<NV>;

template <int NV> using pma12_mod_2 = pma12_mod_0<NV>;

template <int NV>
using pma12_mod = parameter::chain<ranges::Identity, 
                                   pma12_mod_0<NV>, 
                                   pma12_mod_1<NV>, 
                                   pma12_mod_2<NV>>;

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
                                  chain63_t<NV>, 
                                  chain73_t<NV>, 
                                  chain84_t<NV>, 
                                  chain94_t<NV>, 
                                  chain104_t<NV>, 
                                  chain118_t<NV>, 
                                  chain129_t<NV>>;

template <int NV>
using modchain1_t_ = container::chain<parameter::empty, 
                                      wrap::fix<1, split5_t<NV>>, 
                                      split6_t<NV>>;

template <int NV>
using modchain1_t = wrap::control_rate<modchain1_t_<NV>>;

using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::empty>>;

using chain49_t = chain31_t;

using chain32_t = chain31_t;

using chain35_t = chain31_t;

using chain36_t = chain31_t;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain36_t>, 
                                    fx::sampleandhold<NV>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<2, branch6_t<NV>>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain31_t>, 
                                    chain49_t, 
                                    chain32_t, 
                                    chain35_t, 
                                    chain33_t<NV>>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<2, minmax_t<NV>>, 
                                   oscillator8_t<NV>, 
                                   branch5_t<NV>>;

template <int NV>
using chain83_t = container::chain<parameter::empty, 
                                   wrap::fix<2, file_player_t<NV>>, 
                                   math::mul<NV>>;
template <int NV>
using branch1_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain48_t<NV>>, 
                                    chain83_t<NV>>;

using chain50_t = chain31_t;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<2, wrap::no_process<core::gain<NV>>>, 
                                   math::mul<NV>>;

template <int NV> using chain51_t = chain53_t<NV>;
template <int NV>
using branch16_t = container::branch<parameter::empty, 
                                     wrap::fix<2, chain50_t>, 
                                     chain53_t<NV>, 
                                     chain51_t<NV>>;
using oscilloscope_t = wrap::data<analyse::oscilloscope, 
                                  data::external::displaybuffer<0>>;

template <int NV>
using chain_t = container::chain<parameter::empty, 
                                 wrap::fix<2, core::gain<NV>>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr>>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, math::pi<NV>>, 
                                  math::pi<NV>, 
                                  math::pi<NV>, 
                                  math::pi<NV>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, wrap::no_process<math::sub<NV>>>, 
                                   split1_t<NV>, 
                                   math::mul<NV>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<2, wrap::no_process<math::pi<NV>>>, 
                                   math::fmod<NV>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<2, filters::ring_mod<NV>>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table_t<NV>>, 
                                   project::g<NV>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<2, cable_table1_t<NV>>, 
                                   project::granular<NV>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::div<NV>>>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::phasor_fm<NV>>>;
template <int NV>
using branch3_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain12_t<NV>>, 
                                    chain13_t<NV>, 
                                    chain15_t<NV>, 
                                    chain17_t<NV>, 
                                    chain14_t<NV>, 
                                    chain27_t<NV>, 
                                    chain16_t<NV>, 
                                    chain52_t<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<2, core::smoother<NV>>, 
                                  core::smoother<NV>>;

using multi1_t = container::multi<parameter::empty, 
                                  wrap::fix<2, core::empty>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<2, smoothed_parameter1_t<NV>>, 
                                  branch3_t<NV>, 
                                  split2_t<NV>, 
                                  multi1_t, 
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

using chain10_t = chain31_t;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<2, math::add<NV>>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, wrap::no_process<math::add<NV>>>>;
template <int NV>
using branch2_t = container::branch<parameter::empty, 
                                    wrap::fix<2, chain10_t>, 
                                    chain8_t<NV>, 
                                    chain11_t<NV>>;

using chain4_t = chain31_t;
template <int NV>
using file_player3_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<1>>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, file_player3_t<NV>>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<2, chain9_t<NV>>>;
template <int NV>
using file_player4_t = wrap::data<core::file_player<NV>, 
                                  data::external::audiofile<2>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, file_player4_t<NV>>>;
template <int NV>
using branch_t = container::branch<parameter::empty, 
                                   wrap::fix<2, chain4_t>, 
                                   chain5_t<NV>, 
                                   chain6_t<NV>>;
using oscilloscope1_t = wrap::data<analyse::oscilloscope, 
                                   data::external::displaybuffer<3>>;

template <int NV>
using frame2_block_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, smoothed_parameter_t<NV>>, 
                                         branch2_t<NV>, 
                                         branch_t<NV>, 
                                         oscilloscope1_t>;

template <int NV>
using frame2_block_t = wrap::frame<2, frame2_block_t_<NV>>;

template <int NV>
using sb1_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, filters::ladder<NV>>, 
                                filters::svf<NV>>;

template <int NV>
using sb1_t = bypass::smoothed<20, sb1_t_<NV>>;
template <int NV>
using switcher_c0 = parameter::bypass<sb1_t<NV>>;

template <int NV>
using sb2_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, filters::svf<NV>>, 
                                filters::ladder<NV>>;

template <int NV>
using sb2_t = bypass::smoothed<20, sb2_t_<NV>>;
template <int NV>
using switcher_c1 = parameter::bypass<sb2_t<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<2, filters::ladder<NV>>, 
                                  filters::svf<NV>>;

template <int NV>
using sb3_t_ = container::chain<parameter::empty, 
                                wrap::fix<2, split3_t<NV>>>;

template <int NV>
using sb3_t = bypass::smoothed<20, sb3_t_<NV>>;
template <int NV>
using switcher_c2 = parameter::bypass<sb3_t<NV>>;

template <int NV>
using switcher_multimod = parameter::list<switcher_c0<NV>, 
                                          switcher_c1<NV>, 
                                          switcher_c2<NV>>;

template <int NV>
using switcher_t = control::xfader<switcher_multimod<NV>, faders::switcher>;

template <int NV>
using sb_container_t = container::chain<parameter::empty, 
                                        wrap::fix<2, sb1_t<NV>>, 
                                        sb2_t<NV>, 
                                        sb3_t<NV>>;

template <int NV>
using softbypass_switch5_t = container::chain<parameter::empty, 
                                              wrap::fix<2, switcher_t<NV>>, 
                                              sb_container_t<NV>>;

template <int NV>
using ahdsr1_c0 = parameter::chain<ranges::Identity, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>, 
                                   parameter::plain<math::add<NV>, 0>>;

template <int NV>
using ahdsr1_c1 = parameter::chain<ranges::Identity, 
                                   parameter::plain<envelope::voice_manager, 0>, 
                                   parameter::plain<math::add<NV>, 0>>;

template <int NV>
using ahdsr1_multimod = parameter::list<ahdsr1_c0<NV>, ahdsr1_c1<NV>>;

template <int NV>
using ahdsr1_t = wrap::no_data<envelope::ahdsr<NV, ahdsr1_multimod<NV>>>;

namespace filtest_t_parameters
{
// Parameter list for filtest_impl::filtest_t ------------------------------------------------------

DECLARE_PARAMETER_RANGE_SKEW(PosSmooth_InputRange, 
                             0., 
                             2000., 
                             0.231378);
DECLARE_PARAMETER_RANGE_STEP(PosSmooth_0Range, 
                             0.1, 
                             1000., 
                             0.1);

template <int NV>
using PosSmooth_0 = parameter::from0To1<filtest_impl::smoothed_parameter_t<NV>, 
                                        1, 
                                        PosSmooth_0Range>;

template <int NV>
using PosSmooth = parameter::chain<PosSmooth_InputRange, PosSmooth_0<NV>>;

template <int NV>
using MathSmooth = parameter::chain<ranges::Identity, 
                                    parameter::plain<core::smoother<NV>, 0>, 
                                    parameter::plain<core::smoother<NV>, 0>>;

template <int NV>
using Blimey = parameter::from0To1<filtest_impl::pma_t<NV>, 
                                   2, 
                                   filtest_impl::cable_table2_modRange>;

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

DECLARE_PARAMETER_RANGE(Pitch_InputRange, 
                        -1, 
                        1);
template <int NV>
using Pitch_0 = parameter::from0To1<filtest_impl::pma1_t<NV>, 
                                    2, 
                                    filtest_impl::cable_table2_modRange>;

template <int NV>
using Pitch = parameter::chain<Pitch_InputRange, Pitch_0<NV>>;

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
                                     filtest_impl::cable_table2_modRange>;

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
using OscMode_1 = parameter::from0To1<filtest_impl::branch5_t<NV>, 
                                      0, 
                                      OscMode_0Range>;

template <int NV>
using OscMode = parameter::chain<OscMode_InputRange, 
                                 OscMode_0<NV>, 
                                 OscMode_1<NV>>;

template <int NV>
using AdjustMix = parameter::from0To1<filtest_impl::pma6_t<NV>, 
                                      2, 
                                      filtest_impl::cable_table2_modRange>;

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
                             8., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(AdjustMode_0Range, 
                             0., 
                             7., 
                             1.);

template <int NV>
using AdjustMode_0 = parameter::from0To1<filtest_impl::branch3_t<NV>, 
                                         0, 
                                         AdjustMode_0Range>;

template <int NV>
using AdjustMode = parameter::chain<AdjustMode_InputRange, AdjustMode_0<NV>>;

template <int NV>
using Adj = parameter::from0To1<filtest_impl::pma7_t<NV>, 
                                2, 
                                filtest_impl::cable_table2_modRange>;

DECLARE_PARAMETER_RANGE(AdjSrc_InputRange, 
                        1., 
                        10.);
DECLARE_PARAMETER_RANGE_STEP(AdjSrc_0Range, 
                             0., 
                             8., 
                             1.);

template <int NV>
using AdjSrc_0 = parameter::from0To1<filtest_impl::branch11_t<NV>, 
                                     0, 
                                     AdjSrc_0Range>;

template <int NV>
using AdjSrc = parameter::chain<AdjSrc_InputRange, AdjSrc_0<NV>>;

template <int NV>
using Position = parameter::from0To1<filtest_impl::pma8_t<NV>, 
                                     2, 
                                     filtest_impl::cable_table2_modRange>;

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

DECLARE_PARAMETER_RANGE_STEP(OutMode_InputRange, 
                             1., 
                             3., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(OutMode_0Range, 
                             0., 
                             2., 
                             1.);

template <int NV>
using OutMode_0 = parameter::from0To1<filtest_impl::branch_t<NV>, 
                                      0, 
                                      OutMode_0Range>;

template <int NV>
using OutMode_1 = parameter::from0To1<filtest_impl::branch2_t<NV>, 
                                      0, 
                                      OutMode_0Range>;

template <int NV>
using OutMode_2 = parameter::from0To1<filtest_impl::branch16_t<NV>, 
                                      0, 
                                      OutMode_0Range>;

template <int NV>
using OutMode = parameter::chain<OutMode_InputRange, 
                                 OutMode_0<NV>, 
                                 OutMode_1<NV>, 
                                 OutMode_2<NV>>;

template <int NV>
using Gain2 = parameter::from0To1<filtest_impl::pma9_t<NV>, 
                                  2, 
                                  filtest_impl::cable_table2_modRange>;

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
using EnvMod1_1 = parameter::from0To1<filtest_impl::pma3_t<NV>, 
                                      1, 
                                      filtest_impl::cable_table2_modRange>;

template <int NV>
using EnvMod1 = parameter::chain<ranges::Identity, 
                                 parameter::plain<filtest_impl::cable_table2_t<NV>, 0>, 
                                 EnvMod1_1<NV>>;

template <int NV>
using EnvMod2_1 = parameter::from0To1<filtest_impl::pma10_t<NV>, 
                                      1, 
                                      filtest_impl::cable_table2_modRange>;

template <int NV>
using EnvMod2 = parameter::chain<ranges::Identity, 
                                 parameter::plain<filtest_impl::cable_table3_t<NV>, 0>, 
                                 EnvMod2_1<NV>>;

DECLARE_PARAMETER_RANGE_SKEW(q_3Range, 
                             0.3, 
                             9.9, 
                             0.264718);

template <int NV>
using q_3 = parameter::from0To1<filters::ladder<NV>, 
                                1, 
                                q_3Range>;

template <int NV>
using q = parameter::chain<ranges::Identity, 
                           parameter::plain<filters::svf<NV>, 1>, 
                           parameter::plain<filters::ladder<NV>, 1>, 
                           parameter::plain<filters::svf<NV>, 1>, 
                           q_3<NV>, 
                           parameter::plain<filters::ladder<NV>, 1>, 
                           parameter::plain<filters::svf<NV>, 1>>;

template <int NV>
using LP = parameter::from0To1<filtest_impl::pma11_t<NV>, 
                               2, 
                               filtest_impl::cable_table2_modRange>;

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
                               filtest_impl::cable_table2_modRange>;

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
template <int NV>
using Fine = parameter::plain<filtest_impl::pma4_t<NV>, 
                              0>;
template <int NV>
using InputMode = parameter::plain<filtest_impl::branch1_t<NV>, 
                                   0>;
template <int NV>
using AdjustMixMod = parameter::plain<filtest_impl::pma6_t<NV>, 
                                      1>;
template <int NV>
using AdjMod = parameter::plain<filtest_impl::pma7_t<NV>, 
                                1>;
template <int NV>
using PosMod = parameter::plain<filtest_impl::pma8_t<NV>, 
                                1>;
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
using a2 = parameter::plain<filtest_impl::ahdsr2_t<NV>, 
                            0>;
template <int NV>
using h2 = parameter::plain<filtest_impl::ahdsr2_t<NV>, 
                            2>;
template <int NV>
using d2 = parameter::plain<filtest_impl::ahdsr2_t<NV>, 
                            3>;
template <int NV>
using s2 = parameter::plain<filtest_impl::ahdsr2_t<NV>, 
                            4>;
template <int NV>
using r2 = parameter::plain<filtest_impl::ahdsr2_t<NV>, 
                            5>;
template <int NV>
using AmpA = parameter::plain<filtest_impl::ahdsr1_t<NV>, 
                              0>;
template <int NV>
using AmpH = parameter::plain<filtest_impl::ahdsr1_t<NV>, 
                              2>;
template <int NV>
using AmpD = parameter::plain<filtest_impl::ahdsr1_t<NV>, 
                              3>;
template <int NV>
using AmpS = parameter::plain<filtest_impl::ahdsr1_t<NV>, 
                              4>;
template <int NV>
using AmpR = parameter::plain<filtest_impl::ahdsr1_t<NV>, 
                              5>;
template <int NV>
using FilterMode = parameter::plain<filtest_impl::switcher_t<NV>, 
                                    0>;
template <int NV>
using LpMod = parameter::plain<filtest_impl::pma11_t<NV>, 
                               1>;
template <int NV>
using HpMod = parameter::plain<filtest_impl::pma12_t<NV>, 
                               1>;
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
                                        Fine<NV>, 
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
                                        OutMode<NV>, 
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
                                        s2<NV>, 
                                        r2<NV>, 
                                        EnvMod2<NV>, 
                                        AmpA<NV>, 
                                        AmpH<NV>, 
                                        AmpD<NV>, 
                                        AmpS<NV>, 
                                        AmpR<NV>, 
                                        q<NV>, 
                                        FilterMode<NV>, 
                                        LP<NV>, 
                                        LpMod<NV>, 
                                        LpSrc<NV>, 
                                        HP<NV>, 
                                        HpMod<NV>, 
                                        HpSrc<NV>>;
}

template <int NV>
using filtest_t_ = container::chain<filtest_t_parameters::filtest_t_plist<NV>, 
                                    wrap::fix<2, modchain1_t<NV>>, 
                                    tempo_sync_t<NV>, 
                                    converter_t<NV>, 
                                    input_toggle_t<NV>, 
                                    pma4_t<NV>, 
                                    branch1_t<NV>, 
                                    branch16_t<NV>, 
                                    oscilloscope_t, 
                                    soft_bypass_t<NV>, 
                                    wrap::no_process<math::tanh<NV>>, 
                                    frame2_block_t<NV>, 
                                    softbypass_switch5_t<NV>, 
                                    ahdsr1_t<NV>, 
                                    envelope::voice_manager>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public filtest_impl::filtest_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 3;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 4;
		
		SNEX_METADATA_ID(filtest);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(874)
		{
			0x005B, 0x0000, 0x5400, 0x6D65, 0x6F70, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0042, 0x9800, 0x0041, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0001, 0x0000, 0x6F50, 0x5373, 0x6F6D, 0x746F, 0x0068, 0x0000, 
            0x0000, 0x0000, 0x44FA, 0x6667, 0x427C, 0xEE69, 0x3E6C, 0xCCCD, 
            0x3DCC, 0x025B, 0x0000, 0x4D00, 0x7461, 0x5368, 0x6F6D, 0x746F, 
            0x0068, 0x0000, 0x0000, 0x0000, 0x41C0, 0x0000, 0x0000, 0xEE69, 
            0x3E6C, 0xCCCD, 0x3DCC, 0x035B, 0x0000, 0x4200, 0x696C, 0x656D, 
            0x0079, 0x0000, 0x0000, 0x0000, 0x3F80, 0xE0E5, 0x3DC1, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x045B, 0x0000, 0x4200, 0x696C, 0x656D, 
            0x4D79, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0xC000, 
            0x0023, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0005, 0x0000, 0x6C42, 
            0x6D69, 0x7965, 0x6F4D, 0x5364, 0x6372, 0x0000, 0x8000, 0x003F, 
            0x2000, 0x0041, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0006, 0x0000, 0x6950, 0x6374, 0x0068, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0xBE77, 0xBA9F, 0x0000, 0x3F80, 0x0000, 0x0000, 0x075B, 
            0x0000, 0x5000, 0x7469, 0x6863, 0x6F4D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x23C0, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x085B, 0x0000, 0x5000, 0x7469, 0x6863, 0x7253, 0x0063, 0x0000, 
            0x3F80, 0x0000, 0x4120, 0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x095B, 0x0000, 0x4400, 0x7669, 0x6469, 0x0065, 0x0000, 
            0x3F80, 0x0000, 0x4190, 0x0000, 0x4190, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0A5B, 0x0000, 0x4400, 0x7669, 0x6F4D, 0x0064, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x23C0, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0B5B, 0x0000, 0x4400, 0x7669, 0x7253, 0x0063, 0x0000, 
            0x3F80, 0x0000, 0x4120, 0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0C5B, 0x0000, 0x5000, 0x7469, 0x6863, 0x7953, 0x636E, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x000D, 0x0000, 0x6946, 0x656E, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x7A3F, 0x83D3, 0x00BD, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x000E, 0x0000, 0x6E49, 0x7570, 0x4D74, 0x646F, 
            0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0F5B, 0x0000, 0x4F00, 0x6373, 0x6F4D, 
            0x6564, 0x0000, 0x8000, 0x003F, 0xA000, 0x0040, 0x0000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x5B3F, 0x0010, 0x0000, 0x6441, 0x756A, 
            0x7473, 0x694D, 0x0078, 0x0000, 0x0000, 0x0000, 0x3F80, 0x47AE, 
            0x3E61, 0x0000, 0x3F80, 0x0000, 0x0000, 0x115B, 0x0000, 0x4100, 
            0x6A64, 0x7375, 0x4D74, 0x7869, 0x6F4D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0xD99A, 0xBF1B, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x125B, 0x0000, 0x4100, 0x6A64, 0x7375, 0x4D74, 0x7869, 0x7253, 
            0x0063, 0x0000, 0x3F80, 0x0000, 0x4120, 0x0000, 0x4000, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x135B, 0x0000, 0x4100, 0x6A64, 0x7375, 
            0x4D74, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 0x4100, 0x0000, 
            0x4040, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x145B, 0x0000, 0x4100, 
            0x6A64, 0x0000, 0x0000, 0x0000, 0x8000, 0xC33F, 0x28F5, 0x003F, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0015, 0x0000, 0x6441, 0x4D6A, 
            0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0xC000, 0x0023, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0016, 0x0000, 0x6441, 0x536A, 
            0x6372, 0x0000, 0x8000, 0x003F, 0x2000, 0x6641, 0x0E86, 0x0041, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0017, 0x0000, 0x6F50, 0x6973, 
            0x6974, 0x6E6F, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0018, 0x0000, 0x6F50, 
            0x4D73, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0019, 0x0000, 0x6F50, 
            0x5373, 0x6372, 0x0000, 0x8000, 0x003F, 0x2000, 0x0041, 0x8000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x001A, 0x0000, 0x754F, 
            0x4D74, 0x646F, 0x0065, 0x0000, 0x3F80, 0x0000, 0x4040, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x1B5B, 0x0000, 0x4700, 
            0x6961, 0x326E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x001C, 0x0000, 0x6147, 
            0x6E69, 0x4D32, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0xB23F, 
            0x6190, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 0x001D, 0x0000, 
            0x6147, 0x6E69, 0x5332, 0x6372, 0x0000, 0x8000, 0x003F, 0x2000, 
            0x0041, 0x4000, 0x0040, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x001E, 
            0x0000, 0x3161, 0x0000, 0x0000, 0x0000, 0xEA60, 0x0046, 0x0000, 
            0x7200, 0x4A6A, 0xCD3E, 0xCCCC, 0x5B3D, 0x001F, 0x0000, 0x3168, 
            0x0000, 0x0000, 0x0000, 0x1C40, 0x0046, 0xE000, 0x7240, 0x4A6A, 
            0xCD3E, 0xCCCC, 0x5B3D, 0x0020, 0x0000, 0x3164, 0x0000, 0x0000, 
            0x0000, 0x1C40, 0x0046, 0x1C40, 0x7246, 0x4A6A, 0xCD3E, 0xCCCC, 
            0x5B3D, 0x0021, 0x0000, 0x3173, 0x0000, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0022, 
            0x0000, 0x3172, 0x0000, 0x0000, 0x0000, 0xEA60, 0x3346, 0x8323, 
            0x7244, 0x4A6A, 0xCD3E, 0xCCCC, 0x5B3D, 0x0023, 0x0000, 0x6E45, 
            0x4D76, 0x646F, 0x0031, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x245B, 0x0000, 0x6100, 
            0x0032, 0x0000, 0x0000, 0x6000, 0x46EA, 0x0000, 0x0000, 0x6A72, 
            0x3E4A, 0xCCCD, 0x3DCC, 0x255B, 0x0000, 0x6800, 0x0032, 0x0000, 
            0x0000, 0x4000, 0x461C, 0x0000, 0x0000, 0x6A72, 0x3E4A, 0xCCCD, 
            0x3DCC, 0x265B, 0x0000, 0x6400, 0x0032, 0x0000, 0x0000, 0x4000, 
            0x461C, 0x6CCD, 0x44F4, 0x6A72, 0x3E4A, 0xCCCD, 0x3DCC, 0x275B, 
            0x0000, 0x7300, 0x0032, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x285B, 0x0000, 0x7200, 
            0x0032, 0x0000, 0x0000, 0x6000, 0x46EA, 0x6667, 0x429C, 0x6A72, 
            0x3E4A, 0xCCCD, 0x3DCC, 0x295B, 0x0000, 0x4500, 0x766E, 0x6F4D, 
            0x3264, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x002A, 0x0000, 0x6D41, 0x4170, 
            0x0000, 0x0000, 0x0000, 0xEA60, 0x0046, 0x0000, 0x7200, 0x4A6A, 
            0xCD3E, 0xCCCC, 0x5B3D, 0x002B, 0x0000, 0x6D41, 0x4870, 0x0000, 
            0x0000, 0x0000, 0x1C40, 0x0046, 0x1C40, 0x7246, 0x4A6A, 0xCD3E, 
            0xCCCC, 0x5B3D, 0x002C, 0x0000, 0x6D41, 0x4470, 0x0000, 0x0000, 
            0x0000, 0x1C40, 0x0046, 0x1C40, 0x7246, 0x4A6A, 0xCD3E, 0xCCCC, 
            0x5B3D, 0x002D, 0x0000, 0x6D41, 0x5370, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x002E, 0x0000, 0x6D41, 0x5270, 0x0000, 0x0000, 0x0000, 0xEA60, 
            0x0046, 0x1C40, 0x7246, 0x4A6A, 0xCD3E, 0xCCCC, 0x5B3D, 0x002F, 
            0x0000, 0x0071, 0x999A, 0x3E99, 0x6666, 0x411E, 0xC38F, 0x3E9E, 
            0x8918, 0x3E87, 0x0000, 0x0000, 0x305B, 0x0000, 0x4600, 0x6C69, 
            0x6574, 0x4D72, 0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x315B, 0x0000, 
            0x4C00, 0x0050, 0x0000, 0x0000, 0x0000, 0x3F80, 0xDA1D, 0x3F42, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x325B, 0x0000, 0x4C00, 0x4D70, 
            0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0xE53F, 0xE2D0, 0x00BB, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x0033, 0x0000, 0x704C, 0x7253, 
            0x0063, 0x0000, 0x3F80, 0x0000, 0x4120, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x345B, 0x0000, 0x4800, 0x0050, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x355B, 0x0000, 0x4800, 0x4D70, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0036, 0x0000, 0x7048, 0x7253, 0x0063, 0x0000, 0x3F80, 
            0x0000, 0x4120, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& modchain1 = this->getT(0);                                                    // filtest_impl::modchain1_t<NV>
		auto& split5 = this->getT(0).getT(0);                                               // filtest_impl::split5_t<NV>
		auto& chain25 = this->getT(0).getT(0).getT(0);                                      // filtest_impl::chain25_t<NV>
		auto& ahdsr = this->getT(0).getT(0).getT(0).getT(0);                                // filtest_impl::ahdsr_t<NV>
		auto& chain2 = this->getT(0).getT(0).getT(0).getT(1);                               // filtest_impl::chain2_t<NV>
		auto& add12 = this->getT(0).getT(0).getT(0).getT(1).getT(0);                        // math::add<NV>
		auto& cable_table2 = this->getT(0).getT(0).getT(0).getT(1).getT(1);                 // filtest_impl::cable_table2_t<NV>
		auto& split7 = this->getT(0).getT(0).getT(0).getT(1).getT(2);                       // filtest_impl::split7_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(0).getT(1).getT(2).getT(0);                 // filtest_impl::pma3_t<NV>
		auto& gain13 = this->getT(0).getT(0).getT(0).getT(1).getT(3);                       // core::gain<NV>
		auto& peak2 = this->getT(0).getT(0).getT(0).getT(1).getT(4);                        // filtest_impl::peak2_t<NV>
		auto& minmax1 = this->getT(0).getT(0).getT(0).getT(2);                              // filtest_impl::minmax1_t<NV>
		auto& chain34 = this->getT(0).getT(0).getT(1);                                      // filtest_impl::chain34_t<NV>
		auto& ahdsr2 = this->getT(0).getT(0).getT(1).getT(0);                               // filtest_impl::ahdsr2_t<NV>
		auto& chain3 = this->getT(0).getT(0).getT(1).getT(1);                               // filtest_impl::chain3_t<NV>
		auto& add13 = this->getT(0).getT(0).getT(1).getT(1).getT(0);                        // math::add<NV>
		auto& cable_table3 = this->getT(0).getT(0).getT(1).getT(1).getT(1);                 // filtest_impl::cable_table3_t<NV>
		auto& split8 = this->getT(0).getT(0).getT(1).getT(1).getT(2);                       // filtest_impl::split8_t<NV>
		auto& pma10 = this->getT(0).getT(0).getT(1).getT(1).getT(2).getT(0);                // filtest_impl::pma10_t<NV>
		auto& gain14 = this->getT(0).getT(0).getT(1).getT(1).getT(3);                       // core::gain<NV>
		auto& peak4 = this->getT(0).getT(0).getT(1).getT(1).getT(4);                        // filtest_impl::peak4_t<NV>
		auto& minmax2 = this->getT(0).getT(0).getT(1).getT(2);                              // filtest_impl::minmax2_t<NV>
		auto& midi2 = this->getT(0).getT(0).getT(2);                                        // filtest_impl::midi2_t<NV>
		auto& midi3 = this->getT(0).getT(0).getT(3);                                        // filtest_impl::midi3_t<NV>
		auto& midi_cc1 = this->getT(0).getT(0).getT(4);                                     // filtest_impl::midi_cc1_t<NV>
		auto& split6 = this->getT(0).getT(1);                                               // filtest_impl::split6_t<NV>
		auto& chain18 = this->getT(0).getT(1).getT(0);                                      // filtest_impl::chain18_t<NV>
		auto& branch4 = this->getT(0).getT(1).getT(0).getT(0);                              // filtest_impl::branch4_t<NV>
		auto& chain23 = this->getT(0).getT(1).getT(0).getT(0).getT(0);                      // filtest_impl::chain23_t<NV>
		auto& add6 = this->getT(0).getT(1).getT(0).getT(0).getT(0).getT(0);                 // math::add<NV>
		auto& chain24 = this->getT(0).getT(1).getT(0).getT(0).getT(1);                      // filtest_impl::chain24_t<NV>
		auto& add7 = this->getT(0).getT(1).getT(0).getT(0).getT(1).getT(0);                 // math::add<NV>
		auto& chain28 = this->getT(0).getT(1).getT(0).getT(0).getT(2);                      // filtest_impl::chain28_t<NV>
		auto& add11 = this->getT(0).getT(1).getT(0).getT(0).getT(2).getT(0);                // math::add<NV>
		auto& chain19 = this->getT(0).getT(1).getT(0).getT(0).getT(3);                      // filtest_impl::chain19_t<NV>
		auto& global_cable = this->getT(0).getT(1).getT(0).getT(0).getT(3).getT(0);         // filtest_impl::global_cable_t<NV>
		auto& add = this->getT(0).getT(1).getT(0).getT(0).getT(3).getT(1);                  // math::add<NV>
		auto& chain22 = this->getT(0).getT(1).getT(0).getT(0).getT(4);                      // filtest_impl::chain22_t<NV>
		auto& global_cable1 = this->getT(0).getT(1).getT(0).getT(0).getT(4).getT(0);        // filtest_impl::global_cable1_t<NV>
		auto& add5 = this->getT(0).getT(1).getT(0).getT(0).getT(4).getT(1);                 // math::add<NV>
		auto& chain21 = this->getT(0).getT(1).getT(0).getT(0).getT(5);                      // filtest_impl::chain21_t<NV>
		auto& global_cable2 = this->getT(0).getT(1).getT(0).getT(0).getT(5).getT(0);        // filtest_impl::global_cable2_t<NV>
		auto& add4 = this->getT(0).getT(1).getT(0).getT(0).getT(5).getT(1);                 // math::add<NV>
		auto& chain20 = this->getT(0).getT(1).getT(0).getT(0).getT(6);                      // filtest_impl::chain20_t<NV>
		auto& global_cable3 = this->getT(0).getT(1).getT(0).getT(0).getT(6).getT(0);        // filtest_impl::global_cable3_t<NV>
		auto& add1 = this->getT(0).getT(1).getT(0).getT(0).getT(6).getT(1);                 // math::add<NV>
		auto& chain26 = this->getT(0).getT(1).getT(0).getT(0).getT(7);                      // filtest_impl::chain26_t<NV>
		auto& add8 = this->getT(0).getT(1).getT(0).getT(0).getT(7).getT(0);                 // math::add<NV>
		auto& chain29 = this->getT(0).getT(1).getT(0).getT(0).getT(8);                      // filtest_impl::chain29_t<NV>
		auto& add9 = this->getT(0).getT(1).getT(0).getT(0).getT(8).getT(0);                 // math::add<NV>
		auto& chain30 = this->getT(0).getT(1).getT(0).getT(0).getT(9);                      // filtest_impl::chain30_t<NV>
		auto& add10 = this->getT(0).getT(1).getT(0).getT(0).getT(9).getT(0);                // math::add<NV>
		auto& peak = this->getT(0).getT(1).getT(0).getT(1);                                 // filtest_impl::peak_t<NV>
		auto& pma = this->getT(0).getT(1).getT(0).getT(2);                                  // filtest_impl::pma_t<NV>
		auto& clear1 = this->getT(0).getT(1).getT(0).getT(3);                               // math::clear<NV>
		auto& chain37 = this->getT(0).getT(1).getT(1);                                      // filtest_impl::chain37_t<NV>
		auto& branch7 = this->getT(0).getT(1).getT(1).getT(0);                              // filtest_impl::branch7_t<NV>
		auto& chain38 = this->getT(0).getT(1).getT(1).getT(0).getT(0);                      // filtest_impl::chain38_t<NV>
		auto& add16 = this->getT(0).getT(1).getT(1).getT(0).getT(0).getT(0);                // math::add<NV>
		auto& chain39 = this->getT(0).getT(1).getT(1).getT(0).getT(1);                      // filtest_impl::chain39_t<NV>
		auto& add17 = this->getT(0).getT(1).getT(1).getT(0).getT(1).getT(0);                // math::add<NV>
		auto& chain47 = this->getT(0).getT(1).getT(1).getT(0).getT(2);                      // filtest_impl::chain47_t<NV>
		auto& add25 = this->getT(0).getT(1).getT(1).getT(0).getT(2).getT(0);                // math::add<NV>
		auto& chain40 = this->getT(0).getT(1).getT(1).getT(0).getT(3);                      // filtest_impl::chain40_t<NV>
		auto& global_cable4 = this->getT(0).getT(1).getT(1).getT(0).getT(3).getT(0);        // filtest_impl::global_cable4_t<NV>
		auto& add18 = this->getT(0).getT(1).getT(1).getT(0).getT(3).getT(1);                // math::add<NV>
		auto& chain41 = this->getT(0).getT(1).getT(1).getT(0).getT(4);                      // filtest_impl::chain41_t<NV>
		auto& global_cable5 = this->getT(0).getT(1).getT(1).getT(0).getT(4).getT(0);        // filtest_impl::global_cable5_t<NV>
		auto& add19 = this->getT(0).getT(1).getT(1).getT(0).getT(4).getT(1);                // math::add<NV>
		auto& chain42 = this->getT(0).getT(1).getT(1).getT(0).getT(5);                      // filtest_impl::chain42_t<NV>
		auto& global_cable6 = this->getT(0).getT(1).getT(1).getT(0).getT(5).getT(0);        // filtest_impl::global_cable6_t<NV>
		auto& add20 = this->getT(0).getT(1).getT(1).getT(0).getT(5).getT(1);                // math::add<NV>
		auto& chain43 = this->getT(0).getT(1).getT(1).getT(0).getT(6);                      // filtest_impl::chain43_t<NV>
		auto& global_cable7 = this->getT(0).getT(1).getT(1).getT(0).getT(6).getT(0);        // filtest_impl::global_cable7_t<NV>
		auto& add21 = this->getT(0).getT(1).getT(1).getT(0).getT(6).getT(1);                // math::add<NV>
		auto& chain44 = this->getT(0).getT(1).getT(1).getT(0).getT(7);                      // filtest_impl::chain44_t<NV>
		auto& add22 = this->getT(0).getT(1).getT(1).getT(0).getT(7).getT(0);                // math::add<NV>
		auto& chain45 = this->getT(0).getT(1).getT(1).getT(0).getT(8);                      // filtest_impl::chain45_t<NV>
		auto& add23 = this->getT(0).getT(1).getT(1).getT(0).getT(8).getT(0);                // math::add<NV>
		auto& chain46 = this->getT(0).getT(1).getT(1).getT(0).getT(9);                      // filtest_impl::chain46_t<NV>
		auto& add24 = this->getT(0).getT(1).getT(1).getT(0).getT(9).getT(0);                // math::add<NV>
		auto& peak3 = this->getT(0).getT(1).getT(1).getT(1);                                // filtest_impl::peak3_t<NV>
		auto& pma2 = this->getT(0).getT(1).getT(1).getT(2);                                 // filtest_impl::pma2_t<NV>
		auto& clear5 = this->getT(0).getT(1).getT(1).getT(3);                               // math::clear<NV>
		auto& chain63 = this->getT(0).getT(1).getT(2);                                      // filtest_impl::chain63_t<NV>
		auto& branch9 = this->getT(0).getT(1).getT(2).getT(0);                              // filtest_impl::branch9_t<NV>
		auto& chain64 = this->getT(0).getT(1).getT(2).getT(0).getT(0);                      // filtest_impl::chain64_t<NV>
		auto& add34 = this->getT(0).getT(1).getT(2).getT(0).getT(0).getT(0);                // math::add<NV>
		auto& chain65 = this->getT(0).getT(1).getT(2).getT(0).getT(1);                      // filtest_impl::chain65_t<NV>
		auto& add35 = this->getT(0).getT(1).getT(2).getT(0).getT(1).getT(0);                // math::add<NV>
		auto& chain114 = this->getT(0).getT(1).getT(2).getT(0).getT(2);                     // filtest_impl::chain114_t<NV>
		auto& add79 = this->getT(0).getT(1).getT(2).getT(0).getT(2).getT(0);                // math::add<NV>
		auto& chain66 = this->getT(0).getT(1).getT(2).getT(0).getT(3);                      // filtest_impl::chain66_t<NV>
		auto& global_cable12 = this->getT(0).getT(1).getT(2).getT(0).getT(3).getT(0);       // filtest_impl::global_cable12_t<NV>
		auto& add36 = this->getT(0).getT(1).getT(2).getT(0).getT(3).getT(1);                // math::add<NV>
		auto& chain67 = this->getT(0).getT(1).getT(2).getT(0).getT(4);                      // filtest_impl::chain67_t<NV>
		auto& global_cable13 = this->getT(0).getT(1).getT(2).getT(0).getT(4).getT(0);       // filtest_impl::global_cable13_t<NV>
		auto& add37 = this->getT(0).getT(1).getT(2).getT(0).getT(4).getT(1);                // math::add<NV>
		auto& chain68 = this->getT(0).getT(1).getT(2).getT(0).getT(5);                      // filtest_impl::chain68_t<NV>
		auto& global_cable14 = this->getT(0).getT(1).getT(2).getT(0).getT(5).getT(0);       // filtest_impl::global_cable14_t<NV>
		auto& add38 = this->getT(0).getT(1).getT(2).getT(0).getT(5).getT(1);                // math::add<NV>
		auto& chain69 = this->getT(0).getT(1).getT(2).getT(0).getT(6);                      // filtest_impl::chain69_t<NV>
		auto& global_cable15 = this->getT(0).getT(1).getT(2).getT(0).getT(6).getT(0);       // filtest_impl::global_cable15_t<NV>
		auto& add39 = this->getT(0).getT(1).getT(2).getT(0).getT(6).getT(1);                // math::add<NV>
		auto& chain70 = this->getT(0).getT(1).getT(2).getT(0).getT(7);                      // filtest_impl::chain70_t<NV>
		auto& add40 = this->getT(0).getT(1).getT(2).getT(0).getT(7).getT(0);                // math::add<NV>
		auto& chain71 = this->getT(0).getT(1).getT(2).getT(0).getT(8);                      // filtest_impl::chain71_t<NV>
		auto& add41 = this->getT(0).getT(1).getT(2).getT(0).getT(8).getT(0);                // math::add<NV>
		auto& chain72 = this->getT(0).getT(1).getT(2).getT(0).getT(9);                      // filtest_impl::chain72_t<NV>
		auto& add42 = this->getT(0).getT(1).getT(2).getT(0).getT(9).getT(0);                // math::add<NV>
		auto& peak5 = this->getT(0).getT(1).getT(2).getT(1);                                // filtest_impl::peak5_t<NV>
		auto& pma1 = this->getT(0).getT(1).getT(2).getT(2);                                 // filtest_impl::pma1_t<NV>
		auto& clear7 = this->getT(0).getT(1).getT(2).getT(3);                               // math::clear<NV>
		auto& chain73 = this->getT(0).getT(1).getT(3);                                      // filtest_impl::chain73_t<NV>
		auto& branch10 = this->getT(0).getT(1).getT(3).getT(0);                             // filtest_impl::branch10_t<NV>
		auto& chain74 = this->getT(0).getT(1).getT(3).getT(0).getT(0);                      // filtest_impl::chain74_t<NV>
		auto& add43 = this->getT(0).getT(1).getT(3).getT(0).getT(0).getT(0);                // math::add<NV>
		auto& chain75 = this->getT(0).getT(1).getT(3).getT(0).getT(1);                      // filtest_impl::chain75_t<NV>
		auto& add44 = this->getT(0).getT(1).getT(3).getT(0).getT(1).getT(0);                // math::add<NV>
		auto& chain115 = this->getT(0).getT(1).getT(3).getT(0).getT(2);                     // filtest_impl::chain115_t<NV>
		auto& add80 = this->getT(0).getT(1).getT(3).getT(0).getT(2).getT(0);                // math::add<NV>
		auto& chain76 = this->getT(0).getT(1).getT(3).getT(0).getT(3);                      // filtest_impl::chain76_t<NV>
		auto& global_cable16 = this->getT(0).getT(1).getT(3).getT(0).getT(3).getT(0);       // filtest_impl::global_cable16_t<NV>
		auto& add45 = this->getT(0).getT(1).getT(3).getT(0).getT(3).getT(1);                // math::add<NV>
		auto& chain77 = this->getT(0).getT(1).getT(3).getT(0).getT(4);                      // filtest_impl::chain77_t<NV>
		auto& global_cable17 = this->getT(0).getT(1).getT(3).getT(0).getT(4).getT(0);       // filtest_impl::global_cable17_t<NV>
		auto& add46 = this->getT(0).getT(1).getT(3).getT(0).getT(4).getT(1);                // math::add<NV>
		auto& chain78 = this->getT(0).getT(1).getT(3).getT(0).getT(5);                      // filtest_impl::chain78_t<NV>
		auto& global_cable18 = this->getT(0).getT(1).getT(3).getT(0).getT(5).getT(0);       // filtest_impl::global_cable18_t<NV>
		auto& add47 = this->getT(0).getT(1).getT(3).getT(0).getT(5).getT(1);                // math::add<NV>
		auto& chain79 = this->getT(0).getT(1).getT(3).getT(0).getT(6);                      // filtest_impl::chain79_t<NV>
		auto& global_cable19 = this->getT(0).getT(1).getT(3).getT(0).getT(6).getT(0);       // filtest_impl::global_cable19_t<NV>
		auto& add48 = this->getT(0).getT(1).getT(3).getT(0).getT(6).getT(1);                // math::add<NV>
		auto& chain80 = this->getT(0).getT(1).getT(3).getT(0).getT(7);                      // filtest_impl::chain80_t<NV>
		auto& add49 = this->getT(0).getT(1).getT(3).getT(0).getT(7).getT(0);                // math::add<NV>
		auto& chain81 = this->getT(0).getT(1).getT(3).getT(0).getT(8);                      // filtest_impl::chain81_t<NV>
		auto& add50 = this->getT(0).getT(1).getT(3).getT(0).getT(8).getT(0);                // math::add<NV>
		auto& chain82 = this->getT(0).getT(1).getT(3).getT(0).getT(9);                      // filtest_impl::chain82_t<NV>
		auto& add51 = this->getT(0).getT(1).getT(3).getT(0).getT(9).getT(0);                // math::add<NV>
		auto& peak6 = this->getT(0).getT(1).getT(3).getT(1);                                // filtest_impl::peak6_t<NV>
		auto& pma6 = this->getT(0).getT(1).getT(3).getT(2);                                 // filtest_impl::pma6_t<NV>
		auto& clear8 = this->getT(0).getT(1).getT(3).getT(3);                               // math::clear<NV>
		auto& chain84 = this->getT(0).getT(1).getT(4);                                      // filtest_impl::chain84_t<NV>
		auto& branch11 = this->getT(0).getT(1).getT(4).getT(0);                             // filtest_impl::branch11_t<NV>
		auto& chain85 = this->getT(0).getT(1).getT(4).getT(0).getT(0);                      // filtest_impl::chain85_t<NV>
		auto& add52 = this->getT(0).getT(1).getT(4).getT(0).getT(0).getT(0);                // math::add<NV>
		auto& chain86 = this->getT(0).getT(1).getT(4).getT(0).getT(1);                      // filtest_impl::chain86_t<NV>
		auto& add53 = this->getT(0).getT(1).getT(4).getT(0).getT(1).getT(0);                // math::add<NV>
		auto& chain87 = this->getT(0).getT(1).getT(4).getT(0).getT(2);                      // filtest_impl::chain87_t<NV>
		auto& global_cable20 = this->getT(0).getT(1).getT(4).getT(0).getT(2).getT(0);       // filtest_impl::global_cable20_t<NV>
		auto& add54 = this->getT(0).getT(1).getT(4).getT(0).getT(2).getT(1);                // math::add<NV>
		auto& chain88 = this->getT(0).getT(1).getT(4).getT(0).getT(3);                      // filtest_impl::chain88_t<NV>
		auto& global_cable21 = this->getT(0).getT(1).getT(4).getT(0).getT(3).getT(0);       // filtest_impl::global_cable21_t<NV>
		auto& add55 = this->getT(0).getT(1).getT(4).getT(0).getT(3).getT(1);                // math::add<NV>
		auto& chain89 = this->getT(0).getT(1).getT(4).getT(0).getT(4);                      // filtest_impl::chain89_t<NV>
		auto& global_cable22 = this->getT(0).getT(1).getT(4).getT(0).getT(4).getT(0);       // filtest_impl::global_cable22_t<NV>
		auto& add56 = this->getT(0).getT(1).getT(4).getT(0).getT(4).getT(1);                // math::add<NV>
		auto& chain90 = this->getT(0).getT(1).getT(4).getT(0).getT(5);                      // filtest_impl::chain90_t<NV>
		auto& global_cable23 = this->getT(0).getT(1).getT(4).getT(0).getT(5).getT(0);       // filtest_impl::global_cable23_t<NV>
		auto& add57 = this->getT(0).getT(1).getT(4).getT(0).getT(5).getT(1);                // math::add<NV>
		auto& chain91 = this->getT(0).getT(1).getT(4).getT(0).getT(6);                      // filtest_impl::chain91_t<NV>
		auto& add58 = this->getT(0).getT(1).getT(4).getT(0).getT(6).getT(0);                // math::add<NV>
		auto& chain92 = this->getT(0).getT(1).getT(4).getT(0).getT(7);                      // filtest_impl::chain92_t<NV>
		auto& add59 = this->getT(0).getT(1).getT(4).getT(0).getT(7).getT(0);                // math::add<NV>
		auto& chain93 = this->getT(0).getT(1).getT(4).getT(0).getT(8);                      // filtest_impl::chain93_t<NV>
		auto& add60 = this->getT(0).getT(1).getT(4).getT(0).getT(8).getT(0);                // math::add<NV>
		auto& peak7 = this->getT(0).getT(1).getT(4).getT(1);                                // filtest_impl::peak7_t<NV>
		auto& pma7 = this->getT(0).getT(1).getT(4).getT(2);                                 // filtest_impl::pma7_t<NV>
		auto& clear9 = this->getT(0).getT(1).getT(4).getT(3);                               // math::clear<NV>
		auto& chain94 = this->getT(0).getT(1).getT(5);                                      // filtest_impl::chain94_t<NV>
		auto& branch12 = this->getT(0).getT(1).getT(5).getT(0);                             // filtest_impl::branch12_t<NV>
		auto& chain95 = this->getT(0).getT(1).getT(5).getT(0).getT(0);                      // filtest_impl::chain95_t<NV>
		auto& add61 = this->getT(0).getT(1).getT(5).getT(0).getT(0).getT(0);                // math::add<NV>
		auto& chain96 = this->getT(0).getT(1).getT(5).getT(0).getT(1);                      // filtest_impl::chain96_t<NV>
		auto& add62 = this->getT(0).getT(1).getT(5).getT(0).getT(1).getT(0);                // math::add<NV>
		auto& chain117 = this->getT(0).getT(1).getT(5).getT(0).getT(2);                     // filtest_impl::chain117_t<NV>
		auto& add82 = this->getT(0).getT(1).getT(5).getT(0).getT(2).getT(0);                // math::add<NV>
		auto& chain97 = this->getT(0).getT(1).getT(5).getT(0).getT(3);                      // filtest_impl::chain97_t<NV>
		auto& global_cable24 = this->getT(0).getT(1).getT(5).getT(0).getT(3).getT(0);       // filtest_impl::global_cable24_t<NV>
		auto& add63 = this->getT(0).getT(1).getT(5).getT(0).getT(3).getT(1);                // math::add<NV>
		auto& chain98 = this->getT(0).getT(1).getT(5).getT(0).getT(4);                      // filtest_impl::chain98_t<NV>
		auto& global_cable25 = this->getT(0).getT(1).getT(5).getT(0).getT(4).getT(0);       // filtest_impl::global_cable25_t<NV>
		auto& add64 = this->getT(0).getT(1).getT(5).getT(0).getT(4).getT(1);                // math::add<NV>
		auto& chain99 = this->getT(0).getT(1).getT(5).getT(0).getT(5);                      // filtest_impl::chain99_t<NV>
		auto& global_cable26 = this->getT(0).getT(1).getT(5).getT(0).getT(5).getT(0);       // filtest_impl::global_cable26_t<NV>
		auto& add65 = this->getT(0).getT(1).getT(5).getT(0).getT(5).getT(1);                // math::add<NV>
		auto& chain100 = this->getT(0).getT(1).getT(5).getT(0).getT(6);                     // filtest_impl::chain100_t<NV>
		auto& global_cable27 = this->getT(0).getT(1).getT(5).getT(0).getT(6).getT(0);       // filtest_impl::global_cable27_t<NV>
		auto& add66 = this->getT(0).getT(1).getT(5).getT(0).getT(6).getT(1);                // math::add<NV>
		auto& chain101 = this->getT(0).getT(1).getT(5).getT(0).getT(7);                     // filtest_impl::chain101_t<NV>
		auto& add67 = this->getT(0).getT(1).getT(5).getT(0).getT(7).getT(0);                // math::add<NV>
		auto& chain102 = this->getT(0).getT(1).getT(5).getT(0).getT(8);                     // filtest_impl::chain102_t<NV>
		auto& add68 = this->getT(0).getT(1).getT(5).getT(0).getT(8).getT(0);                // math::add<NV>
		auto& chain103 = this->getT(0).getT(1).getT(5).getT(0).getT(9);                     // filtest_impl::chain103_t<NV>
		auto& add69 = this->getT(0).getT(1).getT(5).getT(0).getT(9).getT(0);                // math::add<NV>
		auto& peak8 = this->getT(0).getT(1).getT(5).getT(1);                                // filtest_impl::peak8_t<NV>
		auto& pma8 = this->getT(0).getT(1).getT(5).getT(2);                                 // filtest_impl::pma8_t<NV>
		auto& clear10 = this->getT(0).getT(1).getT(5).getT(3);                              // math::clear<NV>
		auto& chain104 = this->getT(0).getT(1).getT(6);                                     // filtest_impl::chain104_t<NV>
		auto& branch13 = this->getT(0).getT(1).getT(6).getT(0);                             // filtest_impl::branch13_t<NV>
		auto& chain105 = this->getT(0).getT(1).getT(6).getT(0).getT(0);                     // filtest_impl::chain105_t<NV>
		auto& add70 = this->getT(0).getT(1).getT(6).getT(0).getT(0).getT(0);                // math::add<NV>
		auto& chain106 = this->getT(0).getT(1).getT(6).getT(0).getT(1);                     // filtest_impl::chain106_t<NV>
		auto& add71 = this->getT(0).getT(1).getT(6).getT(0).getT(1).getT(0);                // math::add<NV>
		auto& chain116 = this->getT(0).getT(1).getT(6).getT(0).getT(2);                     // filtest_impl::chain116_t<NV>
		auto& add81 = this->getT(0).getT(1).getT(6).getT(0).getT(2).getT(0);                // math::add<NV>
		auto& chain107 = this->getT(0).getT(1).getT(6).getT(0).getT(3);                     // filtest_impl::chain107_t<NV>
		auto& global_cable28 = this->getT(0).getT(1).getT(6).getT(0).getT(3).getT(0);       // filtest_impl::global_cable28_t<NV>
		auto& add72 = this->getT(0).getT(1).getT(6).getT(0).getT(3).getT(1);                // math::add<NV>
		auto& chain108 = this->getT(0).getT(1).getT(6).getT(0).getT(4);                     // filtest_impl::chain108_t<NV>
		auto& global_cable29 = this->getT(0).getT(1).getT(6).getT(0).getT(4).getT(0);       // filtest_impl::global_cable29_t<NV>
		auto& add73 = this->getT(0).getT(1).getT(6).getT(0).getT(4).getT(1);                // math::add<NV>
		auto& chain109 = this->getT(0).getT(1).getT(6).getT(0).getT(5);                     // filtest_impl::chain109_t<NV>
		auto& global_cable30 = this->getT(0).getT(1).getT(6).getT(0).getT(5).getT(0);       // filtest_impl::global_cable30_t<NV>
		auto& add74 = this->getT(0).getT(1).getT(6).getT(0).getT(5).getT(1);                // math::add<NV>
		auto& chain110 = this->getT(0).getT(1).getT(6).getT(0).getT(6);                     // filtest_impl::chain110_t<NV>
		auto& global_cable31 = this->getT(0).getT(1).getT(6).getT(0).getT(6).getT(0);       // filtest_impl::global_cable31_t<NV>
		auto& add75 = this->getT(0).getT(1).getT(6).getT(0).getT(6).getT(1);                // math::add<NV>
		auto& chain111 = this->getT(0).getT(1).getT(6).getT(0).getT(7);                     // filtest_impl::chain111_t<NV>
		auto& add76 = this->getT(0).getT(1).getT(6).getT(0).getT(7).getT(0);                // math::add<NV>
		auto& chain112 = this->getT(0).getT(1).getT(6).getT(0).getT(8);                     // filtest_impl::chain112_t<NV>
		auto& add77 = this->getT(0).getT(1).getT(6).getT(0).getT(8).getT(0);                // math::add<NV>
		auto& chain113 = this->getT(0).getT(1).getT(6).getT(0).getT(9);                     // filtest_impl::chain113_t<NV>
		auto& add78 = this->getT(0).getT(1).getT(6).getT(0).getT(9).getT(0);                // math::add<NV>
		auto& peak9 = this->getT(0).getT(1).getT(6).getT(1);                                // filtest_impl::peak9_t<NV>
		auto& pma9 = this->getT(0).getT(1).getT(6).getT(2);                                 // filtest_impl::pma9_t<NV>
		auto& clear11 = this->getT(0).getT(1).getT(6).getT(3);                              // math::clear<NV>
		auto& chain118 = this->getT(0).getT(1).getT(7);                                     // filtest_impl::chain118_t<NV>
		auto& branch14 = this->getT(0).getT(1).getT(7).getT(0);                             // filtest_impl::branch14_t<NV>
		auto& chain119 = this->getT(0).getT(1).getT(7).getT(0).getT(0);                     // filtest_impl::chain119_t<NV>
		auto& add83 = this->getT(0).getT(1).getT(7).getT(0).getT(0).getT(0);                // math::add<NV>
		auto& chain120 = this->getT(0).getT(1).getT(7).getT(0).getT(1);                     // filtest_impl::chain120_t<NV>
		auto& add84 = this->getT(0).getT(1).getT(7).getT(0).getT(1).getT(0);                // math::add<NV>
		auto& chain121 = this->getT(0).getT(1).getT(7).getT(0).getT(2);                     // filtest_impl::chain121_t<NV>
		auto& add85 = this->getT(0).getT(1).getT(7).getT(0).getT(2).getT(0);                // math::add<NV>
		auto& chain122 = this->getT(0).getT(1).getT(7).getT(0).getT(3);                     // filtest_impl::chain122_t<NV>
		auto& global_cable32 = this->getT(0).getT(1).getT(7).getT(0).getT(3).getT(0);       // filtest_impl::global_cable32_t<NV>
		auto& add86 = this->getT(0).getT(1).getT(7).getT(0).getT(3).getT(1);                // math::add<NV>
		auto& chain123 = this->getT(0).getT(1).getT(7).getT(0).getT(4);                     // filtest_impl::chain123_t<NV>
		auto& global_cable33 = this->getT(0).getT(1).getT(7).getT(0).getT(4).getT(0);       // filtest_impl::global_cable33_t<NV>
		auto& add87 = this->getT(0).getT(1).getT(7).getT(0).getT(4).getT(1);                // math::add<NV>
		auto& chain124 = this->getT(0).getT(1).getT(7).getT(0).getT(5);                     // filtest_impl::chain124_t<NV>
		auto& global_cable34 = this->getT(0).getT(1).getT(7).getT(0).getT(5).getT(0);       // filtest_impl::global_cable34_t<NV>
		auto& add88 = this->getT(0).getT(1).getT(7).getT(0).getT(5).getT(1);                // math::add<NV>
		auto& chain125 = this->getT(0).getT(1).getT(7).getT(0).getT(6);                     // filtest_impl::chain125_t<NV>
		auto& global_cable35 = this->getT(0).getT(1).getT(7).getT(0).getT(6).getT(0);       // filtest_impl::global_cable35_t<NV>
		auto& add89 = this->getT(0).getT(1).getT(7).getT(0).getT(6).getT(1);                // math::add<NV>
		auto& chain126 = this->getT(0).getT(1).getT(7).getT(0).getT(7);                     // filtest_impl::chain126_t<NV>
		auto& add90 = this->getT(0).getT(1).getT(7).getT(0).getT(7).getT(0);                // math::add<NV>
		auto& chain127 = this->getT(0).getT(1).getT(7).getT(0).getT(8);                     // filtest_impl::chain127_t<NV>
		auto& add91 = this->getT(0).getT(1).getT(7).getT(0).getT(8).getT(0);                // math::add<NV>
		auto& chain128 = this->getT(0).getT(1).getT(7).getT(0).getT(9);                     // filtest_impl::chain128_t<NV>
		auto& add92 = this->getT(0).getT(1).getT(7).getT(0).getT(9).getT(0);                // math::add<NV>
		auto& peak10 = this->getT(0).getT(1).getT(7).getT(1);                               // filtest_impl::peak10_t<NV>
		auto& pma11 = this->getT(0).getT(1).getT(7).getT(2);                                // filtest_impl::pma11_t<NV>
		auto& clear12 = this->getT(0).getT(1).getT(7).getT(3);                              // math::clear<NV>
		auto& chain129 = this->getT(0).getT(1).getT(8);                                     // filtest_impl::chain129_t<NV>
		auto& branch15 = this->getT(0).getT(1).getT(8).getT(0);                             // filtest_impl::branch15_t<NV>
		auto& chain130 = this->getT(0).getT(1).getT(8).getT(0).getT(0);                     // filtest_impl::chain130_t<NV>
		auto& add93 = this->getT(0).getT(1).getT(8).getT(0).getT(0).getT(0);                // math::add<NV>
		auto& chain131 = this->getT(0).getT(1).getT(8).getT(0).getT(1);                     // filtest_impl::chain131_t<NV>
		auto& add94 = this->getT(0).getT(1).getT(8).getT(0).getT(1).getT(0);                // math::add<NV>
		auto& chain132 = this->getT(0).getT(1).getT(8).getT(0).getT(2);                     // filtest_impl::chain132_t<NV>
		auto& add95 = this->getT(0).getT(1).getT(8).getT(0).getT(2).getT(0);                // math::add<NV>
		auto& chain133 = this->getT(0).getT(1).getT(8).getT(0).getT(3);                     // filtest_impl::chain133_t<NV>
		auto& global_cable36 = this->getT(0).getT(1).getT(8).getT(0).getT(3).getT(0);       // filtest_impl::global_cable36_t<NV>
		auto& add96 = this->getT(0).getT(1).getT(8).getT(0).getT(3).getT(1);                // math::add<NV>
		auto& chain134 = this->getT(0).getT(1).getT(8).getT(0).getT(4);                     // filtest_impl::chain134_t<NV>
		auto& global_cable37 = this->getT(0).getT(1).getT(8).getT(0).getT(4).getT(0);       // filtest_impl::global_cable37_t<NV>
		auto& add97 = this->getT(0).getT(1).getT(8).getT(0).getT(4).getT(1);                // math::add<NV>
		auto& chain135 = this->getT(0).getT(1).getT(8).getT(0).getT(5);                     // filtest_impl::chain135_t<NV>
		auto& global_cable38 = this->getT(0).getT(1).getT(8).getT(0).getT(5).getT(0);       // filtest_impl::global_cable38_t<NV>
		auto& add98 = this->getT(0).getT(1).getT(8).getT(0).getT(5).getT(1);                // math::add<NV>
		auto& chain136 = this->getT(0).getT(1).getT(8).getT(0).getT(6);                     // filtest_impl::chain136_t<NV>
		auto& global_cable39 = this->getT(0).getT(1).getT(8).getT(0).getT(6).getT(0);       // filtest_impl::global_cable39_t<NV>
		auto& add99 = this->getT(0).getT(1).getT(8).getT(0).getT(6).getT(1);                // math::add<NV>
		auto& chain137 = this->getT(0).getT(1).getT(8).getT(0).getT(7);                     // filtest_impl::chain137_t<NV>
		auto& add100 = this->getT(0).getT(1).getT(8).getT(0).getT(7).getT(0);               // math::add<NV>
		auto& chain138 = this->getT(0).getT(1).getT(8).getT(0).getT(8);                     // filtest_impl::chain138_t<NV>
		auto& add101 = this->getT(0).getT(1).getT(8).getT(0).getT(8).getT(0);               // math::add<NV>
		auto& chain139 = this->getT(0).getT(1).getT(8).getT(0).getT(9);                     // filtest_impl::chain139_t<NV>
		auto& add102 = this->getT(0).getT(1).getT(8).getT(0).getT(9).getT(0);               // math::add<NV>
		auto& peak11 = this->getT(0).getT(1).getT(8).getT(1);                               // filtest_impl::peak11_t<NV>
		auto& pma12 = this->getT(0).getT(1).getT(8).getT(2);                                // filtest_impl::pma12_t<NV>
		auto& clear13 = this->getT(0).getT(1).getT(8).getT(3);                              // math::clear<NV>
		auto& tempo_sync = this->getT(1);                                                   // filtest_impl::tempo_sync_t<NV>
		auto& converter = this->getT(2);                                                    // filtest_impl::converter_t<NV>
		auto& input_toggle = this->getT(3);                                                 // filtest_impl::input_toggle_t<NV>
		auto& pma4 = this->getT(4);                                                         // filtest_impl::pma4_t<NV>
		auto& branch1 = this->getT(5);                                                      // filtest_impl::branch1_t<NV>
		auto& chain48 = this->getT(5).getT(0);                                              // filtest_impl::chain48_t<NV>
		auto& minmax = this->getT(5).getT(0).getT(0);                                       // filtest_impl::minmax_t<NV>
		auto& oscillator8 = this->getT(5).getT(0).getT(1);                                  // filtest_impl::oscillator8_t<NV>
		auto& branch5 = this->getT(5).getT(0).getT(2);                                      // filtest_impl::branch5_t<NV>
		auto& chain31 = this->getT(5).getT(0).getT(2).getT(0);                              // filtest_impl::chain31_t
		auto& chain49 = this->getT(5).getT(0).getT(2).getT(1);                              // filtest_impl::chain49_t
		auto& chain32 = this->getT(5).getT(0).getT(2).getT(2);                              // filtest_impl::chain32_t
		auto& chain35 = this->getT(5).getT(0).getT(2).getT(3);                              // filtest_impl::chain35_t
		auto& chain33 = this->getT(5).getT(0).getT(2).getT(4);                              // filtest_impl::chain33_t<NV>
		auto& branch6 = this->getT(5).getT(0).getT(2).getT(4).getT(0);                      // filtest_impl::branch6_t<NV>
		auto& chain36 = this->getT(5).getT(0).getT(2).getT(4).getT(0).getT(0);              // filtest_impl::chain36_t
		auto& sampleandhold = this->getT(5).getT(0).getT(2).getT(4).getT(0).getT(1);        // fx::sampleandhold<NV>
		auto& chain83 = this->getT(5).getT(1);                                              // filtest_impl::chain83_t<NV>
		auto& file_player = this->getT(5).getT(1).getT(0);                                  // filtest_impl::file_player_t<NV>
		auto& mul8 = this->getT(5).getT(1).getT(1);                                         // math::mul<NV>
		auto& branch16 = this->getT(6);                                                     // filtest_impl::branch16_t<NV>
		auto& chain50 = this->getT(6).getT(0);                                              // filtest_impl::chain50_t
		auto& chain53 = this->getT(6).getT(1);                                              // filtest_impl::chain53_t<NV>
		auto& gain5 = this->getT(6).getT(1).getT(0);                                        // wrap::no_process<core::gain<NV>>
		auto& mul = this->getT(6).getT(1).getT(1);                                          // math::mul<NV>
		auto& chain51 = this->getT(6).getT(2);                                              // filtest_impl::chain51_t<NV>
		auto& gain6 = this->getT(6).getT(2).getT(0);                                        // wrap::no_process<core::gain<NV>>
		auto& mul2 = this->getT(6).getT(2).getT(1);                                         // math::mul<NV>
		auto& oscilloscope = this->getT(7);                                                 // filtest_impl::oscilloscope_t
		auto& soft_bypass = this->getT(8);                                                  // filtest_impl::soft_bypass_t<NV>
		auto& chain7 = this->getT(8).getT(0);                                               // filtest_impl::chain7_t<NV>
		auto& xfader = this->getT(8).getT(0).getT(0);                                       // filtest_impl::xfader_t<NV>
		auto& split = this->getT(8).getT(0).getT(1);                                        // filtest_impl::split_t<NV>
		auto& chain = this->getT(8).getT(0).getT(1).getT(0);                                // filtest_impl::chain_t<NV>
		auto& gain1 = this->getT(8).getT(0).getT(1).getT(0).getT(0);                        // core::gain<NV>
		auto& chain1 = this->getT(8).getT(0).getT(1).getT(1);                               // filtest_impl::chain1_t<NV>
		auto& smoothed_parameter1 = this->getT(8).getT(0).getT(1).getT(1).getT(0);          // filtest_impl::smoothed_parameter1_t<NV>
		auto& branch3 = this->getT(8).getT(0).getT(1).getT(1).getT(1);                      // filtest_impl::branch3_t<NV>
		auto& chain12 = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(0);              // filtest_impl::chain12_t<NV>
		auto& expr = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(0).getT(0);         // math::expr<NV, custom::expr>
		auto& chain13 = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(1);              // filtest_impl::chain13_t<NV>
		auto& sub = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(1).getT(0);          // wrap::no_process<math::sub<NV>>
		auto& split1 = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(1).getT(1);       // filtest_impl::split1_t<NV>
		auto& pi = this->getT(8).getT(0).getT(1).getT(1).                                   // math::pi<NV>
                   getT(1).getT(1).getT(1).getT(0);
		auto& pi1 = this->getT(8).getT(0).getT(1).getT(1).                                  // math::pi<NV>
                    getT(1).getT(1).getT(1).getT(1);
		auto& pi6 = this->getT(8).getT(0).getT(1).getT(1).                                  // math::pi<NV>
                    getT(1).getT(1).getT(1).getT(2);
		auto& pi2 = this->getT(8).getT(0).getT(1).getT(1).                                  // math::pi<NV>
                    getT(1).getT(1).getT(1).getT(3);
		auto& mul1 = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(1).getT(2);         // math::mul<NV>
		auto& chain15 = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(2);              // filtest_impl::chain15_t<NV>
		auto& pi3 = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(2).getT(0);          // wrap::no_process<math::pi<NV>>
		auto& fmod1 = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(2).getT(1);        // math::fmod<NV>
		auto& chain17 = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(3);              // filtest_impl::chain17_t<NV>
		auto& ring_mod2 = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(3).getT(0);    // filters::ring_mod<NV>
		auto& chain14 = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(4);              // filtest_impl::chain14_t<NV>
		auto& cable_table = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(4).getT(0);  // filtest_impl::cable_table_t<NV>
		auto& faust = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(4).getT(1);        // project::g<NV>
		auto& chain27 = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(5);              // filtest_impl::chain27_t<NV>
		auto& cable_table1 = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(5).getT(0); // filtest_impl::cable_table1_t<NV>
		auto& faust1 = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(5).getT(1);       // project::granular<NV>
		auto& chain16 = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(6);              // filtest_impl::chain16_t<NV>
		auto& div2 = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(6).getT(0);         // math::div<NV>
		auto& chain52 = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(7);              // filtest_impl::chain52_t<NV>
		auto& phasor_fm = this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(7).getT(0);    // core::phasor_fm<NV>
		auto& split2 = this->getT(8).getT(0).getT(1).getT(1).getT(2);                       // filtest_impl::split2_t<NV>
		auto& smoother = this->getT(8).getT(0).getT(1).getT(1).getT(2).getT(0);             // core::smoother<NV>
		auto& smoother3 = this->getT(8).getT(0).getT(1).getT(1).getT(2).getT(1);            // core::smoother<NV>
		auto& multi1 = this->getT(8).getT(0).getT(1).getT(1).getT(3);                       // filtest_impl::multi1_t
		auto& gain2 = this->getT(8).getT(0).getT(1).getT(1).getT(4);                        // core::gain<NV>
		auto& tanh = this->getT(9);                                                         // wrap::no_process<math::tanh<NV>>
		auto& frame2_block = this->getT(10);                                                // filtest_impl::frame2_block_t<NV>
		auto& smoothed_parameter = this->getT(10).getT(0);                                  // filtest_impl::smoothed_parameter_t<NV>
		auto& branch2 = this->getT(10).getT(1);                                             // filtest_impl::branch2_t<NV>
		auto& chain10 = this->getT(10).getT(1).getT(0);                                     // filtest_impl::chain10_t
		auto& chain8 = this->getT(10).getT(1).getT(1);                                      // filtest_impl::chain8_t<NV>
		auto& add2 = this->getT(10).getT(1).getT(1).getT(0);                                // math::add<NV>
		auto& chain11 = this->getT(10).getT(1).getT(2);                                     // filtest_impl::chain11_t<NV>
		auto& add3 = this->getT(10).getT(1).getT(2).getT(0);                                // wrap::no_process<math::add<NV>>
		auto& branch = this->getT(10).getT(2);                                              // filtest_impl::branch_t<NV>
		auto& chain4 = this->getT(10).getT(2).getT(0);                                      // filtest_impl::chain4_t
		auto& chain5 = this->getT(10).getT(2).getT(1);                                      // filtest_impl::chain5_t<NV>
		auto& chain9 = this->getT(10).getT(2).getT(1).getT(0);                              // filtest_impl::chain9_t<NV>
		auto& file_player3 = this->getT(10).getT(2).getT(1).getT(0).getT(0);                // filtest_impl::file_player3_t<NV>
		auto& chain6 = this->getT(10).getT(2).getT(2);                                      // filtest_impl::chain6_t<NV>
		auto& file_player4 = this->getT(10).getT(2).getT(2).getT(0);                        // filtest_impl::file_player4_t<NV>
		auto& oscilloscope1 = this->getT(10).getT(3);                                       // filtest_impl::oscilloscope1_t
		auto& softbypass_switch5 = this->getT(11);                                          // filtest_impl::softbypass_switch5_t<NV>
		auto& switcher = this->getT(11).getT(0);                                            // filtest_impl::switcher_t<NV>
		auto& sb_container = this->getT(11).getT(1);                                        // filtest_impl::sb_container_t<NV>
		auto& sb1 = this->getT(11).getT(1).getT(0);                                         // filtest_impl::sb1_t<NV>
		auto& ladder3 = this->getT(11).getT(1).getT(0).getT(0);                             // filters::ladder<NV>
		auto& svf1 = this->getT(11).getT(1).getT(0).getT(1);                                // filters::svf<NV>
		auto& sb2 = this->getT(11).getT(1).getT(1);                                         // filtest_impl::sb2_t<NV>
		auto& svf2 = this->getT(11).getT(1).getT(1).getT(0);                                // filters::svf<NV>
		auto& ladder4 = this->getT(11).getT(1).getT(1).getT(1);                             // filters::ladder<NV>
		auto& sb3 = this->getT(11).getT(1).getT(2);                                         // filtest_impl::sb3_t<NV>
		auto& split3 = this->getT(11).getT(1).getT(2).getT(0);                              // filtest_impl::split3_t<NV>
		auto& ladder5 = this->getT(11).getT(1).getT(2).getT(0).getT(0);                     // filters::ladder<NV>
		auto& svf4 = this->getT(11).getT(1).getT(2).getT(0).getT(1);                        // filters::svf<NV>
		auto& ahdsr1 = this->getT(12);                                                      // filtest_impl::ahdsr1_t<NV>
		auto& voice_manager = this->getT(13);                                               // envelope::voice_manager
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, tempo_sync); // Tempo -> tempo_sync::Multiplier
		
		this->getParameterT(1).connectT(0, smoothed_parameter); // PosSmooth -> smoothed_parameter::SmoothingTime
		
		auto& MathSmooth_p = this->getParameterT(2);
		MathSmooth_p.connectT(0, smoother);  // MathSmooth -> smoother::SmoothingTime
		MathSmooth_p.connectT(1, smoother3); // MathSmooth -> smoother3::SmoothingTime
		
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
		
		this->getParameterT(13).connectT(0, pma4); // Fine -> pma4::Value
		
		this->getParameterT(14).connectT(0, branch1); // InputMode -> branch1::Index
		
		auto& OscMode_p = this->getParameterT(15);
		OscMode_p.connectT(0, oscillator8); // OscMode -> oscillator8::Mode
		OscMode_p.connectT(1, branch5);     // OscMode -> branch5::Index
		
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
		
		auto& OutMode_p = this->getParameterT(26);
		OutMode_p.connectT(0, branch);   // OutMode -> branch::Index
		OutMode_p.connectT(1, branch2);  // OutMode -> branch2::Index
		OutMode_p.connectT(2, branch16); // OutMode -> branch16::Index
		
		this->getParameterT(27).connectT(0, pma9); // Gain2 -> pma9::Add
		
		this->getParameterT(28).connectT(0, pma9); // Gain2Mod -> pma9::Multiply
		
		this->getParameterT(29).connectT(0, branch13); // Gain2Src -> branch13::Index
		
		this->getParameterT(30).connectT(0, ahdsr); // a1 -> ahdsr::Attack
		
		this->getParameterT(31).connectT(0, ahdsr); // h1 -> ahdsr::Hold
		
		this->getParameterT(32).connectT(0, ahdsr); // d1 -> ahdsr::Decay
		
		this->getParameterT(33).connectT(0, ahdsr); // s1 -> ahdsr::Sustain
		
		this->getParameterT(34).connectT(0, ahdsr); // r1 -> ahdsr::Release
		
		auto& EnvMod1_p = this->getParameterT(35);
		EnvMod1_p.connectT(0, cable_table2); // EnvMod1 -> cable_table2::Value
		EnvMod1_p.connectT(1, pma3);         // EnvMod1 -> pma3::Multiply
		
		this->getParameterT(36).connectT(0, ahdsr2); // a2 -> ahdsr2::Attack
		
		this->getParameterT(37).connectT(0, ahdsr2); // h2 -> ahdsr2::Hold
		
		this->getParameterT(38).connectT(0, ahdsr2); // d2 -> ahdsr2::Decay
		
		this->getParameterT(39).connectT(0, ahdsr2); // s2 -> ahdsr2::Sustain
		
		this->getParameterT(40).connectT(0, ahdsr2); // r2 -> ahdsr2::Release
		
		auto& EnvMod2_p = this->getParameterT(41);
		EnvMod2_p.connectT(0, cable_table3); // EnvMod2 -> cable_table3::Value
		EnvMod2_p.connectT(1, pma10);        // EnvMod2 -> pma10::Multiply
		
		this->getParameterT(42).connectT(0, ahdsr1); // AmpA -> ahdsr1::Attack
		
		this->getParameterT(43).connectT(0, ahdsr1); // AmpH -> ahdsr1::Hold
		
		this->getParameterT(44).connectT(0, ahdsr1); // AmpD -> ahdsr1::Decay
		
		this->getParameterT(45).connectT(0, ahdsr1); // AmpS -> ahdsr1::Sustain
		
		this->getParameterT(46).connectT(0, ahdsr1); // AmpR -> ahdsr1::Release
		
		auto& q_p = this->getParameterT(47);
		q_p.connectT(0, svf1);    // q -> svf1::Q
		q_p.connectT(1, ladder3); // q -> ladder3::Q
		q_p.connectT(2, svf2);    // q -> svf2::Q
		q_p.connectT(3, ladder4); // q -> ladder4::Q
		q_p.connectT(4, ladder5); // q -> ladder5::Q
		q_p.connectT(5, svf4);    // q -> svf4::Q
		
		this->getParameterT(48).connectT(0, switcher); // FilterMode -> switcher::Value
		
		this->getParameterT(49).connectT(0, pma11); // LP -> pma11::Add
		
		this->getParameterT(50).connectT(0, pma11); // LpMod -> pma11::Multiply
		
		this->getParameterT(51).connectT(0, branch14); // LpSrc -> branch14::Index
		
		this->getParameterT(52).connectT(0, pma12); // HP -> pma12::Add
		
		this->getParameterT(53).connectT(0, pma12); // HpMod -> pma12::Multiply
		
		this->getParameterT(54).connectT(0, branch15); // HpSrc -> branch15::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& ahdsr_p = ahdsr.getWrappedObject().getParameter();
		ahdsr_p.getParameterT(0).connectT(0, add12);                      // ahdsr -> add12::Value
		pma3.getWrappedObject().getParameter().connectT(0, gain13);       // pma3 -> gain13::Gain
		cable_table2.getWrappedObject().getParameter().connectT(0, pma3); // cable_table2 -> pma3::Add
		minmax1.getWrappedObject().getParameter().connectT(0, add6);      // minmax1 -> add6::Value
		minmax1.getWrappedObject().getParameter().connectT(1, add16);     // minmax1 -> add16::Value
		minmax1.getWrappedObject().getParameter().connectT(2, add52);     // minmax1 -> add52::Value
		minmax1.getWrappedObject().getParameter().connectT(3, add43);     // minmax1 -> add43::Value
		minmax1.getWrappedObject().getParameter().connectT(4, add61);     // minmax1 -> add61::Value
		minmax1.getWrappedObject().getParameter().connectT(5, add70);     // minmax1 -> add70::Value
		minmax1.getWrappedObject().getParameter().connectT(6, add34);     // minmax1 -> add34::Value
		minmax1.getWrappedObject().getParameter().connectT(7, add83);     // minmax1 -> add83::Value
		minmax1.getWrappedObject().getParameter().connectT(8, add93);     // minmax1 -> add93::Value
		peak2.getParameter().connectT(0, minmax1);                        // peak2 -> minmax1::Value
		auto& ahdsr2_p = ahdsr2.getWrappedObject().getParameter();
		ahdsr2_p.getParameterT(0).connectT(0, add13);                          // ahdsr2 -> add13::Value
		pma10.getWrappedObject().getParameter().connectT(0, gain14);           // pma10 -> gain14::Gain
		cable_table3.getWrappedObject().getParameter().connectT(0, pma10);     // cable_table3 -> pma10::Add
		minmax2.getWrappedObject().getParameter().connectT(0, add7);           // minmax2 -> add7::Value
		minmax2.getWrappedObject().getParameter().connectT(1, add17);          // minmax2 -> add17::Value
		minmax2.getWrappedObject().getParameter().connectT(2, add53);          // minmax2 -> add53::Value
		minmax2.getWrappedObject().getParameter().connectT(3, add44);          // minmax2 -> add44::Value
		minmax2.getWrappedObject().getParameter().connectT(4, add62);          // minmax2 -> add62::Value
		minmax2.getWrappedObject().getParameter().connectT(5, add71);          // minmax2 -> add71::Value
		minmax2.getWrappedObject().getParameter().connectT(6, add35);          // minmax2 -> add35::Value
		minmax2.getWrappedObject().getParameter().connectT(7, add84);          // minmax2 -> add84::Value
		minmax2.getWrappedObject().getParameter().connectT(8, add94);          // minmax2 -> add94::Value
		peak4.getParameter().connectT(0, minmax2);                             // peak4 -> minmax2::Value
		midi2.getParameter().connectT(0, add8);                                // midi2 -> add8::Value
		midi2.getParameter().connectT(1, add22);                               // midi2 -> add22::Value
		midi2.getParameter().connectT(2, add49);                               // midi2 -> add49::Value
		midi2.getParameter().connectT(3, add58);                               // midi2 -> add58::Value
		midi2.getParameter().connectT(4, add67);                               // midi2 -> add67::Value
		midi2.getParameter().connectT(5, add76);                               // midi2 -> add76::Value
		midi2.getParameter().connectT(6, add40);                               // midi2 -> add40::Value
		midi2.getParameter().connectT(7, pma3);                                // midi2 -> pma3::Value
		midi2.getParameter().connectT(8, add90);                               // midi2 -> add90::Value
		midi2.getParameter().connectT(9, add100);                              // midi2 -> add100::Value
		midi3.getParameter().connectT(0, add9);                                // midi3 -> add9::Value
		midi3.getParameter().connectT(1, add23);                               // midi3 -> add23::Value
		midi3.getParameter().connectT(2, add50);                               // midi3 -> add50::Value
		midi3.getParameter().connectT(3, add59);                               // midi3 -> add59::Value
		midi3.getParameter().connectT(4, add68);                               // midi3 -> add68::Value
		midi3.getParameter().connectT(5, add77);                               // midi3 -> add77::Value
		midi3.getParameter().connectT(6, add41);                               // midi3 -> add41::Value
		midi3.getParameter().connectT(7, pma10);                               // midi3 -> pma10::Value
		midi3.getParameter().connectT(8, add91);                               // midi3 -> add91::Value
		midi3.getParameter().connectT(9, add101);                              // midi3 -> add101::Value
		midi_cc1.getWrappedObject().getParameter().connectT(0, add10);         // midi_cc1 -> add10::Value
		midi_cc1.getWrappedObject().getParameter().connectT(1, add24);         // midi_cc1 -> add24::Value
		midi_cc1.getWrappedObject().getParameter().connectT(2, add51);         // midi_cc1 -> add51::Value
		midi_cc1.getWrappedObject().getParameter().connectT(3, add60);         // midi_cc1 -> add60::Value
		midi_cc1.getWrappedObject().getParameter().connectT(4, add69);         // midi_cc1 -> add69::Value
		midi_cc1.getWrappedObject().getParameter().connectT(5, add78);         // midi_cc1 -> add78::Value
		midi_cc1.getWrappedObject().getParameter().connectT(6, add42);         // midi_cc1 -> add42::Value
		midi_cc1.getWrappedObject().getParameter().connectT(7, add92);         // midi_cc1 -> add92::Value
		midi_cc1.getWrappedObject().getParameter().connectT(8, add102);        // midi_cc1 -> add102::Value
		global_cable.getWrappedObject().getParameter().connectT(0, add);       // global_cable -> add::Value
		global_cable1.getWrappedObject().getParameter().connectT(0, add5);     // global_cable1 -> add5::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add4);     // global_cable2 -> add4::Value
		global_cable3.getWrappedObject().getParameter().connectT(0, add1);     // global_cable3 -> add1::Value
		pma.getWrappedObject().getParameter().connectT(0, oscillator8);        // pma -> oscillator8::Gain
		pma.getWrappedObject().getParameter().connectT(1, mul8);               // pma -> mul8::Value
		peak.getParameter().connectT(0, pma);                                  // peak -> pma::Value
		global_cable4.getWrappedObject().getParameter().connectT(0, add18);    // global_cable4 -> add18::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add19);    // global_cable5 -> add19::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add20);    // global_cable6 -> add20::Value
		global_cable7.getWrappedObject().getParameter().connectT(0, add21);    // global_cable7 -> add21::Value
		minmax.getWrappedObject().getParameter().connectT(0, oscillator8);     // minmax -> oscillator8::FreqRatio
		pma4.getWrappedObject().getParameter().connectT(0, file_player);       // pma4 -> file_player::FreqRatio
		pma4.getWrappedObject().getParameter().connectT(1, minmax);            // pma4 -> minmax::Value
		input_toggle.getWrappedObject().getParameter().connectT(0, pma4);      // input_toggle -> pma4::Add
		converter.getWrappedObject().getParameter().connectT(0, input_toggle); // converter -> input_toggle::Value2
		tempo_sync.getParameter().connectT(0, converter);                      // tempo_sync -> converter::Value
		tempo_sync.getParameter().connectT(1, sampleandhold);                  // tempo_sync -> sampleandhold::Counter
		pma2.getWrappedObject().getParameter().connectT(0, tempo_sync);        // pma2 -> tempo_sync::Tempo
		peak3.getParameter().connectT(0, pma2);                                // peak3 -> pma2::Value
		global_cable12.getWrappedObject().getParameter().connectT(0, add36);   // global_cable12 -> add36::Value
		global_cable13.getWrappedObject().getParameter().connectT(0, add37);   // global_cable13 -> add37::Value
		global_cable14.getWrappedObject().getParameter().connectT(0, add38);   // global_cable14 -> add38::Value
		global_cable15.getWrappedObject().getParameter().connectT(0, add39);   // global_cable15 -> add39::Value
		pma1.getWrappedObject().getParameter().connectT(0, input_toggle);      // pma1 -> input_toggle::Value1
		peak5.getParameter().connectT(0, pma1);                                // peak5 -> pma1::Value
		global_cable16.getWrappedObject().getParameter().connectT(0, add45);   // global_cable16 -> add45::Value
		global_cable17.getWrappedObject().getParameter().connectT(0, add46);   // global_cable17 -> add46::Value
		global_cable18.getWrappedObject().getParameter().connectT(0, add47);   // global_cable18 -> add47::Value
		global_cable19.getWrappedObject().getParameter().connectT(0, add48);   // global_cable19 -> add48::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain1);                            // xfader -> gain1::Gain
		xfader_p.getParameterT(1).connectT(0, gain2);                            // xfader -> gain2::Gain
		pma6.getWrappedObject().getParameter().connectT(0, xfader);              // pma6 -> xfader::Value
		peak6.getParameter().connectT(0, pma6);                                  // peak6 -> pma6::Value
		global_cable20.getWrappedObject().getParameter().connectT(0, add54);     // global_cable20 -> add54::Value
		global_cable21.getWrappedObject().getParameter().connectT(0, add55);     // global_cable21 -> add55::Value
		global_cable22.getWrappedObject().getParameter().connectT(0, add56);     // global_cable22 -> add56::Value
		global_cable23.getWrappedObject().getParameter().connectT(0, add57);     // global_cable23 -> add57::Value
		cable_table.getWrappedObject().getParameter().connectT(0, faust);        // cable_table -> faust::graindensity
		cable_table1.getWrappedObject().getParameter().connectT(0, faust1);      // cable_table1 -> faust1::decal
		smoothed_parameter1.getParameter().connectT(0, expr);                    // smoothed_parameter1 -> expr::Value
		smoothed_parameter1.getParameter().connectT(1, fmod1);                   // smoothed_parameter1 -> fmod1::Value
		smoothed_parameter1.getParameter().connectT(2, phasor_fm);               // smoothed_parameter1 -> phasor_fm::FreqRatio
		smoothed_parameter1.getParameter().connectT(3, mul1);                    // smoothed_parameter1 -> mul1::Value
		smoothed_parameter1.getParameter().connectT(4, ring_mod2);               // smoothed_parameter1 -> ring_mod2::Frequency
		smoothed_parameter1.getParameter().connectT(5, div2);                    // smoothed_parameter1 -> div2::Value
		smoothed_parameter1.getParameter().connectT(6, cable_table);             // smoothed_parameter1 -> cable_table::Value
		smoothed_parameter1.getParameter().connectT(7, faust);                   // smoothed_parameter1 -> faust::delaylength
		smoothed_parameter1.getParameter().connectT(8, faust);                   // smoothed_parameter1 -> faust::grainlength
		smoothed_parameter1.getParameter().connectT(9, faust1);                  // smoothed_parameter1 -> faust1::population
		smoothed_parameter1.getParameter().connectT(10, faust1);                 // smoothed_parameter1 -> faust1::taille
		smoothed_parameter1.getParameter().connectT(11, cable_table1);           // smoothed_parameter1 -> cable_table1::Value
		pma7.getWrappedObject().getParameter().connectT(0, smoothed_parameter1); // pma7 -> smoothed_parameter1::Value
		peak7.getParameter().connectT(0, pma7);                                  // peak7 -> pma7::Value
		global_cable24.getWrappedObject().getParameter().connectT(0, add63);     // global_cable24 -> add63::Value
		global_cable25.getWrappedObject().getParameter().connectT(0, add64);     // global_cable25 -> add64::Value
		global_cable26.getWrappedObject().getParameter().connectT(0, add65);     // global_cable26 -> add65::Value
		global_cable27.getWrappedObject().getParameter().connectT(0, add66);     // global_cable27 -> add66::Value
		smoothed_parameter.getParameter().connectT(0, add2);                     // smoothed_parameter -> add2::Value
		smoothed_parameter.getParameter().connectT(1, add3);                     // smoothed_parameter -> add3::Value
		pma8.getWrappedObject().getParameter().connectT(0, smoothed_parameter);  // pma8 -> smoothed_parameter::Value
		peak8.getParameter().connectT(0, pma8);                                  // peak8 -> pma8::Value
		global_cable28.getWrappedObject().getParameter().connectT(0, add72);     // global_cable28 -> add72::Value
		global_cable29.getWrappedObject().getParameter().connectT(0, add73);     // global_cable29 -> add73::Value
		global_cable30.getWrappedObject().getParameter().connectT(0, add74);     // global_cable30 -> add74::Value
		global_cable31.getWrappedObject().getParameter().connectT(0, add75);     // global_cable31 -> add75::Value
		pma9.getWrappedObject().getParameter().connectT(0, mul);                 // pma9 -> mul::Value
		pma9.getWrappedObject().getParameter().connectT(1, gain5);               // pma9 -> gain5::Gain
		pma9.getWrappedObject().getParameter().connectT(2, gain6);               // pma9 -> gain6::Gain
		pma9.getWrappedObject().getParameter().connectT(3, mul2);                // pma9 -> mul2::Value
		peak9.getParameter().connectT(0, pma9);                                  // peak9 -> pma9::Value
		global_cable32.getWrappedObject().getParameter().connectT(0, add86);     // global_cable32 -> add86::Value
		global_cable33.getWrappedObject().getParameter().connectT(0, add87);     // global_cable33 -> add87::Value
		global_cable34.getWrappedObject().getParameter().connectT(0, add88);     // global_cable34 -> add88::Value
		global_cable35.getWrappedObject().getParameter().connectT(0, add89);     // global_cable35 -> add89::Value
		pma11.getWrappedObject().getParameter().connectT(0, ladder3);            // pma11 -> ladder3::Frequency
		pma11.getWrappedObject().getParameter().connectT(1, ladder4);            // pma11 -> ladder4::Frequency
		pma11.getWrappedObject().getParameter().connectT(2, ladder5);            // pma11 -> ladder5::Frequency
		peak10.getParameter().connectT(0, pma11);                                // peak10 -> pma11::Value
		global_cable36.getWrappedObject().getParameter().connectT(0, add96);     // global_cable36 -> add96::Value
		global_cable37.getWrappedObject().getParameter().connectT(0, add97);     // global_cable37 -> add97::Value
		global_cable38.getWrappedObject().getParameter().connectT(0, add98);     // global_cable38 -> add98::Value
		global_cable39.getWrappedObject().getParameter().connectT(0, add99);     // global_cable39 -> add99::Value
		pma12.getWrappedObject().getParameter().connectT(0, svf4);               // pma12 -> svf4::Frequency
		pma12.getWrappedObject().getParameter().connectT(1, svf2);               // pma12 -> svf2::Frequency
		pma12.getWrappedObject().getParameter().connectT(2, svf1);               // pma12 -> svf1::Frequency
		peak11.getParameter().connectT(0, pma12);                                // peak11 -> pma12::Value
		auto& switcher_p = switcher.getWrappedObject().getParameter();
		switcher_p.getParameterT(0).connectT(0, sb1); // switcher -> sb1::Bypassed
		switcher_p.getParameterT(1).connectT(0, sb2); // switcher -> sb2::Bypassed
		switcher_p.getParameterT(2).connectT(0, sb3); // switcher -> sb3::Bypassed
		auto& ahdsr1_p = ahdsr1.getWrappedObject().getParameter();
		ahdsr1_p.getParameterT(0).connectT(0, add11);         // ahdsr1 -> add11::Value
		ahdsr1_p.getParameterT(0).connectT(1, add25);         // ahdsr1 -> add25::Value
		ahdsr1_p.getParameterT(0).connectT(2, add79);         // ahdsr1 -> add79::Value
		ahdsr1_p.getParameterT(0).connectT(3, add80);         // ahdsr1 -> add80::Value
		ahdsr1_p.getParameterT(0).connectT(4, add81);         // ahdsr1 -> add81::Value
		ahdsr1_p.getParameterT(0).connectT(5, add85);         // ahdsr1 -> add85::Value
		ahdsr1_p.getParameterT(0).connectT(6, add95);         // ahdsr1 -> add95::Value
		ahdsr1_p.getParameterT(1).connectT(0, voice_manager); // ahdsr1 -> voice_manager::KillVoice
		ahdsr1_p.getParameterT(1).connectT(1, add82);         // ahdsr1 -> add82::Value
		
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
		
		; // add12::Value is automated
		
		; // cable_table2::Value is automated
		
		; // pma3::Value is automated
		; // pma3::Multiply is automated
		; // pma3::Add is automated
		
		;                            // gain13::Gain is automated
		gain13.setParameterT(1, 0.); // core::gain::Smoothing
		gain13.setParameterT(2, 0.); // core::gain::ResetValue
		
		;                             // minmax1::Value is automated
		minmax1.setParameterT(1, 0.); // control::minmax::Minimum
		minmax1.setParameterT(2, 1.); // control::minmax::Maximum
		minmax1.setParameterT(3, 1.); // control::minmax::Skew
		minmax1.setParameterT(4, 0.); // control::minmax::Step
		minmax1.setParameterT(5, 0.); // control::minmax::Polarity
		
		;                             // ahdsr2::Attack is automated
		ahdsr2.setParameterT(1, 1.);  // envelope::ahdsr::AttackLevel
		;                             // ahdsr2::Hold is automated
		;                             // ahdsr2::Decay is automated
		;                             // ahdsr2::Sustain is automated
		;                             // ahdsr2::Release is automated
		ahdsr2.setParameterT(6, 0.5); // envelope::ahdsr::AttackCurve
		ahdsr2.setParameterT(7, 0.);  // envelope::ahdsr::Retrigger
		ahdsr2.setParameterT(8, 0.);  // envelope::ahdsr::Gate
		
		; // add13::Value is automated
		
		; // cable_table3::Value is automated
		
		; // pma10::Value is automated
		; // pma10::Multiply is automated
		; // pma10::Add is automated
		
		;                            // gain14::Gain is automated
		gain14.setParameterT(1, 0.); // core::gain::Smoothing
		gain14.setParameterT(2, 0.); // core::gain::ResetValue
		
		;                             // minmax2::Value is automated
		minmax2.setParameterT(1, 0.); // control::minmax::Minimum
		minmax2.setParameterT(2, 1.); // control::minmax::Maximum
		minmax2.setParameterT(3, 1.); // control::minmax::Skew
		minmax2.setParameterT(4, 0.); // control::minmax::Step
		minmax2.setParameterT(5, 0.); // control::minmax::Polarity
		
		midi_cc1.setParameterT(0, 129.); // control::midi_cc::CCNumber
		midi_cc1.setParameterT(1, 0.);   // control::midi_cc::EnableMPE
		midi_cc1.setParameterT(2, 0.);   // control::midi_cc::DefaultValue
		
		; // branch4::Index is automated
		
		; // add6::Value is automated
		
		; // add7::Value is automated
		
		; // add11::Value is automated
		
		global_cable.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add::Value is automated
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add5::Value is automated
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add4::Value is automated
		
		global_cable3.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add1::Value is automated
		
		; // add8::Value is automated
		
		; // add9::Value is automated
		
		; // add10::Value is automated
		
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
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add20::Value is automated
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add21::Value is automated
		
		; // add22::Value is automated
		
		; // add23::Value is automated
		
		; // add24::Value is automated
		
		; // pma2::Value is automated
		; // pma2::Multiply is automated
		; // pma2::Add is automated
		
		clear5.setParameterT(0, 0.); // math::clear::Value
		
		; // branch9::Index is automated
		
		; // add34::Value is automated
		
		; // add35::Value is automated
		
		; // add79::Value is automated
		
		global_cable12.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add36::Value is automated
		
		global_cable13.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add37::Value is automated
		
		global_cable14.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add38::Value is automated
		
		global_cable15.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add39::Value is automated
		
		; // add40::Value is automated
		
		; // add41::Value is automated
		
		; // add42::Value is automated
		
		; // pma1::Value is automated
		; // pma1::Multiply is automated
		; // pma1::Add is automated
		
		clear7.setParameterT(0, 0.); // math::clear::Value
		
		; // branch10::Index is automated
		
		; // add43::Value is automated
		
		; // add44::Value is automated
		
		; // add80::Value is automated
		
		global_cable16.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add45::Value is automated
		
		global_cable17.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add46::Value is automated
		
		global_cable18.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add47::Value is automated
		
		global_cable19.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add48::Value is automated
		
		; // add49::Value is automated
		
		; // add50::Value is automated
		
		; // add51::Value is automated
		
		; // pma6::Value is automated
		; // pma6::Multiply is automated
		; // pma6::Add is automated
		
		clear8.setParameterT(0, 0.); // math::clear::Value
		
		; // branch11::Index is automated
		
		; // add52::Value is automated
		
		; // add53::Value is automated
		
		global_cable20.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add54::Value is automated
		
		global_cable21.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add55::Value is automated
		
		global_cable22.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add56::Value is automated
		
		global_cable23.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add57::Value is automated
		
		; // add58::Value is automated
		
		; // add59::Value is automated
		
		; // add60::Value is automated
		
		; // pma7::Value is automated
		; // pma7::Multiply is automated
		; // pma7::Add is automated
		
		clear9.setParameterT(0, 0.); // math::clear::Value
		
		; // branch12::Index is automated
		
		; // add61::Value is automated
		
		; // add62::Value is automated
		
		; // add82::Value is automated
		
		global_cable24.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add63::Value is automated
		
		global_cable25.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add64::Value is automated
		
		global_cable26.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add65::Value is automated
		
		global_cable27.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add66::Value is automated
		
		; // add67::Value is automated
		
		; // add68::Value is automated
		
		; // add69::Value is automated
		
		; // pma8::Value is automated
		; // pma8::Multiply is automated
		; // pma8::Add is automated
		
		clear10.setParameterT(0, 0.); // math::clear::Value
		
		; // branch13::Index is automated
		
		; // add70::Value is automated
		
		; // add71::Value is automated
		
		; // add81::Value is automated
		
		global_cable28.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add72::Value is automated
		
		global_cable29.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add73::Value is automated
		
		global_cable30.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add74::Value is automated
		
		global_cable31.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add75::Value is automated
		
		; // add76::Value is automated
		
		; // add77::Value is automated
		
		; // add78::Value is automated
		
		; // pma9::Value is automated
		; // pma9::Multiply is automated
		; // pma9::Add is automated
		
		clear11.setParameterT(0, 0.); // math::clear::Value
		
		; // branch14::Index is automated
		
		; // add83::Value is automated
		
		; // add84::Value is automated
		
		; // add85::Value is automated
		
		global_cable32.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add86::Value is automated
		
		global_cable33.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add87::Value is automated
		
		global_cable34.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add88::Value is automated
		
		global_cable35.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add89::Value is automated
		
		; // add90::Value is automated
		
		; // add91::Value is automated
		
		; // add92::Value is automated
		
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
		
		global_cable38.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add98::Value is automated
		
		global_cable39.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add99::Value is automated
		
		; // add100::Value is automated
		
		; // add101::Value is automated
		
		; // add102::Value is automated
		
		; // pma12::Value is automated
		; // pma12::Multiply is automated
		; // pma12::Add is automated
		
		clear13.setParameterT(0, 0.); // math::clear::Value
		
		;                                   // tempo_sync::Tempo is automated
		;                                   // tempo_sync::Multiplier is automated
		tempo_sync.setParameterT(2, 1.);    // control::tempo_sync::Enabled
		tempo_sync.setParameterT(3, 611.1); // control::tempo_sync::UnsyncedTime
		
		; // converter::Value is automated
		
		; // input_toggle::Input is automated
		; // input_toggle::Value1 is automated
		; // input_toggle::Value2 is automated
		
		;                          // pma4::Value is automated
		pma4.setParameterT(1, 0.); // control::pma::Multiply
		;                          // pma4::Add is automated
		
		; // branch1::Index is automated
		
		;                                 // minmax::Value is automated
		minmax.setParameterT(1, 0.5);     // control::minmax::Minimum
		minmax.setParameterT(2, 2.);      // control::minmax::Maximum
		minmax.setParameterT(3, 0.63093); // control::minmax::Skew
		minmax.setParameterT(4, 0.);      // control::minmax::Step
		minmax.setParameterT(5, 0.);      // control::minmax::Polarity
		
		;                                       // oscillator8::Mode is automated
		oscillator8.setParameterT(1, 134.7);    // core::oscillator::Frequency
		;                                       // oscillator8::FreqRatio is automated
		oscillator8.setParameterT(3, 1.);       // core::oscillator::Gate
		oscillator8.setParameterT(4, 0.451074); // core::oscillator::Phase
		;                                       // oscillator8::Gain is automated
		
		; // branch5::Index is automated
		
		; // branch6::Index is automated
		
		; // sampleandhold::Counter is automated
		
		file_player.setParameterT(0, 2.);   // core::file_player::PlaybackMode
		file_player.setParameterT(1, 1.);   // core::file_player::Gate
		file_player.setParameterT(2, 440.); // core::file_player::RootFrequency
		;                                   // file_player::FreqRatio is automated
		
		; // mul8::Value is automated
		
		; // branch16::Index is automated
		
		;                              // gain5::Gain is automated
		gain5.setParameterT(1, 16.6);  // core::gain::Smoothing
		gain5.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // mul::Value is automated
		
		;                              // gain6::Gain is automated
		gain6.setParameterT(1, 16.6);  // core::gain::Smoothing
		gain6.setParameterT(2, -100.); // core::gain::ResetValue
		
		; // mul2::Value is automated
		
		; // xfader::Value is automated
		
		;                             // gain1::Gain is automated
		gain1.setParameterT(1, 20.);  // core::gain::Smoothing
		gain1.setParameterT(2, -20.); // core::gain::ResetValue
		
		;                                          // smoothed_parameter1::Value is automated
		smoothed_parameter1.setParameterT(1, 0.1); // control::smoothed_parameter::SmoothingTime
		smoothed_parameter1.setParameterT(2, 1.);  // control::smoothed_parameter::Enabled
		
		; // branch3::Index is automated
		
		; // expr::Value is automated
		
		sub.setParameterT(0, 1.); // math::sub::Value
		
		pi.setParameterT(0, 1.); // math::pi::Value
		
		pi1.setParameterT(0, 1.); // math::pi::Value
		
		pi6.setParameterT(0, 1.); // math::pi::Value
		
		pi2.setParameterT(0, 1.); // math::pi::Value
		
		; // mul1::Value is automated
		
		pi3.setParameterT(0, 1.); // math::pi::Value
		
		; // fmod1::Value is automated
		
		;                                     // ring_mod2::Frequency is automated
		ring_mod2.setParameterT(1, 9.9);      // filters::ring_mod::Q
		ring_mod2.setParameterT(2, -3.98306); // filters::ring_mod::Gain
		ring_mod2.setParameterT(3, 0.01);     // filters::ring_mod::Smoothing
		ring_mod2.setParameterT(4, 0.);       // filters::ring_mod::Mode
		ring_mod2.setParameterT(5, 1.);       // filters::ring_mod::Enabled
		
		; // cable_table::Value is automated
		
		; // faust::delaylength is automated
		; // faust::graindensity is automated
		; // faust::grainlength is automated
		
		; // cable_table1::Value is automated
		
		;                            // faust1::decal is automated
		faust1.setParameterT(1, 2.); // core::faust::feedback
		;                            // faust1::population is automated
		faust1.setParameterT(3, 2);  // core::faust::speed
		;                            // faust1::taille is automated
		
		; // div2::Value is automated
		
		phasor_fm.setParameterT(0, 1.);       // core::phasor_fm::Gate
		phasor_fm.setParameterT(1, 440.);     // core::phasor_fm::Frequency
		;                                     // phasor_fm::FreqRatio is automated
		phasor_fm.setParameterT(3, 0.408846); // core::phasor_fm::Phase
		
		;                              // smoother::SmoothingTime is automated
		smoother.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		;                               // smoother3::SmoothingTime is automated
		smoother3.setParameterT(1, 0.); // core::smoother::DefaultValue
		
		;                             // gain2::Gain is automated
		gain2.setParameterT(1, 20.);  // core::gain::Smoothing
		gain2.setParameterT(2, -16.); // core::gain::ResetValue
		
		tanh.setParameterT(0, 0.165435); // math::tanh::Value
		
		;                                        // smoothed_parameter::Value is automated
		;                                        // smoothed_parameter::SmoothingTime is automated
		smoothed_parameter.setParameterT(2, 1.); // control::smoothed_parameter::Enabled
		
		; // branch2::Index is automated
		
		; // add2::Value is automated
		
		; // add3::Value is automated
		
		; // branch::Index is automated
		
		file_player3.setParameterT(0, 1.);       // core::file_player::PlaybackMode
		file_player3.setParameterT(1, 1.);       // core::file_player::Gate
		file_player3.setParameterT(2, 440.);     // core::file_player::RootFrequency
		file_player3.setParameterT(3, 0.882825); // core::file_player::FreqRatio
		
		file_player4.setParameterT(0, 1.);   // core::file_player::PlaybackMode
		file_player4.setParameterT(1, 1.);   // core::file_player::Gate
		file_player4.setParameterT(2, 440.); // core::file_player::RootFrequency
		file_player4.setParameterT(3, 0.89); // core::file_player::FreqRatio
		
		; // switcher::Value is automated
		
		;                               // ladder3::Frequency is automated
		;                               // ladder3::Q is automated
		ladder3.setParameterT(2, 0.);   // filters::ladder::Gain
		ladder3.setParameterT(3, 0.01); // filters::ladder::Smoothing
		ladder3.setParameterT(4, 0.);   // filters::ladder::Mode
		ladder3.setParameterT(5, 1.);   // filters::ladder::Enabled
		
		;                            // svf1::Frequency is automated
		;                            // svf1::Q is automated
		svf1.setParameterT(2, 0.);   // filters::svf::Gain
		svf1.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf1.setParameterT(4, 1.);   // filters::svf::Mode
		svf1.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                            // svf2::Frequency is automated
		;                            // svf2::Q is automated
		svf2.setParameterT(2, 0.);   // filters::svf::Gain
		svf2.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf2.setParameterT(4, 1.);   // filters::svf::Mode
		svf2.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                               // ladder4::Frequency is automated
		;                               // ladder4::Q is automated
		ladder4.setParameterT(2, 0.);   // filters::ladder::Gain
		ladder4.setParameterT(3, 0.01); // filters::ladder::Smoothing
		ladder4.setParameterT(4, 0.);   // filters::ladder::Mode
		ladder4.setParameterT(5, 1.);   // filters::ladder::Enabled
		
		;                               // ladder5::Frequency is automated
		;                               // ladder5::Q is automated
		ladder5.setParameterT(2, 0.);   // filters::ladder::Gain
		ladder5.setParameterT(3, 0.01); // filters::ladder::Smoothing
		ladder5.setParameterT(4, 0.);   // filters::ladder::Mode
		ladder5.setParameterT(5, 1.);   // filters::ladder::Enabled
		
		;                            // svf4::Frequency is automated
		;                            // svf4::Q is automated
		svf4.setParameterT(2, 0.);   // filters::svf::Gain
		svf4.setParameterT(3, 0.01); // filters::svf::Smoothing
		svf4.setParameterT(4, 1.);   // filters::svf::Mode
		svf4.setParameterT(5, 1.);   // filters::svf::Enabled
		
		;                             // ahdsr1::Attack is automated
		ahdsr1.setParameterT(1, 1.);  // envelope::ahdsr::AttackLevel
		;                             // ahdsr1::Hold is automated
		;                             // ahdsr1::Decay is automated
		;                             // ahdsr1::Sustain is automated
		;                             // ahdsr1::Release is automated
		ahdsr1.setParameterT(6, 0.5); // envelope::ahdsr::AttackCurve
		ahdsr1.setParameterT(7, 0.);  // envelope::ahdsr::Retrigger
		ahdsr1.setParameterT(8, 0.);  // envelope::ahdsr::Gate
		
		; // voice_manager::KillVoice is automated
		
		this->setParameterT(0, 19.);
		this->setParameterT(1, 63.1);
		this->setParameterT(2, 0.);
		this->setParameterT(3, 0.0946672);
		this->setParameterT(4, 2.08167e-17);
		this->setParameterT(5, 3.);
		this->setParameterT(6, -0.00121875);
		this->setParameterT(7, 2.08167e-17);
		this->setParameterT(8, 4.);
		this->setParameterT(9, 18.);
		this->setParameterT(10, 2.08167e-17);
		this->setParameterT(11, 4.);
		this->setParameterT(12, 0.);
		this->setParameterT(13, -0.0643682);
		this->setParameterT(14, 0.);
		this->setParameterT(15, 2.);
		this->setParameterT(16, 0.22);
		this->setParameterT(17, -0.608789);
		this->setParameterT(18, 2.);
		this->setParameterT(19, 3.);
		this->setParameterT(20, 0.66);
		this->setParameterT(21, 2.08167e-17);
		this->setParameterT(22, 8.90781);
		this->setParameterT(23, 0.);
		this->setParameterT(24, 1.);
		this->setParameterT(25, 4.);
		this->setParameterT(26, 1.);
		this->setParameterT(27, 1.);
		this->setParameterT(28, 0.220279);
		this->setParameterT(29, 3.);
		this->setParameterT(30, 0.);
		this->setParameterT(31, 7);
		this->setParameterT(32, 10000.);
		this->setParameterT(33, 1.);
		this->setParameterT(34, 1049.1);
		this->setParameterT(35, 0.);
		this->setParameterT(36, 0.);
		this->setParameterT(37, 0.);
		this->setParameterT(38, 1955.4);
		this->setParameterT(39, 0.);
		this->setParameterT(40, 78.2);
		this->setParameterT(41, 0.);
		this->setParameterT(42, 0.);
		this->setParameterT(43, 10000.);
		this->setParameterT(44, 10000.);
		this->setParameterT(45, 1.);
		this->setParameterT(46, 10000.);
		this->setParameterT(47, 0.310086);
		this->setParameterT(48, 0.);
		this->setParameterT(49, 0.761141);
		this->setParameterT(50, -0.00692187);
		this->setParameterT(51, 1.);
		this->setParameterT(52, 0.);
		this->setParameterT(53, 0.);
		this->setParameterT(54, 1.);
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
		
		this->getT(0).getT(1).getT(0).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable1_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable2_t<NV>
		this->getT(0).getT(1).getT(0).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable3_t<NV>
		this->getT(0).getT(1).getT(1).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable4_t<NV>
		this->getT(0).getT(1).getT(1).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable5_t<NV>
		this->getT(0).getT(1).getT(1).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable6_t<NV>
		this->getT(0).getT(1).getT(1).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable7_t<NV>
		this->getT(0).getT(1).getT(2).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable12_t<NV>
		this->getT(0).getT(1).getT(2).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable13_t<NV>
		this->getT(0).getT(1).getT(2).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable14_t<NV>
		this->getT(0).getT(1).getT(2).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable15_t<NV>
		this->getT(0).getT(1).getT(3).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable16_t<NV>
		this->getT(0).getT(1).getT(3).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable17_t<NV>
		this->getT(0).getT(1).getT(3).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable18_t<NV>
		this->getT(0).getT(1).getT(3).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable19_t<NV>
		this->getT(0).getT(1).getT(4).getT(0).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable20_t<NV>
		this->getT(0).getT(1).getT(4).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable21_t<NV>
		this->getT(0).getT(1).getT(4).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable22_t<NV>
		this->getT(0).getT(1).getT(4).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable23_t<NV>
		this->getT(0).getT(1).getT(5).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable24_t<NV>
		this->getT(0).getT(1).getT(5).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable25_t<NV>
		this->getT(0).getT(1).getT(5).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable26_t<NV>
		this->getT(0).getT(1).getT(5).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable27_t<NV>
		this->getT(0).getT(1).getT(6).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable28_t<NV>
		this->getT(0).getT(1).getT(6).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable29_t<NV>
		this->getT(0).getT(1).getT(6).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable30_t<NV>
		this->getT(0).getT(1).getT(6).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable31_t<NV>
		this->getT(0).getT(1).getT(7).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable32_t<NV>
		this->getT(0).getT(1).getT(7).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable33_t<NV>
		this->getT(0).getT(1).getT(7).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable34_t<NV>
		this->getT(0).getT(1).getT(7).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable35_t<NV>
		this->getT(0).getT(1).getT(8).getT(0).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable36_t<NV>
		this->getT(0).getT(1).getT(8).getT(0).getT(4).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable37_t<NV>
		this->getT(0).getT(1).getT(8).getT(0).getT(5).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable38_t<NV>
		this->getT(0).getT(1).getT(8).getT(0).getT(6).getT(0).connectToRuntimeTarget(addConnection, c); // filtest_impl::global_cable39_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).setExternalData(b, index);                         // filtest_impl::ahdsr_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(1).setExternalData(b, index);                 // filtest_impl::cable_table2_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(4).setExternalData(b, index);                 // filtest_impl::peak2_t<NV>
		this->getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);                         // filtest_impl::ahdsr2_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(1).setExternalData(b, index);                 // filtest_impl::cable_table3_t<NV>
		this->getT(0).getT(0).getT(1).getT(1).getT(4).setExternalData(b, index);                 // filtest_impl::peak4_t<NV>
		this->getT(0).getT(1).getT(0).getT(1).setExternalData(b, index);                         // filtest_impl::peak_t<NV>
		this->getT(0).getT(1).getT(1).getT(1).setExternalData(b, index);                         // filtest_impl::peak3_t<NV>
		this->getT(0).getT(1).getT(2).getT(1).setExternalData(b, index);                         // filtest_impl::peak5_t<NV>
		this->getT(0).getT(1).getT(3).getT(1).setExternalData(b, index);                         // filtest_impl::peak6_t<NV>
		this->getT(0).getT(1).getT(4).getT(1).setExternalData(b, index);                         // filtest_impl::peak7_t<NV>
		this->getT(0).getT(1).getT(5).getT(1).setExternalData(b, index);                         // filtest_impl::peak8_t<NV>
		this->getT(0).getT(1).getT(6).getT(1).setExternalData(b, index);                         // filtest_impl::peak9_t<NV>
		this->getT(0).getT(1).getT(7).getT(1).setExternalData(b, index);                         // filtest_impl::peak10_t<NV>
		this->getT(0).getT(1).getT(8).getT(1).setExternalData(b, index);                         // filtest_impl::peak11_t<NV>
		this->getT(5).getT(0).getT(1).setExternalData(b, index);                                 // filtest_impl::oscillator8_t<NV>
		this->getT(5).getT(1).getT(0).setExternalData(b, index);                                 // filtest_impl::file_player_t<NV>
		this->getT(7).setExternalData(b, index);                                                 // filtest_impl::oscilloscope_t
		this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(4).getT(0).setExternalData(b, index); // filtest_impl::cable_table_t<NV>
		this->getT(8).getT(0).getT(1).getT(1).getT(1).getT(5).getT(0).setExternalData(b, index); // filtest_impl::cable_table1_t<NV>
		this->getT(10).getT(2).getT(1).getT(0).getT(0).setExternalData(b, index);                // filtest_impl::file_player3_t<NV>
		this->getT(10).getT(2).getT(2).getT(0).setExternalData(b, index);                        // filtest_impl::file_player4_t<NV>
		this->getT(10).getT(3).setExternalData(b, index);                                        // filtest_impl::oscilloscope1_t
		this->getT(12).setExternalData(b, index);                                                // filtest_impl::ahdsr1_t<NV>
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


