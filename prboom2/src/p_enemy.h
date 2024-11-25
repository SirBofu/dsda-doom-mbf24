/* Emacs style mode select   -*- C -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2000 by
 *  Jess Haas, Nicolas Kalkhof, Colin Phipps, Florian Schulze
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *      Enemy thinking, AI.
 *      Action Pointer Functions
 *      that are associated with states/frames.
 *
 *-----------------------------------------------------------------------------*/

#ifndef __P_ENEMY__
#define __P_ENEMY__

#include "p_mobj.h"

void P_NoiseAlert (mobj_t *target, mobj_t *emmiter);
void P_SpawnBrainTargets(void); /* killough 3/26/98: spawn icon landings */
dboolean P_CheckBossDeath(mobj_t *mo);

extern struct brain_s {         /* killough 3/26/98: global state of boss brain */
  int easy, targeton;
} brain;

// ********************************************************************
// Function addresses or Code Pointers
// ********************************************************************
// These function addresses are the Code Pointers that have been
// modified for years by Dehacked enthusiasts.  The new BEX format
// allows more extensive changes (see d_deh.c)

// Doesn't work with g++, needs actionf_p1
void A_Explode(mobj_t *);
void A_Pain(mobj_t *);
void A_PlayerScream(mobj_t *);
void A_Fall(mobj_t *);
void A_XScream(mobj_t *);
void A_Look(mobj_t *);
void A_Chase(mobj_t *);
void A_FaceTarget(mobj_t *);
void A_PosAttack(mobj_t *);
void A_Scream(mobj_t *);
void A_SPosAttack(mobj_t *);
void A_VileChase(mobj_t *);
void A_VileStart(mobj_t *);
void A_VileTarget(mobj_t *);
void A_VileAttack(mobj_t *);
void A_StartFire(mobj_t *);
void A_Fire(mobj_t *);
void A_FireCrackle(mobj_t *);
void A_Tracer(mobj_t *);
void A_SkelWhoosh(mobj_t *);
void A_SkelFist(mobj_t *);
void A_SkelMissile(mobj_t *);
void A_FatRaise(mobj_t *);
void A_FatAttack1(mobj_t *);
void A_FatAttack2(mobj_t *);
void A_FatAttack3(mobj_t *);
void A_BossDeath(mobj_t *);
void A_CPosAttack(mobj_t *);
void A_CPosRefire(mobj_t *);
void A_TroopAttack(mobj_t *);
void A_SargAttack(mobj_t *);
void A_HeadAttack(mobj_t *);
void A_BruisAttack(mobj_t *);
void A_SkullAttack(mobj_t *);
void A_Metal(mobj_t *);
void A_SpidRefire(mobj_t *);
void A_BabyMetal(mobj_t *);
void A_BspiAttack(mobj_t *);
void A_Hoof(mobj_t *);
void A_CyberAttack(mobj_t *);
void A_PainAttack(mobj_t *);
void A_PainDie(mobj_t *);
void A_KeenDie(mobj_t *);
void A_BrainPain(mobj_t *);
void A_BrainScream(mobj_t *);
void A_BrainDie(mobj_t *);
void A_BrainAwake(mobj_t *);
void A_BrainSpit(mobj_t *);
void A_SpawnSound(mobj_t *);
void A_SpawnFly(mobj_t *);
void A_BrainExplode(mobj_t *);
void A_Die(mobj_t *);
void A_Detonate(mobj_t *);        /* killough 8/9/98: detonate a bomb or other device */
void A_Mushroom(mobj_t *);        /* killough 10/98: mushroom effect */
void A_Spawn(mobj_t *);           // killough 11/98
void A_Turn(mobj_t *);            // killough 11/98
void A_Face(mobj_t *);            // killough 11/98
void A_Scratch(mobj_t *);         // killough 11/98
void A_PlaySound(mobj_t *);       // killough 11/98
void A_RandomJump(mobj_t *);      // killough 11/98
void A_LineEffect(mobj_t *);      // killough 11/98

void A_BetaSkullAttack(mobj_t *); // killough 10/98: beta lost souls attacked different
void A_Stop(mobj_t *);

void A_SkullPop(mobj_t *);

// [XA] New mbf21 codepointers

void A_SpawnObject(mobj_t *);
void A_MonsterProjectile(mobj_t *);
void A_MonsterBulletAttack(mobj_t *);
void A_MonsterMeleeAttack(mobj_t *);
void A_RadiusDamage(mobj_t *);
void A_NoiseAlert(mobj_t *);
void A_HealChase(mobj_t *);
void A_SeekTracer(mobj_t *);
void A_FindTracer(mobj_t *);
void A_ClearTracer(mobj_t *);
void A_JumpIfHealthBelow(mobj_t *);
void A_JumpIfTargetInSight(mobj_t *);
void A_JumpIfTargetCloser(mobj_t *);
void A_JumpIfTracerInSight(mobj_t *);
void A_JumpIfTracerCloser(mobj_t *);
void A_JumpIfFlagsSet(mobj_t *);
void A_AddFlags(mobj_t *);
void A_RemoveFlags(mobj_t *);

// New MBF24 codepointers

void A_LineEffect2(mobj_t *);
void A_JumpIfTargetHigher(mobj_t *);
void A_JumpIfTracerHigher(mobj_t *);
void A_SetCounter(mobj_t *);
void A_AddCounter(mobj_t *);
void A_JumpIfCounterEquals(mobj_t *);
void A_JumpIfCounterGreater(mobj_t *);
void A_LaunchTarget(mobj_t *);
void A_SetHealth(mobj_t *);
void A_RegainHealth(mobj_t *);
void A_ChaseEx(mobj_t *);
void A_ClearTarget(mobj_t *);
void A_JumpIfTargetTouching(mobj_t *);
void A_MonsterJump(mobj_t *);
void A_JumpIfTargetFlagsSet(mobj_t *);
void A_JumpIfTracerFlagsSet(mobj_t *);
void A_JumpIfHasTarget(mobj_t *);
void A_JumpIfHasTracer(mobj_t *);
void A_JumpIfBlocked(mobj_t *);
void A_DodgeChase(mobj_t *);
void A_Wander(mobj_t *);
void A_Patrol(mobj_t *);
void A_MonsterSpawnAttack(mobj_t *);
void A_MonsterSpawnDie(mobj_t *);
void A_MonsterChargeAttack(mobj_t *);
void A_AddTargetFlags(mobj_t *);
void A_AddTracerFlags(mobj_t *);
void A_RemoveTargetFlags(mobj_t *);
void A_RemoveTracerFlags(mobj_t *);
void A_MonsterZapTarget(mobj_t *);
void A_MonsterZapAttack(mobj_t *);
void A_SetTargetState(mobj_t *);
void A_SetTracerState(mobj_t *);
void A_DropThing(mobj_t *);
void A_SetSectorBrightness(mobj_t *);
void A_JumpIfSkill(mobj_t *);
void A_JumpIfMapNum(mobj_t *);
void A_SetVelocity(mobj_t *);
void A_AddVelocity(mobj_t *);
void A_MultiplyVelocity(mobj_t *);
void A_MonsterRefire(mobj_t *);

// heretic

void A_UnHideThing(mobj_t * actor);
void P_InitMonsters(void);
void P_AddBossSpot(fixed_t x, fixed_t y, angle_t angle);
void P_Massacre(void);
void P_DSparilTeleport(mobj_t * actor);
void Heretic_A_BossDeath(mobj_t * actor);
dboolean Heretic_P_LookForMonsters(mobj_t * actor);
dboolean Raven_P_LookForPlayers(mobj_t * actor, dboolean allaround);

// hexen

void P_InitCreatureCorpseQueue(dboolean corpseScan);
void A_DeQueueCorpse(mobj_t * actor);
dboolean A_RaiseMobj(mobj_t * actor);
dboolean A_SinkMobj(mobj_t * actor);
void A_NoBlocking(mobj_t * actor);

// zdoom

dboolean P_RaiseThing(mobj_t *corpse, mobj_t *raiser);

#endif // __P_ENEMY__
