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

namespace oscshaper_impl
{
// ==============================| Node & Parameter type declarations |==============================

DECLARE_PARAMETER_RANGE_SKEW(sliderbank_c0Range, 
                             -100., 
                             0., 
                             5.42227);

template <int NV>
using sliderbank_c0 = parameter::from0To1<core::gain<NV>, 
                                          0, 
                                          sliderbank_c0Range>;

template <int NV> using sliderbank_c1 = sliderbank_c0<NV>;

template <int NV> using sliderbank_c2 = sliderbank_c0<NV>;

template <int NV> using sliderbank_c3 = sliderbank_c0<NV>;

template <int NV> using sliderbank_c4 = sliderbank_c0<NV>;

template <int NV> using sliderbank_c5 = sliderbank_c0<NV>;

template <int NV> using sliderbank_c6 = sliderbank_c0<NV>;

template <int NV> using sliderbank_c7 = sliderbank_c0<NV>;

template <int NV>
using sliderbank_multimod = parameter::list<sliderbank_c0<NV>, 
                                            sliderbank_c1<NV>, 
                                            sliderbank_c2<NV>, 
                                            sliderbank_c3<NV>, 
                                            sliderbank_c4<NV>, 
                                            sliderbank_c5<NV>, 
                                            sliderbank_c6<NV>, 
                                            sliderbank_c7<NV>>;

template <int NV>
using sliderbank_t = wrap::data<control::sliderbank<sliderbank_multimod<NV>>, 
                                data::external::sliderpack<0>>;
using global_cable_t_index = runtime_target::indexers::fix_hash<2333884>;

template <int NV>
using global_cable_t = routing::global_cable<global_cable_t_index, 
                                             parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain1_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable_t<NV>>, 
                                  math::add<NV>, 
                                  core::gain<NV>>;
using global_cable2_t_index = runtime_target::indexers::fix_hash<2333885>;

template <int NV>
using global_cable2_t = routing::global_cable<global_cable2_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain4_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable2_t<NV>>, 
                                  math::add<NV>, 
                                  core::gain<NV>>;
using global_cable1_t_index = runtime_target::indexers::fix_hash<2333886>;

template <int NV>
using global_cable1_t = routing::global_cable<global_cable1_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain3_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable1_t<NV>>, 
                                  math::add<NV>, 
                                  core::gain<NV>>;
using global_cable25_t_index = runtime_target::indexers::fix_hash<2333887>;

template <int NV>
using global_cable25_t = routing::global_cable<global_cable25_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain5_t = container::chain<parameter::empty, 
                                  wrap::fix<1, global_cable25_t<NV>>, 
                                  math::add<NV>, 
                                  core::gain<NV>>;

template <int NV>
using event_data_reader2_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                                       routing::event_data_reader<NV>>;

template <int NV>
using chain10_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader2_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader1_t = event_data_reader2_t<NV>;

template <int NV>
using chain8_t = container::chain<parameter::empty, 
                                  wrap::fix<1, event_data_reader1_t<NV>>, 
                                  math::add<NV>, 
                                  core::gain<NV>>;

template <int NV>
using chain12_t = container::chain<parameter::empty, 
                                   wrap::fix<1, routing::event_data_reader<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV>
using midi_cc10_t = control::midi_cc<parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain34_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc10_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc11_t = midi_cc10_t<NV>;

template <int NV>
using chain35_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc11_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc12_t = midi_cc10_t<NV>;

template <int NV>
using chain36_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc12_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc13_t = midi_cc10_t<NV>;

template <int NV>
using chain37_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc13_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using midi6_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::velocity<NV>>>;

template <int NV>
using chain38_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi6_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using midi7_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::notenumber<NV>>>;

template <int NV>
using chain39_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi7_t<NV>>, 
                                   math::add<NV>>;

template <int NV>
using midi8_t = wrap::mod<parameter::plain<math::add<NV>, 0>, 
                          control::midi<midi_logic::random<NV>>>;

template <int NV>
using chain40_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi8_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch5_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain34_t<NV>>, 
                                    chain35_t<NV>, 
                                    chain36_t<NV>, 
                                    chain37_t<NV>, 
                                    chain38_t<NV>, 
                                    chain39_t<NV>, 
                                    chain40_t<NV>>;

template <int NV>
using chain14_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch5_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split2_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain1_t<NV>>, 
                                  chain4_t<NV>, 
                                  chain3_t<NV>, 
                                  chain5_t<NV>, 
                                  chain10_t<NV>, 
                                  chain8_t<NV>, 
                                  chain12_t<NV>, 
                                  chain14_t<NV>>;

template <int NV> using xfader_c0 = sliderbank_c0<NV>;

template <int NV> using xfader_c1 = sliderbank_c0<NV>;

template <int NV> using xfader_c2 = sliderbank_c0<NV>;

template <int NV> using xfader_c3 = sliderbank_c0<NV>;

template <int NV> using xfader_c4 = sliderbank_c0<NV>;

template <int NV> using xfader_c5 = sliderbank_c0<NV>;

template <int NV> using xfader_c6 = sliderbank_c0<NV>;

template <int NV> using xfader_c7 = sliderbank_c0<NV>;

template <int NV>
using xfader_multimod = parameter::list<xfader_c0<NV>, 
                                        xfader_c1<NV>, 
                                        xfader_c2<NV>, 
                                        xfader_c3<NV>, 
                                        xfader_c4<NV>, 
                                        xfader_c5<NV>, 
                                        xfader_c6<NV>, 
                                        xfader_c7<NV>>;

template <int NV>
using xfader_t = control::xfader<xfader_multimod<NV>, faders::linear>;
template <int NV>
using pma_t = control::pma<NV, 
                           parameter::plain<xfader_t<NV>, 0>>;
template <int NV>
using peak_t = wrap::mod<parameter::plain<pma_t<NV>, 0>, 
                         wrap::no_data<core::peak>>;

template <int NV>
using chain15_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank_t<NV>>, 
                                   split2_t<NV>, 
                                   peak_t<NV>, 
                                   pma_t<NV>>;

template <int NV> using sliderbank2_c0 = sliderbank_c0<NV>;

template <int NV> using sliderbank2_c1 = sliderbank_c0<NV>;

template <int NV> using sliderbank2_c2 = sliderbank_c0<NV>;

template <int NV> using sliderbank2_c3 = sliderbank_c0<NV>;

template <int NV> using sliderbank2_c4 = sliderbank_c0<NV>;

template <int NV> using sliderbank2_c5 = sliderbank_c0<NV>;

template <int NV> using sliderbank2_c6 = sliderbank_c0<NV>;

template <int NV> using sliderbank2_c7 = sliderbank_c0<NV>;

template <int NV>
using sliderbank2_multimod = parameter::list<sliderbank2_c0<NV>, 
                                             sliderbank2_c1<NV>, 
                                             sliderbank2_c2<NV>, 
                                             sliderbank2_c3<NV>, 
                                             sliderbank2_c4<NV>, 
                                             sliderbank2_c5<NV>, 
                                             sliderbank2_c6<NV>, 
                                             sliderbank2_c7<NV>>;

template <int NV>
using sliderbank2_t = wrap::data<control::sliderbank<sliderbank2_multimod<NV>>, 
                                 data::external::sliderpack<1>>;
using global_cable7_t_index = global_cable_t_index;

template <int NV>
using global_cable7_t = routing::global_cable<global_cable7_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain26_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable7_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable8_t_index = global_cable2_t_index;

template <int NV>
using global_cable8_t = routing::global_cable<global_cable8_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain27_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable8_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable9_t_index = global_cable1_t_index;

template <int NV>
using global_cable9_t = routing::global_cable<global_cable9_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain28_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable9_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable26_t_index = global_cable25_t_index;

template <int NV>
using global_cable26_t = routing::global_cable<global_cable26_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain29_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable26_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader8_t = event_data_reader2_t<NV>;

template <int NV>
using chain30_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader8_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader9_t = event_data_reader2_t<NV>;

template <int NV>
using chain31_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader9_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader10_t = event_data_reader2_t<NV>;

template <int NV>
using chain32_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader10_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc14_t = midi_cc10_t<NV>;

template <int NV>
using chain41_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc14_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc15_t = midi_cc10_t<NV>;

template <int NV>
using chain42_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc15_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc16_t = midi_cc10_t<NV>;

template <int NV>
using chain43_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc16_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc17_t = midi_cc10_t<NV>;

template <int NV>
using chain44_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc17_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi9_t = midi6_t<NV>;

template <int NV>
using chain45_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi9_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi10_t = midi7_t<NV>;

template <int NV>
using chain46_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi10_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi11_t = midi8_t<NV>;

template <int NV>
using chain47_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi11_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch6_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain41_t<NV>>, 
                                    chain42_t<NV>, 
                                    chain43_t<NV>, 
                                    chain44_t<NV>, 
                                    chain45_t<NV>, 
                                    chain46_t<NV>, 
                                    chain47_t<NV>>;

template <int NV>
using chain33_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch6_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split5_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain26_t<NV>>, 
                                  chain27_t<NV>, 
                                  chain28_t<NV>, 
                                  chain29_t<NV>, 
                                  chain30_t<NV>, 
                                  chain31_t<NV>, 
                                  chain32_t<NV>, 
                                  chain33_t<NV>>;

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

template <int NV> using xfader1_c0 = sliderbank_c0<NV>;

template <int NV> using xfader1_c1 = sliderbank_c0<NV>;

template <int NV>
using xfader1_multimod = parameter::list<xfader1_c0<NV>, xfader1_c1<NV>>;

template <int NV>
using xfader1_t = control::xfader<xfader1_multimod<NV>, faders::linear>;

struct cable_table_t_data
{
	span<float, 512> data =
	{
		0.f, 0.00196075f, 0.00392157f, 0.00588232f, 0.00784314f, 0.00980389f,
		0.0117646f, 0.0137255f, 0.0156862f, 0.017647f, 0.0196078f, 0.0215685f,
		0.0235294f, 0.0254901f, 0.0274509f, 0.0294117f, 0.0313724f, 0.0333332f,
		0.035294f, 0.0372548f, 0.0392156f, 0.0411763f, 0.0431371f, 0.0450979f,
		0.0470586f, 0.0490194f, 0.0509802f, 0.052941f, 0.0549018f, 0.0568625f,
		0.0588233f, 0.0607841f, 0.0627449f, 0.0647056f, 0.0666664f, 0.0686272f,
		0.070588f, 0.0725487f, 0.0745095f, 0.0764703f, 0.0784311f, 0.0803919f,
		0.0823526f, 0.0843134f, 0.0862741f, 0.088235f, 0.0901957f, 0.0921565f,
		0.0941173f, 0.096078f, 0.0980389f, 0.0999996f, 0.10196f, 0.103921f,
		0.105882f, 0.107843f, 0.109803f, 0.111764f, 0.113725f, 0.115686f,
		0.117647f, 0.119607f, 0.121568f, 0.123529f, 0.12549f, 0.12745f,
		0.129411f, 0.131372f, 0.133333f, 0.135294f, 0.137254f, 0.139215f,
		0.141176f, 0.143137f, 0.145097f, 0.147058f, 0.149019f, 0.15098f,
		0.152941f, 0.154901f, 0.156862f, 0.158823f, 0.160784f, 0.162745f,
		0.164705f, 0.166666f, 0.168627f, 0.170588f, 0.172548f, 0.174509f,
		0.17647f, 0.178431f, 0.180391f, 0.182352f, 0.184313f, 0.186274f,
		0.188235f, 0.190195f, 0.192156f, 0.194117f, 0.196078f, 0.198038f,
		0.199999f, 0.20196f, 0.203921f, 0.205882f, 0.207842f, 0.209803f,
		0.211764f, 0.213725f, 0.215685f, 0.217646f, 0.219607f, 0.221568f,
		0.223529f, 0.225489f, 0.22745f, 0.229411f, 0.231372f, 0.233332f,
		0.235293f, 0.237254f, 0.239215f, 0.241176f, 0.243136f, 0.245097f,
		0.247058f, 0.249019f, 0.250979f, 0.25294f, 0.254901f, 0.256862f,
		0.258823f, 0.260783f, 0.262744f, 0.264705f, 0.266666f, 0.268626f,
		0.270587f, 0.272548f, 0.274509f, 0.27647f, 0.27843f, 0.280391f,
		0.282352f, 0.284313f, 0.286273f, 0.288234f, 0.290195f, 0.292156f,
		0.294116f, 0.296077f, 0.298038f, 0.299999f, 0.30196f, 0.30392f,
		0.305881f, 0.307842f, 0.309803f, 0.311764f, 0.313724f, 0.315685f,
		0.317646f, 0.319607f, 0.321567f, 0.323528f, 0.325489f, 0.32745f,
		0.32941f, 0.331371f, 0.333332f, 0.335293f, 0.337254f, 0.339214f,
		0.341175f, 0.343136f, 0.345097f, 0.347057f, 0.349018f, 0.350979f,
		0.35294f, 0.354901f, 0.356861f, 0.358822f, 0.360783f, 0.362744f,
		0.364704f, 0.366665f, 0.368626f, 0.370587f, 0.372548f, 0.374508f,
		0.376469f, 0.37843f, 0.380391f, 0.382352f, 0.384312f, 0.386273f,
		0.388234f, 0.390195f, 0.392155f, 0.394116f, 0.396077f, 0.398038f,
		0.399998f, 0.401959f, 0.40392f, 0.405881f, 0.407842f, 0.409802f,
		0.411763f, 0.413724f, 0.415685f, 0.417645f, 0.419606f, 0.421567f,
		0.423528f, 0.425489f, 0.427449f, 0.42941f, 0.431371f, 0.433332f,
		0.435292f, 0.437253f, 0.439214f, 0.441175f, 0.443136f, 0.445096f,
		0.447057f, 0.449018f, 0.450979f, 0.45294f, 0.4549f, 0.456861f,
		0.458822f, 0.460783f, 0.462743f, 0.464704f, 0.466665f, 0.468626f,
		0.470586f, 0.472547f, 0.474508f, 0.476469f, 0.47843f, 0.48039f,
		0.482351f, 0.484312f, 0.486273f, 0.488233f, 0.490194f, 0.492155f,
		0.494116f, 0.496077f, 0.498037f, 0.499998f, 0.501959f, 0.50392f,
		0.50588f, 0.507841f, 0.509802f, 0.511763f, 0.513724f, 0.515684f,
		0.517645f, 0.519606f, 0.521567f, 0.523527f, 0.525488f, 0.527449f,
		0.52941f, 0.531371f, 0.533331f, 0.535292f, 0.537253f, 0.539214f,
		0.541174f, 0.543135f, 0.545096f, 0.547057f, 0.549017f, 0.550978f,
		0.552939f, 0.5549f, 0.556861f, 0.558821f, 0.560782f, 0.562743f,
		0.564704f, 0.566664f, 0.568625f, 0.570586f, 0.572547f, 0.574508f,
		0.576468f, 0.578429f, 0.58039f, 0.582351f, 0.584311f, 0.586272f,
		0.588233f, 0.590194f, 0.592155f, 0.594115f, 0.596076f, 0.598037f,
		0.599998f, 0.601958f, 0.603919f, 0.60588f, 0.607841f, 0.609802f,
		0.611762f, 0.613723f, 0.615684f, 0.617645f, 0.619606f, 0.621566f,
		0.623527f, 0.625488f, 0.627449f, 0.629409f, 0.63137f, 0.633331f,
		0.635292f, 0.637253f, 0.639213f, 0.641174f, 0.643135f, 0.645096f,
		0.647056f, 0.649017f, 0.650978f, 0.652939f, 0.654899f, 0.65686f,
		0.658821f, 0.660782f, 0.662743f, 0.664703f, 0.666664f, 0.668625f,
		0.670586f, 0.672546f, 0.674507f, 0.676468f, 0.678429f, 0.68039f,
		0.68235f, 0.684311f, 0.686272f, 0.688233f, 0.690193f, 0.692154f,
		0.694115f, 0.696076f, 0.698037f, 0.699997f, 0.701958f, 0.703919f,
		0.70588f, 0.70784f, 0.709801f, 0.711762f, 0.713723f, 0.715684f,
		0.717644f, 0.719605f, 0.721566f, 0.723527f, 0.725487f, 0.727448f,
		0.729409f, 0.73137f, 0.733331f, 0.735291f, 0.737252f, 0.739213f,
		0.741174f, 0.743134f, 0.745095f, 0.747056f, 0.749017f, 0.750978f,
		0.752938f, 0.754899f, 0.75686f, 0.758821f, 0.760781f, 0.762742f,
		0.764703f, 0.766664f, 0.768624f, 0.770585f, 0.772546f, 0.774507f,
		0.776468f, 0.778428f, 0.780389f, 0.78235f, 0.784311f, 0.786272f,
		0.788232f, 0.790193f, 0.792154f, 0.794115f, 0.796075f, 0.798036f,
		0.799997f, 0.801958f, 0.803918f, 0.805879f, 0.80784f, 0.809801f,
		0.811762f, 0.813722f, 0.815683f, 0.817644f, 0.819605f, 0.821566f,
		0.823526f, 0.825487f, 0.827448f, 0.829409f, 0.831369f, 0.83333f,
		0.835291f, 0.837252f, 0.839212f, 0.841173f, 0.843134f, 0.845095f,
		0.847056f, 0.849016f, 0.850977f, 0.852938f, 0.854899f, 0.85686f,
		0.85882f, 0.860781f, 0.862742f, 0.864703f, 0.866663f, 0.868624f,
		0.870585f, 0.872546f, 0.874506f, 0.876467f, 0.878428f, 0.880389f,
		0.88235f, 0.88431f, 0.886271f, 0.888232f, 0.890193f, 0.892154f,
		0.894114f, 0.896075f, 0.898036f, 0.899997f, 0.901957f, 0.903918f,
		0.905879f, 0.90784f, 0.9098f, 0.911761f, 0.913722f, 0.915683f,
		0.917644f, 0.919604f, 0.921565f, 0.923526f, 0.925487f, 0.927447f,
		0.929408f, 0.931369f, 0.93333f, 0.935291f, 0.937251f, 0.939212f,
		0.941173f, 0.943134f, 0.945094f, 0.947055f, 0.949016f, 0.950977f,
		0.952938f, 0.954898f, 0.956859f, 0.95882f, 0.960781f, 0.962741f,
		0.964702f, 0.966663f, 0.968624f, 0.970585f, 0.972545f, 0.974506f,
		0.976467f, 0.978428f, 0.980388f, 0.982349f, 0.98431f, 0.986271f,
		0.988232f, 0.990192f, 0.992153f, 0.994114f, 0.996075f, 0.998035f,
		0.999996f, 1.f
	};
};

using cable_table_t = wrap::data<control::cable_table<parameter::empty>, 
                                 data::embedded::table<cable_table_t_data>>;

DECLARE_PARAMETER_RANGE(clone_cable1_0Range, 
                        -1., 
                        1.);

template <int NV>
using clone_cable1_0 = parameter::from0To1<jdsp::jpanner<NV>, 
                                           0, 
                                           clone_cable1_0Range>;

DECLARE_PARAMETER_RANGE_STEP(clone_cable1_1Range, 
                             -16., 
                             16., 
                             0.5);

template <int NV>
using clone_cable1_1 = parameter::from0To1<core::gain<NV>, 
                                           0, 
                                           clone_cable1_1Range>;

template <int NV>
using clone_cable1_cc = parameter::clonechain<parameter::cloned<clone_cable1_0<NV>>, 
                                              parameter::cloned<clone_cable1_1<NV>>>;
template <int NV>
using clone_cable1_t = control::clone_cable<clone_cable1_cc<NV>, duplilogic::spread>;

namespace custom
{

struct expr5
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 2.0 * value * input);;
	}
};
}

template <int NV>
using clone_cable3_cable_mod = parameter::cloned<parameter::plain<math::expr<NV, custom::expr5>, 0>>;
template <int NV>
using clone_cable3_t = control::clone_cable<clone_cable3_cable_mod<NV>, 
                                            duplilogic::nyquist>;
DECLARE_PARAMETER_RANGE_STEP(pma4_mod_0Range, 
                             -20., 
                             24., 
                             0.1);

template <int NV>
using pma4_mod_0 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       pma4_mod_0Range>;

DECLARE_PARAMETER_RANGE_STEP(pma4_mod_1Range, 
                             -12., 
                             12., 
                             0.1);

template <int NV>
using pma4_mod_1 = parameter::from0To1<core::gain<NV>, 
                                       0, 
                                       pma4_mod_1Range>;

template <int NV> using pma4_mod_2 = pma4_mod_1<NV>;

template <int NV> using pma4_mod_3 = pma4_mod_1<NV>;

DECLARE_PARAMETER_RANGE(pma4_mod_4Range, 
                        0.11, 
                        1.);

template <int NV>
using pma4_mod_4 = parameter::from0To1<math::expr<NV, custom::expr4>, 
                                       0, 
                                       pma4_mod_4Range>;

DECLARE_PARAMETER_RANGE_SKEW(pma4_mod_5Range, 
                             20., 
                             20000., 
                             0.229905);

template <int NV>
using pma4_mod_5 = parameter::from0To1<wrap::no_process<fx::phase_delay<NV>>, 
                                       0, 
                                       pma4_mod_5Range>;

template <int NV> using pma4_mod_7 = pma4_mod_1<NV>;

template <int NV>
using pma4_mod_9 = parameter::from0To1<clone_cable1_t<NV>, 
                                       1, 
                                       clone_cable1_0Range>;

DECLARE_PARAMETER_RANGE_STEP(pma4_mod_11Range, 
                             -6., 
                             24., 
                             0.1);

template <int NV>
using pma4_mod_11 = parameter::from0To1<core::gain<NV>, 
                                        0, 
                                        pma4_mod_11Range>;

template <int NV>
using pma4_mod = parameter::chain<ranges::Identity, 
                                  pma4_mod_0<NV>, 
                                  pma4_mod_1<NV>, 
                                  pma4_mod_2<NV>, 
                                  pma4_mod_3<NV>, 
                                  pma4_mod_4<NV>, 
                                  pma4_mod_5<NV>, 
                                  parameter::plain<xfader1_t<NV>, 0>, 
                                  pma4_mod_7<NV>, 
                                  parameter::plain<cable_table_t, 0>, 
                                  pma4_mod_9<NV>, 
                                  parameter::plain<clone_cable3_t<NV>, 1>, 
                                  pma4_mod_11<NV>>;

template <int NV>
using pma4_t = control::pma<NV, pma4_mod<NV>>;
template <int NV>
using peak2_t = wrap::mod<parameter::plain<pma4_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain25_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank2_t<NV>>, 
                                   split5_t<NV>, 
                                   peak2_t<NV>>;

template <int NV> using sliderbank1_c0 = sliderbank_c0<NV>;

template <int NV> using sliderbank1_c1 = sliderbank_c0<NV>;

template <int NV> using sliderbank1_c2 = sliderbank_c0<NV>;

template <int NV> using sliderbank1_c3 = sliderbank_c0<NV>;

template <int NV> using sliderbank1_c4 = sliderbank_c0<NV>;

template <int NV> using sliderbank1_c5 = sliderbank_c0<NV>;

template <int NV> using sliderbank1_c6 = sliderbank_c0<NV>;

template <int NV> using sliderbank1_c7 = sliderbank_c0<NV>;

template <int NV>
using sliderbank1_multimod = parameter::list<sliderbank1_c0<NV>, 
                                             sliderbank1_c1<NV>, 
                                             sliderbank1_c2<NV>, 
                                             sliderbank1_c3<NV>, 
                                             sliderbank1_c4<NV>, 
                                             sliderbank1_c5<NV>, 
                                             sliderbank1_c6<NV>, 
                                             sliderbank1_c7<NV>>;

template <int NV>
using sliderbank1_t = wrap::data<control::sliderbank<sliderbank1_multimod<NV>>, 
                                 data::external::sliderpack<2>>;
using global_cable4_t_index = global_cable_t_index;

template <int NV>
using global_cable4_t = routing::global_cable<global_cable4_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain17_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable4_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable5_t_index = global_cable2_t_index;

template <int NV>
using global_cable5_t = routing::global_cable<global_cable5_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain18_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable5_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable6_t_index = global_cable1_t_index;

template <int NV>
using global_cable6_t = routing::global_cable<global_cable6_t_index, 
                                              parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain19_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable6_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;
using global_cable27_t_index = global_cable25_t_index;

template <int NV>
using global_cable27_t = routing::global_cable<global_cable27_t_index, 
                                               parameter::plain<math::add<NV>, 0>>;

template <int NV>
using chain20_t = container::chain<parameter::empty, 
                                   wrap::fix<1, global_cable27_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader5_t = event_data_reader2_t<NV>;

template <int NV>
using chain21_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader5_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader6_t = event_data_reader2_t<NV>;

template <int NV>
using chain22_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader6_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using event_data_reader11_t = event_data_reader2_t<NV>;

template <int NV>
using chain23_t = container::chain<parameter::empty, 
                                   wrap::fix<1, event_data_reader11_t<NV>>, 
                                   math::add<NV>, 
                                   core::gain<NV>>;

template <int NV> using midi_cc18_t = midi_cc10_t<NV>;

template <int NV>
using chain48_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc18_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc19_t = midi_cc10_t<NV>;

template <int NV>
using chain49_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc19_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc20_t = midi_cc10_t<NV>;

template <int NV>
using chain50_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc20_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi_cc21_t = midi_cc10_t<NV>;

template <int NV>
using chain51_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi_cc21_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi12_t = midi6_t<NV>;

template <int NV>
using chain52_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi12_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi13_t = midi7_t<NV>;

template <int NV>
using chain53_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi13_t<NV>>, 
                                   math::add<NV>>;

template <int NV> using midi14_t = midi8_t<NV>;

template <int NV>
using chain54_t = container::chain<parameter::empty, 
                                   wrap::fix<1, midi14_t<NV>>, 
                                   math::add<NV>>;
template <int NV>
using branch7_t = container::branch<parameter::empty, 
                                    wrap::fix<1, chain48_t<NV>>, 
                                    chain49_t<NV>, 
                                    chain50_t<NV>, 
                                    chain51_t<NV>, 
                                    chain52_t<NV>, 
                                    chain53_t<NV>, 
                                    chain54_t<NV>>;

template <int NV>
using chain24_t = container::chain<parameter::empty, 
                                   wrap::fix<1, branch7_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using split4_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain17_t<NV>>, 
                                  chain18_t<NV>, 
                                  chain19_t<NV>, 
                                  chain20_t<NV>, 
                                  chain21_t<NV>, 
                                  chain22_t<NV>, 
                                  chain23_t<NV>, 
                                  chain24_t<NV>>;

template <int NV> using pma3_mod = sliderbank_c0<NV>;

template <int NV>
using pma3_t = control::pma<NV, pma3_mod<NV>>;
template <int NV>
using peak1_t = wrap::mod<parameter::plain<pma3_t<NV>, 0>, 
                          wrap::no_data<core::peak>>;

template <int NV>
using chain16_t = container::chain<parameter::empty, 
                                   wrap::fix<1, sliderbank1_t<NV>>, 
                                   split4_t<NV>, 
                                   peak1_t<NV>, 
                                   pma3_t<NV>>;

template <int NV>
using split3_t = container::split<parameter::empty, 
                                  wrap::fix<1, chain15_t<NV>>, 
                                  chain25_t<NV>, 
                                  chain16_t<NV>>;

template <int NV>
using modchain_t_ = container::chain<parameter::empty, 
                                     wrap::fix<1, split3_t<NV>>>;

template <int NV>
using modchain_t = wrap::control_rate<modchain_t_<NV>>;

template <int NV>
using chain57_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::sub<NV>>, 
                                   math::abs<NV>, 
                                   math::mul<NV>>;

template <int NV>
using chain6_t = container::chain<parameter::empty, 
                                  wrap::fix<2, chain57_t<NV>>, 
                                  core::gain<NV>>;
namespace custom
{

struct expr
{
	static float op(float input, float value)
	{
		return (1.0f - value) * input + value * Math.sin(Math.PI * 2.0 * value * input);;
	}
};
}

template <int NV>
using chain58_t = container::chain<parameter::empty, 
                                   wrap::fix<2, math::expr<NV, custom::expr>>, 
                                   core::gain<NV>>;

template <int NV>
using split1_t = container::split<parameter::empty, 
                                  wrap::fix<2, chain6_t<NV>>, 
                                  chain58_t<NV>>;

template <int NV>
using chain55_t = container::chain<parameter::empty, 
                                   wrap::fix<2, xfader1_t<NV>>, 
                                   split1_t<NV>, 
                                   core::gain<NV>>;
using oscilloscope_t = wrap::no_data<analyse::oscilloscope>;

template <int NV>
using chain9_t = container::chain<parameter::empty, 
                                  wrap::fix<2, core::gain<NV>>, 
                                  math::rect<NV>, 
                                  oscilloscope_t, 
                                  core::gain<NV>>;

template <int NV>
using chain61_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   wrap::no_process<math::mul<NV>>, 
                                   math::pi<NV>>;

template <int NV>
using chain11_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain61_t<NV>>, 
                                   core::gain<NV>>;

template <int NV>
using chain65_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   math::expr<NV, custom::expr4>, 
                                   math::sin<NV>, 
                                   core::gain<NV>>;
namespace custom
{

struct expr1
{
	static float op(float input, float value)
	{
		return input * Math.sin(Math.PI * 12.0 * value * input) * (2 - Math.PI);;
	}
};
}

template <int NV>
using chain7_t = container::chain<parameter::empty, 
                                  wrap::fix<2, math::pi<NV>>, 
                                  wrap::no_process<math::sin<NV>>, 
                                  core::gain<NV>, 
                                  math::sin<NV>, 
                                  math::expr<NV, custom::expr1>, 
                                  core::gain<NV>>;
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

template <int NV>
using chain56_t = container::chain<parameter::empty, 
                                   wrap::fix<2, wrap::no_process<math::pi<NV>>>, 
                                   wrap::no_process<fx::phase_delay<NV>>, 
                                   core::gain<NV>, 
                                   math::expr<NV, custom::expr2>, 
                                   math::sin<NV>, 
                                   core::gain<NV>>;

DECLARE_PARAMETER_RANGE_STEP(clone_pack_modRange, 
                             0., 
                             2.6, 
                             0.1);

template <int NV>
using clone_pack_mod = parameter::from0To1<math::pi<NV>, 
                                           0, 
                                           clone_pack_modRange>;

struct clone_pack_t_data
{
	span<float, 16> data =
	{
		0.06f, 0.06f, 0.82f, 1.f, 1.f, 1.f,
		0.82f, 0.63f, 0.47f, 0.2f, 1.f, 1.f,
		0.85f, 0.78f, 0.65f, 0.44f
	};
};

template <int NV>
using clone_pack_t = wrap::data<control::clone_pack<parameter::cloned<clone_pack_mod<NV>>>, 
                                data::embedded::sliderpack<clone_pack_t_data>>;

template <int NV>
using clone_child_t = container::chain<parameter::empty, 
                                       wrap::fix<2, math::pi<NV>>, 
                                       wrap::no_process<math::sub<NV>>, 
                                       math::expr<NV, custom::expr5>, 
                                       wrap::no_process<math::fmod<NV>>, 
                                       math::add<NV>, 
                                       wrap::no_process<math::rect<NV>>, 
                                       core::gain<NV>, 
                                       jdsp::jpanner<NV>, 
                                       wrap::no_process<math::square<NV>>, 
                                       math::sin<NV>>;
template <int NV>
using clone_t = wrap::fix_clonecopy<clone_child_t<NV>, 16>;

template <int NV>
using chain68_t = container::chain<parameter::empty, 
                                   wrap::fix<2, clone_cable1_t<NV>>, 
                                   clone_cable3_t<NV>, 
                                   clone_pack_t<NV>, 
                                   clone_t<NV>, 
                                   cable_table_t, 
                                   math::sin<NV>>;

template <int NV>
using chain67_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain68_t<NV>>>;

template <int NV>
using chain60_t = container::chain<parameter::empty, 
                                   wrap::fix<2, chain67_t<NV>>, 
                                   core::gain<NV>>;
using table4_t = wrap::data<math::table, 
                            data::external::table<0>>;

template <int NV>
using chain13_t = container::chain<parameter::empty, 
                                   wrap::fix<2, core::gain<NV>>, 
                                   math::pi<NV>, 
                                   table4_t, 
                                   core::gain<NV>>;

template <int NV>
using split_t = container::split<parameter::empty, 
                                 wrap::fix<2, chain55_t<NV>>, 
                                 chain9_t<NV>, 
                                 chain11_t<NV>, 
                                 chain65_t<NV>, 
                                 chain7_t<NV>, 
                                 chain56_t<NV>, 
                                 chain60_t<NV>, 
                                 chain13_t<NV>>;

template <int NV>
using chain2_t = container::chain<parameter::empty, 
                                  wrap::fix<2, modchain_t<NV>>, 
                                  xfader_t<NV>, 
                                  pma4_t<NV>, 
                                  split_t<NV>, 
                                  core::gain<NV>, 
                                  filters::one_pole<NV>>;

namespace oscshaper_t_parameters
{
// Parameter list for oscshaper_impl::oscshaper_t --------------------------------------------------

DECLARE_PARAMETER_RANGE(shaper_InputRange, 
                        1., 
                        8.);

template <int NV>
using shaper = parameter::chain<shaper_InputRange, 
                                parameter::plain<oscshaper_impl::pma_t<NV>, 2>>;

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

DECLARE_PARAMETER_RANGE(Midi1_InputRange, 
                        1., 
                        7.);
DECLARE_PARAMETER_RANGE_STEP(Midi1_0Range, 
                             0., 
                             6., 
                             1.);

template <int NV>
using Midi1_0 = parameter::from0To1<oscshaper_impl::branch5_t<NV>, 
                                    0, 
                                    Midi1_0Range>;

template <int NV>
using Midi1 = parameter::chain<Midi1_InputRange, Midi1_0<NV>>;

DECLARE_PARAMETER_RANGE(xf2_InputRange, 
                        1., 
                        4.);
template <int NV>
using xf2_0 = parameter::from0To1<oscshaper_impl::event_data_reader10_t<NV>, 
                                  0, 
                                  XfStage_0Range>;

template <int NV>
using xf2 = parameter::chain<xf2_InputRange, xf2_0<NV>>;

DECLARE_PARAMETER_RANGE(xf3_InputRange, 
                        1., 
                        4.);
template <int NV>
using xf3_0 = parameter::from0To1<oscshaper_impl::event_data_reader11_t<NV>, 
                                  0, 
                                  XfStage_0Range>;

template <int NV>
using xf3 = parameter::chain<xf3_InputRange, xf3_0<NV>>;

DECLARE_PARAMETER_RANGE(midi2_InputRange, 
                        1., 
                        7.);
template <int NV>
using midi2_0 = parameter::from0To1<oscshaper_impl::branch6_t<NV>, 
                                    0, 
                                    Midi1_0Range>;

template <int NV>
using midi2 = parameter::chain<midi2_InputRange, midi2_0<NV>>;

DECLARE_PARAMETER_RANGE(midi3_InputRange, 
                        1., 
                        7.);
template <int NV>
using midi3_0 = parameter::from0To1<oscshaper_impl::branch7_t<NV>, 
                                    0, 
                                    Midi1_0Range>;

template <int NV>
using midi3 = parameter::chain<midi3_InputRange, midi3_0<NV>>;

template <int NV>
using width = parameter::plain<oscshaper_impl::pma4_t<NV>, 
                               2>;
template <int NV>
using out = parameter::plain<oscshaper_impl::pma3_t<NV>, 
                             2>;
template <int NV>
using shapemod = parameter::plain<oscshaper_impl::pma_t<NV>, 
                                  1>;
template <int NV>
using widthmod = parameter::plain<oscshaper_impl::pma4_t<NV>, 
                                  1>;
template <int NV>
using outmod = parameter::plain<oscshaper_impl::pma3_t<NV>, 
                                1>;
template <int NV>
using oscshaper_t_plist = parameter::list<shaper<NV>, 
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
                                          midi3<NV>>;
}

template <int NV>
using oscshaper_t_ = container::chain<oscshaper_t_parameters::oscshaper_t_plist<NV>, 
                                      wrap::fix<2, chain2_t<NV>>>;

// =================================| Root node initialiser class |=================================

template <int NV> struct instance: public oscshaper_impl::oscshaper_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 1;
		static const int NumSliderPacks = 3;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(oscshaper);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(190)
		{
			0x005B, 0x0000, 0x7300, 0x6168, 0x6570, 0x0072, 0x0000, 0x3F80, 
            0x0000, 0x4100, 0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x015B, 0x0000, 0x7700, 0x6469, 0x6874, 0x0000, 0x0000, 0x0000, 
            0x8000, 0xC33F, 0xA8F5, 0x003E, 0x8000, 0x003F, 0x0000, 0x5B00, 
            0x0002, 0x0000, 0x756F, 0x0074, 0x0000, 0x0000, 0x0000, 0x3F80, 
            0x5C29, 0x3E8F, 0x0000, 0x3F80, 0x0000, 0x0000, 0x035B, 0x0000, 
            0x7300, 0x6168, 0x6570, 0x6F6D, 0x0064, 0x0000, 0xBF80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 0x045B, 
            0x0000, 0x7700, 0x6469, 0x6874, 0x6F6D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x055B, 0x0000, 0x6F00, 0x7475, 0x6F6D, 0x0064, 0x0000, 0xBF80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x065B, 0x0000, 0x5800, 0x5366, 0x6174, 0x6567, 0x0000, 0x8000, 
            0x003F, 0x8000, 0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 
            0x5B3F, 0x0007, 0x0000, 0x694D, 0x6964, 0x0031, 0x0000, 0x3F80, 
            0x0000, 0x40E0, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 
            0x085B, 0x0000, 0x7800, 0x3266, 0x0000, 0x8000, 0x003F, 0x8000, 
            0x0040, 0x8000, 0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x0009, 
            0x0000, 0x6678, 0x0033, 0x0000, 0x3F80, 0x0000, 0x4080, 0x0000, 
            0x3F80, 0x0000, 0x3F80, 0x0000, 0x0000, 0x0A5B, 0x0000, 0x6D00, 
            0x6469, 0x3269, 0x0000, 0x8000, 0x003F, 0xE000, 0x0040, 0x8000, 
            0x003F, 0x8000, 0x003F, 0x0000, 0x5B00, 0x000B, 0x0000, 0x696D, 
            0x6964, 0x0033, 0x0000, 0x3F80, 0x0000, 0x40E0, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------------------------
		
		auto& chain2 = this->getT(0);                                                              // oscshaper_impl::chain2_t<NV>
		auto& modchain = this->getT(0).getT(0);                                                    // oscshaper_impl::modchain_t<NV>
		auto& split3 = this->getT(0).getT(0).getT(0);                                              // oscshaper_impl::split3_t<NV>
		auto& chain15 = this->getT(0).getT(0).getT(0).getT(0);                                     // oscshaper_impl::chain15_t<NV>
		auto& sliderbank = this->getT(0).getT(0).getT(0).getT(0).getT(0);                          // oscshaper_impl::sliderbank_t<NV>
		auto& split2 = this->getT(0).getT(0).getT(0).getT(0).getT(1);                              // oscshaper_impl::split2_t<NV>
		auto& chain1 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0);                      // oscshaper_impl::chain1_t<NV>
		auto& global_cable = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0);        // oscshaper_impl::global_cable_t<NV>
		auto& add = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(1);                 // math::add<NV>
		auto& gain = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(2);                // core::gain<NV>
		auto& chain4 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1);                      // oscshaper_impl::chain4_t<NV>
		auto& global_cable2 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0);       // oscshaper_impl::global_cable2_t<NV>
		auto& add2 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(1);                // math::add<NV>
		auto& gain9 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(2);               // core::gain<NV>
		auto& chain3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2);                      // oscshaper_impl::chain3_t<NV>
		auto& global_cable1 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(0);       // oscshaper_impl::global_cable1_t<NV>
		auto& add1 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(1);                // math::add<NV>
		auto& gain8 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(2);               // core::gain<NV>
		auto& chain5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3);                      // oscshaper_impl::chain5_t<NV>
		auto& global_cable25 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(0);      // oscshaper_impl::global_cable25_t<NV>
		auto& add3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(1);                // math::add<NV>
		auto& gain7 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(2);               // core::gain<NV>
		auto& chain10 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(4);                     // oscshaper_impl::chain10_t<NV>
		auto& event_data_reader2 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(4).getT(0);  // oscshaper_impl::event_data_reader2_t<NV>
		auto& add7 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(4).getT(1);                // math::add<NV>
		auto& gain6 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(4).getT(2);               // core::gain<NV>
		auto& chain8 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5);                      // oscshaper_impl::chain8_t<NV>
		auto& event_data_reader1 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).getT(0);  // oscshaper_impl::event_data_reader1_t<NV>
		auto& add6 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).getT(1);                // math::add<NV>
		auto& gain5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(5).getT(2);               // core::gain<NV>
		auto& chain12 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(6);                     // oscshaper_impl::chain12_t<NV>
		auto& event_data_reader3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(6).getT(0);  // routing::event_data_reader<NV>
		auto& add8 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(6).getT(1);                // math::add<NV>
		auto& gain4 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(6).getT(2);               // core::gain<NV>
		auto& chain14 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(7);                     // oscshaper_impl::chain14_t<NV>
		auto& branch5 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(7).getT(0);             // oscshaper_impl::branch5_t<NV>
		auto& chain34 = this->getT(0).getT(0).getT(0).getT(0).                                     // oscshaper_impl::chain34_t<NV>
                        getT(1).getT(7).getT(0).getT(0);
		auto& midi_cc10 = this->getT(0).getT(0).getT(0).getT(0).                                   // oscshaper_impl::midi_cc10_t<NV>
                          getT(1).getT(7).getT(0).getT(0).
                          getT(0);
		auto& add50 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(0).
                      getT(1);
		auto& chain35 = this->getT(0).getT(0).getT(0).getT(0).                                     // oscshaper_impl::chain35_t<NV>
                        getT(1).getT(7).getT(0).getT(1);
		auto& midi_cc11 = this->getT(0).getT(0).getT(0).getT(0).                                   // oscshaper_impl::midi_cc11_t<NV>
                          getT(1).getT(7).getT(0).getT(1).
                          getT(0);
		auto& add51 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(1).
                      getT(1);
		auto& chain36 = this->getT(0).getT(0).getT(0).getT(0).                                     // oscshaper_impl::chain36_t<NV>
                        getT(1).getT(7).getT(0).getT(2);
		auto& midi_cc12 = this->getT(0).getT(0).getT(0).getT(0).                                   // oscshaper_impl::midi_cc12_t<NV>
                          getT(1).getT(7).getT(0).getT(2).
                          getT(0);
		auto& add52 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(2).
                      getT(1);
		auto& chain37 = this->getT(0).getT(0).getT(0).getT(0).                                     // oscshaper_impl::chain37_t<NV>
                        getT(1).getT(7).getT(0).getT(3);
		auto& midi_cc13 = this->getT(0).getT(0).getT(0).getT(0).                                   // oscshaper_impl::midi_cc13_t<NV>
                          getT(1).getT(7).getT(0).getT(3).
                          getT(0);
		auto& add53 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(3).
                      getT(1);
		auto& chain38 = this->getT(0).getT(0).getT(0).getT(0).                                     // oscshaper_impl::chain38_t<NV>
                        getT(1).getT(7).getT(0).getT(4);
		auto& midi6 = this->getT(0).getT(0).getT(0).getT(0).                                       // oscshaper_impl::midi6_t<NV>
                      getT(1).getT(7).getT(0).getT(4).
                      getT(0);
		auto& add54 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(4).
                      getT(1);
		auto& chain39 = this->getT(0).getT(0).getT(0).getT(0).                                     // oscshaper_impl::chain39_t<NV>
                        getT(1).getT(7).getT(0).getT(5);
		auto& midi7 = this->getT(0).getT(0).getT(0).getT(0).                                       // oscshaper_impl::midi7_t<NV>
                      getT(1).getT(7).getT(0).getT(5).
                      getT(0);
		auto& add55 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(5).
                      getT(1);
		auto& chain40 = this->getT(0).getT(0).getT(0).getT(0).                                     // oscshaper_impl::chain40_t<NV>
                        getT(1).getT(7).getT(0).getT(6);
		auto& midi8 = this->getT(0).getT(0).getT(0).getT(0).                                       // oscshaper_impl::midi8_t<NV>
                      getT(1).getT(7).getT(0).getT(6).
                      getT(0);
		auto& add56 = this->getT(0).getT(0).getT(0).getT(0).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(6).
                      getT(1);
		auto& gain3 = this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(7).getT(1);               // core::gain<NV>
		auto& peak = this->getT(0).getT(0).getT(0).getT(0).getT(2);                                // oscshaper_impl::peak_t<NV>
		auto& pma = this->getT(0).getT(0).getT(0).getT(0).getT(3);                                 // oscshaper_impl::pma_t<NV>
		auto& chain25 = this->getT(0).getT(0).getT(0).getT(1);                                     // oscshaper_impl::chain25_t<NV>
		auto& sliderbank2 = this->getT(0).getT(0).getT(0).getT(1).getT(0);                         // oscshaper_impl::sliderbank2_t<NV>
		auto& split5 = this->getT(0).getT(0).getT(0).getT(1).getT(1);                              // oscshaper_impl::split5_t<NV>
		auto& chain26 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(0);                     // oscshaper_impl::chain26_t<NV>
		auto& global_cable7 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).getT(0);       // oscshaper_impl::global_cable7_t<NV>
		auto& add18 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain23 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain27 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(1);                     // oscshaper_impl::chain27_t<NV>
		auto& global_cable8 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(1).getT(0);       // oscshaper_impl::global_cable8_t<NV>
		auto& add19 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(1).getT(1);               // math::add<NV>
		auto& gain24 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(1).getT(2);              // core::gain<NV>
		auto& chain28 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(2);                     // oscshaper_impl::chain28_t<NV>
		auto& global_cable9 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(2).getT(0);       // oscshaper_impl::global_cable9_t<NV>
		auto& add20 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(2).getT(1);               // math::add<NV>
		auto& gain25 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(2).getT(2);              // core::gain<NV>
		auto& chain29 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(3);                     // oscshaper_impl::chain29_t<NV>
		auto& global_cable26 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(3).getT(0);      // oscshaper_impl::global_cable26_t<NV>
		auto& add21 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(3).getT(1);               // math::add<NV>
		auto& gain27 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(3).getT(2);              // core::gain<NV>
		auto& chain30 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(4);                     // oscshaper_impl::chain30_t<NV>
		auto& event_data_reader8 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(4).getT(0);  // oscshaper_impl::event_data_reader8_t<NV>
		auto& add22 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(4).getT(1);               // math::add<NV>
		auto& gain28 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(4).getT(2);              // core::gain<NV>
		auto& chain31 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(5);                     // oscshaper_impl::chain31_t<NV>
		auto& event_data_reader9 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(5).getT(0);  // oscshaper_impl::event_data_reader9_t<NV>
		auto& add23 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(5).getT(1);               // math::add<NV>
		auto& gain29 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(5).getT(2);              // core::gain<NV>
		auto& chain32 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(6);                     // oscshaper_impl::chain32_t<NV>
		auto& event_data_reader10 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(6).getT(0); // oscshaper_impl::event_data_reader10_t<NV>
		auto& add24 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(6).getT(1);               // math::add<NV>
		auto& gain30 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(6).getT(2);              // core::gain<NV>
		auto& chain33 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(7);                     // oscshaper_impl::chain33_t<NV>
		auto& branch6 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(7).getT(0);             // oscshaper_impl::branch6_t<NV>
		auto& chain41 = this->getT(0).getT(0).getT(0).getT(1).                                     // oscshaper_impl::chain41_t<NV>
                        getT(1).getT(7).getT(0).getT(0);
		auto& midi_cc14 = this->getT(0).getT(0).getT(0).getT(1).                                   // oscshaper_impl::midi_cc14_t<NV>
                          getT(1).getT(7).getT(0).getT(0).
                          getT(0);
		auto& add57 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(0).
                      getT(1);
		auto& chain42 = this->getT(0).getT(0).getT(0).getT(1).                                     // oscshaper_impl::chain42_t<NV>
                        getT(1).getT(7).getT(0).getT(1);
		auto& midi_cc15 = this->getT(0).getT(0).getT(0).getT(1).                                   // oscshaper_impl::midi_cc15_t<NV>
                          getT(1).getT(7).getT(0).getT(1).
                          getT(0);
		auto& add58 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(1).
                      getT(1);
		auto& chain43 = this->getT(0).getT(0).getT(0).getT(1).                                     // oscshaper_impl::chain43_t<NV>
                        getT(1).getT(7).getT(0).getT(2);
		auto& midi_cc16 = this->getT(0).getT(0).getT(0).getT(1).                                   // oscshaper_impl::midi_cc16_t<NV>
                          getT(1).getT(7).getT(0).getT(2).
                          getT(0);
		auto& add59 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(2).
                      getT(1);
		auto& chain44 = this->getT(0).getT(0).getT(0).getT(1).                                     // oscshaper_impl::chain44_t<NV>
                        getT(1).getT(7).getT(0).getT(3);
		auto& midi_cc17 = this->getT(0).getT(0).getT(0).getT(1).                                   // oscshaper_impl::midi_cc17_t<NV>
                          getT(1).getT(7).getT(0).getT(3).
                          getT(0);
		auto& add60 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(3).
                      getT(1);
		auto& chain45 = this->getT(0).getT(0).getT(0).getT(1).                                     // oscshaper_impl::chain45_t<NV>
                        getT(1).getT(7).getT(0).getT(4);
		auto& midi9 = this->getT(0).getT(0).getT(0).getT(1).                                       // oscshaper_impl::midi9_t<NV>
                      getT(1).getT(7).getT(0).getT(4).
                      getT(0);
		auto& add61 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(4).
                      getT(1);
		auto& chain46 = this->getT(0).getT(0).getT(0).getT(1).                                     // oscshaper_impl::chain46_t<NV>
                        getT(1).getT(7).getT(0).getT(5);
		auto& midi10 = this->getT(0).getT(0).getT(0).getT(1).                                      // oscshaper_impl::midi10_t<NV>
                       getT(1).getT(7).getT(0).getT(5).
                       getT(0);
		auto& add62 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(5).
                      getT(1);
		auto& chain47 = this->getT(0).getT(0).getT(0).getT(1).                                     // oscshaper_impl::chain47_t<NV>
                        getT(1).getT(7).getT(0).getT(6);
		auto& midi11 = this->getT(0).getT(0).getT(0).getT(1).                                      // oscshaper_impl::midi11_t<NV>
                       getT(1).getT(7).getT(0).getT(6).
                       getT(0);
		auto& add63 = this->getT(0).getT(0).getT(0).getT(1).                                       // math::add<NV>
                      getT(1).getT(7).getT(0).getT(6).
                      getT(1);
		auto& gain31 = this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(7).getT(1);              // core::gain<NV>
		auto& peak2 = this->getT(0).getT(0).getT(0).getT(1).getT(2);                               // oscshaper_impl::peak2_t<NV>
		auto& chain16 = this->getT(0).getT(0).getT(0).getT(2);                                     // oscshaper_impl::chain16_t<NV>
		auto& sliderbank1 = this->getT(0).getT(0).getT(0).getT(2).getT(0);                         // oscshaper_impl::sliderbank1_t<NV>
		auto& split4 = this->getT(0).getT(0).getT(0).getT(2).getT(1);                              // oscshaper_impl::split4_t<NV>
		auto& chain17 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0);                     // oscshaper_impl::chain17_t<NV>
		auto& global_cable4 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(0);       // oscshaper_impl::global_cable4_t<NV>
		auto& add10 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(1);               // math::add<NV>
		auto& gain10 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(2);              // core::gain<NV>
		auto& chain18 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1);                     // oscshaper_impl::chain18_t<NV>
		auto& global_cable5 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1).getT(0);       // oscshaper_impl::global_cable5_t<NV>
		auto& add11 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1).getT(1);               // math::add<NV>
		auto& gain12 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1).getT(2);              // core::gain<NV>
		auto& chain19 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(2);                     // oscshaper_impl::chain19_t<NV>
		auto& global_cable6 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(2).getT(0);       // oscshaper_impl::global_cable6_t<NV>
		auto& add12 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(2).getT(1);               // math::add<NV>
		auto& gain17 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(2).getT(2);              // core::gain<NV>
		auto& chain20 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(3);                     // oscshaper_impl::chain20_t<NV>
		auto& global_cable27 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(3).getT(0);      // oscshaper_impl::global_cable27_t<NV>
		auto& add13 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(3).getT(1);               // math::add<NV>
		auto& gain18 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(3).getT(2);              // core::gain<NV>
		auto& chain21 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(4);                     // oscshaper_impl::chain21_t<NV>
		auto& event_data_reader5 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(4).getT(0);  // oscshaper_impl::event_data_reader5_t<NV>
		auto& add14 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(4).getT(1);               // math::add<NV>
		auto& gain19 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(4).getT(2);              // core::gain<NV>
		auto& chain22 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(5);                     // oscshaper_impl::chain22_t<NV>
		auto& event_data_reader6 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(5).getT(0);  // oscshaper_impl::event_data_reader6_t<NV>
		auto& add15 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(5).getT(1);               // math::add<NV>
		auto& gain20 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(5).getT(2);              // core::gain<NV>
		auto& chain23 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(6);                     // oscshaper_impl::chain23_t<NV>
		auto& event_data_reader11 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(6).getT(0); // oscshaper_impl::event_data_reader11_t<NV>
		auto& add16 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(6).getT(1);               // math::add<NV>
		auto& gain21 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(6).getT(2);              // core::gain<NV>
		auto& chain24 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(7);                     // oscshaper_impl::chain24_t<NV>
		auto& branch7 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(7).getT(0);             // oscshaper_impl::branch7_t<NV>
		auto& chain48 = this->getT(0).getT(0).getT(0).getT(2).                                     // oscshaper_impl::chain48_t<NV>
                        getT(1).getT(7).getT(0).getT(0);
		auto& midi_cc18 = this->getT(0).getT(0).getT(0).getT(2).                      // oscshaper_impl::midi_cc18_t<NV>
                          getT(1).getT(7).getT(0).getT(0).
                          getT(0);
		auto& add64 = this->getT(0).getT(0).getT(0).getT(2).                          // math::add<NV>
                      getT(1).getT(7).getT(0).getT(0).
                      getT(1);
		auto& chain49 = this->getT(0).getT(0).getT(0).getT(2).                        // oscshaper_impl::chain49_t<NV>
                        getT(1).getT(7).getT(0).getT(1);
		auto& midi_cc19 = this->getT(0).getT(0).getT(0).getT(2).                      // oscshaper_impl::midi_cc19_t<NV>
                          getT(1).getT(7).getT(0).getT(1).
                          getT(0);
		auto& add65 = this->getT(0).getT(0).getT(0).getT(2).                          // math::add<NV>
                      getT(1).getT(7).getT(0).getT(1).
                      getT(1);
		auto& chain50 = this->getT(0).getT(0).getT(0).getT(2).                        // oscshaper_impl::chain50_t<NV>
                        getT(1).getT(7).getT(0).getT(2);
		auto& midi_cc20 = this->getT(0).getT(0).getT(0).getT(2).                      // oscshaper_impl::midi_cc20_t<NV>
                          getT(1).getT(7).getT(0).getT(2).
                          getT(0);
		auto& add66 = this->getT(0).getT(0).getT(0).getT(2).                          // math::add<NV>
                      getT(1).getT(7).getT(0).getT(2).
                      getT(1);
		auto& chain51 = this->getT(0).getT(0).getT(0).getT(2).                        // oscshaper_impl::chain51_t<NV>
                        getT(1).getT(7).getT(0).getT(3);
		auto& midi_cc21 = this->getT(0).getT(0).getT(0).getT(2).                      // oscshaper_impl::midi_cc21_t<NV>
                          getT(1).getT(7).getT(0).getT(3).
                          getT(0);
		auto& add67 = this->getT(0).getT(0).getT(0).getT(2).                          // math::add<NV>
                      getT(1).getT(7).getT(0).getT(3).
                      getT(1);
		auto& chain52 = this->getT(0).getT(0).getT(0).getT(2).                        // oscshaper_impl::chain52_t<NV>
                        getT(1).getT(7).getT(0).getT(4);
		auto& midi12 = this->getT(0).getT(0).getT(0).getT(2).                         // oscshaper_impl::midi12_t<NV>
                       getT(1).getT(7).getT(0).getT(4).
                       getT(0);
		auto& add68 = this->getT(0).getT(0).getT(0).getT(2).                          // math::add<NV>
                      getT(1).getT(7).getT(0).getT(4).
                      getT(1);
		auto& chain53 = this->getT(0).getT(0).getT(0).getT(2).                        // oscshaper_impl::chain53_t<NV>
                        getT(1).getT(7).getT(0).getT(5);
		auto& midi13 = this->getT(0).getT(0).getT(0).getT(2).                         // oscshaper_impl::midi13_t<NV>
                       getT(1).getT(7).getT(0).getT(5).
                       getT(0);
		auto& add69 = this->getT(0).getT(0).getT(0).getT(2).                          // math::add<NV>
                      getT(1).getT(7).getT(0).getT(5).
                      getT(1);
		auto& chain54 = this->getT(0).getT(0).getT(0).getT(2).                        // oscshaper_impl::chain54_t<NV>
                        getT(1).getT(7).getT(0).getT(6);
		auto& midi14 = this->getT(0).getT(0).getT(0).getT(2).                         // oscshaper_impl::midi14_t<NV>
                       getT(1).getT(7).getT(0).getT(6).
                       getT(0);
		auto& add70 = this->getT(0).getT(0).getT(0).getT(2).                          // math::add<NV>
                      getT(1).getT(7).getT(0).getT(6).
                      getT(1);
		auto& gain22 = this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(7).getT(1); // core::gain<NV>
		auto& peak1 = this->getT(0).getT(0).getT(0).getT(2).getT(2);                  // oscshaper_impl::peak1_t<NV>
		auto& pma3 = this->getT(0).getT(0).getT(0).getT(2).getT(3);                   // oscshaper_impl::pma3_t<NV>
		auto& xfader = this->getT(0).getT(1);                                         // oscshaper_impl::xfader_t<NV>
		auto& pma4 = this->getT(0).getT(2);                                           // oscshaper_impl::pma4_t<NV>
		auto& split = this->getT(0).getT(3);                                          // oscshaper_impl::split_t<NV>
		auto& chain55 = this->getT(0).getT(3).getT(0);                                // oscshaper_impl::chain55_t<NV>
		auto& xfader1 = this->getT(0).getT(3).getT(0).getT(0);                        // oscshaper_impl::xfader1_t<NV>
		auto& split1 = this->getT(0).getT(3).getT(0).getT(1);                         // oscshaper_impl::split1_t<NV>
		auto& chain6 = this->getT(0).getT(3).getT(0).getT(1).getT(0);                 // oscshaper_impl::chain6_t<NV>
		auto& chain57 = this->getT(0).getT(3).getT(0).getT(1).getT(0).getT(0);        // oscshaper_impl::chain57_t<NV>
		auto& sub = this->getT(0).getT(3).getT(0).getT(1).getT(0).getT(0).getT(0);    // math::sub<NV>
		auto& abs = this->getT(0).getT(3).getT(0).getT(1).getT(0).getT(0).getT(1);    // math::abs<NV>
		auto& mul1 = this->getT(0).getT(3).getT(0).getT(1).getT(0).getT(0).getT(2);   // math::mul<NV>
		auto& gain34 = this->getT(0).getT(3).getT(0).getT(1).getT(0).getT(1);         // core::gain<NV>
		auto& chain58 = this->getT(0).getT(3).getT(0).getT(1).getT(1);                // oscshaper_impl::chain58_t<NV>
		auto& expr = this->getT(0).getT(3).getT(0).getT(1).getT(1).getT(0);           // math::expr<NV, custom::expr>
		auto& gain32 = this->getT(0).getT(3).getT(0).getT(1).getT(1).getT(1);         // core::gain<NV>
		auto& gain11 = this->getT(0).getT(3).getT(0).getT(2);                         // core::gain<NV>
		auto& chain9 = this->getT(0).getT(3).getT(1);                                 // oscshaper_impl::chain9_t<NV>
		auto& gain16 = this->getT(0).getT(3).getT(1).getT(0);                         // core::gain<NV>
		auto& rect1 = this->getT(0).getT(3).getT(1).getT(1);                          // math::rect<NV>
		auto& oscilloscope = this->getT(0).getT(3).getT(1).getT(2);                   // oscshaper_impl::oscilloscope_t
		auto& gain13 = this->getT(0).getT(3).getT(1).getT(3);                         // core::gain<NV>
		auto& chain11 = this->getT(0).getT(3).getT(2);                                // oscshaper_impl::chain11_t<NV>
		auto& chain61 = this->getT(0).getT(3).getT(2).getT(0);                        // oscshaper_impl::chain61_t<NV>
		auto& gain37 = this->getT(0).getT(3).getT(2).getT(0).getT(0);                 // core::gain<NV>
		auto& mul = this->getT(0).getT(3).getT(2).getT(0).getT(1);                    // wrap::no_process<math::mul<NV>>
		auto& pi5 = this->getT(0).getT(3).getT(2).getT(0).getT(2);                    // math::pi<NV>
		auto& gain15 = this->getT(0).getT(3).getT(2).getT(1);                         // core::gain<NV>
		auto& chain65 = this->getT(0).getT(3).getT(3);                                // oscshaper_impl::chain65_t<NV>
		auto& gain44 = this->getT(0).getT(3).getT(3).getT(0);                         // core::gain<NV>
		auto& expr4 = this->getT(0).getT(3).getT(3).getT(1);                          // math::expr<NV, custom::expr4>
		auto& sin5 = this->getT(0).getT(3).getT(3).getT(2);                           // math::sin<NV>
		auto& gain45 = this->getT(0).getT(3).getT(3).getT(3);                         // core::gain<NV>
		auto& chain7 = this->getT(0).getT(3).getT(4);                                 // oscshaper_impl::chain7_t<NV>
		auto& pi7 = this->getT(0).getT(3).getT(4).getT(0);                            // math::pi<NV>
		auto& sin = this->getT(0).getT(3).getT(4).getT(1);                            // wrap::no_process<math::sin<NV>>
		auto& gain35 = this->getT(0).getT(3).getT(4).getT(2);                         // core::gain<NV>
		auto& sin6 = this->getT(0).getT(3).getT(4).getT(3);                           // math::sin<NV>
		auto& expr1 = this->getT(0).getT(3).getT(4).getT(4);                          // math::expr<NV, custom::expr1>
		auto& gain2 = this->getT(0).getT(3).getT(4).getT(5);                          // core::gain<NV>
		auto& chain56 = this->getT(0).getT(3).getT(5);                                // oscshaper_impl::chain56_t<NV>
		auto& pi2 = this->getT(0).getT(3).getT(5).getT(0);                            // wrap::no_process<math::pi<NV>>
		auto& phase_delay = this->getT(0).getT(3).getT(5).getT(1);                    // wrap::no_process<fx::phase_delay<NV>>
		auto& gain36 = this->getT(0).getT(3).getT(5).getT(2);                         // core::gain<NV>
		auto& expr2 = this->getT(0).getT(3).getT(5).getT(3);                          // math::expr<NV, custom::expr2>
		auto& sin8 = this->getT(0).getT(3).getT(5).getT(4);                           // math::sin<NV>
		auto& gain33 = this->getT(0).getT(3).getT(5).getT(5);                         // core::gain<NV>
		auto& chain60 = this->getT(0).getT(3).getT(6);                                // oscshaper_impl::chain60_t<NV>
		auto& chain67 = this->getT(0).getT(3).getT(6).getT(0);                        // oscshaper_impl::chain67_t<NV>
		auto& chain68 = this->getT(0).getT(3).getT(6).getT(0).getT(0);                // oscshaper_impl::chain68_t<NV>
		auto& clone_cable1 = this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(0);   // oscshaper_impl::clone_cable1_t<NV>
		auto& clone_cable3 = this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(1);   // oscshaper_impl::clone_cable3_t<NV>
		auto& clone_pack = this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(2);     // oscshaper_impl::clone_pack_t<NV>
		auto& clone = this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(3);          // oscshaper_impl::clone_t<NV>          // oscshaper_impl::clone_child_t<NV>
		auto pi10 = this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(3).getT(0);    // math::pi<NV>
		auto sub2 = this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(3).getT(1);    // wrap::no_process<math::sub<NV>>
		auto expr5 = this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(3).getT(2);   // math::expr<NV, custom::expr5>
		auto fmod = this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(3).getT(3);    // wrap::no_process<math::fmod<NV>>
		auto add5 = this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(3).getT(4);    // math::add<NV>
		auto rect = this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(3).getT(5);    // wrap::no_process<math::rect<NV>>
		auto gain54 = this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(3).getT(6);  // core::gain<NV>
		auto jpanner = this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(3).getT(7); // jdsp::jpanner<NV>
		auto square = this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(3).getT(8);  // wrap::no_process<math::square<NV>>
		auto sin11 = this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(3).getT(9);   // math::sin<NV>
		auto& cable_table = this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(4);    // oscshaper_impl::cable_table_t
		auto& sin12 = this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(5);          // math::sin<NV>
		auto& gain40 = this->getT(0).getT(3).getT(6).getT(1);                         // core::gain<NV>
		auto& chain13 = this->getT(0).getT(3).getT(7);                                // oscshaper_impl::chain13_t<NV>
		auto& gain14 = this->getT(0).getT(3).getT(7).getT(0);                         // core::gain<NV>
		auto& pi6 = this->getT(0).getT(3).getT(7).getT(1);                            // math::pi<NV>
		auto& table4 = this->getT(0).getT(3).getT(7).getT(2);                         // oscshaper_impl::table4_t
		auto& gain26 = this->getT(0).getT(3).getT(7).getT(3);                         // core::gain<NV>
		auto& gain1 = this->getT(0).getT(4);                                          // core::gain<NV>
		auto& one_pole = this->getT(0).getT(5);                                       // filters::one_pole<NV>
		
		// Parameter Connections -------------------------------------------------------------------
		
		this->getParameterT(0).connectT(0, pma); // shaper -> pma::Add
		
		this->getParameterT(1).connectT(0, pma4); // width -> pma4::Add
		
		this->getParameterT(2).connectT(0, pma3); // out -> pma3::Add
		
		this->getParameterT(3).connectT(0, pma); // shapemod -> pma::Multiply
		
		this->getParameterT(4).connectT(0, pma4); // widthmod -> pma4::Multiply
		
		this->getParameterT(5).connectT(0, pma3); // outmod -> pma3::Multiply
		
		this->getParameterT(6).connectT(0, event_data_reader3); // XfStage -> event_data_reader3::SlotIndex
		
		this->getParameterT(7).connectT(0, branch5); // Midi1 -> branch5::Index
		
		this->getParameterT(8).connectT(0, event_data_reader10); // xf2 -> event_data_reader10::SlotIndex
		
		this->getParameterT(9).connectT(0, event_data_reader11); // xf3 -> event_data_reader11::SlotIndex
		
		this->getParameterT(10).connectT(0, branch6); // midi2 -> branch6::Index
		
		this->getParameterT(11).connectT(0, branch7); // midi3 -> branch7::Index
		
		// Modulation Connections ------------------------------------------------------------------
		
		auto& sliderbank_p = sliderbank.getWrappedObject().getParameter();
		sliderbank_p.getParameterT(0).connectT(0, gain);                    // sliderbank -> gain::Gain
		sliderbank_p.getParameterT(1).connectT(0, gain9);                   // sliderbank -> gain9::Gain
		sliderbank_p.getParameterT(2).connectT(0, gain8);                   // sliderbank -> gain8::Gain
		sliderbank_p.getParameterT(3).connectT(0, gain7);                   // sliderbank -> gain7::Gain
		sliderbank_p.getParameterT(4).connectT(0, gain6);                   // sliderbank -> gain6::Gain
		sliderbank_p.getParameterT(5).connectT(0, gain5);                   // sliderbank -> gain5::Gain
		sliderbank_p.getParameterT(6).connectT(0, gain4);                   // sliderbank -> gain4::Gain
		sliderbank_p.getParameterT(7).connectT(0, gain3);                   // sliderbank -> gain3::Gain
		global_cable.getWrappedObject().getParameter().connectT(0, add);    // global_cable -> add::Value
		global_cable2.getWrappedObject().getParameter().connectT(0, add2);  // global_cable2 -> add2::Value
		global_cable1.getWrappedObject().getParameter().connectT(0, add1);  // global_cable1 -> add1::Value
		global_cable25.getWrappedObject().getParameter().connectT(0, add3); // global_cable25 -> add3::Value
		event_data_reader2.getParameter().connectT(0, add7);                // event_data_reader2 -> add7::Value
		event_data_reader1.getParameter().connectT(0, add6);                // event_data_reader1 -> add6::Value
		midi_cc10.getWrappedObject().getParameter().connectT(0, add50);     // midi_cc10 -> add50::Value
		midi_cc11.getWrappedObject().getParameter().connectT(0, add51);     // midi_cc11 -> add51::Value
		midi_cc12.getWrappedObject().getParameter().connectT(0, add52);     // midi_cc12 -> add52::Value
		midi_cc13.getWrappedObject().getParameter().connectT(0, add53);     // midi_cc13 -> add53::Value
		midi6.getParameter().connectT(0, add54);                            // midi6 -> add54::Value
		midi7.getParameter().connectT(0, add55);                            // midi7 -> add55::Value
		midi8.getParameter().connectT(0, add56);                            // midi8 -> add56::Value
		auto& xfader_p = xfader.getWrappedObject().getParameter();
		xfader_p.getParameterT(0).connectT(0, gain11);             // xfader -> gain11::Gain
		xfader_p.getParameterT(1).connectT(0, gain13);             // xfader -> gain13::Gain
		xfader_p.getParameterT(2).connectT(0, gain15);             // xfader -> gain15::Gain
		xfader_p.getParameterT(3).connectT(0, gain45);             // xfader -> gain45::Gain
		xfader_p.getParameterT(4).connectT(0, gain2);              // xfader -> gain2::Gain
		xfader_p.getParameterT(5).connectT(0, gain33);             // xfader -> gain33::Gain
		xfader_p.getParameterT(6).connectT(0, gain40);             // xfader -> gain40::Gain
		xfader_p.getParameterT(7).connectT(0, gain26);             // xfader -> gain26::Gain
		pma.getWrappedObject().getParameter().connectT(0, xfader); // pma -> xfader::Value
		peak.getParameter().connectT(0, pma);                      // peak -> pma::Value
		auto& sliderbank2_p = sliderbank2.getWrappedObject().getParameter();
		sliderbank2_p.getParameterT(0).connectT(0, gain23);                  // sliderbank2 -> gain23::Gain
		sliderbank2_p.getParameterT(1).connectT(0, gain24);                  // sliderbank2 -> gain24::Gain
		sliderbank2_p.getParameterT(2).connectT(0, gain25);                  // sliderbank2 -> gain25::Gain
		sliderbank2_p.getParameterT(3).connectT(0, gain27);                  // sliderbank2 -> gain27::Gain
		sliderbank2_p.getParameterT(4).connectT(0, gain28);                  // sliderbank2 -> gain28::Gain
		sliderbank2_p.getParameterT(5).connectT(0, gain29);                  // sliderbank2 -> gain29::Gain
		sliderbank2_p.getParameterT(6).connectT(0, gain30);                  // sliderbank2 -> gain30::Gain
		sliderbank2_p.getParameterT(7).connectT(0, gain31);                  // sliderbank2 -> gain31::Gain
		global_cable7.getWrappedObject().getParameter().connectT(0, add18);  // global_cable7 -> add18::Value
		global_cable8.getWrappedObject().getParameter().connectT(0, add19);  // global_cable8 -> add19::Value
		global_cable9.getWrappedObject().getParameter().connectT(0, add20);  // global_cable9 -> add20::Value
		global_cable26.getWrappedObject().getParameter().connectT(0, add21); // global_cable26 -> add21::Value
		event_data_reader8.getParameter().connectT(0, add22);                // event_data_reader8 -> add22::Value
		event_data_reader9.getParameter().connectT(0, add23);                // event_data_reader9 -> add23::Value
		event_data_reader10.getParameter().connectT(0, add24);               // event_data_reader10 -> add24::Value
		midi_cc14.getWrappedObject().getParameter().connectT(0, add57);      // midi_cc14 -> add57::Value
		midi_cc15.getWrappedObject().getParameter().connectT(0, add58);      // midi_cc15 -> add58::Value
		midi_cc16.getWrappedObject().getParameter().connectT(0, add59);      // midi_cc16 -> add59::Value
		midi_cc17.getWrappedObject().getParameter().connectT(0, add60);      // midi_cc17 -> add60::Value
		midi9.getParameter().connectT(0, add61);                             // midi9 -> add61::Value
		midi10.getParameter().connectT(0, add62);                            // midi10 -> add62::Value
		midi11.getParameter().connectT(0, add63);                            // midi11 -> add63::Value
		auto& xfader1_p = xfader1.getWrappedObject().getParameter();
		xfader1_p.getParameterT(0).connectT(0, gain34);                      // xfader1 -> gain34::Gain
		xfader1_p.getParameterT(1).connectT(0, gain32);                      // xfader1 -> gain32::Gain
		clone_cable1.getWrappedObject().getParameter().connectT(0, jpanner); // clone_cable1 -> jpanner::Pan
		clone_cable1.getWrappedObject().getParameter().connectT(1, gain54);  // clone_cable1 -> gain54::Gain
		clone_cable3.getWrappedObject().getParameter().connectT(0, expr5);   // clone_cable3 -> expr5::Value
		pma4.getWrappedObject().getParameter().connectT(0, gain14);          // pma4 -> gain14::Gain
		pma4.getWrappedObject().getParameter().connectT(1, gain36);          // pma4 -> gain36::Gain
		pma4.getWrappedObject().getParameter().connectT(2, gain37);          // pma4 -> gain37::Gain
		pma4.getWrappedObject().getParameter().connectT(3, gain44);          // pma4 -> gain44::Gain
		pma4.getWrappedObject().getParameter().connectT(4, expr4);           // pma4 -> expr4::Value
		pma4.getWrappedObject().getParameter().connectT(5, phase_delay);     // pma4 -> phase_delay::Frequency
		pma4.getWrappedObject().getParameter().connectT(6, xfader1);         // pma4 -> xfader1::Value
		pma4.getWrappedObject().getParameter().connectT(7, gain35);          // pma4 -> gain35::Gain
		pma4.getWrappedObject().getParameter().connectT(8, cable_table);     // pma4 -> cable_table::Value
		pma4.getWrappedObject().getParameter().connectT(9, clone_cable1);    // pma4 -> clone_cable1::Value
		pma4.getWrappedObject().getParameter().connectT(10, clone_cable3);   // pma4 -> clone_cable3::Value
		pma4.getWrappedObject().getParameter().connectT(11, gain16);         // pma4 -> gain16::Gain
		peak2.getParameter().connectT(0, pma4);                              // peak2 -> pma4::Value
		auto& sliderbank1_p = sliderbank1.getWrappedObject().getParameter();
		sliderbank1_p.getParameterT(0).connectT(0, gain10);                  // sliderbank1 -> gain10::Gain
		sliderbank1_p.getParameterT(1).connectT(0, gain12);                  // sliderbank1 -> gain12::Gain
		sliderbank1_p.getParameterT(2).connectT(0, gain17);                  // sliderbank1 -> gain17::Gain
		sliderbank1_p.getParameterT(3).connectT(0, gain18);                  // sliderbank1 -> gain18::Gain
		sliderbank1_p.getParameterT(4).connectT(0, gain19);                  // sliderbank1 -> gain19::Gain
		sliderbank1_p.getParameterT(5).connectT(0, gain20);                  // sliderbank1 -> gain20::Gain
		sliderbank1_p.getParameterT(6).connectT(0, gain21);                  // sliderbank1 -> gain21::Gain
		sliderbank1_p.getParameterT(7).connectT(0, gain22);                  // sliderbank1 -> gain22::Gain
		global_cable4.getWrappedObject().getParameter().connectT(0, add10);  // global_cable4 -> add10::Value
		global_cable5.getWrappedObject().getParameter().connectT(0, add11);  // global_cable5 -> add11::Value
		global_cable6.getWrappedObject().getParameter().connectT(0, add12);  // global_cable6 -> add12::Value
		global_cable27.getWrappedObject().getParameter().connectT(0, add13); // global_cable27 -> add13::Value
		event_data_reader5.getParameter().connectT(0, add14);                // event_data_reader5 -> add14::Value
		event_data_reader6.getParameter().connectT(0, add15);                // event_data_reader6 -> add15::Value
		event_data_reader11.getParameter().connectT(0, add16);               // event_data_reader11 -> add16::Value
		midi_cc18.getWrappedObject().getParameter().connectT(0, add64);      // midi_cc18 -> add64::Value
		midi_cc19.getWrappedObject().getParameter().connectT(0, add65);      // midi_cc19 -> add65::Value
		midi_cc20.getWrappedObject().getParameter().connectT(0, add66);      // midi_cc20 -> add66::Value
		midi_cc21.getWrappedObject().getParameter().connectT(0, add67);      // midi_cc21 -> add67::Value
		midi12.getParameter().connectT(0, add68);                            // midi12 -> add68::Value
		midi13.getParameter().connectT(0, add69);                            // midi13 -> add69::Value
		midi14.getParameter().connectT(0, add70);                            // midi14 -> add70::Value
		pma3.getWrappedObject().getParameter().connectT(0, gain1);           // pma3 -> gain1::Gain
		peak1.getParameter().connectT(0, pma3);                              // peak1 -> pma3::Value
		clone_pack.getWrappedObject().getParameter().connectT(0, pi10);      // clone_pack -> pi10::Value
		
		// Default Values --------------------------------------------------------------------------
		
		sliderbank.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add::Value is automated
		
		;                           // gain::Gain is automated
		gain.setParameterT(1, 20.); // core::gain::Smoothing
		gain.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable2.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add2::Value is automated
		
		;                            // gain9::Gain is automated
		gain9.setParameterT(1, 20.); // core::gain::Smoothing
		gain9.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable1.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add1::Value is automated
		
		;                            // gain8::Gain is automated
		gain8.setParameterT(1, 20.); // core::gain::Smoothing
		gain8.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable25.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add3::Value is automated
		
		;                            // gain7::Gain is automated
		gain7.setParameterT(1, 20.); // core::gain::Smoothing
		gain7.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader2.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader2.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add7::Value is automated
		
		;                            // gain6::Gain is automated
		gain6.setParameterT(1, 20.); // core::gain::Smoothing
		gain6.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader1.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader1.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add6::Value is automated
		
		;                            // gain5::Gain is automated
		gain5.setParameterT(1, 20.); // core::gain::Smoothing
		gain5.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                        // event_data_reader3::SlotIndex is automated
		event_data_reader3.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		add8.setParameterT(0, 0.); // math::add::Value
		
		;                            // gain4::Gain is automated
		gain4.setParameterT(1, 20.); // core::gain::Smoothing
		gain4.setParameterT(2, 0.);  // core::gain::ResetValue
		
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
		
		;                            // gain3::Gain is automated
		gain3.setParameterT(1, 20.); // core::gain::Smoothing
		gain3.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma::Value is automated
		; // pma::Multiply is automated
		; // pma::Add is automated
		
		sliderbank2.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable7.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add18::Value is automated
		
		;                             // gain23::Gain is automated
		gain23.setParameterT(1, 20.); // core::gain::Smoothing
		gain23.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable8.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add19::Value is automated
		
		;                             // gain24::Gain is automated
		gain24.setParameterT(1, 20.); // core::gain::Smoothing
		gain24.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable9.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add20::Value is automated
		
		;                             // gain25::Gain is automated
		gain25.setParameterT(1, 20.); // core::gain::Smoothing
		gain25.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable26.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add21::Value is automated
		
		;                             // gain27::Gain is automated
		gain27.setParameterT(1, 20.); // core::gain::Smoothing
		gain27.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader8.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader8.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add22::Value is automated
		
		;                             // gain28::Gain is automated
		gain28.setParameterT(1, 20.); // core::gain::Smoothing
		gain28.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader9.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader9.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add23::Value is automated
		
		;                             // gain29::Gain is automated
		gain29.setParameterT(1, 20.); // core::gain::Smoothing
		gain29.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader10::SlotIndex is automated
		event_data_reader10.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add24::Value is automated
		
		;                             // gain30::Gain is automated
		gain30.setParameterT(1, 20.); // core::gain::Smoothing
		gain30.setParameterT(2, 0.);  // core::gain::ResetValue
		
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
		
		;                             // gain31::Gain is automated
		gain31.setParameterT(1, 20.); // core::gain::Smoothing
		gain31.setParameterT(2, 0.);  // core::gain::ResetValue
		
		sliderbank1.setParameterT(0, 1.); // control::sliderbank::Value
		
		global_cable4.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add10::Value is automated
		
		;                             // gain10::Gain is automated
		gain10.setParameterT(1, 20.); // core::gain::Smoothing
		gain10.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable5.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add11::Value is automated
		
		;                             // gain12::Gain is automated
		gain12.setParameterT(1, 20.); // core::gain::Smoothing
		gain12.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable6.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add12::Value is automated
		
		;                             // gain17::Gain is automated
		gain17.setParameterT(1, 20.); // core::gain::Smoothing
		gain17.setParameterT(2, 0.);  // core::gain::ResetValue
		
		global_cable27.setParameterT(0, 1.); // routing::global_cable::Value
		
		; // add13::Value is automated
		
		;                             // gain18::Gain is automated
		gain18.setParameterT(1, 20.); // core::gain::Smoothing
		gain18.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader5.setParameterT(0, 1.); // routing::event_data_reader::SlotIndex
		event_data_reader5.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add14::Value is automated
		
		;                             // gain19::Gain is automated
		gain19.setParameterT(1, 20.); // core::gain::Smoothing
		gain19.setParameterT(2, 0.);  // core::gain::ResetValue
		
		event_data_reader6.setParameterT(0, 0.); // routing::event_data_reader::SlotIndex
		event_data_reader6.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add15::Value is automated
		
		;                             // gain20::Gain is automated
		gain20.setParameterT(1, 20.); // core::gain::Smoothing
		gain20.setParameterT(2, 0.);  // core::gain::ResetValue
		
		;                                         // event_data_reader11::SlotIndex is automated
		event_data_reader11.setParameterT(1, 0.); // routing::event_data_reader::Static
		
		; // add16::Value is automated
		
		;                             // gain21::Gain is automated
		gain21.setParameterT(1, 20.); // core::gain::Smoothing
		gain21.setParameterT(2, 0.);  // core::gain::ResetValue
		
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
		
		;                             // gain22::Gain is automated
		gain22.setParameterT(1, 20.); // core::gain::Smoothing
		gain22.setParameterT(2, 0.);  // core::gain::ResetValue
		
		; // pma3::Value is automated
		; // pma3::Multiply is automated
		; // pma3::Add is automated
		
		; // xfader::Value is automated
		
		; // pma4::Value is automated
		; // pma4::Multiply is automated
		; // pma4::Add is automated
		
		; // xfader1::Value is automated
		
		sub.setParameterT(0, 0.5); // math::sub::Value
		
		abs.setParameterT(0, 1.); // math::abs::Value
		
		mul1.setParameterT(0, 2.); // math::mul::Value
		
		;                               // gain34::Gain is automated
		gain34.setParameterT(1, 19.1);  // core::gain::Smoothing
		gain34.setParameterT(2, -100.); // core::gain::ResetValue
		
		expr.setParameterT(0, 1.); // math::expr::Value
		
		;                              // gain32::Gain is automated
		gain32.setParameterT(1, 19.8); // core::gain::Smoothing
		gain32.setParameterT(2, -22.); // core::gain::ResetValue
		
		;                              // gain11::Gain is automated
		gain11.setParameterT(1, 0.);   // core::gain::Smoothing
		gain11.setParameterT(2, -13.); // core::gain::ResetValue
		
		;                              // gain16::Gain is automated
		gain16.setParameterT(1, 20.6); // core::gain::Smoothing
		gain16.setParameterT(2, -12.); // core::gain::ResetValue
		
		rect1.setParameterT(0, 1.); // math::rect::Value
		
		;                               // gain13::Gain is automated
		gain13.setParameterT(1, 20.);   // core::gain::Smoothing
		gain13.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                             // gain37::Gain is automated
		gain37.setParameterT(1, 20.); // core::gain::Smoothing
		gain37.setParameterT(2, 0.);  // core::gain::ResetValue
		
		mul.setParameterT(0, 1.); // math::mul::Value
		
		pi5.setParameterT(0, 1.); // math::pi::Value
		
		;                               // gain15::Gain is automated
		gain15.setParameterT(1, 0.);    // core::gain::Smoothing
		gain15.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                              // gain44::Gain is automated
		gain44.setParameterT(1, 7);    // core::gain::Smoothing
		gain44.setParameterT(2, -12.); // core::gain::ResetValue
		
		; // expr4::Value is automated
		
		sin5.setParameterT(0, 1.); // math::sin::Value
		
		;                               // gain45::Gain is automated
		gain45.setParameterT(1, 0.);    // core::gain::Smoothing
		gain45.setParameterT(2, -100.); // core::gain::ResetValue
		
		pi7.setParameterT(0, 0.5); // math::pi::Value
		
		sin.setParameterT(0, 1.); // math::sin::Value
		
		;                              // gain35::Gain is automated
		gain35.setParameterT(1, 20.);  // core::gain::Smoothing
		gain35.setParameterT(2, -12.); // core::gain::ResetValue
		
		sin6.setParameterT(0, 1.); // math::sin::Value
		
		expr1.setParameterT(0, 1.); // math::expr::Value
		
		;                              // gain2::Gain is automated
		gain2.setParameterT(1, 0.);    // core::gain::Smoothing
		gain2.setParameterT(2, -100.); // core::gain::ResetValue
		
		pi2.setParameterT(0, 0.465825); // math::pi::Value
		
		; // phase_delay::Frequency is automated
		
		;                              // gain36::Gain is automated
		gain36.setParameterT(1, 20.);  // core::gain::Smoothing
		gain36.setParameterT(2, -12.); // core::gain::ResetValue
		
		expr2.setParameterT(0, 0.479197); // math::expr::Value
		
		sin8.setParameterT(0, 1.); // math::sin::Value
		
		;                               // gain33::Gain is automated
		gain33.setParameterT(1, 0.);    // core::gain::Smoothing
		gain33.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                                  // clone_cable1::NumClones is deactivated
		;                                  // clone_cable1::Value is automated
		clone_cable1.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		;                                  // clone_cable3::NumClones is deactivated
		;                                  // clone_cable3::Value is automated
		clone_cable3.setParameterT(2, 0.); // control::clone_cable::Gamma
		
		clone_pack.setParameterT(0, 16.); // control::clone_pack::NumClones
		clone_pack.setParameterT(1, 1.);  // control::clone_pack::Value
		
		clone.setParameterT(0, 16.); // container::clone::NumClones
		clone.setParameterT(1, 2.);  // container::clone::SplitSignal
		
		; // pi10::Value is automated
		
		sub2.setParameterT(0, 1.); // math::sub::Value
		
		; // expr5::Value is automated
		
		fmod.setParameterT(0, 1.); // math::fmod::Value
		
		add5.setParameterT(0, 1.); // math::add::Value
		
		rect.setParameterT(0, 0.); // math::rect::Value
		
		;                               // gain54::Gain is automated
		gain54.setParameterT(1, 408.9); // core::gain::Smoothing
		gain54.setParameterT(2, -12.);  // core::gain::ResetValue
		
		;                             // jpanner::Pan is automated
		jpanner.setParameterT(1, 1.); // jdsp::jpanner::Rule
		
		square.setParameterT(0, 1.); // math::square::Value
		
		sin11.setParameterT(0, 0.675095); // math::sin::Value
		
		; // cable_table::Value is automated
		
		sin12.setParameterT(0, 1.); // math::sin::Value
		
		;                               // gain40::Gain is automated
		gain40.setParameterT(1, 0.);    // core::gain::Smoothing
		gain40.setParameterT(2, -100.); // core::gain::ResetValue
		
		;                              // gain14::Gain is automated
		gain14.setParameterT(1, 10.8); // core::gain::Smoothing
		gain14.setParameterT(2, -11.); // core::gain::ResetValue
		
		pi6.setParameterT(0, 1.); // math::pi::Value
		
		;                              // gain26::Gain is automated
		gain26.setParameterT(1, 20.);  // core::gain::Smoothing
		gain26.setParameterT(2, -9.5); // core::gain::ResetValue
		
		;                              // gain1::Gain is automated
		gain1.setParameterT(1, 20.);   // core::gain::Smoothing
		gain1.setParameterT(2, -100.); // core::gain::ResetValue
		
		one_pole.setParameterT(0, 50.1457); // filters::one_pole::Frequency
		one_pole.setParameterT(1, 1.);      // filters::one_pole::Q
		one_pole.setParameterT(2, 0.);      // filters::one_pole::Gain
		one_pole.setParameterT(3, 0.01);    // filters::one_pole::Smoothing
		one_pole.setParameterT(4, 1.);      // filters::one_pole::Mode
		one_pole.setParameterT(5, 1.);      // filters::one_pole::Enabled
		
		this->setParameterT(0, 7.);
		this->setParameterT(1, 0.33);
		this->setParameterT(2, 0.28);
		this->setParameterT(3, 0.);
		this->setParameterT(4, 0.);
		this->setParameterT(5, 0.);
		this->setParameterT(6, 1.);
		this->setParameterT(7, 1.);
		this->setParameterT(8, 1.);
		this->setParameterT(9, 1.);
		this->setParameterT(10, 1.);
		this->setParameterT(11, 1.);
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
		
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable2_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable1_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable25_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable7_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable8_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable9_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable26_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(0).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable4_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(1).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable5_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(2).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable6_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(1).getT(3).getT(0).connectToRuntimeTarget(addConnection, c); // oscshaper_impl::global_cable27_t<NV>
	}
	
	void setExternalData(const ExternalData& b, int index)
	{
		// External Data Connections ---------------------------------------------------------------
		
		this->getT(0).getT(0).getT(0).getT(0).getT(0).setExternalData(b, index);         // oscshaper_impl::sliderbank_t<NV>
		this->getT(0).getT(0).getT(0).getT(0).getT(2).setExternalData(b, index);         // oscshaper_impl::peak_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(0).setExternalData(b, index);         // oscshaper_impl::sliderbank2_t<NV>
		this->getT(0).getT(0).getT(0).getT(1).getT(2).setExternalData(b, index);         // oscshaper_impl::peak2_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(0).setExternalData(b, index);         // oscshaper_impl::sliderbank1_t<NV>
		this->getT(0).getT(0).getT(0).getT(2).getT(2).setExternalData(b, index);         // oscshaper_impl::peak1_t<NV>
		this->getT(0).getT(3).getT(1).getT(2).setExternalData(b, index);                 // oscshaper_impl::oscilloscope_t
		this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(2).setExternalData(b, index); // oscshaper_impl::clone_pack_t<NV>
		this->getT(0).getT(3).getT(6).getT(0).getT(0).getT(4).setExternalData(b, index); // oscshaper_impl::cable_table_t
		this->getT(0).getT(3).getT(7).getT(2).setExternalData(b, index);                 // oscshaper_impl::table4_t
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
using oscshaper = wrap::node<oscshaper_impl::instance<NV>>;
}


