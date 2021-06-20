#include "ModelComponent.h"

ModelComponent::ModelComponent(ObjModel* objModel)
{
	model = objModel;
}

ModelComponent::~ModelComponent()
{
}

void ModelComponent::draw()
{
	model->draw();
}
