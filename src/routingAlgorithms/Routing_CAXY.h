#ifndef __NOXIMROUTING_CAXY_H__
#define __NOXIMROUTING_CAXY_H__

#include "RoutingAlgorithm.h"
#include "RoutingAlgorithms.h"
#include "../Router.h"

using namespace std;

class Routing_CAXY : RoutingAlgorithm {
	public:
		vector<int> route(Router * router, const RouteData & routeData);

		static Routing_CAXY * getInstance();
    inline string name() { return "Routing_CAXY";};

	private:
		Routing_CAXY(){};
		~Routing_CAXY(){};

		static Routing_CAXY * routing_CAXY;
		static RoutingAlgorithmsRegister routingAlgorithmsRegister;
		static RoutingAlgorithm * xy;
};

#endif
