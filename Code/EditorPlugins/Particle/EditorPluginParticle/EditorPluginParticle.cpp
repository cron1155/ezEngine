#include <EditorPluginParticle/EditorPluginParticlePCH.h>

#include <EditorFramework/Actions/AssetActions.h>
#include <EditorFramework/Actions/ProjectActions.h>
#include <EditorFramework/Actions/ViewActions.h>
#include <EditorFramework/Actions/ViewLightActions.h>
#include <EditorPluginParticle/Actions/ParticleActions.h>
#include <EditorPluginParticle/ParticleEffectAsset/ParticleEffectAsset.h>
#include <GuiFoundation/Action/CommandHistoryActions.h>
#include <GuiFoundation/Action/DocumentActions.h>
#include <GuiFoundation/Action/StandardMenus.h>
#include <GuiFoundation/PropertyGrid/PropertyMetaState.h>

void OnLoadPlugin()
{
  ezParticleActions::RegisterActions();

  // Particle Effect
  {
    // Menu Bar
    {
      ezActionMapManager::RegisterActionMap("ParticleEffectAssetMenuBar").IgnoreResult();
      ezStandardMenus::MapActions("ParticleEffectAssetMenuBar", ezStandardMenuTypes::Default | ezStandardMenuTypes::Edit);
      ezProjectActions::MapActions("ParticleEffectAssetMenuBar");
      ezDocumentActions::MapMenuActions("ParticleEffectAssetMenuBar");
      ezAssetActions::MapMenuActions("ParticleEffectAssetMenuBar");
      ezCommandHistoryActions::MapActions("ParticleEffectAssetMenuBar");
    }

    // Tool Bar
    {
      ezActionMapManager::RegisterActionMap("ParticleEffectAssetToolBar").IgnoreResult();
      ezDocumentActions::MapToolbarActions("ParticleEffectAssetToolBar");
      ezCommandHistoryActions::MapActions("ParticleEffectAssetToolBar", "");
      ezAssetActions::MapToolBarActions("ParticleEffectAssetToolBar", true);
      ezParticleActions::MapActions("ParticleEffectAssetToolBar");
    }

    // View Tool Bar
    {
      ezActionMapManager::RegisterActionMap("ParticleEffectAssetViewToolBar").IgnoreResult();
      ezViewActions::MapToolbarActions("ParticleEffectAssetViewToolBar", ezViewActions::RenderMode | ezViewActions::ActivateRemoteProcess);
      ezViewLightActions::MapToolbarActions("ParticleEffectAssetViewToolBar");
    }

    ezPropertyMetaState::GetSingleton()->m_Events.AddEventHandler(ezParticleEffectAssetDocument::PropertyMetaStateEventHandler);
  }
}

void OnUnloadPlugin()
{
  ezParticleActions::UnregisterActions();
  ezPropertyMetaState::GetSingleton()->m_Events.RemoveEventHandler(ezParticleEffectAssetDocument::PropertyMetaStateEventHandler);
}

EZ_PLUGIN_ON_LOADED()
{
  OnLoadPlugin();
}

EZ_PLUGIN_ON_UNLOADED()
{
  OnUnloadPlugin();
}
