# Release notes

## v0.2.0-alpha
APWorld 0.2.0 + game mod 0.1.9. **Update both** (`well_dweller.apworld` and `WellDwellerAP.dll`) and start a new save
for a new seed. YAMLs from earlier versions still work; there is one new option (`time_trial_time`).

### Logic
- Every area was checked room by room against the game's own geometry (spikes, gaps, bubbles) and play-tested with
  limited ability sets, so locations now ask for the abilities they really need. Over 150 locations changed.
- Desiccated Castle: most of the castle needs Soar or the Slingshot; past the AC_09 spike pit you need Soar or
  Climb with the Slingshot. AC_33 (Hover Egg) can be reached straight from the Night Garden.
- Midnight Drench: Willow's side (AL_01-AL_08) is only reached with the Drains elevator (3 Elevator Parts).
- Queen's Castle needs Climb + Wall Sling + Hover on top of the 7 Golden Feathers.
- The Depths: everything past the Torpedo's own pickup needs the Torpedo.
- The Drains: the time trial area, Wind Ride rooms and AP_28 have their own requirements.
- Dollmaker's House / Burial Vault: the stretch from AU_14 to AT_41 needs Climb + Slingshot + Hover.
- New routes the logic knows about: Hunter's Cabin -> AN_32, Midnight Drench -> AC_07/AC_08, Night Garden -> AC_33.

### Goals
- Defeating the Queen now completes the goal automatically (`/goal` stays as a fallback).

### Options
- New `time_trial_time` (100-300 %): more time for the time trials.
- `lever_items` is now described as a hard / long setting. Queen's Castle lever gates are part of its logic, the
  three levers that free Ilda's siblings always work as normal levers, and levers whose gates the logic doesn't
  use are no longer progression items.

### Game mod (0.1.9)
- Forge: each trinket's forge price goes up with every upgrade bought for it, and a trinket at its highest level
  can't be forged again.
- A Matchstick picked up from its vanilla spot (when it is shuffled) is taken away straight away instead of at the
  next save point.
- Pulling a lever without its item (lever items) puts you back once instead of dropping you onto the lever again
  and again.
- The levers that free Ilda's siblings work normally with lever items on.
- Time trial time scaling for the new option.
- **F8** records your movement to `archipelago\move_N.csv` for logic reports.

### Known issues
- The `true_ending` goal is not detected automatically yet: use `/goal` in the client.
- Shop checks come into logic later than you can actually buy them (by design, so the shop doesn't fill the
  first spheres).
