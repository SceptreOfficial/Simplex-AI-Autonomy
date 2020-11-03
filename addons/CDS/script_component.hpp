#define COMPONENT cds
#include "\z\saa\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE

#ifdef DEBUG_ENABLED_CDS
	#define DEBUG_MODE_FULL
#endif
	#ifdef DEBUG_SETTINGS_CDS
	#define DEBUG_SETTINGS DEBUG_SETTINGS_CDS
#endif

#include "\z\saa\addons\main\script_macros.hpp"
#include "\a3\ui_f\hpp\definecommongrids.inc"
#include "\a3\ui_f\hpp\definedikcodes.inc"
#include "\a3\ui_f_curator\ui\defineresincldesign.inc"

#define GRID_W(N) (N * GUI_GRID_W)
#define GRID_H(N) (N * GUI_GRID_H)

#define COLOR_DISABLED 1,1,1,0.35

#define SPACING_W GRID_W(0.25)
#define SPACING_H GRID_H(0.25)
#define BUFFER_W GRID_W(0.3)
#define BUFFER_H GRID_H(0.3)
#define MIN_HEIGHT GRID_H(1.3)
#define MAX_HEIGHT GRID_H(21)
#define CONTENT_WIDTH GRID_W(30)
#define ITEM_HEIGHT GRID_H(1.3)
#define DESCRIPTION_WIDTH GRID_W(12)
#define TITLE_HEIGHT GRID_H(1.3)
#define MENU_BUTTON_WIDTH GRID_W(6)
#define MENU_BUTTON_HEIGHT GRID_H(1.2)

#define CONTROL_X (DESCRIPTION_WIDTH + SPACING_W)
#define CONTROL_WIDTH (CONTENT_WIDTH - DESCRIPTION_WIDTH - SPACING_W)

#define CHECKBOX_WIDTH GRID_W(1.25)
#define CHECKBOX_HEIGHT GRID_H(1.3)
#define EDITBOX_WIDTH CONTROL_WIDTH
#define EDITBOX_HEIGHT ITEM_HEIGHT
#define SLIDER_EDIT_WIDTH GRID_W(3)
#define SLIDER_WIDTH (CONTROL_WIDTH - SPACING_W - SLIDER_EDIT_WIDTH)
#define SLIDER_HEIGHT ITEM_HEIGHT
#define COMBOBOX_WIDTH CONTROL_WIDTH
#define COMBOBOX_HEIGHT ITEM_HEIGHT
#define LISTNBOX_WIDTH (DESCRIPTION_WIDTH + SPACING_W + CONTROL_WIDTH)
#define LISTNBOX_HEIGHT ITEM_HEIGHT
#define BUTTON_WIDTH (DESCRIPTION_WIDTH + SPACING_W + CONTROL_WIDTH)
#define BUTTON2_WIDTH (((DESCRIPTION_WIDTH + SPACING_W + CONTROL_WIDTH) / 2) - (SPACING_W / 2))
#define BUTTON_HEIGHT ITEM_HEIGHT
#define CARGOBOX_WIDTH (((DESCRIPTION_WIDTH + SPACING_W + CONTROL_WIDTH) * 0.475) - SPACING_W)
#define CARGOBOX_HEIGHT ITEM_HEIGHT
#define CARGOBOX_BUTTON_WIDTH ((DESCRIPTION_WIDTH + SPACING_W + CONTROL_WIDTH) * 0.05)
#define CARGOBOX_BUTTON_HEIGHT (ITEM_HEIGHT * 0.6)
#define TREE_WIDTH (DESCRIPTION_WIDTH + SPACING_W + CONTROL_WIDTH)
#define TREE_HEIGHT ITEM_HEIGHT

#define CREATE_DESCRIPTION \
	private _ctrlDescription = _display ctrlCreate [QGVAR(Text),-1,_ctrlGroup]; \
	_ctrlDescription ctrlSetPosition [0,_posY,DESCRIPTION_WIDTH,ITEM_HEIGHT]; \
	_ctrlDescription ctrlCommit 0; \
	_ctrlDescription ctrlSetText _descriptionText; \
	_ctrlDescription ctrlSetTooltip _descriptionTooltip
