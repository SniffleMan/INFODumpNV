#include "common/IDebugLog.h"  // IDebugLog
#include "nvse/GameData.h"  // DataHandler
#include "nvse/GameForms.h"  // TESTopic, TESTopicInfo
#include "nvse/PluginAPI.h"  // NVSEMessagingInterface
#include "nvse/nvse_version.h"  // RUNTIME_VERSION

#include <ShlObj.h>  // CSIDL_MYDOCUMENTS

#include "RE/TESTopic.h"  // TESTopic


static PluginHandle					g_pluginHandle = kPluginHandle_Invalid;
static NVSESerializationInterface*	g_serialization = 0;


void SerializationHandler(void*)
{
	DataHandler* dataHandler = DataHandler::Get();
	RE::TESTopic* topic = 0;
	TESTopicInfo* topicInfo = 0;
	for (auto it = dataHandler->topicList.Begin(); !it.End(); ++it) {
		topic = (RE::TESTopic*)*it;
		_MESSAGE("DIAL: %08X", topic->refID);
		if (topic->info) {
			for (UInt32 i = 0; i < topic->info->infoArray.numObjs; ++i) {
				topicInfo = topic->info->infoArray.data[i];
				_MESSAGE("INFO: %08X", topicInfo->refID);
			}
		}
	}
}


extern "C" {
	bool NVSEPlugin_Query(const NVSEInterface* a_nvse, PluginInfo* a_info)
	{
		gLog.OpenRelative(CSIDL_MYDOCUMENTS, "\\My Games\\FalloutNV\\NVSE\\INFODumpNV.log");
		gLog.SetPrintLevel(IDebugLog::kLevel_DebugMessage);
		gLog.SetLogLevel(IDebugLog::kLevel_DebugMessage);

		a_info->infoVersion = PluginInfo::kInfoVersion;
		a_info->name = "INFODumpNV";
		a_info->version = 1;

		g_pluginHandle = a_nvse->GetPluginHandle();

		if (a_nvse->isEditor) {
			_FATALERROR("[FATAL ERROR] Loaded in editor, marking as incompatible!\n");
			return false;
		}

		if (a_nvse->runtimeVersion != RUNTIME_VERSION_1_4_0_525) {
			_FATALERROR("[FATAL ERROR] Unsupported runtime version %08X!\n", a_nvse->runtimeVersion);
			return false;
		}

		return true;
	}

	bool NVSEPlugin_Load(const NVSEInterface* a_nvse)
	{
		g_serialization = (NVSESerializationInterface*)a_nvse->QueryInterface(kInterface_Serialization);
		g_serialization->SetNewGameCallback(g_pluginHandle, SerializationHandler);
		return true;
	};
}
