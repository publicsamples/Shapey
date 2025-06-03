#pragma once

#include "osc1.h"
#include "oscshaper.h"
#include "files.h"
// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace NewArrange_impl
{
// ==============================| Node & Parameter type declarations |==============================

struct oscshaper_t_matrix
{
	static const int NumTables = 1;
	static const int NumSliderPacks = 3;
	static const int NumAudioFiles = 0;
	static const int NumFilters = 0;
	static const int NumDisplayBuffers = 0;
	
	// Index mapping matrix ------------------------------------------------------------------------
	
	const int matrix[3][3] =
	{
		{ 0, -1, -1 }, //  | 0->0
		{ 3, 4, 5 },   //  | 0->3 | 1->4 | 2->5
		{ -1, -1, -1 } // 
	};
};

template <int NV>
using oscshaper_t = wrap::data<project::oscshaper<NV>, 
                               data::matrix<oscshaper_t_matrix>>;

struct files_t_matrix
{
	static const int NumTables = 7;
	static const int NumSliderPacks = 15;
	static const int NumAudioFiles = 3;
	static const int NumFilters = 0;
	static const int NumDisplayBuffers = 0;
	
	// Index mapping matrix ------------------------------------------------------------------------
	
	const int matrix[3][15] =
	{
		{ 1, 2, 3, 4, 1000, 1001, 1002, -1, -1, -1, -1, -1, -1, -1, -1 },         //  | 0->1 | 1->2 | 2->3 | 3->4 | 4->e[0] | 5->e[1] | 6->e[2]
		{ 1003, 6, 7, 8, 9, 10, 11, 12, 13, 1004, 1005, 1006, 1007, 1008, 1009 }, //  | 0->e[3] | 1->6 | 2->7 | 3->8 | 4->9 | 5->10 | 6->11 | 7->12 | 8->13 | 9->e[4] | 10->e[5] | 11->e[6] | 12->e[7] | 13->e[8] | 14->e[9]
		{ 0, 1, 1010, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }            //  | 0->0 | 1->1 | 2->e[10]
	};
	
private:
	
	span<float, 512> d0 =
	{
		0.f, 0.00195694f, 0.00391388f, 0.00587082f, 0.00782776f, 0.00978476f,
		0.0117417f, 0.0136986f, 0.0156556f, 0.0176125f, 0.0195695f, 0.0215264f,
		0.0234834f, 0.0254403f, 0.0273973f, 0.0293542f, 0.0313112f, 0.0332681f,
		0.035225f, 0.037182f, 0.0391389f, 0.0410959f, 0.0430529f, 0.0450098f,
		0.0469667f, 0.0489237f, 0.0508806f, 0.0528376f, 0.0547945f, 0.0567515f,
		0.0587084f, 0.0606654f, 0.0626223f, 0.0645792f, 0.0665362f, 0.0684931f,
		0.0704501f, 0.0724071f, 0.074364f, 0.0763209f, 0.0782779f, 0.0802348f,
		0.0821918f, 0.0841487f, 0.0861057f, 0.0880626f, 0.0900196f, 0.0919765f,
		0.0939335f, 0.0958904f, 0.0978473f, 0.0998043f, 0.101761f, 0.103718f,
		0.105675f, 0.107632f, 0.109589f, 0.111546f, 0.113503f, 0.11546f,
		0.117417f, 0.119374f, 0.121331f, 0.123288f, 0.125245f, 0.127202f,
		0.129158f, 0.131115f, 0.133072f, 0.135029f, 0.136986f, 0.138943f,
		0.1409f, 0.142857f, 0.144814f, 0.146771f, 0.148728f, 0.150685f,
		0.152642f, 0.154599f, 0.156556f, 0.158513f, 0.16047f, 0.162427f,
		0.164384f, 0.166341f, 0.168297f, 0.170254f, 0.172211f, 0.174168f,
		0.176125f, 0.178082f, 0.180039f, 0.181996f, 0.183953f, 0.18591f,
		0.187867f, 0.189824f, 0.191781f, 0.193738f, 0.195695f, 0.197652f,
		0.199609f, 0.201566f, 0.203523f, 0.205479f, 0.207436f, 0.209393f,
		0.21135f, 0.213307f, 0.215264f, 0.217221f, 0.219178f, 0.221135f,
		0.223092f, 0.225049f, 0.227006f, 0.228963f, 0.23092f, 0.232877f,
		0.234834f, 0.236791f, 0.238748f, 0.240705f, 0.242661f, 0.244618f,
		0.246575f, 0.248532f, 0.250489f, 0.252446f, 0.254403f, 0.25636f,
		0.258317f, 0.260274f, 0.262231f, 0.264188f, 0.266145f, 0.268102f,
		0.270059f, 0.272016f, 0.273973f, 0.27593f, 0.277887f, 0.279843f,
		0.2818f, 0.283757f, 0.285714f, 0.287671f, 0.289628f, 0.291585f,
		0.293542f, 0.295499f, 0.297456f, 0.299413f, 0.30137f, 0.303327f,
		0.305284f, 0.307241f, 0.309198f, 0.311155f, 0.313112f, 0.315068f,
		0.317025f, 0.318982f, 0.320939f, 0.322896f, 0.324853f, 0.32681f,
		0.328767f, 0.330724f, 0.332681f, 0.334638f, 0.336595f, 0.338552f,
		0.340509f, 0.342466f, 0.344423f, 0.34638f, 0.348337f, 0.350294f,
		0.35225f, 0.354207f, 0.356164f, 0.358121f, 0.360078f, 0.362035f,
		0.363992f, 0.365949f, 0.367906f, 0.369863f, 0.37182f, 0.373777f,
		0.375734f, 0.377691f, 0.379648f, 0.381605f, 0.383562f, 0.385519f,
		0.387476f, 0.389432f, 0.391389f, 0.393346f, 0.395303f, 0.39726f,
		0.399217f, 0.401174f, 0.403131f, 0.405088f, 0.407045f, 0.409002f,
		0.410959f, 0.412916f, 0.414873f, 0.41683f, 0.418787f, 0.420744f,
		0.422701f, 0.424658f, 0.426615f, 0.428571f, 0.430528f, 0.432485f,
		0.434442f, 0.436399f, 0.438356f, 0.440313f, 0.44227f, 0.444227f,
		0.446184f, 0.448141f, 0.450098f, 0.452055f, 0.454012f, 0.455969f,
		0.457926f, 0.459883f, 0.46184f, 0.463796f, 0.465753f, 0.46771f,
		0.469667f, 0.471624f, 0.473581f, 0.475538f, 0.477495f, 0.479452f,
		0.481409f, 0.483366f, 0.485323f, 0.48728f, 0.489237f, 0.491194f,
		0.493151f, 0.495108f, 0.497065f, 0.499022f, 0.500978f, 0.502935f,
		0.504892f, 0.506849f, 0.508806f, 0.510763f, 0.51272f, 0.514677f,
		0.516634f, 0.518591f, 0.520548f, 0.522505f, 0.524462f, 0.526419f,
		0.528376f, 0.530333f, 0.53229f, 0.534247f, 0.536204f, 0.53816f,
		0.540117f, 0.542074f, 0.544031f, 0.545988f, 0.547945f, 0.549902f,
		0.551859f, 0.553816f, 0.555773f, 0.55773f, 0.559687f, 0.561644f,
		0.563601f, 0.565558f, 0.567515f, 0.569472f, 0.571429f, 0.573386f,
		0.575342f, 0.577299f, 0.579256f, 0.581213f, 0.58317f, 0.585127f,
		0.587084f, 0.589041f, 0.590998f, 0.592955f, 0.594912f, 0.596869f,
		0.598826f, 0.600783f, 0.60274f, 0.604697f, 0.606654f, 0.608611f,
		0.610568f, 0.612524f, 0.614481f, 0.616438f, 0.618395f, 0.620352f,
		0.622309f, 0.624266f, 0.626223f, 0.62818f, 0.630137f, 0.632094f,
		0.634051f, 0.636008f, 0.637965f, 0.639922f, 0.641879f, 0.643836f,
		0.645793f, 0.647749f, 0.649706f, 0.651663f, 0.65362f, 0.655577f,
		0.657534f, 0.659491f, 0.661448f, 0.663405f, 0.665362f, 0.667319f,
		0.669276f, 0.671233f, 0.67319f, 0.675147f, 0.677104f, 0.679061f,
		0.681018f, 0.682975f, 0.684932f, 0.686888f, 0.688845f, 0.690802f,
		0.692759f, 0.694716f, 0.696673f, 0.69863f, 0.700587f, 0.702544f,
		0.704501f, 0.706458f, 0.708415f, 0.710372f, 0.712329f, 0.714286f,
		0.716243f, 0.7182f, 0.720157f, 0.722113f, 0.72407f, 0.726027f,
		0.727984f, 0.729941f, 0.731898f, 0.733855f, 0.735812f, 0.737769f,
		0.739726f, 0.741683f, 0.74364f, 0.745597f, 0.747554f, 0.749511f,
		0.751468f, 0.753425f, 0.755382f, 0.757339f, 0.759296f, 0.761252f,
		0.763209f, 0.765166f, 0.767123f, 0.76908f, 0.771037f, 0.772994f,
		0.774951f, 0.776908f, 0.778865f, 0.780822f, 0.782779f, 0.784736f,
		0.786693f, 0.78865f, 0.790607f, 0.792564f, 0.794521f, 0.796477f,
		0.798434f, 0.800391f, 0.802348f, 0.804305f, 0.806262f, 0.808219f,
		0.810176f, 0.812133f, 0.81409f, 0.816047f, 0.818004f, 0.819961f,
		0.821918f, 0.823875f, 0.825832f, 0.827789f, 0.829746f, 0.831703f,
		0.833659f, 0.835616f, 0.837573f, 0.83953f, 0.841487f, 0.843444f,
		0.845401f, 0.847358f, 0.849315f, 0.851272f, 0.853229f, 0.855186f,
		0.857143f, 0.8591f, 0.861057f, 0.863014f, 0.864971f, 0.866928f,
		0.868885f, 0.870842f, 0.872798f, 0.874755f, 0.876712f, 0.878669f,
		0.880626f, 0.882583f, 0.88454f, 0.886497f, 0.888454f, 0.890411f,
		0.892368f, 0.894325f, 0.896282f, 0.898239f, 0.900196f, 0.902153f,
		0.90411f, 0.906067f, 0.908023f, 0.90998f, 0.911937f, 0.913894f,
		0.915851f, 0.917808f, 0.919765f, 0.921722f, 0.923679f, 0.925636f,
		0.927593f, 0.92955f, 0.931507f, 0.933464f, 0.935421f, 0.937378f,
		0.939335f, 0.941292f, 0.943249f, 0.945205f, 0.947162f, 0.949119f,
		0.951076f, 0.953033f, 0.95499f, 0.956947f, 0.958904f, 0.960861f,
		0.962818f, 0.964775f, 0.966732f, 0.968689f, 0.970646f, 0.972603f,
		0.97456f, 0.976517f, 0.978474f, 0.98043f, 0.982388f, 0.984344f,
		0.986301f, 0.988258f, 0.990215f, 0.992172f, 0.994129f, 0.996086f,
		0.998043f, 1.f
	};
	
	span<float, 512> d1 =
	{
		0.f, 0.00195694f, 0.00391388f, 0.00587082f, 0.00782776f, 0.00978476f,
		0.0117417f, 0.0136986f, 0.0156556f, 0.0176125f, 0.0195695f, 0.0215264f,
		0.0234834f, 0.0254403f, 0.0273973f, 0.0293542f, 0.0313112f, 0.0332681f,
		0.035225f, 0.037182f, 0.0391389f, 0.0410959f, 0.0430529f, 0.0450098f,
		0.0469667f, 0.0489237f, 0.0508806f, 0.0528376f, 0.0547945f, 0.0567515f,
		0.0587084f, 0.0606654f, 0.0626223f, 0.0645792f, 0.0665362f, 0.0684931f,
		0.0704501f, 0.0724071f, 0.074364f, 0.0763209f, 0.0782779f, 0.0802348f,
		0.0821918f, 0.0841487f, 0.0861057f, 0.0880626f, 0.0900196f, 0.0919765f,
		0.0939335f, 0.0958904f, 0.0978473f, 0.0998043f, 0.101761f, 0.103718f,
		0.105675f, 0.107632f, 0.109589f, 0.111546f, 0.113503f, 0.11546f,
		0.117417f, 0.119374f, 0.121331f, 0.123288f, 0.125245f, 0.127202f,
		0.129158f, 0.131115f, 0.133072f, 0.135029f, 0.136986f, 0.138943f,
		0.1409f, 0.142857f, 0.144814f, 0.146771f, 0.148728f, 0.150685f,
		0.152642f, 0.154599f, 0.156556f, 0.158513f, 0.16047f, 0.162427f,
		0.164384f, 0.166341f, 0.168297f, 0.170254f, 0.172211f, 0.174168f,
		0.176125f, 0.178082f, 0.180039f, 0.181996f, 0.183953f, 0.18591f,
		0.187867f, 0.189824f, 0.191781f, 0.193738f, 0.195695f, 0.197652f,
		0.199609f, 0.201566f, 0.203523f, 0.205479f, 0.207436f, 0.209393f,
		0.21135f, 0.213307f, 0.215264f, 0.217221f, 0.219178f, 0.221135f,
		0.223092f, 0.225049f, 0.227006f, 0.228963f, 0.23092f, 0.232877f,
		0.234834f, 0.236791f, 0.238748f, 0.240705f, 0.242661f, 0.244618f,
		0.246575f, 0.248532f, 0.250489f, 0.252446f, 0.254403f, 0.25636f,
		0.258317f, 0.260274f, 0.262231f, 0.264188f, 0.266145f, 0.268102f,
		0.270059f, 0.272016f, 0.273973f, 0.27593f, 0.277887f, 0.279843f,
		0.2818f, 0.283757f, 0.285714f, 0.287671f, 0.289628f, 0.291585f,
		0.293542f, 0.295499f, 0.297456f, 0.299413f, 0.30137f, 0.303327f,
		0.305284f, 0.307241f, 0.309198f, 0.311155f, 0.313112f, 0.315068f,
		0.317025f, 0.318982f, 0.320939f, 0.322896f, 0.324853f, 0.32681f,
		0.328767f, 0.330724f, 0.332681f, 0.334638f, 0.336595f, 0.338552f,
		0.340509f, 0.342466f, 0.344423f, 0.34638f, 0.348337f, 0.350294f,
		0.35225f, 0.354207f, 0.356164f, 0.358121f, 0.360078f, 0.362035f,
		0.363992f, 0.365949f, 0.367906f, 0.369863f, 0.37182f, 0.373777f,
		0.375734f, 0.377691f, 0.379648f, 0.381605f, 0.383562f, 0.385519f,
		0.387476f, 0.389432f, 0.391389f, 0.393346f, 0.395303f, 0.39726f,
		0.399217f, 0.401174f, 0.403131f, 0.405088f, 0.407045f, 0.409002f,
		0.410959f, 0.412916f, 0.414873f, 0.41683f, 0.418787f, 0.420744f,
		0.422701f, 0.424658f, 0.426615f, 0.428571f, 0.430528f, 0.432485f,
		0.434442f, 0.436399f, 0.438356f, 0.440313f, 0.44227f, 0.444227f,
		0.446184f, 0.448141f, 0.450098f, 0.452055f, 0.454012f, 0.455969f,
		0.457926f, 0.459883f, 0.46184f, 0.463796f, 0.465753f, 0.46771f,
		0.469667f, 0.471624f, 0.473581f, 0.475538f, 0.477495f, 0.479452f,
		0.481409f, 0.483366f, 0.485323f, 0.48728f, 0.489237f, 0.491194f,
		0.493151f, 0.495108f, 0.497065f, 0.499022f, 0.500978f, 0.502935f,
		0.504892f, 0.506849f, 0.508806f, 0.510763f, 0.51272f, 0.514677f,
		0.516634f, 0.518591f, 0.520548f, 0.522505f, 0.524462f, 0.526419f,
		0.528376f, 0.530333f, 0.53229f, 0.534247f, 0.536204f, 0.53816f,
		0.540117f, 0.542074f, 0.544031f, 0.545988f, 0.547945f, 0.549902f,
		0.551859f, 0.553816f, 0.555773f, 0.55773f, 0.559687f, 0.561644f,
		0.563601f, 0.565558f, 0.567515f, 0.569472f, 0.571429f, 0.573386f,
		0.575342f, 0.577299f, 0.579256f, 0.581213f, 0.58317f, 0.585127f,
		0.587084f, 0.589041f, 0.590998f, 0.592955f, 0.594912f, 0.596869f,
		0.598826f, 0.600783f, 0.60274f, 0.604697f, 0.606654f, 0.608611f,
		0.610568f, 0.612524f, 0.614481f, 0.616438f, 0.618395f, 0.620352f,
		0.622309f, 0.624266f, 0.626223f, 0.62818f, 0.630137f, 0.632094f,
		0.634051f, 0.636008f, 0.637965f, 0.639922f, 0.641879f, 0.643836f,
		0.645793f, 0.647749f, 0.649706f, 0.651663f, 0.65362f, 0.655577f,
		0.657534f, 0.659491f, 0.661448f, 0.663405f, 0.665362f, 0.667319f,
		0.669276f, 0.671233f, 0.67319f, 0.675147f, 0.677104f, 0.679061f,
		0.681018f, 0.682975f, 0.684932f, 0.686888f, 0.688845f, 0.690802f,
		0.692759f, 0.694716f, 0.696673f, 0.69863f, 0.700587f, 0.702544f,
		0.704501f, 0.706458f, 0.708415f, 0.710372f, 0.712329f, 0.714286f,
		0.716243f, 0.7182f, 0.720157f, 0.722113f, 0.72407f, 0.726027f,
		0.727984f, 0.729941f, 0.731898f, 0.733855f, 0.735812f, 0.737769f,
		0.739726f, 0.741683f, 0.74364f, 0.745597f, 0.747554f, 0.749511f,
		0.751468f, 0.753425f, 0.755382f, 0.757339f, 0.759296f, 0.761252f,
		0.763209f, 0.765166f, 0.767123f, 0.76908f, 0.771037f, 0.772994f,
		0.774951f, 0.776908f, 0.778865f, 0.780822f, 0.782779f, 0.784736f,
		0.786693f, 0.78865f, 0.790607f, 0.792564f, 0.794521f, 0.796477f,
		0.798434f, 0.800391f, 0.802348f, 0.804305f, 0.806262f, 0.808219f,
		0.810176f, 0.812133f, 0.81409f, 0.816047f, 0.818004f, 0.819961f,
		0.821918f, 0.823875f, 0.825832f, 0.827789f, 0.829746f, 0.831703f,
		0.833659f, 0.835616f, 0.837573f, 0.83953f, 0.841487f, 0.843444f,
		0.845401f, 0.847358f, 0.849315f, 0.851272f, 0.853229f, 0.855186f,
		0.857143f, 0.8591f, 0.861057f, 0.863014f, 0.864971f, 0.866928f,
		0.868885f, 0.870842f, 0.872798f, 0.874755f, 0.876712f, 0.878669f,
		0.880626f, 0.882583f, 0.88454f, 0.886497f, 0.888454f, 0.890411f,
		0.892368f, 0.894325f, 0.896282f, 0.898239f, 0.900196f, 0.902153f,
		0.90411f, 0.906067f, 0.908023f, 0.90998f, 0.911937f, 0.913894f,
		0.915851f, 0.917808f, 0.919765f, 0.921722f, 0.923679f, 0.925636f,
		0.927593f, 0.92955f, 0.931507f, 0.933464f, 0.935421f, 0.937378f,
		0.939335f, 0.941292f, 0.943249f, 0.945205f, 0.947162f, 0.949119f,
		0.951076f, 0.953033f, 0.95499f, 0.956947f, 0.958904f, 0.960861f,
		0.962818f, 0.964775f, 0.966732f, 0.968689f, 0.970646f, 0.972603f,
		0.97456f, 0.976517f, 0.978474f, 0.98043f, 0.982388f, 0.984344f,
		0.986301f, 0.988258f, 0.990215f, 0.992172f, 0.994129f, 0.996086f,
		0.998043f, 1.f
	};
	
	span<float, 512> d2 =
	{
		0.f, 0.00195694f, 0.00391388f, 0.00587082f, 0.00782776f, 0.00978476f,
		0.0117417f, 0.0136986f, 0.0156556f, 0.0176125f, 0.0195695f, 0.0215264f,
		0.0234834f, 0.0254403f, 0.0273973f, 0.0293542f, 0.0313112f, 0.0332681f,
		0.035225f, 0.037182f, 0.0391389f, 0.0410959f, 0.0430529f, 0.0450098f,
		0.0469667f, 0.0489237f, 0.0508806f, 0.0528376f, 0.0547945f, 0.0567515f,
		0.0587084f, 0.0606654f, 0.0626223f, 0.0645792f, 0.0665362f, 0.0684931f,
		0.0704501f, 0.0724071f, 0.074364f, 0.0763209f, 0.0782779f, 0.0802348f,
		0.0821918f, 0.0841487f, 0.0861057f, 0.0880626f, 0.0900196f, 0.0919765f,
		0.0939335f, 0.0958904f, 0.0978473f, 0.0998043f, 0.101761f, 0.103718f,
		0.105675f, 0.107632f, 0.109589f, 0.111546f, 0.113503f, 0.11546f,
		0.117417f, 0.119374f, 0.121331f, 0.123288f, 0.125245f, 0.127202f,
		0.129158f, 0.131115f, 0.133072f, 0.135029f, 0.136986f, 0.138943f,
		0.1409f, 0.142857f, 0.144814f, 0.146771f, 0.148728f, 0.150685f,
		0.152642f, 0.154599f, 0.156556f, 0.158513f, 0.16047f, 0.162427f,
		0.164384f, 0.166341f, 0.168297f, 0.170254f, 0.172211f, 0.174168f,
		0.176125f, 0.178082f, 0.180039f, 0.181996f, 0.183953f, 0.18591f,
		0.187867f, 0.189824f, 0.191781f, 0.193738f, 0.195695f, 0.197652f,
		0.199609f, 0.201566f, 0.203523f, 0.205479f, 0.207436f, 0.209393f,
		0.21135f, 0.213307f, 0.215264f, 0.217221f, 0.219178f, 0.221135f,
		0.223092f, 0.225049f, 0.227006f, 0.228963f, 0.23092f, 0.232877f,
		0.234834f, 0.236791f, 0.238748f, 0.240705f, 0.242661f, 0.244618f,
		0.246575f, 0.248532f, 0.250489f, 0.252446f, 0.254403f, 0.25636f,
		0.258317f, 0.260274f, 0.262231f, 0.264188f, 0.266145f, 0.268102f,
		0.270059f, 0.272016f, 0.273973f, 0.27593f, 0.277887f, 0.279843f,
		0.2818f, 0.283757f, 0.285714f, 0.287671f, 0.289628f, 0.291585f,
		0.293542f, 0.295499f, 0.297456f, 0.299413f, 0.30137f, 0.303327f,
		0.305284f, 0.307241f, 0.309198f, 0.311155f, 0.313112f, 0.315068f,
		0.317025f, 0.318982f, 0.320939f, 0.322896f, 0.324853f, 0.32681f,
		0.328767f, 0.330724f, 0.332681f, 0.334638f, 0.336595f, 0.338552f,
		0.340509f, 0.342466f, 0.344423f, 0.34638f, 0.348337f, 0.350294f,
		0.35225f, 0.354207f, 0.356164f, 0.358121f, 0.360078f, 0.362035f,
		0.363992f, 0.365949f, 0.367906f, 0.369863f, 0.37182f, 0.373777f,
		0.375734f, 0.377691f, 0.379648f, 0.381605f, 0.383562f, 0.385519f,
		0.387476f, 0.389432f, 0.391389f, 0.393346f, 0.395303f, 0.39726f,
		0.399217f, 0.401174f, 0.403131f, 0.405088f, 0.407045f, 0.409002f,
		0.410959f, 0.412916f, 0.414873f, 0.41683f, 0.418787f, 0.420744f,
		0.422701f, 0.424658f, 0.426615f, 0.428571f, 0.430528f, 0.432485f,
		0.434442f, 0.436399f, 0.438356f, 0.440313f, 0.44227f, 0.444227f,
		0.446184f, 0.448141f, 0.450098f, 0.452055f, 0.454012f, 0.455969f,
		0.457926f, 0.459883f, 0.46184f, 0.463796f, 0.465753f, 0.46771f,
		0.469667f, 0.471624f, 0.473581f, 0.475538f, 0.477495f, 0.479452f,
		0.481409f, 0.483366f, 0.485323f, 0.48728f, 0.489237f, 0.491194f,
		0.493151f, 0.495108f, 0.497065f, 0.499022f, 0.500978f, 0.502935f,
		0.504892f, 0.506849f, 0.508806f, 0.510763f, 0.51272f, 0.514677f,
		0.516634f, 0.518591f, 0.520548f, 0.522505f, 0.524462f, 0.526419f,
		0.528376f, 0.530333f, 0.53229f, 0.534247f, 0.536204f, 0.53816f,
		0.540117f, 0.542074f, 0.544031f, 0.545988f, 0.547945f, 0.549902f,
		0.551859f, 0.553816f, 0.555773f, 0.55773f, 0.559687f, 0.561644f,
		0.563601f, 0.565558f, 0.567515f, 0.569472f, 0.571429f, 0.573386f,
		0.575342f, 0.577299f, 0.579256f, 0.581213f, 0.58317f, 0.585127f,
		0.587084f, 0.589041f, 0.590998f, 0.592955f, 0.594912f, 0.596869f,
		0.598826f, 0.600783f, 0.60274f, 0.604697f, 0.606654f, 0.608611f,
		0.610568f, 0.612524f, 0.614481f, 0.616438f, 0.618395f, 0.620352f,
		0.622309f, 0.624266f, 0.626223f, 0.62818f, 0.630137f, 0.632094f,
		0.634051f, 0.636008f, 0.637965f, 0.639922f, 0.641879f, 0.643836f,
		0.645793f, 0.647749f, 0.649706f, 0.651663f, 0.65362f, 0.655577f,
		0.657534f, 0.659491f, 0.661448f, 0.663405f, 0.665362f, 0.667319f,
		0.669276f, 0.671233f, 0.67319f, 0.675147f, 0.677104f, 0.679061f,
		0.681018f, 0.682975f, 0.684932f, 0.686888f, 0.688845f, 0.690802f,
		0.692759f, 0.694716f, 0.696673f, 0.69863f, 0.700587f, 0.702544f,
		0.704501f, 0.706458f, 0.708415f, 0.710372f, 0.712329f, 0.714286f,
		0.716243f, 0.7182f, 0.720157f, 0.722113f, 0.72407f, 0.726027f,
		0.727984f, 0.729941f, 0.731898f, 0.733855f, 0.735812f, 0.737769f,
		0.739726f, 0.741683f, 0.74364f, 0.745597f, 0.747554f, 0.749511f,
		0.751468f, 0.753425f, 0.755382f, 0.757339f, 0.759296f, 0.761252f,
		0.763209f, 0.765166f, 0.767123f, 0.76908f, 0.771037f, 0.772994f,
		0.774951f, 0.776908f, 0.778865f, 0.780822f, 0.782779f, 0.784736f,
		0.786693f, 0.78865f, 0.790607f, 0.792564f, 0.794521f, 0.796477f,
		0.798434f, 0.800391f, 0.802348f, 0.804305f, 0.806262f, 0.808219f,
		0.810176f, 0.812133f, 0.81409f, 0.816047f, 0.818004f, 0.819961f,
		0.821918f, 0.823875f, 0.825832f, 0.827789f, 0.829746f, 0.831703f,
		0.833659f, 0.835616f, 0.837573f, 0.83953f, 0.841487f, 0.843444f,
		0.845401f, 0.847358f, 0.849315f, 0.851272f, 0.853229f, 0.855186f,
		0.857143f, 0.8591f, 0.861057f, 0.863014f, 0.864971f, 0.866928f,
		0.868885f, 0.870842f, 0.872798f, 0.874755f, 0.876712f, 0.878669f,
		0.880626f, 0.882583f, 0.88454f, 0.886497f, 0.888454f, 0.890411f,
		0.892368f, 0.894325f, 0.896282f, 0.898239f, 0.900196f, 0.902153f,
		0.90411f, 0.906067f, 0.908023f, 0.90998f, 0.911937f, 0.913894f,
		0.915851f, 0.917808f, 0.919765f, 0.921722f, 0.923679f, 0.925636f,
		0.927593f, 0.92955f, 0.931507f, 0.933464f, 0.935421f, 0.937378f,
		0.939335f, 0.941292f, 0.943249f, 0.945205f, 0.947162f, 0.949119f,
		0.951076f, 0.953033f, 0.95499f, 0.956947f, 0.958904f, 0.960861f,
		0.962818f, 0.964775f, 0.966732f, 0.968689f, 0.970646f, 0.972603f,
		0.97456f, 0.976517f, 0.978474f, 0.98043f, 0.982388f, 0.984344f,
		0.986301f, 0.988258f, 0.990215f, 0.992172f, 0.994129f, 0.996086f,
		0.998043f, 1.f
	};
	
	span<float, 4> d3 =
	{
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d4 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d5 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d6 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d7 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d8 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
	span<float, 16> d9 =
	{
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f
	};
	
public:
	
	const span<dyn<float>, 10> embeddedData = { d0, d1, d2, d3, d4, d5, d6, d7, d8, d9 };
};

template <int NV>
using files_t = wrap::data<project::files<NV>, 
                           data::matrix<files_t_matrix>>;

template <int NV>
using fix8_block_t_ = container::chain<parameter::empty, 
                                       wrap::fix<2, project::osc1<NV>>, 
                                       oscshaper_t<NV>, 
                                       files_t<NV>>;

template <int NV>
using fix8_block_t = wrap::fix_block<8, fix8_block_t_<NV>>;

namespace NewArrange_t_parameters
{
// Parameter list for NewArrange_impl::NewArrange_t ------------------------------------------------

DECLARE_PARAMETER_RANGE_STEP(pitchmode_InputRange, 
                             0., 
                             4., 
                             1.);
DECLARE_PARAMETER_RANGE_STEP(pitchmode_0Range, 
                             1., 
                             4., 
                             1.);

template <int NV>
using pitchmode_0 = parameter::from0To1<project::osc1<NV>, 
                                        3, 
                                        pitchmode_0Range>;

template <int NV>
using pitchmode = parameter::chain<pitchmode_InputRange, pitchmode_0<NV>>;

template <int NV>
using Pitch = parameter::plain<project::osc1<NV>, 0>;
template <int NV>
using tempo = parameter::plain<project::osc1<NV>, 1>;
template <int NV>
using div = parameter::plain<project::osc1<NV>, 2>;
template <int NV>
using step = parameter::plain<project::osc1<NV>, 4>;
template <int NV>
using Input = parameter::plain<project::osc1<NV>, 5>;
template <int NV>
using PitchMod = parameter::plain<project::osc1<NV>, 6>;
template <int NV>
using InputMod = parameter::plain<project::osc1<NV>, 7>;
template <int NV>
using harm = parameter::plain<project::osc1<NV>, 10>;
template <int NV>
using sync = parameter::plain<project::osc1<NV>, 11>;
template <int NV>
using LfoUnsync = parameter::plain<project::osc1<NV>, 12>;
template <int NV>
using XfstagePitch = parameter::plain<project::osc1<NV>, 13>;
template <int NV>
using MidiSlotPitch = parameter::plain<project::osc1<NV>, 14>;
template <int NV>
using XfstageInput = parameter::plain<project::osc1<NV>, 15>;
template <int NV>
using MidiSlotIn = parameter::plain<project::osc1<NV>, 16>;
template <int NV>
using XfstageOut = parameter::plain<project::osc1<NV>, 17>;
template <int NV>
using MidiSlotOut = parameter::plain<project::osc1<NV>, 18>;
template <int NV>
using Bend = parameter::plain<project::osc1<NV>, 19>;
template <int NV>
using shaper = parameter::plain<NewArrange_impl::oscshaper_t<NV>, 
                                0>;
template <int NV>
using width = parameter::plain<NewArrange_impl::oscshaper_t<NV>, 
                               1>;
template <int NV>
using out = parameter::plain<NewArrange_impl::oscshaper_t<NV>, 
                             2>;
template <int NV>
using shapemod = parameter::plain<NewArrange_impl::oscshaper_t<NV>, 
                                  3>;
template <int NV>
using widthmod = parameter::plain<NewArrange_impl::oscshaper_t<NV>, 
                                  4>;
template <int NV>
using outmod = parameter::plain<NewArrange_impl::oscshaper_t<NV>, 
                                5>;
template <int NV>
using XfStage = parameter::plain<NewArrange_impl::oscshaper_t<NV>, 
                                 6>;
template <int NV>
using Midi1 = parameter::plain<NewArrange_impl::oscshaper_t<NV>, 
                               7>;
template <int NV>
using xf2 = parameter::plain<NewArrange_impl::oscshaper_t<NV>, 
                             8>;
template <int NV>
using xf3 = parameter::plain<NewArrange_impl::oscshaper_t<NV>, 
                             9>;
template <int NV>
using midi2 = parameter::plain<NewArrange_impl::oscshaper_t<NV>, 
                               10>;
template <int NV>
using midi3 = parameter::plain<NewArrange_impl::oscshaper_t<NV>, 
                               11>;
template <int NV>
using smooth = parameter::plain<NewArrange_impl::files_t<NV>, 
                                0>;
template <int NV>
using quant = parameter::plain<NewArrange_impl::files_t<NV>, 
                               1>;
template <int NV>
using Position = parameter::plain<NewArrange_impl::files_t<NV>, 
                                  2>;
template <int NV>
using input = parameter::plain<NewArrange_impl::files_t<NV>, 
                               3>;
template <int NV>
using Win = parameter::plain<NewArrange_impl::files_t<NV>, 
                             4>;
template <int NV>
using Xf = parameter::plain<NewArrange_impl::files_t<NV>, 
                            5>;
template <int NV>
using shift = parameter::plain<NewArrange_impl::files_t<NV>, 
                               6>;
template <int NV>
using pitch = parameter::plain<NewArrange_impl::files_t<NV>, 
                               7>;
template <int NV>
using Mix = parameter::plain<NewArrange_impl::files_t<NV>, 
                             8>;
template <int NV>
using PositionTempoMod = parameter::plain<NewArrange_impl::files_t<NV>, 
                                          9>;
template <int NV>
using PsMod = parameter::plain<NewArrange_impl::files_t<NV>, 
                               10>;
template <int NV>
using FileInMod = parameter::plain<NewArrange_impl::files_t<NV>, 
                                   11>;
template <int NV>
using XfFStage1 = parameter::plain<NewArrange_impl::files_t<NV>, 
                                   12>;
template <int NV>
using IntMod = parameter::plain<NewArrange_impl::files_t<NV>, 
                                13>;
template <int NV>
using IntModSteps = parameter::plain<NewArrange_impl::files_t<NV>, 
                                     14>;
template <int NV>
using IntModOne = parameter::plain<NewArrange_impl::files_t<NV>, 
                                   15>;
template <int NV>
using intmodtempo = parameter::plain<NewArrange_impl::files_t<NV>, 
                                     16>;
template <int NV>
using Inmoddiv = parameter::plain<NewArrange_impl::files_t<NV>, 
                                  17>;
template <int NV>
using fb = parameter::plain<NewArrange_impl::files_t<NV>, 
                            18>;
template <int NV>
using tablestep = parameter::plain<NewArrange_impl::files_t<NV>, 
                                   19>;
template <int NV>
using Fmidi1 = parameter::plain<NewArrange_impl::files_t<NV>, 
                                20>;
template <int NV>
using fmidi2 = parameter::plain<NewArrange_impl::files_t<NV>, 
                                21>;
template <int NV>
using fmidi3 = parameter::plain<NewArrange_impl::files_t<NV>, 
                                22>;
template <int NV>
using fmidi4 = parameter::plain<NewArrange_impl::files_t<NV>, 
                                33>;
template <int NV>
using fmidi5 = parameter::plain<NewArrange_impl::files_t<NV>, 
                                34>;
template <int NV>
using fmidi6 = parameter::plain<NewArrange_impl::files_t<NV>, 
                                39>;
template <int NV>
using fmidi7 = parameter::plain<NewArrange_impl::files_t<NV>, 
                                40>;
template <int NV>
using fmidi8 = parameter::plain<NewArrange_impl::files_t<NV>, 
                                41>;
template <int NV>
using Xfstg2 = parameter::plain<NewArrange_impl::files_t<NV>, 
                                23>;
template <int NV>
using XfStg3 = parameter::plain<NewArrange_impl::files_t<NV>, 
                                24>;
template <int NV>
using XfStg4 = parameter::plain<NewArrange_impl::files_t<NV>, 
                                31>;
template <int NV>
using XfStg5 = parameter::plain<NewArrange_impl::files_t<NV>, 
                                32>;
template <int NV>
using XfStg6 = parameter::plain<NewArrange_impl::files_t<NV>, 
                                42>;
template <int NV>
using XfStg7 = parameter::plain<NewArrange_impl::files_t<NV>, 
                                43>;
template <int NV>
using XfStg8 = parameter::plain<NewArrange_impl::files_t<NV>, 
                                44>;
template <int NV>
using UserMode = parameter::plain<NewArrange_impl::files_t<NV>, 
                                  25>;
template <int NV>
using WinSync = parameter::plain<NewArrange_impl::files_t<NV>, 
                                 26>;
template <int NV>
using WinTempo = parameter::plain<NewArrange_impl::files_t<NV>, 
                                  27>;
template <int NV>
using XfTempo = parameter::plain<NewArrange_impl::files_t<NV>, 
                                 28>;
template <int NV>
using WinMod = parameter::plain<NewArrange_impl::files_t<NV>, 
                                29>;
template <int NV>
using XfMod = parameter::plain<NewArrange_impl::files_t<NV>, 
                               30>;
template <int NV>
using InmodClk = parameter::plain<NewArrange_impl::files_t<NV>, 
                                  35>;
template <int NV>
using InTempoMod = parameter::plain<NewArrange_impl::files_t<NV>, 
                                    36>;
template <int NV>
using SmoothMod = parameter::plain<NewArrange_impl::files_t<NV>, 
                                   37>;
template <int NV>
using MixMod = parameter::plain<NewArrange_impl::files_t<NV>, 
                                38>;
template <int NV>
using NewArrange_t_plist = parameter::list<Pitch<NV>, 
                                           tempo<NV>, 
                                           div<NV>, 
                                           pitchmode<NV>, 
                                           step<NV>, 
                                           Input<NV>, 
                                           PitchMod<NV>, 
                                           InputMod<NV>, 
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
                                           shaper<NV>, 
                                           width<NV>, 
                                           out<NV>, 
                                           shapemod<NV>, 
                                           widthmod<NV>, 
                                           outmod<NV>, 
                                           XfStage<NV>, 
                                           Midi1<NV>, 
                                           xf2<NV>, 
                                           xf3<NV>, 
                                           midi2<NV>, 
                                           midi3<NV>, 
                                           smooth<NV>, 
                                           quant<NV>, 
                                           Position<NV>, 
                                           input<NV>, 
                                           Win<NV>, 
                                           Xf<NV>, 
                                           shift<NV>, 
                                           pitch<NV>, 
                                           Mix<NV>, 
                                           PositionTempoMod<NV>, 
                                           PsMod<NV>, 
                                           FileInMod<NV>, 
                                           XfFStage1<NV>, 
                                           IntMod<NV>, 
                                           IntModSteps<NV>, 
                                           IntModOne<NV>, 
                                           intmodtempo<NV>, 
                                           Inmoddiv<NV>, 
                                           fb<NV>, 
                                           tablestep<NV>, 
                                           Fmidi1<NV>, 
                                           fmidi2<NV>, 
                                           fmidi3<NV>, 
                                           fmidi4<NV>, 
                                           fmidi5<NV>, 
                                           fmidi6<NV>, 
                                           fmidi7<NV>, 
                                           fmidi8<NV>, 
                                           Xfstg2<NV>, 
                                           XfStg3<NV>, 
                                           XfStg4<NV>, 
                                           XfStg5<NV>, 
                                           XfStg6<NV>, 
                                           XfStg7<NV>, 
                                           XfStg8<NV>, 
                                           UserMode<NV>, 
                                           WinSync<NV>, 
                                           WinTempo<NV>, 
                                           XfTempo<NV>, 
                                           WinMod<NV>, 
                                           XfMod<NV>, 
                                           InmodClk<NV>, 
                                           InTempoMod<NV>, 
                                           SmoothMod<NV>, 
                                           MixMod<NV>>;
}

template <int NV>
using NewArrange_t_ = container::chain<NewArrange_t_parameters::NewArrange_t_plist<NV>, 
                                       wrap::fix<2, fix8_block_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public NewArrange_impl::NewArrange_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 5;
		static const int NumSliderPacks = 14;
		static const int NumAudioFiles = 2;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(NewArrange);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(1226)
		{
			0x005B, 0x0000, 0x5000, 0x7469, 0x6863, 0x0000, 0xC000, 0x00C1, 
            0xC000, 0xDF41, 0x6BF4, 0x00C1, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0001, 0x0000, 0x6574, 0x706D, 0x006F, 0x0000, 0x0000, 0x0000, 
            0x4190, 0xFA6F, 0x4010, 0x0000, 0x3F80, 0x0000, 0x0000, 0x025B, 
            0x0000, 0x6400, 0x7669, 0x0000, 0x8000, 0x003F, 0x0000, 0x0042, 
            0x0000, 0x0042, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0003, 0x0000, 
            0x6970, 0x6374, 0x6D68, 0x646F, 0x0065, 0x0000, 0x0000, 0x0000, 
            0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x045B, 
            0x0000, 0x7300, 0x6574, 0x0070, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x055B, 0x0000, 
            0x4900, 0x706E, 0x7475, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0006, 0x0000, 
            0x6950, 0x6374, 0x4D68, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 
            0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0007, 
            0x0000, 0x6E49, 0x7570, 0x4D74, 0x646F, 0x0000, 0x8000, 0x00BF, 
            0x8000, 0x213F, 0xD10B, 0x00BD, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0008, 0x0000, 0x6168, 0x6D72, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0009, 
            0x0000, 0x7973, 0x636E, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000A, 0x0000, 
            0x664C, 0x556F, 0x736E, 0x6E79, 0x0063, 0x0000, 0x0000, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0B5B, 
            0x0000, 0x5800, 0x7366, 0x6174, 0x6567, 0x6950, 0x6374, 0x0068, 
            0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0C5B, 0x0000, 0x4D00, 0x6469, 0x5369, 0x6F6C, 
            0x5074, 0x7469, 0x6863, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 
            0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000D, 0x0000, 
            0x6658, 0x7473, 0x6761, 0x4965, 0x706E, 0x7475, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x000E, 0x0000, 0x694D, 0x6964, 0x6C53, 0x746F, 0x6E49, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x000F, 0x0000, 0x6658, 0x7473, 0x6761, 
            0x4F65, 0x7475, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x86C0, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0010, 0x0000, 0x694D, 
            0x6964, 0x6C53, 0x746F, 0x754F, 0x0074, 0x0000, 0x3F80, 0x0000, 
            0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x115B, 
            0x0000, 0x4200, 0x6E65, 0x0064, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x8591, 0x3EEF, 0x0000, 0x3F80, 0x0000, 0x0000, 0x125B, 0x0000, 
            0x7300, 0x6168, 0x6570, 0x0072, 0x0000, 0x3F80, 0x0000, 0x4100, 
            0x7BD3, 0x403F, 0x0000, 0x3F80, 0x0000, 0x0000, 0x135B, 0x0000, 
            0x7700, 0x6469, 0x6874, 0x0000, 0x0000, 0x0000, 0x8000, 0xC83F, 
            0xD342, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0014, 0x0000, 
            0x756F, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 0xE9BD, 0x3E3B, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x155B, 0x0000, 0x7300, 0x6168, 
            0x6570, 0x6F6D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x165B, 0x0000, 0x7700, 
            0x6469, 0x6874, 0x6F6D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x175B, 0x0000, 
            0x6F00, 0x7475, 0x6F6D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x185B, 0x0000, 
            0x5800, 0x5366, 0x6174, 0x6567, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0019, 
            0x0000, 0x694D, 0x6964, 0x0031, 0x0000, 0x3F80, 0x0000, 0x40E0, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x1A5B, 0x0000, 
            0x7800, 0x3266, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x001B, 0x0000, 0x6678, 
            0x0033, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0333, 0x3F81, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x1C5B, 0x0000, 0x6D00, 0x6469, 0x3269, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x001D, 0x0000, 0x696D, 0x6964, 0x0033, 
            0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x1E5B, 0x0000, 0x7300, 0x6F6D, 0x746F, 0x0068, 
            0x0000, 0x0000, 0x0000, 0x44FA, 0x0000, 0x3F80, 0xEE69, 0x3E6C, 
            0xCCCD, 0x3DCC, 0x1F5B, 0x0000, 0x7100, 0x6175, 0x746E, 0x0000, 
            0x8000, 0x003F, 0x1000, 0x0041, 0x8000, 0x003F, 0x8000, 0x003F, 
            0x8000, 0x5B3F, 0x0020, 0x0000, 0x6F50, 0x6973, 0x6974, 0x6E6F, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x433F, 0xA916, 0x003E, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0021, 0x0000, 0x6E69, 0x7570, 0x0074, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x225B, 0x0000, 0x5700, 0x6E69, 0x0000, 0x0000, 
            0x0000, 0x7A00, 0x0044, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0023, 0x0000, 0x6658, 0x0000, 0x0000, 0x0000, 0x7A00, 
            0xF544, 0xA236, 0x0040, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0024, 
            0x0000, 0x6873, 0x6669, 0x0074, 0x0000, 0x3F80, 0x0000, 0x4040, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x255B, 0x0000, 
            0x7000, 0x7469, 0x6863, 0x0000, 0xC000, 0x00C1, 0xC000, 0xDB41, 
            0x7EF9, 0x003A, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0026, 0x0000, 
            0x694D, 0x0078, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x275B, 0x0000, 0x5000, 0x736F, 
            0x7469, 0x6F69, 0x546E, 0x6D65, 0x6F70, 0x6F4D, 0x0064, 0x0000, 
            0xBF80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x285B, 0x0000, 0x5000, 0x4D73, 0x646F, 0x0000, 0x8000, 
            0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 
            0x5B00, 0x0029, 0x0000, 0x6946, 0x656C, 0x6E49, 0x6F4D, 0x0064, 
            0x0000, 0xBF80, 0x0000, 0x3F80, 0x1AA0, 0x3A7B, 0x0000, 0x3F80, 
            0x0000, 0x0000, 0x2A5B, 0x0000, 0x5800, 0x4666, 0x7453, 0x6761, 
            0x3165, 0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 
            0x8000, 0x003F, 0x8000, 0x5B3F, 0x002B, 0x0000, 0x6E49, 0x4D74, 
            0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x5B00, 0x002C, 0x0000, 0x6E49, 0x4D74, 
            0x646F, 0x7453, 0x7065, 0x0073, 0x0000, 0x4080, 0x0000, 0x4280, 
            0x0000, 0x4080, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x2D5B, 0x0000, 
            0x4900, 0x746E, 0x6F4D, 0x4F64, 0x656E, 0x0000, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x002E, 0x0000, 0x6E69, 0x6D74, 0x646F, 0x6574, 0x706D, 0x006F, 
            0x0000, 0x0000, 0x0000, 0x4190, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x2F5B, 0x0000, 0x4900, 0x6D6E, 0x646F, 0x6964, 
            0x0076, 0x0000, 0x3F80, 0x0000, 0x4200, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x305B, 0x0000, 0x6600, 0x0062, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x315B, 0x0000, 0x7400, 0x6261, 0x656C, 0x7473, 0x7065, 
            0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0032, 0x0000, 0x6D46, 0x6469, 0x3169, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0033, 0x0000, 0x6D66, 0x6469, 0x3269, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0034, 0x0000, 0x6D66, 0x6469, 0x3369, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0035, 0x0000, 0x6D66, 0x6469, 0x3469, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0036, 0x0000, 0x6D66, 0x6469, 0x3569, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x0037, 0x0000, 0x6D66, 0x6469, 0x3669, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0038, 0x0000, 0x6D66, 0x6469, 0x3769, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0039, 0x0000, 0x6D66, 0x6469, 0x3869, 
            0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x003A, 0x0000, 0x6658, 0x7473, 0x3267, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x003B, 0x0000, 0x6658, 0x7453, 0x3367, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x003C, 0x0000, 0x6658, 0x7453, 0x3467, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x8000, 0x5B3F, 0x003D, 0x0000, 0x6658, 0x7453, 0x3567, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x003E, 0x0000, 0x6658, 0x7453, 0x3667, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x003F, 0x0000, 0x6658, 0x7453, 0x3767, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0040, 0x0000, 0x6658, 0x7453, 0x3867, 
            0x0000, 0x8000, 0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 
            0x003F, 0x0000, 0x5B00, 0x0041, 0x0000, 0x7355, 0x7265, 0x6F4D, 
            0x6564, 0x0000, 0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x0000, 
            0x8000, 0x003F, 0x8000, 0x5B3F, 0x0042, 0x0000, 0x6957, 0x536E, 
            0x6E79, 0x0063, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x435B, 0x0000, 0x5700, 0x6E69, 
            0x6554, 0x706D, 0x006F, 0x0000, 0xC180, 0x0000, 0x4190, 0x0000, 
            0xC110, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x445B, 0x0000, 0x5800, 
            0x5466, 0x6D65, 0x6F70, 0x0000, 0x8000, 0x00C1, 0x9000, 0x0041, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x8000, 0x5B3F, 0x0045, 0x0000, 
            0x6957, 0x4D6E, 0x646F, 0x0000, 0x8000, 0x00BF, 0x8000, 0x003F, 
            0x0000, 0x0000, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0046, 0x0000, 
            0x6658, 0x6F4D, 0x0064, 0x0000, 0xBF80, 0x0000, 0x3F80, 0x0000, 
            0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x475B, 0x0000, 0x4900, 
            0x6D6E, 0x646F, 0x6C43, 0x006B, 0x0000, 0x0000, 0x0000, 0x4000, 
            0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x485B, 0x0000, 
            0x4900, 0x546E, 0x6D65, 0x6F70, 0x6F4D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x495B, 0x0000, 0x5300, 0x6F6D, 0x746F, 0x4D68, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x5B00, 0x004A, 0x0000, 0x694D, 0x4D78, 0x646F, 0x0000, 
            0x8000, 0x00BF, 0x8000, 0x003F, 0x0000, 0x0000, 0x8000, 0x003F, 
            0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& fix8_block = this->getT(0);        // NewArrange_impl::fix8_block_t<NV>
		auto& osc1 = this->getT(0).getT(0);      // project::osc1<NV>
		auto& oscshaper = this->getT(0).getT(1); // NewArrange_impl::oscshaper_t<NV>
		auto& files = this->getT(0).getT(2);     // NewArrange_impl::files_t<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, osc1); // Pitch -> osc1::Pitch
		
		this->getParameterT(1).connectT(0, osc1); // tempo -> osc1::tempo
		
		this->getParameterT(2).connectT(0, osc1); // div -> osc1::div
		
		this->getParameterT(3).connectT(0, osc1); // pitchmode -> osc1::pitchmode
		
		this->getParameterT(4).connectT(0, osc1); // step -> osc1::step
		
		this->getParameterT(5).connectT(0, osc1); // Input -> osc1::Input
		
		this->getParameterT(6).connectT(0, osc1); // PitchMod -> osc1::PitchMod
		
		this->getParameterT(7).connectT(0, osc1); // InputMod -> osc1::InputMod
		
		this->getParameterT(8).connectT(0, osc1); // harm -> osc1::harm
		
		this->getParameterT(9).connectT(0, osc1); // sync -> osc1::sync
		
		this->getParameterT(10).connectT(0, osc1); // LfoUnsync -> osc1::LfoUnsync
		
		this->getParameterT(11).connectT(0, osc1); // XfstagePitch -> osc1::XfstagePitch
		
		this->getParameterT(12).connectT(0, osc1); // MidiSlotPitch -> osc1::MidiSlotPitch
		
		this->getParameterT(13).connectT(0, osc1); // XfstageInput -> osc1::XfstageInput
		
		this->getParameterT(14).connectT(0, osc1); // MidiSlotIn -> osc1::MidiSlotIn
		
		this->getParameterT(15).connectT(0, osc1); // XfstageOut -> osc1::XfstageOut
		
		this->getParameterT(16).connectT(0, osc1); // MidiSlotOut -> osc1::MidiSlotOut
		
		this->getParameterT(17).connectT(0, osc1); // Bend -> osc1::Bend
		
		this->getParameterT(18).connectT(0, oscshaper); // shaper -> oscshaper::shaper
		
		this->getParameterT(19).connectT(0, oscshaper); // width -> oscshaper::width
		
		this->getParameterT(20).connectT(0, oscshaper); // out -> oscshaper::out
		
		this->getParameterT(21).connectT(0, oscshaper); // shapemod -> oscshaper::shapemod
		
		this->getParameterT(22).connectT(0, oscshaper); // widthmod -> oscshaper::widthmod
		
		this->getParameterT(23).connectT(0, oscshaper); // outmod -> oscshaper::outmod
		
		this->getParameterT(24).connectT(0, oscshaper); // XfStage -> oscshaper::XfStage
		
		this->getParameterT(25).connectT(0, oscshaper); // Midi1 -> oscshaper::Midi1
		
		this->getParameterT(26).connectT(0, oscshaper); // xf2 -> oscshaper::xf2
		
		this->getParameterT(27).connectT(0, oscshaper); // xf3 -> oscshaper::xf3
		
		this->getParameterT(28).connectT(0, oscshaper); // midi2 -> oscshaper::midi2
		
		this->getParameterT(29).connectT(0, oscshaper); // midi3 -> oscshaper::midi3
		
		this->getParameterT(30).connectT(0, files); // smooth -> files::smooth
		
		this->getParameterT(31).connectT(0, files); // quant -> files::quant
		
		this->getParameterT(32).connectT(0, files); // Position -> files::Position
		
		this->getParameterT(33).connectT(0, files); // input -> files::Input
		
		this->getParameterT(34).connectT(0, files); // Win -> files::Win
		
		this->getParameterT(35).connectT(0, files); // Xf -> files::Xf
		
		this->getParameterT(36).connectT(0, files); // shift -> files::shift
		
		this->getParameterT(37).connectT(0, files); // pitch -> files::pitch
		
		this->getParameterT(38).connectT(0, files); // Mix -> files::Mix
		
		this->getParameterT(39).connectT(0, files); // PositionTempoMod -> files::PositionTempoMod
		
		this->getParameterT(40).connectT(0, files); // PsMod -> files::PitchMod
		
		this->getParameterT(41).connectT(0, files); // FileInMod -> files::InputMod
		
		this->getParameterT(42).connectT(0, files); // XfFStage1 -> files::XfStage
		
		this->getParameterT(43).connectT(0, files); // IntMod -> files::IntMod
		
		this->getParameterT(44).connectT(0, files); // IntModSteps -> files::IntModSteps
		
		this->getParameterT(45).connectT(0, files); // IntModOne -> files::IntmodOne
		
		this->getParameterT(46).connectT(0, files); // intmodtempo -> files::intmodtempo
		
		this->getParameterT(47).connectT(0, files); // Inmoddiv -> files::InmodDiv
		
		this->getParameterT(48).connectT(0, files); // fb -> files::fb
		
		this->getParameterT(49).connectT(0, files); // tablestep -> files::tablestep
		
		this->getParameterT(50).connectT(0, files); // Fmidi1 -> files::Midi1
		
		this->getParameterT(51).connectT(0, files); // fmidi2 -> files::Midi2
		
		this->getParameterT(52).connectT(0, files); // fmidi3 -> files::Midi3
		
		this->getParameterT(53).connectT(0, files); // fmidi4 -> files::midi4
		
		this->getParameterT(54).connectT(0, files); // fmidi5 -> files::mid5
		
		this->getParameterT(55).connectT(0, files); // fmidi6 -> files::Midi6
		
		this->getParameterT(56).connectT(0, files); // fmidi7 -> files::Midi7
		
		this->getParameterT(57).connectT(0, files); // fmidi8 -> files::Midi8
		
		this->getParameterT(58).connectT(0, files); // Xfstg2 -> files::xf2
		
		this->getParameterT(59).connectT(0, files); // XfStg3 -> files::xf3
		
		this->getParameterT(60).connectT(0, files); // XfStg4 -> files::xf4
		
		this->getParameterT(61).connectT(0, files); // XfStg5 -> files::xf5
		
		this->getParameterT(62).connectT(0, files); // XfStg6 -> files::XfStage6
		
		this->getParameterT(63).connectT(0, files); // XfStg7 -> files::XfStage7
		
		this->getParameterT(64).connectT(0, files); // XfStg8 -> files::XfStage8
		
		this->getParameterT(65).connectT(0, files); // UserMode -> files::UserMode
		
		this->getParameterT(66).connectT(0, files); // WinSync -> files::WinSync
		
		this->getParameterT(67).connectT(0, files); // WinTempo -> files::WinTempo
		
		this->getParameterT(68).connectT(0, files); // XfTempo -> files::XfTempo
		
		this->getParameterT(69).connectT(0, files); // WinMod -> files::WinMod
		
		this->getParameterT(70).connectT(0, files); // XfMod -> files::XfMod
		
		this->getParameterT(71).connectT(0, files); // InmodClk -> files::InmodClk
		
		this->getParameterT(72).connectT(0, files); // InTempoMod -> files::InTempoMod
		
		this->getParameterT(73).connectT(0, files); // SmoothMod -> files::SmoothMod
		
		this->getParameterT(74).connectT(0, files); // MixMod -> files::MixMod
		
		// Default Values --------------------------------------------------------------------------
		
		;                          // osc1::Pitch is automated
		;                          // osc1::tempo is automated
		;                          // osc1::div is automated
		;                          // osc1::pitchmode is automated
		;                          // osc1::step is automated
		;                          // osc1::Input is automated
		;                          // osc1::PitchMod is automated
		;                          // osc1::InputMod is automated
		osc1.setParameterT(8, 0.); // project::osc1::OutPut
		osc1.setParameterT(9, 0.); // project::osc1::OutMod
		;                          // osc1::harm is automated
		;                          // osc1::sync is automated
		;                          // osc1::LfoUnsync is automated
		;                          // osc1::XfstagePitch is automated
		;                          // osc1::MidiSlotPitch is automated
		;                          // osc1::XfstageInput is automated
		;                          // osc1::MidiSlotIn is automated
		;                          // osc1::XfstageOut is automated
		;                          // osc1::MidiSlotOut is automated
		;                          // osc1::Bend is automated
		
		; // oscshaper::shaper is automated
		; // oscshaper::width is automated
		; // oscshaper::out is automated
		; // oscshaper::shapemod is automated
		; // oscshaper::widthmod is automated
		; // oscshaper::outmod is automated
		; // oscshaper::XfStage is automated
		; // oscshaper::Midi1 is automated
		; // oscshaper::xf2 is automated
		; // oscshaper::xf3 is automated
		; // oscshaper::midi2 is automated
		; // oscshaper::midi3 is automated
		
		; // files::smooth is automated
		; // files::quant is automated
		; // files::Position is automated
		; // files::Input is automated
		; // files::Win is automated
		; // files::Xf is automated
		; // files::shift is automated
		; // files::pitch is automated
		; // files::Mix is automated
		; // files::PositionTempoMod is automated
		; // files::PitchMod is automated
		; // files::InputMod is automated
		; // files::XfStage is automated
		; // files::IntMod is automated
		; // files::IntModSteps is automated
		; // files::IntmodOne is automated
		; // files::intmodtempo is automated
		; // files::InmodDiv is automated
		; // files::fb is automated
		; // files::tablestep is automated
		; // files::Midi1 is automated
		; // files::Midi2 is automated
		; // files::Midi3 is automated
		; // files::xf2 is automated
		; // files::xf3 is automated
		; // files::UserMode is automated
		; // files::WinSync is automated
		; // files::WinTempo is automated
		; // files::XfTempo is automated
		; // files::WinMod is automated
		; // files::XfMod is automated
		; // files::xf4 is automated
		; // files::xf5 is automated
		; // files::midi4 is automated
		; // files::mid5 is automated
		; // files::InmodClk is automated
		; // files::InTempoMod is automated
		; // files::SmoothMod is automated
		; // files::MixMod is automated
		; // files::Midi6 is automated
		; // files::Midi7 is automated
		; // files::Midi8 is automated
		; // files::XfStage6 is automated
		; // files::XfStage7 is automated
		; // files::XfStage8 is automated
		
		this->setParameterT(0, -14.);
		this->setParameterT(1, 2.26529);
		this->setParameterT(2, 32.);
		this->setParameterT(3, 1.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 0.);
		this->setParameterT(7, -0.102072);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 0.);
		this->setParameterT(10, 0.);
		this->setParameterT(11, 1.);
		this->setParameterT(12, 1.);
		this->setParameterT(13, 1.);
		this->setParameterT(14, 1.);
		this->setParameterT(15, 1.05273);
		this->setParameterT(16, 1.);
		this->setParameterT(17, 0.467816);
		this->setParameterT(18, 2.99193);
		this->setParameterT(19, 0.412619);
		this->setParameterT(20, 0.183509);
		this->setParameterT(21, 0.);
		this->setParameterT(22, 0.);
		this->setParameterT(23, 0.);
		this->setParameterT(24, 1.);
		this->setParameterT(25, 1.);
		this->setParameterT(26, 1.);
		this->setParameterT(27, 1.00791);
		this->setParameterT(28, 1.);
		this->setParameterT(29, 1.);
		this->setParameterT(30, 1);
		this->setParameterT(31, 1.);
		this->setParameterT(32, 0.330248);
		this->setParameterT(33, 1.);
		this->setParameterT(34, 0.);
		this->setParameterT(35, 5.06921);
		this->setParameterT(36, 1.);
		this->setParameterT(37, 0.000972656);
		this->setParameterT(38, 1.);
		this->setParameterT(39, 0.);
		this->setParameterT(40, 0.);
		this->setParameterT(41, 0.000957886);
		this->setParameterT(42, 1.);
		this->setParameterT(43, 0.);
		this->setParameterT(44, 4.);
		this->setParameterT(45, 0.);
		this->setParameterT(46, 0.);
		this->setParameterT(47, 1.);
		this->setParameterT(48, 0.);
		this->setParameterT(49, 0.);
		this->setParameterT(50, 1.);
		this->setParameterT(51, 1.);
		this->setParameterT(52, 1.);
		this->setParameterT(53, 1.);
		this->setParameterT(54, 1.);
		this->setParameterT(55, 1.);
		this->setParameterT(56, 1.);
		this->setParameterT(57, 1.);
		this->setParameterT(58, 1.);
		this->setParameterT(59, 1.);
		this->setParameterT(60, 1.);
		this->setParameterT(61, 1.);
		this->setParameterT(62, 1.);
		this->setParameterT(63, 1.);
		this->setParameterT(64, 1.);
		this->setParameterT(65, 0.);
		this->setParameterT(66, 0.);
		this->setParameterT(67, -9.);
		this->setParameterT(68, 0.);
		this->setParameterT(69, 0.);
		this->setParameterT(70, 0.);
		this->setParameterT(71, 0.);
		this->setParameterT(72, 0.);
		this->setParameterT(73, 0.);
		this->setParameterT(74, 0.);
		this->setExternalData({}, -1);
	}
	~instance() override
	{
		// Cleanup external data references --------------------------------------------------------
		
		this->setExternalData({}, -1);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).setExternalData(b, index); // project::osc1<NV>
		this->getT(0).getT(1).setExternalData(b, index); // NewArrange_impl::oscshaper_t<NV>
		this->getT(0).getT(2).setExternalData(b, index); // NewArrange_impl::files_t<NV>
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
using NewArrange = wrap::node<NewArrange_impl::instance<NV>>;
}


