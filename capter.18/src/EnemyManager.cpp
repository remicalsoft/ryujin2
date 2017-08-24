#include "EnemyManager.h"
#include "Define.h"
#include "SmallEnemy.h"
#include "NormalEnemy.h"
#include "BigEnemy.h"
#include <DxLib.h>

using namespace std;

EnemyManager::EnemyManager()
{
    _list.emplace_back(make_shared<BigEnemy>   (Define::CENTER_X - 100.f, -80.f));
    _list.emplace_back(make_shared<BigEnemy>   (Define::CENTER_X + 100.f, -80.f));
    _list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 400.f, -80.f));
    _list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 300.f, -80.f));
    _list.emplace_back(make_shared<SmallEnemy> (Define::CENTER_X - 400.f, -80.f));
    _list.emplace_back(make_shared<SmallEnemy> (Define::CENTER_X - 300.f, -80.f));

    for (auto enemy : _list) {
        enemy->initialize();
    }
}

bool EnemyManager::update()
{
    for (auto it = _list.begin(); it != _list.end();) {
        if ((*it)->update() == false) {
            it = _list.erase(it);
        }
        else {
            it++;
        }
    }
    return true;
}

void EnemyManager::draw() const
{
    DrawFormatString(0, 20, GetColor(255, 255, 255), "“G‚Ì” = %d", _list.size());
    for (const auto enemy : _list) {
        enemy->draw();
    }
}
