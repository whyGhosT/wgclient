#include "hud.h"
#include "cl_util.h"
#include "cl_entity.h"
#include "triangleapi.h"
#include "draw_util.h"
#include "com_model.h"
#include "calcscreen.h"

SCREENINFO ScreenInfo;

int CHudHeadName::Init(void)
{
	gHUD.AddHudElem(this);

	m_iFlags |= HUD_DRAW;

	return 1;
}

int CHudHeadName::VidInit(void)
{

	return 1;
}

bool CHudHeadName::CheckForPlayer(cl_entity_s *pEnt)
{
	if (pEnt && pEnt->model && pEnt->model->name && pEnt->player)
		return true;

	return false;
}

int CHudHeadName::Draw(float flTime)
{
	if ( ( gHUD.m_iHideHUDDisplay & HIDEHUD_ALL ) || g_iUser1 || !gHUD.cl_headname->value )
		return 1;

	for ( int i = 1; i < 33; i++ )	
	{
		cl_entity_t *ent = gEngfuncs.GetEntityByIndex( i );

		if ( !CheckForPlayer( ent ) )
			continue;

		model_t *model = ent->model;
		vec3_t origin  = ent->origin;

		if ( model )
			origin.z += max( model->mins.z, 0.0 );

		float screen[2]{ -1, -1 };
		if ( !CalcScreen( origin, screen ) )
			continue;

		int textlen = DrawUtils::HudStringLen( g_PlayerInfoList[i].name );

			if (g_PlayerExtraInfo[i].dead)
			{
				DrawUtils::DrawHudString( screen[0] - textlen * 0.2f, screen[1], gHUD.m_scrinfo.iWidth, g_PlayerInfoList[i].name, 150, 150, 150 );
			}

			if (g_PlayerExtraInfo[i].teamnumber != g_PlayerExtraInfo[gHUD.m_Scoreboard.m_iPlayerNum].teamnumber)
			{
				DrawUtils::DrawHudString( screen[0] - textlen * 0.2f, screen[1], gHUD.m_scrinfo.iWidth, g_PlayerInfoList[i].name, 255, 0, 0 );
			}

			if (i != gHUD.m_Scoreboard.m_iPlayerNum)
			{
				DrawUtils::DrawHudString( screen[0] - textlen * 0.2f, screen[1], gHUD.m_scrinfo.iWidth, g_PlayerInfoList[i].name, 0, 0, 255 );
			}
	}

	return 1;
}