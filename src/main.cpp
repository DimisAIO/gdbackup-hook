#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GJAccountManager.hpp>
class $modify(GJAccountManager) {
	$override
	void handleIt(bool _requestSentSuccessfully, gd::string _response, gd::string _tag, GJHttpType _httpType) {
		switch(_httpType) {
			case GJHttpType::GetAccountBackupURL:
			case GJHttpType::GetAccountSyncURL:
				_response = "https://gdbackup.141412.xyz";
				break;
			default:
				break;
		}
		GJAccountManager::handleIt(_requestSentSuccessfully,  _response, _tag, _httpType);
	}
};

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!Mod::get()->setSavedValue("first-time", true)) {
		    FLAlertLayer::create(
		        "Warning for new users.",
		        "Since GDBackup uses an online server, it uses sensitive account details in order to verify that you own your account (just like in gd). Your sensitive information will never be stored. If you do not want to share this information, DO NOT backup and uninstall GDBackup from Geode!",
		        "OK"
		    )->show();
		}
		return true;
	}
}
