#pragma once

//GameObject에서 사용하는 Tag enum입니다.
//게임오브젝트에 태그를 달아 줍니다.
//Tag::basic 이런 식으로 사용합니다.
//자세한 사항은 C++ namespace, C++ enum 구글링 하시거나 저에게 질문 주세요.
//충돌 처리 등을 할 때 사용하면 편합니다.
namespace Tag {

	enum Tag {
		basic = 0,
		Player,
		Bullet,
		Enemy,
		System
	};
}