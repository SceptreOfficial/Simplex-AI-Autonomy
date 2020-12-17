#include "script_component.hpp"

params ["_logic","_synced"];

if (!local _logic) exitWith {};
	
[{
	params ["_logic","_synced"];

	if (!local _logic) exitWith {};

	private _object = attachedTo _logic;
	deleteVehicle _logic;

	if (isNull _object) then {
		[{
			params ["_curatorSelected"];
			_curatorSelected params ["_objects","_groups"];

			if (_objects isEqualTo [] && {_groups isEqualTo []}) exitWith {[objNull,"Nothing selected"] call BIS_fnc_showCuratorFeedbackMessage;};

			{_groups pushBackUnique (group _x)} forEach _objects;

			if (_groups isEqualTo []) exitWith {[objNull,"No valid groups were selected"] call BIS_fnc_showCuratorFeedbackMessage;};

			["Toggle cachine",[
				["CHECKBOX","Allow caching for selected groups",false]
			],{
				{_x setVariable ["SAA_allowCaching",_this # 0 # 0,true]} forEach (_this # 1);
			},{},_groups] call EFUNC(CDS,dialog);
		}] call FUNC(zeusSelection);
	} else {
		private _group = group _object;

		["Toggle cachine",[
			["CHECKBOX","Allow caching for selected groups",false]
		],{
			(_this # 1) setVariable ["SAA_allowCaching",_this # 0 # 0,true];
		},{},_group] call EFUNC(CDS,dialog);
	};
},_this] call CBA_fnc_directCall;
