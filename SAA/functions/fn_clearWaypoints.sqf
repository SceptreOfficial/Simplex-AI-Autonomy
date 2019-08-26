#include "script_component.hpp"

params ["_group",["_cacheWaypoints",false,[false]]];

if (_cacheWaypoints) then {
	_group setVariable ["SAA_waypointsCache",(waypoints _group) apply {[
		waypointPosition _x,waypointType _x,
		waypointBehaviour _x,waypointCombatMode _x,
		waypointSpeed _x,waypointFormation _x,
		waypointStatements _x,waypointTimeout _x,
		waypointCompletionRadius _x
	]}];
};

{deleteWaypoint [_group,0]; false} count (waypoints _group);

// Select an alive unit as leader
private _leader = leader _group;
if (!alive _leader) then {
	_leader = ((units _group) select {alive _x}) # 0;
	_group selectLeader _leader;
};

_group enableAttack true;
{_x setUnitPos "AUTO"; false} count (units _group);

// Halt movement to old waypoint
private _WP = [_group,getPos _leader,0,"MOVE","","","","",["true",""],[0,0,0],10] call SAA_fnc_addWaypoint;
_group setCurrentWaypoint _WP;
_leader doMove (waypointPosition _WP);
(units _group) doFollow _leader;