package com.taobao.kmp

import kotlin.math.sqrt


/* The Computer Language Benchmarks game
  https://salsa.debian.org/benchmarksgame-team/benchmarksgame/

 Naive transliteration from Michael Ferguson's Chapel program
 contributed by Isaac Gouy
*/
class Body(
    var x: Double, var y: Double, var z: Double,
    var vx: Double, var vy: Double, var vz: Double, var mass: Double
)

class nbody {
    companion object {
        var PI: Double = 3.141592653589793
        var SOLAR_MASS: Double = 4 * nbody.Companion.PI * nbody.Companion.PI
        var DAYS_PER_YEAR: Double = 365.24

        fun offsetMomentum(bodies: Array<Body>) {
            var px = 0.0
            var py = 0.0
            var pz = 0.0
            var b: Body
            for (i in bodies.indices) {
                b = bodies[i]
                px += b.vx * b.mass
                py += b.vy * b.mass
                pz += b.vz * b.mass
            }
            b = bodies[0]
            b.vx = -px / nbody.Companion.SOLAR_MASS
            b.vy = -py / nbody.Companion.SOLAR_MASS
            b.vz = -pz / nbody.Companion.SOLAR_MASS
        }

        fun energy(bodies: Array<Body>): Double {
            var e = 0.0
            val numBodies = bodies.size
            for (i in 0..<numBodies) {
                val b = bodies[i]
                val sq = b.vx * b.vx + b.vy * b.vy + b.vz * b.vz
                e += 0.5 * bodies[i].mass * sq
                for (j in i + 1..<numBodies) {
                    val dx = b.x - bodies[j].x
                    val dy = b.y - bodies[j].y
                    val dz = b.z - bodies[j].z
                    val dsq = dx * dx + dy * dy + dz * dz
                    e -= (b.mass * bodies[j].mass) / sqrt(dsq)
                }
            }
            return e
        }

        fun advance(bodies: Array<Body>, dt: Double) {
            val numBodies = bodies.size
            for (i in 0..<numBodies) {
                for (j in i + 1..<numBodies) {
                    val dx = bodies[i].x - bodies[j].x
                    val dy = bodies[i].y - bodies[j].y
                    val dz = bodies[i].z - bodies[j].z
                    val dsq = dx * dx + dy * dy + dz * dz
                    val mag = dt / (dsq * sqrt(dsq))

                    val mj = bodies[j].mass * mag
                    bodies[i].vx -= dx * mj
                    bodies[i].vy -= dy * mj
                    bodies[i].vz -= dz * mj

                    val mi = bodies[i].mass * mag
                    bodies[j].vx += dx * mi
                    bodies[j].vy += dy * mi
                    bodies[j].vz += dz * mi
                }
            }

            for (i in 0..<numBodies) {
                bodies[i].x += bodies[i].vx * dt
                bodies[i].y += bodies[i].vy * dt
                bodies[i].z += bodies[i].vz * dt
            }
        }

        fun nbody(n: Int) {
            val bodies = arrayOf( // sun
                Body(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, SOLAR_MASS),  // jupiter
                Body(
                    4.84143144246472090e+00,
                    -1.16032004402742839e+00,
                    -1.03622044471123109e-01,
                    1.66007664274403694e-03 * DAYS_PER_YEAR,
                    7.69901118419740425e-03 * DAYS_PER_YEAR,
                    -6.90460016972063023e-05 * DAYS_PER_YEAR,
                    9.54791938424326609e-04 * SOLAR_MASS
                ),
                Body( // saturn
                    8.34336671824457987e+00,
                    4.12479856412430479e+00,
                    -4.03523417114321381e-01,
                    -2.76742510726862411e-03 * DAYS_PER_YEAR,
                    4.99852801234917238e-03 * DAYS_PER_YEAR,
                    2.30417297573763929e-05 * DAYS_PER_YEAR,
                    2.85885980666130812e-04 * SOLAR_MASS
                ),
                Body( // uranus
                    1.28943695621391310e+01,
                    -1.51111514016986312e+01,
                    -2.23307578892655734e-01,
                    2.96460137564761618e-03 * DAYS_PER_YEAR,
                    2.37847173959480950e-03 * DAYS_PER_YEAR,
                    -2.96589568540237556e-05 * DAYS_PER_YEAR,
                    4.36624404335156298e-05 * SOLAR_MASS
                ),
                Body( // neptune
                    1.53796971148509165e+01,
                    -2.59193146099879641e+01,
                    1.79258772950371181e-01,
                    2.68067772490389322e-03 * DAYS_PER_YEAR,
                    1.62824170038242295e-03 * DAYS_PER_YEAR,
                    -9.51592254519715870e-05 * DAYS_PER_YEAR,
                    5.15138902046611451e-05 * SOLAR_MASS
                )
            )

            offsetMomentum(bodies)
            Logger.info("[KWLM]","[nbody-begin]:${energy(bodies)}")
            for (i in 0..<n) {
                advance(bodies, 0.01)
            }
            Logger.info("[KWLM]","[nbody-end]:${energy(bodies)}")
        }
    }
}

fun runNBody(n: Int) {
    nbody.nbody(n)
}