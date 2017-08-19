#include "EnemyManager.h"
#include "Define.h"

using namespace std;

EnemyManager::EnemyManager()
{
    _list.emplace_back(make_shared<Enemy>(Define::CENTER_X, 100));
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
