# Well Dweller – Archipelago

[Archipelago](https://archipelago.gg) multiworld support for **Well Dweller**: an APWorld (logic, options and the
Well Dweller Client) and a game mod for [Aurie](https://github.com/AurieFramework/Aurie) /
[YYToolkit](https://github.com/AurieFramework/YYToolkit).

> **Public test build (alpha).** Expect bugs and logic gaps. Please test with the Logic Test world and report in
> the Discord - see "Testing with Logic Test" in the [setup guide](docs/setup_en.md).

- Setup, client commands and in-game features: [docs/setup_en.md](docs/setup_en.md)
- Game mod source and build steps: [mod/README.md](mod/README.md)

## Quick start
1. Install Aurie/YYToolkit for Well Dweller with the [Aurie Installer](https://github.com/AurieFramework/Aurie/releases)
   and copy `WellDwellerAP.dll` to `<Well Dweller>\mods\aurie\`.
2. Install [Archipelago](https://github.com/ArchipelagoMW/Archipelago/releases) 0.6.4 or newer, then double-click
   `well_dweller.apworld` (or copy it to Archipelago's `custom_worlds`).
3. Generate with a Well Dweller YAML, start **Well Dweller Client** from the Archipelago Launcher, connect,
   then start a new game in an empty save slot.

Release files: `well_dweller.apworld`, `WellDwellerAP.dll`, `Well Dweller.yaml` (template) and `Logic Test.yaml`.

## Goals
| Goal | What you do | Detected |
|---|---|---|
| `queen` (default) | Defeat the Queen | automatically |
| `true_ending` | Return all 20 Spirits and collect the 5 Spirit Fragments (and defeat the Queen) | `/goal` in the client |
| `secret_treasure` | Collect and equip all 32 trinkets | automatically |

## Locations
Up to 620 locations, depending on your options.

| Always on | Count |
|---|---|
| Bosses | 12 |
| Ability eggs (Slingshot, Climb, Wind Ride, Hover, Wall Sling, Soar, ...) | 8 |
| Key item spots (Golden Feathers, Golden Gate Key, Food, Witch Burning Ticket, ...) | 10 |
| Trinkets found in the world | 23 |
| Trinket Slots | 59 |
| Workshop Tokens | 27 |
| Spirits | 20 |
| Spirit Nest rewards | 20 |
| Pages | 23 |
| Combat rooms | 15 |
| Ilda's Siblings | 3 |
| Looter Parts, Pearls, Elevator Parts, Flight Time Upgrades, Candied Eggs, Moon Songs, Matchstick, Torpedo, Oil Vial | 21 |
| Looter's shop (trinkets, Flaming Vessel, Oil Vial) | 9 |
| Post-game (Spirit Fragments and more) | 8 |

| Optional | Option | Count |
|---|---|---|
| Levers | `lever_checks` | 103 |
| Currency vessels | `vessel_checks` | 123 |
| Time trials | `time_trial_checks` | 10 |
| Forge upgrades | `forge_checks` | 26 |
| Trinket Point purchases in the shop | `shop_trinket_point_checks` | 0-100 |

## Items
- **Abilities:** Matchstick, Slingshot, Progressive Climb (Climb, then Endless Climb), Wind Ride, Hover, Wall Sling,
  Soar, Water Vessel, Torpedo, Tent Travel.
- **Key items:** Golden Feathers (7 open the Queen's Castle), Elevator Parts, Pearls, Looter Parts, Spirits,
  Spirit Fragments, Flight Time Upgrades, Golden Gate Key, Food, Witch Burning Ticket.
- **Trinkets:** all 32, plus Trinket Upgrades when Forge Checks are on.
- **Upgrades:** Workshop Tokens, Trinket Points, Oil Vials, Flaming Vessel Upgrades, The Queen's Coin, Mysterious
  Markings, Hat.
- **Tents** (with `tent_unlocks: shuffled`) and **Lever** items (with `lever_items`).
- **Filler:** Currency; boons (Big Currency, Full Heal, Vial Refill); traps (Thief, Bruise, Spill).

## Options
| Option | Default | What it does |
|---|---|---|
| `goal` | queen | queen / true_ending / secret_treasure |
| `matchstick` | early | start_with / early (shuffled into your own early locations) / shuffled |
| `tent_travel` | start_with | start_with / shuffled |
| `tent_unlocks` | vanilla | vanilla / all_unlocked / shuffled (each tent is an item) |
| `skip_intro` | on | A new game starts in the Night Garden |
| `lever_checks` | off | First hit on each lever is a check |
| `lever_items` | off | **Hard / long.** Gates only open when the lever's item arrives |
| `vessel_checks` | off | First break of each currency vessel is a check |
| `time_trial_checks` | off | Each time trial is a check |
| `time_trial_time` | 100 | 100-300 % of the normal time trial time |
| `forge_checks` | off | Each forge upgrade is a check; the upgrades come from the multiworld |
| `shop_trinket_point_checks` / `shop_trinket_points_per_check` | 5 / 1 | Trinket Point purchases as checks |
| `shop_prices` (+ `shop_price_minimum` / `maximum`) | vanilla | vanilla / randomized (percent of vanilla) |
| `shop_progression` | affordable | Which shop checks may hold progression: affordable / all / none |
| `currency_multiplier` / `currency_item_amount` | 2 / 500 | Currency gain and size of a Currency item |
| `extra_trinket_points` / `extra_workshop_tokens` / `extra_oil_vials` / `extra_golden_feathers` | 0 | Extra copies in the pool |
| `filler_currency` / `filler_boons` / `filler_traps` | 60 / 25 / 15 | Filler weights |
| `boons` / `traps` | all | Which boons and traps can appear |
| `death_link` (+ `death_link_amnesty`, `death_wish`) | off | Death Link, with deaths before sending / receiving |

## In the game
- **HUD:** the last 5 items sent or received (with icons) and a "Checks: found / total" counter.
- **Map tracker:** markers for every location using the game's own icons; bright = in logic, faded = not yet,
  very faint = checked. Press **F6** with the map open to switch: all -> uncollected -> in logic -> off.
- **Shop:** each entry shows what its check sends (item, player, classification).
- **Quality of life:** the whole map is revealed, the intro and ability tutorial rooms are skipped, the Looter's
  shop, workshop and map station are in every tent from the start, **F3** in a tent takes you to its exit.
- **Logic:** checked room by room against the game's own geometry and play-tested, so each location asks for the
  abilities it really needs.

## Client
`/game_dir`, `/claim`, `/wd_status`, `/resync`, `/goal`, `/why <location>`, `/logic`, `/breaklog on|off` - see the
[setup guide](docs/setup_en.md#client-commands).
