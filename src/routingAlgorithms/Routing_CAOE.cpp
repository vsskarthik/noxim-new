#include "Routing_CAOE.h"

RoutingAlgorithmsRegister Routing_CAOE::routingAlgorithmsRegister("CAOE", getInstance());

Routing_CAOE * Routing_CAOE::routing_CAOE = 0;
RoutingAlgorithm * Routing_CAOE::odd_even = 0;

Routing_CAOE * Routing_CAOE::getInstance() {
	if ( routing_CAOE == 0 )
		routing_CAOE = new Routing_CAOE();

	return routing_CAOE;
}

vector<int> Routing_CAOE::route(Router * router, const RouteData & routeData)
{
		vector<int> directions;
		odd_even = RoutingAlgorithms::get("ODD_EVEN");

		if (!odd_even)
				assert(false);

		vector<int> temp_dirs = odd_even->route(router,routeData);
		if(temp_dirs.size() == 1)
			directions.push_back(temp_dirs[0]);
		else{
			int ci1 = router->CI(temp_dirs[0]);
			int ci2 = router->CI(temp_dirs[1]);
			if(ci1<ci2)
				directions.push_back(temp_dirs[0]);
			else if(ci1>ci2)
				directions.push_back(temp_dirs[1]);
			else{
				directions.push_back(temp_dirs[0]);
				directions.push_back(temp_dirs[1]);
			}
		}

    return directions;
}
