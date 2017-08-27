#pragma once

#include <vector>
#include <memory>

class AbstractEnemy;

class EnemyMover 
{

public:
    EnemyMover();
    virtual ~EnemyMover() = default;
    void move(AbstractEnemy* enemy);

private:
    typedef void(EnemyMover::*FUNC)(AbstractEnemy* enemy);
    std::vector<FUNC> _movePattern;
    void setFunction();

    void movePattern00(AbstractEnemy *enemy);
    void movePattern01(AbstractEnemy *enemy);
    void movePattern02(AbstractEnemy *enemy);
    void movePattern03(AbstractEnemy *enemy);
    void movePattern04(AbstractEnemy *enemy);

};
