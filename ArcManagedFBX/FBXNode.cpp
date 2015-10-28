#include "Stdafx.h"
#include "FBXNode.h"

using namespace ArcManagedFBX;
using namespace ArcManagedFBX::Types;
using namespace ArcManagedFBX::Utility;

using namespace System;
using namespace System::Text;

FBXNode::FBXNode() : FBXObject()
{

}

FBXNode::~FBXNode()
{

}

FBXNode::!FBXNode()
{
}

FBXNode::FBXNode(FbxNode* instance) : FBXObject(instance)
{
}

void FBXNode::AddChild(FBXNode^ node)
{
	ARC_CHECK_AND_THROW(node == nullptr || node->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	this->GetFBXNode()->AddChild(node->GetFBXNode());
}

int32 ArcManagedFBX::FBXNode::GetDefaultNodeAttributeIndex()
{
	ARC_CHECK_AND_THROW(this->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	return this->GetFBXNode()->GetDefaultNodeAttributeIndex();
}

int32 ArcManagedFBX::FBXNode::GetNodeAttributeCount()
{
	ARC_CHECK_AND_THROW(this->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	return this->GetFBXNode()->GetNodeAttributeCount();
}

FBXNodeAttribute^ ArcManagedFBX::FBXNode::GetNodeAttribute()
{
	ARC_CHECK_AND_THROW(this->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	return gcnew FBXNodeAttribute(this->GetFBXNode()->GetNodeAttribute());
}

FBXNodeAttribute^ ArcManagedFBX::FBXNode::SetNodeAttribute(FBXNodeAttribute^ attribute)
{
	ARC_CHECK_AND_THROW(this->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	return gcnew FBXNodeAttribute(this->GetFBXNode()->SetNodeAttribute(attribute->GetFBXNodeAttribute()));
}

ArcManagedFBX::Types::EShadingMode ArcManagedFBX::FBXNode::GetShadingMode()
{
	ARC_CHECK_AND_THROW(this->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	return (EShadingMode)this->GetFBXNode()->GetShadingMode();
}

void ArcManagedFBX::FBXNode::SetShadingMode(EShadingMode mode)
{
	this->GetFBXNode()->SetShadingMode((FbxNode::EShadingMode)mode);
}

bool ArcManagedFBX::FBXNode::GetVisibility()
{
	return this->GetFBXNode()->GetVisibility();
}

void ArcManagedFBX::FBXNode::SetVisibility(bool isVisible)
{
	this->GetFBXNode()->SetVisibility(isVisible);
}

ArcManagedFBX::FBXVector ArcManagedFBX::FBXNode::GetTargetUpVector()
{
	return FBXVector(this->GetFBXNode()->GetTargetUpVector());
}

void ArcManagedFBX::FBXNode::SetTargetUpVector(FBXVector vector)
{

}

FBXNode^ ArcManagedFBX::FBXNode::GetTargetUp()
{
	return gcnew FBXNode(this->GetFBXNode()->GetTargetUp());
}

void ArcManagedFBX::FBXNode::SetTargetUp(FBXNode^ pNode)
{
	this->GetFBXNode()->SetTargetUp(pNode->GetFBXNode());
}

ArcManagedFBX::FBXVector ArcManagedFBX::FBXNode::GetPostTargetRotation()
{
	return FBXVector(this->GetFBXNode()->GetPostTargetRotation());
}

void ArcManagedFBX::FBXNode::SetPostTargetRotation(FBXVector vector)
{
	// TODO:
}

FBXNode^ ArcManagedFBX::FBXNode::GetTarget()
{
	return gcnew FBXNode(this->GetFBXNode()->GetTarget());
}

void ArcManagedFBX::FBXNode::SetTarget(FBXNode^ node)
{
	this->GetFBXNode()->SetTarget(node->GetFBXNode());
}

FBXNode^ ArcManagedFBX::FBXNode::FindChild(String^ name, bool recursive, bool initial)
{
	const char* nameNative = StringHelper::ToNative(name);
	return gcnew FBXNode(this->GetFBXNode()->FindChild(nameNative,recursive,initial));
}

FBXNode^ ArcManagedFBX::FBXNode::GetChild(int32 pIndex)
{
	return gcnew FBXNode(this->GetFBXNode()->GetChild(pIndex));
}

void ArcManagedFBX::FBXNode::RemoveChild(FBXNode^ Node)
{
	this->GetFBXNode()->RemoveChild(Node->GetFBXNode());
}

bool ArcManagedFBX::FBXNode::SetDefaultNodeAttributeIndex(int32 index, FBXStatus^ status)
{
	return this->GetFBXNode()->SetDefaultNodeAttributeIndex(index,status->GetInstance());
}

int32 ArcManagedFBX::FBXNode::GetChildCount(bool recursive)
{
	ARC_CHECK_AND_THROW(this->GetFBXNode() == nullptr, "This FBX node has not been properly initialized. Check and try again")

	return this->GetFBXNode()->GetChildCount();
}
