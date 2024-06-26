# MBF21 Specification v0.1

MBF24 is built off of MBF21 and thus supports the full spec of Boom, MBF, and MBF21.

## Things

#### Thing Counters (In Progress)
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
| FLOORHUGGER      | 0x0001000 | Missile moves along floor until it hits a solid wall (to be implemented)                                               |
| STEPMISSILE      | 0x0002000 | Missile can climb up steps (to be implemented)                                                                         |
| RESETONDEATH     | 0x0004000 | Reset thing counters on death                                                                                          |
| NOBFGSPRAY       | 0x0008000 | Thing is ignored by spray attacks (such as A_BFGSpray)                                                                 |
| NOHITTHRUST      | 0x0010000 | Thing does not cause thrust when it directly damages another thing (to be implemented)                                 |
| UNSTOPPABLE      | 0x0020000 | Charging thing does not stop when taking damage                                                                        |
| FLOATBOB         | 0x0040000 | Hexen-style float-bobbing Z movement (partially implemented)                                                           |
| DEADFLOAT        | 0x0080000 | Thing does not drop when killed (such as Lost Souls)                                                                   |
| TOUCHYTARGET     | 0x0100000 | Thing automatically changes its target to any actor that touches it                                                    |
| GENERIC1         | 0x0200000 | Generic flag 1                                                                                                         |
| GENERIC2         | 0x0400000 | Generic flag 2                                                                                                         |
| GENERIC3         | 0x0800000 | Generic flag 3                                                                                                         |
| GENERIC4         | 0x1000000 | Generic flag 4                                                                                                         |

## Frames

#### Updated DEHACKED Actor Codepointers
- Additional optional "Args" fields have been added for additional params.

##### Actor pointers

- **A_AddFlags(flags, flags2, flags3)**
    - Adds the specified thing flags to the caller.
    - Args:
        - `flags (int)`: Standard actor flag(s) to add
        - `flags2 (int)`: MBF21 actor flag(s) to add
        - `flags3 (int)`: MBF24 actor flag(s) to add
    - Notes:
        - If the current complevel is less than MBF24, then `flags3` is ignored. 

- **A_RemoveFlags(flags, flags2, flags3)**
    - Removes the specified thing flags from the caller.
    - Args:
        - `flags (int)`: Standard actor flag(s) to remove
        - `flags2 (int)`: MBF21 actor flag(s) to remove
        - `flags3 (int)`: MBF24 actor flag(s) to remove
    - Notes:
        - If the current complevel is less than MBF24, then `flags3` is ignored.

- **A_JumpIfFlagsSet(state, flags, flags2, flags3)**
    - Jumps to a state if caller has the specified thing flags set.
    - Args:
        - `state (uint)`: State to jump to.
        - `flags (int)`: Standard actor flag(s) to check
        - `flags2 (int)`: MBF21 actor flag(s) to check
        - `flags3 (int)`: MBF24 actor flag(s) to check
    - Notes:
        - If multiple flags are specified in a field, jump will only occur if all the flags are set (e.g. AND comparison, not OR)
        - If the current complevel is les than MBF24, then `flags3` is ignored.

#### New DEHACKED Actor Codepointers

#### Actor pointers

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

#### New DEHACKED Weapon Codepointers

#### Weapon pointers

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

- comp_ssgautoswitch
  - Fixes an MBF21 bug where the super shotgun could potentially get stuck in the lowered state after firing its last shot (default)
    
#### In-progress/To-Do
- Improve handling of FLOATBOB with floating monsters.
- Additional movement codepointers, such as A_Wander codepointer for aimless monster idle movement.
- Codepointer to jump to a specified frame if a thing is stuck.
- Parameterized version of A_SkullAttack that can be used for ground charging enemies.
- Parameterized version of A_VileAttack.
- Parameterized version of A_BFGSpray.
- Add support for Crispy Doom's `Melee threshold`, `Max target range`, `Min missile chance`, and `Missile chance multiplier` values.

#### Potential Additions
- Secondary attack support for weapons, with secondary optional ammo types.
- Support for DEHACKED-defined additional weapon and ammo types as well as pickups.
- Use state for things.
- Function to capture use presses on things that have use states.
- State flag indicating whether or not a thing can be used.
- Teleporter multi-destination support without map format requirements.
- Thing tags.
- Allow DEHACKED definition of what weapons and ammunition the player starts with.
