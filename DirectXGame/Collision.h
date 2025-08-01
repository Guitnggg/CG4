#pragma once

#include <math/Vector3.h>
#include <cmath>

class Collision {
public:

    /// <summary>
    /// 球体同士の衝突判定（中心点と半径）
    /// </summary>
    static bool CheckSphereCollision(const KamataEngine::Vector3& posA, float radiusA,
        const KamataEngine::Vector3& posB, float radiusB) {
        KamataEngine::Vector3 d = {
            posA.x - posB.x,
            posA.y - posB.y,
            posA.z - posB.z
        };

        float distSq = d.x * d.x + d.y * d.y + d.z * d.z;
        float r = radiusA + radiusB;

        return distSq <= r * r;
    }

};

