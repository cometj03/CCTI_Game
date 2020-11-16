#include "stdafx.h"
#include "Scene.h"
#include "Framework.h"
#include "GameObject.h"

Scene* Scene::currentScene = nullptr;
Scene* Scene::nextScene = nullptr;

Scene::Scene(): renderingManager(nullptr), camera(nullptr)
{
}

Scene::~Scene()
{
	for (auto& i : gameObjectList)
	{
		SAFE_DELETE(i);
	}
	gameObjectList.clear();
	renderableList.clear();
	SAFE_DELETE(renderingManager);
	SAFE_DELETE(collisionManager);
}

void Scene::SwapScene(D2DApp* d2dApp)
{
	if (!nextScene)
		return;

	SAFE_DELETE(currentScene);
	currentScene = nextScene;
	nextScene = nullptr;

	currentScene->d2dApp = d2dApp;
	currentScene->renderingManager = new RenderingManager(d2dApp);
	currentScene->collisionManager = new CollisionManager();
	currentScene->camera = new Camera();
	currentScene->Push(currentScene->camera);
	currentScene->Initialize();
}

void Scene::ChangeScene(Scene* nextScene)
{
	Scene::nextScene = nextScene;
}

Scene* Scene::GetCurrentScene()
{
	return Scene::currentScene;
}

GameObject* Scene::PushOnCurrentScene(GameObject* gameObject)
{
	if (currentScene)
		return currentScene->Push(gameObject);
	else
		std::cout << "Scene::PushObject error: 현재 씬이 없습니다.\n";
	return nullptr;
}

GameObject* Scene::PushUIOnCurrentScene(GameObject* gameObject)
{
	if (currentScene)
		return currentScene->PushUI(gameObject);
	else
		std::cout << "Scene::PushObject error: 현재 씬이 없습니다.\n";
	return nullptr;
}

AABBCollider* Scene::PushOnCurrentScene(AABBCollider* col)
{
	if (currentScene)
	{
		return currentScene->Push(col);
	}
	else
	{
		std::cout << "Scene::PushObject: 현재 씬이 없습니다.\n";
	}
	return nullptr;
}

CircleCollider* Scene::PushOnCurrentScene(CircleCollider* col)
{
	if (currentScene)
	{
		return currentScene->Push(col);
	}
	else
	{
		std::cout << "Scene::PushObject: 현재 씬이 없습니다.\n";
	}
	return nullptr;
}

void Scene::Initialize()
{
	GameObject* g = Push(new GameObject(L"a.png"));
	g->transform->SetPosition(100.0f, 100.0f);
}

void Scene::UpdateGameObjects()
{
	//모든 오브젝트의 Update를 수행
	for (auto& i : gameObjectList)
		if (i->isActive)
			i->Update();

	//LateUpdate 수행
	for (auto& i : gameObjectList)
		if (i->isActive)
			i->LateUpdate();
}

void Scene::UpdatePhysics()
{
	collisionManager->Update();
}

void Scene::DeleteDestroyedObjects()
{
	//삭제 요청받은 오브젝트 삭제
	auto i = destroyedObjectList.begin();
	while (i != destroyedObjectList.end())
	{
		(*i)->OnDestroy();
		gameObjectList.remove(*i);		//게임오브젝트리스트에서 삭제
		renderableList.remove(*i);		//렌더러블 리스트에서 삭제
		uiList.remove(*i);		//렌더러블 리스트에서 삭제
		collisionManager->RemoveGameObject(*i);
		GameObject* t = *i;
		SAFE_DELETE(t);				//delete
		destroyedObjectList.remove(*i);
		i = destroyedObjectList.begin();
	}
	destroyedObjectList.clear();
}

void Scene::Render()
{
	renderingManager->BeginRender();

	Vector2 screenSize;
	screenSize.x = WinApp::GetScreenWidthF();
	screenSize.y = WinApp::GetScreenHeightF();
	for (auto& i : renderableList)
	{
		i->renderer->Render(Scene::d2dApp, i->transform,i->renderer->ComputeWorldPosition(screenSize,i->transform,camera->transform->position));
	}

	for (auto& i : uiList)
	{
		i->renderer->Render(Scene::d2dApp, i->transform, i->renderer->ComputeUIPosition(i->transform));
	}
		//renderingManager->Render(i->renderer, i->transform,camera->transform->position);
		//renderingManager->Render(i->renderer, i->transform);
	renderingManager->EndRender();
}

GameObject* Scene::Push(GameObject* gameObject)
{
	//게임 오브젝트에 집어넣음
	gameObjectList.push_back(gameObject);
	//렌더러에 이미지가 있을경우
	//렌더러블 리스트에 집어넣음
	if (gameObject->renderer->GetInitialized())
	{
		renderableList.push_back(gameObject);
	}
	return gameObject;//받은 게임오브젝트를 그대로 반환
}

GameObject* Scene::PushUI(GameObject* gameObject)
{
	//게임 오브젝트에 집어넣음
	gameObjectList.push_back(gameObject);
	//렌더러에 이미지가 있을경우
	//렌더러블 리스트에 집어넣음
	if (gameObject->renderer->GetInitialized())
	{
		uiList.push_back(gameObject);
	}
	return gameObject;//받은 게임오브젝트를 그대로 반환
}

AABBCollider* Scene::Push(AABBCollider* col)
{
	if (currentScene->collisionManager)
		return currentScene->collisionManager->PushBackCollider(col);
	else
		std::cout << "Scene::PushObject: collisionManager가 없습니다.\n";
	return nullptr;
}

CircleCollider* Scene::Push(CircleCollider* col)
{
	if (currentScene->collisionManager)
		return currentScene->collisionManager->PushBackCollider(col);
	else
		std::cout << "Scene::PushObject: collisionManager가 없습니다.\n";
	return nullptr;
}

void Scene::Destroy(GameObject* o)
{
	//삭제될 오브젝트 리스트에 집어넣음
	if (currentScene)
	{
		currentScene->destroyedObjectList.push_back(o);
	}
	else
	{
		std::cout << "Scene::Destroy 현재 씬이 없습니다.\n";
	}
}

RenderingManager* Scene::GetRenderingManager()
{
	return renderingManager;
}

CollisionManager* Scene::GetCollisionManager()
{
	return collisionManager;
}

Camera* Scene::GetCamera()
{
	return camera;
}
