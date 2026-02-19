#pragma once
#include "Texture2D.h"

class ghostBig : public Object
{
public:
	Texture2D m_Texture2D;

public:
	void Init() override;
	void Update() override;
	void Draw(Camera* cam) override;
	void Uninit() override;

	void Control();
};
