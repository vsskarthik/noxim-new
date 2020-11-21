#ifndef __NOXIMSELECTION_RANDOM_FA__
#define __NOXIMSELECTION_RANDOM_FA__

#include "SelectionStrategy.h"
#include "SelectionStrategies.h"
#include "../Router.h"

using namespace std;

class Selection_FA : SelectionStrategy {
	public:
        int apply(Router * router, const vector < int >&directions, const RouteData & route_data);
        void perCycleUpdate(Router * router);

		static Selection_FA * getInstance();

	private:
		Selection_FA(){};
		~Selection_FA(){};

		static Selection_FA * selection_FA;
		static SelectionStrategiesRegister selectionStrategiesRegister;
};

#endif
