#ifndef __NOXIMROUTING_CAOE_H__
#define __NOXIMROUTING_CAOE_H__

#include "RoutingAlgorithm.h"
#include "RoutingAlgorithms.h"
#include "../Router.h"

using namespace std;

class Routing_CAOE : RoutingAlgorithm {
	public:
		vector<int> route(Router * router, const RouteData & routeData);

		static Routing_CAOE * getInstance();
    inline string name() { return "Routing_CAOE";};

	private:
		Routing_CAOE(){};
		~Routing_CAOE(){};

		static Routing_CAOE * routing_CAOE;
		static RoutingAlgorithmsRegister routingAlgorithmsRegister;
		static RoutingAlgorithm * odd_even;
};

#endif
