#include "AbstractScene.h"

/*!
@brief コンストラクタ
@param impl シーン変更のリスナー
@param parameter 前のシーンから渡されたパラメータ
*/
AbstractScene::AbstractScene(IOnSceneChangedListener* impl, const Parameter& parameter) : 
    _implSceneChanged(impl)
{
}
