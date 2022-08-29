#include <cstdint>
#include <string>
#include <unordered_set>

#include "discord_rpc.h"

#include "wrect.h"
#include "cl_dll.h"
#include "discord_integration.h"
#include "hud.h"
#include "parsemsg.h"
#include <time.h>

namespace discord_integration
{
	// From Discord developer dashboard.
	constexpr const char CLIENT_ID[] = "1013569273341423626";

	// This seems to be consistent across PCs.
	constexpr const char STEAM_APP_ID[] = "10";

	namespace
	{
		// For tracking if we're in-game.
		bool updated_client_data = false;

		// The current state.
		state current_state;

		// The current gamemode.
		std::string current_gamemode;

		// void handle_joinGame(const char* join_secret)
		// {
                // 
		// }
                // 
		// void handle_spectateGame(const char* spectate_secret)
		// {
                // 
		// }
                // 
		// void handle_joinRequest(const DiscordJoinRequest* request)
		// {
                // 
		// }


		void update()
		{
			DiscordRichPresence presence{};
		    static char szMapNameStripped[55];
		    const char *szMapName = gEngfuncs.pfnGetLevelName( ); //  "maps/%s.bsp"
		    const char *bspli     = strncpy( szMapNameStripped, szMapName + 5, sizeof( szMapNameStripped ) );
		    char isimmap[256];
		    char isimserver[256];
		    sprintf( isimmap, "Map: %s", bspli );
			sprintf( isimserver, "Server: %s", gHUD.m_szServerName );
		    static int64_t startTimestamp = time( 0 );
		    

			switch (current_state)
			{
			case state::NOT_PLAYING:
				presence.state = "In Menus";
			    presence.largeImageKey  = "xash";
			    presence.largeImageText = "Discord RPC by wg-";
			    presence.smallImageKey  = "cs";
			    presence.smallImageText = "Counter-Strike";
				break;

			case state::PLAYING:
				presence.state = "Playing";
			    presence.details        = isimmap;
			    presence.startTimestamp = startTimestamp;
			    presence.largeImageKey  = "xash";
			    presence.largeImageText = "Discord RPC by wg-";
			    presence.smallImageKey  = "cs";
			    presence.smallImageText = "Counter-Strike";
			    presence.state          = isimserver;
			    presence.partySize      = 1;
			    presence.partyMax       = 32; //yakinda eklicem raat olun
				break;

			case state::SPECTATING:
				presence.state = "Spectating";
			    presence.details        = isimmap;
			    presence.startTimestamp = startTimestamp;
			    presence.largeImageKey  = "xash";
			    presence.largeImageText = "Discord RPC by wg-";
			    presence.smallImageKey  = "cs";
			    presence.smallImageText = "Counter-Strike";
			    presence.state          = isimserver;
			    presence.partySize      = 1;
			    presence.partyMax       = 32;
				break;
			}

			if (current_state != state::NOT_PLAYING && !current_gamemode.empty())
				presence.details = current_gamemode.c_str();

			Discord_UpdatePresence(&presence);
		}
	}

	void initialize()
	{
		DiscordEventHandlers handlers{};
		Discord_Initialize(CLIENT_ID, &handlers, 1, STEAM_APP_ID);

		current_state = state::NOT_PLAYING;
		update();

		Discord_RunCallbacks();
	}

	void shutdown()
	{
		Discord_Shutdown();
	}

	void set_state(state new_state)
	{
		if (current_state != new_state)
		{
			current_state = new_state;

			if (new_state == state::NOT_PLAYING)
				current_gamemode.clear();

			update();
		}
	}

	void set_gamemode(const char* new_gamemode)
	{
		if (current_gamemode != new_gamemode)
		{
			current_gamemode = new_gamemode;
			update();
		}
	}

	void on_update_client_data()
	{
		updated_client_data = true;
	}

	void on_frame()
	{
		if (!updated_client_data)
			set_state(state::NOT_PLAYING);
		else if (current_state == state::NOT_PLAYING)
			set_state(state::PLAYING);

		updated_client_data = false;

		Discord_RunCallbacks();
	}
}