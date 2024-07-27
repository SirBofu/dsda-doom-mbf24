# dsda-doom-mbf24 v0.27.5

This is a heavily WIP, mostly proof of concept build of DSDA-Doom that focuses on building a new complevel, MBF24.
Its implementation is pretty simple so far.

Documentation of the MBF24 spec as envisioned in this build can be found in mbf24_spec.md.

Test WADs implementing the features so far:

[Antitelefrag/Nodamage/Pushable Flag Test](https://www.dropbox.com/scl/fi/0ew1sbdqjf93w87xqczo7/ThingFlagTest.wad?rlkey=vsr9cwgoeare93qbtfrn35ung&st=1ilxe0yg&dl=0)
In this WAD, the Mancubus in the level is impervious to damage, and if the player attempts to teleport into it, they will be telefragged instantly.
In addition, there is a pushable office chair prop that is impervious to damage but can be shot. Both have the `NODAMAGE` flag, while the chair has `PUSHABLE` and the Mancubus has `ANTITELEFRAG`.

[Thing Counter Test](https://www.dropbox.com/scl/fi/kbtqb60lufsfnyz2ar0s0/ThingCounterTest.wad?rlkey=ugu01l5p4hj9hmxupdjkgougf&st=y1hg5yrp&dl=0)
In this WAD, zombiemen have been modified via new DEHACKED codepointers to use a simple incrementing counter and fire a different projectile based thereupon.
After reaching the highest value, the counter resets to 0.
- 0: Imp fireball
- 1: Cacodemon fireball
- 2: Lost Soul
- 3: Revenant missile
- 4: Arachnotron plasma
- 5-6: Baron fireball
- 7: Cyberdemon rocket

[Noinfighting Flag Test](https://www.dropbox.com/scl/fi/hacr3hutcx0pfys1kaqu1/NoInfightingTest.wad?rlkey=y9fra0zqwhesluc5kg54oy06n&st=qa57b1oz&dl=0)
In this WAD, Arachnotrons have been given the new `NOINFIGHTING` flag. Even if the player hasn't damaged them, they won't respond to damage from other
enemies (and are still immune to damage from other Arachnotrons), but will still respond to receiving damage from the player.

[Floatbob Flag Test](https://www.dropbox.com/scl/fi/5b2n1dptx5jwa0vtynwr3/FloatBobTest.wad?rlkey=qzklrg7kbru7vsqecovrpszul&st=nzp11uyq&dl=0)
In this simple WAD, the Soulsphere has been modified via DEHACKED and bobs similar to how Hexen powerups bob thanks to the addition of the `BOBFLOAT` flag.

[Deadfloat, Floatbob, and Onlyslamsolid Flag Test](https://www.dropbox.com/scl/fi/0xt3ma73r2fp584krnle5/DeadFloatTest.wad?rlkey=l1cusdxz8r23fcq9cj2y76c1r&st=n3gwgfry&dl=0)
In this WAD, Pain Elementals have been modified via DEHACKED to have the `DEADFLOAT` flag, which causes them to not fall when they are killed.
They've also been given the `FLOATBOB` flag to demonstrate it working on moving, no-gravity objects.
In addition, Lost Souls have been given the `ONLYSLAMSOLID` flag, which prevents them from colliding with non-solid objects and being interrupted.

[Thing Use Frame Test](https://www.dropbox.com/scl/fi/yqxur4y7xo4077awppm3v/UseThingTest.wad?rlkey=w4ayj0yq4s775xsjurcz07gzn&st=ptjrg0pr&dl=0)
This WAD demonstrates a simple implementation of the `Use frame` Thing property and `ALLOWUSE` Frame flag.
The barrels filled with brown liquid don't explode when damaged; instead, they must be primed by pressing the Use key.
They will play a sound, flash brightly for a couple of seconds, and then explode.