#include "EnemyManager.h"
#include "Define.h"
#include "SmallEnemy.h"
#include "NormalEnemy.h"
#include "BigEnemy.h"

using namespace std;

EnemyManager::EnemyManager()
{
    _list.emplace_back(make_shared<SmallEnemy >(Define::CENTER_X,     100));
    _list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X-200, 100));
    _list.emplace_back(make_shared<BigEnemy>   (Define::CENTER_X+200, 100));

    for (auto enemy : _list) {
        enemy->initialize();
    }
}

bool EnemyManager::update()
{
    for (auto enemy : _list) {
        enemy->update();
    }
    return true;
}

void EnemyManager::draw() const
{
    for (const auto enemy : _list) {
        enemy->draw();
    }
}
