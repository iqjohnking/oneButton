#pragma once
#include "Scene.h"
#include "Object.h"

#include "CloseEye.h"
#include "backGround.h"
#include "ghost.h"
#include "ghostBig.h"
#include "Attack.h"
#include "moji.h"

// TitleSceneクラス
class TitleScene : public Scene
{
private:
	std::vector<Object*> m_MySceneObjects; // このシーンのオブジェクト

	CloseEye*	m_CloseEye; // 目を閉じるオブジェクト
	backGround* m_bg;		// 目を閉じるオブジェクト
	ghost*		m_ghostSml; // 目を閉じるオブジェクト
	ghostBig*	m_ghostBig; // 目を閉じるオブジェクト
	Attack*		m_Attack; // 目を閉じるオブジェクト
	moji*		m_moji; // 目を閉じるオブジェクト

	float range = 0;
	float DeadRange = 500;
	float result = range / DeadRange;
	bool m_IsGameOver = false;
	int goTimer = 0;

	void Init(); // 初期化
	void Uninit(); // 終了処理

public:
	TitleScene(); // コンストラクタ
	~TitleScene(); // デストラクタ

	void Update() override; // 更新
	void DrawImGui() override;
};

