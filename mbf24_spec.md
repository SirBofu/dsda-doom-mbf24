# MBF24 Specification v0.1

MBF24 is built off of MBF21 and thus supports the full spec of Boom, MBF, and MBF21.

## Things

#### Thing Counters
- Every actor has four new instanced counters that are not utilized by any existing code.
- These values initialize to 0 when a thing is spawned.
- Unless the `RESETONDEATH` flag is set on the thing, its values will persist if it is killed and resurrected (but not when resurrected via Nightmare or when using `-respawn`, as these are new instances of the actor).
- These values can be used to force monsters to reload after a certain number of attacks, change behavior after a condition has been met a certain number of times, etc. 

#### New Thing Flags
- Add `MBF24 Bits = X` in the Thing definition.
- The format is the same as the existing `Bits` and `MBF21 Bits` field.
- Example: `MBF24 Bits = NODAMAGE+PUSHABLE`.
- The value can also be given as a number (sum of the individual flag values below).
- While these flags can be set via the `A_AddFlags`/`A_RemoveFlags` or queried via the `A_JumpIfFlagsSet` codepointers (see below) in the MBF21 complevel, the actual gameplay logic is gated behind the MBF24 complevel to preserve demo compatibility.

| Flag             | Value     | Description                                                                                                            |
|------------------|-----------|------------------------------------------------------------------------------------------------------------------------|
| NODAMAGE         | 0x0000001 | Thing doesn't take damage even if it can be shot                                                                       |
| NOCRUSH          | 0x0000002 | Thing's corpse will not turn into gibs when crushed; a dropped Thing with this flag will not be destroyed when crushed |
| PUSHABLE         | 0x0000004 | Thing can be pushed by other things                                                                                    |
| CANNOTPUSH       | 0x0000008 | Thing cannot push other things                                                                                         |
| ANTITELEFRAG     | 0x0000010 | Thing kills things that teleport into it instead of the other way around                                               |
| NEVERRESPAWN     | 0x0000020 | Thing doesn't respawn on Nightmare or with `-respawn`                                                                  |
| NOTAUTOAIMED     | 0x0000040 | Thing is ignored by player autoaim                                                                                     |
| ONLYSLAMSOLID    | 0x0000080 | Charging thing doesn't stop when hitting non-solid objects                                                             |
| KEEPCHARGETARGET | 0x0000100 | Charging thing doesn't lose its target after collision                                                                 |
| NOINFIGHTING     | 0x0000200 | Thing doesn't retaliate against other monsters when damaged                                                            |
| DONTTHRUST       | 0x0000400 | Thing doesn't get moved by damage                                                                                      |
| NOPAIN           | 0x0000800 | Thing doesn't enter its pain state when damaged; can be used to temporarily prevent damage from interrupting attacks   |
| FLOORHUGGER      | 0x0001000 | Missile moves along floor until it hits an obstacle                                                                    |
| STEPMISSILE      | 0x0002000 | Missile can climb up ledges                                                                                            |
| RESETONDEATH     | 0x0004000 | Reset thing counters on death                                                                                          |
| NOBFGSPRAY       | 0x0008000 | Thing is ignored by spray attacks (such as A_BFGSpray)                                                                 |
| NOHITTHRUST      | 0x0010000 | Thing does not cause thrust when it directly damages another thing (to be implemented)                                 |
| UNSTOPPABLE      | 0x0020000 | Charging thing does not stop when taking damage                                                                        |
| FLOATBOB         | 0x0040000 | Renderer-only floatbobbing movement (GZDoom style)                                                                     |
| DEADFLOAT        | 0x0080000 | Thing does not drop when killed (such as Lost Souls)                                                                   |
| TOUCHYTARGET     | 0x0100000 | Thing automatically changes its target to any actor that touches it                                                    |
| TARGETUSE        | 0x0200000 | Thing automatically targets any actor that uses it                                                                     |
| GENERIC1         | 0x0400000 | Generic flag 1                                                                                                         |
| GENERIC2         | 0x0800000 | Generic flag 2                                                                                                         |
| GENERIC3         | 0x1000000 | Generic flag 3                                                                                                         |
| GENERIC4         | 0x2000000 | Generic flag 4                                                                                                         |

#### Use frame

- Sets the state for the thing to jump to when it intercepts a use press.
- Things will only intercept use presses when their current frame has the `ALLOWUSE` flag set.
- Use presses require line of sight between the thing pressing use and the thing being used.
- Things cannot use themselves, but may use other things of the same type as well as dead or inanimate things.
- Precedence is given to the first linedef or thing closest to the player when use is pressed.
- Can be used to create thing-based switches, interactive actors, and many other effects.
- For multi-state presses, consider using the `GENERIC1`, `GENERIC2`, ... flags or counters.
- Add `Use frame = X` in the Thing definition.
- `X` represents a frame number.

#### Damage dice

- Used on projectiles or charging enemies like Lost Souls. Can be used to parameterize the damage dealt by projectiles.
- Defaults to 8 if not set.
- Add `Damage dice = X` in the Thing definition.
- Has no effect on complevels less than MBF24.

#### Flat damage

- Used on projectiles or charging enemies like Lost Souls. Adds a flat damage amount to the randomized damage to the attack when it hits.
- Defaults to 0 if not set.
- Add `Flat damage = X` in the Thing definition.
- Has no effect on complevels less than MBF24.

#### Melee threshold

- Taken from Crispy Doom, which allows generalizing the distance in map units at which an enemy will switch from ranged to melee.
- This is ignored if the thing has the `LONGMELEE` MBF21 Bit set.
- Defaults to 0 if not set.
- Add `Melee threshold = X` in the Thing definition.
- Has no effect on complevels less than MBF24.

#### Max target range

- Taken from Crispy Doom, which allows generalizing the maximum distance in map units at which an enemy will start shooting.
- This is ignored if the thing has the `SHORTMRANGE` MBF21 Bit set.
- Defaults to 0 if not set, which means unlimited range.
- Add `Max target range = X` in the Thing definition.
- Has no effect on complevels less than MBF24.

#### Min missile chance

- Taken from Crispy Doom, which allows generalizing the minimum likelihood of a missile attack.
- This is ignored if the thing has the `HIGHERMPROB` MBF21 Bit set.
- Defaults to 0 if not set, which is interpreted as the default value of 200 for consistency with Crispy Doom.
- Add `Min missile chance = X` in the Thing definition.
- Has no effect on complevels less than MBF24.

#### Missile chance multiplier

- Taken from Crispy Doom, which allows generalizing a multiplier (in fixed notation) for missile firing chance.
- This is ignored if the thing has the `RANGEHALF` MBF21 Bit set.
- Defaults to 65536 if not set, which is the base multiplier.
- Add `Missile chance multiplier = X` in the Thing definition.
- Has no effect on complevels less than MBF24.

## Frames

#### Frame Flags

- Because MBF21 only used one frame flag, frame flags have been added to the `MBF21 Bits` field in the Frame definition.
- MBF21's `SKILL5FAST` is preserved, and the flags introduced here are not consumed unless using MBF24 or greater.
- Example: `MBF21 Bits = SKILL5FAST+ALLOWUSE`.
- As with MBF21, the value can also be given as a number (sum of the individual flag values below).

| Name       | Value | Description                                           |
|------------|-------|-------------------------------------------------------|
| SKILL5FAST | 0x001 | Tics halve on nightmare skill (demon) (from MBF21)    |
| ALLOWUSE   | 0x002 | Thing can intercept use presses if it has a use state |

#### Updated DEHACKED Actor Codepointers
- Additional optional "Args" fields have been added for additional params.

##### Actor pointers

- **A_AddFlags(flags, flags2, flags3)**
    - Adds the specified thing flags to the caller. This command has been updated to support MBF24 flags.
    - Args:
        - `flags (int)`: Standard actor flag(s) to add
        - `flags2 (int)`: MBF21 actor flag(s) to add
        - `flags3 (int)`: MBF24 actor flag(s) to add
    - Notes:
        - If the current complevel is less than MBF24, then `flags3` is ignored. 

- **A_RemoveFlags(flags, flags2, flags3)**
    - Removes the specified thing flags from the caller. This command has been updated to support MBF24 flags.
    - Args:
        - `flags (int)`: Standard actor flag(s) to remove
        - `flags2 (int)`: MBF21 actor flag(s) to remove
        - `flags3 (int)`: MBF24 actor flag(s) to remove
    - Notes:
        - If the current complevel is less than MBF24, then `flags3` is ignored.

- **A_JumpIfFlagsSet(state, flags, flags2, flags3)**
    - Jumps to a state if caller has the specified thing flags set. This command has been updated to support MBF24 flags.
    - Args:
        - `state (uint)`: State to jump to.
        - `flags (int)`: Standard actor flag(s) to check
        - `flags2 (int)`: MBF21 actor flag(s) to check
        - `flags3 (int)`: MBF24 actor flag(s) to check
    - Notes:
        - If multiple flags are specified in a field, jump will only occur if all the flags are set (e.g. AND comparison, not OR)
        - If the current complevel is les than MBF24, then `flags3` is ignored.

- **A_MonsterMeleeAttack(damagebase, damagedice, sound, range, flatdamage)**
    - Generic monster melee attack. This command has been updated to support an optional flat damage parameter.
    - Args:
        - `damagebase (uint)`: Base damage of attack; if not set, defaults to 3
        - `damagedice (uint)`: Attack damage random multiplier; if not set, defaults to 8
        - `sound (uint)`: Sound to play if attack hits
        - `range (fixed)`: Attack range; if not set, defaults to calling actor's melee range property
        - `flatdamage (uint)`: Flat damage to add to attack; if not set, defaults to 0 
    - Notes:
        - Damage formula is: `damage = (damagebase * random(1, damagedice) + flatdamage)`
        - If the current complevel is less than MBF24, then `flatdamage` is ignored.

- **A_MonsterBulletAttack(hspread, vspread, numbullets, damagebase, damagedice, flatdamage)**
    - Generic monster bullet attack. This command has been updated to support an optional flat damage parameter.
    - Args:
        - `hspread (fixed)`: Horizontal spread (degrees, in fixed point)
        - `vspread (fixed)`: Vertical spread (degrees, in fixed point)
        - `numbullets (uint)`: Number of bullets to fire; if not set, defaults to 1
        - `damagebase (uint)`: Base damage of attack; if not set, defaults to 3
        - `damagedice (uint)`: Attack damage random multiplier; if not set, defaults to 5
        - `flatdamage (uint)`: Flat damage to add to attack; if not set, defaults to 0 
    - Notes:
        - Damage formula is: `damage = (damagebase * random(1, damagedice) + flatdamage)`
        - Damage arg defaults are identical to Doom's monster bullet attack damage values.
        - If the current complevel is less than MBF24, then `flatdamage` is ignored.

##### Weapon pointers

- **A_WeaponBulletAttack(hspread, vspread, numbullets, damagebase, damagedice, flatdamage)**
    - Generic weapon bullet attack. This command has been updated to support an optional flat damage parameter.
    - Args:
        - `hspread (fixed)`: Horizontal spread (degrees, in fixed point)
        - `vspread (fixed)`: Vertical spread (degrees, in fixed point)
        - `numbullets (uint)`: Number of bullets to fire; if not set, defaults to 1
        - `damagebase (uint)`: Base damage of attack; if not set, defaults to 5
        - `damagedice (uint)`: Attack damage random multiplier; if not set, defaults to 3
        - `flatdamage (uint)`: Flat damage to add to attack; if not set, defaults to 0
    - Notes:
        - Unlike native Doom attack codepointers, this function will not consume ammo, trigger the Flash state, or play a sound.
        - Damage formula is: `damage = (damagebase * random(1, damagedice) + flatdamage)`
        - Damage arg defaults are identical to Doom's weapon bullet attack damage values.
            - Note that these defaults are intentionally different for weapons vs monsters (5d3 vs 3d5) -- yup, Doom did it this way. :P
        - If the current complevel is less than MBF24, then `flatdamage` is ignored.

- **A_WeaponMeleeAttack(damagebase, damagedice, zerkfactor, sound, range, flatdamage, state)**
- Generic weapon melee attack. This command has been updated to support an optional flat damage parameter, a state to jump to, and to disable turning the player on hit.
- Args:
    - `damagebase (uint)`: Base damage of attack; if not set, defaults to 2
    - `damagedice (uint)`: Attack damage random multiplier; if not set, defaults to 10
    - `zerkfactor (fixed)`: Berserk damage multiplier; if not set, defaults to 1.0
    - `sound (uint)`: Sound index to play if attack hits
    - `range (fixed)`: Attack range; if not set, defaults to player mobj's melee range property
    - `flatdamage (uint)`: Flat damage to add to attack; if not set, defaults to 0
    - `state (uint)`: State to change the weapon to if attack hits
    - `turnonhit (uint)`: If nonzero, then the player will turn toward the target that was hit on a hit; if not set, defaults to 1
- Notes:
    - Damage formula is: `damage = (damagebase * random(1, damagedice) + flatdamage)`; this is then multiplied by `zerkfactor` if the player has Berserk.
    - If the current complevel is less than MBF24, then `flatdamage`. `state`, and `turnonhit` are ignored. 

#### New DEHACKED Actor Codepointers

##### Actor pointers

- **A_JumpIfTargetHigher(state, distance, hilo)**
  - Jumps to a state if caller's target's z position is closer than the specified vertical distance.
  - Args:
      - `state (uint)`: State to jump to.
      - `distance (fixed)`: Vertical distance threshold, in map units.
      - `hilo (uint)`: 0 = check distance in both directions; 1 = only check to make sure the target isn't higher than the target distance; 2 = only check to make sure the target isn't lower than the target distance.
  - Notes:
      - Name is very likely to change.

- **A_JumpIfTracerHigher(state, distance, hilo)**
    - Jumps to a state if caller's tracer target's z position is closer than the specified vertical distance.
    - Args:
        - `state (uint)`: State to jump to.
        - `distance (fixed)`: Vertical distance threshold, in map units.
        - `hilo (uint)`: 0 = check distance in both directions; 1 = only check to make sure the tracer target isn't higher than the target distance; 2 = only check to make sure the tracer target isn't lower than the target distance.
    - Notes:
        - Name is very likely to change.

- **A_SetCounter(counternum, value)**
  - Sets the caller's specified counter to a specific value.
  - Args:
    - `counternum (int)`: Counter to alter (1-4). If any other value, sets all four counters.
    - `value (int)`: Value to set counter to.
  - Notes: 
    - Note that values below 0 or above 100 will result in the counter being adjusted to the minimum of 0 or the maximum of 100 respectively.

- **A_AddCounter(counternum, value)**
    - Adds the specified value to the caller's specified counter.
    - Args:
        - `counternum (int)`: Counter to alter (1-4). If any other value, adds to all four counters.
        - `value (int)`: Value to set counter to.
    - Notes:
        - Negative values are accepted.
        - Note that values below 0 or above 100 will result in the counter being adjusted to the minimum of 0 or the maximum of 100 respectively.

- **A_JumpIfCounterEquals(state, counternum, value)**
    - Jumps to a state if caller's specified counter is equal to the specified value.
    - Args:
        - `state (uint)`: State to jump to.
        - `counternum (int)`: Counter to compare.
        - `value (int)`: Value for the counter to equal in order to jump.
 
- **A_JumpIfCounterGreater(state, counternum, value)**
    - Jumps to a state if caller's specified counter is greater than the specified value.
    - Args:
        - `state (uint)`: State to jump to.
        - `counternum (int)`: Counter to compare.
        - `value (int)`: Value for the counter to be greater than in order to jump.
                
- **A_LaunchTarget(thrust)**
    - Launches caller's target upward vertically.
    - Args:
        - `thrust (int)`: Amount of vertical momentum to apply. Defaults to 1000 if not set, identical to an Archvile jump.

- **A_SetHealth(sethealth)**
    - Sets caller's health to the specified value. Has no effect if currently health is 0 or lower.
    - Args:
        - `sethealth (int)`: Amount to set health to.

- **A_RegainHealth(healamount, maxheal)**
    - Heals caller by a specified amount, up to a specified maximum.
    - Args:
        - `healamount (int)`: Amount of health to regain.
        - `maxheal (int)`: Maximum amount of health to heal up to. If 0, uses the thing's spawnhealth instead.

- **A_ChaseNoAttack(lowerreactiontime, lowerstepcount)**
  - Makes the caller pursue their target similar to A_Chase, but does not perform checks for melee or ranged attacks.
  - Args:
    - `lowerreactiontime (int)`: If nonzero, movement counts toward the caller's reaction time.
    - `lowerstepcount (int)`: If nonzero, movement counts toward the caller's step count between attacks.

- **A_ClearTarget**
  - Removes the caller's current target. Use with caution.
  - No args.

- **A_JumpIfTargetFlagsSet(state, flags, flags2, flags3)**
    - Jumps to a state if caller's target has the specified thing flags set.
    - Args:
        - `state (uint)`: State to jump to.
        - `flags (int)`: Standard actor flag(s) to check
        - `flags2 (int)`: MBF21 actor flag(s) to check
        - `flags3 (int)`: MBF24 actor flag(s) to check
    - Notes:
        - If multiple flags are specified in a field, jump will only occur if all the flags are set (e.g. AND comparison, not OR)
        - If the caller has no target, then has no effect.

- **A_JumpIfTracerFlagsSet(state, flags, flags2, flags3)**
    - Jumps to a state if caller's tracer has the specified thing flags set.
    - Args:
        - `state (uint)`: State to jump to.
        - `flags (int)`: Standard actor flag(s) to check
        - `flags2 (int)`: MBF21 actor flag(s) to check
        - `flags3 (int)`: MBF24 actor flag(s) to check
    - Notes:
        - If multiple flags are specified in a field, jump will only occur if all the flags are set (e.g. AND comparison, not OR)
        - If the caller has no tracer, then has no effect.

- **A_JumpIfHasTarget(state)**
  - Jumps to a state if caller has a target.
  - Args:
    - `state (uint)`: State to jump to.

- **A_JumpIfHasTracer(state)**
    - Jumps to a state if caller has a tracer.
    - Args:
        - `state (uint)`: State to jump to.

- **A_JumpIfBlocked(state, angle, ofs_x, ofs_y)**
  - Jumps to a state if caller's position or relative position is blocked.
  - Args:
    - `state (int)`: State to jump to.
    - `angle (fixed)`: Angle (degrees), relative to calling actor's angle
    - `x_ofs (fixed)`: X (forward/back) position offset
    - `y_ofs (fixed)`: Y (left/right) position offset
  - Notes:
    - Uses existing position checking codepointers and will not check for a clear path.

#### New DEHACKED Weapon Codepointers

##### Weapon pointers

- **A_WeaponRemove(removeammo)**
  - Removes the current weapon from the player's inventory and switches to a different weapon.
  - Args:
    - `removeammo (int)`: If nonzero, also removes all ammunition of the weapon's ammo type.
  - Notes:
    - Does nothing if the calling weapon is the pistol or fist (or DEHACKED replacements). This may change in the future.
   
## Miscellaneous

#### New comp flags

- comp_nohorizontalautoaim:
  - Disables horizontal autoaim for player projectile weapons (default)
  - Note that projectiles that would normally trigger horizontal autoaim will still be aimed vertically, allowing for leading shots.

- comp_ssgautoswitch (to be removed)
  - Fixes an MBF21 bug where the super shotgun could potentially get stuck in the lowered state after firing its last shot (default)
    
#### In-progress/To-Do
- Remove the SSG autoswitch bugfix, as this is being merged into base MBF21 by both Woof! and DSDA-Doom. 
- Additional movement codepointers, such as A_Wander codepointer for aimless monster idle movement.
- Codepointer to jump to a specified frame if a thing is stuck.
- Parameterized version of A_SkullAttack that can be used for ground charging enemies.
- Parameterized version of A_VileAttack.
- Parameterized version of A_BFGSpray.
- A_SetTracerState and A_SetTargetState.
- Add support for Crispy Doom's `Melee threshold`, `Max target range`, `Min missile chance`, and `Missile chance multiplier` values.

#### Potential Additions
- Secondary attack support for weapons, with secondary optional ammo types.
- Support for DEHACKED-defined additional weapon and ammo types as well as pickups.
- Teleporter multi-destination support without map format requirements.
- Allow DEHACKED definition of what weapons and ammunition the player starts with.
