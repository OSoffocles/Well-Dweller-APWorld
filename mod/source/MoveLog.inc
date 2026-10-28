// F8: movement recorder (writes archipelago/move_N.csv). Press F8 to start, F8 again to stop.
// While on, every player step is written to archipelago/move_N.csv, and the first line block
// lists every oPlayer variable once (jump height, gravity, stamina and so on with the current trinkets).
static bool g_F8 = false;
static bool g_MoveRec = false;
static int g_MoveCount = 0;
static long g_MoveFrame = 0;
static std::ofstream g_MoveFile;
static const char* MOVE_VARS[] = { "x", "y", "hsp", "vsp", "state", "on_ground", "on_wall", "hold_wall", "stamina", "stamina_max",
	"fly_stamina", "fly_stamina_max", "hover_bool", "hover_tm", "soar", "wall_sling", "to_sling", "sling_tm", "grv", "jumpheight",
	"runsp", "walksp", "maxvsp", "dir_facing", "current_djump", "swing_spd", "bounce_spd", "dash_tm" };

static void MoveRecorderHotkey()
{
	bool f8 = (GetAsyncKeyState(VK_F8) & 0x8000) != 0;
	bool pressed = f8 && !g_F8;
	g_F8 = f8;
	if (!pressed) return;
	if (g_MoveRec)
	{
		g_MoveRec = false;
		g_MoveFile.close();
		Log("F8: movement recording stopped (" + std::to_string(g_MoveFrame) + " steps)");
		g_Toast = "Movement recording stopped"; g_ToastUntil = GetTickCount64() + 3000;
		return;
	}
	RValue player; double px, py; std::string why;
	if (!InstanceXY("oPlayer", player, px, py, why)) { Log("F8: " + why); return; }
	g_MoveCount++;
	g_MoveFrame = 0;
	g_MoveFile.open(g_Dir / ("move_" + std::to_string(g_MoveCount) + ".csv"), std::ios::trunc);
	g_MoveFile << "# room " << g_LastRoom << "\n";
	RValue names = g_Yytk->CallBuiltin("variable_instance_get_names", { player });
	size_t nn = 0;
	if (names.IsArray() && AurieSuccess(g_Yytk->GetArraySize(names, nn)))
		for (size_t j = 0; j < nn; j++)
		{
			RValue* nm = nullptr;
			if (!AurieSuccess(g_Yytk->GetArrayEntry(names, j, nm)) || !nm) continue;
			RValue v = g_Yytk->CallBuiltin("variable_instance_get", { player, *nm });
			g_MoveFile << "# " << nm->ToString() << " = " << Describe(v) << "\n";
		}
	g_MoveFile << "frame,room";
	for (const char* v : MOVE_VARS) g_MoveFile << "," << v;
	g_MoveFile << ",sprite\n";
	g_MoveRec = true;
	Log("F8: movement recording started -> move_" + std::to_string(g_MoveCount) + ".csv");
	g_Toast = "Recording movement (F8 to stop)"; g_ToastUntil = GetTickCount64() + 3000;
}

// called right after oPlayer's Step event
static void MoveRecorderStep()
{
	if (!g_MoveRec || !g_MoveFile.is_open()) return;
	RValue player; double px, py; std::string why;
	if (!InstanceXY("oPlayer", player, px, py, why)) return;
	g_MoveFile << g_MoveFrame++ << "," << CurrentRoomName();
	for (const char* v : MOVE_VARS)
	{
		RValue r = g_Yytk->CallBuiltin("variable_instance_get", { player, RValue(std::string_view(v)) });
		g_MoveFile << "," << (r.IsNumberConvertible() ? Num(r.ToDouble()) : std::string(""));
	}
	RValue spr = g_Yytk->CallBuiltin("variable_instance_get", { player, RValue(std::string_view("sprite_index")) });
	RValue sn = g_Yytk->CallBuiltin("sprite_get_name", { spr });
	g_MoveFile << "," << (sn.IsString() ? sn.ToString() : std::string("")) << "\n";
}
