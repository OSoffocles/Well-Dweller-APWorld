# WellDwellerAP (game mod)

[Aurie](https://github.com/AurieFramework/Aurie) + [YYToolkit](https://github.com/AurieFramework/YYToolkit) v5 mod that connects Well Dweller to the Archipelago client.

Build: open `WellDwellerAP.sln` in [Visual Studio](https://visualstudio.microsoft.com/) (workload: Desktop development with C++), configuration **Release | x64**, Build > Build Solution.
Output: `build\WellDwellerAP.dll` -> copy to `<Well Dweller>\mods\aurie\`.

The mod and the client talk through text files in `<Well Dweller>\archipelago\` (items.txt, checks.txt, state.txt, mod.log).
