#pragma once
#include "DrawComponent.h"
#include "ObjModel.h"

class ModelComponent : public DrawComponent
{
private:
	ObjModel* model;

public:
	ModelComponent(ObjModel* objModel);
	~ModelComponent();

	virtual void draw() override;
};

