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

namespace shift_impl
{
// ====================| Node & Parameter type declarations |====================

using stereo_cable = cable::block<2>;

namespace shift_t_parameters
{
// Parameter list for shift_impl::shift_t ---------------------------------------

template <int NV>
using shift = parameter::plain<project::shfiter<NV>, 0>;
template <int NV>
using Win = parameter::plain<project::shfiter<NV>, 1>;
template <int NV>
using Xf = parameter::plain<project::shfiter<NV>, 2>;
using Feed = parameter::plain<routing::receive<stereo_cable>, 
                              0>;
template <int NV>
using shift_t_plist = parameter::list<shift<NV>, 
                                      Win<NV>, 
                                      Xf<NV>, 
                                      Feed>;
}

template <int NV>
using shift_t_ = container::chain<shift_t_parameters::shift_t_plist<NV>, 
                                  wrap::fix<2, routing::receive<stereo_cable>>, 
                                  project::shfiter<NV>, 
                                  routing::send<stereo_cable>>;

// ========================| Root node initialiser class |========================

template <int NV> struct instance: public shift_impl::shift_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(shift);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(60)
		{
			0x005B, 0x0000, 0x7300, 0x6968, 0x7466, 0x0000, 0x8000, 0x00C2, 
            0x8000, 0x0042, 0x8000, 0x003F, 0x8000, 0x003F, 0x8000, 0x5B3F, 
            0x0001, 0x0000, 0x6957, 0x006E, 0x0000, 0x4248, 0x4000, 0x461C, 
            0x0000, 0x4248, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x025B, 0x0000, 
            0x5800, 0x0066, 0x0000, 0x3F80, 0x4000, 0x461C, 0x0000, 0x3F80, 
            0x0000, 0x3F80, 0x0000, 0x3F80, 0x035B, 0x0000, 0x4600, 0x6565, 
            0x0064, 0x0000, 0x0000, 0x0000, 0x3F80, 0x0000, 0x3F80, 0x0000, 
            0x3F80, 0x0000, 0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References ------------------------------------------------------
		
		auto& receive = this->getT(0); // routing::receive<stereo_cable>
		auto& faust = this->getT(1);   // project::shfiter<NV>
		auto& send = this->getT(2);    // routing::send<stereo_cable>
		
		// Parameter Connections ------------------------------------------------
		
		this->getParameterT(0).connectT(0, faust); // shift -> faust::shiftfreq
		
		this->getParameterT(1).connectT(0, faust); // Win -> faust::windowsamples
		
		this->getParameterT(2).connectT(0, faust); // Xf -> faust::xfadesamples
		
		this->getParameterT(3).connectT(0, receive); // Feed -> receive::Feedback
		
		// Send Connections -----------------------------------------------------
		
		send.connect(receive);
		
		// Default Values -------------------------------------------------------
		
		; // receive::Feedback is automated
		
		; // faust::shiftfreq is automated
		; // faust::windowsamples is automated
		; // faust::xfadesamples is automated
		
		this->setParameterT(0, 1.);
		this->setParameterT(1, 50.);
		this->setParameterT(2, 1.);
		this->setParameterT(3, 1.);
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// =============================| Public Definition |=============================

namespace project
{
// polyphonic template declaration

template <int NV>
using shift = wrap::node<shift_impl::instance<NV>>;
}


