/*
===========================================================================
Copyright (C) 1999-2005 Id Software, Inc.
Copyright (C) 2000-2013 Darklegion Development

This file is part of Tremulous.

Tremulous is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Tremulous is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tremulous; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/

#include "g_local.h"

/*
================
G_Bounce

================
*/
static void G_Bounce( gentity_t *ent, trace_t *trace )
{
  vec3_t    velocity;
  float     dot;
  int       hitTime;
  float     minNormal;
  qboolean  invert = qfalse;
  vec3_t    normal;

  VectorCopy( trace->plane.normal, normal );

  // reflect the velocity on the trace plane
  hitTime = level.previousTime + ( level.time - level.previousTime ) * trace->fraction;
  BG_EvaluateTrajectoryDelta( &ent->s.pos, hitTime, velocity );
  dot = DotProduct( velocity, normal );
  VectorMA( velocity, -2*dot, normal, ent->s.pos.trDelta );

  if( ent->s.eType == ET_BUILDABLE )
  {
    minNormal = BG_Buildable( ent->s.modelindex )->minNormal;
    invert = BG_Buildable( ent->s.modelindex )->invertNormal;
  }
  else
    minNormal = 0.707f;

  // cut the velocity to keep from bouncing forever
  if( normal[ 2 ] >= minNormal ||
      ( invert && normal[ 2 ] <= -minNormal ) )
  {
    // do some damage with buildables that bounce
    if( ent->s.eType == ET_BUILDABLE &&
        VectorLength( ent->s.pos.trDelta ) > 20 )
    {
      int bounceDamage = (VectorLength( ent->s.pos.trDelta ) / 300 ) *
                       ( BG_Buildable( ent->s.modelindex )->health / 10 + 1 );
      G_Damage( ent, NULL, &g_entities[ ent->dropperNum ], NULL,
                NULL, bounceDamage, DAMAGE_NO_PROTECTION, MOD_FALLING );
      if( G_TakesDamage( &g_entities[trace->entityNum] ) )
      {
        G_Damage( &g_entities[trace->entityNum], NULL,
                  &g_entities[ ent->dropperNum ], NULL, NULL, bounceDamage,
                  DAMAGE_NO_PROTECTION, MOD_CRUSH );
      }
    }

    VectorScale( ent->s.pos.trDelta, ent->physicsBounce, ent->s.pos.trDelta );
  }
  else
    VectorScale( ent->s.pos.trDelta, 0.3f, ent->s.pos.trDelta );

  if( VectorLength( ent->s.pos.trDelta ) < 10 )
  {
    if( ent->s.eType == ET_BUILDABLE )
    {
      // check if a buildable should be damaged at its new location
      if( !IS_WARMUP && g_allowBuildableStacking.integer )
      {
        int contents = SV_PointContents( ent->r.currentOrigin, -1 );
        int surfaceFlags = trace->surfaceFlags;

        if( !( normal[ 2 ] >= minNormal || ( invert && normal[ 2 ] <= -minNormal ) ) ||
            ( surfaceFlags & SURF_NOBUILD || contents & CONTENTS_NOBUILD ) ||
            ( ent->buildableTeam == TEAM_ALIENS &&
              ( trace->surfaceFlags & SURF_NOALIENBUILD || contents & CONTENTS_NOALIENBUILD ) ) ||
            ( ent->buildableTeam == TEAM_HUMANS &&
              ( trace->surfaceFlags & SURF_NOHUMANBUILD || contents & CONTENTS_NOHUMANBUILD ) ) )
          ent->damageDroppedBuildable = qtrue;
        else
          ent->damageDroppedBuildable = qfalse;
      }

      if( normal[ 2 ] >= minNormal ||
          ( invert && normal[ 2 ] <= -minNormal ) )
      {
        G_SetOrigin( ent, trace->endpos );
        ent->s.groundEntityNum = trace->entityNum;
        G_AddBuildableToStack( ent->s.groundEntityNum, ent->s.number );
        VectorCopy( normal, ent->s.origin2 );
        VectorSet( ent->s.pos.trDelta, 0.0f, 0.0f, 0.0f );
        return;
      }
    } else
    {
      G_SetOrigin( ent, trace->endpos );
      ent->s.groundEntityNum = trace->entityNum;
      VectorCopy( normal, ent->s.origin2 );
      VectorSet( ent->s.pos.trDelta, 0.0f, 0.0f, 0.0f );
      return;
    }
  }

  VectorMA( ent->r.currentOrigin, 0.15, normal, ent->r.currentOrigin );
  VectorCopy( ent->r.currentOrigin, ent->s.pos.trBase );
  ent->s.pos.trTime = level.time;
}

#define PHYSICS_TIME 200

/*
================
G_Physics

================
*/
void G_Physics( gentity_t *ent, int msec )
{
  vec3_t    origin;
  trace_t   tr;
  int     contents;
  int     i;

  // if groundentity has been set to ENTITYNUM_NONE, ent may have been pushed off an edge
  if( ent->s.groundEntityNum == ENTITYNUM_NONE )
  {
    if( ent->s.eType == ET_BUILDABLE )
    {
      if( ent->s.pos.trType != BG_Buildable( ent->s.modelindex )->traj )
      {
        ent->s.pos.trType = BG_Buildable( ent->s.modelindex )->traj;
        ent->s.pos.trTime = level.time;
      }
    }
    else if( ent->s.pos.trType != TR_GRAVITY )
    {
      ent->s.pos.trType = TR_GRAVITY;
      ent->s.pos.trTime = level.time;
    }
  }

  if( ent->s.pos.trType == TR_STATIONARY )
  {
    // check think function
    G_RunThink( ent );

    //check floor infrequently
    if( ent->nextPhysicsTime < level.time )
    {
      VectorCopy( ent->r.currentOrigin, origin );

      VectorMA( origin, -2.0f, ent->s.origin2, origin );

      SV_Trace( &tr, ent->r.currentOrigin, ent->r.mins, ent->r.maxs, origin,
        ent->s.number, ent->clipmask, TT_AABB );

      if( tr.fraction == 1.0f )
      {
        if( ent->s.groundEntityNum != ENTITYNUM_NONE )
          G_RemoveBuildableFromStack( ent->s.groundEntityNum, ent->s.number );
        ent->s.groundEntityNum = ENTITYNUM_NONE;
      }
      else if( ent->s.groundEntityNum != tr.entityNum )
      {
        trace_t tr2;
        int unlinkedEntNums[ MAX_GENTITIES ];
        int numUnlinkedEntNums = 0;

        // check to see if the old ground entity is no longer supporting this entity
        tr2.entityNum = tr.entityNum;
        while( ( ent->s.groundEntityNum != tr2.entityNum ) &&
               ( tr2.fraction != 1.0f ) )
        {
          unlinkedEntNums[ numUnlinkedEntNums ] = tr2.entityNum;
          numUnlinkedEntNums++;
          SV_UnlinkEntity( &g_entities[ tr2.entityNum ] );
          SV_Trace( &tr2, ent->r.currentOrigin, ent->r.mins, ent->r.maxs, origin,
            ent->s.number, ent->clipmask, TT_AABB );
        }

        for( i = 0; i < numUnlinkedEntNums; i++ )
          SV_LinkEntity( &g_entities[ unlinkedEntNums[ i ] ] );

        if( ent->s.groundEntityNum != tr2.entityNum )
        {
          G_RemoveBuildableFromStack( ent->s.groundEntityNum, ent->s.number );
          ent->s.groundEntityNum = tr.entityNum;
          G_AddBuildableToStack( ent->s.groundEntityNum, ent->s.number );
        }
      }

      ent->nextPhysicsTime = level.time + PHYSICS_TIME;
    }

    return;
  }

  // trace a line from the previous position to the current position

  // get current position
  BG_EvaluateTrajectory( &ent->s.pos, level.time, origin );

  SV_Trace( &tr, ent->r.currentOrigin, ent->r.mins, ent->r.maxs,
    origin, ent->s.number, ent->clipmask, TT_AABB );

  VectorCopy( tr.endpos, ent->r.currentOrigin );

  if( tr.startsolid )
    tr.fraction = 0;

  SV_LinkEntity( ent ); // FIXME: avoid this for stationary?

  // check think function
  G_RunThink( ent );

  if( tr.fraction == 1.0f )
    return;

  // if it is in a nodrop volume, remove it
  contents = SV_PointContents( ent->r.currentOrigin, -1 );
  if( contents & CONTENTS_NODROP )
  {
    if( ent->s.eType == ET_BUILDABLE )
      G_RemoveRangeMarkerFrom( ent );
    G_FreeEntity( ent );
    return;
  }

  G_Bounce( ent, &tr );
}
