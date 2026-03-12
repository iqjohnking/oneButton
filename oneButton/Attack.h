#pragma once
#include "Texture2D.h"

class Attack : public Object
{
public:
	Texture2D m_Texture2D;

	float timer = 0;

public:
	void Init() override;
	void Update() override;
	void Draw(Camera* cam) override;
	void Uninit() override;

	void Control();
};
#pragma once
