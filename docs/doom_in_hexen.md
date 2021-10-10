## Doom in Hexen

This page tracks support for the "Doom in Hexen" map format and related features, as seen in ZDoom.

### Current Status

Current work is isolated to the initial pass over the level format itself - line and sector specials, necessary changes to internal data structures, etc. Lots of refactoring needs to be done in the engine itself in order to treat different formats correctly without breaking compatibility.

### Features

| Name         | Supported |
|--------------|-----------|
| Levels       | Yes       |
| Poly Objects | No        |
| ACS          | No        |
| MAPINFO      | No        |
| SNDINFO      | No        |
| SNDSEQ       | No        |
| ANIMDEFS     | No        |

### Things

- To Do

### Line Specials

| Value | Name                            | Supported |
| ----- | ------------------------------- | --------- |
| 1     | Polyobj_StartLine               | No        |
| 2     | Polyobj_RotateLeft              | No        |
| 3     | Polyobj_RotateRight             | No        |
| 4     | Polyobj_Move                    | No        |
| 5     | Polyobj_ExplicitLine            | No        |
| 6     | Polyobj_MoveTimes8              | No        |
| 7     | Polyobj_DoorSwing               | No        |
| 8     | Polyobj_DoorSlide               | No        |
| 9     | Line_Horizon                    | No        |
| 10    | Door_Close                      | No        |
| 11    | Door_Open                       | No        |
| 12    | Door_Raise                      | No        |
| 13    | Door_LockedRaise                | No        |
| 14    | Door_Animated                   | No        |
| 15    | Autosave                        | No        |
| 16    | Transfer_WallLight              | No        |
| 17    | Thing_Raise                     | No        |
| 18    | StartConversation               | No        |
| 19    | Thing_Stop                      | No        |
| 20    | Floor_LowerByValue              | No        |
| 21    | Floor_LowerToLowest             | No        |
| 22    | Floor_LowerToNearest            | No        |
| 23    | Floor_RaiseByValue              | No        |
| 24    | Floor_RaiseToHighest            | No        |
| 25    | Floor_RaiseToNearest            | No        |
| 26    | Stairs_BuildDown                | No        |
| 27    | Stairs_BuildUp                  | No        |
| 28    | Floor_RaiseAndCrush             | No        |
| 29    | Pillar_Build                    | No        |
| 30    | Pillar_Open                     | No        |
| 31    | Stairs_BuildDownSync            | No        |
| 32    | Stairs_BuildUpSync              | No        |
| 33    | ForceField                      | No        |
| 34    | ClearForceField                 | No        |
| 35    | Floor_RaiseByValueTimes8        | No        |
| 36    | Floor_LowerByValueTimes8        | No        |
| 37    | Floor_MoveToValue               | No        |
| 38    | Ceiling_Waggle                  | No        |
| 39    | Teleport_ZombieChanger          | No        |
| 40    | Ceiling_LowerByValue            | No        |
| 41    | Ceiling_RaiseByValue            | No        |
| 42    | Ceiling_CrushAndRaise           | No        |
| 43    | Ceiling_LowerAndCrush           | No        |
| 44    | Ceiling_CrushStop               | No        |
| 45    | Ceiling_CrushRaiseAndStay       | No        |
| 46    | Floor_CrushStop                 | No        |
| 47    | Ceiling_MoveToValue             | No        |
| 48    | Sector_Attach3dMidtex           | No        |
| 49    | GlassBreak                      | No        |
| 50    | ExtraFloor_LightOnly            | No        |
| 51    | Sector_SetLink                  | No        |
| 52    | Scroll_Wall                     | No        |
| 53    | Line_SetTextureOffset           | No        |
| 54    | Sector_ChangeFlags              | No        |
| 55    | Line_SetBlocking                | No        |
| 56    | Line_SetTextureScale            | No        |
| 57    | Sector_SetPortal                | No        |
| 58    | Sector_CopyScroller             | Yes       |
| 59    | Polyobj_OR_MoveToSpot           | No        |
| 60    | Plat_PerpetualRaise             | No        |
| 61    | Plat_Stop                       | No        |
| 62    | Plat_DownWaitUpStay             | No        |
| 63    | Plat_DownByValue                | No        |
| 64    | Plat_UpWaitDownStay             | No        |
| 65    | Plat_UpByValue                  | No        |
| 66    | Floor_LowerInstant              | No        |
| 67    | Floor_RaiseInstant              | No        |
| 68    | Floor_MoveToValueTimes8         | No        |
| 69    | Ceiling_MoveToValueTimes8       | No        |
| 70    | Teleport                        | No        |
| 71    | Teleport_NoFog                  | No        |
| 72    | ThrustThing                     | No        |
| 73    | DamageThing                     | No        |
| 74    | Teleport_NewMap                 | No        |
| 75    | Teleport_EndGame                | No        |
| 76    | TeleportOther                   | No        |
| 77    | TeleportGroup                   | No        |
| 78    | TeleportInSector                | No        |
| 79    | Thing_SetConversation           | No        |
| 80    | ACS_Execute                     | No        |
| 81    | ACS_Suspend                     | No        |
| 82    | ACS_Terminate                   | No        |
| 83    | ACS_LockedExecute               | No        |
| 84    | ACS_ExecuteWithResult           | No        |
| 85    | ACS_LockedExecuteDoor           | No        |
| 86    | Polyobj_MoveToSpot              | No        |
| 87    | Polyobj_Stop                    | No        |
| 88    | Polyobj_MoveTo                  | No        |
| 89    | Polyobj_OR_MoveTo               | No        |
| 90    | Polyobj_OR_RotateLeft           | No        |
| 91    | Polyobj_OR_RotateRight          | No        |
| 92    | Polyobj_OR_Move                 | No        |
| 93    | Polyobj_OR_MoveTimes8           | No        |
| 94    | Pillar_BuildAndCrush            | No        |
| 95    | FloorAndCeiling_LowerByValue    | No        |
| 96    | FloorAndCeiling_RaiseByValue    | No        |
| 97    | Ceiling_LowerAndCrushDist       | No        |
| 98    | Sector_SetTranslucent           | No        |
| 99    | Floor_RaiseAndCrushDoom         | No        |
| 100   | Scroll_Texture_Left             | Yes*      |
| 101   | Scroll_Texture_Right            | Yes*      |
| 102   | Scroll_Texture_Up               | Yes*      |
| 103   | Scroll_Texture_Down             | Yes*      |
| 104   | Ceiling_CrushAndRaiseSilentDist | No        |
| 105   | Door_WaitRaise                  | No        |
| 106   | Door_WaitClose                  | No        |
| 107   | Line_SetPortalTarget            | No        |
| -     | -                               | -         |
| 109   | Light_ForceLightning            | No        |
| 110   | Light_RaiseByValue              | No        |
| 111   | Light_LowerByValue              | No        |
| 112   | Light_ChangeToValue             | No        |
| 113   | Light_Fade                      | No        |
| 114   | Light_Glow                      | No        |
| 115   | Light_Flicker                   | No        |
| 116   | Light_Strobe                    | No        |
| 117   | Light_Stop                      | No        |
| 118   | Plane_Copy                      | No        |
| 119   | Thing_Damage                    | No        |
| 120   | Radius_Quake                    | No        |
| 121   | Line_SetIdentification          | No        |
| -     | -                               | -         |
| 125   | Thing_Move                      | No        |
| -     | -                               | -         |
| 127   | Thing_SetSpecial                | No        |
| 128   | ThrustThingZ                    | No        |
| 129   | UsePuzzleItem                   | No        |
| 130   | Thing_Activate                  | No        |
| 131   | Thing_Deactivate                | No        |
| 132   | Thing_Remove                    | No        |
| 133   | Thing_Destroy                   | No        |
| 134   | Thing_Projectile                | No        |
| 135   | Thing_Spawn                     | No        |
| 136   | Thing_ProjectileGravity         | No        |
| 137   | Thing_SpawnNoFog                | No        |
| 138   | Floor_Waggle                    | No        |
| 139   | Thing_SpawnFacing               | No        |
| 140   | Sector_ChangeSound              | No        |
| -     | -                               | -         |
| 154   | Teleport_NoStop                 | No        |
| -     | -                               | -         |
| 157   | SetGlobalFogParameter           | No        |
| 158   | FS_Execute                      | No        |
| 159   | Sector_SetPlaneReflection       | No        |
| 160   | Sector_Set3DFloor               | No        |
| 161   | Sector_SetContents              | No        |
| -     | -                               | -         |
| 168   | Ceiling_CrushAndRaiseDist       | No        |
| 169   | Generic_Crusher2                | No        |
| 170   | Sector_SetCeilingScale2         | No        |
| 171   | Sector_SetFloorScale2           | No        |
| 172   | Plat_UpNearestWaitDownStay      | No        |
| 173   | NoiseAlert                      | No        |
| 174   | SendToCommunicator              | No        |
| 175   | Thing_ProjectileIntercept       | No        |
| 176   | Thing_ChangeTID                 | No        |
| 177   | Thing_Hate                      | No        |
| 178   | Thing_ProjectileAimed           | No        |
| 179   | ChangeSkill                     | No        |
| 180   | Thing_SetTranslation            | No        |
| 181   | Plane_Align                     | No        |
| 182   | Line_Mirror                     | No        |
| 183   | Line_AlignCeiling               | No        |
| 184   | Line_AlignFloor                 | No        |
| 185   | Sector_SetRotation              | No        |
| 186   | Sector_SetCeilingPanning        | No        |
| 187   | Sector_SetFloorPanning          | No        |
| 188   | Sector_SetCeilingScale          | No        |
| 189   | Sector_SetFloorScale            | No        |
| 190   | Static_Init                     | Yes*      |
| 191   | SetPlayerProperty               | No        |
| 192   | Ceiling_LowerToHighestFloor     | No        |
| 193   | Ceiling_LowerInstant            | No        |
| 194   | Ceiling_RaiseInstant            | No        |
| 195   | Ceiling_CrushRaiseAndStayA      | No        |
| 196   | Ceiling_CrushAndRaiseA          | No        |
| 197   | Ceiling_CrushAndRaiseSilentA    | No        |
| 198   | Ceiling_RaiseByValueTimes8      | No        |
| 199   | Ceiling_LowerByValueTimes8      | No        |
| 200   | Generic_Floor                   | No        |
| 201   | Generic_Ceiling                 | No        |
| 202   | Generic_Door                    | No        |
| 203   | Generic_Lift                    | No        |
| 204   | Generic_Stairs                  | No        |
| 205   | Generic_Crusher                 | No        |
| 206   | Plat_DownWaitUpStayLip          | No        |
| 207   | Plat_PerpetualRaiseLip          | No        |
| 208   | TranslucentLine                 | No        |
| 209   | Transfer_Heights                | Yes       |
| 210   | Transfer_FloorLight             | Yes       |
| 211   | Transfer_CeilingLight           | Yes       |
| 212   | Sector_SetColor                 | No        |
| 213   | Sector_SetFade                  | No        |
| 214   | Sector_SetDamage                | No        |
| 215   | Teleport_Line                   | No        |
| 216   | Sector_SetGravity               | No        |
| 217   | Stairs_BuildUpDoom              | No        |
| 218   | Sector_SetWind                  | Yes       |
| 219   | Sector_SetFriction              | Yes       |
| 220   | Sector_SetCurrent               | Yes       |
| 221   | Scroll_Texture_Both             | Yes       |
| 222   | Scroll_Texture_Model            | Yes       |
| 223   | Scroll_Floor                    | Yes       |
| 224   | Scroll_Ceiling                  | Yes       |
| 225   | Scroll_Texture_Offsets          | Yes*      |
| 226   | ACS_ExecuteAlways               | No        |
| 227   | PointPush_SetForce              | Yes       |
| 228   | Plat_RaiseAndStayTx0            | No        |
| 229   | Thing_SetGoal                   | No        |
| 230   | Plat_UpByValueStayTx            | No        |
| 231   | Plat_ToggleCeiling              | No        |
| 232   | Light_StrobeDoom                | No        |
| 233   | Light_MinNeighbor               | No        |
| 234   | Light_MaxNeighbor               | No        |
| 235   | Floor_TransferTrigger           | No        |
| 236   | Floor_TransferNumeric           | No        |
| 237   | ChangeCamera                    | No        |
| 238   | Floor_RaiseToLowestCeiling      | No        |
| 239   | Floor_RaiseByValueTxTy          | No        |
| 240   | Floor_RaiseByTexture            | No        |
| 241   | Floor_LowerToLowestTxTy         | No        |
| 242   | Floor_LowerToHighest            | No        |
| 243   | Exit_Normal                     | No        |
| 244   | Exit_Secret                     | No        |
| 245   | Elevator_RaiseToNearest         | No        |
| 246   | Elevator_MoveToFloor            | No        |
| 247   | Elevator_LowerToNearest         | No        |
| 248   | HealThing                       | No        |
| 249   | Door_CloseWaitOpen              | No        |
| 250   | Floor_Donut                     | No        |
| 251   | FloorAndCeiling_LowerRaise      | No        |
| 252   | Ceiling_RaiseToNearest          | No        |
| 253   | Ceiling_LowerToLowest           | No        |
| 254   | Ceiling_LowerToFloor            | No        |
| 255   | Ceiling_CrushRaiseAndStaySilA   | No        |
| 256   | Floor_LowerToHighestEE          | No        |
| 257   | Floor_RaiseToLowest             | No        |
| 258   | Floor_LowerToLowestCeiling      | No        |
| 259   | Floor_RaiseToCeiling            | No        |
| 260   | Floor_ToCeilingInstant          | No        |
| 261   | Floor_LowerByTexture            | No        |
| 262   | Ceiling_RaiseToHighest          | No        |
| 263   | Ceiling_ToHighestInstant        | No        |
| 264   | Ceiling_LowerToNearest          | No        |
| 265   | Ceiling_RaiseToLowest           | No        |
| 266   | Ceiling_RaiseToHighestFloor     | No        |
| 267   | Ceiling_ToFloorInstant          | No        |
| 268   | Ceiling_RaiseByTexture          | No        |
| 269   | Ceiling_LowerByTexture          | No        |
| 270   | Stairs_BuildDownDoom            | No        |
| 271   | Stairs_BuildUpDoomSync          | No        |
| 272   | Stairs_BuildDownDoomSync        | No        |

#### Notes

- Wall scrollers cannot distinguish between top, bottom, and mid textures.
- The static init supports damage, gravity, and skies only.

### Sector Specials

| Value   | Name                     | Supported |
|---------|--------------------------|-----------|
| *       | Generalized Effects      | Yes       |
| 1       | Light_Phased             | Yes       |
| 2-4     | LightSequence*           | ?         |
| -       | -                        | -         |
| 26-27   | Stairs_Special*          | ?         |
| -       | -                        | -         |
| 40-51   | Wind*                    | Yes       |
| -       | -                        | -         |
| 65      | dLight_Flicker           | Yes       |
| 66      | dLight_StrobeFast        | Yes       |
| 67      | dLight_StrobeSlow        | Yes       |
| 68      | dLight_Strobe_Hurt       | Yes       |
| 69      | dDamage_Hellslime        | Yes       |
| -       | -                        | -         |
| 71      | dDamage_Nukage           | Yes       |
| 72      | dLight_Glow              | Yes       |
| -       | -                        | -         |
| 74      | dSector_DoorCloseIn30    | Yes       |
| 75      | dDamage_End              | Yes       |
| 76      | dLight_StrobeSlowSync    | Yes       |
| 77      | dLight_StrobeFastSync    | Yes       |
| 78      | dSector_DoorRaiseIn5Mins | Yes       |
| 79      | dFriction_Low            | Yes       |
| 80      | dDamage_SuperHellslime   | Yes       |
| 81      | dLight_FireFlicker       | Yes       |
| 82      | dDamage_LavaWimpy        | Yes       |
| 83      | dDamage_LavaHefty        | Yes       |
| 84      | dScroll_EastLavaDamage   | Yes       |
| 85      | hDamage_Sludge           | Yes       |
| -       | -                        | -         |
| 87      | Sector_Outside           | No        |
| -       | -                        | -         |
| 104     | sLight_Strobe_Hurt       | Yes       |
| 105     | sDamage_Hellslime        | Yes       |
| -       | -                        | -         |
| 115     | Damage_InstantDeath      | Yes       |
| 116     | sDamage_SuperHellslime   | Yes       |
| -       | -                        | -         |
| 118     | Scroll_StrifeCurrent     | No        |
| -       | -                        | -         |
| 195     | Sector_Hidden            | Yes       |
| 196     | Sector_Heal              | Yes       |
| 197     | Light_OutdoorLightning   | No        |
| 198-199 | Light_IndoorLightning*   | No        |
| 200     | Sky2                     | No        |
| 201-224 | Scroll*                  | Yes       |
| 225-244 | Carry*                   | Yes       |