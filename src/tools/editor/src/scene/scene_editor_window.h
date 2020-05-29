#pragma once
#include "entity_editor.h"
#include "entity_list.h"
#include "halley/ui/ui_widget.h"
#include "scene_editor_canvas.h"
#include "halley/tools/dll/dynamic_library.h"

namespace Halley {
	class HalleyAPI;
	class Project;
	class UIFactory;
	class EntityFactory;

	class SceneEditorWindow final : public UIWidget, public IDynamicLibraryListener {
	public:
		SceneEditorWindow(UIFactory& factory, Project& project, const HalleyAPI& api);
		~SceneEditorWindow();

		void onAddedToRoot() override;
		
		void loadScene(const String& sceneName);
		void loadPrefab(const String& name);
		void loadScene(const Prefab& prefab);
		void unloadScene();
		void markModified();

		void onEntityAdded(const String& id, const String& parentId);
		void onEntityRemoved(const String& id, const String& parentId);
		void onEntityModified(const String& id);
		void onEntityMoved(const String& id);
		void onComponentRemoved(const String& name);
		void onFieldChangedByGizmo(const String& componentName, const String& fieldName);

		void addNewEntity();
		void addNewPrefab();
		void addNewPrefab(const String& prefabName);
		void addEntity(ConfigNode data);
		void addEntity(const String& parentId, ConfigNode data);
		void removeEntity();
		void removeEntity(const String& entityId);
		void selectEntity(const String& id);

		void setTool(SceneEditorTool tool);
		void setTool(SceneEditorTool tool, const String& componentName, const String& fieldName, ConfigNode options);

		std::shared_ptr<const Prefab> getGamePrefab(const String& id) const;

	protected:
		void update(Time t, bool moved) override;

		bool onKeyPress(KeyboardKeyPress key) override;

		void onUnloadDLL() override;
		void onLoadDLL() override;

	private:
		const HalleyAPI& api;
		UIFactory& uiFactory;
		Project& project;

		std::shared_ptr<SceneEditorGameBridge> gameBridge;
		std::shared_ptr<SceneEditorCanvas> canvas;
		std::shared_ptr<EntityList> entityList;
		std::shared_ptr<EntityEditor> entityEditor;
		std::shared_ptr<UIList> toolMode;

		Path assetPath;
		std::shared_ptr<ISceneData> sceneData;
		std::shared_ptr<Prefab> prefab;
		std::shared_ptr<EntityFactory> entityFactory;

		String currentEntityId;

		std::shared_ptr<UIWidget> curCustomUI;
		std::shared_ptr<UIWidget> curToolUI;
		SceneEditorTool curTool = SceneEditorTool::None;
		String curComponentName;

		void makeUI();
		void onEntitySelected(const String& id);
		void panCameraToEntity(const String& id);
		void saveEntity();

		String findParent(const String& entityId) const;
		const String* findParent(const String& entityId, const EntityTree& tree, const String& prev) const;

		void preparePrefab(Prefab& prefab);
		void preparePrefabEntity(ConfigNode& node);

		void setCustomUI(std::shared_ptr<UIWidget> ui);
		void setToolUI(std::shared_ptr<UIWidget> ui);

		void decayTool();

		void setSaveEnabled(bool enabled);
	};
}
