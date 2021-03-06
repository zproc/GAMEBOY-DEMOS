#include "ZGBMain.h"
#include "StateMenu.h"
#include "StateLevel1.h"
#include "SpritePlayer.h"
#include "../res/src/player.h"
#include "SpriteEnemy.h"
#include "../res/src/enemy.h"

UINT8 next_state = STATE_MENU;

SET_N_STATES(N_STATES);
SET_N_SPRITE_TYPES(N_SPRITE_TYPES);

void InitStates() {
	INIT_STATE(STATE_MENU);	
	INIT_STATE(STATE_LEVEL1);
}

void InitSprites() {
	INIT_SPRITE(SPRITE_PLAYER, player, 3, FRAME_16x16, 14);
	INIT_SPRITE(SPRITE_ENEMY, enemy, 3, FRAME_16x16, 6);
}

#include "Math.h"
UINT8 GetTileReplacement(UINT8* tile_ptr, UINT8* tile) {
	if(current_state == STATE_LEVEL1) {
		if(U_LESS_THAN(255 - (UINT16)*tile_ptr, N_SPRITE_TYPES)) {
			*tile = 0;
			return 255 - (UINT16)*tile_ptr;
		}

		*tile = *tile_ptr;
	}
	return 255u;
}

