# MBF21 Specification v0.1

MBF24 is built off of MBF21 and thus supports the full spec of Boom, MBF, and MBF21.

## Things

#### New Thing Flags
- Add `MBF24 Bits = X` in the Thing definition.
- The format is the same as the existing `Bits` and `MBF21 Bits` field.
- Example: `MBF24 Bits = NODAMAGE+PUSHABLE`.
- The value can also be given as a number (sum of the individual flag values below).
- While these flags can be set via the `A_AddFlags`/`A_RemoveFlags` or queried via the `A_JumpIfFlagsSet` codepointers (see below) in the MBF21 complevel, the actual gameplay logic is gated behind the MBF24 complevel to preserve demo compatibility.

| Flag         | Value   | Description                                                                                                            |
|--------------|---------|------------------------------------------------------------------------------------------------------------------------|
| NODAMAGE     | 0x00001 | Thing doesn't take damage even if it can be shot                                                                       |
| NOCRUSH      | 0x00002 | Thing's corpse will not turn into gibs when crushed; a dropped Thing with this flag will not be destroyed when crushed |
| PUSHABLE     | 0x00004 | Thing can be pushed by other things                                                                                    |
| CANNOTPUSH   | 0x00008 | Thing cannot push other things                                                                                         |
| ANTITELEFRAG | 0x00010 | Thing kills things that teleport into it instead of the other way around                                               |

## Frames

#### Updated DEHACKED Codepointers
- Additional optional "Args" fields have been added for additional params.

- **A_AddFlags(flags, flags2, flags3)**
    - Adds the specified thing flags to the caller.
    - Args:
        - `flags (int)`: Standard actor flag(s) to add
        - `flags2 (int)`: MBF21 actor flag(s) to add
        - `flags3 (int)`: MBF24 actor flag(s) to add

- **A_RemoveFlags(flags, flags2, flags3)**
    - Removes the specified thing flags from the caller.
    - Args:
        - `flags (int)`: Standard actor flag(s) to remove
        - `flags2 (int)`: MBF21 actor flag(s) to remove
        - `flags3 (int)`: MBF24 actor flag(s) to remove

- **A_JumpIfFlagsSet(state, flags, flags2, flags3)**
    - Jumps to a state if caller has the specified thing flags set.
    - Args:
        - `state (uint)`: State to jump to.
        - `flags (int)`: Standard actor flag(s) to check
        - `flags2 (int)`: MBF21 actor flag(s) to check
        - `flags3 (int)`: MBF24 actor flag(s) to check
    - Notes:
        - If multiple flags are specified in a field, jump will only occur if all the flags are set (e.g. AND comparison, not OR)

#### In-progress
- Fix the disappearing SSG reloading bug.
- Additional Thing Flags.
- Additional movement codepointers, such as A_Chase2 codepointer that doesn't perform attack checks for generic movement.
- Parameterized version of A_SkullAttack that can be used for ground charging enemies.
- Paramterized version of A_VileAttack.