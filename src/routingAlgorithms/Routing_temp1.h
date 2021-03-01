#ifndef __NOXIMROUTING_temp1_H__
#define __NOXIMROUTING_temp1_H__

#include "RoutingAlgorithm.h"
#include "RoutingAlgorithms.h"
#include "../Router.h"

using namespace std;

class Routing_temp1 : RoutingAlgorithm {
	public:
		vector<int> route(Router * router, const RouteData & routeData);

		static Routing_temp1 * getInstance();
    inline string name() { return "Routing_temp1";};

	private:
		Routing_temp1(){};
		~Routing_temp1(){};

		static Routing_temp1 * routing_temp1;
		static RoutingAlgorithmsRegister routingAlgorithmsRegister;
		static RoutingAlgorithm * caoe;
		static RoutingAlgorithm * caxy;
};

#endif
