#include "stdafx.h"
#include "AnimationInfo.h"
#include "TimeManager.h"

AnimationInfo::AnimationInfo()
	:RenderInfo(), currentState(0), currentAnimation(nullptr)
{
	initialized = true;
}

AnimationInfo::~AnimationInfo()
{
	for (auto& i : animations)
		SAFE_DELETE(i);
	animations.clear();
}

void AnimationInfo::Render(D2DApp* d2dApp, Transform* transform, Vector2 screenPosition)
{
	if (!d2dApp)
	{
		printf("RenderInfo::Render: d2dApp이 없습니다.\n");
		return;
	}
	ID2D1HwndRenderTarget* renderTarget = d2dApp->GetRenderTarget();
	if (!renderTarget)
	{
		printf("RenderingManger::Render 실패, 렌더타겟이 없습니다.\n");
		return;
	}
	UpdateRenderInfo();
	BasicRender(renderTarget, transform, GetSourceRect(),screenPosition);
}

void AnimationInfo::UpdateRenderInfo()
{
	if (!currentAnimation)
		return;
	currentSprite = currentAnimation->UpdateAnim();
}

void AnimationInfo::ChangeAnimation(int state)
{
	Animation* temp = FindAnimationByState(state);
	if (temp)
	{
		currentState = state;
		currentAnimation = temp;
		currentAnimation->Reset();
		currentSprite = currentAnimation->GetCurrentSprite();
	}
	else
	{
		printf("존재하지 않는 Animation state입니다.\n");
	}
}

void AnimationInfo::PushBackAnimation(Animation* anim)
{
	animations.push_back(anim);
	if (!currentSprite)
	{
		ChangeAnimation(anim->state);
	}
}

Animation* AnimationInfo::FindAnimationByState(int state)
{
	for (auto& i : animations)
	{
		if (i->state == state)
			return i;				//찾았을 경우 해당 애니메이션 반환
	}
	return nullptr;		//없을 경우 nullptr 반환

}

D2D1_RECT_F* AnimationInfo::GetSourceRect()
{
	return currentAnimation->GetSourceRect();
}

int AnimationInfo::GetWidth()
{
	if (currentAnimation)
		return currentAnimation->GetAnimationWidth();
	else
		return 0;
}

int AnimationInfo::GetHeight()
{
	if (currentAnimation)
		return currentAnimation->GetAnimationHeight();
	else
		return 0;
}
