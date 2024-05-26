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

| Flag             | Value    | Description                                                                                                            |
|------------------|----------|------------------------------------------------------------------------------------------------------------------------|
| NODAMAGE         | 0x000001 | Thing doesn't take damage even if it can be shot                                                                       |
| NOCRUSH          | 0x000002 | Thing's corpse will not turn into gibs when crushed; a dropped Thing with this flag will not be destroyed when crushed |
| PUSHABLE         | 0x000004 | Thing can be pushed by other things                                                                                    |
| CANNOTPUSH       | 0x000008 | Thing cannot push other things                                                                                         |
| ANTITELEFRAG     | 0x000010 | Thing kills things that teleport into it instead of the other way around                                               |
| NEVERRESPAWN     | 0x000020 | Thing doesn't respawn on Nightmare or with `-respawn`                                                                  |
| NOTAUTOAIMED     | 0x000040 | Thing is ignored by player autoaim                                                                                     |
| ONLYSLAMSOLID    | 0x000080 | Charging thing doesn't stop when hitting non-solid objects                                                             |
| KEEPCHARGETARGET | 0x000100 | Charging thing doesn't lose its target after collision                                                                 |
| NOINFIGHTING     | 0x000200 | Thing doesn't retaliate against other monsters when damaged (to be implemented)                                        |
| DONTTHRUST       | 0x000400 | Thing doesn't get moved by damage                                                                                      |
| NOPAIN           | 0x000800 | Thing doesn't enter its pain state when damaged; can be used to temporarily prevent damage from interrupting attacks   |
| FLOORHUGGER      | 0x001000 | Missile moves along floor until it hits a solid wall (to be implemented)                                               |
| STEPMISSILE      | 0x002000 | Missile can climb up steps (to be implemented)                                                                         |
| RESETONDEATH     | 0x004000 | Reset thing counters on death                                                                                          |
| NOBFGSPRAY       | 0x008000 | Thing is ignored by spray attacks (such as A_BFGSpray)                                                                 |
| NOHITTHRUST      | 0x010000 | Thing does not cause thrust when it directly damages another thing (to be implemented)                                 |
| UNSTOPPABLE      | 0x020000 | Charging thing does not stop when taking damage                                                                        |
| FLOATBOB         | 0x040000 | Hexen-style float-bobbing Z movement (partially implemented)                                                           |
| DEADFLOAT        | 0x080000 | Thing does not drop when killed (such as Lost Souls)                                                                   |
| GENERIC1         | 0x100000 | Generic flag 1                                                                                                         |
| GENERIC2         | 0x200000 | Generic flag 2                                                                                                         |
| GENERIC3         | 0x400000 | Generic flag 3                                                                                                         |
| GENERIC4         | 0x800000 | Generic flag 4                                                                                                         |

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
      - `hilo (uint)`: 0 = check distance in both directions; 1 = only check to make sure the target isn't higher than the target distance; 2 = only check to make sure the player isn't lower than the target distance.
  - Notes:
      - Name is very likely to change. 

#### In-progress/To-Do
- Fix the disappearing SSG reloading bug.
- Improve handling of FLOATBOB with floating monsters.
- Additional movement codepointers, such as A_Chase2 codepointer that doesn't perform attack checks for generic movement.
- Parameterized version of A_SkullAttack that can be used for ground charging enemies.
- Parameterized version of A_VileAttack.
- Parameterized version of A_BFGSpray.
- Codepointers for altering and checking counters.
- Use state for things.
- Function to capture use presses on things that have use states.
- State flag indicating whether or not a thing can be used.
- Add support for Crispy Doom's `Melee threshold`, `Max target range`, `Min missile chance`, and `Missile chance multiplier` values